---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/BipartiteMatching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include <iostream>\n\
    #line 2 \"src/Graph/BipartiteMatching.hpp\"\n#include <vector>\n#include <array>\n\
    #include <algorithm>\n#include <cassert>\nclass BipartiteMatching {\n std::vector<std::array<int,\
    \ 2>> es;\n std::vector<int> lmate, rmate, rt;\npublic:\n BipartiteMatching()\
    \ {}\n BipartiteMatching(int L, int R): lmate(L, -1), rmate(R, -1) {}\n void add_edge(int\
    \ l, int r) { es.push_back({l, r}); }\n void erase_edge(int l, int r) {\n  auto\
    \ it= std::find(es.begin(), es.end(), std::array{l, r});\n  if (assert(it != es.end()),\
    \ es.erase(it); lmate[l] == r) lmate[l]= rmate[r]= -1;\n }\n template <bool lex=\
    \ false> void build() {\n  const int n= lmate.size();\n  std::vector<int> g(es.size()),\
    \ pos(n + 1), pre, que(n);\n  if constexpr (lex) std::sort(es.rbegin(), es.rend());\n\
    \  for (auto [l, r]: es) ++pos[l];\n  for (int i= 0; i < n; ++i) pos[i + 1]+=\
    \ pos[i];\n  for (auto [l, r]: es) g[--pos[l]]= r;\n  for (bool upd= true; upd;)\
    \ {\n   upd= false, rt.assign(n, -1), pre.assign(n, -1);\n   int t= 0;\n   for\
    \ (int l= n; l--;)\n    if (lmate[l] == -1) que[t++]= rt[l]= pre[l]= l;\n   for\
    \ (int i= 0; i < t; ++i)\n    if (int l= que[i]; lmate[rt[l]] == -1)\n     for\
    \ (int j= pos[l], r, nl; j < pos[l + 1]; ++j) {\n      if (nl= rmate[r= g[j]];\
    \ nl == -1) {\n       for (upd= true; r != -1; l= pre[l]) rmate[r]= l, std::swap(lmate[l],\
    \ r);\n       break;\n      }\n      if (pre[nl] == -1) rt[que[t++]= nl]= rt[pre[nl]=\
    \ l];\n     }\n  }\n  if constexpr (lex) {\n   std::vector<char> alive(n, 1);\n\
    \   for (int v= 0, l, r; v < n; ++v)\n    if (int u= lmate[v]; u != -1) {\n  \
    \   for (pre.assign(n, lmate[v]= rmate[u]= -1), pre[l= v]= -2, que.assign(pos.begin(),\
    \ pos.begin() + n);;) {\n      if (que[l] == pos[l + 1]) l= pre[l];\n      else\
    \ if (r= g[que[l]++], u= rmate[r]; u == -1) {\n       for (; r != -1; l= pre[l])\
    \ rmate[r]= l, std::swap(lmate[l], r);\n       break;\n      } else if (alive[u]\
    \ && pre[u] == -1) pre[u]= l, l= u;\n     }\n     alive[v]= 0;\n    }\n  }\n }\n\
    \ inline size_t left_size() const { return lmate.size(); }\n inline size_t right_size()\
    \ const { return rmate.size(); }\n inline int l_to_r(int l) const { return lmate[l];\
    \ }\n inline int r_to_l(int r) const { return rmate[r]; }\n std::vector<std::array<int,\
    \ 2>> edges() const { return es; }\n std::vector<std::array<int, 2>> max_matching()\
    \ const {\n  std::vector<std::array<int, 2>> ret;\n  for (int l= 0, n= lmate.size();\
    \ l < n; ++l)\n   if (int r= lmate[l]; r != -1) ret.push_back({l, r});\n  return\
    \ ret;\n }\n bool used_as_vertex_cover_left(int l) const { return rt[l] == -1;\
    \ }\n bool used_as_vertex_cover_right(int r) const { return r= rmate[r], r !=\
    \ -1 && rt[r] != -1; }\n};\n#line 4 \"test/yosupo/bipartitematching.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int L, R, M;\n cin >> L >> R >> M;\n BipartiteMatching bm(L, R);\n while (M--)\
    \ {\n  int a, b;\n  cin >> a >> b;\n  bm.add_edge(a, b);\n }\n bm.build();\n auto\
    \ ans= bm.max_matching();\n cout << ans.size() << '\\n';\n for (auto [l, r]: ans)\
    \ cout << l << \" \" << r << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <iostream>\n#include \"src/Graph/BipartiteMatching.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int L, R, M;\n cin\
    \ >> L >> R >> M;\n BipartiteMatching bm(L, R);\n while (M--) {\n  int a, b;\n\
    \  cin >> a >> b;\n  bm.add_edge(a, b);\n }\n bm.build();\n auto ans= bm.max_matching();\n\
    \ cout << ans.size() << '\\n';\n for (auto [l, r]: ans) cout << l << \" \" <<\
    \ r << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/BipartiteMatching.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 17:02:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
