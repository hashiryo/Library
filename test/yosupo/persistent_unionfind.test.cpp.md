---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/PersistentArray.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind_Persistent.hpp
    title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#include <iostream>\n\
    #include <vector>\n#line 3 \"src/DataStructure/PersistentArray.hpp\"\ntemplate\
    \ <class T, std::size_t M= 8> class PersistentArray {\n struct Node {\n  T val;\n\
    \  Node *ch[M];\n } * root;\n T get(Node *&t, std::size_t k) { return t ? (k ?\
    \ get(t->ch[(k - 1) % M], (k - 1) / M) : t->val) : T(); }\n bool is_null(Node\
    \ *&t, std::size_t k) { return t ? (k ? is_null(t->ch[(k - 1) % M], (k - 1) /\
    \ M) : false) : true; }\n template <bool persistent= true> T &at(Node *&t, std::size_t\
    \ k) {\n  if (!t) t= new Node();\n  else if constexpr (persistent) t= new Node(*t);\n\
    \  return k ? at<persistent>(t->ch[(k - 1) % M], (k - 1) / M) : t->val;\n }\n\
    public:\n PersistentArray(): root(nullptr) {}\n PersistentArray(std::size_t n,\
    \ T v): root(nullptr) {\n  for (std::size_t i= n; i--;) at<false>(root, i)= v;\n\
    \ }\n PersistentArray(T *bg, T *ed): root(nullptr) {\n  for (std::size_t i= ed\
    \ - bg; i--;) at<false>(root, i)= *(bg + i);\n }\n PersistentArray(const std::vector<T>\
    \ &ar): PersistentArray(ar.data(), ar.data() + ar.size()) {}\n bool is_null(std::size_t\
    \ k) { return is_null(root, k); }\n T get(std::size_t k) { return get(root, k);\
    \ }\n T &at(std::size_t k) { return at<true>(root, k); }\n T &operator[](std::size_t\
    \ k) { return at(k); }\n};\n#line 3 \"src/DataStructure/UnionFind_Persistent.hpp\"\
    \nstruct UnionFind_Persistent {\n PersistentArray<int, 64> par;\n UnionFind_Persistent()\
    \ {}\n UnionFind_Persistent(int n): par(n, -1) {}\n bool unite(int u, int v) {\n\
    \  if ((u= root(u)) == (v= root(v))) return false;\n  if (par.get(u) > par.get(v))\
    \ std::swap(u, v);\n  par[u]+= par.get(v), par[v]= u;\n  return true;\n }\n bool\
    \ same(int u, int v) { return root(u) == root(v); }\n int root(int u) { return\
    \ par.get(u) < 0 ? u : root(par.get(u)); }\n int size(int u) { return -par.get(root(u));\
    \ }\n};\n#line 6 \"test/yosupo/persistent_unionfind.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n\
    \ cin >> N >> Q;\n vector<UnionFind_Persistent> uf(Q + 1);\n uf[0]= UnionFind_Persistent(N);\n\
    \ for (int i= 1; i <= Q; i++) {\n  int t, k, u, v;\n  cin >> t >> k >> u >> v;\n\
    \  k++;\n  if (t) {\n   cout << uf[k].same(u, v) << endl;\n  } else {\n   uf[i]=\
    \ uf[k];\n   uf[i].unite(u, v);\n  }\n }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include <iostream>\n#include <vector>\n#include \"src/DataStructure/PersistentArray.hpp\"\
    \n#include \"src/DataStructure/UnionFind_Persistent.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >>\
    \ N >> Q;\n vector<UnionFind_Persistent> uf(Q + 1);\n uf[0]= UnionFind_Persistent(N);\n\
    \ for (int i= 1; i <= Q; i++) {\n  int t, k, u, v;\n  cin >> t >> k >> u >> v;\n\
    \  k++;\n  if (t) {\n   cout << uf[k].same(u, v) << endl;\n  } else {\n   uf[i]=\
    \ uf[k];\n   uf[i].unite(u, v);\n  }\n }\n}\n"
  dependsOn:
  - src/DataStructure/PersistentArray.hpp
  - src/DataStructure/UnionFind_Persistent.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 21:27:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.test.cpp
- /verify/test/yosupo/persistent_unionfind.test.cpp.html
title: test/yosupo/persistent_unionfind.test.cpp
---
