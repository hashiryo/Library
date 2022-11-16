---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/SetPowerSeries.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570"
  - icon: ':x:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
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
    #line 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\\
    mathbb{Z}$)\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class\
    \ Int>\nconstexpr inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
    \  Int x = 1, y = 0, b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x,\
    \ c = a, x = y, y = z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a\
    \ == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\
    \n/**\n * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category\
    \ \u6570\u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN\
    \ CUT HERE\nnamespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing u128 = __uint128_t;\nclass MIntPro_Montg {\n  u64\
    \ mod, iv, r2;\n  constexpr u64 inv(u64 n, int e = 6, u64 x = 1) {\n    return\
    \ e ? inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n  constexpr inline u64 reduce(const\
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
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB {\n protected:\n\
    \  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate <class mod_pro_t,\
    \ int id>\nstruct RuntimeB {\n  static inline void set_mod(u64 m) { md = mod_pro_t(m);\
    \ }\n\n protected:\n  static inline mod_pro_t md;\n};\ntemplate <class Int, class\
    \ Uint, class B>\nstruct ModInt : public B {\n  static constexpr inline auto modulo()\
    \ { return B::md.modulo(); }\n  constexpr ModInt() : x(0);\n  constexpr ModInt(const\
    \ ModInt &r) : x(r.x) {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt(T v) : ModInt(v.val()) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T n)\n      : x(B::md.set(n < 0 ? modulo() - ((-n) % modulo())\
    \ : n)) {}\n  constexpr ModInt operator-() const { return ModInt() - *this; }\n\
    #define FUNC(name, op)          \\\n  constexpr ModInt name const { \\\n    ModInt\
    \ ret;                 \\\n    return ret.x = op, ret;     \\\n  }\n  FUNC(operator+(const\
    \ ModInt &r), B::md.plus(x, r.x))\n  FUNC(operator-(const ModInt &r), B::md.diff(x,\
    \ r.x))\n  FUNC(operator*(const ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64\
    \ k), math_internal::pow(x, k, B::md))\n#undef FUNC\n  constexpr ModInt operator/(const\
    \ ModInt &r) const { return *this * r.inv(); }\n  constexpr ModInt &operator+=(const\
    \ ModInt &r) { return *this = *this + r; }\n  constexpr ModInt &operator-=(const\
    \ ModInt &r) { return *this = *this - r; }\n  constexpr ModInt &operator*=(const\
    \ ModInt &r) { return *this = *this * r; }\n  constexpr ModInt &operator/=(const\
    \ ModInt &r) { return *this = *this / r; }\n  constexpr bool operator==(const\
    \ ModInt &r) {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr\
    \ bool operator!=(const ModInt &r) { return !(*this == r); }\n  constexpr bool\
    \ operator<(const ModInt &r) {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
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
    \ math_internal::is_staticmodint_v;\n#line 3 \"src/Math/SetPowerSeries.hpp\"\n\
    /**\n * @title \u96C6\u5408\u51AA\u7D1A\u6570\n * @category \u6570\u5B66\n * @see\n\
    \ * https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex\n\
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
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/SetPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-11-16 17:58:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/subset_convolution.test.cpp
- /verify/test/yosupo/subset_convolution.test.cpp.html
title: test/yosupo/subset_convolution.test.cpp
---
