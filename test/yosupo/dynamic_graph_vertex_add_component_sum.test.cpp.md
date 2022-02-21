---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/EulerTourTree.hpp
    title: Euler-Tour-Tree
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/OnlineDynamicConnectivity.hpp
    title: Online-Dynamic-Connectivity
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
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include <bits/stdc++.h>\n\n#line 3 \"src/DataStructure/EulerTourTree.hpp\"\n\
    /**\n * @title Euler-Tour-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n\
    \ * @brief O(logN)\n * \u5358\u4F4D\u5143\u306F\u5FC5\u8981\u3042\u308A\uFF08\u9045\
    \u5EF6\u5074\u306F\u5FC5\u8981\u306A\u3057\uFF09\n * \u5404\u30CE\u30FC\u30C9\u304C\
    \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u306E\u3067mapping\u95A2\u6570\u3067\u306F\u5F15\u6570\u3068\u3057\u3066\
    size\u3092\u6E21\u305B\u308B\n */\n\n// BEGIN CUT HERE\n\n#define HAS_CHECK(member,\
    \ Dummy)                              \\\n  template <class T>               \
    \                           \\\n  struct has_##member {                      \
    \                 \\\n    template <class U, Dummy>                          \
    \       \\\n    static std::true_type check(U*);                          \\\n\
    \    static std::false_type check(...);                        \\\n    static\
    \ T* mClass;                                         \\\n    static const bool\
    \ value = decltype(check(mClass))::value; \\\n  };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy = (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy = typename U::member)\n\ntemplate <typename M = void, std::size_t\
    \ NODE_SIZE = 303030 * 4>\nclass EulerTourTree {\n  HAS_MEMBER(op);\n  HAS_MEMBER(ti);\n\
    \  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n\
    \  template <class L>\n  using monoid = std::conjunction<has_T<L>, has_op<L>,\
    \ has_ti<L>>;\n  template <class L>\n  using dual =\n      std::conjunction<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n  using node_id = std::int_least32_t;\n\
    \  using vertex_id = std::int_least32_t;\n  template <class U = std::nullptr_t,\
    \ class F = std::nullptr_t>\n  struct Node_B {\n    using T = U;\n    using E\
    \ = F;\n    vertex_id s, d;\n    node_id ch[2], par;\n    std::size_t sz;\n  \
    \  std::int_least8_t flag;\n  };\n  template <bool mo_, bool du_, typename tEnable\
    \ = void>\n  struct Node_D : Node_B<> {};\n  template <bool mo_, bool du_>\n \
    \ struct Node_D<mo_, du_, typename std::enable_if_t<mo_ && !du_>>\n      : Node_B<typename\
    \ M::T> {\n    typename M::T val = M::ti(), sum = M::ti();\n  };\n  template <bool\
    \ mo_, bool du_>\n  struct Node_D<mo_, du_, typename std::enable_if_t<!mo_ &&\
    \ du_>>\n      : Node_B<typename M::T, typename M::E> {\n    typename M::T val;\n\
    \    typename M::E lazy;\n    bool lazy_flg;\n  };\n  template <bool mo_, bool\
    \ du_>\n  struct Node_D<mo_, du_, typename std::enable_if_t<mo_ && du_>>\n   \
    \   : Node_B<typename M::T, typename M::E> {\n    typename M::T val = M::ti(),\
    \ sum = M::ti();\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  using Node\
    \ = Node_D<monoid<M>::value, dual<M>::value>;\n\n public:\n  using T = typename\
    \ Node::T;\n  using E = typename Node::E;\n\n private:\n  static inline Node n[NODE_SIZE];\n\
    \  static inline node_id ni = 1;\n  node_id new_edge(int s, int d, bool hi) {\n\
    \    int i = ni++, ri = ni++;\n    return n[i].s = n[ri].d = s, n[i].d = n[ri].s\
    \ = d, n[i].sz = n[ri].sz = 0,\n           n[i].flag = hi, i;\n  }\n  static void\
    \ pushup(node_id i) {\n    n[i].sz = (n[i].s == n[i].d), n[i].flag &= 0b0101,\n\
    \    n[i].flag |= n[i].flag << 1;\n    if constexpr (monoid<M>::value) n[i].sum\
    \ = n[i].val;\n    if (n[i].ch[0]) {\n      n[i].sz += n[n[i].ch[0]].sz, n[i].flag\
    \ |= n[n[i].ch[0]].flag & 0b1010;\n      if constexpr (monoid<M>::value)\n   \
    \     n[i].sum = M::op(n[n[i].ch[0]].sum, n[i].sum);\n    }\n    if (n[i].ch[1])\
    \ {\n      n[i].sz += n[n[i].ch[1]].sz, n[i].flag |= n[n[i].ch[1]].flag & 0b1010;\n\
    \      if constexpr (monoid<M>::value)\n        n[i].sum = M::op(n[i].sum, n[n[i].ch[1]].sum);\n\
    \    }\n  }\n  inline void propagate(node_id i, const E& v) {\n    n[i].lazy =\
    \ n[i].lazy_flg ? M::composition(n[i].lazy, v) : v;\n    if (n[i].s == n[i].d)\
    \ n[i].val = M::mapping(n[i].val, v, 1);\n    if constexpr (monoid<M>::value)\
    \ n[i].sum = M::mapping(n[i].sum, v, n[i].sz);\n    n[i].lazy_flg = true;\n  }\n\
    \  inline void eval(node_id i) {\n    if (!n[i].lazy_flg) return;\n    if (n[i].ch[0])\
    \ propagate(n[i].ch[0], n[i].lazy);\n    if (n[i].ch[1]) propagate(n[i].ch[1],\
    \ n[i].lazy);\n    n[i].lazy_flg = false;\n  }\n  inline int dir(node_id i) {\n\
    \    if (n[i].par) {\n      if (n[n[i].par].ch[0] == i) return 0;\n      if (n[n[i].par].ch[1]\
    \ == i) return 1;\n    }\n    return 2;\n  }\n  inline void rot(node_id x) {\n\
    \    node_id p = n[x].par;\n    int d = dir(x);\n    if ((n[p].ch[d] = n[x].ch[!d]))\
    \ n[n[p].ch[d]].par = p;\n    n[x].ch[!d] = p, pushup(p), pushup(x), n[x].par\
    \ = n[p].par;\n    if ((d = dir(p)) < 2) n[n[p].par].ch[d] = x, pushup(n[p].par);\n\
    \    n[p].par = x;\n  }\n  inline void splay(node_id i) {\n    if constexpr (dual<M>::value)\
    \ eval(i);\n    for (int i_dir = dir(i), p_dir; i_dir < 2; rot(i), i_dir = dir(i))\
    \ {\n      p_dir = dir(n[i].par);\n      if constexpr (dual<M>::value) {\n   \
    \     if (p_dir < 2) eval(n[n[i].par].par);\n        eval(n[i].par), eval(i);\n\
    \      }\n      if (p_dir < 2) rot(i_dir == p_dir ? n[i].par : i);\n    }\n  }\n\
    \  inline node_id merge_back(node_id l, node_id r) {\n    if (!l) return r;\n\
    \    if (!r) return l;\n    while (n[l].ch[1]) l = n[l].ch[1];\n    return splay(l),\
    \ n[n[r].par = l].ch[1] = r, pushup(l), l;\n  }\n  inline std::pair<node_id, node_id>\
    \ split(node_id i) {\n    splay(i);\n    node_id l = n[i].ch[0];\n    return n[i].ch[0]\
    \ = n[l].par = 0, pushup(i), std::make_pair(l, i);\n  }\n  inline void reroot(node_id\
    \ v) {\n    auto p = split(v);\n    merge_back(p.second, p.first), splay(v);\n\
    \  }\n  inline bool same_root(node_id i, node_id j) {\n    if (i) splay(i);\n\
    \    if (j) splay(j);\n    while (n[i].par) i = n[i].par;\n    while (n[j].par)\
    \ j = n[j].par;\n    return i == j;\n  }\n  node_id n_st;\n  std::unordered_map<std::uint64_t,\
    \ node_id> emp;\n\n public:\n  EulerTourTree() {}\n  EulerTourTree(int N) : n_st(ni)\
    \ {\n    ni += N;\n    for (int i = 0; i < N; i++) n[i + n_st].s = n[i + n_st].d\
    \ = i;\n  }\n  const T& operator[](vertex_id x) { return get(x); }\n  const T&\
    \ get(vertex_id x) {\n    static_assert(monoid<M>::value || dual<M>::value,\n\
    \                  \"\\\"get\\\" is not available\\n\");\n    return n[x + n_st].val;\n\
    \  }\n  void set(vertex_id x, T val) {\n    static_assert(monoid<M>::value ||\
    \ dual<M>::value,\n                  \"\\\"set\\\" is not available\\n\");\n \
    \   splay(x += n_st), n[x].val = val, pushup(x);\n  }\n  bool edge_exist(vertex_id\
    \ x, vertex_id y) {\n    if (x > y) std::swap(x, y);\n    return emp.count(((long\
    \ long)x << 32) | (long long)y);\n  }\n  void link(vertex_id x, vertex_id y, bool\
    \ hi = true) {\n    if (x > y) std::swap(x, y);\n    int ei = new_edge(x, y, hi);\n\
    \    emp.insert(std::make_pair(((long long)x << 32) | (long long)y, ei));\n  \
    \  x += n_st, y += n_st, reroot(x), reroot(y);\n    n[n[x].par = ei].ch[0] = x,\
    \ n[n[y].par = ei].ch[1] = y;\n    pushup(ei), merge_back(ei, ei + 1);\n  }\n\
    \  void cut(vertex_id x, vertex_id y) {\n    if (x > y) std::swap(x, y);\n   \
    \ int ei = emp[((long long)x << 32) | (long long)y], rei = ei + 1;\n    emp.erase(((long\
    \ long)x << 32) | (long long)y);\n    auto [pl, pr] = split(ei);\n    node_id\
    \ left, center, right;\n    if (pl && same_root(pl, rei)) {\n      auto [ql, qr]\
    \ = split(rei);\n      left = ql, center = n[qr].ch[1], right = n[pr].ch[1], n[center].par\
    \ = 0;\n    } else {\n      splay(ei), n[ei = n[ei].ch[1]].par = 0;\n      auto\
    \ [ql, qr] = split(rei);\n      splay(pl), left = pl, right = n[qr].ch[1];\n \
    \   }\n    n[right].par = 0, merge_back(left, right);\n  }\n  bool connected(vertex_id\
    \ x, vertex_id y) {\n    return same_root(x + n_st, y + n_st);\n  }\n  void subedge_set(vertex_id\
    \ x, bool val) {\n    splay(x += n_st);\n    if (val)\n      n[x].flag |= (0b0100);\n\
    \    else\n      n[x].flag &= ~(0b0100);\n    pushup(x);\n  }\n  std::size_t tree_size(vertex_id\
    \ x) { return splay(x += n_st), n[x].sz; }\n  T fold_tree(vertex_id x) {\n   \
    \ static_assert(monoid<M>::value, \"\\\"fold\\\" is not available\\n\");\n   \
    \ return splay(x += n_st), n[x].sum;\n  }\n  T fold_subtree(vertex_id x, vertex_id\
    \ par = -1) {\n    if (par == -1) return fold_tree(x);\n    cut(x, par);\n   \
    \ T ret = fold_tree(x);\n    link(x, par);\n    return ret;\n  }\n  void apply_tree(vertex_id\
    \ x, E v) {\n    static_assert(dual<M>::value, \"\\\"apply\\\" is not available\\\
    n\");\n    splay(x += n_st), propagate(x, v), eval(x);\n  }\n  void apply_subtree(vertex_id\
    \ x, vertex_id par, E v) {\n    cut(x, par), apply_tree(x, v), link(x, par);\n\
    \  }\n  static std::string which_available() {\n    std::string ret = \"\";\n\
    \    if constexpr (monoid<M>::value) ret += \"\\\"fold\\\" \";\n    if constexpr\
    \ (dual<M>::value) ret += \"\\\"apply\\\" \";\n    return ret;\n  }\n  template\
    \ <class Func>\n  void hilevel_edges(vertex_id v, Func f) {\n    splay(v += n_st);\n\
    \    while (v && (n[v].flag & 0b0010))\n      while (1) {\n        if (n[v].flag\
    \ & 0b0001) {\n          f(n[v].s, n[v].d), splay(v), n[v].flag &= ~(0b0001),\
    \ pushup(v);\n          break;\n        } else\n          v = n[v].ch[!(n[v].ch[0]\
    \ && (n[n[v].ch[0]].flag & 0b0010))];\n      }\n  }\n  template <class Func>\n\
    \  int subedges(vertex_id v, Func f) {\n    splay(v += n_st);\n    while (v &&\
    \ (n[v].flag & 0b1000))\n      for (bool loop = true; loop;) {\n        if (n[v].flag\
    \ & 0b0100) {\n          if (f(n[v].s)) return 1;\n          splay(v), loop =\
    \ false;\n        } else\n          v = n[v].ch[!(n[v].ch[0] && (n[n[v].ch[0]].flag\
    \ & 0b1000))];\n      }\n    return 0;\n  }\n};\n#line 3 \"src/DataStructure/OnlineDynamicConnectivity.hpp\"\
    \n\n#line 5 \"src/DataStructure/OnlineDynamicConnectivity.hpp\"\n/**\n * @title\
    \ Online-Dynamic-Connectivity\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *\
    \ @brief link,cut: O(log^2 N)\n * @brief connected: O(log N)\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename M = void>\nclass OnlineDynamicConnectivity {\n\
    \  using T = typename EulerTourTree<M>::T;\n  using E = typename EulerTourTree<M>::E;\n\
    \  int N;\n  std::vector<EulerTourTree<M>> ett;\n  std::vector<std::vector<std::unordered_set<int>>>\
    \ adj;\n  void replace(int x, int y, int level) {\n    for (int k = 0; k < level;\
    \ k++) ett[k].cut(x, y);\n    for (int k = level, loop = true; k-- > 0 && loop;)\
    \ {\n      if (ett[k].tree_size(x) > ett[k].tree_size(y)) std::swap(x, y);\n \
    \     ett[k].hilevel_edges(x,\n                           [&](int s, int d) {\
    \ ett[k + 1].link(s, d, true); });\n      ett[k].subedges(x, [&](int s) {\n  \
    \      for (auto itr = adj[k][s].begin(); itr != adj[k][s].end();) {\n       \
    \   auto d = *itr;\n          if (adj[k][s].size() == 1) ett[k].subedge_set(s,\
    \ 0);\n          if (adj[k][d].size() == 1) ett[k].subedge_set(d, 0);\n      \
    \    adj[k][d].erase(s), itr = adj[k][s].erase(itr);\n          if (ett[k].connected(s,\
    \ d)) {\n            if (adj[k + 1][s].size() == 0) ett[k + 1].subedge_set(s,\
    \ 1);\n            if (adj[k + 1][d].size() == 0) ett[k + 1].subedge_set(d, 1);\n\
    \            adj[k + 1][s].insert(d), adj[k + 1][d].insert(s);\n          } else\
    \ {\n            for (int kk = k + 1; kk-- > 0;) ett[kk].link(s, d, kk == k);\n\
    \            return loop = false, true;\n          }\n        }\n        return\
    \ false;\n      });\n    }\n  }\n\n public:\n  OnlineDynamicConnectivity(int N)\
    \ : N(N) {\n    ett.emplace_back(N), adj.emplace_back(N);\n  }\n  void link(int\
    \ x, int y) {\n    if (ett[0].connected(x, y)) {\n      if (adj[0][x].size() ==\
    \ 0) ett[0].subedge_set(x, 1);\n      if (adj[0][y].size() == 0) ett[0].subedge_set(y,\
    \ 1);\n      adj[0][x].insert(y), adj[0][y].insert(x);\n    } else\n      ett[0].link(x,\
    \ y, true);\n  }\n  void cut(int x, int y) {\n    for (int k = 0; k < ett.size();\
    \ k++)\n      if (adj[k][x].count(y)) {\n        adj[k][x].erase(y), adj[k][y].erase(x);\n\
    \        if (adj[k][x].size() == 0) ett[k].subedge_set(x, 0);\n        if (adj[k][y].size()\
    \ == 0) ett[k].subedge_set(y, 0);\n        return;\n      }\n    for (int k =\
    \ ett.size(); k-- > 0;)\n      if (ett[k].edge_exist(x, y)) {\n        if (k +\
    \ 1 == ett.size()) ett.emplace_back(N), adj.emplace_back(N);\n        replace(x,\
    \ y, k + 1);\n      }\n  }\n  const T& operator[](int x) { return ett[0][x]; }\n\
    \  void set(int x, T val) { ett[0].set(x, val); }\n  int size(int x) { return\
    \ ett[0].tree_size(x); }\n  T fold(int x) { return ett[0].fold_tree(x); }\n  void\
    \ apply(int x, E v) { return ett[0].apply_tree(x, v); }\n  bool connected(int\
    \ x, int y) { return ett[0].connected(x, y); }\n};\n#line 7 \"test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \nusing namespace std;\n\nstruct Monoid {\n  using T = long long;\n  static inline\
    \ T ti() { return 0; }\n  static inline T op(const T& lval, const T& rval) { return\
    \ lval + rval; }\n};\n\nint main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  OnlineDynamicConnectivity<Monoid> dicon(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int a;\n    cin >> a;\n    dicon.set(i,\
    \ a);\n  }\n  int t;\n  int u, v;\n  for (int i = 0; i < Q; i++) {\n    cin >>\
    \ t;\n    if (t == 0) {\n      cin >> u >> v;\n      dicon.link(u, v);\n    }\
    \ else if (t == 1) {\n      cin >> u >> v;\n      dicon.cut(u, v);\n    } else\
    \ if (t == 2) {\n      cin >> u >> v;\n      dicon.set(u, dicon[u] + v);\n   \
    \ } else {\n      cin >> v;\n      cout << dicon.fold(v) << '\\n';\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include <bits/stdc++.h>\n\n#include \"src/DataStructure/EulerTourTree.hpp\"\
    \n#include \"src/DataStructure/OnlineDynamicConnectivity.hpp\"\nusing namespace\
    \ std;\n\nstruct Monoid {\n  using T = long long;\n  static inline T ti() { return\
    \ 0; }\n  static inline T op(const T& lval, const T& rval) { return lval + rval;\
    \ }\n};\n\nint main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  OnlineDynamicConnectivity<Monoid> dicon(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int a;\n    cin >> a;\n    dicon.set(i,\
    \ a);\n  }\n  int t;\n  int u, v;\n  for (int i = 0; i < Q; i++) {\n    cin >>\
    \ t;\n    if (t == 0) {\n      cin >> u >> v;\n      dicon.link(u, v);\n    }\
    \ else if (t == 1) {\n      cin >> u >> v;\n      dicon.cut(u, v);\n    } else\
    \ if (t == 2) {\n      cin >> u >> v;\n      dicon.set(u, dicon[u] + v);\n   \
    \ } else {\n      cin >> v;\n      cout << dicon.fold(v) << '\\n';\n    }\n  }\n\
    }"
  dependsOn:
  - src/DataStructure/EulerTourTree.hpp
  - src/DataStructure/OnlineDynamicConnectivity.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
  requiredBy: []
  timestamp: '2021-11-22 16:08:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
- /verify/test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp.html
title: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
---