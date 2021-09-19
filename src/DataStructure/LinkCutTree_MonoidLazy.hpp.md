---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2450.LCT.test.cpp
    title: test/aoj/2450.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/235.LCT.test.cpp
    title: test/yukicoder/235.LCT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9\u9045\u5EF6\u4F1D\u642C\
      )"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/LinkCutTree_MonoidLazy.hpp\"\n#include\
    \ <bits/stdc++.h>\n/**\n * @title Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9\u9045\
    \u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct LinkCutTree_MonoidLazy\
    \ {\n  using T = typename M::T;\n  using E = typename M::E;\n  struct Node {\n\
    \    Node *ch[2], *par;\n    bool rev;\n    T val, dat, rdat;\n    E laz;\n  \
    \  Node(T init = M::ti())\n        : rev(false), val(init), dat(init), rdat(init),\
    \ laz(M::ei()) {\n      ch[0] = ch[1] = par = nullptr;\n    }\n  };\n\n private:\n\
    \  bool is_root(Node *x) {\n    return !x->par || (x->par->ch[0] != x && x->par->ch[1]\
    \ != x);\n  }\n  bool dir(Node *x) { return x->par && x->par->ch[1] == x; }\n\
    \  void rot(Node *t) {\n    Node *p = t->par;\n    bool d = dir(t);\n    if ((p->ch[d]\
    \ = t->ch[!d])) p->ch[d]->par = p;\n    t->ch[!d] = p;\n    pushup(p);\n    pushup(t);\n\
    \    t->par = p->par;\n    if (!is_root(p)) {\n      p->par->ch[dir(p)] = t;\n\
    \      pushup(t->par);\n    }\n    p->par = t;\n  }\n  void splay(Node *x) {\n\
    \    eval(x);\n    while (!is_root(x)) {\n      if (!is_root(x->par)) eval(x->par->par);\n\
    \      eval(x->par);\n      eval(x);\n      if (!is_root(x->par)) {\n        if\
    \ (dir(x) == dir(x->par))\n          rot(x->par);\n        else\n          rot(x);\n\
    \      }\n      rot(x);\n    }\n  }\n  void pushup(Node *t) {\n    t->rdat = t->dat\
    \ = t->val;\n    if (t->ch[0])\n      t->dat = M::op(t->ch[0]->dat, t->dat),\n\
    \      t->rdat = M::op(t->rdat, t->ch[0]->rdat);\n    if (t->ch[1])\n      t->dat\
    \ = M::op(t->dat, t->ch[1]->dat),\n      t->rdat = M::op(t->ch[1]->rdat, t->rdat);\n\
    \  }\n  Node *expose(Node *x) {\n    Node *r = nullptr;\n    for (Node *p = x;\
    \ p; p = p->par) {\n      splay(p);\n      p->ch[1] = r;\n      pushup(p);\n \
    \     r = p;\n    }\n    splay(x);\n    return r;\n  }\n  void propagate(Node\
    \ *t, E v) {\n    t->laz = M::h(t->laz, v);\n    t->val = M::g(t->val, v);\n \
    \   t->dat = M::g(t->dat, v);\n    t->rdat = M::g(t->rdat, v);\n  }\n  void toggle(Node\
    \ *t) {\n    std::swap(t->ch[0], t->ch[1]);\n    std::swap(t->dat, t->rdat);\n\
    \    t->rev ^= 1;\n  }\n  Node *eval(Node *t) {\n    if (t->laz != M::ei()) {\n\
    \      if (t->ch[0]) propagate(t->ch[0], t->laz);\n      if (t->ch[1]) propagate(t->ch[1],\
    \ t->laz);\n      t->laz = M::ei();\n    }\n    if (t->rev) {\n      if (t->ch[0])\
    \ toggle(t->ch[0]);\n      if (t->ch[1]) toggle(t->ch[1]);\n      t->rev = false;\n\
    \    }\n    return t;\n  }\n\n private:\n  std::vector<Node> ns;\n  size_t linkcnt;\n\
    \n public:\n  LinkCutTree_MonoidLazy(int n, T init = M::ti()) : ns(n, init), linkcnt(0)\
    \ {}\n  // make k the root\n  void evert(int k) {\n    expose(&ns[k]);\n    toggle(&ns[k]);\n\
    \    eval(&ns[k]);\n  }\n  // add link from c to p\n  void link(int c, int p)\
    \ {\n    assert(linkcnt++ < ns.size() - 1);\n    evert(c);\n    expose(&ns[p]);\n\
    \    ns[p].ch[1] = &ns[c];\n    ns[c].par = &ns[p];\n    pushup(&ns[p]);\n  }\n\
    \  // cut link from c to p\n  void cut(int c, int p) {\n    linkcnt--;\n    evert(p);\n\
    \    expose(&ns[c]);\n    Node *y = ns[c].ch[0];\n    ns[c].ch[0] = y->par = nullptr;\n\
    \    pushup(&ns[c]);\n  }\n  int lca(int x, int y) {\n    expose(&ns[x]);\n  \
    \  Node *u = expose(&ns[y]);\n    return ns[x].par ? u - &ns[0] : -1;\n  }\n \
    \ T operator[](int k) {\n    expose(&ns[k]);\n    return ns[k].val;\n  }\n  //\
    \ [a,b] closed section\n  T fold(int a, int b) {\n    evert(a);\n    expose(&ns[b]);\n\
    \    return ns[b].dat;\n  }\n  void update(int a, int b, E v) {\n    evert(a);\n\
    \    expose(&ns[b]);\n    propagate(&ns[b], v);\n    eval(&ns[b]);\n  }\n  void\
    \ set_val(int k, T v) {\n    expose(&ns[k]);\n    ns[k].val = v;\n    eval(&ns[k]);\n\
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Link-Cut-Tree(\u30E2\
    \u30CE\u30A4\u30C9\u9045\u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\n\
    struct LinkCutTree_MonoidLazy {\n  using T = typename M::T;\n  using E = typename\
    \ M::E;\n  struct Node {\n    Node *ch[2], *par;\n    bool rev;\n    T val, dat,\
    \ rdat;\n    E laz;\n    Node(T init = M::ti())\n        : rev(false), val(init),\
    \ dat(init), rdat(init), laz(M::ei()) {\n      ch[0] = ch[1] = par = nullptr;\n\
    \    }\n  };\n\n private:\n  bool is_root(Node *x) {\n    return !x->par || (x->par->ch[0]\
    \ != x && x->par->ch[1] != x);\n  }\n  bool dir(Node *x) { return x->par && x->par->ch[1]\
    \ == x; }\n  void rot(Node *t) {\n    Node *p = t->par;\n    bool d = dir(t);\n\
    \    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par = p;\n    t->ch[!d] = p;\n    pushup(p);\n\
    \    pushup(t);\n    t->par = p->par;\n    if (!is_root(p)) {\n      p->par->ch[dir(p)]\
    \ = t;\n      pushup(t->par);\n    }\n    p->par = t;\n  }\n  void splay(Node\
    \ *x) {\n    eval(x);\n    while (!is_root(x)) {\n      if (!is_root(x->par))\
    \ eval(x->par->par);\n      eval(x->par);\n      eval(x);\n      if (!is_root(x->par))\
    \ {\n        if (dir(x) == dir(x->par))\n          rot(x->par);\n        else\n\
    \          rot(x);\n      }\n      rot(x);\n    }\n  }\n  void pushup(Node *t)\
    \ {\n    t->rdat = t->dat = t->val;\n    if (t->ch[0])\n      t->dat = M::op(t->ch[0]->dat,\
    \ t->dat),\n      t->rdat = M::op(t->rdat, t->ch[0]->rdat);\n    if (t->ch[1])\n\
    \      t->dat = M::op(t->dat, t->ch[1]->dat),\n      t->rdat = M::op(t->ch[1]->rdat,\
    \ t->rdat);\n  }\n  Node *expose(Node *x) {\n    Node *r = nullptr;\n    for (Node\
    \ *p = x; p; p = p->par) {\n      splay(p);\n      p->ch[1] = r;\n      pushup(p);\n\
    \      r = p;\n    }\n    splay(x);\n    return r;\n  }\n  void propagate(Node\
    \ *t, E v) {\n    t->laz = M::h(t->laz, v);\n    t->val = M::g(t->val, v);\n \
    \   t->dat = M::g(t->dat, v);\n    t->rdat = M::g(t->rdat, v);\n  }\n  void toggle(Node\
    \ *t) {\n    std::swap(t->ch[0], t->ch[1]);\n    std::swap(t->dat, t->rdat);\n\
    \    t->rev ^= 1;\n  }\n  Node *eval(Node *t) {\n    if (t->laz != M::ei()) {\n\
    \      if (t->ch[0]) propagate(t->ch[0], t->laz);\n      if (t->ch[1]) propagate(t->ch[1],\
    \ t->laz);\n      t->laz = M::ei();\n    }\n    if (t->rev) {\n      if (t->ch[0])\
    \ toggle(t->ch[0]);\n      if (t->ch[1]) toggle(t->ch[1]);\n      t->rev = false;\n\
    \    }\n    return t;\n  }\n\n private:\n  std::vector<Node> ns;\n  size_t linkcnt;\n\
    \n public:\n  LinkCutTree_MonoidLazy(int n, T init = M::ti()) : ns(n, init), linkcnt(0)\
    \ {}\n  // make k the root\n  void evert(int k) {\n    expose(&ns[k]);\n    toggle(&ns[k]);\n\
    \    eval(&ns[k]);\n  }\n  // add link from c to p\n  void link(int c, int p)\
    \ {\n    assert(linkcnt++ < ns.size() - 1);\n    evert(c);\n    expose(&ns[p]);\n\
    \    ns[p].ch[1] = &ns[c];\n    ns[c].par = &ns[p];\n    pushup(&ns[p]);\n  }\n\
    \  // cut link from c to p\n  void cut(int c, int p) {\n    linkcnt--;\n    evert(p);\n\
    \    expose(&ns[c]);\n    Node *y = ns[c].ch[0];\n    ns[c].ch[0] = y->par = nullptr;\n\
    \    pushup(&ns[c]);\n  }\n  int lca(int x, int y) {\n    expose(&ns[x]);\n  \
    \  Node *u = expose(&ns[y]);\n    return ns[x].par ? u - &ns[0] : -1;\n  }\n \
    \ T operator[](int k) {\n    expose(&ns[k]);\n    return ns[k].val;\n  }\n  //\
    \ [a,b] closed section\n  T fold(int a, int b) {\n    evert(a);\n    expose(&ns[b]);\n\
    \    return ns[b].dat;\n  }\n  void update(int a, int b, E v) {\n    evert(a);\n\
    \    expose(&ns[b]);\n    propagate(&ns[b], v);\n    eval(&ns[b]);\n  }\n  void\
    \ set_val(int k, T v) {\n    expose(&ns[k]);\n    ns[k].val = v;\n    eval(&ns[k]);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LinkCutTree_MonoidLazy.hpp
  requiredBy: []
  timestamp: '2021-09-20 02:18:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2450.LCT.test.cpp
  - test/yukicoder/235.LCT.test.cpp
documentation_of: src/DataStructure/LinkCutTree_MonoidLazy.hpp
layout: document
redirect_from:
- /library/src/DataStructure/LinkCutTree_MonoidLazy.hpp
- /library/src/DataStructure/LinkCutTree_MonoidLazy.hpp.html
title: "Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9\u9045\u5EF6\u4F1D\u642C)"
---
