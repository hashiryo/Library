---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1569.Nimber.test.cpp
    title: test/yukicoder/1569.Nimber.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1595.linear_rec.test.cpp
    title: test/yukicoder/1595.linear_rec.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
  - icon: ':x:'
    path: test/yukicoder/658.linear_rec.test.cpp
    title: test/yukicoder/658.linear_rec.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/bostan_mori.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <cstdint>\ntemplate <class K> K div_at(std::vector<K> p,\
    \ std::vector<K> q, uint64_t k) {\n int n= p.size() - 1, m= q.size() - 1;\n for\
    \ (assert(q[0] != K(0));; --n)\n  if (n < 0 || p[n] != K()) break;\n for (;; --m)\n\
    \  if (m < 0 || q[m] != K()) break;\n const int l= std::max(n, m) + 1;\n p.resize(l),\
    \ q.resize(l);\n for (std::vector<K> np; k > m; q.swap(p), p.swap(np), k>>= 1)\
    \ {\n  np.assign(l, K());\n  if (k & 1) {\n   for (int i= 0; i < l; i+= 2)\n \
    \   for (int j= 1; j < l; j+= 2) np[(i + j) >> 1]+= p[j] * q[i] - p[i] * q[j];\n\
    \  } else {\n   for (int i= 0; i < l; i+= 2)\n    for (int j= 0; j < l; j+= 2)\
    \ np[(i + j) >> 1]+= p[i] * q[j];\n   for (int i= 1; i < l; i+= 2)\n    for (int\
    \ j= 1; j < l; j+= 2) np[(i + j) >> 1]-= p[i] * q[j];\n  }\n  p.assign(l, K());\n\
    \  for (int i= 0; i < l; i+= 2)\n   for (int j= 0; j < i; j+= 2) p[(i + j) >>\
    \ 1]+= q[i] * q[j];\n  for (int i= 1; i < l; i+= 2)\n   for (int j= 1; j < i;\
    \ j+= 2) p[(i + j) >> 1]-= q[i] * q[j];\n  for (int i= l; i--;) p[i]+= p[i];\n\
    \  for (int i= 0; i < l; i+= 2) p[i]+= q[i] * q[i];\n  for (int i= 1; i < l; i+=\
    \ 2) p[i]-= q[i] * q[i];\n }\n K iv= K(1) / q[0];\n for (int j= 0; j <= k; p[j++]*=\
    \ iv)\n  for (int i= j; i; --i) p[j]-= p[j - i] * q[i];\n return p[k];\n}\n//\
    \ a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1] * a[n-d]\n// return a[k]\n\
    template <class K> K linear_recurrence(std::vector<K> c, const std::vector<K>\
    \ &a, uint64_t k) {\n if (k < a.size()) return a[k];\n const size_t d= c.size();\n\
    \ assert(d <= a.size());\n for (auto &x: c) x= -x;\n std::vector<K> p(d);\n c.insert(c.begin(),\
    \ K(1));\n for (int i= d; i--;)\n  for (int j= i; j >= 0; --j) p[i]+= c[j] * a[i\
    \ - j];\n return div_at<K>(p, c, k);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <cstdint>\n\
    template <class K> K div_at(std::vector<K> p, std::vector<K> q, uint64_t k) {\n\
    \ int n= p.size() - 1, m= q.size() - 1;\n for (assert(q[0] != K(0));; --n)\n \
    \ if (n < 0 || p[n] != K()) break;\n for (;; --m)\n  if (m < 0 || q[m] != K())\
    \ break;\n const int l= std::max(n, m) + 1;\n p.resize(l), q.resize(l);\n for\
    \ (std::vector<K> np; k > m; q.swap(p), p.swap(np), k>>= 1) {\n  np.assign(l,\
    \ K());\n  if (k & 1) {\n   for (int i= 0; i < l; i+= 2)\n    for (int j= 1; j\
    \ < l; j+= 2) np[(i + j) >> 1]+= p[j] * q[i] - p[i] * q[j];\n  } else {\n   for\
    \ (int i= 0; i < l; i+= 2)\n    for (int j= 0; j < l; j+= 2) np[(i + j) >> 1]+=\
    \ p[i] * q[j];\n   for (int i= 1; i < l; i+= 2)\n    for (int j= 1; j < l; j+=\
    \ 2) np[(i + j) >> 1]-= p[i] * q[j];\n  }\n  p.assign(l, K());\n  for (int i=\
    \ 0; i < l; i+= 2)\n   for (int j= 0; j < i; j+= 2) p[(i + j) >> 1]+= q[i] * q[j];\n\
    \  for (int i= 1; i < l; i+= 2)\n   for (int j= 1; j < i; j+= 2) p[(i + j) >>\
    \ 1]-= q[i] * q[j];\n  for (int i= l; i--;) p[i]+= p[i];\n  for (int i= 0; i <\
    \ l; i+= 2) p[i]+= q[i] * q[i];\n  for (int i= 1; i < l; i+= 2) p[i]-= q[i] *\
    \ q[i];\n }\n K iv= K(1) / q[0];\n for (int j= 0; j <= k; p[j++]*= iv)\n  for\
    \ (int i= j; i; --i) p[j]-= p[j - i] * q[i];\n return p[k];\n}\n// a[n] = c[0]\
    \ * a[n-1] + c[1] * a[n-2] + ... + c[d-1] * a[n-d]\n// return a[k]\ntemplate <class\
    \ K> K linear_recurrence(std::vector<K> c, const std::vector<K> &a, uint64_t k)\
    \ {\n if (k < a.size()) return a[k];\n const size_t d= c.size();\n assert(d <=\
    \ a.size());\n for (auto &x: c) x= -x;\n std::vector<K> p(d);\n c.insert(c.begin(),\
    \ K(1));\n for (int i= d; i--;)\n  for (int j= i; j >= 0; --j) p[i]+= c[j] * a[i\
    \ - j];\n return div_at<K>(p, c, k);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/bostan_mori.hpp
  requiredBy: []
  timestamp: '2024-02-22 16:45:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1595.linear_rec.test.cpp
  - test/yukicoder/1569.Nimber.test.cpp
  - test/yukicoder/658.linear_rec.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/aoj/0168.test.cpp
documentation_of: src/Math/bostan_mori.hpp
layout: document
title: "\u7DDA\u5F62\u6F38\u5316\u7684\u6570\u5217\u306E\u7B2C$k$\u9805"
---

|名前|概要|計算量|
|---|---|---|
|`div_at(p,q,k)`| $\displaystyle \lbrack x^k\rbrack\frac{p(x)}{q(x)}$ の値を返す.<br> $q(x)$の定数項は $1$ か逆元が存在しないとだめ． | $\mathcal{O}(d^2\log k)$ <br> ただし $d = \max(\deg(p), \deg(q))$|
|`linear_recurrence(c,a,k)`| 線形漸化式 $\displaystyle b_n = \begin{cases}a_n & n \lt d \newline c_0 b_{n-1} + c_1 b_{n-2} + ... + c_{d-1} b_{n-d} & n \geq d \end{cases}$ を満たす数列 $(b_n)$ の第 $k$ 項 $b_k$ の値を返す. |$\mathcal{O}(d^2\log k)$|

## 参考
[線形漸化的数列のN項目の計算](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a)