---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/FFT/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/pow_of_FPS.FPS.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\n#include <bits/stdc++.h>\n\
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
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 3 \"src/Math/is_prime.hpp\"\n\
    /**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category \u6570\u5B66\n *  O(log\
    \ N)\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n// BEGIN CUT HERE\nconstexpr\
    \ std::uint64_t mul(std::uint64_t x, std::uint64_t y, std::uint64_t m) {\n  return\
    \ (__uint128_t)x * y % m;\n}\ntemplate <std::uint64_t... args>\nconstexpr bool\
    \ miller_rabin(std::uint64_t n) {\n  const std::uint64_t s = __builtin_ctzll(n\
    \ - 1), d = n >> s;\n  for (auto a : {args...}) {\n    std::uint64_t b = a % n,\
    \ p = 1, i = s;\n    for (std::uint64_t k = d, x = b;; x = mul(x, x, n))\n   \
    \   if (k& 1 ? p = mul(p, x, n) : 0; !(k >>= 1)) break;\n    while (p != 1 &&\
    \ p != n - 1 && b && i--) p = mul(p, p, n);\n    if (p != n - 1 && i != s) return\
    \ false;\n  }\n  return true;\n}\nconstexpr bool is_prime(std::uint64_t n) {\n\
    \  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX) return\
    \ miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022>(n);\n}\n#line 5 \"src/FFT/NTT.hpp\"\n\n/**\n * @title Number-Theoretic-Transform\n\
    \ * @category FFT\n */\n\n// BEGIN CUT HERE\nnamespace ntt_internal {\nusing u64\
    \ = std::uint64_t;\nusing u128 = __uint128_t;\ntemplate <class mod_t>\nstruct\
    \ NumberTheoreticTransform {\n  static inline void dft(int n, mod_t x[]) {\n \
    \   for (int m = n, h = 0, i0 = 0; m >>= 1; h = 0, i0 = 0)\n      for (mod_t prod\
    \ = 1, u; i0 < n;\n           prod *= r2[__builtin_ctz(++h)], i0 += (m << 1))\n\
    \        for (int i = i0; i < i0 + m; ++i)\n          x[i + m] = x[i] - (u = prod\
    \ * x[i + m]), x[i] += u;\n  }\n  static inline void idft(int n, mod_t x[]) {\n\
    \    for (int m = 1, h = 0, i0 = 0; m < n; m <<= 1, h = 0, i0 = 0)\n      for\
    \ (mod_t prod = 1, y; i0 < n;\n           prod *= ir2[__builtin_ctz(++h)], i0\
    \ += (m << 1))\n        for (int i = i0; i < i0 + m; ++i)\n          y = x[i]\
    \ - x[i + m], x[i] += x[i + m], x[i + m] = prod * y;\n    for (const mod_t iv\
    \ = mod_t(1) / n; n--;) x[n] *= iv;\n  }\n  static void even_dft(int n, mod_t\
    \ x[]) {\n    for (int i = 0, j = 0; i < n; i += 2, j++) x[j] = iv2 * (x[i] +\
    \ x[i + 1]);\n  }\n  static void odd_dft(int n, mod_t x[]) {\n    mod_t prod =\
    \ iv2;\n    for (int i = 0, j = 0; i < n; i += 2, j++)\n      x[j] = prod * (x[i]\
    \ - x[i + 1]), prod *= ir2[__builtin_ctzll(~((u64)j))];\n  }\n  static void dft_doubling(int\
    \ n, mod_t x[]) {\n    std::copy_n(x, n, x + n), idft(n, x + n);\n    mod_t k(1),\
    \ t(rt[__builtin_ctz(n << 1)]);\n    for (int i = 0; i < n; i++) x[n + i] *= k,\
    \ k *= t;\n    dft(n, x + n);\n  }\n  static constexpr std::uint64_t lim() { return\
    \ 1ULL << E; }\n\n protected:\n  static constexpr mod_t pow2th_root(std::uint8_t\
    \ e) {\n    for (mod_t r = 2;; r += 1)\n      if (auto s = r.pow((mod_t::modulo()\
    \ - 1) / 2); s != 1 && s * s == 1)\n        return r.pow((mod_t::modulo() - 1)\
    \ >> e);\n    return 0;  // can not find\n  }            // return \u03C9 (primitive\
    \ 2^e th root)\n  static_assert(mod_t::modulo() & 1);\n  static_assert(is_prime(mod_t::modulo()));\n\
    \  static constexpr std::uint8_t E = __builtin_ctzll(mod_t::modulo() - 1);\n \
    \ static constexpr auto roots(mod_t w) {\n    std::array<mod_t, E + 1> ret = {};\n\
    \    for (std::uint8_t e = E; e; e--, w *= w) ret[e] = w;\n    return ret[0] =\
    \ w, ret;\n  }\n  static constexpr auto ratios(const std::array<mod_t, E + 1>\
    \ &rt,\n                               const std::array<mod_t, E + 1> &irt, int\
    \ i = 2) {\n    std::array<mod_t, E - 1> ret = {};\n    for (mod_t prod = 1; i\
    \ <= E; prod *= irt[i++]) ret[i - 2] = rt[i] * prod;\n    return ret;\n  }\n \
    \ static constexpr mod_t w = pow2th_root(E), iw = w.pow(lim() - 1);\n  static\
    \ constexpr mod_t iv2 = mod_t((mod_t::modulo() + 1) / 2);\n  static_assert(w !=\
    \ mod_t(0));\n  static constexpr auto rt = roots(w), irt = roots(iw);\n  static\
    \ constexpr auto r2 = ratios(rt, irt), ir2 = ratios(irt, rt);\n};\ntemplate <class\
    \ T, class B>\nstruct NTTArrayImpl : public B {\n  using B::B;\n  static constexpr\
    \ std::uint8_t type() { return B::type; }\n#define FUNC(op, name, HOGEHOGE, ...)\
    \            \\\n  inline void name(__VA_ARGS__) {                \\\n    HOGEHOGE(op,\
    \ 1);                             \\\n    if constexpr (B::type >= 2) HOGEHOGE(op,\
    \ 2); \\\n    if constexpr (B::type >= 3) HOGEHOGE(op, 3); \\\n  }\n#define DFT(fft,\
    \ _) B::ntt##_::fft(e - b, this->dat##_ + b)\n#define ZEROS(op, _) std::fill_n(this->dat##_\
    \ + b, e - b, B::Z##_)\n#define SET(op, _) std::copy(x + b, x + e, this->dat##_\
    \ + b)\n#define SET_SINGLE(op, _) this->dat##_[i] = x;\n#define SUBST(op, _) std::copy(r.dat##_\
    \ + b, r.dat##_ + e, this->dat##_ + b)\n  FUNC(dft, dft, DFT, int b, int e)\n\
    \  FUNC(idft, idft, DFT, int b, int e)\n  FUNC(__, zeros, ZEROS, int b, int e)\n\
    \  FUNC(__, set, SET, const T x[], int b, int e)\n  FUNC(__, set, SET_SINGLE,\
    \ int i, T x)\n  template <class C>\n  FUNC(__, subst, SUBST, const NTTArrayImpl<T,\
    \ C> &r, int b, int e)\n  inline void get(T x[], int b, int e) const {\n    if\
    \ constexpr (B::type == 1)\n      std::copy(this->dat1 + b, this->dat1 + e, x\
    \ + b);\n    else\n      for (int i = b; i < e; i++) x[i] = get(i);\n  }\n  inline\
    \ T get(int i) const {\n    if constexpr (B::type == 3) {\n      const T mod1\
    \ = B::mint1::modulo(), mod2 = B::mint2::modulo();\n      u64 r1 = this->dat1[i].val(),\
    \ r2 = (B::iv21 * (this->dat2[i] - r1)).val();\n      u64 r3 = (B::iv31 * (this->dat3[i]\
    \ - r1) - B::iv32 * r2).val();\n      return mod1 * (mod2 * r3 + r2) + r1;\n \
    \   } else if constexpr (B::type == 2) {\n      const T mod1 = B::mint1::modulo();\n\
    \      u64 r1 = this->dat1[i].val();\n      return mod1 * ((this->dat2[i] - r1)\
    \ * B::iv).val() + r1;\n    } else\n      return this->dat1[i];\n  }\n#define\
    \ ASGN(op, _) \\\n  for (int i = b; i < e; i++) this->dat##_[i] op## = r.dat##_[i]\n\
    #define ASSIGN(fname, op) \\\n  template <class C>      \\\n  FUNC(op, fname,\
    \ ASGN, const NTTArrayImpl<T, C> &r, int b, int e)\n#define BOP(op, _) \\\n  for\
    \ (int i = b; i < e; i++) this->dat##_[i] = l.dat##_[i] op r.dat##_[i]\n#define\
    \ OP(fname, op)                               \\\n  template <class C, class D>\
    \                       \\\n  FUNC(op, fname, BOP, const NTTArrayImpl<T, C> &l,\
    \ \\\n       const NTTArrayImpl<T, D> &r, int b, int e)\n  OP(add, +) OP(dif,\
    \ -) OP(mul, *) ASSIGN(add, +) ASSIGN(dif, -) ASSIGN(mul, *)\n#undef DFT\n#undef\
    \ ZEROS\n#undef SET\n#undef SET_SINGLE\n#undef SUBST\n#undef ASGN\n#undef ASSIGN\n\
    #undef BOP\n#undef OP\n#undef FUNC\n};\ntemplate <class T, std::size_t _Nm>\n\
    struct NTTArrayB_SingleB {\n  using ntt1 = NumberTheoreticTransform<T>;\n  static_assert(_Nm\
    \ <= ntt1::lim());\n  static constexpr T Z1 = 0;\n  static constexpr std::uint8_t\
    \ type = 1;\n};\ntemplate <class T, std::size_t _Nm, bool is_heap>\nstruct NTTArrayB_Single\
    \ : protected NTTArrayB_SingleB<T, _Nm> {\n  T dat1[_Nm] = {};\n};\ntemplate <class\
    \ T, std::size_t _Nm>\nstruct NTTArrayB_Single<T, _Nm, true> : protected NTTArrayB_SingleB<T,\
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
    \ <class T>\nconstexpr u64 max_value() {\n  if constexpr (is_dynamicmodint_v<T>)\n\
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
    \ 1) >> 2) >> 4) >> 8) >> 16) + 1;\n}\n#line 4 \"src/FFT/FormalPowerSeries.hpp\"\
    \n\n/**\n * @title \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @category FFT\n *\
    \ @see https://hly1204.github.io/library/math/formal_power_series.hpp\n */\n\n\
    // verify\u7528:\n// https://loj.ac/p/6538\n\n// BEGIN CUT HERE\ntemplate <class\
    \ T, std::size_t _Nm = 1 << 22>\nclass RelaxedConvolution {\n  std::vector<T>\
    \ a, b, c;\n  std::vector<NTTArray<T, _Nm, true>> ac, bc;\n  std::function<T()>\
    \ ha, hb;\n  int n;\n  template <class T0>\n  static auto wrap(T0 &&f, int &n,\
    \ const std::vector<T> &c, std::vector<T> &e) {\n    if constexpr (std::is_invocable_r_v<T,\
    \ T0, int, const std::vector<T> &>) {\n      return std::bind(\n          [f](int\
    \ n, const std::vector<T> &c, std::vector<T> &e) mutable {\n            return\
    \ T(e.emplace_back(f(n, c)));\n          },\n          std::cref(n), std::cref(c),\
    \ std::ref(e));\n    } else if constexpr (std::is_invocable_r_v<T, T0, int>) {\n\
    \      return std::bind(\n          [f](int n, std::vector<T> &e) mutable {\n\
    \            return T(e.emplace_back(f(n)));\n          },\n          std::cref(n),\
    \ std::ref(e));\n    } else if constexpr (std::is_invocable_r_v<T, T0>) {\n  \
    \    return std::bind(\n          [f](std::vector<T> &e) mutable { return T(e.emplace_back(f()));\
    \ },\n          std::ref(e));\n    } else\n      throw;\n  }\n\n public:\n  template\
    \ <class F1, class F2>\n  RelaxedConvolution(F1 &&h1, F2 &&h2)\n      : c(4),\
    \ ha(wrap(h1, n, c, a)), hb(wrap(h2, n, c, b)), n(0) {\n    a.reserve(_Nm), b.reserve(_Nm),\
    \ c.reserve(_Nm);\n  }\n  const std::vector<T> &multiplicand() const { return\
    \ a; }\n  const std::vector<T> &multiplier() const { return b; }\n  T at(int k)\
    \ { return (*this)[k]; }\n  T operator[](int k) {\n    while (n <= k) next();\n\
    \    return c[k];\n  }\n  T next() {\n    using GNA1 = GlobalNTTArray<T, _Nm,\
    \ 1>;\n    using GNA2 = GlobalNTTArray<T, _Nm, 2>;\n    static constexpr int BASE_CASE_SIZE\
    \ = 32;\n    if (int l = get_len(n << 1 | 1); (int)c.size() < l) c.resize(l);\n\
    \    if (n == 0) c[0] = ha() * hb();\n    if (n == 1) c[1] = ha() * b[0] + a[0]\
    \ * hb(), c[2] = a[1] * b[1];\n    if (n == 2)\n      c[2] += ha() * b[0] + a[0]\
    \ * hb(), c[3] = a[2] * b[1] + a[1] * b[2];\n    if (n > 2) {\n      if (!(n &\
    \ (n - 1))) {\n        int t0 = n >> 1, t1 = n;\n        auto &c0 = ac.emplace_back(),\
    \ &c1 = bc.emplace_back();\n        c0.resize(t1), c0.set(a.data() + t0, 0, t0),\
    \ c0.dft(0, t1);\n        c1.resize(t1), c1.set(b.data() + t0, 0, t0), c1.dft(0,\
    \ t1);\n        GNA1::bf.mul(c0, c1, 0, t1), GNA1::bf.idft(0, t1);\n        for\
    \ (int i = t1 - 1; i--;) c[t1 + i] += GNA1::bf.get(i);\n      }\n      c[n] +=\
    \ ha() * b[0] + a[0] * hb(), c[n + 1] += a[1] * b[n] + a[n] * b[1];\n      for\
    \ (int t0 = 2, sft = 0, ofs = get_len(n + 1) >> 1, t = n + 1 - ofs;\n        \
    \   !(t & 1) && t0 < ofs; t0 <<= 1, sft++, t >>= 1)\n        if (int m = n + 1\
    \ - t0, t1 = t0 << 1; t0 > BASE_CASE_SIZE) {\n          GNA1::bf.set(a.data()\
    \ + m, 0, t0), GNA1::bf.zeros(t0, t1);\n          GNA2::bf.set(b.data() + m, 0,\
    \ t0), GNA2::bf.zeros(t0, t1);\n          GNA1::bf.dft(0, t1), GNA2::bf.dft(0,\
    \ t1);\n          GNA1::bf.mul(bc[sft], 0, t1), GNA2::bf.mul(ac[sft], 0, t1);\n\
    \          GNA1::bf.add(GNA2::bf, 0, t1), GNA1::bf.idft(0, t1);\n          for\
    \ (int i = t1 - 1; i--;) c[n + 1 + i] += GNA1::bf.get(i);\n        } else\n  \
    \        for (int i = t0; i--;)\n            for (int j = t0; j--;)\n        \
    \      c[n + 1 + i + j] += a[m + i] * b[j + t0] + a[j + t0] * b[m + i];\n    }\n\
    \    return c[n++];\n  }\n};\ntemplate <class mod_t, std::size_t _Nm = 1 << 22>\n\
    class FormalPowerSeries {\n  using F = std::function<mod_t(int)>;\n  using FPS\
    \ = FormalPowerSeries;\n  F h_;\n\n public:\n  class Resetter {\n    std::shared_ptr<F>\
    \ p_;\n\n   public:\n    Resetter() {}\n    Resetter(std::shared_ptr<F> p) : p_(p)\
    \ {}\n    void set(const FPS &rhs) { *p_ = rhs.handle(); }\n  };\n  class Inde\
    \ {  // indeterminate\n    int p_;\n\n   public:\n    Inde(int p) : p_(p) {}\n\
    \    Inde() : Inde(1) {}\n    Inde operator^(int p) const { return Inde(p_ * p);\
    \ }\n    Inde operator*(const Inde &rhs) const { return Inde(p_ + rhs.p_); }\n\
    \    int pow() const { return p_; }\n  };\n  FormalPowerSeries() : h_([](int)\
    \ { return mod_t(0); }) {}\n  FormalPowerSeries(F f)\n      : h_([f, cache = std::make_shared<std::vector<mod_t>>()](int\
    \ k) -> mod_t {\n          for (int i = (int)cache->size(); i <= k; ++i)\n   \
    \         cache->emplace_back(f(i));\n          return cache->at(k);\n       \
    \ }) {}\n  FormalPowerSeries(const std::vector<mod_t> &coef)\n      : h_([cache\
    \ =\n                std::make_shared<std::vector<mod_t>>(coef)](int k) -> mod_t\
    \ {\n          return k < (int)cache->size() ? cache->at(k) : mod_t(0);\n    \
    \    }) {}\n  FormalPowerSeries(mod_t v)\n      : h_([v](int k) { return k ==\
    \ 0 ? v : mod_t(0); }) {}\n  F handle() const { return h_; }\n  static Inde x()\
    \ { return Inde(); }\n  Resetter reset() {\n    auto p = std::make_shared<F>();\n\
    \    return h_ = [p](int i) { return (*p)(i); }, Resetter(p);\n  }\n  mod_t operator[](int\
    \ k) const { return h_(k); }\n  FPS operator()(const Inde &rhs) const { return\
    \ scale(rhs.pow()); }\n  FPS operator*(const Inde &rhs) const { return shift(rhs.pow());\
    \ }\n  FPS operator*(const mod_t &rhs) const {\n    return FPS([h = h_, v = rhs](int\
    \ i) { return h(i) * v; });\n  }\n  FPS operator/(const mod_t &rhs) const {  //\
    \ `rhs == 0` is not allowed\n    return FPS([h = h_, v = mod_t(1) / rhs](int i)\
    \ { return h(i) * v; });\n  }\n  FPS operator+(const mod_t &rhs) const {\n   \
    \ return FPS([h = h_, v = rhs](int i) { return i ? h(i) : h(i) + v; });\n  }\n\
    \  FPS operator-(const mod_t &rhs) const {\n    return FPS([h = h_, v = rhs](int\
    \ i) { return i ? h(i) : h(i) - v; });\n  }\n  friend FPS operator*(const Inde\
    \ &lhs, const FPS &rhs) {\n    return rhs.shift(lhs.pow());\n  }\n  friend FPS\
    \ operator-(const mod_t &lhs, const FPS &rhs) {\n    return FPS([h = rhs.h_, v\
    \ = lhs](int i) { return i ? -h(i) : v - h(i); });\n  }\n  friend FPS operator+(const\
    \ mod_t &lhs, const FPS &rhs) {\n    return FPS([h = rhs.h_, v = lhs](int i) {\
    \ return i ? h(i) : h(i) + v; });\n  }\n  friend FPS operator*(const mod_t &lhs,\
    \ const FPS &rhs) {\n    return FPS([h = rhs.h_, v = lhs](int i) { return h(i)\
    \ * v; });\n  }\n  friend FPS operator/(const mod_t &lhs, const FPS &rhs) {\n\
    \    return lhs * rhs.inv();\n  }\n  FPS scale(int k) const {\n    return FPS([h\
    \ = h_, k](int i) { return i % k ? mod_t(0) : h(i / k); });\n  }\n  FPS shift(int\
    \ k) const {\n    return FPS([h = h_, k](int i) { return i < k ? mod_t(0) : h(i\
    \ - k); });\n  }\n  FPS inv() const {\n    auto rc = std::make_shared<RelaxedConvolution<mod_t,\
    \ _Nm>>(\n        [h = h_](int i) { return h(i); },\n        [h = h_, iv = mod_t()](int\
    \ i, const auto &c) mutable {\n          return i ? -(c[i] + h(i) * iv) * iv :\
    \ (iv = mod_t(1) / h(0));\n        });\n    return FPS(\n        [rc](int i) {\
    \ return rc->next(), rc->multiplier()[i]; });  // safe\n  }\n  friend FPS deriv(const\
    \ FPS &fps) {\n    return FPS([h = fps.h_](int i) { return h(i + 1) * mod_t(i\
    \ + 1); });\n  }\n  friend FPS integ(const FPS &fps) {\n    return FPS([h = fps.h_](int\
    \ i) {\n      return i ? h(i - 1) * get_inv<mod_t, _Nm>(i) : mod_t(0);\n    });\n\
    \  }\n  // `fps[0]==1` is required\n  friend FPS log(const FPS &fps) { return\
    \ integ(deriv(fps) / fps); }\n  friend FPS exp(const FPS &fps) {  // `fps[0]==0`\
    \ is required\n    auto rc = std::make_shared<RelaxedConvolution<mod_t, _Nm>>(\n\
    \        [h = fps.h_](int i) { return h(i + 1) * mod_t(i + 1); },\n        [](int\
    \ i, const auto &c) {\n          return i ? c[i - 1] * get_inv<mod_t, _Nm>(i)\
    \ : mod_t(1);\n        });\n    return FPS([rc](int i) {\n      return i ? rc->at(i\
    \ - 1) * get_inv<mod_t, _Nm>(i) : mod_t(1);\n    });\n  }\n  friend FPS pow(const\
    \ FPS &fps, std::uint64_t k) {\n    if (!k) return FPS(1);\n    return FPS([h\
    \ = fps.h_, kk = mod_t(k), k, cnt = 0ull,\n                s = std::optional<std::function<mod_t(int)>>()](int\
    \ i) mutable {\n      if (s) return (std::uint64_t)i < cnt ? mod_t(0) : (*s)(i\
    \ - (int)cnt);\n      mod_t v = h(i);\n      if (v == mod_t(0)) return cnt++,\
    \ mod_t(0);\n      cnt *= k;\n      FPS t0([os = i, iv = mod_t(1) / v, h](int\
    \ i) { return h(i + os) * iv; });\n      FPS t1([h0 = log(t0).handle(), kk](int\
    \ i) { return h0(i) * kk; });\n      s.emplace(\n          [vk = v.pow(k), h1\
    \ = exp(t1).handle()](int i) { return h1(i) * vk; });\n      return cnt ? mod_t(0)\
    \ : (*s)(i);\n    });\n  }\n  friend FPS SEQ(const FPS &fps) {  // SEQUENCE `fps[0]==0`\
    \ is required\n    return FPS([h = fps.h_](int i) { return i == 0 ? mod_t(1) :\
    \ -h(i); }).inv();\n  }\n  friend FPS MSET(const FPS &fps) {  // MULTISET `fps[0]==0`\
    \ is required\n    return exp(FPS([h = fps.h_,\n                    cache = std::make_shared<std::vector<mod_t>>()](int\
    \ i) {\n      if (i == 0) return mod_t(0);\n      if ((i & (i - 1)) == 0) {\n\
    \        cache->resize(i * 2, mod_t(0));\n        for (int j = 1; j < i; ++j)\
    \ {\n          mod_t hj = h(j);\n          for (int k = (i + j - 1) / j, ed =\
    \ (i * 2 + j - 1) / j; k < ed; k++)\n            cache->at(j * k) += hj * get_inv<mod_t,\
    \ _Nm>(k);\n        }\n      }\n      return mod_t(cache->at(i) += h(i));\n  \
    \  }));\n  }\n  friend FPS PSET(const FPS &fps) {  //  POWERSET `fps[0]==0` is\
    \ required\n    return exp(FPS([h = fps.h_,\n                    cache = std::make_shared<std::vector<mod_t>>()](int\
    \ i) {\n      if (i == 0) return mod_t(0);\n      if ((i & (i - 1)) == 0) {\n\
    \        cache->resize(i * 2, mod_t(0));\n        for (int j = 1; j < i; ++j)\
    \ {\n          mod_t hj = h(j);\n          for (int k = (i + j - 1) / j, ed =\
    \ (i * 2 + j - 1) / j; k < ed; k++)\n            if (k & 1)\n              cache->at(j\
    \ * k) += hj * get_inv<mod_t, _Nm>(k);\n            else\n              cache->at(j\
    \ * k) -= hj * get_inv<mod_t, _Nm>(k);\n        }\n      }\n      return mod_t(cache->at(i)\
    \ += h(i));\n    }));\n  };\n  FPS operator+(const FPS &rhs) const {\n    return\
    \ FPS([h0 = h_, h1 = rhs.h_](int i) { return h0(i) + h1(i); });\n  }\n  FPS operator-(const\
    \ FPS &rhs) const {\n    return FPS([h0 = h_, h1 = rhs.h_](int i) { return h0(i)\
    \ - h1(i); });\n  }\n  FPS operator-() const {\n    return FPS([h = h_](int i)\
    \ { return -h(i); });\n  }\n  FPS operator*(const FPS &rhs) const {\n    auto\
    \ rc = std::make_shared<RelaxedConvolution<mod_t, _Nm>>(\n        [h = h_](int\
    \ i) { return h(i); }, [h = rhs.h_](int i) { return h(i); });\n    return FPS([rc](int)\
    \ { return rc->next(); });\n  }\n  FPS operator/(const FPS &rhs) const {\n   \
    \ auto rc = std::make_shared<RelaxedConvolution<mod_t, _Nm>>(\n        [h = rhs.h_](int\
    \ i) { return h(i); },\n        [h0 = h_, h1 = rhs.h_, iv = mod_t(), t0 = mod_t()](\n\
    \            int i, const auto &c) mutable {\n          if (i == 0) return t0\
    \ = h0(0) * (iv = mod_t(1) / h1(0));\n          return (h0(i) - h1(i) * t0 - c[i])\
    \ * iv;\n        });\n    return FPS([rc](int i) { return rc->next(), rc->multiplier()[i];\
    \ });\n  }\n};\n#line 5 \"test/yosupo/pow_of_FPS.FPS.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  using Mint = StaticModInt<998244353>;\n  using FPS\
    \ = FormalPowerSeries<Mint>;\n  long long N, M;\n  cin >> N >> M;\n  std::vector<Mint>\
    \ A(N);\n  for (int i = 0; i < N; i++) cin >> A[i];\n  auto ans = pow(FPS(A),\
    \ M);\n  for (int i = 0; i < N; i++) cout << ans[i] << \" \\n\"[i == N - 1];\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/FFT/FormalPowerSeries.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  using Mint = StaticModInt<998244353>;\n\
    \  using FPS = FormalPowerSeries<Mint>;\n  long long N, M;\n  cin >> N >> M;\n\
    \  std::vector<Mint> A(N);\n  for (int i = 0; i < N; i++) cin >> A[i];\n  auto\
    \ ans = pow(FPS(A), M);\n  for (int i = 0; i < N; i++) cout << ans[i] << \" \\\
    n\"[i == N - 1];\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/FFT/FormalPowerSeries.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/pow_of_FPS.FPS.test.cpp
  requiredBy: []
  timestamp: '2022-11-08 16:52:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/pow_of_FPS.FPS.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/pow_of_FPS.FPS.test.cpp
- /verify/test/yosupo/pow_of_FPS.FPS.test.cpp.html
title: test/yosupo/pow_of_FPS.FPS.test.cpp
---