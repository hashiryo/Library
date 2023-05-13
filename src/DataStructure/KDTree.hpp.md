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
    path: test/aoj/1068.KDT.test.cpp
    title: test/aoj/1068.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.KDT.test.cpp
    title: test/aoj/2842.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.KDT.test.cpp
    title: test/aoj/DSL_2_C.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/hackerrank/cube-summation.KDT.test.cpp
    title: test/hackerrank/cube-summation.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
    title: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625.KDT.test.cpp
    title: test/yukicoder/1625.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/728.KDT.test.cpp
    title: test/yukicoder/728.KDT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/KDTree.hpp\"\n#include <array>\n#include\
    \ <vector>\n#include <algorithm>\n#include <tuple>\n#include <cstddef>\n#include\
    \ <cassert>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define HAS_CHECK(member, Dummy) \\\n template <class tClass> struct has_##member\
    \ { \\\n  template <class U, Dummy> static std::true_type check(U *); \\\n  static\
    \ std::false_type check(...); \\\n  static tClass *mClass; \\\n  static const\
    \ bool value= decltype(check(mClass))::value; \\\n };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#line 9 \"src/DataStructure/KDTree.hpp\"\n\
    template <std::uint8_t K, class pos_t, class M> class KDTree {\n HAS_MEMBER(op);\n\
    \ HAS_MEMBER(ti);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n HAS_TYPE(T);\n\
    \ HAS_TYPE(E);\n template <class L> using monoid= std::conjunction<has_T<L>, has_op<L>,\
    \ has_ti<L>>;\n template <class L> using dual= std::conjunction<has_T<L>, has_E<L>,\
    \ has_mapping<L>, has_composition<L>>;\n template <class T, class F= std::nullptr_t>\
    \ struct Node_B {\n  using E= F;\n  T val;\n  int ch[2]= {-1, -1};\n  pos_t range[K][2],\
    \ pos[K];\n };\n template <bool sg_, bool du_, typename tEnable= void> struct\
    \ Node_D: Node_B<M> {};\n template <bool sg_, bool du_> struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && !du_>>: Node_B<typename M::T> { typename M::T\
    \ sum; };\n template <bool sg_, bool du_> struct Node_D<sg_, du_, typename std::enable_if_t<!sg_\
    \ && du_>>: Node_B<typename M::T, typename M::E> {\n  typename M::E lazy;\n  bool\
    \ lazy_flg= false;\n };\n template <bool sg_, bool du_> struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && du_>>: Node_B<typename M::T, typename M::E>\
    \ {\n  typename M::T sum;\n  typename M::E lazy;\n  bool lazy_flg= false;\n };\n\
    \ using Node= Node_D<monoid<M>::value, dual<M>::value>;\n using T= decltype(Node::val);\n\
    \ using E= typename Node::E;\n std::vector<Node> ns;\npublic:\n using PosVal=\
    \ std::pair<std::array<pos_t, K>, T>;\n using Iter= typename std::vector<PosVal>::iterator;\n\
    \ using Range= std::array<std::array<pos_t, 2>, K>;\nprivate:\n inline void pushup(int\
    \ i) {\n  ns[i].sum= ns[i].val;\n  if (ns[i].ch[0] != -1) ns[i].sum= M::op(ns[ns[i].ch[0]].sum,\
    \ ns[i].sum);\n  if (ns[i].ch[1] != -1) ns[i].sum= M::op(ns[i].sum, ns[ns[i].ch[1]].sum);\n\
    \ }\n inline void propagate(int i, const E &x) {\n  if (i == -1) return;\n  ns[i].lazy_flg\
    \ ? (M::composition(ns[i].lazy, x), x) : (ns[i].lazy= x);\n  M::mapping(ns[i].val,\
    \ x), ns[i].lazy_flg= true;\n  if constexpr (monoid<M>::value) M::mapping(ns[i].sum,\
    \ x);\n }\n inline void eval(int i) {\n  if (!ns[i].lazy_flg) return;\n  ns[i].lazy_flg=\
    \ false;\n  propagate(ns[i].ch[0], ns[i].lazy), propagate(ns[i].ch[1], ns[i].lazy);\n\
    \ }\n inline void build(int &i, Iter bg, Iter ed, int &ts, std::uint8_t div= 0)\
    \ {\n  if (ed - bg < 1) return;\n  const int n= ed - bg;\n  auto md= bg + n /\
    \ 2;\n  std::nth_element(bg, md, ed, [div](const PosVal &l, const PosVal &r) {\
    \ return l.first[div] < r.first[div]; });\n  ns[i= ts++].val= md->second;\n  for\
    \ (std::uint8_t j= K; j--; ns[i].pos[j]= md->first[j]) {\n   auto [mn, mx]= std::minmax_element(bg,\
    \ ed, [j](const PosVal &l, const PosVal &r) { return l.first[j] < r.first[j];\
    \ });\n   ns[i].range[j][0]= mn->first[j], ns[i].range[j][1]= mx->first[j];\n\
    \  }\n  if (std::uint8_t nex= (div + 1) % K; n > 1) build(ns[i].ch[0], bg, md,\
    \ ts, nex), build(ns[i].ch[1], md + 1, ed, ts, nex);\n  if constexpr (monoid<M>::value)\
    \ pushup(i);\n }\n template <class F, class G, class H> inline T fold(int i, const\
    \ F &in, const G &inall, const H &outall) {\n  static_assert(monoid<M>::value,\
    \ \"\\\"fold\\\" is not available\");\n  if (i == -1 || outall(ns[i].range)) return\
    \ M::ti();\n  if (inall(ns[i].range)) return ns[i].sum;\n  if constexpr (dual<M>::value)\
    \ eval(i);\n  T ret= M::op(fold(ns[i].ch[0], in, inall, outall), fold(ns[i].ch[1],\
    \ in, inall, outall));\n  ret= in(ns[i].pos) ? M::op(ret, ns[i].val) : ret;\n\
    \  return ret;\n }\n template <class F, class G, class H> inline void apply(int\
    \ i, const F &in, const G &inall, const H &outall, const E &x) {\n  static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\");\n  if (i == -1 || outall(ns[i].range))\
    \ return;\n  if (inall(ns[i].range)) return propagate(i, x), void();\n  if (eval(i);\
    \ in(ns[i].pos)) M::mapping(ns[i].val, x);\n  apply(ns[i].ch[0], in, inall, outall,\
    \ x), apply(ns[i].ch[1], in, inall, outall, x);\n  if constexpr (monoid<M>::value)\
    \ pushup(i);\n }\n inline std::pair<T, bool> get(int i, const std::array<pos_t,\
    \ K> &pos) {\n  if (i == -1) return {T(), false};\n  bool myself= true;\n  for\
    \ (std::uint8_t j= K; j--; myself&= pos[j] == ns[i].pos[j])\n   if (ns[i].range[j][1]\
    \ < pos[j] || pos[j] < ns[i].range[j][0]) return {T(), false};\n  if (myself)\
    \ return {ns[i].val, true};\n  if constexpr (dual<M>::value) eval(i);\n  auto\
    \ ret= get(ns[i].ch[0], pos);\n  return !ret.second ? get(ns[i].ch[1], pos) :\
    \ ret;\n }\n inline bool set(int i, const std::array<pos_t, K> &pos, const T &x)\
    \ {\n  if (i == -1) return false;\n  bool myself= true, ret= true;\n  for (std::uint8_t\
    \ j= K; j--; myself&= pos[j] == ns[i].pos[j])\n   if (ns[i].range[j][1] < pos[j]\
    \ || pos[j] < ns[i].range[j][0]) return false;\n  if constexpr (dual<M>::value)\
    \ eval(i);\n  if (myself) ns[i].val= x;\n  else if (!(ret= set(ns[i].ch[0], pos,\
    \ x))) ret= set(ns[i].ch[1], pos, x);\n  if constexpr (monoid<M>::value) pushup(i);\n\
    \  return ret;\n }\n template <typename... Args> static inline Range to_range(std::initializer_list<Args>...\
    \ intervals) {\n  static_assert(sizeof...(intervals) == K);\n  static_assert(std::conjunction_v<std::is_same<Args,\
    \ pos_t>...>);\n  Range r;\n  std::uint8_t i= 0;\n  for (auto &&x: {intervals...})\
    \ {\n   std::vector<pos_t> tmp(x);\n   assert(tmp.size() == 2), assert(tmp[0]\
    \ <= tmp[1]);\n   r[i][0]= tmp[0], r[i][1]= tmp[1], i++;\n  }\n  return r;\n }\n\
    \ static inline auto funcs(const Range &r) {\n  return std::make_tuple(\n    \
    \  [r](pos_t pos[K]) {\n       for (std::uint8_t i= K; i--;)\n        if (pos[i]\
    \ < r[i][0] || r[i][1] < pos[i]) return false;\n       return true;\n      },\n\
    \      [r](pos_t range[K][2]) {\n       for (std::uint8_t i= K; i--;)\n      \
    \  if (range[i][0] < r[i][0] || r[i][1] < range[i][1]) return false;\n       return\
    \ true;\n      },\n      [r](pos_t range[K][2]) {\n       for (std::uint8_t i=\
    \ K; i--;)\n        if (range[i][1] < r[i][0] || r[i][1] < range[i][0]) return\
    \ true;\n       return false;\n      });\n }\npublic:\n KDTree(std::vector<PosVal>\
    \ v): ns(v.size()) {\n  int root, timestamp= 0;\n  build(root, v.begin(), v.end(),\
    \ timestamp);\n }\n T get(std::array<pos_t, K> pos) {\n  auto [ret, flg]= get(0,\
    \ pos);\n  return assert(flg), ret;\n }\n template <typename... Args> T get(Args...\
    \ ids) {\n  static_assert(sizeof...(ids) == K);\n  static_assert(std::conjunction_v<std::is_convertible<Args,\
    \ pos_t>...>);\n  auto [ret, flg]= get(0, {ids...});\n  return assert(flg), ret;\n\
    \ }\n void set(T x, std::array<pos_t, K> pos) { assert(set(0, pos, x)); }\n template\
    \ <typename... Args> void set(T x, Args... ids) {\n  static_assert(sizeof...(ids)\
    \ == K);\n  static_assert(std::conjunction_v<std::is_convertible<Args, pos_t>...>);\n\
    \  assert(set(0, {ids...}, x));\n }\n T fold(const Range &r) {\n  auto [in, inall,\
    \ outall]= funcs(r);\n  return fold(0, in, inall, outall);\n }\n template <typename...\
    \ Args> T fold(std::initializer_list<Args> &&...intervals) {\n  auto r= to_range(intervals...);\n\
    \  auto [in, inall, outall]= funcs(r);\n  return fold(0, in, inall, outall);\n\
    \ }\n template <class F, class G, class H> T fold(const F &in, const G &inall,\
    \ const H &outall) { return fold(0, in, inall, outall); }\n void apply(E x, const\
    \ Range &r) {\n  auto [in, inall, outall]= funcs(r);\n  apply(0, in, inall, outall,\
    \ x);\n }\n template <typename... Args> void apply(E x, std::initializer_list<Args>\
    \ &&...intervals) {\n  auto r= to_range(intervals...);\n  auto [in, inall, outall]=\
    \ funcs(r);\n  apply(0, in, inall, outall, x);\n }\n template <class F, class\
    \ G, class H> void apply(E x, const F &in, const G &inall, const H &outall) {\
    \ apply(0, in, inall, outall, x); }\n};\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include <algorithm>\n\
    #include <tuple>\n#include <cstddef>\n#include <cassert>\n#include \"src/Internal/HAS_CHECK.hpp\"\
    \ntemplate <std::uint8_t K, class pos_t, class M> class KDTree {\n HAS_MEMBER(op);\n\
    \ HAS_MEMBER(ti);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n HAS_TYPE(T);\n\
    \ HAS_TYPE(E);\n template <class L> using monoid= std::conjunction<has_T<L>, has_op<L>,\
    \ has_ti<L>>;\n template <class L> using dual= std::conjunction<has_T<L>, has_E<L>,\
    \ has_mapping<L>, has_composition<L>>;\n template <class T, class F= std::nullptr_t>\
    \ struct Node_B {\n  using E= F;\n  T val;\n  int ch[2]= {-1, -1};\n  pos_t range[K][2],\
    \ pos[K];\n };\n template <bool sg_, bool du_, typename tEnable= void> struct\
    \ Node_D: Node_B<M> {};\n template <bool sg_, bool du_> struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && !du_>>: Node_B<typename M::T> { typename M::T\
    \ sum; };\n template <bool sg_, bool du_> struct Node_D<sg_, du_, typename std::enable_if_t<!sg_\
    \ && du_>>: Node_B<typename M::T, typename M::E> {\n  typename M::E lazy;\n  bool\
    \ lazy_flg= false;\n };\n template <bool sg_, bool du_> struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && du_>>: Node_B<typename M::T, typename M::E>\
    \ {\n  typename M::T sum;\n  typename M::E lazy;\n  bool lazy_flg= false;\n };\n\
    \ using Node= Node_D<monoid<M>::value, dual<M>::value>;\n using T= decltype(Node::val);\n\
    \ using E= typename Node::E;\n std::vector<Node> ns;\npublic:\n using PosVal=\
    \ std::pair<std::array<pos_t, K>, T>;\n using Iter= typename std::vector<PosVal>::iterator;\n\
    \ using Range= std::array<std::array<pos_t, 2>, K>;\nprivate:\n inline void pushup(int\
    \ i) {\n  ns[i].sum= ns[i].val;\n  if (ns[i].ch[0] != -1) ns[i].sum= M::op(ns[ns[i].ch[0]].sum,\
    \ ns[i].sum);\n  if (ns[i].ch[1] != -1) ns[i].sum= M::op(ns[i].sum, ns[ns[i].ch[1]].sum);\n\
    \ }\n inline void propagate(int i, const E &x) {\n  if (i == -1) return;\n  ns[i].lazy_flg\
    \ ? (M::composition(ns[i].lazy, x), x) : (ns[i].lazy= x);\n  M::mapping(ns[i].val,\
    \ x), ns[i].lazy_flg= true;\n  if constexpr (monoid<M>::value) M::mapping(ns[i].sum,\
    \ x);\n }\n inline void eval(int i) {\n  if (!ns[i].lazy_flg) return;\n  ns[i].lazy_flg=\
    \ false;\n  propagate(ns[i].ch[0], ns[i].lazy), propagate(ns[i].ch[1], ns[i].lazy);\n\
    \ }\n inline void build(int &i, Iter bg, Iter ed, int &ts, std::uint8_t div= 0)\
    \ {\n  if (ed - bg < 1) return;\n  const int n= ed - bg;\n  auto md= bg + n /\
    \ 2;\n  std::nth_element(bg, md, ed, [div](const PosVal &l, const PosVal &r) {\
    \ return l.first[div] < r.first[div]; });\n  ns[i= ts++].val= md->second;\n  for\
    \ (std::uint8_t j= K; j--; ns[i].pos[j]= md->first[j]) {\n   auto [mn, mx]= std::minmax_element(bg,\
    \ ed, [j](const PosVal &l, const PosVal &r) { return l.first[j] < r.first[j];\
    \ });\n   ns[i].range[j][0]= mn->first[j], ns[i].range[j][1]= mx->first[j];\n\
    \  }\n  if (std::uint8_t nex= (div + 1) % K; n > 1) build(ns[i].ch[0], bg, md,\
    \ ts, nex), build(ns[i].ch[1], md + 1, ed, ts, nex);\n  if constexpr (monoid<M>::value)\
    \ pushup(i);\n }\n template <class F, class G, class H> inline T fold(int i, const\
    \ F &in, const G &inall, const H &outall) {\n  static_assert(monoid<M>::value,\
    \ \"\\\"fold\\\" is not available\");\n  if (i == -1 || outall(ns[i].range)) return\
    \ M::ti();\n  if (inall(ns[i].range)) return ns[i].sum;\n  if constexpr (dual<M>::value)\
    \ eval(i);\n  T ret= M::op(fold(ns[i].ch[0], in, inall, outall), fold(ns[i].ch[1],\
    \ in, inall, outall));\n  ret= in(ns[i].pos) ? M::op(ret, ns[i].val) : ret;\n\
    \  return ret;\n }\n template <class F, class G, class H> inline void apply(int\
    \ i, const F &in, const G &inall, const H &outall, const E &x) {\n  static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\");\n  if (i == -1 || outall(ns[i].range))\
    \ return;\n  if (inall(ns[i].range)) return propagate(i, x), void();\n  if (eval(i);\
    \ in(ns[i].pos)) M::mapping(ns[i].val, x);\n  apply(ns[i].ch[0], in, inall, outall,\
    \ x), apply(ns[i].ch[1], in, inall, outall, x);\n  if constexpr (monoid<M>::value)\
    \ pushup(i);\n }\n inline std::pair<T, bool> get(int i, const std::array<pos_t,\
    \ K> &pos) {\n  if (i == -1) return {T(), false};\n  bool myself= true;\n  for\
    \ (std::uint8_t j= K; j--; myself&= pos[j] == ns[i].pos[j])\n   if (ns[i].range[j][1]\
    \ < pos[j] || pos[j] < ns[i].range[j][0]) return {T(), false};\n  if (myself)\
    \ return {ns[i].val, true};\n  if constexpr (dual<M>::value) eval(i);\n  auto\
    \ ret= get(ns[i].ch[0], pos);\n  return !ret.second ? get(ns[i].ch[1], pos) :\
    \ ret;\n }\n inline bool set(int i, const std::array<pos_t, K> &pos, const T &x)\
    \ {\n  if (i == -1) return false;\n  bool myself= true, ret= true;\n  for (std::uint8_t\
    \ j= K; j--; myself&= pos[j] == ns[i].pos[j])\n   if (ns[i].range[j][1] < pos[j]\
    \ || pos[j] < ns[i].range[j][0]) return false;\n  if constexpr (dual<M>::value)\
    \ eval(i);\n  if (myself) ns[i].val= x;\n  else if (!(ret= set(ns[i].ch[0], pos,\
    \ x))) ret= set(ns[i].ch[1], pos, x);\n  if constexpr (monoid<M>::value) pushup(i);\n\
    \  return ret;\n }\n template <typename... Args> static inline Range to_range(std::initializer_list<Args>...\
    \ intervals) {\n  static_assert(sizeof...(intervals) == K);\n  static_assert(std::conjunction_v<std::is_same<Args,\
    \ pos_t>...>);\n  Range r;\n  std::uint8_t i= 0;\n  for (auto &&x: {intervals...})\
    \ {\n   std::vector<pos_t> tmp(x);\n   assert(tmp.size() == 2), assert(tmp[0]\
    \ <= tmp[1]);\n   r[i][0]= tmp[0], r[i][1]= tmp[1], i++;\n  }\n  return r;\n }\n\
    \ static inline auto funcs(const Range &r) {\n  return std::make_tuple(\n    \
    \  [r](pos_t pos[K]) {\n       for (std::uint8_t i= K; i--;)\n        if (pos[i]\
    \ < r[i][0] || r[i][1] < pos[i]) return false;\n       return true;\n      },\n\
    \      [r](pos_t range[K][2]) {\n       for (std::uint8_t i= K; i--;)\n      \
    \  if (range[i][0] < r[i][0] || r[i][1] < range[i][1]) return false;\n       return\
    \ true;\n      },\n      [r](pos_t range[K][2]) {\n       for (std::uint8_t i=\
    \ K; i--;)\n        if (range[i][1] < r[i][0] || r[i][1] < range[i][0]) return\
    \ true;\n       return false;\n      });\n }\npublic:\n KDTree(std::vector<PosVal>\
    \ v): ns(v.size()) {\n  int root, timestamp= 0;\n  build(root, v.begin(), v.end(),\
    \ timestamp);\n }\n T get(std::array<pos_t, K> pos) {\n  auto [ret, flg]= get(0,\
    \ pos);\n  return assert(flg), ret;\n }\n template <typename... Args> T get(Args...\
    \ ids) {\n  static_assert(sizeof...(ids) == K);\n  static_assert(std::conjunction_v<std::is_convertible<Args,\
    \ pos_t>...>);\n  auto [ret, flg]= get(0, {ids...});\n  return assert(flg), ret;\n\
    \ }\n void set(T x, std::array<pos_t, K> pos) { assert(set(0, pos, x)); }\n template\
    \ <typename... Args> void set(T x, Args... ids) {\n  static_assert(sizeof...(ids)\
    \ == K);\n  static_assert(std::conjunction_v<std::is_convertible<Args, pos_t>...>);\n\
    \  assert(set(0, {ids...}, x));\n }\n T fold(const Range &r) {\n  auto [in, inall,\
    \ outall]= funcs(r);\n  return fold(0, in, inall, outall);\n }\n template <typename...\
    \ Args> T fold(std::initializer_list<Args> &&...intervals) {\n  auto r= to_range(intervals...);\n\
    \  auto [in, inall, outall]= funcs(r);\n  return fold(0, in, inall, outall);\n\
    \ }\n template <class F, class G, class H> T fold(const F &in, const G &inall,\
    \ const H &outall) { return fold(0, in, inall, outall); }\n void apply(E x, const\
    \ Range &r) {\n  auto [in, inall, outall]= funcs(r);\n  apply(0, in, inall, outall,\
    \ x);\n }\n template <typename... Args> void apply(E x, std::initializer_list<Args>\
    \ &&...intervals) {\n  auto r= to_range(intervals...);\n  auto [in, inall, outall]=\
    \ funcs(r);\n  apply(0, in, inall, outall, x);\n }\n template <class F, class\
    \ G, class H> void apply(E x, const F &in, const G &inall, const H &outall) {\
    \ apply(0, in, inall, outall, x); }\n};"
  dependsOn:
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/DataStructure/KDTree.hpp
  requiredBy: []
  timestamp: '2023-01-21 20:28:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1625.KDT.test.cpp
  - test/yukicoder/728.KDT.test.cpp
  - test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - test/hackerrank/cube-summation.KDT.test.cpp
  - test/aoj/2842.KDT.test.cpp
  - test/aoj/DSL_2_C.KDT.test.cpp
  - test/aoj/1068.KDT.test.cpp
documentation_of: src/DataStructure/KDTree.hpp
layout: document
title: kD-Tree
---
## 計算量
$\mathcal{O}(k\cdot N^{1-1/k})$
## 参考
[https://trap.jp/post/1489/](https://trap.jp/post/1489/)
## 問題例
[square869120Contest #4 G - Get the Salary of Atcoder](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g) (オイラーツアー+遅延伝搬) \
[第二回 アルゴリズム実技検定 過去問 N - ビルの建設](https://atcoder.jp/contests/past202004-open/tasks/past202004_n) (双対) \
[AtCoder Beginner Contest 234 Ex - Enumerate Pairs](https://atcoder.jp/contests/abc234/tasks/abc234_h) (円形クエリ)
