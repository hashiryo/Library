---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  - icon: ':x:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':x:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_f
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_f
  bundledCode: "#line 1 \"test/atcoder/abc256_f.SegDual.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\\
    mathbb{Z}$)\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class\
    \ Int>\nconstexpr inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
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
    \ { BOP(+, -); }\n#undef BOP\n  constexpr inline Uint set(Uint n) const { return\
    \ n % mod; }\n  static constexpr inline Uint get(Uint n) { return n; }\n  static\
    \ constexpr inline Uint norm(Uint n) { return n; }\n  constexpr Uint modulo()\
    \ const { return mod; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n\
    \ * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB {\n protected:\n\
    \  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate <class mod_pro_t,\
    \ int id>\nstruct RuntimeB {\n  static inline void set_mod(u64 m) { md = mod_pro_t(m);\
    \ }\n\n protected:\n  static inline mod_pro_t md;\n};\ntemplate <class Int, class\
    \ Uint, class B>\nstruct ModInt : public B {\n  static constexpr inline auto modulo()\
    \ { return B::md.modulo(); }\n  constexpr ModInt() : x(0);\n  constexpr ModInt(const\
    \ ModInt &r) : x(r.x) {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt(T v) : ModInt(v.val()) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T n)\n      : x(B::md.set(n < 0 ? modulo() - ((-n) % modulo())\
    \ : n)) {}\n  constexpr ModInt operator-() const { return ModInt() - *this; }\n\
    #define FUNC(name, op)          \\\n  constexpr ModInt name const { \\\n    ModInt\
    \ ret;                 \\\n    return ret.x = op, ret;     \\\n  }\n  FUNC(operator+(const\
    \ ModInt &r), B::md.plus(x, r.x))\n  FUNC(operator-(const ModInt &r), B::md.diff(x,\
    \ r.x))\n  FUNC(operator*(const ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64\
    \ k), math_internal::pow(x, k, B::md))\n#undef FUNC\n  constexpr ModInt operator/(const\
    \ ModInt &r) const { return *this * r.inv(); }\n  constexpr ModInt &operator+=(const\
    \ ModInt &r) { return *this = *this + r; }\n  constexpr ModInt &operator-=(const\
    \ ModInt &r) { return *this = *this - r; }\n  constexpr ModInt &operator*=(const\
    \ ModInt &r) { return *this = *this * r; }\n  constexpr ModInt &operator/=(const\
    \ ModInt &r) { return *this = *this / r; }\n  constexpr bool operator==(const\
    \ ModInt &r) {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr\
    \ bool operator!=(const ModInt &r) { return !(*this == r); }\n  constexpr bool\
    \ operator<(const ModInt &r) {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
    \  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(), modulo());\
    \ }\n  constexpr inline Uint val() const { return B::md.get(x); }\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &r) {\n    return os << r.val();\n  }\n\
    \  friend istream &operator>>(istream &is, ModInt &r) {\n    long long v;\n  \
    \  return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX, ModInt<int,\
    \ u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD &(MOD < LLONG_MAX),\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Montg, MOD>>,\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>, MOD>>>>;\n\
    class Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt =\
    \ conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\n#line 3 \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \n/**\n * @title Segment-Tree(\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\n\
    struct SegmentTree_Dual {\n  using T = typename M::T;\n  using E = typename M::E;\n\
    \  SegmentTree_Dual() {}\n  SegmentTree_Dual(int n_, T v1 = T())\n      : n(n_),\
    \ height(ceil(log2(n))), val(n, v1), laz(n * 2, {E(), false}) {}\n  SegmentTree_Dual(const\
    \ std::vector<T> &v)\n      : n(v.size()), height(ceil(log2(n))), val(v), laz(n\
    \ * 2, {E(), false}) {}\n  void apply(int a, int b, E x) {\n    a += n, b += n;\n\
    \    for (int i = height; i >= 1; i--)\n      if (((a >> i) << i) != a) eval(a\
    \ >> i);\n    for (int i = height; i >= 1; i--)\n      if (((b >> i) << i) !=\
    \ b) eval((b - 1) >> i);\n    for (int l = a, r = b; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) propagate(l++, x);\n      if (r & 1) propagate(--r, x);\n\
    \    }\n  }\n  void set(int k, T x) {\n    for (int i = height; i; i--) eval((k\
    \ + n) >> i);\n    val[k] = x, laz[k + n].flg = false;\n  }\n  T operator[](const\
    \ int k) {\n    for (int i = height; i; i--) eval((k + n) >> i);\n    if (laz[k\
    \ + n].flg)\n      M::mapping(val[k], laz[k + n].val), laz[k + n].flg = false;\n\
    \    return val[k];\n  }\n\n private:\n  const int n, height;\n  struct Lazy {\n\
    \    E val;\n    bool flg;\n  };\n  std::vector<T> val;\n  std::vector<Lazy> laz;\n\
    \  inline void eval(int k) {\n    if (!laz[k].flg) return;\n    propagate(k <<\
    \ 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n    laz[k].flg = false;\n\
    \  }\n  inline void propagate(int k, const E &x) {\n    laz[k].flg ? (M::composition(laz[k].val,\
    \ x), x) : laz[k].val = x;\n    laz[k].flg = true;\n  }\n};\n#line 6 \"test/atcoder/abc256_f.SegDual.test.cpp\"\
    \nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct Mono {\n\
    \  struct T {\n    Mint val, coef[2];\n    T() = default;\n    T(Mint id, Mint\
    \ v)\n        : val(v), coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n \
    \ };\n  using E = array<Mint, 3>;\n  static void mapping(T &x, const E &mapp)\
    \ {\n    x.val += mapp[0] * x.coef[0] - mapp[1] * x.coef[1] + mapp[2];\n  }\n\
    \  static void composition(E &pre, const E &suf) {\n    pre[0] += suf[0], pre[1]\
    \ += suf[1], pre[2] += suf[2];\n  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  Mint A[N], D[N];\n  for (int i = 0; i < N; i++)\
    \ cin >> A[i], D[i] = A[i];\n  for (int j = 0; j < 3; j++)\n    for (int i = 1;\
    \ i < N; i++) D[i] += D[i - 1];\n  SegmentTree_Dual<Mono> seg(N);\n  for (int\
    \ i = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--) {\n    int op, x;\n\
    \    cin >> op >> x, x--;\n    if (op == 1) {\n      Mint v;\n      cin >> v,\
    \ v -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x, v * x * x / 2});\n \
    \   } else {\n      cout << seg[x].val << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct Mono {\n\
    \  struct T {\n    Mint val, coef[2];\n    T() = default;\n    T(Mint id, Mint\
    \ v)\n        : val(v), coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n \
    \ };\n  using E = array<Mint, 3>;\n  static void mapping(T &x, const E &mapp)\
    \ {\n    x.val += mapp[0] * x.coef[0] - mapp[1] * x.coef[1] + mapp[2];\n  }\n\
    \  static void composition(E &pre, const E &suf) {\n    pre[0] += suf[0], pre[1]\
    \ += suf[1], pre[2] += suf[2];\n  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  Mint A[N], D[N];\n  for (int i = 0; i < N; i++)\
    \ cin >> A[i], D[i] = A[i];\n  for (int j = 0; j < 3; j++)\n    for (int i = 1;\
    \ i < N; i++) D[i] += D[i - 1];\n  SegmentTree_Dual<Mono> seg(N);\n  for (int\
    \ i = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--) {\n    int op, x;\n\
    \    cin >> op >> x, x--;\n    if (op == 1) {\n      Mint v;\n      cin >> v,\
    \ v -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x, v * x * x / 2});\n \
    \   } else {\n      cout << seg[x].val << '\\n';\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: true
  path: test/atcoder/abc256_f.SegDual.test.cpp
  requiredBy: []
  timestamp: '2022-11-16 17:58:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc256_f.SegDual.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256_f.SegDual.test.cpp
- /verify/test/atcoder/abc256_f.SegDual.test.cpp.html
title: test/atcoder/abc256_f.SegDual.test.cpp
---
