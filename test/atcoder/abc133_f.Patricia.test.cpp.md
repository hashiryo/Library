---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Patricia.hpp
    title: "Segment-Tree(\u30D1\u30C8\u30EA\u30B7\u30A2\u6728)"
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
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
    PROBLEM: https://atcoder.jp/contests/abc133/tasks/abc133_f
    links:
    - https://atcoder.jp/contests/abc133/tasks/abc133_f
  bundledCode: "#line 1 \"test/atcoder/abc133_f.Patricia.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n\n// \u6C38\u7D9A\u914D\
    \u5217(at) \u306E verify\n\n#include <iostream>\n#include <vector>\n#line 2 \"\
    src/DataStructure/SegmentTree_Patricia.hpp\"\n#include <array>\n#line 4 \"src/DataStructure/SegmentTree_Patricia.hpp\"\
    \n#include <string>\n#include <algorithm>\n#include <tuple>\n#include <cstddef>\n\
    #include <cstdint>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define MEMBER_MACRO(member, Dummy, name, type1, type2, last) \\\n template <class\
    \ tClass> struct name##member { \\\n  template <class U, Dummy> static type1 check(U\
    \ *); \\\n  static type2 check(...); \\\n  static tClass *mClass; \\\n  last;\
    \ \\\n }\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member, Dummy, has_, std::true_type,\
    \ std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)));\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t)\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass)\n#line 10 \"src/DataStructure/SegmentTree_Patricia.hpp\"\
    \ntemplate <typename M, bool persistent= false, uint8_t HEIGHT= 31> class SegmentTree_Patricia\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(ti);\n HAS_TYPE(T);\n template <class L> static\
    \ constexpr bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;\n\
    \ using id_t= long long;\n template <class T, class tDerived> struct Node_B {\n\
    \  id_t bits;\n  uint8_t len;\n  T val;\n  tDerived *ch[2]= {nullptr, nullptr};\n\
    \ };\n template <bool mo, typename tEnable= void> struct Node_D: Node_B<M, Node_D<mo,\
    \ tEnable>> {};\n template <bool mo> struct Node_D<mo, typename std::enable_if_t<mo>>:\
    \ Node_B<typename M::T, Node_D<mo>> {};\n using Node= Node_D<monoid_v<M>>;\n using\
    \ T= decltype(Node::val);\n using np= Node *;\n np root;\n static inline constexpr\
    \ T def_val() {\n  if constexpr (monoid_v<M>) return M::ti();\n  else return T();\n\
    \ }\n template <class S> np build(const id_t &n, id_t l, id_t r, const S &bg)\
    \ {\n  if (n <= l) return nullptr;\n  id_t m= (l + r) / 2;\n  while (n <= m) r=\
    \ m, m= (l + r) / 2;\n  if (r - l == 1) {\n   if constexpr (std::is_same_v<S,\
    \ T>) return new Node{l, HEIGHT + 1, bg};\n   else return new Node{l, HEIGHT +\
    \ 1, *(bg + l)};\n  }\n  uint8_t h= __builtin_ctzll(r - l);\n  np t= new Node{m\
    \ >> h, uint8_t(HEIGHT + 1 - h), def_val(), {build(n, l, m, bg), build(n, m, r,\
    \ bg)}};\n  if constexpr (monoid_v<M>) t->val= M::op(t->ch[0]->val, t->ch[1]->val);\n\
    \  return t;\n }\n void dump(np t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b, typename std::vector<T>::iterator itr, uint8_t h) {\n  if (r <= b[0] ||\
    \ b[1] <= l) return;\n  if (l <= b[0] && b[1] <= r && !t) {\n   for (id_t i= b[0];\
    \ i < b[1]; i++) *(itr + i)= def_val();\n  } else if (b[1] - b[0] != 1) {\n  \
    \ auto m= (b[0] + b[1]) >> 1;\n   dump(next(t, h, 0), l, r, {b[0], m}, itr, h\
    \ - 1);\n   dump(next(t, h, 1), l, r, {m, b[1]}, itr, h - 1);\n  } else *(itr\
    \ + b[0])= t->val;\n }\n T prod(np &t, const id_t &l, const id_t &r, const id_t\
    \ &bias) {\n  static id_t bits, b[2];\n  if (!t) return def_val();\n  uint8_t\
    \ h= (HEIGHT + 1) - t->len;\n  bits= (bias >> h) ^ t->bits, b[0]= bits << h, b[1]=\
    \ (bits + 1) << h;\n  if (r <= b[0] || b[1] <= l) return def_val();\n  if (l <=\
    \ b[0] && b[1] <= r) return t->val;\n  bool flg= (bias >> (h - 1)) & 1;\n  return\
    \ M::op(prod(t->ch[flg], l, r, bias), prod(t->ch[!flg], l, r, bias));\n }\n void\
    \ set_val(np &t, const id_t &k, const T &val) {\n  if (!t) return t= new Node{k,\
    \ HEIGHT + 1, val}, void();\n  if constexpr (persistent) t= new Node{*t};\n  id_t\
    \ bits= (k >> ((HEIGHT + 1) - t->len));\n  if (bits != t->bits) {\n   uint8_t\
    \ i= 64 - __builtin_clzll(bits ^ t->bits);\n   bool flg= (t->bits >> (i - 1))\
    \ & 1;\n   t->ch[flg]= new Node{*t}, t->ch[!flg]= new Node{k, HEIGHT + 1, val};\n\
    \   t->len-= i, t->bits>>= i;\n  } else if (t->len != HEIGHT + 1) {\n   set_val(t->ch[(k\
    \ >> (HEIGHT - t->len)) & 1], k, val);\n  } else return t->val= val, void();\n\
    \  if constexpr (monoid_v<M>) t->val= M::op(t->ch[0]->val, t->ch[1]->val);\n }\n\
    \ T &at_val(np &t, const id_t &k) {\n  if (!t) return t= new Node{k, HEIGHT +\
    \ 1, def_val()}, t->val;\n  if constexpr (persistent) t= new Node{*t};\n  id_t\
    \ bits= (k >> ((HEIGHT + 1) - t->len));\n  if (bits != t->bits) {\n   uint8_t\
    \ i= 64 - __builtin_clzll(bits ^ t->bits);\n   bool flg= (t->bits >> (i - 1))\
    \ & 1;\n   t->ch[flg]= new Node{*t}, t->ch[!flg]= new Node{k, HEIGHT + 1, def_val()};\n\
    \   t->len-= i, t->bits>>= i;\n   return t->ch[!flg]->val;\n  } else if (t->len\
    \ != HEIGHT + 1) return at_val(t->ch[(k >> (HEIGHT - t->len)) & 1], k);\n  return\
    \ t->val;\n }\n bool is_null(np &t, const id_t &k) {\n  if (!t || (k >> ((HEIGHT\
    \ + 1) - t->len)) != t->bits) return true;\n  if (t->len == HEIGHT + 1) return\
    \ false;\n  return is_null(t->ch[(k >> (HEIGHT - t->len)) & 1], k);\n }\n T get_val(np\
    \ &t, const id_t &k) {\n  if (!t || (k >> ((HEIGHT + 1) - t->len)) != t->bits)\
    \ return def_val();\n  if (t->len == HEIGHT + 1) return t->val;\n  return get_val(t->ch[(k\
    \ >> (HEIGHT - t->len)) & 1], k);\n }\n template <bool last> static inline T calc_op(np\
    \ &t, const T &v) {\n  if constexpr (last) return M::op((t ? t->val : def_val()),\
    \ v);\n  else return M::op(v, (t ? t->val : def_val()));\n }\n template <bool\
    \ last> static inline bool is_in(const id_t &m, const id_t &k) {\n  if constexpr\
    \ (last) return k <= m;\n  else return m <= k;\n }\n static inline np next(np\
    \ &t, const uint8_t &h, const bool &f) {\n  if (!t) return nullptr;\n  uint8_t\
    \ len= h + t->len - (HEIGHT + 1);\n  if (!len) return t->ch[f];\n  return (f ==\
    \ ((t->bits >> (len - 1)) & 1)) ? t : nullptr;\n }\n template <bool last, class\
    \ C, std::size_t N> static id_t find(const id_t &k, std::array<id_t, 2> b, const\
    \ id_t &bias, uint8_t h, const C &check, std::array<np, N> &ts, std::array<T,\
    \ N> &sums) {\n  static_assert(monoid_v<M>, \"\\\"find\\\" is not available\\\
    n\");\n  static std::array<T, N> sums2;\n  if (std::all_of(ts.begin(), ts.end(),\
    \ [](np t) { return !t; })) return -1;\n  if (!h) {\n   for (std::size_t i= N;\
    \ i--;) sums[i]= calc_op<last>(ts[i], sums[i]);\n   return std::apply(check, sums)\
    \ ? std::get<last>(b) : -1;\n  } else if (is_in<last>(k, b[0])) {\n   for (std::size_t\
    \ i= N; i--;) sums2[i]= calc_op<last>(ts[i], sums[i]);\n   if (!std::apply(check,\
    \ sums2)) return sums= std::move(sums2), -1;\n  }\n  std::array<np, N> ss;\n \
    \ id_t m= (b[0] + b[1]) >> 1;\n  bool flg= (bias >> (h - 1)) & 1;\n  if (!is_in<last>(m,\
    \ k)) {\n   for (std::size_t i= N; i--;) ss[i]= next(ts[i], h, flg);\n   id_t\
    \ ret= find<last>(k, {b[0], m}, bias, h - 1, check, ss, sums);\n   if (ret >=\
    \ 0) return ret;\n  }\n  for (std::size_t i= N; i--;) ss[i]= next(ts[i], h, !flg);\n\
    \  return find<last>(k, {m, b[1]}, bias, h - 1, check, ss, sums);\n }\npublic:\n\
    \ SegmentTree_Patricia(np t= nullptr): root(t) {}\n SegmentTree_Patricia(std::size_t\
    \ n, T val): root(build(n, 0, 1LL << HEIGHT, val)) {}\n SegmentTree_Patricia(T\
    \ *bg, T *ed): root(build(ed - bg, 0, 1LL << HEIGHT, bg)) {}\n SegmentTree_Patricia(const\
    \ std::vector<T> &ar): SegmentTree_Patricia(ar.data(), ar.data() + ar.size())\
    \ {}\n void set(id_t k, T val) { set_val(root, k, val); }\n T get(id_t k) { return\
    \ get_val(root, k); }\n bool is_null(id_t k) { return is_null(root, k); }\n T\
    \ &at(id_t k) {\n  static_assert(!monoid_v<M>, \"\\\"at\\\" is not available\\\
    n\");\n  return at_val(root, k);\n }\n template <class L= M, std::enable_if_t<monoid_v<L>,\
    \ std::nullptr_t> = nullptr> T operator[](id_t k) { return get(k); }\n template\
    \ <class L= M, std::enable_if_t<!monoid_v<L>, std::nullptr_t> = nullptr> T &operator[](id_t\
    \ k) { return at(k); }\n T prod(id_t a, id_t b, id_t bias= 0) {\n  static_assert(monoid_v<M>,\
    \ \"\\\"prod\\\" is not available\\n\");\n  return prod(root, a, b, bias);\n }\n\
    \ // find i s.t.\n //  check(prod(k,i)) == False, check(prod(k,i+1)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_first(id_t a, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n }\n template\
    \ <std::size_t N, class C> static id_t find_first(id_t a, C check, std::array<SegmentTree_Patricia,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, ts, sums);\n }\n\
    \ // find i s.t.\n //  check(prod(i+1,k)) == False, check(prod(i,k)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_last(id_t b, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, t, sum);\n }\n\
    \ template <std::size_t N, class C> static id_t find_last(id_t b, C check, std::array<SegmentTree_Patricia,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, ts, sums);\n }\n\
    \ std::vector<T> dump(id_t bg, id_t ed) {\n  std::vector<T> ret(ed - bg);\n  dump(root,\
    \ bg, ed, {0, 1LL << HEIGHT}, ret.begin(), HEIGHT);\n  return ret;\n }\n static\
    \ std::string which_available() {\n  std::string ret= \"\";\n  if constexpr (monoid_v<M>)\
    \ ret+= \"\\\"prod\\\" \\\"find\\\"\";\n  else ret+= \"\\\"at\\\" \";\n  return\
    \ ret;\n }\n};\n#line 4 \"src/Internal/ListRange.hpp\"\n#include <iterator>\n\
    #line 6 \"src/Internal/ListRange.hpp\"\n#define _LR(name, IT, CT) \\\n template\
    \ <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT; \\\
    \n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
    \ end() const { return ed; } \\\n  size_t size() const { return std::distance(bg,\
    \ ed); } \\\n  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange,\
    \ iterator, T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\ntemplate\
    \ <class T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int> p;\n size_t\
    \ size() const { return p.size() - 1; }\n ListRange<T> operator[](int i) { return\
    \ {dat.begin() + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T> operator[](int\
    \ i) const { return {dat.cbegin() + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate\
    \ <template <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
    \ ListRange<T>>, std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>,\
    \ std::ostream &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n\
    \ for (int _= 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n\
    \ return os << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int,\
    \ int> {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"src/Graph/HeavyLightDecomposition.hpp\"\
    \n#include <cassert>\n#line 5 \"src/Graph/HeavyLightDecomposition.hpp\"\nclass\
    \ HeavyLightDecomposition {\n std::vector<int> P, PP, D, I, L, R;\npublic:\n HeavyLightDecomposition()=\
    \ default;\n HeavyLightDecomposition(const Graph &g, int root= 0): HeavyLightDecomposition(g.adjacency_vertex(0),\
    \ root) {}\n HeavyLightDecomposition(const CSRArray<int> &adj, int root= 0) {\n\
    \  const int n= adj.size();\n  P.assign(n, -2), PP.resize(n), D.resize(n), I.resize(n),\
    \ L.resize(n), R.resize(n);\n  auto f= [&, i= 0, v= 0, t= 0](int r) mutable {\n\
    \   for (P[r]= -1, I[t++]= r; i < t; ++i)\n    for (int u: adj[v= I[i]])\n   \
    \  if (P[v] != u) P[I[t++]= u]= v;\n  };\n  f(root);\n  for (int r= 0; r < n;\
    \ ++r)\n   if (P[r] == -2) f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for\
    \ (int i= n, v; i--;) {\n   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+=\
    \ Z[v]; nx[P[v]] == -1) nx[P[v]]= v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n\
    \  }\n  for (int v= n; v--;) PP[v]= v;\n  for (int v: I)\n   if (nx[v] != -1)\
    \ PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]], D[v]=\
    \ D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n   int\
    \ ir= R[v]= L[v] + Z[v];\n   for (int u: adj[v])\n    if (u != P[v] && u != nx[v])\
    \ L[u]= (ir-= Z[u]);\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n  }\n  for (int\
    \ i= n; i--;) I[L[i]]= i;\n }\n int to_seq(int v) const { return L[v]; }\n int\
    \ to_vertex(int i) const { return I[i]; }\n size_t size() const { return P.size();\
    \ }\n int parent(int v) const { return P[v]; }\n int head(int v) const { return\
    \ PP[v]; }\n int root(int v) const {\n  for (v= PP[v];; v= PP[P[v]])\n   if (P[v]\
    \ == -1) return v;\n }\n bool connected(int u, int v) const { return root(u) ==\
    \ root(v); }\n // u is in v\n bool in_subtree(int u, int v) const { return L[v]\
    \ <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return R[v] - L[v];\
    \ }\n int lca(int u, int v) const {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v])\
    \ std::swap(u, v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v,\
    \ int k) const {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] + 1, v=\
    \ P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int jump(int\
    \ u, int v, int k) const {\n  if (!k) return u;\n  if (u == v) return -1;\n  if\
    \ (k == 1) return in_subtree(v, u) ? la(v, D[v] - D[u] - 1) : P[u];\n  int w=\
    \ lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n  return k > d_uw + d_vw ?\
    \ -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n }\n int depth(int v) const\
    \ { return D[v]; }\n int dist(int u, int v) const { return D[u] + D[v] - D[lca(u,\
    \ v)] * 2; }\n // half-open interval [l,r)\n std::pair<int, int> subtree(int v)\
    \ const { return {L[v], R[v]}; }\n // sequence of closed intervals [l,r]\n std::vector<std::pair<int,\
    \ int>> path(int u, int v, bool edge= 0) const {\n  std::vector<std::pair<int,\
    \ int>> up, down;\n  while (PP[u] != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(L[PP[v]],\
    \ L[v]), v= P[PP[v]];\n   else up.emplace_back(L[u], L[PP[u]]), u= P[PP[u]];\n\
    \  }\n  if (L[u] < L[v]) down.emplace_back(L[u] + edge, L[v]);\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(L[u], L[v] + edge);\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};\n#line 10 \"test/atcoder/abc133_f.Patricia.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n Graph g(N, N - 1);\n vector<int> c(N - 1), d(N\
    \ - 1);\n for (int i= 0; i < N - 1; ++i) cin >> g[i] >> c[i] >> d[i], --g[i];\n\
    \ HeavyLightDecomposition hld(g, 0);\n using PerArr= SegmentTree_Patricia<int,\
    \ true, 17>;\n vector<PerArr> Arr1(N), Arr2(N);\n vector<int> dep(N);\n auto adj=\
    \ g.adjacency_edge(0);\n for (int i= 0; i < N; ++i) {\n  int v= hld.to_vertex(i),\
    \ p= hld.parent(v);\n  for (int e: adj[v]) {\n   int u= g[e].to(v);\n   if (u\
    \ == p) continue;\n   Arr1[u]= Arr1[v], Arr2[u]= Arr2[v];\n   Arr1[u][c[e]]+=\
    \ 1, Arr2[u][c[e]]+= d[e];\n   dep[u]= dep[v] + d[e];\n  }\n }\n for (int i= 0;\
    \ i < Q; i++) {\n  int x, y, u, v;\n  cin >> x >> y >> u >> v;\n  int lca= hld.lca(--u,\
    \ --v);\n  cout << dep[u] + dep[v] - 2 * dep[lca] + y * (Arr1[u].get(x) + Arr1[v].get(x)\
    \ - 2 * Arr1[lca].get(x)) - (Arr2[u].get(x) + Arr2[v].get(x) - 2 * Arr2[lca].get(x))\
    \ << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n\n\
    // \u6C38\u7D9A\u914D\u5217(at) \u306E verify\n\n#include <iostream>\n#include\
    \ <vector>\n#include \"src/DataStructure/SegmentTree_Patricia.hpp\"\n#include\
    \ \"src/Graph/Graph.hpp\"\n#include \"src/Graph/HeavyLightDecomposition.hpp\"\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n Graph g(N, N - 1);\n vector<int> c(N - 1), d(N\
    \ - 1);\n for (int i= 0; i < N - 1; ++i) cin >> g[i] >> c[i] >> d[i], --g[i];\n\
    \ HeavyLightDecomposition hld(g, 0);\n using PerArr= SegmentTree_Patricia<int,\
    \ true, 17>;\n vector<PerArr> Arr1(N), Arr2(N);\n vector<int> dep(N);\n auto adj=\
    \ g.adjacency_edge(0);\n for (int i= 0; i < N; ++i) {\n  int v= hld.to_vertex(i),\
    \ p= hld.parent(v);\n  for (int e: adj[v]) {\n   int u= g[e].to(v);\n   if (u\
    \ == p) continue;\n   Arr1[u]= Arr1[v], Arr2[u]= Arr2[v];\n   Arr1[u][c[e]]+=\
    \ 1, Arr2[u][c[e]]+= d[e];\n   dep[u]= dep[v] + d[e];\n  }\n }\n for (int i= 0;\
    \ i < Q; i++) {\n  int x, y, u, v;\n  cin >> x >> y >> u >> v;\n  int lca= hld.lca(--u,\
    \ --v);\n  cout << dep[u] + dep[v] - 2 * dep[lca] + y * (Arr1[u].get(x) + Arr1[v].get(x)\
    \ - 2 * Arr1[lca].get(x)) - (Arr2[u].get(x) + Arr2[v].get(x) - 2 * Arr2[lca].get(x))\
    \ << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Patricia.hpp
  - src/Internal/HAS_CHECK.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/Graph/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/atcoder/abc133_f.Patricia.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 13:36:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc133_f.Patricia.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc133_f.Patricia.test.cpp
- /verify/test/atcoder/abc133_f.Patricia.test.cpp.html
title: test/atcoder/abc133_f.Patricia.test.cpp
---
