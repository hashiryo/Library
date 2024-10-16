#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cstddef>
#include <cstdint>
#include "src/Internal/HAS_CHECK.hpp"
template <typename M= void, size_t NODE_SIZE= 4'000'000> class EulerTourTree {
 HAS_MEMBER(op);
 HAS_MEMBER(ti);
 HAS_MEMBER(mp);
 HAS_MEMBER(cp);
 HAS_TYPE(T);
 HAS_TYPE(E);
 NULLPTR_OR(T);
 NULLPTR_OR(E);
 template <class L> static constexpr bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;
 template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>, has_E<L>, has_mp<L>, has_cp<L>>;
 using node_id= int;
 using vertex_id= int;
 struct Node_B {
  node_id ch[2], par;
  uint64_t flag;
 };
 template <class D, bool mo, bool du> struct Node_D: Node_B {};
 template <class D> struct Node_D<D, 1, 0>: Node_B {
  typename M::T val= M::ti(), sum= M::ti();
 };
 template <class D> struct Node_D<D, 0, 1>: Node_B {
  typename M::T val;
  typename M::E laz;
  bool laz_flg;
 };
 template <class D> struct Node_D<D, 1, 1>: Node_B {
  typename M::T val= M::ti(), sum= M::ti();
  typename M::E laz;
  bool laz_flg;
 };
 using Node= Node_D<void, monoid_v<M>, dual_v<M>>;
public:
 using T= nullptr_or_T_t<M>;
 using E= nullptr_or_E_t<M>;
private:
 static inline Node *n= new Node[NODE_SIZE];
 static inline node_id ni= 1;
 node_id new_edge(int s, int d, bool hi) {
  int i= ni++, ri= ni++;
  n[i].flag= (uint64_t(s) << 44) | (uint64_t(d) << 24) | hi;
  n[ri].flag= (uint64_t(d) << 44) | (uint64_t(s) << 24);
  return i;
 }
 static void update(node_id i) {
  n[i].flag&= 0xffffffffff00000f;
  n[i].flag|= ((n[i].flag >> 44) == ((n[i].flag >> 24) & 0xfffff)) << 4;
  n[i].flag&= -11ll, n[i].flag|= (n[i].flag << 1) & 0b1111;
  if constexpr (monoid_v<M>) n[i].sum= n[i].val;
  if (n[i].ch[0]) {
   n[i].flag+= (n[n[i].ch[0]].flag & 0xfffff0), n[i].flag|= n[n[i].ch[0]].flag & 0b1010;
   if constexpr (monoid_v<M>) n[i].sum= M::op(n[n[i].ch[0]].sum, n[i].sum);
  }
  if (n[i].ch[1]) {
   n[i].flag+= (n[n[i].ch[1]].flag & 0xfffff0), n[i].flag|= n[n[i].ch[1]].flag & 0b1010;
   if constexpr (monoid_v<M>) n[i].sum= M::op(n[i].sum, n[n[i].ch[1]].sum);
  }
 }
 static inline void map(T &v, E x, int sz) {
  if constexpr (std::is_invocable_r_v<void, decltype(M::mp), T &, E, int>) M::mp(v, x, sz);
  else M::mp(v, x);
 }
 static inline void propagate(node_id i, const E &x) {
  if (n[i].laz_flg) M::cp(n[i].laz, x);
  else n[i].laz= x, n[i].laz_flg= true;
  if ((n[i].flag >> 44) == ((n[i].flag >> 24) & 0xfffff)) map(n[i].val, x, 1);
  if constexpr (monoid_v<M>) map(n[i].sum, x, ((n[i].flag >> 4) & 0xfffff));
 }
 static inline void push(node_id i) {
  if (!n[i].laz_flg) return;
  if (n[i].ch[0]) propagate(n[i].ch[0], n[i].laz);
  if (n[i].ch[1]) propagate(n[i].ch[1], n[i].laz);
  n[i].laz_flg= false;
 }
 static inline int dir(node_id i) { return n[n[i].par].ch[1] == i; }
 static inline void rot(node_id i) {
  node_id p= n[i].par;
  int d= dir(i);
  if ((n[p].ch[d]= n[i].ch[!d])) n[n[p].ch[d]].par= p;
  n[i].ch[!d]= p;
  if ((n[i].par= n[p].par)) n[n[p].par].ch[dir(p)]= i;
  n[p].par= i, update(p);
 }
 static inline void splay(node_id i) {
  if constexpr (dual_v<M>) push(i);
  for (node_id p= n[i].par; p; rot(i), p= n[i].par) {
   node_id pp= n[p].par;
   if constexpr (dual_v<M>) {
    if (pp) push(pp);
    push(p), push(i);
   }
   if (pp) rot(dir(i) == dir(p) ? p : i);
  }
  update(i);
 }
 static inline node_id merge_back(node_id l, node_id r) {
  if (!l) return r;
  if (!r) return l;
  while (n[l].ch[1]) l= n[l].ch[1];
  return splay(l), n[n[r].par= l].ch[1]= r, update(l), l;
 }
 static inline std::pair<node_id, node_id> split(node_id i) {
  splay(i);
  node_id l= n[i].ch[0];
  return n[i].ch[0]= n[l].par= 0, update(i), std::make_pair(l, i);
 }
 static inline void reroot(node_id v) {
  auto p= split(v);
  merge_back(p.second, p.first), splay(v);
 }
 static inline bool same_root(node_id i, node_id j) {
  if (i) splay(i);
  if (j) splay(j);
  while (n[i].par) i= n[i].par;
  while (n[j].par) j= n[j].par;
  return i == j;
 }
 node_id n_st;
 std::unordered_map<uint64_t, node_id> emp;
public:
 EulerTourTree() {}
 EulerTourTree(int N): n_st(ni) {
  ni+= N;
  for (int i= 0; i < N; i++) n[i + n_st].flag= 0x100001000000 * i;
 }
 const T &operator[](vertex_id x) { return get(x); }
 const T &get(vertex_id x) {
  static_assert(monoid_v<M> || dual_v<M>, "\"get\" is not available\n");
  return n[x + n_st].val;
 }
 void set(vertex_id x, T val) {
  static_assert(monoid_v<M> || dual_v<M>, "\"set\" is not available\n");
  splay(x+= n_st), n[x].val= val, update(x);
 }
 bool edge_exist(vertex_id x, vertex_id y) {
  if (x > y) std::swap(x, y);
  return emp.count(((long long)x << 32) | y);
 }
 void link(vertex_id x, vertex_id y, bool hi= true) {
  if (x > y) std::swap(x, y);
  int ei= new_edge(x, y, hi);
  emp.insert(std::make_pair(((long long)x << 32) | y, ei));
  x+= n_st, y+= n_st, reroot(x), reroot(y);
  n[n[x].par= ei].ch[0]= x, n[n[y].par= ei].ch[1]= y;
  update(ei), merge_back(ei, ei + 1);
 }
 void cut(vertex_id x, vertex_id y) {
  if (x > y) std::swap(x, y);
  int ei= emp[((long long)x << 32) | y], rei= ei + 1;
  emp.erase(((long long)x << 32) | y);
  auto [pl, pr]= split(ei);
  node_id left, center, right;
  if (pl && same_root(pl, rei)) {
   auto [ql, qr]= split(rei);
   left= ql, center= n[qr].ch[1], right= n[pr].ch[1], n[center].par= 0;
  } else {
   splay(ei), n[ei= n[ei].ch[1]].par= 0;
   auto [ql, qr]= split(rei);
   splay(pl), left= pl, right= n[qr].ch[1];
  }
  n[right].par= 0, merge_back(left, right);
 }
 bool connected(vertex_id x, vertex_id y) { return same_root(x + n_st, y + n_st); }
 void subedge_set(vertex_id x, bool val) {
  splay(x+= n_st);
  if (val) n[x].flag|= 0b0100;
  else n[x].flag&= -5ll;
  update(x);
 }
 size_t tree_size(vertex_id x) { return splay(x+= n_st), ((n[x].flag >> 4) & 0xfffff); }
 T prod_tree(vertex_id x) {
  static_assert(monoid_v<M>, "\"prod\" is not available\n");
  return splay(x+= n_st), n[x].sum;
 }
 T prod_subtree(vertex_id x, vertex_id par= -1) {
  if (par == -1) return prod_tree(x);
  cut(x, par);
  T ret= prod_tree(x);
  link(x, par);
  return ret;
 }
 void apply_tree(vertex_id x, E v) {
  static_assert(dual_v<M>, "\"apply\" is not available\n");
  splay(x+= n_st), propagate(x, v), push(x);
 }
 void apply_subtree(vertex_id x, vertex_id par, E v) { cut(x, par), apply_tree(x, v), link(x, par); }
 static std::string which_available() {
  std::string ret= "";
  if constexpr (monoid_v<M>) ret+= "\"prod\" ";
  if constexpr (dual_v<M>) ret+= "\"apply\" ";
  return ret;
 }
 template <class Func> void hilevel_edges(vertex_id v, Func f) {
  splay(v+= n_st);
  while (v && (n[v].flag & 0b0010))
   while (1) {
    if (n[v].flag & 0b0001) {
     f((n[v].flag >> 44), ((n[v].flag >> 24) & 0xfffff)), splay(v), n[v].flag&= -2ll, update(v);
     break;
    } else v= n[v].ch[!(n[v].ch[0] && (n[n[v].ch[0]].flag & 0b0010))];
   }
 }
 template <class Func> int subedges(vertex_id v, Func f) {
  splay(v+= n_st);
  while (v && (n[v].flag & 0b1000))
   for (bool loop= true; loop;) {
    if (n[v].flag & 0b0100) {
     if (f(n[v].flag >> 44)) return 1;
     splay(v), loop= false;
    } else v= n[v].ch[!(n[v].ch[0] && (n[n[v].ch[0]].flag & 0b1000))];
   }
  return 0;
 }
};