---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':question:'
    path: src/Graph/BipartiteGraph.hpp
    title: "(\u6697\u9ED9\u7684\u306A)\u4E8C\u90E8\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u3060\u3051\u6301\u3063\u3066\u304A\u304F\
      \u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.bipatite_graph.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <iostream>\n#line 2 \"src/Graph/BipartiteGraph.hpp\"\n#include <array>\n#include\
    \ <algorithm>\n#include <numeric>\n#include <cassert>\n#line 2 \"src/Internal/ListRange.hpp\"\
    \n#include <vector>\n#include <iterator>\ntemplate <class T> struct ListRange\
    \ {\n using Iterator= typename std::vector<T>::const_iterator;\n Iterator bg,\
    \ ed;\n Iterator begin() const { return bg; }\n Iterator end() const { return\
    \ ed; }\n size_t size() const { return std::distance(bg, ed); }\n const T &operator[](int\
    \ i) const { return bg[i]; }\n};\n#line 3 \"src/DataStructure/CsrArray.hpp\"\n\
    template <class T> class CsrArray {\n std::vector<T> csr;\n std::vector<int> pos;\n\
    public:\n CsrArray()= default;\n CsrArray(const std::vector<T> &c, const std::vector<int>\
    \ &p): csr(c), pos(p) {}\n size_t size() const { return pos.size() - 1; }\n const\
    \ ListRange<T> operator[](int i) const { return {csr.cbegin() + pos[i], csr.cbegin()\
    \ + pos[i + 1]}; }\n};\n#line 7 \"src/Graph/BipartiteGraph.hpp\"\nclass BipartiteGraph\
    \ {\n std::vector<std::array<int, 2>> es;\n std::vector<int> col, pos, ord, pre,\
    \ mate, blg;\n CsrArray<int> dag_[2];\n int l;\npublic:\n BipartiteGraph(int n):\
    \ col(n, -1), pos(n + 1), ord(n), mate(n, -1), blg(n, -3), l(0) {}\n void add_edge(int\
    \ u, int v) { es.push_back({u, v}); }\n void build() {\n  const int n= col.size();\n\
    \  std::vector<int> rt, que(n), g(es.size() * 2);\n  for (auto [u, v]: es) ++pos[u],\
    \ ++pos[v];\n  for (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (auto [u,\
    \ v]: es) g[--pos[u]]= v, g[--pos[v]]= u;\n  for (int s= n, i= 0, t= 0, r= n;\
    \ s--;)\n   if (col[s] == -1)\n    for (col[s]= 0, ord[l++]= que[t++]= s; i <\
    \ t; ++i)\n     for (int v= que[i], c= col[v], j= pos[v], u; j < pos[v + 1]; ++j)\n\
    \      if (assert(col[u= g[j]] != c); col[u] == -1) col[u]= !c, ord[(c ? l++ :\
    \ --r)]= que[t++]= u;\n  int t= 0, k= 0;\n  for (bool upd= true; upd; t= 0) {\n\
    \   upd= false, rt.assign(n, -1), pre.assign(n, -1);\n   for (int i= l; i--;)\n\
    \    if (int v= ord[i]; mate[v] == -1) que[t++]= rt[v]= pre[v]= v;\n   for (int\
    \ i= 0; i < t; ++i)\n    if (int v= que[i]; mate[rt[v]] == -1)\n     for (int\
    \ j= pos[v], u, w; j < pos[v + 1]; ++j) {\n      if (w= mate[u= g[j]]; w == -1)\
    \ {\n       for (upd= true; u != -1; v= pre[v]) mate[u]= v, std::swap(mate[v],\
    \ u);\n       break;\n      }\n      if (pre[w] == -1) rt[que[t++]= w]= rt[pre[w]=\
    \ v];\n     }\n  }\n  for (int i= l; i--;)\n   if (int s= ord[i]; rt[s] != -1)\n\
    \    if (blg[s]= -1, s= mate[s]; s != -1) blg[s]= -1;\n  for (int i= l; i < n;\
    \ ++i)\n   if (int s= ord[i]; mate[s] == -1) blg[que[t++]= s]= 0;\n  for (int\
    \ i= 0; i < t; ++i)\n   for (int v= que[i], j= pos[v], u, w; j < pos[v + 1]; ++j)\n\
    \    if (blg[u= g[j]] == -3)\n     if (w= mate[u], blg[u]= 0; w != -1 && blg[w]\
    \ == -3) blg[que[t++]= w]= 0;\n  pre.assign(pos.begin(), pos.begin() + n), t=\
    \ 0;\n  for (int i= l; i--;)\n   if (int v= ord[i]; blg[v] == -3)\n    for (blg[v]=\
    \ -4; v >= 0;) {\n     if (pre[v] == pos[v + 1]) rt[t++]= v, v= blg[v];\n    \
    \ else if (int w= mate[g[pre[v]++]]; blg[w] == -3) blg[w]= v, v= w;\n    }\n \
    \ for (int i= 0, e= 0; t--;)\n   if (int s= rt[t], p= mate[s]; blg[p] == -3)\n\
    \    for (que[e++]= p, blg[s]= blg[p]= ++k; i < e; ++i)\n     for (int v= que[i],\
    \ j= pos[v]; j < pos[v + 1]; ++j)\n      if (int u= g[j], w= mate[u]; blg[w] ==\
    \ -3) que[e++]= w, blg[u]= blg[w]= k;\n  pos.assign(++k + 2, 0);\n  for (int v=\
    \ n; v--; ++pos[blg[v]])\n   if (blg[v] == -1) blg[v]= k;\n  for (int i= 0; i\
    \ <= k; ++i) pos[i + 1]+= pos[i];\n  for (int v= n; v--;) pre[--pos[blg[v]]]=\
    \ v;\n  std::vector<std::array<int, 2>> es_;\n  for (auto &[u, v]: es) {\n   if\
    \ (col[u]) std::swap(u, v);\n   if (int a= blg[u], b= blg[v]; a != b) es_.push_back({a,\
    \ b});\n  }\n  std::sort(es_.begin(), es_.end()), es_.erase(std::unique(es_.begin(),\
    \ es_.end()), es_.end());\n  std::vector<int> dg0(es_.size()), dg1(es_.size()),\
    \ sp0(k + 2), sp1(k + 2);\n  for (auto [u, v]: es_) ++sp0[u], ++sp1[v];\n  std::partial_sum(sp0.begin(),\
    \ sp0.end(), sp0.begin()), std::partial_sum(sp1.begin(), sp1.end(), sp1.begin());\n\
    \  for (auto [u, v]: es_) dg0[--sp0[u]]= v, dg1[--sp1[v]]= u;\n  dag_[0]= {dg0,\
    \ sp0}, dag_[1]= {dg1, sp1};\n }\n const std::vector<std::array<int, 2>> &edges()\
    \ const { return es; }\n bool color(int v) const { return col[v]; }\n const ListRange<int>\
    \ left_vertices() const { return {ord.cbegin(), ord.cbegin() + l}; }\n const ListRange<int>\
    \ right_vertices() const { return {ord.cbegin() + l, ord.cend()}; }\n int match(int\
    \ v) const { return mate[v]; }\n int component_num() const { return pos.size()\
    \ - 1; }\n int belong(int v) const { return blg[v]; }\n const ListRange<int> block(int\
    \ k) const { return {pre.cbegin() + pos[k], pre.cbegin() + pos[k + 1]}; }\n template\
    \ <bool rev> const CsrArray<int> &dag() { return dag_[rev]; }\n std::vector<std::array<int,\
    \ 2>> max_matching() const {\n  std::vector<std::array<int, 2>> ret;\n  for (int\
    \ i= l; i--;)\n   if (int v= ord[i], u= mate[v]; u != -1) ret.push_back({v, u});\n\
    \  return ret;\n }\n std::vector<int> min_vertex_cover() const {\n  const int\
    \ n= col.size(), m= component_num();\n  std::vector<int> sel(m, -1), ret, que(m);\n\
    \  sel[0]= 1, sel.back()= 0;\n  for (int v= 0, k, s, c, i, t; v < n; ++v) {\n\
    \   if (c= col[v], s= sel[k= blg[v]]; s == -1)\n    for (sel[que[0]= k]= s= !c,\
    \ i= 0, t= 1; i < t; ++i)\n     for (int u: dag_[s][que[i]])\n      if (sel[u]\
    \ == -1) sel[u]= s, que[t++]= u;\n   if (c ^ s) ret.push_back(v);\n  }\n  return\
    \ ret;\n }\n std::vector<int> max_independent_set() const {\n  const int n= col.size(),\
    \ m= component_num();\n  std::vector<int> sel(m, -1), ret, que(m);\n  sel[0]=\
    \ 0, sel.back()= 1;\n  for (int v= 0, k, s, c, i, t; v < n; ++v) {\n   if (c=\
    \ col[v], s= sel[k= blg[v]]; s == -1)\n    for (sel[que[0]= k]= s= !c, i= 0, t=\
    \ 1; i < t; ++i)\n     for (int u: dag_[c][que[i]])\n      if (sel[u] == -1) sel[u]=\
    \ s, que[t++]= u;\n   if (c ^ s) ret.push_back(v);\n  }\n  return ret;\n }\n};\n\
    #line 4 \"test/yosupo/bipartitematching.bipatite_graph.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int L, R, M;\n\
    \ cin >> L >> R >> M;\n BipartiteGraph graph(L + R);\n while (M--) {\n  int a,\
    \ b;\n  cin >> a >> b;\n  graph.add_edge(a, L + b);\n }\n graph.build();\n cout\
    \ << graph.max_matching().size() << '\\n';\n for (int l= 0; l < L; ++l)\n  if\
    \ (int r= graph.match(l); r != -1) cout << l << \" \" << r - L << '\\n';\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <iostream>\n#include \"src/Graph/BipartiteGraph.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int L, R, M;\n cin\
    \ >> L >> R >> M;\n BipartiteGraph graph(L + R);\n while (M--) {\n  int a, b;\n\
    \  cin >> a >> b;\n  graph.add_edge(a, L + b);\n }\n graph.build();\n cout <<\
    \ graph.max_matching().size() << '\\n';\n for (int l= 0; l < L; ++l)\n  if (int\
    \ r= graph.match(l); r != -1) cout << l << \" \" << r - L << '\\n';\n return 0;\n\
    }"
  dependsOn:
  - src/Graph/BipartiteGraph.hpp
  - src/DataStructure/CsrArray.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.bipatite_graph.test.cpp
  requiredBy: []
  timestamp: '2024-02-06 20:21:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.bipatite_graph.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.bipatite_graph.test.cpp
- /verify/test/yosupo/bipartitematching.bipatite_graph.test.cpp.html
title: test/yosupo/bipartitematching.bipatite_graph.test.cpp
---
