---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/LinkCutTree.hpp
    title: Link-Cut-Tree
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/PersistentArray.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc133/tasks/abc133_f
    links:
    - https://atcoder.jp/contests/abc133/tasks/abc133_f
  bundledCode: "#line 1 \"test/atcoder/abc133_f.PerArr.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n// \u6C38\u7D9A\u914D\
    \u5217(at) \u306E verify\n#include <iostream>\n#include <vector>\n#include <tuple>\n\
    #line 3 \"src/DataStructure/PersistentArray.hpp\"\ntemplate <class T, std::size_t\
    \ M= 8> class PersistentArray {\n struct Node {\n  T val;\n  Node *ch[M];\n }\
    \ * root;\n T get(Node *&t, std::size_t k) { return t ? (k ? get(t->ch[(k - 1)\
    \ % M], (k - 1) / M) : t->val) : T(); }\n bool is_null(Node *&t, std::size_t k)\
    \ { return t ? (k ? is_null(t->ch[(k - 1) % M], (k - 1) / M) : false) : true;\
    \ }\n template <bool persistent= true> T &at(Node *&t, std::size_t k) {\n  if\
    \ (!t) t= new Node();\n  else if constexpr (persistent) t= new Node(*t);\n  return\
    \ k ? at<persistent>(t->ch[(k - 1) % M], (k - 1) / M) : t->val;\n }\npublic:\n\
    \ PersistentArray(): root(nullptr) {}\n PersistentArray(std::size_t n, T v): root(nullptr)\
    \ {\n  for (std::size_t i= n; i--;) at<false>(root, i)= v;\n }\n PersistentArray(T\
    \ *bg, T *ed): root(nullptr) {\n  for (std::size_t i= ed - bg; i--;) at<false>(root,\
    \ i)= *(bg + i);\n }\n PersistentArray(const std::vector<T> &ar): PersistentArray(ar.data(),\
    \ ar.data() + ar.size()) {}\n bool is_null(std::size_t k) { return is_null(root,\
    \ k); }\n T get(std::size_t k) { return get(root, k); }\n T &at(std::size_t k)\
    \ { return at<true>(root, k); }\n T &operator[](std::size_t k) { return at(k);\
    \ }\n};\n#line 2 \"src/DataStructure/LinkCutTree.hpp\"\n#include <algorithm>\n\
    #line 4 \"src/DataStructure/LinkCutTree.hpp\"\n#include <string>\n#include <cstddef>\n\
    #include <cassert>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define HAS_CHECK(member, Dummy) \\\n template <class tClass> struct has_##member\
    \ { \\\n  template <class U, Dummy> static std::true_type check(U *); \\\n  static\
    \ std::false_type check(...); \\\n  static tClass *mClass; \\\n  static const\
    \ bool value= decltype(check(mClass))::value; \\\n };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#line 8 \"src/DataStructure/LinkCutTree.hpp\"\
    \ntemplate <typename M= void> class LinkCutTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n\
    \ HAS_MEMBER(composition);\n HAS_TYPE(T);\n HAS_TYPE(E);\n template <class L>\
    \ static constexpr bool semigroup_v= std::conjunction_v<has_T<L>, has_op<L>>;\n\
    \ template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n template <class tDerived, class\
    \ U= std::nullptr_t, class F= std::nullptr_t> struct Node_B {\n  using T= U;\n\
    \  using E= F;\n  tDerived *ch[2], *par;\n  bool rev_flg;\n };\n template <class\
    \ D, bool sg, bool du> struct Node_D: Node_B<Node_D<D, sg, du>> {};\n template\
    \ <class D> struct Node_D<D, 1, 0>: Node_B<Node_D<D, 1, 0>, typename M::T> { typename\
    \ M::T val, sum, rsum; };\n template <class D> struct Node_D<D, 0, 1>: Node_B<Node_D<D,\
    \ 0, 1>, typename M::T, typename M::E> {\n  typename M::T val;\n  typename M::E\
    \ lazy;\n  bool lazy_flg;\n };\n template <class D> struct Node_D<D, 1, 1>: Node_B<Node_D<D,\
    \ 1, 1>, typename M::T, typename M::E> {\n  typename M::T val, sum, rsum;\n  typename\
    \ M::E lazy;\n  bool lazy_flg;\n };\n using Node= Node_D<void, semigroup_v<M>,\
    \ dual_v<M>>;\n using T= typename Node::T;\n using E= typename Node::E;\n static\
    \ inline int dir(Node *&t) {\n  if (t->par) {\n   if (t->par->ch[0] == t) return\
    \ 0;\n   if (t->par->ch[1] == t) return 1;\n  }\n  return 2;\n }\n static inline\
    \ void rot(Node *t) {\n  Node *p= t->par;\n  int d= dir(t);\n  if ((p->ch[d]=\
    \ t->ch[!d])) p->ch[d]->par= p;\n  t->ch[!d]= p;\n  if constexpr (semigroup_v<M>)\
    \ pushup(p), pushup(t);\n  if (t->par= p->par; (d= dir(p)) < 2) {\n   p->par->ch[d]=\
    \ t;\n   if constexpr (semigroup_v<M>) pushup(t->par);\n  }\n  p->par= t;\n }\n\
    \ static inline void splay(Node *t) {\n  eval(t);\n  for (int t_d= dir(t), p_d;\
    \ t_d < 2; rot(t), t_d= dir(t)) {\n   if ((p_d= dir(t->par)) < 2) eval(t->par->par);\n\
    \   if (eval(t->par), eval(t); p_d < 2) rot(t_d == p_d ? t->par : t);\n  }\n }\n\
    \ static inline void pushup(Node *t) {\n  t->rsum= t->sum= t->val;\n  if (t->ch[0])\
    \ t->sum= M::op(t->ch[0]->sum, t->sum), t->rsum= M::op(t->rsum, t->ch[0]->rsum);\n\
    \  if (t->ch[1]) t->sum= M::op(t->sum, t->ch[1]->sum), t->rsum= M::op(t->ch[1]->rsum,\
    \ t->rsum);\n }\n static inline void propagate(Node *t, const E &x) {\n  if (!t)\
    \ return;\n  M::mapping(t->val, x), t->lazy_flg ? (M::composition(t->lazy, x),\
    \ x) : t->lazy= x;\n  if constexpr (semigroup_v<M>) M::mapping(t->sum, x), M::mapping(t->rsum,\
    \ x);\n  t->lazy_flg= true;\n }\n static inline void toggle(Node *t) {\n  if (!t)\
    \ return;\n  std::swap(t->ch[0], t->ch[1]);\n  if constexpr (semigroup_v<M>) std::swap(t->sum,\
    \ t->rsum);\n  t->rev_flg= !t->rev_flg;\n }\n static inline void eval(Node *t)\
    \ {\n  if (t->rev_flg) toggle(t->ch[0]), toggle(t->ch[1]), t->rev_flg= false;\n\
    \  if constexpr (dual_v<M>)\n   if (t->lazy_flg) propagate(t->ch[0], t->lazy),\
    \ propagate(t->ch[1], t->lazy), t->lazy_flg= false;\n }\n static inline Node *expose(Node\
    \ *t) {\n  Node *r= nullptr;\n  for (Node *p= t; p; r= p, p= p->par) {\n   splay(p),\
    \ p->ch[1]= r;\n   if constexpr (semigroup_v<M>) pushup(p);\n  }\n  return splay(t),\
    \ r;\n }\n std::vector<Node> ns;\npublic:\n LinkCutTree(std::size_t n): ns(n)\
    \ {}\n LinkCutTree(std::size_t n, T val): ns(n) {\n  for (std::size_t i= n; i--;)\
    \ ns[i].val= val;\n }\n void evert(std::size_t k) { expose(&ns[k]), toggle(&ns[k]),\
    \ eval(&ns[k]); }\n void link(std::size_t c, std::size_t p) {\n  evert(c), expose(&ns[p]),\
    \ assert(!ns[c].par), ns[p].ch[1]= &ns[c], ns[c].par= &ns[p];\n  if constexpr\
    \ (semigroup_v<M>) pushup(&ns[p]);\n }\n void cut(std::size_t c, std::size_t p)\
    \ {\n  evert(p), expose(&ns[c]), assert(ns[c].ch[0] == &ns[p]), ns[c].ch[0]= ns[c].ch[0]->par=\
    \ nullptr;\n  if constexpr (semigroup_v<M>) pushup(&ns[c]);\n }\n int root(std::size_t\
    \ x) {\n  expose(&ns[x]);\n  Node *t= &ns[x];\n  while (t->ch[0]) t= t->ch[0];\n\
    \  return t - &ns[0];\n }\n int par(std::size_t x) {\n  expose(&ns[x]);\n  Node\
    \ *t= ns[x].ch[0];\n  if (!t) return -1;\n  while (t->ch[1]) t= t->ch[1];\n  return\
    \ t - &ns[0];\n }\n int lca(std::size_t x, std::size_t y) {\n  if (x == y) return\
    \ x;\n  expose(&ns[x]);\n  Node *u= expose(&ns[y]);\n  return ns[x].par ? u -\
    \ &ns[0] : -1;\n }\n const T &operator[](std::size_t k) { return get(k); }\n const\
    \ T &get(std::size_t k) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\"\
    get\\\" is not available\\n\");\n  return expose(&ns[k]), ns[k].val;\n }\n void\
    \ set(std::size_t k, T v) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\
    \"set\\\" is not available\\n\");\n  expose(&ns[k]), ns[k].val= v;\n  if constexpr\
    \ (semigroup_v<M>) pushup(&ns[k]);\n }\n T fold(std::size_t a, std::size_t b)\
    \ {  // [a,b] closed section\n  static_assert(semigroup_v<M>, \"\\\"fold\\\" is\
    \ not available\\n\");\n  if (a == b) return get(a);\n  return evert(a), expose(&ns[b]),\
    \ assert(ns[a].par), ns[b].sum;\n }\n void apply(std::size_t a, std::size_t b,\
    \ E v) {  // [a,b] closed section\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  evert(a), expose(&ns[b]), assert(a == b || ns[a].par),\
    \ propagate(&ns[b], v), eval(&ns[b]);\n }\n static std::string which_available()\
    \ {\n  std::string ret= \"\";\n  if constexpr (semigroup_v<M> || dual_v<M>) ret+=\
    \ \"\\\"set\\\" \\\"get\\\" \";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"\
    fold\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return ret;\n\
    \ }\n};\n#line 8 \"test/atcoder/abc133_f.PerArr.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >>\
    \ N >> Q;\n LinkCutTree lct(N);\n vector<tuple<int, int, int>> adj[N];\n for (int\
    \ i= 0; i < N - 1; i++) {\n  int a, b, c, d;\n  cin >> a >> b >> c >> d;\n  lct.link(--a,\
    \ --b);\n  adj[a].emplace_back(b, c, d);\n  adj[b].emplace_back(a, c, d);\n }\n\
    \ using PerArr= PersistentArray<int, 8>;\n PerArr Arr1[N], Arr2[N];\n int sum[N];\n\
    \ sum[0]= 0;\n auto dfs= [&adj, &Arr1, &Arr2, &sum](auto f, int v, int p) -> void\
    \ {\n  for (auto [u, c, d]: adj[v])\n   if (u != p) {\n    Arr1[u]= Arr1[v], Arr2[u]=\
    \ Arr2[v];\n    Arr1[u][c]+= 1, Arr2[u][c]+= d;\n    sum[u]= sum[v] + d;\n   \
    \ f(f, u, v);\n   }\n };\n dfs(dfs, 0, -1);\n lct.evert(0);\n for (int i= 0; i\
    \ < Q; i++) {\n  int x, y, u, v;\n  cin >> x >> y >> u >> v;\n  int lca= lct.lca(--u,\
    \ --v);\n  cout << sum[u] + sum[v] - 2 * sum[lca] + y * (Arr1[u].get(x) + Arr1[v].get(x)\
    \ - 2 * Arr1[lca].get(x)) - (Arr2[u].get(x) + Arr2[v].get(x) - 2 * Arr2[lca].get(x))\
    \ << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n//\
    \ \u6C38\u7D9A\u914D\u5217(at) \u306E verify\n#include <iostream>\n#include <vector>\n\
    #include <tuple>\n#include \"src/DataStructure/PersistentArray.hpp\"\n#include\
    \ \"src/DataStructure/LinkCutTree.hpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >> Q;\n LinkCutTree\
    \ lct(N);\n vector<tuple<int, int, int>> adj[N];\n for (int i= 0; i < N - 1; i++)\
    \ {\n  int a, b, c, d;\n  cin >> a >> b >> c >> d;\n  lct.link(--a, --b);\n  adj[a].emplace_back(b,\
    \ c, d);\n  adj[b].emplace_back(a, c, d);\n }\n using PerArr= PersistentArray<int,\
    \ 8>;\n PerArr Arr1[N], Arr2[N];\n int sum[N];\n sum[0]= 0;\n auto dfs= [&adj,\
    \ &Arr1, &Arr2, &sum](auto f, int v, int p) -> void {\n  for (auto [u, c, d]:\
    \ adj[v])\n   if (u != p) {\n    Arr1[u]= Arr1[v], Arr2[u]= Arr2[v];\n    Arr1[u][c]+=\
    \ 1, Arr2[u][c]+= d;\n    sum[u]= sum[v] + d;\n    f(f, u, v);\n   }\n };\n dfs(dfs,\
    \ 0, -1);\n lct.evert(0);\n for (int i= 0; i < Q; i++) {\n  int x, y, u, v;\n\
    \  cin >> x >> y >> u >> v;\n  int lca= lct.lca(--u, --v);\n  cout << sum[u] +\
    \ sum[v] - 2 * sum[lca] + y * (Arr1[u].get(x) + Arr1[v].get(x) - 2 * Arr1[lca].get(x))\
    \ - (Arr2[u].get(x) + Arr2[v].get(x) - 2 * Arr2[lca].get(x)) << '\\n';\n }\n return\
    \ 0;\n}"
  dependsOn:
  - src/DataStructure/PersistentArray.hpp
  - src/DataStructure/LinkCutTree.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/atcoder/abc133_f.PerArr.test.cpp
  requiredBy: []
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc133_f.PerArr.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc133_f.PerArr.test.cpp
- /verify/test/atcoder/abc133_f.PerArr.test.cpp.html
title: test/atcoder/abc133_f.PerArr.test.cpp
---
