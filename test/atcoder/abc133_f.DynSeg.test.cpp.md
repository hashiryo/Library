---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/LinkCutTree.hpp
    title: Link-Cut-Tree
  - icon: ':x:'
    path: src/DataStructure/SegmentTree_Dynamic.hpp
    title: "Segment-Tree(\u52D5\u7684\u69CB\u7BC9)"
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc133/tasks/abc133_f
    links:
    - https://atcoder.jp/contests/abc133/tasks/abc133_f
  bundledCode: "#line 1 \"test/atcoder/abc133_f.DynSeg.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n// \u6C38\u7D9A\u914D\
    \u5217(at) \u306E verify\n#include <iostream>\n#include <vector>\n#include <tuple>\n\
    #line 2 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include <array>\n#line\
    \ 4 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include <string>\n#include\
    \ <algorithm>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define MEMBER_MACRO(member, Dummy, name, type1, type2, last) \\\n template <class\
    \ tClass> struct name##member { \\\n  template <class U, Dummy> static type1 check(U\
    \ *); \\\n  static type2 check(...); \\\n  static tClass *mClass; \\\n  last;\
    \ \\\n };\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member, Dummy, has_,\
    \ std::true_type, std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)))\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type;\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t);\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass);\n#line 8 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\
    \ntemplate <typename M, bool persistent= false, uint8_t HEIGHT= 31> class SegmentTree_Dynamic\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(ti);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n\
    \ HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(E);\n template <class L> static constexpr\
    \ bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;\n template\
    \ <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>, has_E<L>,\
    \ has_mapping<L>, has_composition<L>>;\n using id_t= long long;\n template <class\
    \ T, class tDerived> struct Node_B {\n  T val;\n  tDerived *ch[2]= {nullptr, nullptr};\n\
    \ };\n template <bool mo, bool du, typename tEnable= void> struct Node_D: Node_B<M,\
    \ Node_D<mo, du, tEnable>> {};\n template <bool mo, bool du> struct Node_D<mo,\
    \ du, typename std::enable_if_t<mo && !du>>: Node_B<typename M::T, Node_D<mo,\
    \ du>> {};\n template <bool mo, bool du> struct Node_D<mo, du, typename std::enable_if_t<du>>:\
    \ Node_B<typename M::T, Node_D<mo, du>> {\n  typename M::E lazy;\n  bool lazy_flg=\
    \ false;\n };\n using Node= Node_D<monoid_v<M>, dual_v<M>>;\n using T= decltype(Node::val);\n\
    \ using E= nullptr_or_E_t<M>;\n using np= Node *;\n np root;\n static inline constexpr\
    \ T def_val() {\n  if constexpr (monoid_v<M>) return M::ti();\n  else return T();\n\
    \ }\n template <class S> np build(id_t n, id_t l, id_t r, const S &bg) {\n  if\
    \ (n <= l) return nullptr;\n  if (r - l == 1) {\n   if constexpr (std::is_same_v<S,\
    \ T>) return new Node{bg};\n   else return new Node{*(bg + l)};\n  }\n  id_t m=\
    \ (r + l) / 2;\n  np t= new Node{def_val(), {build(n, l, m, bg), build(n, m, r,\
    \ bg)}};\n  if constexpr (monoid_v<M>) update(t);\n  return t;\n }\n void dump(np\
    \ t, const id_t &l, const id_t &r, std::array<id_t, 2> b, typename std::vector<T>::iterator\
    \ itr) {\n  if (r <= b[0] || b[1] <= l) return;\n  if (l <= b[0] && b[1] <= r\
    \ && !t) {\n   for (id_t i= b[0]; i < b[1]; i++) *(itr + i)= def_val();\n  } else\
    \ if (b[1] - b[0] != 1) {\n   if constexpr (dual_v<M>) push(t, b[1] - b[0]);\n\
    \   auto m= (b[0] + b[1]) >> 1;\n   dump(t ? t->ch[0] : nullptr, l, r, {b[0],\
    \ m}, itr);\n   dump(t ? t->ch[1] : nullptr, l, r, {m, b[1]}, itr);\n  } else\
    \ *(itr + b[0])= t->val;\n }\n static inline void update(np &t) {\n  t->val= def_val();\n\
    \  if (t->ch[0]) t->val= M::op(t->ch[0]->val, t->val);\n  if (t->ch[1]) t->val=\
    \ M::op(t->val, t->ch[1]->val);\n }\n static inline T &reflect(np &t) {\n  if\
    \ constexpr (dual_v<M> && !monoid_v<M>)\n   if (t->lazy_flg) M::mapping(t->val,\
    \ t->lazy, 1), t->lazy_flg= false;\n  return t->val;\n }\n static inline void\
    \ propagate(np &t, const E &x, const id_t &sz) {\n  t->lazy_flg ? (M::composition(t->lazy,\
    \ x), x) : t->lazy= x;\n  t->lazy_flg= true;\n  if constexpr (monoid_v<M>) M::mapping(t->val,\
    \ x, sz);\n }\n static inline void cp_node(np &t) {\n  if (!t) t= new Node{def_val()};\n\
    \  else if constexpr (persistent) t= new Node(*t);\n }\n static inline void push(np\
    \ &t, const id_t &sz) {\n  if (!t->lazy_flg) return;\n  cp_node(t->ch[0]), cp_node(t->ch[1]),\
    \ t->lazy_flg= false;\n  propagate(t->ch[0], t->lazy, sz / 2), propagate(t->ch[1],\
    \ t->lazy, sz / 2);\n }\n T fold(np &t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b, const id_t &bias) {\n  if (!t || r <= b[0] || b[1] <= l) return def_val();\n\
    \  if (l <= b[0] && b[1] <= r) return t->val;\n  if constexpr (dual_v<M>) push(t,\
    \ b[1] - b[0]);\n  id_t m= (b[0] + b[1]) >> 1;\n  bool flg= (bias >> (__builtin_ctzll(b[1]\
    \ - b[0]) - 1)) & 1;\n  return M::op(fold(t->ch[flg], l, r, {b[0], m}, bias),\
    \ fold(t->ch[!flg], l, r, {m, b[1]}, bias));\n }\n void apply(np &t, const id_t\
    \ &l, const id_t &r, std::array<id_t, 2> b, const E &x) {\n  if (r <= b[0] ||\
    \ b[1] <= l) return;\n  id_t m= (b[0] + b[1]) >> 1;\n  if (cp_node(t); l <= b[0]\
    \ && b[1] <= r) return propagate(t, x, b[1] - b[0]);\n  push(t, b[1] - b[0]);\n\
    \  apply(t->ch[0], l, r, {b[0], m}, x), apply(t->ch[1], l, r, {m, b[1]}, x);\n\
    \  if constexpr (monoid_v<M>) update(t);\n }\n void set_val(np &t, const id_t\
    \ &k, const T &val, uint8_t h) {\n  if (cp_node(t); !h) return reflect(t)= val,\
    \ void();\n  if constexpr (dual_v<M>) push(t, 1LL << h);\n  set_val(t->ch[(k >>\
    \ (h - 1)) & 1], k, val, h - 1);\n  if constexpr (monoid_v<M>) update(t);\n }\n\
    \ T &at_val(np &t, const id_t &k, uint8_t h) {\n  if (cp_node(t); !h) return reflect(t);\n\
    \  if constexpr (dual_v<M>) push(t, 1LL << h);\n  return at_val(t->ch[(k >> (h\
    \ - 1)) & 1], k, h - 1);\n }\n bool is_null(np &t, const id_t &k, uint8_t h) {\n\
    \  if (!t) return true;\n  if (!h) return false;\n  if constexpr (dual_v<M>) push(t,\
    \ 1LL << h);\n  return is_null(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n }\n T get_val(np\
    \ &t, const id_t &k, uint8_t h) {\n  if (!t) return def_val();\n  if (!h) return\
    \ reflect(t);\n  if constexpr (dual_v<M>) push(t, 1LL << h);\n  return get_val(t->ch[(k\
    \ >> (h - 1)) & 1], k, h - 1);\n }\n template <bool last> static inline T calc_op(np\
    \ &t, const T &v) {\n  if constexpr (last) return M::op((t ? t->val : def_val()),\
    \ v);\n  else return M::op(v, (t ? t->val : def_val()));\n }\n template <bool\
    \ last> static inline bool is_in(const id_t &m, const id_t &k) {\n  if constexpr\
    \ (last) return k <= m;\n  else return m <= k;\n }\n template <bool last, class\
    \ C, std::size_t N> static id_t find(const id_t &k, std::array<id_t, 2> b, const\
    \ id_t &bias, uint8_t h, const C &check, std::array<np, N> &ts, std::array<T,\
    \ N> &sums) {\n  static_assert(monoid_v<M>, \"\\\"find\\\" is not available\\\
    n\");\n  static std::array<T, N> sums2;\n  if (std::all_of(ts.begin(), ts.end(),\
    \ [](np t) { return !t; })) return -1;\n  if (!h) {\n   for (std::size_t i= N;\
    \ i--;) sums[i]= calc_op<last>(ts[i], sums[i]);\n   return std::apply(check, sums)\
    \ ? std::get<last>(b) : -1;\n  } else if (is_in<last>(k, b[0])) {\n   for (std::size_t\
    \ i= N; i--;) sums2[i]= calc_op<last>(ts[i], sums[i]);\n   if (!std::apply(check,\
    \ sums2)) return sums= std::move(sums2), -1;\n  }\n  if constexpr (dual_v<M>)\n\
    \   for (std::size_t i= N; i--;) push(ts[i], b[1] - b[0]);\n  std::array<np, N>\
    \ ss;\n  id_t m= (b[0] + b[1]) >> 1;\n  bool flg= (bias >> (h - 1)) & 1;\n  if\
    \ (!is_in<last>(m, k)) {\n   for (std::size_t i= N; i--;) ss[i]= ts[i] ? ts[i]->ch[flg]\
    \ : nullptr;\n   id_t ret= find<last>(k, {b[0], m}, bias, h - 1, check, ss, sums);\n\
    \   if (ret >= 0) return ret;\n  }\n  for (std::size_t i= N; i--;) ss[i]= ts[i]\
    \ ? ts[i]->ch[!flg] : nullptr;\n  return find<last>(k, {m, b[1]}, bias, h - 1,\
    \ check, ss, sums);\n }\npublic:\n SegmentTree_Dynamic(np t= nullptr): root(t)\
    \ {}\n SegmentTree_Dynamic(std::size_t n, T val) { root= build(n, 0, 1LL << HEIGHT,\
    \ val); }\n SegmentTree_Dynamic(const T *bg, const T *ed) { root= build(ed - bg,\
    \ 0, 1LL << HEIGHT, bg); }\n SegmentTree_Dynamic(const std::vector<T> &ar): SegmentTree_Dynamic(ar.data(),\
    \ ar.data() + ar.size()) {}\n void set(id_t k, T val) { set_val(root, k, val,\
    \ HEIGHT); }\n T get(id_t k) { return get_val(root, k, HEIGHT); }\n bool is_null(id_t\
    \ k) { return is_null(root, k, HEIGHT); }\n T &at(id_t k) {\n  static_assert(!monoid_v<M>,\
    \ \"\\\"at\\\" is not available\\n\");\n  return at_val(root, k, HEIGHT);\n }\n\
    \ template <class L= M, std::enable_if_t<monoid_v<L>, std::nullptr_t> = nullptr>\
    \ T operator[](id_t k) { return get(k); }\n template <class L= M, std::enable_if_t<!monoid_v<L>,\
    \ std::nullptr_t> = nullptr> T &operator[](id_t k) { return at(k); }\n T fold(id_t\
    \ a, id_t b, id_t bias= 0) {\n  static_assert(monoid_v<M>, \"\\\"fold\\\" is not\
    \ available\\n\");\n  return fold(root, a, b, {0, 1LL << HEIGHT}, bias);\n }\n\
    \ // find i s.t.\n //  check(fold(a,i)) == False, check(fold(a,i+1)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_first(id_t a, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n }\n template\
    \ <std::size_t N, class C> static id_t find_first(id_t a, C check, std::array<SegmentTree_Dynamic,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, ts, sums);\n }\n\
    \ // find i s.t.\n //  check(fold(i+1,b)) == False, check(fold(i,b)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_last(id_t b, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, t, sum);\n }\n\
    \ template <std::size_t N, class C> static id_t find_last(id_t b, C check, std::array<SegmentTree_Dynamic,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, ts, sums);\n }\n\
    \ void apply(id_t a, id_t b, E x) {\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  apply(root, a, b, {0, 1LL << HEIGHT}, x);\n }\n std::vector<T>\
    \ dump(id_t bg, id_t ed) {\n  std::vector<T> ret(ed - bg);\n  return dump(root,\
    \ bg, ed, {0, 1LL << HEIGHT}, ret.begin()), ret;\n }\n static std::string which_available()\
    \ {\n  std::string ret= \"\";\n  if constexpr (monoid_v<M>) ret+= \"\\\"fold\\\
    \" \\\"find\\\" \";\n  else ret+= \"\\\"at\\\" \";\n  if constexpr (dual_v<M>)\
    \ ret+= \"\\\"apply\\\" \";\n  return ret;\n }\n};\n#line 5 \"src/DataStructure/LinkCutTree.hpp\"\
    \n#include <cstddef>\n#include <cassert>\n#line 8 \"src/DataStructure/LinkCutTree.hpp\"\
    \ntemplate <typename M= void> class LinkCutTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n\
    \ HAS_MEMBER(composition);\n HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(T);\n NULLPTR_OR(E);\n\
    \ template <class L> static constexpr bool semigroup_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n template struct Node_B {\n\
    \  int ch[2]= {-1, -1}, par= -1;\n  bool rev_flg;\n };\n template <class D, bool\
    \ sg, bool du> struct Node_D: Node_B {};\n template <class D> struct Node_D<D,\
    \ 1, 0>: Node_B {\n  typename M::T val, sum, rsum;\n };\n template <class D> struct\
    \ Node_D<D, 0, 1>: Node_B {\n  typename M::T val;\n  typename M::E laz;\n  bool\
    \ laz_flg;\n };\n template <class D> struct Node_D<D, 1, 1>: Node_B {\n  typename\
    \ M::T val, sum, rsum;\n  typename M::E laz;\n  bool laz_flg;\n };\n using Node=\
    \ Node_D<void, semigroup_v<M>, dual_v<M>>;\n using T= nullptr_or_T_t<M>;\n using\
    \ E= nullptr_or_E_t<M>;\n inline int dir(int i) {\n  if (ns[i].par != -1) {\n\
    \   if (ns[ns[i].par].ch[0] == i) return 0;\n   if (ns[ns[i].par].ch[1] == i)\
    \ return 1;\n  }\n  return 2;\n }\n inline void rot(int i) {\n  int p= ns[i].par;\n\
    \  int d= dir(i);\n  if ((ns[p].ch[d]= ns[i].ch[!d]) != -1) ns[ns[p].ch[d]].par=\
    \ p;\n  ns[i].ch[!d]= p, ns[i].par= ns[p].par;\n  if ((d= dir(p)) < 2) ns[ns[p].par].ch[d]=\
    \ i;\n  ns[p].par= i;\n  if constexpr (semigroup_v<M>) update(p);\n }\n inline\
    \ void splay(int i) {\n  push(i);\n  int p= ns[i].par, pp;\n  for (int d= dir(i),\
    \ c; d < 2; rot(i), d= dir(i), p= ns[i].par) {\n   if (c= dir(p), pp= ns[p].par;\
    \ c < 2) push(pp), push(p), push(i), rot(d == c ? p : i);\n   else push(p), push(i);\n\
    \  }\n  if constexpr (semigroup_v<M>) update(i);\n }\n inline void update(int\
    \ i) {\n  ns[i].rsum= ns[i].sum= ns[i].val;\n  if (ns[i].ch[0] != -1) ns[i].sum=\
    \ M::op(ns[ns[i].ch[0]].sum, ns[i].sum), ns[i].rsum= M::op(ns[i].rsum, ns[ns[i].ch[0]].rsum);\n\
    \  if (ns[i].ch[1] != -1) ns[i].sum= M::op(ns[i].sum, ns[ns[i].ch[1]].sum), ns[i].rsum=\
    \ M::op(ns[ns[i].ch[1]].rsum, ns[i].rsum);\n }\n inline void propagate(int i,\
    \ const E &x) {\n  if (i == -1) return;\n  if (ns[i].laz_flg) M::composition(ns[i].laz,\
    \ x);\n  else ns[i].laz= x;\n  if constexpr (semigroup_v<M>) M::mapping(ns[i].sum,\
    \ x), M::mapping(ns[i].rsum, x);\n  M::mapping(ns[i].val, x), ns[i].laz_flg= true;\n\
    \ }\n inline void toggle(int i) {\n  if (i == -1) return;\n  std::swap(ns[i].ch[0],\
    \ ns[i].ch[1]);\n  if constexpr (semigroup_v<M>) std::swap(ns[i].sum, ns[i].rsum);\n\
    \  ns[i].rev_flg= !ns[i].rev_flg;\n }\n inline void push(int i) {\n  if (ns[i].rev_flg)\
    \ toggle(ns[i].ch[0]), toggle(ns[i].ch[1]), ns[i].rev_flg= false;\n  if constexpr\
    \ (dual_v<M>)\n   if (ns[i].laz_flg) propagate(ns[i].ch[0], ns[i].laz), propagate(ns[i].ch[1],\
    \ ns[i].laz), ns[i].laz_flg= false;\n }\n inline int expose(int i) {\n  int r=\
    \ -1;\n  for (int p= i; p != -1; r= p, p= ns[p].par) {\n   splay(p), ns[p].ch[1]=\
    \ r;\n   if constexpr (semigroup_v<M>) update(p);\n  }\n  return splay(i), r;\n\
    \ }\n std::vector<Node> ns;\npublic:\n LinkCutTree(size_t n): ns(n) {}\n LinkCutTree(size_t\
    \ n, T val): ns(n) {\n  for (int i= n; i--;) ns[i].val= val;\n }\n void evert(int\
    \ k) { expose(k), toggle(k), push(k); }\n void link(int c, int p) {\n  evert(c),\
    \ expose(p), assert(ns[c].par == -1), ns[p].ch[1]= c, ns[c].par= p;\n  if constexpr\
    \ (semigroup_v<M>) update(p);\n }\n void cut(int c, int p) {\n  evert(p), expose(c),\
    \ assert(ns[c].ch[0] == p), ns[c].ch[0]= ns[p].par= -1;\n  if constexpr (semigroup_v<M>)\
    \ update(c);\n }\n int root(int x) {\n  for (expose(x);; x= ns[x].ch[0])\n   if\
    \ (push(x); ns[x].ch[0] == -1) return splay(x), x;\n }\n int parent(int x) {\n\
    \  if (expose(x), x= ns[x].ch[0]; x == -1) return -1;\n  for (;; x= ns[x].ch[1])\n\
    \   if (push(x); ns[x].ch[1] == -1) return splay(x), x;\n }\n int lca(int x, int\
    \ y) { return x == y ? x : (expose(x), y= expose(y), ns[x].par == -1) ? -1 : y;\
    \ }\n const T &operator[](int k) { return get(k); }\n const T &get(int k) {\n\
    \  static_assert(semigroup_v<M> || dual_v<M>, \"\\\"get\\\" is not available\\\
    n\");\n  return expose(k), ns[k].val;\n }\n void set(int k, T v) {\n  static_assert(semigroup_v<M>\
    \ || dual_v<M>, \"\\\"set\\\" is not available\\n\");\n  expose(k), ns[k].val=\
    \ v;\n  if constexpr (semigroup_v<M>) update(k);\n }\n T fold(int a, int b) {\
    \  // [a,b] closed section\n  static_assert(semigroup_v<M>, \"\\\"fold\\\" is\
    \ not available\\n\");\n  return a == b ? get(a) : (evert(a), expose(b), assert(ns[a].par\
    \ != -1), ns[b].sum);\n }\n void apply(int a, int b, E v) {  // [a,b] closed section\n\
    \  static_assert(dual_v<M>, \"\\\"apply\\\" is not available\\n\");\n  evert(a),\
    \ expose(b), assert(a == b || ns[a].par != -1), propagate(b, v), push(b);\n }\n\
    \ static std::string which_available() {\n  std::string ret= \"\";\n  if constexpr\
    \ (semigroup_v<M> || dual_v<M>) ret+= \"\\\"set\\\" \\\"get\\\" \";\n  if constexpr\
    \ (semigroup_v<M>) ret+= \"\\\"fold\\\" \";\n  if constexpr (dual_v<M>) ret+=\
    \ \"\\\"apply\\\" \";\n  return ret;\n }\n};\n#line 8 \"test/atcoder/abc133_f.DynSeg.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n LinkCutTree lct(N);\n vector<tuple<int, int, int>>\
    \ adj[N];\n for (int i= 0; i < N - 1; i++) {\n  int a, b, c, d;\n  cin >> a >>\
    \ b >> c >> d;\n  lct.link(--a, --b);\n  adj[a].emplace_back(b, c, d);\n  adj[b].emplace_back(a,\
    \ c, d);\n }\n using PerArr= SegmentTree_Dynamic<int, true, 17>;\n PerArr Arr1[N],\
    \ Arr2[N];\n int sum[N];\n sum[0]= 0;\n auto dfs= [&adj, &Arr1, &Arr2, &sum](auto\
    \ f, int v, int p) -> void {\n  for (auto [u, c, d]: adj[v])\n   if (u != p) {\n\
    \    Arr1[u]= Arr1[v], Arr2[u]= Arr2[v];\n    Arr1[u][c]+= 1, Arr2[u][c]+= d;\n\
    \    sum[u]= sum[v] + d;\n    f(f, u, v);\n   }\n };\n dfs(dfs, 0, -1);\n lct.evert(0);\n\
    \ for (int i= 0; i < Q; i++) {\n  int x, y, u, v;\n  cin >> x >> y >> u >> v;\n\
    \  int lca= lct.lca(--u, --v);\n  cout << sum[u] + sum[v] - 2 * sum[lca] + y *\
    \ (Arr1[u].get(x) + Arr1[v].get(x) - 2 * Arr1[lca].get(x)) - (Arr2[u].get(x) +\
    \ Arr2[v].get(x) - 2 * Arr2[lca].get(x)) << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n//\
    \ \u6C38\u7D9A\u914D\u5217(at) \u306E verify\n#include <iostream>\n#include <vector>\n\
    #include <tuple>\n#include \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include\
    \ \"src/DataStructure/LinkCutTree.hpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >> Q;\n LinkCutTree\
    \ lct(N);\n vector<tuple<int, int, int>> adj[N];\n for (int i= 0; i < N - 1; i++)\
    \ {\n  int a, b, c, d;\n  cin >> a >> b >> c >> d;\n  lct.link(--a, --b);\n  adj[a].emplace_back(b,\
    \ c, d);\n  adj[b].emplace_back(a, c, d);\n }\n using PerArr= SegmentTree_Dynamic<int,\
    \ true, 17>;\n PerArr Arr1[N], Arr2[N];\n int sum[N];\n sum[0]= 0;\n auto dfs=\
    \ [&adj, &Arr1, &Arr2, &sum](auto f, int v, int p) -> void {\n  for (auto [u,\
    \ c, d]: adj[v])\n   if (u != p) {\n    Arr1[u]= Arr1[v], Arr2[u]= Arr2[v];\n\
    \    Arr1[u][c]+= 1, Arr2[u][c]+= d;\n    sum[u]= sum[v] + d;\n    f(f, u, v);\n\
    \   }\n };\n dfs(dfs, 0, -1);\n lct.evert(0);\n for (int i= 0; i < Q; i++) {\n\
    \  int x, y, u, v;\n  cin >> x >> y >> u >> v;\n  int lca= lct.lca(--u, --v);\n\
    \  cout << sum[u] + sum[v] - 2 * sum[lca] + y * (Arr1[u].get(x) + Arr1[v].get(x)\
    \ - 2 * Arr1[lca].get(x)) - (Arr2[u].get(x) + Arr2[v].get(x) - 2 * Arr2[lca].get(x))\
    \ << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Dynamic.hpp
  - src/Internal/HAS_CHECK.hpp
  - src/DataStructure/LinkCutTree.hpp
  isVerificationFile: true
  path: test/atcoder/abc133_f.DynSeg.test.cpp
  requiredBy: []
  timestamp: '2023-10-29 20:17:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc133_f.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc133_f.DynSeg.test.cpp
- /verify/test/atcoder/abc133_f.DynSeg.test.cpp.html
title: test/atcoder/abc133_f.DynSeg.test.cpp
---
