---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':question:'
    path: src/FFT/fps_inv.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 inv"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u6839 ($\\mathbb{F}_p$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/sqrt_of_FPS.test.cpp
    title: test/yosupo/sqrt_of_FPS.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 sqrt"
    links: []
  bundledCode: "#line 2 \"src/FFT/fps_sqrt.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n * @title ModInt\u306E\u30D7\u30ED\u30C8\
    \u30BF\u30A4\u30D7\n * @category \u6570\u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\
    \u3068\u304B\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\n\
    struct MIntPro_Montg {\n  const u64 mod;\n  constexpr MIntPro_Montg() : mod(0),\
    \ iv(0), r2(0) {}\n  constexpr MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod)\
    \ % mod) {}\n  constexpr inline u64 mul(u64 l, u64 r) const { return reduce(u128(l)\
    \ * r); }\n#define BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n\
    \  constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n\
    \  constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n\
    \  constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline\
    \ u64 get(u64 n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n -\
    \ (mod & -(n >= mod)); }\n\n private:\n  const u64 iv, r2;\n  constexpr u64 inv(u64\
    \ n, int e = 6, u64 x = 1) {\n    return e ? inv(n, e - 1, x * (2 - x * n)) :\
    \ x;\n  }\n  constexpr inline u64 reduce(const u128 &w) const {\n    return u64(w\
    \ >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\n  }\n};\ntemplate <class\
    \ Uint>\nclass MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint, u32>,\
    \ u64, u128>;\n\n public:\n  const Uint mod;\n  constexpr MIntPro_Na() : mod(0){};\n\
    \  constexpr MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint\
    \ l, Uint r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l\
    \ m## = mod & -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint\
    \ r) const { BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const\
    \ { BOP(+, -); }\n#undef BOP\n  static constexpr inline Uint set(Uint n) { return\
    \ n; }\n  static constexpr inline Uint get(Uint n) { return n; }\n  static constexpr\
    \ inline Uint norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t>\n\
    constexpr Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 4 \"src/Math/is_prime.hpp\"\n\
    /**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category \u6570\u5B66\n *  O(log\
    \ N)\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\ntemplate <class Uint,\
    \ class mod_pro_t, u64... args>\nconstexpr bool miller_rabin(Uint n) {\n  const\
    \ mod_pro_t md(n);\n  const Uint s = __builtin_ctzll(n - 1), d = n >> s, one =\
    \ md.set(1),\n             n1 = md.norm(md.set(n - 1));\n  for (auto a : {args...})\
    \ {\n    Uint b = a % n, p = pow(md.set(b), d, md), i = s;\n    while (p = md.norm(p),\
    \ (p != one && p != n1 && b && i--)) p = md.mul(p, p);\n    if (md.norm(p) !=\
    \ n1 && i != s) return false;\n  }\n  return true;\n}\nconstexpr bool is_prime(u64\
    \ n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX)\
    \ return miller_rabin<u32, MIntPro_Na<u32>, 2, 7, 61>(n);\n  if (n < LLONG_MAX)\n\
    \    return miller_rabin<u64, MIntPro_Montg, 2, 325, 9375, 28178, 450775,\n  \
    \                      9780504, 1795265022>(n);\n  return miller_rabin<u64, MIntPro_Na<u64>,\
    \ 2, 325, 9375, 28178, 450775,\n                      9780504, 1795265022>(n);\n\
    }\n}  // namespace math_internal\nusing math_internal::is_prime;\n#line 3 \"src/Math/mod_inv.hpp\"\
    \n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\
    \u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0,\
    \ b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y =\
    \ z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ?\
    \ mod - (-x) % mod : x % mod;\n}\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n * @title\
    \ ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace math_internal\
    \ {\nstruct modint_base {};\nstruct sta_mint_base : modint_base {};\nstruct run_mint_base\
    \ : modint_base {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class U, class B>\nstruct ModInt : public B {\n\
    \  using Uint = U;\n  static constexpr inline auto modulo() { return B::md.mod;\
    \ }\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x)\
    \ {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T v) : x(B::md.set(v.val() % B::md.mod)) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T n)\n      : x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod\
    \ : n % B::md.mod))) {}\n  constexpr ModInt operator-() const { return ModInt()\
    \ - *this; }\n#define FUNC(name, op)          \\\n  constexpr ModInt name const\
    \ { \\\n    ModInt ret;                 \\\n    return ret.x = op, ret;     \\\
    \n  }\n  FUNC(operator+(const ModInt &r), B::md.plus(x, r.x))\n  FUNC(operator-(const\
    \ ModInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const ModInt &r), B::md.mul(x,\
    \ r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n#undef FUNC\n  constexpr\
    \ ModInt operator/(const ModInt &r) const { return *this * r.inv(); }\n  constexpr\
    \ ModInt &operator+=(const ModInt &r) { return *this = *this + r; }\n  constexpr\
    \ ModInt &operator-=(const ModInt &r) { return *this = *this - r; }\n  constexpr\
    \ ModInt &operator*=(const ModInt &r) { return *this = *this * r; }\n  constexpr\
    \ ModInt &operator/=(const ModInt &r) { return *this = *this / r; }\n  constexpr\
    \ bool operator==(const ModInt &r) const {\n    return B::md.norm(x) == B::md.norm(r.x);\n\
    \  }\n  constexpr bool operator!=(const ModInt &r) const { return !(*this == r);\
    \ }\n  constexpr bool operator<(const ModInt &r) const {\n    return B::md.norm(x)\
    \ < B::md.norm(r.x);\n  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n  constexpr inline Uint val() const { return B::md.get(x); }\n\
    \  friend ostream &operator<<(ostream &os, const ModInt &r) {\n    return os <<\
    \ r.val();\n  }\n  friend istream &operator>>(istream &is, ModInt &r) {\n    long\
    \ long v;\n    return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n\
    };\ntemplate <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX,\
    \ ModInt<int, u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD\
    \ &(MOD < LLONG_MAX),\n                      ModInt<long long, u64, StaticB<MIntPro_Montg,\
    \ MOD>>,\n                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt\
    \ = conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM>\n\
    mod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l = 1;\n  if (l\
    \ == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m % l] * (m - m / l);\n\
    \  return dat[n];\n}\n#line 5 \"src/FFT/NTT.hpp\"\n\n/**\n * @title Number-Theoretic-Transform\n\
    \ * @category FFT\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\ntemplate\
    \ <class mod_t>\nstruct NumberTheoreticTransform {\n  static inline void dft(int\
    \ n, mod_t x[]) {\n    if constexpr (mod < INT_MAX) {\n      static constexpr\
    \ auto r3 = ratios<3>(rt, irt);\n      static constexpr u128 imag = rt[2].val(),\
    \ mod3 = u128(mod) << 93;\n      for (int p = n >> 2, ed = 1; p; p >>= 2, ed <<=\
    \ 2) {\n        mod_t rot = one, rot2 = one, rot3 = one, *x0 = x, *x1, *x2, *x3;\n\
    \        for (int s = 0, i;; rot *= r3[__builtin_ctz(s)], rot2 = rot * rot,\n\
    \                 rot3 = rot2 * rot, x0 = x3 + p) {\n          u64 rot_u = rot.val(),\
    \ rot2_u = rot2.val(), rot3_u = rot3.val();\n          for (x1 = x0 + p, x2 =\
    \ x1 + p, x3 = x2 + p, i = p; i--;) {\n            u64 a0 = x0[i].val(), a1 =\
    \ rot_u * x1[i].val(),\n                a2 = rot2_u * x2[i].val(), a3 = rot3_u\
    \ * x3[i].val(),\n                na3 = mod2 - a3, a0n2 = mod2 + a0 - a2;\n  \
    \          u128 a1na3imag = imag * (a1 + na3);\n            x0[i] = a0 + a1 +\
    \ a2 + a3, x1[i] = a0 + (mod2 - a1) + a2 + na3;\n            x2[i] = a1na3imag\
    \ + a0n2, x3[i] = mod3 - a1na3imag + a0n2;\n          }\n          if (++s ==\
    \ ed) break;\n        }\n      }\n      if (__builtin_ctz(n) & 1) {\n        mod_t\
    \ rot = one, u;\n        for (int s = 0, m = 0;; rot *= r2[__builtin_ctz(++s)])\
    \ {\n          x[m + 1] = x[m] - (u = x[m + 1] * rot), x[m] += u;\n          if\
    \ ((m += 2) == n) break;\n        }\n      }\n    } else\n      for (int m = n,\
    \ s = 0, i, ed = 1; m >>= 1; s = 0, ed <<= 1)\n        for (mod_t rot = one, *x0\
    \ = x, *x1, u;;\n             rot *= r2[__builtin_ctz(s)], x0 = x1 + m) {\n  \
    \        for (x1 = x0 + (i = m); i--;)\n            x1[i] = x0[i] - (u = rot *\
    \ x1[i]), x0[i] += u;\n          if (++s == ed) break;\n        }\n  }\n  static\
    \ inline void idft(int n, mod_t x[]) {\n    if constexpr (mod < INT_MAX) {\n \
    \     static constexpr auto ir3 = ratios<3>(irt, rt);\n      static constexpr\
    \ u64 iimag = irt[2].val();\n      for (int ed = n >> 2, p = 1; ed; p <<= 2, ed\
    \ >>= 2) {\n        mod_t irot = one, irot2 = one, irot3 = one, *x0 = x, *x1,\
    \ *x2, *x3;\n        for (int s = 0, i;; irot *= ir3[__builtin_ctz(s)], irot2\
    \ = irot * irot,\n                 irot3 = irot2 * irot, x0 = x3 + p) {\n    \
    \      u64 irot2_u = irot2.val();\n          u128 irot_u = irot.val(), irot3_u\
    \ = irot3.val();\n          for (x1 = x0 + p, x2 = x1 + p, x3 = x2 + p, i = p;\
    \ i--;) {\n            u64 a0 = x0[i].val(), a1 = x1[i].val(), a2 = x2[i].val(),\n\
    \                a3 = x3[i].val(), na3 = mod - a3, a0n1 = a0 + mod - a1,\n   \
    \             a2na3iimag = iimag * (a2 + na3);\n            x0[i] = a0 + a1 +\
    \ a2 + a3, x1[i] = irot_u * (a0n1 + a2na3iimag);\n            x2[i] = irot2_u\
    \ * (a0 + a1 + (mod - a2) + na3);\n            x3[i] = irot3_u * (a0n1 + (mod2\
    \ << 1) - a2na3iimag);\n          }\n          if (++s == ed) break;\n       \
    \ }\n      }\n      if (__builtin_ctz(n) & 1) {\n        mod_t u, *x1 = x + (n\
    \ >> 1);\n        for (int i = n >> 1; i--;) u = x[i] - x1[i], x[i] += x1[i],\
    \ x1[i] = u;\n      }\n    } else\n      for (int m = 1, s = 0, i, ed = n; ed\
    \ >>= 1; m <<= 1, s = 0)\n        for (mod_t irot = one, y, *x0 = x, *x1;;\n \
    \            irot *= ir2[__builtin_ctz(s)], x0 = x1 + m) {\n          for (x1\
    \ = x0 + (i = m); i--;)\n            y = x0[i] - x1[i], x0[i] += x1[i], x1[i]\
    \ = irot * y;\n          if (++s == ed) break;\n        }\n    for (const mod_t\
    \ iv = one / n; n--;) x[n] *= iv;\n  }\n  static inline void even_dft(int n, mod_t\
    \ x[]) {\n    for (int i = 0, j = 0; i < n; i += 2, j++) x[j] = iv2 * (x[i] +\
    \ x[i + 1]);\n  }\n  static inline void odd_dft(int n, mod_t x[]) {\n    mod_t\
    \ prod = iv2;\n    for (int i = 0, j = 0;; i += 2, prod *= ir2[__builtin_ctz(++j)])\n\
    \      if (x[j] = prod * (x[i] - x[i + 1]); i + 2 == n) break;\n  }\n  static\
    \ inline void dft_doubling(int n, mod_t x[]) {\n    copy_n(x, n, x + n), idft(n,\
    \ x + n);\n    mod_t k(1), t(rt[__builtin_ctz(n << 1)]);\n    for (int i = 0;\
    \ i < n; i++) x[n + i] *= k, k *= t;\n    dft(n, x + n);\n  }\n  static constexpr\
    \ u64 lim() { return 1ULL << E; }\n\n protected:\n  static constexpr u64 mod =\
    \ mod_t::modulo(), mod2 = mod << 31;\n  static_assert(mod & 1);\n  static_assert(is_prime(mod));\n\
    \  static constexpr uint8_t E = __builtin_ctzll(mod - 1);\n  static constexpr\
    \ mod_t w = [](uint8_t e) -> mod_t {\n    for (mod_t r = 2;; r += 1)\n      if\
    \ (auto s = r.pow((mod - 1) / 2); s != 1 && s * s == 1)\n        return r.pow((mod\
    \ - 1) >> e);\n    return 0;\n  }(E);\n  static_assert(w != mod_t(0));\n  static\
    \ constexpr mod_t one = 1, iv2 = (mod + 1) / 2, iw = w.pow(lim() - 1);\n  static\
    \ constexpr auto roots(mod_t w) {\n    array<mod_t, E + 1> ret = {};\n    for\
    \ (uint8_t e = E; e; e--, w *= w) ret[e] = w;\n    return ret[0] = w, ret;\n \
    \ }\n  template <size_t N>\n  static constexpr auto ratios(const array<mod_t,\
    \ E + 1> &rt,\n                               const array<mod_t, E + 1> &irt,\
    \ int i = N) {\n    array<mod_t, E + 1 - N> ret = {};\n    for (mod_t prod = 1;\
    \ i <= E; prod *= irt[i++]) ret[i - N] = rt[i] * prod;\n    return ret;\n  }\n\
    \  static constexpr auto rt = roots(w), irt = roots(iw);\n  static constexpr auto\
    \ r2 = ratios<2>(rt, irt), ir2 = ratios<2>(irt, rt);\n};\ntemplate <class T, uint8_t\
    \ type, class B>\nstruct NTTArrayImpl : public B {\n  using B::B;\n#define FUNC(op,\
    \ name, HOGEHOGE, ...)         \\\n  inline void name(__VA_ARGS__) {         \
    \    \\\n    HOGEHOGE(op, 1);                          \\\n    if constexpr (type\
    \ >= 2) HOGEHOGE(op, 2); \\\n    if constexpr (type >= 3) HOGEHOGE(op, 3); \\\n\
    \    if constexpr (type >= 4) HOGEHOGE(op, 4); \\\n    if constexpr (type >= 5)\
    \ HOGEHOGE(op, 5); \\\n  }\n#define DFT(fft, _) B::ntt##_::fft(e - b, this->dat##_\
    \ + b)\n#define ZEROS(op, _) fill_n(this->dat##_ + b, e - b, typename B::mint##_())\n\
    #define SET(op, _) copy(x + b, x + e, this->dat##_ + b)\n#define SET_SINGLE(op,\
    \ _) this->dat##_[i] = x;\n#define SUBST(op, _) copy(r.dat##_ + b, r.dat##_ +\
    \ e, this->dat##_ + b)\n  FUNC(dft, dft, DFT, int b, int e)\n  FUNC(idft, idft,\
    \ DFT, int b, int e)\n  FUNC(__, zeros, ZEROS, int b, int e)\n  FUNC(__, set,\
    \ SET, const T x[], int b, int e)\n  FUNC(__, set, SET_SINGLE, int i, T x)\n \
    \ template <class C>\n  FUNC(__, subst, SUBST, const NTTArrayImpl<T, type, C>\
    \ &r, int b, int e)\n  inline void get(T x[], int b, int e) const {\n    if constexpr\
    \ (type == 1)\n      copy(this->dat1 + b, this->dat1 + e, x + b);\n    else\n\
    \      for (int i = b; i < e; i++) x[i] = get(i);\n  }\n#define TMP(num) B::iv##num##1\
    \ * (this->dat##num[i] - r1)\n  inline T get(int i) const {\n    if constexpr\
    \ (type >= 2) {\n      static const T mod1 = B::mint1::modulo();\n      u64 r1\
    \ = this->dat1[i].val(), r2 = (TMP(2)).val();\n      T ret = 0;\n      if constexpr\
    \ (type >= 3) {\n        static const T mod2 = B::mint2::modulo();\n        u64\
    \ r3 = (TMP(3) - B::iv32 * r2).val();\n        if constexpr (type >= 4) {\n  \
    \        static const T mod3 = B::mint3::modulo();\n          u64 r4 = (TMP(4)\
    \ - B::iv42 * r2 - B::iv43 * r3).val();\n          if constexpr (type >= 5) {\n\
    \            static const T mod4 = B::mint4::modulo();\n            u64 r5 =\n\
    \                (TMP(5) - B::iv52 * r2 - B::iv53 * r3 - B::iv54 * r4).val();\n\
    \            ret = mod4 * r5;\n          }\n          ret = mod3 * (ret + r4);\n\
    \        }\n        ret = mod2 * (ret + r3);\n      }\n      return mod1 * (ret\
    \ + r2) + r1;\n    } else\n      return this->dat1[i];\n  }\n#undef TMP\n#define\
    \ ASGN(op, _) \\\n  for (int i = b; i < e; i++) this->dat##_[i] op## = r.dat##_[i]\n\
    #define ASSIGN(fname, op) \\\n  template <class C>      \\\n  FUNC(op, fname,\
    \ ASGN, const NTTArrayImpl<T, type, C> &r, int b, int e)\n#define BOP(op, _) \\\
    \n  for (int i = b; i < e; i++) this->dat##_[i] = l.dat##_[i] op r.dat##_[i]\n\
    #define OP(fname, op)                                     \\\n  template <class\
    \ C, class D>                             \\\n  FUNC(op, fname, BOP, const NTTArrayImpl<T,\
    \ type, C> &l, \\\n       const NTTArrayImpl<T, type, D> &r, int b, int e)\n \
    \ OP(add, +)\n  OP(dif, -) OP(mul, *) ASSIGN(add, +) ASSIGN(dif, -) ASSIGN(mul,\
    \ *)\n#undef DFT\n#undef ZEROS\n#undef SET\n#undef SET_SINGLE\n#undef SUBST\n\
    #undef ASGN\n#undef ASSIGN\n#undef BOP\n#undef OP\n#undef FUNC\n};\nusing u8 =\
    \ uint8_t;\n#define ARR(num)                                        \\\n  using\
    \ mint##num = StaticModInt<M##num>;               \\\n  using ntt##num = NumberTheoreticTransform<mint##num>;\
    \ \\\n  mint##num dat##num[LIM] = {};\n#define IV2 static constexpr mint2 iv21\
    \ = mint2(1) / mint1::modulo();\n#define IV3                                 \
    \                \\\n  static constexpr mint3 iv32 = mint3(1) / mint2::modulo(),\
    \ \\\n                         iv31 = iv32 / mint1::modulo();\n#define IV4   \
    \                                              \\\n  static constexpr mint4 iv43\
    \ = mint4(1) / mint3::modulo(), \\\n                         iv42 = iv43 / mint2::modulo(),\
    \     \\\n                         iv41 = iv42 / mint1::modulo();\n#define IV5\
    \                                                 \\\n  static constexpr mint5\
    \ iv54 = mint5(1) / mint4::modulo(), \\\n                         iv53 = iv54\
    \ / mint3::modulo(),     \\\n                         iv52 = iv53 / mint2::modulo(),\
    \     \\\n                         iv51 = iv52 / mint1::modulo();\ntemplate <u8\
    \ type, u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM, bool vec>\nstruct\
    \ NTTArrayB_ {\n  ARR(1)\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5,\
    \ size_t LIM>\nstruct NTTArrayB_<2, M1, M2, M3, M4, M5, LIM, false> {\n  ARR(1)\
    \ ARR(2) IV2\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM>\n\
    struct NTTArrayB_<3, M1, M2, M3, M4, M5, LIM, false> {\n  ARR(1) ARR(2) ARR(3)\
    \ IV2 IV3\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM>\n\
    struct NTTArrayB_<4, M1, M2, M3, M4, M5, LIM, false> {\n  ARR(1) ARR(2) ARR(3)\
    \ ARR(4) IV2 IV3 IV4\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t\
    \ LIM>\nstruct NTTArrayB_<5, M1, M2, M3, M4, M5, LIM, false> {\n  ARR(1) ARR(2)\
    \ ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5\n};\n#undef ARR\n#define VEC(num)     \
    \                                   \\\n  using mint##num = StaticModInt<M##num>;\
    \               \\\n  using ntt##num = NumberTheoreticTransform<mint##num>; \\\
    \n  vector<mint##num> buf##num;                           \\\n  mint##num *dat##num;\n\
    template <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM>\nstruct NTTArrayB_<1,\
    \ M1, M2, M3, M4, M5, LIM, true> {\n  NTTArrayB_() : dat1(buf1.data()) {}\n  void\
    \ resize(int n) { buf1.resize(n), dat1 = buf1.data(); }\n  size_t size() const\
    \ { return buf1.size(); }\n  VEC(1)\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32\
    \ M4, u32 M5, size_t LIM>\nstruct NTTArrayB_<2, M1, M2, M3, M4, M5, LIM, true>\
    \ {\n  NTTArrayB_() : dat1(buf1.data()), dat2(buf2.data()) {}\n  void resize(int\
    \ n) {\n    buf1.resize(n), dat1 = buf1.data(), buf2.resize(n), dat2 = buf2.data();\n\
    \  }\n  size_t size() const { return buf1.size(); }\n  VEC(1) VEC(2) IV2\n};\n\
    template <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM>\nstruct NTTArrayB_<3,\
    \ M1, M2, M3, M4, M5, LIM, true> {\n  NTTArrayB_() : dat1(buf1.data()), dat2(buf2.data()),\
    \ dat3(buf3.data()) {}\n  void resize(int n) {\n    buf1.resize(n), dat1 = buf1.data(),\
    \ buf2.resize(n), dat2 = buf2.data();\n    buf3.resize(n), dat3 = buf3.data();\n\
    \  }\n  size_t size() const { return buf1.size(); }\n  VEC(1) VEC(2) VEC(3) IV2\
    \ IV3\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM>\nstruct\
    \ NTTArrayB_<4, M1, M2, M3, M4, M5, LIM, true> {\n  NTTArrayB_()\n      : dat1(buf1.data()),\n\
    \        dat2(buf2.data()),\n        dat3(buf3.data()),\n        dat4(buf4.data())\
    \ {}\n  void resize(int n) {\n    buf1.resize(n), dat1 = buf1.data(), buf2.resize(n),\
    \ dat2 = buf2.data();\n    buf3.resize(n), dat3 = buf3.data(), buf4.resize(n),\
    \ dat4 = buf4.data();\n  }\n  size_t size() const { return buf1.size(); }\n  VEC(1)\
    \ VEC(2) VEC(3) VEC(4) IV2 IV3 IV4\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32\
    \ M4, u32 M5, size_t LIM>\nstruct NTTArrayB_<5, M1, M2, M3, M4, M5, LIM, true>\
    \ {\n  NTTArrayB_()\n      : dat1(buf1.data()),\n        dat2(buf2.data()),\n\
    \        dat3(buf3.data()),\n        dat4(buf4.data()),\n        dat5(buf5.data())\
    \ {}\n  void resize(int n) {\n    buf1.resize(n), dat1 = buf1.data(), buf2.resize(n),\
    \ dat2 = buf2.data();\n    buf3.resize(n), dat3 = buf3.data(), buf4.resize(n),\
    \ dat4 = buf4.data();\n    buf5.resize(n), dat5 = buf5.data();\n  }\n  size_t\
    \ size() const { return buf1.size(); }\n  VEC(1) VEC(2) VEC(3) VEC(4) VEC(5) IV2\
    \ IV3 IV4 IV5\n};\n#undef VEC\n#undef IV2\n#undef IV3\n#undef IV4\n#undef IV5\n\
    template <class T, size_t LIM>\nconstexpr bool is_nttfriend() {\n  if constexpr\
    \ (!is_staticmodint_v<T>)\n    return false;\n  else\n    return (T::modulo()\
    \ & is_prime(T::modulo())) &&\n           LIM <= (1ULL << __builtin_ctzll(T::modulo()\
    \ - 1));\n}\ntemplate <class T>\nconstexpr u64 max_value() {\n  if constexpr (is_runtimemodint_v<T>)\n\
    \    return numeric_limits<typename T::Uint>::max();\n  else if constexpr (is_staticmodint_v<T>)\n\
    \    return T::modulo();\n  else\n    return numeric_limits<T>::max();\n}\ntemplate\
    \ <class T, size_t LIM, u32 M1, u32 M2, u32 M3, u32 M4>\nconstexpr uint8_t nttarray_type_()\
    \ {\n  if constexpr (is_nttfriend<T, LIM>())\n    return 1;\n  else {\n    constexpr\
    \ u128 mv = max_value<T>(), mvmv = mv * mv;\n    if constexpr (mvmv <= M1 / LIM)\n\
    \      return 1;\n    else if constexpr (mvmv <= u64(M1) * M2 / LIM)\n      return\
    \ 2;\n    else if constexpr (mvmv <= u128(M1) * M2 * M3 / LIM)\n      return 3;\n\
    \    else if constexpr (mvmv <= u128(M1) * M2 * M3 * M4 / LIM)\n      return 4;\n\
    \    else\n      return 5;\n  }\n}\nconstexpr std::uint32_t MOD32_1 = 0x7e000001,\
    \ MOD32_2 = 0x78000001,\n                        MOD32_3 = 0x6c000001, MOD32_4\
    \ = 0x66000001,\n                        MOD32_5 = 0x42000001;\ntemplate <class\
    \ T, size_t LIM>\nconstexpr u8 nttarray_type =\n    nttarray_type_<T, LIM, MOD32_1,\
    \ MOD32_2, MOD32_3, MOD32_4>();\ntemplate <class T, size_t LIM>\nconstexpr u8\
    \ nttarr_cat = is_nttfriend<T, LIM>() && (max_value<T>() > INT_MAX)\n        \
    \                      ? 0\n                              : nttarray_type<T, LIM>;\n\
    template <class T, size_t LIM, bool vec>\nusing NTTArrayB =\n    conditional_t<is_nttfriend<T,\
    \ LIM>(),\n                  NTTArrayB_<1, max_value<T>(), 0, 0, 0, 0, LIM, vec>,\n\
    \                  NTTArrayB_<nttarray_type<T, LIM>, MOD32_1, MOD32_2, MOD32_3,\n\
    \                             MOD32_4, MOD32_5, LIM, vec>>;\ntemplate <class T,\
    \ size_t LIM, bool vec>\nusing NTTArray = NTTArrayImpl<T, nttarray_type<T, LIM>,\
    \ NTTArrayB<T, LIM, vec>>;\n}  // namespace math_internal\nusing math_internal::is_nttfriend,\
    \ math_internal::nttarray_type,\n    math_internal::nttarr_cat, math_internal::NumberTheoreticTransform,\n\
    \    math_internal::NTTArray;\ntemplate <class T, std::size_t LIM, int id = 0>\n\
    struct GlobalNTTArray {\n  static inline NTTArray<T, LIM, false> bf;\n};\ntemplate\
    \ <class T, std::size_t LIM, std::size_t LIM2, int id = 0>\nstruct GlobalNTTArray2D\
    \ {\n  static inline NTTArray<T, LIM, false> bf[LIM2];\n};\ntemplate <class T,\
    \ std::size_t LIM, int id = 0>\nstruct GlobalArray {\n  static inline T bf[LIM];\n\
    };\nconstexpr unsigned get_len(unsigned n) { return 1 << (std::__lg(n - 1) + 1);\
    \ }\n#line 4 \"src/FFT/fps_inv.hpp\"\n\n/**\n * @title \u5F62\u5F0F\u7684\u51AA\
    \u7D1A\u6570 inv\n * @category FFT\n */\n\n// BEGIN CUT HERE\nnamespace ntt_internal\
    \ {\ntemplate <std::size_t LIM, class mod_t>\ninline void inv_base(const mod_t\
    \ p[], int n, mod_t r[], int i = 1, int l = -1) {\n  static constexpr int t =\
    \ nttarr_cat<mod_t, LIM>;\n  static constexpr int TH = (int[]){64, 32, 64, 128,\
    \ 128, 256}[t];\n  if (n <= i) return;\n  if (l < 0) l = n;\n  assert(((n & -n)\
    \ == n)), assert(i && ((i & -i) == i));\n  const mod_t miv = -r[0];\n  if (; n\
    \ > TH) {\n    static constexpr int lnR = 2 + (t == 0), LIM2 = LIM >> (lnR - 1),\n\
    \                         R = (1 << lnR) - 1;\n    const auto [m, skip] = [&]()\
    \ -> std::pair<int, int> {\n      if constexpr (t == 0) {\n        const int bn\
    \ = __builtin_ctz(n) % 3;\n        return bn ? std::make_pair(64, bn) : std::make_pair(32,\
    \ 1);\n      } else\n        return std::make_pair(TH, 1 + (__builtin_ctz(TH)\
    \ & 1));\n    }();\n    for (std::fill_n(r + 1, m - 1, mod_t()); i < m; r[i++]\
    \ *= miv)\n      for (int j = std::min(i + 1, l); --j;) r[i] += r[i - j] * p[j];\n\
    \    using GNA1 = GlobalNTTArray<mod_t, LIM2, 1>;\n    using GNA2 = GlobalNTTArray<mod_t,\
    \ LIM2, 2>;\n    auto gt1 = GlobalNTTArray2D<mod_t, LIM2, R, 1>::bf;\n    auto\
    \ gt2 = GlobalNTTArray2D<mod_t, LIM2, R, 2>::bf;\n    for (int ed = (1 << skip)\
    \ - 1; i < n; ed = R) {\n      mod_t *rr = r;\n      const mod_t *pp = p;\n  \
    \    const int s = i, e = s << 1, ss = (l - 1) / s;\n      for (int k = 0, j;\
    \ i < n && k < ed; ++k, i += s, pp += s) {\n        if (j = std::min(e, l - k\
    \ * s); j > 0)\n          gt2[k].set(pp, 0, j), gt2[k].zeros(j, e), gt2[k].dft(0,\
    \ e);\n        gt1[k].set(rr, 0, s), gt1[k].zeros(s, e), gt1[k].dft(0, e);\n \
    \       for (GNA2::bf.mul(gt1[k], gt2[0], 0, e), j = std::min(k, ss) + 1; --j;)\n\
    \          GNA1::bf.mul(gt1[k - j], gt2[j], 0, e), GNA2::bf.add(GNA1::bf, 0, e);\n\
    \        GNA2::bf.idft(0, e), GNA2::bf.zeros(0, s);\n        if constexpr (!is_nttfriend<mod_t,\
    \ LIM2>())\n          GNA2::bf.get(rr, s, e), GNA2::bf.set(rr, s, e);\n      \
    \  GNA2::bf.dft(0, e), GNA2::bf.mul(gt1[0], 0, e), GNA2::bf.idft(0, e);\n    \
    \    for (GNA2::bf.get(rr, s, e), rr += s, j = s; j--;) rr[j] = -rr[j];\n    \
    \  }\n    }\n  } else\n    for (std::fill_n(r + 1, n - 1, mod_t()); i < n; r[i++]\
    \ *= miv)\n      for (int j = std::min(i + 1, l); --j;) r[i] += r[i - j] * p[j];\n\
    }\ntemplate <std::size_t lnR, class mod_t, std::size_t LIM = 1 << 22>\nvoid inv_(const\
    \ mod_t p[], int n, mod_t r[]) {\n  static constexpr std::size_t R = (1 << lnR)\
    \ - 1;\n  static constexpr std::size_t LIM2 = LIM >> (lnR - 1);\n  using GNA1\
    \ = GlobalNTTArray<mod_t, LIM2, 1>;\n  using GNA2 = GlobalNTTArray<mod_t, LIM2,\
    \ 2>;\n  auto gt1 = GlobalNTTArray2D<mod_t, LIM2, R, 1>::bf;\n  auto gt2 = GlobalNTTArray2D<mod_t,\
    \ LIM2, R, 2>::bf;\n  assert(n > 0), assert(p[0] != mod_t());\n  const int m =\
    \ get_len(n) >> lnR, m2 = m << 1, ed = (n - 1) / m;\n  inv_base<LIM2>(p, m, r);\n\
    \  for (int k = 0, l; k < ed; p += m) {\n    gt2[k].set(p, 0, l = std::min(m2,\
    \ n - m * k)), gt2[k].zeros(l, m2);\n    gt2[k].dft(0, m2), gt1[k].set(r, 0, m),\
    \ gt1[k].zeros(m, m2);\n    for (gt1[k].dft(0, m2), GNA2::bf.mul(gt1[k], gt2[0],\
    \ 0, m2), l = k; l--;)\n      GNA1::bf.mul(gt1[l], gt2[k - l], 0, m2), GNA2::bf.add(GNA1::bf,\
    \ 0, m2);\n    GNA2::bf.idft(0, m2), GNA2::bf.zeros(0, m);\n    if constexpr (!is_nttfriend<mod_t,\
    \ LIM2>())\n      GNA2::bf.get(r, m, m2), GNA2::bf.set(r, m, m2);\n    GNA2::bf.dft(0,\
    \ m2), GNA2::bf.mul(gt1[0], 0, m2), GNA2::bf.idft(0, m2);\n    GNA2::bf.get(r,\
    \ m, m + (l = std::min(m, n - m * ++k)));\n    for (r += m; l--;) r[l] = -r[l];\n\
    \  }\n}\ntemplate <class mod_t, std::size_t LIM = 1 << 22>\nstd::vector<mod_t>\
    \ inv(const std::vector<mod_t> &p) {\n  static constexpr int t = nttarr_cat<mod_t,\
    \ LIM>;\n  static constexpr int TH = (int[]){94, 54, 123, 222, 243, 354}[t];\n\
    \  mod_t *pp = GlobalArray<mod_t, LIM, 1>::bf,\n        *rr = GlobalArray<mod_t,\
    \ LIM, 2>::bf;\n  const int n = p.size();\n  assert(n > 0), assert(p[0] != mod_t(0));\n\
    \  std::copy(p.begin(), p.end(), pp);\n  const mod_t miv = -(rr[0] = mod_t(1)\
    \ / pp[0]);\n  if (n <= TH) {\n    for (int j, i = 1; i < n; rr[i++] *= miv)\n\
    \      for (rr[j = i] = mod_t(); j--;) rr[i] += rr[j] * pp[i - j];\n  } else {\n\
    \    const int l = get_len(n), l1 = l >> 1, k = (n - l1 - 1) / (l1 >> 3),\n  \
    \            bl = __builtin_ctz(l1);\n    if constexpr (t != 0) {\n      if (bl\
    \ & 1) {\n        static constexpr int BL = t == 5 ? 11 : 13;\n        (k >= 6\
    \                        ? inv_<1, mod_t, LIM>\n         : k == 0 && bl >= BL\
    \          ? inv_<4, mod_t, LIM>\n         : t == 2 && bl == 7 && k == 1 ? inv_<2,\
    \ mod_t, LIM>\n                                       : inv_<3, mod_t, LIM>)(pp,\
    \ n, rr);\n      } else {\n        if (bl >= 10)\n          (k >= 6 || k == 3\
    \ ? inv_<2, mod_t, LIM>\n           : k == 5         ? inv_<3, mod_t, LIM>\n \
    \                           : inv_<4, mod_t, LIM>)(pp, n, rr);\n        else if\
    \ (bl == 6 || t == 4)\n          (k == 0   ? inv_<4, mod_t, LIM>\n           :\
    \ k == 1 ? inv_<3, mod_t, LIM>\n                    : inv_<2, mod_t, LIM>)(pp,\
    \ n, rr);\n        else\n          (k >= 6 || (2 <= k && k < 4)    ? inv_<2, mod_t,\
    \ LIM>\n           : k == 5 || (k == 1 && t != 1) ? inv_<3, mod_t, LIM>\n    \
    \                                      : inv_<4, mod_t, LIM>)(pp, n, rr);\n  \
    \    }\n    } else\n      (k & 1 ? inv_<3, mod_t, LIM> : inv_<4, mod_t, LIM>)(pp,\
    \ n, rr);\n  }\n  return std::vector<mod_t>(rr, rr + n);\n}\n}  // namespace ntt_internal\n\
    using ntt_internal::inv_base, ntt_internal::inv;\n#line 4 \"src/Math/mod_sqrt.hpp\"\
    \n/**\n * @title \u5E73\u65B9\u6839 ($\\mathbb{F}_p$)\n * @category \u6570\u5B66\
    \n * O( log p )\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\ntemplate\
    \ <class Int, class mod_pro_t>\nconstexpr Int inner_sqrt(Int a, Int p) {\n  const\
    \ mod_pro_t md(p);\n  Int e = (p - 1) >> 1, one = md.set(1);\n  if (a = md.set(a);\
    \ md.norm(pow(a, e, md)) != one) return -1;\n  Int b = 0, d = md.diff(0, a), ret\
    \ = one, r2 = 0, b2 = one;\n  while (md.norm(pow(d, e, md)) == one)\n    b = md.plus(b,\
    \ one), d = md.diff(md.mul(b, b), a);\n  auto mult = [&md, d](Int &u1, Int &u2,\
    \ Int v1, Int v2) {\n    Int tmp = md.plus(md.mul(u1, v1), md.mul(md.mul(u2, v2),\
    \ d));\n    u2 = md.plus(md.mul(u1, v2), md.mul(u2, v1)), u1 = tmp;\n  };\n  for\
    \ (++e;; mult(b, b2, b, b2)) {\n    if (e & 1) mult(ret, r2, b, b2);\n    if (!(e\
    \ >>= 1)) return ret = md.get(ret), ret * 2 < p ? ret : p - ret;\n  }\n}\nconstexpr\
    \ int64_t mod_sqrt(int64_t a, int64_t p) {\n  assert(p > 0), assert(a > 0), assert(is_prime(p)),\
    \ a %= p;\n  if (a <= 1 || p == 2) return a;\n  if (p < INT_MAX) return inner_sqrt<int,\
    \ MIntPro_Na<u32>>(a, p);\n  return inner_sqrt<int64_t, MIntPro_Montg>(a, p);\n\
    }\n}  // namespace math_internal\nusing math_internal::mod_sqrt;\n#line 5 \"src/FFT/fps_sqrt.hpp\"\
    \n\n/**\n * @title \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 sqrt\n * @category FFT\n\
    \ */\n\n// BEGIN CUT HERE\ntemplate <class mod_t, std::size_t _Nm = 1 << 22>\n\
    std::vector<mod_t> sqrt(const std::vector<mod_t> &p) {\n  using GAp = GlobalArray<mod_t,\
    \ _Nm, 1>;\n  using GAr = GlobalArray<mod_t, _Nm, 2>;\n  using GA3 = GlobalArray<mod_t,\
    \ _Nm, 3>;\n  using GA = GlobalArray<mod_t, _Nm, 0>;\n  static constexpr std::size_t\
    \ _Nm2 = _Nm * 2 / 15;\n  using GNA1 = GlobalNTTArray<mod_t, _Nm2, 1>;\n  using\
    \ GNA2 = GlobalNTTArray<mod_t, _Nm2, 2>;\n  using GNA3 = GlobalNTTArray<mod_t,\
    \ _Nm2, 3>;\n  using GNA2D1 = GlobalNTTArray2D<mod_t, _Nm2, 16, 1>;\n  static\
    \ constexpr int TH = 128 << ((!is_nttfriend<mod_t, _Nm2>()) << 1);\n  const mod_t\
    \ Z(0), miv2((mod_t::modulo() - 1) >> 1);\n  std::copy(p.begin(), p.end(), GAp::bf);\n\
    \  int n = p.size(), cnt = 0;\n  while (cnt < n && GAp::bf[cnt] == Z) cnt++;\n\
    \  if (cnt == n) return p;\n  if (cnt & 1) return {};  // no solution\n  mod_t\
    \ *bf = GAr::bf + (cnt >> 1), *pbf = GAp::bf + cnt;\n  std::fill_n(GAr::bf, n,\
    \ Z), bf[0] = mod_sqrt(pbf[0].val(), mod_t::modulo());\n  if (bf[0] * bf[0] !=\
    \ pbf[0]) return {};  // no solution\n  const int nn = n - cnt, len = get_len(nn),\n\
    \            R = get_len(__builtin_ctz(len) + 1) >> 1;\n  int m = TH >= nn ? nn\
    \ : len, lnR = __builtin_ctz(R), i = 2;\n  while (m > TH) m >>= lnR;\n  const\
    \ mod_t miv = mod_t(mod_t::modulo() - 1) / (bf[0] + bf[0]);\n  for ((bf[1] -=\
    \ pbf[1]) *= miv; i < m; (bf[i] -= pbf[i]) *= miv, i++) {\n    for (int j = (i\
    \ + 1) / 2; --j;) bf[i] += bf[j] * bf[i - j];\n    if (bf[i] += bf[i]; !(i & 1))\
    \ bf[i] += bf[i >> 1] * bf[i >> 1];\n  }\n  if (m == nn) return std::vector<mod_t>(GAr::bf,\
    \ GAr::bf + n);\n  for (GA3::bf[0] = mod_t(1) / bf[0], i = 1; m < nn; i = m, m\
    \ <<= lnR) {\n    int m2 = m << 1, ed = std::min(R, (nn + m - 1) / m), k = 1,\
    \ mm = m, j;\n    inv_base<_Nm2>(bf, m, GA3::bf, i);\n    GNA1::bf.set(GA3::bf,\
    \ 0, m), GNA1::bf.zeros(m, m2), GNA1::bf.dft(0, m2);\n    for (mod_t *bfk = bf,\
    \ *pbfk = pbf; k < ed; mm = std::min(m, nn - m * ++k)) {\n      GNA2D1::bf[k -\
    \ 1].set(bfk, 0, m), GNA2D1::bf[k - 1].zeros(m, m2);\n      GNA2D1::bf[k - 1].dft(0,\
    \ m2);\n      for (GNA2::bf.zeros(0, m2), j = (k - 1) >> 1; j--;)\n        GNA3::bf.add(GNA2D1::bf[j\
    \ + 1], GNA2D1::bf[j], 0, m),\n            GNA3::bf.dif(GNA2D1::bf[j + 1], GNA2D1::bf[j],\
    \ m, m2),\n            GNA3::bf.mul(GNA2D1::bf[k - 1 - j], 0, m2),\n         \
    \   GNA2::bf.add(GNA3::bf, 0, m2);\n      if (j = k >> 1; !(k & 1))\n        GNA3::bf.mul(GNA2D1::bf[j],\
    \ GNA2D1::bf[k - 1 - j], 0, m2),\n            GNA2::bf.add(GNA3::bf, 0, m), GNA2::bf.dif(GNA3::bf,\
    \ m, m2);\n      if (k != 1) GNA2::bf.add(GNA2::bf, 0, m2);\n      GNA3::bf.mul(GNA2D1::bf[j],\
    \ GNA2D1::bf[j], 0, m2), pbfk += m;\n      k & 1 ? GNA2::bf.dif(GNA3::bf, m, m2)\
    \ : GNA2::bf.add(GNA3::bf, m, m2);\n      GNA2::bf.add(GNA3::bf, 0, m), GNA2::bf.idft(0,\
    \ m2), GNA2::bf.zeros(m, m2);\n      for (GNA2::bf.get(GA::bf, 0, mm), j = mm;\
    \ j--;) GA::bf[j] -= pbfk[j];\n      GNA2::bf.set(GA::bf, 0, mm), GNA2::bf.dft(0,\
    \ m2);\n      GNA2::bf.mul(GNA1::bf, 0, m2), GNA2::bf.idft(0, m2);\n      for\
    \ (GNA2::bf.get(bfk += m, 0, mm); mm--;) bfk[mm] *= miv2;\n    }\n  }\n  return\
    \ std::vector<mod_t>(GAr::bf, GAr::bf + n);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/FFT/fps_inv.hpp\"\n\
    #include \"src/Math/mod_sqrt.hpp\"\n\n/**\n * @title \u5F62\u5F0F\u7684\u51AA\u7D1A\
    \u6570 sqrt\n * @category FFT\n */\n\n// BEGIN CUT HERE\ntemplate <class mod_t,\
    \ std::size_t _Nm = 1 << 22>\nstd::vector<mod_t> sqrt(const std::vector<mod_t>\
    \ &p) {\n  using GAp = GlobalArray<mod_t, _Nm, 1>;\n  using GAr = GlobalArray<mod_t,\
    \ _Nm, 2>;\n  using GA3 = GlobalArray<mod_t, _Nm, 3>;\n  using GA = GlobalArray<mod_t,\
    \ _Nm, 0>;\n  static constexpr std::size_t _Nm2 = _Nm * 2 / 15;\n  using GNA1\
    \ = GlobalNTTArray<mod_t, _Nm2, 1>;\n  using GNA2 = GlobalNTTArray<mod_t, _Nm2,\
    \ 2>;\n  using GNA3 = GlobalNTTArray<mod_t, _Nm2, 3>;\n  using GNA2D1 = GlobalNTTArray2D<mod_t,\
    \ _Nm2, 16, 1>;\n  static constexpr int TH = 128 << ((!is_nttfriend<mod_t, _Nm2>())\
    \ << 1);\n  const mod_t Z(0), miv2((mod_t::modulo() - 1) >> 1);\n  std::copy(p.begin(),\
    \ p.end(), GAp::bf);\n  int n = p.size(), cnt = 0;\n  while (cnt < n && GAp::bf[cnt]\
    \ == Z) cnt++;\n  if (cnt == n) return p;\n  if (cnt & 1) return {};  // no solution\n\
    \  mod_t *bf = GAr::bf + (cnt >> 1), *pbf = GAp::bf + cnt;\n  std::fill_n(GAr::bf,\
    \ n, Z), bf[0] = mod_sqrt(pbf[0].val(), mod_t::modulo());\n  if (bf[0] * bf[0]\
    \ != pbf[0]) return {};  // no solution\n  const int nn = n - cnt, len = get_len(nn),\n\
    \            R = get_len(__builtin_ctz(len) + 1) >> 1;\n  int m = TH >= nn ? nn\
    \ : len, lnR = __builtin_ctz(R), i = 2;\n  while (m > TH) m >>= lnR;\n  const\
    \ mod_t miv = mod_t(mod_t::modulo() - 1) / (bf[0] + bf[0]);\n  for ((bf[1] -=\
    \ pbf[1]) *= miv; i < m; (bf[i] -= pbf[i]) *= miv, i++) {\n    for (int j = (i\
    \ + 1) / 2; --j;) bf[i] += bf[j] * bf[i - j];\n    if (bf[i] += bf[i]; !(i & 1))\
    \ bf[i] += bf[i >> 1] * bf[i >> 1];\n  }\n  if (m == nn) return std::vector<mod_t>(GAr::bf,\
    \ GAr::bf + n);\n  for (GA3::bf[0] = mod_t(1) / bf[0], i = 1; m < nn; i = m, m\
    \ <<= lnR) {\n    int m2 = m << 1, ed = std::min(R, (nn + m - 1) / m), k = 1,\
    \ mm = m, j;\n    inv_base<_Nm2>(bf, m, GA3::bf, i);\n    GNA1::bf.set(GA3::bf,\
    \ 0, m), GNA1::bf.zeros(m, m2), GNA1::bf.dft(0, m2);\n    for (mod_t *bfk = bf,\
    \ *pbfk = pbf; k < ed; mm = std::min(m, nn - m * ++k)) {\n      GNA2D1::bf[k -\
    \ 1].set(bfk, 0, m), GNA2D1::bf[k - 1].zeros(m, m2);\n      GNA2D1::bf[k - 1].dft(0,\
    \ m2);\n      for (GNA2::bf.zeros(0, m2), j = (k - 1) >> 1; j--;)\n        GNA3::bf.add(GNA2D1::bf[j\
    \ + 1], GNA2D1::bf[j], 0, m),\n            GNA3::bf.dif(GNA2D1::bf[j + 1], GNA2D1::bf[j],\
    \ m, m2),\n            GNA3::bf.mul(GNA2D1::bf[k - 1 - j], 0, m2),\n         \
    \   GNA2::bf.add(GNA3::bf, 0, m2);\n      if (j = k >> 1; !(k & 1))\n        GNA3::bf.mul(GNA2D1::bf[j],\
    \ GNA2D1::bf[k - 1 - j], 0, m2),\n            GNA2::bf.add(GNA3::bf, 0, m), GNA2::bf.dif(GNA3::bf,\
    \ m, m2);\n      if (k != 1) GNA2::bf.add(GNA2::bf, 0, m2);\n      GNA3::bf.mul(GNA2D1::bf[j],\
    \ GNA2D1::bf[j], 0, m2), pbfk += m;\n      k & 1 ? GNA2::bf.dif(GNA3::bf, m, m2)\
    \ : GNA2::bf.add(GNA3::bf, m, m2);\n      GNA2::bf.add(GNA3::bf, 0, m), GNA2::bf.idft(0,\
    \ m2), GNA2::bf.zeros(m, m2);\n      for (GNA2::bf.get(GA::bf, 0, mm), j = mm;\
    \ j--;) GA::bf[j] -= pbfk[j];\n      GNA2::bf.set(GA::bf, 0, mm), GNA2::bf.dft(0,\
    \ m2);\n      GNA2::bf.mul(GNA1::bf, 0, m2), GNA2::bf.idft(0, m2);\n      for\
    \ (GNA2::bf.get(bfk += m, 0, mm); mm--;) bfk[mm] *= miv2;\n    }\n  }\n  return\
    \ std::vector<mod_t>(GAr::bf, GAr::bf + n);\n}"
  dependsOn:
  - src/FFT/fps_inv.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/mod_sqrt.hpp
  isVerificationFile: false
  path: src/FFT/fps_sqrt.hpp
  requiredBy: []
  timestamp: '2022-12-29 22:36:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/sqrt_of_FPS.test.cpp
documentation_of: src/FFT/fps_sqrt.hpp
layout: document
redirect_from:
- /library/src/FFT/fps_sqrt.hpp
- /library/src/FFT/fps_sqrt.hpp.html
title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 sqrt"
---
