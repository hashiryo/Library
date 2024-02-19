---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/old/LinearSystemIncidence.hpp\"\n#include <vector>\n\
    #include <tuple>\n#include <array>\n#include <cassert>\n#include <type_traits>\n\
    template <typename T> class LinearSystemIncidence {\n const int n;\n std::vector<std::array<int,\
    \ 2>> es;\npublic:\n LinearSystemIncidence(int n): n(n) {}\n void add_edge(int\
    \ src, int dst) { es.push_back({src, dst}); }\n std::vector<T> solve(std::vector<T>\
    \ b) const {\n  assert((int)b.size() == n);\n  const int m= es.size();\n  std::vector<T>\
    \ x(m);\n  std::vector<int> adj(m + m), pos(n + 1, 0);\n  for (auto [s, d]: es)\
    \ ++pos[s], ++pos[d];\n  for (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for\
    \ (int i= m; i--;) adj[--pos[es[i][0]]]= i, adj[--pos[es[i][1]]]= i;\n  std::vector<int>\
    \ pre(n, -2), ei(pos.begin(), pos.begin() + n);\n  for (int s= 0, p, e, q, f;\
    \ s < n; ++s)\n   if (pre[s] == -2)\n    for (pre[p= s]= -1;;) {\n     if (ei[p]\
    \ == pos[p + 1]) {\n      if (e= pre[p]; e < 0) {\n       if (b[p] != T()) return\
    \ {};  // no solution\n       break;\n      }\n      T tmp= b[p];\n      p= es[e][f=\
    \ (es[e][0] == p)];\n      if constexpr (std::is_same_v<T, bool>) x[e]= tmp, b[p]=\
    \ tmp ^ b[p];\n      else x[e]= f ? -tmp : tmp, b[p]+= tmp;\n     } else if (e=\
    \ adj[ei[p]++], q= es[e][es[e][0] == p]; pre[q] == -2) pre[p= q]= e;\n    }\n\
    \  return x;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <array>\n#include\
    \ <cassert>\n#include <type_traits>\ntemplate <typename T> class LinearSystemIncidence\
    \ {\n const int n;\n std::vector<std::array<int, 2>> es;\npublic:\n LinearSystemIncidence(int\
    \ n): n(n) {}\n void add_edge(int src, int dst) { es.push_back({src, dst}); }\n\
    \ std::vector<T> solve(std::vector<T> b) const {\n  assert((int)b.size() == n);\n\
    \  const int m= es.size();\n  std::vector<T> x(m);\n  std::vector<int> adj(m +\
    \ m), pos(n + 1, 0);\n  for (auto [s, d]: es) ++pos[s], ++pos[d];\n  for (int\
    \ i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (int i= m; i--;) adj[--pos[es[i][0]]]=\
    \ i, adj[--pos[es[i][1]]]= i;\n  std::vector<int> pre(n, -2), ei(pos.begin(),\
    \ pos.begin() + n);\n  for (int s= 0, p, e, q, f; s < n; ++s)\n   if (pre[s] ==\
    \ -2)\n    for (pre[p= s]= -1;;) {\n     if (ei[p] == pos[p + 1]) {\n      if\
    \ (e= pre[p]; e < 0) {\n       if (b[p] != T()) return {};  // no solution\n \
    \      break;\n      }\n      T tmp= b[p];\n      p= es[e][f= (es[e][0] == p)];\n\
    \      if constexpr (std::is_same_v<T, bool>) x[e]= tmp, b[p]= tmp ^ b[p];\n \
    \     else x[e]= f ? -tmp : tmp, b[p]+= tmp;\n     } else if (e= adj[ei[p]++],\
    \ q= es[e][es[e][0] == p]; pre[q] == -2) pre[p= q]= e;\n    }\n  return x;\n }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/old/LinearSystemIncidence.hpp
  requiredBy: []
  timestamp: '2024-02-19 22:51:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/LinearSystemIncidence.hpp
layout: document
title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
---
## 計算量
$\mathcal{O}(V+E)$
## 問題例
[AtCoder Beginner Contest 155 F - Perils in Parallel](https://atcoder.jp/contests/abc155/tasks/abc155_f) (sp judge)\
[AtCoder Grand Contest 035 B - Even Degrees ](https://atcoder.jp/contests/agc035/tasks/agc035_b) (sp judge)\
[CODE FESTIVAL 2017 Final E - Combination Lock](https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e)