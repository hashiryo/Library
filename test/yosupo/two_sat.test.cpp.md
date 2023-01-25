---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: src/Math/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n#include <iostream>\n#include <string>\n#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\
    \n#include <vector>\n#include <array>\n#include <algorithm>\nclass StronglyConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj, rev;\npublic:\n StronglyConnectedComponents(int\
    \ n): adj(n), rev(n) {}\n void add_edge(int src, int dst) { adj[src].push_back(dst),\
    \ rev[dst].push_back(src); }\n std::vector<std::vector<int>> get_block() const\
    \ {\n  const int n= adj.size();\n  std::vector<std::vector<int>> blk;\n  std::vector<int>\
    \ ord(n), par(n, -2), dat(n, 0);\n  int k= n;\n  for (int s= 0; s < n; ++s)\n\
    \   if (par[s] == -2) {\n    par[s]= -1;\n    for (int p= s; p >= 0;) {\n    \
    \ if (dat[p] == (int)adj[p].size()) {\n      ord[--k]= p, p= par[p];\n      continue;\n\
    \     }\n     if (int q= adj[p][dat[p]++]; par[q] == -2) par[q]= p, p= q;\n  \
    \  }\n   }\n  dat.assign(n, 1);\n  for (int s: ord)\n   if (dat[s]) {\n    blk.resize(++k),\
    \ dat[s]= 0, blk.back().push_back(s);\n    for (int i= 0; i < (int)blk.back().size();\
    \ ++i)\n     for (int v: rev[blk.back()[i]])\n      if (dat[v]) dat[v]= 0, blk.back().push_back(v);\n\
    \   }\n  return blk;\n }\n std::vector<int> get_index(const std::vector<std::vector<int>>\
    \ &blk) const {\n  std::vector<int> index(adj.size());\n  for (int i= blk.size();\
    \ i--;)\n   for (int v: blk[i]) index[v]= i;\n  return index;\n }\n std::vector<std::vector<int>>\
    \ get_dag(const std::vector<int> &index, int num) const {\n  std::vector<std::vector<int>>\
    \ dag(num);\n  std::vector<std::array<int, 2>> es;\n  for (int i= adj.size();\
    \ i--;)\n   for (int j: adj[i])\n    if (int u= index[i], v= index[j]; u != v)\
    \ es.push_back({u, v});\n  std::sort(es.begin(), es.end()), es.erase(std::unique(es.begin(),\
    \ es.end()), es.end());\n  for (auto [u, v]: es) dag[u].push_back(v);\n  return\
    \ dag;\n }\n};\n#line 3 \"src/Math/TwoSatisfiability.hpp\"\nclass TwoSatisfiability\
    \ {\n int sz;\n StronglyConnectedComponents scc;\npublic:\n TwoSatisfiability(int\
    \ n): sz(n), scc(2 * n) {}\n void add_if(int u, int v) { scc.add_edge(u, v), scc.add_edge(neg(v),\
    \ neg(u)); }  // u -> v <=> !v -> !u\n void add_or(int u, int v) { add_if(neg(u),\
    \ v); }                                 // u or v <=> !u -> v\n void add_nand(int\
    \ u, int v) { add_if(u, neg(v)); }                               // u nand v <=>\
    \ u -> !v\n void set_true(int u) { scc.add_edge(neg(u), u); }                \
    \                // u <=> !u -> u\n void set_false(int u) { scc.add_edge(u, neg(u));\
    \ }                               // !u <=> u -> !u\n inline int neg(int x) const\
    \ { return x >= sz ? x - sz : x + sz; }\n std::vector<bool> solve() const {\n\
    \  std::vector<int> I= scc.get_index(scc.get_block());\n  std::vector<bool> ret(sz);\n\
    \  for (int i= 0; i < sz; i++) {\n   if (I[i] == I[neg(i)]) return {};  // no\
    \ solution\n   ret[i]= I[i] > I[neg(i)];\n  }\n  return ret;\n }\n};\n#line 6\
    \ \"test/yosupo/two_sat.test.cpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n string s;\n cin >> s >> s;\n int N, M;\n cin >> N\
    \ >> M;\n TwoSatisfiability sat(N + 1);\n for (int i= 0; i < M; i++) {\n  int\
    \ a, b;\n  cin >> a >> b >> s;\n  if (a < 0) a= sat.neg(-a);\n  if (b < 0) b=\
    \ sat.neg(-b);\n  sat.add_or(a, b);\n }\n auto ans= sat.solve();\n cout << \"\
    s \";\n if (ans.size()) {\n  cout << \"SATISFIABLE\" << endl;\n  cout << \"v \"\
    ;\n  for (int i= 1; i <= N; i++) {\n   cout << (ans[i] ? i : -i) << \" \";\n \
    \ }\n  cout << 0 << endl;\n } else {\n  cout << \"UNSATISFIABLE\" << endl;\n }\n\
    \ return 0;\n}\n"
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
  timestamp: '2023-01-25 18:54:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
