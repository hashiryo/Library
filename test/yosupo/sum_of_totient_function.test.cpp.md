---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':x:'
    path: src/Math/dujiao_sieve.hpp
    title: "\u675C\u6559\u7B5B"
  - icon: ':x:'
    path: src/Math/number_theory.hpp
    title: "\u6570\u8AD6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/yosupo/sum_of_totient_function.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\
    \n#ifndef call_from_test\n#line 8 \"src/Math/ModInt.hpp\"\nusing namespace std;\n\
    #endif\n\ntemplate <uint64_t mod, uint64_t prim_root = 0>\nclass ModInt {\n private:\n\
    \  using u128 = __uint128_t;\n  static constexpr uint64_t mul_inv(uint64_t n,\
    \ int e = 6, uint64_t x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x *\
    \ (2 - x * n));\n  }\n  static constexpr uint64_t inv = mul_inv(mod, 6, 1);\n\
    \  static constexpr uint64_t r2 = -u128(mod) % mod;\n  static constexpr uint64_t\
    \ m2 = mod << 1;\n\n public:\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  ModInt() = default;\n  ~ModInt() = default;\n  constexpr ModInt(uint64_t\
    \ n) : x(init(n)){};\n  static constexpr uint64_t modulo() { return mod; }\n \
    \ static constexpr uint64_t init(uint64_t w) { return reduce(u128(w) * r2); }\n\
    \  static constexpr uint64_t reduce(const u128 w) {\n    return uint64_t(w >>\
    \ 64) + mod - ((u128(uint64_t(w) * inv) * mod) >> 64);\n  }\n  static constexpr\
    \ uint64_t pr_rt() { return prim_root; }\n  constexpr ModInt operator-() const\
    \ {\n    ModInt ret;\n    return ret.x = (m2 & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - m2, x += m2\
    \ & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs)\
    \ {\n    return x -= rhs.x, x += m2 & -(x >> 63), *this;\n  }\n  constexpr ModInt\
    \ &operator*=(const ModInt &rhs) {\n    return this->x = reduce(u128(this->x)\
    \ * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n\
    \    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const ModInt\
    \ &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const ModInt\
    \ &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const ModInt\
    \ &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const ModInt\
    \ &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const ModInt\
    \ &rhs) const { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs) const\
    \ { return x != rhs.x; }\n  uint64_t get() const {\n    uint64_t ret = reduce(x)\
    \ - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  void set(uint64_t n)\
    \ const { this->x = n; }\n  constexpr ModInt pow(uint64_t k) const {\n    ModInt\
    \ ret = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *= base)\n\
    \      if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt inverse()\
    \ const { return pow(mod - 2); }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n\
    \  friend std::ostream &operator<<(std::ostream &os, const ModInt &rhs) {\n  \
    \  return os << rhs.get();\n  }\n  uint64_t x;\n};\n#line 1 \"src/Math/dujiao_sieve.hpp\"\
    \n/**\n * @title \u675C\u6559\u7B5B\n * @category \u6570\u5B66\n * @see https://maspypy.com/yukicoder-no-886-direct\n\
    \ * @see https://yukicoder.me/problems/no/1019/editorial\n * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula\n\
    \ * @see https://yukicoder.me/wiki/sum_totient\n * @see https://oi-wiki.org/math/du/\n\
    \ * @see https://blog.bill.moe/multiplicative-function-sieves-notes/\n *  \u30E1\
    \u30E2\u5316\u518D\u5E30\u3067\u5B9F\u88C5(map\u4F7F\u3063\u3066\u308B\u306E\u3067\
    log\u304C\u3064\u304F)\n *  k==1\u306A\u3089O(N^(3/4)) (g,b\u306E\u8A08\u7B97\u91CF\
    \u3092O(1)\u3068\u3057\u3066)\n *  \u524D\u51E6\u7406\u3067N^(2/3)\u307E\u3067\
    \u8A08\u7B97\u3067\u304D\u308B\u306A\u3089O(N^(2/3))\n */\n\n#ifndef call_from_test\n\
    #line 17 \"src/Math/dujiao_sieve.hpp\"\nusing namespace std;\n#endif\n\n// input\
    \ H,W,g,b,k\n// output f(H,W)\n//  s.t. g(x,y) = sum_{d=1,2,...} a(d)f([x/d^k],[y/d^k])\n\
    //       b(d) = a(1)+a(2)+...+a(d)\n\ntemplate <typename T, typename G, typename\
    \ A>\nT dujiao_sieve(int64_t H, int64_t W, const G &g, const A &b,\n         \
    \      map<pair<int64_t, int64_t>, T> &memo, int k = 1) {\n  if (memo.count(make_pair(H,\
    \ W))) return memo[make_pair(H, W)];\n  T ret = g(H, W);\n  int64_t d = 2;\n \
    \ while (true) {\n    int64_t Hd = H / pow(d, k), Wd = W / pow(d, k);\n    if\
    \ (!Hd || !Wd) break;\n    int64_t next_d\n        = min(pow(1. * H / Hd, 1. /\
    \ k), pow(1. * W / Wd, 1. / k)) + 1;\n    T r = dujiao_sieve<T>(Hd, Wd, g, b,\
    \ memo, k);\n    ret -= r * (b(next_d - 1) - b(d - 1));\n    d = next_d;\n  }\n\
    \  return memo[make_pair(H, W)] = ret / b(1);\n}\n#line 1 \"src/Math/number_theory.hpp\"\
    \n/**\n * @title \u6570\u8AD6\n * @category \u6570\u5B66\n *  \u7D04\u6570\u3084\
    \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3084\
    \u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n *  \u3092\u3082\u3068\u306B\u6570\u8AD6\
    \u7684\u95A2\u6570\u3084gcd\u7573\u307F\u8FBC\u307F\u306A\u3069\u3092\u5B9F\u73FE\
    \n *  O(N log log N)\n * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n\
    \ * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n */\n\n// verify\u7528\
    :\n// https://atcoder.jp/contests/agc038/tasks/agc038_c\n\n#ifndef call_from_test\n\
    #line 16 \"src/Math/number_theory.hpp\"\nusing namespace std;\n#endif\n\nnamespace\
    \ number_theory {\nvector<int> primes;\nconst int MAX_N = 1 << 24;\nint mpf[MAX_N];\
    \  // minimum prime factor\nvoid init(int n) {\n  primes.push_back(2);\n  for\
    \ (int i = 2; i <= n; i += 2) mpf[i] = 2;\n  for (long long p = 3; p <= n; p +=\
    \ 2)\n    if (!mpf[p]) {\n      mpf[p] = p;\n      primes.push_back(p);\n    \
    \  for (long long i = p * p; i <= n; i += 2 * p)\n        if (!mpf[i]) mpf[i]\
    \ = p;\n    }\n}\n\nvector<pair<int, int>> prime_factorize(int n) {  // O(log\
    \ n)\n  vector<pair<int, int>> res;\n  while (n > 1) {\n    int p = mpf[n];\n\
    \    int e = 0;\n    while (mpf[n] == p) e++, n /= p;\n    res.push_back(make_pair(p,\
    \ e));\n  }\n  return res;\n}\n\n// f -> g s.t. g(n) = sum_{m|n} f(m)\ntemplate\
    \ <typename T>\nvoid divisor_zeta(vector<T> &f) {\n  int n = f.size();\n  if (!primes.size())\
    \ init(n);\n  for (int p : primes) {\n    if (p > n) break;\n    for (int i =\
    \ 1; p * i < n; i++) f[p * i] += f[i];\n  }\n}\n// f -> h s.t. f(n) = sum_{m|n}\
    \ h(m)\ntemplate <typename T>\nvoid divisor_mobius(vector<T> &f) {\n  int n =\
    \ f.size();\n  if (!primes.size()) init(n);\n  for (int p : primes) {\n    if\
    \ (p > n) break;\n    for (int i = (n - 1) / p; i > 0; i--) f[p * i] -= f[i];\n\
    \  }\n}\n// get table of Mobius function\ntemplate <typename T = int>\nvector<T>\
    \ get_mu(int n) {\n  vector<T> f(n + 1, T(0));\n  f[1] = T(1);\n  divisor_mobius(f);\n\
    \  return f;\n}\n// get table of Euler's totient function\ntemplate <typename\
    \ T = int>\nvector<T> get_phi(int n) {\n  vector<T> f(n + 1);\n  iota(f.begin(),\
    \ f.end(), 0);\n  divisor_mobius(f);\n  return f;\n}\n// get table of number-of-divisors\
    \ function\ntemplate <typename T = int>\nvector<T> get_d(int n) {\n  vector<T>\
    \ f(n + 1, 1);\n  divisor_zeta(f);\n  return f;\n}\n// get table of sum-of-divisors\
    \ function\ntemplate <typename T = int>\nvector<T> get_sigma(int n) {\n  vector<T>\
    \ f(n + 1);\n  iota(f.begin(), f.end(), 0);\n  divisor_zeta(f);\n  return f;\n\
    }\ntemplate <typename T>\nstatic vector<T> lcm_convolution(vector<T> a, vector<T>\
    \ b) {\n  int n = max(a.size(), b.size());\n  a.resize(n);\n  b.resize(n);\n \
    \ divisor_zeta(a);\n  divisor_zeta(b);\n  for (int i = 0; i < n; i++) a[i] *=\
    \ b[i];\n  divisor_mobius(a);\n  return a;\n}\n// f -> g s.t. g(n) = sum_{n|m}\
    \ f(m)\ntemplate <typename T>\nstatic void multiple_zeta(vector<T> &f) {\n  int\
    \ n = f.size();\n  if (!primes.size()) init(n);\n  for (int p : primes) {\n  \
    \  if (p > n) break;\n    for (int i = (n - 1) / p; i > 0; i--) f[i] += f[p *\
    \ i];\n  }\n}\n// f -> h s.t. f(n) = sum_{n|m} h(m)\ntemplate <typename T>\nstatic\
    \ void multiple_mobius(vector<T> &f) {\n  int n = f.size();\n  if (!primes.size())\
    \ init(n);\n  for (int p : primes) {\n    if (p > n) break;\n    for (int i =\
    \ 1; p * i < n; i++) f[i] -= f[p * i];\n  }\n}\ntemplate <typename T>\nstatic\
    \ vector<T> gcd_convolution(vector<T> a, vector<T> b) {\n  int n = max(a.size(),\
    \ b.size());\n  a.resize(n);\n  b.resize(n);\n  multiple_zeta(a);\n  multiple_zeta(b);\n\
    \  for (int i = 0; i < n; i++) a[i] *= b[i];\n  multiple_mobius(a);\n  return\
    \ a;\n}\n}  // namespace number_theory\n#line 10 \"test/yosupo/sum_of_totient_function.test.cpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<998244353>;\n  using namespace number_theory;\n  const\
    \ int M = 1 << (200 / 9);\n  init(M);\n  auto phi = get_phi<Mint>(M);\n  for (int\
    \ i = 2; i < M; i++) phi[i] += phi[i - 1];\n  auto g = [](int64_t N, int64_t dummy)\
    \ {\n    return Mint(N) * Mint(N + 1) / Mint(2);\n  };\n  auto b = [](int64_t\
    \ d) { return Mint(d); };\n  map<pair<int64_t, int64_t>, Mint> memo;\n  for (int\
    \ i = 1; i < M; i++) memo[make_pair(i, i)] = phi[i];\n  int64_t N;\n  cin >> N;\n\
    \  Mint ans = dujiao_sieve<Mint>(N, N, g, b, memo);\n  cout << ans << endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/Math/ModInt.hpp\"\n#include \"src/Math/dujiao_sieve.hpp\"\n#include\
    \ \"src/Math/number_theory.hpp\"\n#undef call_from_test\n\nsigned main() {\n \
    \ cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint = ModInt<998244353>;\n\
    \  using namespace number_theory;\n  const int M = 1 << (200 / 9);\n  init(M);\n\
    \  auto phi = get_phi<Mint>(M);\n  for (int i = 2; i < M; i++) phi[i] += phi[i\
    \ - 1];\n  auto g = [](int64_t N, int64_t dummy) {\n    return Mint(N) * Mint(N\
    \ + 1) / Mint(2);\n  };\n  auto b = [](int64_t d) { return Mint(d); };\n  map<pair<int64_t,\
    \ int64_t>, Mint> memo;\n  for (int i = 1; i < M; i++) memo[make_pair(i, i)] =\
    \ phi[i];\n  int64_t N;\n  cin >> N;\n  Mint ans = dujiao_sieve<Mint>(N, N, g,\
    \ b, memo);\n  cout << ans << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/dujiao_sieve.hpp
  - src/Math/number_theory.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 15:44:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.test.cpp
- /verify/test/yosupo/sum_of_totient_function.test.cpp.html
title: test/yosupo/sum_of_totient_function.test.cpp
---
