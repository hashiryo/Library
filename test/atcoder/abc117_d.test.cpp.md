---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Automaton/DFA_Inequality.hpp
    title: "$N$\u4EE5\u4E0B(\u4EE5\u4E0A)\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\
      \u7406\u3059\u308BDFA"
  - icon: ':question:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc117/tasks/abc117_d
    links:
    - https://atcoder.jp/contests/abc117/tasks/abc117_d
  bundledCode: "#line 1 \"test/atcoder/abc117_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc117/tasks/abc117_d\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Automaton/dfa_dp.hpp\"\n/**\n * @title\
    \ DFA\u4E0A\u306EDP\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n * @see\
    \ https://kuretchi.github.io/blog/entries/automaton-dp/\n */\n// verify\u7528\
    :\n// https://atcoder.jp/contests/tdpc/tasks/tdpc_number\n// https://atcoder.jp/contests/abc029/tasks/abc029_d\n\
    // https://atcoder.jp/contests/donuts-live2014/tasks/donuts_live2014_2\n// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_f\n\
    \n// BEGIN CUT HERE\n#ifndef HAS_CHECK\n#define HAS_CHECK(member, Dummy)     \
    \                         \\\n  template <class T>                           \
    \               \\\n  struct has_##member {                                  \
    \     \\\n    template <class U, Dummy>                                 \\\n \
    \   static std::true_type check(U *);                         \\\n    static std::false_type\
    \ check(...);                        \\\n    static T *mClass;               \
    \                          \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    #endif\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\n\
    HAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\nHAS_MEMBER(state_size);\nHAS_MEMBER(eps_transition);\n\
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
    \ DFA::symbol_t &, int) { return v; }, t0,\n      init);\n}\n#line 4 \"src/Automaton/DFA_Inequality.hpp\"\
    \n/**\n * @title $N$\u4EE5\u4E0B(\u4EE5\u4E0A)\u306E\u975E\u8CA0\u6574\u6570\u3092\
    \u53D7\u7406\u3059\u308BDFA\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\
    \n * @brief 0-fill\n */\n\n// BEGIN CUT HERE\ntemplate <bool ge = false>  // le\
    \ or ge\nstruct DFA_Inequality {     // view from the top digit\n  using symbol_t\
    \ = int;\n  DFA_Inequality(std::vector<symbol_t> &&str_, std::vector<symbol_t>\
    \ &&alp_)\n      : str(std::move(str_)), alp(std::move(alp_)) {}\n  DFA_Inequality(const\
    \ std::string &n, int m) {  // n : m-ary notation\n    assert(2 <= m && m <= 10);\n\
    \    for (int l = n.length(), i = 0; i < l;) str.push_back(n[i++] - '0');\n  \
    \  for (int i = 0; i < m; i++) alp.push_back(i);\n  }\n  template <class Int>\
    \  // m-ary number\n  DFA_Inequality(Int n, int m, int len = 0) {\n    for (;\
    \ n; n /= m, len--) str.push_back(n % m);\n    while (len-- > 0) str.push_back(0);\n\
    \    for (int i = 0; i < m; i++) alp.push_back(i);\n    std::reverse(str.begin(),\
    \ str.end());\n  }\n  inline std::vector<symbol_t> alphabet() const { return alp;\
    \ }\n  inline int initial_state() const { return 0; }\n  inline int transition(int\
    \ s, const symbol_t &a, int i) const {\n    if (s != 0) return s;\n    if (i >=\
    \ (int)str.size()) return -1;\n    if (a == str[i]) return 0;\n    if constexpr\
    \ (ge)\n      return a < str[i] ? -1 : 1;\n    else\n      return a > str[i] ?\
    \ -1 : 1;\n  }\n  inline bool is_accept(int s) const { return s >= 0; }\n  const\
    \ int state_size = 2;\n\n private:\n  std::vector<symbol_t> str, alp;\n};\n#line\
    \ 5 \"test/atcoder/abc117_d.test.cpp\"\nusing namespace std;\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  long long N, K;\n  cin >>\
    \ N >> K;\n  long long A[N];\n  for (int i = 0; i < N; i++) cin >> A[i];\n  auto\
    \ add = [](long long &l, const long long &r) {\n    if (l < r) l = r;\n  };\n\
    \  auto f = [&](const long long &x, int b, int k) {\n    long long val = x;\n\
    \    for (int i = N; i--;) val += (((A[i] >> k) & 1) ^ b) << k;\n    return val;\n\
    \  };\n  cout << dfa_dp<long long>(DFA_Inequality(K, 2, 41), 41, add, f, 0, 0)\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc117/tasks/abc117_d\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\n#include \"src/Automaton/DFA_Inequality.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  long long N, K;\n  cin >> N >> K;\n  long long A[N];\n  for (int i = 0; i <\
    \ N; i++) cin >> A[i];\n  auto add = [](long long &l, const long long &r) {\n\
    \    if (l < r) l = r;\n  };\n  auto f = [&](const long long &x, int b, int k)\
    \ {\n    long long val = x;\n    for (int i = N; i--;) val += (((A[i] >> k) &\
    \ 1) ^ b) << k;\n    return val;\n  };\n  cout << dfa_dp<long long>(DFA_Inequality(K,\
    \ 2, 41), 41, add, f, 0, 0) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  - src/Automaton/DFA_Inequality.hpp
  isVerificationFile: true
  path: test/atcoder/abc117_d.test.cpp
  requiredBy: []
  timestamp: '2022-07-07 13:36:48+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc117_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc117_d.test.cpp
- /verify/test/atcoder/abc117_d.test.cpp.html
title: test/atcoder/abc117_d.test.cpp
---
