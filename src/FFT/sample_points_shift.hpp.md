---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/FFT/polynomial_matrix_prod.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306E\u7DCF\u7A4D"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: test/yukicoder/42.test.cpp
    title: test/yukicoder/42.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502.test.cpp
    title: test/yukicoder/502.test.cpp
  - icon: ':x:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/FFT/sample_points_shift.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <numeric>\n#include <cassert>\n#line 2 \"src/FFT/NTT.hpp\"\
    \n#include <array>\n#include <limits>\n#line 2 \"src/Internal/Remainder.hpp\"\n\
    namespace math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32=\
    \ uint32_t;\nusing u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n \
    \ if (l+= r; l >= M) l-= M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n\
    \ CE IL U diff(U l, U r) const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return\
    \ l; \\\n }\n#define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static\
    \ CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\n\
    template <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
    \ mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod)\
    \ % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r);\
    \ }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const\
    \ { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n\
    \ }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE\
    \ u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n))\
    \ : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod -\
    \ ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na():\
    \ mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const {\
    \ return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\n\
    struct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n\
    \ CE MP_Br(u32 m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m)\
    \ {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32,\
    \ mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64\
    \ n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return\
    \ n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n\
    \ CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) /\
    \ m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64,\
    \ mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n;\
    \ }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM;\
    \ }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return (n * x)\
    \ >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod; }\n\
    };\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0),\
    \ v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1)\
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
    \ <type_traits>\n#line 4 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr\
    \ inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y=\
    \ z - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n}\n#line 4 \"src/Math/ModInt.hpp\"\nnamespace math_internal\
    \ {\n#define CE constexpr\nstruct m_b {};\nstruct s_b: m_b {};\ntemplate <class\
    \ mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t>\
    \ CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class MP, u64\
    \ MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n};\ntemplate\
    \ <class Int, class U, class B> struct MInt: public B {\n using Uint= U;\n static\
    \ CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n CE MInt(const\
    \ MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template <class\
    \ T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr> CE MInt(T\
    \ n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n % B::md.mod))) {}\n\
    \ CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name, op)\
    \ \\\n CE MInt name const { \\\n  MInt ret; \\\n  ret.x= op; \\\n  return ret;\
    \ \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x, r.x))\n FUNC(operator-(const\
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
    \ & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32, 31>, MOD>>, conditional_t < (MOD\
    \ < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u\
    \ << 31), MInt<int, u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2,\
    \ MOD>>, MInt<i64, u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt,\
    \ math_internal::is_modint_v, math_internal::is_staticmodint_v;\ntemplate <class\
    \ mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
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
    \ n >> 2, n|= n >> 4, n|= n >> 8, n|= n >> 16, ++n; }\n#line 7 \"src/FFT/sample_points_shift.hpp\"\
    \ntemplate <class mod_t, std::size_t LM= 1 << 24> std::vector<mod_t> sample_points_shift(const\
    \ std::vector<mod_t>& y, mod_t c, int m= 1) {\n assert(m <= mod_t::mod()), assert(y.size()\
    \ <= mod_t::mod());\n static constexpr int TH= (int[]){45, 32, 75, 130, 180, 260}[nttarr_cat<mod_t,\
    \ LM>];\n if (m == 0) return {};\n std::uint64_t c_64= c.val(), nc1= (c + (m -\
    \ 1)).val();\n std::uint32_t k= y.size(), d= k - 1, i= d, e;\n if (c_64 + m <=\
    \ k) return std::vector<mod_t>(y.begin() + c_64, y.begin() + c_64 + m);\n mod_t\
    \ *x= GlobalArray<mod_t, LM, 0>::bf, *p= GlobalArray<mod_t, LM, 1>::bf, *bf;\n\
    \ for (x[d]= 1; i; i--) x[i - 1]= x[i] * i;\n mod_t t= mod_t(1) / (x[0] * x[0]);\n\
    \ for (i= d / 2 + 1; i--;) x[i]= x[d - i]= x[i] * x[d - i] * t;\n for (i= k; i--;)\
    \ x[i]*= y[i];\n for (i= 1; i < k; i+= 2) x[d - i]= -x[d - i];\n auto f= [&](mod_t\
    \ a, int n, mod_t ret[]) {\n  using GNA1= GlobalNTTArray<mod_t, LM, 1>;\n  using\
    \ GNA2= GlobalNTTArray<mod_t, LM, 2>;\n  mod_t* q= GlobalArray<mod_t, LM, 2>::bf;\n\
    \  for (e= d + n, i= 0, t= a - d; i < e; ++i, t+= 1) ret[i]= t;\n  std::partial_sum(ret,\
    \ ret + e, q, std::multiplies<>());\n  for (t= mod_t(1) / q[e - 1]; --i;) q[i]=\
    \ t * q[i - 1], t*= ret[i];\n  if (q[0]= t; k >= TH && n >= TH) {\n   const int\
    \ len= pw2(e + (d > 0));\n   GNA1::bf.set(x, 0, k), GNA1::bf.zeros(k, len), GNA1::bf.dft(0,\
    \ len), GNA2::bf.set(q, 0, e), GNA2::bf.zeros(e, len), GNA2::bf.dft(0, len), GNA1::bf.mul(GNA2::bf,\
    \ 0, len), GNA1::bf.idft(0, len), GNA1::bf.get(ret - d, d, e);\n  } else\n   for\
    \ (std::fill_n(ret, n, mod_t()), i= k; i--;)\n    for (int b= d - i, j= n; j--;)\
    \ ret[j]+= x[i] * q[j + b];\n  for (t= a, i= k; --i;) t*= a - i;\n  for (; i <\
    \ n; i++) ret[i]*= t, t*= (a + (i + 1)) * q[i];\n  return ret + n;\n };\n if (c_64\
    \ < k) {\n  if (bf= std::copy_n(y.begin() + c_64, k - c_64, p); nc1 < k) std::copy_n(y.begin(),\
    \ nc1 + 1, f(k, mod_t::mod() - k, bf));\n  else f(k, c_64 + m - k, bf);\n } else\
    \ if (nc1 < c_64) {\n  if (bf= f(c, (-c).val(), p); nc1 < k) std::copy_n(y.begin(),\
    \ nc1 + 1, bf);\n  else f(k, nc1 + 1 - k, std::copy_n(y.begin(), k, bf));\n }\
    \ else f(c, m, p);\n return std::vector(p, p + m);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    #include <cassert>\n#include \"src/FFT/NTT.hpp\"\ntemplate <class mod_t, std::size_t\
    \ LM= 1 << 24> std::vector<mod_t> sample_points_shift(const std::vector<mod_t>&\
    \ y, mod_t c, int m= 1) {\n assert(m <= mod_t::mod()), assert(y.size() <= mod_t::mod());\n\
    \ static constexpr int TH= (int[]){45, 32, 75, 130, 180, 260}[nttarr_cat<mod_t,\
    \ LM>];\n if (m == 0) return {};\n std::uint64_t c_64= c.val(), nc1= (c + (m -\
    \ 1)).val();\n std::uint32_t k= y.size(), d= k - 1, i= d, e;\n if (c_64 + m <=\
    \ k) return std::vector<mod_t>(y.begin() + c_64, y.begin() + c_64 + m);\n mod_t\
    \ *x= GlobalArray<mod_t, LM, 0>::bf, *p= GlobalArray<mod_t, LM, 1>::bf, *bf;\n\
    \ for (x[d]= 1; i; i--) x[i - 1]= x[i] * i;\n mod_t t= mod_t(1) / (x[0] * x[0]);\n\
    \ for (i= d / 2 + 1; i--;) x[i]= x[d - i]= x[i] * x[d - i] * t;\n for (i= k; i--;)\
    \ x[i]*= y[i];\n for (i= 1; i < k; i+= 2) x[d - i]= -x[d - i];\n auto f= [&](mod_t\
    \ a, int n, mod_t ret[]) {\n  using GNA1= GlobalNTTArray<mod_t, LM, 1>;\n  using\
    \ GNA2= GlobalNTTArray<mod_t, LM, 2>;\n  mod_t* q= GlobalArray<mod_t, LM, 2>::bf;\n\
    \  for (e= d + n, i= 0, t= a - d; i < e; ++i, t+= 1) ret[i]= t;\n  std::partial_sum(ret,\
    \ ret + e, q, std::multiplies<>());\n  for (t= mod_t(1) / q[e - 1]; --i;) q[i]=\
    \ t * q[i - 1], t*= ret[i];\n  if (q[0]= t; k >= TH && n >= TH) {\n   const int\
    \ len= pw2(e + (d > 0));\n   GNA1::bf.set(x, 0, k), GNA1::bf.zeros(k, len), GNA1::bf.dft(0,\
    \ len), GNA2::bf.set(q, 0, e), GNA2::bf.zeros(e, len), GNA2::bf.dft(0, len), GNA1::bf.mul(GNA2::bf,\
    \ 0, len), GNA1::bf.idft(0, len), GNA1::bf.get(ret - d, d, e);\n  } else\n   for\
    \ (std::fill_n(ret, n, mod_t()), i= k; i--;)\n    for (int b= d - i, j= n; j--;)\
    \ ret[j]+= x[i] * q[j + b];\n  for (t= a, i= k; --i;) t*= a - i;\n  for (; i <\
    \ n; i++) ret[i]*= t, t*= (a + (i + 1)) * q[i];\n  return ret + n;\n };\n if (c_64\
    \ < k) {\n  if (bf= std::copy_n(y.begin() + c_64, k - c_64, p); nc1 < k) std::copy_n(y.begin(),\
    \ nc1 + 1, f(k, mod_t::mod() - k, bf));\n  else f(k, c_64 + m - k, bf);\n } else\
    \ if (nc1 < c_64) {\n  if (bf= f(c, (-c).val(), p); nc1 < k) std::copy_n(y.begin(),\
    \ nc1 + 1, bf);\n  else f(k, nc1 + 1 - k, std::copy_n(y.begin(), k, bf));\n }\
    \ else f(c, m, p);\n return std::vector(p, p + m);\n}"
  dependsOn:
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  - src/Internal/Remainder.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  isVerificationFile: false
  path: src/FFT/sample_points_shift.hpp
  requiredBy:
  - src/FFT/polynomial_matrix_prod.hpp
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
  - test/yukicoder/502.test.cpp
  - test/yukicoder/665.test.cpp
  - test/yukicoder/42.test.cpp
documentation_of: src/FFT/sample_points_shift.hpp
layout: document
title: "\u591A\u9805\u5F0F\u306E\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8"
---
y=f(0),f(1),...,f(n-1)が与えられたときのf(c),f(c+1),...,f(c+m-1)を計算
## 計算量
$\mathcal{O}((n+m)\log(n+m))$