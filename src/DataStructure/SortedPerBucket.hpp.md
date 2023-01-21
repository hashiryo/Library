---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3170.test.cpp
    title: test/aoj/3170.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/hackerrank/library-query.SqrtDC.test.cpp
    title: test/hackerrank/library-query.SqrtDC.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_chmin_chmax_add_range_sum.SqrtDC.test.cpp
    title: test/yosupo/range_chmin_chmax_add_range_sum.SqrtDC.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/925.SqrtDC.test.cpp
    title: test/yukicoder/925.SqrtDC.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SortedPerBucket.hpp\"\n#include <bits/stdc++.h>\n\
    template <class T, std::size_t B= 700> class SortedPerBucket {\n static constexpr\
    \ T INF= std::numeric_limits<T>::max() / 2;\n struct Dat {\n  const std::size_t\
    \ n;\n  std::array<T, B> a, sorted;\n  std::array<T, B + 1> acc;\n  T add, lb,\
    \ ub;\n  Dat(std::size_t b): n(b), a{0}, sorted{0}, acc{0}, add(0), lb(-INF),\
    \ ub(INF) {}\n  Dat(const T *bg, std::size_t b): n(b), a{0}, acc{0}, add(0), lb(-INF),\
    \ ub(INF) {\n   for (int i= n; i--;) a[i]= *(bg + i);\n   build();\n  }\n  inline\
    \ bool eval() {\n   if (add == 0 && lb == -INF && ub == INF) return false;\n \
    \  for (auto &x: a) x= std::clamp(x, lb, ub) + add;\n   return add= 0, lb= -INF,\
    \ ub= INF, true;\n  }\n  inline void build() {\n   sorted= a, std::sort(sorted.begin(),\
    \ sorted.begin() + n);\n   std::partial_sum(sorted.begin(), sorted.begin() + n,\
    \ acc.begin() + 1);\n  }\n  inline std::size_t idx(T x) const { return std::lower_bound(sorted.begin(),\
    \ sorted.begin() + n, x) - sorted.begin(); }\n  inline std::size_t count(T x)\
    \ const { return x-= add, (x <= lb ? 0 : ub < x ? n : idx(x)); }\n  inline T sum()\
    \ const {\n   std::size_t l= idx(lb), u= idx(ub);\n   return acc[u] - acc[l] +\
    \ lb * l + ub * (n - u) + add * n;\n  }\n  inline T sum(T x) const {\n   if (x-=\
    \ add; x <= lb) return 0;\n   if (ub < x) return sum();\n   std::size_t l= idx(lb),\
    \ u= idx(x);\n   return acc[u] - acc[l] + lb * l + add * u;\n  }\n  inline T get(std::size_t\
    \ k) const { return std::clamp(a[k], lb, ub) + add; }\n };\n const std::size_t\
    \ n;\n std::vector<Dat> dat;\n template <class U, class All, class One> inline\
    \ U fold(std::size_t l, std::size_t r, const All &all, const One &one) const {\n\
    \  U ret= 0;\n  if (std::size_t i= l / B, j= r / B, k= l % B, m= r % B; i < j)\
    \ {\n   if (k) {\n    for (; k < dat[i].n; k++) ret+= one(dat[i].get(k));\n  \
    \  i++;\n   }\n   for (; i < j; i++) ret+= all(dat[i]);\n   if (m)\n    for (;\
    \ m--;) ret+= one(dat[j].get(m));\n  } else\n   for (; k < m; k++) ret+= one(dat[i].get(k));\n\
    \  return ret;\n }\n template <class All, class One> inline void update(std::size_t\
    \ l, std::size_t r, const All &all, const One &one) {\n  if (std::size_t i= l\
    \ / B, j= r / B, k= l % B, m= r % B; i < j) {\n   if (k) {\n    for (dat[i].eval();\
    \ k < dat[i].n; k++) one(dat[i].a[k]);\n    dat[i].build(), i++;\n   }\n   for\
    \ (; i < j; i++) all(dat[i]);\n   if (m) {\n    for (dat[j].eval(); m--;) one(dat[j].a[m]);\n\
    \    dat[j].build();\n   }\n  } else {\n   for (dat[i].eval(); k < m; k++) one(dat[i].a[k]);\n\
    \   dat[i].build();\n  }\n }\npublic:\n SortedPerBucket(std::size_t n_): n(n_)\
    \ {\n  for (int l= 0, r; l < n; l= r) r= std::min(l + B, n), dat.emplace_back(r\
    \ - l);\n }\n SortedPerBucket(const std::vector<T> &a): n(a.size()) {\n  for (int\
    \ l= 0, r; l < n; l= r) r= std::min(l + B, n), dat.emplace_back(a.data() + l,\
    \ r - l);\n }\n // count i s.t. (l <= i < r) && (a[i] < ub)\n std::size_t count(std::size_t\
    \ l, std::size_t r, T ub) const {\n  return fold<std::size_t>(\n      l, r, [&](const\
    \ Dat &d) { return d.count(ub); }, [&](T x) { return x < ub; });\n }\n // count\
    \ i s.t. (l <= i < r) && (lb <= a[i] < ub)\n std::size_t count(std::size_t l,\
    \ std::size_t r, T lb, T ub) const { return count(l, r, ub) - count(l, r, lb);\
    \ }\n // sum a[i] s.t. (l <= i < r)\n T sum(std::size_t l, std::size_t r) const\
    \ {\n  return fold<T>(\n      l, r, [&](const Dat &d) { return d.sum(); }, [&](T\
    \ x) { return x; });\n }\n // sum a[i] s.t. (l <= i < r) && (a[i] < ub)\n T sum(std::size_t\
    \ l, std::size_t r, T ub) const {\n  return fold<T>(\n      l, r, [&](const Dat\
    \ &d) { return d.sum(ub); }, [&](T x) { return x < ub ? x : 0; });\n }\n // sum\
    \ a[i] s.t. (l <= i < r)  && (lb <= a[i] < ub)\n T sum(std::size_t l, std::size_t\
    \ r, T lb, T ub) const { return sum(l, r, ub) - sum(l, r, lb); }\n void set(std::size_t\
    \ k, T x) {\n  std::size_t i= k / B, j= k % B;\n  dat[i].eval(), dat[i].a[j]=\
    \ x, dat[i].build();\n }\n T get(std::size_t k) const { return dat[k / B].get(k\
    \ % B); }\n T operator[](std::size_t k) const { return get(k); }\n void add(std::size_t\
    \ l, std::size_t r, T v) {\n  update(\n      l, r, [&](Dat &d) { d.add+= v; },\
    \ [&](T &x) { x+= v; });\n }\n void chmin(std::size_t l, std::size_t r, T ub)\
    \ {\n  auto f= [&](Dat &d) {\n   T b= ub - d.add;\n   d.ub= std::min(d.ub, b),\
    \ d.lb= std::min(d.lb, b);\n  };\n  update(l, r, f, [&](T &x) { x= std::min(x,\
    \ ub); });\n }\n void chmax(std::size_t l, std::size_t r, T lb) {\n  auto f= [&](Dat\
    \ &d) {\n   T a= lb - d.add;\n   d.lb= std::max(d.lb, a), d.ub= std::max(d.ub,\
    \ a);\n  };\n  update(l, r, f, [&](T &x) { x= std::max(x, lb); });\n }\n void\
    \ chclamp(std::size_t l, std::size_t r, T lb, T ub) {\n  auto f= [&](Dat &d) {\n\
    \   T a= lb - d.add, b= ub - d.add;\n   d.ub= std::clamp(d.ub, a, b), d.lb= std::clamp(d.lb,\
    \ a, b);\n  };\n  update(l, r, f, [&](T &x) { x= std::clamp(x, lb, ub); });\n\
    \ }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\ntemplate <class T, std::size_t B=\
    \ 700> class SortedPerBucket {\n static constexpr T INF= std::numeric_limits<T>::max()\
    \ / 2;\n struct Dat {\n  const std::size_t n;\n  std::array<T, B> a, sorted;\n\
    \  std::array<T, B + 1> acc;\n  T add, lb, ub;\n  Dat(std::size_t b): n(b), a{0},\
    \ sorted{0}, acc{0}, add(0), lb(-INF), ub(INF) {}\n  Dat(const T *bg, std::size_t\
    \ b): n(b), a{0}, acc{0}, add(0), lb(-INF), ub(INF) {\n   for (int i= n; i--;)\
    \ a[i]= *(bg + i);\n   build();\n  }\n  inline bool eval() {\n   if (add == 0\
    \ && lb == -INF && ub == INF) return false;\n   for (auto &x: a) x= std::clamp(x,\
    \ lb, ub) + add;\n   return add= 0, lb= -INF, ub= INF, true;\n  }\n  inline void\
    \ build() {\n   sorted= a, std::sort(sorted.begin(), sorted.begin() + n);\n  \
    \ std::partial_sum(sorted.begin(), sorted.begin() + n, acc.begin() + 1);\n  }\n\
    \  inline std::size_t idx(T x) const { return std::lower_bound(sorted.begin(),\
    \ sorted.begin() + n, x) - sorted.begin(); }\n  inline std::size_t count(T x)\
    \ const { return x-= add, (x <= lb ? 0 : ub < x ? n : idx(x)); }\n  inline T sum()\
    \ const {\n   std::size_t l= idx(lb), u= idx(ub);\n   return acc[u] - acc[l] +\
    \ lb * l + ub * (n - u) + add * n;\n  }\n  inline T sum(T x) const {\n   if (x-=\
    \ add; x <= lb) return 0;\n   if (ub < x) return sum();\n   std::size_t l= idx(lb),\
    \ u= idx(x);\n   return acc[u] - acc[l] + lb * l + add * u;\n  }\n  inline T get(std::size_t\
    \ k) const { return std::clamp(a[k], lb, ub) + add; }\n };\n const std::size_t\
    \ n;\n std::vector<Dat> dat;\n template <class U, class All, class One> inline\
    \ U fold(std::size_t l, std::size_t r, const All &all, const One &one) const {\n\
    \  U ret= 0;\n  if (std::size_t i= l / B, j= r / B, k= l % B, m= r % B; i < j)\
    \ {\n   if (k) {\n    for (; k < dat[i].n; k++) ret+= one(dat[i].get(k));\n  \
    \  i++;\n   }\n   for (; i < j; i++) ret+= all(dat[i]);\n   if (m)\n    for (;\
    \ m--;) ret+= one(dat[j].get(m));\n  } else\n   for (; k < m; k++) ret+= one(dat[i].get(k));\n\
    \  return ret;\n }\n template <class All, class One> inline void update(std::size_t\
    \ l, std::size_t r, const All &all, const One &one) {\n  if (std::size_t i= l\
    \ / B, j= r / B, k= l % B, m= r % B; i < j) {\n   if (k) {\n    for (dat[i].eval();\
    \ k < dat[i].n; k++) one(dat[i].a[k]);\n    dat[i].build(), i++;\n   }\n   for\
    \ (; i < j; i++) all(dat[i]);\n   if (m) {\n    for (dat[j].eval(); m--;) one(dat[j].a[m]);\n\
    \    dat[j].build();\n   }\n  } else {\n   for (dat[i].eval(); k < m; k++) one(dat[i].a[k]);\n\
    \   dat[i].build();\n  }\n }\npublic:\n SortedPerBucket(std::size_t n_): n(n_)\
    \ {\n  for (int l= 0, r; l < n; l= r) r= std::min(l + B, n), dat.emplace_back(r\
    \ - l);\n }\n SortedPerBucket(const std::vector<T> &a): n(a.size()) {\n  for (int\
    \ l= 0, r; l < n; l= r) r= std::min(l + B, n), dat.emplace_back(a.data() + l,\
    \ r - l);\n }\n // count i s.t. (l <= i < r) && (a[i] < ub)\n std::size_t count(std::size_t\
    \ l, std::size_t r, T ub) const {\n  return fold<std::size_t>(\n      l, r, [&](const\
    \ Dat &d) { return d.count(ub); }, [&](T x) { return x < ub; });\n }\n // count\
    \ i s.t. (l <= i < r) && (lb <= a[i] < ub)\n std::size_t count(std::size_t l,\
    \ std::size_t r, T lb, T ub) const { return count(l, r, ub) - count(l, r, lb);\
    \ }\n // sum a[i] s.t. (l <= i < r)\n T sum(std::size_t l, std::size_t r) const\
    \ {\n  return fold<T>(\n      l, r, [&](const Dat &d) { return d.sum(); }, [&](T\
    \ x) { return x; });\n }\n // sum a[i] s.t. (l <= i < r) && (a[i] < ub)\n T sum(std::size_t\
    \ l, std::size_t r, T ub) const {\n  return fold<T>(\n      l, r, [&](const Dat\
    \ &d) { return d.sum(ub); }, [&](T x) { return x < ub ? x : 0; });\n }\n // sum\
    \ a[i] s.t. (l <= i < r)  && (lb <= a[i] < ub)\n T sum(std::size_t l, std::size_t\
    \ r, T lb, T ub) const { return sum(l, r, ub) - sum(l, r, lb); }\n void set(std::size_t\
    \ k, T x) {\n  std::size_t i= k / B, j= k % B;\n  dat[i].eval(), dat[i].a[j]=\
    \ x, dat[i].build();\n }\n T get(std::size_t k) const { return dat[k / B].get(k\
    \ % B); }\n T operator[](std::size_t k) const { return get(k); }\n void add(std::size_t\
    \ l, std::size_t r, T v) {\n  update(\n      l, r, [&](Dat &d) { d.add+= v; },\
    \ [&](T &x) { x+= v; });\n }\n void chmin(std::size_t l, std::size_t r, T ub)\
    \ {\n  auto f= [&](Dat &d) {\n   T b= ub - d.add;\n   d.ub= std::min(d.ub, b),\
    \ d.lb= std::min(d.lb, b);\n  };\n  update(l, r, f, [&](T &x) { x= std::min(x,\
    \ ub); });\n }\n void chmax(std::size_t l, std::size_t r, T lb) {\n  auto f= [&](Dat\
    \ &d) {\n   T a= lb - d.add;\n   d.lb= std::max(d.lb, a), d.ub= std::max(d.ub,\
    \ a);\n  };\n  update(l, r, f, [&](T &x) { x= std::max(x, lb); });\n }\n void\
    \ chclamp(std::size_t l, std::size_t r, T lb, T ub) {\n  auto f= [&](Dat &d) {\n\
    \   T a= lb - d.add, b= ub - d.add;\n   d.ub= std::clamp(d.ub, a, b), d.lb= std::clamp(d.lb,\
    \ a, b);\n  };\n  update(l, r, f, [&](T &x) { x= std::clamp(x, lb, ub); });\n\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SortedPerBucket.hpp
  requiredBy: []
  timestamp: '2022-12-31 23:54:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3170.test.cpp
  - test/yosupo/range_chmin_chmax_add_range_sum.SqrtDC.test.cpp
  - test/yukicoder/925.SqrtDC.test.cpp
  - test/hackerrank/library-query.SqrtDC.test.cpp
documentation_of: src/DataStructure/SortedPerBucket.hpp
layout: document
title: "\u5178\u578B\u7684\u306A\u5E73\u65B9\u5206\u5272"
---
## 計算量
 * set - $\mathcal{O}(B)$
 * add, chmin, chmax, chclamp - $\mathcal{O}(B \log B)$
 * get - $\mathcal{O}(1)$
 * count, sum - $\mathcal{O}(B + N/B \log B)$
## 参考
[https://rian.hatenablog.jp/entry/2020/10/01/001253](https://rian.hatenablog.jp/entry/2020/10/01/001253) \
[https://maspypy.com/yukicoder-no-925-%e7%b4%b2%e6%98%9f-extra](https://maspypy.com/yukicoder-no-925-%e7%b4%b2%e6%98%9f-extra)
