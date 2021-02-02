---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT_Dual.test.cpp
    title: test/aoj/2559.LCT_Dual.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9\u53CC\u5BFE)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/LinkCutTree_MonoidDual.hpp\"\n#include\
    \ <bits/stdc++.h>\n/**\n * @title Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9\u53CC\
    \u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct LinkCutTree_MonoidDual {\n\
    \  using T = typename M::T;\n  using E = typename M::E;\n  struct Node {\n   \
    \ Node *ch[2], *par;\n    bool rev;\n    T val;\n    E laz;\n    Node(T init =\
    \ T()) : rev(false), val(init), laz(M::ei()) {\n      ch[0] = ch[1] = par = nullptr;\n\
    \    }\n  };\n\n private:\n  bool is_root(Node *x) {\n    return !x->par || (x->par->ch[0]\
    \ != x && x->par->ch[1] != x);\n  }\n  bool dir(Node *x) { return x->par && x->par->ch[1]\
    \ == x; }\n  void rot(Node *t) {\n    Node *p = t->par;\n    bool d = dir(t);\n\
    \    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par = p;\n    t->ch[!d] = p;\n    t->par\
    \ = p->par;\n    if (!is_root(p)) {\n      p->par->ch[dir(p)] = t;\n    }\n  \
    \  p->par = t;\n  }\n  void splay(Node *x) {\n    eval(x);\n    while (!is_root(x))\
    \ {\n      if (!is_root(x->par)) eval(x->par->par);\n      eval(x->par);\n   \
    \   eval(x);\n      if (!is_root(x->par)) {\n        if (dir(x) == dir(x->par))\n\
    \          rot(x->par);\n        else\n          rot(x);\n      }\n      rot(x);\n\
    \    }\n  }\n  Node *expose(Node *x) {\n    Node *r = nullptr;\n    for (Node\
    \ *p = x; p; p = p->par) {\n      splay(p);\n      p->ch[1] = r;\n      r = p;\n\
    \    }\n    splay(x);\n    return r;\n  }\n  void propagate(Node *t, E v) {\n\
    \    t->laz = M::h(t->laz, v);\n    t->val = M::g(t->val, v);\n  }\n  void toggle(Node\
    \ *t) {\n    std::swap(t->ch[0], t->ch[1]);\n    t->rev ^= 1;\n  }\n  Node *eval(Node\
    \ *t) {\n    if (t->laz != M::ei()) {\n      if (t->ch[0]) propagate(t->ch[0],\
    \ t->laz);\n      if (t->ch[1]) propagate(t->ch[1], t->laz);\n      t->laz = M::ei();\n\
    \    }\n    if (t->rev) {\n      if (t->ch[0]) toggle(t->ch[0]);\n      if (t->ch[1])\
    \ toggle(t->ch[1]);\n      t->rev = false;\n    }\n    return t;\n  }\n\n private:\n\
    \  std::vector<Node> ns;\n  size_t linkcnt;\n\n public:\n  LinkCutTree_MonoidDual(int\
    \ n, T init = T()) : ns(n, init), linkcnt(0) {}\n  // make k the root\n  void\
    \ evert(int k) {\n    expose(&ns[k]);\n    toggle(&ns[k]);\n    eval(&ns[k]);\n\
    \  }\n  // add link from c to p\n  void link(int c, int p) {\n    assert(linkcnt++\
    \ < ns.size() - 1);\n    evert(c);\n    expose(&ns[p]);\n    ns[p].ch[1] = &ns[c];\n\
    \    ns[c].par = &ns[p];\n  }\n  // cut link from c to p\n  void cut(int c, int\
    \ p) {\n    linkcnt--;\n    evert(p);\n    expose(&ns[c]);\n    Node *y = ns[c].ch[0];\n\
    \    ns[c].ch[0] = y->par = nullptr;\n  }\n  int lca(int x, int y) {\n    expose(&ns[x]);\n\
    \    Node *u = expose(&ns[y]);\n    return ns[x].par ? u - &ns[0] : -1;\n  }\n\
    \  T operator[](int k) {\n    expose(&ns[k]);\n    return ns[k].val;\n  }\n  void\
    \ update(int a, int b, E v) {\n    evert(a);\n    expose(&ns[b]);\n    propagate(&ns[b],\
    \ v);\n    eval(&ns[b]);\n  }\n  void set_val(int k, T v) {\n    expose(&ns[k]);\n\
    \    ns[k].val = v;\n    eval(&ns[k]);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Link-Cut-Tree(\u30E2\
    \u30CE\u30A4\u30C9\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n\
    \ * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct\
    \ LinkCutTree_MonoidDual {\n  using T = typename M::T;\n  using E = typename M::E;\n\
    \  struct Node {\n    Node *ch[2], *par;\n    bool rev;\n    T val;\n    E laz;\n\
    \    Node(T init = T()) : rev(false), val(init), laz(M::ei()) {\n      ch[0] =\
    \ ch[1] = par = nullptr;\n    }\n  };\n\n private:\n  bool is_root(Node *x) {\n\
    \    return !x->par || (x->par->ch[0] != x && x->par->ch[1] != x);\n  }\n  bool\
    \ dir(Node *x) { return x->par && x->par->ch[1] == x; }\n  void rot(Node *t) {\n\
    \    Node *p = t->par;\n    bool d = dir(t);\n    if ((p->ch[d] = t->ch[!d]))\
    \ p->ch[d]->par = p;\n    t->ch[!d] = p;\n    t->par = p->par;\n    if (!is_root(p))\
    \ {\n      p->par->ch[dir(p)] = t;\n    }\n    p->par = t;\n  }\n  void splay(Node\
    \ *x) {\n    eval(x);\n    while (!is_root(x)) {\n      if (!is_root(x->par))\
    \ eval(x->par->par);\n      eval(x->par);\n      eval(x);\n      if (!is_root(x->par))\
    \ {\n        if (dir(x) == dir(x->par))\n          rot(x->par);\n        else\n\
    \          rot(x);\n      }\n      rot(x);\n    }\n  }\n  Node *expose(Node *x)\
    \ {\n    Node *r = nullptr;\n    for (Node *p = x; p; p = p->par) {\n      splay(p);\n\
    \      p->ch[1] = r;\n      r = p;\n    }\n    splay(x);\n    return r;\n  }\n\
    \  void propagate(Node *t, E v) {\n    t->laz = M::h(t->laz, v);\n    t->val =\
    \ M::g(t->val, v);\n  }\n  void toggle(Node *t) {\n    std::swap(t->ch[0], t->ch[1]);\n\
    \    t->rev ^= 1;\n  }\n  Node *eval(Node *t) {\n    if (t->laz != M::ei()) {\n\
    \      if (t->ch[0]) propagate(t->ch[0], t->laz);\n      if (t->ch[1]) propagate(t->ch[1],\
    \ t->laz);\n      t->laz = M::ei();\n    }\n    if (t->rev) {\n      if (t->ch[0])\
    \ toggle(t->ch[0]);\n      if (t->ch[1]) toggle(t->ch[1]);\n      t->rev = false;\n\
    \    }\n    return t;\n  }\n\n private:\n  std::vector<Node> ns;\n  size_t linkcnt;\n\
    \n public:\n  LinkCutTree_MonoidDual(int n, T init = T()) : ns(n, init), linkcnt(0)\
    \ {}\n  // make k the root\n  void evert(int k) {\n    expose(&ns[k]);\n    toggle(&ns[k]);\n\
    \    eval(&ns[k]);\n  }\n  // add link from c to p\n  void link(int c, int p)\
    \ {\n    assert(linkcnt++ < ns.size() - 1);\n    evert(c);\n    expose(&ns[p]);\n\
    \    ns[p].ch[1] = &ns[c];\n    ns[c].par = &ns[p];\n  }\n  // cut link from c\
    \ to p\n  void cut(int c, int p) {\n    linkcnt--;\n    evert(p);\n    expose(&ns[c]);\n\
    \    Node *y = ns[c].ch[0];\n    ns[c].ch[0] = y->par = nullptr;\n  }\n  int lca(int\
    \ x, int y) {\n    expose(&ns[x]);\n    Node *u = expose(&ns[y]);\n    return\
    \ ns[x].par ? u - &ns[0] : -1;\n  }\n  T operator[](int k) {\n    expose(&ns[k]);\n\
    \    return ns[k].val;\n  }\n  void update(int a, int b, E v) {\n    evert(a);\n\
    \    expose(&ns[b]);\n    propagate(&ns[b], v);\n    eval(&ns[b]);\n  }\n  void\
    \ set_val(int k, T v) {\n    expose(&ns[k]);\n    ns[k].val = v;\n    eval(&ns[k]);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LinkCutTree_MonoidDual.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559.LCT_Dual.test.cpp
documentation_of: src/DataStructure/LinkCutTree_MonoidDual.hpp
layout: document
redirect_from:
- /library/src/DataStructure/LinkCutTree_MonoidDual.hpp
- /library/src/DataStructure/LinkCutTree_MonoidDual.hpp.html
title: "Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9\u53CC\u5BFE)"
---
