---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/KDTree.hpp
    title: kD-Tree
  - icon: ':heavy_check_mark:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
  - icon: ':question:'
    path: src/Internal/long_traits.hpp
    title: "int \u304B\u3089 long long \u306A\u3069\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
  - icon: ':heavy_check_mark:'
    path: src/Internal/tuple_traits.hpp
    title: "tuple\u3084array\u306B\u95A2\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_rectangle_sum.KDT.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n#include\
    \ <iostream>\n#include <map>\n#include <array>\n#include <vector>\n#line 3 \"\
    src/DataStructure/KDTree.hpp\"\n#include <algorithm>\n#include <numeric>\n#line\
    \ 6 \"src/DataStructure/KDTree.hpp\"\n#include <set>\n#include <cassert>\n#line\
    \ 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n#define MEMBER_MACRO(member,\
    \ Dummy, name, type1, type2, last) \\\n template <class tClass> struct name##member\
    \ { \\\n  template <class U, Dummy> static type1 check(U *); \\\n  static type2\
    \ check(...); \\\n  static tClass *mClass; \\\n  last; \\\n }\n#define HAS_CHECK(member,\
    \ Dummy) MEMBER_MACRO(member, Dummy, has_, std::true_type, std::false_type, static\
    \ const bool value= decltype(check(mClass))::value)\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#define HOGE_OR(member, name, type2) \\\n\
    \ MEMBER_MACRO(member, class dummy= typename U::member, name, typename U::member,\
    \ type2, using type= decltype(check(mClass))); \\\n template <class tClass> using\
    \ name##member##_t= typename name##member<tClass>::type\n#define NULLPTR_OR(member)\
    \ HOGE_OR(member, nullptr_or_, std::nullptr_t)\n#define MYSELF_OR(member) HOGE_OR(member,\
    \ myself_or_, tClass)\n#line 2 \"src/Internal/tuple_traits.hpp\"\n#include <tuple>\n\
    #line 5 \"src/Internal/tuple_traits.hpp\"\n#include <cstddef>\ntemplate <class\
    \ T> static constexpr bool tuple_like_v= false;\ntemplate <class... Args> static\
    \ constexpr bool tuple_like_v<std::tuple<Args...>> = true;\ntemplate <class T,\
    \ class U> static constexpr bool tuple_like_v<std::pair<T, U>> = true;\ntemplate\
    \ <class T, size_t K> static constexpr bool tuple_like_v<std::array<T, K>> = true;\n\
    template <class T> auto to_tuple(const T &t) {\n if constexpr (tuple_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::make_tuple(x...); }, t);\n}\n\
    template <class T> auto forward_tuple(const T &t) {\n if constexpr (tuple_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::forward_as_tuple(x...); }, t);\n\
    }\ntemplate <class T> static constexpr bool array_like_v= false;\ntemplate <class\
    \ T, size_t K> static constexpr bool array_like_v<std::array<T, K>> = true;\n\
    template <class T, class U> static constexpr bool array_like_v<std::pair<T, U>>\
    \ = std::is_convertible_v<T, U>;\ntemplate <class T> static constexpr bool array_like_v<std::tuple<T>>\
    \ = true;\ntemplate <class T, class U, class... Args> static constexpr bool array_like_v<std::tuple<T,\
    \ U, Args...>> = array_like_v<std::tuple<T, Args...>> && std::is_convertible_v<U,\
    \ T>;\ntemplate <class T> auto to_array(const T &t) {\n if constexpr (array_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::array{x...}; }, t);\n}\ntemplate\
    \ <class T> using to_tuple_t= decltype(to_tuple(T()));\ntemplate <class T> using\
    \ to_array_t= decltype(to_array(T()));\n#line 2 \"src/Internal/long_traits.hpp\"\
    \n#include <cstdint>\n// clang-format off\ntemplate<class T>struct make_long{using\
    \ type= T;};\ntemplate<>struct make_long<int8_t>{using type= int16_t;};\ntemplate<>struct\
    \ make_long<uint8_t>{using type= uint16_t;};\ntemplate<>struct make_long<int16_t>{using\
    \ type= int32_t;};\ntemplate<>struct make_long<uint16_t>{using type= uint32_t;};\n\
    template<>struct make_long<int32_t>{using type= int64_t;};\ntemplate<>struct make_long<uint32_t>{using\
    \ type= uint64_t;};\ntemplate<>struct make_long<int64_t>{using type= __int128_t;};\n\
    template<>struct make_long<uint64_t>{using type= __uint128_t;};\ntemplate<>struct\
    \ make_long<float>{using type= double;};\ntemplate<>struct make_long<double>{using\
    \ type= long double;};\ntemplate<class T> using make_long_t= typename make_long<T>::type;\n\
    // clang-format on\n#line 11 \"src/DataStructure/KDTree.hpp\"\nnamespace kdtree_internal\
    \ {\ntemplate <class pos_t, size_t K, class M, class A, class B> class KDTreeImpl\
    \ {};\ntemplate <class pos_t, size_t K, class M, class... PK, class... PK2> class\
    \ KDTreeImpl<pos_t, K, M, std::tuple<PK...>, std::tuple<PK2...>> {\n HAS_MEMBER(op);\n\
    \ HAS_MEMBER(ti);\n HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n HAS_TYPE(T);\n HAS_TYPE(E);\n\
    \ MYSELF_OR(T);\n NULLPTR_OR(E);\n using Sec= std::array<pos_t, 2>;\n using Pos=\
    \ std::array<pos_t, K>;\n using Range= std::array<Sec, K>;\n using long_pos_t=\
    \ make_long_t<pos_t>;\n template <class L> static constexpr bool monoid_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>, has_ti<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mp<L>, has_cp<L>>;\n struct Node_BB {\n  int ch[2]= {-1, -1};\n\
    \  Pos pos;\n  pos_t range[K][2];\n };\n template <class U> struct Node_B: Node_BB\
    \ {\n  U val;\n };\n template <class D, bool sg, bool du> struct Node_D: Node_B<M>\
    \ {};\n template <bool sg, bool du> struct Node_D<void, sg, du>: Node_BB {};\n\
    \ template <class D> struct Node_D<D, 1, 0>: Node_B<typename M::T> {\n  typename\
    \ M::T sum;\n };\n template <class D> struct Node_D<D, 0, 1>: Node_B<typename\
    \ M::T> {\n  typename M::E laz;\n  bool laz_flg= false;\n };\n template <class\
    \ D> struct Node_D<D, 1, 1>: Node_B<typename M::T> {\n  typename M::T sum;\n \
    \ typename M::E laz;\n  bool laz_flg= false;\n };\n using Node= Node_D<M, monoid_v<M>,\
    \ dual_v<M>>;\n using Iter= typename std::vector<int>::iterator;\n using T= std::conditional_t<std::is_void_v<M>,\
    \ std::nullptr_t, myself_or_T_t<M>>;\n using E= nullptr_or_E_t<M>;\n template\
    \ <class P> using canbe_Pos= std::is_convertible<to_tuple_t<P>, std::tuple<PK...>>;\n\
    \ template <class P> using canbe_PosV= std::is_convertible<to_tuple_t<P>, std::tuple<PK...,\
    \ T>>;\n template <class P, class U> static constexpr bool canbe_Pos_and_T_v=\
    \ std::conjunction_v<canbe_Pos<P>, std::is_convertible<U, T>>;\n std::vector<Node>\
    \ ns;\n static inline T def_val() {\n  if constexpr (monoid_v<M>) return M::ti();\n\
    \  else return T();\n }\n template <bool z, size_t k, class P> static inline auto\
    \ get_(const P &p) {\n  if constexpr (z) return std::get<k>(p);\n  else return\
    \ std::get<k>(p.first);\n }\n template <class P, size_t... I> Range to_range(const\
    \ P &p, std::index_sequence<I...>) { return {(assert(std::get<I + I>(p) <= std::get<I\
    \ + I + 1>(p)), Sec{std::get<I + I>(p), std::get<I + I + 1>(p)})...}; }\n inline\
    \ void update(int t) {\n  ns[t].sum= ns[t].val;\n  if (ns[t].ch[0] != -1) ns[t].sum=\
    \ M::op(ns[t].sum, ns[ns[t].ch[0]].sum);\n  if (ns[t].ch[1] != -1) ns[t].sum=\
    \ M::op(ns[t].sum, ns[ns[t].ch[1]].sum);\n }\n inline void propagate(int t, const\
    \ E &x) {\n  if (t == -1) return;\n  if (ns[t].laz_flg) M::cp(ns[t].laz, x);\n\
    \  else ns[t].laz= x, ns[t].laz_flg= true;\n  M::mp(ns[t].val, x);\n  if constexpr\
    \ (monoid_v<M>) M::mp(ns[t].sum, x);\n }\n inline void push(int t) {\n  if (ns[t].laz_flg)\
    \ ns[t].laz_flg= false, propagate(ns[t].ch[0], ns[t].laz), propagate(ns[t].ch[1],\
    \ ns[t].laz);\n }\n template <bool z, class P, size_t k> inline void set_range(int\
    \ t, int m, Iter bg, Iter ed, const P *p) {\n  auto [mn, mx]= std::minmax_element(bg,\
    \ ed, [&](int a, int b) { return get_<z, k>(p[a]) < get_<z, k>(p[b]); });\n  ns[t].range[k][0]=\
    \ get_<z, k>(p[*mn]), ns[t].range[k][1]= get_<z, k>(p[*mx]), ns[t].pos[k]= get_<z,\
    \ k>(p[m]);\n }\n template <bool z, class P, size_t... I> inline void set_range_lp(int\
    \ t, int m, Iter bg, Iter ed, const P *p, std::index_sequence<I...>) { (void)(int[]){(set_range<z,\
    \ P, I>(t, m, bg, ed, p), 0)...}; }\n template <bool z, uint8_t div, class P>\
    \ inline int build(int &ts, Iter bg, Iter ed, const P *p, const T &v= def_val())\
    \ {\n  if (bg == ed) return -1;\n  auto md= bg + (ed - bg) / 2;\n  int t= ts++;\n\
    \  std::nth_element(bg, md, ed, [&](int a, int b) { return get_<z, div>(p[a])\
    \ < get_<z, div>(p[b]); }), set_range_lp<z>(t, *md, bg, ed, p, std::make_index_sequence<K>());\n\
    \  if constexpr (z) {\n   if constexpr (!std::is_void_v<M>) {\n    if constexpr\
    \ (std::tuple_size_v<P> == K + 1) ns[t].val= std::get<K>(p[*md]);\n    else ns[t].val=\
    \ v;\n   }\n  } else ns[t].val= p[*md].second;\n  static constexpr uint8_t nx=\
    \ div + 1 == K ? 0 : div + 1;\n  ns[t].ch[0]= build<z, nx>(ts, bg, md, p, v),\
    \ ns[t].ch[1]= build<z, nx>(ts, md + 1, ed, p, v);\n  if constexpr (monoid_v<M>)\
    \ update(t);\n  return t;\n }\n template <bool z, uint8_t div, class P> inline\
    \ int build(Iter bg, Iter ed, const P *p, int &ts) {\n  if (bg == ed) return -1;\n\
    \  auto md= bg + (ed - bg) / 2;\n  int t= ts++;\n  std::nth_element(bg, md, ed,\
    \ [&](int a, int b) { return get_<z, div>(p[a]) < get_<z, div>(p[b]); }), set_range_lp<z>(t,\
    \ bg, ed, p, std::make_index_sequence<K>());\n  if constexpr (z) {\n   if constexpr\
    \ (!std::is_void_v<M>) {\n    if constexpr (std::tuple_size_v<P> == K + 1) ns[t].val=\
    \ std::get<K>(p[t]);\n    else ns[t].val= def_val();\n   }\n  } else ns[t].val=\
    \ p[t].second;\n  static constexpr uint8_t nx= div + 1 == K ? 0 : div + 1;\n \
    \ ns[t].ch[0]= build<z, nx>(bg, md, p, ts), ns[t].ch[1]= build<z, nx>(md + 1,\
    \ ed, p, ts);\n  if constexpr (monoid_v<M>) update(t);\n  return t;\n }\n static\
    \ inline auto in_cuboid(const Range &r) {\n  return [r](const Pos &pos) {\n  \
    \ for (uint8_t k= K; k--;)\n    if (r[k][1] < pos[k] || pos[k] < r[k][0]) return\
    \ false;\n   return true;\n  };\n }\n static inline auto out_cuboid(const Range\
    \ &r) {\n  return [r](const pos_t rr[K][2]) {\n   for (uint8_t k= K; k--;)\n \
    \   if (rr[k][1] < r[k][0] || r[k][1] < rr[k][0]) return true;\n   return false;\n\
    \  };\n }\n static inline auto inall_cuboid(const Range &r) {\n  return [r](const\
    \ pos_t rr[K][2]) {\n   for (uint8_t k= K; k--;)\n    if (rr[k][0] < r[k][0] ||\
    \ r[k][1] < rr[k][1]) return false;\n   return true;\n  };\n }\n static inline\
    \ long_pos_t min_dist2(const pos_t r[K][2], const Pos &pos) {\n  long_pos_t d2=\
    \ 0, dx;\n  for (uint8_t k= K; k--;) dx= std::clamp(pos[k], r[k][0], r[k][1])\
    \ - pos[k], d2+= dx * dx;\n  return d2;\n }\n static inline auto in_ball(const\
    \ Pos &c, long_pos_t r2) {\n  return [c, r2](const Pos &pos) {\n   long_pos_t\
    \ d2= 0, dx;\n   for (uint8_t k= K; k--;) dx= pos[k] - c[k], d2+= dx * dx;\n \
    \  return d2 <= r2;\n  };\n }\n static inline auto inall_ball(const Pos &c, long_pos_t\
    \ r2) {\n  return [c, r2](const pos_t rr[K][2]) {\n   long_pos_t d2= 0, dx0, dx1;\n\
    \   for (uint8_t k= K; k--;) dx0= rr[k][0] - c[k], dx1= rr[k][1] - c[k], d2+=\
    \ std::max(dx0 * dx0, dx1 * dx1);\n   return d2 <= r2;\n  };\n }\n static inline\
    \ auto out_ball(const Pos &c, long_pos_t r2) {\n  return [c, r2](const pos_t r[K][2])\
    \ { return min_dist2(r, c) > r2; };\n }\n inline void nns(int t, const Pos &pos,\
    \ std::pair<int, long_pos_t> &ret) const {\n  if (t == -1) return;\n  long_pos_t\
    \ d2= min_dist2(ns[t].range, pos);\n  if (ret.first != -1 && d2 >= ret.second)\
    \ return;\n  long_pos_t dx= d2= 0;\n  for (uint8_t k= K; k--;) dx= pos[k] - ns[t].pos[k],\
    \ d2+= dx * dx;\n  if (ret.first == -1 || d2 < ret.second) ret= {t, d2};\n  bool\
    \ f= 0;\n  if (auto [l, r]= ns[t].ch; l != -1 && r != -1) f= min_dist2(ns[l].range,\
    \ pos) > min_dist2(ns[r].range, pos);\n  nns(ns[t].ch[f], pos, ret), nns(ns[t].ch[!f],\
    \ pos, ret);\n }\n template <class In, class Out> inline void col(int t, const\
    \ In &in, const Out &out, std::vector<T> &ret) const {\n  if (t == -1 || out(ns[t].range))\
    \ return;\n  if (in(ns[t].pos)) ret.push_back(ns[t].val);\n  col(ns[t].ch[0],\
    \ in, out, ret), col(ns[t].ch[1], in, out, ret);\n }\n template <class In, class\
    \ InAll, class Out> inline T fld(int t, const In &in, const InAll &inall, const\
    \ Out &out) {\n  if (t == -1 || out(ns[t].range)) return def_val();\n  if (inall(ns[t].range))\
    \ return ns[t].sum;\n  if constexpr (dual_v<M>) push(t);\n  T ret= M::op(fld(ns[t].ch[0],\
    \ in, inall, out), fld(ns[t].ch[1], in, inall, out));\n  return in(ns[t].pos)\
    \ ? M::op(ret, ns[t].val) : ret;\n }\n template <class In, class InAll, class\
    \ Out> inline void app(int t, const In &in, const InAll &inall, const Out &out,\
    \ const E &x) {\n  if (t == -1 || out(ns[t].range)) return;\n  if (inall(ns[t].range))\
    \ return propagate(t, x);\n  if (push(t); in(ns[t].pos)) M::mp(ns[t].val, x);\n\
    \  app(ns[t].ch[0], in, inall, out, x), app(ns[t].ch[1], in, inall, out, x);\n\
    \  if constexpr (monoid_v<M>) update(t);\n }\n template <bool z> inline bool set(int\
    \ t, const Pos &pos, const T &x) {\n  if (t == -1) return false;\n  bool isok=\
    \ true;\n  for (uint8_t k= K; k--; isok&= pos[k] == ns[t].pos[k])\n   if (ns[t].range[k][1]\
    \ < pos[k] || pos[k] < ns[t].range[k][0]) return false;\n  if constexpr (dual_v<M>)\
    \ push(t);\n  if (isok) {\n   if constexpr (z) ns[t].val= x;\n   else ns[t].val=\
    \ M::op(ns[t].val, x);\n  } else if (!(isok= set<z>(ns[t].ch[0], pos, x))) isok=\
    \ set<z>(ns[t].ch[1], pos, x);\n  if constexpr (monoid_v<M>)\n   if (isok) update(t);\n\
    \  return isok;\n }\n inline std::pair<T, bool> get(int t, const Pos &pos) {\n\
    \  if (t == -1) return {T(), false};\n  bool myself= true;\n  for (uint8_t k=\
    \ K; k--; myself&= pos[k] == ns[t].pos[k])\n   if (ns[t].range[k][1] < pos[k]\
    \ || pos[k] < ns[t].range[k][0]) return {T(), false};\n  if (myself) return {ns[t].val,\
    \ true};\n  if constexpr (dual_v<M>) push(t);\n  auto ret= get(ns[t].ch[0], pos);\n\
    \  return !ret.second ? get(ns[t].ch[1], pos) : ret;\n }\npublic:\n template <class\
    \ P, typename= std::enable_if_t<std::disjunction_v<canbe_Pos<P>, canbe_PosV<P>>>>\
    \ KDTreeImpl(const P *p, size_t n): ns(n) {\n  std::vector<int> ids(n);\n  int\
    \ ts= 0;\n  std::iota(ids.begin(), ids.end(), 0), build<1, 0>(ts, ids.begin(),\
    \ ids.end(), p);\n }\n template <class P, typename= std::enable_if_t<std::disjunction_v<canbe_Pos<P>,\
    \ canbe_PosV<P>>>> KDTreeImpl(const std::vector<P> &p): KDTreeImpl(p.data(), p.size())\
    \ {}\n template <class P, typename= std::enable_if_t<canbe_Pos<P>::value>> KDTreeImpl(const\
    \ std::set<P> &p): KDTreeImpl(std::vector(p.begin(), p.end())) {}\n template <class\
    \ P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> KDTreeImpl(const\
    \ P *p, size_t n, U v): ns(n) {\n  std::vector<int> ids(n);\n  int ts= 0;\n  std::iota(ids.begin(),\
    \ ids.end(), 0), build<1, 0>(ts, ids.begin(), ids.end(), p, v);\n }\n template\
    \ <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> KDTreeImpl(const\
    \ std::vector<P> &p, U v): KDTreeImpl(p.data(), p.size(), v) {}\n template <class\
    \ P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> KDTreeImpl(const\
    \ std::set<P> &p, U v): KDTreeImpl(std::vector(p.begin(), p.end()), v) {}\n template\
    \ <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> KDTreeImpl(const\
    \ std::pair<P, U> *p, size_t n): ns(n) {\n  std::vector<int> ids(n);\n  int ts=\
    \ 0;\n  std::iota(ids.begin(), ids.end(), 0), build<0, 0>(ts, ids.begin(), ids.end(),\
    \ p);\n }\n template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> KDTreeImpl(const std::vector<std::pair<P, U>> &p): KDTreeImpl(p.data(),\
    \ p.size()) {}\n template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> KDTreeImpl(const std::map<P, U> &p): KDTreeImpl(std::vector(p.begin(),\
    \ p.end())) {}\n std::vector<T> enum_cuboid(PK2... xs) {\n  static_assert(!std::is_void_v<M>,\
    \ \"\\\"enum_cuboid\\\" is not available\");\n  std::vector<T> ret;\n  auto r=\
    \ to_range(std::forward_as_tuple(xs...), std::make_index_sequence<K>());\n  return\
    \ col(-ns.empty(), in_cuboid(r), out_cuboid(r), ret), ret;\n }\n std::vector<T>\
    \ enum_ball(PK... xs, pos_t r) const {\n  static_assert(!std::is_void_v<M>, \"\
    \\\"enum_ball\\\" is not available\");\n  std::vector<T> ret;\n  long_pos_t r2=\
    \ long_pos_t(r) * r;\n  return col(-ns.empty(), in_ball({xs...}, r2), out_ball({xs...},\
    \ r2), ret), ret;\n }\n T prod_cuboid(PK2... xs) {\n  static_assert(monoid_v<M>,\
    \ \"\\\"prod_cuboid\\\" is not available\");\n  auto r= to_range(std::forward_as_tuple(xs...),\
    \ std::make_index_sequence<K>());\n  return fld(-ns.empty(), in_cuboid(r), inall_cuboid(r),\
    \ out_cuboid(r));\n }\n T prod_ball(PK... xs, pos_t r) {\n  static_assert(monoid_v<M>,\
    \ \"\\\"prod_ball\\\" is not available\");\n  long_pos_t r2= long_pos_t(r) * r;\n\
    \  return fld(-ns.empty(), in_ball({xs...}, r2), inall_ball({xs...}, r2), out_ball({xs...},\
    \ r2));\n }\n void apply_cuboid(PK2... xs, E a) {\n  static_assert(dual_v<M>,\
    \ \"\\\"apply_cuboid\\\" is not available\");\n  auto r= to_range(std::forward_as_tuple(xs...),\
    \ std::make_index_sequence<K>());\n  app(-ns.empty(), in_cuboid(r), inall_cuboid(r),\
    \ out_cuboid(r), a);\n }\n void apply_ball(PK... xs, pos_t r, E a) {\n  static_assert(dual_v<M>,\
    \ \"\\\"apply_ball\\\" is not available\");\n  long_pos_t r2= long_pos_t(r) *\
    \ r;\n  app(-ns.empty(), in_ball({xs...}, r2), inall_ball({xs...}, r2), out({xs...},\
    \ r2), a);\n }\n void set(PK... xs, T v) { assert(ns.size()), assert(set<1>(0,\
    \ {xs...}, v)); }\n void mul(PK... xs, T v) {\n  static_assert(monoid_v<M>, \"\
    \\\"mul\\\" is not available\");\n  assert(ns.size()), assert(set<0>(0, {xs...},\
    \ v));\n }\n T get(PK... xs) {\n  assert(ns.size());\n  auto [ret, flg]= get(0,\
    \ {xs...});\n  return assert(flg), ret;\n }\n Pos nearest_neighbor(PK... xs) const\
    \ {\n  assert(ns.size());\n  std::pair<int, long_pos_t> ret= {-1, -1};\n  return\
    \ nns(0, {xs...}, ret), ns[ret.first].pos;\n }\n};\ntemplate <class pos_t, size_t\
    \ K, class M= void> using KDTree= KDTreeImpl<pos_t, K, M, to_tuple_t<std::array<pos_t,\
    \ K>>, to_tuple_t<std::array<pos_t, K + K>>>;\n}\nusing kdtree_internal::KDTree;\n\
    #line 7 \"test/yosupo/point_add_rectangle_sum.KDT.test.cpp\"\nusing namespace\
    \ std;\nstruct RSQ {\n using T= long long;\n static T ti() { return 0; }\n static\
    \ T op(T l, T r) { return l + r; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, Q;\n cin >> N >> Q;\n map<array<int, 2>, long long> mp;\n vector<array<int,\
    \ 4>> query;\n for (int i= 0; i < N; i++) {\n  int x, y, w;\n  cin >> x >> y >>\
    \ w;\n  mp[{x, y}]+= w;\n }\n for (int i= 0; i < Q; i++) {\n  int op;\n  cin >>\
    \ op;\n  if (op) {\n   int l, d, r, u;\n   cin >> l >> d >> r >> u;\n   query.push_back({l,\
    \ d, r, u});\n  } else {\n   int x, y, w;\n   cin >> x >> y >> w;\n   query.push_back({-1,\
    \ x, y, w});\n   mp[{x, y}];\n  }\n }\n KDTree<long long, 2, RSQ> kdt(mp);\n for\
    \ (int i= 0; i < Q; i++) {\n  if (query[i][0] != -1) {\n   auto [l, d, r, u]=\
    \ query[i];\n   cout << kdt.prod_cuboid(l, r - 1, d, u - 1) << '\\n';\n  } else\
    \ {\n   auto [_, x, y, w]= query[i];\n   kdt.mul(x, y, w);\n  }\n }\n return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include <iostream>\n#include <map>\n#include <array>\n#include <vector>\n#include\
    \ \"src/DataStructure/KDTree.hpp\"\nusing namespace std;\nstruct RSQ {\n using\
    \ T= long long;\n static T ti() { return 0; }\n static T op(T l, T r) { return\
    \ l + r; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, Q;\n cin >> N >> Q;\n map<array<int, 2>, long long> mp;\n vector<array<int,\
    \ 4>> query;\n for (int i= 0; i < N; i++) {\n  int x, y, w;\n  cin >> x >> y >>\
    \ w;\n  mp[{x, y}]+= w;\n }\n for (int i= 0; i < Q; i++) {\n  int op;\n  cin >>\
    \ op;\n  if (op) {\n   int l, d, r, u;\n   cin >> l >> d >> r >> u;\n   query.push_back({l,\
    \ d, r, u});\n  } else {\n   int x, y, w;\n   cin >> x >> y >> w;\n   query.push_back({-1,\
    \ x, y, w});\n   mp[{x, y}];\n  }\n }\n KDTree<long long, 2, RSQ> kdt(mp);\n for\
    \ (int i= 0; i < Q; i++) {\n  if (query[i][0] != -1) {\n   auto [l, d, r, u]=\
    \ query[i];\n   cout << kdt.prod_cuboid(l, r - 1, d, u - 1) << '\\n';\n  } else\
    \ {\n   auto [_, x, y, w]= query[i];\n   kdt.mul(x, y, w);\n  }\n }\n return 0;\n\
    }"
  dependsOn:
  - src/DataStructure/KDTree.hpp
  - src/Internal/HAS_CHECK.hpp
  - src/Internal/tuple_traits.hpp
  - src/Internal/long_traits.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 13:36:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_rectangle_sum.KDT.test.cpp
- /verify/test/yosupo/point_add_rectangle_sum.KDT.test.cpp.html
title: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
---
