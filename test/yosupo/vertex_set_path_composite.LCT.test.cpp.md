---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/LinkCutTree.hpp
    title: Link-Cut-Tree
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/detection_idiom.hpp
    title: detection idiom
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
  bundledCode: "#line 1 \"test/yosupo/vertex_set_path_composite.LCT.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n#include\
    \ <iostream>\n#include <algorithm>\n#include <array>\n#line 2 \"src/Math/mod_inv.hpp\"\
    \n#include <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline\
    \ Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int\
    \ x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a\
    \ / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return\
    \ l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l,\
    \ U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static\
    \ CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\
    \n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 3 \"src/DataStructure/LinkCutTree.hpp\"\
    \n#include <vector>\n#include <string>\n#include <cstddef>\n#line 3 \"src/Internal/detection_idiom.hpp\"\
    \n#define _DETECT_BOOL(name, ...) \\\n template <class, class= void> struct name:\
    \ std::false_type {}; \\\n template <class T> struct name<T, std::void_t<__VA_ARGS__>>:\
    \ std::true_type {}; \\\n template <class T> static constexpr bool name##_v= name<T>::value\n\
    #define _DETECT_TYPE(name, type1, type2, ...) \\\n template <class T, class= void>\
    \ struct name { \\\n  using type= type2; \\\n }; \\\n template <class T> struct\
    \ name<T, std::void_t<__VA_ARGS__>> { \\\n  using type= type1; \\\n }\n#line 8\
    \ \"src/DataStructure/LinkCutTree.hpp\"\ntemplate <class M= void> class LinkCutTree\
    \ {\n _DETECT_BOOL(semigroup, typename T::T, decltype(&T::op));\n _DETECT_BOOL(dual,\
    \ typename T::T, typename T::E, decltype(&T::mp), decltype(&T::cp));\n _DETECT_BOOL(commute,\
    \ typename T::commute);\n _DETECT_TYPE(myself_or_T, typename T::T, T, typename\
    \ T::T);\n _DETECT_TYPE(nullptr_or_E, typename T::E, std::nullptr_t, typename\
    \ T::E);\n using T= std::conditional_t<std::is_void_v<M>, std::nullptr_t, typename\
    \ myself_or_T<M>::type>;\n using E= typename nullptr_or_E<M>::type;\n struct NodeB\
    \ {\n  int ch[2]= {-1, -1}, par= -1;\n  bool revf= 0;\n };\n template <class D,\
    \ class A> struct NodeV: NodeB {\n  T val;\n };\n template <class D> struct NodeV<D,\
    \ void>: NodeB {};\n template <class D, bool du> struct NodeD: NodeV<D, M> {};\n\
    \ template <class D> struct NodeD<D, 1>: NodeV<D, M> {\n  E laz;\n  bool lazf=\
    \ 0;\n };\n template <class D, bool sg, bool com> struct NodeS: NodeD<D, dual_v<M>>\
    \ {};\n template <class D> struct NodeS<D, 1, 1>: NodeD<D, dual_v<M>> {\n  T sum;\n\
    \ };\n template <class D> struct NodeS<D, 1, 0>: NodeD<D, dual_v<M>> {\n  T sum,\
    \ rsum;\n };\n using Node= NodeS<void, semigroup_v<M>, commute_v<M>>;\n std::vector<Node>\
    \ n;\n inline void update(int i) {\n  n[i].sum= n[i].val;\n  if constexpr (!commute_v<M>)\
    \ n[i].rsum= n[i].val;\n  if (int l= n[i].ch[0]; l != -1) {\n   n[i].sum= M::op(n[l].sum,\
    \ n[i].sum);\n   if constexpr (!commute_v<M>) n[i].rsum= M::op(n[i].rsum, n[l].rsum);\n\
    \  }\n  if (int r= n[i].ch[1]; r != -1) {\n   n[i].sum= M::op(n[i].sum, n[r].sum);\n\
    \   if constexpr (!commute_v<M>) n[i].rsum= M::op(n[r].rsum, n[i].rsum);\n  }\n\
    \ }\n inline void propagate(int i, const E &x) {\n  if (i == -1) return;\n  if\
    \ (n[i].lazf) M::cp(n[i].laz, x);\n  else n[i].laz= x;\n  if constexpr (semigroup_v<M>)\
    \ {\n   M::mp(n[i].sum, x);\n   if constexpr (!commute_v<M>) M::mp(n[i].rsum,\
    \ x);\n  }\n  M::mp(n[i].val, x), n[i].lazf= 1;\n }\n inline void toggle(int i)\
    \ {\n  if (i == -1) return;\n  std::swap(n[i].ch[0], n[i].ch[1]);\n  if constexpr\
    \ (semigroup_v<M> && !commute_v<M>) std::swap(n[i].sum, n[i].rsum);\n  n[i].revf^=\
    \ 1;\n }\n inline void push(int i) {\n  if (n[i].revf) toggle(n[i].ch[0]), toggle(n[i].ch[1]),\
    \ n[i].revf= 0;\n  if constexpr (dual_v<M>)\n   if (n[i].lazf) propagate(n[i].ch[0],\
    \ n[i].laz), propagate(n[i].ch[1], n[i].laz), n[i].lazf= 0;\n }\n inline int dir(int\
    \ i) {\n  if (int p= n[i].par; p != -1) {\n   if (n[p].ch[0] == i) return 0;\n\
    \   if (n[p].ch[1] == i) return 1;\n  }\n  return 2;\n }\n inline void rot(int\
    \ i) {\n  int p= n[i].par, d= n[p].ch[1] == i;\n  if (int c= n[p].ch[d]= std::exchange(n[i].ch[!d],\
    \ p); c != -1) n[c].par= p;\n  if (d= dir(p); d < 2) n[n[p].par].ch[d]= i;\n \
    \ n[i].par= std::exchange(n[p].par, i);\n  if constexpr (semigroup_v<M>) update(p);\n\
    \ }\n inline void splay(int i) {\n  push(i);\n  for (int d; d= dir(i), d < 2;\
    \ rot(i))\n   if (int p= n[i].par, c= dir(p), pp= n[p].par; c < 2) push(pp), push(p),\
    \ push(i), rot(d == c ? p : i);\n   else push(p), push(i);\n  if constexpr (semigroup_v<M>)\
    \ update(i);\n }\n inline int expose(int i) {\n  int r= -1;\n  for (int p= i;\
    \ p != -1; r= p, p= n[p].par) {\n   splay(p), n[p].ch[1]= r;\n   if constexpr\
    \ (semigroup_v<M>) update(p);\n  }\n  return splay(i), r;\n }\npublic:\n LinkCutTree(size_t\
    \ sz): n(sz) {}\n LinkCutTree(size_t sz, T val): n(sz) {\n  for (int i= sz; i--;)\
    \ n[i].val= val;\n }\n void evert(int k) { expose(k), toggle(k), push(k); }\n\
    \ void link(int c, int p) {\n  evert(c), expose(p), assert(n[c].par == -1), n[p].ch[1]=\
    \ c, n[c].par= p;\n  if constexpr (semigroup_v<M>) update(p);\n }\n void cut(int\
    \ c, int p) {\n  evert(c), expose(p), assert(n[c].ch[0] == p), n[c].ch[0]= n[p].par=\
    \ -1;\n  if constexpr (semigroup_v<M>) update(c);\n }\n int root(int x) {\n  for\
    \ (expose(x);; x= n[x].ch[0])\n   if (push(x), n[x].ch[0] == -1) return splay(x),\
    \ x;\n }\n int parent(int x) {\n  if (expose(x), x= n[x].ch[0]; x == -1) return\
    \ -1;\n  for (;; x= n[x].ch[1])\n   if (push(x), n[x].ch[1] == -1) return splay(x),\
    \ x;\n }\n int lca(int x, int y) { return x == y ? x : (expose(x), y= expose(y),\
    \ n[x].par == -1) ? -1 : y; }\n const T &get(int k) {\n  static_assert(!std::is_void_v<M>,\
    \ \"\\\"get\\\" is not available\\n\");\n  return expose(k), n[k].val;\n }\n T\
    \ &at(int k) {\n  static_assert(!std::is_void_v<M> && !semigroup_v<M>, \"\\\"\
    at\\\" is not available\\n\");\n  return expose(k), n[k].val;\n }\n template <class\
    \ L= M> const std::enable_if_t<semigroup_v<L>, T> &operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n void set(int k, const T &v) {\n  static_assert(!std::is_void_v<M>,\
    \ \"\\\"set\\\" is not available\\n\");\n  expose(k), n[k].val= v;\n  if constexpr\
    \ (semigroup_v<M>) update(k);\n }\n void mul(int k, const T &v) {\n  static_assert(semigroup_v<M>\
    \ && commute_v<M>, \"\\\"mul\\\" is not available\\n\");\n  expose(k), n[k].val=\
    \ M::op(n[k].val, v), update(k);\n }\n // [a,b] closed section\n T prod(int a,\
    \ int b) {\n  static_assert(semigroup_v<M>, \"\\\"prod\\\" is not available\\\
    n\");\n  return a == b ? get(a) : (evert(a), expose(b), assert(n[a].par != -1),\
    \ n[b].sum);\n }\n // [a,b] closed section\n void apply(int a, int b, const E\
    \ &v) {\n  static_assert(dual_v<M>, \"\\\"apply\\\" is not available\\n\");\n\
    \  evert(a), expose(b), assert(a == b || n[a].par != -1), propagate(b, v), push(b);\n\
    \ }\n static std::string which_unavailable() {\n  std::string ret= \"\";\n  if\
    \ constexpr (semigroup_v<M>) ret+= \"\\\"at\\\" \";\n  else ret+= \"\\\"prod\\\
    \" \";\n  if constexpr (!semigroup_v<M> || !commute_v<M>) ret+= \"\\\"mul\\\"\
    \ \";\n  if constexpr (!dual_v<M>) ret+= \"\\\"apply\\\" \";\n  if constexpr (std::is_void_v<M>)\
    \ ret+= \"\\\"get\\\" \\\"set\\\" \";\n  return ret;\n }\n};\n#line 7 \"test/yosupo/vertex_set_path_composite.LCT.test.cpp\"\
    \nusing namespace std;\nusing Mint= ModInt<998244353>;\nstruct Mono {\n using\
    \ T= array<Mint, 2>;\n static T op(const T &l, const T &r) { return {l[0] * r[0],\
    \ l[1] * r[0] + r[1]}; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n LinkCutTree<Mono> lct(N);\n for (int i= 0; i <\
    \ N; ++i) {\n  Mint a, b;\n  cin >> a >> b;\n  lct.set(i, {a, b});\n }\n for (int\
    \ i= 0, u, v; i < N - 1; ++i) cin >> u >> v, lct.link(u, v);\n\n while (Q--) {\n\
    \  bool op;\n  cin >> op;\n  if (op) {\n   int u, v;\n   Mint x;\n   cin >> u\
    \ >> v >> x;\n   auto [a, b]= lct.prod(u, v);\n   cout << a * x + b << '\\n';\n\
    \  } else {\n   int p;\n   Mint c, d;\n   cin >> p >> c >> d;\n   lct.set(p, {c,\
    \ d});\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include <iostream>\n#include <algorithm>\n#include <array>\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/DataStructure/LinkCutTree.hpp\"\nusing namespace std;\nusing\
    \ Mint= ModInt<998244353>;\nstruct Mono {\n using T= array<Mint, 2>;\n static\
    \ T op(const T &l, const T &r) { return {l[0] * r[0], l[1] * r[0] + r[1]}; }\n\
    };\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin\
    \ >> N >> Q;\n LinkCutTree<Mono> lct(N);\n for (int i= 0; i < N; ++i) {\n  Mint\
    \ a, b;\n  cin >> a >> b;\n  lct.set(i, {a, b});\n }\n for (int i= 0, u, v; i\
    \ < N - 1; ++i) cin >> u >> v, lct.link(u, v);\n\n while (Q--) {\n  bool op;\n\
    \  cin >> op;\n  if (op) {\n   int u, v;\n   Mint x;\n   cin >> u >> v >> x;\n\
    \   auto [a, b]= lct.prod(u, v);\n   cout << a * x + b << '\\n';\n  } else {\n\
    \   int p;\n   Mint c, d;\n   cin >> p >> c >> d;\n   lct.set(p, {c, d});\n  }\n\
    \ }\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/DataStructure/LinkCutTree.hpp
  - src/Internal/detection_idiom.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_set_path_composite.LCT.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 13:36:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/vertex_set_path_composite.LCT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_set_path_composite.LCT.test.cpp
- /verify/test/yosupo/vertex_set_path_composite.LCT.test.cpp.html
title: test/yosupo/vertex_set_path_composite.LCT.test.cpp
---
