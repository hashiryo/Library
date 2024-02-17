---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/WaveletMatrix.hpp
    title: "Wavelet\u884C\u5217"
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
    PROBLEM: https://atcoder.jp/contests/abc202/tasks/abc202_e
    links:
    - https://atcoder.jp/contests/abc202/tasks/abc202_e
  bundledCode: "#line 1 \"test/atcoder/abc202_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_e\"\
    \n#include <iostream>\n#include <vector>\n#line 4 \"src/Internal/ListRange.hpp\"\
    \n#include <iterator>\n#include <type_traits>\n#define _LR(name, IT, CT) \\\n\
    \ template <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT;\
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
    \ return os << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int,\
    \ int> {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
    \ --second, *this; }\n int to(int v) const { return first ^ second ^ v; }\n friend\
    \ std::istream &operator>>(std::istream &is, Edge &e) { return is >> e.first >>\
    \ e.second, is; }\n};\nstruct Graph: std::vector<Edge> {\n size_t n;\n Graph(size_t\
    \ n= 0, size_t m= 0): n(n), vector(m) {}\n size_t vertex_size() const { return\
    \ n; }\n size_t edge_size() const { return size(); }\n size_t add_vertex() { return\
    \ n++; }\n size_t add_edge(int s, int d) { return emplace_back(s, d), size() -\
    \ 1; }\n size_t add_edge(Edge e) { return emplace_back(e), size() - 1; }\n#define\
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (int i= 0; i < n; ++i)\
    \ p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) b;\n#define _ADJ(a, b) \\\n\
    \ vector<int> p(n + 1), c(size() << !direct); \\\n if (direct) { \\\n  _ADJ_FOR(++p[u],\
    \ c[--p[(*this)[i].first]]= a) \\\n } else { \\\n  _ADJ_FOR((++p[u], ++p[v]),\
    \ (c[--p[(*this)[i].first]]= a, c[--p[(*this)[i].second]]= b)) \\\n } \\\n return\
    \ {std::move(c), std::move(p)}\n CSRArray<int> adjacency_vertex(bool direct) const\
    \ { _ADJ((*this)[i].second, (*this)[i].first); }\n CSRArray<int> adjacency_edge(bool\
    \ direct) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 2 \"\
    src/Graph/HeavyLightDecomposition.hpp\"\n#include <array>\n#include <cassert>\n\
    #line 5 \"src/Graph/HeavyLightDecomposition.hpp\"\nclass HeavyLightDecomposition\
    \ {\n std::vector<int> P, PP, D, I, L, R;\npublic:\n HeavyLightDecomposition()=\
    \ default;\n HeavyLightDecomposition(const Graph &g, int root= 0): HeavyLightDecomposition(g.adjacency_vertex(0),\
    \ root) {}\n HeavyLightDecomposition(const CSRArray<int> &adj, int root= 0) {\n\
    \  const int n= adj.size();\n  P.assign(n, -2), PP.resize(n), D.resize(n), I.resize(n),\
    \ L.resize(n), R.resize(n);\n  auto f= [&, i= 0, v= 0, t= 0](int r) mutable {\n\
    \   for (P[r]= -1, I[t++]= r; i < t; ++i)\n    for (int u: adj[v= I[i]])\n   \
    \  if (P[v] != u) P[I[t++]= u]= v;\n  };\n  f(root);\n  for (int r= 0; r < n;\
    \ ++r)\n   if (P[r] == -2) f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for\
    \ (int i= n, v; i--;) {\n   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+=\
    \ Z[v]; nx[P[v]] == -1) nx[P[v]]= v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n\
    \  }\n  for (int v= n; v--;) PP[v]= v;\n  for (int v: I)\n   if (nx[v] != -1)\
    \ PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]], D[v]=\
    \ D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n   int\
    \ ir= R[v]= L[v] + Z[v];\n   for (int u: adj[v])\n    if (u != P[v] && u != nx[v])\
    \ L[u]= (ir-= Z[u]);\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n  }\n  for (int\
    \ i= n; i--;) I[L[i]]= i;\n }\n int to_seq(int v) const { return L[v]; }\n int\
    \ to_vertex(int i) const { return I[i]; }\n size_t size() const { return P.size();\
    \ }\n int parent(int v) const { return P[v]; }\n int head(int v) const { return\
    \ PP[v]; }\n int root(int v) const {\n  for (v= PP[v];; v= PP[P[v]])\n   if (P[v]\
    \ == -1) return v;\n }\n bool connected(int u, int v) const { return root(u) ==\
    \ root(v); }\n // u is in v\n bool in_subtree(int u, int v) const { return L[v]\
    \ <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return R[v] - L[v];\
    \ }\n int lca(int u, int v) const {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v])\
    \ std::swap(u, v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v,\
    \ int k) const {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] + 1, v=\
    \ P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int jump(int\
    \ u, int v, int k) const {\n  if (!k) return u;\n  if (u == v) return -1;\n  if\
    \ (k == 1) return in_subtree(v, u) ? la(v, D[v] - D[u] - 1) : P[u];\n  int w=\
    \ lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n  return k > d_uw + d_vw ?\
    \ -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n }\n int depth(int v) const\
    \ { return D[v]; }\n int dist(int u, int v) const { return D[u] + D[v] - D[lca(u,\
    \ v)] * 2; }\n // half-open interval\n std::array<int, 2> subtree(int v) const\
    \ { return std::array{L[v], R[v]}; }\n // sequence of closed intervals\n template\
    \ <bool edge= 0> std::vector<std::array<int, 2>> path(int u, int v) const {\n\
    \  std::vector<std::array<int, 2>> up, down;\n  while (PP[u] != PP[v]) {\n   if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}), v= P[PP[v]];\n\
    \   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n  }\n  if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};\n#line 3 \"src/DataStructure/WaveletMatrix.hpp\"\
    \n#include <algorithm>\n#line 6 \"src/DataStructure/WaveletMatrix.hpp\"\ntemplate\
    \ <class T> class WaveletMatrix {\n struct SuccinctIndexableDictionary {\n  size_t\
    \ len, blocks, zeros;\n  std::vector<unsigned> bit, sum;\n  SuccinctIndexableDictionary(size_t\
    \ len): len(len), blocks((len >> 5) + 1), bit(blocks, 0), sum(blocks, 0) {}\n\
    \  void set(int k) { bit[k >> 5]|= 1U << (k & 31); }\n  void build() {\n   for\
    \ (size_t i= 1; i < blocks; ++i) sum[i]= sum[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\n   zeros= rank0(len);\n  }\n  bool operator[](int k) const { return\
    \ (bit[k >> 5] >> (k & 31)) & 1; }\n  size_t rank(size_t k) const { return (sum[k\
    \ >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1))); }\n  size_t\
    \ rank0(size_t k) const { return k - rank(k); }\n };\n size_t len, lg;\n std::vector<SuccinctIndexableDictionary>\
    \ mat;\n std::vector<T> vec;\npublic:\n WaveletMatrix(const std::vector<T> &v):\
    \ len(v.size()), lg(len ? 32 - __builtin_clz(len) : 1), mat(lg, len), vec(v) {\n\
    \  std::sort(vec.begin(), vec.end()), vec.erase(std::unique(vec.begin(), vec.end()),\
    \ vec.end());\n  std::vector<unsigned> cur(len), nex(len);\n  for (int i= len;\
    \ i--;) cur[i]= std::lower_bound(vec.begin(), vec.end(), v[i]) - vec.begin();\n\
    \  for (auto h= lg; h--; cur.swap(nex)) {\n   for (size_t i= 0; i < len; ++i)\n\
    \    if ((cur[i] >> h) & 1) mat[h].set(i);\n   mat[h].build();\n   std::array\
    \ it{nex.begin(), nex.begin() + mat[h].zeros};\n   for (size_t i= 0; i < len;\
    \ ++i) *it[mat[h][i]]++= cur[i];\n  }\n }\n // k-th(0-indexed) smallest number\
    \ in v[l,r)\n T kth_smallest(int l, int r, int k) const {\n  assert(k < r - l);\n\
    \  size_t ret= 0;\n  for (auto h= lg; h--;)\n   if (auto l0= mat[h].rank0(l),\
    \ r0= mat[h].rank0(r); k >= r0 - l0) k-= r0 - l0, ret|= 1 << h, l+= mat[h].zeros\
    \ - l0, r+= mat[h].zeros - r0;\n   else l= l0, r= r0;\n  return vec[ret];\n }\n\
    \ // k-th(0-indexed) largest number in v[l,r)\n T kth_largest(int l, int r, int\
    \ k) const { return kth_smallest(l, r, r - l - k - 1); }\n // count i s.t. (l\
    \ <= i < r) && (v[i] < ub)\n size_t count(int l, int r, T ub) const {\n  size_t\
    \ x= std::lower_bound(vec.begin(), vec.end(), ub) - vec.begin();\n  if (x >= 1u\
    \ << lg) return r - l;\n  if (x == 0) return 0;\n  size_t ret= 0;\n  for (auto\
    \ h= lg; h--;)\n   if (auto l0= mat[h].rank0(l), r0= mat[h].rank0(r); (x >> h)\
    \ & 1) ret+= r0 - l0, l+= mat[h].zeros - l0, r+= mat[h].zeros - r0;\n   else l=\
    \ l0, r= r0;\n  return ret;\n }\n // count i s.t. (l <= i < r) && (lb <= v[i]\
    \ < ub)\n size_t count(int l, int r, T lb, T ub) const { return count(l, r, ub)\
    \ - count(l, r, lb); }\n};\n#line 7 \"test/atcoder/abc202_e.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N;\n cin >> N;\n Graph g(N);\n for (int i= 1, p; i < N; ++i) cin >> p, g.add_edge(p\
    \ - 1, i);\n HeavyLightDecomposition tree(g, 0);\n vector<int> d(N);\n for (int\
    \ v= N; v--;) d[tree.to_seq(v)]= tree.depth(v);\n WaveletMatrix wm(d);\n int Q;\n\
    \ cin >> Q;\n while (Q--) {\n  int U, D;\n  cin >> U >> D;\n  auto [l, r]= tree.subtree(U\
    \ - 1);\n  cout << wm.count(l, r, D, D + 1) << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_e\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Graph/Graph.hpp\"\n#include \"\
    src/Graph/HeavyLightDecomposition.hpp\"\n#include \"src/DataStructure/WaveletMatrix.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n Graph g(N);\n for (int i= 1, p; i < N; ++i) cin >> p, g.add_edge(p\
    \ - 1, i);\n HeavyLightDecomposition tree(g, 0);\n vector<int> d(N);\n for (int\
    \ v= N; v--;) d[tree.to_seq(v)]= tree.depth(v);\n WaveletMatrix wm(d);\n int Q;\n\
    \ cin >> Q;\n while (Q--) {\n  int U, D;\n  cin >> U >> D;\n  auto [l, r]= tree.subtree(U\
    \ - 1);\n  cout << wm.count(l, r, D, D + 1) << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/Graph/HeavyLightDecomposition.hpp
  - src/DataStructure/WaveletMatrix.hpp
  isVerificationFile: true
  path: test/atcoder/abc202_e.test.cpp
  requiredBy: []
  timestamp: '2024-02-17 11:26:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc202_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc202_e.test.cpp
- /verify/test/atcoder/abc202_e.test.cpp.html
title: test/atcoder/abc202_e.test.cpp
---
