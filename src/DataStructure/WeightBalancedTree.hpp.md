---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.WBT.test.cpp
    title: test/aoj/1508.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3024.WBT.test.cpp
    title: test/aoj/3024.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256_f.WBT.test.cpp
    title: test/atcoder/abc256_f.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.WBT.test.cpp
    title: test/yosupo/persistent_queue.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.WBT.test.cpp
    title: test/yosupo/range_affine_range_sum.WBT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/WeightBalancedTree.hpp\"\n#include <vector>\n\
    #include <array>\n#include <string>\n#include <tuple>\n#include <cstddef>\n#include\
    \ <cassert>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define HAS_CHECK(member, Dummy) \\\n template <class tClass> struct has_##member\
    \ { \\\n  template <class U, Dummy> static std::true_type check(U *); \\\n  static\
    \ std::false_type check(...); \\\n  static tClass *mClass; \\\n  static const\
    \ bool value= decltype(check(mClass))::value; \\\n };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#line 9 \"src/DataStructure/WeightBalancedTree.hpp\"\
    \ntemplate <typename M, std::size_t NODE_SIZE= 1 << 23> class WeightBalancedTree\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n HAS_TYPE(T);\n\
    \ HAS_TYPE(E);\n template <class L> static constexpr bool semigroup_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n using node_id= std::int_least32_t;\n\
    \ template <class T, class F= std::nullptr_t> struct Node_B {\n  using E= F;\n\
    \  T val;\n  std::size_t size= 0;\n  node_id ch[2]= {0, 0};\n };\n template <class\
    \ D, bool sg, bool du> struct Node_D: Node_B<typename M::T, typename M::E> {\n\
    \  typename M::E lazy;\n  bool lazy_flg= false;\n };\n template <class D> struct\
    \ Node_D<D, 1, 0>: Node_B<typename M::T> {};\n template <class D> struct Node_D<D,\
    \ 0, 0>: Node_B<M> {};\n using Node= Node_D<void, semigroup_v<M>, dual_v<M>>;\n\
    \ using T= decltype(Node::val);\n using E= typename Node::E;\n using WBT= WeightBalancedTree;\n\
    \ static inline Node n[NODE_SIZE];\n static inline node_id ni= 1;\n node_id root;\n\
    \ static inline void pushup(node_id t) {\n  n[t].size= n[n[t].ch[0]].size + n[n[t].ch[1]].size;\n\
    \  if constexpr (semigroup_v<M>) n[t].val= M::op(n[n[t].ch[0]].val, n[n[t].ch[1]].val);\n\
    \ }\n static inline T &reflect(node_id t) {\n  if constexpr (dual_v<M> && !semigroup_v<M>)\n\
    \   if (n[t].lazy_flg) M::mapping(n[t].val, n[t].lazy, 1), n[t].lazy_flg= false;\n\
    \  return n[t].val;\n }\n static inline void propagate(node_id t, const E &x)\
    \ {\n  n[t].lazy_flg ? (M::composition(n[t].lazy, x), x) : n[t].lazy= x;\n  if\
    \ constexpr (semigroup_v<M>) M::mapping(n[t].val, x, n[t].size);\n  n[t].lazy_flg=\
    \ true;\n }\n static inline void cp_node(node_id &t) { n[t= ni++]= Node(n[t]);\
    \ }\n static inline void eval(node_id t) {\n  if (!n[t].lazy_flg) return;\n  cp_node(n[t].ch[0]),\
    \ cp_node(n[t].ch[1]), n[t].lazy_flg= false;\n  propagate(n[t].ch[0], n[t].lazy),\
    \ propagate(n[t].ch[1], n[t].lazy);\n }\n template <bool b> static inline node_id\
    \ helper(std::array<node_id, 2> &m) {\n  if constexpr (dual_v<M>) eval(m[b]);\n\
    \  node_id c;\n  if constexpr (b) c= submerge({m[0], n[m[1]].ch[0]});\n  else\
    \ c= submerge({n[m[0]].ch[1], m[1]});\n  if (cp_node(m[b]), n[n[m[b]].ch[b]].size\
    \ * 4 >= n[c].size) return n[m[b]].ch[!b]= c, pushup(m[b]), m[b];\n  return n[m[b]].ch[!b]=\
    \ n[c].ch[b], pushup(n[c].ch[b]= m[b]), pushup(c), c;\n }\n static inline node_id\
    \ submerge(std::array<node_id, 2> m) {\n  if (n[m[0]].size > n[m[1]].size * 4)\
    \ return helper<0>(m);\n  if (n[m[1]].size > n[m[0]].size * 4) return helper<1>(m);\n\
    \  return n[ni]= Node{T(), 0, {m[0], m[1]}}, pushup(ni), ni++;\n }\n static inline\
    \ node_id merge(node_id l, node_id r) { return !l ? r : (!r ? l : submerge({l,\
    \ r})); }\n static inline std::pair<node_id, node_id> split(node_id t, std::size_t\
    \ k) {\n  if (!t) return {0, 0};\n  if (k == 0) return {0, t};\n  if (k >= n[t].size)\
    \ return {t, 0};\n  if constexpr (dual_v<M>) eval(t);\n  if (k == n[n[t].ch[0]].size)\
    \ return {n[t].ch[0], n[t].ch[1]};\n  if (k < n[n[t].ch[0]].size) {\n   auto [ll,\
    \ m]= split(n[t].ch[0], k);\n   return {ll, merge(m, n[t].ch[1])};\n  } else {\n\
    \   auto [rl, rr]= split(n[t].ch[1], k - n[n[t].ch[0]].size);\n   return {merge(n[t].ch[0],\
    \ rl), rr};\n  }\n }\n template <class S> node_id build(std::size_t l, std::size_t\
    \ r, const S &bg) {\n  if (r - l == 1) {\n   if constexpr (std::is_same_v<S, T>)\
    \ return n[ni]= Node{bg, 1}, ni++;\n   else return n[ni]= Node{*(bg + l), 1},\
    \ ni++;\n  }\n  return merge(build(l, (l + r) >> 1, bg), build((l + r) >> 1, r,\
    \ bg));\n }\n void dump(node_id t, typename std::vector<T>::iterator it) {\n \
    \ if (!n[t].ch[0]) return *it= reflect(t), void();\n  if constexpr (dual_v<M>)\
    \ eval(t);\n  dump(n[t].ch[0], it), dump(n[t].ch[1], it + n[n[t].ch[0]].size);\n\
    \ }\n T fold(node_id t, const std::size_t &l, const std::size_t &r, std::size_t\
    \ bl, std::size_t br) {\n  if (l <= bl && br <= r) return n[t].val;\n  if constexpr\
    \ (dual_v<M>) eval(t);\n  std::size_t m= bl + n[n[t].ch[0]].size;\n  if (r <=\
    \ m) return fold(n[t].ch[0], l, r, bl, m);\n  if (m <= l) return fold(n[t].ch[1],\
    \ l, r, m, br);\n  return M::op(fold(n[t].ch[0], l, r, bl, m), fold(n[t].ch[1],\
    \ l, r, m, br));\n }\n void apply(node_id &t, const std::size_t &l, const std::size_t\
    \ &r, std::size_t bl, std::size_t br, const E &x) {\n  if (r <= bl || br <= l)\
    \ return;\n  if (cp_node(t); l <= bl && br <= r) return propagate(t, x), void();\n\
    \  eval(t);\n  std::size_t m= bl + n[n[t].ch[0]].size;\n  apply(n[t].ch[0], l,\
    \ r, bl, m, x), apply(n[t].ch[1], l, r, m, br, x);\n  if constexpr (semigroup_v<M>)\
    \ pushup(t);\n }\n void set_val(node_id &t, std::size_t k, const T &x) {\n  if\
    \ (cp_node(t); !n[t].ch[0]) return reflect(t)= x, void();\n  if constexpr (dual_v<M>)\
    \ eval(t);\n  bool flg= n[n[t].ch[0]].size <= k;\n  set_val(n[t].ch[flg], flg\
    \ ? k - n[n[t].ch[0]].size : k, x);\n  if constexpr (semigroup_v<M>) pushup(t);\n\
    \ }\n T get_val(node_id t, std::size_t k) {\n  if (!n[t].ch[0]) return reflect(t);\n\
    \  if constexpr (dual_v<M>) eval(t);\n  bool flg= n[n[t].ch[0]].size <= k;\n \
    \ return get_val(n[t].ch[flg], flg ? k - n[n[t].ch[0]].size : k);\n }\n T &at_val(node_id\
    \ t, std::size_t k) {\n  if (cp_node(t); !n[t].ch[0]) return reflect(t);\n  if\
    \ constexpr (dual_v<M>) eval(t);\n  bool flg= n[n[t].ch[0]].size <= k;\n  return\
    \ at_val(n[t].ch[flg], flg ? k - n[n[t].ch[0]].size : k);\n }\n static WBT id_to_wbt(node_id\
    \ t) {\n  WBT ret;\n  return ret.root= t, ret;\n }\npublic:\n WeightBalancedTree():\
    \ root(0) {}\n WeightBalancedTree(std::size_t n, T val= T()) { root= build(0,\
    \ n, val); }\n WeightBalancedTree(const T *bg, const T *ed) { root= build(0, ed\
    \ - bg, bg); }\n WeightBalancedTree(const std::vector<T> &ar): WeightBalancedTree(ar.data(),\
    \ ar.data() + ar.size()){};\n WBT &operator+=(WBT rhs) { return root= merge(root,\
    \ rhs.root), *this; }\n WBT operator+(WBT rhs) { return WBT(*this)+= rhs; }\n\
    \ std::pair<WBT, WBT> split(std::size_t k) {\n  auto [l, r]= split(root, k);\n\
    \  return {id_to_wbt(l), id_to_wbt(r)};\n }\n std::tuple<WBT, WBT, WBT> split3(std::size_t\
    \ a, std::size_t b) {\n  auto [tmp, r]= split(root, b);\n  auto [l, c]= split(tmp,\
    \ a);\n  return {id_to_wbt(l), id_to_wbt(c), id_to_wbt(r)};\n }\n void push_back(T\
    \ val) { n[ni]= Node{val, 1}, root= merge(root, ni++); }\n void push_front(T val)\
    \ { n[ni]= Node{val, 1}, root= merge(ni++, root); }\n void insert(std::size_t\
    \ k, T val) {\n  auto [l, r]= split(root, k);\n  n[ni]= Node{val, 1}, root= merge(merge(l,\
    \ ni++), r);\n }\n T pop_back() {\n  assert(root);\n  auto [l, t]= split(root,\
    \ size() - 1);\n  return root= l, reflect(t);\n }\n T pop_front() {\n  assert(root);\n\
    \  auto [t, r]= split(root, 1);\n  return root= r, reflect(t);\n }\n T erase(std::size_t\
    \ k) {\n  assert(k < size());\n  auto [l, tmp]= split(root, k);\n  auto [t, r]=\
    \ split(tmp, 1);\n  return root= merge(l, r), reflect(t);\n }\n void set(std::size_t\
    \ k, T val) { set_val(root, k, val); }\n T get(std::size_t k) { return get_val(root,\
    \ k); }\n T &at(std::size_t k) {\n  static_assert(!semigroup_v<M>, \"\\\"at\\\"\
    \ is not available\\n\");\n  return at_val(root, k);\n }\n template <class L=\
    \ M> std::enable_if_t<semigroup_v<L>, T> operator[](std::size_t k) { return get(k);\
    \ }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](std::size_t\
    \ k) { return at(k); }\n T fold(std::size_t a, std::size_t b) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return fold(root, a, b, 0, size());\n\
    \ }\n void apply(std::size_t a, std::size_t b, E x) {\n  static_assert(dual_v<M>,\
    \ \"\\\"apply\\\" is not available\\n\");\n  apply(root, a, b, 0, size(), x);\n\
    \ }\n std::size_t size() { return n[root].size; }\n std::vector<T> dump() {\n\
    \  if (!root) return std::vector<T>();\n  std::vector<T> ret(size());\n  return\
    \ dump(root, ret.begin()), ret;\n }\n void clear() { root= 0; }\n static void\
    \ reset() { ni= 1; }\n void rebuild() {\n  auto dmp= dump();\n  reset(), *this=\
    \ WBT(dmp);\n }\n static std::string which_available() {\n  std::string ret= \"\
    \";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"fold\\\" \";\n  else ret+= \"\
    \\\"at\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return\
    \ ret;\n }\n static double percentage_used() { return 100. * ni / NODE_SIZE; }\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <array>\n#include <string>\n#include\
    \ <tuple>\n#include <cstddef>\n#include <cassert>\n#include \"src/Internal/HAS_CHECK.hpp\"\
    \ntemplate <typename M, std::size_t NODE_SIZE= 1 << 23> class WeightBalancedTree\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n HAS_TYPE(T);\n\
    \ HAS_TYPE(E);\n template <class L> static constexpr bool semigroup_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n using node_id= std::int_least32_t;\n\
    \ template <class T, class F= std::nullptr_t> struct Node_B {\n  using E= F;\n\
    \  T val;\n  std::size_t size= 0;\n  node_id ch[2]= {0, 0};\n };\n template <class\
    \ D, bool sg, bool du> struct Node_D: Node_B<typename M::T, typename M::E> {\n\
    \  typename M::E lazy;\n  bool lazy_flg= false;\n };\n template <class D> struct\
    \ Node_D<D, 1, 0>: Node_B<typename M::T> {};\n template <class D> struct Node_D<D,\
    \ 0, 0>: Node_B<M> {};\n using Node= Node_D<void, semigroup_v<M>, dual_v<M>>;\n\
    \ using T= decltype(Node::val);\n using E= typename Node::E;\n using WBT= WeightBalancedTree;\n\
    \ static inline Node n[NODE_SIZE];\n static inline node_id ni= 1;\n node_id root;\n\
    \ static inline void pushup(node_id t) {\n  n[t].size= n[n[t].ch[0]].size + n[n[t].ch[1]].size;\n\
    \  if constexpr (semigroup_v<M>) n[t].val= M::op(n[n[t].ch[0]].val, n[n[t].ch[1]].val);\n\
    \ }\n static inline T &reflect(node_id t) {\n  if constexpr (dual_v<M> && !semigroup_v<M>)\n\
    \   if (n[t].lazy_flg) M::mapping(n[t].val, n[t].lazy, 1), n[t].lazy_flg= false;\n\
    \  return n[t].val;\n }\n static inline void propagate(node_id t, const E &x)\
    \ {\n  n[t].lazy_flg ? (M::composition(n[t].lazy, x), x) : n[t].lazy= x;\n  if\
    \ constexpr (semigroup_v<M>) M::mapping(n[t].val, x, n[t].size);\n  n[t].lazy_flg=\
    \ true;\n }\n static inline void cp_node(node_id &t) { n[t= ni++]= Node(n[t]);\
    \ }\n static inline void eval(node_id t) {\n  if (!n[t].lazy_flg) return;\n  cp_node(n[t].ch[0]),\
    \ cp_node(n[t].ch[1]), n[t].lazy_flg= false;\n  propagate(n[t].ch[0], n[t].lazy),\
    \ propagate(n[t].ch[1], n[t].lazy);\n }\n template <bool b> static inline node_id\
    \ helper(std::array<node_id, 2> &m) {\n  if constexpr (dual_v<M>) eval(m[b]);\n\
    \  node_id c;\n  if constexpr (b) c= submerge({m[0], n[m[1]].ch[0]});\n  else\
    \ c= submerge({n[m[0]].ch[1], m[1]});\n  if (cp_node(m[b]), n[n[m[b]].ch[b]].size\
    \ * 4 >= n[c].size) return n[m[b]].ch[!b]= c, pushup(m[b]), m[b];\n  return n[m[b]].ch[!b]=\
    \ n[c].ch[b], pushup(n[c].ch[b]= m[b]), pushup(c), c;\n }\n static inline node_id\
    \ submerge(std::array<node_id, 2> m) {\n  if (n[m[0]].size > n[m[1]].size * 4)\
    \ return helper<0>(m);\n  if (n[m[1]].size > n[m[0]].size * 4) return helper<1>(m);\n\
    \  return n[ni]= Node{T(), 0, {m[0], m[1]}}, pushup(ni), ni++;\n }\n static inline\
    \ node_id merge(node_id l, node_id r) { return !l ? r : (!r ? l : submerge({l,\
    \ r})); }\n static inline std::pair<node_id, node_id> split(node_id t, std::size_t\
    \ k) {\n  if (!t) return {0, 0};\n  if (k == 0) return {0, t};\n  if (k >= n[t].size)\
    \ return {t, 0};\n  if constexpr (dual_v<M>) eval(t);\n  if (k == n[n[t].ch[0]].size)\
    \ return {n[t].ch[0], n[t].ch[1]};\n  if (k < n[n[t].ch[0]].size) {\n   auto [ll,\
    \ m]= split(n[t].ch[0], k);\n   return {ll, merge(m, n[t].ch[1])};\n  } else {\n\
    \   auto [rl, rr]= split(n[t].ch[1], k - n[n[t].ch[0]].size);\n   return {merge(n[t].ch[0],\
    \ rl), rr};\n  }\n }\n template <class S> node_id build(std::size_t l, std::size_t\
    \ r, const S &bg) {\n  if (r - l == 1) {\n   if constexpr (std::is_same_v<S, T>)\
    \ return n[ni]= Node{bg, 1}, ni++;\n   else return n[ni]= Node{*(bg + l), 1},\
    \ ni++;\n  }\n  return merge(build(l, (l + r) >> 1, bg), build((l + r) >> 1, r,\
    \ bg));\n }\n void dump(node_id t, typename std::vector<T>::iterator it) {\n \
    \ if (!n[t].ch[0]) return *it= reflect(t), void();\n  if constexpr (dual_v<M>)\
    \ eval(t);\n  dump(n[t].ch[0], it), dump(n[t].ch[1], it + n[n[t].ch[0]].size);\n\
    \ }\n T fold(node_id t, const std::size_t &l, const std::size_t &r, std::size_t\
    \ bl, std::size_t br) {\n  if (l <= bl && br <= r) return n[t].val;\n  if constexpr\
    \ (dual_v<M>) eval(t);\n  std::size_t m= bl + n[n[t].ch[0]].size;\n  if (r <=\
    \ m) return fold(n[t].ch[0], l, r, bl, m);\n  if (m <= l) return fold(n[t].ch[1],\
    \ l, r, m, br);\n  return M::op(fold(n[t].ch[0], l, r, bl, m), fold(n[t].ch[1],\
    \ l, r, m, br));\n }\n void apply(node_id &t, const std::size_t &l, const std::size_t\
    \ &r, std::size_t bl, std::size_t br, const E &x) {\n  if (r <= bl || br <= l)\
    \ return;\n  if (cp_node(t); l <= bl && br <= r) return propagate(t, x), void();\n\
    \  eval(t);\n  std::size_t m= bl + n[n[t].ch[0]].size;\n  apply(n[t].ch[0], l,\
    \ r, bl, m, x), apply(n[t].ch[1], l, r, m, br, x);\n  if constexpr (semigroup_v<M>)\
    \ pushup(t);\n }\n void set_val(node_id &t, std::size_t k, const T &x) {\n  if\
    \ (cp_node(t); !n[t].ch[0]) return reflect(t)= x, void();\n  if constexpr (dual_v<M>)\
    \ eval(t);\n  bool flg= n[n[t].ch[0]].size <= k;\n  set_val(n[t].ch[flg], flg\
    \ ? k - n[n[t].ch[0]].size : k, x);\n  if constexpr (semigroup_v<M>) pushup(t);\n\
    \ }\n T get_val(node_id t, std::size_t k) {\n  if (!n[t].ch[0]) return reflect(t);\n\
    \  if constexpr (dual_v<M>) eval(t);\n  bool flg= n[n[t].ch[0]].size <= k;\n \
    \ return get_val(n[t].ch[flg], flg ? k - n[n[t].ch[0]].size : k);\n }\n T &at_val(node_id\
    \ t, std::size_t k) {\n  if (cp_node(t); !n[t].ch[0]) return reflect(t);\n  if\
    \ constexpr (dual_v<M>) eval(t);\n  bool flg= n[n[t].ch[0]].size <= k;\n  return\
    \ at_val(n[t].ch[flg], flg ? k - n[n[t].ch[0]].size : k);\n }\n static WBT id_to_wbt(node_id\
    \ t) {\n  WBT ret;\n  return ret.root= t, ret;\n }\npublic:\n WeightBalancedTree():\
    \ root(0) {}\n WeightBalancedTree(std::size_t n, T val= T()) { root= build(0,\
    \ n, val); }\n WeightBalancedTree(const T *bg, const T *ed) { root= build(0, ed\
    \ - bg, bg); }\n WeightBalancedTree(const std::vector<T> &ar): WeightBalancedTree(ar.data(),\
    \ ar.data() + ar.size()){};\n WBT &operator+=(WBT rhs) { return root= merge(root,\
    \ rhs.root), *this; }\n WBT operator+(WBT rhs) { return WBT(*this)+= rhs; }\n\
    \ std::pair<WBT, WBT> split(std::size_t k) {\n  auto [l, r]= split(root, k);\n\
    \  return {id_to_wbt(l), id_to_wbt(r)};\n }\n std::tuple<WBT, WBT, WBT> split3(std::size_t\
    \ a, std::size_t b) {\n  auto [tmp, r]= split(root, b);\n  auto [l, c]= split(tmp,\
    \ a);\n  return {id_to_wbt(l), id_to_wbt(c), id_to_wbt(r)};\n }\n void push_back(T\
    \ val) { n[ni]= Node{val, 1}, root= merge(root, ni++); }\n void push_front(T val)\
    \ { n[ni]= Node{val, 1}, root= merge(ni++, root); }\n void insert(std::size_t\
    \ k, T val) {\n  auto [l, r]= split(root, k);\n  n[ni]= Node{val, 1}, root= merge(merge(l,\
    \ ni++), r);\n }\n T pop_back() {\n  assert(root);\n  auto [l, t]= split(root,\
    \ size() - 1);\n  return root= l, reflect(t);\n }\n T pop_front() {\n  assert(root);\n\
    \  auto [t, r]= split(root, 1);\n  return root= r, reflect(t);\n }\n T erase(std::size_t\
    \ k) {\n  assert(k < size());\n  auto [l, tmp]= split(root, k);\n  auto [t, r]=\
    \ split(tmp, 1);\n  return root= merge(l, r), reflect(t);\n }\n void set(std::size_t\
    \ k, T val) { set_val(root, k, val); }\n T get(std::size_t k) { return get_val(root,\
    \ k); }\n T &at(std::size_t k) {\n  static_assert(!semigroup_v<M>, \"\\\"at\\\"\
    \ is not available\\n\");\n  return at_val(root, k);\n }\n template <class L=\
    \ M> std::enable_if_t<semigroup_v<L>, T> operator[](std::size_t k) { return get(k);\
    \ }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](std::size_t\
    \ k) { return at(k); }\n T fold(std::size_t a, std::size_t b) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return fold(root, a, b, 0, size());\n\
    \ }\n void apply(std::size_t a, std::size_t b, E x) {\n  static_assert(dual_v<M>,\
    \ \"\\\"apply\\\" is not available\\n\");\n  apply(root, a, b, 0, size(), x);\n\
    \ }\n std::size_t size() { return n[root].size; }\n std::vector<T> dump() {\n\
    \  if (!root) return std::vector<T>();\n  std::vector<T> ret(size());\n  return\
    \ dump(root, ret.begin()), ret;\n }\n void clear() { root= 0; }\n static void\
    \ reset() { ni= 1; }\n void rebuild() {\n  auto dmp= dump();\n  reset(), *this=\
    \ WBT(dmp);\n }\n static std::string which_available() {\n  std::string ret= \"\
    \";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"fold\\\" \";\n  else ret+= \"\
    \\\"at\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return\
    \ ret;\n }\n static double percentage_used() { return 100. * ni / NODE_SIZE; }\n\
    };"
  dependsOn:
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/DataStructure/WeightBalancedTree.hpp
  requiredBy: []
  timestamp: '2023-02-10 18:24:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.WBT.test.cpp
  - test/yosupo/range_affine_range_sum.WBT.test.cpp
  - test/aoj/3024.WBT.test.cpp
  - test/aoj/1508.WBT.test.cpp
  - test/atcoder/abc256_f.WBT.test.cpp
documentation_of: src/DataStructure/WeightBalancedTree.hpp
layout: document
title: "\u6C38\u7D9AWeight-Balanced-Tree"
---
永続平衡二分木 \
※これは永続化（逆に非永続にできるようにしてない）\
単位元は必要なし（遅延側も）\
各ノードが葉のサイズを保持しているのでmapping関数では引数としてsizeを渡せる 
## 計算量
$\mathcal{O}(\log N)$
## 問題例
[2012年 日本情報オリンピック春合宿 copypaste - コピー＆ペースト](https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste) (永続) \
[AtCoder Regular Contest 030 D - グラフではない](https://atcoder.jp/contests/arc030/tasks/arc030_4) (永続遅延伝搬)