---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/SortedPerBucket.hpp
    title: "\u5178\u578B\u7684\u306A\u5E73\u65B9\u5206\u5272"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/challenges/library-query/problem
    links:
    - https://www.hackerrank.com/challenges/library-query/problem
  bundledCode: "#line 1 \"test/hackerrank/library-query.SqrtDC.test.cpp\"\n#define\
    \ PROBLEM \"https://www.hackerrank.com/challenges/library-query/problem\"\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"src/DataStructure/SortedPerBucket.hpp\"\
    \n#include <limits>\n#include <algorithm>\n#include <array>\n#line 6 \"src/DataStructure/SortedPerBucket.hpp\"\
    \n#include <numeric>\ntemplate <class T, size_t B= 700> class SortedPerBucket\
    \ {\n static constexpr T INF= std::numeric_limits<T>::max() / 2;\n struct Dat\
    \ {\n  const size_t n;\n  T a[B], sorted[B], acc[B + 1];\n  T add, lb, ub;\n \
    \ Dat(size_t b): n(b), a{0}, sorted{0}, acc{0}, add(0), lb(-INF), ub(INF) {}\n\
    \  Dat(const T *bg, size_t b): n(b), a{0}, acc{0}, add(0), lb(-INF), ub(INF) {\n\
    \   for (int i= n; i--;) a[i]= *(bg + i);\n   build();\n  }\n  inline bool eval()\
    \ {\n   if (add == 0 && lb == -INF && ub == INF) return false;\n   for (auto &x:\
    \ a) x= std::clamp(x, lb, ub) + add;\n   return add= 0, lb= -INF, ub= INF, true;\n\
    \  }\n  inline void build() { sorted= a, std::sort(sorted, sorted + n), std::partial_sum(sorted,\
    \ sorted + n, acc + 1); }\n  inline size_t idx(T x) const { return std::lower_bound(sorted,\
    \ sorted + n, x) - sorted; }\n  inline size_t count(T x) const { return x-= add,\
    \ (x <= lb ? 0 : ub < x ? n : idx(x)); }\n  inline T sum() const {\n   size_t\
    \ l= idx(lb), u= idx(ub);\n   return acc[u] - acc[l] + lb * l + ub * (n - u) +\
    \ add * n;\n  }\n  inline T sum(T x) const {\n   if (x-= add; x <= lb) return\
    \ 0;\n   if (ub < x) return sum();\n   size_t l= idx(lb), u= idx(x);\n   return\
    \ acc[u] - acc[l] + lb * l + add * u;\n  }\n  inline T get(size_t k) const { return\
    \ std::clamp(a[k], lb, ub) + add; }\n };\n const size_t n;\n std::vector<Dat>\
    \ dat;\n template <class U, class All, class One> inline U fold(size_t l, size_t\
    \ r, const All &all, const One &one) const {\n  U ret= 0;\n  if (size_t i= l /\
    \ B, j= r / B, k= l % B, m= r % B; i < j) {\n   if (k) {\n    for (; k < dat[i].n;\
    \ k++) ret+= one(dat[i].get(k));\n    i++;\n   }\n   for (; i < j; i++) ret+=\
    \ all(dat[i]);\n   if (m)\n    for (; m--;) ret+= one(dat[j].get(m));\n  } else\n\
    \   for (; k < m; k++) ret+= one(dat[i].get(k));\n  return ret;\n }\n template\
    \ <class All, class One> inline void update(size_t l, size_t r, const All &all,\
    \ const One &one) {\n  if (size_t i= l / B, j= r / B, k= l % B, m= r % B; i <\
    \ j) {\n   if (k) {\n    for (dat[i].eval(); k < dat[i].n; k++) one(dat[i].a[k]);\n\
    \    dat[i].build(), i++;\n   }\n   for (; i < j; i++) all(dat[i]);\n   if (m)\
    \ {\n    for (dat[j].eval(); m--;) one(dat[j].a[m]);\n    dat[j].build();\n  \
    \ }\n  } else {\n   for (dat[i].eval(); k < m; k++) one(dat[i].a[k]);\n   dat[i].build();\n\
    \  }\n }\npublic:\n SortedPerBucket(size_t n): n(n) {\n  for (int l= 0, r; l <\
    \ n; l= r) r= std::min(l + B, n), dat.emplace_back(r - l);\n }\n SortedPerBucket(const\
    \ std::vector<T> &a): n(a.size()) {\n  for (int l= 0, r; l < n; l= r) r= std::min(l\
    \ + B, n), dat.emplace_back(a.data() + l, r - l);\n }\n // count i s.t. (l <=\
    \ i < r) && (a[i] < ub)\n size_t count(size_t l, size_t r, T ub) const {\n  return\
    \ fold<size_t>(\n      l, r, [&](const Dat &d) { return d.count(ub); }, [&](T\
    \ x) { return x < ub; });\n }\n // count i s.t. (l <= i < r) && (lb <= a[i] <\
    \ ub)\n size_t count(size_t l, size_t r, T lb, T ub) const { return count(l, r,\
    \ ub) - count(l, r, lb); }\n // sum a[i] s.t. (l <= i < r)\n T sum(size_t l, size_t\
    \ r) const {\n  return fold<T>(\n      l, r, [&](const Dat &d) { return d.sum();\
    \ }, [&](T x) { return x; });\n }\n // sum a[i] s.t. (l <= i < r) && (a[i] < ub)\n\
    \ T sum(size_t l, size_t r, T ub) const {\n  return fold<T>(\n      l, r, [&](const\
    \ Dat &d) { return d.sum(ub); }, [&](T x) { return x < ub ? x : 0; });\n }\n //\
    \ sum a[i] s.t. (l <= i < r)  && (lb <= a[i] < ub)\n T sum(size_t l, size_t r,\
    \ T lb, T ub) const { return sum(l, r, ub) - sum(l, r, lb); }\n void set(size_t\
    \ k, T x) {\n  auto [i, j]= div(k, B);\n  dat[i].eval(), dat[i].a[j]= x, dat[i].build();\n\
    \ }\n T get(size_t k) const { return dat[k / B].get(k % B); }\n T operator[](size_t\
    \ k) const { return get(k); }\n void add(size_t l, size_t r, T v) {\n  update(\n\
    \      l, r, [&](Dat &d) { d.add+= v; }, [&](T &x) { x+= v; });\n }\n void chmin(size_t\
    \ l, size_t r, T ub) {\n  auto f= [&](Dat &d) {\n   T b= ub - d.add;\n   d.ub=\
    \ std::min(d.ub, b), d.lb= std::min(d.lb, b);\n  };\n  update(l, r, f, [&](T &x)\
    \ { x= std::min(x, ub); });\n }\n void chmax(size_t l, size_t r, T lb) {\n  auto\
    \ f= [&](Dat &d) {\n   T a= lb - d.add;\n   d.lb= std::max(d.lb, a), d.ub= std::max(d.ub,\
    \ a);\n  };\n  update(l, r, f, [&](T &x) { x= std::max(x, lb); });\n }\n void\
    \ chclamp(size_t l, size_t r, T lb, T ub) {\n  auto f= [&](Dat &d) {\n   T a=\
    \ lb - d.add, b= ub - d.add;\n   d.ub= std::clamp(d.ub, a, b), d.lb= std::clamp(d.lb,\
    \ a, b);\n  };\n  update(l, r, f, [&](T &x) { x= std::clamp(x, lb, ub); });\n\
    \ }\n};\n#line 5 \"test/hackerrank/library-query.SqrtDC.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int T;\n bool\
    \ first= true;\n for (cin >> T; T--;) {\n  int N;\n  cin >> N;\n  vector<int>\
    \ a(N);\n  for (int i= 0; i < N; i++) cin >> a[i];\n  SortedPerBucket<int, 50>\
    \ sqrtdc(a);\n  int Q;\n  cin >> Q;\n  while (Q--) {\n   int type;\n   cin >>\
    \ type;\n   if (type) {\n    int x, k;\n    cin >> x >> k, x--;\n    sqrtdc.set(x,\
    \ k);\n   } else {\n    int x, y, k;\n    cin >> x >> y >> k, x--;\n    int ok=\
    \ 0, ng= 1010;\n    while (abs(ok - ng) > 1) {\n     int t= (ok + ng) / 2;\n \
    \    (sqrtdc.count(x, y, t) < k ? ok : ng)= t;\n    }\n    if (!first) cout <<\
    \ '\\n';\n    first= false;\n    cout << ok;\n   }\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/challenges/library-query/problem\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/DataStructure/SortedPerBucket.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int T;\n bool first= true;\n for (cin >> T; T--;) {\n  int N;\n  cin >> N;\n\
    \  vector<int> a(N);\n  for (int i= 0; i < N; i++) cin >> a[i];\n  SortedPerBucket<int,\
    \ 50> sqrtdc(a);\n  int Q;\n  cin >> Q;\n  while (Q--) {\n   int type;\n   cin\
    \ >> type;\n   if (type) {\n    int x, k;\n    cin >> x >> k, x--;\n    sqrtdc.set(x,\
    \ k);\n   } else {\n    int x, y, k;\n    cin >> x >> y >> k, x--;\n    int ok=\
    \ 0, ng= 1010;\n    while (abs(ok - ng) > 1) {\n     int t= (ok + ng) / 2;\n \
    \    (sqrtdc.count(x, y, t) < k ? ok : ng)= t;\n    }\n    if (!first) cout <<\
    \ '\\n';\n    first= false;\n    cout << ok;\n   }\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SortedPerBucket.hpp
  isVerificationFile: true
  path: test/hackerrank/library-query.SqrtDC.test.cpp
  requiredBy: []
  timestamp: '2023-10-13 01:19:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/hackerrank/library-query.SqrtDC.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/library-query.SqrtDC.test.cpp
- /verify/test/hackerrank/library-query.SqrtDC.test.cpp.html
title: test/hackerrank/library-query.SqrtDC.test.cpp
---
