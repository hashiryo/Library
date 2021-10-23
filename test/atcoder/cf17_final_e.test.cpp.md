---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/LinearSystemIncidence.hpp
    title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
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
    PROBLEM: https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e
    links:
    - https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e
  bundledCode: "#line 1 \"test/atcoder/cf17_final_e.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\nnamespace internal {\ntemplate <std::uint64_t mod,\
    \ std::uint64_t prim_root, class ModInt>\nstruct ModIntImpl {\n  static constexpr\
    \ std::uint64_t modulo() { return mod; }\n  static constexpr std::uint64_t pr_rt()\
    \ { return prim_root; }\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace internal\n\
    template <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\n    :\
    \ public internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n  using\
    \ u64 = std::uint64_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x\
    \ = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n \
    \ static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -__uint128_t(mod) % mod;\n\
    \  static constexpr u64 init(u64 w) { return reduce(__uint128_t(w) * r2); }\n\
    \  static constexpr u64 reduce(const __uint128_t w) {\n    return u64(w >> 64)\
    \ + mod - ((__uint128_t(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n public:\n\
    \  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n\
    \ < 0 ? mod - (-n) % mod : n)) {}\n  static constexpr u64 norm(u64 w) { return\
    \ w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const {\n    ModInt\
    \ ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - (mod << 1),\
    \ x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n\
    \  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x\
    \ = reduce(__uint128_t(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t\
    \ k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt base = *this; k; k\
    \ >>= 1, base *= base)\n      if (k & 1) ret *= base;\n    return ret;\n  }\n\
    \  constexpr ModInt inverse() const { return pow(mod - 2); }\n  constexpr ModInt\
    \ sqrt() const {\n    if (*this == ModInt(0) || mod == 2) return *this;\n    if\
    \ (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt ONE\
    \ = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b +=\
    \ ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt,\
    \ ModInt> v) {\n      ModInt a = (u.first * v.first + u.second * v.second * w);\n\
    \      ModInt b = (u.first * v.second + u.second * v.first);\n      return std::make_pair(a,\
    \ b);\n    };\n    std::uint64_t e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE,\
    \ ModInt(0));\n    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs,\
    \ bs))\n      if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 <\
    \ mod ? ret.first : -ret.first;\n  }\n  constexpr u64 val() const {\n    u64 ret\
    \ = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  friend std::istream\
    \ &operator>>(std::istream &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x\
    \ = init(rhs.x), is;\n  }\n};\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2,\
    \ pr_rt> : internal::ModIntImpl<2, pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t\
    \ n = 0) : x(n & 1) {}\n  constexpr ModInt operator-() const { return *this; }\n\
    \  constexpr ModInt &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator*=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator/=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return x == rhs.x; }\n  bool\
    \ operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n  constexpr\
    \ ModInt pow(std::uint64_t k) const { return !k ? ModInt(1) : *this; }\n  constexpr\
    \ ModInt sqrt() const { return *this; }\n  constexpr ModInt inverse() const {\
    \ return *this; }\n  constexpr std::uint64_t val() const { return x; }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 3 \"src/Graph/LinearSystemIncidence.hpp\"\
    \n/**\n * @title \u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F\n\
    \ * @category \u30B0\u30E9\u30D5\n * @see https://opt-cp.com/linear-system-incidence/\n\
    \ * O(V+E)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\nclass LinearSystemIncidence\
    \ {\n  struct Edge {\n    int id, to;\n    bool fwd;\n  };\n  int m;\n  std::vector<T>\
    \ x;\n  std::vector<char> used;\n  std::vector<std::vector<Edge>> adj;\n  T dfs(std::vector<T>\
    \ &b, int u) {\n    used[u] = true;\n    T ret = b[u];\n    for (Edge e : adj[u])\n\
    \      if (!used[e.to]) {\n        T tmp = dfs(b, e.to);\n        x[e.id] = e.fwd\
    \ ? tmp : -tmp, ret += tmp;\n      }\n    return ret;\n  }\n\n public:\n  LinearSystemIncidence(int\
    \ n) : m(0), adj(n) {}\n  void add_edge(int src, int dst) {\n    adj[src].emplace_back(m,\
    \ dst, true), adj[dst].emplace_back(m++, src, false);\n  }\n  std::pair<bool,\
    \ std::vector<T>> solve(std::vector<T> &b) {\n    x.assign(m, T(0)), used.assign(adj.size(),\
    \ false);\n    for (std::size_t u = 0; u < adj.size(); u++)\n      if (!used[u]\
    \ && dfs(b, u) != T(0))\n        return {false, std::vector<T>()};  // no sloution\n\
    \    return {true, std::move(x)};\n  }\n};\n#line 5 \"test/atcoder/cf17_final_e.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<26>;\n  string S;\n  cin >> S;\n  int N, M = S.length()\
    \ + 1;\n  cin >> N;\n  LinearSystemIncidence<Mint> lsi((M + 1) / 2);\n  for (int\
    \ i = 0; i < N; i++) {\n    int L, R;\n    cin >> L >> R;\n    L--;\n    if (2\
    \ * L >= M) L = M - 1 - L;\n    if (2 * R >= M) R = M - 1 - R;\n    lsi.add_edge(L,\
    \ R);\n  }\n  vector<Mint> b((M + 1) / 2);\n  b[0] = S[0] - S.back();\n  for (int\
    \ i = 1; i < M / 2; i++)\n    b[i] = (S[i] - S[i - 1]) + (S[M - 1 - i] - S[M -\
    \ 2 - i]);\n  if (M & 1) b[M / 2] = S[M / 2] - S[M / 2 - 1];\n  auto [isok, sol]\
    \ = lsi.solve(b);\n  cout << (isok ? \"YES\" : \"NO\") << '\\n';\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Graph/LinearSystemIncidence.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<26>;\n  string S;\n  cin >> S;\n  int N, M = S.length()\
    \ + 1;\n  cin >> N;\n  LinearSystemIncidence<Mint> lsi((M + 1) / 2);\n  for (int\
    \ i = 0; i < N; i++) {\n    int L, R;\n    cin >> L >> R;\n    L--;\n    if (2\
    \ * L >= M) L = M - 1 - L;\n    if (2 * R >= M) R = M - 1 - R;\n    lsi.add_edge(L,\
    \ R);\n  }\n  vector<Mint> b((M + 1) / 2);\n  b[0] = S[0] - S.back();\n  for (int\
    \ i = 1; i < M / 2; i++)\n    b[i] = (S[i] - S[i - 1]) + (S[M - 1 - i] - S[M -\
    \ 2 - i]);\n  if (M & 1) b[M / 2] = S[M / 2] - S[M / 2 - 1];\n  auto [isok, sol]\
    \ = lsi.solve(b);\n  cout << (isok ? \"YES\" : \"NO\") << '\\n';\n  return 0;\n\
    }"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Graph/LinearSystemIncidence.hpp
  isVerificationFile: true
  path: test/atcoder/cf17_final_e.test.cpp
  requiredBy: []
  timestamp: '2021-10-24 01:42:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/cf17_final_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/cf17_final_e.test.cpp
- /verify/test/atcoder/cf17_final_e.test.cpp.html
title: test/atcoder/cf17_final_e.test.cpp
---
