---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Optimization/monotone_minima.hpp
    title: monotone minima
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#include <iostream>\n#line 2 \"src/Optimization/monotone_minima.hpp\"\n#include\
    \ <vector>\n// select(i,j,k) -> true if (i,k) is better than (i,j)\ntemplate <typename\
    \ F> std::vector<int> monotone_minima(int H, int W, const F &select) {\n std::vector<int>\
    \ ret(H);\n auto rec= [&](auto &rec, int h1, int h2, int w1, int w2) -> void {\n\
    \  if (h1 == h2) return;\n  int h= (h1 + h2) / 2, best_w= w1;\n  for (int w= w1\
    \ + 1; w < w2; ++w)\n   if (select(h, best_w, w)) best_w= w;\n  ret[h]= best_w,\
    \ rec(rec, h1, h, w1, best_w + 1), rec(rec, h + 1, h2, best_w, w2);\n };\n return\
    \ rec(rec, 0, H, 0, W), ret;\n}\n#line 4 \"test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \nusing namespace std;\nnamespace yosupo_min_plus_conv {\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n int N, M;\n cin >> N >> M;\n long long a[N], b[M];\n\
    \ for (int i= 0; i < N; ++i) cin >> a[i];\n for (int j= 0; j < M; ++j) cin >>\
    \ b[j];\n auto f= [&](int i, int j) { return a[i - j] + b[j]; };\n auto select=\
    \ [&](int i, int j, int k) {\n  if (i < k) return false;\n  if (i - j >= N) return\
    \ true;\n  return a[i - j] + b[j] >= a[i - k] + b[k];\n };\n auto r= monotone_minima(N\
    \ + M - 1, M, select);\n for (int i= 0; i < N + M - 1; ++i) cout << a[i - r[i]]\
    \ + b[r[i]] << \" \\n\"[i == N + M - 2];\n return 0;\n}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#include <iostream>\n#include \"src/Optimization/monotone_minima.hpp\"\nusing\
    \ namespace std;\nnamespace yosupo_min_plus_conv {\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n int N, M;\n cin >> N >> M;\n long long a[N], b[M];\n\
    \ for (int i= 0; i < N; ++i) cin >> a[i];\n for (int j= 0; j < M; ++j) cin >>\
    \ b[j];\n auto f= [&](int i, int j) { return a[i - j] + b[j]; };\n auto select=\
    \ [&](int i, int j, int k) {\n  if (i < k) return false;\n  if (i - j >= N) return\
    \ true;\n  return a[i - j] + b[j] >= a[i - k] + b[k];\n };\n auto r= monotone_minima(N\
    \ + M - 1, M, select);\n for (int i= 0; i < N + M - 1; ++i) cout << a[i - r[i]]\
    \ + b[r[i]] << \" \\n\"[i == N + M - 2];\n return 0;\n}\n}"
  dependsOn:
  - src/Optimization/monotone_minima.hpp
  isVerificationFile: true
  path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2023-08-17 22:34:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp.html
title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
---
