---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':question:'
    path: src/Graph/BipartiteGraph.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
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
    PROBLEM: https://atcoder.jp/contests/abc282/tasks/abc282_d
    links:
    - https://atcoder.jp/contests/abc282/tasks/abc282_d
  bundledCode: "#line 1 \"test/atcoder/abc282_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc282/tasks/abc282_d\"\
    \n\n// 2\u8272\u5857\u308A\u5206\u3051\u306E verify\n\n#include <iostream>\n#include\
    \ <vector>\n#line 3 \"src/DataStructure/UnionFind.hpp\"\n#include <algorithm>\n\
    #include <cassert>\ntemplate <bool undoable= false> class UnionFind {\n std::vector<int>\
    \ par;\n std::vector<std::pair<int, int>> his;\npublic:\n UnionFind(int n): par(n,\
    \ -1) {}\n bool unite(int u, int v) {\n  if ((u= root(u)) == (v= root(v))) return\
    \ false;\n  if (par[u] > par[v]) std::swap(u, v);\n  if constexpr (undoable) his.emplace_back(v,\
    \ par[v]);\n  return par[u]+= par[v], par[v]= u, true;\n }\n bool same(int u,\
    \ int v) { return root(u) == root(v); }\n int root(int u) {\n  if constexpr (undoable)\
    \ return par[u] < 0 ? u : root(par[u]);\n  else return par[u] < 0 ? u : par[u]=\
    \ root(par[u]);\n }\n int size(int u) { return -par[root(u)]; }\n int time() const\
    \ {\n  static_assert(undoable, \"\\'time\\' is not enabled\");\n  return his.size();\n\
    \ }\n void undo() {\n  static_assert(undoable, \"\\'undo\\' is not enabled\");\n\
    \  auto [u, s]= his.back();\n  his.pop_back(), par[par[u]]-= s, par[u]= s;\n }\n\
    \ void rollback(size_t t) {\n  static_assert(undoable, \"\\'rollback\\' is not\
    \ enabled\");\n  assert(t <= his.size());\n  while (his.size() > t) undo();\n\
    \ }\n};\n#line 4 \"src/Internal/ListRange.hpp\"\n#include <iterator>\n#include\
    \ <type_traits>\n#define _LR(name, IT, CT) \\\n template <class T> struct name\
    \ { \\\n  using Iterator= typename std::vector<T>::IT; \\\n  Iterator bg, ed;\
    \ \\\n  Iterator begin() const { return bg; } \\\n  Iterator end() const { return\
    \ ed; } \\\n  size_t size() const { return std::distance(bg, ed); } \\\n  CT &operator[](int\
    \ i) const { return bg[i]; } \\\n }\n_LR(ListRange, iterator, T);\n_LR(ConstListRange,\
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
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (size_t i= 0; i < n;\
    \ ++i) p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) { \\\n  auto [u, v]= (*this)[i];\
    \ \\\n  b; \\\n }\n#define _ADJ(a, b) \\\n vector<int> p(n + 1), c(size() << !dir);\
    \ \\\n if (!dir) { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[u]]= a, c[--p[v]]=\
    \ b)) \\\n } else if (dir > 0) { \\\n  _ADJ_FOR(++p[u], c[--p[u]]= a) \\\n } else\
    \ { \\\n  _ADJ_FOR(++p[v], c[--p[v]]= b) \\\n } \\\n return {c, p}\n CSRArray<int>\
    \ adjacency_vertex(int dir) const { _ADJ(v, u); }\n CSRArray<int> adjacency_edge(int\
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"src/Graph/BipartiteGraph.hpp\"\
    \n#include <tuple>\n#line 6 \"src/Graph/BipartiteGraph.hpp\"\n// [0, L) is left,\
    \ [L, n) is right\nstruct BipartiteGraph: Graph {\n size_t L;\n BipartiteGraph()\
    \ {}\n BipartiteGraph(size_t L, size_t R, size_t m= 0): Graph(L + R, m), L(L)\
    \ {}\n size_t left_size() const { return L; }\n size_t right_size() const { return\
    \ this->n - L; }\n};\nstd::vector<int> paint_two_colors(const CSRArray<int> &adj)\
    \ {\n const int n= adj.size();\n std::vector<int> col(n, -1);\n for (int s= n;\
    \ s--;)\n  if (col[s] == -1) {\n   std::vector<int> q= {s};\n   for (int i= col[s]=\
    \ 0, v; i < (int)q.size(); ++i)\n    for (int u: adj[v= q[i]])\n     if (int c=\
    \ col[v]; col[u] == c) return {};\n     else if (col[u] == -1) col[u]= c ^ 1,\
    \ q.push_back(u);\n  }\n return col;\n}\nstd::vector<int> paint_two_colors(const\
    \ Graph &g) { return paint_two_colors(g.adjacency_vertex(0)); }\n// { BipartiteGraph\
    \ , original to new, new to original }\n// {{},{},{}} if not bipartite\nstd::tuple<BipartiteGraph,\
    \ std::vector<int>, std::vector<int>> graph_to_bipartite(const Graph &g, std::vector<int>\
    \ color= {}) {\n if (color.empty()) color= paint_two_colors(g);\n if (color.empty())\
    \ return {};\n const int n= g.vertex_size(), m= g.edge_size();\n std::vector<int>\
    \ a(n), b(n);\n int l= 0, r= n;\n for (int i= n; i--;) b[a[i]= color[i] ? --r\
    \ : l++]= i;\n BipartiteGraph bg(l, n - l, m);\n for (int i= m; i--;) {\n  auto\
    \ [u, v]= g[i];\n  bg[i]= std::minmax(a[u], a[v]);\n }\n return {bg, a, b};\n\
    }\nnamespace _bg_internal {\nstd::vector<int> _bm(int L, const CSRArray<int> &adj,\
    \ std::vector<int> &m) {\n std::vector<int> a, p, q(L);\n for (bool u= true; u;)\
    \ {\n  u= false, a.assign(L, -1), p.assign(L, -1);\n  int t= 0;\n  for (int l=\
    \ L; l--;)\n   if (m[l] == -1) q[t++]= a[l]= p[l]= l;\n  for (int i= 0; i < t;\
    \ ++i)\n   if (int l= q[i], x; m[a[l]] == -1)\n    for (int r: adj[l]) {\n   \
    \  if (x= m[r]; x == -1) {\n      for (u= true; r != -1; l= p[l]) m[r]= l, std::swap(m[l],\
    \ r);\n      break;\n     }\n     if (p[x] == -1) a[q[t++]= x]= a[p[x]= l];\n\
    \    }\n }\n return a;\n}\n}\ntemplate <bool lexical= false> std::pair<std::vector<int>,\
    \ std::vector<int>> bipartite_matching(const BipartiteGraph &bg, std::vector<int>\
    \ partner= {}) {\n const int L= bg.left_size(), M= bg.edge_size();\n if (partner.empty())\
    \ partner.assign(bg.vertex_size(), -1);\n assert(partner.size() == bg.vertex_size());\n\
    \ {\n  CSRArray<int> adj{std::vector<int>(M), std::vector<int>(L + 1)};\n  for\
    \ (auto [l, r]: bg) ++adj.p[l];\n  for (int i= 0; i < L; ++i) adj.p[i + 1]+= adj.p[i];\n\
    \  for (auto [l, r]: bg) adj.dat[--adj.p[l]]= r;\n  if constexpr (lexical) {\n\
    \   for (int l= L; l--;) std::sort(adj[l].begin(), adj[l].end());\n   _bg_internal::_bm(L,\
    \ adj, partner);\n   std::vector<char> a(L, 1);\n   for (int l= 0; l < L; ++l)\n\
    \    if (int r= partner[l], v= l; r != -1) {\n     std::vector<int> p(L, partner[v]=\
    \ partner[r]= -1), c(adj.p.begin(), adj.p.begin() + L);\n     for (p[v]= -2;;)\
    \ {\n      if (c[v] == adj.p[v + 1]) v= p[v];\n      else if (int u= partner[r=\
    \ adj.dat[c[v]++]]; u == -1) {\n       for (; r != -1; v= p[v]) partner[r]= v,\
    \ std::swap(partner[v], r);\n       break;\n      } else if (a[u] && p[u] == -1)\
    \ p[u]= v, v= u;\n     }\n     a[l]= 0;\n    }\n  } else _bg_internal::_bm(L,\
    \ adj, partner);\n }\n std::vector<int> c;\n std::vector<char> p(L);\n for (int\
    \ i= 0; i < M; ++i)\n  if (auto [l, r]= bg[i]; partner[l] == r && !p[l]) c.push_back(i),\
    \ p[l]= 1;\n return {c, partner};\n}\n#line 10 \"test/atcoder/abc282_d.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n Graph g(N, M);\n for (int i= 0; i < M; ++i) cin\
    \ >> g[i], --g[i];\n UnionFind uf(N);\n for (auto [u, v]: g) uf.unite(u, v);\n\
    \ auto col= paint_two_colors(g);\n if (col.empty()) return cout << 0 << '\\n',\
    \ 0;\n vector cnt(2, vector(N, 0));\n for (int v= N; v--;) ++cnt[col[v]][uf.root(v)];\n\
    \ long long ans= 0;\n for (int s= 2; s--;)\n  for (int v= N; v--;) ans+= (long\
    \ long)cnt[s][v] * (N - cnt[s][v]);\n ans/= 2, ans-= M;\n cout << ans << '\\n';\n\
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc282/tasks/abc282_d\"\n\n\
    // 2\u8272\u5857\u308A\u5206\u3051\u306E verify\n\n#include <iostream>\n#include\
    \ <vector>\n#include \"src/DataStructure/UnionFind.hpp\"\n#include \"src/Graph/Graph.hpp\"\
    \n#include \"src/Graph/BipartiteGraph.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n cin >> N >> M;\n Graph\
    \ g(N, M);\n for (int i= 0; i < M; ++i) cin >> g[i], --g[i];\n UnionFind uf(N);\n\
    \ for (auto [u, v]: g) uf.unite(u, v);\n auto col= paint_two_colors(g);\n if (col.empty())\
    \ return cout << 0 << '\\n', 0;\n vector cnt(2, vector(N, 0));\n for (int v= N;\
    \ v--;) ++cnt[col[v]][uf.root(v)];\n long long ans= 0;\n for (int s= 2; s--;)\n\
    \  for (int v= N; v--;) ans+= (long long)cnt[s][v] * (N - cnt[s][v]);\n ans/=\
    \ 2, ans-= M;\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/Graph/BipartiteGraph.hpp
  isVerificationFile: true
  path: test/atcoder/abc282_d.test.cpp
  requiredBy: []
  timestamp: '2024-02-20 18:08:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc282_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc282_d.test.cpp
- /verify/test/atcoder/abc282_d.test.cpp.html
title: test/atcoder/abc282_d.test.cpp
---
