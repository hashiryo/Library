---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':x:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
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
    \n#include <algorithm>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n\
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
    \ << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge {\n int s, d;\n Edge(int\
    \ s= 0, int d= 0): s(s), d(d) {}\n Edge &operator--() { return --s, --d, *this;\
    \ }\n int to(int u) const { return u ^ s ^ d; }\n bool operator<(const Edge &e)\
    \ const { return s != e.s ? s < e.s : d < e.d; }\n friend std::istream &operator>>(std::istream\
    \ &is, Edge &e) { return is >> e.s >> e.d, is; }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const Edge &e) { return os << '(' << e.s << \", \" << e.d << ')'; }\n};\n\
    struct Graph: public std::vector<Edge> {\n size_t n;\n Graph(size_t n= 0, size_t\
    \ m= 0): vector(m), n(n) {}\n size_t vertex_size() const { return n; }\n size_t\
    \ edge_size() const { return size(); }\n int add_vertex() { return n++; }\n int\
    \ add_edge(int s, int d) { return emplace_back(s, d), size() - 1; }\n int add_edge(Edge\
    \ e) { return add_edge(e.s, e.d); }\n#define _ADJ_FOR(a, b) \\\n for (auto [u,\
    \ v]: *this) a; \\\n for (size_t i= 0; i < n; ++i) p[i + 1]+= p[i]; \\\n for (int\
    \ i= size(); i--;) b;\n#define _ADJ(a, b) \\\n vector<int> p(n + 1), c(size()\
    \ << !direct); \\\n if (direct) { \\\n  _ADJ_FOR(++p[u], c[--p[(*this)[i].s]]=\
    \ a) \\\n } else { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[(*this)[i].s]]= a,\
    \ c[--p[(*this)[i].d]]= b)) \\\n } \\\n return {std::move(c), std::move(p)}\n\
    \ CSRArray<int> adjacency_vertex(bool direct) const { _ADJ((*this)[i].d, (*this)[i].s);\
    \ }\n CSRArray<int> adjacency_edge(bool direct) const { _ADJ(i, i); }\n#undef\
    \ _ADJ\n#undef _ADJ_FOR\n};\n#line 4 \"src/Graph/StronglyConnectedComponents.hpp\"\
    \nclass StronglyConnectedComponents {\n Graph _g;\n std::vector<int> csr, pos,\
    \ ord;\npublic:\n StronglyConnectedComponents(const Graph &g): _g(g) {\n  const\
    \ int n= g.vertex_size();\n  csr.assign(n, -2), ord.resize(n), pos= {0};\n  {\n\
    \   auto adj= g.adjacency_vertex(1);\n   std::vector<int> ei(adj.p.begin(), adj.p.begin()\
    \ + n);\n   for (int s= 0, k= n, p; s < n; ++s)\n    if (csr[s] == -2)\n     for\
    \ (csr[p= s]= -1; p >= 0;)\n      if (ei[p] == adj.p[p + 1]) ord[--k]= p, p= csr[p];\n\
    \      else if (int q= adj.dat[ei[p]++]; csr[q] == -2) csr[q]= p, p= q;\n  }\n\
    \  for (auto &[s, d]: _g) std::swap(s, d);\n  auto adj= _g.adjacency_vertex(1);\n\
    \  std::vector<char> vis(n);\n  int k= 0, p= 0;\n  for (int s: ord)\n   if (!vis[s])\
    \ {\n    for (vis[csr[k++]= s]= 1; p < k; ++p)\n     for (int u: adj[csr[p]])\n\
    \      if (!vis[u]) vis[csr[k++]= u]= 1;\n    pos.push_back(k);\n   }\n  for (int\
    \ i= pos.size() - 1; i--;)\n   while (k > pos[i]) ord[csr[--k]]= i;\n }\n size_t\
    \ size() const { return pos.size() - 1; }\n ConstListRange<int> block(int k) const\
    \ { return {csr.cbegin() + pos[k], csr.cbegin() + pos[k + 1]}; }\n int operator()(int\
    \ i) const { return ord[i]; }\n Graph dag() const {\n  Graph ret(size());\n  for\
    \ (auto [d, s]: _g)\n   if (int u= (*this)(s), v= (*this)(d); u != v) ret.add_edge(u,\
    \ v);\n  return sort(ret.begin(), ret.end()), ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end()), ret;\n }\n};\n#line 3 \"src/Math/TwoSatisfiability.hpp\"\nclass\
    \ TwoSatisfiability {\n int n;\n Graph g;\n inline int neg(int x) const { return\
    \ x >= n ? x - n : x + n; }\npublic:\n TwoSatisfiability(int n): n(n), g(n + n)\
    \ {}\n void add_if(int u, int v) { g.add_edge(u, v), g.add_edge(neg(v), neg(u));\
    \ }  // u -> v <=> !v -> !u\n void add_or(int u, int v) { add_if(neg(u), v); }\
    \                             // u or v <=> !u -> v\n void add_nand(int u, int\
    \ v) { add_if(u, neg(v)); }                           // u nand v <=> u -> !v\n\
    \ void set_true(int u) { g.add_edge(neg(u), u); }                            \
    \  // u <=> !u -> u\n void set_false(int u) { g.add_edge(u, neg(u)); }       \
    \                      // !u <=> u -> !u\n std::vector<bool> solve() {\n  StronglyConnectedComponents\
    \ scc(g);\n  std::vector<bool> ret(n);\n  for (int i= 0, l, r; i<n; ret[i++]=\
    \ l> r)\n   if (l= scc(i), r= scc(neg(i)); l == r) return {};  // no solution\n\
    \  return ret;\n }\n};\n#line 5 \"test/yosupo/two_sat.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n string s;\n\
    \ cin >> s >> s;\n int N, M;\n cin >> N >> M;\n TwoSatisfiability sat(N + 1);\n\
    \ for (int i= 0; i < M; i++) {\n  int a, b;\n  cin >> a >> b >> s;\n  if (a <\
    \ 0) a= sat.neg(-a);\n  if (b < 0) b= sat.neg(-b);\n  sat.add_or(a, b);\n }\n\
    \ auto ans= sat.solve();\n cout << \"s \";\n if (ans.size()) {\n  cout << \"SATISFIABLE\"\
    \ << '\\n';\n  cout << \"v \";\n  for (int i= 1; i <= N; i++) cout << (ans[i]\
    \ ? i : -i) << \" \";\n  cout << 0 << '\\n';\n } else cout << \"UNSATISFIABLE\"\
    \ << '\\n';\n\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <iostream>\n\
    #include <string>\n#include \"src/Math/TwoSatisfiability.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n string s;\n\
    \ cin >> s >> s;\n int N, M;\n cin >> N >> M;\n TwoSatisfiability sat(N + 1);\n\
    \ for (int i= 0; i < M; i++) {\n  int a, b;\n  cin >> a >> b >> s;\n  if (a <\
    \ 0) a= sat.neg(-a);\n  if (b < 0) b= sat.neg(-b);\n  sat.add_or(a, b);\n }\n\
    \ auto ans= sat.solve();\n cout << \"s \";\n if (ans.size()) {\n  cout << \"SATISFIABLE\"\
    \ << '\\n';\n  cout << \"v \";\n  for (int i= 1; i <= N; i++) cout << (ans[i]\
    \ ? i : -i) << \" \";\n  cout << 0 << '\\n';\n } else cout << \"UNSATISFIABLE\"\
    \ << '\\n';\n\n return 0;\n}"
  dependsOn:
  - src/Math/TwoSatisfiability.hpp
  - src/Graph/StronglyConnectedComponents.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2024-02-15 23:40:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
