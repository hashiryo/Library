---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/EulerTourTree_Monoid.hpp
    title: "Euler-Tour-Tree(\u30E2\u30CE\u30A4\u30C9)"
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/OnlineDynamicConnectivity_Monoid.hpp
    title: "Euler-Tour-Tree(\u30E2\u30CE\u30A4\u30C9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/EulerTourTree_Monoid.hpp\"\
    \n/**\n * @title Euler-Tour-Tree(\u30E2\u30CE\u30A4\u30C9)\n * @category \u30C7\
    \u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <typename M>\nclass EulerTourTree_Monoid {\n  using T = typename M::T;\n  using\
    \ size_type = std::size_t;\n  using node_id = std::int_least32_t;\n  using vertex_id\
    \ = std::int_least32_t;\n\n  struct Node {\n    vertex_id s, d;\n    node_id ch[2],\
    \ par;\n    int sz;\n    std::int_least8_t flag;\n    T val, sum;\n    Node(T\
    \ init = M::ti()) : sz(1), val(init), sum(init) {}\n  };\n  static constexpr int\
    \ NODE_SIZE = 303030 * 4;\n  static struct Node n[NODE_SIZE];\n  static inline\
    \ node_id ni = 1;\n\n  node_id new_edge(int s, int d, bool hi) {\n    int i =\
    \ ni++, ri = ni++;\n    return n[i].s = n[ri].d = s, n[i].d = n[ri].s = d, n[i].sz\
    \ = n[ri].sz = 0,\n           n[i].flag = hi, i;\n  }\n\n  static void pushup(node_id\
    \ i) {\n    n[i].sz = (n[i].s == n[i].d), n[i].flag &= 0b0101,\n    n[i].flag\
    \ |= n[i].flag << 1, n[i].sum = n[i].val;\n    if (n[i].ch[0])\n      n[i].sz\
    \ += n[n[i].ch[0]].sz, n[i].flag |= n[n[i].ch[0]].flag & 0b1010,\n          n[i].sum\
    \ = M::op(n[n[i].ch[0]].sum, n[i].sum);\n    if (n[i].ch[1])\n      n[i].sz +=\
    \ n[n[i].ch[1]].sz, n[i].flag |= n[n[i].ch[1]].flag & 0b1010,\n          n[i].sum\
    \ = M::op(n[i].sum, n[n[i].ch[1]].sum);\n  }\n\n  static int dir(node_id i) {\n\
    \    if (n[i].par) {\n      if (n[n[i].par].ch[0] == i)\n        return 0;\n \
    \     else if (n[n[i].par].ch[1] == i)\n        return 1;\n    }\n    return 2;\n\
    \  }\n\n  static void rot(node_id x) {\n    node_id p = n[x].par;\n    int d =\
    \ dir(x);\n    if ((n[p].ch[d] = n[x].ch[!d])) n[n[p].ch[d]].par = p;\n    n[x].ch[!d]\
    \ = p, pushup(p), pushup(x), n[x].par = n[p].par;\n    if ((d = dir(p)) < 2) n[n[p].par].ch[d]\
    \ = x, pushup(n[p].par);\n    n[p].par = x;\n  }\n\n  static void splay(node_id\
    \ i) {\n    for (int i_dir = dir(i), p_dir; i_dir < 2; rot(i), i_dir = dir(i))\n\
    \      if ((p_dir = dir(n[i].par)) < 2) rot(i_dir == p_dir ? n[i].par : i);\n\
    \  }\n\n  static node_id merge_back(node_id l, node_id r) {\n    if (!l) return\
    \ r;\n    if (!r) return l;\n    while (n[l].ch[1]) l = n[l].ch[1];\n    return\
    \ splay(l), n[n[r].par = l].ch[1] = r, pushup(l), l;\n  }\n\n  static std::pair<node_id,\
    \ node_id> split(node_id i) {\n    splay(i);\n    node_id l = n[i].ch[0];\n  \
    \  return n[i].ch[0] = n[l].par = 0, pushup(i), std::make_pair(l, i);\n  }\n\n\
    \  static void reroot(node_id v) {\n    auto p = split(v);\n    merge_back(p.second,\
    \ p.first), splay(v);\n  }\n\n  static bool same_root(node_id i, node_id j) {\n\
    \    if (i) splay(i);\n    if (j) splay(j);\n    while (n[i].par) i = n[i].par;\n\
    \    while (n[j].par) j = n[j].par;\n    return i == j;\n  }\n\n  node_id n_st;\n\
    \  std::unordered_map<std::uint64_t, node_id> emp;\n\n public:\n  EulerTourTree_Monoid()\
    \ {}\n  EulerTourTree_Monoid(int N) : n_st(ni) {\n    ni += N;\n    for (int i\
    \ = 0; i < N; i++) n[i + n_st].s = n[i + n_st].d = i;\n  }\n\n  bool edge_exist(vertex_id\
    \ x, vertex_id y) {\n    if (x > y) std::swap(x, y);\n    return emp.count(((long\
    \ long)x << 32) | (long long)y);\n  }\n\n  void link(vertex_id x, vertex_id y,\
    \ bool hi = true) {\n    if (x > y) std::swap(x, y);\n    int ei = new_edge(x,\
    \ y, hi);\n    emp.insert(std::make_pair(((long long)x << 32) | (long long)y,\
    \ ei));\n    x += n_st, y += n_st, reroot(x), reroot(y);\n    n[n[x].par = ei].ch[0]\
    \ = x, n[n[y].par = ei].ch[1] = y;\n    pushup(ei), merge_back(ei, ei + 1);\n\
    \  }\n\n  void cut(vertex_id x, vertex_id y) {\n    if (x > y) std::swap(x, y);\n\
    \    int ei = emp[((long long)x << 32) | (long long)y], rei = ei + 1;\n    emp.erase(((long\
    \ long)x << 32) | (long long)y);\n    auto [pl, pr] = split(ei);\n    node_id\
    \ left, center, right;\n    if (pl && same_root(pl, rei)) {\n      auto [ql, qr]\
    \ = split(rei);\n      left = ql, center = n[qr].ch[1], right = n[pr].ch[1], n[center].par\
    \ = 0;\n    } else {\n      splay(ei), n[ei = n[ei].ch[1]].par = 0;\n      auto\
    \ [ql, qr] = split(rei);\n      splay(pl), left = pl, right = n[qr].ch[1];\n \
    \   }\n    n[right].par = 0, merge_back(left, right);\n  }\n\n  bool connected(vertex_id\
    \ x, vertex_id y) {\n    return same_root(x + n_st, y + n_st);\n  }\n\n  void\
    \ subedge_set(vertex_id x, bool val) {\n    splay(x += n_st);\n    if (val)\n\
    \      n[x].flag |= (0b0100);\n    else\n      n[x].flag &= ~(0b0100);\n    pushup(x);\n\
    \  }\n\n  void set_val(vertex_id x, T val) {\n    splay(x += n_st), n[x].val =\
    \ M::op(n[x].val, val), pushup(x);\n  }\n\n  int tree_size(vertex_id x) { return\
    \ splay(x += n_st), n[x].sz; }\n  T tree_fold(vertex_id x) { return splay(x +=\
    \ n_st), n[x].sum; }\n\n  template <class Func>\n  void hilevel_edges(vertex_id\
    \ v, Func f) {\n    splay(v += n_st);\n    while (v && (n[v].flag & 0b0010)) {\n\
    \      while (1) {\n        if (n[v].flag & 0b0001) {\n          f(n[v].s, n[v].d),\
    \ splay(v), n[v].flag &= ~(0b0001), pushup(v);\n          break;\n        } else\n\
    \          v = n[v].ch[!(n[v].ch[0] && (n[n[v].ch[0]].flag & 0b0010))];\n    \
    \  }\n    }\n  }\n\n  template <class Func>\n  int subedges(vertex_id v, Func\
    \ f) {\n    splay(v += n_st);\n    while (v && (n[v].flag & 0b1000)) {\n     \
    \ for (bool loop = true; loop;) {\n        if (n[v].flag & 0b0100) {\n       \
    \   if (f(n[v].s)) return 1;\n          splay(v), loop = false;\n        } else\n\
    \          v = n[v].ch[!(n[v].ch[0] && (n[n[v].ch[0]].flag & 0b1000))];\n    \
    \  }\n    }\n    return 0;\n  }\n\n  void debug_tree(node_id i, std::string indent)\
    \ {\n    if (n[i].ch[0]) {\n      debug_tree(n[i].ch[0], indent + \"l\");\n  \
    \  }\n    std::cout << \" \" << i << \" = (\" << n[i].s << \" \" << n[i].d <<\
    \ \")\"\n              << \" p \" << n[i].par << std::endl;\n    if (n[i].ch[1])\
    \ {\n      debug_tree(n[i].ch[1], indent + \"r\");\n    }\n  }\n};\ntemplate <typename\
    \ M>\ntypename EulerTourTree_Monoid<M>::Node EulerTourTree_Monoid<M>::n[NODE_SIZE];\n\
    #line 4 \"src/DataStructure/OnlineDynamicConnectivity_Monoid.hpp\"\n/**\n * @title\
    \ Euler-Tour-Tree(\u30E2\u30CE\u30A4\u30C9)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\n\
    struct OnlineDynamicConnectivity_Monoid {\n  using T = typename M::T;\n  int N;\n\
    \  std::vector<EulerTourTree_Monoid<M>> ett;\n  std::vector<std::vector<std::unordered_set<int>>>\
    \ E;\n\n  OnlineDynamicConnectivity_Monoid(int N) : N(N) {\n    ett.emplace_back(N),\
    \ E.emplace_back(N);\n  }\n\n  void link(int x, int y) {\n    if (ett[0].connected(x,\
    \ y)) {\n      if (E[0][x].size() == 0) ett[0].subedge_set(x, 1);\n      if (E[0][y].size()\
    \ == 0) ett[0].subedge_set(y, 1);\n      E[0][x].insert(y), E[0][y].insert(x);\n\
    \    } else\n      ett[0].link(x, y, true);\n  }\n\n  void replace(int x, int\
    \ y, int level) {\n    for (int k = 0; k < level; k++) ett[k].cut(x, y);\n   \
    \ for (int k = level, loop = true; k-- > 0 && loop;) {\n      if (ett[k].tree_size(x)\
    \ > ett[k].tree_size(y)) std::swap(x, y);\n      ett[k].hilevel_edges(x,\n   \
    \                        [&](int s, int d) { ett[k + 1].link(s, d, true); });\n\
    \      ett[k].subedges(x, [&](int s) {\n        for (auto itr = E[k][s].begin();\
    \ itr != E[k][s].end();) {\n          auto d = *itr;\n          if (E[k][s].size()\
    \ == 1) ett[k].subedge_set(s, 0);\n          if (E[k][d].size() == 1) ett[k].subedge_set(d,\
    \ 0);\n          E[k][d].erase(s), itr = E[k][s].erase(itr);\n          if (ett[k].connected(s,\
    \ d)) {\n            if (E[k + 1][s].size() == 0) ett[k + 1].subedge_set(s, 1);\n\
    \            if (E[k + 1][d].size() == 0) ett[k + 1].subedge_set(d, 1);\n    \
    \        E[k + 1][s].insert(d), E[k + 1][d].insert(s);\n          } else {\n \
    \           for (int kk = k + 1; kk-- > 0;) ett[kk].link(s, d, kk == k);\n   \
    \         return loop = false, true;\n          }\n        }\n        return false;\n\
    \      });\n    }\n  }\n\n  void cut(int x, int y) {\n    for (int k = 0; k <\
    \ ett.size(); k++)\n      if (E[k][x].count(y)) {\n        E[k][x].erase(y), E[k][y].erase(x);\n\
    \        if (E[k][x].size() == 0) ett[k].subedge_set(x, 0);\n        if (E[k][y].size()\
    \ == 0) ett[k].subedge_set(y, 0);\n        return;\n      }\n    for (int k =\
    \ ett.size(); k-- > 0;)\n      if (ett[k].edge_exist(x, y)) {\n        if (k +\
    \ 1 == ett.size()) ett.emplace_back(N), E.emplace_back(N);\n        replace(x,\
    \ y, k + 1);\n      }\n  }\n  void set_val(int x, T val) { ett[0].set_val(x, val);\
    \ }\n  int size(int x) { return ett[0].tree_size(x); }\n  long long fold(int x)\
    \ { return ett[0].tree_fold(x); }\n  bool connected(int x, int y) { return ett[0].connected(x,\
    \ y); }\n};\n#line 5 \"test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \nusing namespace std;\n\nstruct Monoid {\n  using T = long long;\n  static inline\
    \ T ti() { return 0; }\n  static inline T op(const T& lval, const T& rval) { return\
    \ lval + rval; }\n};\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  OnlineDynamicConnectivity_Monoid<Monoid> dicon(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int a;\n    cin >> a;\n    dicon.set_val(i,\
    \ a);\n  }\n  int t;\n  int u, v;\n  for (int i = 0; i < Q; i++) {\n    cin >>\
    \ t;\n    if (t == 0) {\n      cin >> u >> v;\n      dicon.link(u, v);\n    }\
    \ else if (t == 1) {\n      cin >> u >> v;\n      dicon.cut(u, v);\n    } else\
    \ if (t == 2) {\n      cin >> u >> v;\n      dicon.set_val(u, v);\n    } else\
    \ {\n      cin >> v;\n      cout << dicon.fold(v) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/EulerTourTree_Monoid.hpp\"\
    \n#include \"src/DataStructure/OnlineDynamicConnectivity_Monoid.hpp\"\nusing namespace\
    \ std;\n\nstruct Monoid {\n  using T = long long;\n  static inline T ti() { return\
    \ 0; }\n  static inline T op(const T& lval, const T& rval) { return lval + rval;\
    \ }\n};\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  OnlineDynamicConnectivity_Monoid<Monoid> dicon(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int a;\n    cin >> a;\n    dicon.set_val(i,\
    \ a);\n  }\n  int t;\n  int u, v;\n  for (int i = 0; i < Q; i++) {\n    cin >>\
    \ t;\n    if (t == 0) {\n      cin >> u >> v;\n      dicon.link(u, v);\n    }\
    \ else if (t == 1) {\n      cin >> u >> v;\n      dicon.cut(u, v);\n    } else\
    \ if (t == 2) {\n      cin >> u >> v;\n      dicon.set_val(u, v);\n    } else\
    \ {\n      cin >> v;\n      cout << dicon.fold(v) << '\\n';\n    }\n  }\n}"
  dependsOn:
  - src/DataStructure/EulerTourTree_Monoid.hpp
  - src/DataStructure/OnlineDynamicConnectivity_Monoid.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
  requiredBy: []
  timestamp: '2021-09-20 02:18:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
- /verify/test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp.html
title: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
---
