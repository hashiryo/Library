---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SplayTree.hpp
    title: Splay-Tree
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
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
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_f
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_f
  bundledCode: "#line 1 \"test/atcoder/abc256_f.SplayTree.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n// \u53CC\u5BFE \u306E\
    \ verify\n\n#include <iostream>\n#include <array>\n#line 2 \"src/Math/mod_inv.hpp\"\
    \n#include <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline\
    \ Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int\
    \ x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a\
    \ / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-=\
    \ M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r)\
    \ const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U)\
    \ \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE\
    \ MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n\
    \ CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod)\
    \ DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const\
    \ { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n)\
    \ * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2():\
    \ mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL\
    \ u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod <<\
    \ 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE\
    \ IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\n\
    private:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return (n * x) >> 84;\
    \ }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod; }\n};\nstruct\
    \ MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0)\
    \ {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    };\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n\
    \ for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x)\
    \ : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
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
    \ return dat[n];\n}\n#line 2 \"src/DataStructure/SplayTree.hpp\"\n#include <vector>\n\
    #include <string>\n#line 5 \"src/DataStructure/SplayTree.hpp\"\n#include <cstddef>\n\
    #line 3 \"src/Internal/HAS_CHECK.hpp\"\n#define HAS_CHECK(member, Dummy) \\\n\
    \ template <class tClass> struct has_##member { \\\n  template <class U, Dummy>\
    \ static std::true_type check(U *); \\\n  static std::false_type check(...); \\\
    \n  static tClass *mClass; \\\n  static const bool value= decltype(check(mClass))::value;\
    \ \\\n };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n\
    #line 8 \"src/DataStructure/SplayTree.hpp\"\ntemplate <class M, bool reversible=\
    \ false> class SplayTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n\
    \ HAS_TYPE(T);\n HAS_TYPE(E);\n template <class L> static constexpr bool semigroup_v=\
    \ std::conjunction_v<has_T<L>, has_op<L>>;\n template <class L> static constexpr\
    \ bool dual_v= std::conjunction_v<has_T<L>, has_E<L>, has_mapping<L>, has_composition<L>>;\n\
    \ template <class T, class tDerived, class F= std::nullptr_t> struct Node_B {\n\
    \  using E= F;\n  T val;\n  tDerived *ch[2], *par;\n  size_t size;\n };\n template\
    \ <class D, bool sg, bool du, bool rev> struct Node_D: Node_B<M, Node_D<D, sg,\
    \ du, rev>> {};\n template <class D> struct Node_D<D, 1, 0, 0>: Node_B<typename\
    \ M::T, Node_D<D, 1, 0, 0>> {\n  typename M::T sum;\n };\n template <class D>\
    \ struct Node_D<D, 0, 1, 0>: Node_B<typename M::T, Node_D<D, 0, 1, 0>, typename\
    \ M::E> {\n  typename M::E lazy;\n  bool lazy_flg= false;\n };\n template <class\
    \ D> struct Node_D<D, 1, 1, 0>: Node_B<typename M::T, Node_D<D, 1, 1, 0>, typename\
    \ M::E> {\n  typename M::T sum;\n  typename M::E lazy;\n  bool lazy_flg= false;\n\
    \ };\n template <class D> struct Node_D<D, 0, 0, 1>: Node_B<M, Node_D<D, 0, 0,\
    \ 1>> {\n  bool revflg= false;\n };\n template <class D> struct Node_D<D, 1, 0,\
    \ 1>: Node_B<typename M::T, Node_D<D, 1, 0, 1>> {\n  typename M::T sum, rsum;\n\
    \  bool revflg= false;\n };\n template <class D> struct Node_D<D, 0, 1, 1>: Node_B<typename\
    \ M::T, Node_D<D, 0, 1, 1>, typename M::E> {\n  typename M::E lazy;\n  bool lazy_flg=\
    \ false, revflg= false;\n };\n template <class D> struct Node_D<D, 1, 1, 1>: Node_B<typename\
    \ M::T, Node_D<D, 1, 1, 1>, typename M::E> {\n  typename M::T sum, rsum;\n  typename\
    \ M::E lazy;\n  bool lazy_flg= false, revflg= false;\n };\n using Node= Node_D<void,\
    \ semigroup_v<M>, dual_v<M>, reversible>;\n friend std::ostream &operator<<(std::ostream\
    \ &os, Node t) { return os << \"{ch[2]:(\" << t.ch[0] << \",\" << t.ch[1] << \"\
    ),par:\" << t.par << \"}\"; }\n using T= decltype(Node::val);\n using E= typename\
    \ Node::E;\n Node *root;\n static inline Node *build(const T *bg, const T *ed,\
    \ Node *par) {\n  if (bg == ed) return nullptr;\n  const T *mid= bg + (ed - bg)\
    \ / 2;\n  Node *t= new Node{*mid};\n  return t->par= par, t->ch[0]= build(bg,\
    \ mid, t), t->ch[1]= build(mid + 1, ed, t), pushup(t);\n }\n static inline Node\
    \ *build(size_t bg, size_t ed, const T &val, Node *par) {\n  if (bg == ed) return\
    \ nullptr;\n  size_t mid= bg + (ed - bg) / 2;\n  Node *t= new Node{val};\n  return\
    \ t->par= par, t->ch[0]= build(bg, mid, val, t), t->ch[1]= build(mid + 1, ed,\
    \ val, t), pushup(t);\n }\n static inline void dump(typename std::vector<T>::iterator\
    \ itr, Node *t) {\n  if (!t) return;\n  if constexpr (dual_v<M>) eval_propagate(t);\n\
    \  if constexpr (reversible) eval_toggle(t);\n  size_t sz= t->ch[0] ? t->ch[0]->size\
    \ : 0;\n  *(itr + sz)= t->val, dump(itr, t->ch[0]), dump(itr + sz + 1, t->ch[1]);\n\
    \ }\n template <bool b> static inline void helper(Node *t) {\n  if (!t->ch[b])\
    \ return;\n  t->size+= t->ch[b]->size;\n  if constexpr (semigroup_v<M>)\n   if\
    \ constexpr (b) {\n    t->sum= M::op(t->sum, t->ch[1]->sum);\n    if constexpr\
    \ (reversible) t->rsum= M::op(t->ch[1]->rsum, t->rsum);\n   } else {\n    t->sum=\
    \ M::op(t->ch[0]->sum, t->sum);\n    if constexpr (reversible) t->rsum= M::op(t->rsum,\
    \ t->ch[0]->rsum);\n   }\n }\n static inline Node *pushup(Node *t) {\n  if (!t)\
    \ return t;\n  t->size= 1;\n  if constexpr (semigroup_v<M>) {\n   t->sum= t->val;\n\
    \   if constexpr (reversible) t->rsum= t->sum;\n  }\n  return helper<0>(t), helper<1>(t),\
    \ t;\n }\n static inline void propagate(Node *t, const E &x) {\n  if (!t) return;\n\
    \  t->lazy_flg ? (M::composition(t->lazy, x), x) : t->lazy= x;\n  if constexpr\
    \ (semigroup_v<M>) {\n   M::mapping(t->sum, x, t->size);\n   if constexpr (reversible)\
    \ M::mapping(t->rsum, x, t->size);\n  }\n  M::mapping(t->val, x, 1), t->lazy_flg=\
    \ true;\n }\n static inline void toggle(Node *t) {\n  if (!t) return;\n  if constexpr\
    \ (semigroup_v<M>) std::swap(t->sum, t->rsum);\n  std::swap(t->ch[0], t->ch[1]),\
    \ t->revflg= !t->revflg;\n }\n static inline void eval_propagate(Node *t) {\n\
    \  if (t->lazy_flg) propagate(t->ch[0], t->lazy), propagate(t->ch[1], t->lazy),\
    \ t->lazy_flg= false;\n }\n static inline void eval_toggle(Node *t) {\n  if (t->revflg)\
    \ toggle(t->ch[0]), toggle(t->ch[1]), t->revflg= false;\n }\n static inline int\
    \ dir(Node *t) { return t->par->ch[1] == t; }\n static inline void rot(Node *t)\
    \ {\n  Node *p= t->par;\n  int d= dir(t);\n  if ((p->ch[d]= t->ch[!d])) p->ch[d]->par=\
    \ p;\n  t->ch[!d]= p;\n  if ((t->par= p->par)) p->par->ch[dir(p)]= t;\n  p->par=\
    \ t, pushup(p);\n }\n static inline void splay_(Node *t) {\n  if constexpr (dual_v<M>)\
    \ eval_propagate(t);\n  if constexpr (reversible) eval_toggle(t);\n  for (Node\
    \ *p= t->par; p; rot(t), p= t->par)\n   if (Node *pp= p->par; pp) rot(dir(t) ==\
    \ dir(p) ? p : t);\n  pushup(t);\n }\n static inline void splay(Node *&t, size_t\
    \ k) {\n  if (!t) return;\n  for (bool d;; t= t->ch[d]) {\n   size_t sz= t->ch[0]\
    \ ? t->ch[0]->size : 0;\n   if (sz == k) break;\n   if constexpr (dual_v<M>) eval_propagate(t);\n\
    \   if constexpr (reversible) eval_toggle(t);\n   if ((d= sz < k)) k-= sz + 1;\n\
    \  }\n  splay_(t);\n }\n static inline void between(Node *&t, size_t a, size_t\
    \ b) {\n  assert(a < b), assert(b <= t->size);\n  if (!a && b == t->size) return;\n\
    \  if (!a) splay(t, b), t= t->ch[0];\n  else if (b == t->size) splay(t, a - 1),\
    \ t= t->ch[1];\n  else splay(t, b), t->ch[0]->par= nullptr, splay(t->ch[0], a\
    \ - 1), t->ch[0]->par= t, t= t->ch[0]->ch[1];\n }\npublic:\n SplayTree(Node *t=\
    \ nullptr): root(t) {}\n SplayTree(size_t n, T val= T()) { root= build(0, n, val,\
    \ nullptr); }\n SplayTree(const T *bg, const T *ed) { root= build(bg, ed, nullptr);\
    \ }\n SplayTree(const std::vector<T> &ar): SplayTree(ar.data(), ar.data() + ar.size())\
    \ {}\n std::vector<T> dump() {\n  std::vector<T> ret(size());\n  return dump(ret.begin(),\
    \ root), ret;\n }\n static std::string which_available() {\n  std::string ret=\
    \ \"\";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"fold\\\" \";\n  else ret+=\
    \ \"\\\"at\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  if\
    \ constexpr (reversible) ret+= \"\\\"reverse\\\" \";\n  return ret;\n }\n size_t\
    \ size() { return root ? root->size : 0; }\n void clear() { root= nullptr; }\n\
    \ template <class L= M> const std::enable_if_t<semigroup_v<L>, T> &operator[](size_t\
    \ k) { return get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>,\
    \ T> &operator[](size_t k) { return at(k); }\n const T &get(size_t k) { return\
    \ splay(root, k), root->val; }\n T &at(size_t k) {\n  static_assert(!semigroup_v<M>,\
    \ \"\\\"at\\\" is not available\");\n  return splay(root, k), root->val;\n }\n\
    \ void set(size_t k, T val) { splay(root, k), root->val= val, pushup(root); }\n\
    \ T fold(size_t a, size_t b) {\n  static_assert(semigroup_v<M>, \"\\\"fold\\\"\
    \ is not available\");\n  between(root, a, b);\n  T ret= root->sum;\n  return\
    \ splay_(root), ret;\n }\n void apply(size_t a, size_t b, E x) {\n  static_assert(dual_v<M>,\
    \ \"\\\"apply\\\" is not available\");\n  between(root, a, b), propagate(root,\
    \ x), splay_(root);\n }\n void reverse(size_t a, size_t b) {\n  static_assert(reversible,\
    \ \"\\\"reverse\\\" is not available\");\n  between(root, a, b), toggle(root),\
    \ splay_(root);\n }\n std::array<SplayTree, 2> split(size_t k) {\n  assert(k <=\
    \ size());\n  if (!k) return {SplayTree(), *this};\n  if (size() == k) return\
    \ {*this, SplayTree()};\n  splay(root, k);\n  Node *l= root->ch[0];\n  root->ch[0]=\
    \ l->par= nullptr;\n  return {SplayTree(l), SplayTree(pushup(root))};\n }\n std::array<SplayTree,\
    \ 3> split3(size_t a, size_t b) {\n  auto [tmp, right]= split(b);\n  auto [left,\
    \ center]= tmp.split(a);\n  return {left, center, right};\n }\n SplayTree &operator+=(SplayTree\
    \ rhs) {  // merge\n  if (!root) root= rhs.root;\n  else if (rhs.root) splay(root,\
    \ root->size - 1), root->ch[1]= rhs.root, rhs.root->par= root, pushup(root);\n\
    \  return *this;\n }\n SplayTree &operator+(SplayTree rhs) { return *this+= rhs;\
    \ }\n void push_back(T val) { insert(size(), val); }\n void push_front(T val)\
    \ { insert(0, val); }\n void insert(size_t k, T val) {\n  assert(k <= size());\n\
    \  auto [l, r]= split(k);\n  *this= l + SplayTree(pushup(new Node{val, {nullptr,\
    \ nullptr}, nullptr})) + r;\n }\n T pop_back() { return erase(root->size - 1);\
    \ }\n T pop_front() { return erase(0); }\n T erase(size_t k) {\n  assert(root\
    \ && k < root->size);\n  auto [l, c, r]= split3(k, k + 1);\n  return *this= l\
    \ + r, c.root->val;\n }\n};\n#line 9 \"test/atcoder/abc256_f.SplayTree.test.cpp\"\
    \nusing namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct Mono {\n struct\
    \ T {\n  Mint val, coef[2];\n  T()= default;\n  T(Mint id, Mint v): val(v), coef{(id\
    \ + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n };\n using E= array<Mint, 3>;\n\
    \ static void mapping(T &x, const E &mapp, int) { x.val+= mapp[0] * x.coef[0]\
    \ - mapp[1] * x.coef[1] + mapp[2]; }\n static void composition(E &pre, const E\
    \ &suf) { pre[0]+= suf[0], pre[1]+= suf[1], pre[2]+= suf[2]; }\n};\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, Q;\n cin >> N >> Q;\n\
    \ Mint A[N], D[N];\n for (int i= 0; i < N; i++) cin >> A[i], D[i]= A[i];\n for\
    \ (int j= 0; j < 3; j++)\n  for (int i= 1; i < N; i++) D[i]+= D[i - 1];\n SplayTree<Mono>\
    \ spt(N);\n for (int i= 0; i < N; i++) spt.set(i, {i, D[i]});\n while (Q--) {\n\
    \  int op, x;\n  cin >> op >> x, x--;\n  if (op == 1) {\n   Mint v;\n   cin >>\
    \ v, v-= A[x], A[x]+= v;\n   spt.apply(x, N, {v, v * x, v * x * x / 2});\n  }\
    \ else {\n   cout << spt[x].val << '\\n';\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n\
    // \u53CC\u5BFE \u306E verify\n\n#include <iostream>\n#include <array>\n#include\
    \ \"src/Math/ModInt.hpp\"\n#include \"src/DataStructure/SplayTree.hpp\"\nusing\
    \ namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct Mono {\n struct T {\n\
    \  Mint val, coef[2];\n  T()= default;\n  T(Mint id, Mint v): val(v), coef{(id\
    \ + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n };\n using E= array<Mint, 3>;\n\
    \ static void mapping(T &x, const E &mapp, int) { x.val+= mapp[0] * x.coef[0]\
    \ - mapp[1] * x.coef[1] + mapp[2]; }\n static void composition(E &pre, const E\
    \ &suf) { pre[0]+= suf[0], pre[1]+= suf[1], pre[2]+= suf[2]; }\n};\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, Q;\n cin >> N >> Q;\n\
    \ Mint A[N], D[N];\n for (int i= 0; i < N; i++) cin >> A[i], D[i]= A[i];\n for\
    \ (int j= 0; j < 3; j++)\n  for (int i= 1; i < N; i++) D[i]+= D[i - 1];\n SplayTree<Mono>\
    \ spt(N);\n for (int i= 0; i < N; i++) spt.set(i, {i, D[i]});\n while (Q--) {\n\
    \  int op, x;\n  cin >> op >> x, x--;\n  if (op == 1) {\n   Mint v;\n   cin >>\
    \ v, v-= A[x], A[x]+= v;\n   spt.apply(x, N, {v, v * x, v * x * x / 2});\n  }\
    \ else {\n   cout << spt[x].val << '\\n';\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/DataStructure/SplayTree.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/atcoder/abc256_f.SplayTree.test.cpp
  requiredBy: []
  timestamp: '2023-10-25 00:54:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc256_f.SplayTree.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256_f.SplayTree.test.cpp
- /verify/test/atcoder/abc256_f.SplayTree.test.cpp.html
title: test/atcoder/abc256_f.SplayTree.test.cpp
---