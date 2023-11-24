---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/LinearAlgebra/Vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB"
  - icon: ':heavy_check_mark:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  - icon: ':question:'
    path: src/Misc/rng.hpp
    title: "\u7591\u4F3C\u4E71\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.MinPoly.test.cpp
    title: test/aoj/2397.MinPoly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.MinPoly.test.cpp
    title: test/yukicoder/1750.MinPoly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/MinimalPolynomial.hpp\"\n#include <cassert>\n\
    #line 2 \"src/Internal/modint_traits.hpp\"\n#include <type_traits>\nnamespace\
    \ math_internal {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t>\
    \ constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\n\
    template <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 2 \"src/Math/berlekamp_massey.hpp\"\n#include <vector>\n// a[n]\
    \ = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1] * a[n-d]\n// return c\ntemplate\
    \ <class K> std::vector<K> berlekamp_massey(const std::vector<K> &a) {\n size_t\
    \ n= a.size(), d= 0, m= 0, i, j;\n if (n == 0) return {};\n std::vector<K> c(n),\
    \ b(n), tmp;\n K x= 1, y, coef;\n for (c[0]= b[0]= 1, i= 0, j; i < n; ++i) {\n\
    \  for (++m, y= a[i], j= 1; j <= d; ++j) y+= c[j] * a[i - j];\n  if (y == K())\
    \ continue;\n  for (tmp= c, coef= y / x, j= m; j < n; ++j) c[j]-= coef * b[j -\
    \ m];\n  if (2 * d <= i) d= i + 1 - d, b= tmp, x= y, m= 0;\n }\n c.resize(d +\
    \ 1), c.erase(c.begin());\n for (auto &x: c) x= -x;\n return c;\n}\n#line 2 \"\
    src/LinearAlgebra/Vector.hpp\"\n#include <cstdint>\n#include <valarray>\nnamespace\
    \ la_internal {\nusing namespace std;\ntemplate <class R> struct Vector: public\
    \ valarray<R> {\n using valarray<R>::valarray;\n};\nusing u128= __uint128_t;\n\
    using u8= uint8_t;\nclass Ref {\n u128 *ref;\n u8 i;\n bool val;\npublic:\n Ref(u128\
    \ *r, u8 j, bool v): ref(r), i(j), val(v) {}\n ~Ref() {\n  if (val ^ ((*ref >>\
    \ i) & 1)) *ref^= u128(1) << i;\n }\n Ref &operator=(const Ref &r) { return val=\
    \ r.val, *this; }\n Ref &operator=(bool b) { return val= b, *this; }\n Ref &operator|=(bool\
    \ b) { return val|= b, *this; }\n Ref &operator&=(bool b) { return val&= b, *this;\
    \ }\n Ref &operator^=(bool b) { return val^= b, *this; }\n operator bool() const\
    \ { return val; }\n};\ntemplate <> class Vector<bool> {\n size_t n;\n valarray<u128>\
    \ dat;\npublic:\n Vector(): n(0) {}\n Vector(size_t n): n(n), dat((n + 127) >>\
    \ 7) {}\n Vector(bool b, size_t n): n(n), dat(-u128(b), (n + 127) >> 7) {}\n Ref\
    \ operator[](int i) {\n  u128 *ref= begin(dat) + (i >> 7);\n  u8 j= i & 127;\n\
    \  bool val= (*ref >> j) & 1;\n  return Ref{ref, j, val};\n }\n bool operator[](int\
    \ i) const { return (dat[i >> 7] >> (i & 127)) & 1; }\n Vector &operator+=(const\
    \ Vector &r) { return dat^= r.dat, *this; }\n Vector &operator-=(const Vector\
    \ &r) { return dat^= r.dat, *this; }\n Vector &operator*=(bool b) {\n  if (!b)\
    \ dat= 0;\n  return *this;\n }\n Vector operator+(const Vector &r) const { return\
    \ Vector(*this)+= r; }\n Vector operator-(const Vector &r) const { return Vector(*this)-=\
    \ r; }\n Vector operator*(bool b) const { return Vector(*this)*= b; }\n size_t\
    \ size() const { return n; }\n u128 *data() { return begin(dat); }\n friend Vector\
    \ operator*(bool b, const Vector &r) { return r * b; }\n};\n}\nusing la_internal::Vector;\n\
    #line 2 \"src/Misc/rng.hpp\"\n#include <random>\n#line 4 \"src/Misc/rng.hpp\"\n\
    uint64_t rng() {\n static uint64_t x= 10150724397891781847ULL * std::random_device{}();\n\
    \ return x^= x << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t lim) { return rng()\
    \ % lim; }\nint64_t rng(int64_t l, int64_t r) { return l + rng() % (r - l); }\n\
    #line 7 \"src/LinearAlgebra/MinimalPolynomial.hpp\"\n// c s.t. (c[d] * M^d + c[d-1]\
    \ * M^(d-1)  + ... + c[1] * M + c[0]) * b = 0\ntemplate <class mod_t, class LinMap>\
    \ class MinimalPolynomial {\n std::vector<mod_t> poly, rev;\n size_t dg, n;\n\
    \ std::vector<Vector<mod_t>> bs;\n static inline int deg(const std::vector<mod_t>\
    \ &p) {\n  for (int d= p.size() - 1;; d--)\n   if (d < 0 || p[d] != mod_t()) return\
    \ d;\n }\n static inline std::vector<mod_t> bostan_mori_msb(const std::vector<mod_t>\
    \ &q, uint64_t k) {\n  int d= deg(q);\n  assert(d >= 0), assert(q[0] != mod_t());\n\
    \  std::vector<mod_t> ret(std::max(d, 1));\n  if (k == 0) return ret.back()= mod_t(1),\
    \ ret;\n  std::vector<mod_t> v(d + 1);\n  for (int i= 0; i <= d; i+= 2)\n   for\
    \ (int j= 0; j <= d; j+= 2) v[(i + j) >> 1]+= q[i] * q[j];\n  for (int i= 1; i\
    \ <= d; i+= 2)\n   for (int j= 1; j <= d; j+= 2) v[(i + j) >> 1]-= q[i] * q[j];\n\
    \  auto w= bostan_mori_msb(v, k >> 1);\n  for (int i= 2 * d - 1 - (k & 1); i >=\
    \ d; i-= 2)\n   for (int j= 0; j <= d; j+= 2) ret[i - d]+= q[j] * w[(i - j) >>\
    \ 1];\n  for (int i= 2 * d - 1 - !(k & 1); i >= d; i-= 2)\n   for (int j= 1; j\
    \ <= d; j+= 2) ret[i - d]-= q[j] * w[(i - j) >> 1];\n  return ret;\n }\n std::vector<mod_t>\
    \ x_pow_mod(uint64_t k) const {\n  assert(k >= n);\n  std::vector<mod_t> ret(n),\
    \ u= bostan_mori_msb(rev, k - n + dg);\n  for (int i= dg; i--;)\n   for (int j=\
    \ i + 1; j--;) ret[n - 1 - i]+= u[j] * rev[i - j];\n  return ret;\n }\npublic:\n\
    \ MinimalPolynomial(const LinMap &M, Vector<mod_t> b): n(b.size()), bs(n) {\n\
    \  static_assert(is_modint_v<mod_t>);\n  Vector<mod_t> a(n);\n  for (auto &x:\
    \ a) x= rng(1, mod_t::mod() - 1);\n  std::vector<mod_t> v((n + 1) << 1);\n  for\
    \ (size_t i= v.size(), j= 0;; b= M(b)) {\n   if (j < n) bs[j]= b;\n   if (v[j++]=\
    \ (a * b).sum(); !(--i)) break;\n  }\n  rev= berlekamp_massey(v);\n  for (auto\
    \ &x: rev) x= -x;\n  rev.insert(rev.begin(), 1), poly.assign(rev.rbegin(), rev.rend()),\
    \ rev.erase(rev.begin() + (dg= deg(rev)) + 1, rev.end());\n }\n Vector<mod_t>\
    \ pow(uint64_t k) const {  // M^k * b\n  if (k < n) return bs[k];\n  auto r= x_pow_mod(k);\n\
    \  Vector<mod_t> ret= r[0] * bs[0];\n  for (int i= r.size(); --i;) ret+= r[i]\
    \ * bs[i];\n  return ret;\n }\n const mod_t &operator[](size_t k) const { return\
    \ poly[k]; }\n const auto begin() const { return poly.begin(); }\n const auto\
    \ end() const { return poly.end(); }\n size_t degree() const { return dg; }\n\
    };\ntemplate <class mod_t, class LinMap> mod_t linear_map_det(const LinMap &M,\
    \ int n) {\n Vector<mod_t> b(n);\n for (auto &x: b) x= rng(1, mod_t::mod() - 1);\n\
    \ std::vector<mod_t> D(n);\n for (auto &x: D) x= rng(1, mod_t::mod() - 1);\n auto\
    \ f= [&](Vector<mod_t> a) {\n  for (int i= n; i--;) a[i]*= D[i];\n  return M(a);\n\
    \ };\n mod_t ret= MinimalPolynomial(f, b)[0], den= 1;\n if (n & 1) ret= -ret;\n\
    \ for (const auto &x: D) den*= x;\n return ret / den;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include \"src/Internal/modint_traits.hpp\"\
    \n#include \"src/Math/berlekamp_massey.hpp\"\n#include \"src/LinearAlgebra/Vector.hpp\"\
    \n#include \"src/Misc/rng.hpp\"\n// c s.t. (c[d] * M^d + c[d-1] * M^(d-1)  + ...\
    \ + c[1] * M + c[0]) * b = 0\ntemplate <class mod_t, class LinMap> class MinimalPolynomial\
    \ {\n std::vector<mod_t> poly, rev;\n size_t dg, n;\n std::vector<Vector<mod_t>>\
    \ bs;\n static inline int deg(const std::vector<mod_t> &p) {\n  for (int d= p.size()\
    \ - 1;; d--)\n   if (d < 0 || p[d] != mod_t()) return d;\n }\n static inline std::vector<mod_t>\
    \ bostan_mori_msb(const std::vector<mod_t> &q, uint64_t k) {\n  int d= deg(q);\n\
    \  assert(d >= 0), assert(q[0] != mod_t());\n  std::vector<mod_t> ret(std::max(d,\
    \ 1));\n  if (k == 0) return ret.back()= mod_t(1), ret;\n  std::vector<mod_t>\
    \ v(d + 1);\n  for (int i= 0; i <= d; i+= 2)\n   for (int j= 0; j <= d; j+= 2)\
    \ v[(i + j) >> 1]+= q[i] * q[j];\n  for (int i= 1; i <= d; i+= 2)\n   for (int\
    \ j= 1; j <= d; j+= 2) v[(i + j) >> 1]-= q[i] * q[j];\n  auto w= bostan_mori_msb(v,\
    \ k >> 1);\n  for (int i= 2 * d - 1 - (k & 1); i >= d; i-= 2)\n   for (int j=\
    \ 0; j <= d; j+= 2) ret[i - d]+= q[j] * w[(i - j) >> 1];\n  for (int i= 2 * d\
    \ - 1 - !(k & 1); i >= d; i-= 2)\n   for (int j= 1; j <= d; j+= 2) ret[i - d]-=\
    \ q[j] * w[(i - j) >> 1];\n  return ret;\n }\n std::vector<mod_t> x_pow_mod(uint64_t\
    \ k) const {\n  assert(k >= n);\n  std::vector<mod_t> ret(n), u= bostan_mori_msb(rev,\
    \ k - n + dg);\n  for (int i= dg; i--;)\n   for (int j= i + 1; j--;) ret[n - 1\
    \ - i]+= u[j] * rev[i - j];\n  return ret;\n }\npublic:\n MinimalPolynomial(const\
    \ LinMap &M, Vector<mod_t> b): n(b.size()), bs(n) {\n  static_assert(is_modint_v<mod_t>);\n\
    \  Vector<mod_t> a(n);\n  for (auto &x: a) x= rng(1, mod_t::mod() - 1);\n  std::vector<mod_t>\
    \ v((n + 1) << 1);\n  for (size_t i= v.size(), j= 0;; b= M(b)) {\n   if (j < n)\
    \ bs[j]= b;\n   if (v[j++]= (a * b).sum(); !(--i)) break;\n  }\n  rev= berlekamp_massey(v);\n\
    \  for (auto &x: rev) x= -x;\n  rev.insert(rev.begin(), 1), poly.assign(rev.rbegin(),\
    \ rev.rend()), rev.erase(rev.begin() + (dg= deg(rev)) + 1, rev.end());\n }\n Vector<mod_t>\
    \ pow(uint64_t k) const {  // M^k * b\n  if (k < n) return bs[k];\n  auto r= x_pow_mod(k);\n\
    \  Vector<mod_t> ret= r[0] * bs[0];\n  for (int i= r.size(); --i;) ret+= r[i]\
    \ * bs[i];\n  return ret;\n }\n const mod_t &operator[](size_t k) const { return\
    \ poly[k]; }\n const auto begin() const { return poly.begin(); }\n const auto\
    \ end() const { return poly.end(); }\n size_t degree() const { return dg; }\n\
    };\ntemplate <class mod_t, class LinMap> mod_t linear_map_det(const LinMap &M,\
    \ int n) {\n Vector<mod_t> b(n);\n for (auto &x: b) x= rng(1, mod_t::mod() - 1);\n\
    \ std::vector<mod_t> D(n);\n for (auto &x: D) x= rng(1, mod_t::mod() - 1);\n auto\
    \ f= [&](Vector<mod_t> a) {\n  for (int i= n; i--;) a[i]*= D[i];\n  return M(a);\n\
    \ };\n mod_t ret= MinimalPolynomial(f, b)[0], den= 1;\n if (n & 1) ret= -ret;\n\
    \ for (const auto &x: D) den*= x;\n return ret / den;\n}"
  dependsOn:
  - src/Internal/modint_traits.hpp
  - src/Math/berlekamp_massey.hpp
  - src/LinearAlgebra/Vector.hpp
  - src/Misc/rng.hpp
  isVerificationFile: false
  path: src/LinearAlgebra/MinimalPolynomial.hpp
  requiredBy: []
  timestamp: '2023-11-17 11:57:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/yukicoder/310.test.cpp
  - test/yukicoder/1750.MinPoly.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/aoj/2397.MinPoly.test.cpp
documentation_of: src/LinearAlgebra/MinimalPolynomial.hpp
layout: document
title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
---

## `MinimalPolynomial` クラス
正方行列 $M$ と ベクトル $\boldsymbol{b}$ を与えて 最小多項式 $p(x)=p_0+p_1x+\cdots+p_{d-1}x^{d-1}+x^d$ を求める. \
ただしここでの最小多項式とは、モニックな多項式であって
\\[
p(M)\boldsymbol{b} = p_0\boldsymbol{b}+p_1M\boldsymbol{b}+\cdots+p_{d-1}M^{d-1}\boldsymbol{b} + M^d\boldsymbol{b} = \boldsymbol{0}
\\]
を満たす最小次数のものを指す.

`ModInt` クラスを前提にしている.

### メンバ関数

| 関数                     | 概要                                                                                                                                                 | 計算量                                                                         |
| ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| `MinimalPolynomial(M,b)` | コンストラクタ. 表現行列が $n\times n$ 正方行列な線型写像 $M$ ( `Vector` $\rightarrow$ `Vector` の関数 or `Matrix` クラス) とベクトル $\boldsymbol{b}$ ( `Vector` クラス ) を与えて最小多項式を求める | $\mathcal{O}(n^2+nT(n))$<br> ただし $T(n)$ は $M$ とベクトルの乗算にかかる時間 |
| `degree()`               | 最小多項式の次元を返す                                                                                                                               | $\mathcal{O}(1)$                                                               |
| `operator[](i)`          | 最小多項式の$x^i$の係数を返す                                                                                                                        | $\mathcal{O}(1)$                                                               |
| `pow(k)`                 | $M^k\boldsymbol{b}$ ( `Vector` クラス ) を返す                                                                                                       | $\mathcal{O}(n^2\log k)$                                                       |

## その他関数

| 関数     | 概要                                                                                   | 計算量                                                                         |
| -------- | -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| `linear_map_det(M,n)` | 表現行列が $n\times n$ 正方行列な線型写像 $M$ ( `Vector` $\rightarrow$ `Vector` の関数 or `Matrix` クラス) の行列式 $\det M$ の値を返す | $\mathcal{O}(n^2+nT(n))$<br> ただし $T(n)$ は $M$ とベクトルの乗算にかかる時間 |


## 参考
[https://yukicoder.me/wiki/black_box_linear_algebra](https://yukicoder.me/wiki/black_box_linear_algebra)