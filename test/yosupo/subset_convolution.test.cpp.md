---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/SetPowerSeries.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/yosupo/subset_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/subset_convolution\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\nnamespace internal {\ntemplate <std::uint64_t mod,\
    \ std::uint64_t prim_root, class ModInt>\nstruct ModIntImpl {\n  static constexpr\
    \ std::uint64_t modulo() { return mod; }\n  static constexpr std::uint64_t pr_rt()\
    \ { return prim_root; }\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace internal\n\
    template <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\n    :\
    \ public internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n  using\
    \ u64 = std::uint64_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x\
    \ = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n \
    \ static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -__uint128_t(mod) % mod;\n\
    \  static constexpr u64 init(u64 w) { return reduce(__uint128_t(w) * r2); }\n\
    \  static constexpr u64 reduce(const __uint128_t w) {\n    return u64(w >> 64)\
    \ + mod - ((__uint128_t(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n public:\n\
    \  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n\
    \ < 0 ? mod - (-n) % mod : n)) {}\n  static constexpr u64 norm(u64 w) { return\
    \ w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const {\n    ModInt\
    \ ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - (mod << 1),\
    \ x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n\
    \  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x\
    \ = reduce(__uint128_t(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t\
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
    \ mod ? ret.first : -ret.first;\n  }\n  constexpr u64 val() const {\n    u64 ret\
    \ = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  friend std::istream\
    \ &operator>>(std::istream &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x\
    \ = init(rhs.x), is;\n  }\n};\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2,\
    \ pr_rt> : internal::ModIntImpl<2, pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t\
    \ n = 0) : x(n & 1) {}\n  constexpr ModInt operator-() const { return *this; }\n\
    \  constexpr ModInt &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator*=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator/=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return x == rhs.x; }\n  bool\
    \ operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n  constexpr\
    \ ModInt pow(std::uint64_t k) const { return !k ? ModInt(1) : *this; }\n  constexpr\
    \ ModInt sqrt() const { return *this; }\n  constexpr ModInt inverse() const {\
    \ return *this; }\n  constexpr std::uint64_t val() const { return x; }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 3 \"src/Math/SetPowerSeries.hpp\"\
    \n/**\n * @title \u96C6\u5408\u51AA\u7D1A\u6570\n * @category \u6570\u5B66\n *\
    \ @see\n * https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex\n\
    \ * @see\n * https://notes.sshwy.name/Math/Subset-Power-Series/#%E5%88%86%E6%B2%BB%E5%8D%B7%E7%A7%AF-1\n\
    \ */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n\
    //                        (\u30AA\u30F3\u30E9\u30A4\u30F3\u7573\u8FBC\u307F2 or\
    \ \u5408\u6210 1-\u221A(1-2f))\n// https://loj.ac/p/2340 (\u30AA\u30F3\u30E9\u30A4\
    \u30F3\u7573\u8FBC\u307F)\n\n// BEGIN CUT HERE\n\ntemplate <unsigned short MAX_N\
    \ = 21>\nclass SetPowerSeries {\n#define SUBSET_REP(i, j, n)                 \
    \          \\\n  for (int _ = (n); _ >>= 1;)                         \\\n    for\
    \ (int __ = 0, _2 = _ << 1; __ < (n); __ += _2) \\\n      for (int j = __, i =\
    \ j | _, ___ = i; j < ___; j++, i++)\n  template <typename T>\n  static inline\
    \ void ranked_zeta_tr(const T f[], T ret[][MAX_N + 1],\n                     \
    \               const int &sz) {\n    for (int S = sz, c; S--;)\n      ret[S][c\
    \ = __builtin_popcount(S)] = f[S], std::fill_n(ret[S], c, 0);\n    SUBSET_REP(S,\
    \ U, sz)\n    for (int d = __builtin_popcount(S); d--;) ret[S][d] += ret[U][d];\n\
    \  }\n  template <typename T>\n  static inline void conv_na(const T f[], const\
    \ T g[], T ret[], const int &sz) {\n    for (int s = sz, t; s--;)\n      for (ret[t\
    \ = s] = f[s] * g[0]; t; (--t) &= s) ret[s] += f[s ^ t] * g[t];\n  }\n  template\
    \ <typename T>\n  static inline void conv_tr(const T f[], const T g[], T ret[],\
    \ const int &sz) {\n    static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N\
    \ + 1];\n    T tmp[MAX_N + 1];\n    ranked_zeta_tr(f, F, sz), ranked_zeta_tr(g,\
    \ G, sz);\n    const int n = __builtin_ctz(sz);\n    for (int S = sz, c, d, e,\
    \ bg; S--;) {\n      c = __builtin_popcount(S), bg = std::min(2 * c, n);\n   \
    \   for (d = bg; d >= c; d--)\n        for (tmp[d] = 0, e = d - c; e <= c; e++)\n\
    \          tmp[d] += F[S][e] * G[S][d - e];\n      for (d = bg; d >= c; d--) F[S][d]\
    \ = tmp[d];\n    }\n    SUBSET_REP(S, U, sz)\n    for (int c = __builtin_popcount(U),\
    \ d = std::min(2 * c, n); d > c; d--)\n      F[S][d] -= F[U][d];\n    for (int\
    \ S = sz; S--;) ret[S] = F[S][__builtin_popcount(S)];\n  }\n  template <typename\
    \ T, class F>\n  static inline void onconv_na(const T g[], T ret[], const F &phi,\n\
    \                               const int &sz) {\n    for (int s = 1, t; s < sz;\
    \ phi(s, ret[s]), s++)\n      for (ret[t = s] = 0; t; (--t) &= s) ret[s] += ret[s\
    \ ^ t] * g[t];\n  }\n  template <typename T, class F>\n  static inline void onconv_tr(const\
    \ T g[], T ret[], const F &phi,\n                               const int &sz)\
    \ {\n    static T G[1 << MAX_N][MAX_N + 1], mat[MAX_N + 1][1 << MAX_N];\n    const\
    \ int n = __builtin_ctz(sz);\n    ranked_zeta_tr(g, G, sz), std::fill_n(mat[0],\
    \ sz, ret[0]);\n    for (int d = n; d; d--) std::fill_n(mat[d], sz, 0);\n    for\
    \ (int I = sz; I >>= 1;) phi(I, mat[1][I] = ret[0] * g[I]);\n    for (int d =\
    \ 2; d <= n; d++) {\n      SUBSET_REP(S, U, sz) mat[d - 1][S] += mat[d - 1][U];\n\
    \      for (int S = sz; S--;)\n        if (int c = __builtin_popcount(S); c <=\
    \ d && d <= 2 * c)\n          for (int e = d; e--;) mat[d][S] += mat[e][S] * G[S][d\
    \ - e];\n      SUBSET_REP(S, U, sz) mat[d][S] -= mat[d][U];\n      for (int S\
    \ = sz; S--;)\n        __builtin_popcount(S) == d ? phi(S, mat[d][S]), 0 : (mat[d][S]\
    \ = 0);\n    }\n    for (int S = sz; --S;) ret[S] = mat[__builtin_popcount(S)][S];\n\
    \  }\n\n public:\n  template <typename T>  // O(n 2^n)\n  static inline void subset_sum(std::vector<T>\
    \ &f) {\n    SUBSET_REP(S, U, f.size()) f[S] += f[U];\n  }\n  template <typename\
    \ T>  // O(n 2^n)\n  static inline void subset_sum_inv(std::vector<T> &f) {\n\
    \    SUBSET_REP(S, U, f.size()) f[S] -= f[U];\n  }\n  template <class T>  // O(n^2\
    \ 2^n)\n  static inline std::vector<T> convolve(const std::vector<T> &f,\n   \
    \                                     const std::vector<T> &g) {\n    const int\
    \ sz = f.size(), n = __builtin_ctz(sz);\n    std::vector<T> ret(sz);\n    if (n\
    \ <= 10) return conv_na(f.data(), g.data(), ret.data(), sz), ret;\n    assert(sz\
    \ == 1 << n && sz == g.size());\n    return conv_tr(f.data(), g.data(), ret.data(),\
    \ sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{T\u228AS} f(T)g(S/T) )\n  template\
    \ <class T, class F = void (*)(int, T &)>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ online_convolve(\n      const std::vector<T> &g, T init, const F &phi = [](int,\
    \ T &) {}) {\n    const int sz = g.size(), n = __builtin_ctz(sz);\n    std::vector<T>\
    \ ret(sz);\n    ret[0] = init;\n    if (n <= 12) return onconv_na(g.data(), ret.data(),\
    \ phi, sz), ret;\n    assert(sz == 1 << n);\n    return onconv_tr(g.data(), ret.data(),\
    \ phi, sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{\u2205\u2260T\u228AS & (T<(S/T)\
    \ as binary numbers) } f(T)f(S/T) )\n  template <class T, class F>  // O(n^2 2^n)\n\
    \  static inline std::vector<T> online_convolve2(int sz, const F &phi) {\n   \
    \ assert(__builtin_popcount(sz) == 1);\n    int mid = std::min(1 << 13, sz);\n\
    \    std::vector<T> ret(sz, 0);\n    for (int I = 1, s, t, u = 1; I < mid; I <<=\
    \ 1)\n      for (t = s = 0; s < I; phi(u, ret[u]), t = ++s, u++)\n        for\
    \ (ret[u] = 0; t; (--t) &= s) ret[u] += ret[I | (s ^ t)] * ret[t];\n    T *h =\
    \ ret.data();\n    for (int I = mid; I < sz; I <<= 1)\n      phi(I, ret[I]), onconv_tr(\n\
    \                          h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n\
    \    return ret;\n  }\n  // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n\
    \  // \"f[\u2205] = 0\" is required.\n  template <class T, class EGF>  // O(n^2\
    \ 2^n)\n  static inline std::vector<T> composite(const std::vector<T> &f,\n  \
    \                                       const EGF &F) {\n    const int sz = f.size(),\
    \ m = __builtin_ctz(sz), sz2 = sz >> 1;\n    assert(sz == 1 << m), assert(f.at(0)\
    \ == 0);\n    std::vector<T> ret(sz);\n    T *h = ret.data() + sz;\n    const\
    \ T *g = f.data();\n    for (int i = 0; i <= m; i++) ret[sz - (1 << i)] = F[m\
    \ - i];\n    int l = 1, ed = std::min(sz, 1 << 11), j;\n    for (; l < ed; l <<=\
    \ 1)\n      for (j = sz2; j >= l; j >>= 1) conv_na(h - j, g + l, h - j - j + l,\
    \ l);\n    for (; l < sz; l <<= 1)\n      for (j = sz2; j >= l; j >>= 1) conv_tr(h\
    \ - j, g + l, h - j - j + l, l);\n    return ret;\n  }\n  // exp(f) : \"f[\u2205\
    ] = 0\" is required.\n  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ exp(const std::vector<T> &f) {\n    const int sz = f.size();\n    assert(sz\
    \ == 1 << __builtin_ctz(sz)), assert(f.at(0) == 0);\n    std::vector<T> ret(sz);\n\
    \    T *h = ret.data();\n    const T *g = f.data();\n    int l = 1, ed = std::min(sz,\
    \ 1 << 11);\n    for (h[0] = 1; l < ed; l <<= 1) conv_na(h, g + l, h + l, l);\n\
    \    for (; l < sz; l <<= 1) conv_tr(h, g + l, h + l, l);\n    return ret;\n \
    \ }\n  // log(f) : \"f[\u2205] = 1\" is required.\n  template <class T>  // O(n^2\
    \ 2^n)\n  static inline std::vector<T> log(std::vector<T> f) {\n    const int\
    \ sz = f.size(), m = __builtin_ctz(sz);\n    assert(sz == 1 << m), assert(f.at(0)\
    \ == T(1));\n    T F[MAX_N + 1] = {0, 1};\n    for (int i = 2; i <= m; i++) F[i]\
    \ = -F[i - 1] * (i - 1);\n    return f[0] = 0, composite(f, F);\n  }\n  // f^k\n\
    \  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T> pow(std::vector<T>\
    \ f, std::uint64_t k) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n\
    \    assert(sz == 1 << n);\n    T F[MAX_N + 1] = {1}, pw = 1, bs = f[0];\n   \
    \ int i = 1, ed = std::min<std::uint64_t>(n, k);\n    for (; i <= ed; i++) F[i]\
    \ = F[i - 1] * (k - i + 1);\n    for (auto e = k - --i; e; e >>= 1, bs *= bs)\n\
    \      if (e & 1) pw *= bs;\n    for (; i >= 0; i--, pw *= f[0]) F[i] *= pw;\n\
    \    return f[0] = 0, composite(f, F);\n  }\n  // {[X^{[n]}](f^k)/(k!)} for k=0,1,...,n\n\
    \  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T> egf(std::vector<T>\
    \ f) {\n    const int sz = f.size(), n = __builtin_ctz(sz), md = 1 << 11, sz4\
    \ = sz >> 2;\n    assert(sz == 1 << n);\n    if (n == 1) return {0, f[1]};\n \
    \   int l = sz4, m;\n    T *in = f.data() + l, *dp = in + l, tmp[sz4], *dp2;\n\
    \    for (int s; l > md; conv_tr(dp, in, dp, l), in -= (l >>= 1))\n      for (s\
    \ = l, m = sz4; dp2 = dp + (m - l), m > l; m >>= 1, s = l)\n        for (conv_tr(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s] += tmp[s];\n    for (int s; l; conv_na(dp,\
    \ in, dp, l), in -= (l >>= 1))\n      for (s = l, m = sz4; dp2 = dp + (m - l),\
    \ m > l; m >>= 1, s = l)\n        for (conv_na(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s] += tmp[s];\n    std::vector<T> ret(n + 1, 0);\n    for (int i = n + 1;\
    \ --i;) ret[i] = dp[(1 << (n - i)) - 1];\n    return ret;\n  }\n#undef SUBSET_REP\n\
    };\n#line 5 \"test/yosupo/subset_convolution.test.cpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n\
    \  int N;\n  cin >> N;\n  vector<Mint> a(1 << N), b(1 << N);\n  for (auto &ai\
    \ : a) cin >> ai;\n  for (auto &bi : b) cin >> bi;\n  auto c = SetPowerSeries<20>::convolve(a,\
    \ b);\n  for (int i = 0; i < (1 << N); i++) cout << c[i] << \" \\n\"[i + 1 ==\
    \ 1 << N];\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/SetPowerSeries.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint> a(1\
    \ << N), b(1 << N);\n  for (auto &ai : a) cin >> ai;\n  for (auto &bi : b) cin\
    \ >> bi;\n  auto c = SetPowerSeries<20>::convolve(a, b);\n  for (int i = 0; i\
    \ < (1 << N); i++) cout << c[i] << \" \\n\"[i + 1 == 1 << N];\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/SetPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-06-16 15:13:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/subset_convolution.test.cpp
- /verify/test/yosupo/subset_convolution.test.cpp.html
title: test/yosupo/subset_convolution.test.cpp
---
