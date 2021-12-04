---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/LinearSystemIncidence.hpp
    title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc106/tasks/arc106_b
    links:
    - https://atcoder.jp/contests/arc106/tasks/arc106_b
  bundledCode: "#line 1 \"test/atcoder/arc106_b.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc106/tasks/arc106_b\"\
    \n\n#include <bits/stdc++.h>\n#line 3 \"src/Graph/LinearSystemIncidence.hpp\"\n\
    /**\n * @title \u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F\n\
    \ * @category \u30B0\u30E9\u30D5\n * @see https://opt-cp.com/linear-system-incidence/\n\
    \ * O(V+E)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/abc155/tasks/abc155_f\n\
    // https://atcoder.jp/contests/agc035/tasks/agc035_b\n// https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename T>\nclass LinearSystemIncidence {\n\
    \  int m;\n  std::vector<T> x;\n  std::vector<char> used;\n  std::vector<std::vector<std::tuple<int,\
    \ int, bool>>> adj;\n  T dfs(const std::vector<T> &b, int u) {\n    used[u] =\
    \ true;\n    T ret = b[u];\n    for (auto [id, to, fwd] : adj[u])\n      if (!used[to])\
    \ {\n        T tmp = dfs(b, to);\n        if constexpr (std::is_same_v<T, bool>)\n\
    \          x[id] = tmp, ret ^= tmp;\n        else\n          x[id] = fwd ? tmp\
    \ : -tmp, ret += tmp;\n      }\n    return ret;\n  }\n\n public:\n  LinearSystemIncidence(int\
    \ n) : m(0), adj(n) {}\n  void add_edge(int src, int dst) {\n    adj[src].emplace_back(m,\
    \ dst, true), adj[dst].emplace_back(m++, src, false);\n  }\n  std::vector<T> solve(const\
    \ std::vector<T> &b) {\n    x.assign(m, T(0)), used.assign(adj.size(), false);\n\
    \    for (std::size_t u = 0; u < adj.size(); u++)\n      if (!used[u] && dfs(b,\
    \ u) != T(0))\n        return std::vector<T>();  // no sloution\n    return std::move(x);\n\
    \  }\n};\n#line 5 \"test/atcoder/arc106_b.test.cpp\"\nusing namespace std;\n\n\
    // \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  int N, M;\n  cin >> N >> M;\n  LinearSystemIncidence<long\
    \ long> graph(N);\n  vector<long long> a(N), b(N);\n  for (int i = 0; i < N; i++)\
    \ cin >> a[i];\n  for (int i = 0; i < N; i++) cin >> b[i], b[i] -= a[i];\n  for\
    \ (int i = 0; i < M; i++) {\n    int c, d;\n    cin >> c >> d;\n    graph.add_edge(--c,\
    \ --d);\n  }\n  if (M)\n    cout << (graph.solve(b).empty() ? \"No\" : \"Yes\"\
    ) << '\\n';\n  else\n    cout << (b[0] ? \"No\" : \"Yes\") << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc106/tasks/arc106_b\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Graph/LinearSystemIncidence.hpp\"\nusing\
    \ namespace std;\n\n// \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int N, M;\n  cin\
    \ >> N >> M;\n  LinearSystemIncidence<long long> graph(N);\n  vector<long long>\
    \ a(N), b(N);\n  for (int i = 0; i < N; i++) cin >> a[i];\n  for (int i = 0; i\
    \ < N; i++) cin >> b[i], b[i] -= a[i];\n  for (int i = 0; i < M; i++) {\n    int\
    \ c, d;\n    cin >> c >> d;\n    graph.add_edge(--c, --d);\n  }\n  if (M)\n  \
    \  cout << (graph.solve(b).empty() ? \"No\" : \"Yes\") << '\\n';\n  else\n   \
    \ cout << (b[0] ? \"No\" : \"Yes\") << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Graph/LinearSystemIncidence.hpp
  isVerificationFile: true
  path: test/atcoder/arc106_b.test.cpp
  requiredBy: []
  timestamp: '2021-12-04 18:40:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/arc106_b.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc106_b.test.cpp
- /verify/test/atcoder/arc106_b.test.cpp.html
title: test/atcoder/arc106_b.test.cpp
---
