---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/Matching.hpp
    title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.matching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include <iostream>\n\
    #line 2 \"src/Graph/Matching.hpp\"\n#include <vector>\n#include <array>\nclass\
    \ Matching {\n std::vector<std::array<int, 2>> es;\n std::vector<int> mate;\n\
    public:\n Matching(int n): mate(n, -1) {}\n void add_edge(int u, int v) { es.push_back({u,\
    \ v}); }\n void build() {\n  const int n= mate.size();\n  std::vector<int> g(es.size()\
    \ * 2), pos(n + 1), que(n), id(n, -1), p(n);\n  std::vector<std::array<int, 2>>\
    \ fs(n);\n  for (auto [u, v]: es) ++pos[u], ++pos[v];\n  for (int i= 0; i < n;\
    \ ++i) pos[i + 1]+= pos[i];\n  for (auto [u, v]: es) g[--pos[u]]= v, g[--pos[v]]=\
    \ u;\n  auto rematch= [&](auto self, int u, int v) -> void {\n   int w;\n   if\
    \ (w= mate[u], mate[u]= v; w == -1 || mate[w] != u) return;\n   if (auto [x, y]=\
    \ fs[u]; y == -1) self(self, mate[w]= x, w);\n   else self(self, x, y), self(self,\
    \ y, x);\n  };\n  int ts= 0;\n  auto f= [&](auto self, int x) -> int { return\
    \ id[x] != ts || p[x] == -1 ? x : (p[x]= self(self, p[x])); };\n  auto check=\
    \ [&](int rt) {\n   int s= 1;\n   fs[rt]= {-1, -1}, id[rt]= ts, p[que[0]= rt]=\
    \ -1;\n   for (int i= 0; i < s; ++i) {\n    for (int x= que[i], j= pos[x], y,\
    \ u, v, w, a, b; j < pos[x + 1]; ++j) {\n     if (y= g[j]; y == rt) continue;\n\
    \     if (mate[y] == -1) return rematch(rematch, mate[y]= x, y), true;\n     if\
    \ (id[y] == ts) {\n      if (a= u= f(f, x), b= v= f(f, y), w= rt; u == v) continue;\n\
    \      for (; u != rt || v != rt; fs[u]= {x, y}, u= f(f, fs[mate[u]][0])) {\n\
    \       if (v != rt) std::swap(u, v);\n       if (fs[u][0] == x && fs[u][1] ==\
    \ y) {\n        w= u;\n        break;\n       }\n      }\n      for (; a != w;\
    \ a= f(f, fs[mate[a]][0])) id[a]= ts, p[a]= w, que[s++]= a;\n      for (; b !=\
    \ w; b= f(f, fs[mate[b]][0])) id[b]= ts, p[b]= w, que[s++]= b;\n     } else if\
    \ (id[mate[y]] != ts) fs[y]= {-1, -1}, fs[mate[y]]= {x, -1}, id[mate[y]]= ts,\
    \ p[mate[y]]= y, que[s++]= mate[y];\n    }\n   }\n   return false;\n  };\n  for\
    \ (int rt= n; rt--;)\n   if (mate[rt] == -1) ts+= check(rt);\n }\n int match(int\
    \ u) const { return mate[u]; }\n std::vector<std::array<int, 2>> max_matching()\
    \ const {\n  std::vector<std::array<int, 2>> ret;\n  const int n= mate.size();\n\
    \  for (int i= 0; i < n; ++i)\n   if (int j= mate[i]; i < j) ret.push_back({i,\
    \ j});\n  return ret;\n }\n};\n#line 4 \"test/yosupo/bipartitematching.matching.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int L, R, M;\n cin >> L >> R >> M;\n Matching graph(L + R);\n while (M--) {\n\
    \  int a, b;\n  cin >> a >> b;\n  graph.add_edge(a, L + b);\n }\n graph.build();\n\
    \ cout << graph.max_matching().size() << '\\n';\n for (int l= 0; l < L; ++l)\n\
    \  if (int r= graph.match(l); r != -1) cout << l << \" \" << r - L << '\\n';\n\
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <iostream>\n#include \"src/Graph/Matching.hpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int L, R, M;\n cin >> L\
    \ >> R >> M;\n Matching graph(L + R);\n while (M--) {\n  int a, b;\n  cin >> a\
    \ >> b;\n  graph.add_edge(a, L + b);\n }\n graph.build();\n cout << graph.max_matching().size()\
    \ << '\\n';\n for (int l= 0; l < L; ++l)\n  if (int r= graph.match(l); r != -1)\
    \ cout << l << \" \" << r - L << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/Matching.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.matching.test.cpp
  requiredBy: []
  timestamp: '2023-03-16 02:01:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.matching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.matching.test.cpp
- /verify/test/yosupo/bipartitematching.matching.test.cpp.html
title: test/yosupo/bipartitematching.matching.test.cpp
---
