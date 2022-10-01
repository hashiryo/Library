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
    document_title: "\u72B6\u614B\u3092int\u3067\u5727\u7E2E"
    links: []
  bundledCode: "#line 2 \"src/Automaton/DFA_Compress.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Automaton/dfa_dp.hpp\"\n/**\n * @title DFA\u4E0A\u306EDP\n * @category\
    \ \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n * @see https://kuretchi.github.io/blog/entries/automaton-dp/\n\
    \ */\n// verify\u7528:\n// https://atcoder.jp/contests/tdpc/tasks/tdpc_number\n\
    // https://atcoder.jp/contests/abc029/tasks/abc029_d\n// https://atcoder.jp/contests/donuts-live2014/tasks/donuts_live2014_2\n\
    // https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_f\n\n// BEGIN CUT HERE\n\
    #ifndef HAS_CHECK\n#define HAS_CHECK(member, Dummy)                          \
    \    \\\n  template <class T>                                          \\\n  struct\
    \ has_##member {                                       \\\n    template <class\
    \ U, Dummy>                                 \\\n    static std::true_type check(U\
    \ *);                         \\\n    static std::false_type check(...);     \
    \                   \\\n    static T *mClass;                                \
    \         \\\n    static const bool value = decltype(check(mClass))::value; \\\
    \n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    #endif\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\n\
    HAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\nHAS_MEMBER(state_size);\nHAS_MEMBER(eps_transition);\n\
    HAS_MEMBER(is_reject);\n#undef HAS_TYPE\n#undef HAS_MEMBER\n#undef HAS_CHECK\n\
    template <class A>\nusing is_automaton =\n    std::conjunction<has_symbol_t<A>,\
    \ has_alphabet<A>, has_initial_state<A>,\n                     has_transition<A>,\
    \ has_is_accept<A>>;\ntemplate <class A>\nusing trans_t = std::invoke_result_t<decltype(&A::transition),\
    \ A, int,\n                                     typename A::symbol_t, int>;\n\
    template <class DFA>\nconstexpr bool is_dfa_v =\n    std::conjunction_v<has_state_size<DFA>,\
    \ is_automaton<DFA>,\n                       std::is_same<trans_t<DFA>, int>>;\n\
    template <class T, class DFA, class Add, class F>\nT dfa_dp(const DFA &dfa, int\
    \ len, const Add &add, const F &f, const T t0 = T(0),\n         const T init =\
    \ T(1)) {\n  static_assert(is_dfa_v<DFA>);\n  const auto alphabet = dfa.alphabet();\n\
    \  const int S = dfa.state_size;\n  std::vector<T> dp(S, t0);\n  std::vector<char>\
    \ visit(S, false);\n  dp[dfa.initial_state()] = init, visit[dfa.initial_state()]\
    \ = true;\n  for (int i = 0; i < len; i++) {\n    std::vector<T> next(S, t0);\n\
    \    std::vector<char> next_visit(S, false);\n    for (int s = S; s--;)\n    \
    \  if (visit[s])\n        for (const auto &a : alphabet)\n          if (int q\
    \ = dfa.transition(s, a, i); q != -1)\n            add(next[q], f(dp[s], a, i)),\
    \ next_visit[q] = true;\n    dp.swap(next), visit.swap(next_visit);\n  }\n  T\
    \ ret = t0;\n  for (int s = S; s--;)\n    if (dfa.is_accept(s)) add(ret, dp[s]);\n\
    \  return ret;\n}\ntemplate <class T, class DFA>\nT dfa_dp(const DFA &dfa, int\
    \ len, const T t0 = T(0), const T init = T(1)) {\n  return dfa_dp<T>(\n      dfa,\
    \ len, [](T &l, const T &r) { l += r; },\n      [](const T &v, const typename\
    \ DFA::symbol_t &, int) { return v; }, t0,\n      init);\n}\n#line 4 \"src/Automaton/DFA_Compress.hpp\"\
    \n/**\n * @title \u72B6\u614B\u3092int\u3067\u5727\u7E2E\n * @category \u30AA\u30FC\
    \u30C8\u30DE\u30C8\u30F3\n */\n\n// BEGIN CUT HERE\ntemplate <class DFAx, class\
    \ S = typename DFAx::state_t>\nstruct DFA_Compress {\n  using symbol_t = typename\
    \ DFAx::symbol_t;\n  DFA_Compress(const DFAx &dfa_, int N) : state_size(0), dfa(dfa_)\
    \ {\n    static_assert(is_automaton<DFAx>::value);\n    static_assert(has_is_reject<DFAx>::value);\n\
    \    std::set<int> ss{mapping(dfa.initial_state())};\n    for (int i = 0; i <\
    \ N && !ss.empty(); i++) {\n      std::set<int> ts;\n      for (int s : ss)\n\
    \        for (const auto &a : alphabet()) {\n          int q = mapping(dfa.transition(states[s],\
    \ a, i));\n          memo[std::make_tuple(s, a, i)] = q;\n          if (q != -1)\
    \ ts.insert(q);\n        }\n      ss.swap(ts);\n    }\n  }\n  inline std::vector<symbol_t>\
    \ alphabet() const { return dfa.alphabet(); }\n  inline int initial_state() const\
    \ { return 0; }\n  inline int transition(int s, const symbol_t &c, int i) const\
    \ {\n    return memo.at(std::make_tuple(s, c, i));\n  }\n  inline bool is_accept(int\
    \ s) const { return dfa.is_accept(states[s]); }\n  int state_size;\n\n private:\n\
    \  DFAx dfa;\n  std::vector<S> states;\n  std::map<S, int> mp;\n  std::map<std::tuple<int,\
    \ symbol_t, int>, int> memo;\n  inline int mapping(const S &ss) {\n    if (dfa.is_reject(ss))\
    \ return -1;\n    if (mp.count(ss)) return mp[ss];\n    return states.push_back(ss),\
    \ mp[ss] = state_size++;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\
    \n/**\n * @title \u72B6\u614B\u3092int\u3067\u5727\u7E2E\n * @category \u30AA\u30FC\
    \u30C8\u30DE\u30C8\u30F3\n */\n\n// BEGIN CUT HERE\ntemplate <class DFAx, class\
    \ S = typename DFAx::state_t>\nstruct DFA_Compress {\n  using symbol_t = typename\
    \ DFAx::symbol_t;\n  DFA_Compress(const DFAx &dfa_, int N) : state_size(0), dfa(dfa_)\
    \ {\n    static_assert(is_automaton<DFAx>::value);\n    static_assert(has_is_reject<DFAx>::value);\n\
    \    std::set<int> ss{mapping(dfa.initial_state())};\n    for (int i = 0; i <\
    \ N && !ss.empty(); i++) {\n      std::set<int> ts;\n      for (int s : ss)\n\
    \        for (const auto &a : alphabet()) {\n          int q = mapping(dfa.transition(states[s],\
    \ a, i));\n          memo[std::make_tuple(s, a, i)] = q;\n          if (q != -1)\
    \ ts.insert(q);\n        }\n      ss.swap(ts);\n    }\n  }\n  inline std::vector<symbol_t>\
    \ alphabet() const { return dfa.alphabet(); }\n  inline int initial_state() const\
    \ { return 0; }\n  inline int transition(int s, const symbol_t &c, int i) const\
    \ {\n    return memo.at(std::make_tuple(s, c, i));\n  }\n  inline bool is_accept(int\
    \ s) const { return dfa.is_accept(states[s]); }\n  int state_size;\n\n private:\n\
    \  DFAx dfa;\n  std::vector<S> states;\n  std::map<S, int> mp;\n  std::map<std::tuple<int,\
    \ symbol_t, int>, int> memo;\n  inline int mapping(const S &ss) {\n    if (dfa.is_reject(ss))\
    \ return -1;\n    if (mp.count(ss)) return mp[ss];\n    return states.push_back(ss),\
    \ mp[ss] = state_size++;\n  }\n};"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  isVerificationFile: false
  path: src/Automaton/DFA_Compress.hpp
  requiredBy: []
  timestamp: '2022-07-07 14:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc208_e.test.cpp
documentation_of: src/Automaton/DFA_Compress.hpp
layout: document
redirect_from:
- /library/src/Automaton/DFA_Compress.hpp
- /library/src/Automaton/DFA_Compress.hpp.html
title: "\u72B6\u614B\u3092int\u3067\u5727\u7E2E"
---
