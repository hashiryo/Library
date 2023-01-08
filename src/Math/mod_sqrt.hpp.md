---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/FFT/fps_sqrt.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 sqrt"
  - icon: ':question:'
    path: src/Math/sparse_fps.hpp
    title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc222_h.sparse_FPS.test.cpp
    title: test/atcoder/abc222_h.sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc276_g.sparse_FPS.test.cpp
    title: test/atcoder/abc276_g.sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_sparse_FPS.test.cpp
    title: test/yosupo/exp_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_sparse_FPS.test.cpp
    title: test/yosupo/inv_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_sparse_FPS.test.cpp
    title: test/yosupo/log_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_sparse_FPS.test.cpp
    title: test/yosupo/pow_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_FPS.test.cpp
    title: test/yosupo/sqrt_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_sparse_FPS.test.cpp
    title: test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.sparse_FPS.test.cpp
    title: test/yukicoder/1080.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.test.cpp
    title: test/yukicoder/1080.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1939.test.cpp
    title: test/yukicoder/1939.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/mod_sqrt.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo {\n const u64 mod;\n constexpr\
    \ MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr MP_Mo(u64 m): mod(m), iv(inv(m)),\
    \ r2(-u128(mod) % mod) {}\n constexpr inline u64 mul(u64 l, u64 r) const { return\
    \ reduce(u128(l) * r); }\n#define BOP(op, a) return l op##= a, l+= (mod << 1)\
    \ & -(l >> 63)\n constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod\
    \ << 1)); }\n constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef\
    \ BOP\n constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n constexpr\
    \ inline u64 get(u64 n) const {\n  u64 ret= reduce(n) - mod;\n  return ret + (mod\
    \ & -(ret >> 63));\n }\n constexpr inline u64 norm(u64 n) const { return n - (mod\
    \ & -(n >= mod)); }\nprivate:\n const u64 iv, r2;\n constexpr u64 inv(u64 n, int\
    \ e= 6, u64 x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr\
    \ inline u64 reduce(const u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w)\
    \ * iv) * mod) >> 64); }\n};\ntemplate <class Uint> class MP_Na {\n using DUint=\
    \ conditional_t<is_same_v<Uint, u32>, u64, u128>;\npublic:\n const Uint mod;\n\
    \ constexpr MP_Na(): mod(0){};\n constexpr MP_Na(Uint m): mod(m) {}\n constexpr\
    \ inline Uint mul(Uint l, Uint r) const { return DUint(l) * r % mod; }\n#define\
    \ BOP(m, p) return l m##= mod & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint\
    \ l, Uint r) const { BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r)\
    \ const { BOP(+, -); }\n#undef BOP\n static constexpr inline Uint set(Uint n)\
    \ { return n; }\n static constexpr inline Uint get(Uint n) { return n; }\n static\
    \ constexpr inline Uint norm(Uint n) { return n; }\n};\ntemplate <class Uint,\
    \ class mod_pro_t> constexpr Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n\
    \ for (Uint ret= md.set(1);; x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x)\
    \ : 0; !(k>>= 1)) return ret;\n}\n}\n#line 4 \"src/Math/is_prime.hpp\"\nnamespace\
    \ math_internal {\ntemplate <class Uint, class mod_pro_t, u64... args> constexpr\
    \ bool miller_rabin(Uint n) {\n const mod_pro_t md(n);\n const Uint s= __builtin_ctzll(n\
    \ - 1), d= n >> s, one= md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a:\
    \ {args...}) {\n  Uint b= a % n, p= pow(md.set(b), d, md), i= s;\n  while (p=\
    \ md.norm(p), (p != one && p != n1 && b && i--)) p= md.mul(p, p);\n  if (md.norm(p)\
    \ != n1 && i != s) return 0;\n }\n return true;\n}\nconstexpr bool is_prime(u64\
    \ n) {\n if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n if (n < UINT_MAX)\
    \ return miller_rabin<u32, MP_Na<u32>, 2, 7, 61>(n);\n if (n < LLONG_MAX) return\
    \ miller_rabin<u64, MP_Mo, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    \ return miller_rabin<u64, MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    }\n}\nusing math_internal::is_prime;\n#line 4 \"src/Math/mod_sqrt.hpp\"\nnamespace\
    \ math_internal {\ntemplate <class Int, class mod_pro_t> constexpr int64_t inner_sqrt(Int\
    \ a, Int p) {\n const mod_pro_t md(p);\n Int e= (p - 1) >> 1, one= md.set(1);\n\
    \ if (a= md.set(a); md.norm(pow(a, e, md)) != one) return -1;\n Int b= 0, d= md.diff(0,\
    \ a), ret= one, r2= 0, b2= one;\n while (md.norm(pow(d, e, md)) == one) b= md.plus(b,\
    \ one), d= md.diff(md.mul(b, b), a);\n auto mult= [&md, d](Int &u1, Int &u2, Int\
    \ v1, Int v2) {\n  Int tmp= md.plus(md.mul(u1, v1), md.mul(md.mul(u2, v2), d));\n\
    \  u2= md.plus(md.mul(u1, v2), md.mul(u2, v1)), u1= tmp;\n };\n for (++e;; mult(b,\
    \ b2, b, b2)) {\n  if (e & 1) mult(ret, r2, b, b2);\n  if (!(e>>= 1)) return ret=\
    \ md.get(ret), ret * 2 < p ? ret : p - ret;\n }\n}\nconstexpr int64_t mod_sqrt(int64_t\
    \ a, int64_t p) {\n assert(p > 0), assert(a >= 0), assert(is_prime(p)), a%= p;\n\
    \ if (a <= 1 || p == 2) return a;\n if (p < INT_MAX) return inner_sqrt<u32, MP_Na<u32>>(a,\
    \ p);\n return inner_sqrt<u64, MP_Mo>(a, p);\n}\n}\nusing math_internal::mod_sqrt;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/is_prime.hpp\"\
    \nnamespace math_internal {\ntemplate <class Int, class mod_pro_t> constexpr int64_t\
    \ inner_sqrt(Int a, Int p) {\n const mod_pro_t md(p);\n Int e= (p - 1) >> 1, one=\
    \ md.set(1);\n if (a= md.set(a); md.norm(pow(a, e, md)) != one) return -1;\n Int\
    \ b= 0, d= md.diff(0, a), ret= one, r2= 0, b2= one;\n while (md.norm(pow(d, e,\
    \ md)) == one) b= md.plus(b, one), d= md.diff(md.mul(b, b), a);\n auto mult= [&md,\
    \ d](Int &u1, Int &u2, Int v1, Int v2) {\n  Int tmp= md.plus(md.mul(u1, v1), md.mul(md.mul(u2,\
    \ v2), d));\n  u2= md.plus(md.mul(u1, v2), md.mul(u2, v1)), u1= tmp;\n };\n for\
    \ (++e;; mult(b, b2, b, b2)) {\n  if (e & 1) mult(ret, r2, b, b2);\n  if (!(e>>=\
    \ 1)) return ret= md.get(ret), ret * 2 < p ? ret : p - ret;\n }\n}\nconstexpr\
    \ int64_t mod_sqrt(int64_t a, int64_t p) {\n assert(p > 0), assert(a >= 0), assert(is_prime(p)),\
    \ a%= p;\n if (a <= 1 || p == 2) return a;\n if (p < INT_MAX) return inner_sqrt<u32,\
    \ MP_Na<u32>>(a, p);\n return inner_sqrt<u64, MP_Mo>(a, p);\n}\n}\nusing math_internal::mod_sqrt;"
  dependsOn:
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: false
  path: src/Math/mod_sqrt.hpp
  requiredBy:
  - src/Math/sparse_fps.hpp
  - src/FFT/fps_sqrt.hpp
  timestamp: '2023-01-08 22:12:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1939.test.cpp
  - test/yukicoder/1080.sparse_FPS.test.cpp
  - test/yukicoder/1533.test.cpp
  - test/yukicoder/1080.test.cpp
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/exp_of_sparse_FPS.test.cpp
  - test/yosupo/log_of_sparse_FPS.test.cpp
  - test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - test/yosupo/sqrt_of_FPS.test.cpp
  - test/yosupo/inv_of_sparse_FPS.test.cpp
  - test/yosupo/pow_of_sparse_FPS.test.cpp
  - test/atcoder/abc222_h.sparse_FPS.test.cpp
  - test/atcoder/abc276_g.sparse_FPS.test.cpp
documentation_of: src/Math/mod_sqrt.hpp
layout: document
title: "\u5E73\u65B9\u6839 ($\\mathbb{F}_p$)"
---

## 計算量
 $\mathcal{O} (\log p) $