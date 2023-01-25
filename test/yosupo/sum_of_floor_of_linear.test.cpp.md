---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/AllPurposeEuclid.hpp
    title: "\u4E07\u80FD\u6B27\u51E0\u91CC\u5F97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n#include <iostream>\n\
    #line 2 \"src/Math/AllPurposeEuclid.hpp\"\n#include <algorithm>\n#include <array>\n\
    template <typename M> class AllPurposeEuclid {\n using Node= typename M::Node;\n\
    \ using u64= unsigned long long;\n static inline Node pow(Node x, u64 e) {\n \
    \ Node ret= M::ti();\n  for (; e; e>>= 1, x= M::f(x, x))\n   if (e & 1) ret= M::f(ret,\
    \ x);\n  return ret;\n }\n static Node rec(u64 n, u64 a, u64 b, u64 c, const Node\
    \ &sU, const Node &sR) {\n  if (!n) return M::ti();\n  if (a >= c) return rec(n,\
    \ a % c, b, c, sU, M::f(pow(sU, a / c), sR));\n  u64 m= ((long double)a * n +\
    \ b) / c;\n  if (!m) return pow(sR, n);\n  u64 cnt= n - u64(((long double)c *\
    \ m - b - 1) / a);\n  return M::f(M::f(pow(sR, (c - b - 1) / a), sU), M::f(rec(m\
    \ - 1, c, (c - b - 1) % a, a, sR, sU), pow(sR, cnt)));\n }\npublic:\n static Node\
    \ solve(u64 n, u64 a, u64 b, u64 c) { return M::f(pow(M::sU, b / c), rec(n, a,\
    \ b % c, c, M::sU, M::sR)); }\n};\ntemplate <typename int_t, int MXK1, int MXK2>\
    \ struct FloorSumTable {\n static constexpr int MXK= std::max(MXK1, MXK2) + 1;\n\
    \ static inline int_t C[MXK][MXK]= {}, pwX[MXK1 + 1]= {1}, pwY[MXK2 + 1]= {1};\n\
    \ static inline int k1= MXK1, k2= MXK2;\n using u64= unsigned long long;\n struct\
    \ Monoid {\n  struct Node {\n   int_t cntU= 0, cntR= 0, v[MXK1 + 1][MXK2 + 1]=\
    \ {0};\n  };\n  static inline Node sU, sR;\n  static Node ti() { return Node();\
    \ }\n  static Node f(Node vl, const Node &vr) {\n   for (int i= 0; i < k1; i++)\
    \ pwX[i + 1]= pwX[i] * vl.cntR;\n   for (int j= 0; j < k2; j++) pwY[j + 1]= pwY[j]\
    \ * vl.cntU;\n   vl.cntU+= vr.cntU, vl.cntR+= vr.cntR;\n   for (int i= 0; i <=\
    \ k1; i++)\n    for (int j= 0; j <= k2; j++)\n     for (int k= 0; k <= i; k++)\n\
    \      for (int l= 0; l <= j; l++) vl.v[i][j]+= pwX[k] * pwY[l] * C[i][k] * C[j][l]\
    \ * vr.v[i - k][j - l];\n   return vl;\n  }\n };\n static void init() {\n  for\
    \ (int i= 0; i < MXK; i++) C[i][0]= 1;\n  for (int i= 1; i < MXK; i++)\n   for\
    \ (int j= 1; j <= i; j++) C[i][j]= C[i - 1][j] + C[i - 1][j - 1];\n  Monoid::sU.cntU=\
    \ Monoid::sR.cntR= 1;\n  for (int i= 0; i <= k1; i++) Monoid::sR.v[i][0]= 1;\n\
    \ }\n static auto solve(u64 n, u64 a, u64 b, u64 c, int k1_, int k2_) {\n  k1=\
    \ k1_, k2= k2_;\n  auto tmp= AllPurposeEuclid<Monoid>::solve(n, a, b, c);\n  std::array<std::array<int_t,\
    \ MXK2 + 1>, MXK1 + 1> ret;\n  for (int i= 0; i <= k1; i++)\n   for (int j= 0;\
    \ j <= k2; j++) ret[i][j]= tmp.v[i][j];\n  int_t pw= 1, bs= double(b) / c;\n \
    \ for (int j= 0; j <= k2; j++, pw*= bs) ret[0][j]+= pw;\n  return ret;\n }\n};\n\
    template <class R_t, R_t (*ro)(), R_t (*ri)()> struct RingFloorSum {\n using u64=\
    \ unsigned long long;\n struct Monoid {\n  struct Node {\n   R_t u= ri(), r= ri(),\
    \ v= ro();\n  };\n  static inline Node sU, sR;\n  static Node ti() { return Node();\
    \ }\n  static Node f(Node vl, const Node &vr) {\n   vl.v+= vl.r * vr.v * vl.u,\
    \ vl.u*= vr.u, vl.r*= vr.r;\n   return vl;\n  }\n };\n static R_t solve(u64 n,\
    \ u64 a, u64 b, u64 c, const R_t &A, const R_t &B) {\n  Monoid::sU= {B, ri(),\
    \ ro()}, Monoid::sR= {ri(), A, A};\n  return AllPurposeEuclid<Monoid>::solve(n,\
    \ a, b, c).v;\n }\n};\n#line 4 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using FST= FloorSumTable<long long, 0, 1>;\n FST::init();\n int T;\n cin >>\
    \ T;\n while (T--) {\n  long long N, M, A, B;\n  cin >> N >> M >> A >> B;\n  cout\
    \ << FST::solve(N - 1, A, B, M, 0, 1)[0][1] << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include <iostream>\n#include \"src/Math/AllPurposeEuclid.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using FST=\
    \ FloorSumTable<long long, 0, 1>;\n FST::init();\n int T;\n cin >> T;\n while\
    \ (T--) {\n  long long N, M, A, B;\n  cin >> N >> M >> A >> B;\n  cout << FST::solve(N\
    \ - 1, A, B, M, 0, 1)[0][1] << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Math/AllPurposeEuclid.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 16:45:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html
title: test/yosupo/sum_of_floor_of_linear.test.cpp
---
