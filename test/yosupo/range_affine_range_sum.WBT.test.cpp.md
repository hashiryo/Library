---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/WeightBalancedTree.hpp
    title: "\u6C38\u7D9AWeight-Balanced-Tree"
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.WBT.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n// \u9045\
    \u5EF6\u4F1D\u642C\u306Everify\n#include <iostream>\n\n#line 2 \"src/DataStructure/WeightBalancedTree.hpp\"\
    \n#include <vector>\n#include <array>\n#include <string>\n#include <tuple>\n#include\
    \ <cstddef>\n#include <cassert>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include\
    \ <type_traits>\n#define MEMBER_MACRO(member, Dummy, name, type1, type2, last)\
    \ \\\n template <class tClass> struct name##member { \\\n  template <class U,\
    \ Dummy> static type1 check(U *); \\\n  static type2 check(...); \\\n  static\
    \ tClass *mClass; \\\n  last; \\\n };\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member,\
    \ Dummy, has_, std::true_type, std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)))\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type;\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t);\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass);\n#line 9 \"src/DataStructure/WeightBalancedTree.hpp\"\
    \ntemplate <class M, size_t NODE_SIZE= 1 << 22> class WeightBalancedTree {\n HAS_MEMBER(op);\n\
    \ HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(E);\n\
    \ template <class L> static constexpr bool semigroup_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mp<L>, has_cp<L>>;\n struct NodeB {\n  size_t sz= 0;\n };\n template\
    \ <class D, bool sg, bool du> struct NodeD: NodeB {\n  inline size_t size() const\
    \ { return this->sz; }\n };\n template <class D> struct NodeD<D, 1, 0>: NodeB\
    \ {\n  typename M::T val;\n  inline size_t size() const { return this->sz; }\n\
    \ };\n template <class D> struct NodeD<D, 0, 1>: NodeB {\n  typename M::E laz;\n\
    \  inline bool laz_flg() const { return this->sz >> 31; }\n  inline size_t size()\
    \ const { return this->sz & 0x7fffffff; }\n };\n template <class D> struct NodeD<D,\
    \ 1, 1>: NodeB {\n  typename M::T val;\n  typename M::E laz;\n  inline bool laz_flg()\
    \ const { return this->sz >> 31; }\n  inline size_t size() const { return this->sz\
    \ & 0x7fffffff; }\n };\n using Node= NodeD<void, semigroup_v<M>, dual_v<M>>;\n\
    \ using np= Node *;\n struct NodeM: Node {\n  np ch[2];\n  NodeM() {}\n  NodeM(np\
    \ l, np r): ch{l, r} {}\n };\n template <class D, bool sg, bool du> struct NodeLD:\
    \ Node {};\n template <class D> struct NodeLD<D, 0, 1>: Node {\n  typename M::T\
    \ val;\n };\n template <class D> struct NodeLD<D, 0, 0>: Node {\n  M val;\n };\n\
    \ using NodeL= NodeLD<void, semigroup_v<M>, dual_v<M>>;\n using T= decltype(NodeL::val);\n\
    \ using E= nullptr_or_E_t<M>;\n using WBT= WeightBalancedTree;\n static inline\
    \ int nmi= 0, nli= 0;\n static inline NodeM nm[NODE_SIZE];\n static inline NodeL\
    \ nl[NODE_SIZE];\n np root;\n static inline np &ch(np t, bool rig) { return ((NodeM\
    \ *)t)->ch[rig]; }\n static inline np new_nm(np l, np r) { return &(nm[nmi++]=\
    \ NodeM(l, r)); }\n static inline np new_nl(T x) { return nl[nli]= NodeL(), nl[nli].val=\
    \ x, nl[nli].sz= 1, nl + nli++; }\n static inline np cp_nm(np &t) { return t=\
    \ &(nm[nmi++]= NodeM(*((NodeM *)t))); }\n static inline np cp_nl(np &t) { return\
    \ t= &(nl[nli++]= NodeL(*((NodeL *)t))); }\n static inline np cp_node(np &t) {\
    \ return t->size() == 1 ? cp_nl(t) : cp_nm(t); }\n static inline void update(np\
    \ t) {\n  if constexpr (dual_v<M>) t->sz= (ch(t, 0)->size() + ch(t, 1)->size())\
    \ | (t->sz & 0x80000000);\n  else t->sz= ch(t, 0)->size() + ch(t, 1)->size();\n\
    \  if constexpr (semigroup_v<M>) t->val= M::op(ch(t, 0)->val, ch(t, 1)->val);\n\
    \ }\n static inline T &reflect(np t) {\n  if constexpr (dual_v<M> && !semigroup_v<M>)\n\
    \   if (t->laz_flg()) M::mp(((NodeL *)t)->val, t->laz, 1), t->sz&= 0x7fffffff;\n\
    \  return ((NodeL *)t)->val;\n }\n static inline void propagate(np t, const E\
    \ &x) {\n  if (t->laz_flg()) M::cp(t->laz, x);\n  else t->laz= x;\n  if constexpr\
    \ (semigroup_v<M>) M::mp(t->val, x, t->size());\n  t->sz|= 0x80000000;\n }\n static\
    \ inline void push(np t) {\n  if (t->laz_flg()) propagate(cp_node(ch(t, 0)), t->laz),\
    \ propagate(cp_node(ch(t, 1)), t->laz), t->sz&= 0x7fffffff;\n }\n template <bool\
    \ b> static inline np helper(std::array<np, 2> &m) {\n  if constexpr (dual_v<M>)\
    \ push(m[b]);\n  np c;\n  if constexpr (b) c= submerge({m[0], ch(m[1], 0)});\n\
    \  else c= submerge({ch(m[0], 1), m[1]});\n  if (ch(cp_nm(m[b]), b)->size() *\
    \ 4 >= c->size()) return ch(m[b], !b)= c, update(m[b]), m[b];\n  return ch(m[b],\
    \ !b)= ch(c, b), update(ch(c, b)= m[b]), update(c), c;\n }\n static inline np\
    \ submerge(std::array<np, 2> m) {\n  if (m[0]->size() > m[1]->size() * 4) return\
    \ helper<0>(m);\n  if (m[1]->size() > m[0]->size() * 4) return helper<1>(m);\n\
    \  auto t= new_nm(m[0], m[1]);\n  return update(t), t;\n }\n static inline np\
    \ merge(np l, np r) { return !l ? r : !r ? l : submerge({l, r}); }\n static inline\
    \ std::pair<np, np> split(np t, size_t k) {\n  if (!t) return {nullptr, nullptr};\n\
    \  if (k == 0) return {nullptr, t};\n  if (k >= t->size()) return {t, nullptr};\n\
    \  if constexpr (dual_v<M>) push(t);\n  auto l= ch(t, 0), r= ch(t, 1);\n  if (size_t\
    \ lsz= l->size(); k == lsz) return {l, r};\n  else if (k < lsz) {\n   auto [ll,\
    \ lr]= split(l, k);\n   return {ll, merge(lr, r)};\n  } else {\n   auto [rl, rr]=\
    \ split(r, k - lsz);\n   return {merge(l, rl), rr};\n  }\n }\n template <class\
    \ S> np build(size_t l, size_t r, const S &bg) {\n  if (r - l == 1) {\n   if constexpr\
    \ (std::is_same_v<S, T>) return new_nl(bg);\n   else return new_nl(*(bg + l));\n\
    \  }\n  size_t m= (l + r) / 2;\n  auto t= new_nm(build(l, m, bg), build(m, r,\
    \ bg));\n  return update(t), t;\n }\n void dump(np t, typename std::vector<T>::iterator\
    \ it) {\n  if (t->size() == 1) *it= reflect(t);\n  else {\n   if constexpr (dual_v<M>)\
    \ push(t);\n   dump(ch(t, 0), it), dump(ch(t, 1), it + ch(t, 0)->size());\n  }\n\
    \ }\n T fold(np t, size_t l, size_t r) {\n  if (l <= 0 && t->size() <= r) return\
    \ t->val;\n  if constexpr (dual_v<M>) push(t);\n  size_t lsz= ch(t, 0)->size();\n\
    \  if (r <= lsz) return fold(ch(t, 0), l, r);\n  if (lsz <= l) return fold(ch(t,\
    \ 1), l - lsz, r - lsz);\n  return M::op(fold(ch(t, 0), l, lsz), fold(ch(t, 1),\
    \ 0, r - lsz));\n }\n void apply(np &t, size_t l, size_t r, const E &x) {\n  if\
    \ (cp_node(t); l <= 0 && t->size() <= r) return propagate(t, x), void();\n  push(t);\n\
    \  size_t lsz= ch(t, 0)->size();\n  if (r <= lsz) apply(ch(t, 0), l, r, x);\n\
    \  else if (lsz <= l) apply(ch(t, 1), l - lsz, r - lsz, x);\n  else apply(ch(t,\
    \ 0), l, lsz, x), apply(ch(t, 1), 0, r - lsz, x);\n  if constexpr (semigroup_v<M>)\
    \ update(t);\n }\n void set_val(np &t, size_t k, const T &x) {\n  if (t->size()\
    \ == 1) return reflect(cp_nl(t))= x, void();\n  if constexpr (dual_v<M>) push(t);\n\
    \  size_t lsz= ch(cp_nm(t), 0)->size();\n  lsz > k ? set_val(ch(t, 0), k, x) :\
    \ set_val(ch(t, 1), k - lsz, x);\n  if constexpr (semigroup_v<M>) update(t);\n\
    \ }\n T get_val(np t, size_t k) {\n  if (t->size() == 1) return reflect(t);\n\
    \  if constexpr (dual_v<M>) push(t);\n  size_t lsz= ch(t, 0)->size();\n  return\
    \ lsz > k ? get_val(ch(t, 0), k) : get_val(ch(t, 1), k - lsz);\n }\n T &at_val(np\
    \ t, size_t k) {\n  if (t->size() == 1) return reflect(cp_nl(t));\n  if constexpr\
    \ (dual_v<M>) push(t);\n  size_t lsz= ch(cp_nm(t), 0)->size();\n  return lsz >\
    \ k ? at_val(ch(t, 0), k) : at_val(ch(t, 1), k - lsz);\n }\n static WBT id_to_wbt(np\
    \ t) {\n  WBT ret;\n  return ret.root= t, ret;\n }\npublic:\n WeightBalancedTree():\
    \ root(nullptr) {}\n WeightBalancedTree(size_t n, T val= T()): root(build(0, n,\
    \ val)) {}\n WeightBalancedTree(const T *bg, const T *ed): root(build(0, ed -\
    \ bg, bg)) {}\n WeightBalancedTree(const std::vector<T> &ar): WeightBalancedTree(ar.data(),\
    \ ar.data() + ar.size()){};\n WBT &operator+=(WBT rhs) { return root= merge(root,\
    \ rhs.root), *this; }\n WBT operator+(WBT rhs) { return WBT(*this)+= rhs; }\n\
    \ std::pair<WBT, WBT> split(size_t k) {\n  assert(root);\n  auto [l, r]= split(root,\
    \ k);\n  return {id_to_wbt(l), id_to_wbt(r)};\n }\n std::tuple<WBT, WBT, WBT>\
    \ split3(size_t a, size_t b) {\n  assert(root), assert(a <= b);\n  auto [tmp,\
    \ r]= split(root, b);\n  auto [l, c]= split(tmp, a);\n  return {id_to_wbt(l),\
    \ id_to_wbt(c), id_to_wbt(r)};\n }\n size_t size() const { return root ? root->size()\
    \ : 0; }\n void insert(size_t k, T val) {\n  auto [l, r]= split(root, k);\n  root=\
    \ merge(merge(l, new_nl(val)), r);\n }\n void push_back(T val) { root= merge(root,\
    \ new_nl(val)); }\n void push_front(T val) { root= merge(new_nl(val), root); }\n\
    \ T erase(size_t k) {\n  assert(k < size());\n  auto [l, tmp]= split(root, k);\n\
    \  auto [t, r]= split(tmp, 1);\n  return root= merge(l, r), reflect(t);\n }\n\
    \ T pop_back() {\n  auto [l, t]= split(root, size() - 1);\n  return root= l, reflect(t);\n\
    \ }\n T pop_front() {\n  auto [t, r]= split(root, 1);\n  return root= r, reflect(t);\n\
    \ }\n void set(size_t k, T val) { set_val(root, k, val); }\n T get(size_t k) {\
    \ return get_val(root, k); }\n T &at(size_t k) {\n  static_assert(!semigroup_v<M>,\
    \ \"\\\"at\\\" is not available\\n\");\n  return at_val(root, k);\n }\n template\
    \ <class L= M> std::enable_if_t<semigroup_v<L>, T> operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n T fold(size_t a, size_t b) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return fold(root, a, b);\n }\n void\
    \ apply(size_t a, size_t b, E x) {\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  apply(root, a, b, x);\n }\n std::vector<T> dump()\
    \ {\n  if (!root) return std::vector<T>();\n  std::vector<T> ret(size());\n  return\
    \ dump(root, ret.begin()), ret;\n }\n void clear() { root= nullptr; }\n static\
    \ void reset() { nmi= 0, nli= 0; }\n void rebuild() {\n  auto dmp= dump();\n \
    \ reset(), *this= WBT(dmp);\n }\n static std::string which_available() {\n  std::string\
    \ ret= \"\";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"fold\\\" \";\n  else\
    \ ret+= \"\\\"at\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \"\
    ;\n  return ret;\n }\n static double percentage_used() { return 100. * std::max(nmi,\
    \ nli) / NODE_SIZE; }\n};\n#line 4 \"src/Math/mod_inv.hpp\"\ntemplate <class Int>\
    \ constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
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
    \ return dat[n];\n}\n#line 7 \"test/yosupo/range_affine_range_sum.WBT.test.cpp\"\
    \nusing namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct RaffineQ_RsumQ\
    \ {\n using T= Mint;\n using E= pair<Mint, Mint>;\n static T op(const T &l, const\
    \ T &r) { return l + r; }\n static void mp(T &v, const E &f, std::size_t sz) {\
    \ v= f.first * v + f.second * sz; }\n static void cp(E &pre, const E &suf) { pre=\
    \ {suf.first * pre.first, suf.first * pre.second + suf.second}; }\n};\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >>\
    \ Q;\n Mint v[N];\n for (int i= 0; i < N; i++) cin >> v[i];\n using WBT= WeightBalancedTree<RaffineQ_RsumQ,\
    \ 1 << 24>;\n WBT wbt(v, v + N);\n while (Q--) {\n  bool op;\n  int l, r;\n  cin\
    \ >> op >> l >> r;\n  if (op) {\n   cout << wbt.fold(l, r) << endl;\n  } else\
    \ {\n   Mint b, c;\n   cin >> b >> c;\n   wbt.apply(l, r, {b, c});\n  }\n  if\
    \ (WBT::percentage_used() > 90) wbt.rebuild();\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n// \u9045\u5EF6\u4F1D\u642C\u306Everify\n#include <iostream>\n\n#include \"\
    src/DataStructure/WeightBalancedTree.hpp\"\n#include \"src/Math/ModInt.hpp\"\n\
    using namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct RaffineQ_RsumQ\
    \ {\n using T= Mint;\n using E= pair<Mint, Mint>;\n static T op(const T &l, const\
    \ T &r) { return l + r; }\n static void mp(T &v, const E &f, std::size_t sz) {\
    \ v= f.first * v + f.second * sz; }\n static void cp(E &pre, const E &suf) { pre=\
    \ {suf.first * pre.first, suf.first * pre.second + suf.second}; }\n};\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >>\
    \ Q;\n Mint v[N];\n for (int i= 0; i < N; i++) cin >> v[i];\n using WBT= WeightBalancedTree<RaffineQ_RsumQ,\
    \ 1 << 24>;\n WBT wbt(v, v + N);\n while (Q--) {\n  bool op;\n  int l, r;\n  cin\
    \ >> op >> l >> r;\n  if (op) {\n   cout << wbt.fold(l, r) << endl;\n  } else\
    \ {\n   Mint b, c;\n   cin >> b >> c;\n   wbt.apply(l, r, {b, c});\n  }\n  if\
    \ (WBT::percentage_used() > 90) wbt.rebuild();\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/WeightBalancedTree.hpp
  - src/Internal/HAS_CHECK.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.WBT.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 14:53:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.WBT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.WBT.test.cpp
- /verify/test/yosupo/range_affine_range_sum.WBT.test.cpp.html
title: test/yosupo/range_affine_range_sum.WBT.test.cpp
---
