---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModIntExp.hpp
    title: "\u6307\u6570\u306B\u4E57\u305B\u3089\u308C\u308BModInt"
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc228/tasks/abc228_e
    links:
    - https://atcoder.jp/contests/abc228/tasks/abc228_e
  bundledCode: "#line 1 \"test/atcoder/abc228_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc228/tasks/abc228_e\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate <class\
    \ Uint, class mod_pro_t, u64... args> constexpr bool miller_rabin(Uint n) {\n\
    \ const mod_pro_t md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one=\
    \ md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...}) {\n  Uint b=\
    \ a % n, p= pow(md.set(b), d, md), i= s;\n  while (p= md.norm(p), (p != one &&\
    \ p != n1 && b && i--)) p= md.mul(p, p);\n  if (md.norm(p) != n1 && i != s) return\
    \ 0;\n }\n return true;\n}\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n\
    \ % 6 % 4 != 1) return (n | 1) == 3;\n if (n < UINT_MAX) return miller_rabin<u32,\
    \ MP_Na<u32>, 2, 7, 61>(n);\n if (n < LLONG_MAX) return miller_rabin<u64, MP_Mo,\
    \ 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64,\
    \ MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing\
    \ math_internal::is_prime;\n#line 4 \"src/Math/Factors.hpp\"\nnamespace math_internal\
    \ {\ntemplate <class T> constexpr void bubble_sort(T *bg, T *ed) {\n for (int\
    \ sz= ed - bg, i= 0; i < sz; i++)\n  for (int j= sz; --j > i;)\n   if (auto tmp=\
    \ bg[j - 1]; bg[j - 1] > bg[j]) bg[j - 1]= bg[j], bg[j]= tmp;\n}\ntemplate <class\
    \ T, size_t _Nm> struct ConstexprArray {\n constexpr size_t size() const { return\
    \ sz; }\n constexpr auto &operator[](int i) const { return dat[i]; }\n constexpr\
    \ auto *begin() const { return dat; }\n constexpr auto *end() const { return dat\
    \ + sz; }\nprotected:\n T dat[_Nm]= {};\n size_t sz= 0;\n};\nclass Factors: public\
    \ ConstexprArray<pair<u64, uint16_t>, 16> {\n template <class Uint, class mod_pro_t>\
    \ static constexpr Uint rho(Uint n, Uint c) {\n  const mod_pro_t md(n);\n  auto\
    \ f= [&md, n, c](Uint x) { return md.plus(md.mul(x, x), c); };\n  const Uint m=\
    \ 1LL << (__lg(n) / 5);\n  Uint x= 1, y= md.set(2), z= 1, q= md.set(1), g= 1;\n\
    \  for (Uint r= 1, i= 0; g == 1; r<<= 1) {\n   for (x= y, i= r; i--;) y= f(y);\n\
    \   for (Uint k= 0; k < r && g == 1; g= gcd(md.get(q), n), k+= m)\n    for (z=\
    \ y, i= min(m, r - k); i--;) y= f(y), q= md.mul(q, md.diff(y, x));\n  }\n  if\
    \ (g == n) do {\n    z= f(z), g= gcd(md.get(md.diff(z, x)), n);\n   } while (g\
    \ == 1);\n  return g;\n }\n static constexpr u64 find_prime_factor(u64 n) {\n\
    \  if (is_prime(n)) return n;\n  for (u64 i= 100; i--;)\n   if (n= n < UINT_MAX\
    \ ? rho<u32, MP_Na<u32>>(n, i + 1) : n < LLONG_MAX ? rho<u64, MP_Mo>(n, i + 1)\
    \ : rho<u64, MP_Na<u64>>(n, i + 1); is_prime(n)) return n;\n  return 0;\n }\n\
    \ constexpr void init(u64 n) {\n  for (u64 p= 2; p < 100 && p * p <= n; p++)\n\
    \   if (n % p == 0)\n    for (dat[sz++].first= p; n % p == 0;) n/= p, dat[sz -\
    \ 1].second++;\n  for (u64 p= 0; n > 1; dat[sz++].first= p)\n   for (p= find_prime_factor(n);\
    \ n % p == 0;) n/= p, dat[sz].second++;\n }\npublic:\n constexpr Factors()= default;\n\
    \ constexpr Factors(u64 n) { init(n), bubble_sort(dat, dat + sz); }\n};\ntemplate\
    \ <class Uint, class mod_pro_t> constexpr Uint inner_primitive_root(Uint p) {\n\
    \ const mod_pro_t md(p);\n const auto f= Factors(p - 1);\n for (Uint ret= 2, one=\
    \ md.set(1), ng= 0;; ret++) {\n  for (auto [q, e]: f)\n   if (ng= (md.norm(pow(md.set(ret),\
    \ (p - 1) / q, md)) == one)) break;\n  if (!ng) return ret;\n }\n}\nconstexpr\
    \ u64 primitive_root(u64 p) {\n if (assert(is_prime(p)); p == 2) return 1;\n if\
    \ (p < UINT_MAX) return inner_primitive_root<u32, MP_Na<u32>>(p);\n if (p < LLONG_MAX)\
    \ return inner_primitive_root<u64, MP_Mo>(p);\n return inner_primitive_root<u64,\
    \ MP_Na<u64>>(p);\n}\n}  // namespace math_internal\nusing math_internal::Factors,\
    \ math_internal::primitive_root;\nconstexpr std::uint64_t totient(const Factors\
    \ &f) {\n std::uint64_t ret= 1, i= 0;\n for (const auto &[p, e]: f)\n  for (ret*=\
    \ p - 1, i= e; --i;) ret*= p;\n return ret;\n}\nconstexpr auto totient(std::uint64_t\
    \ n) { return totient(Factors(n)); }\n#line 4 \"src/Math/ModIntExp.hpp\"\n/**\n\
    \ * @title \u6307\u6570\u306B\u4E57\u305B\u3089\u308C\u308BModInt\n * @category\
    \ \u6570\u5B66\n * @see https://trap.jp/post/1444/\n */\n// verify\u7528:\n\n\
    // BEGIN CUT HERE\ntemplate <std::uint64_t MOD>\nclass ModIntExp {\n  static_assert(MOD\
    \ < 1uLL << 63, \"MOD must be smaller than 2^63\");\n  using Uint = std::conditional_t\
    \ < MOD<UINT_MAX, std::uint32_t, std::uint64_t>;\n  using DUint = std::conditional_t<std::is_same_v<Uint,\
    \ std::uint64_t>,\n                                   __uint128_t, std::uint64_t>;\n\
    \  using mod_t = ModIntExp;\n  static constexpr inline Uint mod(DUint x) {\n \
    \   return x < MOD * 2 ? Uint(x) : Uint(x % MOD) + MOD;\n  }\n  static constexpr\
    \ inline Uint mul(Uint a, Uint b) { return mod(DUint(a) * b); }\n  static constexpr\
    \ inline Uint pow(Uint b, Uint k) {\n    for (Uint ret(1);; b = mul(b, b))\n \
    \     if (k & 1 ? ret = mul(ret, b) : 0; !(k >>= 1)) return ret;\n  }\n  static\
    \ constexpr inline std::uint64_t f(std::uint64_t x) {\n    std::uint64_t ret =\
    \ 1, i = 0, tmp = 1;\n    for (const auto &[p, e] : Factors(x)) {\n      for (tmp\
    \ = p - 1, i = e - (p == 2 && e > 3); --i;) tmp *= p;\n      ret = std::lcm(ret,\
    \ tmp);\n    }\n    return ret;\n  }\n\n public:\n  Uint a;\n  ModIntExp<f(MOD)>\
    \ b;\n  constexpr ModIntExp() = default;\n  constexpr ModIntExp(std::uint64_t\
    \ x) : a(mod(x)), b(x) {}\n  constexpr ModIntExp(Uint a_, ModIntExp<f(MOD)> b_)\
    \ : a(a_), b(b_) {}\n  constexpr Uint val() const { return a < MOD ? a : a - MOD;\
    \ }\n  constexpr mod_t &operator*=(const mod_t &r) {\n    return a = mul(a, r.a),\
    \ b *= r.b, *this;\n  }\n  constexpr mod_t &operator+=(const mod_t &r) {\n   \
    \ return a -= MOD & -((a += r.a) >= MOD * 2), b += r.b, *this;\n  }\n  constexpr\
    \ mod_t operator*(const mod_t &r) const { return mod_t(*this) *= r; }\n  constexpr\
    \ mod_t operator+(const mod_t &r) const { return mod_t(*this) += r; }\n  constexpr\
    \ mod_t pow(const mod_t &r) const {\n    return mod_t{pow(a, r.b.a), b.pow(r.b)};\n\
    \  };\n};\ntemplate <>\nstruct ModIntExp<1> {\n  using mod_t = ModIntExp;\n  bool\
    \ a;\n  constexpr ModIntExp() : a(0) {}\n  constexpr ModIntExp(std::uint64_t x)\
    \ : a(x) {}\n  constexpr std::uint32_t val() { return 0; }\n  constexpr mod_t\
    \ &operator*=(const mod_t &r) { return a &= r.a, *this; }\n  constexpr mod_t &operator+=(const\
    \ mod_t &r) { return a |= r.a, *this; }\n  constexpr mod_t operator*(const mod_t\
    \ &r) const { return mod_t(*this) *= r; }\n  constexpr mod_t operator+(const mod_t\
    \ &r) const { return mod_t(*this) += r; }\n  constexpr mod_t pow(const mod_t &r)\
    \ const { return {a || !r.a}; };\n};\ntemplate <std::uint64_t MOD>\nstd::ostream\
    \ &operator<<(std::ostream &os, const ModIntExp<MOD> &r) {\n  return os << r.val();\n\
    }\ntemplate <std::uint64_t MOD>\nstd::istream &operator>>(std::istream &is, ModIntExp<MOD>\
    \ &r) {\n  std::uint64_t v;\n  return is >> v, r = ModIntExp<MOD>(v), is;\n}\n\
    #line 4 \"test/atcoder/abc228_e.test.cpp\"\nusing namespace std;\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint = ModIntExp<998244353>;\n\
    \  Mint n, k, m;\n  cin >> n >> k >> m;\n  cout << m.pow(k.pow(n)) << endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc228/tasks/abc228_e\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModIntExp.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint\
    \ = ModIntExp<998244353>;\n  Mint n, k, m;\n  cin >> n >> k >> m;\n  cout << m.pow(k.pow(n))\
    \ << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/ModIntExp.hpp
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/atcoder/abc228_e.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 19:53:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc228_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc228_e.test.cpp
- /verify/test/atcoder/abc228_e.test.cpp.html
title: test/atcoder/abc228_e.test.cpp
---
