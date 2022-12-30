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
    \ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
    \  Int x= 1, y= 0, b= mod;\n  for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y,\
    \ y= z - y * (q= a / b), a= b, b= c - b * q;\n  return assert(a == 1), x < 0 ?\
    \ mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing u128= __uint128_t;\nstruct MP_Mo {\n  const u64 mod;\n\
    \  constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n  constexpr MP_Mo(u64 m): mod(m),\
    \ iv(inv(m)), r2(-u128(mod) % mod) {}\n  constexpr inline u64 mul(u64 l, u64 r)\
    \ const { return reduce(u128(l) * r); }\n#define BOP(op, a) return l op##= a,\
    \ l+= (mod << 1) & -(l >> 63)\n  constexpr inline u64 plus(u64 l, u64 r) const\
    \ { BOP(+, r - (mod << 1)); }\n  constexpr inline u64 diff(u64 l, u64 r) const\
    \ { BOP(-, r); }\n#undef BOP\n  constexpr inline u64 set(u64 n) const { return\
    \ mul(n, r2); }\n  constexpr inline u64 get(u64 n) const {\n    u64 ret= reduce(n)\
    \ - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  constexpr inline u64\
    \ norm(u64 n) const { return n - (mod & -(n >= mod)); }\n private:\n  const u64\
    \ iv, r2;\n  constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e ? inv(n,\
    \ e - 1, x * (2 - x * n)) : x; }\n  constexpr inline u64 reduce(const u128 &w)\
    \ const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64); }\n};\n\
    template <class Uint> class MP_Na {\n  using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\n public:\n  const Uint mod;\n  constexpr MP_Na(): mod(0){};\n\
    \  constexpr MP_Na(Uint m): mod(m) {}\n  constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n  static constexpr inline Uint set(Uint n) { return n; }\n  static\
    \ constexpr inline Uint get(Uint n) { return n; }\n  static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n    if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return\
    \ ret;\n}\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\nstruct\
    \ m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> constexpr\
    \ bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> constexpr\
    \ bool is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64\
    \ MOD> struct SB: s_b {\n protected:\n  static constexpr mpt md= mpt(MOD);\n};\n\
    template <class mpt, int id> struct RB: r_b {\n  static inline void set_mod(u64\
    \ m) { md= mpt(m); }\n protected:\n  static inline mpt md;\n};\ntemplate <class\
    \ Int, class U, class B> struct MInt: public B {\n  using Uint= U;\n  static constexpr\
    \ inline auto modulo() { return B::md.mod; }\n  constexpr MInt(): x(0) {}\n  constexpr\
    \ MInt(const MInt &r): x(r.x) {}\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> constexpr MInt(T v): x(B::md.set(v.val() % B::md.mod))\
    \ {}\n  template <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t>\
    \ = nullptr> constexpr MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod\
    \ : n % B::md.mod))) {}\n  constexpr MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n  constexpr MInt name const { \\\n    MInt\
    \ ret; \\\n    return ret.x= op, ret; \\\n  }\n  FUNC(operator+(const MInt &r),\
    \ B::md.plus(x, r.x))\n  FUNC(operator-(const MInt &r), B::md.diff(x, r.x))\n\
    \  FUNC(operator*(const MInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64 k), math_internal::pow(x,\
    \ k, B::md))\n#undef FUNC\n  constexpr MInt operator/(const MInt &r) const { return\
    \ *this * r.inv(); }\n  constexpr MInt &operator+=(const MInt &r) { return *this=\
    \ *this + r; }\n  constexpr MInt &operator-=(const MInt &r) { return *this= *this\
    \ - r; }\n  constexpr MInt &operator*=(const MInt &r) { return *this= *this *\
    \ r; }\n  constexpr MInt &operator/=(const MInt &r) { return *this= *this / r;\
    \ }\n  constexpr bool operator==(const MInt &r) const { return B::md.norm(x) ==\
    \ B::md.norm(r.x); }\n  constexpr bool operator!=(const MInt &r) const { return\
    \ !(*this == r); }\n  constexpr bool operator<(const MInt &r) const { return B::md.norm(x)\
    \ < B::md.norm(r.x); }\n  constexpr inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n  constexpr inline Uint val() const { return B::md.get(x); }\n\
    \  friend ostream &operator<<(ostream &os, const MInt &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, MInt &r) {\n    long long v;\n\
    \    return is >> v, r= MInt(v), is;\n  }\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD> using StaticModInt= conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>,\
    \ MOD>>, conditional_t<MOD &(MOD < LLONG_MAX), MInt<long long, u64, SB<MP_Mo,\
    \ MOD>>, MInt<long long, u64, SB<MP_Na<u64>, MOD>>>>;\nclass Moomery {};\ntemplate\
    \ <class Int, int id= -1> using RuntimeModInt= conditional_t<is_same_v<Int, Moomery>,\
    \ MInt<long long, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>, MInt<long long, u64, RB<MP_Na<u64>, id>>, MInt<int,\
    \ u32, RB<MP_Na<u32>, id>>>>;\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Moomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM> mod_t\
    \ get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m= mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l= 1;\n  if (l ==\
    \ 1) dat[l++]= 1;\n  while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n  return\
    \ dat[n];\n}\n#line 5 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\
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
  timestamp: '2022-12-31 01:36:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.SegTree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html
title: test/yosupo/point_set_range_composite.SegTree.test.cpp
---
