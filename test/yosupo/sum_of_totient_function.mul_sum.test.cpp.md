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
  - icon: ':question:'
    path: src/NumberTheory/ExtendedEratosthenesSieve.hpp
    title: "\u62E1\u5F35\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u7BE9"
  - icon: ':question:'
    path: src/NumberTheory/famous_arithmetic_functions.hpp
    title: "\u6709\u540D\u306A\u6570\u8AD6\u7684\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/yosupo/sum_of_totient_function.mul_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
    // O(N^(3/4)/log N)\n#include <iostream>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include\
    \ <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b),\
    \ z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod\
    \ : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return\
    \ l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l,\
    \ U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static\
    \ CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\
    \n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/NumberTheory/ExtendedEratosthenesSieve.hpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <tuple>\n#include <cmath>\n\
    #include <cstdint>\ntemplate <class T> struct PrimeSum {\n uint64_t N;\n size_t\
    \ K;\n std::vector<T> Xs, Xl;\n PrimeSum(uint64_t N= 0): N(N), K(std::sqrt(N)),\
    \ Xs(K + 1), Xl(K + 1) {}\n PrimeSum(uint64_t N, size_t K, const std::vector<T>\
    \ &s, const std::vector<T> &l): N(N), K(K), Xs(s), Xl(l) {}\n PrimeSum operator-()\
    \ const {\n  auto Ys= Xs, Yl= Xl;\n  for (auto &x: Ys) x= -x;\n  for (auto &x:\
    \ Yl) x= -x;\n  return PrimeSum(N, K, Ys, Yl);\n }\n PrimeSum &operator*=(T r)\
    \ {\n  for (auto &x: Xs) x*= r;\n  for (auto &x: Xl) x*= r;\n  return *this;\n\
    \ }\n PrimeSum &operator+=(const PrimeSum &r) {\n  for (size_t i= K + 1; i--;)\
    \ Xs[i]+= r.Xs[i];\n  for (size_t i= K + 1; i--;) Xl[i]+= r.Xl[i];\n  return *this;\n\
    \ }\n PrimeSum &operator-=(const PrimeSum &r) {\n  for (size_t i= K + 1; i--;)\
    \ Xs[i]-= r.Xs[i];\n  for (size_t i= K + 1; i--;) Xl[i]-= r.Xl[i];\n  return *this;\n\
    \ }\n PrimeSum operator*(T r) const { return PrimeSum(*this)*= r; }\n friend PrimeSum\
    \ operator*(T l, const PrimeSum &r) { return r * l; }\n PrimeSum operator+(const\
    \ PrimeSum &r) const { return PrimeSum(*this)+= r; }\n PrimeSum operator-(const\
    \ PrimeSum &r) const { return PrimeSum(*this)-= r; }\n inline T sum() const {\
    \ return Xl[1]; }\n inline T sum(uint64_t n) const { return n <= K ? Xs[n] : Xl[N\
    \ / n]; }\n void add(uint64_t p, T v) {\n  for (size_t i= p; i <= K; ++i) Xs[i]+=\
    \ v;\n  for (size_t i= std::min<uint64_t>(N / p, K); i; --i) Xl[i]+= v;\n }\n\
    };\ntemplate <class T> class ExtendedEratosthenesSieve {\n uint64_t N;\n size_t\
    \ K;\npublic:\n std::vector<size_t> primes;\n std::vector<PrimeSum<T>> pwsum;\n\
    \ ExtendedEratosthenesSieve(uint64_t N, size_t D): N(N), K(std::sqrt(N)), pwsum(D\
    \ + 1) {\n  std::vector<std::vector<T>> s(D + 1, std::vector<T>(K + 1)), l(D +\
    \ 1, std::vector<T>(K + 1));\n  T fct= 1;\n  for (size_t d= D + 1; d; --d) fct*=\
    \ d;\n  fct= T(1) / fct;\n  for (size_t n= 1, d= 0; n <= K; ++n, d= 0)\n   for\
    \ (T prd= n; d <= D; prd*= (n + ++d)) s[d][n]= prd;\n  for (size_t n= 1, d= 0;\
    \ n <= K; ++n, d= 0)\n   for (T prd= N / n; d <= D; prd*= ((N / n) + ++d)) l[d][n]=\
    \ prd;\n  for (size_t d= D + 1; --d; fct*= d + 1)\n   for (size_t n= 1; n <= K;\
    \ ++n) s[d][n]*= fct, l[d][n]*= fct;\n  if (D >= 2) {\n   std::vector<T> stir(D\
    \ + 1, 0);\n   stir[1]= 1;\n   for (size_t d= 2; d <= D; stir[d++]= 1) {\n   \
    \ for (size_t j= d; --j;) stir[j]= stir[j - 1] + stir[j] * (d - 1);\n    for (size_t\
    \ n= 1; n <= K; ++n)\n     for (size_t j= 1; j < d; ++j) s[d][n]-= stir[j] * s[j][n],\
    \ l[d][n]-= stir[j] * l[j][n];\n   }\n  }\n  for (size_t d= 0; d <= D; ++d)\n\
    \   for (size_t n= 1; n <= K; ++n) s[d][n]-= 1, l[d][n]-= 1;\n  for (size_t p=\
    \ 2, d= 0; p <= K; ++p, d= 0)\n   if (s[0][p] != s[0][p - 1]) {\n    primes.emplace_back(p);\n\
    \    uint64_t q= uint64_t(p) * p, M= N / p;\n    int t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n    for (T pw= 1; d <= D; ++d, pw*= p) {\n     T tk= s[d][p - 1];\n\
    \     for (int n= 1; n <= t; ++n) l[d][n]-= (l[d][n * p] - tk) * pw;\n     for\
    \ (int n= t + 1; n <= u; ++n) l[d][n]-= (s[d][M / n] - tk) * pw;\n     for (uint64_t\
    \ n= K; n >= q; --n) s[d][n]-= (s[d][n / p] - tk) * pw;\n    }\n   }\n  for (int\
    \ d= 0; d <= D; ++d) pwsum[d]= PrimeSum(N, K, s[d], l[d]);\n }\n template <class\
    \ F> T additive_sum(const F &f, const PrimeSum<T> &X) const {\n  T ret= X.sum();\n\
    \  for (uint64_t d= 2, nN, nd; nN; d= nd) ret+= X.sum(nN= N / d) * ((nd= N / nN\
    \ + 1) - d);\n  for (uint64_t p: primes)\n   for (uint64_t pw= p * p, e= 2; pw\
    \ <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * (N / pw);\n  return ret;\n\
    \ }\n template <class F> T additive_sum(const F &f, const std::vector<T> &poly)\
    \ const {\n  PrimeSum<T> X(N);\n  assert(poly.size() <= pwsum.size());\n  for\
    \ (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n  return additive_sum(f,\
    \ X);\n }\n template <class F> T multiplicative_sum(const F &f, PrimeSum<T> X)\
    \ const {\n  size_t psz= primes.size();\n  for (size_t j= psz; j--;) {\n   uint64_t\
    \ p= primes[j], M= N / p, q= p * p;\n   size_t t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n   T tk= X.Xs[p - 1];\n   for (auto i= q; i <= K; ++i) X.Xs[i]+= (X.Xs[i\
    \ / p] - tk) * f(p, 1);\n   for (size_t i= u; i > t; --i) X.Xl[i]+= (X.Xs[M /\
    \ i] - tk) * f(p, 1);\n   for (size_t i= t; i; --i) X.Xl[i]+= (X.Xl[i * p] - tk)\
    \ * f(p, 1);\n  }\n  for (auto n= K; n; --n) X.Xs[n]+= 1;\n  for (auto n= K; n;\
    \ --n) X.Xl[n]+= 1;\n  auto dfs= [&](auto &rc, uint64_t n, size_t bg, T cf) ->\
    \ T {\n   if (cf == T(0)) return T(0);\n   T ret= cf * X.sum(n);\n   for (auto\
    \ i= bg; i < psz; ++i) {\n    uint64_t p= primes[i], q= p * p, nn= n / q;\n  \
    \  if (!nn) break;\n    for (int e= 2; nn; nn/= p, ++e) ret+= rc(rc, nn, i + 1,\
    \ cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n   }\n   return ret;\n  };\n  return\
    \ dfs(dfs, N, 0, 1);\n }\n template <class F> T multiplicative_sum(const F &f,\
    \ const std::vector<T> &poly) const {\n  PrimeSum<T> X(N);\n  assert(poly.size()\
    \ <= pwsum.size());\n  for (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n\
    \  return multiplicative_sum(f, X);\n }\n};\n#line 4 \"src/NumberTheory/famous_arithmetic_functions.hpp\"\
    \nnamespace famous_arithmetic_functions {\nnamespace mul {\ntemplate <class T>\
    \ struct Totient {\n static constexpr T f(uint64_t p, short e) {\n  T ret= p -\
    \ 1;\n  while (--e) ret*= p;\n  return ret;\n }\n static std::vector<T> poly()\
    \ { return {-1, 1}; }\n};\ntemplate <class T> struct Moebius {\n static constexpr\
    \ T f(uint64_t, short e) { return (e == 0) - (e == 1); }\n static std::vector<T>\
    \ poly() { return {-1}; }\n};\ntemplate <class T> struct Liouville {\n static\
    \ constexpr T f(uint64_t, short e) { return e & 1 ? -1 : 1; }\n static std::vector<T>\
    \ poly() { return {-1}; }\n};\ntemplate <class T, uint64_t k> struct Divisor {\n\
    \ static constexpr T f(uint64_t p, short e) {\n  T ret= 0, pk= 1, pkpw= 1, b=\
    \ p;\n  for (uint64_t kk= k; kk; kk>>= 1, b*= b)\n   if (kk & 1) pk*= b;\n  for\
    \ (short i= 0; i <= e; i++, pkpw*= pk) ret+= pkpw;\n  return ret;\n }\n static\
    \ std::vector<T> poly() {\n  std::vector<T> ret(k + 1, 0);\n  return ret[0]+=\
    \ 1, ret[k]+= 1, ret;\n }\n};\ntemplate <class T> struct Dedekind {\n static constexpr\
    \ T f(uint64_t p, short e) {\n  T ret= p + 1;\n  while (e-- > 1) ret*= p;\n  return\
    \ ret;\n }\n static std::vector<T> poly() { return {1, 1}; }\n};\n}  // namespace\
    \ mul\nnamespace add {\ntemplate <class T> struct BigOmega {  // the total number\
    \ of prime factors of n\n static constexpr T f(uint64_t, short e) { return e;\
    \ }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class T> struct\
    \ LittleOmega {  // the total number of different prime factors of n\n static\
    \ constexpr T f(uint64_t, short) { return 1; }\n static std::vector<T> poly()\
    \ { return {1}; }\n};\ntemplate <class T> struct Sopfr {  // the sum of primes\
    \ dividing n counting multiplicity\n static constexpr T f(uint64_t p, short e)\
    \ { return p * e; }\n static std::vector<T> poly() { return {0, 1}; }\n};\ntemplate\
    \ <class T> struct Sopf {  // the sum of the distinct primes dividing n\n static\
    \ constexpr T f(uint64_t p, short) { return p; }\n static std::vector<T> poly()\
    \ { return {0, 1}; }\n};\n}  // namespace add\n}\n#line 7 \"test/yosupo/sum_of_totient_function.mul_sum.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n using namespace famous_arithmetic_functions;\n\
    \ using T= mul::Totient<Mint>;\n long long N;\n cin >> N;\n ExtendedEratosthenesSieve<Mint>\
    \ ees(N, 1);\n cout << ees.multiplicative_sum(T::f, T::poly()) << '\\n';\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n// O(N^(3/4)/log N)\n#include <iostream>\n#include \"src/Math/ModInt.hpp\"\n\
    #include \"src/NumberTheory/ExtendedEratosthenesSieve.hpp\"\n#include \"src/NumberTheory/famous_arithmetic_functions.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n using namespace famous_arithmetic_functions;\n\
    \ using T= mul::Totient<Mint>;\n long long N;\n cin >> N;\n ExtendedEratosthenesSieve<Mint>\
    \ ees(N, 1);\n cout << ees.multiplicative_sum(T::f, T::poly()) << '\\n';\n return\
    \ 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/NumberTheory/ExtendedEratosthenesSieve.hpp
  - src/NumberTheory/famous_arithmetic_functions.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-26 00:08:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp.html
title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
---
