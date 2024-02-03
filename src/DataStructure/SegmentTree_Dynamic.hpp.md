---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.DynSeg.test.cpp
    title: test/aoj/2270.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3024.DynSeg.test.cpp
    title: test/aoj/3024.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.DynSeg.test.cpp
    title: test/aoj/DSL_2_I.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.DynSeg.test.cpp
    title: test/atcoder/abc133_f.DynSeg.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc256_f.DynSeg.test.cpp
    title: test/atcoder/abc256_f.DynSeg.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
    title: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.DynSeg.test.cpp
    title: test/yosupo/set_xor_min.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.DynSeg.test.cpp
    title: test/yukicoder/649.DynSeg.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include <array>\n\
    #include <vector>\n#include <string>\n#include <algorithm>\n#include <tuple>\n\
    #include <cstddef>\n#include <cstdint>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\
    \n#include <type_traits>\n#define MEMBER_MACRO(member, Dummy, name, type1, type2,\
    \ last) \\\n template <class tClass> struct name##member { \\\n  template <class\
    \ U, Dummy> static type1 check(U *); \\\n  static type2 check(...); \\\n  static\
    \ tClass *mClass; \\\n  last; \\\n }\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member,\
    \ Dummy, has_, std::true_type, std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)));\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t)\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass)\n#line 10 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\
    \ntemplate <typename M, bool persistent= false, uint8_t HEIGHT= 31> class SegmentTree_Dynamic\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(ti);\n HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n\
    \ HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(E);\n template <class L> static constexpr\
    \ bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;\n template\
    \ <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>, has_E<L>,\
    \ has_mp<L>, has_cp<L>>;\n using id_t= long long;\n template <class T, class tDerived>\
    \ struct Node_B {\n  T val;\n  tDerived *ch[2]= {nullptr, nullptr};\n };\n template\
    \ <bool mo, bool du, typename tEnable= void> struct Node_D: Node_B<M, Node_D<mo,\
    \ du, tEnable>> {};\n template <bool mo, bool du> struct Node_D<mo, du, typename\
    \ std::enable_if_t<mo && !du>>: Node_B<typename M::T, Node_D<mo, du>> {};\n template\
    \ <bool mo, bool du> struct Node_D<mo, du, typename std::enable_if_t<du>>: Node_B<typename\
    \ M::T, Node_D<mo, du>> {\n  typename M::E lazy;\n  bool lazy_flg= false;\n };\n\
    \ using Node= Node_D<monoid_v<M>, dual_v<M>>;\n using T= decltype(Node::val);\n\
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
    \ constexpr (dual_v<M> && !monoid_v<M>)\n   if (t->lazy_flg) M::mp(t->val, t->lazy,\
    \ 1), t->lazy_flg= false;\n  return t->val;\n }\n static inline void propagate(np\
    \ &t, const E &x, const id_t &sz) {\n  t->lazy_flg ? (M::cp(t->lazy, x), x) :\
    \ t->lazy= x;\n  t->lazy_flg= true;\n  if constexpr (monoid_v<M>) M::mp(t->val,\
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
    \ {}\n SegmentTree_Dynamic(std::size_t n, T val): root(build(n, 0, 1LL << HEIGHT,\
    \ val)) {}\n SegmentTree_Dynamic(const T *bg, const T *ed): root(build(ed - bg,\
    \ 0, 1LL << HEIGHT, bg)) {}\n SegmentTree_Dynamic(const std::vector<T> &ar): SegmentTree_Dynamic(ar.data(),\
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
    \ ret+= \"\\\"apply\\\" \";\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include <string>\n#include\
    \ <algorithm>\n#include <tuple>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ \"src/Internal/HAS_CHECK.hpp\"\ntemplate <typename M, bool persistent= false,\
    \ uint8_t HEIGHT= 31> class SegmentTree_Dynamic {\n HAS_MEMBER(op);\n HAS_MEMBER(ti);\n\
    \ HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(E);\n\
    \ template <class L> static constexpr bool monoid_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>, has_ti<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mp<L>, has_cp<L>>;\n using id_t= long long;\n template <class\
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
    \ constexpr (dual_v<M> && !monoid_v<M>)\n   if (t->lazy_flg) M::mp(t->val, t->lazy,\
    \ 1), t->lazy_flg= false;\n  return t->val;\n }\n static inline void propagate(np\
    \ &t, const E &x, const id_t &sz) {\n  t->lazy_flg ? (M::cp(t->lazy, x), x) :\
    \ t->lazy= x;\n  t->lazy_flg= true;\n  if constexpr (monoid_v<M>) M::mp(t->val,\
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
    \ {}\n SegmentTree_Dynamic(std::size_t n, T val): root(build(n, 0, 1LL << HEIGHT,\
    \ val)) {}\n SegmentTree_Dynamic(const T *bg, const T *ed): root(build(ed - bg,\
    \ 0, 1LL << HEIGHT, bg)) {}\n SegmentTree_Dynamic(const std::vector<T> &ar): SegmentTree_Dynamic(ar.data(),\
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
    \ ret+= \"\\\"apply\\\" \";\n  return ret;\n }\n};"
  dependsOn:
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Dynamic.hpp
  requiredBy: []
  timestamp: '2023-11-02 17:27:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/649.DynSeg.test.cpp
  - test/aoj/DSL_2_I.DynSeg.test.cpp
  - test/aoj/2270.DynSeg.test.cpp
  - test/aoj/3024.DynSeg.test.cpp
  - test/atcoder/abc133_f.DynSeg.test.cpp
  - test/atcoder/abc256_f.DynSeg.test.cpp
  - test/yosupo/set_xor_min.DynSeg.test.cpp
  - test/yosupo/range_affine_range_sum.DynSeg.test.cpp
documentation_of: src/DataStructure/SegmentTree_Dynamic.hpp
layout: document
title: "Segment-Tree(\u52D5\u7684\u69CB\u7BC9)"
---
遅延伝搬可 \
永続化可
## 計算量
$\mathcal{O}(\log N)$
## 問題例
[Codeforces Round #265 (Div. 1) E. The Classic Problem](https://codeforces.com/contest/464/problem/E) (永続+遅延伝搬+find+find) \
[Codeforces Round #470 (rated, Div. 1, based on VK Cup 2018 Round 1) C. Perfect Security](https://codeforces.com/contest/947/problem/C) (find+xor) \
[Codeforces Round #477 (rated, Div. 1, based on VK Cup 2018 Round 3) C. Big Secret](https://codeforces.com/contest/966/problem/C) (find+xor) \
[Codeforces Round #179 (Div. 1) E. Yaroslav and Points](https://codeforces.com/contest/295/problem/E) (特殊モノイド+座圧サボり) \
[HackerRank Happy Query Contest 2019 Minimum History Query](https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query) (永続) \
[CodeChef Gotham PD](https://www.codechef.com/problems/GPD) (永続, xor)\
[CodeChef Pishty and tree](https://www.codechef.com/problems/PSHTTR) (永続)