---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':x:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primitive_root
    links:
    - https://judge.yosupo.jp/problem/primitive_root
  bundledCode: "#line 1 \"test/yosupo/primitive_root.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/primitive_root\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n\
    #define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n\
    \ CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n  return\
    \ l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { \\\n  if\
    \ (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n static CE\
    \ IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\n\
    \ static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n const u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n const u_t iv, r2;\n CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n const u32 mod;\n CE MP_Na(): mod(0){};\n\
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
    \ PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 4 \"src/Math/is_prime.hpp\"\
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
    }\n}\nusing math_internal::is_prime;\n#line 4 \"src/Math/Factors.hpp\"\nnamespace\
    \ math_internal {\ntemplate <class T> constexpr void bubble_sort(T *bg, T *ed)\
    \ {\n for (int sz= ed - bg, i= 0; i < sz; i++)\n  for (int j= sz; --j > i;)\n\
    \   if (auto tmp= bg[j - 1]; bg[j - 1] > bg[j]) bg[j - 1]= bg[j], bg[j]= tmp;\n\
    }\ntemplate <class T, size_t _Nm> struct ConstexprArray {\n constexpr size_t size()\
    \ const { return sz; }\n constexpr auto &operator[](int i) const { return dat[i];\
    \ }\n constexpr auto *begin() const { return dat; }\n constexpr auto *end() const\
    \ { return dat + sz; }\nprotected:\n T dat[_Nm]= {};\n size_t sz= 0;\n};\nclass\
    \ Factors: public ConstexprArray<pair<u64, uint16_t>, 16> {\n template <class\
    \ Uint, class MP> static constexpr Uint rho(Uint n, Uint c) {\n  const MP md(n);\n\
    \  auto f= [&md, n, c](Uint x) { return md.plus(md.mul(x, x), c); };\n  const\
    \ Uint m= 1LL << (__lg(n) / 5);\n  Uint x= 1, y= md.set(2), z= 1, q= md.set(1),\
    \ g= 1;\n  for (Uint r= 1, i= 0; g == 1; r<<= 1) {\n   for (x= y, i= r; i--;)\
    \ y= f(y);\n   for (Uint k= 0; k < r && g == 1; g= gcd(md.get(q), n), k+= m)\n\
    \    for (z= y, i= min(m, r - k); i--;) y= f(y), q= md.mul(q, md.diff(y, x));\n\
    \  }\n  if (g == n) do {\n    z= f(z), g= gcd(md.get(md.diff(z, x)), n);\n   }\
    \ while (g == 1);\n  return g;\n }\n static constexpr u64 find_prime_factor(u64\
    \ n) {\n  if (is_prime(n)) return n;\n  for (u64 i= 100; i--;)\n   if (n= n <\
    \ (1 << 30) ? rho<u32, MP_Mo<u32, u64, 32, 31>>(n, i + 1) : n < (1ull << 62) ?\
    \ rho<u64, MP_Mo<u64, u128, 64, 63>>(n, i + 1) : rho<u64, MP_D2B1>(n, i + 1);\
    \ is_prime(n)) return n;\n  return 0;\n }\n constexpr void init(u64 n) {\n  for\
    \ (u64 p= 2; p < 100 && p * p <= n; p++)\n   if (n % p == 0)\n    for (dat[sz++].first=\
    \ p; n % p == 0;) n/= p, dat[sz - 1].second++;\n  for (u64 p= 0; n > 1; dat[sz++].first=\
    \ p)\n   for (p= find_prime_factor(n); n % p == 0;) n/= p, dat[sz].second++;\n\
    \ }\npublic:\n constexpr Factors()= default;\n constexpr Factors(u64 n) { init(n),\
    \ bubble_sort(dat, dat + sz); }\n};\ntemplate <class Uint, class MP> constexpr\
    \ Uint inner_primitive_root(Uint p) {\n const MP md(p);\n const auto f= Factors(p\
    \ - 1);\n for (Uint ret= 2, one= md.set(1), ng= 0;; ret++) {\n  for (const auto\
    \ [q, e]: f)\n   if (ng= (md.norm(pow(md.set(ret), (p - 1) / q, md)) == one))\
    \ break;\n  if (!ng) return ret;\n }\n}\nconstexpr u64 primitive_root(u64 p) {\n\
    \ if (assert(is_prime(p)); p == 2) return 1;\n if (p < (1 << 30)) return inner_primitive_root<u32,\
    \ MP_Mo<u32, u64, 32, 31>>(p);\n if (p < (1ull << 62)) return inner_primitive_root<u64,\
    \ MP_Mo<u64, u128, 64, 63>>(p);\n return inner_primitive_root<u64, MP_D2B1>(p);\n\
    }\n}  // namespace math_internal\nusing math_internal::Factors, math_internal::primitive_root;\n\
    constexpr std::uint64_t totient(const Factors &f) {\n std::uint64_t ret= 1, i=\
    \ 0;\n for (const auto [p, e]: f)\n  for (ret*= p - 1, i= e; --i;) ret*= p;\n\
    \ return ret;\n}\nconstexpr auto totient(std::uint64_t n) { return totient(Factors(n));\
    \ }\n#line 4 \"test/yosupo/primitive_root.test.cpp\"\nusing namespace std;\n\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int Q;\n  cin\
    \ >> Q;\n  while (Q--) {\n    long long p;\n    cin >> p;\n    cout << primitive_root(p)\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/Factors.hpp\"\nusing namespace std;\n\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int Q;\n  cin\
    \ >> Q;\n  while (Q--) {\n    long long p;\n    cin >> p;\n    cout << primitive_root(p)\
    \ << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  - src/Internal/Remainder.hpp
  isVerificationFile: true
  path: test/yosupo/primitive_root.test.cpp
  requiredBy: []
  timestamp: '2023-01-13 21:45:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/primitive_root.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/primitive_root.test.cpp
- /verify/test/yosupo/primitive_root.test.cpp.html
title: test/yosupo/primitive_root.test.cpp
---
