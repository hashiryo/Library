---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/discrete_logarithm.hpp\"\n#include <numeric>\n\
    #include <cmath>\n#include <vector>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include\
    \ <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y *\
    \ (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-=\
    \ M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r)\
    \ const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U)\
    \ \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE\
    \ MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return\
    \ (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0),\
    \ x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 7 \"\
    src/Math/discrete_logarithm.hpp\"\nint discrete_logarithm(int a, int b, int mod)\
    \ {\n if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b == 1 ? 0 : -1);\n using\
    \ namespace math_internal;\n int cnt= 0;\n for (int g= 0;; ++cnt, b/= g, mod/=\
    \ g, b= u64(b) * mod_inv<int>(a / g, mod) % mod) {\n  if ((b == 1) || (mod ==\
    \ 1)) return cnt;\n  if ((g= gcd(a, mod)) == 1) break;\n  if (b % g != 0) return\
    \ -1;  // no solution\n }\n auto mul= [md= MP_Br(mod)](int &x, int y) { x= md.mul(x,\
    \ y); };\n int baby= 1, size= 1 << __lg(int(sqrt(mod)) + 1), mask= size - 1, vs[size][2];\n\
    \ vector<int> os(size + 1);\n for (int i= 0; i < size; ++i, mul(baby, a)) ++os[baby\
    \ & mask];\n for (int i= 1; i < size; ++i) os[i]+= os[i - 1];\n os[size]= size,\
    \ baby= 1;\n for (int i= 0, j= 0; i < size; ++i, mul(baby, a)) j= --os[baby &\
    \ mask], vs[j][0]= baby, vs[j][1]= i;\n for (int t= 0, iv= mod_inv<int>(baby,\
    \ mod); t < mod; t+= size, mul(b, iv))\n  for (int m= (b & mask), i= os[m + 1];\
    \ i-- > os[m];)\n   if (b == vs[i][0]) return cnt + vs[i][1] + t;\n return -1;\
    \  // no solution\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <cmath>\n#include <vector>\n#include\
    \ \"src/Math/mod_inv.hpp\"\n#include \"src/Internal/Remainder.hpp\"\nint discrete_logarithm(int\
    \ a, int b, int mod) {\n if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b ==\
    \ 1 ? 0 : -1);\n using namespace math_internal;\n int cnt= 0;\n for (int g= 0;;\
    \ ++cnt, b/= g, mod/= g, b= u64(b) * mod_inv<int>(a / g, mod) % mod) {\n  if ((b\
    \ == 1) || (mod == 1)) return cnt;\n  if ((g= gcd(a, mod)) == 1) break;\n  if\
    \ (b % g != 0) return -1;  // no solution\n }\n auto mul= [md= MP_Br(mod)](int\
    \ &x, int y) { x= md.mul(x, y); };\n int baby= 1, size= 1 << __lg(int(sqrt(mod))\
    \ + 1), mask= size - 1, vs[size][2];\n vector<int> os(size + 1);\n for (int i=\
    \ 0; i < size; ++i, mul(baby, a)) ++os[baby & mask];\n for (int i= 1; i < size;\
    \ ++i) os[i]+= os[i - 1];\n os[size]= size, baby= 1;\n for (int i= 0, j= 0; i\
    \ < size; ++i, mul(baby, a)) j= --os[baby & mask], vs[j][0]= baby, vs[j][1]= i;\n\
    \ for (int t= 0, iv= mod_inv<int>(baby, mod); t < mod; t+= size, mul(b, iv))\n\
    \  for (int m= (b & mask), i= os[m + 1]; i-- > os[m];)\n   if (b == vs[i][0])\
    \ return cnt + vs[i][1] + t;\n return -1;  // no solution\n}"
  dependsOn:
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  isVerificationFile: false
  path: src/Math/discrete_logarithm.hpp
  requiredBy: []
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: src/Math/discrete_logarithm.hpp
layout: document
title: "\u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
---
## 計算量
$\mathcal{O} (\sqrt{m})$