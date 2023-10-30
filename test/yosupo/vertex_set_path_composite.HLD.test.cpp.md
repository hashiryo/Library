---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':question:'
    path: src/DataStructure/SegmentTree.hpp
    title: Segment-Tree
  - icon: ':question:'
    path: src/Graph/Tree.hpp
    title: "\u6728"
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/vertex_set_path_composite.HLD.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\n#line 2 \"src/Math/mod_inv.hpp\"\
    \n#include <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline\
    \ Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int\
    \ x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a\
    \ / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n \
    \ if (l+= r; l >= M) l-= M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n\
    \ CE IL U diff(U l, U r) const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return\
    \ l; \\\n }\n#define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static\
    \ CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\n\
    template <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
    \ mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod)\
    \ % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r);\
    \ }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const\
    \ { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n\
    \ }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE\
    \ u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n))\
    \ : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod -\
    \ ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na():\
    \ mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const {\
    \ return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\n\
    struct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n\
    \ CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m\
    \ - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64\
    \ quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const\
    \ { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64\
    \ mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) <<\
    \ 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n\
    \ PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n)\
    \ { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n)\
    \ const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return\
    \ (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) *\
    \ mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0),\
    \ mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m\
    \ << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, enable_if_t<is_modint_v<T> && !is_same_v<T,\
    \ MInt>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod))\
    \ {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 3 \"src/Graph/Tree.hpp\"\n#include <cstddef>\n#line\
    \ 5 \"src/Graph/Tree.hpp\"\n#include <array>\n#include <tuple>\n#include <numeric>\n\
    #line 3 \"src/DataStructure/CsrArray.hpp\"\n#include <iterator>\ntemplate <class\
    \ T> struct ListRange {\n using Iterator= typename std::vector<T>::const_iterator;\n\
    \ Iterator bg, ed;\n Iterator begin() const { return bg; }\n Iterator end() const\
    \ { return ed; }\n size_t size() const { return std::distance(bg, ed); }\n const\
    \ T &operator[](int i) const { return bg[i]; }\n};\ntemplate <class T> class CsrArray\
    \ {\n std::vector<T> csr;\n std::vector<int> pos;\npublic:\n CsrArray()= default;\n\
    \ CsrArray(const std::vector<T> &c, const std::vector<int> &p): csr(c), pos(p)\
    \ {}\n size_t size() const { return pos.size() - 1; }\n const ListRange<T> operator[](int\
    \ i) const { return {csr.cbegin() + pos[i], csr.cbegin() + pos[i + 1]}; }\n};\n\
    #line 10 \"src/Graph/Tree.hpp\"\ntemplate <class Cost= void> class Tree {\n template\
    \ <class D, class T> struct Edge_B {\n  int to;\n  T cost;\n  operator int() const\
    \ { return to; }\n };\n template <class D> struct Edge_B<D, void> {\n  int to;\n\
    \  operator int() const { return to; }\n };\n using Edge= Edge_B<void, Cost>;\n\
    \ std::vector<std::conditional_t<std::is_same_v<Cost, void>, std::pair<int, int>,\
    \ std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n std::vector<int> P,\
    \ PP, D, I, L, R, pos;\npublic:\n Tree(int n): P(n, -2) {}\n template <class T=\
    \ Cost, std::enable_if_t<std::is_same_v<T, void>, std::nullptr_t> = nullptr> void\
    \ add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u); }\n template\
    \ <class T, std::enable_if_t<std::is_convertible_v<T, Cost>, std::nullptr_t> =\
    \ nullptr> void add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, d); }\n void build(int root= 0) {\n  size_t n= P.size();\n  I.resize(n),\
    \ PP.resize(n), std::iota(PP.begin(), PP.end(), 0), D.assign(n, 0), L.assign(n,\
    \ 0), R.assign(n, 0), pos.resize(n + 1), g.resize(es.size());\n  for (const auto\
    \ &e: es) ++pos[std::get<0>(e)];\n  std::partial_sum(pos.begin(), pos.end(), pos.begin());\n\
    \  if constexpr (std::is_same_v<Cost, void>)\n   for (const auto &[f, t]: es)\
    \ g[--pos[f]]= {t};\n  else\n   for (const auto &[f, t, c]: es) g[--pos[f]]= {t,\
    \ c};\n  auto f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]=\
    \ r; i < t; ++i)\n    for (int u: operator[](v= I[i]))\n     if (P[v] != u) P[I[t++]=\
    \ u]= v;\n  };\n  f(root);\n  for (size_t r= 0; r < n; ++r)\n   if (P[r] == -2)\
    \ f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n\
    \   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]=\
    \ v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n   if (nx[v]\
    \ != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: operator[](v))\n    if (u != P[v]\
    \ && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n \
    \ }\n  for (int i= n; i--;) I[L[i]]= i;\n }\n size_t size() const { return P.size();\
    \ }\n const ListRange<Edge> operator[](int v) const { return {g.cbegin() + pos[v],\
    \ g.cbegin() + pos[v + 1]}; }\n int depth(int v) const { return D[v]; }\n int\
    \ to_seq(int v) const { return L[v]; }\n int to_node(int i) const { return I[i];\
    \ }\n int parent(int v) const { return P[v]; }\n int root(int v) const {\n  for\
    \ (v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n bool connected(int\
    \ u, int v) const { return root(u) == root(v); }\n int lca(int u, int v) const\
    \ {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u, v);\n   if (PP[u]\
    \ == PP[v]) return u;\n  }\n }\n int la(int v, int k) const {\n  assert(k <= D[v]);\n\
    \  for (int u;; k-= L[v] - L[u] + 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]])\
    \ return I[L[v] - k];\n }\n int jump(int u, int v, int k) const {\n  if (!k) return\
    \ u;\n  if (u == v) return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v,\
    \ D[v] - D[u] - 1) : P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v]\
    \ - D[w];\n  return k > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw +\
    \ d_vw - k);\n }\n int dist(int u, int v) const { return depth(u) + depth(v) -\
    \ depth(lca(u, v)) * 2; }\n // u is in v\n bool in_subtree(int u, int v) const\
    \ { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return\
    \ R[v] - L[v]; }\n // half-open interval\n std::array<int, 2> subtree(int v) const\
    \ { return std::array{L[v], R[v]}; }\n // sequence of closed intervals\n template\
    \ <bool edge= 0> std::vector<std::array<int, 2>> path(int u, int v) const {\n\
    \  std::vector<std::array<int, 2>> up, down;\n  while (PP[u] != PP[v]) {\n   if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}), v= P[PP[v]];\n\
    \   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n  }\n  if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};\n#line 4 \"src/DataStructure/SegmentTree.hpp\"\
    \ntemplate <typename M> struct SegmentTree {\n using T= typename M::T;\n SegmentTree()\
    \ {}\n SegmentTree(int n_): n(n_), dat(n << 1, M::ti()) {}\n SegmentTree(int n_,\
    \ T v): n(n_), dat(n << 1, M::ti()) {\n  for (int i= n; i--;) dat[i + n]= v;\n\
    \  rebuild();\n }\n SegmentTree(const std::vector<T> &v): n(v.size()), dat(n <<\
    \ 1, M::ti()) {\n  for (int i= n; i--;) dat[i + n]= v[i];\n  rebuild();\n }\n\
    \ void set(int k, T x) {\n  for (dat[k+= n]= x; k>>= 1;) dat[k]= M::op(dat[(k\
    \ << 1) | 0], dat[(k << 1) | 1]);\n }\n void unsafe_set(int k, T x) { dat[k +\
    \ n]= x; }\n void rebuild() {\n  for (int i= n; --i;) dat[i]= M::op(dat[i << 1\
    \ | 0], dat[i << 1 | 1]);\n }\n void clear() { fill(dat.begin(), dat.end(), M::ti());\
    \ }\n inline T fold(int l, int r) const {  //[l,r)\n  T vl= M::ti(), vr= M::ti();\n\
    \  for (int a= l + n, b= r + n; a < b; a>>= 1, b>>= 1) {\n   if (a & 1) vl= M::op(vl,\
    \ dat[a++]);\n   if (b & 1) vr= M::op(dat[--b], vr);\n  }\n  return M::op(vl,\
    \ vr);\n }\n T operator[](const int &k) const { return dat[k + n]; }\n template\
    \ <bool last> static inline T calc_op(const T &v, const T &d) {\n  if constexpr\
    \ (last) return M::op(d, v);\n  else return M::op(v, d);\n }\n // Case 0. find\
    \ i s.t check(fold(k,i)) == False, check(fold(k,i+1)) == True\n // Case 1. find\
    \ i s.t check(fold(i+1,b)) == False, check(fold(i,b)) == True\n // return -1 if\
    \ not found\n template <bool last, class C> int find(const C &check, int k) const\
    \ {\n  assert(!check(M::ti()));\n  std::vector<int> id[2];\n  int a= n + (k &\
    \ -(!last)), b= n + n + ((k - n) & -(last));\n  for (; a < b; a>>= 1, b>>= 1)\
    \ {\n   if (a & 1) id[0].push_back(a++);\n   if (b & 1) id[1].push_back(--b);\n\
    \  }\n  id[last].insert(id[last].end(), id[!last].rbegin(), id[!last].rend());\n\
    \  T val= M::ti();\n  for (int i: id[last]) {\n   if (T tmp= calc_op<last>(val,\
    \ dat[i]); check(tmp)) {\n    while (i < n)\n     if (tmp= calc_op<last>(val,\
    \ dat[i= i << 1 | last]); !check(tmp)) val= tmp, i-= last * 2 - 1;\n    return\
    \ i - n + last;\n   } else val= tmp;\n  }\n  return -1;\n }\nprivate:\n const\
    \ int n;\n std::vector<T> dat;\n};\n#line 8 \"test/yosupo/vertex_set_path_composite.HLD.test.cpp\"\
    \nusing namespace std;\nusing Mint= ModInt<998244353>;\nstruct Mono {\n using\
    \ T= array<Mint, 2>;\n static T ti() { return {Mint(1), Mint()}; }\n static T\
    \ op(const T &l, const T &r) { return {l[0] * r[0], l[1] * r[0] + r[1]}; }\n};\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >>\
    \ N >> Q;\n Mint a[N], b[N];\n for (int i= 0; i < N; ++i) cin >> a[i] >> b[i];\n\
    \ Tree tree(N);\n for (int i= 0; i < N - 1; ++i) {\n  int u, v;\n  cin >> u >>\
    \ v;\n  tree.add_edge(u, v);\n }\n tree.build(0);\n vector<typename Mono::T> vec(N);\n\
    \ for (int v= 0; v < N; ++v) vec[tree.to_seq(v)]= {a[v], b[v]};\n SegmentTree<Mono>\
    \ seg1(vec);\n reverse(vec.begin(), vec.end());\n SegmentTree<Mono> seg2(vec);\n\
    \ while (Q--) {\n  bool op;\n  cin >> op;\n  if (op) {\n   int u, v;\n   Mint\
    \ x;\n   cin >> u >> v >> x;\n   auto f= Mono::ti();\n   for (auto [s, t]: tree.path(u,\
    \ v)) f= Mono::op(f, s < t ? seg1.fold(s, t + 1) : seg2.fold(N - s - 1, N - t));\n\
    \   cout << f[0] * x + f[1] << '\\n';\n  } else {\n   int p;\n   Mint c, d;\n\
    \   cin >> p >> c >> d;\n   int i= tree.to_seq(p);\n   seg1.set(i, {c, d});\n\
    \   seg2.set(N - i - 1, {c, d});\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/Graph/Tree.hpp\"\n#include \"src/DataStructure/SegmentTree.hpp\"\
    \nusing namespace std;\nusing Mint= ModInt<998244353>;\nstruct Mono {\n using\
    \ T= array<Mint, 2>;\n static T ti() { return {Mint(1), Mint()}; }\n static T\
    \ op(const T &l, const T &r) { return {l[0] * r[0], l[1] * r[0] + r[1]}; }\n};\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >>\
    \ N >> Q;\n Mint a[N], b[N];\n for (int i= 0; i < N; ++i) cin >> a[i] >> b[i];\n\
    \ Tree tree(N);\n for (int i= 0; i < N - 1; ++i) {\n  int u, v;\n  cin >> u >>\
    \ v;\n  tree.add_edge(u, v);\n }\n tree.build(0);\n vector<typename Mono::T> vec(N);\n\
    \ for (int v= 0; v < N; ++v) vec[tree.to_seq(v)]= {a[v], b[v]};\n SegmentTree<Mono>\
    \ seg1(vec);\n reverse(vec.begin(), vec.end());\n SegmentTree<Mono> seg2(vec);\n\
    \ while (Q--) {\n  bool op;\n  cin >> op;\n  if (op) {\n   int u, v;\n   Mint\
    \ x;\n   cin >> u >> v >> x;\n   auto f= Mono::ti();\n   for (auto [s, t]: tree.path(u,\
    \ v)) f= Mono::op(f, s < t ? seg1.fold(s, t + 1) : seg2.fold(N - s - 1, N - t));\n\
    \   cout << f[0] * x + f[1] << '\\n';\n  } else {\n   int p;\n   Mint c, d;\n\
    \   cin >> p >> c >> d;\n   int i= tree.to_seq(p);\n   seg1.set(i, {c, d});\n\
    \   seg2.set(N - i - 1, {c, d});\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Graph/Tree.hpp
  - src/DataStructure/CsrArray.hpp
  - src/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_set_path_composite.HLD.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 13:15:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/vertex_set_path_composite.HLD.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_set_path_composite.HLD.test.cpp
- /verify/test/yosupo/vertex_set_path_composite.HLD.test.cpp.html
title: test/yosupo/vertex_set_path_composite.HLD.test.cpp
---
