---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':question:'
    path: src/FFT/Polynomial.hpp
    title: "\u591A\u9805\u5F0F"
  - icon: ':question:'
    path: src/FFT/convolve.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  - icon: ':question:'
    path: src/FFT/fps_div.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 div"
  - icon: ':question:'
    path: src/FFT/fps_inv.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 inv"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/composition_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/composition_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/comp_of_FPS.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n *\
    \ @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace modint_internal\
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
    \ 3 \"src/Math/is_prime.hpp\"\n/**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category\
    \ \u6570\u5B66\n *  O(log N)\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n//\
    \ BEGIN CUT HERE\nconstexpr std::uint16_t bsf(std::uint64_t n) {\n  constexpr\
    \ std::uint8_t convert[64] = {\n      0,  1,  2,  53, 3,  7,  54, 27, 4,  38,\
    \ 41, 8,  34, 55, 48, 28,\n      62, 5,  39, 46, 44, 42, 22, 9,  24, 35, 59, 56,\
    \ 49, 18, 29, 11,\n      63, 52, 6,  26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58,\
    \ 17, 10,\n      51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12};\n\
    \  return convert[(n & ~(n - 1)) * 157587932685088877 >> 58];\n}\nconstexpr std::uint64_t\
    \ mul(std::uint64_t x, std::uint64_t y, std::uint64_t m) {\n  return (__uint128_t)x\
    \ * y % m;\n}\ntemplate <std::uint64_t... args>\nconstexpr bool miller_rabin(std::uint64_t\
    \ n) {\n  const std::uint64_t s = bsf(n - 1), d = n >> s;\n  for (auto a : {args...})\
    \ {\n    std::uint64_t b = a % n, p = 1, i = s;\n    for (std::uint64_t k = d,\
    \ x = b;; x = mul(x, x, n))\n      if (k& 1 ? p = mul(p, x, n) : 0; !(k >>= 1))\
    \ break;\n    while (p != 1 && p != n - 1 && b && i--) p = mul(p, p, n);\n   \
    \ if (p != n - 1 && i != s) return false;\n  }\n  return true;\n}\nconstexpr bool\
    \ is_prime(std::uint64_t n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) ==\
    \ 3;\n  if (n < UINT_MAX) return miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n#line 5 \"src/FFT/NTT.hpp\"\
    \n\n/**\n * @title Number-Theoretic-Transform\n * @category FFT\n */\n\n// BEGIN\
    \ CUT HERE\nnamespace ntt_internal {\nusing u64 = std::uint64_t;\nusing u128 =\
    \ __uint128_t;\ntemplate <class mod_t>\nstruct NumberTheoreticTransform {\n  static\
    \ inline void dft(int n, mod_t x[]) {\n    for (int m = n, h = 0, i0 = 0; m >>=\
    \ 1; h = 0, i0 = 0)\n      for (mod_t prod = 1, u; i0 < n; prod *= r2[bsf(++h)],\
    \ i0 += (m << 1))\n        for (int i = i0; i < i0 + m; ++i)\n          x[i +\
    \ m] = x[i] - (u = prod * x[i + m]), x[i] += u;\n  }\n  static inline void idft(int\
    \ n, mod_t x[]) {\n    for (int m = 1, h = 0, i0 = 0; m < n; m <<= 1, h = 0, i0\
    \ = 0)\n      for (mod_t prod = 1, y; i0 < n; prod *= ir2[bsf(++h)], i0 += (m\
    \ << 1))\n        for (int i = i0; i < i0 + m; ++i)\n          y = x[i] - x[i\
    \ + m], x[i] += x[i + m], x[i + m] = prod * y;\n    for (const mod_t iv = mod_t(1)\
    \ / n; n--;) x[n] *= iv;\n  }\n  static void even_dft(int n, mod_t x[]) {\n  \
    \  for (int i = 0, j = 0; i < n; i += 2, j++) x[j] = iv2 * (x[i] + x[i + 1]);\n\
    \  }\n  static void odd_dft(int n, mod_t x[]) {\n    mod_t prod = iv2;\n    for\
    \ (int i = 0, j = 0; i < n; i += 2, j++)\n      x[j] = prod * (x[i] - x[i + 1]),\
    \ prod *= ir2[bsf(~((u64)j))];\n  }\n  static void dft_doubling(int n, mod_t x[])\
    \ {\n    std::copy_n(x, n, x + n), idft(n, x + n);\n    mod_t k(1), t(rt[bsf(n\
    \ << 1)]);\n    for (int i = 0; i < n; i++) x[n + i] *= k, k *= t;\n    dft(n,\
    \ x + n);\n  }\n  static constexpr std::uint64_t lim() { return 1ULL << E; }\n\
    \n protected:\n  static constexpr mod_t pow2th_root(std::uint8_t e) {\n    for\
    \ (mod_t r = 2;; r += 1)\n      if (auto s = r.pow((mod_t::modulo() - 1) / 2);\
    \ s != 1 && s * s == 1)\n        return r.pow((mod_t::modulo() - 1) >> e);\n \
    \   return 0;  // can not find\n  }            // return \u03C9 (primitive 2^e\
    \ th root)\n  static_assert(mod_t::modulo() & 1);\n  static_assert(is_prime(mod_t::modulo()));\n\
    \  static constexpr std::uint8_t E = bsf(mod_t::modulo() - 1);\n  static constexpr\
    \ auto roots(mod_t w) {\n    std::array<mod_t, E + 1> ret = {};\n    for (std::uint8_t\
    \ e = E; e; e--, w *= w) ret[e] = w;\n    return ret[0] = w, ret;\n  }\n  static\
    \ constexpr auto ratios(const std::array<mod_t, E + 1> &rt,\n                \
    \               const std::array<mod_t, E + 1> &irt, int i = 2) {\n    std::array<mod_t,\
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
    \           _Nm <= (1ULL << bsf(T::modulo() - 1));\n}\nconstexpr std::uint32_t\
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
    \ 1) >> 2) >> 4) >> 8) >> 16) + 1;\n}\n#line 4 \"src/FFT/fps_inv.hpp\"\n\n/**\n\
    \ * @title \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 inv\n * @category FFT\n */\n\n\
    // BEGIN CUT HERE\ntemplate <class mod_t, std::size_t LIM>\nmod_t get_inv(int\
    \ n) {\n  static mod_t dat[LIM] = {0, 1};\n  static int l = 2;\n  for (auto m\
    \ = mod_t::modulo(); l <= n;) dat[l++] = dat[m % l] * (m - m / l);\n  return dat[n];\n\
    }\ntemplate <std::size_t _Nm, class mod_t>\nvoid inv_base(const mod_t p[], int\
    \ n, mod_t r[], int i = 1) {\n  using GNA1 = GlobalNTTArray<mod_t, _Nm, 1>;\n\
    \  using GNA2 = GlobalNTTArray<mod_t, _Nm, 2>;\n  static constexpr int TH = 64\
    \ << (!is_nttfriend<mod_t, _Nm>() << 1);\n  if (n <= i) return;\n  assert(((n\
    \ & -n) == n)), assert(i && ((i & -i) == i));\n  const int m = std::min(n, TH);\n\
    \  const mod_t Z = 0, miv = -r[0];\n  for (int j; i < m; r[i++] *= miv)\n    for\
    \ (r[j = i] = Z; j--;) r[i] += r[j] * p[i - j];\n  for (int e = i << 1; i < n;\
    \ e = i << 1) {\n    GNA1::bf.set(r, 0, i), GNA1::bf.zeros(i, e), GNA1::bf.dft(0,\
    \ e);\n    GNA2::bf.set(p, 0, e), GNA2::bf.dft(0, e);\n    GNA2::bf.mul(GNA1::bf,\
    \ 0, e), GNA2::bf.idft(0, e);\n    if constexpr (!is_nttfriend<mod_t, _Nm>())\n\
    \      GNA2::bf.get(r, i, e), GNA2::bf.set(r, i, e);\n    GNA2::bf.zeros(0, i),\
    \ GNA2::bf.dft(0, e), GNA1::bf.mul(GNA2::bf, 0, e);\n    for (GNA1::bf.idft(0,\
    \ e), GNA1::bf.get(r, i, e); i < e; i++) r[i] = -r[i];\n  }\n}\ntemplate <class\
    \ mod_t, std::size_t _Nm = 1 << 22>\nstd::vector<mod_t> inv(const std::vector<mod_t>\
    \ &p) {\n  using GAp = GlobalArray<mod_t, _Nm, 1>;\n  using GAr = GlobalArray<mod_t,\
    \ _Nm, 2>;\n  static constexpr std::size_t _Nm2 = _Nm * 2 / 15;\n  using GNA1\
    \ = GlobalNTTArray<mod_t, _Nm2, 1>;\n  using GNA2 = GlobalNTTArray<mod_t, _Nm2,\
    \ 2>;\n  using GNA2D1 = GlobalNTTArray2D<mod_t, _Nm2, 16, 1>;\n  using GNA2D2\
    \ = GlobalNTTArray2D<mod_t, _Nm2, 16, 2>;\n  static constexpr int TH2 = is_nttfriend<mod_t,\
    \ _Nm2>()\n                                 ? 115\n                          \
    \       : (is_nttarraydouble<mod_t, _Nm2> ? 384 : 452);\n  static constexpr int\
    \ C = nttarray_type<mod_t, _Nm> << 1, lnR = 4;\n  static constexpr int TH3 = 5\
    \ + ((nttarray_type<mod_t, _Nm> == 3) << 1);\n  static constexpr int D = 10 *\
    \ nttarray_type<mod_t, _Nm>;\n  const int n = p.size();\n  assert(n > 0), assert(p[0]\
    \ != mod_t(0));\n  std::copy(p.begin(), p.end(), GAp::bf);\n  mod_t *bfk = GAr::bf,\
    \ *pbfk = GAp::bf;\n  const mod_t Z = 0, miv = -(bfk[0] = mod_t(1) / pbfk[0]);\n\
    \  if (n < TH2) {\n    for (int j, i = 1; i < n; bfk[i++] *= miv)\n      for (bfk[j\
    \ = i] = Z; j--;) bfk[i] += bfk[j] * pbfk[i - j];\n    return std::vector<mod_t>(bfk,\
    \ bfk + n);\n  }\n  const int bl = std::max(bsf(get_len(n)) - lnR, TH3);\n  int\
    \ l = ((n >> bl) + ((((1 << bl) - 1) & n) > (C * bl + D))) << bl;\n  const int\
    \ m = l & -l, m2 = m << 1, ed = (l + m - 1) / m;\n  if (inv_base<_Nm2>(pbfk, m,\
    \ bfk); 1 < ed)\n    GNA2D2::bf[0].set(pbfk, 0, m), GNA2D2::bf[0].zeros(m, m2),\n\
    \        GNA2D2::bf[0].dft(0, m2);\n  for (int k = 1, mm = m; k < ed; mm = std::min(m,\
    \ n - m * ++k)) {\n    GNA2D1::bf[k - 1].set(bfk, 0, m), GNA2D1::bf[k - 1].zeros(m,\
    \ m2);\n    GNA2D1::bf[k - 1].dft(0, m2), GNA1::bf.set(pbfk += m, 0, m);\n   \
    \ GNA1::bf.zeros(m, m2);\n    GNA1::bf.dft(0, m2), GNA2D2::bf[k].add(GNA1::bf,\
    \ GNA2D2::bf[0], 0, m);\n    GNA2D2::bf[k].dif(GNA1::bf, GNA2D2::bf[0], m, m2),\
    \ GNA2::bf.zeros(0, m2);\n    if (k + 1 < ed) GNA2D2::bf[0].subst(GNA1::bf, 0,\
    \ m2);\n    for (int j = k; j--;)\n      GNA1::bf.mul(GNA2D1::bf[j], GNA2D2::bf[k\
    \ - j], 0, m2),\n          GNA2::bf.add(GNA1::bf, 0, m2);\n    GNA2::bf.idft(0,\
    \ m2), GNA2::bf.zeros(m, m2), bfk += m;\n    if constexpr (!is_nttfriend<mod_t,\
    \ _Nm2>())\n      GNA2::bf.get(bfk, 0, m), GNA2::bf.set(bfk, 0, m);\n    GNA2::bf.dft(0,\
    \ m2);\n    GNA2::bf.mul(GNA2D1::bf[0], 0, m2), GNA2::bf.idft(0, m2);\n    for\
    \ (GNA2::bf.get(bfk, 0, mm); mm--;) bfk[mm] = -bfk[mm];\n  }\n  if (l < n)\n \
    \   for (int j; l < n; GAr::bf[l++] *= miv)\n      for (GAr::bf[j = l] = Z; j--;)\
    \ GAr::bf[l] += GAr::bf[j] * GAp::bf[l - j];\n  return std::vector<mod_t>(GAr::bf,\
    \ GAr::bf + n);\n}\n#line 4 \"src/FFT/fps_div.hpp\"\n\n/**\n * @title \u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 div\n * @category FFT\n */\n\n// BEGIN CUT HERE\ntemplate\
    \ <class mod_t, std::size_t _Nm = 1 << 22>\nstd::vector<mod_t> div(const std::vector<mod_t>\
    \ &p,\n                       const std::vector<mod_t> &q) {\n  using GAp = GlobalArray<mod_t,\
    \ _Nm, 0>;\n  using GAq = GlobalArray<mod_t, _Nm, 1>;\n  using GAr = GlobalArray<mod_t,\
    \ _Nm, 2>;\n  using GA = GlobalArray<mod_t, _Nm, 3>;\n  static constexpr std::size_t\
    \ _Nm2 = _Nm * 2 / 15;\n  using GNA1 = GlobalNTTArray<mod_t, _Nm2, 1>;\n  using\
    \ GNA2 = GlobalNTTArray<mod_t, _Nm2, 2>;\n  using GNA3 = GlobalNTTArray<mod_t,\
    \ _Nm2, 3>;\n  using GNA2D1 = GlobalNTTArray2D<mod_t, _Nm2, 16, 1>;\n  using GNA2D2\
    \ = GlobalNTTArray2D<mod_t, _Nm2, 16, 2>;\n  static constexpr int TH = 128 <<\
    \ (!is_nttfriend<mod_t, _Nm2>());\n  static constexpr int TH2 = 1024 << (!is_nttfriend<mod_t,\
    \ _Nm2>());\n  static constexpr int A = is_nttfriend<mod_t, _Nm2>()      ? 7\n\
    \                           : is_nttarraydouble<mod_t, _Nm2> ? 17\n          \
    \                                                  : 18;\n  static constexpr int\
    \ B = is_nttfriend<mod_t, _Nm2>()      ? 29\n                           : is_nttarraydouble<mod_t,\
    \ _Nm2> ? 85\n                                                            : 129;\n\
    \  const int n = p.size(), len = get_len(n), R = len < TH2 ? 8 : 16;\n  const\
    \ int l = q.size(), lnR = bsf(R);\n  std::copy(p.begin(), p.end(), GAp::bf);\n\
    \  std::copy(q.begin(), q.end(), GAq::bf);\n  const mod_t iv0 = mod_t(1) / GAq::bf[0];\n\
    \  if (l < A * bsf(len) + B || TH >= n) {\n    for (int i = 0; i < n; GAp::bf[i++]\
    \ *= iv0)\n      for (int j = std::min(i + 1, l); --j;)\n        GAp::bf[i] -=\
    \ GAp::bf[i - j] * GAq::bf[j];\n    return std::vector<mod_t>(GAp::bf, GAp::bf\
    \ + n);\n  }\n  int m = len, i = 0;\n  while (m > TH) m >>= lnR;\n  for (std::copy_n(GAp::bf,\
    \ m, GAr::bf); i < m; GAr::bf[i++] *= iv0)\n    for (int j = std::min(i + 1, l);\
    \ --j;)\n      GAr::bf[i] -= GAr::bf[i - j] * GAq::bf[j];\n  if (l < n) std::fill(GAq::bf\
    \ + l, GAq::bf + n, mod_t(0));\n  for (GA::bf[0] = iv0, i = 1; m < n; i = m, m\
    \ <<= lnR) {\n    int m2 = m << 1, ed = std::min(R, (n + m - 1) / m), k = 1, j,\
    \ mm = m;\n    inv_base<_Nm2>(GAq::bf, m, GA::bf, i);\n    GNA1::bf.set(GA::bf,\
    \ 0, m), GNA1::bf.zeros(m, m2), GNA1::bf.dft(0, m2);\n    mod_t *bfk = GAr::bf,\
    \ *qbfk = GAq::bf, *pbfk = GAp::bf;\n    GNA2D2::bf[0].set(qbfk, 0, m), GNA2D2::bf[0].zeros(m,\
    \ m2);\n    for (GNA2D2::bf[0].dft(0, m2); k < ed; mm = std::min(m, n - m * ++k))\
    \ {\n      GNA2D1::bf[k - 1].set(bfk, 0, m), GNA2D1::bf[k - 1].zeros(m, m2);\n\
    \      GNA2D1::bf[k - 1].dft(0, m2);\n      GNA3::bf.set(qbfk += m, 0, m), GNA3::bf.zeros(m,\
    \ m2), GNA3::bf.dft(0, m2);\n      GNA2D2::bf[k].add(GNA3::bf, GNA2D2::bf[0],\
    \ 0, m);\n      GNA2D2::bf[k].dif(GNA3::bf, GNA2D2::bf[0], m, m2), GNA2::bf.zeros(0,\
    \ m2);\n      if (k + 1 < ed) GNA2D2::bf[0].subst(GNA3::bf, 0, m2);\n      for\
    \ (j = k; j--;)\n        GNA3::bf.mul(GNA2D1::bf[j], GNA2D2::bf[k - j], 0, m2),\n\
    \            GNA2::bf.add(GNA3::bf, 0, m2);\n      GNA2::bf.idft(0, m2), GNA2::bf.zeros(m,\
    \ m2), pbfk += m;\n      for (GNA2::bf.get(bfk += m, 0, mm), j = mm; j--;) bfk[j]\
    \ -= pbfk[j];\n      GNA2::bf.set(bfk, 0, mm);\n      GNA2::bf.dft(0, m2), GNA2::bf.mul(GNA1::bf,\
    \ 0, m2), GNA2::bf.idft(0, m2);\n      for (GNA2::bf.get(bfk, 0, mm); mm--;) bfk[mm]\
    \ = -bfk[mm];\n    }\n  }\n  return std::vector<mod_t>(GAr::bf, GAr::bf + n);\n\
    }\n#line 4 \"src/FFT/convolve.hpp\"\n\n/**\n * @title \u7573\u307F\u8FBC\u307F\
    \n * @category FFT\n */\n\n// BEGIN CUT HERE\ntemplate <class mod_t, std::size_t\
    \ _Nm = 1 << 22>\nstd::vector<mod_t> convolve(const std::vector<mod_t> &p,\n \
    \                           const std::vector<mod_t> &q) {\n  using GNA1 = GlobalNTTArray<mod_t,\
    \ _Nm, 1>;\n  using GAr = GlobalArray<mod_t, _Nm, 0>;\n  using GAp = GlobalArray<mod_t,\
    \ _Nm, 1>;\n  using GAq = GlobalArray<mod_t, _Nm, 2>;\n  using GNA2 = GlobalNTTArray<mod_t,\
    \ _Nm, 2>;\n  static constexpr int TH = 74, TMP = 7 * nttarray_type<mod_t, _Nm>;\n\
    \  const int n = p.size(), m = q.size(), r_len = n + m - 1;\n  if (!n || !m) return\
    \ std::vector<mod_t>();\n  if (std::min(n, m) < TH) {\n    std::fill_n(GAr::bf,\
    \ r_len, mod_t(0));\n    std::copy(p.begin(), p.end(), GAp::bf);\n    std::copy(q.begin(),\
    \ q.end(), GAq::bf);\n    for (int i = n; i--;)\n      for (int j = m; j--;) GAr::bf[i\
    \ + j] += GAp::bf[i] * GAq::bf[j];\n  } else {\n    const int l = get_len(std::max(n,\
    \ m)),\n              bl = bsf(l) + 2 * nttarray_type<mod_t, _Nm> - 6;\n    const\
    \ int len = r_len - l < bl * bl * TMP - TH ? l : get_len(r_len);\n    GNA1::bf.set(p.data(),\
    \ 0, n), GNA1::bf.zeros(n, len), GNA1::bf.dft(0, len);\n    if (&p == &q)\n  \
    \    GNA1::bf.mul(GNA1::bf, 0, len);\n    else\n      GNA2::bf.set(q.data(), 0,\
    \ m), GNA2::bf.zeros(m, len),\n          GNA2::bf.dft(0, len), GNA1::bf.mul(GNA2::bf,\
    \ 0, len);\n    GNA1::bf.idft(0, len), GNA1::bf.get(GAr::bf, 0, std::min(r_len,\
    \ len));\n    if (len < r_len) {\n      std::copy(p.begin() + len - m + 1, p.end(),\
    \ GAp::bf + len - m + 1);\n      std::copy(q.begin() + len - n + 1, q.end(), GAq::bf\
    \ + len - n + 1);\n      for (int i = len, j; i < r_len; GAr::bf[i - len] -= GAr::bf[i],\
    \ i++)\n        for (GAr::bf[i] = 0, j = i - m + 1; j < n; j++)\n          GAr::bf[i]\
    \ += GAp::bf[j] * GAq::bf[i - j];\n    }\n  }\n  return std::vector<mod_t>(GAr::bf,\
    \ GAr::bf + r_len);\n}\n#line 5 \"src/FFT/Polynomial.hpp\"\n\n/**\n * @title \u591A\
    \u9805\u5F0F\n * @category FFT\n */\n\n// BEGIN CUT HERE\ntemplate <class mod_t,\
    \ std::size_t _Nm = 1 << 22>\nclass Polynomial : public std::vector<mod_t> {\n\
    \  using Poly = Polynomial;\n  struct Inde;\n  struct XP_plus_C {  // x^p+c\n\
    \    Inde x;\n    mod_t c;\n    XP_plus_C(const Inde &x_) : x(x_), c(Z) {}\n \
    \   XP_plus_C(int p_, mod_t c_) : x(p_), c(c_) {}\n  };\n  struct Inde {  // indeterminate\n\
    \    int p_;\n    Inde(int p) : p_(p) {}\n    Inde() : Inde(1) {}\n    Inde operator^(int\
    \ p) const { return Inde(p_ * p); }\n    Inde operator*(const Inde &rhs) const\
    \ { return Inde(p_ + rhs.p_); }\n    int pow() const { return p_; }\n    XP_plus_C\
    \ operator+(mod_t c) { return XP_plus_C(p_, c); }\n    XP_plus_C operator-(mod_t\
    \ c) { return XP_plus_C(p_, -c); }\n  };\n  using GNA1 = GlobalNTTArray<mod_t,\
    \ _Nm, 1>;\n  using GNA2 = GlobalNTTArray<mod_t, _Nm, 2>;\n  using GA = GlobalArray<mod_t,\
    \ _Nm, 0>;\n  using GAp = GlobalArray<mod_t, _Nm, 1>;\n  using GAq = GlobalArray<mod_t,\
    \ _Nm, 2>;\n  using GA3 = GlobalArray<mod_t, _Nm, 3>;\n  static inline const mod_t\
    \ Z = 0;\n  static constexpr int A = is_nttfriend<mod_t, _Nm>()      ? 8\n   \
    \                        : is_nttarraydouble<mod_t, _Nm> ? 17\n              \
    \                                             : 20;\n  static constexpr int B\
    \ = is_nttfriend<mod_t, _Nm>()      ? 42\n                           : is_nttarraydouble<mod_t,\
    \ _Nm> ? 110\n                                                           : 138;\n\
    \  std::pair<Poly, Poly> quorem_na(const Poly &q) const {\n    int n = deg(),\
    \ m = q.deg(), qsz = n - m + 1, i = qsz, j;\n    std::copy_n(this->begin(), n\
    \ + 1, GAp::bf);\n    std::copy_n(q.begin(), m + 1, GAq::bf);\n    for (mod_t\
    \ *bf = GAp::bf + n - m, iv = mod_t(1) / GAq::bf[m]; i--; bf--)\n      for (GA::bf[i]\
    \ = bf[j = m] * iv; j--;) bf[j] -= GAq::bf[j] * GA::bf[i];\n    Poly rem(GAp::bf,\
    \ GAp::bf + m);\n    return {Poly(GA::bf, GA::bf + qsz), rem.shrink()};\n  }\n\
    \  Poly quo(const Poly &q) const {\n    const int n = deg() + 1, m = q.deg() +\
    \ 1, qsz = n - m + 1,\n              nb = this->size() - n, mb = q.size() - m;\n\
    \    auto ret = div<mod_t, _Nm>(\n        Poly(this->rbegin() + nb, this->rbegin()\
    \ + nb + qsz),\n        Poly(q.rbegin() + mb, q.rbegin() + mb + std::min(qsz,\
    \ m)));\n    return std::reverse(ret.begin(), ret.end()), ret;\n  }\n  std::pair<Poly,\
    \ Poly> quorem_ntt(const Poly &q) const {\n    const int n = deg(), m = q.deg(),\
    \ qsz = n - m + 1;\n    auto qu = quo(q);\n    std::copy(qu.begin(), qu.end(),\
    \ GA::bf);\n    std::copy_n(this->begin(), n + 1, GAp::bf);\n    std::copy_n(q.begin(),\
    \ m + 1, GAq::bf);\n    const int len = get_len(m), mask = len - 1;\n    if (len\
    \ > qsz) std::fill_n(GA::bf + qsz, len - qsz, Z);\n    if (len > m + 1) std::fill_n(GAq::bf\
    \ + m + 1, len - m - 1, Z);\n    for (int i = qsz; i-- > len;) GA::bf[i & mask]\
    \ += GA::bf[i];\n    for (int i = n; i >= len; i--) GAp::bf[i & mask] += GAp::bf[i];\n\
    \    if (GNA1::bf.set(GA::bf, 0, len); m == len) GAq::bf[0] += GAq::bf[m];\n \
    \   GNA2::bf.set(GAq::bf, 0, len), GNA1::bf.dft(0, len), GNA2::bf.dft(0, len);\n\
    \    GNA1::bf.mul(GNA2::bf, 0, len), GNA1::bf.idft(0, len);\n    GNA1::bf.get(GAq::bf,\
    \ 0, m);\n    for (int i = m; i--;) GAp::bf[i] -= GAq::bf[i];\n    Poly rem(GAp::bf,\
    \ GAp::bf + m);\n    return std::make_pair(qu, rem.shrink());\n  }\n\n public:\n\
    \  using std::vector<mod_t>::vector;\n  Polynomial(const std::vector<mod_t> &p)\
    \ : Polynomial(p.begin(), p.end()) {}\n  Polynomial(const XP_plus_C &xpc) : Polynomial(xpc.x.pow()\
    \ + 1) {\n    (*this)[xpc.x.pow()] = 1, (*this)[0] = xpc.c;\n  }\n  static Inde\
    \ x() { return Inde(); }\n  inline int deg() const {\n    for (int n = this->size()\
    \ - 1;; n--)\n      if (n < 0 || (*this)[n] != Z) return n;\n  }\n  inline Poly\
    \ &shrink() { return this->resize(std::max(deg() + 1, 1)), *this; }\n#define ASSIGN(op)\
    \                                \\\n  Poly &operator op##=(const Poly &r) { \
    \          \\\n    const std::size_t n = r.deg() + 1;            \\\n    if (this->size()\
    \ < n) this->resize(n);        \\\n    for (int i = n; i--;) (*this)[i] op## =\
    \ r[i]; \\\n    return shrink();                              \\\n  }\n  ASSIGN(+)\n\
    \  ASSIGN(-)\n#undef ASSIGN\n  Poly &operator*=(const Poly &r) { return *this\
    \ = *this * r, *this; }\n  Poly &operator/=(const Poly &r) { return *this = *this\
    \ / r, *this; }\n  Poly &operator%=(const Poly &r) { return *this = *this % r,\
    \ *this; }\n  Poly operator-() const { return Poly() -= *this; }\n  Poly operator+(const\
    \ Poly &r) const { return Poly(*this) += r; }\n  Poly operator-(const Poly &r)\
    \ const { return Poly(*this) -= r; }\n  Poly operator*(const Poly &r) const {\
    \ return convolve<mod_t, _Nm>(*this, r); }\n  Poly operator/(const Poly &r) const\
    \ {\n    const int m = r.deg(), qsz = deg() - m + 1, ln = bsf(get_len(qsz));\n\
    \    assert(m >= 0);\n    if (qsz <= 0) return Poly{Z};\n    return m + 3 < A\
    \ * ln + B || qsz <= 64 ? quorem_na(r).first : quo(r);\n  }\n  std::pair<Poly,\
    \ Poly> quorem(const Poly &r) const {\n    const int n = deg(), m = r.deg(), qsz\
    \ = n - m + 1, ln = bsf(get_len(qsz));\n    assert(m >= 0);\n    if (qsz <= 0)\
    \ return {Poly{Z}, Poly(this->begin(), this->begin() + n + 1)};\n    return m\
    \ < A * ln + B || qsz <= 64 ? quorem_na(r) : quorem_ntt(r);\n  }\n  Poly operator%(const\
    \ Poly &r) const { return quorem(r).second; }\n  Poly &operator+=(const mod_t\
    \ r) { return *this[0] += r, *this; }\n  Poly &operator-=(const mod_t r) { return\
    \ *this[0] -= r, *this; }\n  Poly &operator*=(const mod_t r) {\n    for (mod_t\
    \ &c : *this) c *= r;\n    return shrink();\n  }\n  Poly &operator/=(const mod_t\
    \ r) {\n    for (mod_t &c : *this) c /= r;\n    return shrink();\n  }\n  Poly\
    \ operator+(const mod_t r) { return Poly(*this) += r; }\n  Poly operator-(const\
    \ mod_t r) { return Poly(*this) -= r; }\n  Poly operator*(const mod_t r) { return\
    \ Poly(*this) *= r; }\n  Poly operator/(const mod_t r) { return Poly(*this) /=\
    \ r; }\n  friend Poly operator+(const mod_t l, Poly r) { return r += l; }\n  friend\
    \ Poly operator-(const mod_t l, Poly r) { return -(r -= l); }\n  friend Poly operator*(const\
    \ mod_t l, Poly r) { return r *= l; }\n  mod_t operator()(mod_t c) const {  //\
    \ eval f(c)\n    if (c == Z) return (*this)[0];\n    mod_t ret = 0;\n    for (int\
    \ i = deg() + 1; i--;) ret *= c, ret += (*this)[i];\n    return ret;\n  }\n  Poly\
    \ operator()(const XP_plus_C &xpc) const {  // f(x^p+c)\n    return taylor_shift(xpc.c).scale(xpc.x.pow());\n\
    \  }\n  Poly operator()(const Poly &q) const {  // f(g) mod x^n\n    const int\
    \ n = this->deg() + 1, k = std::ceil(std::sqrt(n));\n    std::vector<Poly> pw1(k\
    \ + 1), pw2(k + 1);\n    if (pw1[0] = {1}, pw1[1] = q; q.size() > n) pw1[1].resize(n);\n\
    \    for (int i = 2; i <= k; ++i)\n      if (pw1[i] = pw1[i - 1] * pw1[1]; pw1[i].size()\
    \ > n) pw1[i].resize(n);\n    pw2[0] = {1}, pw2[1] = pw1[k];\n    for (int i =\
    \ 2; i <= k; ++i)\n      if (pw2[i] = pw2[i - 1] * pw2[1]; pw2[i].size() > n)\
    \ pw2[i].resize(n);\n    Poly ret(n, Z), f;\n    for (int i = 0, j; i <= k; ++i)\
    \ {\n      for (f.assign(n, Z), j = std::min(k, std::max(0, n - k * i)); j--;)\
    \ {\n        mod_t coef = (*this)[k * i + j];\n        for (int d = pw1[j].size();\
    \ d--;) f[d] += pw1[j][d] * coef;\n      }\n      for (f *= pw2[i], j = std::min<int>(n,\
    \ f.size()); j--;) ret[j] += f[j];\n    }\n    return ret;\n  }\n  Poly &operator*=(const\
    \ XP_plus_C &xpc) {\n    Poly q;\n    if (xpc.c != Z) q = *this * xpc.c;\n   \
    \ return this->insert(this->begin(), xpc.x.pow(), Z), *this += q;\n  }\n  Poly\
    \ operator*(const XP_plus_C &xpc) const { return Poly(*this) *= xpc; }\n  friend\
    \ Poly operator*(const XP_plus_C &xpc, const Poly &p) { return p * xpc; }\n  Poly\
    \ scale(int k) const {\n    const int n = deg();\n    Poly ret(n * k + 1, Z);\n\
    \    for (int i = 0; i <= n; i++) ret[i * k] += (*this)[i];\n    return ret;\n\
    \  }\n  Poly taylor_shift(mod_t c) const {\n    int n = deg(), i = 0;\n    if\
    \ (n < 1 || c == Z) return Poly(*this);\n    mod_t cpw = 1, fact = 1;\n    for\
    \ (; i <= n; fact *= ++i) GAp::bf[n - i] = (*this)[i] * fact;\n    for (fact =\
    \ mod_t(1) / fact; i--;) GA3::bf[i] = (fact *= i + 1);\n    for (; ++i <= n;)\
    \ GAq::bf[i] = cpw * GA3::bf[i], cpw *= c;\n    auto ret = Poly(GAp::bf, GAp::bf\
    \ + n + 1) * Poly(GAq::bf, GAq::bf + n + 1);\n    for (ret.resize(n + 1), std::reverse(ret.begin(),\
    \ ret.end()); i--;)\n      ret[i] *= GA3::bf[i];\n    return ret;\n  }\n  friend\
    \ std::ostream &operator<<(std::ostream &os, const Poly &p) {\n    if (p.deg()\
    \ == -1) return os << 0;\n    for (int i = 0, e = p.deg(); i <= e; i++) {\n  \
    \    if (p[i] == Z) continue;\n      if (i == 0 || p[i] != mod_t(1)) os << p[i];\n\
    \      if (i >= 1) os << 'x';\n      if (i > 9)\n        os << \"^(\" << i <<\
    \ ')';\n      else if (i > 1)\n        os << '^' << i;\n      if (i + 1 <= e)\
    \ os << \" + \";\n    }\n    return os;\n  }\n};\n#line 6 \"test/yosupo/comp_of_FPS.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N;\n  cin >> N;\n  Polynomial<Mint>\
    \ a(N), b(N);\n  for (int i = 0; i < N; i++) cin >> a[i];\n  for (int i = 0; i\
    \ < N; i++) cin >> b[i];\n  auto c = a(b);\n  for (int i = 0; i < N; i++) cout\
    \ << c[i] << \" \\n\"[i == N - 1];\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/FFT/Polynomial.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N;\n  cin >> N;\n  Polynomial<Mint>\
    \ a(N), b(N);\n  for (int i = 0; i < N; i++) cin >> a[i];\n  for (int i = 0; i\
    \ < N; i++) cin >> b[i];\n  auto c = a(b);\n  for (int i = 0; i < N; i++) cout\
    \ << c[i] << \" \\n\"[i == N - 1];\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/FFT/Polynomial.hpp
  - src/FFT/fps_div.hpp
  - src/FFT/fps_inv.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  - src/FFT/convolve.hpp
  isVerificationFile: true
  path: test/yosupo/comp_of_FPS.test.cpp
  requiredBy: []
  timestamp: '2022-09-22 22:33:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/comp_of_FPS.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/comp_of_FPS.test.cpp
- /verify/test/yosupo/comp_of_FPS.test.cpp.html
title: test/yosupo/comp_of_FPS.test.cpp
---
