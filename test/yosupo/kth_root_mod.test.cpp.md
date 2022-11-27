---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':x:'
    path: src/Math/mod_kth_root.hpp
    title: "k\u4E57\u6839 ($\\mathbb{F}_p$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_mod
    links:
    - https://judge.yosupo.jp/problem/kth_root_mod
  bundledCode: "#line 1 \"test/yosupo/kth_root_mod.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/kth_root_mod\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr\
    \ inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
    \  Int x = 1, y = 0, b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x,\
    \ c = a, x = y, y = z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a\
    \ == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\
    \n/**\n * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category\
    \ \u6570\u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN\
    \ CUT HERE\nnamespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing u128 = __uint128_t;\nclass MIntPro_Montg {\n  u64\
    \ mod, iv, r2;\n  constexpr u64 inv(u64 n, int e = 6, u64 x = 1) {\n    return\
    \ e ? inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n  constexpr inline u64 reduce(const\
    \ u128 &w) const {\n    return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod)\
    \ >> 64);\n  }\n\n public:\n  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0)\
    \ {}\n  constexpr MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod)\
    \ {}\n  constexpr inline u64 mul(u64 l, u64 r) const { return reduce(u128(l) *\
    \ r); }\n#define BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n\
    \  constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n\
    \  constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n\
    \  constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline\
    \ u64 get(u64 n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n -\
    \ (mod & -(n >= mod)); }\n  constexpr u64 modulo() const { return mod; }\n};\n\
    template <class Uint>\nclass MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\n  Uint mod;\n\n public:\n  constexpr MIntPro_Na() : mod(0){};\n\
    \  constexpr MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint\
    \ l, Uint r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l\
    \ m## = mod & -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint\
    \ r) const { BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const\
    \ { BOP(+, -); }\n#undef BOP\n  constexpr inline Uint set(u64 n) const { return\
    \ n % mod; }\n  static constexpr inline Uint get(Uint n) { return n; }\n  static\
    \ constexpr inline Uint norm(Uint n) { return n; }\n  constexpr Uint modulo()\
    \ const { return mod; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 4 \"src/Math/is_prime.hpp\"\n\
    /**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category \u6570\u5B66\n *  O(log\
    \ N)\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\ntemplate <class Uint,\
    \ class mod_pro_t, u64... args>\nconstexpr bool miller_rabin(Uint n) {\n  const\
    \ mod_pro_t md(n);\n  const Uint s = __builtin_ctzll(n - 1), d = n >> s, one =\
    \ md.set(1),\n             n1 = md.norm(md.set(n - 1));\n  for (auto a : {args...})\
    \ {\n    Uint b = a % n, p = pow(md.set(b), d, md), i = s;\n    while (p = md.norm(p),\
    \ (p != one && p != n1 && b && i--)) p = md.mul(p, p);\n    if (md.norm(p) !=\
    \ n1 && i != s) return false;\n  }\n  return true;\n}\nconstexpr bool is_prime(u64\
    \ n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX)\
    \ return miller_rabin<u32, MIntPro_Na<u32>, 2, 7, 61>(n);\n  if (n < LLONG_MAX)\n\
    \    return miller_rabin<u64, MIntPro_Montg, 2, 325, 9375, 28178, 450775,\n  \
    \                      9780504, 1795265022>(n);\n  return miller_rabin<u64, MIntPro_Na<u64>,\
    \ 2, 325, 9375, 28178, 450775,\n                      9780504, 1795265022>(n);\n\
    }\n}  // namespace math_internal\nusing math_internal::is_prime;\n#line 4 \"src/Math/Factors.hpp\"\
    \n/**\n * @title \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069\n * @category\
    \ \u6570\u5B66\n *  O(N^(1/4))\n */\n\n// BEGIN CUT HERE\nnamespace math_internal\
    \ {\ntemplate <class T>\nconstexpr void bubble_sort(T *bg, T *ed) {\n  for (int\
    \ sz = ed - bg, i = 0; i < sz; i++)\n    for (int j = sz; --j > i;)\n      if\
    \ (auto tmp = bg[j - 1]; bg[j - 1] > bg[j])\n        bg[j - 1] = bg[j], bg[j]\
    \ = tmp;\n}\ntemplate <class T, size_t _Nm>\nstruct ConstexprArray {\n  constexpr\
    \ size_t size() const { return sz; }\n  constexpr auto &operator[](int i) const\
    \ { return dat[i]; }\n  constexpr auto *begin() const { return dat; }\n  constexpr\
    \ auto *end() const { return dat + sz; }\n\n protected:\n  T dat[_Nm] = {};\n\
    \  size_t sz = 0;\n};\nclass Factors : public ConstexprArray<pair<u64, uint16_t>,\
    \ 16> {\n  template <class Uint, class mod_pro_t>\n  static constexpr Uint rho(Uint\
    \ n, Uint c) {\n    const mod_pro_t md(n);\n    auto f = [&md, n, c](Uint x) {\
    \ return md.plus(md.mul(x, x), c); };\n    const Uint m = 1LL << (__lg(n) / 5);\n\
    \    Uint x = 1, y = md.set(2), z = 1, q = md.set(1), g = 1;\n    for (Uint r\
    \ = 1, i = 0; g == 1; r <<= 1) {\n      for (x = y, i = r; i--;) y = f(y);\n \
    \     for (Uint k = 0; k < r && g == 1; g = gcd(md.get(q), n), k += m)\n     \
    \   for (z = y, i = min(m, r - k); i--;)\n          y = f(y), q = md.mul(q, md.diff(y,\
    \ x));\n    }\n    if (g == n) do {\n        z = f(z), g = gcd(md.get(md.diff(z,\
    \ x)), n);\n      } while (g == 1);\n    return g;\n  }\n  static constexpr u64\
    \ find_prime_factor(u64 n) {\n    if (is_prime(n)) return n;\n    for (u64 i =\
    \ 100; i--;)\n      if (n = n < UINT_MAX    ? rho<u32, MIntPro_Na<u32>>(n, i +\
    \ 1)\n              : n < LLONG_MAX ? rho<u64, MIntPro_Montg>(n, i + 1)\n    \
    \                          : rho<u64, MIntPro_Na<u64>>(n, i + 1);\n          is_prime(n))\n\
    \        return n;\n    return 0;\n  }\n  constexpr void init(u64 n) {\n    for\
    \ (u64 p = 2; p < 100 && p * p <= n; p++)\n      if (n % p == 0)\n        for\
    \ (dat[sz++].first = p; n % p == 0;) n /= p, dat[sz - 1].second++;\n    for (u64\
    \ p = 0; n > 1; dat[sz++].first = p)\n      for (p = find_prime_factor(n); n %\
    \ p == 0;) n /= p, dat[sz].second++;\n  }\n\n public:\n  constexpr Factors() =\
    \ default;\n  constexpr Factors(u64 n) { init(n), bubble_sort(dat, dat + sz);\
    \ }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr Uint inner_primitive_root(Uint\
    \ p) {\n  const mod_pro_t md(p);\n  const auto f = Factors(p - 1);\n  for (Uint\
    \ ret = 2, one = md.set(1), pw = 0, x = 0, k = 0, ng = 0;; ret++) {\n    for (auto\
    \ [q, e] : f)\n      if (ng = (md.norm(pow(md.set(ret), (p - 1) / q, md)) == one))\
    \ break;\n    if (!ng) return ret;\n  }\n}\nconstexpr u64 primitive_root(u64 p)\
    \ {\n  if (assert(is_prime(p)); p == 2) return 1;\n  if (p < UINT_MAX) return\
    \ inner_primitive_root<u32, MIntPro_Na<u32>>(p);\n  if (p < LLONG_MAX) return\
    \ inner_primitive_root<u64, MIntPro_Montg>(p);\n  return inner_primitive_root<u64,\
    \ MIntPro_Na<u64>>(p);\n}\n}  // namespace math_internal\nusing math_internal::Factors,\
    \ math_internal::primitive_root;\nconstexpr std::uint64_t totient(const Factors\
    \ &f) {\n  std::uint64_t ret = 1, i = 0;\n  for (const auto &[p, e] : f)\n   \
    \ for (ret *= p - 1, i = e; --i;) ret *= p;\n  return ret;\n}\nconstexpr auto\
    \ totient(std::uint64_t n) { return totient(Factors(n)); }\n#line 5 \"src/Math/mod_kth_root.hpp\"\
    \n/**\n * @title k\u4E57\u6839 ($\\mathbb{F}_p$)\n * @category \u6570\u5B66\n\
    \ * O( min(k,p)^(1/4) )\n * @see https://nyaannyaan.github.io/library/modulo/mod-kth-root.hpp\n\
    \ */\n\n// verify\u7528\n// https://yukicoder.me/problems/no/981 (\u53B3\u3057\
    \u3044\u5236\u7D04\u306E\u30B1\u30FC\u30B9\u3042\u308A, sp judge)\n\n// BEGIN\
    \ CUT HERE\nnamespace math_internal {\ntemplate <class Int, class mod_pro_t>\n\
    constexpr inline Int peth_root(Int c, Int pi, int ei, const mod_pro_t &md) {\n\
    \  const Int p = md.modulo();\n  int t = 0;\n  Int s = p - 1, pe = 1;\n  while\
    \ (s % pi == 0) s /= pi, ++t;\n  for (int i = ei; i--;) pe *= pi;\n  Int u = mod_inv(pe\
    \ - s % pe, pe), ONE = md.set(1),\n      z = pow(c, (s * u + 1) / pe, md), zpe\
    \ = md.norm(pow(c, s * u, md));\n  if (zpe == ONE) return z;\n  Int ptm1 = 1,\
    \ vs = 0, bs = 0;\n  for (int i = t; --i;) ptm1 *= pi;\n  for (Int v = md.set(2);;\
    \ v = md.plus(v, ONE))\n    if (vs = pow(v, s, md), bs = md.norm(pow(vs, ptm1,\
    \ md)); bs != ONE) break;\n  int size = 1 << __lg(int(sqrt(pi)) + 1), mask = size\
    \ - 1, os[size + 1] = {},\n      vsc[size] = {};\n  Int vf[size] = {};\n  Int\
    \ x = ONE, vspe = pow(vs, pe, md);\n  for (int i = 0; i < size; i++, x = md.mul(x,\
    \ bs)) os[md.norm(x) & mask]++;\n  for (int i = 1; i < size; i++) os[i] += os[i\
    \ - 1];\n  x = ONE, os[size] = size;\n  for (int i = 0, j = 0; i < size; i++,\
    \ x = md.mul(x, bs))\n    vf[j = --os[md.norm(x) & mask]] = md.norm(x), vsc[j]\
    \ = i;\n  for (int vs_e = ei, td = 0, n = 0; zpe != ONE; z = md.mul(z, pow(vs,\
    \ n, md)),\n           zpe = md.norm(md.mul(zpe, pow(vspe, n, md)))) {\n    for\
    \ (u = zpe, td = 0; u != ONE; td++) u = md.norm(pow(bs = u, pi, md));\n    for\
    \ (int e = t - td; vs_e != e; vs_e++)\n      vs = pow(vs, pi, md), vspe = pow(vspe,\
    \ pi, md);\n    for (int tt = 0, upd = 1; upd; tt += size, bs = md.mul(bs, x))\n\
    \      for (int m = (md.norm(bs) & mask), i = os[m]; i < os[m + 1]; i++)\n   \
    \     if (md.norm(bs) == vf[i]) {\n          if (upd = false, n = tt - vsc[i];\
    \ n < 0) n += pi;\n          break;\n        }\n  }\n  return z;\n}\ntemplate\
    \ <class Int, class mod_pro_t>\nconstexpr Int inner_kth_root(Int a, u64 k, Int\
    \ p) {\n  if (k == 0) return a == 1 ? a : -1;\n  if (a <= 1 || k <= 1) return\
    \ a;\n  const mod_pro_t md(p);\n  Int g = gcd(k, p - 1), pp = (p - 1) / g, kk\
    \ = (k / g) % pp;\n  if (a = md.set(a); md.norm(pow(a, pp, md)) != md.set(1))\
    \ return -1;\n  a = pow(a, mod_inv(kk, pp), md);\n  for (auto [pi, ei] : Factors(g))\
    \ a = peth_root<Int>(a, pi, ei, md);\n  return md.get(a);\n}\nconstexpr int64_t\
    \ mod_kth_root(int64_t a, u64 k, int64_t p) {\n  assert(p > 0), assert(a > 0),\
    \ assert(is_prime(p)), a %= p;\n  if (p < INT_MAX) return inner_kth_root<int,\
    \ MIntPro_Na<u32>>(a, k, p);\n  return inner_kth_root<int64_t, MIntPro_Montg>(a,\
    \ k, p);\n}\n}  // namespace math_internal\nusing math_internal::mod_kth_root;\n\
    #line 4 \"test/yosupo/kth_root_mod.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int T;\n  cin >> T;\n  while\
    \ (T--) {\n    int K, Y, P;\n    cin >> K >> Y >> P;\n    cout << mod_kth_root(Y,\
    \ K, P) << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/mod_kth_root.hpp\"\nusing namespace std;\n\
    \nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int T;\n  cin\
    \ >> T;\n  while (T--) {\n    int K, Y, P;\n    cin >> K >> Y >> P;\n    cout\
    \ << mod_kth_root(Y, K, P) << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/mod_kth_root.hpp
  - src/Math/mod_inv.hpp
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/kth_root_mod.test.cpp
  requiredBy: []
  timestamp: '2022-11-27 21:09:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/kth_root_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_root_mod.test.cpp
- /verify/test/yosupo/kth_root_mod.test.cpp.html
title: test/yosupo/kth_root_mod.test.cpp
---
