---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':question:'
    path: src/FFT/BigInt.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':question:'
    path: src/Graph/FunctionalGraph.hpp
    title: "Functional\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/Tree.hpp
    title: "\u6728"
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc136/tasks/abc136_d
    links:
    - https://atcoder.jp/contests/abc136/tasks/abc136_d
  bundledCode: "#line 1 \"test/atcoder/abc136_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc136/tasks/abc136_d\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"src/FFT/BigInt.hpp\"\n#include\
    \ <sstream>\n#include <iomanip>\n#line 5 \"src/FFT/BigInt.hpp\"\n#include <string>\n\
    #include <cmath>\n#include <algorithm>\n#line 2 \"src/FFT/NTT.hpp\"\n#include\
    \ <array>\n#include <limits>\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= unsigned char;\nusing u32=\
    \ unsigned;\nusing i64= long long;\nusing u64= unsigned long long;\nusing u128=\
    \ __uint128_t;\n#define CE constexpr\n#define IL inline\n#define NORM \\\n if\
    \ (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l,\
    \ U r) const { return l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\
    \n CE IL U diff(U l, U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define\
    \ SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U\
    \ n) { return n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class\
    \ u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0),\
    \ iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod)\
    \ {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t,\
    \ mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n,\
    \ r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL\
    \ u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t\
    \ n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n\
    \ CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w)\
    \ * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n\
    \ CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n\
    \ CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod)\
    \ DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const\
    \ { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n)\
    \ * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2():\
    \ mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL\
    \ u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod <<\
    \ 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE\
    \ IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\n\
    private:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return (n * x) >> 84;\
    \ }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod; }\n};\nstruct\
    \ MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0)\
    \ {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    };\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n\
    \ for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x)\
    \ : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Math/is_prime.hpp\"\nnamespace math_internal\
    \ {\ntemplate <class Uint, class MP, u64... args> constexpr bool miller_rabin(Uint\
    \ n) {\n const MP md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one=\
    \ md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...})\n  if (Uint\
    \ b= a % n; b)\n   if (Uint p= md.norm(pow(md.set(b), d, md)); p != one)\n   \
    \ for (int i= s; p != n1; p= md.norm(md.mul(p, p)))\n     if (!(--i)) return 0;\n\
    \ return 1;\n}\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n % 6 % 4 != 1)\
    \ return (n | 1) == 3;\n if (n < (1 << 30)) return miller_rabin<u32, MP_Mo<u32,\
    \ u64, 32, 31>, 2, 7, 61>(n);\n if (n < (1ull << 62)) return miller_rabin<u64,\
    \ MP_Mo<u64, u128, 64, 63>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    \ return miller_rabin<u64, MP_D2B1, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    }\n}\nusing math_internal::is_prime;\n#line 2 \"src/Math/mod_inv.hpp\"\n#include\
    \ <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b),\
    \ z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod\
    \ : x % mod;\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
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
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
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
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 6 \"src/FFT/NTT.hpp\"\nnamespace math_internal {\n\
    #define CE constexpr\n#define ST static\n#define TP template\n#define BSF(_, n)\
    \ __builtin_ctz##_(n)\nTP<class mod_t> struct NTT {\n#define _DFT(a, b, c, ...)\
    \ \\\n mod_t r, u, *x0, *x1; \\\n for (int a= n, b= 1, s, i; a>>= 1; b<<= 1) \\\
    \n  for (s= 0, r= I, x0= x;; r*= c[BSF(, s)], x0= x1 + p) { \\\n   for (x1= x0\
    \ + (i= p); i--;) __VA_ARGS__; \\\n   if (++s == e) break; \\\n  }\n ST inline\
    \ void dft(int n, mod_t x[]) { _DFT(p, e, r2, x1[i]= x0[i] - (u= r * x1[i]), x0[i]+=\
    \ u); }\n ST inline void idft(int n, mod_t x[]) {\n  _DFT(e, p, ir2, u= x0[i]\
    \ - x1[i], x0[i]+= x1[i], x1[i]= r * u)\n  for (const mod_t iv= I / n; n--;) x[n]*=\
    \ iv;\n }\n#undef _DFT\n ST inline void even_dft(int n, mod_t x[]) {\n  for (int\
    \ i= 0, j= 0; i < n; i+= 2) x[j++]= iv2 * (x[i] + x[i + 1]);\n }\n ST inline void\
    \ odd_dft(int n, mod_t x[], mod_t r= iv2) {\n  for (int i= 0, j= 0;; r*= ir2[BSF(,\
    \ ++j)])\n   if (x[j]= r * (x[i] - x[i + 1]); (i+= 2) == n) break;\n }\n ST inline\
    \ void dft_doubling(int n, mod_t x[], int i= 0) {\n  mod_t k= I, t= rt[BSF(, n\
    \ << 1)];\n  for (copy_n(x, n, x + n), idft(n, x + n); i < n; ++i) x[n + i]*=\
    \ k, k*= t;\n  dft(n, x + n);\n }\nprotected:\n ST CE u64 md= mod_t::mod();\n\
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
    \ n >> 2, n|= n >> 4, n|= n >> 8, n|= n >> 16, ++n; }\n#line 9 \"src/FFT/BigInt.hpp\"\
    \nnamespace math_internal {\nclass BigInt {\n static constexpr u64 BASE= 1e15;\n\
    \ static constexpr int8_t D= 15;\n using Vec= vector<u64>;\n bool neg;\n Vec dat;\n\
    \ BigInt(bool n, const Vec &d): neg(n), dat(d) {}\npublic:\n BigInt(): neg(false),\
    \ dat() {}\n BigInt(__int128_t v): neg(v < 0) {\n  for (v= v < 0 ? -v : v; v;\
    \ v/= BASE) dat.push_back(v % BASE);\n }\n BigInt(const string &s): neg(false)\
    \ {\n  int p= 0, i= s.size(), j;\n  for (; p < i && (s[p] == '-' || s[p] == '+');\
    \ ++p)\n   if (s[p] == '-') neg= !neg;\n  for (u64 x= 0; i > p; i-= D, dat.push_back(x),\
    \ x= 0)\n   for (j= max(p, i - D); j < i;) x= x * 10 + s[j++] - '0';\n  shrink();\n\
    \ }\n inline void shrink() {\n  while (!dat.empty() && !dat.back()) dat.pop_back();\n\
    \  if (dat.empty()) neg= false;\n }\n string to_str() const {\n  if (is_zero())\
    \ return \"0\";\n  stringstream ss;\n  if (neg) ss << '-';\n  ss << (dat.empty()\
    \ ? 0 : dat.back());\n  for (int i= dat.size() - 1; i-- > 0;) ss << setw(D) <<\
    \ setfill('0') << dat[i];\n  string ret;\n  return ss >> ret, ret;\n }\n bool\
    \ is_zero() const { return dat.empty() || (dat.size() == 1 && !dat[0]); }\n bool\
    \ operator<(const BigInt &r) const {\n  if (neg != r.neg) return neg;\n  if (dat.size()\
    \ != r.dat.size()) return (dat.size() < r.dat.size()) ^ neg;\n  for (int i= dat.size();\
    \ i--;)\n   if (dat[i] != r.dat[i]) return (dat[i] < r.dat[i]) ^ neg;\n  return\
    \ false;\n }\n bool operator>(const BigInt &r) const { return r < *this; }\n bool\
    \ operator<=(const BigInt &r) const { return !(r < *this); }\n bool operator>=(const\
    \ BigInt &r) const { return !(*this < r); }\n bool operator==(const BigInt &r)\
    \ const { return (neg == r.neg && dat == r.dat) || (is_zero() && r.is_zero());\
    \ }\n bool operator!=(const BigInt &r) const { return !(*this == r); }\n BigInt\
    \ abs() const { return BigInt(false, dat); }\n BigInt operator-() const { return\
    \ BigInt(!neg, dat); }\n BigInt operator+(const BigInt &r) const {\n  if (neg\
    \ != r.neg) return *this - (-r);\n  auto [ret, tmp]= dat.size() > r.dat.size()\
    \ ? make_pair(*this, &r) : make_pair(r, this);\n  int car= 0, i, n= ret.dat.size(),\
    \ m= tmp->dat.size();\n  for (i= 0; i < m; i++) ret.dat[i]-= BASE & -(car= ((ret.dat[i]+=\
    \ car + tmp->dat[i]) >= BASE));\n  if (car) {\n   while (i < n && ret.dat[i] ==\
    \ BASE - 1) ret.dat[i++]= 0;\n   i < n ? ++ret.dat[i] : (ret.dat.push_back(1),\
    \ 0);\n  }\n  return ret;\n }\n BigInt operator-(const BigInt &r) const {\n  if\
    \ (neg != r.neg) return *this + (-r);\n  if (r.is_zero()) return *this;\n  if\
    \ (is_zero()) return -r;\n  auto [ret, tmp]= abs() > r.abs() ? make_pair(*this,\
    \ &r) : make_pair(r, this);\n  int car= 0, i, n= ret.dat.size(), m= tmp->dat.size();\n\
    \  for (i= 0; i < m; i++) ret.dat[i]+= BASE & -(car= ((ret.dat[i]-= car + tmp->dat[i])\
    \ >> 63));\n  while (car && i < n && !ret.dat[i]) ret.dat[i++]= BASE - 1;\n  return\
    \ ret.neg^= (tmp == this), ret.dat[i]-= car, ret.shrink(), ret;\n }\n long long\
    \ operator%(long long r) const {\n  long long ret= 0;\n  for (int i= dat.size();\
    \ i--;) ret= ((u128)ret * BASE + dat[i]) % r;\n  return ret;\n }\n BigInt operator*(const\
    \ BigInt &r) const {\n  using mint1= ModInt<MOD1>;\n  using mint2= ModInt<MOD2>;\n\
    \  using mint3= ModInt<MOD3>;\n  using mint4= ModInt<MOD4>;\n  using ntt1= NTT<mint1>;\n\
    \  using ntt2= NTT<mint2>;\n  using ntt3= NTT<mint3>;\n  using ntt4= NTT<mint4>;\n\
    \  static constexpr mint2 iv21= mint2(1) / MOD1;\n  static constexpr mint3 iv32=\
    \ mint3(1) / MOD2, iv31= iv32 / MOD1;\n  static constexpr mint4 iv43= mint4(1)\
    \ / MOD3, iv42= iv43 / MOD2, iv41= iv42 / MOD1;\n  if (is_zero() || r.is_zero())\
    \ return 0;\n  const int n= dat.size(), m= r.dat.size(), sz= n + m - 1;\n  static\
    \ mint1 f1[1 << 20], g1[1 << 20];\n  static mint2 f2[1 << 20], g2[1 << 20];\n\
    \  static mint3 f3[1 << 20], g3[1 << 20];\n  static mint4 f4[1 << 20], g4[1 <<\
    \ 20];\n  static u128 h[1 << 20];\n  if (int i= n, j; min(n, m) >= 135) {\n  \
    \ const int l= pw2(max(n, m)), fl= std::pow(l, 0.535) * 8.288, len= sz <= l +\
    \ fl ? l : pw2(sz);\n   for (i= n; i--;) f1[i]= dat[i];\n   for (i= n; i--;) f2[i]=\
    \ dat[i];\n   for (i= n; i--;) f3[i]= dat[i];\n   for (i= n; i--;) f4[i]= dat[i];\n\
    \   fill_n(f1 + n, len - n, mint1()), ntt1::dft(len, f1), fill_n(f2 + n, len -\
    \ n, mint2()), ntt2::dft(len, f2), fill_n(f3 + n, len - n, mint3()), ntt3::dft(len,\
    \ f3), fill_n(f4 + n, len - n, mint4()), ntt4::dft(len, f4);\n   if (this != &r)\
    \ {\n#define TMP(k) \\\n for (i= m; i--;) g##k[i]= r.dat[i]; \\\n fill_n(g##k\
    \ + m, len - m, mint##k()), ntt##k::dft(len, g##k); \\\n for (i= len; i--;) f##k[i]*=\
    \ g##k[i];\n    TMP(1) TMP(2) TMP(3) TMP(4)\n#undef TMP\n   } else {\n    for\
    \ (i= len; i--;) f1[i]*= f1[i];\n    for (i= len; i--;) f2[i]*= f2[i];\n    for\
    \ (i= len; i--;) f3[i]*= f3[i];\n    for (i= len; i--;) f4[i]*= f4[i];\n   }\n\
    \   for (ntt1::idft(len, f1), ntt2::idft(len, f2), ntt3::idft(len, f3), ntt4::idft(len,\
    \ f4), i= len; i < sz; f1[i - len]-= h[i], f2[i - len]-= h[i], f3[i - len]-= h[i],\
    \ f4[i - len]-= h[i], ++i)\n    for (h[i]= 0, j= i - m + 1; j < n; j++) h[i]+=\
    \ (u128)dat[j] * r.dat[i - j];\n   for (i= min(sz, len); i--;) {\n    u32 r1=\
    \ f1[i].val(), r2= (iv21 * (f2[i] - r1)).val(), r3= (iv31 * (f3[i] - r1) - iv32\
    \ * r2).val();\n    h[i]= ((u128)((u64)(iv41 * (f4[i] - r1) - iv42 * r2 - iv43\
    \ * r3).val() * MOD3 + r3) * MOD2 + r2) * MOD1 + r1;\n   }\n  } else\n   for (fill_n(h,\
    \ sz, 0); i--;)\n    for (j= m; j--;) h[i + j]+= (u128)dat[i] * r.dat[j];\n  BigInt\
    \ ret(neg ^ r.neg, Vec(sz));\n  u128 car= 0;\n  for (int i= 0; i < sz; ++i, car/=\
    \ BASE) ret.dat[i]= (car+= h[i]) % BASE;\n  for (; car; car/= BASE) ret.dat.push_back(car\
    \ % BASE);\n  return ret;\n }\n BigInt operator/(const BigInt &r) const {\n  if\
    \ (assert(!r.is_zero()); r.dat.size() == 1) {\n   BigInt qu(neg ^ r.neg, Vec(dat.size()));\n\
    \   u128 d= 0, q;\n   u64 r0= r.dat[0];\n   for (int i= dat.size(); i--;) (d*=\
    \ BASE)+= dat[i], q= d / r0, d= d % r0, qu.dat[i]= q;\n   return qu.shrink(),\
    \ qu;\n  }\n  BigInt a= this->abs(), b= r.abs();\n  if (a < b) return 0;\n  const\
    \ u64 norm= BASE / (b.dat.back() + 1);\n  const u32 s= (a*= norm).dat.size(),\
    \ t= (b*= norm).dat.size(), deg= s - t + 2;\n  const u64 yb= b.dat.back();\n \
    \ u32 k= deg;\n  while (k > 64) k= (k + 1) / 2;\n  BigInt z(0, Vec(k + 2)), rem(0,\
    \ Vec(t));\n  rem.dat.back()= 1;\n  for (int i= z.dat.size(); i--;) {\n   if (rem.dat.size()\
    \ == t) {\n    if (b <= rem) z.dat[i]= 1, rem-= b;\n   } else if (rem.dat.size()\
    \ > t) {\n    u64 q= ((u128)rem.dat[rem.dat.size() - 1] * BASE + rem.dat[rem.dat.size()\
    \ - 2]) / yb;\n    BigInt yq= b * q;\n    while (rem < yq) --q, yq-= b;\n    rem-=\
    \ yq, z.dat[i]= q;\n   }\n   if (i) rem.dat.insert(rem.dat.begin(), 0);\n  }\n\
    \  for (z.shrink(); k < deg; k<<= 1) {\n   int d= min(t, 2 * k + 1);\n   BigInt\
    \ x= z * z, w2= z + z;\n   Vec w_(k + 1);\n   x.dat.insert(x.dat.begin(), 0),\
    \ x*= BigInt(0, Vec(b.dat.end() - d, b.dat.end())), x.dat.erase(x.dat.begin(),\
    \ x.dat.begin() + d), copy(w2.dat.begin(), w2.dat.end(), back_inserter(w_)), z=\
    \ BigInt(0, w_) - x, z.dat.erase(z.dat.begin());\n  }\n  z.dat.erase(z.dat.begin(),\
    \ z.dat.begin() + k - deg);\n  BigInt q= a * z;\n  for (q.dat.erase(q.dat.begin(),\
    \ q.dat.begin() + t + deg), z= b * q; a < z;) q-= 1, z-= b;\n  for (rem= a - z;\
    \ b <= rem;) q+= 1, rem-= b;\n  return q.shrink(), q.neg= neg ^ r.neg, q;\n }\n\
    \ BigInt operator%(const BigInt &r) const { return *this - (*this / r) * r; }\n\
    \ BigInt &operator+=(const BigInt &r) { return *this= *this + r; }\n BigInt &operator-=(const\
    \ BigInt &r) { return *this= *this - r; }\n BigInt &operator*=(const BigInt &r)\
    \ { return *this= *this * r; }\n BigInt &operator/=(const BigInt &r) { return\
    \ *this= *this / r; }\n BigInt &operator%=(const BigInt &r) { return *this= *this\
    \ % r; }\n friend istream &operator>>(istream &is, BigInt &v) {\n  string s;\n\
    \  return is >> s, v= BigInt(s), is;\n }\n friend ostream &operator<<(ostream\
    \ &os, const BigInt &v) { return os << v.to_str(), os; }\n explicit operator int()\
    \ { return is_zero() ? 0 : neg ? -dat[0] : dat[0]; }\n};\n}\nusing math_internal::BigInt;\n\
    #line 3 \"src/Graph/Tree.hpp\"\n#include <cstddef>\n#line 6 \"src/Graph/Tree.hpp\"\
    \n#include <tuple>\n#include <numeric>\n#line 3 \"src/DataStructure/CsrArray.hpp\"\
    \n#include <iterator>\ntemplate <class T> struct ListRange {\n using Iterator=\
    \ typename std::vector<T>::const_iterator;\n Iterator bg, ed;\n Iterator begin()\
    \ const { return bg; }\n Iterator end() const { return ed; }\n size_t size() const\
    \ { return std::distance(bg, ed); }\n const T &operator[](int i) const { return\
    \ bg[i]; }\n};\ntemplate <class T> class CsrArray {\n std::vector<T> csr;\n std::vector<int>\
    \ pos;\npublic:\n CsrArray()= default;\n CsrArray(const std::vector<T> &c, const\
    \ std::vector<int> &p): csr(c), pos(p) {}\n size_t size() const { return pos.size()\
    \ - 1; }\n const ListRange<T> operator[](int i) const { return {csr.cbegin() +\
    \ pos[i], csr.cbegin() + pos[i + 1]}; }\n};\n#line 10 \"src/Graph/Tree.hpp\"\n\
    template <class Cost= void, bool weight= false> class Tree {\n template <class\
    \ D, class T> struct Edge_B {\n  int to;\n  T cost;\n  operator int() const {\
    \ return to; }\n };\n template <class D> struct Edge_B<D, void> {\n  int to;\n\
    \  operator int() const { return to; }\n };\n using Edge= Edge_B<void, Cost>;\n\
    \ using C= std::conditional_t<std::is_void_v<Cost>, std::nullptr_t, Cost>;\n std::vector<std::conditional_t<std::is_void_v<Cost>,\
    \ std::pair<int, int>, std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n\
    \ std::vector<int> P, PP, D, I, L, R, pos;\n std::vector<C> DW, W;\npublic:\n\
    \ Tree(int n): P(n, -2) {}\n template <class T= Cost> std::enable_if_t<std::is_void_v<T>,\
    \ void> add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u);\
    \ }\n template <class T> std::enable_if_t<std::is_convertible_v<T, Cost>, void>\
    \ add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v, u,\
    \ c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, d); }\n void build(int root= 0) {\n  size_t n= P.size();\n  I.resize(n),\
    \ PP.resize(n), std::iota(PP.begin(), PP.end(), 0), D.assign(n, 0), L.assign(n,\
    \ 0), R.assign(n, 0), pos.resize(n + 1), g.resize(es.size());\n  for (const auto\
    \ &e: es) ++pos[std::get<0>(e)];\n  std::partial_sum(pos.begin(), pos.end(), pos.begin());\n\
    \  if constexpr (std::is_void_v<Cost>)\n   for (const auto &[f, t]: es) g[--pos[f]]=\
    \ {t};\n  else\n   for (const auto &[f, t, c]: es) g[--pos[f]]= {t, c};\n  auto\
    \ f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]= r; i <\
    \ t; ++i)\n    for (int u: operator[](v= I[i]))\n     if (P[v] != u) P[I[t++]=\
    \ u]= v;\n  };\n  f(root);\n  for (size_t r= 0; r < n; ++r)\n   if (P[r] == -2)\
    \ f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n\
    \   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]=\
    \ v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n   if (nx[v]\
    \ != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: operator[](v))\n    if (u != P[v]\
    \ && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n \
    \ }\n  if constexpr (weight) {\n   DW.resize(n), W.resize(n);\n   for (int v:\
    \ I)\n    for (auto &[u, c]: operator[](v)) {\n     if (u != P[v]) DW[u]= DW[v]\
    \ + c;\n     else W[v]= c;\n    }\n  }\n  for (int i= n; i--;) I[L[i]]= i;\n }\n\
    \ size_t size() const { return P.size(); }\n const ListRange<Edge> operator[](int\
    \ v) const { return {g.cbegin() + pos[v], g.cbegin() + pos[v + 1]}; }\n int depth(int\
    \ v) const { return D[v]; }\n C depth_w(int v) const {\n  static_assert(weight,\
    \ \"\\'depth_w\\' is not available\");\n  return DW[v];\n }\n int to_seq(int v)\
    \ const { return L[v]; }\n int to_node(int i) const { return I[i]; }\n int parent(int\
    \ v) const { return P[v]; }\n int root(int v) const {\n  for (v= PP[v];; v= PP[P[v]])\n\
    \   if (P[v] == -1) return v;\n }\n bool connected(int u, int v) const { return\
    \ root(u) == root(v); }\n int lca(int u, int v) const {\n  for (;; v= P[PP[v]])\
    \ {\n   if (L[u] > L[v]) std::swap(u, v);\n   if (PP[u] == PP[v]) return u;\n\
    \  }\n }\n int la(int v, int k) const {\n  assert(k <= D[v]);\n  for (int u;;\
    \ k-= L[v] - L[u] + 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v]\
    \ - k];\n }\n int la_w(int v, C w) const {\n  static_assert(weight, \"\\'la_w\\\
    ' is not available\");\n  for (C c;; w-= c) {\n   int u= PP[v];\n   c= DW[v] -\
    \ DW[u] + W[u];\n   if (w < c) {\n    int ok= L[v], ng= L[u] - 1;\n    while (ok\
    \ - ng > 1) {\n     if (int m= (ok + ng) / 2; DW[v] - DW[I[m]] <= w) ok= m;\n\
    \     else ng= m;\n    }\n    return I[ok];\n   }\n   if (v= P[u]; v == -1) return\
    \ u;\n  }\n }\n int jump(int u, int v, int k) const {\n  if (!k) return u;\n \
    \ if (u == v) return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v, D[v] -\
    \ D[u] - 1) : P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n\
    \  return k > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n\
    \ }\n int jump_w(int u, int v, C w) const {\n  static_assert(weight, \"\\'jump_w\\\
    ' is not available\");\n  if (u == v) return u;\n  int z= lca(u, v);\n  C d_uz=\
    \ DW[u] - DW[z], d_vz= DW[v] - DW[z];\n  return w >= d_uz + d_vz ? v : w <= d_uz\
    \ ? la_w(u, w) : la_w(v, d_uz + d_vz - w);\n }\n int dist(int u, int v) const\
    \ { return D[u] + D[v] - D[lca(u, v)] * 2; }\n C dist_w(int u, int v) const {\n\
    \  static_assert(weight, \"\\'dist_w\\' is not available\");\n  return DW[u] +\
    \ DW[v] - DW[lca(u, v)] * 2;\n }\n // u is in v\n bool in_subtree(int u, int v)\
    \ const { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const\
    \ { return R[v] - L[v]; }\n // half-open interval\n std::array<int, 2> subtree(int\
    \ v) const { return std::array{L[v], R[v]}; }\n // sequence of closed intervals\n\
    \ template <bool edge= 0> std::vector<std::array<int, 2>> path(int u, int v) const\
    \ {\n  std::vector<std::array<int, 2>> up, down;\n  while (PP[u] != PP[v]) {\n\
    \   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}), v= P[PP[v]];\n\
    \   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n  }\n  if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};\n#line 3 \"src/Graph/FunctionalGraph.hpp\"\
    \nclass FunctionalGraph {\n std::vector<int> to, rt;\n Tree<> tree;\npublic:\n\
    \ FunctionalGraph(int n): to(n, -1), rt(n, -1), tree(n + 1) {}\n void add_edge(int\
    \ src, int dst) { assert(to[src] == -1), to[src]= dst; }\n void build() {\n  const\
    \ int n= to.size();\n  for (int u, w, v= n; v--;)\n   if (rt[v] == -1) {\n   \
    \ for (rt[v]= -2, w= to[v];; rt[w]= -2, w= to[w])\n     if (assert(w != -1); rt[w]\
    \ != -1) {\n      if (rt[w] != -2) w= rt[w];\n      break;\n     }\n    for (u=\
    \ v; rt[u] == -2; u= to[u]) rt[u]= w;\n   }\n  for (int v= n; v--;)\n   if (rt[v]\
    \ == v) tree.add_edge(v, n);\n   else tree.add_edge(v, to[v]);\n  tree.build(n);\n\
    \ }\n template <class Int> std::enable_if_t<std::is_convertible_v<int, Int>, int>\
    \ jump(int v, Int k) const {\n  int n= to.size(), d= tree.depth(v) - 1;\n  if\
    \ (k <= d) return tree.jump(v, n, (int)k);\n  int b= to[v= rt[v]], l= (k-= d)\
    \ % tree.depth(b);\n  if (l == 0) return v;\n  return tree.jump(b, n, l - 1);\n\
    \ }\n // ((a_0,...,a_{i-1}) x 1, (a_i,...,a_{j-1}) x loop_num, (a_j,...,a_m) x\
    \ 1)\n template <class Int> std::enable_if_t<std::is_convertible_v<int, Int>,\
    \ std::array<std::pair<std::vector<int>, Int>, 3>> path(int v, Int k) const {\n\
    \  std::array<std::pair<std::vector<int>, Int>, 3> ret;\n  int n= to.size(), d=\
    \ tree.depth(v) - 1;\n  if (ret[0].second= 1; k <= d) {\n   for (int e= k; e--;\
    \ v= to[v]) ret[0].first.push_back(v);\n   return ret;\n  }\n  for (int e= d;\
    \ e--; v= to[v]) ret[0].first.push_back(v);\n  int b= to[v= rt[v]], c= tree.depth(b),\
    \ l= (k-= d) % c;\n  ret[1].second= k / c, ret[2].second= 1;\n  for (int e= c;\
    \ e--; v= to[v]) ret[1].first.push_back(v);\n  for (int e= l; e--; v= to[v]) ret[2].first.push_back(v);\n\
    \  return ret;\n }\n};\n#line 6 \"test/atcoder/abc136_d.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n string S;\n\
    \ cin >> S;\n int N= S.length();\n FunctionalGraph graph(N);\n for (int i= 0;\
    \ i < N; ++i)\n  if (S[i] == 'L') graph.add_edge(i, i - 1);\n  else graph.add_edge(i,\
    \ i + 1);\n graph.build();\n BigInt K(\"1\" + string(100, '0'));\n vector cnt(N,\
    \ 0);\n for (int i= 0; i < N; ++i) ++cnt[graph.jump(i, K)];\n for (int i= 0; i\
    \ < N; ++i) cout << cnt[i] << \" \\n\"[i == N - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc136/tasks/abc136_d\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/FFT/BigInt.hpp\"\n#include \"\
    src/Graph/FunctionalGraph.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n string S;\n cin >> S;\n int N= S.length();\n FunctionalGraph\
    \ graph(N);\n for (int i= 0; i < N; ++i)\n  if (S[i] == 'L') graph.add_edge(i,\
    \ i - 1);\n  else graph.add_edge(i, i + 1);\n graph.build();\n BigInt K(\"1\"\
    \ + string(100, '0'));\n vector cnt(N, 0);\n for (int i= 0; i < N; ++i) ++cnt[graph.jump(i,\
    \ K)];\n for (int i= 0; i < N; ++i) cout << cnt[i] << \" \\n\"[i == N - 1];\n\
    \ return 0;\n}"
  dependsOn:
  - src/FFT/BigInt.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  - src/Internal/Remainder.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/modint_traits.hpp
  - src/Graph/FunctionalGraph.hpp
  - src/Graph/Tree.hpp
  - src/DataStructure/CsrArray.hpp
  isVerificationFile: true
  path: test/atcoder/abc136_d.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 11:44:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc136_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc136_d.test.cpp
- /verify/test/atcoder/abc136_d.test.cpp.html
title: test/atcoder/abc136_d.test.cpp
---
