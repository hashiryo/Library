---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/WeightBalancedTree.hpp
    title: Weight-Balanced-Tree
  - icon: ':question:'
    path: src/Internal/detection_idiom.hpp
    title: detection idiom
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D
  bundledCode: "#line 1 \"test/aoj/ITP2_2_D.WBT.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D\"\
    \n\n// push_back, operator+= \u306E verify\n\n#include <iostream>\n#include <vector>\n\
    #line 3 \"src/DataStructure/WeightBalancedTree.hpp\"\n#include <array>\n#include\
    \ <string>\n#include <tuple>\n#include <cstddef>\n#include <cassert>\n#line 2\
    \ \"src/Internal/detection_idiom.hpp\"\n#include <type_traits>\n#define _DETECT_BOOL(name,\
    \ ...) \\\n template <class, class= void> struct name: std::false_type {}; \\\n\
    \ template <class T> struct name<T, std::void_t<__VA_ARGS__>>: std::true_type\
    \ {}; \\\n template <class T> static constexpr bool name##_v= name<T>::value\n\
    #define _DETECT_TYPE(name, type1, type2, ...) \\\n template <class T, class= void>\
    \ struct name { \\\n  using type= type2; \\\n }; \\\n template <class T> struct\
    \ name<T, std::void_t<__VA_ARGS__>> { \\\n  using type= type1; \\\n }\n#line 9\
    \ \"src/DataStructure/WeightBalancedTree.hpp\"\nnamespace wbt_internal {\n#ifdef\
    \ __LOCAL\nstatic constexpr size_t __LEAF_SIZE= 1 << 15;\n#else\nstatic constexpr\
    \ size_t __LEAF_SIZE= 1 << 20;\n#endif\n}\ntemplate <class M, bool reversible=\
    \ false, bool persistent= false, size_t LEAF_SIZE= wbt_internal::__LEAF_SIZE>\
    \ class WeightBalancedTree {\n _DETECT_BOOL(semigroup, typename T::T, decltype(&T::op));\n\
    \ _DETECT_BOOL(dual, typename T::T, typename T::E, decltype(&T::mp), decltype(&T::cp));\n\
    \ _DETECT_BOOL(commute, typename T::commute);\n _DETECT_TYPE(nullptr_or_E, typename\
    \ T::E, std::nullptr_t, typename T::E);\n _DETECT_TYPE(myself_or_T, typename T::T,\
    \ T, typename T::T);\n struct NodeMB {\n  std::array<int, 2> ch;\n  size_t sz=\
    \ 0;\n };\n template <class D, bool du> struct NodeMD: NodeMB {};\n template <class\
    \ D> struct NodeMD<D, 1>: NodeMB {\n  typename M::E laz;\n };\n template <class\
    \ D, bool sg, bool rev, bool com> struct NodeMS: NodeMD<D, dual_v<M>> {\n  typename\
    \ M::T sum;\n };\n template <class D, bool rev, bool com> struct NodeMS<D, 0,\
    \ rev, com>: NodeMD<D, dual_v<M>> {};\n template <class D> struct NodeMS<D, 1,\
    \ 1, 0>: NodeMD<D, dual_v<M>> {\n  typename M::T sum, rsum;\n };\n using NodeM=\
    \ NodeMS<void, semigroup_v<M>, reversible, commute_v<M>>;\n using T= typename\
    \ myself_or_T<M>::type;\n using E= typename nullptr_or_E<M>::type;\n using WBT=\
    \ WeightBalancedTree;\n static inline int nmi= 1, nli= 1;\n static constexpr size_t\
    \ M_SIZE= LEAF_SIZE * 10;\n static constexpr size_t L_SIZE= persistent && (dual_v<M>\
    \ || reversible) ? LEAF_SIZE * 10 : LEAF_SIZE;\n static inline NodeM nm[M_SIZE];\n\
    \ static inline T nl[L_SIZE];\n int root;\n static inline size_t msize(int i)\
    \ noexcept {\n  if constexpr (dual_v<M> || reversible) return nm[i].sz & 0x3fffffff;\n\
    \  else return nm[i].sz;\n }\n static inline size_t size(int i) noexcept { return\
    \ i < 0 ? 1 : msize(i); }\n static inline T sum(int i) noexcept { return i < 0\
    \ ? nl[-i] : nm[i].sum; }\n static inline T rsum(int i) noexcept { return i <\
    \ 0 ? nl[-i] : nm[i].rsum; }\n static inline void update(int i) noexcept {\n \
    \ auto t= nm + i;\n  auto [l, r]= t->ch;\n  t->sz= size(l) + size(r);\n  if constexpr\
    \ (semigroup_v<M>) {\n   t->sum= M::op(sum(l), sum(r));\n   if constexpr (reversible\
    \ && !commute_v<M>) t->rsum= M::op(rsum(r), rsum(l));\n  }\n }\n static inline\
    \ void propagate(int &i, const E &x) noexcept {\n  if constexpr (persistent) nm[nmi]=\
    \ nm[i], i= nmi++;\n  auto t= nm + i;\n  if (t->sz >> 31) M::cp(t->laz, x);\n\
    \  else t->laz= x;\n  if constexpr (semigroup_v<M>) {\n   M::mp(t->sum, x, t->sz\
    \ & 0x3fffffff);\n   if constexpr (reversible && !commute_v<M>) M::mp(t->rsum,\
    \ x, t->sz & 0x3fffffff);\n  }\n  t->sz|= 0x80000000;\n }\n static inline void\
    \ push_prop(int i) noexcept {\n  if (auto t= nm + i; t->sz >> 31) {\n   auto &[l,\
    \ r]= t->ch;\n   if (l < 0) {\n    if constexpr (persistent) nl[nli]= nl[-l],\
    \ l= -nli++;\n    M::mp(nl[-l], t->laz, 1);\n   } else propagate(l, t->laz);\n\
    \   if (r < 0) {\n    if constexpr (persistent) nl[nli]= nl[-r], r= -nli++;\n\
    \    M::mp(nl[-r], t->laz, 1);\n   } else propagate(r, t->laz);\n   t->sz^= 0x80000000;\n\
    \  }\n }\n static inline void toggle(int &i) noexcept {\n  if constexpr (persistent)\
    \ nm[nmi]= nm[i], i= nmi++;\n  auto t= nm + i;\n  std::swap(t->ch[0], t->ch[1]);\n\
    \  if constexpr (semigroup_v<M> && !commute_v<M>) std::swap(t->sum, t->rsum);\n\
    \  t->sz^= 0x40000000;\n }\n static inline void push_tog(int i) noexcept {\n \
    \ if (auto t= nm + i; t->sz & 0x40000000) {\n   auto &[l, r]= t->ch;\n   if (l\
    \ > 0) toggle(l);\n   if (r > 0) toggle(r);\n   t->sz^= 0x40000000;\n  }\n }\n\
    \ template <bool b> static inline int helper(std::array<int, 2> &m) noexcept {\n\
    \  if constexpr (dual_v<M>) push_prop(m[b]);\n  if constexpr (reversible) push_tog(m[b]);\n\
    \  int c;\n  if constexpr (b) c= _merge({m[0], nm[m[1]].ch[0]});\n  else c= _merge({nm[m[0]].ch[1],\
    \ m[1]});\n  if constexpr (persistent) nm[nmi]= nm[m[b]], m[b]= nmi++;\n  if (size(nm[m[b]].ch[b])\
    \ * 4 >= msize(c)) return nm[m[b]].ch[!b]= c, update(m[b]), m[b];\n  return nm[m[b]].ch[!b]=\
    \ nm[c].ch[b], update(nm[c].ch[b]= m[b]), update(c), c;\n }\n static inline int\
    \ _merge(std::array<int, 2> m) noexcept {\n  int lsz= size(m[0]), rsz= size(m[1]);\n\
    \  if (lsz > rsz * 4) return helper<0>(m);\n  if (rsz > lsz * 4) return helper<1>(m);\n\
    \  return nm[nmi]= NodeM{m[0], m[1]}, update(nmi), nmi++;\n }\n static inline\
    \ int merge(int l, int r) noexcept { return !l ? r : !r ? l : _merge({l, r});\
    \ }\n static inline std::pair<int, int> _split(int i, size_t k) noexcept {\n \
    \ if constexpr (dual_v<M>) push_prop(i);\n  if constexpr (reversible) push_tog(i);\n\
    \  auto t= nm + i;\n  auto [l, r]= t->ch;\n  if (size_t lsz= size(l); k == lsz)\
    \ return {l, r};\n  else if (k < lsz) {\n   auto [ll, lr]= _split(l, k);\n   return\
    \ {ll, _merge({lr, r})};\n  } else {\n   auto [rl, rr]= _split(r, k - lsz);\n\
    \   return {_merge({l, rl}), rr};\n  }\n }\n static inline std::pair<int, int>\
    \ split(int i, size_t k) noexcept {\n  if (k == 0) return {0, i};\n  if (k >=\
    \ size(i)) return {i, 0};\n  return _split(i, k);\n }\n template <class S> int\
    \ build(size_t l, size_t r, const S &bg) noexcept {\n  if (r - l == 1) {\n   if\
    \ constexpr (std::is_same_v<S, T>) return nl[nli]= bg, -nli++;\n   else return\
    \ nl[nli]= *(bg + l), -nli++;\n  }\n  size_t m= (l + r) / 2, i= nmi++;\n  return\
    \ nm[i]= NodeM{build(l, m, bg), build(m, r, bg)}, update(i), i;\n }\n void dump(int\
    \ i, typename std::vector<T>::iterator it) noexcept {\n  if (i < 0) *it= nl[-i];\n\
    \  else {\n   if constexpr (dual_v<M>) push_prop(i);\n   if constexpr (reversible)\
    \ push_tog(i);\n   dump(nm[i].ch[0], it), dump(nm[i].ch[1], it + size(nm[i].ch[0]));\n\
    \  }\n }\n T fold(int i, size_t l, size_t r) noexcept {\n  if (i < 0) return nl[-i];\n\
    \  if (l <= 0 && msize(i) <= r) return nm[i].sum;\n  if constexpr (dual_v<M>)\
    \ push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  auto [n0, n1]= nm[i].ch;\n\
    \  size_t lsz= size(n0);\n  if (r <= lsz) return fold(n0, l, r);\n  if (lsz <=\
    \ l) return fold(n1, l - lsz, r - lsz);\n  return M::op(fold(n0, l, lsz), fold(n1,\
    \ 0, r - lsz));\n }\n void apply(int &i, size_t l, size_t r, const E &x) noexcept\
    \ {\n  if (i < 0) {\n   if constexpr (persistent) nl[nli]= nl[-i], i= -nli++;\n\
    \   M::mp(nl[-i], x, 1);\n   return;\n  }\n  if (l <= 0 && msize(i) <= r) return\
    \ propagate(i, x);\n  if constexpr (reversible) push_tog(i);\n  push_prop(i);\n\
    \  if constexpr (persistent) nm[nmi]= nm[i], i= nmi++;\n  auto &[n0, n1]= nm[i].ch;\n\
    \  size_t lsz= size(n0);\n  if (r <= lsz) apply(n0, l, r, x);\n  else if (lsz\
    \ <= l) apply(n1, l - lsz, r - lsz, x);\n  else apply(n0, l, lsz, x), apply(n1,\
    \ 0, r - lsz, x);\n  if constexpr (semigroup_v<M>) update(i);\n }\n void set_val(int\
    \ &i, size_t k, const T &x) noexcept {\n  if (i < 0) {\n   if constexpr (persistent)\
    \ nl[nli]= x, i= -nli++;\n   else nl[-i]= x;\n   return;\n  }\n  if constexpr\
    \ (dual_v<M>) push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  if constexpr\
    \ (persistent) nm[nmi]= nm[i], i= nmi++;\n  auto &[l, r]= nm[i].ch;\n  size_t\
    \ lsz= size(l);\n  lsz > k ? set_val(l, k, x) : set_val(r, k - lsz, x);\n  if\
    \ constexpr (semigroup_v<M>) update(i);\n }\n void mul_val(int &i, size_t k, const\
    \ T &x) noexcept {\n  if (i < 0) {\n   if constexpr (persistent) nl[nli]= M::op(nl[-i],\
    \ x), i= -nli++;\n   else nl[-i]= M::op(nl[-i], x);\n   return;\n  }\n  if constexpr\
    \ (dual_v<M>) push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  if constexpr\
    \ (persistent) nm[nmi]= nm[i], i= nmi++;\n  auto &[l, r]= nm[i].ch;\n  size_t\
    \ lsz= size(l);\n  lsz > k ? mul_val(l, k, x) : mul_val(r, k - lsz, x);\n  if\
    \ constexpr (semigroup_v<M>) update(i);\n }\n T get_val(int i, size_t k) noexcept\
    \ {\n  if (i < 0) return nl[-i];\n  if constexpr (dual_v<M>) push_prop(i);\n \
    \ if constexpr (reversible) push_tog(i);\n  auto [l, r]= nm[i].ch;\n  size_t lsz=\
    \ size(l);\n  return lsz > k ? get_val(l, k) : get_val(r, k - lsz);\n }\n T &at_val(int\
    \ i, size_t k) noexcept {\n  if (i < 0) {\n   if constexpr (persistent) return\
    \ nl[nli++]= nl[-i];\n   else return nl[-i];\n  }\n  if constexpr (dual_v<M>)\
    \ push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  if constexpr (persistent)\
    \ nm[nmi]= nm[i], i= nmi++;\n  auto [l, r]= nm[i].ch;\n  size_t lsz= size(l);\n\
    \  return lsz > k ? at_val(l, k) : at_val(r, k - lsz);\n }\n static WBT id_to_wbt(int\
    \ t) noexcept {\n  WBT ret;\n  return ret.root= t, ret;\n }\npublic:\n WeightBalancedTree():\
    \ root(0) {}\n WeightBalancedTree(size_t n, T val= T()): root(n ? build(0, n,\
    \ val) : 0) {}\n WeightBalancedTree(const T *bg, const T *ed): root(bg == ed ?\
    \ 0 : build(0, ed - bg, bg)) {}\n WeightBalancedTree(const std::vector<T> &ar):\
    \ WeightBalancedTree(ar.data(), ar.data() + ar.size()){};\n WBT &operator+=(WBT\
    \ rhs) { return root= merge(root, rhs.root), *this; }\n WBT operator+(WBT rhs)\
    \ { return WBT(*this)+= rhs; }\n std::pair<WBT, WBT> split(size_t k) {\n  assert(root);\n\
    \  auto [l, r]= split(root, k);\n  return {id_to_wbt(l), id_to_wbt(r)};\n }\n\
    \ std::tuple<WBT, WBT, WBT> split3(size_t a, size_t b) {\n  assert(root), assert(a\
    \ <= b);\n  auto [tmp, r]= split(root, b);\n  auto [l, c]= split(tmp, a);\n  return\
    \ {id_to_wbt(l), id_to_wbt(c), id_to_wbt(r)};\n }\n size_t size() const { return\
    \ root ? size(root) : 0; }\n void insert(size_t k, T val) {\n  auto [l, r]= split(root,\
    \ k);\n  nl[nli]= val, root= merge(merge(l, -nli++), r);\n }\n void push_back(T\
    \ val) { nl[nli]= val, root= merge(root, -nli++); }\n void push_front(T val) {\
    \ nl[nli]= val, root= merge(-nli++, root); }\n T erase(size_t k) {\n  assert(k\
    \ < size());\n  auto [l, tmp]= split(root, k);\n  auto [t, r]= split(tmp, 1);\n\
    \  return root= merge(l, r), nl[-t];\n }\n T pop_back() {\n  auto [l, t]= split(root,\
    \ size() - 1);\n  return root= l, nl[-t];\n }\n T pop_front() {\n  auto [t, r]=\
    \ split(root, 1);\n  return root= r, nl[-t];\n }\n void set(size_t k, T val) {\
    \ set_val(root, k, val); }\n void mul(size_t k, T val) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"mul\\\" is not available\\n\");\n  mul_val(root, k, val);\n }\n T get(size_t\
    \ k) { return get_val(root, k); }\n T &at(size_t k) {\n  static_assert(!semigroup_v<M>,\
    \ \"\\\"at\\\" is not available\\n\");\n  return at_val(root, k);\n }\n template\
    \ <class L= M> std::enable_if_t<semigroup_v<L>, T> operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n T fold(size_t a, size_t b) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return fold(root, a, b);\n }\n void\
    \ apply(size_t a, size_t b, E x) {\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  apply(root, a, b, x);\n }\n void reverse(size_t a,\
    \ size_t b) {\n  static_assert(reversible, \"\\\"reverse\\\" is not available\\\
    n\");\n  assert(root), assert(a <= b);\n  auto [tmp, r]= split(root, b);\n  auto\
    \ [l, c]= split(tmp, a);\n  if (c > 0) toggle(c);\n  root= merge(merge(l, c),\
    \ r);\n }\n std::vector<T> dump() {\n  if (!root) return std::vector<T>();\n \
    \ std::vector<T> ret(size());\n  return dump(root, ret.begin()), ret;\n }\n void\
    \ clear() { root= 0; }\n static void reset() { nmi= 1, nli= 1; }\n static std::string\
    \ which_available() {\n  std::string ret= \"\";\n  if constexpr (semigroup_v<M>)\
    \ ret+= \"\\\"fold\\\" \";\n  else ret+= \"\\\"at\\\" \";\n  if constexpr (dual_v<M>)\
    \ ret+= \"\\\"apply\\\" \";\n  if constexpr (reversible) ret+= \"\\\"reverse\\\
    \" \";\n  return ret;\n }\n static bool pool_empty() {\n  if constexpr (persistent\
    \ && (dual_v<M> || reversible)) return nmi + LEAF_SIZE >= M_SIZE || nli + LEAF_SIZE\
    \ >= L_SIZE;\n  else return nmi + 1000 >= M_SIZE || nli + 1000 >= L_SIZE;\n }\n\
    };\n#line 8 \"test/aoj/ITP2_2_D.WBT.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n cin >> n >> q;\n using\
    \ WBT= WeightBalancedTree<int>;\n WBT ar[n];\n for (int i= 0; i < q; ++i) {\n\
    \  int op;\n  cin >> op;\n  if (op == 0) {\n   int t, x;\n   cin >> t >> x;\n\
    \   ar[t].push_back(x);\n  } else if (op == 1) {\n   int t;\n   cin >> t;\n  \
    \ auto ans= ar[t].dump();\n   for (int i= 0; i < ans.size(); ++i) cout << (i ?\
    \ \" \" : \"\") << ans[i];\n   cout << '\\n';\n  } else {\n   int s, t;\n   cin\
    \ >> s >> t;\n   ar[t]+= ar[s];\n   ar[s].clear();\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_2_D\"\
    \n\n// push_back, operator+= \u306E verify\n\n#include <iostream>\n#include <vector>\n\
    #include \"src/DataStructure/WeightBalancedTree.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n cin >>\
    \ n >> q;\n using WBT= WeightBalancedTree<int>;\n WBT ar[n];\n for (int i= 0;\
    \ i < q; ++i) {\n  int op;\n  cin >> op;\n  if (op == 0) {\n   int t, x;\n   cin\
    \ >> t >> x;\n   ar[t].push_back(x);\n  } else if (op == 1) {\n   int t;\n   cin\
    \ >> t;\n   auto ans= ar[t].dump();\n   for (int i= 0; i < ans.size(); ++i) cout\
    \ << (i ? \" \" : \"\") << ans[i];\n   cout << '\\n';\n  } else {\n   int s, t;\n\
    \   cin >> s >> t;\n   ar[t]+= ar[s];\n   ar[s].clear();\n  }\n }\n return 0;\n\
    }\n"
  dependsOn:
  - src/DataStructure/WeightBalancedTree.hpp
  - src/Internal/detection_idiom.hpp
  isVerificationFile: true
  path: test/aoj/ITP2_2_D.WBT.test.cpp
  requiredBy: []
  timestamp: '2024-03-22 15:43:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP2_2_D.WBT.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_2_D.WBT.test.cpp
- /verify/test/aoj/ITP2_2_D.WBT.test.cpp.html
title: test/aoj/ITP2_2_D.WBT.test.cpp
---
