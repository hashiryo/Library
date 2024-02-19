---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\n#include <algorithm>\n\
    #line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include <iostream>\n\
    #include <iterator>\n#include <type_traits>\n#define _LR(name, IT, CT) \\\n template\
    \ <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT; \\\
    \n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
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
    \ return os << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int,\
    \ int> {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
    \ --second, *this; }\n int to(int v) const { return first ^ second ^ v; }\n friend\
    \ std::istream &operator>>(std::istream &is, Edge &e) { return is >> e.first >>\
    \ e.second, is; }\n};\nstruct Graph: std::vector<Edge> {\n size_t n;\n Graph(size_t\
    \ n= 0, size_t m= 0): vector(m), n(n) {}\n size_t vertex_size() const { return\
    \ n; }\n size_t edge_size() const { return size(); }\n size_t add_vertex() { return\
    \ n++; }\n size_t add_edge(int s, int d) { return emplace_back(s, d), size() -\
    \ 1; }\n size_t add_edge(Edge e) { return emplace_back(e), size() - 1; }\n#define\
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (size_t i= 0; i < n;\
    \ ++i) p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) { \\\n  auto [u, v]= (*this)[i];\
    \ \\\n  b; \\\n }\n#define _ADJ(a, b) \\\n vector<int> p(n + 1), c(size() << !dir);\
    \ \\\n if (!dir) { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[u]]= a, c[--p[v]]=\
    \ b)) \\\n } else if (dir > 0) { \\\n  _ADJ_FOR(++p[u], c[--p[u]]= a) \\\n } else\
    \ { \\\n  _ADJ_FOR(++p[v], c[--p[v]]= b) \\\n } \\\n return {c, p}\n CSRArray<int>\
    \ adjacency_vertex(int dir) const { _ADJ(v, u); }\n CSRArray<int> adjacency_edge(int\
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 4 \"src/Graph/StronglyConnectedComponents.hpp\"\
    \nclass StronglyConnectedComponents {\n std::vector<int> m, q, b;\npublic:\n StronglyConnectedComponents(const\
    \ Graph &g) {\n  const int n= g.vertex_size();\n  m.assign(n, -2), b.resize(n);\n\
    \  {\n   auto adj= g.adjacency_vertex(1);\n   std::vector<int> c(adj.p.begin(),\
    \ adj.p.begin() + n);\n   for (int s= 0, k= n, p; s < n; ++s)\n    if (m[s] ==\
    \ -2)\n     for (m[p= s]= -1; p >= 0;) {\n      if (c[p] == adj.p[p + 1]) b[--k]=\
    \ p, p= m[p];\n      else if (int w= adj.dat[c[p]++]; m[w] == -2) m[w]= p, p=\
    \ w;\n     }\n  }\n  auto adj= g.adjacency_vertex(-1);\n  std::vector<char> z(n);\n\
    \  int k= 0, p= 0;\n  q= {0};\n  for (int s: b)\n   if (!z[s]) {\n    for (z[m[k++]=\
    \ s]= 1; p < k; ++p)\n     for (int u: adj[m[p]])\n      if (!z[u]) z[m[k++]=\
    \ u]= 1;\n    q.push_back(k);\n   }\n  for (int i= q.size() - 1; i--;)\n   while\
    \ (k > q[i]) b[m[--k]]= i;\n }\n size_t size() const { return q.size() - 1; }\n\
    \ ConstListRange<int> block(int k) const { return {m.cbegin() + q[k], m.cbegin()\
    \ + q[k + 1]}; }\n int operator()(int i) const { return b[i]; }\n Graph dag(const\
    \ Graph &g) const {\n  Graph ret(size());\n  for (auto [s, d]: g)\n   if (b[s]\
    \ != b[d]) ret.add_edge(b[s], b[d]);\n  return std::sort(ret.begin(), ret.end()),\
    \ ret.erase(std::unique(ret.begin(), ret.end()), ret.end()), ret;\n }\n};\n#line\
    \ 3 \"src/Math/TwoSatisfiability.hpp\"\nclass TwoSatisfiability {\n int n;\n Graph\
    \ g;\n inline int neg(int x) const { return x >= n ? x - n : x + n; }\npublic:\n\
    \ TwoSatisfiability(int n): n(n), g(n + n) {}\n void add_if(int u, int v) { g.add_edge(u,\
    \ v), g.add_edge(neg(v), neg(u)); }  // u -> v <=> !v -> !u\n void add_or(int\
    \ u, int v) { add_if(neg(u), v); }                             // u or v <=> !u\
    \ -> v\n void add_nand(int u, int v) { add_if(u, neg(v)); }                  \
    \         // u nand v <=> u -> !v\n void set_true(int u) { g.add_edge(neg(u),\
    \ u); }                              // u <=> !u -> u\n void set_false(int u)\
    \ { g.add_edge(u, neg(u)); }                             // !u <=> u -> !u\n std::vector<bool>\
    \ solve() {\n  StronglyConnectedComponents scc(g);\n  std::vector<bool> ret(n);\n\
    \  for (int i= 0, l, r; i<n; ret[i++]= l> r)\n   if (l= scc(i), r= scc(neg(i));\
    \ l == r) return {};  // no solution\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include \"src/Graph/StronglyConnectedComponents.hpp\"\nclass\
    \ TwoSatisfiability {\n int n;\n Graph g;\n inline int neg(int x) const { return\
    \ x >= n ? x - n : x + n; }\npublic:\n TwoSatisfiability(int n): n(n), g(n + n)\
    \ {}\n void add_if(int u, int v) { g.add_edge(u, v), g.add_edge(neg(v), neg(u));\
    \ }  // u -> v <=> !v -> !u\n void add_or(int u, int v) { add_if(neg(u), v); }\
    \                             // u or v <=> !u -> v\n void add_nand(int u, int\
    \ v) { add_if(u, neg(v)); }                           // u nand v <=> u -> !v\n\
    \ void set_true(int u) { g.add_edge(neg(u), u); }                            \
    \  // u <=> !u -> u\n void set_false(int u) { g.add_edge(u, neg(u)); }       \
    \                      // !u <=> u -> !u\n std::vector<bool> solve() {\n  StronglyConnectedComponents\
    \ scc(g);\n  std::vector<bool> ret(n);\n  for (int i= 0, l, r; i<n; ret[i++]=\
    \ l> r)\n   if (l= scc(i), r= scc(neg(i)); l == r) return {};  // no solution\n\
    \  return ret;\n }\n};"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Math/TwoSatisfiability.hpp
  requiredBy: []
  timestamp: '2024-02-19 13:27:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: src/Math/TwoSatisfiability.hpp
layout: document
title: 2-SAT
---
強連結成分分解を用いる \
solve():真偽値の割当を返す(充足不可能なら空)