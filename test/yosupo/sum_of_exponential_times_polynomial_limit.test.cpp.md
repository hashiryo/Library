---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
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
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/NumberTheory/enumerate_primes.hpp
    title: "\u7D20\u6570\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    - https://min-25.hatenablog.com/entry/2015/04/24/031413
  bundledCode: "#line 1 \"test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"src/Math/FactorialPrecalculation.hpp\"\
    \n#include <cassert>\n#line 2 \"src/Internal/modint_traits.hpp\"\n#include <type_traits>\n\
    namespace math_internal {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class\
    \ mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\n\
    template <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/FactorialPrecalculation.hpp\"\ntemplate <class mod_t>\
    \ class FactorialPrecalculation {\n static_assert(is_modint_v<mod_t>);\n static\
    \ inline std::vector<mod_t> iv, fct, fiv;\npublic:\n static void reset() { iv.clear(),\
    \ fct.clear(), fiv.clear(); }\n static inline mod_t inv(int n) {\n  assert(0 <\
    \ n);\n  if (int k= iv.size(); k <= n) {\n   if (iv.resize(n + 1); !k) iv[1]=\
    \ 1, k= 2;\n   for (int mod= mod_t::mod(), q; k <= n; ++k) q= (mod + k - 1) /\
    \ k, iv[k]= iv[k * q - mod] * q;\n  }\n  return iv[n];\n }\n static inline mod_t\
    \ fact(int n) {\n  assert(0 <= n);\n  if (int k= fct.size(); k <= n) {\n   if\
    \ (fct.resize(n + 1); !k) fct[0]= 1, k= 1;\n   for (; k <= n; ++k) fct[k]= fct[k\
    \ - 1] * k;\n  }\n  return fct[n];\n }\n static inline mod_t finv(int n) {\n \
    \ assert(0 <= n);\n  if (int k= fiv.size(); k <= n) {\n   if (fiv.resize(n + 1);\
    \ !k) fiv[0]= 1, k= 1;\n   for (; k <= n; ++k) fiv[k]= fiv[k - 1] * inv(k);\n\
    \  }\n  return fiv[n];\n }\n static inline mod_t nPr(int n, int r) { return r\
    \ < 0 || n < r ? mod_t(0) : fact(n) * finv(n - r); }\n // [x^r] (1 + x)^n\n static\
    \ inline mod_t nCr(int n, int r) { return r < 0 || n < r ? mod_t(0) : fact(n)\
    \ * finv(n - r) * finv(r); }\n // [x^r] (1 - x)^{-n}\n static inline mod_t nHr(int\
    \ n, int r) { return !r ? mod_t(1) : nCr(n + r - 1, r); }\n};\n#line 4 \"src/Math/mod_inv.hpp\"\
    \ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
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
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 5 \"\
    src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\ntemplate\
    \ <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n\
    };\ntemplate <class Int, class U, class B> struct MInt: public B {\n using Uint=\
    \ U;\n static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n\
    \ template <class T, typename= enable_if_t<is_modint_v<T> && !is_same_v<T, MInt>>>\
    \ CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n CE MInt(__int128_t n):\
    \ x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod - n : n) : n % B::md.mod)))\
    \ {}\n CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name,\
    \ op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  return ret.x= op, ret; \\\
    \n }\n FUNC(operator+(const MInt & r), B::md.plus(x, r.x))\n FUNC(operator-(const\
    \ MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const MInt & r), B::md.mul(x,\
    \ r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n#undef FUNC\n CE\
    \ MInt operator/(const MInt& r) const { return *this * r.inv(); }\n CE MInt& operator+=(const\
    \ MInt& r) { return *this= *this + r; }\n CE MInt& operator-=(const MInt& r) {\
    \ return *this= *this - r; }\n CE MInt& operator*=(const MInt& r) { return *this=\
    \ *this * r; }\n CE MInt& operator/=(const MInt& r) { return *this= *this / r;\
    \ }\n CE bool operator==(const MInt& r) const { return B::md.norm(x) == B::md.norm(r.x);\
    \ }\n CE bool operator!=(const MInt& r) const { return !(*this == r); }\n CE bool\
    \ operator<(const MInt& r) const { return B::md.norm(x) < B::md.norm(r.x); }\n\
    \ CE inline MInt inv() const { return mod_inv<Int>(val(), B::md.mod); }\n CE inline\
    \ Uint val() const { return B::md.get(x); }\n friend ostream& operator<<(ostream&\
    \ os, const MInt& r) { return os << r.val(); }\n friend istream& operator>>(istream&\
    \ is, MInt& r) {\n  i64 v;\n  return is >> v, r= MInt(v), is;\n }\nprivate:\n\
    \ Uint x;\n};\ntemplate <u64 MOD> using ModInt= conditional_t < (MOD < (1 << 30))\
    \ & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32, 31>, MOD>>, conditional_t < (MOD\
    \ < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u\
    \ << 31), MInt<int, u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2,\
    \ MOD>>, MInt<i64, u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n\
    #line 2 \"src/NumberTheory/enumerate_primes.hpp\"\n#include <algorithm>\n#include\
    \ <cstdint>\n#line 4 \"src/Internal/ListRange.hpp\"\n#include <iterator>\n#line\
    \ 6 \"src/Internal/ListRange.hpp\"\n#define _LR(name, IT, CT) \\\n template <class\
    \ T> struct name { \\\n  using Iterator= typename std::vector<T>::IT; \\\n  Iterator\
    \ bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator end() const\
    \ { return ed; } \\\n  size_t size() const { return std::distance(bg, ed); } \\\
    \n  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange, iterator,\
    \ T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\ntemplate <class\
    \ T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int> p;\n size_t size()\
    \ const { return p.size() - 1; }\n ListRange<T> operator[](int i) { return {dat.begin()\
    \ + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T> operator[](int i) const\
    \ { return {dat.cbegin() + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template\
    \ <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
    \ ListRange<T>>, std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>,\
    \ std::ostream &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n\
    \ for (int _= 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n\
    \ return os << ']';\n}\n#line 5 \"src/NumberTheory/enumerate_primes.hpp\"\nnamespace\
    \ nt_internal {\nusing namespace std;\nvector<int> ps, lf;\nvoid sieve(int N)\
    \ {\n static int n= 2;\n if (n > N) return;\n if (lf.resize((N + 1) >> 1); n ==\
    \ 2) ps.push_back(n++);\n int M= (N - 1) / 2;\n for (int j= 1, e= ps.size(); j\
    \ < e; ++j) {\n  int p= ps[j];\n  if (int64_t(p) * p > N) break;\n  for (auto\
    \ k= int64_t(p) * max(n / p / 2 * 2 + 1, p) / 2; k <= M; k+= p) lf[k]+= p * !lf[k];\n\
    \ }\n for (; n <= N; n+= 2)\n  if (!lf[n >> 1]) {\n   ps.push_back(lf[n >> 1]=\
    \ n);\n   for (auto j= int64_t(n) * n / 2; j <= M; j+= n) lf[j]+= n * !lf[j];\n\
    \  }\n}\nConstListRange<int> enumerate_primes() { return {ps.cbegin(), ps.cend()};\
    \ }\nConstListRange<int> enumerate_primes(int N) {\n sieve(N);\n return {ps.cbegin(),\
    \ upper_bound(ps.cbegin(), ps.cend(), N)};\n}\nint least_prime_factor(int n) {\
    \ return n & 1 ? sieve(n), lf[(n >> 1)] : 2; }\n// f(p,e) := f(p^e)\ntemplate\
    \ <class T, class F> vector<T> completely_multiplicative_table(int N, const F\
    \ &f) {\n vector<T> ret(N + 1);\n sieve(N);\n for (int n= 3, i= 1; n <= N; n+=\
    \ 2, ++i) ret[n]= lf[i] == n ? f(n, 1) : ret[lf[i]] * ret[n / lf[i]];\n if (int\
    \ n= 4; 2 <= N)\n  for (T t= ret[2]= f(2, 1); n <= N; n+= 2) ret[n]= t * ret[n\
    \ >> 1];\n return ret[1]= 1, ret;\n}\n}\nusing nt_internal::enumerate_primes,\
    \ nt_internal::least_prime_factor, nt_internal::completely_multiplicative_table;\n\
    // O(N log k / log N + N)\ntemplate <class T> static std::vector<T> pow_table(int\
    \ N, uint64_t k) {\n if (k == 0) return std::vector<T>(N + 1, 1);\n auto f= [k](int\
    \ p, int) {\n  T ret= 1, b= p;\n  for (auto e= k;; b*= b) {\n   if (e & 1) ret*=\
    \ b;\n   if (!(e>>= 1)) return ret;\n  }\n };\n return completely_multiplicative_table<T>(N,\
    \ f);\n}\n#line 9 \"test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n using F= FactorialPrecalculation<Mint>;\n long\
    \ long r, d;\n cin >> r >> d;\n vector<Mint> sum(d + 1), rpow(d + 1), pd= pow_table<Mint>(d\
    \ + 1, d);\n rpow[0]= 1, sum[0]= rpow[0] * pd[0];\n for (int i= 1; i <= d; i++)\
    \ rpow[i]= rpow[i - 1] * r;\n for (int i= 1; i <= d; i++) sum[i]= sum[i - 1] +\
    \ rpow[i] * pd[i];\n Mint ans= 0;\n for (int i= 0; i <= d; i++) {\n  Mint tmp=\
    \ F::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];\n  ans+= (d - i) & 1 ? -tmp : tmp;\n\
    \ }\n ans/= Mint(1 - r).pow(d + 1);\n cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Math/FactorialPrecalculation.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\n#include \"src/NumberTheory/enumerate_primes.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n using F= FactorialPrecalculation<Mint>;\n long\
    \ long r, d;\n cin >> r >> d;\n vector<Mint> sum(d + 1), rpow(d + 1), pd= pow_table<Mint>(d\
    \ + 1, d);\n rpow[0]= 1, sum[0]= rpow[0] * pd[0];\n for (int i= 1; i <= d; i++)\
    \ rpow[i]= rpow[i - 1] * r;\n for (int i= 1; i <= d; i++) sum[i]= sum[i - 1] +\
    \ rpow[i] * pd[i];\n Mint ans= 0;\n for (int i= 0; i <= d; i++) {\n  Mint tmp=\
    \ F::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];\n  ans+= (d - i) & 1 ? -tmp : tmp;\n\
    \ }\n ans/= Mint(1 - r).pow(d + 1);\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/FactorialPrecalculation.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/NumberTheory/enumerate_primes.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  requiredBy: []
  timestamp: '2024-02-19 15:31:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
---
