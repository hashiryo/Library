---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc208_e.test.cpp
    title: test/atcoder/abc208_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Automaton/DFA_Compress.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Automaton/dfa_dp.hpp\"\n#ifndef HAS_CHECK\n#define HAS_CHECK(member,\
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
    \ DFA::symbol_t &, int) { return v; }, t0, init);\n}\n#line 4 \"src/Automaton/DFA_Compress.hpp\"\
    \ntemplate <class DFAx, class S= typename DFAx::state_t> struct DFA_Compress {\n\
    \ using symbol_t= typename DFAx::symbol_t;\n DFA_Compress(const DFAx &dfa_, int\
    \ N): size(0), dfa(dfa_) {\n  static_assert(is_automaton<DFAx>::value);\n  static_assert(has_is_reject<DFAx>::value);\n\
    \  std::set<int> ss{mapping(dfa.initial_state())};\n  for (int i= 0; i < N &&\
    \ !ss.empty(); i++) {\n   std::set<int> ts;\n   for (int s: ss)\n    for (const\
    \ auto &a: alphabet()) {\n     int q= mapping(dfa.transition(states[s], a, i));\n\
    \     memo[std::make_tuple(s, a, i)]= q;\n     if (q != -1) ts.insert(q);\n  \
    \  }\n   ss.swap(ts);\n  }\n }\n inline std::vector<symbol_t> alphabet() const\
    \ { return dfa.alphabet(); }\n inline int initial_state() const { return 0; }\n\
    \ inline int transition(int s, const symbol_t &c, int i) const { return memo.at(std::make_tuple(s,\
    \ c, i)); }\n inline bool is_accept(int s) const { return dfa.is_accept(states[s]);\
    \ }\n inline int state_size() const { return size; }\nprivate:\n int size;\n DFAx\
    \ dfa;\n std::vector<S> states;\n std::map<S, int> mp;\n std::map<std::tuple<int,\
    \ symbol_t, int>, int> memo;\n inline int mapping(const S &ss) {\n  if (dfa.is_reject(ss))\
    \ return -1;\n  if (mp.count(ss)) return mp[ss];\n  return states.push_back(ss),\
    \ mp[ss]= size++;\n }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\
    \ntemplate <class DFAx, class S= typename DFAx::state_t> struct DFA_Compress {\n\
    \ using symbol_t= typename DFAx::symbol_t;\n DFA_Compress(const DFAx &dfa_, int\
    \ N): size(0), dfa(dfa_) {\n  static_assert(is_automaton<DFAx>::value);\n  static_assert(has_is_reject<DFAx>::value);\n\
    \  std::set<int> ss{mapping(dfa.initial_state())};\n  for (int i= 0; i < N &&\
    \ !ss.empty(); i++) {\n   std::set<int> ts;\n   for (int s: ss)\n    for (const\
    \ auto &a: alphabet()) {\n     int q= mapping(dfa.transition(states[s], a, i));\n\
    \     memo[std::make_tuple(s, a, i)]= q;\n     if (q != -1) ts.insert(q);\n  \
    \  }\n   ss.swap(ts);\n  }\n }\n inline std::vector<symbol_t> alphabet() const\
    \ { return dfa.alphabet(); }\n inline int initial_state() const { return 0; }\n\
    \ inline int transition(int s, const symbol_t &c, int i) const { return memo.at(std::make_tuple(s,\
    \ c, i)); }\n inline bool is_accept(int s) const { return dfa.is_accept(states[s]);\
    \ }\n inline int state_size() const { return size; }\nprivate:\n int size;\n DFAx\
    \ dfa;\n std::vector<S> states;\n std::map<S, int> mp;\n std::map<std::tuple<int,\
    \ symbol_t, int>, int> memo;\n inline int mapping(const S &ss) {\n  if (dfa.is_reject(ss))\
    \ return -1;\n  if (mp.count(ss)) return mp[ss];\n  return states.push_back(ss),\
    \ mp[ss]= size++;\n }\n};"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  isVerificationFile: false
  path: src/Automaton/DFA_Compress.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:35:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc208_e.test.cpp
documentation_of: src/Automaton/DFA_Compress.hpp
layout: document
title: "\u72B6\u614B\u3092int\u3067\u5727\u7E2E"
---
