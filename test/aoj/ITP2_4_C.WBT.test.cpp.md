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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C
  bundledCode: "#line 1 \"test/aoj/ITP2_4_C.WBT.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C\"\
    \n#include <iostream>\n#line 2 \"src/DataStructure/WeightBalancedTree.hpp\"\n\
    #include <vector>\n#include <array>\n#include <string>\n#include <tuple>\n#include\
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
    \ HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n HAS_TYPE(T);\n HAS_TYPE(E);\n\
    \ NULLPTR_OR(E);\n template <class L> static constexpr bool semigroup_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n struct NodeB {\n  size_t sz=\
    \ 0;\n };\n template <class D, bool sg, bool du> struct NodeD: NodeB {\n  inline\
    \ size_t size() const { return this->sz; }\n };\n template <class D> struct NodeD<D,\
    \ 1, 0>: NodeB {\n  typename M::T val;\n  inline size_t size() const { return\
    \ this->sz; }\n };\n template <class D> struct NodeD<D, 0, 1>: NodeB {\n  typename\
    \ M::E laz;\n  inline bool laz_flg() const { return this->sz >> 31; }\n  inline\
    \ size_t size() const { return this->sz & 0x7fffffff; }\n };\n template <class\
    \ D> struct NodeD<D, 1, 1>: NodeB {\n  typename M::T val;\n  typename M::E laz;\n\
    \  inline bool laz_flg() const { return this->sz >> 31; }\n  inline size_t size()\
    \ const { return this->sz & 0x7fffffff; }\n };\n using Node= NodeD<void, semigroup_v<M>,\
    \ dual_v<M>>;\n using np= Node *;\n struct NodeM: Node {\n  np ch[2];\n  NodeM()\
    \ {}\n  NodeM(np l, np r): ch{l, r} {}\n };\n template <class D, bool sg, bool\
    \ du> struct NodeLD: Node {};\n template <class D> struct NodeLD<D, 0, 1>: Node\
    \ {\n  typename M::T val;\n };\n template <class D> struct NodeLD<D, 0, 0>: Node\
    \ {\n  M val;\n };\n using NodeL= NodeLD<void, semigroup_v<M>, dual_v<M>>;\n using\
    \ T= decltype(NodeL::val);\n using E= nullptr_or_E_t<M>;\n using WBT= WeightBalancedTree;\n\
    \ static inline int nmi= 0, nli= 0;\n static inline NodeM nm[NODE_SIZE];\n static\
    \ inline NodeL nl[NODE_SIZE];\n np root;\n static inline np &ch(np t, bool rig)\
    \ { return ((NodeM *)t)->ch[rig]; }\n static inline np new_nm(np l, np r) { return\
    \ &(nm[nmi++]= NodeM(l, r)); }\n static inline np new_nl(T x) { return nl[nli]=\
    \ NodeL(), nl[nli].val= x, nl[nli].sz= 1, nl + nli++; }\n static inline np cp_nm(np\
    \ &t) { return t= &(nm[nmi++]= NodeM(*((NodeM *)t))); }\n static inline np cp_nl(np\
    \ &t) { return t= &(nl[nli++]= NodeL(*((NodeL *)t))); }\n static inline np cp_node(np\
    \ &t) { return t->size() == 1 ? cp_nl(t) : cp_nm(t); }\n static inline void update(np\
    \ t) {\n  if constexpr (dual_v<M>) t->sz= (ch(t, 0)->size() + ch(t, 1)->size())\
    \ | (t->sz & 0x80000000);\n  else t->sz= ch(t, 0)->size() + ch(t, 1)->size();\n\
    \  if constexpr (semigroup_v<M>) t->val= M::op(ch(t, 0)->val, ch(t, 1)->val);\n\
    \ }\n static inline T &reflect(np t) {\n  if constexpr (dual_v<M> && !semigroup_v<M>)\n\
    \   if (t->laz_flg()) M::mapping(((NodeL *)t)->val, t->laz, 1), t->sz&= 0x7fffffff;\n\
    \  return ((NodeL *)t)->val;\n }\n static inline void propagate(np t, const E\
    \ &x) {\n  if (t->laz_flg()) M::composition(t->laz, x);\n  else t->laz= x;\n \
    \ if constexpr (semigroup_v<M>) M::mapping(t->val, x, t->size());\n  t->sz|= 0x80000000;\n\
    \ }\n static inline void push(np t) {\n  if (t->laz_flg()) propagate(cp_node(ch(t,\
    \ 0)), t->laz), propagate(cp_node(ch(t, 1)), t->laz), t->sz&= 0x7fffffff;\n }\n\
    \ template <bool b> static inline np helper(std::array<np, 2> &m) {\n  if constexpr\
    \ (dual_v<M>) push(m[b]);\n  np c;\n  if constexpr (b) c= submerge({m[0], ch(m[1],\
    \ 0)});\n  else c= submerge({ch(m[0], 1), m[1]});\n  if (ch(cp_nm(m[b]), b)->size()\
    \ * 4 >= c->size()) return ch(m[b], !b)= c, update(m[b]), m[b];\n  return ch(m[b],\
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
    \ root(nullptr) {}\n WeightBalancedTree(size_t n, T val= T()) { root= build(0,\
    \ n, val); }\n WeightBalancedTree(const T *bg, const T *ed) { root= build(0, ed\
    \ - bg, bg); }\n WeightBalancedTree(const std::vector<T> &ar): WeightBalancedTree(ar.data(),\
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
    \ nli) / NODE_SIZE; }\n};\n#line 4 \"test/aoj/ITP2_4_C.WBT.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n;\n cin\
    \ >> n;\n int a[n];\n for (int i= 0; i < n; i++) cin >> a[i];\n WeightBalancedTree<int>\
    \ ar(a, a + n);\n int q;\n cin >> q;\n for (int i= 0; i < q; i++) {\n  int b,\
    \ e, t;\n  cin >> b >> e >> t;\n  int f= t + e - b;\n  if (t < b) swap(b, t),\
    \ swap(e, f);\n  auto [tl, tc, tr]= ar.split3(t, f);\n  auto [bl, bc, br]= tl.split3(b,\
    \ e);\n  ar= bl + tc + br + bc + tr;\n }\n auto ans= ar.dump();\n for (int i=\
    \ 0; i < n; i++) cout << (i ? \" \" : \"\") << ans[i];\n cout << '\\n';\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C\"\
    \n#include <iostream>\n#include \"src/DataStructure/WeightBalancedTree.hpp\"\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int n;\n cin >> n;\n int a[n];\n for (int i= 0; i < n; i++) cin >> a[i];\n WeightBalancedTree<int>\
    \ ar(a, a + n);\n int q;\n cin >> q;\n for (int i= 0; i < q; i++) {\n  int b,\
    \ e, t;\n  cin >> b >> e >> t;\n  int f= t + e - b;\n  if (t < b) swap(b, t),\
    \ swap(e, f);\n  auto [tl, tc, tr]= ar.split3(t, f);\n  auto [bl, bc, br]= tl.split3(b,\
    \ e);\n  ar= bl + tc + br + bc + tr;\n }\n auto ans= ar.dump();\n for (int i=\
    \ 0; i < n; i++) cout << (i ? \" \" : \"\") << ans[i];\n cout << '\\n';\n return\
    \ 0;\n}"
  dependsOn:
  - src/DataStructure/WeightBalancedTree.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/aoj/ITP2_4_C.WBT.test.cpp
  requiredBy: []
  timestamp: '2023-10-29 17:46:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP2_4_C.WBT.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_4_C.WBT.test.cpp
- /verify/test/aoj/ITP2_4_C.WBT.test.cpp.html
title: test/aoj/ITP2_4_C.WBT.test.cpp
---
