---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/WaveletMatrix.hpp
    title: "Wavelet\u884C\u5217"
  - icon: ':question:'
    path: src/Graph/Tree.hpp
    title: "\u6728"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc202/tasks/abc202_e
    links:
    - https://atcoder.jp/contests/abc202/tasks/abc202_e
  bundledCode: "#line 1 \"test/atcoder/abc202_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_e\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"src/Graph/Tree.hpp\"\n#include\
    \ <type_traits>\n#include <cstddef>\n#include <algorithm>\n#include <array>\n\
    #include <tuple>\n#include <numeric>\n#include <cassert>\n#line 4 \"src/Internal/ListRange.hpp\"\
    \n#include <iterator>\n#line 6 \"src/Internal/ListRange.hpp\"\n#define _LR(name,\
    \ IT, CT) \\\n template <class T> struct name { \\\n  using Iterator= typename\
    \ std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const { return\
    \ bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size() const {\
    \ return std::distance(bg, ed); } \\\n  CT &operator[](int i) const { return bg[i];\
    \ } \\\n }\n_LR(ListRange, iterator, const T);\n_LR(ConstListRange, const_iterator,\
    \ const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n std::vector<T>\
    \ dat;\n std::vector<int> p;\n size_t size() const { return p.size() - 1; }\n\
    \ ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin() + p[i\
    \ + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 10 \"src/Graph/Tree.hpp\"\ntemplate <class Cost= void, bool\
    \ weight= false> class Tree {\n template <class D, class T> struct Edge_B {\n\
    \  int to;\n  T cost;\n  operator int() const { return to; }\n };\n template <class\
    \ D> struct Edge_B<D, void> {\n  int to;\n  operator int() const { return to;\
    \ }\n };\n using Edge= Edge_B<void, Cost>;\n using C= std::conditional_t<std::is_void_v<Cost>,\
    \ std::nullptr_t, Cost>;\n std::vector<std::conditional_t<std::is_void_v<Cost>,\
    \ std::pair<int, int>, std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n\
    \ std::vector<int> P, PP, D, I, L, R, pos;\n std::vector<C> DW, W;\npublic:\n\
    \ Tree(int n): P(n, -2) {}\n template <class T= Cost> std::enable_if_t<std::is_void_v<T>,\
    \ void> add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u);\
    \ }\n template <class T> std::enable_if_t<std::is_convertible_v<T, Cost>, void>\
    \ add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v, u,\
    \ c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, d); }\n void build(int root= 0) {\n  size_t n= P.size();\n  I.resize(n),\
    \ PP.resize(n), std::iota(PP.begin(), PP.end(), 0), D.assign(n, 0), L.assign(n,\
    \ 0), R.assign(n, 0), pos.resize(n + 1), g.resize(es.size());\n  for (const auto\
    \ &e: es) ++pos[std::get<0>(e)];\n  std::partial_sum(pos.begin(), pos.end(), pos.begin());\n\
    \  if constexpr (std::is_void_v<Cost>)\n   for (const auto &[f, t]: es) g[--pos[f]]=\
    \ {t};\n  else\n   for (const auto &[f, t, c]: es) g[--pos[f]]= {t, c};\n  auto\
    \ f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]= r; i <\
    \ t; ++i)\n    for (int u: operator[](v= I[i]))\n     if (P[v] != u) P[I[t++]=\
    \ u]= v;\n  };\n  f(root);\n  for (size_t r= 0; r < n; ++r)\n   if (P[r] == -2)\
    \ f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n\
    \   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]=\
    \ v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n   if (nx[v]\
    \ != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: operator[](v))\n    if (u != P[v]\
    \ && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n \
    \ }\n  if constexpr (weight) {\n   DW.resize(n), W.resize(n);\n   for (int v:\
    \ I)\n    for (auto &[u, c]: operator[](v)) {\n     if (u != P[v]) DW[u]= DW[v]\
    \ + c;\n     else W[v]= c;\n    }\n  }\n  for (int i= n; i--;) I[L[i]]= i;\n }\n\
    \ size_t size() const { return P.size(); }\n ConstListRange<Edge> operator[](int\
    \ v) const { return {g.cbegin() + pos[v], g.cbegin() + pos[v + 1]}; }\n int depth(int\
    \ v) const { return D[v]; }\n C depth_w(int v) const {\n  static_assert(weight,\
    \ \"\\'depth_w\\' is not available\");\n  return DW[v];\n }\n int to_seq(int v)\
    \ const { return L[v]; }\n int to_node(int i) const { return I[i]; }\n int parent(int\
    \ v) const { return P[v]; }\n int head(int v) const { return PP[v]; }\n int root(int\
    \ v) const {\n  for (v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n\
    \ bool connected(int u, int v) const { return root(u) == root(v); }\n int lca(int\
    \ u, int v) const {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u,\
    \ v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v, int k) const\
    \ {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] + 1, v= P[u])\n   if\
    \ (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int la_w(int v, C w) const\
    \ {\n  static_assert(weight, \"\\'la_w\\' is not available\");\n  for (C c;; w-=\
    \ c) {\n   int u= PP[v];\n   if (c= DW[v] - DW[u] + W[u]; w < c) {\n    int ok=\
    \ L[v], ng= L[u] - 1;\n    for (int m; ok - ng > 1;) m= (ok + ng) / 2, (DW[v]\
    \ - DW[I[m]] <= w ? ok : ng)= m;\n    return I[ok];\n   }\n   if (v= P[u]; v ==\
    \ -1) return u;\n  }\n }\n int jump(int u, int v, int k) const {\n  if (!k) return\
    \ u;\n  if (u == v) return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v,\
    \ D[v] - D[u] - 1) : P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v]\
    \ - D[w];\n  return k > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw +\
    \ d_vw - k);\n }\n int jump_w(int u, int v, C w) const {\n  static_assert(weight,\
    \ \"\\'jump_w\\' is not available\");\n  if (u == v) return u;\n  int z= lca(u,\
    \ v);\n  C d_uz= DW[u] - DW[z], d_vz= DW[v] - DW[z];\n  return w >= d_uz + d_vz\
    \ ? v : w <= d_uz ? la_w(u, w) : la_w(v, d_uz + d_vz - w);\n }\n int dist(int\
    \ u, int v) const { return D[u] + D[v] - D[lca(u, v)] * 2; }\n C dist_w(int u,\
    \ int v) const {\n  static_assert(weight, \"\\'dist_w\\' is not available\");\n\
    \  return DW[u] + DW[v] - DW[lca(u, v)] * 2;\n }\n // u is in v\n bool in_subtree(int\
    \ u, int v) const { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int\
    \ v) const { return R[v] - L[v]; }\n // half-open interval\n std::array<int, 2>\
    \ subtree(int v) const { return std::array{L[v], R[v]}; }\n // sequence of closed\
    \ intervals\n template <bool edge= 0> std::vector<std::array<int, 2>> path(int\
    \ u, int v) const {\n  std::vector<std::array<int, 2>> up, down;\n  while (PP[u]\
    \ != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}),\
    \ v= P[PP[v]];\n   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n\
    \  }\n  if (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n \
    \ else if (L[v] + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n\
    \  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n};\n#line\
    \ 6 \"src/DataStructure/WaveletMatrix.hpp\"\ntemplate <class T> class WaveletMatrix\
    \ {\n struct SuccinctIndexableDictionary {\n  size_t len, blocks, zeros;\n  std::vector<unsigned>\
    \ bit, sum;\n  SuccinctIndexableDictionary(size_t len): len(len), blocks((len\
    \ >> 5) + 1), bit(blocks, 0), sum(blocks, 0) {}\n  void set(int k) { bit[k >>\
    \ 5]|= 1U << (k & 31); }\n  void build() {\n   for (size_t i= 1; i < blocks; ++i)\
    \ sum[i]= sum[i - 1] + __builtin_popcount(bit[i - 1]);\n   zeros= rank0(len);\n\
    \  }\n  bool operator[](int k) const { return (bit[k >> 5] >> (k & 31)) & 1; }\n\
    \  size_t rank(size_t k) const { return (sum[k >> 5] + __builtin_popcount(bit[k\
    \ >> 5] & ((1U << (k & 31)) - 1))); }\n  size_t rank0(size_t k) const { return\
    \ k - rank(k); }\n };\n size_t len, lg;\n std::vector<SuccinctIndexableDictionary>\
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
    \ - count(l, r, lb); }\n};\n#line 6 \"test/atcoder/abc202_e.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N;\n cin >> N;\n Tree tree(N);\n for (int i= 1; i < N; ++i) {\n  int p;\n  cin\
    \ >> p;\n  tree.add_edge(p - 1, i);\n }\n tree.build(0);\n vector<int> d(N);\n\
    \ for (int v= N; v--;) d[tree.to_seq(v)]= tree.depth(v);\n WaveletMatrix wm(d);\n\
    \ int Q;\n cin >> Q;\n while (Q--) {\n  int U, D;\n  cin >> U >> D;\n  auto [l,\
    \ r]= tree.subtree(U - 1);\n  cout << wm.count(l, r, D, D + 1) << '\\n';\n }\n\
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_e\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Graph/Tree.hpp\"\n#include \"\
    src/DataStructure/WaveletMatrix.hpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin >> N;\n Tree tree(N);\n\
    \ for (int i= 1; i < N; ++i) {\n  int p;\n  cin >> p;\n  tree.add_edge(p - 1,\
    \ i);\n }\n tree.build(0);\n vector<int> d(N);\n for (int v= N; v--;) d[tree.to_seq(v)]=\
    \ tree.depth(v);\n WaveletMatrix wm(d);\n int Q;\n cin >> Q;\n while (Q--) {\n\
    \  int U, D;\n  cin >> U >> D;\n  auto [l, r]= tree.subtree(U - 1);\n  cout <<\
    \ wm.count(l, r, D, D + 1) << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Graph/Tree.hpp
  - src/Internal/ListRange.hpp
  - src/DataStructure/WaveletMatrix.hpp
  isVerificationFile: true
  path: test/atcoder/abc202_e.test.cpp
  requiredBy: []
  timestamp: '2024-02-15 14:27:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc202_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc202_e.test.cpp
- /verify/test/atcoder/abc202_e.test.cpp.html
title: test/atcoder/abc202_e.test.cpp
---
