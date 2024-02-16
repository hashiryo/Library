---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':x:'
    path: src/Graph/block_cut_tree.hpp
    title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (block-cut-tree (\u62E1\
      \u5F35))"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/yosupo/biconnected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n#include <iostream>\n\
    #line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#line 4 \"src/Internal/ListRange.hpp\"\
    \n#include <iterator>\n#include <type_traits>\n#define _LR(name, IT, CT) \\\n\
    \ template <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT;\
    \ \\\n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
    \ end() const { return ed; } \\\n  size_t size() const { return std::distance(bg,\
    \ ed); } \\\n  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange,\
    \ iterator, const T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\n\
    template <class T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int>\
    \ p;\n size_t size() const { return p.size() - 1; }\n ListRange<T> operator[](int\
    \ i) { return {dat.begin() + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T>\
    \ operator[](int i) const { return {dat.cbegin() + p[i], dat.cbegin() + p[i +\
    \ 1]}; }\n};\ntemplate <template <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
    \ ListRange<T>>, std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>,\
    \ std::ostream &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n\
    \ for (int _= 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n\
    \ return os << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int,\
    \ int> {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
    \ --second, *this; }\n int to(int v) const { return first ^ second ^ v; }\n friend\
    \ std::istream &operator>>(std::istream &is, Edge &e) { return is >> e.first >>\
    \ e.second, is; }\n};\nstruct Graph: std::vector<Edge> {\n size_t n;\n Graph(size_t\
    \ n= 0, size_t m= 0): n(n), vector(m) {}\n size_t vertex_size() const { return\
    \ n; }\n size_t edge_size() const { return size(); }\n size_t add_vertex() { return\
    \ n++; }\n size_t add_edge(int s, int d) { return emplace_back(s, d), size() -\
    \ 1; }\n size_t add_edge(Edge e) { return emplace_back(e), size() - 1; }\n#define\
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (int i= 0; i < n; ++i)\
    \ p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) b;\n#define _ADJ(a, b) \\\n\
    \ vector<int> p(n + 1), c(size() << !direct); \\\n if (direct) { \\\n  _ADJ_FOR(++p[u],\
    \ c[--p[(*this)[i].first]]= a) \\\n } else { \\\n  _ADJ_FOR((++p[u], ++p[v]),\
    \ (c[--p[(*this)[i].first]]= a, c[--p[(*this)[i].second]]= b)) \\\n } \\\n return\
    \ {std::move(c), std::move(p)}\n CSRArray<int> adjacency_vertex(bool direct) const\
    \ { _ADJ((*this)[i].second, (*this)[i].first); }\n CSRArray<int> adjacency_edge(bool\
    \ direct) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"\
    src/Graph/block_cut_tree.hpp\"\n// [0,n) : vertex\n// [n,n+b) : block\n// deg(v)\
    \ > 1 -> articulation point\nGraph block_cut_tree(const CSRArray<int> &adj) {\n\
    \ const int n= adj.size();\n std::vector<int> ord(n), par(n, -2), dat(adj.p.begin(),\
    \ adj.p.begin() + n);\n int k= 0;\n for (int s= n, p; s--;)\n  if (par[s] == -2)\n\
    \   for (par[p= s]= -1; p >= 0;) {\n    if (dat[p] == adj.p[p]) ord[k++]= p;\n\
    \    if (dat[p] == adj.p[p + 1]) p= par[p];\n    else if (int q= adj.dat[dat[p]++];\
    \ par[q] == -2) par[q]= p, p= q;\n   }\n for (int i= n; i--;) dat[ord[i]]= i;\n\
    \ auto low= dat;\n for (int v= n; v--;)\n  for (int u: adj[v]) low[v]= std::min(low[v],\
    \ dat[u]);\n for (int i= n; i--;)\n  if (int p= ord[i], pp= par[p]; pp >= 0) low[pp]=\
    \ std::min(low[pp], low[p]);\n Graph ret(k);\n for (int p: ord)\n  if (par[p]\
    \ >= 0) {\n   if (int pp= par[p]; low[p] < dat[pp]) ret.add_edge(low[p]= low[pp],\
    \ p);\n   else ret.add_vertex(), ret.add_edge(k, pp), ret.add_edge(k, p), low[p]=\
    \ k++;\n  }\n for (int s= 0; s < n; ++s)\n  if (!adj[s].size()) ret.add_edge(ret.add_vertex(),\
    \ s);\n return ret;\n}\nGraph block_cut_tree(const Graph &g) { return block_cut_tree(g.adjacency_vertex(0));\
    \ }\n#line 5 \"test/yosupo/biconnected_components.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n\
    \ cin >> N >> M;\n Graph g(N, M);\n for (int i= 0; i < M; ++i) cin >> g[i];\n\
    \ auto bct= block_cut_tree(g).adjecency_vertex(0);\n int K= bct.size();\n cout\
    \ << K - N << '\\n';\n for (int i= N; i < K; ++i) {\n  cout << bct[i].size();\n\
    \  for (int v: bct[i]) cout << \" \" << v;\n  cout << '\\n';\n }\n return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n#include <iostream>\n#include \"src/Graph/Graph.hpp\"\n#include \"src/Graph/block_cut_tree.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n Graph g(N, M);\n for (int i= 0; i < M; ++i) cin\
    \ >> g[i];\n auto bct= block_cut_tree(g).adjecency_vertex(0);\n int K= bct.size();\n\
    \ cout << K - N << '\\n';\n for (int i= N; i < K; ++i) {\n  cout << bct[i].size();\n\
    \  for (int v: bct[i]) cout << \" \" << v;\n  cout << '\\n';\n }\n return 0;\n\
    }"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/Graph/block_cut_tree.hpp
  isVerificationFile: true
  path: test/yosupo/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2024-02-16 12:23:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/biconnected_components.test.cpp
- /verify/test/yosupo/biconnected_components.test.cpp.html
title: test/yosupo/biconnected_components.test.cpp
---
