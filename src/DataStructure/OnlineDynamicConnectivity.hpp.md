---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/EulerTourTree.hpp
    title: Euler-Tour-Tree
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2235.onlinedicon.test.cpp
    title: test/aoj/2235.onlinedicon.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2893.onlinedicon.test.cpp
    title: test/aoj/2893.onlinedicon.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/OnlineDynamicConnectivity.hpp\"\n#include\
    \ <vector>\n#include <unordered_set>\n#line 2 \"src/DataStructure/EulerTourTree.hpp\"\
    \n#include <algorithm>\n#include <string>\n#include <unordered_map>\n#include\
    \ <cstddef>\n#include <cstdint>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include\
    \ <type_traits>\n#define MEMBER_MACRO(member, Dummy, name, type1, type2, last)\
    \ \\\n template <class tClass> struct name##member { \\\n  template <class U,\
    \ Dummy> static type1 check(U *); \\\n  static type2 check(...); \\\n  static\
    \ tClass *mClass; \\\n  last; \\\n }\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member,\
    \ Dummy, has_, std::true_type, std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)));\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t)\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass)\n#line 8 \"src/DataStructure/EulerTourTree.hpp\"\
    \ntemplate <typename M= void, size_t NODE_SIZE= 4'000'000> class EulerTourTree\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(ti);\n HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n\
    \ HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(T);\n NULLPTR_OR(E);\n template <class\
    \ L> static constexpr bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;\n\
    \ template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mp<L>, has_cp<L>>;\n using node_id= int;\n using vertex_id= int;\n\
    \ struct Node_B {\n  node_id ch[2], par;\n  uint64_t flag;\n };\n template <class\
    \ D, bool mo, bool du> struct Node_D: Node_B {};\n template <class D> struct Node_D<D,\
    \ 1, 0>: Node_B {\n  typename M::T val= M::ti(), sum= M::ti();\n };\n template\
    \ <class D> struct Node_D<D, 0, 1>: Node_B {\n  typename M::T val;\n  typename\
    \ M::E laz;\n  bool laz_flg;\n };\n template <class D> struct Node_D<D, 1, 1>:\
    \ Node_B {\n  typename M::T val= M::ti(), sum= M::ti();\n  typename M::E laz;\n\
    \  bool laz_flg;\n };\n using Node= Node_D<void, monoid_v<M>, dual_v<M>>;\npublic:\n\
    \ using T= nullptr_or_T_t<M>;\n using E= nullptr_or_E_t<M>;\nprivate:\n static\
    \ inline Node n[NODE_SIZE];\n static inline node_id ni= 1;\n node_id new_edge(int\
    \ s, int d, bool hi) {\n  int i= ni++, ri= ni++;\n  n[i].flag= (uint64_t(s) <<\
    \ 44) | (uint64_t(d) << 24) | hi;\n  n[ri].flag= (uint64_t(d) << 44) | (uint64_t(s)\
    \ << 24);\n  return i;\n }\n static void update(node_id i) {\n  n[i].flag&= 0xffffffffff00000f;\n\
    \  n[i].flag|= ((n[i].flag >> 44) == ((n[i].flag >> 24) & 0xfffff)) << 4;\n  n[i].flag&=\
    \ -11ll, n[i].flag|= (n[i].flag << 1) & 0b1111;\n  if constexpr (monoid_v<M>)\
    \ n[i].sum= n[i].val;\n  if (n[i].ch[0]) {\n   n[i].flag+= (n[n[i].ch[0]].flag\
    \ & 0xfffff0), n[i].flag|= n[n[i].ch[0]].flag & 0b1010;\n   if constexpr (monoid_v<M>)\
    \ n[i].sum= M::op(n[n[i].ch[0]].sum, n[i].sum);\n  }\n  if (n[i].ch[1]) {\n  \
    \ n[i].flag+= (n[n[i].ch[1]].flag & 0xfffff0), n[i].flag|= n[n[i].ch[1]].flag\
    \ & 0b1010;\n   if constexpr (monoid_v<M>) n[i].sum= M::op(n[i].sum, n[n[i].ch[1]].sum);\n\
    \  }\n }\n static inline void propagate(node_id i, const E &x) {\n  if (n[i].laz_flg)\
    \ M::cp(n[i].laz, x);\n  else n[i].laz= x, n[i].laz_flg= true;\n  if ((n[i].flag\
    \ >> 44) == ((n[i].flag >> 24) & 0xfffff)) M::mp(n[i].val, x, 1);\n  if constexpr\
    \ (monoid_v<M>) M::mp(n[i].sum, x, ((n[i].flag >> 4) & 0xfffff));\n }\n static\
    \ inline void push(node_id i) {\n  if (!n[i].laz_flg) return;\n  if (n[i].ch[0])\
    \ propagate(n[i].ch[0], n[i].laz);\n  if (n[i].ch[1]) propagate(n[i].ch[1], n[i].laz);\n\
    \  n[i].laz_flg= false;\n }\n static inline int dir(node_id i) { return n[n[i].par].ch[1]\
    \ == i; }\n static inline void rot(node_id i) {\n  node_id p= n[i].par;\n  int\
    \ d= dir(i);\n  if ((n[p].ch[d]= n[i].ch[!d])) n[n[p].ch[d]].par= p;\n  n[i].ch[!d]=\
    \ p;\n  if ((n[i].par= n[p].par)) n[n[p].par].ch[dir(p)]= i;\n  n[p].par= i, update(p);\n\
    \ }\n static inline void splay(node_id i) {\n  if constexpr (dual_v<M>) push(i);\n\
    \  for (node_id p= n[i].par; p; rot(i), p= n[i].par) {\n   node_id pp= n[p].par;\n\
    \   if constexpr (dual_v<M>) {\n    if (pp) push(pp);\n    push(p), push(i);\n\
    \   }\n   if (pp) rot(dir(i) == dir(p) ? p : i);\n  }\n  update(i);\n }\n static\
    \ inline node_id merge_back(node_id l, node_id r) {\n  if (!l) return r;\n  if\
    \ (!r) return l;\n  while (n[l].ch[1]) l= n[l].ch[1];\n  return splay(l), n[n[r].par=\
    \ l].ch[1]= r, update(l), l;\n }\n static inline std::pair<node_id, node_id> split(node_id\
    \ i) {\n  splay(i);\n  node_id l= n[i].ch[0];\n  return n[i].ch[0]= n[l].par=\
    \ 0, update(i), std::make_pair(l, i);\n }\n static inline void reroot(node_id\
    \ v) {\n  auto p= split(v);\n  merge_back(p.second, p.first), splay(v);\n }\n\
    \ static inline bool same_root(node_id i, node_id j) {\n  if (i) splay(i);\n \
    \ if (j) splay(j);\n  while (n[i].par) i= n[i].par;\n  while (n[j].par) j= n[j].par;\n\
    \  return i == j;\n }\n node_id n_st;\n std::unordered_map<uint64_t, node_id>\
    \ emp;\npublic:\n EulerTourTree() {}\n EulerTourTree(int N): n_st(ni) {\n  ni+=\
    \ N;\n  for (int i= 0; i < N; i++) n[i + n_st].flag= 0x100001000000 * i;\n }\n\
    \ const T &operator[](vertex_id x) { return get(x); }\n const T &get(vertex_id\
    \ x) {\n  static_assert(monoid_v<M> || dual_v<M>, \"\\\"get\\\" is not available\\\
    n\");\n  return n[x + n_st].val;\n }\n void set(vertex_id x, T val) {\n  static_assert(monoid_v<M>\
    \ || dual_v<M>, \"\\\"set\\\" is not available\\n\");\n  splay(x+= n_st), n[x].val=\
    \ val, update(x);\n }\n bool edge_exist(vertex_id x, vertex_id y) {\n  if (x >\
    \ y) std::swap(x, y);\n  return emp.count(((long long)x << 32) | y);\n }\n void\
    \ link(vertex_id x, vertex_id y, bool hi= true) {\n  if (x > y) std::swap(x, y);\n\
    \  int ei= new_edge(x, y, hi);\n  emp.insert(std::make_pair(((long long)x << 32)\
    \ | y, ei));\n  x+= n_st, y+= n_st, reroot(x), reroot(y);\n  n[n[x].par= ei].ch[0]=\
    \ x, n[n[y].par= ei].ch[1]= y;\n  update(ei), merge_back(ei, ei + 1);\n }\n void\
    \ cut(vertex_id x, vertex_id y) {\n  if (x > y) std::swap(x, y);\n  int ei= emp[((long\
    \ long)x << 32) | y], rei= ei + 1;\n  emp.erase(((long long)x << 32) | y);\n \
    \ auto [pl, pr]= split(ei);\n  node_id left, center, right;\n  if (pl && same_root(pl,\
    \ rei)) {\n   auto [ql, qr]= split(rei);\n   left= ql, center= n[qr].ch[1], right=\
    \ n[pr].ch[1], n[center].par= 0;\n  } else {\n   splay(ei), n[ei= n[ei].ch[1]].par=\
    \ 0;\n   auto [ql, qr]= split(rei);\n   splay(pl), left= pl, right= n[qr].ch[1];\n\
    \  }\n  n[right].par= 0, merge_back(left, right);\n }\n bool connected(vertex_id\
    \ x, vertex_id y) { return same_root(x + n_st, y + n_st); }\n void subedge_set(vertex_id\
    \ x, bool val) {\n  splay(x+= n_st);\n  if (val) n[x].flag|= 0b0100;\n  else n[x].flag&=\
    \ -5ll;\n  update(x);\n }\n size_t tree_size(vertex_id x) { return splay(x+= n_st),\
    \ ((n[x].flag >> 4) & 0xfffff); }\n T prod_tree(vertex_id x) {\n  static_assert(monoid_v<M>,\
    \ \"\\\"prod\\\" is not available\\n\");\n  return splay(x+= n_st), n[x].sum;\n\
    \ }\n T prod_subtree(vertex_id x, vertex_id par= -1) {\n  if (par == -1) return\
    \ prod_tree(x);\n  cut(x, par);\n  T ret= prod_tree(x);\n  link(x, par);\n  return\
    \ ret;\n }\n void apply_tree(vertex_id x, E v) {\n  static_assert(dual_v<M>, \"\
    \\\"apply\\\" is not available\\n\");\n  splay(x+= n_st), propagate(x, v), push(x);\n\
    \ }\n void apply_subtree(vertex_id x, vertex_id par, E v) { cut(x, par), apply_tree(x,\
    \ v), link(x, par); }\n static std::string which_available() {\n  std::string\
    \ ret= \"\";\n  if constexpr (monoid_v<M>) ret+= \"\\\"prod\\\" \";\n  if constexpr\
    \ (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return ret;\n }\n template <class Func>\
    \ void hilevel_edges(vertex_id v, Func f) {\n  splay(v+= n_st);\n  while (v &&\
    \ (n[v].flag & 0b0010))\n   while (1) {\n    if (n[v].flag & 0b0001) {\n     f((n[v].flag\
    \ >> 44), ((n[v].flag >> 24) & 0xfffff)), splay(v), n[v].flag&= -2ll, update(v);\n\
    \     break;\n    } else v= n[v].ch[!(n[v].ch[0] && (n[n[v].ch[0]].flag & 0b0010))];\n\
    \   }\n }\n template <class Func> int subedges(vertex_id v, Func f) {\n  splay(v+=\
    \ n_st);\n  while (v && (n[v].flag & 0b1000))\n   for (bool loop= true; loop;)\
    \ {\n    if (n[v].flag & 0b0100) {\n     if (f(n[v].flag >> 44)) return 1;\n \
    \    splay(v), loop= false;\n    } else v= n[v].ch[!(n[v].ch[0] && (n[n[v].ch[0]].flag\
    \ & 0b1000))];\n   }\n  return 0;\n }\n};\n#line 5 \"src/DataStructure/OnlineDynamicConnectivity.hpp\"\
    \ntemplate <typename M= void, std::size_t NODE_SIZE= 4'000'000> class OnlineDynamicConnectivity\
    \ {\n using T= typename EulerTourTree<M, NODE_SIZE>::T;\n using E= typename EulerTourTree<M,\
    \ NODE_SIZE>::E;\n int N;\n std::vector<EulerTourTree<M, NODE_SIZE>> ett;\n std::vector<std::vector<std::unordered_set<int>>>\
    \ adj;\n void replace(int x, int y, int level) {\n  for (int k= 0; k < level;\
    \ k++) ett[k].cut(x, y);\n  for (int k= level, loop= true; k-- && loop;) {\n \
    \  if (ett[k].tree_size(x) > ett[k].tree_size(y)) std::swap(x, y);\n   ett[k].hilevel_edges(x,\
    \ [&](int s, int d) { ett[k + 1].link(s, d, true); });\n   ett[k].subedges(x,\
    \ [&](int s) {\n    for (auto itr= adj[k][s].begin(); itr != adj[k][s].end();)\
    \ {\n     auto d= *itr;\n     if (adj[k][s].size() == 1) ett[k].subedge_set(s,\
    \ 0);\n     if (adj[k][d].size() == 1) ett[k].subedge_set(d, 0);\n     adj[k][d].erase(s),\
    \ itr= adj[k][s].erase(itr);\n     if (ett[k].connected(s, d)) {\n      if (adj[k\
    \ + 1][s].size() == 0) ett[k + 1].subedge_set(s, 1);\n      if (adj[k + 1][d].size()\
    \ == 0) ett[k + 1].subedge_set(d, 1);\n      adj[k + 1][s].insert(d), adj[k +\
    \ 1][d].insert(s);\n     } else {\n      for (int kk= k + 1; kk--;) ett[kk].link(s,\
    \ d, kk == k);\n      return loop= false, true;\n     }\n    }\n    return false;\n\
    \   });\n  }\n }\npublic:\n OnlineDynamicConnectivity(int N): N(N) { ett.emplace_back(N),\
    \ adj.emplace_back(N); }\n void link(int x, int y) {\n  if (ett[0].connected(x,\
    \ y)) {\n   if (adj[0][x].size() == 0) ett[0].subedge_set(x, 1);\n   if (adj[0][y].size()\
    \ == 0) ett[0].subedge_set(y, 1);\n   adj[0][x].insert(y), adj[0][y].insert(x);\n\
    \  } else ett[0].link(x, y, true);\n }\n void cut(int x, int y) {\n  for (int\
    \ k= 0; k < ett.size(); k++)\n   if (adj[k][x].count(y)) {\n    adj[k][x].erase(y),\
    \ adj[k][y].erase(x);\n    if (adj[k][x].size() == 0) ett[k].subedge_set(x, 0);\n\
    \    if (adj[k][y].size() == 0) ett[k].subedge_set(y, 0);\n    return;\n   }\n\
    \  for (int k= ett.size(); k--;)\n   if (ett[k].edge_exist(x, y)) {\n    if (k\
    \ + 1 == ett.size()) ett.emplace_back(N), adj.emplace_back(N);\n    replace(x,\
    \ y, k + 1);\n   }\n }\n const T &operator[](int x) { return ett[0][x]; }\n const\
    \ T &get(int x) { return ett[0].get(x); }\n void set(int x, T val) { ett[0].set(x,\
    \ val); }\n int size(int x) { return ett[0].tree_size(x); }\n T prod(int x) {\
    \ return ett[0].prod_tree(x); }\n void apply(int x, E v) { return ett[0].apply_tree(x,\
    \ v); }\n bool connected(int x, int y) { return ett[0].connected(x, y); }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <unordered_set>\n#include \"src/DataStructure/EulerTourTree.hpp\"\
    \ntemplate <typename M= void, std::size_t NODE_SIZE= 4'000'000> class OnlineDynamicConnectivity\
    \ {\n using T= typename EulerTourTree<M, NODE_SIZE>::T;\n using E= typename EulerTourTree<M,\
    \ NODE_SIZE>::E;\n int N;\n std::vector<EulerTourTree<M, NODE_SIZE>> ett;\n std::vector<std::vector<std::unordered_set<int>>>\
    \ adj;\n void replace(int x, int y, int level) {\n  for (int k= 0; k < level;\
    \ k++) ett[k].cut(x, y);\n  for (int k= level, loop= true; k-- && loop;) {\n \
    \  if (ett[k].tree_size(x) > ett[k].tree_size(y)) std::swap(x, y);\n   ett[k].hilevel_edges(x,\
    \ [&](int s, int d) { ett[k + 1].link(s, d, true); });\n   ett[k].subedges(x,\
    \ [&](int s) {\n    for (auto itr= adj[k][s].begin(); itr != adj[k][s].end();)\
    \ {\n     auto d= *itr;\n     if (adj[k][s].size() == 1) ett[k].subedge_set(s,\
    \ 0);\n     if (adj[k][d].size() == 1) ett[k].subedge_set(d, 0);\n     adj[k][d].erase(s),\
    \ itr= adj[k][s].erase(itr);\n     if (ett[k].connected(s, d)) {\n      if (adj[k\
    \ + 1][s].size() == 0) ett[k + 1].subedge_set(s, 1);\n      if (adj[k + 1][d].size()\
    \ == 0) ett[k + 1].subedge_set(d, 1);\n      adj[k + 1][s].insert(d), adj[k +\
    \ 1][d].insert(s);\n     } else {\n      for (int kk= k + 1; kk--;) ett[kk].link(s,\
    \ d, kk == k);\n      return loop= false, true;\n     }\n    }\n    return false;\n\
    \   });\n  }\n }\npublic:\n OnlineDynamicConnectivity(int N): N(N) { ett.emplace_back(N),\
    \ adj.emplace_back(N); }\n void link(int x, int y) {\n  if (ett[0].connected(x,\
    \ y)) {\n   if (adj[0][x].size() == 0) ett[0].subedge_set(x, 1);\n   if (adj[0][y].size()\
    \ == 0) ett[0].subedge_set(y, 1);\n   adj[0][x].insert(y), adj[0][y].insert(x);\n\
    \  } else ett[0].link(x, y, true);\n }\n void cut(int x, int y) {\n  for (int\
    \ k= 0; k < ett.size(); k++)\n   if (adj[k][x].count(y)) {\n    adj[k][x].erase(y),\
    \ adj[k][y].erase(x);\n    if (adj[k][x].size() == 0) ett[k].subedge_set(x, 0);\n\
    \    if (adj[k][y].size() == 0) ett[k].subedge_set(y, 0);\n    return;\n   }\n\
    \  for (int k= ett.size(); k--;)\n   if (ett[k].edge_exist(x, y)) {\n    if (k\
    \ + 1 == ett.size()) ett.emplace_back(N), adj.emplace_back(N);\n    replace(x,\
    \ y, k + 1);\n   }\n }\n const T &operator[](int x) { return ett[0][x]; }\n const\
    \ T &get(int x) { return ett[0].get(x); }\n void set(int x, T val) { ett[0].set(x,\
    \ val); }\n int size(int x) { return ett[0].tree_size(x); }\n T prod(int x) {\
    \ return ett[0].prod_tree(x); }\n void apply(int x, E v) { return ett[0].apply_tree(x,\
    \ v); }\n bool connected(int x, int y) { return ett[0].connected(x, y); }\n};\n"
  dependsOn:
  - src/DataStructure/EulerTourTree.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/DataStructure/OnlineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '2024-04-13 13:36:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2893.onlinedicon.test.cpp
  - test/aoj/2235.onlinedicon.test.cpp
  - test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: src/DataStructure/OnlineDynamicConnectivity.hpp
layout: document
title: Online-Dynamic-Connectivity
---
単位元は必要あり（遅延側は必要なし）\
各ノードが部分木のサイズを保持しているのでmapping関数では引数としてsizeを渡せる
## 計算量
- `link`, `cut`: $\mathcal{O}((\log N)^2)$
- `connected`: $\mathcal{O}(\log N)$
## 参考
[https://qiita.com/hotman78/items/78cd3aa50b05a57738d4](https://qiita.com/hotman78/items/78cd3aa50b05a57738d4)