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
    PROBLEM: https://atcoder.jp/contests/abc218/tasks/abc218_h
    links:
    - https://atcoder.jp/contests/abc218/tasks/abc218_h
  bundledCode: "#line 1 \"test/atcoder/abc218_h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc218/tasks/abc218_h\"\
    \n// Alien DP\n#include <iostream>\n#include <algorithm>\n#line 3 \"src/Optimization/fibonacci_search.hpp\"\
    \n#include <cassert>\n#line 2 \"src/Internal/function_type.hpp\"\n#include <type_traits>\n\
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
    }\n#line 6 \"test/atcoder/abc218_h.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, R;\n cin >> N >> R;\n\
    \ if (R > N - R) R= N - R;\n long long A[N - 1];\n for (int i= 0; i < N - 1; ++i)\
    \ cin >> A[i];\n long long B[N];\n fill_n(B, N, 0);\n for (int i= 0; i < N - 1;\
    \ ++i) B[i]+= A[i], B[i + 1]+= A[i];\n auto f= [&](long long p) {\n  long long\
    \ dp[N + 1][2];\n  dp[0][0]= 0, dp[0][1]= -1e18;\n  for (int i= 0; i < N; ++i)\
    \ {\n   dp[i + 1][1]= dp[i][0] + B[i] - p;\n   dp[i + 1][0]= max(dp[i][0], dp[i][1]);\n\
    \  }\n  return max(dp[N][0], dp[N][1]) + p * R;\n };\n auto a= *max_element(B,\
    \ B + N);\n auto [_, ans]= fibonacci_search<MINIMIZE>(f, -3 * a, 3 * a);\n cout\
    \ << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc218/tasks/abc218_h\"\n//\
    \ Alien DP\n#include <iostream>\n#include <algorithm>\n#include \"src/Optimization/fibonacci_search.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, R;\n cin >> N >> R;\n if (R > N - R) R= N - R;\n long long A[N - 1];\n\
    \ for (int i= 0; i < N - 1; ++i) cin >> A[i];\n long long B[N];\n fill_n(B, N,\
    \ 0);\n for (int i= 0; i < N - 1; ++i) B[i]+= A[i], B[i + 1]+= A[i];\n auto f=\
    \ [&](long long p) {\n  long long dp[N + 1][2];\n  dp[0][0]= 0, dp[0][1]= -1e18;\n\
    \  for (int i= 0; i < N; ++i) {\n   dp[i + 1][1]= dp[i][0] + B[i] - p;\n   dp[i\
    \ + 1][0]= max(dp[i][0], dp[i][1]);\n  }\n  return max(dp[N][0], dp[N][1]) + p\
    \ * R;\n };\n auto a= *max_element(B, B + N);\n auto [_, ans]= fibonacci_search<MINIMIZE>(f,\
    \ -3 * a, 3 * a);\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/fibonacci_search.hpp
  - src/Internal/function_type.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: true
  path: test/atcoder/abc218_h.test.cpp
  requiredBy: []
  timestamp: '2023-10-17 01:28:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc218_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc218_h.test.cpp
- /verify/test/atcoder/abc218_h.test.cpp.html
title: test/atcoder/abc218_h.test.cpp
---