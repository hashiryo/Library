---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/RangeSet.hpp
    title: "\u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc194/tasks/abc194_e
    links:
    - https://atcoder.jp/contests/abc194/tasks/abc194_e
  bundledCode: "#line 1 \"test/atcoder/abc194_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc194/tasks/abc194_e\"\
    \n#include <iostream>\n#include <algorithm>\n#line 3 \"src/DataStructure/RangeSet.hpp\"\
    \n#include <set>\n#include <iterator>\n#include <limits>\n#include <cassert>\n\
    template <class Int, bool merge= true> class RangeSet {\n struct ClosedSection\
    \ {\n  Int l, r;\n  Int length() const { return r - l + 1; }\n  bool operator<(const\
    \ ClosedSection &cs) const { return l < cs.l || (l == cs.l && r > cs.r); }\n \
    \ operator bool() const { return l <= r; }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ClosedSection &cs) { return cs ? os << \"[\" << cs.l << \",\" <<\
    \ cs.r << \"]\" : os << \"\u2205\"; }\n };\n std::set<ClosedSection> mp;\npublic:\n\
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
    \ ? \"\" : \",\") << *it;\n  return os << \"]\";\n }\n};\n#line 5 \"test/atcoder/abc194_e.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n int A[N];\n for (int i= 0; i < N; ++i) cin >> A[i];\n\
    \ RangeSet<int> rs;\n int cnt[N];\n fill_n(cnt, N, 0);\n int r= 0;\n for (; r\
    \ < M; ++r) rs.insert(A[r]), ++cnt[A[r]];\n int ans= rs.mex(0);\n for (int l=\
    \ 0; r < N; ++l, ++r) {\n  if (--cnt[A[l]] == 0) rs.erase(A[l]);\n  if (cnt[A[r]]++\
    \ == 0) rs.insert(A[r]);\n  ans= min(ans, rs.mex(0));\n }\n cout << ans << '\\\
    n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc194/tasks/abc194_e\"\n#include\
    \ <iostream>\n#include <algorithm>\n#include \"src/DataStructure/RangeSet.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n int A[N];\n for (int i= 0; i < N; ++i) cin >> A[i];\n\
    \ RangeSet<int> rs;\n int cnt[N];\n fill_n(cnt, N, 0);\n int r= 0;\n for (; r\
    \ < M; ++r) rs.insert(A[r]), ++cnt[A[r]];\n int ans= rs.mex(0);\n for (int l=\
    \ 0; r < N; ++l, ++r) {\n  if (--cnt[A[l]] == 0) rs.erase(A[l]);\n  if (cnt[A[r]]++\
    \ == 0) rs.insert(A[r]);\n  ans= min(ans, rs.mex(0));\n }\n cout << ans << '\\\
    n';\n return 0;\n}"
  dependsOn:
  - src/DataStructure/RangeSet.hpp
  isVerificationFile: true
  path: test/atcoder/abc194_e.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 17:20:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc194_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc194_e.test.cpp
- /verify/test/atcoder/abc194_e.test.cpp.html
title: test/atcoder/abc194_e.test.cpp
---
