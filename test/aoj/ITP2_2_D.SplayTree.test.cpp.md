---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/SplayTree.hpp
    title: Splay-Tree
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D
  bundledCode: "#line 1 \"test/aoj/ITP2_2_D.SplayTree.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D\"\n#include\
    \ <iostream>\n#line 2 \"src/DataStructure/SplayTree.hpp\"\n#include <vector>\n\
    #include <string>\n#include <tuple>\n#include <cstddef>\n#include <cassert>\n\
    #line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n#define HAS_CHECK(member,\
    \ Dummy) \\\n template <class tClass> struct has_##member { \\\n  template <class\
    \ U, Dummy> static std::true_type check(U *); \\\n  static std::false_type check(...);\
    \ \\\n  static tClass *mClass; \\\n  static const bool value= decltype(check(mClass))::value;\
    \ \\\n };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n\
    #line 8 \"src/DataStructure/SplayTree.hpp\"\ntemplate <class M, bool reversible=\
    \ false> class SplayTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n\
    \ HAS_TYPE(T);\n HAS_TYPE(E);\n template <class L> using semigroup= std::conjunction<has_T<L>,\
    \ has_op<L>>;\n template <class L> using dual= std::conjunction<has_T<L>, has_E<L>,\
    \ has_mapping<L>, has_composition<L>>;\n template <class T, class tDerived, class\
    \ F= std::nullptr_t> struct Node_B {\n  using E= F;\n  T val;\n  tDerived *ch[2];\n\
    \  std::size_t size;\n };\n template <bool sg_, bool du_, bool rev_, typename\
    \ tEnable= void> struct Node_D: Node_B<M, Node_D<sg_, du_, rev_, tEnable>> {};\n\
    \ template <bool sg_, bool du_, bool rev_> struct Node_D<sg_, du_, rev_, typename\
    \ std::enable_if_t<sg_ && !du_ && !rev_>>: Node_B<typename M::T, Node_D<sg_, du_,\
    \ rev_>> { typename M::T sum; };\n template <bool sg_, bool du_, bool rev_> struct\
    \ Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_ && du_ && !rev_>>: Node_B<typename\
    \ M::T, Node_D<sg_, du_, rev_>, typename M::E> {\n  typename M::E lazy;\n  bool\
    \ lazy_flg= false;\n };\n template <bool sg_, bool du_, bool rev_> struct Node_D<sg_,\
    \ du_, rev_, typename std::enable_if_t<sg_ && du_ && !rev_>>: Node_B<typename\
    \ M::T, Node_D<sg_, du_, rev_>, typename M::E> {\n  typename M::T sum;\n  typename\
    \ M::E lazy;\n  bool lazy_flg= false;\n };\n template <bool sg_, bool du_, bool\
    \ rev_> struct Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_ && !du_ &&\
    \ rev_>>: Node_B<M, Node_D<sg_, du_, rev_>> { bool rev_flg= false; };\n template\
    \ <bool sg_, bool du_, bool rev_> struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
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
    \ nullptr; }\n template <class L= M, std::enable_if_t<monoid<L>::value, std::nullptr_t>\
    \ = nullptr> const T &operator[](std::size_t k) { return get(k); }\n template\
    \ <class L= M, std::enable_if_t<monoid<L>::value, std::nullptr_t> = nullptr> T\
    \ &operator[](std::size_t k) { return at(k); }\n const T &get(std::size_t k) {\
    \ return splay(root, k), root->val; }\n T &at(std::size_t k) {\n  static_assert(!semigroup<M>::value,\
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
    #line 4 \"test/aoj/ITP2_2_D.SplayTree.test.cpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n cin >> n >>\
    \ q;\n SplayTree<int> ar[n];\n for (int i= 0; i < q; i++) {\n  int op;\n  cin\
    \ >> op;\n  if (op == 0) {\n   int t, x;\n   cin >> t >> x;\n   ar[t].push_back(x);\n\
    \  } else if (op == 1) {\n   int t;\n   cin >> t;\n   auto ans= ar[t].dump();\n\
    \   for (int i= 0; i < ar[t].size(); i++) cout << (i ? \" \" : \"\") << ans[i];\n\
    \   cout << '\\n';\n  } else {\n   int s, t;\n   cin >> s >> t;\n   ar[t]+= ar[s];\n\
    \   ar[s].clear();\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D\"\
    \n#include <iostream>\n#include \"src/DataStructure/SplayTree.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n\
    \ cin >> n >> q;\n SplayTree<int> ar[n];\n for (int i= 0; i < q; i++) {\n  int\
    \ op;\n  cin >> op;\n  if (op == 0) {\n   int t, x;\n   cin >> t >> x;\n   ar[t].push_back(x);\n\
    \  } else if (op == 1) {\n   int t;\n   cin >> t;\n   auto ans= ar[t].dump();\n\
    \   for (int i= 0; i < ar[t].size(); i++) cout << (i ? \" \" : \"\") << ans[i];\n\
    \   cout << '\\n';\n  } else {\n   int s, t;\n   cin >> s >> t;\n   ar[t]+= ar[s];\n\
    \   ar[s].clear();\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SplayTree.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/aoj/ITP2_2_D.SplayTree.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 20:52:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ITP2_2_D.SplayTree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_2_D.SplayTree.test.cpp
- /verify/test/aoj/ITP2_2_D.SplayTree.test.cpp.html
title: test/aoj/ITP2_2_D.SplayTree.test.cpp
---
