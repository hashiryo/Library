---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/Sieve.hpp
    title: "\u7BE9\u306A\u3069"
  - icon: ':question:'
    path: src/Math/lagrange_interpolation.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    - https://min-25.hatenablog.com/entry/2015/04/24/031413
  bundledCode: "#line 1 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Math/Combination.hpp\"\n/**\n * @title \u4E8C\
    \u9805\u4FC2\u6570\u306A\u3069\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT\
    \ HERE\n\ntemplate <class mint, std::size_t LIM = (1 << 24)>\nstruct Combination\
    \ {\n private:\n  static inline mint _fact[LIM] = {1}, _finv[LIM] = {1};\n  static\
    \ inline int lim = 1;\n  static inline void set(int sz) {\n    if (lim > sz) return;\n\
    \    for (int i = lim; i <= sz; i++) _fact[i] = _fact[i - 1] * i;\n    _finv[sz]\
    \ = mint(1) / _fact[sz];\n    for (int i = sz; i >= lim; i--) _finv[i - 1] = _finv[i]\
    \ * i;\n    lim = sz + 1;\n  }\n\n public:\n  static inline mint fact(int n) {\
    \ return set(n), n < 0 ? mint(0) : _fact[n]; }\n  static inline mint finv(int\
    \ n) { return set(n), n < 0 ? mint(0) : _finv[n]; }\n  static mint nPr(int n,\
    \ int r) { return fact(n) * finv(n - r); }\n  static mint nCr(int n, int r) {\
    \ return nPr(n, r) * finv(r); }\n  static mint nHr(int n, int r) { return !r ?\
    \ mint(1) : nCr(n + r - 1, r); }\n};\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n *\
    \ @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ modint_internal {\nusing namespace std;\nstruct modint_base {};\nstruct sta_mint_base\
    \ : modint_base {};\nstruct dyn_mint_base : modint_base {};\ntemplate <class mod_t>\n\
    constexpr bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class\
    \ mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\n\
    template <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
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
    \ 1)) return ret;\n  }\n  constexpr D inv() const { return pow(D::mod - 2); }\n\
    \  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, u64>, u128, u64>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_integral_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod)\
    \ : n % B::mod) {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n#define ASSIGN(m,\
    \ p) return x m## = B::mod & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na\
    \ &operator+=(const ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const\
    \ ModInt_Na &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Uint = u64;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_integral_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    #define ASGN(op, a) return x op## = a, x += (B::mod << 1) & -(x >> 63), *this\n\
    \  constexpr mod_t &operator+=(const mod_t &r) { ASGN(+, r.x - (B::mod << 1));\
    \ }\n  constexpr mod_t &operator-=(const mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n\
    \  constexpr mod_t &operator*=(const mod_t &r) { return x = mul(x, r.x), *this;\
    \ }\n  constexpr bool operator==(const mod_t &r) const { return norm() == r.norm();\
    \ }\n  constexpr u64 val() const {\n    u64 ret = reduce(x) - B::mod;\n    return\
    \ ret + (B::mod & -(ret >> 63));\n  }\n\n private:\n  static constexpr inline\
    \ u64 reduce(const u128 &w) {\n    return u64(w >> 64) + B::mod - ((u128(u64(w)\
    \ * B::iv) * B::mod) >> 64);\n  }\n  static constexpr inline u64 mul(u64 l, u64\
    \ r) { return reduce(u128(l) * r); }\n  u64 x = 0;\n  constexpr inline u64 norm()\
    \ const { return x - (B::mod & -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64\
    \ n, int e = 6, u64 x = 1) {\n  return e ? mul_inv(n, e - 1, x * (2 - x * n))\
    \ : x;\n}\ntemplate <u64 MOD>\nstruct StaticB_Na : sta_mint_base {\n protected:\n\
    \  using Uint = conditional_t < MOD<UINT_MAX, uint32_t, u64>;\n  static constexpr\
    \ Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct StaticB_Mon : sta_mint_base\
    \ {\n protected:\n  static_assert(MOD & 1);\n  static constexpr u64 mod = MOD,\
    \ iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate <class Int, int id =\
    \ -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<Int>);\n\
    \  static inline void set_mod(Int m) { mod = m; }\n\n protected:\n  using Uint\
    \ = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate <int id>\n\
    struct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64 m) {\n\
    \    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n protected:\n\
    \  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing StaticModInt\
    \ =\n    conditional_t<mod &(mod >= UINT_MAX), ModInt_Mon<StaticB_Mon<mod>>,\n\
    \                  ModInt_Na<StaticB_Na<mod>>>;\nstruct Montgomery {};\ntemplate\
    \ <class Int, int id = -1>\nusing DynamicModInt =\n    conditional_t<is_same_v<Int,\
    \ Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n                  ModInt_Na<DynamicB_Na<Int,\
    \ id>>>;\n}  // namespace modint_internal\nusing modint_internal::DynamicModInt,\
    \ modint_internal::StaticModInt,\n    modint_internal::Montgomery, modint_internal::is_dynamicmodint_v,\n\
    \    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n#line\
    \ 3 \"src/Math/Sieve.hpp\"\n/**\n * @title \u7BE9\u306A\u3069\n * @category \u6570\
    \u5B66\n * \u7DDA\u5F62\u7BE9\u306B\u3088\u308B\u7D20\u6570\u5217\u6319\u306E\u524D\
    \u51E6\u7406\n * \u4E57\u6CD5\u7684\u95A2\u6570 \u30C6\u30FC\u30D6\u30EB\u5217\
    \u6319 \u3084 gcd\u7573\u307F\u8FBC\u307F\u306A\u3069\n * @see https://37zigen.com/linear-sieve/\n\
    \ * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n\
    \ * @see\n * https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <int LIM = 1 << 24>\nclass Sieve {\n public:\n\
    \  static inline int ps[LIM >> 4], lpf[LIM], lpfe[LIM], lpfpw[LIM], psz = 0;\n\
    \  static inline void sieve(int N) {  // O(N)\n    static int n = 2;\n    for\
    \ (; n <= N; n++) {\n      if (!lpf[n]) lpf[n] = ps[psz++] = n;\n      for (int\
    \ j = 0, e = std::min(lpf[n], N / n); j < psz && ps[j] <= e; j++)\n        lpf[ps[j]\
    \ * n] = ps[j];\n    }\n  }\n  static inline void set_lpfe(int N) {  // O(N)\n\
    \    static int n = 2;\n    if (N < n) return;\n    sieve(N), std::fill(lpfe +\
    \ n, lpfe + N + 1, 1);\n    for (std::copy(lpf + n, lpf + N + 1, lpfpw + n); n\
    \ <= N; n++)\n      if (int m = n / lpf[n]; lpf[n] == lpf[m])\n        lpfe[n]\
    \ += lpfe[m], lpfpw[n] *= lpfpw[m];\n  }\n\n public:\n  static int least_prime_factor(int\
    \ n) { return sieve(n), lpf[n]; }\n  // O(log n)\n  static std::map<int, short>\
    \ factorize(int n) {\n    std::map<int, short> ret;\n    for (set_lpfe(n); n >\
    \ 1;) ret[lpf[n]] = lpfe[n], n /= lpfpw[n];\n    return ret;\n  }\n  // O(log\
    \ n)\n  static std::vector<int> divisors(int n) {\n    std::vector<int> ret =\
    \ {1};\n    for (auto [p, e] : factorize(n))\n      for (std::size_t sz = ret.size(),\
    \ pw = p; e--; pw *= p)\n        for (int i = sz - 1; i >= 0; i--) ret.push_back(ret[i]\
    \ * pw);\n    return std::sort(ret.begin(), ret.end()), ret;\n  }\n  // O(N)\n\
    \  static std::vector<int> get_primes(int N) {\n    return sieve(N), std::vector<int>(ps,\
    \ std::upper_bound(ps, ps + psz, N));\n  }\n  template <class T, class F>\n  static\
    \ inline std::vector<T> completely_multiplicative_table(int N,\n             \
    \                                                  const F &f) {\n    std::vector<T>\
    \ ret(N + 1);\n    sieve(N);\n    for (int i = 2; i <= N; i++)\n      ret[i] =\
    \ lpf[i] == i ? f(i, 1) : ret[lpf[i]] * ret[i / lpf[i]];\n    return ret[1] =\
    \ 1, ret;\n  }\n  template <class T, class F>\n  static inline std::vector<T>\
    \ multiplicative_table(int N, const F &f) {\n    std::vector<T> ret(N + 1);\n\
    \    set_lpfe(N);\n    for (int i = 2; i <= N; i++)\n      ret[i] = lpfpw[i] ==\
    \ i ? f(lpf[i], lpfe[i])\n                             : ret[lpfpw[i]] * ret[i\
    \ / lpfpw[i]];\n    return ret[1] = 1, ret;\n  }\n  // O(N log k / log N + N)\n\
    \  template <class T>\n  static std::vector<T> pow_table(int N, std::uint64_t\
    \ k) {\n    if (k == 0) return std::vector<T>(N + 1, 1);\n    auto f = [k](int\
    \ p, short) {\n      T ret = 1, b = p;\n      for (auto e = k;; b *= b)\n    \
    \    if (e & 1 ? ret *= b, !(e >>= 1) : !(e >>= 1)) return ret;\n    };\n    return\
    \ completely_multiplicative_table<T>(N, f);\n  }\n  // O(N log MOD / log N + N)\n\
    \  template <class T>\n  static std::vector<T> inv_table(int N) {\n    return\
    \ completely_multiplicative_table<T>(\n        N, [](int p, short) { return T(1)\
    \ / p; });\n  }\n  // naive , O(N log N)\n  template <class T>\n  static std::vector<T>\
    \ dirichlet_conv(const std::vector<T> &a,\n                                  \
    \     const std::vector<T> &b) {\n    std::size_t N = std::max(a.size(), b.size())\
    \ - 1, i, j;\n    std::vector<T> ret(N + 1, 0);\n    for (i = a.size(); --i;)\n\
    \      for (j = std::min(b.size() - 1, N / i); j; j--) ret[i * j] += a[i] * b[j];\n\
    \    return ret;\n  }\n  // a is multiplicative, O(N log log N)\n  template <class\
    \ T, class F>\n  static std::vector<T> dirichlet_conv(const F &a, std::vector<T>\
    \ b) {\n    std::size_t N = b.size() - 1, j = 0;\n    for (sieve(N), b.resize(N\
    \ + 1, 0); j < psz && ps[j] <= N; j++)\n      for (int i = N / ps[j], n, m, e;\
    \ i; i--)\n        for (b[n = ps[j] * i] += a(ps[j], e = 1) * b[m = i]; m % ps[j]\
    \ == 0;)\n          b[n] += a(ps[j], ++e) * b[m /= ps[j]];\n    return b;\n  }\n\
    \  // both a and b are multiplicative, O(N)\n  template <class T, class F1, class\
    \ F2>\n  static std::vector<T> dirichlet_conv(const F1 &a, const F2 &b,\n    \
    \                                   std::size_t N) {\n    auto f = [&a, &b](int\
    \ p, short e) {\n      T ret = a(p, e) + b(p, e);\n      for (int k = e; --k;)\
    \ ret += a(p, e - k) * b(p, k);\n      return ret;\n    };\n    return multiplicative_table<T>(N,\
    \ f);\n  }\n  // f -> g s.t. g(n) = sum_{m|n} f(m), O(N log log N)\n  template\
    \ <typename T>\n  static void divisor_zeta(std::vector<T> &f) {\n    std::size_t\
    \ N = f.size(), i, j;\n    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n\
    \      for (j = 1; ps[i] * j < N; j++) f[ps[i] * j] += f[j];\n  }\n  // f -> h\
    \ s.t. f(n) = sum_{m|n} h(m), O(N log log N)\n  template <typename T>\n  static\
    \ void divisor_mobius(std::vector<T> &f) {\n    std::size_t N = f.size(), i, j;\n\
    \    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n      for (j = (N - 1)\
    \ / ps[i]; j; j--) f[ps[i] * j] -= f[j];\n  }\n  // O(N log log N)\n  template\
    \ <typename T>\n  static std::vector<T> lcm_conv(std::vector<T> a, std::vector<T>\
    \ b) {\n    std::size_t N = std::max(a.size(), b.size());\n    a.resize(N), b.resize(N),\
    \ divisor_zeta(a), divisor_zeta(b);\n    for (; N--;) a[N] *= b[N];\n    return\
    \ divisor_mobius(a), a;\n  }\n  // both a and b are multiplicative, O(N)\n  template\
    \ <class T, class F1, class F2>\n  static std::vector<T> lcm_conv(const F1 &a,\
    \ const F2 &b, std::size_t N) {\n    auto f = [&a, &b](int p, short e) {\n   \
    \   T suma = 1, sumb = 1;\n      for (short k = 1; k < e; k++) suma += a(p, k),\
    \ sumb += b(p, k);\n      return (a(p, e) + suma) * (b(p, e) + sumb) - suma *\
    \ sumb;\n    };\n    return multiplicative_table<T>(N, f);\n  }\n  // f -> g s.t.\
    \ g(n) = sum_{n|m} f(m), O(N log log N)\n  template <typename T>\n  static void\
    \ multiple_zeta(std::vector<T> &f) {\n    std::size_t N = f.size(), i, j;\n  \
    \  for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n      for (j = (N - 1) /\
    \ ps[i]; j; j--) f[j] += f[ps[i] * j];\n  }\n  // f -> h s.t. f(n) = sum_{n|m}\
    \ h(m), O(N log log N)\n  template <typename T>\n  static void multiple_mobius(std::vector<T>\
    \ &f) {\n    std::size_t N = f.size(), i, j;\n    for (sieve(N), i = 0; i < psz\
    \ && ps[i] < N; i++)\n      for (j = 1; ps[i] * j < N; j++) f[j] -= f[ps[i] *\
    \ j];\n  }\n  // O(N log log N)\n  template <typename T>\n  static std::vector<T>\
    \ gcd_conv(std::vector<T> a, std::vector<T> b) {\n    std::size_t N = std::max(a.size(),\
    \ b.size());\n    a.resize(N), b.resize(N), multiple_zeta(a), multiple_zeta(b);\n\
    \    for (; N--;) a[N] *= b[N];\n    return multiple_mobius(a), a;\n  }\n};\n\
    #line 3 \"src/Math/lagrange_interpolation.hpp\"\n/**\n * @title \u30E9\u30B0\u30E9\
    \u30F3\u30B8\u30E5\u88DC\u9593\n * @category \u6570\u5B66\n *  x=0,1,..,N-1\u3068\
    y=f(0),f(1),...,f(N-1)\u304C\u4E0E\u3048\u3089\u308C\u305F\u3068\u304D\u306Ef(t)\u3092\
    \u8A08\u7B97\n *  O(N)\n */\n\n// verify\u7528:\n// http://codeforces.com/contest/622/problem/F\n\
    // https://atcoder.jp/contests/arc033/tasks/arc033_4\n\n// BEGIN CUT HERE\n\n\
    template <typename K>\nK lagrange_interpolation(std::vector<K> &y, K t) {\n  int\
    \ n = y.size() - 1;\n  std::vector<K> pro(n + 1, 1), orp(n + 1, 1);\n  for (int\
    \ i = 0; i < n; i++) pro[i + 1] = pro[i] * (t - K(i));\n  for (int i = n; i >\
    \ 0; i--) orp[i - 1] = orp[i] * (t - K(i));\n  K fact = K(1);\n  for (int i =\
    \ 1; i <= n; i++) fact *= K(i);\n  std::vector<K> finv(n + 1, 1);\n  finv[n] =\
    \ K(1) / fact;\n  for (int i = n; i >= 1; i--) finv[i - 1] = finv[i] * K(i);\n\
    \  K res(0);\n  for (int i = 0; i <= n; i++) {\n    K tmp = y[i] * pro[i] * orp[i]\
    \ * finv[i] * finv[n - i];\n    res += (n - i) & 1 ? -tmp : tmp;\n  }\n  return\
    \ res;\n}\n#line 10 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using C = Combination<Mint>;\n  long\
    \ long r, d, n;\n  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n\
    \    return 0;\n  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = Sieve<>::pow_table<Mint>(d\
    \ + 2, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d\
    \ + 1; i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i]\
    \ = sum[i - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = lagrange_interpolation<Mint>(sum,\
    \ n);\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(1) / r, rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n     \
    \ y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n    ans\
    \ += Mint(r).pow(n) * lagrange_interpolation<Mint>(y, n);\n  }\n  cout << ans\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/Combination.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/Math/Sieve.hpp\"\n#include \"src/Math/lagrange_interpolation.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using C = Combination<Mint>;\n  long\
    \ long r, d, n;\n  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n\
    \    return 0;\n  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = Sieve<>::pow_table<Mint>(d\
    \ + 2, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d\
    \ + 1; i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i]\
    \ = sum[i - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = lagrange_interpolation<Mint>(sum,\
    \ n);\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(1) / r, rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n     \
    \ y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n    ans\
    \ += Mint(r).pow(n) * lagrange_interpolation<Mint>(y, n);\n  }\n  cout << ans\
    \ << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  - src/Math/Sieve.hpp
  - src/Math/lagrange_interpolation.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  requiredBy: []
  timestamp: '2022-09-21 15:23:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
---
