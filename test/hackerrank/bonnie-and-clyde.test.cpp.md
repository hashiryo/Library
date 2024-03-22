---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  - icon: ':question:'
    path: src/Graph/block_cut_tree.hpp
    title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (block-cut-tree (\u62E1\
      \u5F35))"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/contests/w33/challenges/bonnie-and-clyde
    links:
    - https://www.hackerrank.com/contests/w33/challenges/bonnie-and-clyde
  bundledCode: "#line 1 \"test/hackerrank/bonnie-and-clyde.test.cpp\"\n#define PROBLEM\
    \ \"https://www.hackerrank.com/contests/w33/challenges/bonnie-and-clyde\"\n#include\
    \ <iostream>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#line\
    \ 4 \"src/Internal/ListRange.hpp\"\n#include <iterator>\n#include <type_traits>\n\
    #define _LR(name, IT, CT) \\\n template <class T> struct name { \\\n  using Iterator=\
    \ typename std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const\
    \ { return bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size()\
    \ const { return std::distance(bg, ed); } \\\n  CT &operator[](int i) const {\
    \ return bg[i]; } \\\n }\n_LR(ListRange, iterator, T);\n_LR(ConstListRange, const_iterator,\
    \ const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n std::vector<T>\
    \ dat;\n std::vector<int> p;\n size_t size() const { return p.size() - 1; }\n\
    \ ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin() + p[i\
    \ + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
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
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (size_t i= 0; i < n;\
    \ ++i) p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) { \\\n  auto [u, v]= (*this)[i];\
    \ \\\n  b; \\\n }\n#define _ADJ(a, b) \\\n vector<int> p(n + 1), c(size() << !dir);\
    \ \\\n if (!dir) { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[u]]= a, c[--p[v]]=\
    \ b)) \\\n } else if (dir > 0) { \\\n  _ADJ_FOR(++p[u], c[--p[u]]= a) \\\n } else\
    \ { \\\n  _ADJ_FOR(++p[v], c[--p[v]]= b) \\\n } \\\n return {c, p}\n CSRArray<int>\
    \ adjacency_vertex(int dir) const { _ADJ(v, u); }\n CSRArray<int> adjacency_edge(int\
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"src/Graph/block_cut_tree.hpp\"\
    \n// [0,n) : vertex\n// [n,n+b) : block\n// deg(v) > 1 -> articulation point\n\
    Graph block_cut_tree(const CSRArray<int> &adj) {\n const int n= adj.size();\n\
    \ std::vector<int> ord(n), par(n, -2), dat(adj.p.begin(), adj.p.begin() + n);\n\
    \ int k= 0;\n for (int s= n, p; s--;)\n  if (par[s] == -2)\n   for (par[p= s]=\
    \ -1; p >= 0;) {\n    if (dat[p] == adj.p[p]) ord[k++]= p;\n    if (dat[p] ==\
    \ adj.p[p + 1]) p= par[p];\n    else if (int q= adj.dat[dat[p]++]; par[q] == -2)\
    \ par[q]= p, p= q;\n   }\n for (int i= n; i--;) dat[ord[i]]= i;\n auto low= dat;\n\
    \ for (int v= n; v--;)\n  for (int u: adj[v]) low[v]= std::min(low[v], dat[u]);\n\
    \ for (int i= n; i--;)\n  if (int p= ord[i], pp= par[p]; pp >= 0) low[pp]= std::min(low[pp],\
    \ low[p]);\n Graph ret(k);\n for (int p: ord)\n  if (par[p] >= 0) {\n   if (int\
    \ pp= par[p]; low[p] < dat[pp]) ret.add_edge(low[p]= low[pp], p);\n   else ret.add_vertex(),\
    \ ret.add_edge(k, pp), ret.add_edge(k, p), low[p]= k++;\n  }\n for (int s= 0;\
    \ s < n; ++s)\n  if (!adj[s].size()) ret.add_edge(ret.add_vertex(), s);\n return\
    \ ret;\n}\nGraph block_cut_tree(const Graph &g) { return block_cut_tree(g.adjacency_vertex(0));\
    \ }\n#line 2 \"src/Graph/HeavyLightDecomposition.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#line 5 \"src/Graph/HeavyLightDecomposition.hpp\"\nclass HeavyLightDecomposition\
    \ {\n std::vector<int> P, PP, D, I, L, R;\npublic:\n HeavyLightDecomposition()=\
    \ default;\n HeavyLightDecomposition(const Graph &g, int root= 0): HeavyLightDecomposition(g.adjacency_vertex(0),\
    \ root) {}\n HeavyLightDecomposition(const CSRArray<int> &adj, int root= 0) {\n\
    \  const int n= adj.size();\n  P.assign(n, -2), PP.resize(n), D.resize(n), I.resize(n),\
    \ L.resize(n), R.resize(n);\n  auto f= [&, i= 0, v= 0, t= 0](int r) mutable {\n\
    \   for (P[r]= -1, I[t++]= r; i < t; ++i)\n    for (int u: adj[v= I[i]])\n   \
    \  if (P[v] != u) P[I[t++]= u]= v;\n  };\n  f(root);\n  for (int r= 0; r < n;\
    \ ++r)\n   if (P[r] == -2) f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for\
    \ (int i= n, v; i--;) {\n   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+=\
    \ Z[v]; nx[P[v]] == -1) nx[P[v]]= v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n\
    \  }\n  for (int v= n; v--;) PP[v]= v;\n  for (int v: I)\n   if (nx[v] != -1)\
    \ PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]], D[v]=\
    \ D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n   int\
    \ ir= R[v]= L[v] + Z[v];\n   for (int u: adj[v])\n    if (u != P[v] && u != nx[v])\
    \ L[u]= (ir-= Z[u]);\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n  }\n  for (int\
    \ i= n; i--;) I[L[i]]= i;\n }\n int to_seq(int v) const { return L[v]; }\n int\
    \ to_vertex(int i) const { return I[i]; }\n size_t size() const { return P.size();\
    \ }\n int parent(int v) const { return P[v]; }\n int head(int v) const { return\
    \ PP[v]; }\n int root(int v) const {\n  for (v= PP[v];; v= PP[P[v]])\n   if (P[v]\
    \ == -1) return v;\n }\n bool connected(int u, int v) const { return root(u) ==\
    \ root(v); }\n // u is in v\n bool in_subtree(int u, int v) const { return L[v]\
    \ <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return R[v] - L[v];\
    \ }\n int lca(int u, int v) const {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v])\
    \ std::swap(u, v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v,\
    \ int k) const {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] + 1, v=\
    \ P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int jump(int\
    \ u, int v, int k) const {\n  if (!k) return u;\n  if (u == v) return -1;\n  if\
    \ (k == 1) return in_subtree(v, u) ? la(v, D[v] - D[u] - 1) : P[u];\n  int w=\
    \ lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n  return k > d_uw + d_vw ?\
    \ -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n }\n int depth(int v) const\
    \ { return D[v]; }\n int dist(int u, int v) const { return D[u] + D[v] - D[lca(u,\
    \ v)] * 2; }\n // half-open interval [l,r)\n std::pair<int, int> subtree(int v)\
    \ const { return {L[v], R[v]}; }\n // sequence of closed intervals [l,r]\n std::vector<std::pair<int,\
    \ int>> path(int u, int v, bool edge= 0) const {\n  std::vector<std::pair<int,\
    \ int>> up, down;\n  while (PP[u] != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(L[PP[v]],\
    \ L[v]), v= P[PP[v]];\n   else up.emplace_back(L[u], L[PP[u]]), u= P[PP[u]];\n\
    \  }\n  if (L[u] < L[v]) down.emplace_back(L[u] + edge, L[v]);\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(L[u], L[v] + edge);\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};\n#line 6 \"test/hackerrank/bonnie-and-clyde.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int n, m, q;\n cin >> n >> m >> q;\n Graph g(n, m);\n for (int i= 0; i < m;\
    \ ++i) cin >> g[i], --g[i];\n HeavyLightDecomposition bct(block_cut_tree(g));\n\
    \ while (q--) {\n  int u, v, w;\n  cin >> u >> v >> w;\n  --u, --v, --w;\n  if\
    \ (!bct.connected(u, w) || !bct.connected(w, v)) cout << \"NO\";\n  else {\n \
    \  int tmp= bct.dist(u, w) + bct.dist(w, v) - bct.dist(u, v);\n   cout << (tmp\
    \ == 0 || tmp == 2 ? \"YES\" : \"NO\");\n  }\n  if (q) cout << '\\n';\n }\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/contests/w33/challenges/bonnie-and-clyde\"\
    \n#include <iostream>\n#include \"src/Graph/Graph.hpp\"\n#include \"src/Graph/block_cut_tree.hpp\"\
    \n#include \"src/Graph/HeavyLightDecomposition.hpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, m, q;\n cin >> n\
    \ >> m >> q;\n Graph g(n, m);\n for (int i= 0; i < m; ++i) cin >> g[i], --g[i];\n\
    \ HeavyLightDecomposition bct(block_cut_tree(g));\n while (q--) {\n  int u, v,\
    \ w;\n  cin >> u >> v >> w;\n  --u, --v, --w;\n  if (!bct.connected(u, w) || !bct.connected(w,\
    \ v)) cout << \"NO\";\n  else {\n   int tmp= bct.dist(u, w) + bct.dist(w, v) -\
    \ bct.dist(u, v);\n   cout << (tmp == 0 || tmp == 2 ? \"YES\" : \"NO\");\n  }\n\
    \  if (q) cout << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/Graph/block_cut_tree.hpp
  - src/Graph/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/hackerrank/bonnie-and-clyde.test.cpp
  requiredBy: []
  timestamp: '2024-02-22 11:37:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/hackerrank/bonnie-and-clyde.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/bonnie-and-clyde.test.cpp
- /verify/test/hackerrank/bonnie-and-clyde.test.cpp.html
title: test/hackerrank/bonnie-and-clyde.test.cpp
---
