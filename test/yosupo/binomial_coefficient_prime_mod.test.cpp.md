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
    path: src/Math/FactorialPrecalculation.hpp
    title: "\u4E8C\u9805\u4FC2\u6570 \u4ED6 (\u968E\u4E57\u524D\u8A08\u7B97) ($\\\
      mathbb{F}_p$)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModInt_Runtime.hpp
    title: "ModInt(\u5B9F\u884C\u6642mod\u30BB\u30C3\u30C8)"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/yosupo/binomial_coefficient_prime_mod.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include <iostream>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n\
    #include <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int\
    \ mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for\
    \ (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b\
    \ * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing i64= long long;\n\
    using u64= unsigned long long;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return l+= r, l < (M) ? l : l\
    \ - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { return l-=\
    \ r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static CE IL U set(U n) { return\
    \ n; } \\\n static CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n)\
    \ { return n; }\ntemplate <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n\
    \ u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)),\
    \ r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l)\
    \ * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n)\
    \ const { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n\
    \  NORM;\n }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n\
    \ static CE u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x *\
    \ (2 - x * n)) : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >>\
    \ B) + mod - ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n\
    \ CE MP_Na(): mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32\
    \ r) const { return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n\
    };\nstruct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0)\
    \ {}\n CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s)\
    \ + m - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r);\
    \ }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE\
    \ IL u64 quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n)\
    \ const { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n\
    \ u64 mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1)\
    \ << 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r);\
    \ }\n PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64\
    \ n) { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64\
    \ n) const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const\
    \ { return (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n -\
    \ quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1():\
    \ s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m),\
    \ d(m << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
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
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 3 \"src/Math/ModInt_Runtime.hpp\"\
    \nnamespace math_internal {\nstruct r_b: m_b {};\ntemplate <class mod_t> constexpr\
    \ bool is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class MP, u64\
    \ M, int id> struct RB: r_b {\n static inline void set_mod(u64 m) { md= MP(m);\
    \ }\n static inline u64 max() { return M; }\nprotected:\n static inline MP md;\n\
    };\nclass Montgomery32 {};\nclass Montgomery64 {};\nclass Barrett {};\nclass Barrett2\
    \ {};\ntemplate <class Int, int id= -1> using ModInt_Runtime= conditional_t<is_same_v<Int,\
    \ Montgomery32>, MInt<int, u32, RB<MP_Mo<u32, u64, 32, 31>, (1 << 30), id>>, conditional_t<is_same_v<Int,\
    \ Montgomery64>, MInt<i64, u64, RB<MP_Mo<u64, u128, 64, 63>, (1ull << 62), id>>,\
    \ conditional_t<is_same_v<Int, Barrett>, MInt<int, u32, RB<MP_Br, (1u << 31),\
    \ id>>, conditional_t<is_same_v<Int, Barrett2>, MInt<i64, u64, RB<MP_Br2, (1ull\
    \ << 41), id>>, conditional_t<disjunction_v<is_same<Int, i64>, is_same<Int, u64>>,\
    \ MInt<i64, u64, RB<MP_D2B1, u64(-1), id>>, MInt<int, u32, RB<MP_Na, u32(-1),\
    \ id>>>>>>>;\ntemplate <class T, enable_if_t<is_runtimemodint_v<T>, nullptr_t>\
    \ = nullptr> constexpr u64 mv() { return T::max(); }\n}\nusing math_internal::ModInt_Runtime,\
    \ math_internal::Montgomery32, math_internal::Montgomery64, math_internal::Barrett,\
    \ math_internal::Barrett2, math_internal::is_runtimemodint_v;\n#line 3 \"src/Math/FactorialPrecalculation.hpp\"\
    \n#include <vector>\n#line 5 \"src/Math/FactorialPrecalculation.hpp\"\ntemplate\
    \ <class mod_t> class FactorialPrecalculation {\n static_assert(is_modint_v<mod_t>);\n\
    \ static inline std::vector<mod_t> iv, fct, fiv;\npublic:\n static void reset()\
    \ { iv.clear(), fct.clear(), fiv.clear(); }\n static inline mod_t inv(int n) {\n\
    \  assert(0 < n);\n  if (int k= iv.size(); k <= n) {\n   if (iv.resize(n + 1);\
    \ !k) iv[1]= 1, k= 2;\n   for (int mod= mod_t::mod(), q; k <= n; ++k) q= (mod\
    \ + k - 1) / k, iv[k]= iv[k * q - mod] * q;\n  }\n  return iv[n];\n }\n static\
    \ inline mod_t fact(int n) {\n  assert(0 <= n);\n  if (int k= fct.size(); k <=\
    \ n) {\n   if (fct.resize(n + 1); !k) fct[0]= 1, k= 1;\n   for (; k <= n; ++k)\
    \ fct[k]= fct[k - 1] * k;\n  }\n  return fct[n];\n }\n static inline mod_t finv(int\
    \ n) {\n  assert(0 <= n);\n  if (int k= fiv.size(); k <= n) {\n   if (fiv.resize(n\
    \ + 1); !k) fiv[0]= 1, k= 1;\n   for (; k <= n; ++k) fiv[k]= fiv[k - 1] * inv(k);\n\
    \  }\n  return fiv[n];\n }\n static inline mod_t nPr(int n, int r) { return r\
    \ < 0 || n < r ? mod_t(0) : fact(n) * finv(n - r); }\n // [x^r] (1 + x)^n\n static\
    \ inline mod_t nCr(int n, int r) { return r < 0 || n < r ? mod_t(0) : fact(n)\
    \ * finv(n - r) * finv(r); }\n // [x^r] (1 - x)^{-n}\n static inline mod_t nHr(int\
    \ n, int r) { return !r ? mod_t(1) : nCr(n + r - 1, r); }\n};\n#line 5 \"test/yosupo/binomial_coefficient_prime_mod.test.cpp\"\
    \nusing namespace std;\nint main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt_Runtime<int>;\n using F= FactorialPrecalculation<Mint>;\n\
    \ int T, m;\n cin >> T >> m;\n Mint::set_mod(m);\n while (T--) {\n  int n, k;\n\
    \  cin >> n >> k;\n  cout << F::nCr(n, k) << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include <iostream>\n#include \"src/Math/ModInt_Runtime.hpp\"\n#include \"src/Math/FactorialPrecalculation.hpp\"\
    \nusing namespace std;\nint main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt_Runtime<int>;\n using F= FactorialPrecalculation<Mint>;\n\
    \ int T, m;\n cin >> T >> m;\n Mint::set_mod(m);\n while (T--) {\n  int n, k;\n\
    \  cin >> n >> k;\n  cout << F::nCr(n, k) << '\\n';\n }\n return 0;\n}\n"
  dependsOn:
  - src/Math/ModInt_Runtime.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/FactorialPrecalculation.hpp
  isVerificationFile: true
  path: test/yosupo/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2024-02-03 19:27:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/binomial_coefficient_prime_mod.test.cpp
- /verify/test/yosupo/binomial_coefficient_prime_mod.test.cpp.html
title: test/yosupo/binomial_coefficient_prime_mod.test.cpp
---