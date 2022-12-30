---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':x:'
    path: src/FFT/Polynomial.hpp
    title: "\u591A\u9805\u5F0F"
  - icon: ':question:'
    path: src/FFT/convolve.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  - icon: ':x:'
    path: src/FFT/fps_div.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 div"
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_taylor_shift
    links:
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
  bundledCode: "#line 1 \"test/yosupo/shift_of_FPS.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x= 1, y= 0, b=\
    \ mod;\n  for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a /\
    \ b), a= b, b= c - b * q;\n  return assert(a == 1), x < 0 ? mod - (-x) % mod :\
    \ x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing u128= __uint128_t;\nstruct MP_Mo {\n  const u64 mod;\n  constexpr\
    \ MP_Mo(): mod(0), iv(0), r2(0) {}\n  constexpr MP_Mo(u64 m): mod(m), iv(inv(m)),\
    \ r2(-u128(mod) % mod) {}\n  constexpr inline u64 mul(u64 l, u64 r) const { return\
    \ reduce(u128(l) * r); }\n#define BOP(op, a) return l op##= a, l+= (mod << 1)\
    \ & -(l >> 63)\n  constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod\
    \ << 1)); }\n  constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n\
    #undef BOP\n  constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n \
    \ constexpr inline u64 get(u64 n) const {\n    u64 ret= reduce(n) - mod;\n   \
    \ return ret + (mod & -(ret >> 63));\n  }\n  constexpr inline u64 norm(u64 n)\
    \ const { return n - (mod & -(n >= mod)); }\n private:\n  const u64 iv, r2;\n\
    \  constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e ? inv(n, e - 1, x *\
    \ (2 - x * n)) : x; }\n  constexpr inline u64 reduce(const u128 &w) const { return\
    \ u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64); }\n};\ntemplate <class\
    \ Uint> class MP_Na {\n  using DUint= conditional_t<is_same_v<Uint, u32>, u64,\
    \ u128>;\n public:\n  const Uint mod;\n  constexpr MP_Na(): mod(0){};\n  constexpr\
    \ MP_Na(Uint m): mod(m) {}\n  constexpr inline Uint mul(Uint l, Uint r) const\
    \ { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod & -((l p##=\
    \ r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint r) const { BOP(-, +);\
    \ }\n  constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -); }\n#undef\
    \ BOP\n  static constexpr inline Uint set(Uint n) { return n; }\n  static constexpr\
    \ inline Uint get(Uint n) { return n; }\n  static constexpr inline Uint norm(Uint\
    \ n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr Uint\
    \ pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret= md.set(1);; x= md.mul(x,\
    \ x))\n    if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n}\n}\n\
    #line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\nstruct m_b {};\nstruct\
    \ s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t> constexpr bool is_modint_v=\
    \ is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v=\
    \ is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> constexpr bool is_runtimemodint_v=\
    \ is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64 MOD> struct SB: s_b {\n\
    \ protected:\n  static constexpr mpt md= mpt(MOD);\n};\ntemplate <class mpt, int\
    \ id> struct RB: r_b {\n  static inline void set_mod(u64 m) { md= mpt(m); }\n\
    \ protected:\n  static inline mpt md;\n};\ntemplate <class Int, class U, class\
    \ B> struct MInt: public B {\n  using Uint= U;\n  static constexpr inline auto\
    \ modulo() { return B::md.mod; }\n  constexpr MInt(): x(0) {}\n  constexpr MInt(const\
    \ MInt &r): x(r.x) {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr> constexpr MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n  template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ constexpr MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n %\
    \ B::md.mod))) {}\n  constexpr MInt operator-() const { return MInt() - *this;\
    \ }\n#define FUNC(name, op) \\\n  constexpr MInt name const { \\\n    MInt ret;\
    \ \\\n    return ret.x= op, ret; \\\n  }\n  FUNC(operator+(const MInt &r), B::md.plus(x,\
    \ r.x))\n  FUNC(operator-(const MInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const\
    \ MInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n  constexpr MInt operator/(const MInt &r) const { return *this *\
    \ r.inv(); }\n  constexpr MInt &operator+=(const MInt &r) { return *this= *this\
    \ + r; }\n  constexpr MInt &operator-=(const MInt &r) { return *this= *this -\
    \ r; }\n  constexpr MInt &operator*=(const MInt &r) { return *this= *this * r;\
    \ }\n  constexpr MInt &operator/=(const MInt &r) { return *this= *this / r; }\n\
    \  constexpr bool operator==(const MInt &r) const { return B::md.norm(x) == B::md.norm(r.x);\
    \ }\n  constexpr bool operator!=(const MInt &r) const { return !(*this == r);\
    \ }\n  constexpr bool operator<(const MInt &r) const { return B::md.norm(x) <\
    \ B::md.norm(r.x); }\n  constexpr inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n  constexpr inline Uint val() const { return B::md.get(x); }\n\
    \  friend ostream &operator<<(ostream &os, const MInt &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, MInt &r) {\n    long long v;\n\
    \    return is >> v, r= MInt(v), is;\n  }\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD> using StaticModInt= conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>,\
    \ MOD>>, conditional_t<MOD &(MOD < LLONG_MAX), MInt<long long, u64, SB<MP_Mo,\
    \ MOD>>, MInt<long long, u64, SB<MP_Na<u64>, MOD>>>>;\nclass Moomery {};\ntemplate\
    \ <class Int, int id= -1> using RuntimeModInt= conditional_t<is_same_v<Int, Moomery>,\
    \ MInt<long long, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>, MInt<long long, u64, RB<MP_Na<u64>, id>>, MInt<int,\
    \ u32, RB<MP_Na<u32>, id>>>>;\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Moomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM> mod_t\
    \ get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m= mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l= 1;\n  if (l ==\
    \ 1) dat[l++]= 1;\n  while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n  return\
    \ dat[n];\n}\n#line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate\
    \ <class Uint, class mod_pro_t, u64... args> constexpr bool miller_rabin(Uint\
    \ n) {\n  const mod_pro_t md(n);\n  const Uint s= __builtin_ctzll(n - 1), d= n\
    \ >> s, one= md.set(1), n1= md.norm(md.set(n - 1));\n  for (auto a: {args...})\
    \ {\n    Uint b= a % n, p= pow(md.set(b), d, md), i= s;\n    while (p= md.norm(p),\
    \ (p != one && p != n1 && b && i--)) p= md.mul(p, p);\n    if (md.norm(p) != n1\
    \ && i != s) return 0;\n  }\n  return true;\n}\nconstexpr bool is_prime(u64 n)\
    \ {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX)\
    \ return miller_rabin<u32, MP_Na<u32>, 2, 7, 61>(n);\n  if (n < LLONG_MAX) return\
    \ miller_rabin<u64, MP_Mo, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    \  return miller_rabin<u64, MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022>(n);\n}\n}\nusing math_internal::is_prime;\n#line 5 \"src/FFT/NTT.hpp\"\
    \nnamespace math_internal {\ntemplate <class mod_t> struct NumberTheoreticTransform\
    \ {\n  static inline void dft(int n, mod_t x[]) {\n    if constexpr (mod < INT_MAX)\
    \ {\n      static constexpr auto r3= ratios<3>(rt, irt);\n      static constexpr\
    \ u128 img= rt[2].val(), mod3= u128(mod) << 93;\n      for (int p= n >> 2, ed=\
    \ 1; p; p>>= 2, ed<<= 2) {\n        mod_t rot= I, rot2= I, rot3= I, *x0= x, *x1,\
    \ *x2, *x3;\n        for (int s= 0, i;; rot*= r3[__builtin_ctz(s)], rot2= rot\
    \ * rot, rot3= rot2 * rot, x0= x3 + p) {\n          u64 rot_u= rot.val(), rot2_u=\
    \ rot2.val(), rot3_u= rot3.val();\n          for (x1= x0 + p, x2= x1 + p, x3=\
    \ x2 + p, i= p; i--;) {\n            u64 a0= x0[i].val(), a1= rot_u * x1[i].val(),\
    \ a2= rot2_u * x2[i].val(), a3= rot3_u * x3[i].val(), na3= mod2 - a3, a0n2= mod2\
    \ + a0 - a2;\n            u128 a1na3img= img * (a1 + na3);\n            x0[i]=\
    \ a0 + a1 + a2 + a3, x1[i]= a0 + (mod2 - a1) + a2 + na3, x2[i]= a1na3img + a0n2,\
    \ x3[i]= mod3 - a1na3img + a0n2;\n          }\n          if (++s == ed) break;\n\
    \        }\n      }\n      if (__builtin_ctz(n) & 1) {\n        mod_t rot= I,\
    \ u;\n        for (int s= 0, m= 0;; rot*= r2[__builtin_ctz(++s)])\n          if\
    \ (x[m + 1]= x[m] - (u= x[m + 1] * rot), x[m]+= u; (m+= 2) == n) break;\n    \
    \  }\n    } else\n      for (int m= n, s= 0, i, ed= 1; m>>= 1; s= 0, ed<<= 1)\n\
    \        for (mod_t rot= I, *x0= x, *x1, u;; rot*= r2[__builtin_ctz(s)], x0= x1\
    \ + m) {\n          for (x1= x0 + (i= m); i--;) x1[i]= x0[i] - (u= rot * x1[i]),\
    \ x0[i]+= u;\n          if (++s == ed) break;\n        }\n  }\n  static inline\
    \ void idft(int n, mod_t x[], int i= 0) {\n    if constexpr (mod < INT_MAX) {\n\
    \      static constexpr auto ir3= ratios<3>(irt, rt);\n      static constexpr\
    \ u64 iimg= irt[2].val();\n      for (int ed= n >> 2, p= 1; ed; p<<= 2, ed>>=\
    \ 2) {\n        mod_t rot= I, rot2= I, rot3= I, *x0= x, *x1, *x2, *x3;\n     \
    \   for (int s= 0;; rot*= ir3[__builtin_ctz(s)], rot2= rot * rot, rot3= rot2 *\
    \ rot, x0= x3 + p) {\n          u64 rot2_u= rot2.val();\n          u128 rot_u=\
    \ rot.val(), rot3_u= rot3.val();\n          for (x1= x0 + p, x2= x1 + p, x3= x2\
    \ + p, i= p; i--;) {\n            u64 a0= x0[i].val(), a1= x1[i].val(), a2= x2[i].val(),\
    \ a3= x3[i].val(), na3= mod - a3, a0n1= a0 + mod - a1, a2na3iimg= iimg * (a2 +\
    \ na3);\n            x0[i]= a0 + a1 + a2 + a3, x1[i]= rot_u * (a0n1 + a2na3iimg),\
    \ x2[i]= rot2_u * (a0 + a1 + (mod - a2) + na3), x3[i]= rot3_u * (a0n1 + (mod2\
    \ << 1) - a2na3iimg);\n          }\n          if (++s == ed) break;\n        }\n\
    \      }\n      if (__builtin_ctz(n) & 1)\n        for (mod_t u, *x1= x + (i=\
    \ n >> 1); i--;) u= x[i] - x1[i], x[i]+= x1[i], x1[i]= u;\n    } else\n      for\
    \ (int m= 1, s= 0, i, ed= n; ed>>= 1; m<<= 1, s= 0)\n        for (mod_t rot= I,\
    \ y, *x0= x, *x1;; rot*= ir2[__builtin_ctz(s)], x0= x1 + m) {\n          for (x1=\
    \ x0 + (i= m); i--;) y= x0[i] - x1[i], x0[i]+= x1[i], x1[i]= rot * y;\n      \
    \    if (++s == ed) break;\n        }\n    for (const mod_t iv= I / n; n--;) x[n]*=\
    \ iv;\n  }\n  static inline void even_dft(int n, mod_t x[]) {\n    for (int i=\
    \ 0, j= 0; i < n; i+= 2, j++) x[j]= iv2 * (x[i] + x[i + 1]);\n  }\n  static inline\
    \ void odd_dft(int n, mod_t x[], mod_t prod= iv2) {\n    for (int i= 0, j= 0;;\
    \ i+= 2, prod*= ir2[__builtin_ctz(++j)])\n      if (x[j]= prod * (x[i] - x[i +\
    \ 1]); i + 2 == n) break;\n  }\n  static inline void dft_doubling(int n, mod_t\
    \ x[], int i= 0) {\n    mod_t k(1), t(rt[__builtin_ctz(n << 1)]);\n    for (copy_n(x,\
    \ n, x + n), idft(n, x + n); i < n; i++) x[n + i]*= k, k*= t;\n    dft(n, x +\
    \ n);\n  }\n  static constexpr u64 lim() { return 1ULL << E; }\n protected:\n\
    \  static constexpr u64 mod= mod_t::modulo(), mod2= mod << 31;\n  static_assert(mod\
    \ & 1);\n  static_assert(is_prime(mod));\n  static constexpr u8 E= __builtin_ctzll(mod\
    \ - 1);\n  static constexpr mod_t w= [](u8 e) -> mod_t {\n    for (mod_t r= 2;;\
    \ r+= 1)\n      if (auto s= r.pow((mod - 1) / 2); s != 1 && s * s == 1) return\
    \ r.pow((mod - 1) >> e);\n    return 0;\n  }(E);\n  static_assert(w != mod_t(0));\n\
    \  static constexpr mod_t I= 1, iv2= (mod + 1) / 2, iw= w.pow(lim() - 1);\n  static\
    \ constexpr auto roots(mod_t w) {\n    array<mod_t, E + 1> ret= {};\n    for (u8\
    \ e= E; e; w*= w) ret[e--]= w;\n    return ret[0]= w, ret;\n  }\n  template <size_t\
    \ N> static constexpr auto ratios(const array<mod_t, E + 1> &rt, const array<mod_t,\
    \ E + 1> &irt, int i= N) {\n    array<mod_t, E + 1 - N> ret= {};\n    for (mod_t\
    \ prod= 1; i <= E; prod*= irt[i++]) ret[i - N]= rt[i] * prod;\n    return ret;\n\
    \  }\n  static constexpr auto rt= roots(w), irt= roots(iw);\n  static constexpr\
    \ auto r2= ratios<2>(rt, irt), ir2= ratios<2>(irt, rt);\n};\ntemplate <class T,\
    \ u8 type, class B> struct NTTArrayImpl: public B {\n  using B::B;\n#define FUNC(op,\
    \ name, HOGE, ...) \\\n  inline void name(__VA_ARGS__) { \\\n    HOGE(op, 1);\
    \ \\\n    if constexpr (type >= 2) HOGE(op, 2); \\\n    if constexpr (type >=\
    \ 3) HOGE(op, 3); \\\n    if constexpr (type >= 4) HOGE(op, 4); \\\n    if constexpr\
    \ (type >= 5) HOGE(op, 5); \\\n  }\n#define DFT(fft, _) B::ntt##_::fft(e - b,\
    \ this->dat##_ + b)\n#define ZEROS(op, _) fill_n(this->dat##_ + b, e - b, typename\
    \ B::mint##_())\n#define SET(op, _) copy(x + b, x + e, this->dat##_ + b)\n#define\
    \ SET_SINGLE(op, _) this->dat##_[i]= x;\n#define SUBST(op, _) copy(r.dat##_ +\
    \ b, r.dat##_ + e, this->dat##_ + b)\n#define ASGN(op, _) \\\n  for (int i= b;\
    \ i < e; ++i) this->dat##_[i] op##= r.dat##_[i]\n#define ASSIGN(fname, op) template\
    \ <class C> FUNC(op, fname, ASGN, const NTTArrayImpl<T, type, C> &r, int b, int\
    \ e)\n#define BOP(op, _) \\\n  for (int i= b; i < e; ++i) this->dat##_[i]= l.dat##_[i]\
    \ op r.dat##_[i]\n#define OP(fname, op) template <class C, class D> FUNC(op, fname,\
    \ BOP, const NTTArrayImpl<T, type, C> &l, const NTTArrayImpl<T, type, D> &r, int\
    \ b, int e)\n  OP(add, +) OP(dif, -) OP(mul, *) ASSIGN(add, +) ASSIGN(dif, -)\
    \ ASSIGN(mul, *) FUNC(dft, dft, DFT, int b, int e) FUNC(idft, idft, DFT, int b,\
    \ int e) FUNC(__, zeros, ZEROS, int b, int e) FUNC(__, set, SET, const T x[],\
    \ int b, int e) FUNC(__, set, SET_SINGLE, int i, T x) template <class C> FUNC(__,\
    \ subst, SUBST, const NTTArrayImpl<T, type, C> &r, int b, int e) inline void get(T\
    \ x[], int b, int e) const {\n    if constexpr (type == 1) copy(this->dat1 + b,\
    \ this->dat1 + e, x + b);\n    else\n      for (int i= b; i < e; i++) x[i]= get(i);\n\
    \  }\n#define TMP(_) B::iv##_##1 * (this->dat##_[i] - r1)\n  inline T get(int\
    \ i) const {\n    if constexpr (type >= 2) {\n      u64 r1= this->dat1[i].val(),\
    \ r2= (TMP(2)).val();\n      T ret= 0;\n      if constexpr (type >= 3) {\n   \
    \     u64 r3= (TMP(3) - B::iv32 * r2).val();\n        if constexpr (type >= 4)\
    \ {\n          u64 r4= (TMP(4) - B::iv42 * r2 - B::iv43 * r3).val();\n       \
    \   if constexpr (type >= 5) ret= B::mint4::modulo() * (TMP(5) - B::iv52 * r2\
    \ - B::iv53 * r3 - B::iv54 * r4).val();\n          ret= B::mint3::modulo() * (ret\
    \ + r4);\n        }\n        ret= B::mint2::modulo() * (ret + r3);\n      }\n\
    \      return B::mint1::modulo() * (ret + r2) + r1;\n    } else return this->dat1[i];\n\
    \  }\n#undef TMP\n#undef DFT\n#undef ZEROS\n#undef SET\n#undef SET_SINGLE\n#undef\
    \ SUBST\n#undef ASGN\n#undef ASSIGN\n#undef BOP\n#undef OP\n#undef FUNC\n};\n\
    #define ARR(_) \\\n  using mint##_= StaticModInt<M##_>; \\\n  using ntt##_= NumberTheoreticTransform<mint##_>;\
    \ \\\n  mint##_ dat##_[LIM]= {};\n#define IV2 static constexpr mint2 iv21= mint2(1)\
    \ / mint1::modulo();\n#define IV3 static constexpr mint3 iv32= mint3(1) / mint2::modulo(),\
    \ iv31= iv32 / mint1::modulo();\n#define IV4 static constexpr mint4 iv43= mint4(1)\
    \ / mint3::modulo(), iv42= iv43 / mint2::modulo(), iv41= iv42 / mint1::modulo();\n\
    #define IV5 static constexpr mint5 iv54= mint5(1) / mint4::modulo(), iv53= iv54\
    \ / mint3::modulo(), iv52= iv53 / mint2::modulo(), iv51= iv52 / mint1::modulo();\n\
    template <u8 type, u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM, bool v>\
    \ struct NB { ARR(1) };\ntemplate <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t\
    \ LIM> struct NB<2, M1, M2, M3, M4, M5, LIM, 0> { ARR(1) ARR(2) IV2 };\ntemplate\
    \ <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM> struct NB<3, M1, M2, M3,\
    \ M4, M5, LIM, 0> { ARR(1) ARR(2) ARR(3) IV2 IV3 };\ntemplate <u64 M1, u32 M2,\
    \ u32 M3, u32 M4, u32 M5, size_t LIM> struct NB<4, M1, M2, M3, M4, M5, LIM, 0>\
    \ { ARR(1) ARR(2) ARR(3) ARR(4) IV2 IV3 IV4 };\ntemplate <u64 M1, u32 M2, u32\
    \ M3, u32 M4, u32 M5, size_t LIM> struct NB<5, M1, M2, M3, M4, M5, LIM, 0> { ARR(1)\
    \ ARR(2) ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5 };\n#undef ARR\n#define VEC(_) \\\
    \n  using mint##_= StaticModInt<M##_>; \\\n  using ntt##_= NumberTheoreticTransform<mint##_>;\
    \ \\\n  vector<mint##_> buf##_; \\\n  mint##_ *dat##_;\ntemplate <u64 M1, u32\
    \ M2, u32 M3, u32 M4, u32 M5, size_t LIM> struct NB<1, M1, M2, M3, M4, M5, LIM,\
    \ 1> {\n  NB(): dat1(buf1.data()) {}\n  void resize(int n) { buf1.resize(n), dat1=\
    \ buf1.data(); }\n  size_t size() const { return buf1.size(); }\n  VEC(1)\n};\n\
    template <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM> struct NB<2, M1,\
    \ M2, M3, M4, M5, LIM, 1> {\n  NB(): dat1(buf1.data()), dat2(buf2.data()) {}\n\
    \  void resize(int n) { buf1.resize(n), dat1= buf1.data(), buf2.resize(n), dat2=\
    \ buf2.data(); }\n  size_t size() const { return buf1.size(); }\n  VEC(1) VEC(2)\
    \ IV2\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM> struct\
    \ NB<3, M1, M2, M3, M4, M5, LIM, 1> {\n  NB(): dat1(buf1.data()), dat2(buf2.data()),\
    \ dat3(buf3.data()) {}\n  void resize(int n) { buf1.resize(n), dat1= buf1.data(),\
    \ buf2.resize(n), dat2= buf2.data(), buf3.resize(n), dat3= buf3.data(); }\n  size_t\
    \ size() const { return buf1.size(); }\n  VEC(1) VEC(2) VEC(3) IV2 IV3\n};\ntemplate\
    \ <u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, size_t LIM> struct NB<4, M1, M2, M3,\
    \ M4, M5, LIM, 1> {\n  NB(): dat1(buf1.data()), dat2(buf2.data()), dat3(buf3.data()),\
    \ dat4(buf4.data()) {}\n  void resize(int n) { buf1.resize(n), dat1= buf1.data(),\
    \ buf2.resize(n), dat2= buf2.data(), buf3.resize(n), dat3= buf3.data(), buf4.resize(n),\
    \ dat4= buf4.data(); }\n  size_t size() const { return buf1.size(); }\n  VEC(1)\
    \ VEC(2) VEC(3) VEC(4) IV2 IV3 IV4\n};\ntemplate <u64 M1, u32 M2, u32 M3, u32\
    \ M4, u32 M5, size_t LIM> struct NB<5, M1, M2, M3, M4, M5, LIM, 1> {\n  NB():\
    \ dat1(buf1.data()), dat2(buf2.data()), dat3(buf3.data()), dat4(buf4.data()),\
    \ dat5(buf5.data()) {}\n  void resize(int n) { buf1.resize(n), dat1= buf1.data(),\
    \ buf2.resize(n), dat2= buf2.data(), buf3.resize(n), dat3= buf3.data(), buf4.resize(n),\
    \ dat4= buf4.data(), buf5.resize(n), dat5= buf5.data(); }\n  size_t size() const\
    \ { return buf1.size(); }\n  VEC(1) VEC(2) VEC(3) VEC(4) VEC(5) IV2 IV3 IV4 IV5\n\
    };\n#undef VEC\n#undef IV2\n#undef IV3\n#undef IV4\n#undef IV5\ntemplate <class\
    \ T, size_t LIM> constexpr bool is_nttfriend() {\n  if constexpr (!is_staticmodint_v<T>)\
    \ return 0;\n  else return (T::modulo() & is_prime(T::modulo())) && LIM <= (1ULL\
    \ << __builtin_ctzll(T::modulo() - 1));\n}\ntemplate <class T> constexpr u64 max_value()\
    \ {\n  if constexpr (is_runtimemodint_v<T>) return numeric_limits<typename T::Uint>::max();\n\
    \  else if constexpr (is_staticmodint_v<T>) return T::modulo();\n  else return\
    \ numeric_limits<T>::max();\n}\ntemplate <class T, size_t LIM, u32 M1, u32 M2,\
    \ u32 M3, u32 M4> constexpr u8 nttarray_type_() {\n  if constexpr (!is_nttfriend<T,\
    \ LIM>()) {\n    constexpr u128 mv= max_value<T>(), mvmv= mv * mv;\n    if constexpr\
    \ (mvmv <= M1 / LIM) return 1;\n    else if constexpr (mvmv <= u64(M1) * M2 /\
    \ LIM) return 2;\n    else if constexpr (mvmv <= u128(M1) * M2 * M3 / LIM) return\
    \ 3;\n    else if constexpr (mvmv <= u128(M1) * M2 * M3 * M4 / LIM) return 4;\n\
    \    else return 5;\n  } else return 1;\n}\nconstexpr u32 MOD32_1= 0x7e000001,\
    \ MOD32_2= 0x78000001, MOD32_3= 0x6c000001, MOD32_4= 0x66000001, MOD32_5= 0x42000001;\n\
    template <class T, size_t LIM> constexpr u8 nttarray_type= nttarray_type_<T, LIM,\
    \ MOD32_1, MOD32_2, MOD32_3, MOD32_4>();\ntemplate <class T, size_t LIM> constexpr\
    \ u8 nttarr_cat= is_nttfriend<T, LIM>() && (max_value<T>() > INT_MAX) ? 0 : nttarray_type<T,\
    \ LIM>;\ntemplate <class T, size_t LIM, bool v> using NTTArray= NTTArrayImpl<T,\
    \ nttarray_type<T, LIM>, conditional_t<is_nttfriend<T, LIM>(), NB<1, max_value<T>(),\
    \ 0, 0, 0, 0, LIM, v>, NB<nttarray_type<T, LIM>, MOD32_1, MOD32_2, MOD32_3, MOD32_4,\
    \ MOD32_5, LIM, v>>>;\n}\nusing math_internal::is_nttfriend, math_internal::nttarray_type,\
    \ math_internal::nttarr_cat, math_internal::NumberTheoreticTransform, math_internal::NTTArray;\n\
    template <class T, std::size_t LIM, int id= 0> struct GlobalNTTArray { static\
    \ inline NTTArray<T, LIM, 0> bf; };\ntemplate <class T, std::size_t LIM, std::size_t\
    \ LIM2, int id= 0> struct GlobalNTTArray2D { static inline NTTArray<T, LIM, 0>\
    \ bf[LIM2]; };\ntemplate <class T, std::size_t LIM, int id= 0> struct GlobalArray\
    \ { static inline T bf[LIM]; };\nconstexpr unsigned get_len(unsigned n) { return\
    \ 1 << (std::__lg(n - 1) + 1); }\n#line 4 \"src/FFT/fps_inv.hpp\"\nnamespace math_internal\
    \ {\ntemplate <size_t LIM, class mod_t> inline void inv_base(const mod_t p[],\
    \ int n, mod_t r[], int i= 1, int l= -1) {\n  static constexpr int t= nttarr_cat<mod_t,\
    \ LIM>, TH= (int[]){64, 32, 64, 128, 128, 256}[t];\n  if (n <= i) return;\n  if\
    \ (l < 0) l= n;\n  assert(((n & -n) == n)), assert(i && ((i & -i) == i));\n  const\
    \ mod_t miv= -r[0];\n  if (; n > TH) {\n    static constexpr int lnR= 2 + (!t),\
    \ LIM2= LIM >> (lnR - 1), R= (1 << lnR) - 1;\n    const auto [m, skip]= [&]()\
    \ {\n      if constexpr (!t) {\n        const int bn= __builtin_ctz(n) % 3;\n\
    \        return bn ? make_pair(64, bn) : make_pair(32, 1);\n      } else return\
    \ make_pair(TH, 1 + (__builtin_ctz(TH) & 1));\n    }();\n    for (fill_n(r + 1,\
    \ m - 1, mod_t()); i < m; r[i++]*= miv)\n      for (int j= min(i + 1, l); --j;)\
    \ r[i]+= r[i - j] * p[j];\n    using GNA1= GlobalNTTArray<mod_t, LIM2, 1>;\n \
    \   using GNA2= GlobalNTTArray<mod_t, LIM2, 2>;\n    auto gt1= GlobalNTTArray2D<mod_t,\
    \ LIM2, R, 1>::bf, gt2= GlobalNTTArray2D<mod_t, LIM2, R, 2>::bf;\n    for (int\
    \ ed= (1 << skip) - 1; i < n; ed= R) {\n      mod_t *rr= r;\n      const mod_t\
    \ *pp= p;\n      const int s= i, e= s << 1, ss= (l - 1) / s;\n      for (int k=\
    \ 0, j; i < n && k < ed; ++k, i+= s, pp+= s) {\n        if (j= min(e, l - k *\
    \ s); j > 0) gt2[k].set(pp, 0, j), gt2[k].zeros(j, e), gt2[k].dft(0, e);\n   \
    \     for (gt1[k].set(rr, 0, s), gt1[k].zeros(s, e), gt1[k].dft(0, e), GNA2::bf.mul(gt1[k],\
    \ gt2[0], 0, e), j= min(k, ss) + 1; --j;) GNA1::bf.mul(gt1[k - j], gt2[j], 0,\
    \ e), GNA2::bf.add(GNA1::bf, 0, e);\n        GNA2::bf.idft(0, e), GNA2::bf.zeros(0,\
    \ s);\n        if constexpr (!is_nttfriend<mod_t, LIM2>()) GNA2::bf.get(rr, s,\
    \ e), GNA2::bf.set(rr, s, e);\n        for (GNA2::bf.dft(0, e), GNA2::bf.mul(gt1[0],\
    \ 0, e), GNA2::bf.idft(0, e), GNA2::bf.get(rr, s, e), rr+= s, j= s; j--;) rr[j]=\
    \ -rr[j];\n      }\n    }\n  } else\n    for (fill_n(r + 1, n - 1, mod_t()); i\
    \ < n; r[i++]*= miv)\n      for (int j= min(i + 1, l); --j;) r[i]+= r[i - j] *\
    \ p[j];\n}\ntemplate <size_t lnR, class mod_t, size_t LIM= 1 << 22> void inv_(const\
    \ mod_t p[], int n, mod_t r[]) {\n  static constexpr size_t R= (1 << lnR) - 1,\
    \ LIM2= LIM >> (lnR - 1);\n  using GNA1= GlobalNTTArray<mod_t, LIM2, 1>;\n  using\
    \ GNA2= GlobalNTTArray<mod_t, LIM2, 2>;\n  auto gt1= GlobalNTTArray2D<mod_t, LIM2,\
    \ R, 1>::bf, gt2= GlobalNTTArray2D<mod_t, LIM2, R, 2>::bf;\n  assert(n > 0), assert(p[0]\
    \ != mod_t());\n  const int m= get_len(n) >> lnR, m2= m << 1, ed= (n - 1) / m;\n\
    \  inv_base<LIM2>(p, m, r);\n  for (int k= 0, l; k < ed; p+= m) {\n    for (gt2[k].set(p,\
    \ 0, l= min(m2, n - m * k)), gt2[k].zeros(l, m2), gt2[k].dft(0, m2), gt1[k].set(r,\
    \ 0, m), gt1[k].zeros(m, m2), gt1[k].dft(0, m2), GNA2::bf.mul(gt1[k], gt2[0],\
    \ 0, m2), l= k; l--;) GNA1::bf.mul(gt1[l], gt2[k - l], 0, m2), GNA2::bf.add(GNA1::bf,\
    \ 0, m2);\n    GNA2::bf.idft(0, m2), GNA2::bf.zeros(0, m);\n    if constexpr (!is_nttfriend<mod_t,\
    \ LIM2>()) GNA2::bf.get(r, m, m2), GNA2::bf.set(r, m, m2);\n    for (GNA2::bf.dft(0,\
    \ m2), GNA2::bf.mul(gt1[0], 0, m2), GNA2::bf.idft(0, m2), GNA2::bf.get(r, m, m\
    \ + (l= min(m, n - m * ++k))), r+= m; l--;) r[l]= -r[l];\n  }\n}\ntemplate <class\
    \ mod_t, size_t LIM= 1 << 22> vector<mod_t> inv(const vector<mod_t> &p) {\n  static\
    \ constexpr int t= nttarr_cat<mod_t, LIM>, TH= (int[]){94, 54, 123, 222, 243,\
    \ 354}[t];\n  mod_t *pp= GlobalArray<mod_t, LIM, 1>::bf, *rr= GlobalArray<mod_t,\
    \ LIM, 2>::bf;\n  const int n= p.size();\n  assert(n > 0), assert(p[0] != mod_t(0));\n\
    \  copy(p.begin(), p.end(), pp);\n  if (const mod_t miv= -(rr[0]= mod_t(1) / pp[0]);\
    \ n > TH) {\n    const int l= get_len(n), l1= l >> 1, k= (n - l1 - 1) / (l1 >>\
    \ 3), bl= __builtin_ctz(l1);\n    if constexpr (t != 0) {\n      if (bl & 1) {\n\
    \        static constexpr int BL= t == 5 ? 11 : 13;\n        (k >= 6 ? inv_<1,\
    \ mod_t, LIM> : !k && bl >= BL ? inv_<4, mod_t, LIM> : t == 2 && bl == 7 && k\
    \ == 1 ? inv_<2, mod_t, LIM> : inv_<3, mod_t, LIM>)(pp, n, rr);\n      } else\
    \ {\n        if (bl >= 10) (k >= 6 || k == 3 ? inv_<2, mod_t, LIM> : k == 5 ?\
    \ inv_<3, mod_t, LIM> : inv_<4, mod_t, LIM>)(pp, n, rr);\n        else if (bl\
    \ == 6 || t == 4) (!k ? inv_<4, mod_t, LIM> : k == 1 ? inv_<3, mod_t, LIM> : inv_<2,\
    \ mod_t, LIM>)(pp, n, rr);\n        else (k >= 6 || (2 <= k && k < 4) ? inv_<2,\
    \ mod_t, LIM> : k == 5 || (k == 1 && t != 1) ? inv_<3, mod_t, LIM> : inv_<4, mod_t,\
    \ LIM>)(pp, n, rr);\n      }\n    } else (k & 1 ? inv_<3, mod_t, LIM> : inv_<4,\
    \ mod_t, LIM>)(pp, n, rr);\n  } else\n    for (int j, i= 1; i < n; rr[i++]*= miv)\n\
    \      for (rr[j= i]= mod_t(); j--;) rr[i]+= rr[j] * pp[i - j];\n  return vector(rr,\
    \ rr + n);\n}\n}\nusing math_internal::inv_base, math_internal::inv;\n#line 4\
    \ \"src/FFT/fps_div.hpp\"\n\n/**\n * @title \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
    \ div\n * @category FFT\n */\n\n// BEGIN CUT HERE\ntemplate <class mod_t, std::size_t\
    \ _Nm = 1 << 22>\nstd::vector<mod_t> div(const std::vector<mod_t> &p,\n      \
    \                 const std::vector<mod_t> &q) {\n  using GAp = GlobalArray<mod_t,\
    \ _Nm, 0>;\n  using GAq = GlobalArray<mod_t, _Nm, 1>;\n  using GAr = GlobalArray<mod_t,\
    \ _Nm, 2>;\n  using GA = GlobalArray<mod_t, _Nm, 3>;\n  static constexpr std::size_t\
    \ _Nm2 = _Nm * 2 / 15;\n  using GNA1 = GlobalNTTArray<mod_t, _Nm2, 1>;\n  using\
    \ GNA2 = GlobalNTTArray<mod_t, _Nm2, 2>;\n  using GNA3 = GlobalNTTArray<mod_t,\
    \ _Nm2, 3>;\n  using GNA2D1 = GlobalNTTArray2D<mod_t, _Nm2, 16, 1>;\n  using GNA2D2\
    \ = GlobalNTTArray2D<mod_t, _Nm2, 16, 2>;\n  static constexpr int TH = 128 <<\
    \ (!is_nttfriend<mod_t, _Nm2>());\n  static constexpr int TH2 = 1024 << (!is_nttfriend<mod_t,\
    \ _Nm2>());\n  static constexpr int A = 7;\n  static constexpr int B = 29;\n \
    \ const int n = p.size(), len = get_len(n), R = len < TH2 ? 8 : 16;\n  const int\
    \ l = q.size(), lnR = __builtin_ctz(R);\n  std::copy(p.begin(), p.end(), GAp::bf);\n\
    \  std::copy(q.begin(), q.end(), GAq::bf);\n  const mod_t iv0 = mod_t(1) / GAq::bf[0];\n\
    \  if (l < A * __builtin_ctz(len) + B || TH >= n) {\n    for (int i = 0; i < n;\
    \ GAp::bf[i++] *= iv0)\n      for (int j = std::min(i + 1, l); --j;)\n       \
    \ GAp::bf[i] -= GAp::bf[i - j] * GAq::bf[j];\n    return std::vector<mod_t>(GAp::bf,\
    \ GAp::bf + n);\n  }\n  int m = len, i = 0;\n  while (m > TH) m >>= lnR;\n  for\
    \ (std::copy_n(GAp::bf, m, GAr::bf); i < m; GAr::bf[i++] *= iv0)\n    for (int\
    \ j = std::min(i + 1, l); --j;)\n      GAr::bf[i] -= GAr::bf[i - j] * GAq::bf[j];\n\
    \  if (l < n) std::fill(GAq::bf + l, GAq::bf + n, mod_t(0));\n  for (GA::bf[0]\
    \ = iv0, i = 1; m < n; i = m, m <<= lnR) {\n    int m2 = m << 1, ed = std::min(R,\
    \ (n + m - 1) / m), k = 1, j, mm = m;\n    inv_base<_Nm2>(GAq::bf, m, GA::bf,\
    \ i);\n    GNA1::bf.set(GA::bf, 0, m), GNA1::bf.zeros(m, m2), GNA1::bf.dft(0,\
    \ m2);\n    mod_t *bfk = GAr::bf, *qbfk = GAq::bf, *pbfk = GAp::bf;\n    GNA2D2::bf[0].set(qbfk,\
    \ 0, m), GNA2D2::bf[0].zeros(m, m2);\n    for (GNA2D2::bf[0].dft(0, m2); k < ed;\
    \ mm = std::min(m, n - m * ++k)) {\n      GNA2D1::bf[k - 1].set(bfk, 0, m), GNA2D1::bf[k\
    \ - 1].zeros(m, m2);\n      GNA2D1::bf[k - 1].dft(0, m2);\n      GNA3::bf.set(qbfk\
    \ += m, 0, m), GNA3::bf.zeros(m, m2), GNA3::bf.dft(0, m2);\n      GNA2D2::bf[k].add(GNA3::bf,\
    \ GNA2D2::bf[0], 0, m);\n      GNA2D2::bf[k].dif(GNA3::bf, GNA2D2::bf[0], m, m2),\
    \ GNA2::bf.zeros(0, m2);\n      if (k + 1 < ed) GNA2D2::bf[0].subst(GNA3::bf,\
    \ 0, m2);\n      for (j = k; j--;)\n        GNA3::bf.mul(GNA2D1::bf[j], GNA2D2::bf[k\
    \ - j], 0, m2),\n            GNA2::bf.add(GNA3::bf, 0, m2);\n      GNA2::bf.idft(0,\
    \ m2), GNA2::bf.zeros(m, m2), pbfk += m;\n      for (GNA2::bf.get(bfk += m, 0,\
    \ mm), j = mm; j--;) bfk[j] -= pbfk[j];\n      GNA2::bf.set(bfk, 0, mm);\n   \
    \   GNA2::bf.dft(0, m2), GNA2::bf.mul(GNA1::bf, 0, m2), GNA2::bf.idft(0, m2);\n\
    \      for (GNA2::bf.get(bfk, 0, mm); mm--;) bfk[mm] = -bfk[mm];\n    }\n  }\n\
    \  return std::vector<mod_t>(GAr::bf, GAr::bf + n);\n}\n#line 4 \"src/FFT/convolve.hpp\"\
    \ntemplate <class mod_t, std::size_t LIM= 1 << 22> std::vector<mod_t> convolve(const\
    \ std::vector<mod_t> &p, const std::vector<mod_t> &q) {\n  mod_t *pp= GlobalArray<mod_t,\
    \ LIM, 0>::bf, *qq= GlobalArray<mod_t, LIM, 1>::bf, *rr= GlobalArray<mod_t, LIM,\
    \ 2>::bf;\n  static constexpr int t= nttarr_cat<mod_t, LIM>, TH= (int[]){70, 30,\
    \ 70, 100, 135, 150}[t];\n  auto f= [](int l) -> int {\n    static constexpr double\
    \ B[]= {(double[]){8.288, 5.418, 7.070, 9.676, 11.713, 13.374}[t], (double[]){8.252,\
    \ 6.578, 9.283, 12.810, 13.853, 15.501}[t]};\n    return std::round(std::pow(l,\
    \ 0.535) * B[__builtin_ctz(l) & 1]);\n  };\n  const int n= p.size(), m= q.size(),\
    \ sz= n + m - 1;\n  if (!n || !m) return std::vector<mod_t>();\n  if (std::min(n,\
    \ m) < TH) {\n    std::fill_n(rr, sz, mod_t()), std::copy(p.begin(), p.end(),\
    \ pp), std::copy(q.begin(), q.end(), qq);\n    for (int i= n; i--;)\n      for\
    \ (int j= m; j--;) rr[i + j]+= pp[i] * qq[j];\n  } else {\n    const int rl= get_len(sz),\
    \ l= get_len(std::max(n, m)), fl= f(l);\n    static constexpr std::size_t LIM2=\
    \ LIM >> 3;\n    static constexpr bool b= nttarr_cat<mod_t, LIM2> < t;\n    if\
    \ (b || (l + fl < sz && sz <= (rl >> 3) * 5)) {\n      using GNA1= GlobalNTTArray<mod_t,\
    \ LIM2, 1>;\n      using GNA2= GlobalNTTArray<mod_t, LIM2, 2>;\n      auto gt1=\
    \ GlobalNTTArray2D<mod_t, LIM2, 16, 1>::bf, gt2= GlobalNTTArray2D<mod_t, LIM2,\
    \ 16, 2>::bf;\n      const int l= rl >> 4, l2= l << 1, nn= (n + l - 1) / l, mm=\
    \ (m + l - 1) / l, ss= nn + mm - 1;\n      for (int i= 0, k= 0, s; k < n; ++i,\
    \ k+= l) gt1[i].set(p.data() + k, 0, s= std::min(l, n - k)), gt1[i].zeros(s, l2),\
    \ gt1[i].dft(0, l2);\n      if (&p != &q)\n        for (int i= 0, k= 0, s; k <\
    \ m; ++i, k+= l) gt2[i].set(q.data() + k, 0, s= std::min(l, m - k)), gt2[i].zeros(s,\
    \ l2), gt2[i].dft(0, l2);\n      else\n        for (int i= nn; i--;) gt2[i].subst(gt1[i],\
    \ 0, l2);\n      GNA2::bf.mul(gt1[0], gt2[0], 0, l2), GNA2::bf.idft(0, l2), GNA2::bf.get(rr,\
    \ 0, l2);\n      for (int i= 1, k= l, j, ed; i < ss; ++i, k+= l) {\n        for\
    \ (j= std::max(0, i - nn + 1), ed= std::min(mm - 1, i), GNA2::bf.mul(gt1[i - ed],\
    \ gt2[ed], 0, l2); j < ed; ++j) GNA1::bf.mul(gt1[i - j], gt2[j], 0, l2), GNA2::bf.add(GNA1::bf,\
    \ 0, l2);\n        for (GNA2::bf.idft(0, l2), GNA2::bf.get(pp, 0, j= std::min(l,\
    \ sz - k)); j--;) rr[k + j]+= pp[j];\n        if (l < sz - k) GNA2::bf.get(rr\
    \ + k, l, std::min(l2, sz - k));\n      }\n    } else {\n      using GNA1= GlobalNTTArray<mod_t,\
    \ LIM, 1>;\n      using GNA2= GlobalNTTArray<mod_t, LIM, 2>;\n      const int\
    \ len= sz <= l + fl ? l : rl;\n      if (GNA1::bf.set(p.data(), 0, n), GNA1::bf.zeros(n,\
    \ len), GNA1::bf.dft(0, len); &p != &q) GNA2::bf.set(q.data(), 0, m), GNA2::bf.zeros(m,\
    \ len), GNA2::bf.dft(0, len), GNA1::bf.mul(GNA2::bf, 0, len);\n      else GNA1::bf.mul(GNA1::bf,\
    \ 0, len);\n      if (GNA1::bf.idft(0, len), GNA1::bf.get(rr, 0, std::min(sz,\
    \ len)); len < sz) {\n        std::copy(p.begin() + len - m + 1, p.end(), pp +\
    \ len - m + 1), std::copy(q.begin() + len - n + 1, q.end(), qq + len - n + 1);\n\
    \        for (int i= len, j; i < sz; rr[i - len]-= rr[i], ++i)\n          for\
    \ (rr[i]= mod_t(), j= i - m + 1; j < n; ++j) rr[i]+= pp[j] * qq[i - j];\n    \
    \  }\n    }\n  }\n  return std::vector(rr, rr + sz);\n}\n#line 5 \"src/FFT/Polynomial.hpp\"\
    \n\n/**\n * @title \u591A\u9805\u5F0F\n * @category FFT\n */\n\n// BEGIN CUT HERE\n\
    template <class mod_t, std::size_t _Nm = 1 << 22>\nclass Polynomial : public std::vector<mod_t>\
    \ {\n  using Poly = Polynomial;\n  struct Inde;\n  struct XP_plus_C {  // x^p+c\n\
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
    \ Z = 0;\n  static constexpr int A = 8;\n  static constexpr int B = 42;\n  std::pair<Poly,\
    \ Poly> quorem_na(const Poly &q) const {\n    int n = deg(), m = q.deg(), qsz\
    \ = n - m + 1, i = qsz, j;\n    std::copy_n(this->begin(), n + 1, GAp::bf);\n\
    \    std::copy_n(q.begin(), m + 1, GAq::bf);\n    for (mod_t *bf = GAp::bf + n\
    \ - m, iv = mod_t(1) / GAq::bf[m]; i--; bf--)\n      for (GA::bf[i] = bf[j = m]\
    \ * iv; j--;) bf[j] -= GAq::bf[j] * GA::bf[i];\n    Poly rem(GAp::bf, GAp::bf\
    \ + m);\n    return {Poly(GA::bf, GA::bf + qsz), rem.shrink()};\n  }\n  Poly quo(const\
    \ Poly &q) const {\n    const int n = deg() + 1, m = q.deg() + 1, qsz = n - m\
    \ + 1,\n              nb = this->size() - n, mb = q.size() - m;\n    auto ret\
    \ = div<mod_t, _Nm>(\n        Poly(this->rbegin() + nb, this->rbegin() + nb +\
    \ qsz),\n        Poly(q.rbegin() + mb, q.rbegin() + mb + std::min(qsz, m)));\n\
    \    return std::reverse(ret.begin(), ret.end()), ret;\n  }\n  std::pair<Poly,\
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
    \  using std::vector<mod_t>::vector;\n  Polynomial(mod_t a) : Polynomial(1, a)\
    \ {}\n  Polynomial(const std::vector<mod_t> &p) : Polynomial(p.begin(), p.end())\
    \ {}\n  Polynomial(const XP_plus_C &xpc) : Polynomial(xpc.x.pow() + 1) {\n   \
    \ (*this)[xpc.x.pow()] = 1, (*this)[0] = xpc.c;\n  }\n  static Inde x() { return\
    \ Inde(); }\n  inline int deg() const {\n    for (int n = this->size() - 1;; n--)\n\
    \      if (n < 0 || (*this)[n] != Z) return n;\n  }\n  inline Poly &shrink() {\
    \ return this->resize(std::max(deg() + 1, 1)), *this; }\n#define ASSIGN(op)  \
    \                              \\\n  Poly &operator op##=(const Poly &r) {   \
    \        \\\n    const std::size_t n = r.deg() + 1;            \\\n    if (this->size()\
    \ < n) this->resize(n);        \\\n    for (int i = n; i--;) (*this)[i] op## =\
    \ r[i]; \\\n    return shrink();                              \\\n  }\n  ASSIGN(+)\n\
    \  ASSIGN(-)\n#undef ASSIGN\n  Poly &operator*=(const Poly &r) { return *this\
    \ = *this * r, *this; }\n  Poly &operator/=(const Poly &r) { return *this = *this\
    \ / r, *this; }\n  Poly &operator%=(const Poly &r) { return *this = *this % r,\
    \ *this; }\n  Poly operator-() const { return Poly() -= *this; }\n  Poly operator+(const\
    \ Poly &r) const { return Poly(*this) += r; }\n  Poly operator-(const Poly &r)\
    \ const { return Poly(*this) -= r; }\n  Poly operator*(const Poly &r) const {\
    \ return convolve<mod_t, _Nm>(*this, r); }\n  Poly operator/(const Poly &r) const\
    \ {\n    const int m = r.deg(), qsz = deg() - m + 1,\n              ln = __builtin_ctz(get_len(qsz));\n\
    \    assert(m >= 0);\n    if (qsz <= 0) return Poly{Z};\n    return m + 3 < A\
    \ * ln + B || qsz <= 64 ? quorem_na(r).first : quo(r);\n  }\n  std::pair<Poly,\
    \ Poly> quorem(const Poly &r) const {\n    const int n = deg(), m = r.deg(), qsz\
    \ = n - m + 1,\n              ln = __builtin_ctz(get_len(qsz));\n    assert(m\
    \ >= 0);\n    if (qsz <= 0) return {Poly{Z}, Poly(this->begin(), this->begin()\
    \ + n + 1)};\n    return m < A * ln + B || qsz <= 64 ? quorem_na(r) : quorem_ntt(r);\n\
    \  }\n  Poly operator%(const Poly &r) const { return quorem(r).second; }\n  Poly\
    \ &operator+=(const mod_t r) { return (*this)[0] += r, *this; }\n  Poly &operator-=(const\
    \ mod_t r) { return (*this)[0] -= r, *this; }\n  Poly &operator*=(const mod_t\
    \ r) {\n    for (mod_t &c : *this) c *= r;\n    return shrink();\n  }\n  Poly\
    \ &operator/=(const mod_t r) {\n    for (mod_t &c : *this) c /= r;\n    return\
    \ shrink();\n  }\n  Poly operator+(const mod_t r) { return Poly(*this) += r; }\n\
    \  Poly operator-(const mod_t r) { return Poly(*this) -= r; }\n  Poly operator*(const\
    \ mod_t r) { return Poly(*this) *= r; }\n  Poly operator/(const mod_t r) { return\
    \ Poly(*this) /= r; }\n  friend Poly operator+(const mod_t l, Poly r) { return\
    \ r += l; }\n  friend Poly operator-(const mod_t l, Poly r) { return -(r -= l);\
    \ }\n  friend Poly operator*(const mod_t l, Poly r) { return r *= l; }\n  mod_t\
    \ operator()(mod_t c) const {  // eval f(c)\n    if (c == Z) return (*this)[0];\n\
    \    mod_t ret = 0;\n    for (int i = deg() + 1; i--;) ret *= c, ret += (*this)[i];\n\
    \    return ret;\n  }\n  Poly operator()(const XP_plus_C &xpc) const {  // f(x^p+c)\n\
    \    return taylor_shift(xpc.c).scale(xpc.x.pow());\n  }\n  Poly operator()(const\
    \ Poly &q) const {  // f(g) mod x^n\n    const int n = this->deg() + 1, k = std::ceil(std::sqrt(n));\n\
    \    std::vector<Poly> pw1(k + 1), pw2(k + 1);\n    if (pw1[0] = {1}, pw1[1] =\
    \ q; q.size() > n) pw1[1].resize(n);\n    for (int i = 2; i <= k; ++i)\n     \
    \ if (pw1[i] = pw1[i - 1] * pw1[1]; pw1[i].size() > n) pw1[i].resize(n);\n   \
    \ pw2[0] = {1}, pw2[1] = pw1[k];\n    for (int i = 2; i <= k; ++i)\n      if (pw2[i]\
    \ = pw2[i - 1] * pw2[1]; pw2[i].size() > n) pw2[i].resize(n);\n    Poly ret(n,\
    \ Z), f;\n    for (int i = 0, j; i <= k; ++i) {\n      for (f.assign(n, Z), j\
    \ = std::min(k, std::max(0, n - k * i)); j--;) {\n        mod_t coef = (*this)[k\
    \ * i + j];\n        for (int d = pw1[j].size(); d--;) f[d] += pw1[j][d] * coef;\n\
    \      }\n      for (f *= pw2[i], j = std::min<int>(n, f.size()); j--;) ret[j]\
    \ += f[j];\n    }\n    return ret;\n  }\n  Poly &operator*=(const XP_plus_C &xpc)\
    \ {\n    Poly q;\n    if (xpc.c != Z) q = *this * xpc.c;\n    return this->insert(this->begin(),\
    \ xpc.x.pow(), Z), *this += q;\n  }\n  Poly operator*(const XP_plus_C &xpc) const\
    \ { return Poly(*this) *= xpc; }\n  friend Poly operator*(const XP_plus_C &xpc,\
    \ const Poly &p) { return p * xpc; }\n  Poly scale(int k) const {\n    const int\
    \ n = deg();\n    Poly ret(n * k + 1, Z);\n    for (int i = 0; i <= n; i++) ret[i\
    \ * k] += (*this)[i];\n    return ret;\n  }\n  Poly taylor_shift(mod_t c) const\
    \ {\n    int n = deg(), i = 0;\n    if (n < 1 || c == Z) return Poly(*this);\n\
    \    mod_t cpw = 1, fact = 1;\n    for (; i <= n; fact *= ++i) GAp::bf[n - i]\
    \ = (*this)[i] * fact;\n    for (fact = mod_t(1) / fact; i--;) GA3::bf[i] = (fact\
    \ *= i + 1);\n    for (; ++i <= n;) GAq::bf[i] = cpw * GA3::bf[i], cpw *= c;\n\
    \    auto ret = Poly(GAp::bf, GAp::bf + n + 1) * Poly(GAq::bf, GAq::bf + n + 1);\n\
    \    for (ret.resize(n + 1), std::reverse(ret.begin(), ret.end()); i--;)\n   \
    \   ret[i] *= GA3::bf[i];\n    return ret;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const Poly &p) {\n    if (p.deg() == -1) return os << 0;\n    for (int\
    \ i = 0, e = p.deg(); i <= e; i++) {\n      if (p[i] == Z) continue;\n      if\
    \ (i == 0 || p[i] != mod_t(1)) os << p[i];\n      if (i >= 1) os << 'x';\n   \
    \   if (i > 9)\n        os << \"^(\" << i << ')';\n      else if (i > 1)\n   \
    \     os << '^' << i;\n      if (i + 1 <= e) os << \" + \";\n    }\n    return\
    \ os;\n  }\n};\n\n#define __POLYNOMIAL Polynomial<mod_t, _Nm>\n#ifdef __FPS_DIVAT\n\
    __FPS_DIVAT(__POLYNOMIAL)\n#endif\n#line 5 \"test/yosupo/shift_of_FPS.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using Poly = Polynomial<Mint>;\n \
    \ int N, c;\n  cin >> N >> c;\n  Poly a(N);\n  for (int i = 0; i < N; i++) cin\
    \ >> a[i];\n  auto x = Poly::x();\n  auto b = a(x + c);\n  b.resize(N);\n  for\
    \ (int i = 0; i < N; i++) cout << b[i] << \" \\n\"[i == N - 1];\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/FFT/Polynomial.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using Poly = Polynomial<Mint>;\n \
    \ int N, c;\n  cin >> N >> c;\n  Poly a(N);\n  for (int i = 0; i < N; i++) cin\
    \ >> a[i];\n  auto x = Poly::x();\n  auto b = a(x + c);\n  b.resize(N);\n  for\
    \ (int i = 0; i < N; i++) cout << b[i] << \" \\n\"[i == N - 1];\n  return 0;\n\
    }"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/FFT/Polynomial.hpp
  - src/FFT/fps_div.hpp
  - src/FFT/fps_inv.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  - src/FFT/convolve.hpp
  isVerificationFile: true
  path: test/yosupo/shift_of_FPS.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 01:36:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/shift_of_FPS.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shift_of_FPS.test.cpp
- /verify/test/yosupo/shift_of_FPS.test.cpp.html
title: test/yosupo/shift_of_FPS.test.cpp
---
