---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree.hpp
    title: Segment-Tree
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
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
    \n private:\n  const int n;\n  std::vector<T> dat;\n};\n#line 3 \"src/Math/ModInt.hpp\"\
    \n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\
    namespace modint_internal {\nusing namespace std;\nstruct modint_base {};\nstruct\
    \ sta_mint_base : modint_base {};\nstruct dyn_mint_base : modint_base {};\ntemplate\
    \ <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base, mod_t>;\n\
    template <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
    \ mod_t>;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\n\
    struct ModIntImpl {\n  static constexpr inline auto modulo() { return D::mod;\
    \ }\n  constexpr D operator-() const { return D() -= (D &)*this; }\n  constexpr\
    \ D &operator/=(const D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const\
    \ D &r) const { return D((D &)*this) += r; }\n  constexpr D operator-(const D\
    \ &r) const { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r)\
    \ const { return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const\
    \ { return D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const\
    \ { return !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D\
    \ ret(1), b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>=\
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    typename D::Int x = 1,\
    \ y = 0, a = ((D *)this)->val(), b = D::mod;\n    for (typename D::Int q = 0,\
    \ z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y * (q = a / b), a = b,\
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  constexpr bool operator<(const\
    \ D &r) const {\n    return ((D *)this)->val() < r.val();\n  }  // for set or\
    \ map\n  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using Int = typename B::Int;\n\
    \  using DUint = conditional_t<is_same_v<typename B::Uint, uint32_t>, u64, u128>;\n\
    \  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr ModInt_Na() = default;\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T\
    \ n) : ModInt_Na(n.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod) {}\n#define ASSIGN(m, p) return x m## = B::mod\
    \ & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na &operator+=(const\
    \ ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const ModInt_Na\
    \ &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Int = int64_t;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    \  template <class T,\n            enable_if_t<is_convertible_v<T, __int128_t>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op##\
    \ = a, x += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const\
    \ mod_t &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const\
    \ mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const\
    \ mod_t &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const\
    \ mod_t &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const\
    \ {\n    u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
    \  }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n   \
    \ return u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n\
    \  static constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r);\
    \ }\n  u64 x = 0;\n  constexpr inline u64 norm() const { return x - (B::mod &\
    \ -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n\
    \  return e ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\n\
    struct StaticB_Na : sta_mint_base {\n protected:\n  using Int = conditional_t\
    \ < MOD < INT_MAX, int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n\
    \  using Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing DynamicModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n\
    \                  ModInt_Na<DynamicB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::DynamicModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_dynamicmodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    template <class mod_t, std::size_t LIM>\nmod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n\
    \  static const auto m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static\
    \ int l = 1;\n  if (l == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m %\
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 5 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\
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
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.SegTree.test.cpp
  requiredBy: []
  timestamp: '2022-11-08 16:52:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.SegTree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html
title: test/yosupo/point_set_range_composite.SegTree.test.cpp
---
