---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':x:'
    path: src/FFT/fps_div.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 div"
  - icon: ':x:'
    path: src/FFT/fps_exp.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 log, exp, pow"
  - icon: ':x:'
    path: src/FFT/fps_inv.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 inv"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':x:'
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
  attributes: {}
  bundledCode: "#line 1 \"test/yosupo/sharp_p_subset_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n\
    \ for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a / b), a= b,\
    \ b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n\
    }\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace math_internal {\nusing\
    \ namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\n\
    using i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL\
    \ inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U,\
    \ M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n\
    \  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const {\
    \ \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n\
    \ static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n const u_t mod;\n CE MP_Mo(): mod(0), iv(0),\
    \ r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE\
    \ IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod\
    \ << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n,\
    \ r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL\
    \ u_t norm(u_t n) const { NORM; }\nprivate:\n const u_t iv, r2;\n CE u_t inv(u_t\
    \ n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n\
    \ CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w)\
    \ * iv) * mod) >> B); }\n};\nstruct MP_Na {\n const u32 mod;\n CE MP_Na(): mod(0){};\n\
    \ CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n const u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: const u8 s;\n const u64 x;\n CE IL u64 quo(u64 n)\
    \ const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n\
    \ - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n const u64 mod;\n\
    \ CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) /\
    \ m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64,\
    \ mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n;\
    \ }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM;\
    \ }\nprivate:\n const u64 x;\n CE IL u128 quo(const u128 &n) const { return (n\
    \ * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_D2B1 {\n const u64 mod;\n CE MP_D2B1(): mod(0), s(0), d(0),\
    \ v(0) {}\n CE MP_D2B1(u64 m): mod(m), s(__builtin_clzll(m)), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    \ const u8 s;\n const u64 d, v;\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t\
    \ x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if\
    \ (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef\
    \ PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 5 \"src/Math/ModInt.hpp\"\
    \nnamespace math_internal {\n#define CE constexpr\nstruct m_b {};\nstruct s_b:\
    \ m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\n\
    template <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\n\
    template <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n\
    };\ntemplate <class Int, class U, class B> struct MInt: public B {\n using Uint=\
    \ U;\n static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n\
    \ CE MInt(const MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n % B::md.mod)))\
    \ {}\n CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name,\
    \ op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  ret.x= op; \\\n  return\
    \ ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x, r.x))\n FUNC(operator-(const\
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
    \ Uint x;\n};\ntemplate <u64 MOD> using ModInt= conditional_t < (MOD < (1 << 30))\
    \ & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32, 31>, MOD>>, conditional_t<(MOD\
    \ < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<INT_MAX,\
    \ MInt<int, u32, SB<MP_Na, MOD>>, conditional_t<MOD <= UINT_MAX, MInt<i64, u32,\
    \ SB<MP_Na, MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2,\
    \ MOD>>, MInt<i64, u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt,\
    \ math_internal::is_modint_v, math_internal::is_staticmodint_v;\n#line 4 \"src/Math/is_prime.hpp\"\
    \nnamespace math_internal {\ntemplate <class Uint, class MP, u64... args> constexpr\
    \ bool miller_rabin(Uint n) {\n const MP md(n);\n const Uint s= __builtin_ctzll(n\
    \ - 1), d= n >> s, one= md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a:\
    \ {args...})\n  if (Uint b= a % n; b)\n   if (Uint p= md.norm(pow(md.set(b), d,\
    \ md)); p != one)\n    for (int i= s; p != n1; p= md.norm(md.mul(p, p)))\n   \
    \  if (!(--i)) return 0;\n return 1;\n}\nconstexpr bool is_prime(u64 n) {\n if\
    \ (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n if (n < (1 << 30)) return miller_rabin<u32,\
    \ MP_Mo<u32, u64, 32, 31>, 2, 7, 61>(n);\n if (n < (1ull << 62)) return miller_rabin<u64,\
    \ MP_Mo<u64, u128, 64, 63>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    \ return miller_rabin<u64, MP_D2B1, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    }\n}\nusing math_internal::is_prime;\n#line 5 \"src/FFT/NTT.hpp\"\nnamespace math_internal\
    \ {\n#define CE constexpr\n#define ST static\n#define TP template\n#define BSF(_,\
    \ n) __builtin_ctz##_(n)\nTP<class mod_t> struct NTT {\n#define _DFT(a, b, c,\
    \ ...) \\\n mod_t r, u, *x0, *x1; \\\n for (int a= n, b= 1, s, i; a>>= 1; b<<=\
    \ 1) \\\n  for (s= 0, r= I, x0= x;; r*= c[BSF(, s)], x0= x1 + p) { \\\n   for\
    \ (x1= x0 + (i= p); i--;) __VA_ARGS__; \\\n   if (++s == e) break; \\\n  }\n ST\
    \ inline void dft(int n, mod_t x[]) { _DFT(p, e, r2, x1[i]= x0[i] - (u= r * x1[i]),\
    \ x0[i]+= u); }\n ST inline void idft(int n, mod_t x[]) {\n  _DFT(e, p, ir2, u=\
    \ x0[i] - x1[i], x0[i]+= x1[i], x1[i]= r * u)\n  for (const mod_t iv= I / n; n--;)\
    \ x[n]*= iv;\n }\n#undef _DFT\n ST inline void even_dft(int n, mod_t x[]) {\n\
    \  for (int i= 0, j= 0; i < n; i+= 2) x[j++]= iv2 * (x[i] + x[i + 1]);\n }\n ST\
    \ inline void odd_dft(int n, mod_t x[], mod_t r= iv2) {\n  for (int i= 0, j= 0;;\
    \ r*= ir2[BSF(, ++j)])\n   if (x[j]= r * (x[i] - x[i + 1]); (i+= 2) == n) break;\n\
    \ }\n ST inline void dft_doubling(int n, mod_t x[], int i= 0) {\n  mod_t k= I,\
    \ t= rt[BSF(, n << 1)];\n  for (copy_n(x, n, x + n), idft(n, x + n); i < n; ++i)\
    \ x[n + i]*= k, k*= t;\n  dft(n, x + n);\n }\nprotected:\n ST CE u64 md= mod_t::mod();\n\
    \ static_assert(md & 1);\n static_assert(is_prime(md));\n ST CE u8 E= BSF(ll,\
    \ md - 1);\n ST CE mod_t w= [](u8 e) {\n  for (mod_t r= 2;; r+= 1)\n   if (auto\
    \ s= r.pow((md - 1) / 2); s != 1 && s * s == 1) return r.pow((md - 1) >> e);\n\
    \  return mod_t();\n }(E);\n static_assert(w != mod_t());\n ST CE mod_t I= 1,\
    \ iv2= (md + 1) / 2, iw= w.pow((1ULL << E) - 1);\n ST CE auto roots(mod_t w) {\n\
    \  array<mod_t, E + 1> x= {};\n  for (u8 e= E; e; w*= w) x[e--]= w;\n  return\
    \ x[0]= w, x;\n }\n TP<u32 N> ST CE auto ras(const array<mod_t, E + 1>& rt, const\
    \ array<mod_t, E + 1>& irt, int i= N) {\n  array<mod_t, E + 1 - N> x= {};\n  for\
    \ (mod_t ro= 1; i <= E; ro*= irt[i++]) x[i - N]= rt[i] * ro;\n  return x;\n }\n\
    \ ST CE auto rt= roots(w), irt= roots(iw);\n ST CE auto r2= ras<2>(rt, irt), ir2=\
    \ ras<2>(irt, rt);\n};\nTP<class T, u8 t, class B> struct NI: public B {\n using\
    \ B::B;\n#define FUNC(op, name, HG, ...) \\\n inline void name(__VA_ARGS__) {\
    \ \\\n  HG(op, 1); \\\n  if CE (t > 1) HG(op, 2); \\\n  if CE (t > 2) HG(op, 3);\
    \ \\\n  if CE (t > 3) HG(op, 4); \\\n  if CE (t > 4) HG(op, 5); \\\n }\n#define\
    \ REP for (int i= b; i < e; ++i)\n#define DFT(fft, _) B::ntt##_::fft(e - b, this->dt##_\
    \ + b)\n#define ZEROS(op, _) fill_n(this->dt##_ + b, e - b, typename B::m##_())\n\
    #define SET(op, _) copy(x + b, x + e, this->dt##_ + b)\n#define SET_S(op, _) this->dt##_[i]=\
    \ x;\n#define SUBST(op, _) copy(r.dt##_ + b, r.dt##_ + e, this->dt##_ + b)\n#define\
    \ ASGN(op, _) REP this->dt##_[i] op##= r.dt##_[i]\n#define ASN(nm, op) TP<class\
    \ C> FUNC(op, nm, ASGN, const NI<T, t, C>& r, int b, int e)\n#define BOP(op, _)\
    \ REP this->dt##_[i]= l.dt##_[i] op r.dt##_[i]\n#define OP(nm, op) TP<class C,\
    \ class D> FUNC(op, nm, BOP, const NI<T, t, C>& l, const NI<T, t, D>& r, int b,\
    \ int e)\n OP(add, +) OP(dif, -) OP(mul, *) ASN(add, +) ASN(dif, -) ASN(mul, *)\
    \ FUNC(dft, dft, DFT, int b, int e) FUNC(idft, idft, DFT, int b, int e) FUNC(__,\
    \ zeros, ZEROS, int b, int e) FUNC(__, set, SET, const T x[], int b, int e) FUNC(__,\
    \ set, SET_S, int i, T x) TP<class C> FUNC(__, subst, SUBST, const NI<T, t, C>&\
    \ r, int b, int e) inline void get(T x[], int b, int e) const {\n  if CE (t ==\
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
    \ FUNC\n#undef REP\n};\n#define ARR(_) \\\n using m##_= ModInt<M##_>; \\\n using\
    \ ntt##_= NTT<m##_>; \\\n m##_ dt##_[LM]= {};\n#define IV2 ST CE m2 iv21= m2(1)\
    \ / m1::mod();\n#define IV3 ST CE m3 iv32= m3(1) / m2::mod(), iv31= iv32 / m1::mod();\n\
    #define IV4 ST CE m4 iv43= m4(1) / m3::mod(), iv42= iv43 / m2::mod(), iv41= iv42\
    \ / m1::mod();\n#define IV5 ST CE m5 iv54= m5(1) / m4::mod(), iv53= iv54 / m3::mod(),\
    \ iv52= iv53 / m2::mod(), iv51= iv52 / m1::mod();\nTP<u8 t, u64 M1, u32 M2, u32\
    \ M3, u32 M4, u32 M5, u32 LM, bool v> struct NB { ARR(1) };\nTP<u64 M1, u32 M2,\
    \ u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4, M5, LM, 0> { ARR(1)\
    \ ARR(2) IV2 };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<3,\
    \ M1, M2, M3, M4, M5, LM, 0> { ARR(1) ARR(2) ARR(3) IV2 IV3 };\nTP<u64 M1, u32\
    \ M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4, M1, M2, M3, M4, M5, LM, 0>\
    \ { ARR(1) ARR(2) ARR(3) ARR(4) IV2 IV3 IV4 };\nTP<u64 M1, u32 M2, u32 M3, u32\
    \ M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5, LM, 0> { ARR(1) ARR(2)\
    \ ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5 };\n#undef ARR\n#define VC(_) \\\n using\
    \ m##_= ModInt<M##_>; \\\n using ntt##_= NTT<m##_>; \\\n vector<m##_> bf##_; \\\
    \n m##_* dt##_;\n#define RS resize\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5,\
    \ u32 LM> struct NB<1, M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()) {}\n\
    \ void RS(int n) { bf1.RS(n), dt1= bf1.data(); }\n u32 size() const { return bf1.size();\
    \ }\n VC(1)\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2,\
    \ M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()) {}\n void\
    \ RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(); }\n u32\
    \ size() const { return bf1.size(); }\n VC(1) VC(2) IV2\n};\nTP<u64 M1, u32 M2,\
    \ u32 M3, u32 M4, u32 M5, u32 LM> struct NB<3, M1, M2, M3, M4, M5, LM, 1> {\n\
    \ NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()) {}\n void RS(int n)\
    \ { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data();\
    \ }\n u32 size() const { return bf1.size(); }\n VC(1) VC(2) VC(3) IV2 IV3\n};\n\
    TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4, M1, M2, M3, M4,\
    \ M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()), dt4(bf4.data())\
    \ {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(),\
    \ bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(); }\n u32 size() const\
    \ { return bf1.size(); }\n VC(1) VC(2) VC(3) VC(4) IV2 IV3 IV4\n};\nTP<u64 M1,\
    \ u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5, LM,\
    \ 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()), dt4(bf4.data()),\
    \ dt5(bf5.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n),\
    \ dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(), bf5.RS(n),\
    \ dt5= bf5.data(); }\n u32 size() const { return bf1.size(); }\n VC(1) VC(2) VC(3)\
    \ VC(4) VC(5) IV2 IV3 IV4 IV5\n};\n#undef VC\n#undef IV2\n#undef IV3\n#undef IV4\n\
    #undef IV5\nTP<class T, u32 LM> CE bool is_nttfriend() {\n if CE (!is_staticmodint_v<T>)\
    \ return 0;\n else return (T::mod() & is_prime(T::mod())) && LM <= (1ULL << BSF(ll,\
    \ T::mod() - 1));\n}\nTP<class T, enable_if_t<is_arithmetic_v<T>, nullptr_t> =\
    \ nullptr> CE u64 mv() { return numeric_limits<T>::max(); }\nTP<class T, enable_if_t<is_staticmodint_v<T>,\
    \ nullptr_t> = nullptr> CE u64 mv() { return T::mod(); }\nTP<class T, u32 LM,\
    \ u32 M1, u32 M2, u32 M3, u32 M4> CE u8 nt() {\n if CE (!is_nttfriend<T, LM>())\
    \ {\n  CE u128 m= mv<T>(), mm= m * m;\n  if CE (mm <= M1 / LM) return 1;\n  else\
    \ if CE (mm <= u64(M1) * M2 / LM) return 2;\n  else if CE (mm <= u128(M1) * M2\
    \ * M3 / LM) return 3;\n  else if CE (mm <= u128(M1) * M2 * M3 * M4 / LM) return\
    \ 4;\n  else return 5;\n } else return 1;\n}\n#undef BSF\n#undef RS\nCE u32 MOD1=\
    \ 998244353, MOD2= 897581057, MOD3= 880803841, MOD4= 754974721, MOD5= 645922817;\n\
    TP<class T, u32 LM> CE u8 nttarr_type= nt<T, LM, MOD1, MOD2, MOD3, MOD4>();\n\
    TP<class T, u32 LM> CE u8 nttarr_cat= is_nttfriend<T, LM>() && (mv<T>() > (1 <<\
    \ 30)) ? 0 : nttarr_type<T, LM>;\nTP<class T, u32 LM, bool v> using NTTArray=\
    \ NI<T, nttarr_type<T, LM>, conditional_t<is_nttfriend<T, LM>(), NB<1, mv<T>(),\
    \ 0, 0, 0, 0, LM, v>, NB<nttarr_type<T, LM>, MOD1, MOD2, MOD3, MOD4, MOD5, LM,\
    \ v>>>;\n#undef CE\n#undef ST\n#undef TP\n}\nusing math_internal::is_nttfriend,\
    \ math_internal::nttarr_type, math_internal::nttarr_cat, math_internal::NTT, math_internal::NTTArray;\n\
    template <class T, size_t LM, int id= 0> struct GlobalNTTArray { static inline\
    \ NTTArray<T, LM, 0> bf; };\ntemplate <class T, size_t LM, size_t LM2, int id=\
    \ 0> struct GlobalNTTArray2D { static inline NTTArray<T, LM, 0> bf[LM2]; };\n\
    template <class T, size_t LM, int id= 0> struct GlobalArray { static inline T\
    \ bf[LM]; };\nconstexpr unsigned pw2(unsigned n) { return --n, n|= n >> 1, n|=\
    \ n >> 2, n|= n >> 4, n|= n >> 8, n|= n >> 16, ++n; }\n#line 4 \"src/FFT/fps_inv.hpp\"\
    \nnamespace math_internal {\ntemplate <u32 LM, class mod_t> inline void inv_base(const\
    \ mod_t p[], int n, mod_t r[], int i= 1, int l= -1) {\n static constexpr int t=\
    \ nttarr_cat<mod_t, LM>, TH= (int[]){64, 32, 64, 128, 128, 256}[t];\n if (n <=\
    \ i) return;\n if (l < 0) l= n;\n assert(((n & -n) == n)), assert(i && ((i & -i)\
    \ == i));\n if (const mod_t miv= -r[0]; n > TH) {\n  static constexpr int lnR=\
    \ 2 + (!t), LM2= LM >> (lnR - 1), R= (1 << lnR) - 1;\n  const auto [m, skip]=\
    \ [&]() {\n   if constexpr (!t) {\n    const int bn= __builtin_ctz(n) % 3;\n \
    \   return bn ? make_pair(64, bn) : make_pair(32, 1);\n   } else return make_pair(TH,\
    \ 1 + (__builtin_ctz(TH) & 1));\n  }();\n  for (int j; i < m; r[i++]*= miv)\n\
    \   for (r[i]= mod_t(), j= min(i + 1, l); --j;) r[i]+= r[i - j] * p[j];\n  using\
    \ GNA1= GlobalNTTArray<mod_t, LM2, 1>;\n  using GNA2= GlobalNTTArray<mod_t, LM2,\
    \ 2>;\n  auto gt1= GlobalNTTArray2D<mod_t, LM2, R, 1>::bf, gt2= GlobalNTTArray2D<mod_t,\
    \ LM2, R, 2>::bf;\n  for (int ed= (1 << skip) - 1; i < n; ed= R) {\n   mod_t*\
    \ rr= r;\n   const mod_t* pp= p;\n   const int s= i, e= s << 1, ss= (l - 1) /\
    \ s;\n   for (int k= 0, j; i < n && k < ed; ++k, i+= s, pp+= s) {\n    if (j=\
    \ min(e, l - k * s); j > 0) gt2[k].set(pp, 0, j), gt2[k].zeros(j, e), gt2[k].dft(0,\
    \ e);\n    for (gt1[k].set(rr, 0, s), gt1[k].zeros(s, e), gt1[k].dft(0, e), GNA2::bf.mul(gt1[k],\
    \ gt2[0], 0, e), j= min(k, ss) + 1; --j;) GNA1::bf.mul(gt1[k - j], gt2[j], 0,\
    \ e), GNA2::bf.add(GNA1::bf, 0, e);\n    GNA2::bf.idft(0, e), GNA2::bf.zeros(0,\
    \ s);\n    if constexpr (!is_nttfriend<mod_t, LM2>()) GNA2::bf.get(rr, s, e),\
    \ GNA2::bf.set(rr, s, e);\n    for (GNA2::bf.dft(0, e), GNA2::bf.mul(gt1[0], 0,\
    \ e), GNA2::bf.idft(0, e), GNA2::bf.get(rr, s, e), rr+= s, j= s; j--;) rr[j]=\
    \ -rr[j];\n   }\n  }\n } else\n  for (int j; i < n; r[i++]*= miv)\n   for (r[i]=\
    \ mod_t(), j= min(i + 1, l); --j;) r[i]+= r[i - j] * p[j];\n}\ntemplate <u32 lnR,\
    \ class mod_t, u32 LM= 1 << 22> void inv_(const mod_t p[], int n, mod_t r[]) {\n\
    \ static constexpr u32 R= (1 << lnR) - 1, LM2= LM >> (lnR - 1);\n using GNA1=\
    \ GlobalNTTArray<mod_t, LM2, 1>;\n using GNA2= GlobalNTTArray<mod_t, LM2, 2>;\n\
    \ auto gt1= GlobalNTTArray2D<mod_t, LM2, R, 1>::bf, gt2= GlobalNTTArray2D<mod_t,\
    \ LM2, R, 2>::bf;\n assert(n > 0), assert(p[0] != mod_t());\n const int m= pw2(n)\
    \ >> lnR, m2= m << 1, ed= (n - 1) / m;\n inv_base<LM2>(p, m, r);\n for (int k=\
    \ 0, l; k < ed; p+= m) {\n  for (gt2[k].set(p, 0, l= min(m2, n - m * k)), gt2[k].zeros(l,\
    \ m2), gt2[k].dft(0, m2), gt1[k].set(r, 0, m), gt1[k].zeros(m, m2), gt1[k].dft(0,\
    \ m2), GNA2::bf.mul(gt1[k], gt2[0], 0, m2), l= k; l--;) GNA1::bf.mul(gt1[l], gt2[k\
    \ - l], 0, m2), GNA2::bf.add(GNA1::bf, 0, m2);\n  GNA2::bf.idft(0, m2), GNA2::bf.zeros(0,\
    \ m);\n  if constexpr (!is_nttfriend<mod_t, LM2>()) GNA2::bf.get(r, m, m2), GNA2::bf.set(r,\
    \ m, m2);\n  for (GNA2::bf.dft(0, m2), GNA2::bf.mul(gt1[0], 0, m2), GNA2::bf.idft(0,\
    \ m2), GNA2::bf.get(r, m, m + (l= min(m, n - m * ++k))), r+= m; l--;) r[l]= -r[l];\n\
    \ }\n}\ntemplate <class mod_t, u32 LM= 1 << 22> vector<mod_t> inv(const vector<mod_t>&\
    \ p) {\n static constexpr int t= nttarr_cat<mod_t, LM>, TH= (int[]){102, 60, 178,\
    \ 245, 370, 480}[t];\n mod_t *pp= GlobalArray<mod_t, LM, 1>::bf, *r= GlobalArray<mod_t,\
    \ LM, 2>::bf;\n const int n= p.size();\n copy_n(p.begin(), n, pp), assert(n >\
    \ 0), assert(p[0] != mod_t());\n if (const mod_t miv= -(r[0]= mod_t(1) / p[0]);\
    \ n > TH) {\n  const int l= pw2(n), l1= l >> 1, k= (n - l1 - 1) / (l1 >> 3), bl=\
    \ __builtin_ctz(l1);\n  int a= 4;\n  if constexpr (!t) a= bl < 7 ? k > 5 ? 1 :\
    \ k > 4 ? 3 : k > 3 ? 4 : 2 : k & 1 ? 3 : 4;\n  else if constexpr (t < 2) a= bl\
    \ & 1 ? k > 5 ? 1 : bl < 8 ? 3 : bl < 12 ? k > 2 || k == 1 ? 3 : 4 : k & 1 ? 3\
    \ : 4 : k > 5 ? bl > 17 && k < 7 ? 4 : 2 : k > 4 ? 3 : k > 3 ? 4 : bl < 7 ? k\
    \ > 1 ? 2 : k ? 3 : 4 : k > 2 ? 2 : 4;\n  else if constexpr (t < 3) a= bl & 1\
    \ ? k > 5 ? 1 : bl < 8 ? k > 3 || k < 2 ? 3 : 2 : k & 1 ? 3 : 4 : k > 5 ? bl >\
    \ 13 && k < 7 ? 4 : 2 : k == 3 ? 2 : k & 1 ? 3 : 4;\n  else if constexpr (t <\
    \ 5) a= bl & 1 ? k > 5 ? 1 : k == 1 ? 3 : k < 3 ? 4 : bl > 12 && k == 4 ? 4 :\
    \ 3 : k > 5 ? bl > 13 && k < 7 ? 4 : 2 : k > 4 ? 3 : k > 3 ? 4 : bl < 9 ? k >\
    \ 1 ? 2 : k ? 3 : 4 : k > 2 ? 2 : 4;\n  else a= bl & 1 ? k > 5 ? 1 : bl < 10 ?\
    \ k > 3 || k < 2 ? 3 : 2 : k & 1 ? 3 : 4 : bl < 9 ? k > 3 ? 1 : 2 : k > 5 ? bl\
    \ > 13 && k < 7 ? 4 : 2 : k == 3 ? 2 : k & 1 ? 3 : 4;\n  (a < 2 ? inv_<1, mod_t,\
    \ LM> : a < 3 ? inv_<2, mod_t, LM> : a < 4 ? inv_<3, mod_t, LM> : inv_<4, mod_t,\
    \ LM>)(pp, n, r);\n } else\n  for (int j, i= 1; i < n; r[i++]*= miv)\n   for (r[j=\
    \ i]= mod_t(); j--;) r[i]+= r[j] * pp[i - j];\n return vector(r, r + n);\n}\n\
    }\nusing math_internal::inv_base, math_internal::inv;\n#line 4 \"src/FFT/fps_div.hpp\"\
    \nnamespace math_internal {\ntemplate <int TH, int lnR, int skip, size_t LM, class\
    \ mod_t> void div_base_(const mod_t p[], int n, const mod_t q[], int l, mod_t\
    \ r[], const mod_t iv[]) {\n static constexpr int LM2= LM >> (lnR - 1), R= (1\
    \ << lnR) - 1;\n using GNA1= GlobalNTTArray<mod_t, LM2, 1>;\n using GNA2= GlobalNTTArray<mod_t,\
    \ LM2, 2>;\n using GNA3= GlobalNTTArray<mod_t, LM2, 3>;\n auto gt1= GlobalNTTArray2D<mod_t,\
    \ LM2, R, 1>::bf, gt2= GlobalNTTArray2D<mod_t, LM2, R, 2>::bf;\n assert(n > 0),\
    \ assert(((n & -n) == n)), assert(l > 0);\n const mod_t iv0= iv[0];\n int i= 0;\n\
    \ for (copy_n(p, TH, r); i < TH; r[i++]*= iv0)\n  for (int j= min(i + 1, l); --j;)\
    \ r[i]-= r[i - j] * q[j];\n for (int ed= (1 << skip) - 1; i < n; ed= R) {\n  mod_t*\
    \ rr= r;\n  const mod_t *qq= q, *pp= p;\n  const int s= i, e= s << 1, ss= (l -\
    \ 1) / s;\n  GNA3::bf.set(iv, 0, s), GNA3::bf.zeros(s, e), GNA3::bf.dft(0, e);\n\
    \  for (int k= 0, j; i < n && k < ed; ++k, i+= s, qq+= s, pp+= s) {\n   if (j=\
    \ min(e, l - k * s); j > 0) gt2[k].set(qq, 0, j), gt2[k].zeros(j, e), gt2[k].dft(0,\
    \ e);\n   gt1[k].set(rr, 0, s), gt1[k].zeros(s, e), gt1[k].dft(0, e);\n   for\
    \ (GNA2::bf.mul(gt1[k], gt2[0], 0, e), j= min(k, ss) + 1; --j;) GNA1::bf.mul(gt1[k\
    \ - j], gt2[j], 0, e), GNA2::bf.add(GNA1::bf, 0, e);\n   GNA2::bf.idft(0, e),\
    \ GNA2::bf.zeros(0, s), GNA2::bf.get(rr, s, e);\n   for (j= s; j < e; ++j) rr[j]-=\
    \ pp[j];\n   GNA2::bf.set(rr, s, e), GNA2::bf.dft(0, e), GNA2::bf.mul(GNA3::bf,\
    \ 0, e), GNA2::bf.idft(0, e), GNA2::bf.get(rr, s, e);\n   for (rr+= s, j= s; j--;)\
    \ rr[j]= -rr[j];\n  }\n }\n}\ntemplate <size_t LM, class mod_t> void div_base(const\
    \ mod_t p[], int n, const mod_t q[], int l, mod_t r[], const mod_t iv[]) {\n static\
    \ constexpr int t= nttarr_cat<mod_t, LM>, TH= (int[]){64, 32, 128, 128, 128, 256}[t];\n\
    \ assert(n > 0), assert(((n & -n) == n)), assert(l > 0);\n const mod_t iv0= iv[0];\n\
    \ if (int i= 0; n > TH) {\n  if constexpr (t == 0) {\n   const int bn= __builtin_ctz(n)\
    \ % 3;\n   (bn == 0 ? div_base_<64, 3, 3, LM, mod_t> : bn == 1 ? div_base_<32,\
    \ 3, 2, LM, mod_t> : div_base_<32, 3, 3, LM, mod_t>)(p, n, q, l, r, iv);\n  }\
    \ else {\n   const int bn= __builtin_ctz(n) % 6;\n   if constexpr (t == 1) (bn\
    \ & 1 ? div_base_<32, 2, 2, LM, mod_t> : bn == 0 ? div_base_<32, 3, 1, LM, mod_t>\
    \ : bn == 2 ? div_base_<32, 3, 3, LM, mod_t> : div_base_<32, 3, 2, LM, mod_t>)(p,\
    \ n, q, l, r, iv);\n   else if constexpr (t == 5) (bn & 1 ? div_base_<128, 2,\
    \ 2, LM, mod_t> : bn == 0 ? div_base_<128, 3, 2, LM, mod_t> : bn == 2 ? div_base_<256,\
    \ 3, 3, LM, mod_t> : div_base_<128, 3, 3, LM, mod_t>)(p, n, q, l, r, iv);\n  \
    \ else (bn & 1 ? div_base_<128, 2, 2, LM, mod_t> : bn == 0 ? div_base_<128, 3,\
    \ 2, LM, mod_t> : bn == 2 ? div_base_<128, 3, 1, LM, mod_t> : div_base_<128, 3,\
    \ 3, LM, mod_t>)(p, n, q, l, r, iv);\n  }\n } else\n  for (copy_n(p, n, r); i\
    \ < n; r[i++]*= iv0)\n   for (int j= min(i + 1, l); --j;) r[i]-= r[i - j] * q[j];\n\
    }\ntemplate <size_t lnR, class mod_t, size_t LM= 1 << 22> void div_(const mod_t\
    \ p[], int n, const mod_t q[], int l, mod_t r[]) {\n static constexpr size_t R=\
    \ (1 << lnR) - 1, LM2= LM >> (lnR - 1);\n mod_t* iv= GlobalArray<mod_t, LM2, 2>::bf;\n\
    \ using GNA1= GlobalNTTArray<mod_t, LM2, 1>;\n using GNA2= GlobalNTTArray<mod_t,\
    \ LM2, 2>;\n using GNA3= GlobalNTTArray<mod_t, LM2, 3>;\n auto gt1= GlobalNTTArray2D<mod_t,\
    \ LM2, R, 1>::bf, gt2= GlobalNTTArray2D<mod_t, LM2, R, 2>::bf;\n const int m=\
    \ pw2(n) >> lnR, m2= m << 1, ed= (n - 1) / m, ss= (l - 1) / m;\n iv[0]= mod_t(1)\
    \ / q[0], inv_base<LM2>(q, m, iv, 1, l), div_base<LM2>(p, m, q, l, r, iv), GNA3::bf.set(iv,\
    \ 0, m), GNA3::bf.zeros(m, m2), GNA3::bf.dft(0, m2);\n for (int k= 0, i= m, j,\
    \ o; k < ed; ++k, i+= m, q+= m, p+= m) {\n  if (j= min(m2, l - k * m); j > 0)\
    \ gt2[k].set(q, 0, j), gt2[k].zeros(j, m2), gt2[k].dft(0, m2);\n  for (gt1[k].set(r,\
    \ 0, m), gt1[k].zeros(m, m2), gt1[k].dft(0, m2), GNA2::bf.mul(gt1[k], gt2[0],\
    \ 0, m2), j= min(k, ss) + 1; --j;) GNA1::bf.mul(gt1[k - j], gt2[j], 0, m2), GNA2::bf.add(GNA1::bf,\
    \ 0, m2);\n  for (GNA2::bf.idft(0, m2), GNA2::bf.zeros(0, m), GNA2::bf.get(r,\
    \ m, m + (o= min(m, n - i))), j= o + m; j-- > m;) r[j]-= p[j];\n  for (GNA2::bf.set(r,\
    \ m, m + o), GNA2::bf.dft(0, m2), GNA2::bf.mul(GNA3::bf, 0, m2), GNA2::bf.idft(0,\
    \ m2), GNA2::bf.get(r, m, m + o), r+= m, j= o; j--;) r[j]= -r[j];\n }\n}\ntemplate\
    \ <class mod_t, size_t LM= 1 << 22> vector<mod_t> div(const vector<mod_t>& p,\
    \ const vector<mod_t>& q) {\n static constexpr int t= nttarr_cat<mod_t, LM>, TH=\
    \ (int[]){107, 75, 205, 350, 450, 600}[t];\n mod_t *r= GlobalArray<mod_t, LM,\
    \ 1>::bf, *qq= GlobalArray<mod_t, LM, 2>::bf;\n const int n= p.size(), l= q.size();\n\
    \ assert(l > 0), assert(q[0] != mod_t(0));\n if (n > TH) {\n  const int m= pw2(n),\
    \ l1= m >> 1, k= (n - l1 - 1) / (l1 >> 3), bl= __builtin_ctz(l1);\n  int a= 5;\n\
    \  if constexpr (!t) a= bl < 8 ? 4 - (k & 1 && k > 2) : bl < 9 ? 4 : 4 + (k <\
    \ (bl == 9 ? 1 : bl < 12 ? 3 : bl < 16 ? 4 : bl < 17 ? 5 : 6));\n  else if constexpr\
    \ (t < 2) a= bl & 1 ? bl < 8 ? k && k != 2 ? 3 : 4 : k > 6 ? 3 : k > 5 ? 4 : !k\
    \ ? 5 : bl < 10 ? k & 1 ? 3 : 4 : bl < 12 ? k > 4 ? 3 : 4 : bl < 16 ? k > 4 ?\
    \ 3 : k < (bl < 14 ? 2 : 3) ? 5 : 4 : k < 3 ? 5 : 4 : bl < 7 ? k & 1 && k > 2\
    \ ? 3 : 4 : bl < 17 ? 4 : k ? 4 : 5;\n  else if constexpr (t < 3) a= bl & 1 ?\
    \ bl < 8 || k > 6 ? 3 : bl < 10 ? k == 5 ? 3 : 4 : bl < 12 ? k < 2 ? 5 : k & 1\
    \ ? 3 : 4 : bl < 14 ? k < 2 ? 5 : k == 5 ? 3 : 4 : k < 3 ? 5 : 4 : bl < 9 ? k\
    \ & 1 && k > 4 ? 3 : 4 : bl < 15 ? 4 : k ? 4 : 5;\n  else if constexpr (t < 4)\
    \ a= bl & 1 ? bl < 10 ? k & 1 || k > 4 ? 3 : 4 : k > 6 ? 3 : bl < 14 ? k < 2 ?\
    \ 5 : k == 5 ? 3 : 4 : bl < 18 ? k < 3 ? 5 : 4 : k < 4 ? 5 : 4 : bl < 9 ? k &\
    \ 1 && k > 2 ? 3 : 4 : bl < 15 ? 4 : k ? 4 : 5;\n  else if constexpr (t < 5) a=\
    \ bl & 1 ? bl < 10 ? k && k != 2 ? 3 : 4 : k > 6 ? 3 : bl < 14 ? k < 2 ? 5 : k\
    \ == 5 ? 3 : 4 : bl < 18 ? k < 3 ? 5 : 4 : k < 4 ? 5 : 4 : bl < 9 ? 2 : bl < 15\
    \ ? 4 : k ? 4 : 5;\n  else a= bl & 1 ? bl < 10 ? !k || k == 2 ? 4 : 3 : k > 6\
    \ ? 3 : bl < 12 ? k ? 4 : 5 : bl < 18 ? k < 3 ? 5 : 4 : k < 4 ? 5 : 4 : bl < 11\
    \ ? k > 6 ? 3 : 4 : bl < 15 || k ? 4 : 5;\n  (a == 2 ? div_<2, mod_t, LM> : a\
    \ == 3 ? div_<3, mod_t, LM> : a == 4 ? div_<4, mod_t, LM> : div_<5, mod_t, LM>)(p.data(),\
    \ n, q.data(), l, r);\n } else {\n  const mod_t iv0= mod_t(1) / q[0];\n  copy(p.begin(),\
    \ p.end(), r), copy(q.begin(), q.end(), qq);\n  for (int i= 0; i < n; r[i++]*=\
    \ iv0)\n   for (int j= min(i + 1, l); --j;) r[i]-= r[i - j] * qq[j];\n }\n return\
    \ vector(r, r + n);\n}\n}\nusing math_internal::div;\n#line 5 \"src/FFT/fps_exp.hpp\"\
    \n/**\n * @title \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 log, exp, pow\n * @category\
    \ FFT\n */\n\n// BEGIN CUT HERE\nnamespace ntt_internal {\ntemplate <class mod_t>\
    \ std::vector<mod_t> deriv(const std::vector<mod_t> &p) {\n std::vector<mod_t>\
    \ ret(p.size() - 1);\n for (int i= p.size(); --i;) ret[i - 1]= p[i] * i;\n return\
    \ ret;\n}\ntemplate <class mod_t, std::size_t _Nm= 1 << 22> std::vector<mod_t>\
    \ integ(const std::vector<mod_t> &p) {\n std::vector<mod_t> ret(p.size() + 1,\
    \ mod_t(0));\n for (int i= p.size(); i; i--) ret[i]= p[i - 1] * get_inv<mod_t,\
    \ _Nm>(i);\n return ret;\n}\ntemplate <class mod_t, std::size_t _Nm= 1 << 22>\
    \ std::vector<mod_t> log(const std::vector<mod_t> &p) {\n assert(p[0] == mod_t(1));\n\
    \ return integ<mod_t, _Nm>(div<mod_t, _Nm>(deriv(p), p));\n}\ntemplate <class\
    \ mod_t, std::size_t _Nm= 1 << 22> std::vector<mod_t> exp(const std::vector<mod_t>\
    \ &p) {\n static constexpr int _Nm2= _Nm * 2 / 15;\n static constexpr int TH=\
    \ 64 << ((!is_nttfriend<mod_t, _Nm>()) << 1);\n using GAdp= GlobalArray<mod_t,\
    \ _Nm, 1>;\n using GAr= GlobalArray<mod_t, _Nm, 2>;\n using GA= GlobalArray<mod_t,\
    \ _Nm2, 0>;\n using GNA1= GlobalNTTArray<mod_t, _Nm2, 1>;\n using GNA2= GlobalNTTArray<mod_t,\
    \ _Nm2, 2>;\n using GNA2D1= GlobalNTTArray2D<mod_t, _Nm2, 16, 1>;\n using GNA2D2=\
    \ GlobalNTTArray2D<mod_t, _Nm2, 16, 2>;\n const int n= p.size(), m= pw2(n);\n\
    \ assert(n > 0), assert(p[0] == mod_t(0));\n std::copy(p.begin(), p.end(), GAdp::bf);\n\
    \ for (int i= n; --i;) GAdp::bf[i]*= i;\n std::fill_n(GAr::bf, n, mod_t(0)), GAr::bf[0]=\
    \ 1;\n for (int r= m, d= 0, R, k, i; r > TH; d+= k) {\n  k= (r/= (R= pw2(__builtin_ctz(r)\
    \ + 1) >> 1)) << 1;\n  for (i= std::min(R - 1, (n - 1) / r); i--;) GNA2D1::bf[i].set(GAdp::bf\
    \ + i * r - d, d, d + k), GNA2D1::bf[i].dft(d, d + k);\n }\n auto rec= [&](auto\
    \ f, int l, int r, int d) -> void {\n  if (int i= l | (!l), ed= std::min(r, n),\
    \ j; r - l > TH) {\n   int R= pw2(__builtin_ctz(r - l) + 1) >> 1, len= (r - l)\
    \ / R, k= len << 1;\n   for (i= 0, ed= std::min(R, (n - l + len - 1) / len);;\
    \ i++) {\n    if (mod_t *ret= GAr::bf + l + i * len, *bf= GA::bf + d + len; i)\
    \ {\n     for (GNA1::bf.zeros(d, d + k), j= i; j--;) GNA2::bf.mul(GNA2D2::bf[j],\
    \ GNA2D1::bf[i - j - 1], d, d + k), GNA1::bf.add(GNA2::bf, d, d + k);\n     GNA1::bf.idft(d,\
    \ d + k), GNA1::bf.get(GA::bf, d + len, d + k);\n     for (int t= len; t--;) ret[t]+=\
    \ bf[t];\n    }\n    if (f(f, l + i * len, l + (i + 1) * len, d + k); i == ed\
    \ - 1) break;\n    GNA2D2::bf[i].set(GAr::bf + l + i * len - d, d, d + len);\n\
    \    GNA2D2::bf[i].zeros(d + len, d + k), GNA2D2::bf[i].dft(d, d + k);\n   }\n\
    \  } else\n   for (; i < ed; GAr::bf[i]*= get_inv<mod_t, _Nm>(i), i++)\n    for\
    \ (j= l; j < i; j++) GAr::bf[i]+= GAr::bf[j] * GAdp::bf[i - j];\n };\n return\
    \ rec(rec, 0, m, 0), std::vector<mod_t>(GAr::bf, GAr::bf + n);\n}\ntemplate <class\
    \ mod_t, std::size_t _Nm= 1 << 22> std::vector<mod_t> pow(const std::vector<mod_t>\
    \ &p, std::uint64_t k) {\n using GA= GlobalArray<mod_t, _Nm, 4>;\n const mod_t\
    \ Z(0), MK(k);\n int n= p.size(), cnt= 0;\n if (GA::bf[0]= 1; k) {\n  while (cnt\
    \ < n && p[cnt] == Z) cnt++;\n  const __int128_t ofs= (__int128_t)k * cnt, sz=\
    \ n - ofs;\n  if (sz <= 0) return std::vector<mod_t>(n, Z);\n  const mod_t p0=\
    \ p[cnt], iv= mod_t(1) / p0, pk= p0.pow(k);\n  for (int i= sz; --i;) GA::bf[i]=\
    \ p[i + cnt] * iv;\n  auto q= log<mod_t, _Nm>(std::vector<mod_t>(GA::bf, GA::bf\
    \ + sz));\n  for (int i= sz; --i;) q[i]*= MK;\n  std::copy_n(exp<mod_t, _Nm>(q).begin(),\
    \ (int)sz, GA::bf + ofs);\n  std::fill_n(GA::bf, (int)ofs, Z);\n  for (int i=\
    \ sz; i--;) GA::bf[i + ofs]*= pk;\n } else std::fill_n(GA::bf + 1, n - 1, Z);\n\
    \ return std::vector<mod_t>(GA::bf, GA::bf + n);\n}\n}  // namespace ntt_internal\n\
    using ntt_internal::deriv, ntt_internal::integ, ntt_internal::log, ntt_internal::exp,\
    \ ntt_internal::pow;\n#line 5 \"test/yosupo/sharp_p_subset_sum.test.cpp\"\nusing\
    \ namespace std;\n\n// log(1+x^s_1)(1+x^s_2)...(1+x^s_N)=log(1+x^s_1)+log(1+x^s_2)+...log(1+x^s_N)\n\
    // log(1+x)=x-x^2/2+x^3/3-x^4/4...\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N, T;\n  cin >> N >> T;\n  int\
    \ c[T + 1];\n  fill_n(c, T + 1, 0);\n  for (int i = 0; i < N; i++) {\n    int\
    \ s;\n    cin >> s, c[s]++;\n  }\n  vector<Mint> a(T + 1);\n  for (int t = 1;\
    \ t <= T; t++)\n    if (c[t])\n      for (int j = 1; j * t <= T; j++) {\n    \
    \    Mint tmp = Mint(c[t]) / j;\n        a[j * t] += j & 1 ? tmp : -tmp;\n   \
    \   }\n  auto ans = exp(a);\n  for (int t = 1; t <= T; t++) cout << ans[t] <<\
    \ \" \\n\"[t == T];\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/FFT/fps_exp.hpp\"\
    \nusing namespace std;\n\n// log(1+x^s_1)(1+x^s_2)...(1+x^s_N)=log(1+x^s_1)+log(1+x^s_2)+...log(1+x^s_N)\n\
    // log(1+x)=x-x^2/2+x^3/3-x^4/4...\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N, T;\n  cin >> N >> T;\n  int\
    \ c[T + 1];\n  fill_n(c, T + 1, 0);\n  for (int i = 0; i < N; i++) {\n    int\
    \ s;\n    cin >> s, c[s]++;\n  }\n  vector<Mint> a(T + 1);\n  for (int t = 1;\
    \ t <= T; t++)\n    if (c[t])\n      for (int j = 1; j * t <= T; j++) {\n    \
    \    Mint tmp = Mint(c[t]) / j;\n        a[j * t] += j & 1 ? tmp : -tmp;\n   \
    \   }\n  auto ans = exp(a);\n  for (int t = 1; t <= T; t++) cout << ans[t] <<\
    \ \" \\n\"[t == T];\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/FFT/fps_exp.hpp
  - src/FFT/fps_div.hpp
  - src/FFT/fps_inv.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/sharp_p_subset_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-13 17:51:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sharp_p_subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp.html
title: test/yosupo/sharp_p_subset_sum.test.cpp
---
