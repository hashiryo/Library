---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/IncrementalBridgeConnectivity.hpp
    title: "Incremental-Bridge-Connectivity (\u4E8C\u8FBA\u9023\u7D50\u6210\u5206)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\
    #include <iostream>\n#include <vector>\n#line 2 \"src/Graph/IncrementalBridgeConnectivity.hpp\"\
    \n#include <utility>\n#line 4 \"src/Graph/IncrementalBridgeConnectivity.hpp\"\n\
    class IncrementalBridgeConnectivity {\n std::vector<int> cp, bp, bbf, z;\n int\
    \ t;\n inline int crt(int v) { return cp[v] < 0 ? v : cp[v]= crt(cp[v]); }\n inline\
    \ int par(int v) { return bbf[v] < 0 ? -1 : leader(bbf[v]); }\npublic:\n IncrementalBridgeConnectivity(int\
    \ n): cp(n, -1), bp(n, -1), bbf(n, -1), z(n), t(0) {}\n inline int leader(int\
    \ v) { return bp[v] < 0 ? v : bp[v]= leader(bp[v]); }\n int size(int v) { return\
    \ -bp[leader(v)]; }\n bool two_edge_connected(int u, int v) { return leader(u)\
    \ == leader(v); }\n bool connected(int u, int v) { return crt(u) == crt(v); }\n\
    \ void add_edge(int u, int v) {\n  int a= crt(u= leader(u)), b= crt(v= leader(v));\n\
    \  if (a == b)\n   for (++t, a= u, b= v;;) {\n    if (z[a] == t) {\n     for (int\
    \ w: {u, v})\n      for (int p; w= leader(w), w != a; bp[a]+= bp[w], bp[w]= a,\
    \ w= p)\n       if (p= bbf[w], bbf[w]= bbf[a]; bp[a] > bp[w]) std::swap(w, a);\n\
    \     return;\n    }\n    if (z[a]= t, a= par(a); b != -1) std::swap(a, b);\n\
    \   }\n  if (cp[a] < cp[b]) std::swap(u, v), cp[a]+= cp[b], cp[b]= a;\n  else\
    \ cp[b]+= cp[a], cp[a]= b;\n  for (int p; u != -1; u= p) p= par(u), bbf[u]= v,\
    \ v= u;\n }\n};\n#line 5 \"test/yosupo/two_edge_connected_components.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n IncrementalBridgeConnectivity ibc(N);\n for (int\
    \ i= 0, a, b; i < M; i++) cin >> a >> b, ibc.add_edge(a, b);\n int n= 0;\n vector<int>\
    \ ans[N];\n for (int i= 0; i < N; ++i) {\n  int j= ibc.leader(i);\n  ans[j].push_back(i);\n\
    \  if (ans[j].size() == 1) ++n;\n }\n cout << n << '\\n';\n for (int i= 0; i <\
    \ N; ++i)\n  if (!ans[i].empty()) {\n   cout << ans[i].size();\n   for (int v:\
    \ ans[i]) cout << \" \" << v;\n   cout << '\\n';\n  }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/Graph/IncrementalBridgeConnectivity.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n IncrementalBridgeConnectivity ibc(N);\n for (int\
    \ i= 0, a, b; i < M; i++) cin >> a >> b, ibc.add_edge(a, b);\n int n= 0;\n vector<int>\
    \ ans[N];\n for (int i= 0; i < N; ++i) {\n  int j= ibc.leader(i);\n  ans[j].push_back(i);\n\
    \  if (ans[j].size() == 1) ++n;\n }\n cout << n << '\\n';\n for (int i= 0; i <\
    \ N; ++i)\n  if (!ans[i].empty()) {\n   cout << ans[i].size();\n   for (int v:\
    \ ans[i]) cout << \" \" << v;\n   cout << '\\n';\n  }\n return 0;\n}"
  dependsOn:
  - src/Graph/IncrementalBridgeConnectivity.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-02-20 18:08:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
