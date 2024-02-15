---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/arc106_b.test.cpp
    title: test/atcoder/arc106_b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <iterator>\n#include <type_traits>\n#define _LR(name, IT,\
    \ CT) \\\n template <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT;\
    \ \\\n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
    \ end() const { return ed; } \\\n  size_t size() const { return std::distance(bg,\
    \ ed); } \\\n  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange,\
    \ iterator, const T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\n\
    template <class T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int>\
    \ p;\n size_t size() const { return p.size() - 1; }\n ListRange<T> operator[](int\
    \ i) { return {dat.begin() + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T>\
    \ operator[](int i) const { return {dat.cbegin() + p[i], dat.cbegin() + p[i +\
    \ 1]}; }\n};\ntemplate <template <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
    \ ListRange<T>>, std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>,\
    \ std::ostream &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n\
    \ for (int _= 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n\
    \ return os << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge {\n int s,\
    \ d;\n Edge(int s= 0, int d= 0): s(s), d(d) {}\n Edge &operator--() { return --s,\
    \ --d, *this; }\n int to(int u) const { return u ^ s ^ d; }\n bool operator<(const\
    \ Edge &e) const { return s != e.s ? s < e.s : d < e.d; }\n friend std::istream\
    \ &operator>>(std::istream &is, Edge &e) { return is >> e.s >> e.d, is; }\n friend\
    \ std::ostream &operator<<(std::ostream &os, const Edge &e) { return os << '('\
    \ << e.s << \", \" << e.d << ')'; }\n};\nstruct Graph: public std::vector<Edge>\
    \ {\n size_t n;\n Graph(size_t n= 0, size_t m= 0): vector(m), n(n) {}\n size_t\
    \ vertex_size() const { return n; }\n size_t edge_size() const { return size();\
    \ }\n int add_vertex() { return n++; }\n int add_edge(int s, int d) { return emplace_back(s,\
    \ d), size() - 1; }\n int add_edge(Edge e) { return add_edge(e.s, e.d); }\n#define\
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (size_t i= 0; i < n;\
    \ ++i) p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) b;\n#define _ADJ(a, b)\
    \ \\\n vector<int> p(n + 1), c(size() << !direct); \\\n if (direct) { \\\n  _ADJ_FOR(++p[u],\
    \ c[--p[(*this)[i].s]]= a) \\\n } else { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[(*this)[i].s]]=\
    \ a, c[--p[(*this)[i].d]]= b)) \\\n } \\\n return {std::move(c), std::move(p)}\n\
    \ CSRArray<int> adjacency_vertex(bool direct) const { _ADJ((*this)[i].d, (*this)[i].s);\
    \ }\n CSRArray<int> adjacency_edge(bool direct) const { _ADJ(i, i); }\n#undef\
    \ _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"src/Graph/incidence_linear_system.hpp\"\
    \ntemplate <class T> std::vector<T> incidence_linear_system(const Graph &g, std::vector<T>\
    \ b) {\n const int n= g.vertex_size();\n assert((int)b.size() == n);\n std::vector<T>\
    \ x(g.edge_size());\n auto adje= g.adjecency_edge(0);\n std::vector<int> pre(n,\
    \ -2), ei(adje.p.begin(), adje.p.begin() + n);\n for (int s= 0, p, e; s < n; ++s)\n\
    \  if (pre[s] == -2)\n   for (pre[p= s]= -1;;) {\n    if (ei[p] == adje.p[p +\
    \ 1]) {\n     if (e= pre[p]; e < 0) {\n      if (b[p] != T()) return {};  // no\
    \ solution\n      break;\n     }\n     T tmp= b[p];\n     p= g[e].to(p);\n   \
    \  if constexpr (std::is_same_v<T, bool>) x[e]= tmp, b[p]= tmp ^ b[p];\n     else\
    \ x[e]= g[e].d == p ? -tmp : tmp, b[p]+= tmp;\n    } else if (int q= g[e= adje.dat[ei[p]++]].to(p);\
    \ pre[q] == -2) pre[p= q]= e;\n   }\n return x;\n}\n"
  code: "#pragma once\n#include \"src/Graph/Graph.hpp\"\ntemplate <class T> std::vector<T>\
    \ incidence_linear_system(const Graph &g, std::vector<T> b) {\n const int n= g.vertex_size();\n\
    \ assert((int)b.size() == n);\n std::vector<T> x(g.edge_size());\n auto adje=\
    \ g.adjecency_edge(0);\n std::vector<int> pre(n, -2), ei(adje.p.begin(), adje.p.begin()\
    \ + n);\n for (int s= 0, p, e; s < n; ++s)\n  if (pre[s] == -2)\n   for (pre[p=\
    \ s]= -1;;) {\n    if (ei[p] == adje.p[p + 1]) {\n     if (e= pre[p]; e < 0) {\n\
    \      if (b[p] != T()) return {};  // no solution\n      break;\n     }\n   \
    \  T tmp= b[p];\n     p= g[e].to(p);\n     if constexpr (std::is_same_v<T, bool>)\
    \ x[e]= tmp, b[p]= tmp ^ b[p];\n     else x[e]= g[e].d == p ? -tmp : tmp, b[p]+=\
    \ tmp;\n    } else if (int q= g[e= adje.dat[ei[p]++]].to(p); pre[q] == -2) pre[p=\
    \ q]= e;\n   }\n return x;\n}"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/incidence_linear_system.hpp
  requiredBy: []
  timestamp: '2024-02-15 23:40:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/arc106_b.test.cpp
documentation_of: src/Graph/incidence_linear_system.hpp
layout: document
title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
---

|関数名|概要|計算量|
|---|---|---|
|`incidence_linear_system<T>(g, b)`|有向グラフ $g$ の接続行列 $A$ と頂点数 $n$ の次元を持つベクトル $\boldsymbol{b}$ に対して <br> $\displaystyle A\boldsymbol{x}=\boldsymbol{b}$<br>を満たす辺数 $m$ の次元を持つベクトル $\boldsymbol{x}$ を一つ返す. <br> 解なしなら空集合を返す.|$O(n+m)$|

## 問題例
[AtCoder Beginner Contest 155 F - Perils in Parallel](https://atcoder.jp/contests/abc155/tasks/abc155_f) (sp judge)\
[AtCoder Grand Contest 035 B - Even Degrees ](https://atcoder.jp/contests/agc035/tasks/agc035_b) (sp judge)\
[CODE FESTIVAL 2017 Final E - Combination Lock](https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e)