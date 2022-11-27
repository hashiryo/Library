---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SortedPerBucket.hpp
    title: "\u5178\u578B\u7684\u306A\u5E73\u65B9\u5206\u5272"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/challenges/library-query/problem
    links:
    - https://www.hackerrank.com/challenges/library-query/problem
  bundledCode: "#line 1 \"test/hackerrank/library-query.SqrtDC.test.cpp\"\n#define\
    \ PROBLEM \"https://www.hackerrank.com/challenges/library-query/problem\"\n\n\
    #include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SortedPerBucket.hpp\"\n\
    /**\n * @title \u5178\u578B\u7684\u306A\u5E73\u65B9\u5206\u5272\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @see https://rian.hatenablog.jp/entry/2020/10/01/001253\n\
    \ * @see https://maspypy.com/yukicoder-no-925-%e7%b4%b2%e6%98%9f-extra\n * set\
    \ - O(B)\n * add, chmin, chmax, chclamp - O(B log B)\n * get - O(1)\n * count,\
    \ sum - O(B + N/B log B)\n */\n\n// BEGIN CUT HERE\ntemplate <class T, std::size_t\
    \ B = 700>\nclass SortedPerBucket {\n  static constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n  struct Dat {\n    const std::size_t n;\n    std::array<T, B> a, sorted;\n\
    \    std::array<T, B + 1> acc;\n    T add, lb, ub;\n    Dat(std::size_t b)\n \
    \       : n(b), a{0}, sorted{0}, acc{0}, add(0), lb(-INF), ub(INF) {}\n    Dat(const\
    \ T *bg, std::size_t b)\n        : n(b), a{0}, acc{0}, add(0), lb(-INF), ub(INF)\
    \ {\n      for (int i = n; i--;) a[i] = *(bg + i);\n      build();\n    }\n  \
    \  inline bool eval() {\n      if (add == 0 && lb == -INF && ub == INF) return\
    \ false;\n      for (auto &x : a) x = std::clamp(x, lb, ub) + add;\n      return\
    \ add = 0, lb = -INF, ub = INF, true;\n    }\n    inline void build() {\n    \
    \  sorted = a, std::sort(sorted.begin(), sorted.begin() + n);\n      std::partial_sum(sorted.begin(),\
    \ sorted.begin() + n, acc.begin() + 1);\n    }\n    inline std::size_t idx(T x)\
    \ const {\n      return std::lower_bound(sorted.begin(), sorted.begin() + n, x)\
    \ -\n             sorted.begin();\n    }\n    inline std::size_t count(T x) const\
    \ {\n      return x -= add, (x <= lb ? 0 : ub < x ? n : idx(x));\n    }\n    inline\
    \ T sum() const {\n      std::size_t l = idx(lb), u = idx(ub);\n      return acc[u]\
    \ - acc[l] + lb * l + ub * (n - u) + add * n;\n    }\n    inline T sum(T x) const\
    \ {\n      if (x -= add; x <= lb) return 0;\n      if (ub < x) return sum();\n\
    \      std::size_t l = idx(lb), u = idx(x);\n      return acc[u] - acc[l] + lb\
    \ * l + add * u;\n    }\n    inline T get(std::size_t k) const { return std::clamp(a[k],\
    \ lb, ub) + add; }\n  };\n  const std::size_t n;\n  std::vector<Dat> dat;\n  template\
    \ <class U, class All, class One>\n  inline U fold(std::size_t l, std::size_t\
    \ r, const All &all,\n                const One &one) const {\n    U ret = 0;\n\
    \    if (std::size_t i = l / B, j = r / B, k = l % B, m = r % B; i < j) {\n  \
    \    if (k) {\n        for (; k < dat[i].n; k++) ret += one(dat[i].get(k));\n\
    \        i++;\n      }\n      for (; i < j; i++) ret += all(dat[i]);\n      if\
    \ (m)\n        for (; m--;) ret += one(dat[j].get(m));\n    } else\n      for\
    \ (; k < m; k++) ret += one(dat[i].get(k));\n    return ret;\n  }\n  template\
    \ <class All, class One>\n  inline void update(std::size_t l, std::size_t r, const\
    \ All &all,\n                     const One &one) {\n    if (std::size_t i = l\
    \ / B, j = r / B, k = l % B, m = r % B; i < j) {\n      if (k) {\n        for\
    \ (dat[i].eval(); k < dat[i].n; k++) one(dat[i].a[k]);\n        dat[i].build(),\
    \ i++;\n      }\n      for (; i < j; i++) all(dat[i]);\n      if (m) {\n     \
    \   for (dat[j].eval(); m--;) one(dat[j].a[m]);\n        dat[j].build();\n   \
    \   }\n    } else {\n      for (dat[i].eval(); k < m; k++) one(dat[i].a[k]);\n\
    \      dat[i].build();\n    }\n  }\n\n public:\n  SortedPerBucket(std::size_t\
    \ n_) : n(n_) {\n    for (int l = 0, r; l < n; l = r)\n      r = std::min(l +\
    \ B, n), dat.emplace_back(r - l);\n  }\n  SortedPerBucket(const std::vector<T>\
    \ &a) : n(a.size()) {\n    for (int l = 0, r; l < n; l = r)\n      r = std::min(l\
    \ + B, n), dat.emplace_back(a.data() + l, r - l);\n  }\n  // count i s.t. (l <=\
    \ i < r) && (a[i] < ub)\n  std::size_t count(std::size_t l, std::size_t r, T ub)\
    \ const {\n    return fold<std::size_t>(\n        l, r, [&](const Dat &d) { return\
    \ d.count(ub); },\n        [&](T x) { return x < ub; });\n  }\n  // count i s.t.\
    \ (l <= i < r) && (lb <= a[i] < ub)\n  std::size_t count(std::size_t l, std::size_t\
    \ r, T lb, T ub) const {\n    return count(l, r, ub) - count(l, r, lb);\n  }\n\
    \  // sum a[i] s.t. (l <= i < r)\n  T sum(std::size_t l, std::size_t r) const\
    \ {\n    return fold<T>(\n        l, r, [&](const Dat &d) { return d.sum(); },\
    \ [&](T x) { return x; });\n  }\n  // sum a[i] s.t. (l <= i < r) && (a[i] < ub)\n\
    \  T sum(std::size_t l, std::size_t r, T ub) const {\n    return fold<T>(\n  \
    \      l, r, [&](const Dat &d) { return d.sum(ub); },\n        [&](T x) { return\
    \ x < ub ? x : 0; });\n  }\n  // sum a[i] s.t. (l <= i < r)  && (lb <= a[i] <\
    \ ub)\n  T sum(std::size_t l, std::size_t r, T lb, T ub) const {\n    return sum(l,\
    \ r, ub) - sum(l, r, lb);\n  }\n  void set(std::size_t k, T x) {\n    std::size_t\
    \ i = k / B, j = k % B;\n    dat[i].eval(), dat[i].a[j] = x, dat[i].build();\n\
    \  }\n  T get(std::size_t k) const { return dat[k / B].get(k % B); }\n  T operator[](std::size_t\
    \ k) const { return get(k); }\n  void add(std::size_t l, std::size_t r, T v) {\n\
    \    update(\n        l, r, [&](Dat &d) { d.add += v; }, [&](T &x) { x += v; });\n\
    \  }\n  void chmin(std::size_t l, std::size_t r, T ub) {\n    auto f = [&](Dat\
    \ &d) {\n      T b = ub - d.add;\n      d.ub = std::min(d.ub, b), d.lb = std::min(d.lb,\
    \ b);\n    };\n    update(l, r, f, [&](T &x) { x = std::min(x, ub); });\n  }\n\
    \  void chmax(std::size_t l, std::size_t r, T lb) {\n    auto f = [&](Dat &d)\
    \ {\n      T a = lb - d.add;\n      d.lb = std::max(d.lb, a), d.ub = std::max(d.ub,\
    \ a);\n    };\n    update(l, r, f, [&](T &x) { x = std::max(x, lb); });\n  }\n\
    \  void chclamp(std::size_t l, std::size_t r, T lb, T ub) {\n    auto f = [&](Dat\
    \ &d) {\n      T a = lb - d.add, b = ub - d.add;\n      d.ub = std::clamp(d.ub,\
    \ a, b), d.lb = std::clamp(d.lb, a, b);\n    };\n    update(l, r, f, [&](T &x)\
    \ { x = std::clamp(x, lb, ub); });\n  }\n};\n#line 5 \"test/hackerrank/library-query.SqrtDC.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int T;\n  bool first = true;\n  for (cin >> T; T--;) {\n    int N;\n    cin\
    \ >> N;\n    vector<int> a(N);\n    for (int i = 0; i < N; i++) cin >> a[i];\n\
    \    SortedPerBucket<int, 50> sqrtdc(a);\n    int Q;\n    cin >> Q;\n    while\
    \ (Q--) {\n      int type;\n      cin >> type;\n      if (type) {\n        int\
    \ x, k;\n        cin >> x >> k, x--;\n        sqrtdc.set(x, k);\n      } else\
    \ {\n        int x, y, k;\n        cin >> x >> y >> k, x--;\n        int ok =\
    \ 0, ng = 1010;\n        while (abs(ok - ng) > 1) {\n          int t = (ok + ng)\
    \ / 2;\n          (sqrtdc.count(x, y, t) < k ? ok : ng) = t;\n        }\n    \
    \    if (!first) cout << '\\n';\n        first = false;\n        cout << ok;\n\
    \      }\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/challenges/library-query/problem\"\
    \n\n#include <bits/stdc++.h>\n#include \"src/DataStructure/SortedPerBucket.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int T;\n  bool first = true;\n  for (cin >> T; T--;) {\n    int N;\n    cin\
    \ >> N;\n    vector<int> a(N);\n    for (int i = 0; i < N; i++) cin >> a[i];\n\
    \    SortedPerBucket<int, 50> sqrtdc(a);\n    int Q;\n    cin >> Q;\n    while\
    \ (Q--) {\n      int type;\n      cin >> type;\n      if (type) {\n        int\
    \ x, k;\n        cin >> x >> k, x--;\n        sqrtdc.set(x, k);\n      } else\
    \ {\n        int x, y, k;\n        cin >> x >> y >> k, x--;\n        int ok =\
    \ 0, ng = 1010;\n        while (abs(ok - ng) > 1) {\n          int t = (ok + ng)\
    \ / 2;\n          (sqrtdc.count(x, y, t) < k ? ok : ng) = t;\n        }\n    \
    \    if (!first) cout << '\\n';\n        first = false;\n        cout << ok;\n\
    \      }\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/SortedPerBucket.hpp
  isVerificationFile: true
  path: test/hackerrank/library-query.SqrtDC.test.cpp
  requiredBy: []
  timestamp: '2022-11-27 19:11:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/hackerrank/library-query.SqrtDC.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/library-query.SqrtDC.test.cpp
- /verify/test/hackerrank/library-query.SqrtDC.test.cpp.html
title: test/hackerrank/library-query.SqrtDC.test.cpp
---
