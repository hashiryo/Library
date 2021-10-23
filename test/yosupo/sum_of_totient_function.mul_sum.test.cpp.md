---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':x:'
    path: src/Math/multiplicative_and_additive.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u3068\u52A0\u6CD5\u7684\u95A2\u6570"
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
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\nnamespace internal {\n\
    template <std::uint64_t mod, std::uint64_t prim_root, class ModInt>\nclass ModIntImpl\
    \ {\n  static constexpr std::uint64_t modulo() { return mod; }\n  static constexpr\
    \ std::uint64_t pr_rt() { return prim_root; }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  constexpr ModInt pow(std::uint64_t\
    \ k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt base = *this; k; k\
    \ >>= 1, base *= base)\n      if (k & 1) ret *= base;\n    return ret;\n  }\n\
    \  constexpr ModInt inverse() const { return pow(mod - 2); }\n  constexpr ModInt\
    \ sqrt() const {\n    if (*this == ModInt(0) || mod == 2) return *this;\n    if\
    \ (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt ONE\
    \ = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b +=\
    \ ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt,\
    \ ModInt> v) {\n      ModInt a = (u.first * v.first + u.second * v.second * w);\n\
    \      ModInt b = (u.first * v.second + u.second * v.first);\n      return std::make_pair(a,\
    \ b);\n    };\n    std::uint64_t e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE,\
    \ ModInt(0));\n    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs,\
    \ bs))\n      if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 <\
    \ mod ? ret.first : -ret.first;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace\
    \ internal\ntemplate <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\
    \ : internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n  using u64\
    \ = std::uint64_t;\n  using u128 = __uint128_t;\n  static constexpr u64 mul_inv(u64\
    \ n, int e = 6, u64 x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2\
    \ - x * n));\n  }\n  static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -u128(mod)\
    \ % mod;\n  static constexpr u64 init(u64 w) { return reduce(u128(w) * r2); }\n\
    \  static constexpr u64 reduce(const u128 w) {\n    return u64(w >> 64) + mod\
    \ - ((u128(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n public:\n  constexpr\
    \ ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n < 0 ? mod\
    \ - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static constexpr u64 norm(u64\
    \ w) { return w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const\
    \ {\n    ModInt ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n\
    \  }\n  constexpr ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x\
    \ - (mod << 1), x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt\
    \ &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x\
    \ >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n \
    \   return this->x = reduce(u128(this->x) * rhs.x), *this;\n  }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return norm(x) != norm(rhs.x); }\n  u64 val() const {\n\
    \    u64 ret = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n\
    \  friend std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return\
    \ is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n};\ntemplate <std::uint64_t prim_root>\n\
    class ModInt<2, prim_root>\n    : internal::ModIntImpl<2, prim_root, ModInt<2,\
    \ prim_root>> {\n  bool x;\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(n & 1) {}\n  ~ModInt() = default;\n  constexpr ModInt\
    \ operator-() const { return *this; }\n  constexpr ModInt &operator+=(const ModInt\
    \ &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt &operator-=(const ModInt\
    \ &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt &operator*=(const ModInt\
    \ &rhs) { return x &= rhs.x, *this; }\n  bool operator==(const ModInt &rhs) const\
    \ { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs) const { return\
    \ x != rhs.x; }\n  std::uint64_t val() const { return x; }\n  friend std::istream\
    \ &operator>>(std::istream &is, ModInt &rhs) {\n    return is >> rhs.x, is;\n\
    \  }\n};\n#line 3 \"src/Math/prime_count.hpp\"\n/**\n * @title \u7D20\u6570\u30AB\
    \u30A6\u30F3\u30C8\u306A\u3069\n * \u4E57\u6CD5\u7684\u95A2\u6570\u3084\u52A0\u6CD5\
    \u7684\u95A2\u6570\u306E\u548C\u3082\u3042\u308A\n * @category \u6570\u5B66\n\
    \ */\n\n// verify\u7528:\n// https://atcoder.jp/contests/abc172/tasks/abc172_d\n\
    // https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n// https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e\
    \ (\u52A0\u6CD5\u7684\u95A2\u6570)\n\n// BEGIN CUT HERE\n\n// O(d^2\u221AN+dN^(3/4)/log\
    \ N) d := degre of polynomial\ntemplate <class T = __int128_t>\nauto polynomial_prime_sum_table(std::uint64_t\
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
    \n/**\n * @title \u4E57\u6CD5\u7684\u95A2\u6570\u3068\u52A0\u6CD5\u7684\u95A2\u6570\
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
    \  using Mint = ModInt<998244353>;\n  using namespace multiplicative_functions;\n\
    \  long long N;\n  cin >> N;\n  cout << multiplicative_sum<Mint>(N, Totient<Mint>::f,\
    \ Totient<Mint>::poly())\n       << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/prime_count.hpp\"\
    \n#include \"src/Math/multiplicative_and_additive.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint\
    \ = ModInt<998244353>;\n  using namespace multiplicative_functions;\n  long long\
    \ N;\n  cin >> N;\n  cout << multiplicative_sum<Mint>(N, Totient<Mint>::f, Totient<Mint>::poly())\n\
    \       << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/prime_count.hpp
  - src/Math/multiplicative_and_additive.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  requiredBy: []
  timestamp: '2021-10-23 18:23:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp
- /verify/test/yosupo/sum_of_totient_function.mul_sum.test.cpp.html
title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
---
