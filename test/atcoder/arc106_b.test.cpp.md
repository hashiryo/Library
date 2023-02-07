---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/LinearSystemIncidence.hpp
    title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc106/tasks/arc106_b
    links:
    - https://atcoder.jp/contests/arc106/tasks/arc106_b
  bundledCode: "#line 1 \"test/atcoder/arc106_b.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc106/tasks/arc106_b\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#line 3 \"src/Graph/LinearSystemIncidence.hpp\"\
    \n#include <tuple>\n#include <type_traits>\ntemplate <typename T> class LinearSystemIncidence\
    \ {\n int m;\n std::vector<std::vector<std::tuple<int, int, bool>>> adj;\npublic:\n\
    \ LinearSystemIncidence(int n): m(0), adj(n) {}\n void add_edge(int src, int dst)\
    \ { adj[src].emplace_back(m, dst, true), adj[dst].emplace_back(m++, src, false);\
    \ }\n std::vector<T> solve(const std::vector<T> &b) const {\n  std::vector<T>\
    \ x(m);\n  std::vector<bool> used(adj.size());\n  auto dfs= [&](auto self, int\
    \ u) -> T {\n   used[u]= true;\n   T ret= b[u];\n   for (auto [id, to, fwd]: adj[u])\n\
    \    if (!used[to]) {\n     T tmp= self(self, to);\n     if constexpr (std::is_same_v<T,\
    \ bool>) x[id]= tmp, ret^= tmp;\n     else x[id]= fwd ? tmp : -tmp, ret+= tmp;\n\
    \    }\n   return ret;\n  };\n  for (std::size_t u= adj.size(); u--;)\n   if (!used[u]\
    \ && dfs(dfs, u) != T(0)) return std::vector<T>();  // no sloutions\n  return\
    \ x;\n }\n};\n#line 6 \"test/atcoder/arc106_b.test.cpp\"\nusing namespace std;\n\
    // \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(false);\n int N, M;\n cin >> N >> M;\n LinearSystemIncidence<long\
    \ long> graph(N);\n vector<long long> a(N);\n for (int i= 0; i < N; i++) cin >>\
    \ a[i];\n for (int i= 0, b; i < N; i++) cin >> b, a[i]-= b;\n for (int i= 0, c,\
    \ d; i < M; i++) cin >> c >> d, graph.add_edge(--c, --d);\n if (M) cout << (graph.solve(a).empty()\
    \ ? \"No\" : \"Yes\") << '\\n';\n else cout << (all_of(begin(a), end(a), [](auto\
    \ t) { return !t; }) ? \"Yes\" : \"No\") << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc106/tasks/arc106_b\"\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\n#include \"src/Graph/LinearSystemIncidence.hpp\"\
    \nusing namespace std;\n// \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, M;\n cin\
    \ >> N >> M;\n LinearSystemIncidence<long long> graph(N);\n vector<long long>\
    \ a(N);\n for (int i= 0; i < N; i++) cin >> a[i];\n for (int i= 0, b; i < N; i++)\
    \ cin >> b, a[i]-= b;\n for (int i= 0, c, d; i < M; i++) cin >> c >> d, graph.add_edge(--c,\
    \ --d);\n if (M) cout << (graph.solve(a).empty() ? \"No\" : \"Yes\") << '\\n';\n\
    \ else cout << (all_of(begin(a), end(a), [](auto t) { return !t; }) ? \"Yes\"\
    \ : \"No\") << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/LinearSystemIncidence.hpp
  isVerificationFile: true
  path: test/atcoder/arc106_b.test.cpp
  requiredBy: []
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc106_b.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc106_b.test.cpp
- /verify/test/atcoder/arc106_b.test.cpp.html
title: test/atcoder/arc106_b.test.cpp
---
