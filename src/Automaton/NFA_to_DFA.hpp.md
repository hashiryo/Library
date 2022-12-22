---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \  const int S = dfa.state_size();\n  std::vector<T> dp(S, t0);\n  std::vector<char>\
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
    \ DFA::symbol_t &, int) { return v; }, t0,\n      init);\n}\n#line 4 \"src/Automaton/NFA_to_DFA.hpp\"\
    \n/**\n * @title NFA\u3092DFA\u306B\u5909\u63DB\n * @category \u30AA\u30FC\u30C8\
    \u30DE\u30C8\u30F3\n * @see https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836\n\
    \ * @see https://blog.knshnb.com/posts/aoj2587/\n */\n// verify\u7528\n// https://atcoder.jp/contests/abc050/tasks/arc066_b\n\
    \n// BEGIN CUT HERE\ntemplate <class NFA>\nconstexpr bool is_nfa_v =\n    std::conjunction_v<is_automaton<NFA>,\
    \ has_eps_transition<NFA>,\n                       std::is_same<trans_t<NFA>,\
    \ std::set<int>>>;\ntemplate <class NFA>\nstruct NFA_to_DFA {\n  using symbol_t\
    \ = typename NFA::symbol_t;\n  NFA_to_DFA(NFA &&nfa_) : size(0), nfa(std::move(nfa_))\
    \ {\n    static_assert(is_nfa_v<NFA>);\n    std::set<int> ss{initial_state_()};\n\
    \    for (int i = 0; !ss.empty(); i++) {\n      std::set<int> ts;\n      for (int\
    \ s : ss)\n        for (const auto &a : alphabet()) {\n          int q = transition_(s,\
    \ a, i);\n          memo[std::make_tuple(s, a, i)] = q;\n          if (q != -1)\
    \ ts.insert(q);\n        }\n      ss.swap(ts);\n    }\n  }\n  std::vector<symbol_t>\
    \ alphabet() const { return nfa.alphabet(); }\n  inline int initial_state() const\
    \ { return 0; }\n  inline int transition(int s, const symbol_t &c, int i) const\
    \ {\n    return memo.at(std::make_tuple(s, c, i));\n  }\n  inline bool is_accept(int\
    \ s) const {\n    std::set<int> ss = states[s];\n    return std::any_of(ss.begin(),\
    \ ss.end(),\n                       [&](int x) { return nfa.is_accept(x); });\n\
    \  }\n  inline int state_size() const { return size; }\n\n private:\n  int size;\n\
    \  NFA nfa;\n  std::vector<std::set<int>> states;\n  std::map<std::set<int>, int>\
    \ mp;\n  std::map<std::tuple<int, symbol_t, int>, int> memo;\n  inline int mapping(const\
    \ std::set<int> &ss) {\n    if (ss.empty()) return -1;\n    if (mp.count(ss))\
    \ return mp[ss];\n    return states.push_back(ss), mp[ss] = size++;\n  }\n  inline\
    \ int transition_(int s, const symbol_t &c, int i) {\n    std::set<int> ss;\n\
    \    for (const auto &x : states[s]) {\n      auto ys = nfa.transition(x, c, i);\n\
    \      ss.insert(ys.begin(), ys.end());\n    }\n    return eps_closure(ss);\n\
    \  }\n  inline int initial_state_() { return eps_closure({nfa.initial_state()});\
    \ }\n  inline int eps_closure(std::set<int> ss) {\n    for (std::set<int> ts;\
    \ ss != ts;) {\n      ts = ss;\n      for (const auto &x : ts) {\n        auto\
    \ ys = nfa.eps_transition(x);\n        ss.insert(ys.begin(), ys.end());\n    \
    \  }\n    }\n    return mapping(ss);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\
    \n/**\n * @title NFA\u3092DFA\u306B\u5909\u63DB\n * @category \u30AA\u30FC\u30C8\
    \u30DE\u30C8\u30F3\n * @see https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836\n\
    \ * @see https://blog.knshnb.com/posts/aoj2587/\n */\n// verify\u7528\n// https://atcoder.jp/contests/abc050/tasks/arc066_b\n\
    \n// BEGIN CUT HERE\ntemplate <class NFA>\nconstexpr bool is_nfa_v =\n    std::conjunction_v<is_automaton<NFA>,\
    \ has_eps_transition<NFA>,\n                       std::is_same<trans_t<NFA>,\
    \ std::set<int>>>;\ntemplate <class NFA>\nstruct NFA_to_DFA {\n  using symbol_t\
    \ = typename NFA::symbol_t;\n  NFA_to_DFA(NFA &&nfa_) : size(0), nfa(std::move(nfa_))\
    \ {\n    static_assert(is_nfa_v<NFA>);\n    std::set<int> ss{initial_state_()};\n\
    \    for (int i = 0; !ss.empty(); i++) {\n      std::set<int> ts;\n      for (int\
    \ s : ss)\n        for (const auto &a : alphabet()) {\n          int q = transition_(s,\
    \ a, i);\n          memo[std::make_tuple(s, a, i)] = q;\n          if (q != -1)\
    \ ts.insert(q);\n        }\n      ss.swap(ts);\n    }\n  }\n  std::vector<symbol_t>\
    \ alphabet() const { return nfa.alphabet(); }\n  inline int initial_state() const\
    \ { return 0; }\n  inline int transition(int s, const symbol_t &c, int i) const\
    \ {\n    return memo.at(std::make_tuple(s, c, i));\n  }\n  inline bool is_accept(int\
    \ s) const {\n    std::set<int> ss = states[s];\n    return std::any_of(ss.begin(),\
    \ ss.end(),\n                       [&](int x) { return nfa.is_accept(x); });\n\
    \  }\n  inline int state_size() const { return size; }\n\n private:\n  int size;\n\
    \  NFA nfa;\n  std::vector<std::set<int>> states;\n  std::map<std::set<int>, int>\
    \ mp;\n  std::map<std::tuple<int, symbol_t, int>, int> memo;\n  inline int mapping(const\
    \ std::set<int> &ss) {\n    if (ss.empty()) return -1;\n    if (mp.count(ss))\
    \ return mp[ss];\n    return states.push_back(ss), mp[ss] = size++;\n  }\n  inline\
    \ int transition_(int s, const symbol_t &c, int i) {\n    std::set<int> ss;\n\
    \    for (const auto &x : states[s]) {\n      auto ys = nfa.transition(x, c, i);\n\
    \      ss.insert(ys.begin(), ys.end());\n    }\n    return eps_closure(ss);\n\
    \  }\n  inline int initial_state_() { return eps_closure({nfa.initial_state()});\
    \ }\n  inline int eps_closure(std::set<int> ss) {\n    for (std::set<int> ts;\
    \ ss != ts;) {\n      ts = ss;\n      for (const auto &x : ts) {\n        auto\
    \ ys = nfa.eps_transition(x);\n        ss.insert(ys.begin(), ys.end());\n    \
    \  }\n    }\n    return mapping(ss);\n  }\n};"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  isVerificationFile: false
  path: src/Automaton/NFA_to_DFA.hpp
  requiredBy: []
  timestamp: '2022-11-27 14:04:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2587.test.cpp
  - test/atcoder/agc015_d.test.cpp
documentation_of: src/Automaton/NFA_to_DFA.hpp
layout: document
redirect_from:
- /library/src/Automaton/NFA_to_DFA.hpp
- /library/src/Automaton/NFA_to_DFA.hpp.html
title: "NFA\u3092DFA\u306B\u5909\u63DB"
---
