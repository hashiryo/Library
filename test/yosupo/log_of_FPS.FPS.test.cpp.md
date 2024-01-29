---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/FFT/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
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
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/log_of_FPS.FPS.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/log_of_formal_power_series\"\n#include <iostream>\n\
    #include <vector>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n\
    #include <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int\
    \ mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for\
    \ (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b\
    \ * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing i64= long long;\n\
    using u64= unsigned long long;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return l+= r, l < (M) ? l : l\
    \ - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { return l-=\
    \ r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static CE IL U set(U n) { return\
    \ n; } \\\n static CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n)\
    \ { return n; }\ntemplate <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n\
    \ u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)),\
    \ r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l)\
    \ * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n)\
    \ const { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n\
    \  NORM;\n }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n\
    \ static CE u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x *\
    \ (2 - x * n)) : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >>\
    \ B) + mod - ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n\
    \ CE MP_Na(): mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32\
    \ r) const { return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n\
    };\nstruct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0)\
    \ {}\n CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s)\
    \ + m - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r);\
    \ }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE\
    \ IL u64 quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n)\
    \ const { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n\
    \ u64 mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1)\
    \ << 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r);\
    \ }\n PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64\
    \ n) { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64\
    \ n) const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const\
    \ { return (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n -\
    \ quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1():\
    \ s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m),\
    \ d(m << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
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
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 3 \"src/FFT/FormalPowerSeries.hpp\"\
    \n#include <functional>\n#include <memory>\n#include <optional>\n#include <cstdint>\n\
    #include <cstddef>\n#line 2 \"src/FFT/NTT.hpp\"\n#include <array>\n#include <limits>\n\
    #line 3 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate <class\
    \ Uint, class MP, u64... args> constexpr bool miller_rabin(Uint n) {\n const MP\
    \ md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one= md.set(1), n1=\
    \ md.norm(md.set(n - 1));\n for (auto a: {args...})\n  if (Uint b= a % n; b)\n\
    \   if (Uint p= md.norm(pow(md.set(b), d, md)); p != one)\n    for (int i= s;\
    \ p != n1; p= md.norm(md.mul(p, p)))\n     if (!(--i)) return 0;\n return 1;\n\
    }\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n % 6 % 4 != 1) return (n |\
    \ 1) == 3;\n if (n < (1 << 30)) return miller_rabin<u32, MP_Mo<u32, u64, 32, 31>,\
    \ 2, 7, 61>(n);\n if (n < (1ull << 62)) return miller_rabin<u64, MP_Mo<u64, u128,\
    \ 64, 63>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64,\
    \ MP_D2B1, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing\
    \ math_internal::is_prime;\n#line 6 \"src/FFT/NTT.hpp\"\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\nnamespace math_internal {\n#define CE constexpr\n#define\
    \ ST static\n#define TP template\n#define BSF(_, n) __builtin_ctz##_(n)\nTP<class\
    \ mod_t> struct NTT {\n#define _DFT(a, b, c, ...) \\\n mod_t r, u, *x0, *x1; \\\
    \n for (int a= n, b= 1, s, i; a>>= 1; b<<= 1) \\\n  for (s= 0, r= I, x0= x;; r*=\
    \ c[BSF(, s)], x0= x1 + p) { \\\n   for (x1= x0 + (i= p); i--;) __VA_ARGS__; \\\
    \n   if (++s == e) break; \\\n  }\n ST inline void dft(int n, mod_t x[]) { _DFT(p,\
    \ e, r2, x1[i]= x0[i] - (u= r * x1[i]), x0[i]+= u); }\n ST inline void idft(int\
    \ n, mod_t x[]) {\n  _DFT(e, p, ir2, u= x0[i] - x1[i], x0[i]+= x1[i], x1[i]= r\
    \ * u)\n  for (const mod_t iv= I / n; n--;) x[n]*= iv;\n }\n#undef _DFT\n ST inline\
    \ void even_dft(int n, mod_t x[]) {\n  for (int i= 0, j= 0; i < n; i+= 2) x[j++]=\
    \ iv2 * (x[i] + x[i + 1]);\n }\n ST inline void odd_dft(int n, mod_t x[], mod_t\
    \ r= iv2) {\n  for (int i= 0, j= 0;; r*= ir2[BSF(, ++j)])\n   if (x[j]= r * (x[i]\
    \ - x[i + 1]); (i+= 2) == n) break;\n }\n ST inline void dft_doubling(int n, mod_t\
    \ x[], int i= 0) {\n  mod_t k= I, t= rt[BSF(, n << 1)];\n  for (copy_n(x, n, x\
    \ + n), idft(n, x + n); i < n; ++i) x[n + i]*= k, k*= t;\n  dft(n, x + n);\n }\n\
    protected:\n ST CE u64 md= mod_t::mod();\n static_assert(md & 1);\n static_assert(is_prime(md));\n\
    \ ST CE u8 E= BSF(ll, md - 1);\n ST CE mod_t w= [](u8 e) {\n  for (mod_t r= 2;;\
    \ r+= 1)\n   if (auto s= r.pow((md - 1) / 2); s != 1 && s * s == 1) return r.pow((md\
    \ - 1) >> e);\n  return mod_t();\n }(E);\n static_assert(w != mod_t());\n ST CE\
    \ mod_t I= 1, iv2= (md + 1) / 2, iw= w.pow((1ULL << E) - 1);\n ST CE auto roots(mod_t\
    \ w) {\n  array<mod_t, E + 1> x= {};\n  for (u8 e= E; e; w*= w) x[e--]= w;\n \
    \ return x[0]= w, x;\n }\n TP<u32 N> ST CE auto ras(const array<mod_t, E + 1>&\
    \ rt, const array<mod_t, E + 1>& irt, int i= N) {\n  array<mod_t, E + 1 - N> x=\
    \ {};\n  for (mod_t ro= 1; i <= E; ro*= irt[i++]) x[i - N]= rt[i] * ro;\n  return\
    \ x;\n }\n ST CE auto rt= roots(w), irt= roots(iw);\n ST CE auto r2= ras<2>(rt,\
    \ irt), ir2= ras<2>(irt, rt);\n};\nTP<class T, u8 t, class B> struct NI: public\
    \ B {\n using B::B;\n#define FUNC(op, name, HG, ...) \\\n inline void name(__VA_ARGS__)\
    \ { \\\n  HG(op, 1); \\\n  if CE (t > 1) HG(op, 2); \\\n  if CE (t > 2) HG(op,\
    \ 3); \\\n  if CE (t > 3) HG(op, 4); \\\n  if CE (t > 4) HG(op, 5); \\\n }\n#define\
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
    \ M3, u32 M4, u32 M5, u32 LM, bool v> struct NB {\n ARR(1)\n};\nTP<u64 M1, u32\
    \ M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4, M5, LM, 0>\
    \ {\n ARR(1) ARR(2) IV2\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM>\
    \ struct NB<3, M1, M2, M3, M4, M5, LM, 0> {\n ARR(1) ARR(2) ARR(3) IV2 IV3\n};\n\
    TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4, M1, M2, M3, M4,\
    \ M5, LM, 0> {\n ARR(1) ARR(2) ARR(3) ARR(4) IV2 IV3 IV4\n};\nTP<u64 M1, u32 M2,\
    \ u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5, LM, 0> {\n\
    \ ARR(1) ARR(2) ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5\n};\n#undef ARR\n#define\
    \ VC(_) \\\n using m##_= ModInt<M##_>; \\\n using ntt##_= NTT<m##_>; \\\n vector<m##_>\
    \ bf##_; \\\n m##_* dt##_;\n#define RS resize\nTP<u64 M1, u32 M2, u32 M3, u32\
    \ M4, u32 M5, u32 LM> struct NB<1, M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data())\
    \ {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(); }\n u32 size() const { return\
    \ bf1.size(); }\n VC(1)\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM>\
    \ struct NB<2, M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data())\
    \ {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data();\
    \ }\n u32 size() const { return bf1.size(); }\n VC(1) VC(2) IV2\n};\nTP<u64 M1,\
    \ u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<3, M1, M2, M3, M4, M5, LM,\
    \ 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()) {}\n void RS(int\
    \ n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3=\
    \ bf3.data(); }\n u32 size() const { return bf1.size(); }\n VC(1) VC(2) VC(3)\
    \ IV2 IV3\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4,\
    \ M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()),\
    \ dt4(bf4.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n),\
    \ dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(); }\n\
    \ u32 size() const { return bf1.size(); }\n VC(1) VC(2) VC(3) VC(4) IV2 IV3 IV4\n\
    };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3,\
    \ M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()),\
    \ dt4(bf4.data()), dt5(bf5.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(),\
    \ bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(),\
    \ bf5.RS(n), dt5= bf5.data(); }\n u32 size() const { return bf1.size(); }\n VC(1)\
    \ VC(2) VC(3) VC(4) VC(5) IV2 IV3 IV4 IV5\n};\n#undef VC\n#undef IV2\n#undef IV3\n\
    #undef IV4\n#undef IV5\nTP<class T, u32 LM> CE bool is_nttfriend() {\n if CE (!is_staticmodint_v<T>)\
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
    template <class T, size_t LM, int id= 0> struct GlobalNTTArray {\n static inline\
    \ NTTArray<T, LM, 0> bf;\n};\ntemplate <class T, size_t LM, size_t LM2, int id=\
    \ 0> struct GlobalNTTArray2D {\n static inline NTTArray<T, LM, 0> bf[LM2];\n};\n\
    template <class T, size_t LM, int id= 0> struct GlobalArray {\n static inline\
    \ T bf[LM];\n};\nconstexpr unsigned pw2(unsigned n) { return --n, n|= n >> 1,\
    \ n|= n >> 2, n|= n >> 4, n|= n >> 8, n|= n >> 16, ++n; }\n#line 9 \"src/FFT/FormalPowerSeries.hpp\"\
    \ntemplate <class T, size_t LM= 1 << 22> class RelaxedConvolution {\n std::vector<T>\
    \ a, b, c;\n std::vector<NTTArray<T, LM, true>> ac, bc;\n std::function<T()> ha,\
    \ hb;\n int n;\n template <class T0> static auto wrap(T0 &&f, int &n, const std::vector<T>\
    \ &c, std::vector<T> &e) {\n  if constexpr (std::is_invocable_r_v<T, T0, int,\
    \ const std::vector<T> &>) return std::bind([f](int n, const std::vector<T> &c,\
    \ std::vector<T> &e) mutable { return T(e.emplace_back(f(n, c))); }, std::cref(n),\
    \ std::cref(c), std::ref(e));\n  else if constexpr (std::is_invocable_r_v<T, T0,\
    \ int>) return std::bind([f](int n, std::vector<T> &e) mutable { return T(e.emplace_back(f(n)));\
    \ }, std::cref(n), std::ref(e));\n  else if constexpr (std::is_invocable_r_v<T,\
    \ T0>) return std::bind([f](std::vector<T> &e) mutable { return T(e.emplace_back(f()));\
    \ }, std::ref(e));\n  else throw;\n }\npublic:\n template <class F1, class F2>\
    \ RelaxedConvolution(F1 &&h1, F2 &&h2): c(4), ha(wrap(h1, n, c, a)), hb(wrap(h2,\
    \ n, c, b)), n(0) { a.reserve(LM), b.reserve(LM), c.reserve(LM); }\n const std::vector<T>\
    \ &multiplicand() const { return a; }\n const std::vector<T> &multiplier() const\
    \ { return b; }\n T at(int k) { return (*this)[k]; }\n T operator[](int k) {\n\
    \  while (n <= k) next();\n  return c[k];\n }\n T next() {\n  using GNA1= GlobalNTTArray<T,\
    \ LM, 1>;\n  using GNA2= GlobalNTTArray<T, LM, 2>;\n  static constexpr int BASE_CASE_SIZE=\
    \ 32;\n  if (int l= pw2(n << 1 | 1); (int)c.size() < l) c.resize(l);\n  if (n\
    \ == 0) c[0]= ha() * hb();\n  if (n == 1) c[1]= ha() * b[0] + a[0] * hb(), c[2]=\
    \ a[1] * b[1];\n  if (n == 2) c[2]+= ha() * b[0] + a[0] * hb(), c[3]= a[2] * b[1]\
    \ + a[1] * b[2];\n  if (n > 2) {\n   if (!(n & (n - 1))) {\n    int t0= n >> 1,\
    \ t1= n;\n    auto &c0= ac.emplace_back(), &c1= bc.emplace_back();\n    c0.resize(t1),\
    \ c0.set(a.data() + t0, 0, t0), c0.dft(0, t1), c1.resize(t1), c1.set(b.data()\
    \ + t0, 0, t0), c1.dft(0, t1), GNA1::bf.mul(c0, c1, 0, t1), GNA1::bf.idft(0, t1);\n\
    \    for (int i= t1 - 1; i--;) c[t1 + i]+= GNA1::bf.get(i);\n   }\n   c[n]+= ha()\
    \ * b[0] + a[0] * hb(), c[n + 1]+= a[1] * b[n] + a[n] * b[1];\n   for (int t0=\
    \ 2, sft= 0, ofs= pw2(n + 1) >> 1, t= n + 1 - ofs; !(t & 1) && t0 < ofs; t0<<=\
    \ 1, sft++, t>>= 1)\n    if (int m= n + 1 - t0, t1= t0 << 1; t0 > BASE_CASE_SIZE)\
    \ {\n     GNA1::bf.set(a.data() + m, 0, t0), GNA1::bf.zeros(t0, t1), GNA2::bf.set(b.data()\
    \ + m, 0, t0), GNA2::bf.zeros(t0, t1), GNA1::bf.dft(0, t1), GNA2::bf.dft(0, t1),\
    \ GNA1::bf.mul(bc[sft], 0, t1), GNA2::bf.mul(ac[sft], 0, t1), GNA1::bf.add(GNA2::bf,\
    \ 0, t1), GNA1::bf.idft(0, t1);\n     for (int i= t1 - 1; i--;) c[n + 1 + i]+=\
    \ GNA1::bf.get(i);\n    } else\n     for (int i= t0; i--;)\n      for (int j=\
    \ t0; j--;) c[n + 1 + i + j]+= a[m + i] * b[j + t0] + a[j + t0] * b[m + i];\n\
    \  }\n  return c[n++];\n }\n};\ntemplate <class mod_t, size_t LM= 1 << 22> class\
    \ FormalPowerSeries {\n using F= std::function<mod_t(int)>;\n using FPS= FormalPowerSeries;\n\
    \ F h_;\npublic:\n class Resetter {\n  std::shared_ptr<F> p_;\n public:\n  Resetter()\
    \ {}\n  Resetter(std::shared_ptr<F> p): p_(p) {}\n  void set(const FPS &rhs) {\
    \ *p_= rhs.handle(); }\n };\n class Inde {  // indeterminate\n  int p_;\n public:\n\
    \  Inde(int p): p_(p) {}\n  Inde(): Inde(1) {}\n  Inde operator^(int p) const\
    \ { return Inde(p_ * p); }\n  Inde operator*(const Inde &rhs) const { return Inde(p_\
    \ + rhs.p_); }\n  int pow() const { return p_; }\n };\n FormalPowerSeries(): h_([](int)\
    \ { return mod_t(0); }) {}\n FormalPowerSeries(F f)\n     : h_([f, cache= std::make_shared<std::vector<mod_t>>()](int\
    \ k) -> mod_t {\n        for (int i= (int)cache->size(); i <= k; ++i) cache->emplace_back(f(i));\n\
    \        return cache->at(k);\n       }) {}\n FormalPowerSeries(const std::vector<mod_t>\
    \ &coef): h_([cache= std::make_shared<std::vector<mod_t>>(coef)](int k) -> mod_t\
    \ { return k < (int)cache->size() ? cache->at(k) : mod_t(0); }) {}\n FormalPowerSeries(mod_t\
    \ v): h_([v](int k) { return k == 0 ? v : mod_t(0); }) {}\n F handle() const {\
    \ return h_; }\n static Inde x() { return Inde(); }\n Resetter reset() {\n  auto\
    \ p= std::make_shared<F>();\n  return h_= [p](int i) { return (*p)(i); }, Resetter(p);\n\
    \ }\n mod_t operator[](int k) const { return h_(k); }\n FPS operator()(const Inde\
    \ &rhs) const { return scale(rhs.pow()); }\n FPS operator*(const Inde &rhs) const\
    \ { return shift(rhs.pow()); }\n FPS operator*(const mod_t &rhs) const {\n  return\
    \ FPS([h= h_, v= rhs](int i) { return h(i) * v; });\n }\n FPS operator/(const\
    \ mod_t &rhs) const {  // `rhs == 0` is not allowed\n  return FPS([h= h_, v= mod_t(1)\
    \ / rhs](int i) { return h(i) * v; });\n }\n FPS operator+(const mod_t &rhs) const\
    \ {\n  return FPS([h= h_, v= rhs](int i) { return i ? h(i) : h(i) + v; });\n }\n\
    \ FPS operator-(const mod_t &rhs) const {\n  return FPS([h= h_, v= rhs](int i)\
    \ { return i ? h(i) : h(i) - v; });\n }\n friend FPS operator*(const Inde &lhs,\
    \ const FPS &rhs) { return rhs.shift(lhs.pow()); }\n friend FPS operator-(const\
    \ mod_t &lhs, const FPS &rhs) {\n  return FPS([h= rhs.h_, v= lhs](int i) { return\
    \ i ? -h(i) : v - h(i); });\n }\n friend FPS operator+(const mod_t &lhs, const\
    \ FPS &rhs) {\n  return FPS([h= rhs.h_, v= lhs](int i) { return i ? h(i) : h(i)\
    \ + v; });\n }\n friend FPS operator*(const mod_t &lhs, const FPS &rhs) {\n  return\
    \ FPS([h= rhs.h_, v= lhs](int i) { return h(i) * v; });\n }\n friend FPS operator/(const\
    \ mod_t &lhs, const FPS &rhs) { return lhs * rhs.inv(); }\n FPS scale(int k) const\
    \ {\n  return FPS([h= h_, k](int i) { return i % k ? mod_t(0) : h(i / k); });\n\
    \ }\n FPS shift(int k) const {\n  return FPS([h= h_, k](int i) { return i < k\
    \ ? mod_t(0) : h(i - k); });\n }\n FPS inv() const {\n  auto rc= std::make_shared<RelaxedConvolution<mod_t,\
    \ LM>>([h= h_](int i) { return h(i); }, [h= h_, iv= mod_t()](int i, const auto\
    \ &c) mutable { return i ? -(c[i] + h(i) * iv) * iv : (iv= mod_t(1) / h(0)); });\n\
    \  return FPS([rc](int i) { return rc->next(), rc->multiplier()[i]; });  // safe\n\
    \ }\n friend FPS deriv(const FPS &fps) {\n  return FPS([h= fps.h_](int i) { return\
    \ h(i + 1) * mod_t(i + 1); });\n }\n friend FPS integ(const FPS &fps) {\n  return\
    \ FPS([h= fps.h_](int i) { return i ? h(i - 1) * get_inv<mod_t, LM>(i) : mod_t(0);\
    \ });\n }\n // `fps[0]==1` is required\n friend FPS log(const FPS &fps) { return\
    \ integ(deriv(fps) / fps); }\n friend FPS exp(const FPS &fps) {  // `fps[0]==0`\
    \ is required\n  auto rc= std::make_shared<RelaxedConvolution<mod_t, LM>>([h=\
    \ fps.h_](int i) { return h(i + 1) * mod_t(i + 1); }, [](int i, const auto &c)\
    \ { return i ? c[i - 1] * get_inv<mod_t, LM>(i) : mod_t(1); });\n  return FPS([rc](int\
    \ i) { return i ? rc->at(i - 1) * get_inv<mod_t, LM>(i) : mod_t(1); });\n }\n\
    \ friend FPS pow(const FPS &fps, uint64_t k) {\n  if (!k) return FPS(1);\n  return\
    \ FPS([h= fps.h_, kk= mod_t(k), k, cnt= 0ull, s= std::optional<std::function<mod_t(int)>>()](int\
    \ i) mutable {\n   if (s) return (uint64_t)i < cnt ? mod_t(0) : (*s)(i - (int)cnt);\n\
    \   mod_t v= h(i);\n   if (v == mod_t(0)) return cnt++, mod_t(0);\n   cnt*= k;\n\
    \   FPS t0([os= i, iv= mod_t(1) / v, h](int i) { return h(i + os) * iv; });\n\
    \   FPS t1([h0= log(t0).handle(), kk](int i) { return h0(i) * kk; });\n   s.emplace([vk=\
    \ v.pow(k), h1= exp(t1).handle()](int i) { return h1(i) * vk; });\n   return cnt\
    \ ? mod_t(0) : (*s)(i);\n  });\n }\n friend FPS SEQ(const FPS &fps) {  // SEQUENCE\
    \ `fps[0]==0` is required\n  return FPS([h= fps.h_](int i) { return i == 0 ? mod_t(1)\
    \ : -h(i); }).inv();\n }\n friend FPS MSET(const FPS &fps) {  // MULTISET `fps[0]==0`\
    \ is required\n  return exp(FPS([h= fps.h_, cache= std::make_shared<std::vector<mod_t>>()](int\
    \ i) {\n   if (i == 0) return mod_t(0);\n   if ((i & (i - 1)) == 0) {\n    cache->resize(i\
    \ * 2, mod_t(0));\n    for (int j= 1; j < i; ++j) {\n     mod_t hj= h(j);\n  \
    \   for (int k= (i + j - 1) / j, ed= (i * 2 + j - 1) / j; k < ed; k++) cache->at(j\
    \ * k)+= hj * get_inv<mod_t, LM>(k);\n    }\n   }\n   return mod_t(cache->at(i)+=\
    \ h(i));\n  }));\n }\n friend FPS PSET(const FPS &fps) {  //  POWERSET `fps[0]==0`\
    \ is required\n  return exp(FPS([h= fps.h_, cache= std::make_shared<std::vector<mod_t>>()](int\
    \ i) {\n   if (i == 0) return mod_t(0);\n   if ((i & (i - 1)) == 0) {\n    cache->resize(i\
    \ * 2, mod_t(0));\n    for (int j= 1; j < i; ++j) {\n     mod_t hj= h(j);\n  \
    \   for (int k= (i + j - 1) / j, ed= (i * 2 + j - 1) / j; k < ed; k++)\n     \
    \ if (k & 1) cache->at(j * k)+= hj * get_inv<mod_t, LM>(k);\n      else cache->at(j\
    \ * k)-= hj * get_inv<mod_t, LM>(k);\n    }\n   }\n   return mod_t(cache->at(i)+=\
    \ h(i));\n  }));\n };\n FPS operator+(const FPS &rhs) const {\n  return FPS([h0=\
    \ h_, h1= rhs.h_](int i) { return h0(i) + h1(i); });\n }\n FPS operator-(const\
    \ FPS &rhs) const {\n  return FPS([h0= h_, h1= rhs.h_](int i) { return h0(i) -\
    \ h1(i); });\n }\n FPS operator-() const {\n  return FPS([h= h_](int i) { return\
    \ -h(i); });\n }\n FPS operator*(const FPS &rhs) const {\n  auto rc= std::make_shared<RelaxedConvolution<mod_t,\
    \ LM>>([h= h_](int i) { return h(i); }, [h= rhs.h_](int i) { return h(i); });\n\
    \  return FPS([rc](int) { return rc->next(); });\n }\n FPS operator/(const FPS\
    \ &rhs) const {\n  auto rc= std::make_shared<RelaxedConvolution<mod_t, LM>>([h=\
    \ rhs.h_](int i) { return h(i); },\n                                         \
    \                  [h0= h_, h1= rhs.h_, iv= mod_t(), t0= mod_t()](int i, const\
    \ auto &c) mutable {\n                                                       \
    \     if (i == 0) return t0= h0(0) * (iv= mod_t(1) / h1(0));\n               \
    \                                             return (h0(i) - h1(i) * t0 - c[i])\
    \ * iv;\n                                                           });\n  return\
    \ FPS([rc](int i) { return rc->next(), rc->multiplier()[i]; });\n }\n};\n#line\
    \ 6 \"test/yosupo/log_of_FPS.FPS.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n using Mint= ModInt<998244353>;\n using FPS= FormalPowerSeries<Mint>;\n int\
    \ N;\n cin >> N;\n std::vector<Mint> A(N);\n for (int i= 0; i < N; i++) cin >>\
    \ A[i];\n auto ans= log(FPS(A));\n for (int i= 0; i < N; i++) cout << ans[i] <<\
    \ \" \\n\"[i == N - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/Math/ModInt.hpp\"\n#include\
    \ \"src/FFT/FormalPowerSeries.hpp\"\nusing namespace std;\nsigned main() {\n using\
    \ Mint= ModInt<998244353>;\n using FPS= FormalPowerSeries<Mint>;\n int N;\n cin\
    \ >> N;\n std::vector<Mint> A(N);\n for (int i= 0; i < N; i++) cin >> A[i];\n\
    \ auto ans= log(FPS(A));\n for (int i= 0; i < N; i++) cout << ans[i] << \" \\\
    n\"[i == N - 1];\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/FFT/FormalPowerSeries.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/log_of_FPS.FPS.test.cpp
  requiredBy: []
  timestamp: '2024-01-29 15:51:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/log_of_FPS.FPS.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/log_of_FPS.FPS.test.cpp
- /verify/test/yosupo/log_of_FPS.FPS.test.cpp.html
title: test/yosupo/log_of_FPS.FPS.test.cpp
---
