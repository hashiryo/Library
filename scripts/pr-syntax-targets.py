#!/usr/bin/env python3
# /// script
# requires-python = ">=3.12"
# ///
"""PR で変わったヘッダを閉包に持つ test を 1 行 1 ファイルで出す。

PR の軽い検査 (.github/workflows/pr-check.yml) が、ここで出た test を 1 環境で
-fsyntax-only でコンパイルする。テストデータもトークンも要らず、数分で終わる。
CE は拾えるが WA は拾えない。WA はマージ後に procon-judge が測って分かる。

test に含まれない変更 (どの test も使わないヘッダ、あるいは test/ を消したあと) は
変わったヘッダそのものを出す。ヘッダ単体のコンパイルはテンプレートを実体化しない
ので弱いが、構文と非テンプレートの誤りは拾える。
"""

import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from lib.rerun import ROOT, TEST_DIR, get_dependencies, get_hpp_transitive_deps


def changed_files(base: str, head: str) -> set[str]:
    """base から head までに変わったファイル (ROOT からの相対)。"""
    proc = subprocess.run(
        ["git", "diff", "--name-only", f"{base}...{head}"],
        cwd=ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    return {line.strip() for line in proc.stdout.splitlines() if line.strip()}


def test_closures() -> dict[str, set[str]]:
    """test ごとの、直接と推移的な mylib の依存。IGNORE の test は除く。"""
    closures: dict[str, set[str]] = {}
    if not TEST_DIR.is_dir():
        return closures
    cache: dict[str, set[str]] = {}
    for path in sorted(TEST_DIR.rglob("*.test.cpp")):
        if re.search(r"competitive-verifier:\s*IGNORE", path.read_text()):
            continue
        rel = path.relative_to(ROOT).as_posix()
        deps: set[str] = set()
        for hpp in get_dependencies(rel):
            deps.add(hpp)
            deps |= get_hpp_transitive_deps(hpp, cache)
        closures[rel] = deps
    return closures


def select_targets(changed: set[str], closures: dict[str, set[str]]) -> list[str]:
    """変わったヘッダを閉包に持つ test と、変わった test。

    どの test にも入らない変わったヘッダは、そのヘッダ自身を出す。
    """
    headers = {f for f in changed if f.startswith("mylib/") and f.endswith(".hpp")}
    targets: list[str] = []
    covered: set[str] = set()
    for test, deps in closures.items():
        if test in changed or deps & headers:
            targets.append(test)
            covered |= deps & headers
    targets.extend(sorted(headers - covered))
    return targets


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("base")
    parser.add_argument("head", nargs="?", default="HEAD")
    args = parser.parse_args()
    changed = changed_files(args.base, args.head)
    for target in select_targets(changed, test_closures()):
        print(target)


if __name__ == "__main__":
    main()
