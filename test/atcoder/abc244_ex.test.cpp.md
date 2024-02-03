---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Optimization/ConvexHullTrick.hpp
    title: Convex-Hull-Trick
  - icon: ':question:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc244/tasks/abc244_Ex
    links:
    - https://atcoder.jp/contests/abc244/tasks/abc244_Ex
    - https://atcoder.jp/contests/abc244/tasks/abc244_h
  bundledCode: "#line 1 \"test/atcoder/abc244_ex.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc244/tasks/abc244_Ex\"\
    \n// https://atcoder.jp/contests/abc244/tasks/abc244_h\n#include <iostream>\n\
    #line 2 \"src/Optimization/ConvexHullTrick.hpp\"\n#include <limits>\n#include\
    \ <algorithm>\n#include <set>\n#include <array>\n#include <cassert>\n#line 2 \"\
    src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum { MAXIMIZE= -1, MINIMIZE= 1\
    \ };\n#line 8 \"src/Optimization/ConvexHullTrick.hpp\"\ntemplate <typename T,\
    \ MinMaxEnum obj= MINIMIZE> class ConvexHullTrick {\n struct Line {\n  T k, m;\n\
    \  mutable T p;\n  bool operator<(const Line &o) const { return k < o.k; }\n \
    \ bool operator<(T x) const { return p < x; }\n };\n static constexpr T INF= std::numeric_limits<T>::max();\n\
    \ static T lc_div(T a, T b) {\n  if constexpr (std::is_integral_v<T>) return a\
    \ / b - ((a ^ b) < 0 && a % b);\n  else return a / b;\n }\n using ms= std::multiset<Line,\
    \ std::less<>>;\n ms ls;\n bool insect(typename ms::iterator x, typename ms::iterator\
    \ y) {\n  if (y == ls.end()) return x->p= INF, false;\n  if (x->k == y->k) x->p=\
    \ (x->m > y->m ? INF : -INF);\n  else x->p= lc_div(y->m - x->m, x->k - y->k);\n\
    \  return x->p >= y->p;\n }\npublic:\n void insert(T k, T m) {\n  if constexpr\
    \ (obj == MINIMIZE) k= -k, m= -m;\n  auto z= ls.insert({k, m, 0}), y= z++, x=\
    \ y;\n  while (insect(y, z)) z= ls.erase(z);\n  if (x != ls.begin() && insect(--x,\
    \ y)) insect(x, y= ls.erase(y));\n  while ((y= x) != ls.begin() && (--x)->p >=\
    \ y->p) insect(x, ls.erase(y));\n }\n bool empty() const { return ls.empty();\
    \ }\n std::array<T, 2> query_line(T x) const {\n  assert(!ls.empty());\n  auto\
    \ l= ls.lower_bound(x);\n  if constexpr (obj == MINIMIZE) return {-l->k, -l->m};\n\
    \  else return {l->k, l->m};\n }\n T query(T x) const {\n  auto [k, m]= query_line(x);\n\
    \  return k * x + m;\n }\n};\ntemplate <typename T> class ConvexHullTrick_XY {\n\
    \ ConvexHullTrick<long double, MINIMIZE> cht_mn;\n ConvexHullTrick<long double,\
    \ MAXIMIZE> cht_mx;\n T amx= std::numeric_limits<T>::lowest(), amn= std::numeric_limits<T>::max();\n\
    public:\n void insert(T a, T b) { cht_mn.insert(a, b), cht_mx.insert(a, b), amn=\
    \ std::min(amn, a), amx= std::max(amx, a); }\n bool empty() const { return cht_mn.empty();\
    \ }\n T get_max(T x, T y) const {\n  assert(!cht_mn.empty());\n  if (y == 0) return\
    \ std::max(amn * x, amx * x);\n  auto z= (long double)x / y;\n  auto [a, b]= y\
    \ > 0 ? cht_mx.query_line(z) : cht_mn.query_line(z);\n  return T(a) * x + T(b)\
    \ * y;\n }\n T get_min(T x, T y) const {\n  assert(!cht_mn.empty());\n  if (y\
    \ == 0) return std::min(amn * x, amx * x);\n  auto z= (long double)x / y;\n  auto\
    \ [a, b]= y > 0 ? cht_mn.query_line(z) : cht_mx.query_line(z);\n  return T(a)\
    \ * x + T(b) * y;\n }\n};\n#line 5 \"test/atcoder/abc244_ex.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ Q;\n cin >> Q;\n ConvexHullTrick_XY<int64_t> cht;\n while (Q--) {\n  int X,\
    \ Y, A, B;\n  cin >> X >> Y >> A >> B;\n  cht.insert(X, Y);\n  cout << cht.get_max(A,\
    \ B) << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc244/tasks/abc244_Ex\"\n\
    // https://atcoder.jp/contests/abc244/tasks/abc244_h\n#include <iostream>\n#include\
    \ \"src/Optimization/ConvexHullTrick.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int Q;\n cin >> Q;\n ConvexHullTrick_XY<int64_t>\
    \ cht;\n while (Q--) {\n  int X, Y, A, B;\n  cin >> X >> Y >> A >> B;\n  cht.insert(X,\
    \ Y);\n  cout << cht.get_max(A, B) << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Optimization/ConvexHullTrick.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: true
  path: test/atcoder/abc244_ex.test.cpp
  requiredBy: []
  timestamp: '2024-02-03 19:27:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc244_ex.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc244_ex.test.cpp
- /verify/test/atcoder/abc244_ex.test.cpp.html
title: test/atcoder/abc244_ex.test.cpp
---
