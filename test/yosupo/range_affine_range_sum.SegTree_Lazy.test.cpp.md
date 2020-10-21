---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Lazy.hpp
    title: "Segment-Tree(\u9045\u5EF6\u4F1D\u642C)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"src/DataStructure/SegmentTree_Lazy.hpp\"\n/**\n * @title Segment-Tree(\u9045\
    \u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n\
    \ */\n\n#ifndef call_from_test\n#line 9 \"src/DataStructure/SegmentTree_Lazy.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <typename M>\nstruct SegmentTree_Lazy\
    \ {\n  using T = typename M::T;\n  using E = typename M::E;\n\n private:\n  const\
    \ int height, n;\n  vector<T> dat;\n  vector<E> laz;\n\n private:\n  inline T\
    \ reflect(int k) {\n    return laz[k] == M::ei() ? dat[k] : M::g(dat[k], laz[k]);\n\
    \  }\n  inline void eval(int k) {\n    if (laz[k] == M::ei()) return;\n    laz[(k\
    \ << 1) | 0] = M::h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = M::h(laz[(k\
    \ << 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k] = M::ei();\n  }\n\
    \  inline void thrust(int k) {\n    for (int i = height; i; i--) eval(k >> i);\n\
    \  }\n  inline void recalc(int k) {\n    while (k >>= 1) dat[k] = M::f(reflect((k\
    \ << 1) | 0), reflect((k << 1) | 1));\n  }\n\n public:\n  SegmentTree_Lazy() {}\n\
    \  SegmentTree_Lazy(int n_, T v1 = M::ti())\n      : SegmentTree_Lazy(vector<T>(n_,\
    \ v1)) {}\n  SegmentTree_Lazy(const vector<T>& v)\n      : height(ceil(log2(v.size()))),\n\
    \        n(1 << height),\n        dat(n * 2, M::ti()),\n        laz(n * 2, M::ei())\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];\n    for (int\
    \ i = n - 1; i >= 1; i--)\n      dat[i] = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);\n\
    \  }\n  void update(int a, int b, E x) {\n    thrust(a += n);\n    thrust(b +=\
    \ n - 1);\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) laz[l] = M::h(laz[l], x), l++;\n      if (r & 1) --r, laz[r] = M::h(laz[r],\
    \ x);\n    }\n    recalc(a);\n    recalc(b);\n  }\n  void set_val(int a, T x)\
    \ {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a] = M::ei();\n    recalc(a);\n\
    \  }\n  //[a,b)\n  T query(int a, int b) {\n    thrust(a += n);\n    thrust(b\
    \ += n - 1);\n    T vl = M::ti(), vr = M::ti();\n    for (int l = a, r = b + 1;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl = M::f(vl, reflect(l++));\n\
    \      if (r & 1) vr = M::f(reflect(--r), vr);\n    }\n    return M::f(vl, vr);\n\
    \  }\n  T operator[](const int k) { return query(k, k + 1); }\n};\n#line 1 \"\
    src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\
    \n#ifndef call_from_test\n#line 8 \"src/Math/ModInt.hpp\"\nusing namespace std;\n\
    #endif\n\ntemplate <uint64_t mod, uint64_t prim_root = 0>\nclass ModInt {\n private:\n\
    \  using u128 = __uint128_t;\n  static constexpr uint64_t mul_inv(uint64_t n,\
    \ int e = 6, uint64_t x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x *\
    \ (2 - x * n));\n  }\n  static constexpr uint64_t inv = mul_inv(mod, 6, 1);\n\
    \  static constexpr uint64_t r2 = -u128(mod) % mod;\n  static constexpr uint64_t\
    \ m2 = mod << 1;\n\n public:\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(int64_t n) : x(init(n\
    \ < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static constexpr\
    \ uint64_t modulo() { return mod; }\n  static constexpr uint64_t init(uint64_t\
    \ w) { return reduce(u128(w) * r2); }\n  static constexpr uint64_t reduce(const\
    \ u128 w) {\n    return uint64_t(w >> 64) + mod - ((u128(uint64_t(w) * inv) *\
    \ mod) >> 64);\n  }\n  static constexpr uint64_t norm(uint64_t x) { return x -\
    \ (mod & -(x >= mod)); }\n  static constexpr uint64_t pr_rt() { return prim_root;\
    \ }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x\
    \ = (m2 & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const ModInt\
    \ &rhs) {\n    return x += rhs.x - m2, x += m2 & -(x >> 63), *this;\n  }\n  constexpr\
    \ ModInt &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x += m2 & -(x\
    \ >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n \
    \   return this->x = reduce(u128(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt\
    \ &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  uint64_t get() const {\n    uint64_t ret = reduce(x) - mod;\n    return\
    \ ret + (mod & -(ret >> 63));\n  }\n  constexpr ModInt pow(uint64_t k) const {\n\
    \    ModInt ret = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *=\
    \ base)\n      if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt\
    \ inverse() const { return pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n\
    \    if (*this == ModInt(0) || mod == 2) return *this;\n    if (pow((mod - 1)\
    \ >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt ONE = 1, b(2), w(b\
    \ * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b\
    \ - *this;\n    auto mul = [&](pair<ModInt, ModInt> u, pair<ModInt, ModInt> v)\
    \ {\n      ModInt a = (u.first * v.first + u.second * v.second * w);\n      ModInt\
    \ b = (u.first * v.second + u.second * v.first);\n      return make_pair(a, b);\n\
    \    };\n    uint64_t e = (mod + 1) >> 1;\n    auto ret = make_pair(ONE, ModInt(0));\n\
    \    for (auto bs = make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n      if\
    \ (e & 1) ret = mul(ret, bs);\n    return ret.first.get() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.get();\n\
    \  }\n  uint64_t x;\n};\n#line 9 \"test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp\"\
    \n#undef call_from_test\n\nusing Mint = ModInt<998244353>;\n// RsumQ\u306F\u30E2\
    \u30CE\u30A4\u30C9\u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\u3066\u304A\u304F\
    \nstruct RaffineQ_RsumQ {\n  struct T {\n    Mint val;\n    int size;\n    T(Mint\
    \ v = 0, int s = 1) : val(v), size(s) {}\n  };\n  using E = pair<Mint, Mint>;\n\
    \  static T ti() { return T(0, 0); }\n  static E ei() { return make_pair(Mint(1),\
    \ Mint(0)); }\n  static T f(const T &l, const T &r) {\n    return T(l.val + r.val,\
    \ l.size + r.size);\n  }\n  static T g(const T &l, const E &r) {\n    return T(r.first\
    \ * l.val + r.second * l.size, l.size);\n  }\n  static E h(const E &l, const E\
    \ &r) {\n    return make_pair(r.first * l.first, r.first * l.second + r.second);\n\
    \  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<RaffineQ_RsumQ::T> v(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    Mint a;\n    cin >> a;\n    v[i] = {a, 1};\n  }\n  SegmentTree_Lazy<RaffineQ_RsumQ>\
    \ seg(v);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op >> l >>\
    \ r;\n    if (op) {\n      cout << seg.query(l, r).val << endl;\n    } else {\n\
    \      Mint b, c;\n      cin >> b >> c;\n      seg.update(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/DataStructure/SegmentTree_Lazy.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n#undef call_from_test\n\nusing Mint = ModInt<998244353>;\n// RsumQ\u306F\u30E2\
    \u30CE\u30A4\u30C9\u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\u3066\u304A\u304F\
    \nstruct RaffineQ_RsumQ {\n  struct T {\n    Mint val;\n    int size;\n    T(Mint\
    \ v = 0, int s = 1) : val(v), size(s) {}\n  };\n  using E = pair<Mint, Mint>;\n\
    \  static T ti() { return T(0, 0); }\n  static E ei() { return make_pair(Mint(1),\
    \ Mint(0)); }\n  static T f(const T &l, const T &r) {\n    return T(l.val + r.val,\
    \ l.size + r.size);\n  }\n  static T g(const T &l, const E &r) {\n    return T(r.first\
    \ * l.val + r.second * l.size, l.size);\n  }\n  static E h(const E &l, const E\
    \ &r) {\n    return make_pair(r.first * l.first, r.first * l.second + r.second);\n\
    \  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<RaffineQ_RsumQ::T> v(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    Mint a;\n    cin >> a;\n    v[i] = {a, 1};\n  }\n  SegmentTree_Lazy<RaffineQ_RsumQ>\
    \ seg(v);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op >> l >>\
    \ r;\n    if (op) {\n      cout << seg.query(l, r).val << endl;\n    } else {\n\
    \      Mint b, c;\n      cin >> b >> c;\n      seg.update(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree_Lazy.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 16:47:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp.html
title: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
---