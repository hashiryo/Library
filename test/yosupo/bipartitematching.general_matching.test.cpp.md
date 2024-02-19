---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/general_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.general_matching.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 2 \"src/Graph/general_matching.hpp\"\
    \n#include <cassert>\n#line 4 \"src/Graph/general_matching.hpp\"\n// {matching\
    \ edge ids, partner(-1 if unmatched)}\nstd::pair<std::vector<int>, std::vector<int>>\
    \ general_matching(const Graph &g, const std::vector<int> &partner= {}) {\n auto\
    \ adj= g.adjacency_vertex(0);\n const int n= adj.size();\n std::vector<int> q,\
    \ z(n), p(n), m(partner);\n if (m.empty()) m.assign(n, -1);\n assert((int)m.size()\
    \ == n);\n std::vector<Edge> fs(n);\n auto rematch= [&](auto &&rc, int u, int\
    \ v) -> void {\n  int w= m[u];\n  if (m[u]= v; w == -1 || m[w] != u) return;\n\
    \  if (auto [x, y]= fs[u]; y == -1) rc(rc, m[w]= x, w);\n  else rc(rc, x, y),\
    \ rc(rc, y, x);\n };\n int t= 1;\n auto f= [&](auto &&rc, int x) -> int { return\
    \ z[x] != t || p[x] == -1 ? x : (p[x]= rc(rc, p[x])); };\n auto check= [&](int\
    \ r) {\n  q.clear(), q.push_back(r), fs[r]= {-1, -1}, z[r]= t, p[r]= -1;\n  for\
    \ (int i= 0; i < (int)q.size(); ++i) {\n   int x= q[i];\n   for (int y: adj[x])\
    \ {\n    if (y == r) continue;\n    if (m[y] == -1) return rematch(rematch, m[y]=\
    \ x, y), true;\n    if (z[y] == t) {\n     int u= f(f, x), v= f(f, y), w= r;\n\
    \     if (u == v) continue;\n     for (; u != r || v != r; fs[u]= {x, y}, u= f(f,\
    \ fs[m[u]].first)) {\n      if (v != r) std::swap(u, v);\n      if (fs[u].first\
    \ == x && fs[u].second == y) {\n       w= u;\n       break;\n      }\n     }\n\
    \     for (int a: {f(f, x), f(f, y)})\n      for (; a != w; a= f(f, fs[m[a]].first))\
    \ z[a]= t, p[a]= w, q.push_back(a);\n    } else if (z[m[y]] != t) fs[y]= {-1,\
    \ -1}, fs[m[y]]= {x, -1}, z[m[y]]= t, p[m[y]]= y, q.push_back(m[y]);\n   }\n \
    \ }\n  return false;\n };\n for (int r= n; r--;)\n  if (m[r] == -1) t+= check(r);\n\
    \ q.clear();\n for (int i= 0, e= g.edge_size(); i < e; ++i)\n  if (auto [u, v]=\
    \ g[i]; m[u] == v && z[u] >= 0) q.push_back(i), z[u]= z[v]= -1;\n return {q, m};\n\
    }\n#line 5 \"test/yosupo/bipartitematching.general_matching.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ L, R, M;\n cin >> L >> R >> M;\n Graph g(L + R, M);\n for (int i= 0; i < M;\
    \ ++i) cin >> g[i], g[i].second+= L;\n auto [ans, _]= general_matching(g);\n cout\
    \ << ans.size() << '\\n';\n for (int i: ans) {\n  auto [l, r]= g[i];\n  cout <<\
    \ l << \" \" << r - L << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <iostream>\n#include \"src/Graph/Graph.hpp\"\n#include \"src/Graph/general_matching.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int L, R, M;\n cin >> L >> R >> M;\n Graph g(L + R, M);\n for (int i= 0; i <\
    \ M; ++i) cin >> g[i], g[i].second+= L;\n auto [ans, _]= general_matching(g);\n\
    \ cout << ans.size() << '\\n';\n for (int i: ans) {\n  auto [l, r]= g[i];\n  cout\
    \ << l << \" \" << r - L << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/Graph/general_matching.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.general_matching.test.cpp
  requiredBy: []
  timestamp: '2024-02-19 15:51:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.general_matching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.general_matching.test.cpp
- /verify/test/yosupo/bipartitematching.general_matching.test.cpp.html
title: test/yosupo/bipartitematching.general_matching.test.cpp
---
