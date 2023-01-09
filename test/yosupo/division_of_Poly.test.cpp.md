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
    PROBLEM: https://judge.yosupo.jp/problem/division_of_polynomials
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "#line 1 \"test/yosupo/division_of_Poly.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/division_of_polynomials\"\n#include <bits/stdc++.h>\n\
    \n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y *\
    \ (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo {\n const\
    \ u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr MP_Mo(u64\
    \ m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline u64 mul(u64\
    \ l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op, a) return l\
    \ op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64 l, u64\
    \ r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64 l, u64\
    \ r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n) const\
    \ { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64 ret=\
    \ reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr inline\
    \ u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n const\
    \ u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e ? inv(n,\
    \ e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const u128& w)\
    \ const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64); }\n};\n\
    template <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\n\
    struct m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t>\
    \ CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64 MOD>\
    \ struct SB: s_b {\nprotected:\n static CE mpt md= mpt(MOD);\n};\ntemplate <class\
    \ mpt, int id> struct RB: r_b {\n static inline void set_mod(u64 m) { md= mpt(m);\
    \ }\nprotected:\n static inline mpt md;\n};\ntemplate <class Int, class U, class\
    \ B> struct MInt: public B {\n using Uint= U;\n static CE inline auto mod() {\
    \ return B::md.mod; }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n\
    \ template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T\
    \ v): x(B::md.set(v.val() % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod\
    \ - (-n) % B::md.mod : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using StaticModInt=\
    \ conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>, MOD>>, conditional_t<MOD&(MOD\
    \ < LLONG_MAX), MInt<i64, u64, SB<MP_Mo, MOD>>, MInt<i64, u64, SB<MP_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id= -1> using RuntimeModInt=\
    \ conditional_t<is_same_v<Int, Montgomery>, MInt<i64, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ i64>, is_same<Int, u64>>, MInt<i64, u64, RB<MP_Na<u64>, id>>, MInt<int, u32,\
    \ RB<MP_Na<u32>, id>>>>;\n#undef CE\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Montgomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LIM> mod_t\
    \ get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m=\
    \ mod_t::mod();\n static mod_t dat[LIM];\n static int l= 1;\n if (l == 1) dat[l++]=\
    \ 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n\
    #line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate <class\
    \ Uint, class mod_pro_t, u64... args> constexpr bool miller_rabin(Uint n) {\n\
    \ const mod_pro_t md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one=\
    \ md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...})\n  if (Uint\
    \ b= a % n; b)\n   if (Uint p= md.norm(pow(md.set(b), d, md)); p != one)\n   \
    \ for (int i= s; p != n1; p= md.norm(md.mul(p, p)))\n     if (!(--i)) return 0;\n\
    \ return 1;\n}\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n % 6 % 4 != 1)\
    \ return (n | 1) == 3;\n if (n < UINT_MAX) return miller_rabin<u32, MP_Na<u32>,\
    \ 2, 7, 61>(n);\n if (n < (LLONG_MAX >> 1)) return miller_rabin<u64, MP_Mo, 2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64,\
    \ MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing\
    \ math_internal::is_prime;\n#line 5 \"src/FFT/NTT.hpp\"\nnamespace math_internal\
    \ {\n#define CE constexpr\n#define ST static\n#define TP template\n#define BSF(_,\
    \ n) __builtin_ctz##_(n)\nTP<class mod_t> struct NTT {\n#define FOR(a, b, c) \\\
    \n for (a= n >> 2; a; a>>= 2, b<<= 2) \\\n  for (y= u= r= I, x0= x, s= 0;; r*=\
    \ c[BSF(, s)], u= r * r, y= u * r, x0= x3 + p)\n#define FOR2(a, b, c) \\\n for\
    \ (a= n; a>>= 1; b<<= 1) \\\n  for (s= 0, r= I, x0= x;; r*= c[BSF(, s)], x0= x1\
    \ + p)\n#define REP for (x1= x0 + p, x2= x1 + p, x3= x2 + (i= p); i--;)\n ST inline\
    \ void dft(int n, mod_t x[]) {\n  int p, e= 1, s, i;\n  mod_t r, u, y, *x0, *x1,\
    \ *x2, *x3;\n  if CE (md < INT_MAX) {\n   ST CE auto r3= ras<3>(rt, irt);\n  \
    \ ST CE u128 im= rt[2].val(), md3= u128(md) << 93;\n   FOR(p, e, r3) {\n    u64\
    \ ru= r.val(), ru2= u.val(), ru3= y.val();\n    REP {\n     u64 a= x0[i].val(),\
    \ b= ru * x1[i].val(), c= ru2 * x2[i].val(), d= ru3 * x3[i].val(), f= md2 - d,\
    \ g= md2 + a - c;\n     u128 h= im * (b + f);\n     x0[i]= a + b + c + d, x1[i]=\
    \ a + (md2 - b) + c + f, x2[i]= h + g, x3[i]= md3 - h + g;\n    }\n    if (++s\
    \ == e) break;\n   }\n   if (BSF(, n) & 1)\n    for (r= I, s= 0, p= 0;; r*= r2[BSF(,\
    \ ++s)])\n     if (x[p + 1]= x[p] - (u= x[p + 1] * r), x[p]+= u; (p+= 2) == n)\
    \ break;\n  } else FOR2(p, e, r2) {\n    for (x1= x0 + (i= p); i--;) x1[i]= x0[i]\
    \ - (u= r * x1[i]), x0[i]+= u;\n    if (++s == e) break;\n   }\n }\n ST inline\
    \ void idft(int n, mod_t x[]) {\n  int e, p= 1, s, i;\n  mod_t r, u, y, *x0, *x1,\
    \ *x2, *x3;\n  if CE (md < INT_MAX) {\n   ST CE auto ir3= ras<3>(irt, rt);\n \
    \  ST CE u64 im= irt[2].val();\n   FOR(e, p, ir3) {\n    u64 ru2= u.val();\n \
    \   u128 ru= r.val(), ru3= y.val();\n    REP {\n     u64 a= x0[i].val(), b= x1[i].val(),\
    \ c= x2[i].val(), d= x3[i].val(), f= md - d, g= a + md - b, h= im * (c + f);\n\
    \     x0[i]= a + b + c + d, x1[i]= ru * (g + h), x2[i]= ru2 * (a + b + (md - c)\
    \ + f), x3[i]= ru3 * (g + (md2 << 1) - h);\n    }\n    if (++s == e) break;\n\
    \   }\n   if (BSF(, n) & 1)\n    for (x1= x + (i= n >> 1); i--;) u= x[i] - x1[i],\
    \ x[i]+= x1[i], x1[i]= u;\n  } else FOR2(e, p, ir2) {\n    for (x1= x0 + (i= p);\
    \ i--;) u= x0[i] - x1[i], x0[i]+= x1[i], x1[i]= r * u;\n    if (++s == e) break;\n\
    \   }\n  for (const mod_t iv= I / n; n--;) x[n]*= iv;\n }\n#undef FOR\n#undef\
    \ FOR2\n#undef REP\n ST inline void even_dft(int n, mod_t x[]) {\n  for (int i=\
    \ 0, j= 0; i < n; i+= 2) x[j++]= iv2 * (x[i] + x[i + 1]);\n }\n ST inline void\
    \ odd_dft(int n, mod_t x[], mod_t r= iv2) {\n  for (int i= 0, j= 0;; r*= ir2[BSF(,\
    \ ++j)])\n   if (x[j]= r * (x[i] - x[i + 1]); (i+= 2) == n) break;\n }\n ST inline\
    \ void dft_doubling(int n, mod_t x[], int i= 0) {\n  mod_t k= I, t= rt[BSF(, n\
    \ << 1)];\n  for (copy_n(x, n, x + n), idft(n, x + n); i < n; ++i) x[n + i]*=\
    \ k, k*= t;\n  dft(n, x + n);\n }\nprotected:\n ST CE u64 md= mod_t::mod(), md2=\
    \ md << 31;\n static_assert(md & 1);\n static_assert(is_prime(md));\n ST CE u8\
    \ E= BSF(ll, md - 1);\n ST CE mod_t w= [](u8 e) {\n  for (mod_t r= 2;; r+= 1)\n\
    \   if (auto s= r.pow((md - 1) / 2); s != 1 && s * s == 1) return r.pow((md -\
    \ 1) >> e);\n  return mod_t();\n }(E);\n static_assert(w != mod_t());\n ST CE\
    \ mod_t I= 1, iv2= (md + 1) / 2, iw= w.pow((1ULL << E) - 1);\n ST CE auto roots(mod_t\
    \ w) {\n  array<mod_t, E + 1> x= {};\n  for (u8 e= E; e; w*= w) x[e--]= w;\n \
    \ return x[0]= w, x;\n }\n TP<u32 N> ST CE auto ras(const array<mod_t, E + 1>\
    \ &rt, const array<mod_t, E + 1> &irt, int i= N) {\n  array<mod_t, E + 1 - N>\
    \ x= {};\n  for (mod_t ro= 1; i <= E; ro*= irt[i++]) x[i - N]= rt[i] * ro;\n \
    \ return x;\n }\n ST CE auto rt= roots(w), irt= roots(iw);\n ST CE auto r2= ras<2>(rt,\
    \ irt), ir2= ras<2>(irt, rt);\n};\nTP<class T, u8 t, class B> struct NI: public\
    \ B {\n using B::B;\n#define FUNC(op, name, HG, ...) \\\n inline void name(__VA_ARGS__)\
    \ { \\\n  HG(op, 1); \\\n  if CE (t > 1) HG(op, 2); \\\n  if CE (t > 2) HG(op,\
    \ 3); \\\n  if CE (t > 3) HG(op, 4); \\\n  if CE (t > 4) HG(op, 5); \\\n }\n#define\
    \ REP for (int i= b; i < e; ++i)\n#define DFT(fft, _) B::ntt##_::fft(e - b, this->dt##_\
    \ + b)\n#define ZEROS(op, _) fill_n(this->dt##_ + b, e - b, typename B::m##_())\n\
    #define SET(op, _) copy(x + b, x + e, this->dt##_ + b)\n#define SET_S(op, _) this->dt##_[i]=\
    \ x;\n#define SUBST(op, _) copy(r.dt##_ + b, r.dt##_ + e, this->dt##_ + b)\n#define\
    \ ASGN(op, _) REP this->dt##_[i] op##= r.dt##_[i]\n#define ASN(nm, op) TP<class\
    \ C> FUNC(op, nm, ASGN, const NI<T, t, C> &r, int b, int e)\n#define BOP(op, _)\
    \ REP this->dt##_[i]= l.dt##_[i] op r.dt##_[i]\n#define OP(nm, op) TP<class C,\
    \ class D> FUNC(op, nm, BOP, const NI<T, t, C> &l, const NI<T, t, D> &r, int b,\
    \ int e)\n OP(add, +) OP(dif, -) OP(mul, *) ASN(add, +) ASN(dif, -) ASN(mul, *)\
    \ FUNC(dft, dft, DFT, int b, int e) FUNC(idft, idft, DFT, int b, int e) FUNC(__,\
    \ zeros, ZEROS, int b, int e) FUNC(__, set, SET, const T x[], int b, int e) FUNC(__,\
    \ set, SET_S, int i, T x) TP<class C> FUNC(__, subst, SUBST, const NI<T, t, C>\
    \ &r, int b, int e) inline void get(T x[], int b, int e) const {\n  if CE (t ==\
    \ 1) copy(this->dt1 + b, this->dt1 + e, x + b);\n  else REP x[i]= get(i);\n }\n\
    #define TMP(_) B::iv##_##1 * (this->dt##_[i] - r1)\n inline T get(int i) const\
    \ {\n  if CE (t > 1) {\n   u64 r1= this->dt1[i].val(), r2= (TMP(2)).val();\n \
    \  T a= 0;\n   if CE (t > 2) {\n    u64 r3= (TMP(3) - B::iv32 * r2).val();\n \
    \   if CE (t > 3) {\n     u64 r4= (TMP(4) - B::iv42 * r2 - B::iv43 * r3).val();\n\
    \     if CE (t > 4) a= T(B::m4::mod()) * (TMP(5) - B::iv52 * r2 - B::iv53 * r3\
    \ - B::iv54 * r4).val();\n     a= (a + r4) * B::m3::mod();\n    }\n    a= (a +\
    \ r3) * B::m2::mod();\n   }\n   return (a + r2) * B::m1::mod() + r1;\n  } else\
    \ return this->dt1[i];\n }\n#undef TMP\n#undef DFT\n#undef ZEROS\n#undef SET\n\
    #undef SET_S\n#undef SUBST\n#undef ASGN\n#undef ASN\n#undef BOP\n#undef OP\n#undef\
    \ FUNC\n#undef REP\n};\n#define ARR(_) \\\n using m##_= StaticModInt<M##_>; \\\
    \n using ntt##_= NTT<m##_>; \\\n m##_ dt##_[LM]= {};\n#define IV2 ST CE m2 iv21=\
    \ m2(1) / m1::mod();\n#define IV3 ST CE m3 iv32= m3(1) / m2::mod(), iv31= iv32\
    \ / m1::mod();\n#define IV4 ST CE m4 iv43= m4(1) / m3::mod(), iv42= iv43 / m2::mod(),\
    \ iv41= iv42 / m1::mod();\n#define IV5 ST CE m5 iv54= m5(1) / m4::mod(), iv53=\
    \ iv54 / m3::mod(), iv52= iv53 / m2::mod(), iv51= iv52 / m1::mod();\nTP<u8 t,\
    \ u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM, bool v> struct NB { ARR(1) };\n\
    TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4,\
    \ M5, LM, 0> { ARR(1) ARR(2) IV2 };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5,\
    \ u32 LM> struct NB<3, M1, M2, M3, M4, M5, LM, 0> { ARR(1) ARR(2) ARR(3) IV2 IV3\
    \ };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4, M1, M2,\
    \ M3, M4, M5, LM, 0> { ARR(1) ARR(2) ARR(3) ARR(4) IV2 IV3 IV4 };\nTP<u64 M1,\
    \ u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5, LM,\
    \ 0> { ARR(1) ARR(2) ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5 };\n#undef ARR\n#define\
    \ VC(_) \\\n using m##_= StaticModInt<M##_>; \\\n using ntt##_= NTT<m##_>; \\\n\
    \ vector<m##_> bf##_; \\\n m##_ *dt##_;\n#define RS resize\nTP<u64 M1, u32 M2,\
    \ u32 M3, u32 M4, u32 M5, u32 LM> struct NB<1, M1, M2, M3, M4, M5, LM, 1> {\n\
    \ NB(): dt1(bf1.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(); }\n\
    \ u32 size() const { return bf1.size(); }\n VC(1)\n};\nTP<u64 M1, u32 M2, u32\
    \ M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4, M5, LM, 1> {\n NB():\
    \ dt1(bf1.data()), dt2(bf2.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(),\
    \ bf2.RS(n), dt2= bf2.data(); }\n u32 size() const { return bf1.size(); }\n VC(1)\
    \ VC(2) IV2\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<3,\
    \ M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data())\
    \ {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(),\
    \ bf3.RS(n), dt3= bf3.data(); }\n u32 size() const { return bf1.size(); }\n VC(1)\
    \ VC(2) VC(3) IV2 IV3\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM>\
    \ struct NB<4, M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()),\
    \ dt3(bf3.data()), dt4(bf4.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(),\
    \ bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data();\
    \ }\n u32 size() const { return bf1.size(); }\n VC(1) VC(2) VC(3) VC(4) IV2 IV3\
    \ IV4\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1,\
    \ M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()),\
    \ dt4(bf4.data()), dt5(bf5.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(),\
    \ bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(),\
    \ bf5.RS(n), dt5= bf5.data(); }\n u32 size() const { return bf1.size(); }\n VC(1)\
    \ VC(2) VC(3) VC(4) VC(5) IV2 IV3 IV4 IV5\n};\n#undef VC\n#undef IV2\n#undef IV3\n\
    #undef IV4\n#undef IV5\nTP<class T, u32 LM> CE bool is_nttfriend() {\n if CE (!is_staticmodint_v<T>)\
    \ return 0;\n else return (T::mod() & is_prime(T::mod())) && LM <= (1ULL << BSF(ll,\
    \ T::mod() - 1));\n}\nTP<class T> CE u64 mv() {\n if CE (is_runtimemodint_v<T>)\
    \ return numeric_limits<typename T::Uint>::max();\n else if CE (is_staticmodint_v<T>)\
    \ return T::mod();\n else return numeric_limits<T>::max();\n}\nTP<class T, u32\
    \ LM, u32 M1, u32 M2, u32 M3, u32 M4> CE u8 nt() {\n if CE (!is_nttfriend<T, LM>())\
    \ {\n  CE u128 m= mv<T>(), mv= m * m;\n  if CE (mv <= M1 / LM) return 1;\n  else\
    \ if CE (mv <= u64(M1) * M2 / LM) return 2;\n  else if CE (mv <= u128(M1) * M2\
    \ * M3 / LM) return 3;\n  else if CE (mv <= u128(M1) * M2 * M3 * M4 / LM) return\
    \ 4;\n  else return 5;\n } else return 1;\n}\n#undef BSF\n#undef RS\nCE u32 MOD1=\
    \ 0x7e000001, MOD2= 0x78000001, MOD3= 0x6c000001, MOD4= 0x66000001, MOD5= 0x42000001;\n\
    TP<class T, u32 LM> CE u8 nttarr_type= nt<T, LM, MOD1, MOD2, MOD3, MOD4>();\n\
    TP<class T, u32 LM> CE u8 nttarr_cat= is_nttfriend<T, LM>() && (mv<T>() > INT_MAX)\
    \ ? 0 : nttarr_type<T, LM>;\nTP<class T, u32 LM, bool v> using NTTArray= NI<T,\
    \ nttarr_type<T, LM>, conditional_t<is_nttfriend<T, LM>(), NB<1, mv<T>(), 0, 0,\
    \ 0, 0, LM, v>, NB<nttarr_type<T, LM>, MOD1, MOD2, MOD3, MOD4, MOD5, LM, v>>>;\n\
    #undef CE\n#undef ST\n#undef TP\n}\nusing math_internal::is_nttfriend, math_internal::nttarr_type,\
    \ math_internal::nttarr_cat, math_internal::NTT, math_internal::NTTArray;\ntemplate\
    \ <class T, size_t LM, int id= 0> struct GlobalNTTArray { static inline NTTArray<T,\
    \ LM, 0> bf; };\ntemplate <class T, size_t LM, size_t LM2, int id= 0> struct GlobalNTTArray2D\
    \ { static inline NTTArray<T, LM, 0> bf[LM2]; };\ntemplate <class T, size_t LM,\
    \ int id= 0> struct GlobalArray { static inline T bf[LM]; };\nconstexpr unsigned\
    \ pw2(unsigned n) { return --n, n|= n >> 1, n|= n >> 2, n|= n >> 4, n|= n >> 8,\
    \ n|= n >> 16, ++n; }\n#line 4 \"src/FFT/fps_inv.hpp\"\nnamespace math_internal\
    \ {\ntemplate <u32 LM, class mod_t> inline void inv_base(const mod_t p[], int\
    \ n, mod_t r[], int i= 1, int l= -1) {\n static constexpr int t= nttarr_cat<mod_t,\
    \ LM>, TH= (int[]){64, 32, 64, 128, 128, 256}[t];\n if (n <= i) return;\n if (l\
    \ < 0) l= n;\n assert(((n & -n) == n)), assert(i && ((i & -i) == i));\n if (const\
    \ mod_t miv= -r[0]; n > TH) {\n  static constexpr int lnR= 2 + (!t), LM2= LM >>\
    \ (lnR - 1), R= (1 << lnR) - 1;\n  const auto [m, skip]= [&]() {\n   if constexpr\
    \ (!t) {\n    const int bn= __builtin_ctz(n) % 3;\n    return bn ? make_pair(64,\
    \ bn) : make_pair(32, 1);\n   } else return make_pair(TH, 1 + (__builtin_ctz(TH)\
    \ & 1));\n  }();\n  for (int j; i < m; r[i++]*= miv)\n   for (r[i]= mod_t(), j=\
    \ min(i + 1, l); --j;) r[i]+= r[i - j] * p[j];\n  using GNA1= GlobalNTTArray<mod_t,\
    \ LM2, 1>;\n  using GNA2= GlobalNTTArray<mod_t, LM2, 2>;\n  auto gt1= GlobalNTTArray2D<mod_t,\
    \ LM2, R, 1>::bf, gt2= GlobalNTTArray2D<mod_t, LM2, R, 2>::bf;\n  for (int ed=\
    \ (1 << skip) - 1; i < n; ed= R) {\n   mod_t* rr= r;\n   const mod_t* pp= p;\n\
    \   const int s= i, e= s << 1, ss= (l - 1) / s;\n   for (int k= 0, j; i < n &&\
    \ k < ed; ++k, i+= s, pp+= s) {\n    if (j= min(e, l - k * s); j > 0) gt2[k].set(pp,\
    \ 0, j), gt2[k].zeros(j, e), gt2[k].dft(0, e);\n    for (gt1[k].set(rr, 0, s),\
    \ gt1[k].zeros(s, e), gt1[k].dft(0, e), GNA2::bf.mul(gt1[k], gt2[0], 0, e), j=\
    \ min(k, ss) + 1; --j;) GNA1::bf.mul(gt1[k - j], gt2[j], 0, e), GNA2::bf.add(GNA1::bf,\
    \ 0, e);\n    GNA2::bf.idft(0, e), GNA2::bf.zeros(0, s);\n    if constexpr (!is_nttfriend<mod_t,\
    \ LM2>()) GNA2::bf.get(rr, s, e), GNA2::bf.set(rr, s, e);\n    for (GNA2::bf.dft(0,\
    \ e), GNA2::bf.mul(gt1[0], 0, e), GNA2::bf.idft(0, e), GNA2::bf.get(rr, s, e),\
    \ rr+= s, j= s; j--;) rr[j]= -rr[j];\n   }\n  }\n } else\n  for (int j; i < n;\
    \ r[i++]*= miv)\n   for (r[i]= mod_t(), j= min(i + 1, l); --j;) r[i]+= r[i - j]\
    \ * p[j];\n}\ntemplate <u32 lnR, class mod_t, u32 LM= 1 << 22> void inv_(const\
    \ mod_t p[], int n, mod_t r[]) {\n static constexpr u32 R= (1 << lnR) - 1, LM2=\
    \ LM >> (lnR - 1);\n using GNA1= GlobalNTTArray<mod_t, LM2, 1>;\n using GNA2=\
    \ GlobalNTTArray<mod_t, LM2, 2>;\n auto gt1= GlobalNTTArray2D<mod_t, LM2, R, 1>::bf,\
    \ gt2= GlobalNTTArray2D<mod_t, LM2, R, 2>::bf;\n assert(n > 0), assert(p[0] !=\
    \ mod_t());\n const int m= pw2(n) >> lnR, m2= m << 1, ed= (n - 1) / m;\n inv_base<LM2>(p,\
    \ m, r);\n for (int k= 0, l; k < ed; p+= m) {\n  for (gt2[k].set(p, 0, l= min(m2,\
    \ n - m * k)), gt2[k].zeros(l, m2), gt2[k].dft(0, m2), gt1[k].set(r, 0, m), gt1[k].zeros(m,\
    \ m2), gt1[k].dft(0, m2), GNA2::bf.mul(gt1[k], gt2[0], 0, m2), l= k; l--;) GNA1::bf.mul(gt1[l],\
    \ gt2[k - l], 0, m2), GNA2::bf.add(GNA1::bf, 0, m2);\n  GNA2::bf.idft(0, m2),\
    \ GNA2::bf.zeros(0, m);\n  if constexpr (!is_nttfriend<mod_t, LM2>()) GNA2::bf.get(r,\
    \ m, m2), GNA2::bf.set(r, m, m2);\n  for (GNA2::bf.dft(0, m2), GNA2::bf.mul(gt1[0],\
    \ 0, m2), GNA2::bf.idft(0, m2), GNA2::bf.get(r, m, m + (l= min(m, n - m * ++k))),\
    \ r+= m; l--;) r[l]= -r[l];\n }\n}\ntemplate <class mod_t, u32 LM= 1 << 22> vector<mod_t>\
    \ inv(const vector<mod_t>& p) {\n static constexpr int t= nttarr_cat<mod_t, LM>,\
    \ TH= (int[]){102, 60, 178, 245, 370, 480}[t];\n mod_t *pp= GlobalArray<mod_t,\
    \ LM, 1>::bf, *r= GlobalArray<mod_t, LM, 2>::bf;\n const int n= p.size();\n copy_n(p.begin(),\
    \ n, pp), assert(n > 0), assert(p[0] != mod_t());\n if (const mod_t miv= -(r[0]=\
    \ mod_t(1) / p[0]); n > TH) {\n  const int l= pw2(n), l1= l >> 1, k= (n - l1 -\
    \ 1) / (l1 >> 3), bl= __builtin_ctz(l1);\n  int a= 4;\n  if constexpr (!t) a=\
    \ bl < 7 ? k > 5 ? 1 : k > 4 ? 3 : k > 3 ? 4 : 2 : k & 1 ? 3 : 4;\n  else if constexpr\
    \ (t < 2) a= bl & 1 ? k > 5 ? 1 : bl < 8 ? 3 : bl < 12 ? k > 2 || k == 1 ? 3 :\
    \ 4 : k & 1 ? 3 : 4 : k > 5 ? bl > 17 && k < 7 ? 4 : 2 : k > 4 ? 3 : k > 3 ? 4\
    \ : bl < 7 ? k > 1 ? 2 : k ? 3 : 4 : k > 2 ? 2 : 4;\n  else if constexpr (t <\
    \ 3) a= bl & 1 ? k > 5 ? 1 : bl < 8 ? k > 3 || k < 2 ? 3 : 2 : k & 1 ? 3 : 4 :\
    \ k > 5 ? bl > 13 && k < 7 ? 4 : 2 : k == 3 ? 2 : k & 1 ? 3 : 4;\n  else if constexpr\
    \ (t < 5) a= bl & 1 ? k > 5 ? 1 : k == 1 ? 3 : k < 3 ? 4 : bl > 12 && k == 4 ?\
    \ 4 : 3 : k > 5 ? bl > 13 && k < 7 ? 4 : 2 : k > 4 ? 3 : k > 3 ? 4 : bl < 9 ?\
    \ k > 1 ? 2 : k ? 3 : 4 : k > 2 ? 2 : 4;\n  else a= bl & 1 ? k > 5 ? 1 : bl <\
    \ 10 ? k > 3 || k < 2 ? 3 : 2 : k & 1 ? 3 : 4 : bl < 9 ? k > 3 ? 1 : 2 : k > 5\
    \ ? bl > 13 && k < 7 ? 4 : 2 : k == 3 ? 2 : k & 1 ? 3 : 4;\n  (a < 2 ? inv_<1,\
    \ mod_t, LM> : a < 3 ? inv_<2, mod_t, LM> : a < 4 ? inv_<3, mod_t, LM> : inv_<4,\
    \ mod_t, LM>)(pp, n, r);\n } else\n  for (int j, i= 1; i < n; r[i++]*= miv)\n\
    \   for (r[j= i]= mod_t(); j--;) r[i]+= r[j] * pp[i - j];\n return vector(r, r\
    \ + n);\n}\n}\nusing math_internal::inv_base, math_internal::inv;\n#line 4 \"\
    src/FFT/fps_div.hpp\"\nnamespace math_internal {\ntemplate <int TH, int lnR, int\
    \ skip, size_t LIM, class mod_t> void div_base_(const mod_t p[], int n, const\
    \ mod_t q[], int l, mod_t r[], const mod_t iv[]) {\n static constexpr int LIM2=\
    \ LIM >> (lnR - 1), R= (1 << lnR) - 1;\n using GNA1= GlobalNTTArray<mod_t, LIM2,\
    \ 1>;\n using GNA2= GlobalNTTArray<mod_t, LIM2, 2>;\n using GNA3= GlobalNTTArray<mod_t,\
    \ LIM2, 3>;\n auto gt1= GlobalNTTArray2D<mod_t, LIM2, R, 1>::bf;\n auto gt2= GlobalNTTArray2D<mod_t,\
    \ LIM2, R, 2>::bf;\n assert(n > 0), assert(((n & -n) == n)), assert(l > 0);\n\
    \ const mod_t iv0= iv[0];\n int i= 0;\n for (copy_n(p, TH, r); i < TH; r[i++]*=\
    \ iv0)\n  for (int j= min(i + 1, l); --j;) r[i]-= r[i - j] * q[j];\n for (int\
    \ ed= (1 << skip) - 1; i < n; ed= R) {\n  mod_t* rr= r;\n  const mod_t *qq= q,\
    \ *pp= p;\n  const int s= i, e= s << 1, ss= (l - 1) / s;\n  GNA3::bf.set(iv, 0,\
    \ s), GNA3::bf.zeros(s, e), GNA3::bf.dft(0, e);\n  for (int k= 0, j; i < n &&\
    \ k < ed; ++k, i+= s, qq+= s, pp+= s) {\n   if (j= min(e, l - k * s); j > 0) gt2[k].set(qq,\
    \ 0, j), gt2[k].zeros(j, e), gt2[k].dft(0, e);\n   gt1[k].set(rr, 0, s), gt1[k].zeros(s,\
    \ e), gt1[k].dft(0, e);\n   for (GNA2::bf.mul(gt1[k], gt2[0], 0, e), j= min(k,\
    \ ss) + 1; --j;) GNA1::bf.mul(gt1[k - j], gt2[j], 0, e), GNA2::bf.add(GNA1::bf,\
    \ 0, e);\n   GNA2::bf.idft(0, e), GNA2::bf.zeros(0, s), GNA2::bf.get(rr, s, e);\n\
    \   for (j= s; j < e; ++j) rr[j]-= pp[j];\n   GNA2::bf.set(rr, s, e), GNA2::bf.dft(0,\
    \ e), GNA2::bf.mul(GNA3::bf, 0, e);\n   GNA2::bf.idft(0, e), GNA2::bf.get(rr,\
    \ s, e);\n   for (rr+= s, j= s; j--;) rr[j]= -rr[j];\n  }\n }\n}\ntemplate <size_t\
    \ LIM, class mod_t> void div_base(const mod_t p[], int n, const mod_t q[], int\
    \ l, mod_t r[], const mod_t iv[]) {\n static constexpr int t= nttarr_cat<mod_t,\
    \ LIM>, TH= (int[]){64, 32, 128, 128, 128, 256}[t];\n assert(n > 0), assert(((n\
    \ & -n) == n)), assert(l > 0);\n const mod_t iv0= iv[0];\n if (int i= 0; n > TH)\
    \ {\n  if constexpr (t == 0) {\n   const int bn= __builtin_ctz(n) % 3;\n   (bn\
    \ == 0 ? div_base_<64, 3, 3, LIM, mod_t> : bn == 1 ? div_base_<32, 3, 2, LIM,\
    \ mod_t> : div_base_<32, 3, 3, LIM, mod_t>)(p, n, q, l, r, iv);\n  } else {\n\
    \   const int bn= __builtin_ctz(n) % 6;\n   if constexpr (t == 1) (bn & 1 ? div_base_<32,\
    \ 2, 2, LIM, mod_t> : bn == 0 ? div_base_<32, 3, 1, LIM, mod_t> : bn == 2 ? div_base_<32,\
    \ 3, 3, LIM, mod_t> : div_base_<32, 3, 2, LIM, mod_t>)(p, n, q, l, r, iv);\n \
    \  else if constexpr (t == 5) (bn & 1 ? div_base_<128, 2, 2, LIM, mod_t> : bn\
    \ == 0 ? div_base_<128, 3, 2, LIM, mod_t> : bn == 2 ? div_base_<256, 3, 3, LIM,\
    \ mod_t> : div_base_<128, 3, 3, LIM, mod_t>)(p, n, q, l, r, iv);\n   else (bn\
    \ & 1 ? div_base_<128, 2, 2, LIM, mod_t> : bn == 0 ? div_base_<128, 3, 2, LIM,\
    \ mod_t> : bn == 2 ? div_base_<128, 3, 1, LIM, mod_t> : div_base_<128, 3, 3, LIM,\
    \ mod_t>)(p, n, q, l, r, iv);\n  }\n } else\n  for (copy_n(p, n, r); i < n; r[i++]*=\
    \ iv0)\n   for (int j= min(i + 1, l); --j;) r[i]-= r[i - j] * q[j];\n}\ntemplate\
    \ <size_t lnR, class mod_t, size_t LIM= 1 << 22> void div_(const mod_t p[], int\
    \ n, const mod_t q[], int l, mod_t r[]) {\n static constexpr size_t R= (1 << lnR)\
    \ - 1, LIM2= LIM >> (lnR - 1);\n mod_t* iv= GlobalArray<mod_t, LIM2, 2>::bf;\n\
    \ using GNA1= GlobalNTTArray<mod_t, LIM2, 1>;\n using GNA2= GlobalNTTArray<mod_t,\
    \ LIM2, 2>;\n using GNA3= GlobalNTTArray<mod_t, LIM2, 3>;\n auto gt1= GlobalNTTArray2D<mod_t,\
    \ LIM2, R, 1>::bf, gt2= GlobalNTTArray2D<mod_t, LIM2, R, 2>::bf;\n const int m=\
    \ pw2(n) >> lnR, m2= m << 1, ed= (n - 1) / m, ss= (l - 1) / m;\n iv[0]= mod_t(1)\
    \ / q[0], inv_base<LIM2>(q, m, iv, 1, l), div_base<LIM2>(p, m, q, l, r, iv), GNA3::bf.set(iv,\
    \ 0, m), GNA3::bf.zeros(m, m2), GNA3::bf.dft(0, m2);\n for (int k= 0, i= m, j,\
    \ o; k < ed; ++k, i+= m, q+= m, p+= m) {\n  if (j= min(m2, l - k * m); j > 0)\
    \ gt2[k].set(q, 0, j), gt2[k].zeros(j, m2), gt2[k].dft(0, m2);\n  for (gt1[k].set(r,\
    \ 0, m), gt1[k].zeros(m, m2), gt1[k].dft(0, m2), GNA2::bf.mul(gt1[k], gt2[0],\
    \ 0, m2), j= min(k, ss) + 1; --j;) GNA1::bf.mul(gt1[k - j], gt2[j], 0, m2), GNA2::bf.add(GNA1::bf,\
    \ 0, m2);\n  for (GNA2::bf.idft(0, m2), GNA2::bf.zeros(0, m), GNA2::bf.get(r,\
    \ m, m + (o= min(m, n - i))), j= o + m; j-- > m;) r[j]-= p[j];\n  for (GNA2::bf.set(r,\
    \ m, m + o), GNA2::bf.dft(0, m2), GNA2::bf.mul(GNA3::bf, 0, m2), GNA2::bf.idft(0,\
    \ m2), GNA2::bf.get(r, m, m + o), r+= m, j= o; j--;) r[j]= -r[j];\n }\n}\ntemplate\
    \ <class mod_t, size_t LIM= 1 << 22> vector<mod_t> div(const vector<mod_t>& p,\
    \ const vector<mod_t>& q) {\n static constexpr int t= nttarr_cat<mod_t, LIM>,\
    \ TH= (int[]){107, 75, 205, 350, 450, 600}[t];\n mod_t *r= GlobalArray<mod_t,\
    \ LIM, 1>::bf, *qq= GlobalArray<mod_t, LIM, 2>::bf;\n const int n= p.size(), l=\
    \ q.size();\n assert(l > 0), assert(q[0] != mod_t(0));\n if (n > TH) {\n  const\
    \ int m= pw2(n), l1= m >> 1, k= (n - l1 - 1) / (l1 >> 3), bl= __builtin_ctz(l1);\n\
    \  int a= 5;\n  if constexpr (!t) {\n   a= bl < 8 ? 4 - (k & 1 && k > 2) : bl\
    \ < 9 ? 4 : 4 + (k < (bl == 9 ? 1 : bl < 12 ? 3 : bl < 16 ? 4 : bl < 17 ? 5 :\
    \ 6));\n  } else if constexpr (t < 2) {\n   if (bl & 1) {\n    if (bl < 8) a=\
    \ k && k != 2 ? 3 : 4;\n    else if (k > 6) a= 3;\n    else if (k > 5) a= 4;\n\
    \    else if (!k) a= 5;\n    else if (bl < 10) k & 1 ? 3 : 4;\n    else if (bl\
    \ < 12) a= k > 4 ? 3 : 4;\n    else if (bl < 16) a= k > 4 ? 3 : k < (bl < 14 ?\
    \ 2 : 3) ? 5 : 4;\n    else a= k < 3 ? 5 : 4;\n   } else {\n    if (bl < 7) a=\
    \ k & 1 && k > 2 ? 3 : 4;\n    else if (bl < 17) a= 4;\n    else a= k ? 4 : 5;\n\
    \   }\n  } else if constexpr (t < 3) {\n   if (bl & 1) {\n    if (bl < 8 || k\
    \ > 6) a= 3;\n    else if (bl < 10) a= k == 5 ? 3 : 4;\n    else if (bl < 12)\
    \ a= k < 2 ? 5 : k & 1 ? 3 : 4;\n    else if (bl < 14) a= k < 2 ? 5 : k == 5 ?\
    \ 3 : 4;\n    else a= k < 3 ? 5 : 4;\n   } else {\n    if (bl < 9) a= k & 1 &&\
    \ k > 4 ? 3 : 4;\n    else if (bl < 15) a= 4;\n    else a= k ? 4 : 5;\n   }\n\
    \  } else if constexpr (t < 4) {\n   if (bl & 1) {\n    if (bl < 10) a= k & 1\
    \ || k > 4 ? 3 : 4;\n    else if (k > 6) a= 3;\n    else if (bl < 14) a= k < 2\
    \ ? 5 : k == 5 ? 3 : 4;\n    else if (bl < 18) a= k < 3 ? 5 : 4;\n    else a=\
    \ k < 4 ? 5 : 4;\n   } else {\n    if (bl < 9) a= k & 1 && k > 2 ? 3 : 4;\n  \
    \  else if (bl < 15) a= 4;\n    else a= k ? 4 : 5;\n   }\n  } else if constexpr\
    \ (t < 5) {\n   if (bl & 1) {\n    if (bl < 10) a= k && k != 2 ? 3 : 4;\n    else\
    \ if (k > 6) a= 3;\n    else if (bl < 14) a= k < 2 ? 5 : k == 5 ? 3 : 4;\n   \
    \ else if (bl < 18) a= k < 3 ? 5 : 4;\n    else a= k < 4 ? 5 : 4;\n   } else {\n\
    \    if (bl < 9) a= 2;\n    else if (bl < 15) a= 4;\n    else a= k ? 4 : 5;\n\
    \   }\n  } else {\n   if (bl & 1) {\n    if (bl < 10) a= !k || k == 2 ? 4 : 3;\n\
    \    else if (k > 6) a= 3;\n    else if (bl < 12) a= k ? 4 : 5;\n    else if (bl\
    \ < 18) a= k < 3 ? 5 : 4;\n    else a= k < 4 ? 5 : 4;\n   } else {\n    if (bl\
    \ < 11) a= k > 6 ? 3 : 4;\n    else if (bl < 15) a= 4;\n    else a= k ? 4 : 5;\n\
    \   }\n  }\n  (a == 2 ? div_<2, mod_t, LIM> : a == 3 ? div_<3, mod_t, LIM> : a\
    \ == 4 ? div_<4, mod_t, LIM> : div_<5, mod_t, LIM>)(p.data(), n, q.data(), l,\
    \ r);\n } else {\n  const mod_t iv0= mod_t(1) / q[0];\n  copy(p.begin(), p.end(),\
    \ r), copy(q.begin(), q.end(), qq);\n  for (int i= 0; i < n; r[i++]*= iv0)\n \
    \  for (int j= min(i + 1, l); --j;) r[i]-= r[i - j] * qq[j];\n }\n return vector(r,\
    \ r + n);\n}\n}\nusing math_internal::div;\n#line 4 \"src/FFT/convolve.hpp\"\n\
    template <class mod_t, size_t LM= 1 << 22> std::vector<mod_t> convolve(const std::vector<mod_t>&\
    \ p, const std::vector<mod_t>& q) {\n mod_t *pp= GlobalArray<mod_t, LM, 0>::bf,\
    \ *qq= GlobalArray<mod_t, LM, 1>::bf, *rr= GlobalArray<mod_t, LM, 2>::bf;\n static\
    \ constexpr int t= nttarr_cat<mod_t, LM>, TH= (int[]){70, 30, 70, 100, 135, 150}[t];\n\
    \ auto f= [](int l) -> int {\n  static constexpr double B[]= {(double[]){8.288,\
    \ 5.418, 7.070, 9.676, 11.713, 13.374}[t], (double[]){8.252, 6.578, 9.283, 12.810,\
    \ 13.853, 15.501}[t]};\n  return std::round(std::pow(l, 0.535) * B[__builtin_ctz(l)\
    \ & 1]);\n };\n const int n= p.size(), m= q.size(), sz= n + m - 1;\n if (!n ||\
    \ !m) return std::vector<mod_t>();\n if (std::min(n, m) < TH) {\n  std::fill_n(rr,\
    \ sz, mod_t()), std::copy(p.begin(), p.end(), pp), std::copy(q.begin(), q.end(),\
    \ qq);\n  for (int i= n; i--;)\n   for (int j= m; j--;) rr[i + j]+= pp[i] * qq[j];\n\
    \ } else {\n  const int rl= pw2(sz), l= pw2(std::max(n, m)), fl= f(l);\n  static\
    \ constexpr size_t LM2= LM >> 3;\n  static constexpr bool b= nttarr_cat<mod_t,\
    \ LM2> < t;\n  if (b || (l + fl < sz && sz <= (rl >> 3) * 5)) {\n   using GNA1=\
    \ GlobalNTTArray<mod_t, LM2, 1>;\n   using GNA2= GlobalNTTArray<mod_t, LM2, 2>;\n\
    \   auto gt1= GlobalNTTArray2D<mod_t, LM2, 16, 1>::bf, gt2= GlobalNTTArray2D<mod_t,\
    \ LM2, 16, 2>::bf;\n   const int l= rl >> 4, l2= l << 1, nn= (n + l - 1) / l,\
    \ mm= (m + l - 1) / l, ss= nn + mm - 1;\n   for (int i= 0, k= 0, s; k < n; ++i,\
    \ k+= l) gt1[i].set(p.data() + k, 0, s= std::min(l, n - k)), gt1[i].zeros(s, l2),\
    \ gt1[i].dft(0, l2);\n   if (&p != &q)\n    for (int i= 0, k= 0, s; k < m; ++i,\
    \ k+= l) gt2[i].set(q.data() + k, 0, s= std::min(l, m - k)), gt2[i].zeros(s, l2),\
    \ gt2[i].dft(0, l2);\n   else\n    for (int i= nn; i--;) gt2[i].subst(gt1[i],\
    \ 0, l2);\n   GNA2::bf.mul(gt1[0], gt2[0], 0, l2), GNA2::bf.idft(0, l2), GNA2::bf.get(rr,\
    \ 0, l2);\n   for (int i= 1, k= l, j, ed; i < ss; ++i, k+= l) {\n    for (j= std::max(0,\
    \ i - nn + 1), ed= std::min(mm - 1, i), GNA2::bf.mul(gt1[i - ed], gt2[ed], 0,\
    \ l2); j < ed; ++j) GNA1::bf.mul(gt1[i - j], gt2[j], 0, l2), GNA2::bf.add(GNA1::bf,\
    \ 0, l2);\n    for (GNA2::bf.idft(0, l2), GNA2::bf.get(pp, 0, j= std::min(l, sz\
    \ - k)); j--;) rr[k + j]+= pp[j];\n    if (l < sz - k) GNA2::bf.get(rr + k, l,\
    \ std::min(l2, sz - k));\n   }\n  } else {\n   using GNA1= GlobalNTTArray<mod_t,\
    \ LM, 1>;\n   using GNA2= GlobalNTTArray<mod_t, LM, 2>;\n   const int len= sz\
    \ <= l + fl ? l : rl;\n   if (GNA1::bf.set(p.data(), 0, n), GNA1::bf.zeros(n,\
    \ len), GNA1::bf.dft(0, len); &p != &q) GNA2::bf.set(q.data(), 0, m), GNA2::bf.zeros(m,\
    \ len), GNA2::bf.dft(0, len), GNA1::bf.mul(GNA2::bf, 0, len);\n   else GNA1::bf.mul(GNA1::bf,\
    \ 0, len);\n   if (GNA1::bf.idft(0, len), GNA1::bf.get(rr, 0, std::min(sz, len));\
    \ len < sz) {\n    std::copy(p.begin() + len - m + 1, p.end(), pp + len - m +\
    \ 1), std::copy(q.begin() + len - n + 1, q.end(), qq + len - n + 1);\n    for\
    \ (int i= len, j; i < sz; rr[i - len]-= rr[i], ++i)\n     for (rr[i]= mod_t(),\
    \ j= i - m + 1; j < n; ++j) rr[i]+= pp[j] * qq[i - j];\n   }\n  }\n }\n return\
    \ std::vector(rr, rr + sz);\n}\n#line 5 \"src/FFT/Polynomial.hpp\"\ntemplate <class\
    \ mod_t, std::size_t LM= 1 << 22> class Polynomial: public std::vector<mod_t>\
    \ {\n using Poly= Polynomial;\n struct Inde;\n struct XP_plus_C {  // x^p+c\n\
    \  Inde x;\n  mod_t c;\n  XP_plus_C(const Inde &x_): x(x_), c(Z) {}\n  XP_plus_C(int\
    \ p_, mod_t c_): x(p_), c(c_) {}\n };\n struct Inde {  // indeterminate\n  int\
    \ p_;\n  Inde(int p): p_(p) {}\n  Inde(): Inde(1) {}\n  Inde operator^(int p)\
    \ const { return Inde(p_ * p); }\n  Inde operator*(const Inde &rhs) const { return\
    \ Inde(p_ + rhs.p_); }\n  int pow() const { return p_; }\n  XP_plus_C operator+(mod_t\
    \ c) { return XP_plus_C(p_, c); }\n  XP_plus_C operator-(mod_t c) { return XP_plus_C(p_,\
    \ -c); }\n };\n using GNA1= GlobalNTTArray<mod_t, LM, 1>;\n using GNA2= GlobalNTTArray<mod_t,\
    \ LM, 2>;\n using GA= GlobalArray<mod_t, LM, 0>;\n using GAp= GlobalArray<mod_t,\
    \ LM, 1>;\n using GAq= GlobalArray<mod_t, LM, 2>;\n using GA3= GlobalArray<mod_t,\
    \ LM, 3>;\n static inline const mod_t Z= 0;\n static constexpr int A= 8;\n static\
    \ constexpr int B= 42;\n std::pair<Poly, Poly> quorem_na(const Poly &q) const\
    \ {\n  int n= deg(), m= q.deg(), qsz= n - m + 1, i= qsz, j;\n  std::copy_n(this->begin(),\
    \ n + 1, GAp::bf);\n  std::copy_n(q.begin(), m + 1, GAq::bf);\n  for (mod_t *bf=\
    \ GAp::bf + n - m, iv= mod_t(1) / GAq::bf[m]; i--; bf--)\n   for (GA::bf[i]= bf[j=\
    \ m] * iv; j--;) bf[j]-= GAq::bf[j] * GA::bf[i];\n  Poly rem(GAp::bf, GAp::bf\
    \ + m);\n  return {Poly(GA::bf, GA::bf + qsz), rem.shrink()};\n }\n Poly quo(const\
    \ Poly &q) const {\n  const int n= deg() + 1, m= q.deg() + 1, qsz= n - m + 1,\
    \ nb= this->size() - n, mb= q.size() - m;\n  auto ret= div<mod_t, LM>(Poly(this->rbegin()\
    \ + nb, this->rbegin() + nb + qsz), Poly(q.rbegin() + mb, q.rbegin() + mb + std::min(qsz,\
    \ m)));\n  return std::reverse(ret.begin(), ret.end()), ret;\n }\n std::pair<Poly,\
    \ Poly> quorem_ntt(const Poly &q) const {\n  const int n= deg(), m= q.deg(), qsz=\
    \ n - m + 1;\n  auto qu= quo(q);\n  std::copy(qu.begin(), qu.end(), GA::bf);\n\
    \  std::copy_n(this->begin(), n + 1, GAp::bf);\n  std::copy_n(q.begin(), m + 1,\
    \ GAq::bf);\n  const int len= pw2(m), mask= len - 1;\n  if (len > qsz) std::fill_n(GA::bf\
    \ + qsz, len - qsz, Z);\n  if (len > m + 1) std::fill_n(GAq::bf + m + 1, len -\
    \ m - 1, Z);\n  for (int i= qsz; i-- > len;) GA::bf[i & mask]+= GA::bf[i];\n \
    \ for (int i= n; i >= len; i--) GAp::bf[i & mask]+= GAp::bf[i];\n  if (GNA1::bf.set(GA::bf,\
    \ 0, len); m == len) GAq::bf[0]+= GAq::bf[m];\n  GNA2::bf.set(GAq::bf, 0, len),\
    \ GNA1::bf.dft(0, len), GNA2::bf.dft(0, len);\n  GNA1::bf.mul(GNA2::bf, 0, len),\
    \ GNA1::bf.idft(0, len);\n  GNA1::bf.get(GAq::bf, 0, m);\n  for (int i= m; i--;)\
    \ GAp::bf[i]-= GAq::bf[i];\n  Poly rem(GAp::bf, GAp::bf + m);\n  return std::make_pair(qu,\
    \ rem.shrink());\n }\npublic:\n using std::vector<mod_t>::vector;\n Polynomial(mod_t\
    \ a): Polynomial(1, a) {}\n Polynomial(const std::vector<mod_t> &p): Polynomial(p.begin(),\
    \ p.end()) {}\n Polynomial(const XP_plus_C &xpc): Polynomial(xpc.x.pow() + 1)\
    \ { (*this)[xpc.x.pow()]= 1, (*this)[0]= xpc.c; }\n static Inde x() { return Inde();\
    \ }\n inline int deg() const {\n  for (int n= this->size() - 1;; n--)\n   if (n\
    \ < 0 || (*this)[n] != Z) return n;\n }\n inline Poly &shrink() { return this->resize(std::max(deg()\
    \ + 1, 1)), *this; }\n#define ASSIGN(op) \\\n Poly &operator op##=(const Poly\
    \ &r) { \\\n  const std::size_t n= r.deg() + 1; \\\n  if (this->size() < n) this->resize(n);\
    \ \\\n  for (int i= n; i--;) (*this)[i] op##= r[i]; \\\n  return shrink(); \\\n\
    \ }\n ASSIGN(+)\n ASSIGN(-)\n#undef ASSIGN\n Poly &operator*=(const Poly &r) {\
    \ return *this= *this * r, *this; }\n Poly &operator/=(const Poly &r) { return\
    \ *this= *this / r, *this; }\n Poly &operator%=(const Poly &r) { return *this=\
    \ *this % r, *this; }\n Poly operator-() const { return Poly()-= *this; }\n Poly\
    \ operator+(const Poly &r) const { return Poly(*this)+= r; }\n Poly operator-(const\
    \ Poly &r) const { return Poly(*this)-= r; }\n Poly operator*(const Poly &r) const\
    \ { return convolve<mod_t, LM>(*this, r); }\n Poly operator/(const Poly &r) const\
    \ {\n  const int m= r.deg(), qsz= deg() - m + 1, ln= __builtin_ctz(pw2(qsz));\n\
    \  assert(m >= 0);\n  if (qsz <= 0) return Poly{Z};\n  return m + 3 < A * ln +\
    \ B || qsz <= 64 ? quorem_na(r).first : quo(r);\n }\n std::pair<Poly, Poly> quorem(const\
    \ Poly &r) const {\n  const int n= deg(), m= r.deg(), qsz= n - m + 1, ln= __builtin_ctz(pw2(qsz));\n\
    \  assert(m >= 0);\n  if (qsz <= 0) return {Poly{Z}, Poly(this->begin(), this->begin()\
    \ + n + 1)};\n  return m < A * ln + B || qsz <= 64 ? quorem_na(r) : quorem_ntt(r);\n\
    \ }\n Poly operator%(const Poly &r) const { return quorem(r).second; }\n Poly\
    \ &operator+=(const mod_t r) { return (*this)[0]+= r, *this; }\n Poly &operator-=(const\
    \ mod_t r) { return (*this)[0]-= r, *this; }\n Poly &operator*=(const mod_t r)\
    \ {\n  for (mod_t &c: *this) c*= r;\n  return shrink();\n }\n Poly &operator/=(const\
    \ mod_t r) {\n  for (mod_t &c: *this) c/= r;\n  return shrink();\n }\n Poly operator+(const\
    \ mod_t r) { return Poly(*this)+= r; }\n Poly operator-(const mod_t r) { return\
    \ Poly(*this)-= r; }\n Poly operator*(const mod_t r) { return Poly(*this)*= r;\
    \ }\n Poly operator/(const mod_t r) { return Poly(*this)/= r; }\n friend Poly\
    \ operator+(const mod_t l, Poly r) { return r+= l; }\n friend Poly operator-(const\
    \ mod_t l, Poly r) { return -(r-= l); }\n friend Poly operator*(const mod_t l,\
    \ Poly r) { return r*= l; }\n mod_t operator()(mod_t c) const {  // eval f(c)\n\
    \  if (c == Z) return (*this)[0];\n  mod_t ret= 0;\n  for (int i= deg() + 1; i--;)\
    \ ret*= c, ret+= (*this)[i];\n  return ret;\n }\n Poly operator()(const XP_plus_C\
    \ &xpc) const {  // f(x^p+c)\n  return taylor_shift(xpc.c).scale(xpc.x.pow());\n\
    \ }\n Poly operator()(const Poly &q) const {  // f(g) mod x^n\n  const int n=\
    \ this->deg() + 1, k= std::ceil(std::sqrt(n));\n  std::vector<Poly> pw1(k + 1),\
    \ pw2(k + 1);\n  if (pw1[0]= {1}, pw1[1]= q; q.size() > n) pw1[1].resize(n);\n\
    \  for (int i= 2; i <= k; ++i)\n   if (pw1[i]= pw1[i - 1] * pw1[1]; pw1[i].size()\
    \ > n) pw1[i].resize(n);\n  pw2[0]= {1}, pw2[1]= pw1[k];\n  for (int i= 2; i <=\
    \ k; ++i)\n   if (pw2[i]= pw2[i - 1] * pw2[1]; pw2[i].size() > n) pw2[i].resize(n);\n\
    \  Poly ret(n, Z), f;\n  for (int i= 0, j; i <= k; ++i) {\n   for (f.assign(n,\
    \ Z), j= std::min(k, std::max(0, n - k * i)); j--;) {\n    mod_t coef= (*this)[k\
    \ * i + j];\n    for (int d= pw1[j].size(); d--;) f[d]+= pw1[j][d] * coef;\n \
    \  }\n   for (f*= pw2[i], j= std::min<int>(n, f.size()); j--;) ret[j]+= f[j];\n\
    \  }\n  return ret;\n }\n Poly &operator*=(const XP_plus_C &xpc) {\n  Poly q;\n\
    \  if (xpc.c != Z) q= *this * xpc.c;\n  return this->insert(this->begin(), xpc.x.pow(),\
    \ Z), *this+= q;\n }\n Poly operator*(const XP_plus_C &xpc) const { return Poly(*this)*=\
    \ xpc; }\n friend Poly operator*(const XP_plus_C &xpc, const Poly &p) { return\
    \ p * xpc; }\n Poly scale(int k) const {\n  const int n= deg();\n  Poly ret(n\
    \ * k + 1, Z);\n  for (int i= 0; i <= n; i++) ret[i * k]+= (*this)[i];\n  return\
    \ ret;\n }\n Poly taylor_shift(mod_t c) const {\n  int n= deg(), i= 0;\n  if (n\
    \ < 1 || c == Z) return Poly(*this);\n  mod_t cpw= 1, fact= 1;\n  for (; i <=\
    \ n; fact*= ++i) GAp::bf[n - i]= (*this)[i] * fact;\n  for (fact= mod_t(1) / fact;\
    \ i--;) GA3::bf[i]= (fact*= i + 1);\n  for (; ++i <= n;) GAq::bf[i]= cpw * GA3::bf[i],\
    \ cpw*= c;\n  auto ret= Poly(GAp::bf, GAp::bf + n + 1) * Poly(GAq::bf, GAq::bf\
    \ + n + 1);\n  for (ret.resize(n + 1), std::reverse(ret.begin(), ret.end()); i--;)\
    \ ret[i]*= GA3::bf[i];\n  return ret;\n }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const Poly &p) {\n  if (p.deg() == -1) return os << 0;\n  for (int i= 0,\
    \ e= p.deg(); i <= e; i++) {\n   if (p[i] == Z) continue;\n   if (i == 0 || p[i]\
    \ != mod_t(1)) os << p[i];\n   if (i >= 1) os << 'x';\n   if (i > 9) os << \"\
    ^(\" << i << ')';\n   else if (i > 1) os << '^' << i;\n   if (i + 1 <= e) os <<\
    \ \" + \";\n  }\n  return os;\n }\n};\n#define __POLYNOMIAL Polynomial<mod_t,\
    \ LM>\n#ifdef __FPS_DIVAT\n__FPS_DIVAT(__POLYNOMIAL)\n#endif\n#line 6 \"test/yosupo/division_of_Poly.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N, M;\n  cin >> N >> M;\n  Polynomial<Mint>\
    \ f(N), g(M), x, y;\n  for (int i = 0; i < N; i++) cin >> f[i];\n  for (int i\
    \ = 0; i < M; i++) cin >> g[i];\n  auto [q, r] = f.quorem(g);\n  cout << q.deg()\
    \ + 1 << \" \" << r.deg() + 1 << '\\n';\n  if (q.deg() != -1)\n    for (int i\
    \ = 0, ed = q.size(); i < ed; i++)\n      cout << q[i] << \" \\n\"[i == ed - 1];\n\
    \  if (r.deg() != -1)\n    for (int i = 0, ed = r.size(); i < ed; i++)\n     \
    \ cout << r[i] << \" \\n\"[i == ed - 1];\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \n#include <bits/stdc++.h>\n\n#include \"src/Math/ModInt.hpp\"\n#include \"src/FFT/Polynomial.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N, M;\n  cin >> N >> M;\n  Polynomial<Mint>\
    \ f(N), g(M), x, y;\n  for (int i = 0; i < N; i++) cin >> f[i];\n  for (int i\
    \ = 0; i < M; i++) cin >> g[i];\n  auto [q, r] = f.quorem(g);\n  cout << q.deg()\
    \ + 1 << \" \" << r.deg() + 1 << '\\n';\n  if (q.deg() != -1)\n    for (int i\
    \ = 0, ed = q.size(); i < ed; i++)\n      cout << q[i] << \" \\n\"[i == ed - 1];\n\
    \  if (r.deg() != -1)\n    for (int i = 0, ed = r.size(); i < ed; i++)\n     \
    \ cout << r[i] << \" \\n\"[i == ed - 1];\n  return 0;\n}"
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
  path: test/yosupo/division_of_Poly.test.cpp
  requiredBy: []
  timestamp: '2023-01-09 22:42:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/division_of_Poly.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/division_of_Poly.test.cpp
- /verify/test/yosupo/division_of_Poly.test.cpp.html
title: test/yosupo/division_of_Poly.test.cpp
---
