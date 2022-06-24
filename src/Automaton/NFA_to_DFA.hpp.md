---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2587.test.cpp
    title: test/aoj/2587.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc015_d.test.cpp
    title: test/atcoder/agc015_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "NFA\u3092DFA\u306B\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/abc050/tasks/arc066_b
    - https://blog.knshnb.com/posts/aoj2587/
    - https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836
  bundledCode: "#line 2 \"src/Automaton/NFA_to_DFA.hpp\"\n#include <bits/stdc++.h>\n\
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
    #endif\nHAS_TYPE(state_t);\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\n\
    HAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\nHAS_MEMBER(eps_transition);\n\
    template <class A>\nusing is_automaton =\n    std::conjunction<has_state_t<A>,\
    \ has_symbol_t<A>, has_alphabet<A>,\n                     has_initial_state<A>,\
    \ has_transition<A>, has_is_accept<A>>;\ntemplate <class A>\nusing trans_t = std::invoke_result_t<decltype(&A::transition),\
    \ A,\n                                     typename A::state_t, typename A::symbol_t>;\n\
    template <class DFA>\nconstexpr bool is_dfa_v =\n    std::conjunction_v<is_automaton<DFA>,\n\
    \                       std::is_same<trans_t<DFA>, typename DFA::state_t>>;\n\
    template <class NFA>\nconstexpr bool is_nfa_v = std::conjunction_v<\n    is_automaton<NFA>,\
    \ has_eps_transition<NFA>,\n    std::is_same<trans_t<NFA>, std::set<typename NFA::state_t>>>;\n\
    \ntemplate <class T, class DFA, class Add, class F>\nT dfa_dp(const DFA &dfa,\
    \ int len, const Add &add, const F &f, const T t0 = T(0),\n         const T init\
    \ = T(1)) {\n  static_assert(is_dfa_v<DFA>);\n  const auto alphabet = dfa.alphabet();\n\
    \  std::map<typename DFA::state_t, T> dp;\n  dp[dfa.initial_state()] = init;\n\
    \  for (int i = 0; i < len; i++) {\n    std::map<typename DFA::state_t, T> next;\n\
    \    for (const auto &[k, v] : dp)\n      for (const auto &a : alphabet) {\n \
    \       if (auto q = dfa.transition(k, a); next.count(q))\n          add(next[q],\
    \ f(v, a, i));\n        else\n          next[q] = f(v, a, i);\n      }\n    dp\
    \ = std::move(next);\n  }\n  T ret = t0;\n  for (const auto &[k, v] : dp)\n  \
    \  if (dfa.is_accept(k)) add(ret, v);\n  return ret;\n}\ntemplate <class T, class\
    \ DFA>\nT dfa_dp(const DFA &dfa, int len, const T t0 = T(0), const T init = T(1))\
    \ {\n  return dfa_dp<T>(\n      dfa, len, [](T &l, const T &r) { l += r; },\n\
    \      [](const T &v, const typename DFA::symbol_t &, int) { return v; }, t0,\n\
    \      init);\n}\n#line 4 \"src/Automaton/NFA_to_DFA.hpp\"\n/**\n * @title NFA\u3092\
    DFA\u306B\u5909\u63DB\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n * @see\
    \ https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836\n * @see https://blog.knshnb.com/posts/aoj2587/\n\
    \ */\n// verify\u7528\n// https://atcoder.jp/contests/abc050/tasks/arc066_b\n\n\
    // BEGIN CUT HERE\n\ntemplate <class NFA>\nstruct NFA_to_DFA {\n  using state_t\
    \ = std::set<typename NFA::state_t>;\n  using symbol_t = typename NFA::symbol_t;\n\
    \  NFA_to_DFA(NFA nfa_) : nfa(std::move(nfa_)) { static_assert(is_nfa_v<NFA>);\
    \ }\n  std::set<symbol_t> alphabet() const { return nfa.alphabet(); }\n  state_t\
    \ initial_state() const { return eps_closure({nfa.initial_state()}); }\n  state_t\
    \ transition(const state_t &s, const symbol_t &c) const {\n    state_t t;\n  \
    \  for (const auto &x : s) {\n      auto ys = nfa.transition(x, c);\n      t.insert(ys.begin(),\
    \ ys.end());\n    }\n    return eps_closure(t);\n  }\n  bool is_accept(const state_t\
    \ &s) const {\n    return std::any_of(s.begin(), s.end(),\n                  \
    \     [&](const auto &x) { return nfa.is_accept(x); });\n  }\n\n private:\n  NFA\
    \ nfa;\n  state_t eps_closure(state_t s) const {\n    for (state_t t; s != t;)\
    \ {\n      t = s;\n      for (const auto &x : t) {\n        auto ys = nfa.eps_transition(x);\n\
    \        s.insert(ys.begin(), ys.end());\n      }\n    }\n    return s;\n  }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\
    \n/**\n * @title NFA\u3092DFA\u306B\u5909\u63DB\n * @category \u30AA\u30FC\u30C8\
    \u30DE\u30C8\u30F3\n * @see https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836\n\
    \ * @see https://blog.knshnb.com/posts/aoj2587/\n */\n// verify\u7528\n// https://atcoder.jp/contests/abc050/tasks/arc066_b\n\
    \n// BEGIN CUT HERE\n\ntemplate <class NFA>\nstruct NFA_to_DFA {\n  using state_t\
    \ = std::set<typename NFA::state_t>;\n  using symbol_t = typename NFA::symbol_t;\n\
    \  NFA_to_DFA(NFA nfa_) : nfa(std::move(nfa_)) { static_assert(is_nfa_v<NFA>);\
    \ }\n  std::set<symbol_t> alphabet() const { return nfa.alphabet(); }\n  state_t\
    \ initial_state() const { return eps_closure({nfa.initial_state()}); }\n  state_t\
    \ transition(const state_t &s, const symbol_t &c) const {\n    state_t t;\n  \
    \  for (const auto &x : s) {\n      auto ys = nfa.transition(x, c);\n      t.insert(ys.begin(),\
    \ ys.end());\n    }\n    return eps_closure(t);\n  }\n  bool is_accept(const state_t\
    \ &s) const {\n    return std::any_of(s.begin(), s.end(),\n                  \
    \     [&](const auto &x) { return nfa.is_accept(x); });\n  }\n\n private:\n  NFA\
    \ nfa;\n  state_t eps_closure(state_t s) const {\n    for (state_t t; s != t;)\
    \ {\n      t = s;\n      for (const auto &x : t) {\n        auto ys = nfa.eps_transition(x);\n\
    \        s.insert(ys.begin(), ys.end());\n      }\n    }\n    return s;\n  }\n\
    };"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  isVerificationFile: false
  path: src/Automaton/NFA_to_DFA.hpp
  requiredBy: []
  timestamp: '2022-06-23 14:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/agc015_d.test.cpp
  - test/aoj/2587.test.cpp
documentation_of: src/Automaton/NFA_to_DFA.hpp
layout: document
redirect_from:
- /library/src/Automaton/NFA_to_DFA.hpp
- /library/src/Automaton/NFA_to_DFA.hpp.html
title: "NFA\u3092DFA\u306B\u5909\u63DB"
---
