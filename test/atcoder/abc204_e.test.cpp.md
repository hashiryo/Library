---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/function_type.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  - icon: ':question:'
    path: src/Optimization/fibonacci_search.hpp
    title: "\u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc204/tasks/abc204_e
    links:
    - https://atcoder.jp/contests/abc204/tasks/abc204_e
  bundledCode: "#line 1 \"test/atcoder/abc204_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc204/tasks/abc204_e\"\
    \n#include <iostream>\n#include <vector>\n#include <queue>\n#include <cmath>\n\
    #line 2 \"src/Optimization/fibonacci_search.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#line 2 \"src/Internal/function_type.hpp\"\n#include <type_traits>\n\
    namespace function_template_internal {\ntemplate <class C> struct is_function_object\
    \ {\n template <class U, int dummy= (&U::operator(), 0)> static std::true_type\
    \ check(U *);\n static std::false_type check(...);\n static C *m;\n static constexpr\
    \ bool value= decltype(check(m))::value;\n};\ntemplate <class F, bool, bool> struct\
    \ function_type_impl {\n using type= void;\n};\ntemplate <class F> struct function_type_impl<F,\
    \ true, false> {\n using type= F *;\n};\ntemplate <class F> struct function_type_impl<F,\
    \ false, true> {\n using type= decltype(&F::operator());\n};\ntemplate <class\
    \ F> using function_type_t= typename function_type_impl<F, std::is_function_v<F>,\
    \ is_function_object<F>::value>::type;\ntemplate <class... Args> struct result_type_impl\
    \ {\n using type= void;\n};\ntemplate <class R, class... Args> struct result_type_impl<R\
    \ (*)(Args...)> {\n using type= R;\n};\ntemplate <class C, class R, class... Args>\
    \ struct result_type_impl<R (C::*)(Args...)> {\n using type= R;\n};\ntemplate\
    \ <class C, class R, class... Args> struct result_type_impl<R (C::*)(Args...)\
    \ const> {\n using type= R;\n};\ntemplate <class F> using result_type_t= typename\
    \ result_type_impl<function_type_t<F>>::type;\ntemplate <class... Args> struct\
    \ argument_type_impl {\n using type= void;\n};\ntemplate <class R, class... Args>\
    \ struct argument_type_impl<R (*)(Args...)> {\n using type= std::tuple<Args...>;\n\
    };\ntemplate <class C, class R, class... Args> struct argument_type_impl<R (C::*)(Args...)>\
    \ {\n using type= std::tuple<Args...>;\n};\ntemplate <class C, class R, class...\
    \ Args> struct argument_type_impl<R (C::*)(Args...) const> {\n using type= std::tuple<Args...>;\n\
    };\ntemplate <class F> using argument_type_t= typename argument_type_impl<function_type_t<F>>::type;\n\
    template <class T> struct other_than_first_argument_type_impl {\n using type=\
    \ void;\n};\ntemplate <class T, class... Args> struct other_than_first_argument_type_impl<std::tuple<T,\
    \ Args...>> {\n using type= std::tuple<Args...>;\n};\ntemplate <class T> using\
    \ other_than_first_argument_type_t= typename other_than_first_argument_type_impl<T>::type;\n\
    }\nusing function_template_internal::result_type_t, function_template_internal::argument_type_t,\
    \ function_template_internal::other_than_first_argument_type_t;\n#line 2 \"src/Optimization/MinMaxEnum.hpp\"\
    \nenum MinMaxEnum { MAXIMIZE= -1, MINIMIZE= 1 };\n#line 6 \"src/Optimization/fibonacci_search.hpp\"\
    \n// [l,r]\ntemplate <MinMaxEnum obj, class F> std::pair<int64_t, result_type_t<F>>\
    \ fibonacci_search(const F &f, int64_t l, int64_t r) {\n assert(l <= r);\n int64_t\
    \ s= 1, t= 2, a= l - 1, x, b, y;\n for (int64_t e= r - l + 2; t < e;) std::swap(s+=\
    \ t, t);\n b= a + t, x= b - s;\n result_type_t<F> fx= f(x), fy;\n for (bool g;\
    \ a + b != 2 * x;) {\n  if (y= a + b - x; r < y) b= a, a= y;\n  else {\n   if\
    \ constexpr (obj == MINIMIZE) g= fx < (fy= f(y));\n   else g= fx > (fy= f(y));\n\
    \   if (g) b= a, a= y;\n   else a= x, x= y, fx= fy;\n  }\n }\n return {x, fx};\n\
    }\n#line 7 \"test/atcoder/abc204_e.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n cin >> N >> M;\n int\
    \ A[M], B[M];\n long long C[M], D[M];\n vector<int> adj[N];\n for (int i= 0; i\
    \ < M; ++i) {\n  cin >> A[i] >> B[i] >> C[i] >> D[i], --A[i], --B[i];\n  adj[A[i]].push_back(i),\
    \ adj[B[i]].push_back(i);\n }\n priority_queue<pair<long long, int>> pq;\n static\
    \ constexpr long long INF= 1e18;\n long long dist[N];\n fill_n(dist, N, INF);\n\
    \ dist[0]= 0, pq.emplace(0, 0);\n while (!pq.empty()) {\n  auto [d, u]= pq.top();\n\
    \  pq.pop();\n  d= -d;\n  if (dist[u] != d) continue;\n  for (auto e: adj[u])\
    \ {\n   int v= A[e] ^ B[e] ^ u;\n   auto f= [&](long long t) { return t + C[e]\
    \ + double(D[e]) / (t + 1); };\n   auto [_, nd_f]= fibonacci_search<MINIMIZE>(f,\
    \ d, max(d, D[e]));\n   long long nd= floor(nd_f) + 0.5;\n   if (dist[v] > nd)\
    \ dist[v]= nd, pq.emplace(-nd, v);\n  }\n }\n cout << (dist[N - 1] == INF ? -1\
    \ : dist[N - 1]) << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc204/tasks/abc204_e\"\n#include\
    \ <iostream>\n#include <vector>\n#include <queue>\n#include <cmath>\n#include\
    \ \"src/Optimization/fibonacci_search.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n cin >> N >> M;\n int\
    \ A[M], B[M];\n long long C[M], D[M];\n vector<int> adj[N];\n for (int i= 0; i\
    \ < M; ++i) {\n  cin >> A[i] >> B[i] >> C[i] >> D[i], --A[i], --B[i];\n  adj[A[i]].push_back(i),\
    \ adj[B[i]].push_back(i);\n }\n priority_queue<pair<long long, int>> pq;\n static\
    \ constexpr long long INF= 1e18;\n long long dist[N];\n fill_n(dist, N, INF);\n\
    \ dist[0]= 0, pq.emplace(0, 0);\n while (!pq.empty()) {\n  auto [d, u]= pq.top();\n\
    \  pq.pop();\n  d= -d;\n  if (dist[u] != d) continue;\n  for (auto e: adj[u])\
    \ {\n   int v= A[e] ^ B[e] ^ u;\n   auto f= [&](long long t) { return t + C[e]\
    \ + double(D[e]) / (t + 1); };\n   auto [_, nd_f]= fibonacci_search<MINIMIZE>(f,\
    \ d, max(d, D[e]));\n   long long nd= floor(nd_f) + 0.5;\n   if (dist[v] > nd)\
    \ dist[v]= nd, pq.emplace(-nd, v);\n  }\n }\n cout << (dist[N - 1] == INF ? -1\
    \ : dist[N - 1]) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/fibonacci_search.hpp
  - src/Internal/function_type.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: true
  path: test/atcoder/abc204_e.test.cpp
  requiredBy: []
  timestamp: '2023-10-17 01:28:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc204_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc204_e.test.cpp
- /verify/test/atcoder/abc204_e.test.cpp.html
title: test/atcoder/abc204_e.test.cpp
---
