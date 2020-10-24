---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':x:'
    path: src/Math/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Graph/StronglyConnectedComponents.hpp\"\
    \n/**\n * @title \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @category \u30B0\
    \u30E9\u30D5\n *  Gabow\n *  O(V + E)\n *  \u8FD4\u308A\u5024:{\u5F37\u9023\u7D50\
    \u6210\u5206(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8),\u30CE\u30FC\
    \u30C9\u306E\u5C5E\u3059\u308B\u6210\u5206\u306E\u6DFB\u5B57}\n */\n\n// BEGIN\
    \ CUT HERE\n\nstruct StronglyConnectedComponents {\n  std::vector<std::vector<int>>\
    \ adj;\n\n  StronglyConnectedComponents(int n) : adj(n) {}\n  void add_edge(int\
    \ src, int dst) { adj[src].push_back(dst); }\n  std::pair<std::vector<std::vector<int>>,\
    \ std::vector<int>> get_SCC() {\n    std::vector<std::vector<int>> scc;\n    std::vector<int>\
    \ S, B, index(adj.size());\n    std::function<void(int)> dfs = [&](int u) {\n\
    \      B.push_back(index[u] = S.size());\n      S.push_back(u);\n      for (int\
    \ v : adj[u]) {\n        if (!index[v])\n          dfs(v);\n        else\n   \
    \       while (index[v] < B.back()) B.pop_back();\n      }\n      if (index[u]\
    \ == B.back()) {\n        scc.push_back({});\n        B.pop_back();\n        for\
    \ (; index[u] < (int)S.size(); S.pop_back()) {\n          scc.back().push_back(S.back());\n\
    \          index[S.back()] = adj.size() + scc.size();\n        }\n      }\n  \
    \  };\n    for (std::size_t u = 0; u < adj.size(); u++)\n      if (!index[u])\
    \ dfs(u);\n    reverse(scc.begin(), scc.end());\n    for (std::size_t u = 0; u\
    \ < adj.size(); u++)\n      index[u] = scc.size() - index[u] + adj.size();\n \
    \   return std::make_pair(scc, index);\n  }\n};\n#line 4 \"src/Math/TwoSatisfiability.hpp\"\
    \n/**\n * @title 2-SAT\n * @category \u6570\u5B66\n *  \u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3092\u7528\u3044\u308B\n *  solve():\u771F\u507D\u5024\u306E\
    \u5272\u5F53\u3092\u8FD4\u3059(\u5145\u8DB3\u4E0D\u53EF\u80FD\u306A\u3089\u7A7A\
    )\n */\n\n// BEGIN CUT HERE\n\nstruct TwoSatisfiability {\n private:\n  int sz;\n\
    \  StronglyConnectedComponents scc;\n\n public:\n  TwoSatisfiability(int n) :\
    \ sz(n), scc(2 * n) {}\n  void add_if(int u, int v) {\n    scc.add_edge(u, v);\n\
    \    scc.add_edge(neg(v), neg(u));\n  }                                      \
    \             // u -> v <=> !v -> !u\n  void add_or(int u, int v) { add_if(neg(u),\
    \ v); }    // u or v <=> !u -> v\n  void add_nand(int u, int v) { add_if(u, neg(v));\
    \ }  // u nand v <=> u -> !v\n  void set_true(int u) { scc.add_edge(neg(u), u);\
    \ }   // u <=> !u -> u\n  void set_false(int u) { scc.add_edge(u, neg(u)); } \
    \ // !u <=> u -> !u\n  inline int neg(int x) { return x >= sz ? x - sz : x + sz;\
    \ }\n  std::vector<short> solve() {\n    std::vector<int> I = scc.get_SCC().second;\n\
    \    std::vector<short> ret(sz);\n    for (int i = 0; i < sz; i++) {\n      if\
    \ (I[i] == I[neg(i)]) return {};\n      ret[i] = I[i] > I[neg(i)];\n    }\n  \
    \  return ret;\n  }\n};\n#line 5 \"test/yosupo/two_sat.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  string\
    \ s;\n  cin >> s >> s;\n  int N, M;\n  cin >> N >> M;\n  TwoSatisfiability sat(N\
    \ + 1);\n  for (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >> b >>\
    \ s;\n    if (a < 0) a = sat.neg(-a);\n    if (b < 0) b = sat.neg(-b);\n    sat.add_or(a,\
    \ b);\n  }\n  auto ans = sat.solve();\n  cout << \"s \";\n  if (ans.size()) {\n\
    \    cout << \"SATISFIABLE\" << endl;\n    cout << \"v \";\n    for (int i = 1;\
    \ i <= N; i++) {\n      cout << (ans[i] ? i : -i) << \" \";\n    }\n    cout <<\
    \ 0 << endl;\n  } else {\n    cout << \"UNSATISFIABLE\" << endl;\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\n\
    #include \"src/Graph/StronglyConnectedComponents.hpp\"\n#include \"src/Math/TwoSatisfiability.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  string s;\n  cin >> s >> s;\n  int N, M;\n  cin >> N >> M;\n  TwoSatisfiability\
    \ sat(N + 1);\n  for (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >>\
    \ b >> s;\n    if (a < 0) a = sat.neg(-a);\n    if (b < 0) b = sat.neg(-b);\n\
    \    sat.add_or(a, b);\n  }\n  auto ans = sat.solve();\n  cout << \"s \";\n  if\
    \ (ans.size()) {\n    cout << \"SATISFIABLE\" << endl;\n    cout << \"v \";\n\
    \    for (int i = 1; i <= N; i++) {\n      cout << (ans[i] ? i : -i) << \" \"\
    ;\n    }\n    cout << 0 << endl;\n  } else {\n    cout << \"UNSATISFIABLE\" <<\
    \ endl;\n  }\n  return 0;\n}"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  - src/Math/TwoSatisfiability.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:09:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
