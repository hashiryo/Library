---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#include <iostream>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n\
    #line 4 \"src/Internal/ListRange.hpp\"\n#include <iterator>\n#include <type_traits>\n\
    #define _LR(name, IT, CT) \\\n template <class T> struct name { \\\n  using Iterator=\
    \ typename std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const\
    \ { return bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size()\
    \ const { return std::distance(bg, ed); } \\\n  CT &operator[](int i) const {\
    \ return bg[i]; } \\\n }\n_LR(ListRange, iterator, const T);\n_LR(ConstListRange,\
    \ const_iterator, const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n\
    \ std::vector<T> dat;\n std::vector<int> p;\n size_t size() const { return p.size()\
    \ - 1; }\n ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin()\
    \ + p[i + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int, int>\
    \ {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
    \ --second, *this; }\n int to(int v) const { return first ^ second ^ v; }\n friend\
    \ std::istream &operator>>(std::istream &is, Edge &e) { return is >> e.first >>\
    \ e.second, is; }\n};\nstruct Graph: std::vector<Edge> {\n size_t n;\n Graph(size_t\
    \ n= 0, size_t m= 0): vector(m), n(n) {}\n size_t vertex_size() const { return\
    \ n; }\n size_t edge_size() const { return size(); }\n size_t add_vertex() { return\
    \ n++; }\n size_t add_edge(int s, int d) { return emplace_back(s, d), size() -\
    \ 1; }\n size_t add_edge(Edge e) { return emplace_back(e), size() - 1; }\n#define\
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (int i= 0; i < n; ++i)\
    \ p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) { \\\n  auto [u, v]= (*this)[i];\
    \ \\\n  b; \\\n }\n#define _ADJ(a, b) \\\n vector<int> p(n + 1), c(size() << !dir);\
    \ \\\n if (!dir) { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[u]]= a, c[--p[v]]=\
    \ b)) \\\n } else if (dir > 0) { \\\n  _ADJ_FOR(++p[u], c[--p[u]]= a) \\\n } else\
    \ { \\\n  _ADJ_FOR(++p[v], c[--p[v]]= b) \\\n } \\\n return {c, p}\n CSRArray<int>\
    \ adjacency_vertex(int dir) const { _ADJ(v, u); }\n CSRArray<int> adjacency_edge(int\
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/Graph/StronglyConnectedComponents.hpp\"\n\
    class StronglyConnectedComponents {\n std::vector<int> csr, pos, ord;\npublic:\n\
    \ StronglyConnectedComponents(const Graph &g) {\n  const int n= g.vertex_size();\n\
    \  csr.assign(n, -2), ord.resize(n), pos= {0};\n  {\n   auto adj= g.adjacency_vertex(1);\n\
    \   std::vector<int> ei(adj.p.begin(), adj.p.begin() + n);\n   for (int s= 0,\
    \ k= n, p; s < n; ++s)\n    if (csr[s] == -2)\n     for (csr[p= s]= -1; p >= 0;)\
    \ {\n      if (ei[p] == adj.p[p + 1]) ord[--k]= p, p= csr[p];\n      else if (int\
    \ q= adj.dat[ei[p]++]; csr[q] == -2) csr[q]= p, p= q;\n     }\n  }\n  auto adj=\
    \ g.adjacency_vertex(-1);\n  std::vector<char> vis(n);\n  int k= 0, p= 0;\n  for\
    \ (int s: ord)\n   if (!vis[s]) {\n    for (vis[csr[k++]= s]= 1; p < k; ++p)\n\
    \     for (int u: adj[csr[p]])\n      if (!vis[u]) vis[csr[k++]= u]= 1;\n    pos.push_back(k);\n\
    \   }\n  for (int i= pos.size() - 1; i--;)\n   while (k > pos[i]) ord[csr[--k]]=\
    \ i;\n }\n size_t size() const { return pos.size() - 1; }\n ConstListRange<int>\
    \ block(int k) const { return {csr.cbegin() + pos[k], csr.cbegin() + pos[k + 1]};\
    \ }\n int operator()(int i) const { return ord[i]; }\n Graph dag(const Graph &g)\
    \ const {\n  Graph ret(size());\n  for (auto [s, d]: g)\n   if (int u= (*this)(s),\
    \ v= (*this)(d); u != v) ret.add_edge(u, v);\n  return sort(ret.begin(), ret.end()),\
    \ ret.erase(unique(ret.begin(), ret.end()), ret.end()), ret;\n }\n};\n#line 5\
    \ \"test/yosupo/scc.test.cpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n int N, M;\n cin >> N >> M;\n Graph g(N, M);\n for\
    \ (int i= 0; i < M; ++i) cin >> g[i];\n StronglyConnectedComponents scc(g);\n\
    \ int C= scc.size();\n cout << C << '\\n';\n for (int i= 0; i < C; ++i) {\n  auto\
    \ blk= scc.block(i);\n  cout << blk.size();\n  for (int v: blk) cout << \" \"\
    \ << v;\n  cout << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <iostream>\n\
    #include \"src/Graph/Graph.hpp\"\n#include \"src/Graph/StronglyConnectedComponents.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n Graph g(N, M);\n for (int i= 0; i < M; ++i) cin\
    \ >> g[i];\n StronglyConnectedComponents scc(g);\n int C= scc.size();\n cout <<\
    \ C << '\\n';\n for (int i= 0; i < C; ++i) {\n  auto blk= scc.block(i);\n  cout\
    \ << blk.size();\n  for (int v: blk) cout << \" \" << v;\n  cout << '\\n';\n }\n\
    \ return 0;\n}"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 22:00:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
