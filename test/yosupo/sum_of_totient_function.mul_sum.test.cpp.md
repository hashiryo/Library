---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Math/multiplicative_and_additive.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/Math/prime_count.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8\u306A\u3069"
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
    #include <bits/stdc++.h>\n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int>\
    \ constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y=\
    \ z - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\n\
    struct m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t>\
    \ CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64 MOD>\
    \ struct SB: s_b {\nprotected:\n static CE mpt md= mpt(MOD);\n};\ntemplate <class\
    \ mpt, int id> struct RB: r_b {\n static inline void set_mod(u64 m) { md= mpt(m);\
    \ }\nprotected:\n static inline mpt md;\n};\ntemplate <class Int, class U, class\
    \ B> struct MInt: public B {\n using Uint= U;\n static CE inline auto mod() {\
    \ return B::md.mod; }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n\
    \ template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T\
    \ v): x(B::md.set(v.val() % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod\
    \ - (-n) % B::md.mod : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
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
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using StaticModInt=\
    \ conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>, MOD>>, conditional_t<MOD&(MOD\
    \ < LLONG_MAX), MInt<i64, u64, SB<MP_Mo, MOD>>, MInt<i64, u64, SB<MP_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id= -1> using RuntimeModInt=\
    \ conditional_t<is_same_v<Int, Montgomery>, MInt<i64, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ i64>, is_same<Int, u64>>, MInt<i64, u64, RB<MP_Na<u64>, id>>, MInt<int, u32,\
    \ RB<MP_Na<u32>, id>>>>;\n#undef CE\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Montgomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LIM> mod_t\
    \ get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m=\
    \ mod_t::mod();\n static mod_t dat[LIM];\n static int l= 1;\n if (l == 1) dat[l++]=\
    \ 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n\
    #line 3 \"src/Math/prime_count.hpp\"\ntemplate <class T= __int128_t> auto polynomial_prime_sum_table(std::uint64_t\
    \ N, const std::vector<T> &poly) {\n const int sqrtN= std::sqrt(N), d= poly.size();\n\
    \ std::vector<int> primes;\n std::vector<T> small(sqrtN + 1, 0), large(sqrtN +\
    \ 1, 0);\n std::vector<std::vector<T>> s(d, std::vector<T>(sqrtN + 1)), l(d, std::vector<T>(sqrtN\
    \ + 1));\n for (int n= 1, k= 0; n <= sqrtN; n++, k= 0)\n  for (T prd= n; k < d;\
    \ prd*= (n + ++k)) s[k][n]= prd / (k + 1);\n for (int n= 1, k= 0; n <= sqrtN;\
    \ n++, k= 0)\n  for (T prd= N / n; k < d; prd*= ((N / n) + ++k)) l[k][n]= prd\
    \ / (k + 1);\n if (d > 2) {\n  std::vector<T> stir(d, 0);\n  stir[1]= 1;\n  for\
    \ (int k= 2; k < d; stir[k++]= 1) {\n   for (int j= k - 1; j; j--) stir[j]= stir[j\
    \ - 1] + stir[j] * (k - 1);\n   for (int n= 1; n <= sqrtN; n++)\n    for (int\
    \ j= 1; j < k; j++) s[k][n]-= stir[j] * s[j][n], l[k][n]-= stir[j] * l[j][n];\n\
    \  }\n }\n for (int k= 0; k < d; k++)\n  for (int n= 1; n <= sqrtN; n++) s[k][n]-=\
    \ 1, l[k][n]-= 1;\n for (int p= 2, k= 0; p <= sqrtN; p++, k= 0)\n  if (s[0][p]\
    \ != s[0][p - 1]) {\n   primes.emplace_back(p);\n   std::uint64_t q= std::uint64_t(p)\
    \ * p, M= N / p;\n   int t= sqrtN / p, u= std::min<std::uint64_t>(sqrtN, N / q);\n\
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
    \n/**\n * @title \u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570\
    \n * @category \u6570\u5B66\n * @see https://en.wikipedia.org/wiki/Arithmetic_function\n\
    \ */\n\n// BEGIN CUT HERE\n\nnamespace multiplicative_functions {\ntemplate <class\
    \ T>\nstruct Totient {\n  static constexpr T f(std::uint64_t p, short e) {\n \
    \   T ret = p - 1;\n    while (e-- > 1) ret *= p;\n    return ret;\n  }\n  static\
    \ std::vector<T> poly() { return {-1, 1}; }\n};\ntemplate <class T>\nstruct Moebius\
    \ {\n  static constexpr T f(std::uint64_t, short e) { return (e == 0) - (e ==\
    \ 1); }\n  static std::vector<T> poly() { return {-1}; }\n};\ntemplate <class\
    \ T>\nstruct Liouville {\n  static constexpr T f(std::uint64_t, short e) { return\
    \ e & 1 ? -1 : 1; }\n  static std::vector<T> poly() { return {-1}; }\n};\ntemplate\
    \ <class T, std::uint64_t k>\nstruct Divisor {\n  static constexpr T f(std::uint64_t\
    \ p, short e) {\n    T ret = 0, pk = 1, pkpw = 1, b = p;\n    for (std::uint64_t\
    \ kk = k; kk; kk >>= 1, b *= b)\n      if (kk & 1) pk *= b;\n    for (short i\
    \ = 0; i <= e; i++, pkpw *= pk) ret += pkpw;\n    return ret;\n  }\n  static std::vector<T>\
    \ poly() {\n    std::vector<T> ret(k + 1, 0);\n    ret[0] += 1, ret[k] += 1;\n\
    \    return ret;\n  }\n};\ntemplate <class T>\nstruct Dedekind {\n  static constexpr\
    \ T f(std::uint64_t p, short e) {\n    T ret = p + 1;\n    while (e-- > 1) ret\
    \ *= p;\n    return ret;\n  }\n  static std::vector<T> poly() { return {1, 1};\
    \ }\n};\n}  // namespace multiplicative_functions\n\nnamespace additive_functions\
    \ {\n// the total number of prime factors of n\ntemplate <class T>\nstruct BigOmega\
    \ {\n  static constexpr T f(std::uint64_t, short e) { return e; }\n  static std::vector<T>\
    \ poly() { return {1}; }\n};\n// the total number of different prime factors of\
    \ n\ntemplate <class T>\nstruct LittleOmega {\n  static constexpr T f(std::uint64_t,\
    \ short) { return 1; }\n  static std::vector<T> poly() { return {1}; }\n};\n//\
    \ the sum of primes dividing n counting multiplicity\ntemplate <class T>\nstruct\
    \ Sopfr {\n  static constexpr T f(std::uint64_t p, short e) { return p * e; }\n\
    \  static std::vector<T> poly() { return {0, 1}; }\n};\n// the sum of the distinct\
    \ primes dividing n\ntemplate <class T>\nstruct Sopf {\n  static constexpr T f(std::uint64_t\
    \ p, short) { return p; }\n  static std::vector<T> poly() { return {0, 1}; }\n\
    };\n}  // namespace additive_functions\n#line 6 \"test/yosupo/sum_of_totient_function.mul_sum.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = StaticModInt<998244353>;\n  using namespace multiplicative_functions;\n\
    \  long long N;\n  cin >> N;\n  cout << multiplicative_sum<Mint>(N, Totient<Mint>::f,\
    \ Totient<Mint>::poly())\n       << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/prime_count.hpp\"\
    \n#include \"src/Math/multiplicative_and_additive.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint\
    \ = StaticModInt<998244353>;\n  using namespace multiplicative_functions;\n  long\
    \ long N;\n  cin >> N;\n  cout << multiplicative_sum<Mint>(N, Totient<Mint>::f,\
    \ Totient<Mint>::poly())\n       << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/prime_count.hpp
  - src/Math/multiplicative_and_additive.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 21:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp.html
title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
---
