---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
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
    #include <bits/stdc++.h>\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace modint_internal\
    \ {\nusing namespace std;\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct dyn_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
    \ mod_t>;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\n\
    struct ModIntImpl {\n  static constexpr inline auto modulo() { return D::mod;\
    \ }\n  constexpr D operator-() const { return D() -= (D &)*this; }\n  constexpr\
    \ D &operator/=(const D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const\
    \ D &r) const { return D((D &)*this) += r; }\n  constexpr D operator-(const D\
    \ &r) const { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r)\
    \ const { return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const\
    \ { return D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const\
    \ { return !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D\
    \ ret(1), b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>=\
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    typename D::Int x = 1,\
    \ y = 0, a = ((D *)this)->val(), b = D::mod;\n    for (typename D::Int q = 0,\
    \ z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y * (q = a / b), a = b,\
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  constexpr bool operator<(const\
    \ D &r) const {\n    return ((D *)this)->val() < r.val();\n  }  // for set or\
    \ map\n  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using Int = typename B::Int;\n\
    \  using DUint = conditional_t<is_same_v<typename B::Uint, uint32_t>, u64, u128>;\n\
    \  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr ModInt_Na() = default;\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T\
    \ n) : ModInt_Na(n.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod) {}\n#define ASSIGN(m, p) return x m## = B::mod\
    \ & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na &operator+=(const\
    \ ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const ModInt_Na\
    \ &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Int = int64_t;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    \  template <class T,\n            enable_if_t<is_convertible_v<T, __int128_t>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op##\
    \ = a, x += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const\
    \ mod_t &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const\
    \ mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const\
    \ mod_t &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const\
    \ mod_t &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const\
    \ {\n    u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
    \  }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n   \
    \ return u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n\
    \  static constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r);\
    \ }\n  u64 x = 0;\n  constexpr inline u64 norm() const { return x - (B::mod &\
    \ -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n\
    \  return e ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\n\
    struct StaticB_Na : sta_mint_base {\n protected:\n  using Int = conditional_t\
    \ < MOD < INT_MAX, int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n\
    \  using Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing DynamicModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n\
    \                  ModInt_Na<DynamicB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::DynamicModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_dynamicmodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    template <class mod_t, std::size_t LIM>\nmod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n\
    \  static const auto m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static\
    \ int l = 1;\n  if (l == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m %\
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 3 \"src/Math/prime_count.hpp\"\
    \n/**\n * @title \u7D20\u6570\u30AB\u30A6\u30F3\u30C8\u306A\u3069\n * \u4E57\u6CD5\
    \u7684\u95A2\u6570\u3084\u52A0\u6CD5\u7684\u95A2\u6570\u306E\u548C\u3082\u3042\
    \u308A\n * @category \u6570\u5B66\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n\
    // https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e (\u52A0\u6CD5\u7684\
    \u95A2\u6570)\n\n// BEGIN CUT HERE\n\n// O(d^2\u221AN+dN^(3/4)/log N) d := degre\
    \ of polynomial\ntemplate <class T = __int128_t>\nauto polynomial_prime_sum_table(std::uint64_t\
    \ N, const std::vector<T> &poly) {\n  const int sqrtN = std::sqrt(N), d = poly.size();\n\
    \  std::vector<int> primes;\n  std::vector<T> small(sqrtN + 1, 0), large(sqrtN\
    \ + 1, 0);\n  std::vector<std::vector<T>> s(d, std::vector<T>(sqrtN + 1)),\n \
    \     l(d, std::vector<T>(sqrtN + 1));\n  for (int n = 1, k = 0; n <= sqrtN; n++,\
    \ k = 0)\n    for (T prd = n; k < d; prd *= (n + ++k)) s[k][n] = prd / (k + 1);\n\
    \  for (int n = 1, k = 0; n <= sqrtN; n++, k = 0)\n    for (T prd = N / n; k <\
    \ d; prd *= ((N / n) + ++k)) l[k][n] = prd / (k + 1);\n  if (d > 2) {\n    std::vector<T>\
    \ stir(d, 0);\n    stir[1] = 1;\n    for (int k = 2; k < d; stir[k++] = 1) {\n\
    \      for (int j = k - 1; j; j--) stir[j] = stir[j - 1] + stir[j] * (k - 1);\n\
    \      for (int n = 1; n <= sqrtN; n++)\n        for (int j = 1; j < k; j++)\n\
    \          s[k][n] -= stir[j] * s[j][n], l[k][n] -= stir[j] * l[j][n];\n    }\n\
    \  }\n  for (int k = 0; k < d; k++)\n    for (int n = 1; n <= sqrtN; n++) s[k][n]\
    \ -= 1, l[k][n] -= 1;\n  for (int p = 2, k = 0; p <= sqrtN; p++, k = 0)\n    if\
    \ (s[0][p] != s[0][p - 1]) {\n      primes.emplace_back(p);\n      std::uint64_t\
    \ q = std::uint64_t(p) * p, M = N / p;\n      int t = sqrtN / p, u = std::min<std::uint64_t>(sqrtN,\
    \ N / q);\n      for (T pw = 1; k < d; k++, pw *= p)\n        if (!k || poly[k]\
    \ != T(0)) {\n          T tk = s[k][p - 1];\n          for (int i = 1; i <= t;\
    \ i++) l[k][i] -= (l[k][i * p] - tk) * pw;\n          for (int i = t + 1; i <=\
    \ u; i++)\n            l[k][i] -= (s[k][double(M) / i] - tk) * pw;\n         \
    \ for (int i = sqrtN; (std::uint64_t)i >= q; i--)\n            s[k][i] -= (s[k][double(i)\
    \ / p] - tk) * pw;\n        }\n    }\n  for (int n = 1; n <= sqrtN; n++)\n   \
    \ for (int k = 0; k < d; k++)\n      small[n] += s[k][n] * poly[k], large[n] +=\
    \ l[k][n] * poly[k];\n  return std::make_tuple(primes, small, large);\n}\n\nauto\
    \ prime_count_table(std::uint64_t N) {\n  return polynomial_prime_sum_table<std::uint64_t>(N,\
    \ {1});\n}\n\nstd::uint64_t prime_count(std::uint64_t N) {\n  return std::get<2>(prime_count_table(N))[1];\n\
    }\n\ntemplate <class T>\nT polynomial_prime_sum(std::uint64_t N, const std::vector<T>\
    \ &poly) {\n  return std::get<2>(polynomial_prime_sum_table<T>(N, poly))[1];\n\
    }\n\ntemplate <class T, class F>\nT additive_sum(std::uint64_t N, F f, std::vector<T>\
    \ poly) {\n  const std::uint64_t sqrtN = std::sqrt(N);\n  auto [primes, s, l]\
    \ = polynomial_prime_sum_table<T>(N, poly);\n  T ret = l[1];\n  for (std::uint64_t\
    \ d = 2, nN = N / d, nd; nN; nN = N / (d = nd))\n    ret += (nN > sqrtN ? l[d]\
    \ : s[nN]) * ((nd = N / nN + 1) - d);\n  for (std::uint64_t p : primes)\n    for\
    \ (std::uint64_t pw = p * p, e = 2; pw <= N; e++, pw *= p)\n      ret += (f(p,\
    \ e) - f(p, e - 1)) * (N / pw);\n  return ret;\n}\n\ntemplate <class T = __int128_t,\
    \ class F>\nT multiplicative_sum(std::uint64_t N, const F &f, const std::vector<T>\
    \ &poly) {\n  const std::uint64_t sqrtN = std::sqrt(N);\n  std::vector<int> primes;\n\
    \  std::vector<T> s, l;\n  tie(primes, s, l) = polynomial_prime_sum_table<T>(N,\
    \ poly);\n  for (auto it = primes.rbegin(); it != primes.rend(); it++) {\n   \
    \ std::uint64_t p = *it, M = N / p, q = p * p;\n    int t = sqrtN / p, u = std::min(sqrtN,\
    \ N / q);\n    T tk = s[p - 1];\n    for (auto i = q; i <= sqrtN; i++) s[i] +=\
    \ (s[double(i) / p] - tk) * f(p, 1);\n    for (int i = u; i > t; i--) l[i] +=\
    \ (s[double(M) / i] - tk) * f(p, 1);\n    for (int i = t; i >= 1; i--) l[i] +=\
    \ (l[i * p] - tk) * f(p, 1);\n  }\n  for (auto n = sqrtN; n; n--) s[n] += 1, l[n]\
    \ += 1;\n  auto dfs = [&](auto rc, std::uint64_t n, std::size_t bg, T cf) -> T\
    \ {\n    if (cf == T(0)) return T(0);\n    T ret = cf * (n > sqrtN ? l[double(N)\
    \ / n] : s[n]);\n    for (auto i = bg; i < primes.size(); i++) {\n      std::uint64_t\
    \ p = primes[i], q = p * p, nn = double(n) / q;\n      if (!nn) break;\n     \
    \ for (int e = 2; nn; nn = double(nn) / p, e++)\n        ret += rc(rc, nn, i +\
    \ 1, cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n    }\n    return ret;\n  };\n\
    \  return dfs(dfs, N, 0, 1);\n}\n#line 3 \"src/Math/multiplicative_and_additive.hpp\"\
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
  - src/Math/prime_count.hpp
  - src/Math/multiplicative_and_additive.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  requiredBy: []
  timestamp: '2022-11-08 16:52:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp.html
title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
---
