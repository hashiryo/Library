---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/RangeSet.hpp
    title: "\u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
  - icon: ':question:'
    path: src/Graph/BipartiteMatching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/contests/university-codesprint-4/challenges/drawing-rectangles
    links:
    - https://www.hackerrank.com/contests/university-codesprint-4/challenges/drawing-rectangles
  bundledCode: "#line 1 \"test/hackerrank/drawing-rectangles.test.cpp\"\n#define PROBLEM\
    \ \"https://www.hackerrank.com/contests/university-codesprint-4/challenges/drawing-rectangles\"\
    \n#include <iostream>\n#include <vector>\n#line 3 \"src/Graph/BipartiteMatching.hpp\"\
    \n#include <array>\n#include <algorithm>\n#include <cassert>\nclass BipartiteMatching\
    \ {\n std::vector<std::array<int, 2>> es;\n std::vector<int> lmate, rmate, rt;\n\
    public:\n BipartiteMatching() {}\n BipartiteMatching(int L, int R): lmate(L, -1),\
    \ rmate(R, -1) {}\n void add_edge(int l, int r) { es.push_back({l, r}); }\n void\
    \ erase_edge(int l, int r) {\n  auto it= std::find(es.begin(), es.end(), std::array{l,\
    \ r});\n  if (assert(it != es.end()), es.erase(it); lmate[l] == r) lmate[l]= rmate[r]=\
    \ -1;\n }\n template <bool lex= false> void build() {\n  const int n= lmate.size();\n\
    \  std::vector<int> g(es.size()), pos(n + 1), pre, que(n);\n  if constexpr (lex)\
    \ std::sort(es.rbegin(), es.rend());\n  for (auto [l, r]: es) ++pos[l];\n  for\
    \ (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (auto [l, r]: es) g[--pos[l]]=\
    \ r;\n  for (bool upd= true; upd;) {\n   upd= false, rt.assign(n, -1), pre.assign(n,\
    \ -1);\n   int t= 0;\n   for (int l= n; l--;)\n    if (lmate[l] == -1) que[t++]=\
    \ rt[l]= pre[l]= l;\n   for (int i= 0; i < t; ++i)\n    if (int l= que[i]; lmate[rt[l]]\
    \ == -1)\n     for (int j= pos[l], r, nl; j < pos[l + 1]; ++j) {\n      if (nl=\
    \ rmate[r= g[j]]; nl == -1) {\n       for (upd= true; r != -1; l= pre[l]) rmate[r]=\
    \ l, std::swap(lmate[l], r);\n       break;\n      }\n      if (pre[nl] == -1)\
    \ rt[que[t++]= nl]= rt[pre[nl]= l];\n     }\n  }\n  if constexpr (lex) {\n   std::vector<char>\
    \ alive(n, 1);\n   for (int v= 0, l, r; v < n; ++v)\n    if (int u= lmate[v];\
    \ u != -1) {\n     for (pre.assign(n, lmate[v]= rmate[u]= -1), pre[l= v]= -2,\
    \ que.assign(pos.begin(), pos.begin() + n);;) {\n      if (que[l] == pos[l + 1])\
    \ l= pre[l];\n      else if (r= g[que[l]++], u= rmate[r]; u == -1) {\n       for\
    \ (; r != -1; l= pre[l]) rmate[r]= l, std::swap(lmate[l], r);\n       break;\n\
    \      } else if (alive[u] && pre[u] == -1) pre[u]= l, l= u;\n     }\n     alive[v]=\
    \ 0;\n    }\n  }\n }\n inline size_t left_size() const { return lmate.size();\
    \ }\n inline size_t right_size() const { return rmate.size(); }\n inline int l_to_r(int\
    \ l) const { return lmate[l]; }\n inline int r_to_l(int r) const { return rmate[r];\
    \ }\n std::vector<std::array<int, 2>> edges() const { return es; }\n std::vector<std::array<int,\
    \ 2>> max_matching() const {\n  std::vector<std::array<int, 2>> ret;\n  for (int\
    \ l= 0, n= lmate.size(); l < n; ++l)\n   if (int r= lmate[l]; r != -1) ret.push_back({l,\
    \ r});\n  return ret;\n }\n bool used_as_vertex_cover_left(int l) const { return\
    \ rt[l] == -1; }\n bool used_as_vertex_cover_right(int r) const { return r= rmate[r],\
    \ r != -1 && rt[r] != -1; }\n};\n#line 3 \"src/DataStructure/RangeSet.hpp\"\n\
    #include <set>\n#include <iterator>\n#include <limits>\n#line 7 \"src/DataStructure/RangeSet.hpp\"\
    \ntemplate <class Int, bool merge= true> class RangeSet {\n struct ClosedSection\
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
    \ ? \"\" : \",\") << *it;\n  return os << \"]\";\n }\n};\n#line 6 \"test/hackerrank/drawing-rectangles.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ static constexpr int N= 300'001;\n BipartiteMatching bm(N, N);\n int n;\n cin\
    \ >> n;\n vector<RangeSet<int>> ys(N);\n for (int i= 0; i < n; ++i) {\n  int x1,\
    \ y1, x2, y2;\n  cin >> x1 >> y1 >> x2 >> y2;\n  for (int x= x1; x <= x2; ++x)\
    \ ys[x].insert(y1, y2);\n }\n for (int x= 0; x < N; ++x)\n  for (auto [y1, y2]:\
    \ ys[x])\n   for (int y= y1; y <= y2; ++y) bm.add_edge(x, y);\n bm.build();\n\
    \ vector<int> l, r;\n for (int i= 0; i < N; ++i)\n  if (bm.used_as_vertex_cover_left(i))\
    \ l.push_back(i);\n for (int i= 0; i < N; ++i)\n  if (bm.used_as_vertex_cover_right(i))\
    \ r.push_back(i);\n int L= l.size(), R= r.size();\n cout << L + R << '\\n';\n\
    \ cout << L << '\\n';\n for (int i= 0; i < L; ++i) cout << (i ? \" \" : \"\")\
    \ << l[i];\n cout << '\\n';\n cout << R << '\\n';\n for (int i= 0; i < R; ++i)\
    \ cout << (i ? \" \" : \"\") << r[i];\n cout << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/contests/university-codesprint-4/challenges/drawing-rectangles\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/Graph/BipartiteMatching.hpp\"\
    \n#include \"src/DataStructure/RangeSet.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n static constexpr int N= 300'001;\n\
    \ BipartiteMatching bm(N, N);\n int n;\n cin >> n;\n vector<RangeSet<int>> ys(N);\n\
    \ for (int i= 0; i < n; ++i) {\n  int x1, y1, x2, y2;\n  cin >> x1 >> y1 >> x2\
    \ >> y2;\n  for (int x= x1; x <= x2; ++x) ys[x].insert(y1, y2);\n }\n for (int\
    \ x= 0; x < N; ++x)\n  for (auto [y1, y2]: ys[x])\n   for (int y= y1; y <= y2;\
    \ ++y) bm.add_edge(x, y);\n bm.build();\n vector<int> l, r;\n for (int i= 0; i\
    \ < N; ++i)\n  if (bm.used_as_vertex_cover_left(i)) l.push_back(i);\n for (int\
    \ i= 0; i < N; ++i)\n  if (bm.used_as_vertex_cover_right(i)) r.push_back(i);\n\
    \ int L= l.size(), R= r.size();\n cout << L + R << '\\n';\n cout << L << '\\n';\n\
    \ for (int i= 0; i < L; ++i) cout << (i ? \" \" : \"\") << l[i];\n cout << '\\\
    n';\n cout << R << '\\n';\n for (int i= 0; i < R; ++i) cout << (i ? \" \" : \"\
    \") << r[i];\n cout << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/BipartiteMatching.hpp
  - src/DataStructure/RangeSet.hpp
  isVerificationFile: true
  path: test/hackerrank/drawing-rectangles.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 17:20:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/hackerrank/drawing-rectangles.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/drawing-rectangles.test.cpp
- /verify/test/hackerrank/drawing-rectangles.test.cpp.html
title: test/hackerrank/drawing-rectangles.test.cpp
---
