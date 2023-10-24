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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_B
  bundledCode: "#line 1 \"test/aoj/ITP2_4_B.SplayTree.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_B\"\n#include\
    \ <iostream>\n#line 2 \"src/DataStructure/SplayTree.hpp\"\n#include <vector>\n\
    #include <string>\n#include <array>\n#include <cstddef>\n#include <cassert>\n\
    #line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n#define HAS_CHECK(member,\
    \ Dummy) \\\n template <class tClass> struct has_##member { \\\n  template <class\
    \ U, Dummy> static std::true_type check(U *); \\\n  static std::false_type check(...);\
    \ \\\n  static tClass *mClass; \\\n  static const bool value= decltype(check(mClass))::value;\
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
    \ + r, c.root->val;\n }\n};\n#line 4 \"test/aoj/ITP2_4_B.SplayTree.test.cpp\"\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int n;\n cin >> n;\n int a[n];\n for (int i= 0; i < n; i++) cin >> a[i];\n SplayTree<int>\
    \ ar(a, a + n);\n int q;\n cin >> q;\n for (int i= 0; i < q; i++) {\n  int b,\
    \ m, e;\n  cin >> b >> m >> e;\n  auto [l, c, r]= ar.split3(b, e);\n  auto [cl,\
    \ cr]= c.split(m - b);\n  ar= l + cr + cl + r;\n }\n auto ans= ar.dump();\n for\
    \ (int i= 0; i < n; i++) cout << (i ? \" \" : \"\") << ans[i];\n cout << '\\n';\n\
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_B\"\
    \n#include <iostream>\n#include \"src/DataStructure/SplayTree.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n;\n cin\
    \ >> n;\n int a[n];\n for (int i= 0; i < n; i++) cin >> a[i];\n SplayTree<int>\
    \ ar(a, a + n);\n int q;\n cin >> q;\n for (int i= 0; i < q; i++) {\n  int b,\
    \ m, e;\n  cin >> b >> m >> e;\n  auto [l, c, r]= ar.split3(b, e);\n  auto [cl,\
    \ cr]= c.split(m - b);\n  ar= l + cr + cl + r;\n }\n auto ans= ar.dump();\n for\
    \ (int i= 0; i < n; i++) cout << (i ? \" \" : \"\") << ans[i];\n cout << '\\n';\n\
    \ return 0;\n}"
  dependsOn:
  - src/DataStructure/SplayTree.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/aoj/ITP2_4_B.SplayTree.test.cpp
  requiredBy: []
  timestamp: '2023-10-25 00:54:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ITP2_4_B.SplayTree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_4_B.SplayTree.test.cpp
- /verify/test/aoj/ITP2_4_B.SplayTree.test.cpp.html
title: test/aoj/ITP2_4_B.SplayTree.test.cpp
---
