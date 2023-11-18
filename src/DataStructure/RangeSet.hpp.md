---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0655.test.cpp
    title: test/aoj/0655.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1242.longdouble.test.cpp
    title: test/aoj/1242.longdouble.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1242.rational.test.cpp
    title: test/aoj/1242.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2880.test.cpp
    title: test/aoj/2880.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc182_e.test.cpp
    title: test/atcoder/abc182_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc194_e.test.cpp
    title: test/atcoder/abc194_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc214_e.test.cpp
    title: test/atcoder/abc214_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc228_d.test.cpp
    title: test/atcoder/abc228_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256_d.test.cpp
    title: test/atcoder/abc256_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/674.test.cpp
    title: test/yukicoder/674.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/RangeSet.hpp\"\n#include <iostream>\n\
    #include <set>\n#include <iterator>\n#include <limits>\n#include <cassert>\ntemplate\
    \ <class Int, bool merge= true> class RangeSet {\n struct ClosedSection {\n  Int\
    \ l, r;\n  Int length() const { return r - l + 1; }\n  bool operator<(const ClosedSection\
    \ &cs) const { return l < cs.l || (l == cs.l && r > cs.r); }\n  operator bool()\
    \ const { return l <= r; }\n  friend std::ostream &operator<<(std::ostream &os,\
    \ const ClosedSection &cs) { return cs ? os << \"[\" << cs.l << \",\" << cs.r\
    \ << \"]\" : os << \"\u2205\"; }\n };\n std::set<ClosedSection> mp;\npublic:\n\
    \ RangeSet() {\n  constexpr Int INF= std::numeric_limits<Int>::max() / 2;\n  mp.insert({INF,\
    \ INF}), mp.insert({-INF, -INF});\n }\n ClosedSection covered_by(Int l, Int r)\
    \ const {\n  assert(l <= r);\n  if (auto it= std::prev(mp.upper_bound(ClosedSection{l,\
    \ l})); it->l <= l && r <= it->r) return *it;\n  return {1, 0};\n }\n ClosedSection\
    \ covered_by(Int x) const { return covered_by(x, x); }\n ClosedSection covered_by(const\
    \ ClosedSection &cs) const { return covered_by(cs.l, cs.r); }\n size_t size()\
    \ const { return mp.size() - 2; }\n auto begin() const { return std::next(mp.begin());\
    \ }\n auto end() const { return std::prev(mp.end()); }\n Int insert(Int l, Int\
    \ r) {\n  assert(l <= r);\n  auto it= std::prev(mp.upper_bound(ClosedSection{l,\
    \ l}));\n  Int sum= 0, x= it->l, y= it->r;\n  if (x <= l && r <= y) return sum;\n\
    \  if (x <= l && l <= y + merge) sum+= y - (l= x) + 1, it= mp.erase(it);\n  else\
    \ std::advance(it, 1);\n  for (; it->r < r; it= mp.erase(it)) sum+= it->r - it->l\
    \ + 1;\n  if (x= it->l, y= it->r; x - merge <= r && r <= y) sum+= (r= y) - x +\
    \ 1, mp.erase(it);\n  return mp.insert({l, r}), r - l + 1 - sum;\n }\n Int insert(Int\
    \ x) { return insert(x, x); }\n Int insert(const ClosedSection &cs) { return insert(cs.l,\
    \ cs.r); }\n Int erase(Int l, Int r) {\n  assert(l <= r);\n  auto it= std::prev(mp.upper_bound(ClosedSection{l,\
    \ l}));\n  Int sum= 0, x= it->l, y= it->r;\n  if (x <= l && r <= y) {\n   if (mp.erase(it);\
    \ x < l) mp.insert({x, l - 1});\n   if (r < y) mp.insert({r + 1, y});\n   return\
    \ r - l + 1;\n  }\n  if (x <= l && l <= y) {\n   if (x < l) mp.insert({x, l -\
    \ 1});\n   sum+= y - l + 1, it= mp.erase(it);\n  } else std::advance(it, 1);\n\
    \  for (; it->r <= r; it= mp.erase(it)) sum+= it->r - it->l + 1;\n  if (x= it->l,\
    \ y= it->r; x <= r && r <= y)\n   if (sum+= r - x + 1, mp.erase(it); r < y) mp.insert({r\
    \ + 1, y});\n  return sum;\n }\n Int erase(Int x) { return erase(x, x); }\n Int\
    \ erase(const ClosedSection &cs) { return erase(cs.l, cs.r); }\n Int mex(Int x)\
    \ const {\n  auto cs= covered_by(x);\n  return cs ? cs.r + 1 : x;\n }\n friend\
    \ std::ostream &operator<<(std::ostream &os, const RangeSet &rs) {\n  os << \"\
    [\";\n  for (auto it= rs.begin(); it != rs.end(); ++it) os << (it == rs.begin()\
    \ ? \"\" : \",\") << *it;\n  return os << \"]\";\n }\n};\n"
  code: "#pragma once\n#include <iostream>\n#include <set>\n#include <iterator>\n\
    #include <limits>\n#include <cassert>\ntemplate <class Int, bool merge= true>\
    \ class RangeSet {\n struct ClosedSection {\n  Int l, r;\n  Int length() const\
    \ { return r - l + 1; }\n  bool operator<(const ClosedSection &cs) const { return\
    \ l < cs.l || (l == cs.l && r > cs.r); }\n  operator bool() const { return l <=\
    \ r; }\n  friend std::ostream &operator<<(std::ostream &os, const ClosedSection\
    \ &cs) { return cs ? os << \"[\" << cs.l << \",\" << cs.r << \"]\" : os << \"\u2205\
    \"; }\n };\n std::set<ClosedSection> mp;\npublic:\n RangeSet() {\n  constexpr\
    \ Int INF= std::numeric_limits<Int>::max() / 2;\n  mp.insert({INF, INF}), mp.insert({-INF,\
    \ -INF});\n }\n ClosedSection covered_by(Int l, Int r) const {\n  assert(l <=\
    \ r);\n  if (auto it= std::prev(mp.upper_bound(ClosedSection{l, l})); it->l <=\
    \ l && r <= it->r) return *it;\n  return {1, 0};\n }\n ClosedSection covered_by(Int\
    \ x) const { return covered_by(x, x); }\n ClosedSection covered_by(const ClosedSection\
    \ &cs) const { return covered_by(cs.l, cs.r); }\n size_t size() const { return\
    \ mp.size() - 2; }\n auto begin() const { return std::next(mp.begin()); }\n auto\
    \ end() const { return std::prev(mp.end()); }\n Int insert(Int l, Int r) {\n \
    \ assert(l <= r);\n  auto it= std::prev(mp.upper_bound(ClosedSection{l, l}));\n\
    \  Int sum= 0, x= it->l, y= it->r;\n  if (x <= l && r <= y) return sum;\n  if\
    \ (x <= l && l <= y + merge) sum+= y - (l= x) + 1, it= mp.erase(it);\n  else std::advance(it,\
    \ 1);\n  for (; it->r < r; it= mp.erase(it)) sum+= it->r - it->l + 1;\n  if (x=\
    \ it->l, y= it->r; x - merge <= r && r <= y) sum+= (r= y) - x + 1, mp.erase(it);\n\
    \  return mp.insert({l, r}), r - l + 1 - sum;\n }\n Int insert(Int x) { return\
    \ insert(x, x); }\n Int insert(const ClosedSection &cs) { return insert(cs.l,\
    \ cs.r); }\n Int erase(Int l, Int r) {\n  assert(l <= r);\n  auto it= std::prev(mp.upper_bound(ClosedSection{l,\
    \ l}));\n  Int sum= 0, x= it->l, y= it->r;\n  if (x <= l && r <= y) {\n   if (mp.erase(it);\
    \ x < l) mp.insert({x, l - 1});\n   if (r < y) mp.insert({r + 1, y});\n   return\
    \ r - l + 1;\n  }\n  if (x <= l && l <= y) {\n   if (x < l) mp.insert({x, l -\
    \ 1});\n   sum+= y - l + 1, it= mp.erase(it);\n  } else std::advance(it, 1);\n\
    \  for (; it->r <= r; it= mp.erase(it)) sum+= it->r - it->l + 1;\n  if (x= it->l,\
    \ y= it->r; x <= r && r <= y)\n   if (sum+= r - x + 1, mp.erase(it); r < y) mp.insert({r\
    \ + 1, y});\n  return sum;\n }\n Int erase(Int x) { return erase(x, x); }\n Int\
    \ erase(const ClosedSection &cs) { return erase(cs.l, cs.r); }\n Int mex(Int x)\
    \ const {\n  auto cs= covered_by(x);\n  return cs ? cs.r + 1 : x;\n }\n friend\
    \ std::ostream &operator<<(std::ostream &os, const RangeSet &rs) {\n  os << \"\
    [\";\n  for (auto it= rs.begin(); it != rs.end(); ++it) os << (it == rs.begin()\
    \ ? \"\" : \",\") << *it;\n  return os << \"]\";\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/RangeSet.hpp
  requiredBy: []
  timestamp: '2023-03-10 17:20:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/674.test.cpp
  - test/atcoder/abc214_e.test.cpp
  - test/atcoder/abc194_e.test.cpp
  - test/atcoder/abc182_e.test.cpp
  - test/atcoder/abc228_d.test.cpp
  - test/atcoder/abc256_d.test.cpp
  - test/aoj/1242.rational.test.cpp
  - test/aoj/1242.longdouble.test.cpp
  - test/aoj/0655.test.cpp
  - test/aoj/2880.test.cpp
documentation_of: src/DataStructure/RangeSet.hpp
layout: document
title: "\u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
---

## `ClosedSection` クラス
`pair<Int,Int>` みたいなもん. 閉区間  $\lbrack l, r\rbrack$ を表すクラス. \
メンバ変数 `l`, `r` を持っていてそれぞれ区間の左端，右端を表す. \
bool にキャストできて、valid (具体的には $l\gt r$) ならtrueを返す. \
メンバ関数 `length()` で 閉区間の長さを返す.

## メンバ関数

| 関数名                                                                            | 概要                                                                                                                                                                                    |
| --------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `RangeSet<Int,bool>()`                                                            | コンストラクタ. 内部で 番兵 [-inf, -inf], [inf, inf]を insertしてる. 第2テンプレート引数が true なら " [a,b], [b+1,c] を [a,c] にマージ " を行う. false ならしない. (デフォルトは true) |
| 1. `covered_by(l,r)`<br> 2. `covered_by(x)` <br>3. `covered_by(ClosedSection cs)` | (1. 閉区間 [l,r], 2. 点 x, 3. ClosedSection クラス )を包含する閉区間を返す. **存在しないなら invalid な閉区間 (具体的には [1, 0]) を返す.**                                             |
| 1. `insert(l,r)` <br> 2. `insert(x)` <br> 3. `insert(ClosedSection cs)`           | (1. 閉区間 [l,r], 2. 閉区間 [x,x], 3. ClosedSection クラス )を追加. 重なっているとこは合併           .                                                                                  |
| 1. `erase(l,r)` <br> 2. `erase(x)` <br> 3. `erase(ClosedSection cs)`              | (1. 閉区間 [l,r], 2. 閉区間 [x,x], 3. ClosedSection クラス ) 部分を削除.                                                                                                                |
| `size()`                                                                          | 管理してる閉区間の数を返す. (番兵は含まない)                                                                                                                                            |
| `begin()`                                                                         | 番兵は含まないようにしてる                                                                                                                                                              |
| `end()`                                                                           | 番兵は含まないようにしてる                                                                                                                                                              |
| `mex(x)`                                                                          | 管理してる閉区間に属さない x 以上の 最小の整数を返す                                                                                                                                    |


## 問題例
[HHKB プログラミングコンテスト 2020 C - Neq Min](https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c) \
[AtCoder Regular Contest 039 C - 幼稚園児高橋君](https://atcoder.jp/contests/arc039/tasks/arc039_c) \
[HackerRank Drawing Rectangles](https://www.hackerrank.com/contests/university-codesprint-4/challenges/drawing-rectangles)