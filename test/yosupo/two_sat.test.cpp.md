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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n#include <iostream>\n#include <string>\n#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\
    \n#include <vector>\n#include <functional>\n#include <algorithm>\nstruct StronglyConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj;\n StronglyConnectedComponents(int n):\
    \ adj(n) {}\n void add_edge(int src, int dst) { adj[src].push_back(dst); }\n std::pair<std::vector<std::vector<int>>,\
    \ std::vector<int>> get_SCC() {\n  std::vector<std::vector<int>> scc;\n  std::vector<int>\
    \ S, B, index(adj.size());\n  std::function<void(int)> dfs= [&](int u) {\n   B.push_back(index[u]=\
    \ S.size());\n   S.push_back(u);\n   for (int v: adj[u]) {\n    if (!index[v])\
    \ dfs(v);\n    else\n     while (index[v] < B.back()) B.pop_back();\n   }\n  \
    \ if (index[u] == B.back()) {\n    scc.push_back({});\n    B.pop_back();\n   \
    \ for (; index[u] < (int)S.size(); S.pop_back()) {\n     scc.back().push_back(S.back());\n\
    \     index[S.back()]= adj.size() + scc.size();\n    }\n   }\n  };\n  for (std::size_t\
    \ u= 0; u < adj.size(); u++)\n   if (!index[u]) dfs(u);\n  reverse(scc.begin(),\
    \ scc.end());\n  for (std::size_t u= 0; u < adj.size(); u++) index[u]= scc.size()\
    \ - index[u] + adj.size();\n  return std::make_pair(scc, index);\n }\n};\n#line\
    \ 3 \"src/Math/TwoSatisfiability.hpp\"\nstruct TwoSatisfiability {\nprivate:\n\
    \ int sz;\n StronglyConnectedComponents scc;\npublic:\n TwoSatisfiability(int\
    \ n): sz(n), scc(2 * n) {}\n void add_if(int u, int v) {\n  scc.add_edge(u, v);\n\
    \  scc.add_edge(neg(v), neg(u));\n }                                         \
    \          // u -> v <=> !v -> !u\n void add_or(int u, int v) { add_if(neg(u),\
    \ v); }    // u or v <=> !u -> v\n void add_nand(int u, int v) { add_if(u, neg(v));\
    \ }  // u nand v <=> u -> !v\n void set_true(int u) { scc.add_edge(neg(u), u);\
    \ }   // u <=> !u -> u\n void set_false(int u) { scc.add_edge(u, neg(u)); }  //\
    \ !u <=> u -> !u\n inline int neg(int x) { return x >= sz ? x - sz : x + sz; }\n\
    \ std::vector<short> solve() {\n  std::vector<int> I= scc.get_SCC().second;\n\
    \  std::vector<short> ret(sz);\n  for (int i= 0; i < sz; i++) {\n   if (I[i] ==\
    \ I[neg(i)]) return {};\n   ret[i]= I[i] > I[neg(i)];\n  }\n  return ret;\n }\n\
    };\n#line 6 \"test/yosupo/two_sat.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n string s;\n cin >> s >> s;\n int\
    \ N, M;\n cin >> N >> M;\n TwoSatisfiability sat(N + 1);\n for (int i= 0; i <\
    \ M; i++) {\n  int a, b;\n  cin >> a >> b >> s;\n  if (a < 0) a= sat.neg(-a);\n\
    \  if (b < 0) b= sat.neg(-b);\n  sat.add_or(a, b);\n }\n auto ans= sat.solve();\n\
    \ cout << \"s \";\n if (ans.size()) {\n  cout << \"SATISFIABLE\" << endl;\n  cout\
    \ << \"v \";\n  for (int i= 1; i <= N; i++) {\n   cout << (ans[i] ? i : -i) <<\
    \ \" \";\n  }\n  cout << 0 << endl;\n } else {\n  cout << \"UNSATISFIABLE\" <<\
    \ endl;\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <iostream>\n\
    #include <string>\n#include \"src/Graph/StronglyConnectedComponents.hpp\"\n#include\
    \ \"src/Math/TwoSatisfiability.hpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(0);\n string s;\n cin >> s >> s;\n int N,\
    \ M;\n cin >> N >> M;\n TwoSatisfiability sat(N + 1);\n for (int i= 0; i < M;\
    \ i++) {\n  int a, b;\n  cin >> a >> b >> s;\n  if (a < 0) a= sat.neg(-a);\n \
    \ if (b < 0) b= sat.neg(-b);\n  sat.add_or(a, b);\n }\n auto ans= sat.solve();\n\
    \ cout << \"s \";\n if (ans.size()) {\n  cout << \"SATISFIABLE\" << endl;\n  cout\
    \ << \"v \";\n  for (int i= 1; i <= N; i++) {\n   cout << (ans[i] ? i : -i) <<\
    \ \" \";\n  }\n  cout << 0 << endl;\n } else {\n  cout << \"UNSATISFIABLE\" <<\
    \ endl;\n }\n return 0;\n}"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  - src/Math/TwoSatisfiability.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 20:22:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
