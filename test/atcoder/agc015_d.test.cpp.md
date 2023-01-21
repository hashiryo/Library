---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Automaton/NFA_to_DFA.hpp
    title: "NFA\u3092DFA\u306B\u5909\u63DB"
  - icon: ':x:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/agc015/tasks/agc015_d
    links:
    - https://atcoder.jp/contests/agc015/tasks/agc015_d
  bundledCode: "#line 1 \"test/atcoder/agc015_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc015/tasks/agc015_d\"\
    \n#include <iostream>\n#include <vector>\n#include <set>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\
    \n#include <type_traits>\n#define HAS_CHECK(member, Dummy) \\\n template <class\
    \ tClass> struct has_##member { \\\n  template <class U, Dummy> static std::true_type\
    \ check(U *); \\\n  static std::false_type check(...); \\\n  static tClass *mClass;\
    \ \\\n  static const bool value= decltype(check(mClass))::value; \\\n };\n#define\
    \ HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member)\
    \ HAS_CHECK(member, class dummy= typename U::member)\n#line 4 \"src/Automaton/dfa_dp.hpp\"\
    \nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\nHAS_MEMBER(transition);\n\
    HAS_MEMBER(is_accept);\nHAS_MEMBER(state_size);\nHAS_MEMBER(eps_transition);\n\
    HAS_MEMBER(is_reject);\ntemplate <class A> using is_automaton= std::conjunction<has_symbol_t<A>,\
    \ has_alphabet<A>, has_initial_state<A>, has_transition<A>, has_is_accept<A>>;\n\
    template <class A> using trans_t= std::invoke_result_t<decltype(&A::transition),\
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
    \ &, int) { return v; }, t0, init);\n}\n#line 3 \"src/Automaton/NFA_to_DFA.hpp\"\
    \n#include <map>\n#include <tuple>\n#line 6 \"src/Automaton/NFA_to_DFA.hpp\"\n\
    template <class NFA> constexpr bool is_nfa_v= std::conjunction_v<is_automaton<NFA>,\
    \ has_eps_transition<NFA>, std::is_same<trans_t<NFA>, std::set<int>>>;\ntemplate\
    \ <class NFA> struct NFA_to_DFA {\n using symbol_t= typename NFA::symbol_t;\n\
    \ NFA_to_DFA(NFA &&nfa_): size(0), nfa(std::move(nfa_)) {\n  static_assert(is_nfa_v<NFA>);\n\
    \  std::set<int> ss{initial_state_()};\n  for (int i= 0; !ss.empty(); i++) {\n\
    \   std::set<int> ts;\n   for (int s: ss)\n    for (const auto &a: alphabet())\
    \ {\n     int q= transition_(s, a, i);\n     memo[std::make_tuple(s, a, i)]= q;\n\
    \     if (q != -1) ts.insert(q);\n    }\n   ss.swap(ts);\n  }\n }\n std::vector<symbol_t>\
    \ alphabet() const { return nfa.alphabet(); }\n inline int initial_state() const\
    \ { return 0; }\n inline int transition(int s, const symbol_t &c, int i) const\
    \ { return memo.at(std::make_tuple(s, c, i)); }\n inline bool is_accept(int s)\
    \ const {\n  std::set<int> ss= states[s];\n  return std::any_of(ss.begin(), ss.end(),\
    \ [&](int x) { return nfa.is_accept(x); });\n }\n inline int state_size() const\
    \ { return size; }\nprivate:\n int size;\n NFA nfa;\n std::vector<std::set<int>>\
    \ states;\n std::map<std::set<int>, int> mp;\n std::map<std::tuple<int, symbol_t,\
    \ int>, int> memo;\n inline int mapping(const std::set<int> &ss) {\n  if (ss.empty())\
    \ return -1;\n  if (mp.count(ss)) return mp[ss];\n  return states.push_back(ss),\
    \ mp[ss]= size++;\n }\n inline int transition_(int s, const symbol_t &c, int i)\
    \ {\n  std::set<int> ss;\n  for (const auto &x: states[s]) {\n   auto ys= nfa.transition(x,\
    \ c, i);\n   ss.insert(ys.begin(), ys.end());\n  }\n  return eps_closure(ss);\n\
    \ }\n inline int initial_state_() { return eps_closure({nfa.initial_state()});\
    \ }\n inline int eps_closure(std::set<int> ss) {\n  for (std::set<int> ts; ss\
    \ != ts;) {\n   ts= ss;\n   for (const auto &x: ts) {\n    auto ys= nfa.eps_transition(x);\n\
    \    ss.insert(ys.begin(), ys.end());\n   }\n  }\n  return mapping(ss);\n }\n\
    };\n#line 7 \"test/atcoder/agc015_d.test.cpp\"\nusing namespace std;\nclass AororB\
    \ {\n const long long A, B;\npublic:\n using symbol_t= int;\n AororB(long long\
    \ A_, long long B_): A(A_), B(B_) {}\n std::vector<symbol_t> alphabet() const\
    \ { return {0, 1}; }\n int initial_state() const { return 3; }\n std::set<int>\
    \ transition(int s, const symbol_t &c, int i) const {\n  if (i >= 60) return {};\n\
    \  if (s == 0) return {0};\n  long long l= A >> (59 - i), u= B >> (59 - i);\n\
    \  if (l == u) {\n   if (c == (l & 1)) return {3};\n   return {};\n  }\n  if (c\
    \ == 0) {\n   if (s == 1) {\n    if (l & 1) return {};\n    return {1};\n   }\
    \ else if (s == 2 || s == 4) {\n    if (u & 1) return {0};\n    return {s};\n\
    \   } else {\n    if (l & 1) return {};\n    if (u & 1) return {1};\n    return\
    \ {3};\n   }\n  } else {\n   if (s == 1) {\n    if (l & 1) return {1};\n    return\
    \ {0};\n   } else if (s == 2) {\n    if (u & 1) return {4};\n    return {};\n\
    \   } else if (s == 4) {\n    if (u & 1) return {0};\n    return {4};\n   } else\
    \ {\n    if (u - l == 1) {\n     if (l & 1) return {3};\n     return {3, 2};\n\
    \    } else {\n     if (l & 1) {\n      if (u & 1) return {1};\n      return {3};\n\
    \     }\n     if (u & 1) return {0};\n     return {4};\n    }\n   }\n  }\n }\n\
    \ std::set<int> eps_transition(const int) const { return {}; }\n bool is_accept(int\
    \ s) const { return true; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ long long A, B;\n cin >> A >> B;\n cout << dfa_dp<long long>(NFA_to_DFA(AororB(A,\
    \ B)), 60) << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc015/tasks/agc015_d\"\n#include\
    \ <iostream>\n#include <vector>\n#include <set>\n#include \"src/Automaton/dfa_dp.hpp\"\
    \n#include \"src/Automaton/NFA_to_DFA.hpp\"\nusing namespace std;\nclass AororB\
    \ {\n const long long A, B;\npublic:\n using symbol_t= int;\n AororB(long long\
    \ A_, long long B_): A(A_), B(B_) {}\n std::vector<symbol_t> alphabet() const\
    \ { return {0, 1}; }\n int initial_state() const { return 3; }\n std::set<int>\
    \ transition(int s, const symbol_t &c, int i) const {\n  if (i >= 60) return {};\n\
    \  if (s == 0) return {0};\n  long long l= A >> (59 - i), u= B >> (59 - i);\n\
    \  if (l == u) {\n   if (c == (l & 1)) return {3};\n   return {};\n  }\n  if (c\
    \ == 0) {\n   if (s == 1) {\n    if (l & 1) return {};\n    return {1};\n   }\
    \ else if (s == 2 || s == 4) {\n    if (u & 1) return {0};\n    return {s};\n\
    \   } else {\n    if (l & 1) return {};\n    if (u & 1) return {1};\n    return\
    \ {3};\n   }\n  } else {\n   if (s == 1) {\n    if (l & 1) return {1};\n    return\
    \ {0};\n   } else if (s == 2) {\n    if (u & 1) return {4};\n    return {};\n\
    \   } else if (s == 4) {\n    if (u & 1) return {0};\n    return {4};\n   } else\
    \ {\n    if (u - l == 1) {\n     if (l & 1) return {3};\n     return {3, 2};\n\
    \    } else {\n     if (l & 1) {\n      if (u & 1) return {1};\n      return {3};\n\
    \     }\n     if (u & 1) return {0};\n     return {4};\n    }\n   }\n  }\n }\n\
    \ std::set<int> eps_transition(const int) const { return {}; }\n bool is_accept(int\
    \ s) const { return true; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ long long A, B;\n cin >> A >> B;\n cout << dfa_dp<long long>(NFA_to_DFA(AororB(A,\
    \ B)), 60) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  - src/Internal/HAS_CHECK.hpp
  - src/Automaton/NFA_to_DFA.hpp
  isVerificationFile: true
  path: test/atcoder/agc015_d.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 17:49:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/agc015_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/agc015_d.test.cpp
- /verify/test/atcoder/agc015_d.test.cpp.html
title: test/atcoder/agc015_d.test.cpp
---
