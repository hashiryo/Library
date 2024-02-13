---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc150_f.RH.Nimber.test.cpp
    title: test/atcoder/abc150_f.RH.Nimber.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit_test/nimber_inv.test.cpp
    title: test/unit_test/nimber_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit_test/nimber_log.test.cpp
    title: test/unit_test/nimber_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit_test/nimber_sqrt.test.cpp
    title: test/unit_test/nimber_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/nim_product_64.test.cpp
    title: test/yosupo/nim_product_64.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/Nimber.hpp\"\n#include <array>\n#include <numeric>\n\
    #include <utility>\n#include <cassert>\nclass Nimber {\n using u64= uint64_t;\n\
    \ using u32= uint32_t;\n using u16= uint16_t;\n static inline std::array<u16,\
    \ 65536> pw, ln;\n template <u16 h= 3> static inline u16 half(u16 A) { return\
    \ A ? pw[(ln[A] + h) % 65535] : 0; }\n template <u16 h= 0> static inline u16 mul(u16\
    \ A, u16 B) { return A && B ? pw[(ln[A] + ln[B] + h) % 65535] : 0; }\n template\
    \ <u16 h= 0> static inline u16 mul(u16 A, u16 B, u16 C) { return A && B && C ?\
    \ pw[(ln[A] + ln[B] + ln[C] + h) % 65535] : 0; }\n static inline u16 inv(u16 A)\
    \ { return assert(A), pw[65535 - ln[A]]; }\n static inline u16 sqrt(u16 A) { return\
    \ A ? pw[u16((65537 * u32(ln[A])) >> 1)] : 0; }\n static inline u64 mul(u64 A,\
    \ u64 B) {\n  u16 a0= u16(A), a1= u16(A >> 16), a2= u16(A >> 32), a3= A >> 48,\
    \ b0= u16(B), b1= u16(B >> 16), b2= u16(B >> 32), b3= B >> 48, x0= a1 ^ a0, x1=\
    \ a3 ^ a2, y0= b1 ^ b0, y1= b3 ^ b2, c0= mul(a0, b0), c1= mul(x0, y0) ^ c0, c2=\
    \ mul<0>(a2 ^ a0, b2 ^ b0), c3= mul<0>(x0 ^ x1, y0 ^ y1) ^ c2 ^ c1;\n  return\
    \ c2^= (c0^= mul<3>(a1, b1)) ^ mul<3>(u16(a3 ^ a1), u16(b3 ^ b1)), c1^= mul<6>(a3,\
    \ b3) ^ mul<3>(x1, y1), c0^= mul<6>(a2, b2) ^ mul<6>(x1, y1), (u64(c3) << 48)\
    \ | (u64(c2) << 32) | (u32(c1) << 16) | c0;\n }\n static inline u64 inv(u64 A)\
    \ {\n  u16 a0= u16(A), a1= u16(A >> 16), a2= u16(A >> 32), a3= A >> 48, x= a2\
    \ ^ a3, y= a1 ^ a3, w= a0 ^ a2, v= a0 ^ a1, b3= mul(a1, a2, a1 ^ x), b2= mul(a0,\
    \ a2, a0 ^ x), b1= mul(a0, a1, a0 ^ y), b0= mul(a0, v, w), t= mul<3>(w, x, x);\n\
    \  return b0^= b1 ^ b2, b1^= b3, b2^= b3, b0^= b3^= mul(a0, a0, a3), b1^= t ^\
    \ mul<3>(a1, y, y), b0^= t ^ mul<3>(v, y, y), b3^= t= mul<3>(a1, a3, y) ^ mul<3>(a2,\
    \ x, x), b2^= t ^ mul<3>(a0, a3, a3) ^ mul<3>(a1, a1, a2), b3^= mul<6>(a3, a3,\
    \ x), b2^= mul<6>(a3, x, x), b1^= mul<6>(a3, a3, y ^ w), b0^= mul<6>(y, x, x),\
    \ b2^= mul<9>(a3, a3, a3), b0^= mul<9>(a3, a3, y), t= mul<6>(x, b3) ^ mul<6>(a3,\
    \ b2) ^ mul<3>(a1, b1) ^ mul(a0, b0), t= inv(t), (u64(mul(b3, t)) << 48) | (u64(mul(b2,\
    \ t)) << 32) | (u32(mul(b1, t)) << 16) | mul(b0, t);\n }\n static inline u64 square(u64\
    \ A) {\n  u16 a0= u16(A), a1= u16(A >> 16), a2= u16(A >> 32), a3= A >> 48;\n \
    \ return a3= mul(a3, a3), a2= mul(a2, a2), a1= mul(a1, a1), a0= mul(a0, a0), a0^=\
    \ half(a1) ^ half<6>(a3), a2^= half(a3), a1^= half(a3 ^ a2), (u64(a3) << 48) |\
    \ (u64(a2) << 32) | (u32(a1) << 16) | a0;\n }\n static inline u64 pow(u64 A, u64\
    \ k) {\n  for (u64 ret= 1;; A= square(A))\n   if (k & 1 ? ret= mul(ret, A) : 0;\
    \ !(k>>= 1)) return ret;\n }\n template <int mod> static inline int mdif(int a,\
    \ int b) { return a+= mod & -((a-= b) < 0); }\n template <int mod> static inline\
    \ int mmul(int a, int b) { return u64(a) * b % mod; }\n static inline int log16(u16\
    \ A, u16 B) {\n  int a= ln[A], b= ln[B], x= 1;\n  if (a == 0) return b == 0 ?\
    \ 1 : -1;\n  for (int q, z, u, y= 0, t= 65535; t;) z= x, u= a, x= y, y= z - y\
    \ * (q= a / t), a= t, t= u - t * q;\n  return b % a ? -1 : u32(b / a) * (x < 0\
    \ ? 65535 + x : x) % 65535;\n }\n template <int period, int size> static inline\
    \ int bsgs(u64 x, u64 y) {\n  static constexpr int mask= size - 1;\n  std::pair<u64,\
    \ int> vs[size];\n  int os[size + 1]= {};\n  u64 so[size], big= 1;\n  for (int\
    \ i= 0; i < size; ++i, big= mul(big, x)) ++os[(so[i]= big) & mask];\n  for (int\
    \ i= 0; i < size; ++i) os[i + 1]+= os[i];\n  for (int i= 0; i < size; ++i) vs[--os[so[i]\
    \ & mask]]= {so[i], i};\n  for (int t= 0; t < period; t+= size, y= mul(y, big))\n\
    \   for (int m= (y & mask), i= os[m], ret; i < os[m + 1]; ++i)\n    if (y == vs[i].first)\
    \ return (ret= vs[i].second - t) < 0 ? ret + period : ret;\n  return -1;\n }\n\
    \ static inline u64 log(u64 A, u64 B) {\n  if (B == 1) return 0;\n  if (!A &&\
    \ !B) return 1;\n  if (!A || !B) return u64(-1);\n  static constexpr int P0= 641,\
    \ P1= 65535, P2= 65537, P3= 6700417, iv10= 40691, iv21= 32768, iv20= 45242, iv32=\
    \ 3317441, iv31= 3350208, iv30= 3883315;\n  int a0= bsgs<P0, 16>(pow(A, 0x663d80ff99c27f),\
    \ pow(B, 0x663d80ff99c27f));\n  if (a0 == -1) return u64(-1);\n  int a1= log16(pow(A,\
    \ 0x1000100010001), pow(B, 0x1000100010001));\n  if (a1 == -1) return u64(-1);\n\
    \  int a2= bsgs<P2, 256>(pow(A, 0xffff0000ffff), pow(B, 0xffff0000ffff));\n  if\
    \ (a2 == -1) return u64(-1);\n  int a3= bsgs<P3, 2048>(pow(A, 0x280fffffd7f),\
    \ pow(B, 0x280fffffd7f));\n  if (a3 == -1) return u64(-1);\n  int x1= mmul<P1>(mdif<P1>(a1,\
    \ a0), iv10), x2= mdif<P2>(mmul<P2>(mdif<P2>(a2, a0), iv20), mmul<P2>(x1, iv21)),\
    \ x3= mdif<P3>(mdif<P3>(mmul<P3>(mdif<P3>(a3, a0), iv30), mmul<P3>(x1, iv31)),\
    \ mmul<P3>(x2, iv32));\n  return u64(P0) * (u64(P1) * (u64(P2) * x3 + x2) + x1)\
    \ + a0;\n }\n u64 x;\npublic:\n static inline void init(u32 x= 0, u32 y= 0) {\n\
    \  constexpr u16 f2n[16]= {0x0001u, 0x2827u, 0x392bu, 0x8000u, 0x20fdu, 0x4d1du,\
    \ 0xde4au, 0x0a17u, 0x3464u, 0xe3a9u, 0x6d8du, 0x34bcu, 0xa921u, 0xa173u, 0x0ebcu,\
    \ 0x0e69u};\n  for (int i= pw[0]= pw[65535]= 1; i < 65535; ++i) pw[i]= (pw[i -\
    \ 1] << 1) ^ (0x1681fu & (-(pw[i - 1] >= 0x8000u)));\n  for (int i= 1; i < 65535;\
    \ ln[pw[i]= y]= i, i++)\n   for (x= pw[i], y= 0; x; x&= x - 1) y^= f2n[__builtin_ctz(x)];\n\
    \ }\n Nimber(u64 x_= 0): x(x_) {}\n Nimber &operator+=(const Nimber &r) { return\
    \ x^= r.x, *this; }\n Nimber &operator-=(const Nimber &r) { return x^= r.x, *this;\
    \ }\n Nimber &operator*=(const Nimber &r) { return x= mul(x, r.x), *this; }\n\
    \ Nimber &operator/=(const Nimber &r) { return x= mul(x, inv(r.x)), *this; }\n\
    \ Nimber operator+(const Nimber &r) const { return Nimber(x ^ r.x); }\n Nimber\
    \ operator-(const Nimber &r) const { return Nimber(x ^ r.x); }\n Nimber operator*(const\
    \ Nimber &r) const { return Nimber(mul(x, r.x)); }\n Nimber operator/(const Nimber\
    \ &r) const { return Nimber(mul(x, inv(r.x))); }\n Nimber inv() const { return\
    \ Nimber(inv(x)); }\n Nimber square() const { return Nimber(square(x)); }\n Nimber\
    \ sqrt() const {\n  u16 a0= u16(x), a1= u16(x >> 16), a2= u16(x >> 32), a3= x\
    \ >> 48;\n  return a1^= half(a3 ^ a2), a2^= half(a3), a0^= half(a1) ^ half<6>(a3),\
    \ Nimber((u64(sqrt(a3)) << 48) | (u64(sqrt(a2)) << 32) | (u32(sqrt(a1)) << 16)\
    \ | sqrt(a0));\n }\n u64 val() const { return x; }\n Nimber pow(u64 k) const {\
    \ return Nimber(pow(x, k)); }\n u64 log(const Nimber &r) const { return log(x,\
    \ r.x); }\n bool operator==(const Nimber &r) const { return x == r.x; }\n bool\
    \ operator!=(const Nimber &r) const { return x != r.x; }\n bool operator<(const\
    \ Nimber &r) const { return x < r.x; }\n bool operator>(const Nimber &r) const\
    \ { return x > r.x; }\n bool operator<=(const Nimber &r) const { return x <= r.x;\
    \ }\n bool operator>=(const Nimber &r) const { return x >= r.x; }\n friend std::ostream\
    \ &operator<<(std::ostream &os, const Nimber &r) { return os << r.x; }\n friend\
    \ std::istream &operator>>(std::istream &is, Nimber &r) { return is >> r.x, is;\
    \ }\n};\n"
  code: "#pragma once\n#include <array>\n#include <numeric>\n#include <utility>\n\
    #include <cassert>\nclass Nimber {\n using u64= uint64_t;\n using u32= uint32_t;\n\
    \ using u16= uint16_t;\n static inline std::array<u16, 65536> pw, ln;\n template\
    \ <u16 h= 3> static inline u16 half(u16 A) { return A ? pw[(ln[A] + h) % 65535]\
    \ : 0; }\n template <u16 h= 0> static inline u16 mul(u16 A, u16 B) { return A\
    \ && B ? pw[(ln[A] + ln[B] + h) % 65535] : 0; }\n template <u16 h= 0> static inline\
    \ u16 mul(u16 A, u16 B, u16 C) { return A && B && C ? pw[(ln[A] + ln[B] + ln[C]\
    \ + h) % 65535] : 0; }\n static inline u16 inv(u16 A) { return assert(A), pw[65535\
    \ - ln[A]]; }\n static inline u16 sqrt(u16 A) { return A ? pw[u16((65537 * u32(ln[A]))\
    \ >> 1)] : 0; }\n static inline u64 mul(u64 A, u64 B) {\n  u16 a0= u16(A), a1=\
    \ u16(A >> 16), a2= u16(A >> 32), a3= A >> 48, b0= u16(B), b1= u16(B >> 16), b2=\
    \ u16(B >> 32), b3= B >> 48, x0= a1 ^ a0, x1= a3 ^ a2, y0= b1 ^ b0, y1= b3 ^ b2,\
    \ c0= mul(a0, b0), c1= mul(x0, y0) ^ c0, c2= mul<0>(a2 ^ a0, b2 ^ b0), c3= mul<0>(x0\
    \ ^ x1, y0 ^ y1) ^ c2 ^ c1;\n  return c2^= (c0^= mul<3>(a1, b1)) ^ mul<3>(u16(a3\
    \ ^ a1), u16(b3 ^ b1)), c1^= mul<6>(a3, b3) ^ mul<3>(x1, y1), c0^= mul<6>(a2,\
    \ b2) ^ mul<6>(x1, y1), (u64(c3) << 48) | (u64(c2) << 32) | (u32(c1) << 16) |\
    \ c0;\n }\n static inline u64 inv(u64 A) {\n  u16 a0= u16(A), a1= u16(A >> 16),\
    \ a2= u16(A >> 32), a3= A >> 48, x= a2 ^ a3, y= a1 ^ a3, w= a0 ^ a2, v= a0 ^ a1,\
    \ b3= mul(a1, a2, a1 ^ x), b2= mul(a0, a2, a0 ^ x), b1= mul(a0, a1, a0 ^ y), b0=\
    \ mul(a0, v, w), t= mul<3>(w, x, x);\n  return b0^= b1 ^ b2, b1^= b3, b2^= b3,\
    \ b0^= b3^= mul(a0, a0, a3), b1^= t ^ mul<3>(a1, y, y), b0^= t ^ mul<3>(v, y,\
    \ y), b3^= t= mul<3>(a1, a3, y) ^ mul<3>(a2, x, x), b2^= t ^ mul<3>(a0, a3, a3)\
    \ ^ mul<3>(a1, a1, a2), b3^= mul<6>(a3, a3, x), b2^= mul<6>(a3, x, x), b1^= mul<6>(a3,\
    \ a3, y ^ w), b0^= mul<6>(y, x, x), b2^= mul<9>(a3, a3, a3), b0^= mul<9>(a3, a3,\
    \ y), t= mul<6>(x, b3) ^ mul<6>(a3, b2) ^ mul<3>(a1, b1) ^ mul(a0, b0), t= inv(t),\
    \ (u64(mul(b3, t)) << 48) | (u64(mul(b2, t)) << 32) | (u32(mul(b1, t)) << 16)\
    \ | mul(b0, t);\n }\n static inline u64 square(u64 A) {\n  u16 a0= u16(A), a1=\
    \ u16(A >> 16), a2= u16(A >> 32), a3= A >> 48;\n  return a3= mul(a3, a3), a2=\
    \ mul(a2, a2), a1= mul(a1, a1), a0= mul(a0, a0), a0^= half(a1) ^ half<6>(a3),\
    \ a2^= half(a3), a1^= half(a3 ^ a2), (u64(a3) << 48) | (u64(a2) << 32) | (u32(a1)\
    \ << 16) | a0;\n }\n static inline u64 pow(u64 A, u64 k) {\n  for (u64 ret= 1;;\
    \ A= square(A))\n   if (k & 1 ? ret= mul(ret, A) : 0; !(k>>= 1)) return ret;\n\
    \ }\n template <int mod> static inline int mdif(int a, int b) { return a+= mod\
    \ & -((a-= b) < 0); }\n template <int mod> static inline int mmul(int a, int b)\
    \ { return u64(a) * b % mod; }\n static inline int log16(u16 A, u16 B) {\n  int\
    \ a= ln[A], b= ln[B], x= 1;\n  if (a == 0) return b == 0 ? 1 : -1;\n  for (int\
    \ q, z, u, y= 0, t= 65535; t;) z= x, u= a, x= y, y= z - y * (q= a / t), a= t,\
    \ t= u - t * q;\n  return b % a ? -1 : u32(b / a) * (x < 0 ? 65535 + x : x) %\
    \ 65535;\n }\n template <int period, int size> static inline int bsgs(u64 x, u64\
    \ y) {\n  static constexpr int mask= size - 1;\n  std::pair<u64, int> vs[size];\n\
    \  int os[size + 1]= {};\n  u64 so[size], big= 1;\n  for (int i= 0; i < size;\
    \ ++i, big= mul(big, x)) ++os[(so[i]= big) & mask];\n  for (int i= 0; i < size;\
    \ ++i) os[i + 1]+= os[i];\n  for (int i= 0; i < size; ++i) vs[--os[so[i] & mask]]=\
    \ {so[i], i};\n  for (int t= 0; t < period; t+= size, y= mul(y, big))\n   for\
    \ (int m= (y & mask), i= os[m], ret; i < os[m + 1]; ++i)\n    if (y == vs[i].first)\
    \ return (ret= vs[i].second - t) < 0 ? ret + period : ret;\n  return -1;\n }\n\
    \ static inline u64 log(u64 A, u64 B) {\n  if (B == 1) return 0;\n  if (!A &&\
    \ !B) return 1;\n  if (!A || !B) return u64(-1);\n  static constexpr int P0= 641,\
    \ P1= 65535, P2= 65537, P3= 6700417, iv10= 40691, iv21= 32768, iv20= 45242, iv32=\
    \ 3317441, iv31= 3350208, iv30= 3883315;\n  int a0= bsgs<P0, 16>(pow(A, 0x663d80ff99c27f),\
    \ pow(B, 0x663d80ff99c27f));\n  if (a0 == -1) return u64(-1);\n  int a1= log16(pow(A,\
    \ 0x1000100010001), pow(B, 0x1000100010001));\n  if (a1 == -1) return u64(-1);\n\
    \  int a2= bsgs<P2, 256>(pow(A, 0xffff0000ffff), pow(B, 0xffff0000ffff));\n  if\
    \ (a2 == -1) return u64(-1);\n  int a3= bsgs<P3, 2048>(pow(A, 0x280fffffd7f),\
    \ pow(B, 0x280fffffd7f));\n  if (a3 == -1) return u64(-1);\n  int x1= mmul<P1>(mdif<P1>(a1,\
    \ a0), iv10), x2= mdif<P2>(mmul<P2>(mdif<P2>(a2, a0), iv20), mmul<P2>(x1, iv21)),\
    \ x3= mdif<P3>(mdif<P3>(mmul<P3>(mdif<P3>(a3, a0), iv30), mmul<P3>(x1, iv31)),\
    \ mmul<P3>(x2, iv32));\n  return u64(P0) * (u64(P1) * (u64(P2) * x3 + x2) + x1)\
    \ + a0;\n }\n u64 x;\npublic:\n static inline void init(u32 x= 0, u32 y= 0) {\n\
    \  constexpr u16 f2n[16]= {0x0001u, 0x2827u, 0x392bu, 0x8000u, 0x20fdu, 0x4d1du,\
    \ 0xde4au, 0x0a17u, 0x3464u, 0xe3a9u, 0x6d8du, 0x34bcu, 0xa921u, 0xa173u, 0x0ebcu,\
    \ 0x0e69u};\n  for (int i= pw[0]= pw[65535]= 1; i < 65535; ++i) pw[i]= (pw[i -\
    \ 1] << 1) ^ (0x1681fu & (-(pw[i - 1] >= 0x8000u)));\n  for (int i= 1; i < 65535;\
    \ ln[pw[i]= y]= i, i++)\n   for (x= pw[i], y= 0; x; x&= x - 1) y^= f2n[__builtin_ctz(x)];\n\
    \ }\n Nimber(u64 x_= 0): x(x_) {}\n Nimber &operator+=(const Nimber &r) { return\
    \ x^= r.x, *this; }\n Nimber &operator-=(const Nimber &r) { return x^= r.x, *this;\
    \ }\n Nimber &operator*=(const Nimber &r) { return x= mul(x, r.x), *this; }\n\
    \ Nimber &operator/=(const Nimber &r) { return x= mul(x, inv(r.x)), *this; }\n\
    \ Nimber operator+(const Nimber &r) const { return Nimber(x ^ r.x); }\n Nimber\
    \ operator-(const Nimber &r) const { return Nimber(x ^ r.x); }\n Nimber operator*(const\
    \ Nimber &r) const { return Nimber(mul(x, r.x)); }\n Nimber operator/(const Nimber\
    \ &r) const { return Nimber(mul(x, inv(r.x))); }\n Nimber inv() const { return\
    \ Nimber(inv(x)); }\n Nimber square() const { return Nimber(square(x)); }\n Nimber\
    \ sqrt() const {\n  u16 a0= u16(x), a1= u16(x >> 16), a2= u16(x >> 32), a3= x\
    \ >> 48;\n  return a1^= half(a3 ^ a2), a2^= half(a3), a0^= half(a1) ^ half<6>(a3),\
    \ Nimber((u64(sqrt(a3)) << 48) | (u64(sqrt(a2)) << 32) | (u32(sqrt(a1)) << 16)\
    \ | sqrt(a0));\n }\n u64 val() const { return x; }\n Nimber pow(u64 k) const {\
    \ return Nimber(pow(x, k)); }\n u64 log(const Nimber &r) const { return log(x,\
    \ r.x); }\n bool operator==(const Nimber &r) const { return x == r.x; }\n bool\
    \ operator!=(const Nimber &r) const { return x != r.x; }\n bool operator<(const\
    \ Nimber &r) const { return x < r.x; }\n bool operator>(const Nimber &r) const\
    \ { return x > r.x; }\n bool operator<=(const Nimber &r) const { return x <= r.x;\
    \ }\n bool operator>=(const Nimber &r) const { return x >= r.x; }\n friend std::ostream\
    \ &operator<<(std::ostream &os, const Nimber &r) { return os << r.x; }\n friend\
    \ std::istream &operator>>(std::istream &is, Nimber &r) { return is >> r.x, is;\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Nimber.hpp
  requiredBy: []
  timestamp: '2023-08-06 16:57:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc150_f.RH.Nimber.test.cpp
  - test/unit_test/nimber_inv.test.cpp
  - test/unit_test/nimber_log.test.cpp
  - test/unit_test/nimber_sqrt.test.cpp
  - test/yosupo/nim_product_64.test.cpp
documentation_of: src/Math/Nimber.hpp
layout: document
title: Nimber $\mathbb{F}_{2^{64}}$
---
## 参考
[https://en.wikipedia.org/wiki/Nimber](https://en.wikipedia.org/wiki/Nimber) \
[https://natsugiri.hatenablog.com/entry/2020/03/29/073605](https://natsugiri.hatenablog.com/entry/2020/03/29/073605)
## 問題例
[Codeforces Round #623 (Div. 1, based on VK Cup 2019-2020 - Elimination Round, Engine) F. Bad Cryptography](https://codeforces.com/contest/1314/problem/F) (log) \
[World Tour Finals 2019 Open Contest C2 - Triangular Lamps Hard](https://atcoder.jp/contests/wtf19-open/tasks/wtf19_c2) (log) \
[AtCoder Beginner Contest 274 Ex - XOR Sum of Arrays](https://atcoder.jp/contests/abc274/tasks/abc274_h) (ロリハに乗せる)
