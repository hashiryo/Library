---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc222_g.test.cpp
    title: test/atcoder/abc222_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/binomial_coefficient_prime_mod.test.cpp
    title: test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det_arbitrary_mod.test.cpp
    title: test/yosupo/matrix_det_arbitrary_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test/yukicoder/950.test.cpp
    title: test/yukicoder/950.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include\
    \ <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod)\
    \ {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for (Int\
    \ q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b * q;\n\
    \ return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\
    \nnamespace math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32=\
    \ uint32_t;\nusing u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n \
    \ if (l+= r; l >= M) l-= M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n\
    \ CE IL U diff(U l, U r) const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return\
    \ l; \\\n }\n#define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static\
    \ CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\n\
    template <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
    \ mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod)\
    \ % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r);\
    \ }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const\
    \ { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n\
    \ }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE\
    \ u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n))\
    \ : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod -\
    \ ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na():\
    \ mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const {\
    \ return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\n\
    struct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n\
    \ CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m\
    \ - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64\
    \ quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const\
    \ { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64\
    \ mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) <<\
    \ 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n\
    \ PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n)\
    \ { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n)\
    \ const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return\
    \ (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) *\
    \ mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0),\
    \ mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m\
    \ << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n template <class\
    \ T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val()\
    \ % B::md.mod)) {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod)\
    \ ? B::md.mod - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt&\
    \ r), B::md.plus(x, r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n\
    \ FUNC(operator*(const MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x,\
    \ k, B::md))\n#undef FUNC\n CE MInt operator/(const MInt& r) const { return *this\
    \ * r.inv(); }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r;\
    \ }\n CE MInt& operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt&\
    \ operator*=(const MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const\
    \ MInt& r) { return *this= *this / r; }\n CE bool operator==(const MInt& r) const\
    \ { return B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt&\
    \ r) const { return !(*this == r); }\n CE bool operator<(const MInt& r) const\
    \ { return B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return\
    \ mod_inv<Int>(val(), B::md.mod); }\n CE inline Uint val() const { return B::md.get(x);\
    \ }\n friend ostream& operator<<(ostream& os, const MInt& r) { return os << r.val();\
    \ }\n friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is\
    \ >> v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using\
    \ ModInt= conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32,\
    \ u64, 32, 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64,\
    \ SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64,\
    \ u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate\
    \ <class mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 3 \"src/Math/ModInt_Runtime.hpp\"\nnamespace math_internal\
    \ {\nstruct r_b: m_b {};\ntemplate <class mod_t> constexpr bool is_runtimemodint_v=\
    \ is_base_of_v<r_b, mod_t>;\ntemplate <class MP, u64 M, int id> struct RB: r_b\
    \ {\n static inline void set_mod(u64 m) { md= MP(m); }\n static inline u64 max()\
    \ { return M; }\nprotected:\n static inline MP md;\n};\nclass Montgomery32 {};\n\
    class Montgomery64 {};\nclass Barrett {};\nclass Barrett2 {};\ntemplate <class\
    \ Int, int id= -1> using ModInt_Runtime= conditional_t<is_same_v<Int, Montgomery32>,\
    \ MInt<int, u32, RB<MP_Mo<u32, u64, 32, 31>, (1 << 30), id>>, conditional_t<is_same_v<Int,\
    \ Montgomery64>, MInt<i64, u64, RB<MP_Mo<u64, u128, 64, 63>, (1ull << 62), id>>,\
    \ conditional_t<is_same_v<Int, Barrett>, MInt<int, u32, RB<MP_Br, (1u << 31),\
    \ id>>, conditional_t<is_same_v<Int, Barrett2>, MInt<i64, u64, RB<MP_Br2, (1ull\
    \ << 41), id>>, conditional_t<disjunction_v<is_same<Int, i64>, is_same<Int, u64>>,\
    \ MInt<i64, u64, RB<MP_D2B1, u64(-1), id>>, MInt<int, u32, RB<MP_Na, u32(-1),\
    \ id>>>>>>>;\ntemplate <class T, enable_if_t<is_runtimemodint_v<T>, nullptr_t>\
    \ = nullptr> constexpr u64 mv() { return T::max(); }\n}\nusing math_internal::ModInt_Runtime,\
    \ math_internal::Montgomery32, math_internal::Montgomery64, math_internal::Barrett,\
    \ math_internal::Barrett2, math_internal::is_runtimemodint_v;\n"
  code: "#pragma once\n#include \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n\
    struct r_b: m_b {};\ntemplate <class mod_t> constexpr bool is_runtimemodint_v=\
    \ is_base_of_v<r_b, mod_t>;\ntemplate <class MP, u64 M, int id> struct RB: r_b\
    \ {\n static inline void set_mod(u64 m) { md= MP(m); }\n static inline u64 max()\
    \ { return M; }\nprotected:\n static inline MP md;\n};\nclass Montgomery32 {};\n\
    class Montgomery64 {};\nclass Barrett {};\nclass Barrett2 {};\ntemplate <class\
    \ Int, int id= -1> using ModInt_Runtime= conditional_t<is_same_v<Int, Montgomery32>,\
    \ MInt<int, u32, RB<MP_Mo<u32, u64, 32, 31>, (1 << 30), id>>, conditional_t<is_same_v<Int,\
    \ Montgomery64>, MInt<i64, u64, RB<MP_Mo<u64, u128, 64, 63>, (1ull << 62), id>>,\
    \ conditional_t<is_same_v<Int, Barrett>, MInt<int, u32, RB<MP_Br, (1u << 31),\
    \ id>>, conditional_t<is_same_v<Int, Barrett2>, MInt<i64, u64, RB<MP_Br2, (1ull\
    \ << 41), id>>, conditional_t<disjunction_v<is_same<Int, i64>, is_same<Int, u64>>,\
    \ MInt<i64, u64, RB<MP_D2B1, u64(-1), id>>, MInt<int, u32, RB<MP_Na, u32(-1),\
    \ id>>>>>>>;\ntemplate <class T, enable_if_t<is_runtimemodint_v<T>, nullptr_t>\
    \ = nullptr> constexpr u64 mv() { return T::max(); }\n}\nusing math_internal::ModInt_Runtime,\
    \ math_internal::Montgomery32, math_internal::Montgomery64, math_internal::Barrett,\
    \ math_internal::Barrett2, math_internal::is_runtimemodint_v;\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: false
  path: src/Math/ModInt_Runtime.hpp
  requiredBy: []
  timestamp: '2023-08-05 18:38:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/discrete_logarithm_mod.test.cpp
  - test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - test/yosupo/matrix_det_arbitrary_mod.test.cpp
  - test/yukicoder/950.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/atcoder/abc270_g.test.cpp
  - test/atcoder/abc222_g.test.cpp
documentation_of: src/Math/ModInt_Runtime.hpp
layout: document
title: "ModInt(\u5B9F\u884C\u6642mod\u30BB\u30C3\u30C8)"
---
## 問題例
[Educational DP Contest  V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v)