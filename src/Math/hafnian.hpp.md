---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/hafnian.hpp\"\n#include <bits/stdc++.h>\ntemplate\
    \ <typename T, unsigned short MAX_N= 38> T hafnian(const std::vector<std::vector<T>>\
    \ &mat) {\n using Poly= std::array<T, MAX_N / 2 + 1>;\n const int n= mat.size(),\
    \ n2= n / 2;\n assert(!(n & 1));\n for (int i= n; i--;)\n  for (int j= i; j--;)\
    \ assert(mat[i][j] == mat[j][i]);\n std::vector<std::vector<Poly>> a(n);\n for\
    \ (int i= n, j; i--;)\n  for (a[j= i].resize(i); j--;) a[i][j][0]= mat[i][j];\n\
    \ auto rec= [&](auto self, const auto &b) -> Poly {\n  const int m= b.size() -\
    \ 2;\n  if (m < 0) return Poly{1};\n  auto c= b;\n  c.resize(m);\n  Poly r= self(self,\
    \ c);\n  for (int i= m; i--;)\n   for (int j= i; j--;)\n    for (int k= n2 - m\
    \ / 2; k--;)\n     for (int l= k; l >= 0; l--) c[i][j][k + 1]+= b[m][i][l] * b[m\
    \ + 1][j][k - l] + b[m + 1][i][l] * b[m][j][k - l];\n  Poly t= self(self, c);\n\
    \  for (int i= n2, j; i >= 0; i--)\n   for (r[i]= t[j= i] - r[i]; j--;) r[i]+=\
    \ t[j] * b[m + 1][m][i - j - 1];\n  return r;\n };\n return rec(rec, a)[n2];\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\ntemplate <typename T, unsigned short\
    \ MAX_N= 38> T hafnian(const std::vector<std::vector<T>> &mat) {\n using Poly=\
    \ std::array<T, MAX_N / 2 + 1>;\n const int n= mat.size(), n2= n / 2;\n assert(!(n\
    \ & 1));\n for (int i= n; i--;)\n  for (int j= i; j--;) assert(mat[i][j] == mat[j][i]);\n\
    \ std::vector<std::vector<Poly>> a(n);\n for (int i= n, j; i--;)\n  for (a[j=\
    \ i].resize(i); j--;) a[i][j][0]= mat[i][j];\n auto rec= [&](auto self, const\
    \ auto &b) -> Poly {\n  const int m= b.size() - 2;\n  if (m < 0) return Poly{1};\n\
    \  auto c= b;\n  c.resize(m);\n  Poly r= self(self, c);\n  for (int i= m; i--;)\n\
    \   for (int j= i; j--;)\n    for (int k= n2 - m / 2; k--;)\n     for (int l=\
    \ k; l >= 0; l--) c[i][j][k + 1]+= b[m][i][l] * b[m + 1][j][k - l] + b[m + 1][i][l]\
    \ * b[m][j][k - l];\n  Poly t= self(self, c);\n  for (int i= n2, j; i >= 0; i--)\n\
    \   for (r[i]= t[j= i] - r[i]; j--;) r[i]+= t[j] * b[m + 1][m][i - j - 1];\n \
    \ return r;\n };\n return rec(rec, a)[n2];\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/hafnian.hpp
  requiredBy: []
  timestamp: '2022-12-31 19:53:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/hafnian_of_matrix.test.cpp
documentation_of: src/Math/hafnian.hpp
layout: document
title: "\u30CF\u30D5\u30CB\u30A2\u30F3 (\u7121\u5411\u30B0\u30E9\u30D5\u306E\u5B8C\
  \u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u6570)"
---
自己ループなし
## 計算量
$\mathcal{O} (N^2 2^{N/2})$ time \
polynomial space
## 参考
A. Björklund, "Counting Perfect Matchings as Fast as Ryser,　Proc. of 23rd ACM-SIAM symposium on Discrete Algorithms, pp.914-921, 2012.