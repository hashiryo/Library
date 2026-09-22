"""pr-syntax-targets.py の選び方。"""
import importlib.util
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
_spec = importlib.util.spec_from_file_location(
    "pr_syntax_targets", Path(__file__).resolve().parent.parent / "pr-syntax-targets.py"
)
_mod = importlib.util.module_from_spec(_spec)
assert _spec.loader is not None
_spec.loader.exec_module(_mod)
select_targets = _mod.select_targets


class TestSelectTargets(unittest.TestCase):
    closures = {
        "test/a.test.cpp": {"mylib/A.hpp", "mylib/internal/X.hpp"},
        "test/b.test.cpp": {"mylib/B.hpp"},
    }

    def test_a_changed_header_selects_the_tests_whose_closure_has_it(self):
        self.assertEqual(
            select_targets({"mylib/internal/X.hpp"}, self.closures), ["test/a.test.cpp"]
        )

    def test_a_changed_test_is_selected_itself(self):
        self.assertEqual(select_targets({"test/b.test.cpp"}, self.closures), ["test/b.test.cpp"])

    def test_a_header_no_test_uses_is_compiled_by_itself(self):
        self.assertEqual(
            select_targets({"mylib/Orphan.hpp"}, self.closures), ["mylib/Orphan.hpp"]
        )

    def test_without_tests_every_changed_header_is_a_target(self):
        self.assertEqual(
            select_targets({"mylib/B.hpp", "mylib/A.hpp", "README.md"}, {}),
            ["mylib/A.hpp", "mylib/B.hpp"],
        )

    def test_unrelated_changes_select_nothing(self):
        self.assertEqual(select_targets({"scripts/x.ts", "README.md"}, self.closures), [])


if __name__ == "__main__":
    unittest.main()
