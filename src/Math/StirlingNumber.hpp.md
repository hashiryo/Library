---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_1_small_p_large_n.test.cpp
    title: test/yosupo/stirling_1_small_p_large_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_2_small_p_large_n.test.cpp
    title: test/yosupo/stirling_2_small_p_large_n.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/StirlingNumber.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE\
    \ constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n\
    \ return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+=\
    \ r; l >= M) l-= M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U\
    \ diff(U l, U r) const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n\
    \ }\n#define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static CE\
    \ IL U get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate\
    \ <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
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
    \ CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m\
    \ - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64\
    \ quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const\
    \ { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64\
    \ mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) <<\
    \ 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n\
    \ PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n)\
    \ { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n)\
    \ const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return\
    \ (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) *\
    \ mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0),\
    \ mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m\
    \ << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
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
    }\n}\nusing math_internal::is_prime;\n#line 6 \"src/Math/StirlingNumber.hpp\"\n\
    class StirlingNumber {\n const uint16_t p;\n std::vector<std::vector<uint16_t>>\
    \ c, s1, s2;\n void buildS1() {\n  s1.resize(p), s1[0]= {1};\n  for (int i= 1,\
    \ j, t; i < p; s1[i][i]= 1, i++)\n   for (s1[i].resize(i + 1, 0), j= 1, t= p -\
    \ i + 1; j < i; j++) s1[i][j]= (t * s1[i - 1][j] + s1[i - 1][j - 1]) % p;\n }\n\
    \ void buildS2() {\n  s2.resize(p), s2[0]= {1};\n  for (int i= 1, j; i < p; s2[i][i]=\
    \ 1, i++)\n   for (s2[i].resize(i + 1, 0), j= 1; j < i; j++) s2[i][j]= (j * s2[i\
    \ - 1][j] + s2[i - 1][j - 1]) % p;\n }\npublic:\n StirlingNumber(uint32_t p_,\
    \ bool first= true, bool second= true): p(p_), c(p) {\n  assert(is_prime(p_)),\
    \ assert(p_ < (1 << 15)), c[0]= {1};\n  for (int i= 1, j; i < p; i++)\n   for\
    \ (c[i]= c[i - 1], c[i].emplace_back(0), j= 1; j <= i; j++) c[i][j]-= p & -((c[i][j]+=\
    \ c[i - 1][j - 1]) >= p);\n  if (first) buildS1();\n  if (second) buildS2();\n\
    \ }\n int nCk(uint64_t n, uint64_t k) {\n  if (k > n) return 0;\n  int ret= 1,\
    \ i, j;\n  for (k= std::min(k, n - k); k; ret= ret * c[i][j] % p, n/= p, k/= p)\n\
    \   if (i= n % p, j= k % p; j > i) return 0;\n  return ret;\n }\n int S1(uint64_t\
    \ n, uint64_t k) {\n  if (k > n) return 0;\n  uint64_t i= n / p;\n  if (i > k)\
    \ return 0;\n  int64_t a= (k - i) / (p - 1);\n  uint16_t j= n % p, b= (k - i)\
    \ % (p - 1);\n  if (!b && j) b+= (p - 1), a-= 1;\n  if (a < 0 || i < a || b >\
    \ j) return 0;\n  return (j= nCk(i, a) * s1[j][b] % p) && ((i + a) & 1) ? p -\
    \ j : j;\n }\n int S2(uint64_t n, uint64_t k) {\n  if (k > n) return 0;\n  if\
    \ (!n) return 1;\n  uint64_t i= k / p;\n  if (n <= i) return 0;\n  uint64_t a=\
    \ (n - i - 1) / (p - 1);\n  uint16_t j= k % p, b= (n - i) - a * (p - 1);\n  if\
    \ (j > b) return 0;\n  return b == p - 1 && !j ? nCk(a, i - 1) : nCk(a, i) * s2[b][j]\
    \ % p;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include \"src/Math/is_prime.hpp\"\nclass StirlingNumber {\n const uint16_t p;\n\
    \ std::vector<std::vector<uint16_t>> c, s1, s2;\n void buildS1() {\n  s1.resize(p),\
    \ s1[0]= {1};\n  for (int i= 1, j, t; i < p; s1[i][i]= 1, i++)\n   for (s1[i].resize(i\
    \ + 1, 0), j= 1, t= p - i + 1; j < i; j++) s1[i][j]= (t * s1[i - 1][j] + s1[i\
    \ - 1][j - 1]) % p;\n }\n void buildS2() {\n  s2.resize(p), s2[0]= {1};\n  for\
    \ (int i= 1, j; i < p; s2[i][i]= 1, i++)\n   for (s2[i].resize(i + 1, 0), j= 1;\
    \ j < i; j++) s2[i][j]= (j * s2[i - 1][j] + s2[i - 1][j - 1]) % p;\n }\npublic:\n\
    \ StirlingNumber(uint32_t p_, bool first= true, bool second= true): p(p_), c(p)\
    \ {\n  assert(is_prime(p_)), assert(p_ < (1 << 15)), c[0]= {1};\n  for (int i=\
    \ 1, j; i < p; i++)\n   for (c[i]= c[i - 1], c[i].emplace_back(0), j= 1; j <=\
    \ i; j++) c[i][j]-= p & -((c[i][j]+= c[i - 1][j - 1]) >= p);\n  if (first) buildS1();\n\
    \  if (second) buildS2();\n }\n int nCk(uint64_t n, uint64_t k) {\n  if (k > n)\
    \ return 0;\n  int ret= 1, i, j;\n  for (k= std::min(k, n - k); k; ret= ret *\
    \ c[i][j] % p, n/= p, k/= p)\n   if (i= n % p, j= k % p; j > i) return 0;\n  return\
    \ ret;\n }\n int S1(uint64_t n, uint64_t k) {\n  if (k > n) return 0;\n  uint64_t\
    \ i= n / p;\n  if (i > k) return 0;\n  int64_t a= (k - i) / (p - 1);\n  uint16_t\
    \ j= n % p, b= (k - i) % (p - 1);\n  if (!b && j) b+= (p - 1), a-= 1;\n  if (a\
    \ < 0 || i < a || b > j) return 0;\n  return (j= nCk(i, a) * s1[j][b] % p) &&\
    \ ((i + a) & 1) ? p - j : j;\n }\n int S2(uint64_t n, uint64_t k) {\n  if (k >\
    \ n) return 0;\n  if (!n) return 1;\n  uint64_t i= k / p;\n  if (n <= i) return\
    \ 0;\n  uint64_t a= (n - i - 1) / (p - 1);\n  uint16_t j= k % p, b= (n - i) -\
    \ a * (p - 1);\n  if (j > b) return 0;\n  return b == p - 1 && !j ? nCk(a, i -\
    \ 1) : nCk(a, i) * s2[b][j] % p;\n }\n};"
  dependsOn:
  - src/Math/is_prime.hpp
  - src/Internal/Remainder.hpp
  isVerificationFile: false
  path: src/Math/StirlingNumber.hpp
  requiredBy: []
  timestamp: '2023-08-05 22:03:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_2_small_p_large_n.test.cpp
  - test/yosupo/stirling_1_small_p_large_n.test.cpp
documentation_of: src/Math/StirlingNumber.hpp
layout: document
title: "\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 ($\\mathbb{F}_p$)"
---
## 計算量
前処理 $\mathcal{O}(p^2)$, クエリ $\mathcal{O}(\log n)$
## 参考
[https://maspypy.com/stirling-数を-p-で割った余りの計算](https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97)