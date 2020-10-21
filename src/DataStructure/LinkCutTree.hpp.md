---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.LCT.test.cpp
    title: test/yosupo/lca.LCT.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Link-Cut-Tree(\u30B7\u30F3\u30D7\u30EB)"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/LinkCutTree.hpp\"\n/**\n * @title Link-Cut-Tree(\u30B7\
    \u30F3\u30D7\u30EB)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\nstruct LinkCutTree {\n  struct Node {\n    Node *ch[2], *par;\n    bool\
    \ rev;\n  };\n\n private:\n  bool is_root(Node *x) {\n    return !x->par || (x->par->ch[0]\
    \ != x && x->par->ch[1] != x);\n  }\n  bool dir(Node *x) { return x->par && x->par->ch[1]\
    \ == x; }\n  void rot(Node *t) {\n    Node *p = t->par;\n    bool d = dir(t);\n\
    \    if ((p->ch[d] = t->ch[!d])) t->ch[!d]->par = p;\n    t->ch[!d] = p;\n   \
    \ t->par = p->par;\n    if (!is_root(p)) p->par->ch[dir(p)] = t;\n    p->par =\
    \ t;\n  }\n  void splay(Node *x) {\n    eval(x);\n    while (!is_root(x)) {\n\
    \      if (!is_root(x->par)) eval(x->par->par);\n      eval(x->par);\n      eval(x);\n\
    \      if (!is_root(x->par)) {\n        if (dir(x) == dir(x->par))\n         \
    \ rot(x->par);\n        else\n          rot(x);\n      }\n      rot(x);\n    }\n\
    \  }\n  Node *expose(Node *x) {\n    Node *r = nullptr;\n    for (Node *p = x;\
    \ p; p = p->par) {\n      splay(p);\n      p->ch[1] = r;\n      r = p;\n    }\n\
    \    splay(x);\n    return r;\n  }\n  void toggle(Node *t) {\n    swap(t->ch[0],\
    \ t->ch[1]);\n    t->rev ^= true;\n  }\n  Node *eval(Node *t) {\n    if (t->rev)\
    \ {\n      if (t->ch[0]) toggle(t->ch[0]);\n      if (t->ch[1]) toggle(t->ch[1]);\n\
    \      t->rev = false;\n    }\n    return t;\n  }\n\n private:\n  vector<Node>\
    \ ns;\n  size_t linkcnt;\n\n public:\n  LinkCutTree(int n) : ns(n), linkcnt(0)\
    \ {}\n  // make k the root\n  void evert(int k) {\n    expose(&ns[k]);\n    toggle(&ns[k]);\n\
    \    eval(&ns[k]);\n  }\n  // add link from c to p\n  void link(int c, int p)\
    \ {\n    assert(linkcnt++ < ns.size() - 1);\n    evert(c);\n    expose(&ns[p]);\n\
    \    ns[p].ch[1] = &ns[c];\n    ns[c].par = &ns[p];\n  }\n  // cut link from c\
    \ (to the root direction)\n  void cut(int c, int p) {\n    linkcnt--;\n    evert(p);\n\
    \    expose(&ns[c]);\n    Node *y = ns[c].ch[0];\n    ns[c].ch[0] = y->par = nullptr;\n\
    \  }\n  int lca(int x, int y) {\n    expose(&ns[x]);\n    Node *u = expose(&ns[y]);\n\
    \    return ns[x].par ? u - &ns[0] : -1;\n  }\n};\n"
  code: "/**\n * @title Link-Cut-Tree(\u30B7\u30F3\u30D7\u30EB)\n * @category \u30C7\
    \u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n\nstruct LinkCutTree {\n  struct\
    \ Node {\n    Node *ch[2], *par;\n    bool rev;\n  };\n\n private:\n  bool is_root(Node\
    \ *x) {\n    return !x->par || (x->par->ch[0] != x && x->par->ch[1] != x);\n \
    \ }\n  bool dir(Node *x) { return x->par && x->par->ch[1] == x; }\n  void rot(Node\
    \ *t) {\n    Node *p = t->par;\n    bool d = dir(t);\n    if ((p->ch[d] = t->ch[!d]))\
    \ t->ch[!d]->par = p;\n    t->ch[!d] = p;\n    t->par = p->par;\n    if (!is_root(p))\
    \ p->par->ch[dir(p)] = t;\n    p->par = t;\n  }\n  void splay(Node *x) {\n   \
    \ eval(x);\n    while (!is_root(x)) {\n      if (!is_root(x->par)) eval(x->par->par);\n\
    \      eval(x->par);\n      eval(x);\n      if (!is_root(x->par)) {\n        if\
    \ (dir(x) == dir(x->par))\n          rot(x->par);\n        else\n          rot(x);\n\
    \      }\n      rot(x);\n    }\n  }\n  Node *expose(Node *x) {\n    Node *r =\
    \ nullptr;\n    for (Node *p = x; p; p = p->par) {\n      splay(p);\n      p->ch[1]\
    \ = r;\n      r = p;\n    }\n    splay(x);\n    return r;\n  }\n  void toggle(Node\
    \ *t) {\n    swap(t->ch[0], t->ch[1]);\n    t->rev ^= true;\n  }\n  Node *eval(Node\
    \ *t) {\n    if (t->rev) {\n      if (t->ch[0]) toggle(t->ch[0]);\n      if (t->ch[1])\
    \ toggle(t->ch[1]);\n      t->rev = false;\n    }\n    return t;\n  }\n\n private:\n\
    \  vector<Node> ns;\n  size_t linkcnt;\n\n public:\n  LinkCutTree(int n) : ns(n),\
    \ linkcnt(0) {}\n  // make k the root\n  void evert(int k) {\n    expose(&ns[k]);\n\
    \    toggle(&ns[k]);\n    eval(&ns[k]);\n  }\n  // add link from c to p\n  void\
    \ link(int c, int p) {\n    assert(linkcnt++ < ns.size() - 1);\n    evert(c);\n\
    \    expose(&ns[p]);\n    ns[p].ch[1] = &ns[c];\n    ns[c].par = &ns[p];\n  }\n\
    \  // cut link from c (to the root direction)\n  void cut(int c, int p) {\n  \
    \  linkcnt--;\n    evert(p);\n    expose(&ns[c]);\n    Node *y = ns[c].ch[0];\n\
    \    ns[c].ch[0] = y->par = nullptr;\n  }\n  int lca(int x, int y) {\n    expose(&ns[x]);\n\
    \    Node *u = expose(&ns[y]);\n    return ns[x].par ? u - &ns[0] : -1;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LinkCutTree.hpp
  requiredBy: []
  timestamp: '2020-10-17 15:44:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.LCT.test.cpp
documentation_of: src/DataStructure/LinkCutTree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/LinkCutTree.hpp
- /library/src/DataStructure/LinkCutTree.hpp.html
title: "Link-Cut-Tree(\u30B7\u30F3\u30D7\u30EB)"
---
