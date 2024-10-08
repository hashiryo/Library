#pragma once
#include <array>
#include <limits>
#include "src/NumberTheory/is_prime.hpp"
#include "src/Math/ModInt.hpp"
template <class mod_t, size_t LM> mod_t get_inv(int n) {
 static_assert(is_modint_v<mod_t>);
 static const auto m= mod_t::mod();
 static mod_t* dat= new mod_t[LM];
 static int l= 1;
 if (l == 1) dat[l++]= 1;
 for (; l <= n; ++l) dat[l]= dat[m % l] * (m - m / l);
 return dat[n];
}
namespace math_internal {
#define CE constexpr
#define ST static
#define TP template
#define BSF(_, n) __builtin_ctz##_(n)
TP<class mod_t> struct NTT {
#define _DFT(a, b, c, ...) \
 mod_t r, u, *x0, *x1; \
 for (int a= n, b= 1, s, i; a>>= 1; b<<= 1) \
  for (s= 0, r= I, x0= x;; r*= c[BSF(, s)], x0= x1 + p) { \
   for (x1= x0 + (i= p); i--;) __VA_ARGS__; \
   if (++s == e) break; \
  }
 ST inline void dft(int n, mod_t x[]) { _DFT(p, e, r2, x1[i]= x0[i] - (u= r * x1[i]), x0[i]+= u); }
 ST inline void idft(int n, mod_t x[]) {
  _DFT(e, p, ir2, u= x0[i] - x1[i], x0[i]+= x1[i], x1[i]= r * u)
  for (const mod_t iv= I / n; n--;) x[n]*= iv;
 }
#undef _DFT
 ST inline void even_dft(int n, mod_t x[]) {
  for (int i= 0, j= 0; i < n; i+= 2) x[j++]= iv2 * (x[i] + x[i + 1]);
 }
 ST inline void odd_dft(int n, mod_t x[], mod_t r= iv2) {
  for (int i= 0, j= 0;; r*= ir2[BSF(, ++j)])
   if (x[j]= r * (x[i] - x[i + 1]); (i+= 2) == n) break;
 }
 ST inline void dft_doubling(int n, mod_t x[], int i= 0) {
  mod_t k= I, t= rt[BSF(, n << 1)];
  for (copy_n(x, n, x + n), idft(n, x + n); i < n; ++i) x[n + i]*= k, k*= t;
  dft(n, x + n);
 }
protected:
 ST CE u64 md= mod_t::mod();
 static_assert(md & 1);
 static_assert(is_prime(md));
 ST CE u8 E= BSF(ll, md - 1);
 ST CE mod_t w= [](u8 e) {
  for (mod_t r= 2;; r+= 1)
   if (auto s= r.pow((md - 1) / 2); s != 1 && s * s == 1) return r.pow((md - 1) >> e);
  return mod_t();
 }(E);
 static_assert(w != mod_t());
 ST CE mod_t I= 1, iv2= (md + 1) / 2, iw= w.pow((1ULL << E) - 1);
 ST CE auto roots(mod_t w) {
  array<mod_t, E + 1> x= {};
  for (u8 e= E; e; w*= w) x[e--]= w;
  return x[0]= w, x;
 }
 TP<u32 N> ST CE auto ras(const array<mod_t, E + 1>& rt, const array<mod_t, E + 1>& irt, int i= N) {
  array<mod_t, E + 1 - N> x= {};
  for (mod_t ro= 1; i <= E; ro*= irt[i++]) x[i - N]= rt[i] * ro;
  return x;
 }
 ST CE auto rt= roots(w), irt= roots(iw);
 ST CE auto r2= ras<2>(rt, irt), ir2= ras<2>(irt, rt);
};
TP<class T, u8 t, class B> struct NI: public B {
 using B::B;
#define FUNC(op, name, HG, ...) \
 inline void name(__VA_ARGS__) { \
  HG(op, 1); \
  if CE (t > 1) HG(op, 2); \
  if CE (t > 2) HG(op, 3); \
  if CE (t > 3) HG(op, 4); \
  if CE (t > 4) HG(op, 5); \
 }
#define REP for (int i= b; i < e; ++i)
#define DFT(fft, _) B::ntt##_::fft(e - b, this->dt##_ + b)
#define ZEROS(op, _) fill_n(this->dt##_ + b, e - b, typename B::m##_())
#define SET(op, _) copy(x + b, x + e, this->dt##_ + b)
#define SET_S(op, _) this->dt##_[i]= x;
#define SUBST(op, _) copy(r.dt##_ + b, r.dt##_ + e, this->dt##_ + b)
#define ASGN(op, _) REP this->dt##_[i] op##= r.dt##_[i]
#define ASN(nm, op) TP<class C> FUNC(op, nm, ASGN, const NI<T, t, C>& r, int b, int e)
#define BOP(op, _) REP this->dt##_[i]= l.dt##_[i] op r.dt##_[i]
#define OP(nm, op) TP<class C, class D> FUNC(op, nm, BOP, const NI<T, t, C>& l, const NI<T, t, D>& r, int b, int e)
 OP(add, +) OP(dif, -) OP(mul, *) ASN(add, +) ASN(dif, -) ASN(mul, *) FUNC(dft, dft, DFT, int b, int e) FUNC(idft, idft, DFT, int b, int e) FUNC(__, zeros, ZEROS, int b, int e) FUNC(__, set, SET, const T x[], int b, int e) FUNC(__, set, SET_S, int i, T x) TP<class C> FUNC(__, subst, SUBST, const NI<T, t, C>& r, int b, int e) inline void get(T x[], int b, int e) const {
  if CE (t == 1) copy(this->dt1 + b, this->dt1 + e, x + b);
  else REP x[i]= get(i);
 }
#define TMP(_) B::iv##_##1 * (this->dt##_[i] - r1)
 inline T get(int i) const {
  if CE (t > 1) {
   u64 r1= this->dt1[i].val(), r2= (TMP(2)).val();
   T a= 0;
   if CE (t > 2) {
    u64 r3= (TMP(3) - B::iv32 * r2).val();
    if CE (t > 3) {
     u64 r4= (TMP(4) - B::iv42 * r2 - B::iv43 * r3).val();
     if CE (t > 4) a= T(B::m4::mod()) * (TMP(5) - B::iv52 * r2 - B::iv53 * r3 - B::iv54 * r4).val();
     a= (a + r4) * B::m3::mod();
    }
    a= (a + r3) * B::m2::mod();
   }
   return (a + r2) * B::m1::mod() + r1;
  } else return this->dt1[i];
 }
#undef TMP
#undef DFT
#undef ZEROS
#undef SET
#undef SET_S
#undef SUBST
#undef ASGN
#undef ASN
#undef BOP
#undef OP
#undef FUNC
#undef REP
};
#define ARR(_) \
 using m##_= ModInt<M##_>; \
 using ntt##_= NTT<m##_>; \
 m##_* dt##_= new m##_[LM];
#define IV2 ST CE m2 iv21= m2(1) / m1::mod();
#define IV3 ST CE m3 iv32= m3(1) / m2::mod(), iv31= iv32 / m1::mod();
#define IV4 ST CE m4 iv43= m4(1) / m3::mod(), iv42= iv43 / m2::mod(), iv41= iv42 / m1::mod();
#define IV5 ST CE m5 iv54= m5(1) / m4::mod(), iv53= iv54 / m3::mod(), iv52= iv53 / m2::mod(), iv51= iv52 / m1::mod();
TP<u8 t, u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM, bool v> struct NB {
 ARR(1)
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4, M5, LM, 0> {
 ARR(1) ARR(2) IV2
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<3, M1, M2, M3, M4, M5, LM, 0> {
 ARR(1) ARR(2) ARR(3) IV2 IV3
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4, M1, M2, M3, M4, M5, LM, 0> {
 ARR(1) ARR(2) ARR(3) ARR(4) IV2 IV3 IV4
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5, LM, 0> {
 ARR(1) ARR(2) ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5
};
#undef ARR
#define VC(_) \
 using m##_= ModInt<M##_>; \
 using ntt##_= NTT<m##_>; \
 vector<m##_> bf##_; \
 m##_* dt##_;
#define RS resize
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<1, M1, M2, M3, M4, M5, LM, 1> {
 NB(): dt1(bf1.data()) {}
 void RS(int n) { bf1.RS(n), dt1= bf1.data(); }
 u32 size() const { return bf1.size(); }
 VC(1)
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4, M5, LM, 1> {
 NB(): dt1(bf1.data()), dt2(bf2.data()) {}
 void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(); }
 u32 size() const { return bf1.size(); }
 VC(1) VC(2) IV2
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<3, M1, M2, M3, M4, M5, LM, 1> {
 NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()) {}
 void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(); }
 u32 size() const { return bf1.size(); }
 VC(1) VC(2) VC(3) IV2 IV3
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4, M1, M2, M3, M4, M5, LM, 1> {
 NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()), dt4(bf4.data()) {}
 void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(); }
 u32 size() const { return bf1.size(); }
 VC(1) VC(2) VC(3) VC(4) IV2 IV3 IV4
};
TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5, LM, 1> {
 NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()), dt4(bf4.data()), dt5(bf5.data()) {}
 void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(), bf5.RS(n), dt5= bf5.data(); }
 u32 size() const { return bf1.size(); }
 VC(1) VC(2) VC(3) VC(4) VC(5) IV2 IV3 IV4 IV5
};
#undef VC
#undef IV2
#undef IV3
#undef IV4
#undef IV5
TP<class T, u32 LM> CE bool is_nttfriend() {
 if CE (!is_staticmodint_v<T>) return 0;
 else return (T::mod() & is_prime(T::mod())) && LM <= (1ULL << BSF(ll, T::mod() - 1));
}
TP<class T, enable_if_t<is_arithmetic_v<T>, nullptr_t> = nullptr> CE u64 mv() { return numeric_limits<T>::max(); }
TP<class T, enable_if_t<is_staticmodint_v<T>, nullptr_t> = nullptr> CE u64 mv() { return T::mod(); }
TP<class T, u32 LM, u32 M1, u32 M2, u32 M3, u32 M4> CE u8 nt() {
 if CE (!is_nttfriend<T, LM>()) {
  CE u128 m= mv<T>(), mm= m * m;
  if CE (mm <= M1 / LM) return 1;
  else if CE (mm <= u64(M1) * M2 / LM) return 2;
  else if CE (mm <= u128(M1) * M2 * M3 / LM) return 3;
  else if CE (mm <= u128(M1) * M2 * M3 * M4 / LM) return 4;
  else return 5;
 } else return 1;
}
#undef BSF
#undef RS
CE u32 MOD1= 998244353, MOD2= 897581057, MOD3= 880803841, MOD4= 754974721, MOD5= 645922817;
TP<class T, u32 LM> CE u8 nttarr_type= nt<T, LM, MOD1, MOD2, MOD3, MOD4>();
TP<class T, u32 LM> CE u8 nttarr_cat= is_nttfriend<T, LM>() && (mv<T>() > (1 << 30)) ? 0 : nttarr_type<T, LM>;
TP<class T, u32 LM, bool v> using NTTArray= NI<T, nttarr_type<T, LM>, conditional_t<is_nttfriend<T, LM>(), NB<1, mv<T>(), 0, 0, 0, 0, LM, v>, NB<nttarr_type<T, LM>, MOD1, MOD2, MOD3, MOD4, MOD5, LM, v>>>;
#undef CE
#undef ST
#undef TP
}
using math_internal::is_nttfriend, math_internal::nttarr_type, math_internal::nttarr_cat, math_internal::NTT, math_internal::NTTArray;
template <class T, size_t LM, int id= 0> struct GlobalNTTArray {
 static inline NTTArray<T, LM, 0> bf;
};
template <class T, size_t LM, size_t LM2, int id= 0> struct GlobalNTTArray2D {
 static inline NTTArray<T, LM, 0>* bf= new NTTArray<T, LM, 0>[LM2];
};
template <class T, size_t LM, int id= 0> struct GlobalArray {
 static inline T* bf= new T[LM];
};
constexpr unsigned pw2(unsigned n) { return --n, n|= n >> 1, n|= n >> 2, n|= n >> 4, n|= n >> 8, n|= n >> 16, ++n; }
