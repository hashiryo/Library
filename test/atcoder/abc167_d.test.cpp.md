---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/FunctionalGraph.hpp
    title: "Functional\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc167/tasks/abc167_d
    links:
    - https://atcoder.jp/contests/abc167/tasks/abc167_d
  bundledCode: "#line 1 \"test/atcoder/abc167_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc167/tasks/abc167_d\"\
    \n#include <iostream>\n#line 2 \"src/Graph/HeavyLightDecomposition.hpp\"\n#include\
    \ <array>\n#include <cassert>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include\
    \ <vector>\n#line 4 \"src/Internal/ListRange.hpp\"\n#include <iterator>\n#include\
    \ <type_traits>\n#define _LR(name, IT, CT) \\\n template <class T> struct name\
    \ { \\\n  using Iterator= typename std::vector<T>::IT; \\\n  Iterator bg, ed;\
    \ \\\n  Iterator begin() const { return bg; } \\\n  Iterator end() const { return\
    \ ed; } \\\n  size_t size() const { return std::distance(bg, ed); } \\\n  CT &operator[](int\
    \ i) const { return bg[i]; } \\\n }\n_LR(ListRange, iterator, const T);\n_LR(ConstListRange,\
    \ const_iterator, const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n\
    \ std::vector<T> dat;\n std::vector<int> p;\n size_t size() const { return p.size()\
    \ - 1; }\n ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin()\
    \ + p[i + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int, int>\
    \ {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 5 \"src/Graph/HeavyLightDecomposition.hpp\"\
    \nclass HeavyLightDecomposition {\n std::vector<int> P, PP, D, I, L, R;\npublic:\n\
    \ HeavyLightDecomposition()= default;\n HeavyLightDecomposition(const Graph &g,\
    \ int root= 0): HeavyLightDecomposition(g.adjacency_vertex(0), root) {}\n HeavyLightDecomposition(const\
    \ CSRArray<int> &adj, int root= 0) {\n  const int n= adj.size();\n  P.assign(n,\
    \ -2), PP.resize(n), D.resize(n), I.resize(n), L.resize(n), R.resize(n);\n  auto\
    \ f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]= r; i <\
    \ t; ++i)\n    for (int u: adj[v= I[i]])\n     if (P[v] != u) P[I[t++]= u]= v;\n\
    \  };\n  f(root);\n  for (int r= 0; r < n; ++r)\n   if (P[r] == -2) f(r);\n  std::vector<int>\
    \ Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n   if (P[v= I[i]] == -1) continue;\n\
    \   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]= v;\n   if (Z[nx[P[v]]] < Z[v])\
    \ nx[P[v]]= v;\n  }\n  for (int v= n; v--;) PP[v]= v;\n  for (int v: I)\n   if\
    \ (nx[v] != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: adj[v])\n    if (u != P[v] && u\
    \ != nx[v]) L[u]= (ir-= Z[u]);\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n  }\n\
    \  for (int i= n; i--;) I[L[i]]= i;\n }\n int to_seq(int v) const { return L[v];\
    \ }\n int to_vertex(int i) const { return I[i]; }\n size_t size() const { return\
    \ P.size(); }\n int parent(int v) const { return P[v]; }\n int head(int v) const\
    \ { return PP[v]; }\n int root(int v) const {\n  for (v= PP[v];; v= PP[P[v]])\n\
    \   if (P[v] == -1) return v;\n }\n bool connected(int u, int v) const { return\
    \ root(u) == root(v); }\n // u is in v\n bool in_subtree(int u, int v) const {\
    \ return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return\
    \ R[v] - L[v]; }\n int lca(int u, int v) const {\n  for (;; v= P[PP[v]]) {\n \
    \  if (L[u] > L[v]) std::swap(u, v);\n   if (PP[u] == PP[v]) return u;\n  }\n\
    \ }\n int la(int v, int k) const {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v]\
    \ - L[u] + 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n\
    \ }\n int jump(int u, int v, int k) const {\n  if (!k) return u;\n  if (u == v)\
    \ return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v, D[v] - D[u] - 1) :\
    \ P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n  return k\
    \ > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n }\n int\
    \ depth(int v) const { return D[v]; }\n int dist(int u, int v) const { return\
    \ D[u] + D[v] - D[lca(u, v)] * 2; }\n // half-open interval\n std::array<int,\
    \ 2> subtree(int v) const { return std::array{L[v], R[v]}; }\n // sequence of\
    \ closed intervals\n template <bool edge= 0> std::vector<std::array<int, 2>> path(int\
    \ u, int v) const {\n  std::vector<std::array<int, 2>> up, down;\n  while (PP[u]\
    \ != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}),\
    \ v= P[PP[v]];\n   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n\
    \  }\n  if (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n \
    \ else if (L[v] + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n\
    \  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n};\n#line\
    \ 3 \"src/Graph/FunctionalGraph.hpp\"\nclass FunctionalGraph {\n std::vector<int>\
    \ t, rt;\n HeavyLightDecomposition hld;\npublic:\n FunctionalGraph(const std::vector<int>\
    \ &to): t(to) {\n  const int n= t.size();\n  rt.assign(n, -1);\n  for (int u,\
    \ w, v= n; v--;)\n   if (rt[v] == -1) {\n    for (rt[v]= -2, w= t[v];; rt[w]=\
    \ -2, w= t[w])\n     if (assert(0 <= w && w < n); rt[w] != -1) {\n      if (rt[w]\
    \ != -2) w= rt[w];\n      break;\n     }\n    for (u= v; rt[u] == -2; u= t[u])\
    \ rt[u]= w;\n   }\n  Graph g(n + 1, n);\n  for (int v= n; v--;) g[v]= {(rt[v]\
    \ == v ? n : t[v]), v};\n  hld= HeavyLightDecomposition(g.adjacency_vertex(1),\
    \ n);\n }\n template <class Int> std::enable_if_t<std::is_convertible_v<int, Int>,\
    \ int> jump(int v, Int k) const {\n  int n= t.size(), d= hld.depth(v) - 1;\n \
    \ if (k <= d) return hld.jump(v, n, (int)k);\n  int b= t[v= rt[v]], l= (k-= d)\
    \ % hld.depth(b);\n  if (l == 0) return v;\n  return hld.jump(b, n, l - 1);\n\
    \ }\n // ((a_0,...,a_{i-1}) x 1, (a_i,...,a_{j-1}) x loop_num, (a_j,...,a_m) x\
    \ 1)\n template <class Int> std::enable_if_t<std::is_convertible_v<int, Int>,\
    \ std::array<std::pair<std::vector<int>, Int>, 3>> path(int v, Int k) const {\n\
    \  std::array<std::pair<std::vector<int>, Int>, 3> ret;\n  int d= hld.depth(v)\
    \ - 1;\n  if (ret[0].second= 1; k <= d) {\n   for (int e= k; e--; v= t[v]) ret[0].first.push_back(v);\n\
    \   return ret;\n  }\n  for (int e= d; e--; v= t[v]) ret[0].first.push_back(v);\n\
    \  int b= t[v= rt[v]], c= hld.depth(b), l= (k-= d) % c;\n  ret[1].second= k /\
    \ c, ret[2].second= 1;\n  for (int e= c; e--; v= t[v]) ret[1].first.push_back(v);\n\
    \  for (int e= l; e--; v= t[v]) ret[2].first.push_back(v);\n  return ret;\n }\n\
    };\n#line 4 \"test/atcoder/abc167_d.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n long long K;\n cin >>\
    \ N >> K;\n vector<int> A(N);\n for (int i= 0; i < N; ++i) cin >> A[i], --A[i];\n\
    \ cout << FunctionalGraph(A).jump(0, K) + 1 << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc167/tasks/abc167_d\"\n#include\
    \ <iostream>\n#include \"src/Graph/FunctionalGraph.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n long long\
    \ K;\n cin >> N >> K;\n vector<int> A(N);\n for (int i= 0; i < N; ++i) cin >>\
    \ A[i], --A[i];\n cout << FunctionalGraph(A).jump(0, K) + 1 << '\\n';\n return\
    \ 0;\n}"
  dependsOn:
  - src/Graph/FunctionalGraph.hpp
  - src/Graph/HeavyLightDecomposition.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: true
  path: test/atcoder/abc167_d.test.cpp
  requiredBy: []
  timestamp: '2024-02-19 02:01:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc167_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc167_d.test.cpp
- /verify/test/atcoder/abc167_d.test.cpp.html
title: test/atcoder/abc167_d.test.cpp
---
