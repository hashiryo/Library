---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree.hpp
    title: Segment-Tree
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SegmentTree.hpp\"\n/**\n\
    \ * @title Segment-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n\
    \ * 2\u51AA\u306B\u3057\u3066\u3044\u306A\u3044(\u30E1\u30E2\u30EA\u7BC0\u7D04\
    )\n */\n\n// 2\u51AA\u306B\u3059\u308B\u306E\u3084\u3081\u3066\u4E8C\u6B21\u5143\
    array(10x10)\u3092\u306E\u305B\u308B\u3053\u3068\u306B\u6210\u529F\n// https://atcoder.jp/contests/arc027/tasks/arc027_4\n\
    \n// find_left, find_right verify\n// https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree {\n  using T\
    \ = typename M::T;\n  SegmentTree() {}\n  SegmentTree(int n_) : n(n_), dat(n <<\
    \ 1, M::ti()) {}\n  SegmentTree(int n_, T v) : n(n_), dat(n << 1, M::ti()) {\n\
    \    for (int i = n; i--;) dat[i + n] = v;\n    rebuild();\n  }\n  SegmentTree(const\
    \ std::vector<T> &v) : n(v.size()), dat(n << 1, M::ti()) {\n    for (int i = n;\
    \ i--;) dat[i + n] = v[i];\n    rebuild();\n  }\n  void set(int k, T x) {\n  \
    \  for (dat[k += n] = x; k >>= 1;)\n      dat[k] = M::op(dat[(k << 1) | 0], dat[(k\
    \ << 1) | 1]);\n  }\n  void unsafe_set(int k, T x) { dat[k + n] = x; }\n  void\
    \ rebuild() {\n    for (int i = n; --i;) dat[i] = M::op(dat[i << 1 | 0], dat[i\
    \ << 1 | 1]);\n  }\n  void clear() { fill(dat.begin(), dat.end(), M::ti()); }\n\
    \  inline T fold(int l, int r) const {  //[l,r)\n    T vl = M::ti(), vr = M::ti();\n\
    \    for (int a = l + n, b = r + n; a < b; a >>= 1, b >>= 1) {\n      if (a &\
    \ 1) vl = M::op(vl, dat[a++]);\n      if (b & 1) vr = M::op(dat[--b], vr);\n \
    \   }\n    return M::op(vl, vr);\n  }\n  T operator[](const int &k) const { return\
    \ dat[k + n]; }\n  template <bool last>\n  static inline T calc_op(const T &v,\
    \ const T &d) {\n    if constexpr (last)\n      return M::op(d, v);\n    else\n\
    \      return M::op(v, d);\n  }\n  // Case 0. find i s.t check(fold(k,i)) == False,\
    \ check(fold(k,i+1)) == True\n  // Case 1. find i s.t check(fold(i+1,b)) == False,\
    \ check(fold(i,b)) == True\n  // return -1 if not found\n  template <bool last,\
    \ class C>\n  int find(const C &check, int k) const {\n    assert(!check(M::ti()));\n\
    \    std::vector<int> id[2];\n    int a = n + (k & -(!last)), b = n + n + ((k\
    \ - n) & -(last));\n    for (; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) id[0].push_back(a++);\n\
    \      if (b & 1) id[1].push_back(--b);\n    }\n    id[last].insert(id[last].end(),\
    \ id[!last].rbegin(), id[!last].rend());\n    T val = M::ti();\n    for (int i\
    \ : id[last]) {\n      if (T tmp = calc_op<last>(val, dat[i]); check(tmp)) {\n\
    \        while (i < n)\n          if (tmp = calc_op<last>(val, dat[i = i << 1\
    \ | last]); !check(tmp))\n            val = tmp, i -= last * 2 - 1;\n        return\
    \ i - n + last;\n      } else\n        val = tmp;\n    }\n    return -1;\n  }\n\
    \n private:\n  const int n;\n  std::vector<T> dat;\n};\n#line 3 \"src/Math/mod_inv.hpp\"\
    \n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\
    \u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0,\
    \ b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y =\
    \ z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ?\
    \ mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n\
    \ * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category \u6570\
    \u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\n\
    namespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\nclass MIntPro_Montg {\n  u64 mod,\
    \ iv, r2;\n  constexpr u64 inv(u64 n, int e = 6, u64 x = 1) {\n    return e ?\
    \ inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n  constexpr inline u64 reduce(const\
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
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class Uint, class B>\nstruct ModInt : public B\
    \ {\n  static constexpr inline auto modulo() { return B::md.modulo(); }\n  constexpr\
    \ ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x) {}\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt(T\
    \ v) : ModInt(v.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt(T n)\n      : x(B::md.set(n\
    \ < 0 ? modulo() - ((-n) % modulo()) : n)) {}\n  constexpr ModInt operator-()\
    \ const { return ModInt() - *this; }\n#define FUNC(name, op)          \\\n  constexpr\
    \ ModInt name const { \\\n    ModInt ret;                 \\\n    return ret.x\
    \ = op, ret;     \\\n  }\n  FUNC(operator+(const ModInt &r), B::md.plus(x, r.x))\n\
    \  FUNC(operator-(const ModInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const\
    \ ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k,\
    \ B::md))\n#undef FUNC\n  constexpr ModInt operator/(const ModInt &r) const {\
    \ return *this * r.inv(); }\n  constexpr ModInt &operator+=(const ModInt &r) {\
    \ return *this = *this + r; }\n  constexpr ModInt &operator-=(const ModInt &r)\
    \ { return *this = *this - r; }\n  constexpr ModInt &operator*=(const ModInt &r)\
    \ { return *this = *this * r; }\n  constexpr ModInt &operator/=(const ModInt &r)\
    \ { return *this = *this / r; }\n  constexpr bool operator==(const ModInt &r)\
    \ const {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr bool\
    \ operator!=(const ModInt &r) const { return !(*this == r); }\n  constexpr bool\
    \ operator<(const ModInt &r) const {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
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
    \ math_internal::is_staticmodint_v;\n#line 5 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\
    \nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct RcompositeQ\
    \ {\n  using T = pair<Mint, Mint>;\n  static T ti() { return make_pair(Mint(1),\
    \ Mint(0)); }\n  static T op(const T &l, const T &r) {\n    return make_pair(r.first\
    \ * l.first, r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  vector<RcompositeQ::T>\
    \ v(N);\n  for (int i = 0; i < N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n\
    \    v[i] = {a, b};\n  }\n  SegmentTree<RcompositeQ> seg(v);\n  while (Q--) {\n\
    \    bool op;\n    cin >> op;\n    if (op) {\n      int l, r;\n      Mint x;\n\
    \      cin >> l >> r >> x;\n      auto ans = seg.fold(l, r);\n      cout << ans.first\
    \ * x + ans.second << endl;\n    } else {\n      int p;\n      Mint c, d;\n  \
    \    cin >> p >> c >> d;\n      seg.set(p, {c, d});\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SegmentTree.hpp\"\n#include\
    \ \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\n\
    struct RcompositeQ {\n  using T = pair<Mint, Mint>;\n  static T ti() { return\
    \ make_pair(Mint(1), Mint(0)); }\n  static T op(const T &l, const T &r) {\n  \
    \  return make_pair(r.first * l.first, r.first * l.second + r.second);\n  }\n\
    };\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n\
    \  cin >> N >> Q;\n  vector<RcompositeQ::T> v(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    Mint a, b;\n    cin >> a >> b;\n    v[i] = {a, b};\n  }\n  SegmentTree<RcompositeQ>\
    \ seg(v);\n  while (Q--) {\n    bool op;\n    cin >> op;\n    if (op) {\n    \
    \  int l, r;\n      Mint x;\n      cin >> l >> r >> x;\n      auto ans = seg.fold(l,\
    \ r);\n      cout << ans.first * x + ans.second << endl;\n    } else {\n     \
    \ int p;\n      Mint c, d;\n      cin >> p >> c >> d;\n      seg.set(p, {c, d});\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.SegTree.test.cpp
  requiredBy: []
  timestamp: '2022-11-16 19:55:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.SegTree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html
title: test/yosupo/point_set_range_composite.SegTree.test.cpp
---
