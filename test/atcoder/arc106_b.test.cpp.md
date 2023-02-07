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
    \ {\n std::vector<std::array<int, 2>> es;\n std::vector<std::vector<int>> adj;\n\
    public:\n LinearSystemIncidence(int n): adj(n) {}\n void add_edge(int src, int\
    \ dst) {\n  int m= es.size();\n  adj[src].push_back(m), adj[dst].push_back(m),\
    \ es.push_back({src, dst});\n }\n std::vector<T> solve(std::vector<T> b) const\
    \ {\n  const int n= adj.size();\n  std::vector<T> x(es.size());\n  std::vector<int>\
    \ pre(n, -2), dat(n, 0);\n  for (int s= 0, p, e, q, f; s < n; ++s)\n   if (pre[s]\
    \ == -2)\n    for (pre[p= s]= -1;;) {\n     if (dat[p] == (int)adj[p].size())\
    \ {\n      if (e= pre[p]; e < 0) {\n       if (b[p] != T()) return {};  // no\
    \ solution\n       break;\n      }\n      f= (es[e][0] == p), q= es[e][f];\n \
    \     T tmp= b[p];\n      if constexpr (std::is_same_v<T, bool>) x[e]= tmp, b[q]=\
    \ tmp ^ b[q];\n      else x[e]= f ? -tmp : tmp, b[q]+= tmp;\n      p= q;\n   \
    \   continue;\n     }\n     if (e= adj[p][dat[p]++], q= es[e][es[e][0] == p];\
    \ pre[q] == -2) pre[q]= e, p= q;\n    }\n  return x;\n }\n};\n#line 6 \"test/atcoder/arc106_b.test.cpp\"\
    \nusing namespace std;\n// \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, M;\n cin\
    \ >> N >> M;\n LinearSystemIncidence<long long> graph(N);\n vector<long long>\
    \ a(N);\n for (int i= 0; i < N; i++) cin >> a[i];\n for (int i= 0, b; i < N; i++)\
    \ cin >> b, a[i]-= b;\n for (int i= 0, c, d; i < M; i++) cin >> c >> d, graph.add_edge(--c,\
    \ --d);\n if (M) cout << (graph.solve(a).empty() ? \"No\" : \"Yes\") << '\\n';\n\
    \ else cout << (all_of(begin(a), end(a), [](auto t) { return !t; }) ? \"Yes\"\
    \ : \"No\") << '\\n';\n return 0;\n}\n"
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
  timestamp: '2023-02-07 17:34:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc106_b.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc106_b.test.cpp
- /verify/test/atcoder/arc106_b.test.cpp.html
title: test/atcoder/arc106_b.test.cpp
---
