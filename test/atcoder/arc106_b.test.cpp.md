---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':x:'
    path: src/Graph/incidence_linear_system.hpp
    title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
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
    PROBLEM: https://atcoder.jp/contests/arc106/tasks/arc106_b
    links:
    - https://atcoder.jp/contests/arc106/tasks/arc106_b
  bundledCode: "#line 1 \"test/atcoder/arc106_b.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc106/tasks/arc106_b\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#line 4 \"src/Internal/ListRange.hpp\"\
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
    src/Graph/incidence_linear_system.hpp\"\ntemplate <class T> std::vector<T> incidence_linear_system(const\
    \ Graph &g, std::vector<T> b) {\n const int n= g.vertex_size();\n assert((int)b.size()\
    \ == n);\n std::vector<T> x(g.edge_size());\n auto adje= g.adjecency_edge(0);\n\
    \ std::vector<int> pre(n, -2), ei(adje.p.begin(), adje.p.begin() + n);\n for (int\
    \ s= 0, p, e; s < n; ++s)\n  if (pre[s] == -2)\n   for (pre[p= s]= -1;;) {\n \
    \   if (ei[p] == adje.p[p + 1]) {\n     if (e= pre[p]; e < 0) {\n      if (b[p]\
    \ != T()) return {};  // no solution\n      break;\n     }\n     T tmp= b[p];\n\
    \     p= g[e].to(p);\n     if constexpr (std::is_same_v<T, bool>) x[e]= tmp, b[p]=\
    \ tmp ^ b[p];\n     else x[e]= g[e].second == p ? -tmp : tmp, b[p]+= tmp;\n  \
    \  } else if (int q= g[e= adje.dat[ei[p]++]].to(p); pre[q] == -2) pre[p= q]= e;\n\
    \   }\n return x;\n}\n#line 6 \"test/atcoder/arc106_b.test.cpp\"\nusing namespace\
    \ std;\n// \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(false);\n int N, M;\n cin >> N >> M;\n vector<long\
    \ long> a(N);\n for (int i= 0; i < N; i++) cin >> a[i];\n for (int i= 0, b; i\
    \ < N; i++) cin >> b, a[i]-= b;\n Graph g(N, M);\n for (int i= 0; i < M; ++i)\
    \ cin >> g[i], --g[i];\n if (M) cout << (incidence_linear_system(g, a).empty()\
    \ ? \"No\" : \"Yes\") << '\\n';\n else cout << (all_of(begin(a), end(a), [](auto\
    \ t) { return !t; }) ? \"Yes\" : \"No\") << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc106/tasks/arc106_b\"\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\n#include \"src/Graph/incidence_linear_system.hpp\"\
    \nusing namespace std;\n// \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, M;\n cin\
    \ >> N >> M;\n vector<long long> a(N);\n for (int i= 0; i < N; i++) cin >> a[i];\n\
    \ for (int i= 0, b; i < N; i++) cin >> b, a[i]-= b;\n Graph g(N, M);\n for (int\
    \ i= 0; i < M; ++i) cin >> g[i], --g[i];\n if (M) cout << (incidence_linear_system(g,\
    \ a).empty() ? \"No\" : \"Yes\") << '\\n';\n else cout << (all_of(begin(a), end(a),\
    \ [](auto t) { return !t; }) ? \"Yes\" : \"No\") << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/incidence_linear_system.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: true
  path: test/atcoder/arc106_b.test.cpp
  requiredBy: []
  timestamp: '2024-02-16 12:23:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc106_b.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc106_b.test.cpp
- /verify/test/atcoder/arc106_b.test.cpp.html
title: test/atcoder/arc106_b.test.cpp
---
