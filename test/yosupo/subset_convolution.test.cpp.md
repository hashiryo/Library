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
    \n */\n\n// BEGIN CUT HERE\nnamespace modint_internal {\nusing namespace std;\n\
    struct modint_base {};\nstruct sta_mint_base : modint_base {};\nstruct dyn_mint_base\
    \ : modint_base {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
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
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  friend ostream &operator<<(ostream\
    \ &os, const D &r) { return os << r.val(); }\n  friend istream &operator>>(istream\
    \ &is, D &r) {\n    long long v;\n    return is >> v, r = D(v), is;\n  }\n};\n\
    template <class B>\nstruct ModInt_Na : public B, public ModIntImpl<ModInt_Na<B>>\
    \ {\n  using Int = typename B::Int;\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, uint32_t>, u64, u128>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod) : n % B::mod)\
    \ {}\n#define ASSIGN(m, p) return x m## = B::mod & -((x p## = r.x) >= B::mod),\
    \ *this\n  constexpr ModInt_Na &operator+=(const ModInt_Na &r) { ASSIGN(-, +);\
    \ }\n  constexpr ModInt_Na &operator-=(const ModInt_Na &r) { ASSIGN(+, -); }\n\
    #undef ASSIGN\n  constexpr ModInt_Na &operator*=(const ModInt_Na &r) {\n    return\
    \ x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr bool operator==(const\
    \ ModInt_Na &r) const { return x == r.x; }\n  constexpr auto val() const { return\
    \ x; }\n\n private:\n  typename B::Uint x = 0;\n};\ntemplate <class B>\nstruct\
    \ ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>> {\n  using Int = int64_t;\n\
    \  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n  constexpr\
    \ ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n  template\
    \ <class T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod - ((-n)\
    \ % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op## = a, x\
    \ += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const mod_t\
    \ &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const mod_t\
    \ &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const mod_t\
    \ &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const mod_t\
    \ &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const {\n  \
    \  u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
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
    #line 3 \"src/Math/SetPowerSeries.hpp\"\n/**\n * @title \u96C6\u5408\u51AA\u7D1A\
    \u6570\n * @category \u6570\u5B66\n * @see\n * https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex\n\
    \ * @see\n * https://notes.sshwy.name/Math/Subset-Power-Series/#%E5%88%86%E6%B2%BB%E5%8D%B7%E7%A7%AF-1\n\
    \ */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n\
    //                        (\u30AA\u30F3\u30E9\u30A4\u30F3\u7573\u8FBC\u307F2 or\
    \ \u5408\u6210 1-\u221A(1-2f))\n// https://loj.ac/p/2340 (\u30AA\u30F3\u30E9\u30A4\
    \u30F3\u7573\u8FBC\u307F)\n// https://atcoder.jp/contests/abc253/tasks/abc253_h\
    \ (egf)\n\n// BEGIN CUT HERE\n\ntemplate <unsigned short MAX_N = 21>\nstruct SetPowerSeries\
    \ {\n#define SUBSET_REP(i, j, n)                           \\\n  for (int _ =\
    \ (n); _ >>= 1;)                         \\\n    for (int __ = 0, _2 = _ << 1;\
    \ __ < (n); __ += _2) \\\n      for (int j = __, i = j | _, ___ = i; j < ___;\
    \ j++, i++)\n  template <typename T>\n  static inline void ranked_zeta_tr(const\
    \ T f[], T ret[][MAX_N + 1],\n                                    const int sz)\
    \ {\n    for (int S = sz, c; S--;)\n      ret[S][c = __builtin_popcount(S)] =\
    \ f[S], std::fill_n(ret[S], c, 0);\n    SUBSET_REP(S, U, sz)\n    for (int d =\
    \ __builtin_popcount(S); d--;) ret[S][d] += ret[U][d];\n  }\n  template <typename\
    \ T>\n  static inline void conv_na(const T f[], const T g[], T ret[], const int\
    \ sz) {\n    for (int s = sz, t; s--;)\n      for (ret[t = s] = f[s] * g[0]; t;\
    \ --t &= s) ret[s] += f[s ^ t] * g[t];\n  }\n  template <typename T>\n  static\
    \ inline void conv_tr(const T f[], const T g[], T ret[], const int sz) {\n   \
    \ static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N + 1];\n    T tmp[MAX_N\
    \ + 1];\n    ranked_zeta_tr(f, F, sz), ranked_zeta_tr(g, G, sz);\n    const int\
    \ n = __builtin_ctz(sz);\n    for (int S = sz, c, d, e, bg; S--;) {\n      c =\
    \ __builtin_popcount(S), bg = std::min(2 * c, n);\n      for (d = bg; d >= c;\
    \ d--)\n        for (tmp[d] = 0, e = d - c; e <= c; e++)\n          tmp[d] +=\
    \ F[S][e] * G[S][d - e];\n      for (d = bg; d >= c; d--) F[S][d] = tmp[d];\n\
    \    }\n    SUBSET_REP(S, U, sz)\n    for (int c = __builtin_popcount(U), d =\
    \ std::min(2 * c, n); d > c; d--)\n      F[S][d] -= F[U][d];\n    for (int S =\
    \ sz; S--;) ret[S] = F[S][__builtin_popcount(S)];\n  }\n  template <typename T,\
    \ class F>\n  static inline void onconv_na(const T g[], T ret[], const F &phi,\n\
    \                               const int sz) {\n    for (int s = 1, t; s < sz;\
    \ phi(s, ret[s]), s++)\n      for (ret[t = s] = 0; t; --t &= s) ret[s] += ret[s\
    \ ^ t] * g[t];\n  }\n  template <typename T, class F>\n  static inline void onconv_tr(const\
    \ T g[], T ret[], const F &phi,\n                               const int sz)\
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
    \ assert(__builtin_popcount(sz) == 1);\n    int I = 1, ed = std::min(1 << 13,\
    \ sz);\n    std::vector<T> ret(sz, 0);\n    for (int s, t, u = 1; I < ed; I <<=\
    \ 1)\n      for (t = s = 0; s < I; phi(u, ret[u]), t = ++s, u++)\n        for\
    \ (ret[u] = 0; t; --t &= s) ret[u] += ret[u ^ t] * ret[t];\n    T *h = ret.data();\n\
    \    for (; I < sz; I <<= 1)\n      phi(I, ret[I]), onconv_tr(\n             \
    \             h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n    return ret;\n\
    \  }\n  // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n  // \"f[\u2205\
    ] = 0\" is required.\n  template <class T, class EGF>  // O(n^2 2^n)\n  static\
    \ inline std::vector<T> composite(const std::vector<T> &f,\n                 \
    \                        const EGF &F) {\n    const int sz = f.size(), m = __builtin_ctz(sz),\
    \ sz2 = sz >> 1;\n    assert(sz == 1 << m), assert(f.at(0) == 0);\n    std::vector<T>\
    \ ret(sz);\n    T *h = ret.data() + sz;\n    const T *g = f.data();\n    for (int\
    \ i = 0; i <= m; i++) ret[sz - (1 << i)] = F[m - i];\n    int l = 1, ed = std::min(sz,\
    \ 1 << 11), j;\n    for (; l < ed; l <<= 1)\n      for (j = sz2; j >= l; j >>=\
    \ 1) conv_na(h - j, g + l, h - j - j + l, l);\n    for (; l < sz; l <<= 1)\n \
    \     for (j = sz2; j >= l; j >>= 1) conv_tr(h - j, g + l, h - j - j + l, l);\n\
    \    return ret;\n  }\n  // exp(f) : \"f[\u2205] = 0\" is required.\n  template\
    \ <class T>  // O(n^2 2^n)\n  static inline std::vector<T> exp(const std::vector<T>\
    \ &f) {\n    const int sz = f.size();\n    assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == 0);\n    T h[sz];\n    const T *g = f.data();\n    int l = 1, ed = std::min(sz,\
    \ 1 << 11);\n    for (h[0] = 1; l < ed; l <<= 1) conv_na(h, g + l, h + l, l);\n\
    \    for (; l < sz; l <<= 1) conv_tr(h, g + l, h + l, l);\n    return std::vector<T>(h,\
    \ h + sz);\n  }\n  // log(f) : \"f[\u2205] = 1\" is required.\n  template <class\
    \ T>  // O(n^2 2^n)\n  static inline std::vector<T> log(const std::vector<T> &f)\
    \ {\n    const int sz = f.size();\n    assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == T(1));\n    int I = 2, ed = std::min(sz, 1 << 13);\n    T h[sz];\n    for\
    \ (std::copy_n(f.begin(), ed, h); I < ed; I <<= 1)\n      for (int s = 1, u =\
    \ s | I; s < I; s++, u++)\n        for (int t = s; t; --t &= s) h[u] -= h[u ^\
    \ t] * f[t];\n    const T *g = f.data();\n    for (; I < sz; I <<= 1)\n      h[I]\
    \ = g[I], onconv_tr(\n                       g, h + I, [&](int s, T &x) { x =\
    \ g[I | s] - x; }, I);\n    return h[0] = 0, std::vector<T>(h, h + sz);\n  }\n\
    \  // f^k\n  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ pow(std::vector<T> f, std::uint64_t k) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n\
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
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<998244353>;\n\
    \  int N;\n  cin >> N;\n  vector<Mint> a(1 << N), b(1 << N);\n  for (auto &ai\
    \ : a) cin >> ai;\n  for (auto &bi : b) cin >> bi;\n  auto c = SetPowerSeries<20>::convolve(a,\
    \ b);\n  for (int i = 0; i < (1 << N); i++) cout << c[i] << \" \\n\"[i + 1 ==\
    \ 1 << N];\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/SetPowerSeries.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint>\
    \ a(1 << N), b(1 << N);\n  for (auto &ai : a) cin >> ai;\n  for (auto &bi : b)\
    \ cin >> bi;\n  auto c = SetPowerSeries<20>::convolve(a, b);\n  for (int i = 0;\
    \ i < (1 << N); i++) cout << c[i] << \" \\n\"[i + 1 == 1 << N];\n  return 0;\n\
    }"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/SetPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-10-28 12:41:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/subset_convolution.test.cpp
- /verify/test/yosupo/subset_convolution.test.cpp.html
title: test/yosupo/subset_convolution.test.cpp
---
