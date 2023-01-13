---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Automaton/DFA_Compress.hpp
    title: "\u72B6\u614B\u3092int\u3067\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: src/Automaton/NFA_to_DFA.hpp
    title: "NFA\u3092DFA\u306B\u5909\u63DB"
  - icon: ':question:'
    path: src/Automaton/dfa_operations.hpp
    title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u96C6\u5408\
      \u6F14\u7B97"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2587.test.cpp
    title: test/aoj/2587.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc117_d.test.cpp
    title: test/atcoder/abc117_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc129_e.test.cpp
    title: test/atcoder/abc129_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc138_f.test.cpp
    title: test/atcoder/abc138_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc154_e.test.cpp
    title: test/atcoder/abc154_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc208_e.test.cpp
    title: test/atcoder/abc208_e.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc235_f.test.cpp
    title: test/atcoder/abc235_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc015_d.test.cpp
    title: test/atcoder/agc015_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc127_a.test.cpp
    title: test/atcoder/arc127_a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Automaton/dfa_dp.hpp\"\n#include <bits/stdc++.h>\n#ifndef\
    \ HAS_CHECK\n#define HAS_CHECK(member, Dummy) \\\n template <class T> struct has_##member\
    \ { \\\n  template <class U, Dummy> static std::true_type check(U *); \\\n  static\
    \ std::false_type check(...); \\\n  static T *mClass; \\\n  static const bool\
    \ value= decltype(check(mClass))::value; \\\n };\n#define HAS_MEMBER(member) HAS_CHECK(member,\
    \ int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class\
    \ dummy= typename U::member)\n#endif\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\n\
    HAS_MEMBER(initial_state);\nHAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\n\
    HAS_MEMBER(state_size);\nHAS_MEMBER(eps_transition);\nHAS_MEMBER(is_reject);\n\
    #undef HAS_TYPE\n#undef HAS_MEMBER\n#undef HAS_CHECK\ntemplate <class A> using\
    \ is_automaton= std::conjunction<has_symbol_t<A>, has_alphabet<A>, has_initial_state<A>,\
    \ has_transition<A>, has_is_accept<A>>;\ntemplate <class A> using trans_t= std::invoke_result_t<decltype(&A::transition),\
    \ A, int, typename A::symbol_t, int>;\ntemplate <class DFA> constexpr bool is_dfa_v=\
    \ std::conjunction_v<has_state_size<DFA>, is_automaton<DFA>, std::is_same<trans_t<DFA>,\
    \ int>>;\ntemplate <class T, class DFA, class Add, class F> T dfa_dp(const DFA\
    \ &dfa, int len, const Add &add, const F &f, const T t0= T(0), const T init= T(1))\
    \ {\n static_assert(is_dfa_v<DFA>);\n const auto alphabet= dfa.alphabet();\n const\
    \ int S= dfa.state_size();\n std::vector<T> dp(S, t0);\n std::vector<char> visit(S,\
    \ false);\n dp[dfa.initial_state()]= init, visit[dfa.initial_state()]= true;\n\
    \ for (int i= 0; i < len; i++) {\n  std::vector<T> next(S, t0);\n  std::vector<char>\
    \ next_visit(S, false);\n  for (int s= S; s--;)\n   if (visit[s])\n    for (const\
    \ auto &a: alphabet)\n     if (int q= dfa.transition(s, a, i); q != -1) add(next[q],\
    \ f(dp[s], a, i)), next_visit[q]= true;\n  dp.swap(next), visit.swap(next_visit);\n\
    \ }\n T ret= t0;\n for (int s= S; s--;)\n  if (dfa.is_accept(s)) add(ret, dp[s]);\n\
    \ return ret;\n}\ntemplate <class T, class DFA> T dfa_dp(const DFA &dfa, int len,\
    \ const T t0= T(0), const T init= T(1)) {\n return dfa_dp<T>(\n     dfa, len,\
    \ [](T &l, const T &r) { l+= r; }, [](const T &v, const typename DFA::symbol_t\
    \ &, int) { return v; }, t0, init);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#ifndef HAS_CHECK\n#define HAS_CHECK(member,\
    \ Dummy) \\\n template <class T> struct has_##member { \\\n  template <class U,\
    \ Dummy> static std::true_type check(U *); \\\n  static std::false_type check(...);\
    \ \\\n  static T *mClass; \\\n  static const bool value= decltype(check(mClass))::value;\
    \ \\\n };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n\
    #endif\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\n\
    HAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\nHAS_MEMBER(state_size);\nHAS_MEMBER(eps_transition);\n\
    HAS_MEMBER(is_reject);\n#undef HAS_TYPE\n#undef HAS_MEMBER\n#undef HAS_CHECK\n\
    template <class A> using is_automaton= std::conjunction<has_symbol_t<A>, has_alphabet<A>,\
    \ has_initial_state<A>, has_transition<A>, has_is_accept<A>>;\ntemplate <class\
    \ A> using trans_t= std::invoke_result_t<decltype(&A::transition), A, int, typename\
    \ A::symbol_t, int>;\ntemplate <class DFA> constexpr bool is_dfa_v= std::conjunction_v<has_state_size<DFA>,\
    \ is_automaton<DFA>, std::is_same<trans_t<DFA>, int>>;\ntemplate <class T, class\
    \ DFA, class Add, class F> T dfa_dp(const DFA &dfa, int len, const Add &add, const\
    \ F &f, const T t0= T(0), const T init= T(1)) {\n static_assert(is_dfa_v<DFA>);\n\
    \ const auto alphabet= dfa.alphabet();\n const int S= dfa.state_size();\n std::vector<T>\
    \ dp(S, t0);\n std::vector<char> visit(S, false);\n dp[dfa.initial_state()]= init,\
    \ visit[dfa.initial_state()]= true;\n for (int i= 0; i < len; i++) {\n  std::vector<T>\
    \ next(S, t0);\n  std::vector<char> next_visit(S, false);\n  for (int s= S; s--;)\n\
    \   if (visit[s])\n    for (const auto &a: alphabet)\n     if (int q= dfa.transition(s,\
    \ a, i); q != -1) add(next[q], f(dp[s], a, i)), next_visit[q]= true;\n  dp.swap(next),\
    \ visit.swap(next_visit);\n }\n T ret= t0;\n for (int s= S; s--;)\n  if (dfa.is_accept(s))\
    \ add(ret, dp[s]);\n return ret;\n}\ntemplate <class T, class DFA> T dfa_dp(const\
    \ DFA &dfa, int len, const T t0= T(0), const T init= T(1)) {\n return dfa_dp<T>(\n\
    \     dfa, len, [](T &l, const T &r) { l+= r; }, [](const T &v, const typename\
    \ DFA::symbol_t &, int) { return v; }, t0, init);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Automaton/dfa_dp.hpp
  requiredBy:
  - src/Automaton/dfa_operations.hpp
  - src/Automaton/NFA_to_DFA.hpp
  - src/Automaton/DFA_Compress.hpp
  timestamp: '2022-12-31 22:35:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2587.test.cpp
  - test/atcoder/abc117_d.test.cpp
  - test/atcoder/abc129_e.test.cpp
  - test/atcoder/abc138_f.test.cpp
  - test/atcoder/abc235_f.test.cpp
  - test/atcoder/agc015_d.test.cpp
  - test/atcoder/abc154_e.test.cpp
  - test/atcoder/abc208_e.test.cpp
  - test/atcoder/arc127_a.test.cpp
documentation_of: src/Automaton/dfa_dp.hpp
layout: document
title: "DFA\u4E0A\u306EDP"
---
## 参考
[https://kuretchi.github.io/blog/entries/automaton-dp/](https://kuretchi.github.io/blog/entries/automaton-dp/)
## 問題例
[Typical DP Contest E - 数](https://atcoder.jp/contests/tdpc/tasks/tdpc_number) \
[AtCoder Beginner Contest 029 D - 1](https://atcoder.jp/contests/abc029/tasks/abc029_d) \
[Donuts プロコンチャレンジ2014 B - 7th](https://atcoder.jp/contests/donuts-live2014/tasks/donuts_live2014_2) \
[第１１回日本情報オリンピック 予選（過去問） F - ジグザグ数 (Zig-Zag Numbers)](https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_f)