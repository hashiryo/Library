---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/tuple_traits.hpp
    title: "tuple\u3084array\u306B\u95A2\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1068.Seg2D.test.cpp
    title: test/aoj/1068.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.Seg2D.test.cpp
    title: test/aoj/2842.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc228_f.Seg2D.test.cpp
    title: test/atcoder/abc228_f.Seg2D.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc309_f.Seg2D.test.cpp
    title: test/atcoder/abc309_f.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.Seg2D.test.cpp
    title: test/yosupo/point_add_rectangle_sum.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1216.Seg2D.test.cpp
    title: test/yukicoder/1216.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1600.Seg2D.test.cpp
    title: test/yukicoder/1600.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625.Seg2D.test.cpp
    title: test/yukicoder/1625.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1649.Seg2D.test.cpp
    title: test/yukicoder/1649.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2065.Seg2D.test.cpp
    title: test/yukicoder/2065.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.Seg2D.test.cpp
    title: test/yukicoder/924.Seg2D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_2D.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <numeric>\n#include <map>\n#include <set>\n#include\
    \ <cassert>\n#line 2 \"src/Internal/tuple_traits.hpp\"\n#include <tuple>\n#include\
    \ <array>\n#include <type_traits>\n#include <cstddef>\ntemplate <class T> static\
    \ constexpr bool tuple_like_v= false;\ntemplate <class... Args> static constexpr\
    \ bool tuple_like_v<std::tuple<Args...>> = true;\ntemplate <class T, class U>\
    \ static constexpr bool tuple_like_v<std::pair<T, U>> = true;\ntemplate <class\
    \ T, size_t K> static constexpr bool tuple_like_v<std::array<T, K>> = true;\n\
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
    \ to_array_t= decltype(to_array(T()));\n#line 9 \"src/DataStructure/SegmentTree_2D.hpp\"\
    \ntemplate <class pos_t, class M> class SegmentTree_2D {\n using T= typename M::T;\n\
    \ using Pos= std::array<pos_t, 2>;\n std::vector<pos_t> xs;\n std::vector<Pos>\
    \ yxs;\n std::vector<int> id, tol;\n std::vector<T> val;\n template <class P>\
    \ using canbe_Pos= std::is_convertible<to_tuple_t<P>, std::tuple<pos_t, pos_t>>;\n\
    \ template <class P> using canbe_PosV= std::is_convertible<to_tuple_t<P>, std::tuple<pos_t,\
    \ pos_t, T>>;\n template <class P, class U> static constexpr bool canbe_Pos_and_T_v=\
    \ std::conjunction_v<canbe_Pos<P>, std::is_convertible<U, T>>;\n int sz;\n inline\
    \ int x2i(pos_t x) const { return std::lower_bound(xs.begin(), xs.end(), x) -\
    \ xs.begin(); }\n inline int y2i(pos_t y) const {\n  return std::lower_bound(yxs.begin(),\
    \ yxs.end(), Pos{y, 0}, [](const Pos &a, const Pos &b) { return a[0] < b[0]; })\
    \ - yxs.begin();\n }\n inline int xy2i(pos_t x, pos_t y) const {\n  Pos p{y, x};\n\
    \  auto it= std::lower_bound(yxs.begin(), yxs.end(), p);\n  return assert(p ==\
    \ *it), it - yxs.begin();\n }\n template <bool z, size_t k, class P> inline auto\
    \ get_(const P &p) {\n  if constexpr (z) return std::get<k>(p);\n  else return\
    \ std::get<k>(p.first);\n }\n template <bool z, class XYW> inline void build(const\
    \ XYW *xyw, int n, const T &v= M::ti()) {\n  xs.resize(n), yxs.resize(n);\n  for\
    \ (int i= n; i--;) xs[i]= get_<z, 0>(xyw[i]);\n  std::sort(xs.begin(), xs.end()),\
    \ xs.erase(std::unique(xs.begin(), xs.end()), xs.end()), id.resize((sz= 1 << (32\
    \ - __builtin_clz(xs.size()))) * 2 + 1);\n  std::vector<int> ix(n), ord(n);\n\
    \  for (int i= n; i--;) ix[i]= x2i(get_<z, 0>(xyw[i]));\n  for (int i: ix)\n \
    \  for (i+= sz; i; i>>= 1) ++id[i + 1];\n  for (int i= 1, e= sz * 2; i < e; ++i)\
    \ id[i + 1]+= id[i];\n  val.assign(id.back() * 2, M::ti()), tol.resize(id[sz]\
    \ + 1), std::iota(ord.begin(), ord.end(), 0), std::sort(ord.begin(), ord.end(),\
    \ [&](int i, int j) { return get_<z, 1>(xyw[i]) == get_<z, 1>(xyw[j]) ? get_<z,\
    \ 0>(xyw[i]) < get_<z, 0>(xyw[j]) : get_<z, 1>(xyw[i]) < get_<z, 1>(xyw[j]); });\n\
    \  for (int i= n; i--;) yxs[i]= {get_<z, 1>(xyw[ord[i]]), get_<z, 0>(xyw[ord[i]])};\n\
    \  std::vector<int> ptr= id;\n  for (int r: ord)\n   for (int i= ix[r] + sz, j=\
    \ -1; i; j= i, i>>= 1) {\n    int p= ptr[i]++;\n    if constexpr (z) {\n     if\
    \ constexpr (std::tuple_size_v<XYW> == 3) val[id[i + 1] + p]= std::get<2>(xyw[r]);\n\
    \     else val[id[i + 1] + p]= v;\n    } else val[id[i + 1] + p]= xyw[r].second;\n\
    \    if (j != -1) tol[p + 1]= !(j & 1);\n   }\n  for (int i= 1, e= id[sz]; i <\
    \ e; ++i) tol[i + 1]+= tol[i];\n  for (int i= 0, e= sz * 2; i < e; ++i) {\n  \
    \ auto dat= val.begin() + id[i] * 2;\n   for (int j= id[i + 1] - id[i]; --j >\
    \ 0;) dat[j]= M::op(dat[j * 2], dat[j * 2 + 1]);\n  }\n }\n inline T prod(int\
    \ i, int a, int b) const {\n  int n= id[i + 1] - id[i];\n  T ret= M::ti();\n \
    \ auto dat= val.begin() + id[i] * 2;\n  for (a+= n, b+= n; a < b; a>>= 1, b>>=\
    \ 1) {\n   if (a & 1) ret= M::op(ret, dat[a++]);\n   if (b & 1) ret= M::op(dat[--b],\
    \ ret);\n  }\n  return ret;\n }\n template <bool z> inline void seti(int i, int\
    \ j, T v) {\n  auto dat= val.begin() + id[i] * 2;\n  j+= id[i + 1] - id[i];\n\
    \  if constexpr (z) dat[j]= v;\n  else dat[j]= M::op(dat[j], v);\n  for (; j;)\
    \ j>>= 1, dat[j]= M::op(dat[2 * j], dat[2 * j + 1]);\n }\n template <bool z> inline\
    \ void set_(pos_t x, pos_t y, T v) {\n  for (int i= 1, p= xy2i(x, y);;) {\n  \
    \ if (seti<z>(i, p - id[i], v); i >= sz) break;\n   if (int lc= tol[p] - tol[id[i]],\
    \ rc= (p - id[i]) - lc; tol[p + 1] - tol[p]) p= id[2 * i] + lc, i= 2 * i;\n  \
    \ else p= id[2 * i + 1] + rc, i= 2 * i + 1;\n  }\n }\npublic:\n template <class\
    \ P, typename= std::enable_if_t<std::disjunction_v<canbe_Pos<P>, canbe_PosV<P>>>>\
    \ SegmentTree_2D(const P *p, size_t n) { build<1>(p, n); }\n template <class P,\
    \ typename= std::enable_if_t<std::disjunction_v<canbe_Pos<P>, canbe_PosV<P>>>>\
    \ SegmentTree_2D(const std::vector<P> &p): SegmentTree_2D(p.data(), p.size())\
    \ {}\n template <class P, typename= std::enable_if_t<canbe_Pos<P>::value>> SegmentTree_2D(const\
    \ std::set<P> &p): SegmentTree_2D(std::vector(p.begin(), p.end())) {}\n template\
    \ <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> SegmentTree_2D(const\
    \ P *p, size_t n, const U &v) { build<1>(p, n, v); }\n template <class P, class\
    \ U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> SegmentTree_2D(const\
    \ std::vector<P> &p, const U &v): SegmentTree_2D(p.data(), p.size(), v) {}\n template\
    \ <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> SegmentTree_2D(const\
    \ std::set<P> &p, const U &v): SegmentTree_2D(std::vector(p.begin(), p.end()),\
    \ v) {}\n template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> SegmentTree_2D(const std::pair<P, U> *p, size_t n) { build<0>(p, n); }\n\
    \ template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> SegmentTree_2D(const std::vector<std::pair<P, U>> &p): SegmentTree_2D(p.data(),\
    \ p.size()) {}\n template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> SegmentTree_2D(const std::map<P, U> &p): SegmentTree_2D(std::vector(p.begin(),\
    \ p.end())) {}\n // [l,r) x [u,d)\n T prod(pos_t l, pos_t r, pos_t u, pos_t d)\
    \ const {\n  T ret= M::ti();\n  int L= x2i(l), R= x2i(r);\n  auto dfs= [&](auto\
    \ &dfs, int i, int a, int b, int c, int d) -> void {\n   if (c == d || R <= a\
    \ || b <= L) return;\n   if (L <= a && b <= R) return ret= M::op(ret, prod(i,\
    \ c, d)), void();\n   int m= (a + b) / 2, ac= tol[id[i] + c] - tol[id[i]], bc=\
    \ c - ac, ad= tol[id[i] + d] - tol[id[i]], bd= d - ad;\n   dfs(dfs, i * 2, a,\
    \ m, ac, ad), dfs(dfs, i * 2 + 1, m, b, bc, bd);\n  };\n  return dfs(dfs, 1, 0,\
    \ sz, y2i(u), y2i(d)), ret;\n }\n void set(pos_t x, pos_t y, T v) { set_<1>(x,\
    \ y, v); }\n void mul(pos_t x, pos_t y, T v) { set_<0>(x, y, v); }\n T get(pos_t\
    \ x, pos_t y) const { return val[xy2i(x, y) + id[2]]; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    #include <map>\n#include <set>\n#include <cassert>\n#include \"src/Internal/tuple_traits.hpp\"\
    \ntemplate <class pos_t, class M> class SegmentTree_2D {\n using T= typename M::T;\n\
    \ using Pos= std::array<pos_t, 2>;\n std::vector<pos_t> xs;\n std::vector<Pos>\
    \ yxs;\n std::vector<int> id, tol;\n std::vector<T> val;\n template <class P>\
    \ using canbe_Pos= std::is_convertible<to_tuple_t<P>, std::tuple<pos_t, pos_t>>;\n\
    \ template <class P> using canbe_PosV= std::is_convertible<to_tuple_t<P>, std::tuple<pos_t,\
    \ pos_t, T>>;\n template <class P, class U> static constexpr bool canbe_Pos_and_T_v=\
    \ std::conjunction_v<canbe_Pos<P>, std::is_convertible<U, T>>;\n int sz;\n inline\
    \ int x2i(pos_t x) const { return std::lower_bound(xs.begin(), xs.end(), x) -\
    \ xs.begin(); }\n inline int y2i(pos_t y) const {\n  return std::lower_bound(yxs.begin(),\
    \ yxs.end(), Pos{y, 0}, [](const Pos &a, const Pos &b) { return a[0] < b[0]; })\
    \ - yxs.begin();\n }\n inline int xy2i(pos_t x, pos_t y) const {\n  Pos p{y, x};\n\
    \  auto it= std::lower_bound(yxs.begin(), yxs.end(), p);\n  return assert(p ==\
    \ *it), it - yxs.begin();\n }\n template <bool z, size_t k, class P> inline auto\
    \ get_(const P &p) {\n  if constexpr (z) return std::get<k>(p);\n  else return\
    \ std::get<k>(p.first);\n }\n template <bool z, class XYW> inline void build(const\
    \ XYW *xyw, int n, const T &v= M::ti()) {\n  xs.resize(n), yxs.resize(n);\n  for\
    \ (int i= n; i--;) xs[i]= get_<z, 0>(xyw[i]);\n  std::sort(xs.begin(), xs.end()),\
    \ xs.erase(std::unique(xs.begin(), xs.end()), xs.end()), id.resize((sz= 1 << (32\
    \ - __builtin_clz(xs.size()))) * 2 + 1);\n  std::vector<int> ix(n), ord(n);\n\
    \  for (int i= n; i--;) ix[i]= x2i(get_<z, 0>(xyw[i]));\n  for (int i: ix)\n \
    \  for (i+= sz; i; i>>= 1) ++id[i + 1];\n  for (int i= 1, e= sz * 2; i < e; ++i)\
    \ id[i + 1]+= id[i];\n  val.assign(id.back() * 2, M::ti()), tol.resize(id[sz]\
    \ + 1), std::iota(ord.begin(), ord.end(), 0), std::sort(ord.begin(), ord.end(),\
    \ [&](int i, int j) { return get_<z, 1>(xyw[i]) == get_<z, 1>(xyw[j]) ? get_<z,\
    \ 0>(xyw[i]) < get_<z, 0>(xyw[j]) : get_<z, 1>(xyw[i]) < get_<z, 1>(xyw[j]); });\n\
    \  for (int i= n; i--;) yxs[i]= {get_<z, 1>(xyw[ord[i]]), get_<z, 0>(xyw[ord[i]])};\n\
    \  std::vector<int> ptr= id;\n  for (int r: ord)\n   for (int i= ix[r] + sz, j=\
    \ -1; i; j= i, i>>= 1) {\n    int p= ptr[i]++;\n    if constexpr (z) {\n     if\
    \ constexpr (std::tuple_size_v<XYW> == 3) val[id[i + 1] + p]= std::get<2>(xyw[r]);\n\
    \     else val[id[i + 1] + p]= v;\n    } else val[id[i + 1] + p]= xyw[r].second;\n\
    \    if (j != -1) tol[p + 1]= !(j & 1);\n   }\n  for (int i= 1, e= id[sz]; i <\
    \ e; ++i) tol[i + 1]+= tol[i];\n  for (int i= 0, e= sz * 2; i < e; ++i) {\n  \
    \ auto dat= val.begin() + id[i] * 2;\n   for (int j= id[i + 1] - id[i]; --j >\
    \ 0;) dat[j]= M::op(dat[j * 2], dat[j * 2 + 1]);\n  }\n }\n inline T prod(int\
    \ i, int a, int b) const {\n  int n= id[i + 1] - id[i];\n  T ret= M::ti();\n \
    \ auto dat= val.begin() + id[i] * 2;\n  for (a+= n, b+= n; a < b; a>>= 1, b>>=\
    \ 1) {\n   if (a & 1) ret= M::op(ret, dat[a++]);\n   if (b & 1) ret= M::op(dat[--b],\
    \ ret);\n  }\n  return ret;\n }\n template <bool z> inline void seti(int i, int\
    \ j, T v) {\n  auto dat= val.begin() + id[i] * 2;\n  j+= id[i + 1] - id[i];\n\
    \  if constexpr (z) dat[j]= v;\n  else dat[j]= M::op(dat[j], v);\n  for (; j;)\
    \ j>>= 1, dat[j]= M::op(dat[2 * j], dat[2 * j + 1]);\n }\n template <bool z> inline\
    \ void set_(pos_t x, pos_t y, T v) {\n  for (int i= 1, p= xy2i(x, y);;) {\n  \
    \ if (seti<z>(i, p - id[i], v); i >= sz) break;\n   if (int lc= tol[p] - tol[id[i]],\
    \ rc= (p - id[i]) - lc; tol[p + 1] - tol[p]) p= id[2 * i] + lc, i= 2 * i;\n  \
    \ else p= id[2 * i + 1] + rc, i= 2 * i + 1;\n  }\n }\npublic:\n template <class\
    \ P, typename= std::enable_if_t<std::disjunction_v<canbe_Pos<P>, canbe_PosV<P>>>>\
    \ SegmentTree_2D(const P *p, size_t n) { build<1>(p, n); }\n template <class P,\
    \ typename= std::enable_if_t<std::disjunction_v<canbe_Pos<P>, canbe_PosV<P>>>>\
    \ SegmentTree_2D(const std::vector<P> &p): SegmentTree_2D(p.data(), p.size())\
    \ {}\n template <class P, typename= std::enable_if_t<canbe_Pos<P>::value>> SegmentTree_2D(const\
    \ std::set<P> &p): SegmentTree_2D(std::vector(p.begin(), p.end())) {}\n template\
    \ <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> SegmentTree_2D(const\
    \ P *p, size_t n, const U &v) { build<1>(p, n, v); }\n template <class P, class\
    \ U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> SegmentTree_2D(const\
    \ std::vector<P> &p, const U &v): SegmentTree_2D(p.data(), p.size(), v) {}\n template\
    \ <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P, U>>> SegmentTree_2D(const\
    \ std::set<P> &p, const U &v): SegmentTree_2D(std::vector(p.begin(), p.end()),\
    \ v) {}\n template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> SegmentTree_2D(const std::pair<P, U> *p, size_t n) { build<0>(p, n); }\n\
    \ template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> SegmentTree_2D(const std::vector<std::pair<P, U>> &p): SegmentTree_2D(p.data(),\
    \ p.size()) {}\n template <class P, class U, typename= std::enable_if_t<canbe_Pos_and_T_v<P,\
    \ U>>> SegmentTree_2D(const std::map<P, U> &p): SegmentTree_2D(std::vector(p.begin(),\
    \ p.end())) {}\n // [l,r) x [u,d)\n T prod(pos_t l, pos_t r, pos_t u, pos_t d)\
    \ const {\n  T ret= M::ti();\n  int L= x2i(l), R= x2i(r);\n  auto dfs= [&](auto\
    \ &dfs, int i, int a, int b, int c, int d) -> void {\n   if (c == d || R <= a\
    \ || b <= L) return;\n   if (L <= a && b <= R) return ret= M::op(ret, prod(i,\
    \ c, d)), void();\n   int m= (a + b) / 2, ac= tol[id[i] + c] - tol[id[i]], bc=\
    \ c - ac, ad= tol[id[i] + d] - tol[id[i]], bd= d - ad;\n   dfs(dfs, i * 2, a,\
    \ m, ac, ad), dfs(dfs, i * 2 + 1, m, b, bc, bd);\n  };\n  return dfs(dfs, 1, 0,\
    \ sz, y2i(u), y2i(d)), ret;\n }\n void set(pos_t x, pos_t y, T v) { set_<1>(x,\
    \ y, v); }\n void mul(pos_t x, pos_t y, T v) { set_<0>(x, y, v); }\n T get(pos_t\
    \ x, pos_t y) const { return val[xy2i(x, y) + id[2]]; }\n};"
  dependsOn:
  - src/Internal/tuple_traits.hpp
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_2D.hpp
  requiredBy: []
  timestamp: '2024-04-13 13:36:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1625.Seg2D.test.cpp
  - test/yukicoder/1216.Seg2D.test.cpp
  - test/yukicoder/2065.Seg2D.test.cpp
  - test/yukicoder/1649.Seg2D.test.cpp
  - test/yukicoder/1600.Seg2D.test.cpp
  - test/yukicoder/924.Seg2D.test.cpp
  - test/atcoder/abc309_f.Seg2D.test.cpp
  - test/atcoder/abc228_f.Seg2D.test.cpp
  - test/yosupo/point_add_rectangle_sum.Seg2D.test.cpp
  - test/aoj/2842.Seg2D.test.cpp
  - test/aoj/1068.Seg2D.test.cpp
documentation_of: src/DataStructure/SegmentTree_2D.hpp
layout: document
title: "Segment-Tree(2\u6B21\u5143)"
---

半群は乗らない. モノイドの単位元 `M::ti` は明示的に与える必要あり. 

## テンプレート  `SegmentTree_2D<class pos_t, class M>`

`pos_t` : 座標(一次元)を表現する型. 通常 int とか使う.\
`M` : いつものモノイドのやつを与える. 

## メンバ関数

使用例で出てくる`RMQ`は次のような感じ.
```c++
struct RMQ{
 using T=int;
 static T ti(){return 1<<31;}
 static T op(T l,T r){return min(l,r);}
};
```

|名前|概要|
|---|---|
|`SegmentTree_2D(P* p, n)` <br> `SegmentTree_2D(vector<P>& p)` <br> `SegmentTree_2D(set<P>& p)` <br>(クラス`P` は `tuple<pos_t,pos_t>` like)|コンストラクタ. <br> n個の点の座標を与える. <br> この時の初期値はモノイドの単位元.|

使用例
```c++
vector<array<int>> xy(N);
for(auto&[x,y]:xy) cin>>x>>y;
SegmentTree_2D<int,RMQ> seg(xy);
```

|||
|---|---|
|`SegmentTree_2D(P* p,int n, U v)` <br> `SegmentTree_2D(vector<P>& p, U v)` <br> `SegmentTree_2D(set<P>& p, U v)` <br>(クラス`P` は `tuple<pos_t,pos_t>` like)|コンストラクタ. <br> n個の点の座標と点に乗せる共通の初期値を与える.|

使用例
```c++
vector<array<int>> xy(N);
for(auto&[x,y]:xy) cin>>x>>y;
SegmentTree_2D<int,RMQ> seg(xy,1);
```

|||
|---|---|
|`SegmentTree_2D(P* p,int n)` <br> `SegmentTree_2D(vector<P>& p)` <br> (クラス`P` は `tuple<pos_t,pos_t,T>` like)|コンストラクタ. <br> n個の点の座標と各々の点に乗せる初期値を与える.|

使用例
```c++
vector<array<int,3>> xyv(N);
for(auto&[x,y,v]:xyv) cin>>x>>y>>v;
SegmentTree_2D<int,RMQ> seg(xyv);
```

|||
|---|---|
|`SegmentTree_2D(pair<P,U>* p,int n)` <br> `SegmentTree_2D(vector<pair<P,U>>& p)` <br> `SegmentTree_2D(map<P,U>& p)` <br> (クラス`P` は `tuple<pos_t,pos_t>` like)|コンストラクタ. <br> n個の点の座標と各々の点に乗せる初期値を与える.|

使用例
```c++
map<array<int>,int> xyv;
for(int i=0;i<N;++i){
 int x,y,v;cin>>x>>y>>v;
 xyv[{x,y}] += v;
}
SegmentTree_2D<int,RMQ> seg(xyv);
```

|||計算量|
|---|---|---|
|`fold(l,r,u,d)`| 直方体(長方形) 内部に位置する点についてその点に乗っている値を集約した値を返す. <br> **※半開区間** $\lbrack l,r )\times \lbrack u,d)$ |以下, 点の個数を $n$ とする. <br> $\mathcal{O}((\log n)^2)$|
|`set(x,y,v)`|点 $(x,y)$ の値を `v` に変更する. <br> 点が存在しないとassertで落ちる.|$\mathcal{O}(\log n)$|
|`get(x,y)`|点 $(x,y)$ の値を返す.　<br> 点が存在しないとassertで落ちる.|$\mathcal{O}(\log n)$|
|`mul(x,y,v)`|点 $(x,y)$ の値に `v` を (モノイド演算で) かける. <br> 点が存在しないとassertで落ちる.|$\mathcal{O}(\log n)$|

## 問題例
[AtCoder Beginner Contest 266 Ex - Snuke Panic (2D)](https://atcoder.jp/contests/abc266/tasks/abc266_h) (2次元 max) \
[技術室奥プログラミングコンテスト#6 Day1 N - Jump and Walk](https://atcoder.jp/contests/tkppc6-1/tasks/tkppc6_1_n) (2次元 min, kdtだとTLE)\
[JOI 2018/2019 春合宿 過去問 A - 試験 (Examination)](https://atcoder.jp/contests/joisc2019/tasks/joisc2019_a)(2次元 sum + 走査)\
[H - 3人の昼食 (The Lunch)](https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_h)\
[Happy Query Contest 2019 Grid Xor Query](https://www.hackerrank.com/contests/happy-query-contest/challenges/grid-xor-query) (2次元 xor)