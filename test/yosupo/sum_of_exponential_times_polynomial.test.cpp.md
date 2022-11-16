---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':x:'
    path: src/FFT/sample_points_shift.hpp
    title: "\u591A\u9805\u5F0F\u306E\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8"
  - icon: ':question:'
    path: src/Math/Combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069 (\u968E\u4E57\u524D\u8A08\u7B97)\
      \ ($\\mathbb{F}_p$)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/Sieve.hpp
    title: "\u7BE9\u306A\u3069"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
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
    \u9805\u4FC2\u6570\u306A\u3069 (\u968E\u4E57\u524D\u8A08\u7B97) ($\\mathbb{F}_p$)\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\ntemplate <class mint,\
    \ std::size_t LIM = (1 << 24)>\nclass Combination {\n  static inline mint _fact[LIM],\
    \ _finv[LIM];\n  static inline int lim = 0;\n  static inline void set(int sz)\
    \ {\n    if (lim > sz) return;\n    if (lim == 0) _fact[0] = 1, _finv[0] = 1,\
    \ lim = 1;\n    for (int i = lim; i <= sz; i++) _fact[i] = _fact[i - 1] * i;\n\
    \    _finv[sz] = mint(1) / _fact[sz];\n    for (int i = sz; i >= lim; i--) _finv[i\
    \ - 1] = _finv[i] * i;\n    lim = sz + 1;\n  }\n\n public:\n  static inline mint\
    \ fact(int n) { return set(n), n < 0 ? mint(0) : _fact[n]; }\n  static inline\
    \ mint finv(int n) { return set(n), n < 0 ? mint(0) : _finv[n]; }\n  static mint\
    \ nPr(int n, int r) { return fact(n) * finv(n - r); }\n  static mint nCr(int n,\
    \ int r) { return nPr(n, r) * finv(r); }\n  static mint nHr(int n, int r) { return\
    \ !r ? mint(1) : nCr(n + r - 1, r); }\n};\n#line 3 \"src/Math/mod_inv.hpp\"\n\
    /**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0,\
    \ b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y =\
    \ z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ?\
    \ mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n\
    \ * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category \u6570\
    \u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\n\
    namespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\nclass MIntPro_Montg {\n  u64 mod,\
    \ iv, r2;\n  constexpr u64 inv(u64 n, int e = 6, u64 x = 1) {\n    return e ?\
    \ inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n  constexpr inline u64 reduce(const\
    \ u128 &w) const {\n    return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod)\
    \ >> 64);\n  }\n\n public:\n  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0)\
    \ {}\n  constexpr MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod)\
    \ {}\n  constexpr inline u64 mul(u64 l, u64 r) const { return reduce(u128(l) *\
    \ r); }\n#define BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n\
    \  constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n\
    \  constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n\
    \  constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline\
    \ u64 get(u64 n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n -\
    \ (mod & -(n >= mod)); }\n  constexpr u64 modulo() const { return mod; }\n};\n\
    template <class Uint>\nclass MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\n  Uint mod;\n\n public:\n  constexpr MIntPro_Na() : mod(0){};\n\
    \  constexpr MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint\
    \ l, Uint r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l\
    \ m## = mod & -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint\
    \ r) const { BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const\
    \ { BOP(+, -); }\n#undef BOP\n  constexpr inline Uint set(Uint n) const { return\
    \ n % mod; }\n  static constexpr inline Uint get(Uint n) { return n; }\n  static\
    \ constexpr inline Uint norm(Uint n) { return n; }\n  constexpr Uint modulo()\
    \ const { return mod; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n\
    \ * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class Uint, class B>\nstruct ModInt : public B\
    \ {\n  static constexpr inline auto modulo() { return B::md.modulo(); }\n  constexpr\
    \ ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x) {}\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt(T\
    \ v) : ModInt(v.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt(T n)\n      : x(B::md.set(n\
    \ < 0 ? modulo() - ((-n) % modulo()) : n)) {}\n  constexpr ModInt operator-()\
    \ const { return ModInt() - *this; }\n#define FUNC(name, op)          \\\n  constexpr\
    \ ModInt name const { \\\n    ModInt ret;                 \\\n    return ret.x\
    \ = op, ret;     \\\n  }\n  FUNC(operator+(const ModInt &r), B::md.plus(x, r.x))\n\
    \  FUNC(operator-(const ModInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const\
    \ ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k,\
    \ B::md))\n#undef FUNC\n  constexpr ModInt operator/(const ModInt &r) const {\
    \ return *this * r.inv(); }\n  constexpr ModInt &operator+=(const ModInt &r) {\
    \ return *this = *this + r; }\n  constexpr ModInt &operator-=(const ModInt &r)\
    \ { return *this = *this - r; }\n  constexpr ModInt &operator*=(const ModInt &r)\
    \ { return *this = *this * r; }\n  constexpr ModInt &operator/=(const ModInt &r)\
    \ { return *this = *this / r; }\n  constexpr bool operator==(const ModInt &r)\
    \ const {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr bool\
    \ operator!=(const ModInt &r) const { return !(*this == r); }\n  constexpr bool\
    \ operator<(const ModInt &r) const {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
    \  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(), modulo());\
    \ }\n  constexpr inline Uint val() const { return B::md.get(x); }\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &r) {\n    return os << r.val();\n  }\n\
    \  friend istream &operator>>(istream &is, ModInt &r) {\n    long long v;\n  \
    \  return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX, ModInt<int,\
    \ u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD &(MOD < LLONG_MAX),\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Montg, MOD>>,\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>, MOD>>>>;\n\
    class Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt =\
    \ conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\n#line 3 \"src/Math/Sieve.hpp\"\n/**\n * @title\
    \ \u7BE9\u306A\u3069\n * @category \u6570\u5B66\n * \u7DDA\u5F62\u7BE9\u306B\u3088\
    \u308B\u7D20\u6570\u5217\u6319\u306E\u524D\u51E6\u7406\n * \u4E57\u6CD5\u7684\u95A2\
    \u6570 \u30C6\u30FC\u30D6\u30EB\u5217\u6319 \u3084 gcd\u7573\u307F\u8FBC\u307F\
    \u306A\u3069\n * @see https://37zigen.com/linear-sieve/\n * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n\
    \ * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n * @see\n * https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <int LIM = 1 << 24>\nclass Sieve {\n  static\
    \ inline int ps[LIM >> 4], lpf[LIM >> 1], lpfpw[LIM >> 1], psz = 0;\n  static\
    \ inline std::int8_t lpfe[LIM >> 1];\n  static inline void sieve(int N) {  //\
    \ O(N)\n    static int n = 2, i = 1;\n    if (n == 2) ps[psz++] = 2, n++;\n  \
    \  for (; n <= N; n += 2, i++) {\n      if (!lpf[i]) lpf[i] = ps[psz++] = n;\n\
    \      for (int j = 1, e = std::min(lpf[i], N / n); j < psz && ps[j] <= e; j++)\n\
    \        lpf[(ps[j] * n) >> 1] = ps[j];\n    }\n  }\n  static inline void set_lpfe(int\
    \ N) {  // O(N)\n    static int n = 3, i = 1;\n    if (N < n) return;\n    sieve(N),\
    \ std::copy(lpf + i, lpf + (N >> 1) + 1, lpfpw + i);\n    for (std::fill(lpfe\
    \ + i, lpfe + (N >> 1) + 1, 1); n <= N; n += 2, i++)\n      if (int j = (n / lpf[i])\
    \ >> 1; lpf[i] == lpf[j])\n        lpfe[i] += lpfe[j], lpfpw[i] *= lpfpw[j];\n\
    \  }\n\n public:\n  static int least_prime_factor(int n) { return sieve(n), lpf[n];\
    \ }\n  // O(log n)\n  static std::map<int, short> factorize(int n) {\n    std::map<int,\
    \ short> ret;\n    if (int t; !(n & 1)) ret[2] = t = __builtin_ctz(n), n >>= t;\n\
    \    if (int i = n >> 1; n > 1)\n      for (set_lpfe(n); n > 1; i = n >> 1) ret[lpf[i]]\
    \ = lpfe[i], n /= lpfpw[i];\n    return ret;\n  }\n  // O(log n)\n  static std::vector<int>\
    \ divisors(int n) {\n    std::vector<int> ret = {1};\n    for (auto [p, e] : factorize(n))\n\
    \      for (std::size_t sz = ret.size(), pw = p; e--; pw *= p)\n        for (int\
    \ i = sz - 1; i >= 0; i--) ret.push_back(ret[i] * pw);\n    return std::sort(ret.begin(),\
    \ ret.end()), ret;\n  }\n  // O(N)\n  static std::vector<int> get_primes(int N)\
    \ {\n    return sieve(N), std::vector<int>(ps, std::upper_bound(ps, ps + psz,\
    \ N));\n  }\n  template <class T, class F>\n  static inline std::vector<T> completely_multiplicative_table(int\
    \ N,\n                                                               const F &f)\
    \ {\n    std::vector<T> ret(N + 1);\n    sieve(N);\n    for (int n = 3, i = 1;\
    \ n <= N; n += 2, i++)\n      ret[n] = lpf[i] == n ? f(n, 1) : ret[lpf[i]] * ret[n\
    \ / lpf[i]];\n    if (int n = 4; 2 <= N)\n      for (ret[2] = f(2, 1); n <= N;\
    \ n += 2) ret[n] = ret[2] * ret[n >> 1];\n    return ret[1] = 1, ret;\n  }\n \
    \ template <class T, class F>\n  static inline std::vector<T> multiplicative_table(int\
    \ N, const F &f) {\n    std::vector<T> ret(N + 1);\n    set_lpfe(N);\n    for\
    \ (int n = 3, i = 1; n <= N; n += 2, i++)\n      ret[n] = lpfpw[i] == n ? f(lpf[i],\
    \ lpfe[i])\n                             : ret[lpfpw[i]] * ret[n / lpfpw[i]];\n\
    \    for (int n = 2, t; n <= N; n += 2)\n      t = __builtin_ctz(n),\n      ret[n]\
    \ = n & (n - 1) ? ret[n & -n] * ret[n >> t] : f(2, t);\n    return ret[1] = 1,\
    \ ret;\n  }\n  // O(N log k / log N + N)\n  template <class T>\n  static std::vector<T>\
    \ pow_table(int N, std::uint64_t k) {\n    if (k == 0) return std::vector<T>(N\
    \ + 1, 1);\n    auto f = [k](int p, short) {\n      T ret = 1, b = p;\n      for\
    \ (auto e = k;; b *= b)\n        if (e & 1 ? ret *= b, !(e >>= 1) : !(e >>= 1))\
    \ return ret;\n    };\n    return completely_multiplicative_table<T>(N, f);\n\
    \  }\n  // O(N log MOD / log N + N)\n  template <class T>\n  static std::vector<T>\
    \ inv_table(int N) {\n    return completely_multiplicative_table<T>(\n       \
    \ N, [](int p, short) { return T(1) / p; });\n  }\n  // naive , O(N log N)\n \
    \ template <class T>\n  static std::vector<T> dirichlet_conv(const std::vector<T>\
    \ &a,\n                                       const std::vector<T> &b) {\n   \
    \ std::size_t N = std::max(a.size(), b.size()) - 1, i, j;\n    std::vector<T>\
    \ ret(N + 1, 0);\n    for (i = a.size(); --i;)\n      for (j = std::min(b.size()\
    \ - 1, N / i); j; j--) ret[i * j] += a[i] * b[j];\n    return ret;\n  }\n  //\
    \ a is multiplicative, O(N log log N)\n  template <class T, class F>\n  static\
    \ std::vector<T> dirichlet_conv(const F &a, std::vector<T> b) {\n    std::size_t\
    \ N = b.size() - 1, j = 0;\n    for (sieve(N), b.resize(N + 1, 0); j < psz &&\
    \ ps[j] <= N; j++)\n      for (int i = N / ps[j], n, m, e; i; i--)\n        for\
    \ (b[n = ps[j] * i] += a(ps[j], e = 1) * b[m = i]; m % ps[j] == 0;)\n        \
    \  b[n] += a(ps[j], ++e) * b[m /= ps[j]];\n    return b;\n  }\n  // both a and\
    \ b are multiplicative, O(N)\n  template <class T, class F1, class F2>\n  static\
    \ std::vector<T> dirichlet_conv(const F1 &a, const F2 &b,\n                  \
    \                     std::size_t N) {\n    auto f = [&a, &b](int p, short e)\
    \ {\n      T ret = a(p, e) + b(p, e);\n      for (int k = e; --k;) ret += a(p,\
    \ e - k) * b(p, k);\n      return ret;\n    };\n    return multiplicative_table<T>(N,\
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
    #line 4 \"src/Math/is_prime.hpp\"\n/**\n * @title \u7D20\u6570\u5224\u5B9A\n *\
    \ @category \u6570\u5B66\n *  O(log N)\n */\n\n// BEGIN CUT HERE\nnamespace math_internal\
    \ {\ntemplate <class Uint, class mod_pro_t, u64... args>\nconstexpr bool miller_rabin(Uint\
    \ n) {\n  const mod_pro_t md(n);\n  const Uint s = __builtin_ctzll(n - 1), d =\
    \ n >> s, one = md.set(1),\n             n1 = md.norm(md.set(n - 1));\n  for (auto\
    \ a : {args...}) {\n    Uint b = a % n, p = pow(md.set(b), d, md), i = s;\n  \
    \  while (p = md.norm(p), (p != one && p != n1 && b && i--)) p = md.mul(p, p);\n\
    \    if (md.norm(p) != n1 && i != s) return false;\n  }\n  return true;\n}\nconstexpr\
    \ bool is_prime(u64 n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\
    \  if (n < UINT_MAX) return miller_rabin<u32, MIntPro_Na<u32>, 2, 7, 61>(n);\n\
    \  if (n < LLONG_MAX)\n    return miller_rabin<u64, MIntPro_Montg, 2, 325, 9375,\
    \ 28178, 450775,\n                        9780504, 1795265022>(n);\n  return miller_rabin<u64,\
    \ MIntPro_Na<u64>, 2, 325, 9375, 28178, 450775,\n                      9780504,\
    \ 1795265022>(n);\n}\n}  // namespace math_internal\nusing math_internal::is_prime;\n\
    #line 5 \"src/FFT/NTT.hpp\"\n\n/**\n * @title Number-Theoretic-Transform\n * @category\
    \ FFT\n */\n\n// BEGIN CUT HERE\nnamespace ntt_internal {\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\ntemplate <class mod_t>\nstruct NumberTheoreticTransform\
    \ {\n  static inline void dft(int n, mod_t x[]) {\n    for (int m = n, h = 0,\
    \ i0 = 0; m >>= 1; h = 0, i0 = 0)\n      for (mod_t prod = 1, u; i0 < n;\n   \
    \        prod *= r2[__builtin_ctz(++h)], i0 += (m << 1))\n        for (int i =\
    \ i0; i < i0 + m; ++i)\n          x[i + m] = x[i] - (u = prod * x[i + m]), x[i]\
    \ += u;\n  }\n  static inline void idft(int n, mod_t x[]) {\n    for (int m =\
    \ 1, h = 0, i0 = 0; m < n; m <<= 1, h = 0, i0 = 0)\n      for (mod_t prod = 1,\
    \ y; i0 < n;\n           prod *= ir2[__builtin_ctz(++h)], i0 += (m << 1))\n  \
    \      for (int i = i0; i < i0 + m; ++i)\n          y = x[i] - x[i + m], x[i]\
    \ += x[i + m], x[i + m] = prod * y;\n    for (const mod_t iv = mod_t(1) / n; n--;)\
    \ x[n] *= iv;\n  }\n  static void even_dft(int n, mod_t x[]) {\n    for (int i\
    \ = 0, j = 0; i < n; i += 2, j++) x[j] = iv2 * (x[i] + x[i + 1]);\n  }\n  static\
    \ void odd_dft(int n, mod_t x[]) {\n    mod_t prod = iv2;\n    for (int i = 0,\
    \ j = 0; i < n; i += 2, j++)\n      x[j] = prod * (x[i] - x[i + 1]), prod *= ir2[__builtin_ctzll(~((u64)j))];\n\
    \  }\n  static void dft_doubling(int n, mod_t x[]) {\n    std::copy_n(x, n, x\
    \ + n), idft(n, x + n);\n    mod_t k(1), t(rt[__builtin_ctz(n << 1)]);\n    for\
    \ (int i = 0; i < n; i++) x[n + i] *= k, k *= t;\n    dft(n, x + n);\n  }\n  static\
    \ constexpr std::uint64_t lim() { return 1ULL << E; }\n\n protected:\n  static\
    \ constexpr mod_t pow2th_root(std::uint8_t e) {\n    for (mod_t r = 2;; r += 1)\n\
    \      if (auto s = r.pow((mod_t::modulo() - 1) / 2); s != 1 && s * s == 1)\n\
    \        return r.pow((mod_t::modulo() - 1) >> e);\n    return 0;  // can not\
    \ find\n  }            // return \u03C9 (primitive 2^e th root)\n  static_assert(mod_t::modulo()\
    \ & 1);\n  static_assert(is_prime(mod_t::modulo()));\n  static constexpr std::uint8_t\
    \ E = __builtin_ctzll(mod_t::modulo() - 1);\n  static constexpr auto roots(mod_t\
    \ w) {\n    std::array<mod_t, E + 1> ret = {};\n    for (std::uint8_t e = E; e;\
    \ e--, w *= w) ret[e] = w;\n    return ret[0] = w, ret;\n  }\n  static constexpr\
    \ auto ratios(const std::array<mod_t, E + 1> &rt,\n                          \
    \     const std::array<mod_t, E + 1> &irt, int i = 2) {\n    std::array<mod_t,\
    \ E - 1> ret = {};\n    for (mod_t prod = 1; i <= E; prod *= irt[i++]) ret[i -\
    \ 2] = rt[i] * prod;\n    return ret;\n  }\n  static constexpr mod_t w = pow2th_root(E),\
    \ iw = w.pow(lim() - 1);\n  static constexpr mod_t iv2 = mod_t((mod_t::modulo()\
    \ + 1) / 2);\n  static_assert(w != mod_t(0));\n  static constexpr auto rt = roots(w),\
    \ irt = roots(iw);\n  static constexpr auto r2 = ratios(rt, irt), ir2 = ratios(irt,\
    \ rt);\n};\ntemplate <class T, class B>\nstruct NTTArrayImpl : public B {\n  using\
    \ B::B;\n  static constexpr std::uint8_t type() { return B::type; }\n#define FUNC(op,\
    \ name, HOGEHOGE, ...)            \\\n  inline void name(__VA_ARGS__) {      \
    \          \\\n    HOGEHOGE(op, 1);                             \\\n    if constexpr\
    \ (B::type >= 2) HOGEHOGE(op, 2); \\\n    if constexpr (B::type >= 3) HOGEHOGE(op,\
    \ 3); \\\n  }\n#define DFT(fft, _) B::ntt##_::fft(e - b, this->dat##_ + b)\n#define\
    \ ZEROS(op, _) std::fill_n(this->dat##_ + b, e - b, B::Z##_)\n#define SET(op,\
    \ _) std::copy(x + b, x + e, this->dat##_ + b)\n#define SET_SINGLE(op, _) this->dat##_[i]\
    \ = x;\n#define SUBST(op, _) std::copy(r.dat##_ + b, r.dat##_ + e, this->dat##_\
    \ + b)\n  FUNC(dft, dft, DFT, int b, int e)\n  FUNC(idft, idft, DFT, int b, int\
    \ e)\n  FUNC(__, zeros, ZEROS, int b, int e)\n  FUNC(__, set, SET, const T x[],\
    \ int b, int e)\n  FUNC(__, set, SET_SINGLE, int i, T x)\n  template <class C>\n\
    \  FUNC(__, subst, SUBST, const NTTArrayImpl<T, C> &r, int b, int e)\n  inline\
    \ void get(T x[], int b, int e) const {\n    if constexpr (B::type == 1)\n   \
    \   std::copy(this->dat1 + b, this->dat1 + e, x + b);\n    else\n      for (int\
    \ i = b; i < e; i++) x[i] = get(i);\n  }\n  inline T get(int i) const {\n    if\
    \ constexpr (B::type == 3) {\n      const T mod1 = B::mint1::modulo(), mod2 =\
    \ B::mint2::modulo();\n      u64 r1 = this->dat1[i].val(), r2 = (B::iv21 * (this->dat2[i]\
    \ - r1)).val();\n      u64 r3 = (B::iv31 * (this->dat3[i] - r1) - B::iv32 * r2).val();\n\
    \      return mod1 * (mod2 * r3 + r2) + r1;\n    } else if constexpr (B::type\
    \ == 2) {\n      const T mod1 = B::mint1::modulo();\n      u64 r1 = this->dat1[i].val();\n\
    \      return mod1 * ((this->dat2[i] - r1) * B::iv).val() + r1;\n    } else\n\
    \      return this->dat1[i];\n  }\n#define ASGN(op, _) \\\n  for (int i = b; i\
    \ < e; i++) this->dat##_[i] op## = r.dat##_[i]\n#define ASSIGN(fname, op) \\\n\
    \  template <class C>      \\\n  FUNC(op, fname, ASGN, const NTTArrayImpl<T, C>\
    \ &r, int b, int e)\n#define BOP(op, _) \\\n  for (int i = b; i < e; i++) this->dat##_[i]\
    \ = l.dat##_[i] op r.dat##_[i]\n#define OP(fname, op)                        \
    \       \\\n  template <class C, class D>                       \\\n  FUNC(op,\
    \ fname, BOP, const NTTArrayImpl<T, C> &l, \\\n       const NTTArrayImpl<T, D>\
    \ &r, int b, int e)\n  OP(add, +) OP(dif, -) OP(mul, *) ASSIGN(add, +) ASSIGN(dif,\
    \ -) ASSIGN(mul, *)\n#undef DFT\n#undef ZEROS\n#undef SET\n#undef SET_SINGLE\n\
    #undef SUBST\n#undef ASGN\n#undef ASSIGN\n#undef BOP\n#undef OP\n#undef FUNC\n\
    };\ntemplate <class T, std::size_t _Nm>\nstruct NTTArrayB_SingleB {\n  using ntt1\
    \ = NumberTheoreticTransform<T>;\n  static_assert(_Nm <= ntt1::lim());\n  static\
    \ constexpr T Z1 = 0;\n  static constexpr std::uint8_t type = 1;\n};\ntemplate\
    \ <class T, std::size_t _Nm, bool is_heap>\nstruct NTTArrayB_Single : protected\
    \ NTTArrayB_SingleB<T, _Nm> {\n  T dat1[_Nm] = {};\n};\ntemplate <class T, std::size_t\
    \ _Nm>\nstruct NTTArrayB_Single<T, _Nm, true> : protected NTTArrayB_SingleB<T,\
    \ _Nm> {\n  NTTArrayB_Single() : dat1(buf1.data()) {}\n  void resize(int n) {\n\
    \    buf1.resize(n, NTTArrayB_Single::Z1), dat1 = buf1.data();\n  }\n  std::size_t\
    \ size() const { return buf1.size(); }\n  std::vector<T> buf1;\n  T *dat1;\n};\n\
    #define NTTARRAYB_MULTI(iv, t)                                    \\\n  using\
    \ mint1 = StaticModInt<MOD1>;                               \\\n  using mint2\
    \ = StaticModInt<MOD2>;                               \\\n  using ntt1 = NumberTheoreticTransform<mint1>;\
    \                   \\\n  using ntt2 = NumberTheoreticTransform<mint2>;      \
    \             \\\n  static_assert(_Nm <= (1 << 25));                         \
    \       \\\n  static constexpr mint1 Z1 = 0;                                 \
    \ \\\n  static constexpr mint2 iv = mint2(1) / mint1::modulo(), Z2 = 0; \\\n \
    \ static constexpr std::uint8_t type = t;\ntemplate <std::size_t _Nm, u64 MOD1,\
    \ u64 MOD2>\nstruct NTTArrayB_DoubleB {\n  NTTARRAYB_MULTI(iv, 2);\n};\ntemplate\
    \ <std::size_t _Nm, u64 MOD1, u64 MOD2, u64 MOD3>\nstruct NTTArrayB_TripleB {\n\
    \  NTTARRAYB_MULTI(iv21, 3);\n  using mint3 = StaticModInt<MOD3>;\n  using ntt3\
    \ = NumberTheoreticTransform<mint3>;\n  static constexpr mint3 iv32 = mint3(1)\
    \ / mint2::modulo(),\n                         iv31 = iv32 / mint1::modulo(),\
    \ Z3 = 0;\n};\n#undef NTTARRAYB_MULTI\ntemplate <std::size_t _Nm, u64 MOD1, u64\
    \ MOD2, bool is_heap>\nstruct NTTArrayB_Double : protected NTTArrayB_DoubleB<_Nm,\
    \ MOD1, MOD2> {\n  typename NTTArrayB_DoubleB<_Nm, MOD1, MOD2>::mint1 dat1[_Nm]\
    \ = {};\n  typename NTTArrayB_DoubleB<_Nm, MOD1, MOD2>::mint2 dat2[_Nm] = {};\n\
    };\ntemplate <std::size_t _Nm, u64 MOD1, u64 MOD2>\nstruct NTTArrayB_Double<_Nm,\
    \ MOD1, MOD2, true>\n    : protected NTTArrayB_DoubleB<_Nm, MOD1, MOD2> {\n  NTTArrayB_Double()\
    \ : dat1(buf1.data()), dat2(buf2.data()) {}\n  void resize(int n) {\n    buf1.resize(n,\
    \ NTTArrayB_DoubleB<_Nm, MOD1, MOD2>::Z1), dat1 = buf1.data();\n    buf2.resize(n,\
    \ NTTArrayB_DoubleB<_Nm, MOD1, MOD2>::Z2), dat2 = buf2.data();\n  }\n  std::size_t\
    \ size() const { return buf1.size(); }\n  std::vector<typename NTTArrayB_DoubleB<_Nm,\
    \ MOD1, MOD2>::mint1> buf1;\n  std::vector<typename NTTArrayB_DoubleB<_Nm, MOD1,\
    \ MOD2>::mint2> buf2;\n  typename NTTArrayB_DoubleB<_Nm, MOD1, MOD2>::mint1 *dat1;\n\
    \  typename NTTArrayB_DoubleB<_Nm, MOD1, MOD2>::mint2 *dat2;\n};\ntemplate <std::size_t\
    \ _Nm, u64 MOD1, u64 MOD2, u64 MOD3, bool is_heap>\nstruct NTTArrayB_Triple :\
    \ protected NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3> {\n  typename NTTArrayB_TripleB<_Nm,\
    \ MOD1, MOD2, MOD3>::mint1 dat1[_Nm] = {};\n  typename NTTArrayB_TripleB<_Nm,\
    \ MOD1, MOD2, MOD3>::mint2 dat2[_Nm] = {};\n  typename NTTArrayB_TripleB<_Nm,\
    \ MOD1, MOD2, MOD3>::mint3 dat3[_Nm] = {};\n};\ntemplate <std::size_t _Nm, u64\
    \ MOD1, u64 MOD2, u64 MOD3>\nstruct NTTArrayB_Triple<_Nm, MOD1, MOD2, MOD3, true>\n\
    \    : protected NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3> {\n  NTTArrayB_Triple()\n\
    \      : dat1(buf1.data()), dat2(buf2.data()), dat3(buf3.data()) {}\n  void resize(int\
    \ n) {\n    buf1.resize(n, NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::Z1);\n  \
    \  buf2.resize(n, NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::Z2);\n    buf3.resize(n,\
    \ NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::Z3);\n    dat1 = buf1.data(), dat2\
    \ = buf2.data(), dat3 = buf3.data();\n  }\n  std::size_t size() const { return\
    \ buf1.size(); }\n  std::vector<typename NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::mint1>\
    \ buf1;\n  std::vector<typename NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::mint2>\
    \ buf2;\n  std::vector<typename NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::mint3>\
    \ buf3;\n  typename NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::mint1 *dat1;\n \
    \ typename NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::mint2 *dat2;\n  typename\
    \ NTTArrayB_TripleB<_Nm, MOD1, MOD2, MOD3>::mint3 *dat3;\n};\ntemplate <class\
    \ T, std::size_t _Nm>\nconstexpr bool is_nttfriend() {\n  if constexpr (!is_staticmodint_v<T>)\n\
    \    return false;\n  else\n    return (T::modulo() & is_prime(T::modulo())) &&\n\
    \           _Nm <= (1ULL << __builtin_ctzll(T::modulo() - 1));\n}\nconstexpr std::uint32_t\
    \ MOD32 = 0x7e000001;\nconstexpr u64 MOD64_1 = 0x3ffffffffa000001, MOD64_2 = 0x3fffffffea000001,\n\
    \              MOD64_3 = 0x3fffffffcc000001;\nconstexpr bool threshold(u64 val,\
    \ u64 s, u64 m) {\n  return u128(val) * val <= u128(MOD64_1) * m / s;\n}\ntemplate\
    \ <class T>\nconstexpr u64 max_value() {\n  if constexpr (is_runtimemodint_v<T>)\n\
    \    return std::numeric_limits<typename T::Uint>::max();\n  else if constexpr\
    \ (is_staticmodint_v<T>)\n    return T::modulo();\n  else\n    return std::numeric_limits<T>::max();\n\
    }\ntemplate <class T, std::size_t _Nm>\nconstexpr bool is_nttarraydouble = threshold(max_value<T>(),\
    \ _Nm, MOD32);\ntemplate <class T, std::size_t _Nm, bool is_heap>\nusing NTTArrayB_Multi\
    \ =\n    std::conditional_t<is_nttarraydouble<T, _Nm>,\n                     \
    \  NTTArrayB_Double<_Nm, MOD64_1, MOD32, is_heap>,\n                       NTTArrayB_Triple<_Nm,\
    \ MOD64_1, MOD64_2, MOD32, is_heap>>;\ntemplate <class T, std::size_t _Nm, bool\
    \ is_heap>\nusing NTTArrayB = std::conditional_t<is_nttfriend<T, _Nm>(),\n   \
    \                                  NTTArrayB_Single<T, _Nm, is_heap>,\n      \
    \                               NTTArrayB_Multi<T, _Nm, is_heap>>;\ntemplate <class\
    \ T, std::size_t _Nm, bool is_heap = false>\nusing NTTArray = NTTArrayImpl<T,\
    \ NTTArrayB<T, _Nm, is_heap>>;\n}  // namespace ntt_internal\nusing ntt_internal::is_nttarraydouble,\
    \ ntt_internal::is_nttfriend,\n    ntt_internal::NumberTheoreticTransform, ntt_internal::NTTArray;\n\
    template <class T, std::size_t _Nm>\nconstexpr int nttarray_type = NTTArray<T,\
    \ _Nm>::type();\ntemplate <class T, std::size_t _Nm, int id = 0>\nstruct GlobalNTTArray\
    \ {\n  static inline NTTArray<T, _Nm, false> bf;\n};\ntemplate <class T, std::size_t\
    \ _Nm, std::size_t _Nm2, int id = 0>\nstruct GlobalNTTArray2D {\n  static inline\
    \ NTTArray<T, _Nm, false> bf[_Nm2];\n};\ntemplate <class T, std::size_t _Nm, int\
    \ id = 0>\nstruct GlobalArray {\n  static inline T bf[_Nm];\n};\nconstexpr std::uint32_t\
    \ get_len(std::uint32_t n) {\n  return (n |= (n |= (n |= (n |= (n |= (--n) >>\
    \ 1) >> 2) >> 4) >> 8) >> 16) + 1;\n}\n#line 4 \"src/FFT/sample_points_shift.hpp\"\
    \n\n/**\n * @title \u591A\u9805\u5F0F\u306E\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8\
    \n * @category FFT\n * y=f(0),f(1),...,f(n-1)\u304C\u4E0E\u3048\u3089\u308C\u305F\
    \u3068\u304D\u306Ef(c),f(c+1),...,f(c+m-1)\u3092\u8A08\u7B97\n * O( (n+m)log(n+m)\
    \ )\n */\n\n// BEGIN CUT HERE\ntemplate <class mod_t, std::size_t _Nm = 1 << 22>\n\
    std::vector<mod_t> sample_points_shift(const std::vector<mod_t> &y, mod_t c,\n\
    \                                       int m = 1) {\n  assert(m <= mod_t::modulo()),\
    \ assert(y.size() <= mod_t::modulo());\n  static constexpr int TH = = is_nttfriend<mod_t,\
    \ _Nm2>()      ? 50\n                              : is_nttarraydouble<mod_t,\
    \ _Nm2> ? 130\n                                                              \
    \ : 145;\n  if (m == 0) return {};\n  std::uint64_t c_64 = c.val(), nc1 = (c +\
    \ (m - 1)).val();\n  std::uint32_t k = y.size(), d = k - 1, i = d, e;\n  if (c_64\
    \ + m <= k)\n    return std::vector<mod_t>(y.begin() + c_64, y.begin() + c_64\
    \ + m);\n  using GA = GlobalArray<mod_t, _Nm, 0>;\n  for (GA::bf[d] = 1; i; i--)\
    \ GA::bf[i - 1] = GA::bf[i] * i;\n  mod_t t = mod_t(1) / (GA::bf[0] * GA::bf[0]);\n\
    \  for (i = d / 2 + 1; i--;)\n    GA::bf[i] = GA::bf[d - i] = GA::bf[i] * GA::bf[d\
    \ - i] * t;\n  for (i = k; i--;) GA::bf[i] *= y[i];\n  for (i = 1; i < k; i +=\
    \ 2) GA::bf[d - i] = -GA::bf[d - i];\n  const mod_t Z = 0;\n  auto f = [&](mod_t\
    \ a, int n, mod_t ret[]) {\n    using GNA1 = GlobalNTTArray<mod_t, _Nm, 1>;\n\
    \    using GNA2 = GlobalNTTArray<mod_t, _Nm, 2>;\n    using GAq = GlobalArray<mod_t,\
    \ _Nm, 2>;\n    for (e = d + n, i = 0, t = a - d; i < e; i++, t += 1) ret[i] =\
    \ t;\n    std::partial_sum(ret, ret + e, GAq::bf, std::multiplies<>());\n    for\
    \ (t = mod_t(1) / GAq::bf[e - 1]; --i;)\n      GAq::bf[i] = t * GAq::bf[i - 1],\
    \ t *= ret[i];\n    if (GAq::bf[0] = t; k >= TH && n >= TH) {\n      const int\
    \ len = get_len(e + (d > 0));\n      GNA1::bf.set(GA::bf, 0, k), GNA1::bf.zeros(k,\
    \ len), GNA1::bf.dft(0, len);\n      GNA2::bf.set(GAq::bf, 0, e), GNA2::bf.zeros(e,\
    \ len), GNA2::bf.dft(0, len);\n      GNA1::bf.mul(GNA2::bf, 0, len), GNA1::bf.idft(0,\
    \ len);\n      GNA1::bf.get(ret - d, d, e);\n    } else\n      for (std::fill_n(ret,\
    \ n, Z), i = k; i--;)\n        for (int b = d - i, j = n; j--;) ret[j] += GA::bf[i]\
    \ * GAq::bf[j + b];\n    for (t = a, i = k; --i;) t *= a - i;\n    for (; i <\
    \ n; i++) ret[i] *= t, t *= (a + (i + 1)) * GAq::bf[i];\n    return ret + n;\n\
    \  };\n  using GAp = GlobalArray<mod_t, _Nm, 1>;\n  if (mod_t * bf; c_64 < k)\
    \ {\n    if (bf = std::copy_n(y.begin() + c_64, k - c_64, GAp::bf); nc1 < k)\n\
    \      std::copy_n(y.begin(), nc1 + 1, f(k, mod_t::modulo() - k, bf));\n    else\n\
    \      f(k, c_64 + m - k, bf);\n  } else if (nc1 < c_64) {\n    if (mod_t *bf\
    \ = f(c, (-c).val(), GAp::bf); nc1 < k)\n      std::copy_n(y.begin(), nc1 + 1,\
    \ bf);\n    else\n      f(k, nc1 + 1 - k, std::copy_n(y.begin(), k, bf));\n  }\
    \ else\n    f(c, m, GAp::bf);\n  return std::vector<mod_t>(GAp::bf, GAp::bf +\
    \ m);\n}\n#line 10 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using C = Combination<Mint>;\n  long\
    \ long r, d, n;\n  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n\
    \    return 0;\n  }\n  if (r == 0) {\n    cout << (d ? 0 : 1) << '\\n';\n    return\
    \ 0;\n  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = Sieve<>::pow_table<Mint>(d\
    \ + 2, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d\
    \ + 1; i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i]\
    \ = sum[i - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = sample_points_shift<Mint>(sum,\
    \ n)[0];\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(1) / r, rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n     \
    \ y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n    ans\
    \ += Mint(r).pow(n) * sample_points_shift<Mint>(y, n)[0];\n  }\n  cout << ans\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/Combination.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/Math/Sieve.hpp\"\n#include \"src/FFT/sample_points_shift.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using C = Combination<Mint>;\n  long\
    \ long r, d, n;\n  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n\
    \    return 0;\n  }\n  if (r == 0) {\n    cout << (d ? 0 : 1) << '\\n';\n    return\
    \ 0;\n  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = Sieve<>::pow_table<Mint>(d\
    \ + 2, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d\
    \ + 1; i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i]\
    \ = sum[i - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = sample_points_shift<Mint>(sum,\
    \ n)[0];\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(1) / r, rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n     \
    \ y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n    ans\
    \ += Mint(r).pow(n) * sample_points_shift<Mint>(y, n)[0];\n  }\n  cout << ans\
    \ << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/Sieve.hpp
  - src/FFT/sample_points_shift.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  requiredBy: []
  timestamp: '2022-11-16 19:55:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
---
