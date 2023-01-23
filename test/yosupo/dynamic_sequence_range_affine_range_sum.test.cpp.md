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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n// set_balance \u3057\u306A\u3044\u3068 \u30B9\u30BF\u30C3\u30AF\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\n// \uFF08\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    \ wrong_avl_killer_01\uFF09\n\n#include <iostream>\n#line 2 \"src/DataStructure/SplayTree.hpp\"\
    \n#include <vector>\n#include <string>\n#include <tuple>\n#include <cstddef>\n\
    #include <cassert>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define HAS_CHECK(member, Dummy) \\\n template <class tClass> struct has_##member\
    \ { \\\n  template <class U, Dummy> static std::true_type check(U *); \\\n  static\
    \ std::false_type check(...); \\\n  static tClass *mClass; \\\n  static const\
    \ bool value= decltype(check(mClass))::value; \\\n };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#line 8 \"src/DataStructure/SplayTree.hpp\"\
    \ntemplate <class M, bool reversible= false> class SplayTree {\n HAS_MEMBER(op);\n\
    \ HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n HAS_TYPE(T);\n HAS_TYPE(E);\n\
    \ template <class L> using semigroup= std::conjunction<has_T<L>, has_op<L>>;\n\
    \ template <class L> using dual= std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n template <class T, class tDerived, class F= std::nullptr_t>\
    \ struct Node_B {\n  using E= F;\n  T val;\n  tDerived *ch[2];\n  std::size_t\
    \ size;\n };\n template <bool sg_, bool du_, bool rev_, typename tEnable= void>\
    \ struct Node_D: Node_B<M, Node_D<sg_, du_, rev_, tEnable>> {};\n template <bool\
    \ sg_, bool du_, bool rev_> struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
    \ && !du_ && !rev_>>: Node_B<typename M::T, Node_D<sg_, du_, rev_>> { typename\
    \ M::T sum; };\n template <bool sg_, bool du_, bool rev_> struct Node_D<sg_, du_,\
    \ rev_, typename std::enable_if_t<!sg_ && du_ && !rev_>>: Node_B<typename M::T,\
    \ Node_D<sg_, du_, rev_>, typename M::E> {\n  typename M::E lazy;\n  bool lazy_flg=\
    \ false;\n };\n template <bool sg_, bool du_, bool rev_> struct Node_D<sg_, du_,\
    \ rev_, typename std::enable_if_t<sg_ && du_ && !rev_>>: Node_B<typename M::T,\
    \ Node_D<sg_, du_, rev_>, typename M::E> {\n  typename M::T sum;\n  typename M::E\
    \ lazy;\n  bool lazy_flg= false;\n };\n template <bool sg_, bool du_, bool rev_>\
    \ struct Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_ && !du_ && rev_>>:\
    \ Node_B<M, Node_D<sg_, du_, rev_>> { bool rev_flg= false; };\n template <bool\
    \ sg_, bool du_, bool rev_> struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
    \ && !du_ && rev_>>: Node_B<typename M::T, Node_D<sg_, du_, rev_>> {\n  typename\
    \ M::T sum, rsum;\n  bool rev_flg= false;\n };\n template <bool sg_, bool du_,\
    \ bool rev_> struct Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_ && du_\
    \ && rev_>>: Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename M::E> {\n\
    \  typename M::E lazy;\n  bool lazy_flg= false, rev_flg= false;\n };\n template\
    \ <bool sg_, bool du_, bool rev_> struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
    \ && du_ && rev_>>: Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename M::E>\
    \ {\n  typename M::T sum, rsum;\n  typename M::E lazy;\n  bool lazy_flg= false,\
    \ rev_flg= false;\n };\n using Node= Node_D<semigroup<M>::value, dual<M>::value,\
    \ reversible>;\n using T= decltype(Node::val);\n using E= typename Node::E;\n\
    \ Node *root;\n static inline Node *build(const T *bg, const T *ed) {\n  if (bg\
    \ == ed) return nullptr;\n  const T *mid= bg + (ed - bg) / 2;\n  return pushup(new\
    \ Node{*mid, {build(bg, mid), build(mid + 1, ed)}});\n }\n static inline Node\
    \ *build(std::size_t bg, std::size_t ed, const T &val) {\n  if (bg == ed) return\
    \ nullptr;\n  std::size_t mid= bg + (ed - bg) / 2;\n  return pushup(new Node{val,\
    \ {build(bg, mid, val), build(mid + 1, ed, val)}});\n }\n static inline void dump(typename\
    \ std::vector<T>::iterator itr, Node *t) {\n  if (!t) return;\n  if constexpr\
    \ (dual<M>::value) eval_propagate(t);\n  if constexpr (reversible) eval_toggle(t);\n\
    \  std::size_t sz= t->ch[0] ? t->ch[0]->size : 0;\n  *(itr + sz)= t->val, dump(itr,\
    \ t->ch[0]), dump(itr + sz + 1, t->ch[1]);\n }\n template <bool b> static inline\
    \ void helper(Node *&t) {\n  if (!t->ch[b]) return;\n  t->size+= t->ch[b]->size;\n\
    \  if constexpr (semigroup<M>::value)\n   if constexpr (b) {\n    t->sum= M::op(t->sum,\
    \ t->ch[1]->sum);\n    if constexpr (reversible) t->rsum= M::op(t->ch[1]->rsum,\
    \ t->rsum);\n   } else {\n    t->sum= M::op(t->ch[0]->sum, t->sum);\n    if constexpr\
    \ (reversible) t->rsum= M::op(t->rsum, t->ch[0]->rsum);\n   }\n }\n static inline\
    \ Node *pushup(Node *t) {\n  if (!t) return t;\n  t->size= 1;\n  if constexpr\
    \ (semigroup<M>::value) {\n   t->sum= t->val;\n   if constexpr (reversible) t->rsum=\
    \ t->sum;\n  }\n  return helper<0>(t), helper<1>(t), t;\n }\n static inline void\
    \ propagate(Node *t, const E &x) {\n  if (!t) return;\n  t->lazy_flg ? (M::composition(t->lazy,\
    \ x), x) : t->lazy= x;\n  if constexpr (semigroup<M>::value) {\n   M::mapping(t->sum,\
    \ x, t->size);\n   if constexpr (reversible) M::mapping(t->rsum, x, t->size);\n\
    \  }\n  M::mapping(t->val, x, 1), t->lazy_flg= true;\n }\n static inline void\
    \ toggle(Node *t) {\n  if (!t) return;\n  if constexpr (semigroup<M>::value) std::swap(t->sum,\
    \ t->rsum);\n  std::swap(t->ch[0], t->ch[1]), t->rev_flg= !t->rev_flg;\n }\n static\
    \ inline void eval_propagate(Node *t) {\n  if (t->lazy_flg) propagate(t->ch[0],\
    \ t->lazy), propagate(t->ch[1], t->lazy), t->lazy_flg= false;\n }\n static inline\
    \ void eval_toggle(Node *t) {\n  if (t->rev_flg) toggle(t->ch[0]), toggle(t->ch[1]),\
    \ t->rev_flg= false;\n }\n static inline void rot(Node *&t, bool d) {\n  Node\
    \ *s= t->ch[d];\n  t->ch[d]= s->ch[!d], s->ch[!d]= pushup(t), t= pushup(s);\n\
    \ }\n static inline void splay(Node *&t, std::size_t k) {\n  if (!t) return;\n\
    \  if constexpr (dual<M>::value) eval_propagate(t);\n  if constexpr (reversible)\
    \ eval_toggle(t);\n  std::size_t sz= t->ch[0] ? t->ch[0]->size : 0;\n  if (sz\
    \ == k) return;\n  bool d= sz < k;\n  if (d) k-= sz + 1;\n  if constexpr (dual<M>::value)\
    \ eval_propagate(t->ch[d]);\n  if constexpr (reversible) eval_toggle(t->ch[d]);\n\
    \  sz= t->ch[d]->ch[0] ? t->ch[d]->ch[0]->size : 0;\n  if (sz != k) {\n   bool\
    \ c= sz < k;\n   if (c) k-= sz + 1;\n   splay(t->ch[d]->ch[c], k);\n   c == d\
    \ ? rot(t, d) : rot(t->ch[d], !d);\n  }\n  rot(t, d);\n }\n template <class F>\
    \ void query(std::size_t a, std::size_t b, const F &f) {\n  if (size() == b) {\n\
    \   a-- ? (splay(root, a), f(root->ch[1]), pushup(root)) : (f(root), root);\n\
    \  } else {\n   splay(root, b);\n   a-- ? (splay(root->ch[0], a), f(root->ch[0]->ch[1]),\
    \ pushup(root->ch[0])) : (f(root->ch[0]), root->ch[0]);\n   pushup(root);\n  }\n\
    \ }\n static inline unsigned xor128() {\n  static unsigned x= 123456789, y= 362436069,\
    \ z= 521288629, w= 88675123;\n  unsigned t= (x ^ (x << 11));\n  return x= y, y=\
    \ z, z= w, (w= (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n }\npublic:\n SplayTree(Node\
    \ *t= nullptr): root(t) {}\n SplayTree(std::size_t n, T val= T()) { root= build(0,\
    \ n, val); }\n SplayTree(const T *bg, const T *ed) { root= build(bg, ed); }\n\
    \ SplayTree(const std::vector<T> &ar): SplayTree(ar.data(), ar.data() + ar.size())\
    \ {}\n std::vector<T> dump() {\n  std::vector<T> ret(size());\n  return dump(ret.begin(),\
    \ root), ret;\n }\n static std::string which_available() {\n  std::string ret=\
    \ \"\";\n  if constexpr (semigroup<M>::value) ret+= \"\\\"fold\\\" \";\n  else\
    \ ret+= \"\\\"at\\\" \";\n  if constexpr (dual<M>::value) ret+= \"\\\"apply\\\"\
    \ \";\n  if constexpr (reversible) ret+= \"\\\"reverse\\\" \";\n  return ret;\n\
    \ }\n std::size_t size() { return root ? root->size : 0; }\n void clear() { root=\
    \ nullptr; }\n template <class L= M, std::enable_if_t<semigroup<L>::value, std::nullptr_t>\
    \ = nullptr> const T &operator[](std::size_t k) { return get(k); }\n template\
    \ <class L= M, std::enable_if_t<!semigroup<L>::value, std::nullptr_t> = nullptr>\
    \ T &operator[](std::size_t k) { return at(k); }\n const T &get(std::size_t k)\
    \ { return splay(root, k), root->val; }\n T &at(std::size_t k) {\n  static_assert(!semigroup<M>::value,\
    \ \"\\\"at\\\" is not available\");\n  return splay(root, k), root->val;\n }\n\
    \ void set(std::size_t k, T val) { splay(root, k), root->val= val, pushup(root);\
    \ }\n void set_balance() {\n  if (root) splay(root, xor128() % size()), splay(root,\
    \ xor128() % size());\n }\n T fold(std::size_t a, std::size_t b) {\n  static_assert(semigroup<M>::value,\
    \ \"\\\"fold\\\" is not available\");\n  if (size() == b) {\n   return a-- ? splay(root,\
    \ a), root->ch[1]->sum : root->sum;\n  } else {\n   splay(root, b);\n   return\
    \ a-- ? (splay(root->ch[0], a), root->ch[0]->ch[1]->sum) : root->ch[0]->sum;\n\
    \  }\n }\n void apply(std::size_t a, std::size_t b, E x) {\n  static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\");\n  query(a, b, [&](Node *t) { propagate(t,\
    \ x); });\n }\n void reverse(std::size_t a, std::size_t b) {\n  static_assert(reversible,\
    \ \"\\\"reverse\\\" is not available\");\n  query(a, b, [&](Node *t) { toggle(t);\
    \ });\n }\n std::pair<SplayTree, SplayTree> split(std::size_t k) {\n  assert(k\
    \ <= size());\n  if (size() == k) return {*this, SplayTree()};\n  splay(root,\
    \ k);\n  Node *l= root->ch[0];\n  root->ch[0]= nullptr;\n  return {SplayTree(l),\
    \ SplayTree(pushup(root))};\n }\n std::tuple<SplayTree, SplayTree, SplayTree>\
    \ split3(std::size_t a, std::size_t b) {\n  auto [tmp, right]= split(b);\n  auto\
    \ [left, center]= tmp.split(a);\n  return {left, center, right};\n }\n SplayTree\
    \ &operator+=(SplayTree rhs) {  // merge\n  root ? (splay(root, root->size - 1),\
    \ root->ch[1]= rhs.root, pushup(root)) : root= rhs.root;\n  return *this;\n }\n\
    \ SplayTree &operator+(SplayTree rhs) { return *this+= rhs; }\n void push_back(T\
    \ val) { insert(size(), val); }\n void push_front(T val) { insert(0, val); }\n\
    \ void insert(std::size_t k, T val) {\n  assert(!k || (root && k <= root->size));\n\
    \  if (size() == k) {\n   root= pushup(new Node{val, {root, nullptr}});\n  } else\
    \ {\n   splay(root, k), root= new Node{val, {root->ch[0], root}};\n   root->ch[1]->ch[0]=\
    \ nullptr, pushup(root->ch[1]), pushup(root);\n  }\n }\n T pop_back() { return\
    \ erase(root->size - 1); }\n T pop_front() { return erase(0); }\n T erase(std::size_t\
    \ k) {\n  assert(root && k < root->size);\n  splay(root, k);\n  T ret= root->val;\n\
    \  splay(root->ch[1], 0);\n  if (root->ch[1]) root->ch[1]->ch[0]= root->ch[0],\
    \ root= pushup(root->ch[1]);\n  else root= root->ch[0];\n  return ret;\n }\n};\n\
    #line 4 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n\
    \ for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a / b), a= b,\
    \ b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n\
    }\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n\
    #define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n\
    \ CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n  return\
    \ l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { \\\n  if\
    \ (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n static CE\
    \ IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\n\
    \ static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n const u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n const u_t iv, r2;\n static CE u_t inv(u_t n,\
    \ int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE\
    \ IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w)\
    \ * iv) * mod) >> B); }\n};\nstruct MP_Na {\n const u32 mod;\n CE MP_Na(): mod(0){};\n\
    \ CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n const u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: const u8 s;\n const u64 x;\n CE IL u64 quo(u64 n)\
    \ const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n\
    \ - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n const u64 mod;\n\
    \ CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) /\
    \ m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64,\
    \ mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n;\
    \ }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM;\
    \ }\nprivate:\n const u64 x;\n CE IL u128 quo(const u128 &n) const { return (n\
    \ * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_D2B1 {\n const u64 mod;\n CE MP_D2B1(): mod(0), s(0), d(0),\
    \ v(0) {}\n CE MP_D2B1(u64 m): mod(m), s(__builtin_clzll(m)), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    \ const u8 s;\n const u64 d, v;\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t\
    \ x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if\
    \ (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef\
    \ PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 4 \"src/Math/ModInt.hpp\"\
    \nnamespace math_internal {\n#define CE constexpr\nstruct m_b {};\nstruct s_b:\
    \ m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\n\
    template <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\n\
    template <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n\
    };\ntemplate <class Int, class U, class B> struct MInt: public B {\n using Uint=\
    \ U;\n static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n\
    \ CE MInt(const MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n % B::md.mod)))\
    \ {}\n CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name,\
    \ op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  ret.x= op; \\\n  return\
    \ ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x, r.x))\n FUNC(operator-(const\
    \ MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const MInt& r), B::md.mul(x,\
    \ r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n#undef FUNC\n CE\
    \ MInt operator/(const MInt& r) const { return *this * r.inv(); }\n CE MInt& operator+=(const\
    \ MInt& r) { return *this= *this + r; }\n CE MInt& operator-=(const MInt& r) {\
    \ return *this= *this - r; }\n CE MInt& operator*=(const MInt& r) { return *this=\
    \ *this * r; }\n CE MInt& operator/=(const MInt& r) { return *this= *this / r;\
    \ }\n CE bool operator==(const MInt& r) const { return B::md.norm(x) == B::md.norm(r.x);\
    \ }\n CE bool operator!=(const MInt& r) const { return !(*this == r); }\n CE bool\
    \ operator<(const MInt& r) const { return B::md.norm(x) < B::md.norm(r.x); }\n\
    \ CE inline MInt inv() const { return mod_inv<Int>(val(), B::md.mod); }\n CE inline\
    \ Uint val() const { return B::md.get(x); }\n friend ostream& operator<<(ostream&\
    \ os, const MInt& r) { return os << r.val(); }\n friend istream& operator>>(istream&\
    \ is, MInt& r) {\n  i64 v;\n  return is >> v, r= MInt(v), is;\n }\nprivate:\n\
    \ Uint x;\n};\ntemplate <u64 MOD> using ModInt= conditional_t < (MOD < (1 << 30))\
    \ & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32, 31>, MOD>>, conditional_t < (MOD\
    \ < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u\
    \ << 31), MInt<int, u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2,\
    \ MOD>>, MInt<i64, u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt,\
    \ math_internal::is_modint_v, math_internal::is_staticmodint_v;\ntemplate <class\
    \ mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 9 \"test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct RaffineRsumQ\
    \ {\n using T= Mint;\n using E= pair<T, T>;\n static T op(const T &vl, const T\
    \ &vr) { return vl + vr; }\n static void mapping(T &val, const E &f, int sz) {\
    \ val= f.first * val + f.second * sz; }\n static void composition(E &pre, const\
    \ E &suf) { pre= {pre.first * suf.first, suf.first * pre.second + suf.second};\
    \ }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n\
    \ cin >> N >> Q;\n Mint a[N];\n for (int i= 0; i < N; i++) cin >> a[i];\n SplayTree<RaffineRsumQ,\
    \ true> splay(a, a + N);\n for (int q= 0; q < Q; q++) {\n  int op;\n  cin >> op;\n\
    \  if (op == 0) {\n   int i, x;\n   cin >> i >> x;\n   splay.insert(i, x);\n \
    \ } else if (op == 1) {\n   int i;\n   cin >> i;\n   splay.erase(i);\n  } else\
    \ if (op == 2) {\n   int l, r;\n   cin >> l >> r;\n   splay.reverse(l, r);\n \
    \ } else if (op == 3) {\n   int l, r, b, c;\n   cin >> l >> r >> b >> c;\n   splay.apply(l,\
    \ r, {b, c});\n  } else {\n   int l, r;\n   cin >> l >> r;\n   cout << splay.fold(l,\
    \ r) << '\\n';\n  }\n  if (q % 100000 == 0) splay.set_balance();\n }\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n// set_balance \u3057\u306A\u3044\u3068 \u30B9\u30BF\u30C3\u30AF\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\n// \uFF08\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    \ wrong_avl_killer_01\uFF09\n\n#include <iostream>\n#include \"src/DataStructure/SplayTree.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint= ModInt<998244353>;\n\
    struct RaffineRsumQ {\n using T= Mint;\n using E= pair<T, T>;\n static T op(const\
    \ T &vl, const T &vr) { return vl + vr; }\n static void mapping(T &val, const\
    \ E &f, int sz) { val= f.first * val + f.second * sz; }\n static void composition(E\
    \ &pre, const E &suf) { pre= {pre.first * suf.first, suf.first * pre.second +\
    \ suf.second}; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n Mint a[N];\n for (int i= 0; i < N; i++) cin >>\
    \ a[i];\n SplayTree<RaffineRsumQ, true> splay(a, a + N);\n for (int q= 0; q <\
    \ Q; q++) {\n  int op;\n  cin >> op;\n  if (op == 0) {\n   int i, x;\n   cin >>\
    \ i >> x;\n   splay.insert(i, x);\n  } else if (op == 1) {\n   int i;\n   cin\
    \ >> i;\n   splay.erase(i);\n  } else if (op == 2) {\n   int l, r;\n   cin >>\
    \ l >> r;\n   splay.reverse(l, r);\n  } else if (op == 3) {\n   int l, r, b, c;\n\
    \   cin >> l >> r >> b >> c;\n   splay.apply(l, r, {b, c});\n  } else {\n   int\
    \ l, r;\n   cin >> l >> r;\n   cout << splay.fold(l, r) << '\\n';\n  }\n  if (q\
    \ % 100000 == 0) splay.set_balance();\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SplayTree.hpp
  - src/Internal/HAS_CHECK.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 21:38:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
---
