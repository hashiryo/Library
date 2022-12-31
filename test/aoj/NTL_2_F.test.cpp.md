---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FFT/BigInt.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F
  bundledCode: "#line 1 \"test/aoj/NTL_2_F.test.cpp\"\n#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
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
    }\n}\n#line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate <class\
    \ Uint, class mod_pro_t, u64... args> constexpr bool miller_rabin(Uint n) {\n\
    \ const mod_pro_t md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one=\
    \ md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...}) {\n  Uint b=\
    \ a % n, p= pow(md.set(b), d, md), i= s;\n  while (p= md.norm(p), (p != one &&\
    \ p != n1 && b && i--)) p= md.mul(p, p);\n  if (md.norm(p) != n1 && i != s) return\
    \ 0;\n }\n return true;\n}\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n\
    \ % 6 % 4 != 1) return (n | 1) == 3;\n if (n < UINT_MAX) return miller_rabin<u32,\
    \ MP_Na<u32>, 2, 7, 61>(n);\n if (n < LLONG_MAX) return miller_rabin<u64, MP_Mo,\
    \ 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64,\
    \ MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing\
    \ math_internal::is_prime;\n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class\
    \ Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y=\
    \ z - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal\
    \ {\n#define CE constexpr\nstruct m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b\
    \ {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\n\
    template <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\n\
    template <class mod_t> CE bool is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\n\
    template <class mpt, u64 MOD> struct SB: s_b {\nprotected:\n static CE mpt md=\
    \ mpt(MOD);\n};\ntemplate <class mpt, int id> struct RB: r_b {\n static inline\
    \ void set_mod(u64 m) { md= mpt(m); }\nprotected:\n static inline mpt md;\n};\n\
    template <class Int, class U, class B> struct MInt: public B {\n using Uint= U;\n\
    \ static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n CE\
    \ MInt(const MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n % B::md.mod)))\
    \ {}\n CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name,\
    \ op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  return ret.x= op, ret; \\\
    \n }\n FUNC(operator+(const MInt& r), B::md.plus(x, r.x))\n FUNC(operator-(const\
    \ MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const MInt& r), B::md.mul(x,\
    \ r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n#undef FUNC\n CE\
    \ MInt operator/(const MInt& r) const { return *this * r.inv(); }\n CE MInt& operator+=(const\
    \ MInt& r) { return *this= *this + r; }\n CE MInt& operator-=(const MInt& r) {\
    \ return *this= *this - r; }\n CE MInt& operator*=(const MInt& r) { return *this=\
    \ *this * r; }\n CE MInt& operator/=(const MInt& r) { return *this= *this / r;\
    \ }\n CE bool operator==(const MInt& r) const { return B::md.norm(x) == B::md.norm(r.x);\
    \ }\n CE bool operator!=(const MInt& r) const { return !(*this == r); }\n CE bool\
    \ operator<(const MInt& r) const { return B::md.norm(x) < B::md.norm(r.x); }\n\
    \ CE inline MInt inv() const { return mod_inv<Int>(val(), B::md.mod); }\n CE inline\
    \ Uint val() const { return B::md.get(x); }\n friend ostream& operator<<(ostream&\
    \ os, const MInt& r) { return os << r.val(); }\n friend istream& operator>>(istream&\
    \ is, MInt& r) {\n  i64 v;\n  return is >> v, r= MInt(v), is;\n }\nprivate:\n\
    \ Uint x;\n};\ntemplate <u64 MOD> using StaticModInt= conditional_t < MOD<INT_MAX,\
    \ MInt<int, u32, SB<MP_Na<u32>, MOD>>, conditional_t<MOD&(MOD < LLONG_MAX), MInt<i64,\
    \ u64, SB<MP_Mo, MOD>>, MInt<i64, u64, SB<MP_Na<u64>, MOD>>>>;\nclass Montgomery\
    \ {};\ntemplate <class Int, int id= -1> using RuntimeModInt= conditional_t<is_same_v<Int,\
    \ Montgomery>, MInt<i64, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ i64>, is_same<Int, u64>>, MInt<i64, u64, RB<MP_Na<u64>, id>>, MInt<int, u32,\
    \ RB<MP_Na<u32>, id>>>>;\n#undef CE\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Montgomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LIM> mod_t\
    \ get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m=\
    \ mod_t::mod();\n static mod_t dat[LIM];\n static int l= 1;\n if (l == 1) dat[l++]=\
    \ 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n\
    #line 5 \"src/FFT/NTT.hpp\"\nnamespace math_internal {\n#define CE constexpr\n\
    #define ST static\n#define TP template\n#define BSF(_, n) __builtin_ctz##_(n)\n\
    TP<class mod_t> struct NTT {\n#define FOR(a, b, c) \\\n for (a= n >> 2; a; a>>=\
    \ 2, b<<= 2) \\\n  for (y= u= r= I, x0= x, s= 0;; r*= c[BSF(, s)], u= r * r, y=\
    \ u * r, x0= x3 + p)\n#define FOR2(a, b, c) \\\n for (a= n; a>>= 1; b<<= 1) \\\
    \n  for (s= 0, r= I, x0= x;; r*= c[BSF(, s)], x0= x1 + p)\n#define REP for (x1=\
    \ x0 + p, x2= x1 + p, x3= x2 + (i= p); i--;)\n ST inline void dft(int n, mod_t\
    \ x[]) {\n  int p, e= 1, s, i;\n  mod_t r, u, y, *x0, *x1, *x2, *x3;\n  if CE\
    \ (md < INT_MAX) {\n   ST CE auto r3= ras<3>(rt, irt);\n   ST CE u128 im= rt[2].val(),\
    \ md3= u128(md) << 93;\n   FOR(p, e, r3) {\n    u64 ru= r.val(), ru2= u.val(),\
    \ ru3= y.val();\n    REP {\n     u64 a= x0[i].val(), b= ru * x1[i].val(), c= ru2\
    \ * x2[i].val(), d= ru3 * x3[i].val(), f= md2 - d, g= md2 + a - c;\n     u128\
    \ h= im * (b + f);\n     x0[i]= a + b + c + d, x1[i]= a + (md2 - b) + c + f, x2[i]=\
    \ h + g, x3[i]= md3 - h + g;\n    }\n    if (++s == e) break;\n   }\n   if (BSF(,\
    \ n) & 1)\n    for (r= I, s= 0, p= 0;; r*= r2[BSF(, ++s)])\n     if (x[p + 1]=\
    \ x[p] - (u= x[p + 1] * r), x[p]+= u; (p+= 2) == n) break;\n  } else FOR2(p, e,\
    \ r2) {\n    for (x1= x0 + (i= p); i--;) x1[i]= x0[i] - (u= r * x1[i]), x0[i]+=\
    \ u;\n    if (++s == e) break;\n   }\n }\n ST inline void idft(int n, mod_t x[])\
    \ {\n  int e, p= 1, s, i;\n  mod_t r, u, y, *x0, *x1, *x2, *x3;\n  if CE (md <\
    \ INT_MAX) {\n   ST CE auto ir3= ras<3>(irt, rt);\n   ST CE u64 im= irt[2].val();\n\
    \   FOR(e, p, ir3) {\n    u64 ru2= u.val();\n    u128 ru= r.val(), ru3= y.val();\n\
    \    REP {\n     u64 a= x0[i].val(), b= x1[i].val(), c= x2[i].val(), d= x3[i].val(),\
    \ f= md - d, g= a + md - b, h= im * (c + f);\n     x0[i]= a + b + c + d, x1[i]=\
    \ ru * (g + h), x2[i]= ru2 * (a + b + (md - c) + f), x3[i]= ru3 * (g + (md2 <<\
    \ 1) - h);\n    }\n    if (++s == e) break;\n   }\n   if (BSF(, n) & 1)\n    for\
    \ (x1= x + (i= n >> 1); i--;) u= x[i] - x1[i], x[i]+= x1[i], x1[i]= u;\n  } else\
    \ FOR2(e, p, ir2) {\n    for (x1= x0 + (i= p); i--;) u= x0[i] - x1[i], x0[i]+=\
    \ x1[i], x1[i]= r * u;\n    if (++s == e) break;\n   }\n  for (const mod_t iv=\
    \ I / n; n--;) x[n]*= iv;\n }\n#undef FOR\n#undef FOR2\n#undef REP\n ST inline\
    \ void even_dft(int n, mod_t x[]) {\n  for (int i= 0, j= 0; i < n; i+= 2) x[j++]=\
    \ iv2 * (x[i] + x[i + 1]);\n }\n ST inline void odd_dft(int n, mod_t x[], mod_t\
    \ r= iv2) {\n  for (int i= 0, j= 0;; r*= ir2[BSF(, ++j)])\n   if (x[j]= r * (x[i]\
    \ - x[i + 1]); (i+= 2) == n) break;\n }\n ST inline void dft_doubling(int n, mod_t\
    \ x[], int i= 0) {\n  mod_t k= I, t= rt[BSF(, n << 1)];\n  for (copy_n(x, n, x\
    \ + n), idft(n, x + n); i < n; ++i) x[n + i]*= k, k*= t;\n  dft(n, x + n);\n }\n\
    protected:\n ST CE u64 md= mod_t::mod(), md2= md << 31;\n static_assert(md & 1);\n\
    \ static_assert(is_prime(md));\n ST CE u8 E= BSF(ll, md - 1);\n ST CE mod_t w=\
    \ [](u8 e) {\n  for (mod_t r= 2;; r+= 1)\n   if (auto s= r.pow((md - 1) / 2);\
    \ s != 1 && s * s == 1) return r.pow((md - 1) >> e);\n  return mod_t();\n }(E);\n\
    \ static_assert(w != mod_t());\n ST CE mod_t I= 1, iv2= (md + 1) / 2, iw= w.pow((1ULL\
    \ << E) - 1);\n ST CE auto roots(mod_t w) {\n  array<mod_t, E + 1> x= {};\n  for\
    \ (u8 e= E; e; w*= w) x[e--]= w;\n  return x[0]= w, x;\n }\n TP<u32 N> ST CE auto\
    \ ras(const array<mod_t, E + 1> &rt, const array<mod_t, E + 1> &irt, int i= N)\
    \ {\n  array<mod_t, E + 1 - N> x= {};\n  for (mod_t ro= 1; i <= E; ro*= irt[i++])\
    \ x[i - N]= rt[i] * ro;\n  return x;\n }\n ST CE auto rt= roots(w), irt= roots(iw);\n\
    \ ST CE auto r2= ras<2>(rt, irt), ir2= ras<2>(irt, rt);\n};\nTP<class T, u8 t,\
    \ class B> struct NI: public B {\n using B::B;\n#define FUNC(op, name, HG, ...)\
    \ \\\n inline void name(__VA_ARGS__) { \\\n  HG(op, 1); \\\n  if CE (t > 1) HG(op,\
    \ 2); \\\n  if CE (t > 2) HG(op, 3); \\\n  if CE (t > 3) HG(op, 4); \\\n  if CE\
    \ (t > 4) HG(op, 5); \\\n }\n#define REP for (int i= b; i < e; ++i)\n#define DFT(fft,\
    \ _) B::ntt##_::fft(e - b, this->dt##_ + b)\n#define ZEROS(op, _) fill_n(this->dt##_\
    \ + b, e - b, typename B::m##_())\n#define SET(op, _) copy(x + b, x + e, this->dt##_\
    \ + b)\n#define SET_S(op, _) this->dt##_[i]= x;\n#define SUBST(op, _) copy(r.dt##_\
    \ + b, r.dt##_ + e, this->dt##_ + b)\n#define ASGN(op, _) REP this->dt##_[i] op##=\
    \ r.dt##_[i]\n#define ASN(nm, op) TP<class C> FUNC(op, nm, ASGN, const NI<T, t,\
    \ C> &r, int b, int e)\n#define BOP(op, _) REP this->dt##_[i]= l.dt##_[i] op r.dt##_[i]\n\
    #define OP(nm, op) TP<class C, class D> FUNC(op, nm, BOP, const NI<T, t, C> &l,\
    \ const NI<T, t, D> &r, int b, int e)\n OP(add, +) OP(dif, -) OP(mul, *) ASN(add,\
    \ +) ASN(dif, -) ASN(mul, *) FUNC(dft, dft, DFT, int b, int e) FUNC(idft, idft,\
    \ DFT, int b, int e) FUNC(__, zeros, ZEROS, int b, int e) FUNC(__, set, SET, const\
    \ T x[], int b, int e) FUNC(__, set, SET_S, int i, T x) TP<class C> FUNC(__, subst,\
    \ SUBST, const NI<T, t, C> &r, int b, int e) inline void get(T x[], int b, int\
    \ e) const {\n  if CE (t == 1) copy(this->dt1 + b, this->dt1 + e, x + b);\n  else\
    \ REP x[i]= get(i);\n }\n#define TMP(_) B::iv##_##1 * (this->dt##_[i] - r1)\n\
    \ inline T get(int i) const {\n  if CE (t > 1) {\n   u64 r1= this->dt1[i].val(),\
    \ r2= (TMP(2)).val();\n   T a= 0;\n   if CE (t > 2) {\n    u64 r3= (TMP(3) - B::iv32\
    \ * r2).val();\n    if CE (t > 3) {\n     u64 r4= (TMP(4) - B::iv42 * r2 - B::iv43\
    \ * r3).val();\n     if CE (t > 4) a= B::m4::mod() * (TMP(5) - B::iv52 * r2 -\
    \ B::iv53 * r3 - B::iv54 * r4).val();\n     a= B::m3::mod() * (a + r4);\n    }\n\
    \    a= B::m2::mod() * (a + r3);\n   }\n   return B::m1::mod() * (a + r2) + r1;\n\
    \  } else return this->dt1[i];\n }\n#undef TMP\n#undef DFT\n#undef ZEROS\n#undef\
    \ SET\n#undef SET_S\n#undef SUBST\n#undef ASGN\n#undef ASN\n#undef BOP\n#undef\
    \ OP\n#undef FUNC\n#undef REP\n};\n#define ARR(_) \\\n using m##_= StaticModInt<M##_>;\
    \ \\\n using ntt##_= NTT<m##_>; \\\n m##_ dt##_[LM]= {};\n#define IV2 ST CE m2\
    \ iv21= m2(1) / m1::mod();\n#define IV3 ST CE m3 iv32= m3(1) / m2::mod(), iv31=\
    \ iv32 / m1::mod();\n#define IV4 ST CE m4 iv43= m4(1) / m3::mod(), iv42= iv43\
    \ / m2::mod(), iv41= iv42 / m1::mod();\n#define IV5 ST CE m5 iv54= m5(1) / m4::mod(),\
    \ iv53= iv54 / m3::mod(), iv52= iv53 / m2::mod(), iv51= iv52 / m1::mod();\nTP<u8\
    \ t, u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM, bool v> struct NB { ARR(1)\
    \ };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2,\
    \ M3, M4, M5, LM, 0> { ARR(1) ARR(2) IV2 };\nTP<u64 M1, u32 M2, u32 M3, u32 M4,\
    \ u32 M5, u32 LM> struct NB<3, M1, M2, M3, M4, M5, LM, 0> { ARR(1) ARR(2) ARR(3)\
    \ IV2 IV3 };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4,\
    \ M1, M2, M3, M4, M5, LM, 0> { ARR(1) ARR(2) ARR(3) ARR(4) IV2 IV3 IV4 };\nTP<u64\
    \ M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5,\
    \ LM, 0> { ARR(1) ARR(2) ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5 };\n#undef ARR\n\
    #define VC(_) \\\n using m##_= StaticModInt<M##_>; \\\n using ntt##_= NTT<m##_>;\
    \ \\\n vector<m##_> bf##_; \\\n m##_ *dt##_;\n#define RS resize\nTP<u64 M1, u32\
    \ M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<1, M1, M2, M3, M4, M5, LM, 1>\
    \ {\n NB(): dt1(bf1.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data();\
    \ }\n u32 size() const { return bf1.size(); }\n VC(1)\n};\nTP<u64 M1, u32 M2,\
    \ u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4, M5, LM, 1> {\n\
    \ NB(): dt1(bf1.data()), dt2(bf2.data()) {}\n void RS(int n) { bf1.RS(n), dt1=\
    \ bf1.data(), bf2.RS(n), dt2= bf2.data(); }\n u32 size() const { return bf1.size();\
    \ }\n VC(1) VC(2) IV2\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM>\
    \ struct NB<3, M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()),\
    \ dt3(bf3.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n),\
    \ dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(); }\n u32 size() const { return bf1.size();\
    \ }\n VC(1) VC(2) VC(3) IV2 IV3\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5,\
    \ u32 LM> struct NB<4, M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()),\
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
    \ get_len(unsigned n) { return 1 << (std::__lg(n - 1) + 1); }\n#line 4 \"src/FFT/BigInt.hpp\"\
    \nclass BigInt {\n static constexpr unsigned BASE= 10000000, D= 7;\n using mod_t=\
    \ StaticModInt<0x3ffffffffa000001>;\n using Vec= std::vector<unsigned>;\n using\
    \ ntt= NTT<mod_t>;\n bool neg;\n Vec dat;\n BigInt shift(int sz) const { return\
    \ {neg, Vec(dat.begin() + sz, dat.end())}; }\n BigInt(bool n, const Vec &d): neg(n),\
    \ dat(d) {}\npublic:\n BigInt(): neg(false), dat() {}\n BigInt(long long v): neg(v\
    \ < 0) {\n  for (v= std::abs(v); v; v/= BASE) dat.push_back(v % BASE);\n }\n BigInt(const\
    \ std::string &s): neg(false) {\n  int p= 0, x= 0;\n  for (; p < (int)s.size()\
    \ && (s[p] == '-' || s[p] == '+'); p++)\n   if (s[p] == '-') neg= !neg;\n  for\
    \ (int i= s.size(), j; i > p; i-= D, dat.push_back(x), x= 0)\n   for (j= std::max(p,\
    \ i - int(D)); j < i;) x= x * 10 + s[j++] - '0';\n  shrink();\n }\n inline void\
    \ shrink() {\n  while (!dat.empty() && !dat.back()) dat.pop_back();\n  if (dat.empty())\
    \ neg= false;\n }\n std::string to_str() const {\n  if (is_zero()) return \"0\"\
    ;\n  std::stringstream ss;\n  if (neg) ss << '-';\n  ss << (dat.empty() ? 0 :\
    \ dat.back());\n  for (long long i= dat.size() - 1; i-- > 0;) ss << std::setw(D)\
    \ << std::setfill('0') << dat[i];\n  std::string ret;\n  return ss >> ret, ret;\n\
    \ }\n bool is_zero() const { return dat.empty() || (dat.size() == 1 && !dat[0]);\
    \ }\n bool operator<(const BigInt &r) const {\n  if (neg != r.neg) return neg;\n\
    \  if (dat.size() != r.dat.size()) return (dat.size() < r.dat.size()) ^ neg;\n\
    \  for (int i= dat.size(); i--;)\n   if (dat[i] != r.dat[i]) return (dat[i] <\
    \ r.dat[i]) ^ neg;\n  return false;\n }\n bool operator>(const BigInt &r) const\
    \ { return r < *this; }\n bool operator<=(const BigInt &r) const { return !(r\
    \ < *this); }\n bool operator>=(const BigInt &r) const { return !(*this < r);\
    \ }\n bool operator==(const BigInt &r) const { return (neg == r.neg && dat ==\
    \ r.dat) || (is_zero() && r.is_zero()); }\n bool operator!=(const BigInt &r) const\
    \ { return !(*this == r); }\n BigInt abs() const { return BigInt(false, dat);\
    \ }\n BigInt operator-() const { return BigInt(!neg, dat); }\n BigInt operator+(const\
    \ BigInt &r) const {\n  if (neg != r.neg) return *this - (-r);\n  auto [ret, tmp]=\
    \ dat.size() > r.dat.size() ? std::make_pair(*this, &r) : std::make_pair(r, this);\n\
    \  int car= 0, i, n= ret.dat.size(), m= tmp->dat.size();\n  for (i= 0; i < m;\
    \ i++) ret.dat[i]-= BASE & -(car= ((ret.dat[i]+= car + tmp->dat[i]) >= BASE));\n\
    \  if (car) {\n   while (i < n && ret.dat[i] == BASE - 1) ret.dat[i++]= 0;\n \
    \  i < n ? ret.dat[i]++ : (ret.dat.push_back(1), 0);\n  }\n  return ret;\n }\n\
    \ BigInt operator-(const BigInt &r) const {\n  if (neg != r.neg) return *this\
    \ + (-r);\n  if (r.is_zero()) return *this;\n  if (is_zero()) return -r;\n  auto\
    \ [ret, tmp]= abs() > r.abs() ? std::make_pair(*this, &r) : std::make_pair(r,\
    \ this);\n  int car= 0, i, n= ret.dat.size(), m= tmp->dat.size();\n  for (i= 0;\
    \ i < m; i++) ret.dat[i]+= BASE & -(car= ((ret.dat[i]-= car + tmp->dat[i]) >>\
    \ 31));\n  while (car && i < n && !ret.dat[i]) ret.dat[i++]= BASE - 1;\n  return\
    \ ret.neg^= (tmp == this), ret.dat[i]-= car, ret.shrink(), ret;\n }\n long long\
    \ operator%(long long r) const {\n  long long ret= 0;\n  for (int i= dat.size();\
    \ i--;) ret= (ret * BASE + dat[i]) % r;\n  return ret;\n }\n BigInt operator*(const\
    \ BigInt &r) const {\n  if (is_zero() || r.is_zero()) return 0;\n  const int n=\
    \ dat.size(), m= r.dat.size(), sz= n + m - 1;\n  static mod_t f[1 << 20], g[1\
    \ << 20], f2[1 << 17][16], g2[1 << 17][16];\n  static long long h[1 << 20];\n\
    \  if (int i= n, j; std::min(n, m) >= 74) {\n   const int rl= get_len(sz), l=\
    \ get_len(std::max(n, m));\n   const int fl= std::pow(l, 0.535) * 8.288;\n   if\
    \ (l + fl < sz && sz <= (rl >> 3) * 5) {\n    const int l= rl >> 4, l2= l << 1,\
    \ nn= (n + l - 1) / l, mm= (m + l - 1) / l, ss= nn + mm - 1;\n    for (int k=\
    \ i= 0, s; k < n; i++, k+= l) {\n     for (j= s= std::min(l, n - k); j--;) f2[i][j]=\
    \ dat[k + j];\n     std::fill_n(f2[i] + s, l2 - s, mod_t()), ntt::dft(l2, f2[i]);\n\
    \    }\n    if (this != &r)\n     for (int k= i= 0, s; k < m; i++, k+= l) {\n\
    \      for (j= s= std::min(l, m - k); j--;) g2[i][j]= dat[k + j];\n      std::fill_n(g2[i]\
    \ + s, l2 - s, mod_t()), ntt::dft(l2, g2[i]);\n     }\n    else\n     for (i=\
    \ nn; i--;) std::copy_n(f2[i], l2, g2[i]);\n    for (i= l2; i--;) f[i]= f2[0][i]\
    \ * g2[0][i];\n    for (ntt::idft(l2, f), i= l2; i--;) h[i]= f[i].val();\n   \
    \ for (int k= l, ed, ii= 1; ii < ss; ++ii, k+= l) {\n     j= std::max(0, ii -\
    \ nn + 1), ed= std::min(mm - 1, ii);\n     for (i= l2; i--;) f[i]= f2[ii - ed][i]\
    \ * g2[ed][i];\n     for (; j < ed; ++j)\n      for (i= l2; i--;) f[i]+= f2[ii\
    \ - j][i] * g2[j][i];\n     for (ntt::idft(l2, f), i= std::min(l, sz - k); i--;)\
    \ h[i + k]+= f[i].val();\n     for (i= std::min(l2, sz - k); i-- > l;) h[i + k]=\
    \ f[i].val();\n    }\n   } else {\n    const int len= sz <= l + fl ? l : get_len(sz);\n\
    \    for (i= n; i--;) f[i]= dat[i];\n    std::fill_n(f + n, len - n, mod_t()),\
    \ ntt::dft(len, f);\n    if (this != &r) {\n     for (i= m; i--;) g[i]= r.dat[i];\n\
    \     std::fill_n(g + m, len - m, mod_t()), ntt::dft(len, g);\n     for (i= len;\
    \ i--;) f[i]*= g[i];\n    } else\n     for (i= len; i--;) f[i]*= f[i];\n    for\
    \ (ntt::idft(len, f), i= len; i < sz; f[i - len]-= h[i], i++)\n     for (h[i]=\
    \ 0, j= i - m + 1; j < n; j++) h[i]+= (long long)dat[j] * r.dat[i - j];\n    for\
    \ (i= std::min(sz, len); i--;) h[i]= f[i].val();\n   }\n  } else\n   for (std::fill_n(h,\
    \ sz, 0); i--;)\n    for (j= m; j--;) h[i + j]+= (long long)dat[i] * r.dat[j];\n\
    \  BigInt ret(neg ^ r.neg, Vec(sz));\n  long long car= 0;\n  for (int i= 0; i\
    \ < sz; i++, car/= BASE) ret.dat[i]= (car+= h[i]) % BASE;\n  for (; car; car/=\
    \ BASE) ret.dat.emplace_back(car % BASE);\n  return ret;\n }\n BigInt operator/(const\
    \ BigInt &r) const {\n  assert(!r.is_zero());\n  if (r.dat.size() == 1 && r.dat.back()\
    \ == 1) return r.neg ? -*this : *this;\n  BigInt a= this->abs(), b= r.abs();\n\
    \  if (a < b) return 0;\n  const int pb= dat.size(), qb= r.dat.size(), prec= std::max(pb\
    \ - qb, 1);\n  int l= std::min(prec, 3), ql= std::min(qb, 6), nl, nql;\n  BigInt\
    \ x(0, Vec(l + 1)), p, rr= b.shift(qb - ql), c(0, Vec(l + ql + 1));\n  x.dat.back()=\
    \ 1, c.dat.back()= 2;\n  while (x != p) p.dat.swap(x.dat), x= (p * (c - rr * p)).shift(l\
    \ + ql);\n  if (l != prec)\n   for (p.neg= true; x != p; l= nl, ql= nql) {\n \
    \   nl= std::min(l * 2 + 1, prec), nql= std::min(ql * 2 + 1, qb);\n    p.dat.swap(x.dat),\
    \ x= (p * (c - rr * p)).shift(2 * l - nl + ql);\n    if (p.neg= false; nql !=\
    \ ql) rr= b.shift(qb - nql);\n    c.dat.back()= 0, c.dat.resize(nql + nl + 1),\
    \ c.dat.back()= 2;\n   }\n  if (x= (x * a).shift(pb + (pb == qb)); a >= (x + 1)\
    \ * b) x+= 1;\n  return x.neg= neg ^ r.neg, x;\n }\n BigInt operator%(const BigInt\
    \ &r) const { return *this - (*this / r) * r; }\n BigInt &operator+=(const BigInt\
    \ &r) { return *this= *this + r; }\n BigInt &operator-=(const BigInt &r) { return\
    \ *this= *this - r; }\n BigInt &operator*=(const BigInt &r) { return *this= *this\
    \ * r; }\n BigInt &operator/=(const BigInt &r) { return *this= *this / r; }\n\
    \ BigInt &operator%=(const BigInt &r) { return *this= *this % r; }\n friend std::istream\
    \ &operator>>(std::istream &is, BigInt &v) {\n  std::string s;\n  return is >>\
    \ s, v= BigInt(s), is;\n }\n friend std::ostream &operator<<(std::ostream &os,\
    \ const BigInt &v) { return os << v.to_str(), os; }\n};\n#line 5 \"test/aoj/NTL_2_F.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  BigInt A, B;\n  cin >> A >> B;\n  cout << A * B << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F\"\
    \n#include <bits/stdc++.h>\n#include \"src/FFT/BigInt.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  BigInt A,\
    \ B;\n  cin >> A >> B;\n  cout << A * B << endl;\n  return 0;\n}"
  dependsOn:
  - src/FFT/BigInt.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  isVerificationFile: true
  path: test/aoj/NTL_2_F.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 19:14:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_2_F.test.cpp
- /verify/test/aoj/NTL_2_F.test.cpp.html
title: test/aoj/NTL_2_F.test.cpp
---
