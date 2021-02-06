---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/AllPurposeEuclid.hpp
    title: "\u4E07\u80FD\u6B27\u51E0\u91CC\u5F97"
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\n\ntemplate <std::uint64_t mod, std::uint64_t prim_root\
    \ = 0>\nclass ModInt {\n  using u64 = std::uint64_t;\n  using u128 = __uint128_t;\n\
    \  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e ==\
    \ 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv\
    \ = mul_inv(mod, 6, 1), r2 = -u128(mod) % mod;\n  static constexpr u64 init(u64\
    \ w) { return reduce(u128(w) * r2); }\n  static constexpr u64 reduce(const u128\
    \ w) {\n    return u64(w >> 64) + mod - ((u128(u64(w) * inv) * mod) >> 64);\n\
    \  }\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t\
    \ n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static\
    \ constexpr u64 modulo() { return mod; }\n  static constexpr u64 norm(u64 w) {\
    \ return w - (mod & -(w >= mod)); }\n  static constexpr u64 pr_rt() { return prim_root;\
    \ }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x\
    \ = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n    return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >>\
    \ 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return\
    \ x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(u128(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr ModInt pow(u64 k) const {\n    ModInt ret\
    \ = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *= base)\n    \
    \  if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt inverse()\
    \ const { return pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this\
    \ == ModInt(0) || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return\
    \ ModInt(0);  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n \
    \   while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto\
    \ mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt, ModInt> v) {\n    \
    \  ModInt a = (u.first * v.first + u.second * v.second * w);\n      ModInt b =\
    \ (u.first * v.second + u.second * v.first);\n      return std::make_pair(a, b);\n\
    \    };\n    u64 e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n\
    \    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n  \
    \    if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.val();\n\
    \  }\n  u64 x;\n};\n#line 3 \"src/Math/AllPurposeEuclid.hpp\"\n/**\n * @title\
    \ \u4E07\u80FD\u6B27\u51E0\u91CC\u5F97\n * @category \u6570\u5B66\n * @see https://www.luogu.com.cn/blog/ix-35/solution-p5170\n\
    \ * @see\n * https://kewth.github.io/2020/07/19/%E4%B8%87%E8%83%BD%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97/\n\
    \ * @see https://www.cnblogs.com/p-b-p-b/p/13070809.html\n */\n\n// verify\u7528\
    :\n// https://loj.ac/p/138\n// https://loj.ac/p/6440\n\n// BEGIN CUT HERE\n\n\
    template <typename M>\nclass AllPurposeEuclid {\n  using Node = typename M::Node;\n\
    \  using u64 = unsigned long long;\n  static inline Node pow(Node x, u64 e) {\n\
    \    Node ret = M::ti();\n    for (; e; e >>= 1, x = M::f(x, x))\n      if (e\
    \ & 1) ret = M::f(ret, x);\n    return ret;\n  }\n  static Node rec(u64 n, u64\
    \ a, u64 b, u64 c, const Node &sU, const Node &sR) {\n    if (!n) return M::ti();\n\
    \    if (a >= c) return rec(n, a % c, b, c, sU, M::f(pow(sU, a / c), sR));\n \
    \   u64 m = ((long double)a * n + b) / c;\n    if (!m) return pow(sR, n);\n  \
    \  u64 cnt = n - u64(((long double)c * m - b - 1) / a);\n    return M::f(M::f(pow(sR,\
    \ (c - b - 1) / a), sU),\n                M::f(rec(m - 1, c, (c - b - 1) % a,\
    \ a, sR, sU), pow(sR, cnt)));\n  }\n\n public:\n  static Node solve(u64 n, u64\
    \ a, u64 b, u64 c) {\n    return M::f(pow(M::sU, b / c), rec(n, a, b % c, c, M::sU,\
    \ M::sR));\n  }\n};\n\ntemplate <typename int_t, int MXK1, int MXK2>\nstruct FloorSumTable\
    \ {\n  static constexpr int MXK = std::max(MXK1, MXK2) + 1;\n  static inline int_t\
    \ C[MXK][MXK] = {}, pwX[MXK1 + 1] = {1},\n                      pwY[MXK2 + 1]\
    \ = {1};\n  static inline int k1 = MXK1, k2 = MXK2;\n  using u64 = unsigned long\
    \ long;\n  struct Monoid {\n    struct Node {\n      int_t cntU = 0, cntR = 0,\
    \ v[MXK1 + 1][MXK2 + 1] = {0};\n    };\n    static inline Node sU, sR;\n    static\
    \ Node ti() { return Node(); }\n    static Node f(Node vl, const Node &vr) {\n\
    \      for (int i = 0; i < k1; i++) pwX[i + 1] = pwX[i] * vl.cntR;\n      for\
    \ (int j = 0; j < k2; j++) pwY[j + 1] = pwY[j] * vl.cntU;\n      vl.cntU += vr.cntU,\
    \ vl.cntR += vr.cntR;\n      for (int i = 0; i <= k1; i++)\n        for (int j\
    \ = 0; j <= k2; j++)\n          for (int k = 0; k <= i; k++)\n            for\
    \ (int l = 0; l <= j; l++)\n              vl.v[i][j]\n                  += pwX[k]\
    \ * pwY[l] * C[i][k] * C[j][l] * vr.v[i - k][j - l];\n      return vl;\n    }\n\
    \  };\n  static void init() {\n    for (int i = 0; i < MXK; i++) C[i][0] = 1;\n\
    \    for (int i = 1; i < MXK; i++)\n      for (int j = 1; j <= i; j++) C[i][j]\
    \ = C[i - 1][j] + C[i - 1][j - 1];\n    Monoid::sU.cntU = Monoid::sR.cntR = 1;\n\
    \    for (int i = 0; i <= k1; i++) Monoid::sR.v[i][0] = 1;\n  }\n  static auto\
    \ solve(u64 n, u64 a, u64 b, u64 c, int k1_, int k2_) {\n    k1 = k1_, k2 = k2_;\n\
    \    auto tmp = AllPurposeEuclid<Monoid>::solve(n, a, b, c);\n    std::array<std::array<int_t,\
    \ MXK2 + 1>, MXK1 + 1> ret;\n    for (int i = 0; i <= k1; i++)\n      for (int\
    \ j = 0; j <= k2; j++) ret[i][j] = tmp.v[i][j];\n    int_t pw = 1, bs = double(b)\
    \ / c;\n    for (int j = 0; j <= k2; j++, pw *= bs) ret[0][j] += pw;\n    return\
    \ ret;\n  }\n};\n\ntemplate <class R_t, R_t (*ro)(), R_t (*ri)()>\nstruct RingFloorSum\
    \ {\n  using u64 = unsigned long long;\n  struct Monoid {\n    struct Node {\n\
    \      R_t u = ri(), r = ri(), v = ro();\n    };\n    static inline Node sU, sR;\n\
    \    static Node ti() { return Node(); }\n    static Node f(Node vl, const Node\
    \ &vr) {\n      vl.v += vl.r * vr.v * vl.u, vl.u *= vr.u, vl.r *= vr.r;\n    \
    \  return vl;\n    }\n  };\n  static R_t solve(u64 n, u64 a, u64 b, u64 c, const\
    \ R_t &A, const R_t &B) {\n    Monoid::sU = {B, ri(), ro()}, Monoid::sR = {ri(),\
    \ A, A};\n    return AllPurposeEuclid<Monoid>::solve(n, a, b, c).v;\n  }\n};\n\
    #line 5 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using FST = FloorSumTable<long\
    \ long, 0, 1>;\n  FST::init();\n  int T;\n  cin >> T;\n  while (T--) {\n    long\
    \ long N, M, A, B;\n    cin >> N >> M >> A >> B;\n    cout << FST::solve(N - 1,\
    \ A, B, M, 0, 1)[0][1] << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/AllPurposeEuclid.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using FST = FloorSumTable<long long, 0, 1>;\n  FST::init();\n  int T;\n  cin\
    \ >> T;\n  while (T--) {\n    long long N, M, A, B;\n    cin >> N >> M >> A >>\
    \ B;\n    cout << FST::solve(N - 1, A, B, M, 0, 1)[0][1] << '\\n';\n  }\n  return\
    \ 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/AllPurposeEuclid.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 20:31:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html
title: test/yosupo/sum_of_floor_of_linear.test.cpp
---
