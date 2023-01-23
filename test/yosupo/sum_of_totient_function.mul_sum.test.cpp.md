---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Math/multiplicative_and_additive.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570"
  - icon: ':question:'
    path: src/Math/prime_count.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8\u306A\u3069"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/yosupo/sum_of_totient_function.mul_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
    #include <iostream>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n\
    #include <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int\
    \ mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for\
    \ (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a / b), a= b, b=\
    \ c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n\
    #line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n\
    #define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n\
    \ CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n  return\
    \ l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { \\\n  if\
    \ (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n static CE\
    \ IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\n\
    \ static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n const u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n const u_t iv, r2;\n static CE u_t inv(u_t n,\
    \ int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE\
    \ IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w)\
    \ * iv) * mod) >> B); }\n};\nstruct MP_Na {\n const u32 mod;\n CE MP_Na(): mod(0){};\n\
    \ CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n const u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: const u8 s;\n const u64 x;\n CE IL u64 quo(u64 n)\
    \ const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n\
    \ - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n const u64 mod;\n\
    \ CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) /\
    \ m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64,\
    \ mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n;\
    \ }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM;\
    \ }\nprivate:\n const u64 x;\n CE IL u128 quo(const u128 &n) const { return (n\
    \ * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_D2B1 {\n const u64 mod;\n CE MP_D2B1(): mod(0), s(0), d(0),\
    \ v(0) {}\n CE MP_D2B1(u64 m): mod(m), s(__builtin_clzll(m)), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    \ const u8 s;\n const u64 d, v;\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t\
    \ x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if\
    \ (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef\
    \ PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 4 \"src/Math/ModInt.hpp\"\
    \nnamespace math_internal {\n#define CE constexpr\nstruct m_b {};\nstruct s_b:\
    \ m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\n\
    template <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\n\
    template <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n\
    };\ntemplate <class Int, class U, class B> struct MInt: public B {\n using Uint=\
    \ U;\n static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n\
    \ CE MInt(const MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n % B::md.mod)))\
    \ {}\n CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name,\
    \ op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  ret.x= op; \\\n  return\
    \ ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x, r.x))\n FUNC(operator-(const\
    \ MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const MInt& r), B::md.mul(x,\
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
    \ MOD>>, MInt<i64, u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt,\
    \ math_internal::is_modint_v, math_internal::is_staticmodint_v;\ntemplate <class\
    \ mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/Math/prime_count.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <tuple>\n#include <cmath>\ntemplate <class T= __int128_t>\
    \ auto polynomial_prime_sum_table(std::uint64_t N, const std::vector<T> &poly)\
    \ {\n const int sqrtN= std::sqrt(N), d= poly.size();\n std::vector<int> primes;\n\
    \ std::vector<T> small(sqrtN + 1, 0), large(sqrtN + 1, 0);\n std::vector<std::vector<T>>\
    \ s(d, std::vector<T>(sqrtN + 1)), l(d, std::vector<T>(sqrtN + 1));\n for (int\
    \ n= 1, k= 0; n <= sqrtN; n++, k= 0)\n  for (T prd= n; k < d; prd*= (n + ++k))\
    \ s[k][n]= prd / (k + 1);\n for (int n= 1, k= 0; n <= sqrtN; n++, k= 0)\n  for\
    \ (T prd= N / n; k < d; prd*= ((N / n) + ++k)) l[k][n]= prd / (k + 1);\n if (d\
    \ > 2) {\n  std::vector<T> stir(d, 0);\n  stir[1]= 1;\n  for (int k= 2; k < d;\
    \ stir[k++]= 1) {\n   for (int j= k - 1; j; j--) stir[j]= stir[j - 1] + stir[j]\
    \ * (k - 1);\n   for (int n= 1; n <= sqrtN; n++)\n    for (int j= 1; j < k; j++)\
    \ s[k][n]-= stir[j] * s[j][n], l[k][n]-= stir[j] * l[j][n];\n  }\n }\n for (int\
    \ k= 0; k < d; k++)\n  for (int n= 1; n <= sqrtN; n++) s[k][n]-= 1, l[k][n]-=\
    \ 1;\n for (int p= 2, k= 0; p <= sqrtN; p++, k= 0)\n  if (s[0][p] != s[0][p -\
    \ 1]) {\n   primes.emplace_back(p);\n   std::uint64_t q= std::uint64_t(p) * p,\
    \ M= N / p;\n   int t= sqrtN / p, u= std::min<std::uint64_t>(sqrtN, N / q);\n\
    \   for (T pw= 1; k < d; k++, pw*= p)\n    if (!k || poly[k] != T(0)) {\n    \
    \ T tk= s[k][p - 1];\n     for (int i= 1; i <= t; i++) l[k][i]-= (l[k][i * p]\
    \ - tk) * pw;\n     for (int i= t + 1; i <= u; i++) l[k][i]-= (s[k][double(M)\
    \ / i] - tk) * pw;\n     for (int i= sqrtN; (std::uint64_t)i >= q; i--) s[k][i]-=\
    \ (s[k][double(i) / p] - tk) * pw;\n    }\n  }\n for (int n= 1; n <= sqrtN; n++)\n\
    \  for (int k= 0; k < d; k++) small[n]+= s[k][n] * poly[k], large[n]+= l[k][n]\
    \ * poly[k];\n return std::make_tuple(primes, small, large);\n}\nauto prime_count_table(std::uint64_t\
    \ N) { return polynomial_prime_sum_table<std::uint64_t>(N, {1}); }\nstd::uint64_t\
    \ prime_count(std::uint64_t N) { return std::get<2>(prime_count_table(N))[1];\
    \ }\ntemplate <class T> T polynomial_prime_sum(std::uint64_t N, const std::vector<T>\
    \ &poly) { return std::get<2>(polynomial_prime_sum_table<T>(N, poly))[1]; }\n\
    template <class T, class F> T additive_sum(std::uint64_t N, F f, std::vector<T>\
    \ poly) {\n const std::uint64_t sqrtN= std::sqrt(N);\n auto [primes, s, l]= polynomial_prime_sum_table<T>(N,\
    \ poly);\n T ret= l[1];\n for (std::uint64_t d= 2, nN= N / d, nd; nN; nN= N /\
    \ (d= nd)) ret+= (nN > sqrtN ? l[d] : s[nN]) * ((nd= N / nN + 1) - d);\n for (std::uint64_t\
    \ p: primes)\n  for (std::uint64_t pw= p * p, e= 2; pw <= N; e++, pw*= p) ret+=\
    \ (f(p, e) - f(p, e - 1)) * (N / pw);\n return ret;\n}\ntemplate <class T= __int128_t,\
    \ class F> T multiplicative_sum(std::uint64_t N, const F &f, const std::vector<T>\
    \ &poly) {\n const std::uint64_t sqrtN= std::sqrt(N);\n std::vector<int> primes;\n\
    \ std::vector<T> s, l;\n tie(primes, s, l)= polynomial_prime_sum_table<T>(N, poly);\n\
    \ for (auto it= primes.rbegin(); it != primes.rend(); it++) {\n  std::uint64_t\
    \ p= *it, M= N / p, q= p * p;\n  int t= sqrtN / p, u= std::min(sqrtN, N / q);\n\
    \  T tk= s[p - 1];\n  for (auto i= q; i <= sqrtN; i++) s[i]+= (s[double(i) / p]\
    \ - tk) * f(p, 1);\n  for (int i= u; i > t; i--) l[i]+= (s[double(M) / i] - tk)\
    \ * f(p, 1);\n  for (int i= t; i >= 1; i--) l[i]+= (l[i * p] - tk) * f(p, 1);\n\
    \ }\n for (auto n= sqrtN; n; n--) s[n]+= 1, l[n]+= 1;\n auto dfs= [&](auto rc,\
    \ std::uint64_t n, std::size_t bg, T cf) -> T {\n  if (cf == T(0)) return T(0);\n\
    \  T ret= cf * (n > sqrtN ? l[double(N) / n] : s[n]);\n  for (auto i= bg; i <\
    \ primes.size(); i++) {\n   std::uint64_t p= primes[i], q= p * p, nn= double(n)\
    \ / q;\n   if (!nn) break;\n   for (int e= 2; nn; nn= double(nn) / p, e++) ret+=\
    \ rc(rc, nn, i + 1, cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n  }\n  return ret;\n\
    \ };\n return dfs(dfs, N, 0, 1);\n}\n#line 3 \"src/Math/multiplicative_and_additive.hpp\"\
    \nnamespace multiplicative_functions {\ntemplate <class T> struct Totient {\n\
    \ static constexpr T f(std::uint64_t p, short e) {\n  T ret= p - 1;\n  while (e--\
    \ > 1) ret*= p;\n  return ret;\n }\n static std::vector<T> poly() { return {-1,\
    \ 1}; }\n};\ntemplate <class T> struct Moebius {\n static constexpr T f(std::uint64_t,\
    \ short e) { return (e == 0) - (e == 1); }\n static std::vector<T> poly() { return\
    \ {-1}; }\n};\ntemplate <class T> struct Liouville {\n static constexpr T f(std::uint64_t,\
    \ short e) { return e & 1 ? -1 : 1; }\n static std::vector<T> poly() { return\
    \ {-1}; }\n};\ntemplate <class T, std::uint64_t k> struct Divisor {\n static constexpr\
    \ T f(std::uint64_t p, short e) {\n  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (std::uint64_t\
    \ kk= k; kk; kk>>= 1, b*= b)\n   if (kk & 1) pk*= b;\n  for (short i= 0; i <=\
    \ e; i++, pkpw*= pk) ret+= pkpw;\n  return ret;\n }\n static std::vector<T> poly()\
    \ {\n  std::vector<T> ret(k + 1, 0);\n  ret[0]+= 1, ret[k]+= 1;\n  return ret;\n\
    \ }\n};\ntemplate <class T> struct Dedekind {\n static constexpr T f(std::uint64_t\
    \ p, short e) {\n  T ret= p + 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n\
    \ }\n static std::vector<T> poly() { return {1, 1}; }\n};\n}  // namespace multiplicative_functions\n\
    namespace additive_functions {\ntemplate <class T> struct BigOmega {  // the total\
    \ number of prime factors of n\n static constexpr T f(std::uint64_t, short e)\
    \ { return e; }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class\
    \ T> struct LittleOmega {  // the total number of different prime factors of n\n\
    \ static constexpr T f(std::uint64_t, short) { return 1; }\n static std::vector<T>\
    \ poly() { return {1}; }\n};\ntemplate <class T> struct Sopfr {  // the sum of\
    \ primes dividing n counting multiplicity\n static constexpr T f(std::uint64_t\
    \ p, short e) { return p * e; }\n static std::vector<T> poly() { return {0, 1};\
    \ }\n};\ntemplate <class T> struct Sopf {  // the sum of the distinct primes dividing\
    \ n\n static constexpr T f(std::uint64_t p, short) { return p; }\n static std::vector<T>\
    \ poly() { return {0, 1}; }\n};\n}  // namespace additive_functions\n#line 6 \"\
    test/yosupo/sum_of_totient_function.mul_sum.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint= ModInt<998244353>;\n\
    \ using namespace multiplicative_functions;\n long long N;\n cin >> N;\n cout\
    \ << multiplicative_sum<Mint>(N, Totient<Mint>::f, Totient<Mint>::poly()) << '\\\
    n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include <iostream>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/prime_count.hpp\"\
    \n#include \"src/Math/multiplicative_and_additive.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint= ModInt<998244353>;\n\
    \ using namespace multiplicative_functions;\n long long N;\n cin >> N;\n cout\
    \ << multiplicative_sum<Mint>(N, Totient<Mint>::f, Totient<Mint>::poly()) << '\\\
    n';\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Math/prime_count.hpp
  - src/Math/multiplicative_and_additive.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 16:52:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp.html
title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
---
