---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/WeightBalancedTree.hpp
    title: "\u6C38\u7D9AWeight-Balanced-Tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/yosupo/persistent_queue.WBT.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_queue\"\n// \u6C38\u7D9A\u6027\u306E\
    verify\n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/WeightBalancedTree.hpp\"\
    \n/**\n * @title \u6C38\u7D9AWeight-Balanced-Tree\n * @category \u30C7\u30FC\u30BF\
    \u69CB\u9020\n * @brief O(logN)\n * \u6C38\u7D9A\u5E73\u8861\u4E8C\u5206\u6728\
    \n * \u203B\u3053\u308C\u306F\u6C38\u7D9A\u5316\u3057\u3066\u307E\u3059\uFF08\u9006\
    \u306B\u975E\u6C38\u7D9A\u306B\u3067\u304D\u308B\u3088\u3046\u306B\u3057\u3066\
    \u307E\u305B\u3093\uFF09\n * \u5358\u4F4D\u5143\u306F\u5FC5\u8981\u306A\u3057\uFF08\
    \u9045\u5EF6\u5074\u3082\uFF09\n * \u5404\u30CE\u30FC\u30C9\u304C\u8449\u306E\u30B5\
    \u30A4\u30BA\u3092\u4FDD\u6301\u3057\u3066\u3044\u308B\u306E\u3067mapping\u95A2\
    \u6570\u3067\u306F\u5F15\u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\u308B\n\
    \ */\n\n// verify\u7528:\n// https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste\
    \ (\u6C38\u7D9A)\n// https://atcoder.jp/contests/arc030/tasks/arc030_4 (\u6C38\
    \u7D9A\u9045\u5EF6\u4F1D\u642C)\n\n// BEGIN CUT HERE\n\n#ifndef HAS_CHECK\n#define\
    \ HAS_CHECK(member, Dummy)                              \\\n  template <class\
    \ T>                                          \\\n  struct has_##member {    \
    \                                   \\\n    template <class U, Dummy>        \
    \                         \\\n    static std::true_type check(U *);          \
    \               \\\n    static std::false_type check(...);                   \
    \     \\\n    static T *mClass;                                         \\\n \
    \   static const bool value = decltype(check(mClass))::value; \\\n  };\n#define\
    \ HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member, 0))\n#define HAS_TYPE(member)\
    \ HAS_CHECK(member, class dummy = typename U::member)\n#endif\n\ntemplate <typename\
    \ M, std::size_t NODE_SIZE = 1 << 23>\nclass WeightBalancedTree {\n  HAS_MEMBER(op);\n\
    \  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n\
    \  template <class L>\n  using semigroup = std::conjunction<has_T<L>, has_op<L>>;\n\
    \  template <class L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>,\
    \ has_mapping<L>, has_composition<L>>;\n  using node_id = std::int_least32_t;\n\
    \  template <class T, class F = std::nullptr_t>\n  struct Node_B {\n    using\
    \ E = F;\n    T val;\n    std::size_t size = 0;\n    node_id ch[2] = {0, 0};\n\
    \  };\n  template <bool sg_, bool du_, typename tEnable = void>\n  struct Node_D\
    \ : Node_B<M> {};\n  template <bool sg_, bool du_>\n  struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && !du_>>\n      : Node_B<typename M::T> {};\n\
    \  template <bool sg_, bool du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<du_>>\n\
    \      : Node_B<typename M::T, typename M::E> {\n    typename M::E lazy;\n   \
    \ bool lazy_flg = false;\n  };\n  using Node = Node_D<semigroup<M>::value, dual<M>::value>;\n\
    \  using T = decltype(Node::val);\n  using E = typename Node::E;\n  using WBT\
    \ = WeightBalancedTree;\n  static inline Node n[NODE_SIZE];\n  static inline node_id\
    \ ni = 1;\n  node_id root;\n  static inline void pushup(node_id t) {\n    n[t].size\
    \ = n[n[t].ch[0]].size + n[n[t].ch[1]].size;\n    if constexpr (semigroup<M>::value)\n\
    \      n[t].val = M::op(n[n[t].ch[0]].val, n[n[t].ch[1]].val);\n  }\n  static\
    \ inline T &reflect(node_id t) {\n    if constexpr (dual<M>::value && !semigroup<M>::value)\n\
    \      if (n[t].lazy_flg)\n        M::mapping(n[t].val, n[t].lazy, 1), n[t].lazy_flg\
    \ = false;\n    return n[t].val;\n  }\n  static inline void propagate(node_id\
    \ t, const E &x) {\n    n[t].lazy_flg ? (M::composition(n[t].lazy, x), x) : n[t].lazy\
    \ = x;\n    if constexpr (semigroup<M>::value) M::mapping(n[t].val, x, n[t].size);\n\
    \    n[t].lazy_flg = true;\n  }\n  static inline void cp_node(node_id &t) { n[t\
    \ = ni++] = Node(n[t]); }\n  static inline void eval(node_id t) {\n    if (!n[t].lazy_flg)\
    \ return;\n    cp_node(n[t].ch[0]), cp_node(n[t].ch[1]), n[t].lazy_flg = false;\n\
    \    propagate(n[t].ch[0], n[t].lazy), propagate(n[t].ch[1], n[t].lazy);\n  }\n\
    \  template <bool b>\n  static inline node_id helper(std::array<node_id, 2> &m)\
    \ {\n    if constexpr (dual<M>::value) eval(m[b]);\n    node_id c;\n    if constexpr\
    \ (b)\n      c = submerge({m[0], n[m[1]].ch[0]});\n    else\n      c = submerge({n[m[0]].ch[1],\
    \ m[1]});\n    if (cp_node(m[b]), n[n[m[b]].ch[b]].size * 4 >= n[c].size)\n  \
    \    return n[m[b]].ch[!b] = c, pushup(m[b]), m[b];\n    return n[m[b]].ch[!b]\
    \ = n[c].ch[b], pushup(n[c].ch[b] = m[b]), pushup(c), c;\n  }\n  static inline\
    \ node_id submerge(std::array<node_id, 2> m) {\n    if (n[m[0]].size > n[m[1]].size\
    \ * 4) return helper<0>(m);\n    if (n[m[1]].size > n[m[0]].size * 4) return helper<1>(m);\n\
    \    return n[ni] = Node{T(), 0, {m[0], m[1]}}, pushup(ni), ni++;\n  }\n  static\
    \ inline node_id merge(node_id l, node_id r) {\n    return !l ? r : (!r ? l :\
    \ submerge({l, r}));\n  }\n  static inline std::pair<node_id, node_id> split(node_id\
    \ t, std::size_t k) {\n    if (!t) return {0, 0};\n    if (k == 0) return {0,\
    \ t};\n    if (k >= n[t].size) return {t, 0};\n    if constexpr (dual<M>::value)\
    \ eval(t);\n    if (k == n[n[t].ch[0]].size) return {n[t].ch[0], n[t].ch[1]};\n\
    \    if (k < n[n[t].ch[0]].size) {\n      auto [ll, m] = split(n[t].ch[0], k);\n\
    \      return {ll, merge(m, n[t].ch[1])};\n    } else {\n      auto [rl, rr] =\
    \ split(n[t].ch[1], k - n[n[t].ch[0]].size);\n      return {merge(n[t].ch[0],\
    \ rl), rr};\n    }\n  }\n  template <class S>\n  node_id build(std::size_t l,\
    \ std::size_t r, const S &bg) {\n    if (r - l == 1) {\n      if constexpr (std::is_same_v<S,\
    \ T>)\n        return n[ni] = Node{bg, 1}, ni++;\n      else\n        return n[ni]\
    \ = Node{*(bg + l), 1}, ni++;\n    }\n    return merge(build(l, (l + r) >> 1,\
    \ bg), build((l + r) >> 1, r, bg));\n  }\n  void dump(node_id t, typename std::vector<T>::iterator\
    \ it) {\n    if (!n[t].ch[0]) return *it = reflect(t), void();\n    if constexpr\
    \ (dual<M>::value) eval(t);\n    dump(n[t].ch[0], it), dump(n[t].ch[1], it + n[n[t].ch[0]].size);\n\
    \  }\n  T fold(node_id t, const std::size_t &l, const std::size_t &r, std::size_t\
    \ bl,\n         std::size_t br) {\n    if (l <= bl && br <= r) return n[t].val;\n\
    \    if constexpr (dual<M>::value) eval(t);\n    std::size_t m = bl + n[n[t].ch[0]].size;\n\
    \    if (r <= m) return fold(n[t].ch[0], l, r, bl, m);\n    if (m <= l) return\
    \ fold(n[t].ch[1], l, r, m, br);\n    return M::op(fold(n[t].ch[0], l, r, bl,\
    \ m), fold(n[t].ch[1], l, r, m, br));\n  }\n  void apply(node_id &t, const std::size_t\
    \ &l, const std::size_t &r,\n             std::size_t bl, std::size_t br, const\
    \ E &x) {\n    if (r <= bl || br <= l) return;\n    if (cp_node(t); l <= bl &&\
    \ br <= r) return propagate(t, x), void();\n    eval(t);\n    std::size_t m =\
    \ bl + n[n[t].ch[0]].size;\n    apply(n[t].ch[0], l, r, bl, m, x), apply(n[t].ch[1],\
    \ l, r, m, br, x);\n    if constexpr (semigroup<M>::value) pushup(t);\n  }\n \
    \ void set_val(node_id &t, std::size_t k, const T &x) {\n    if (cp_node(t); !n[t].ch[0])\
    \ return reflect(t) = x, void();\n    if constexpr (dual<M>::value) eval(t);\n\
    \    bool flg = n[n[t].ch[0]].size <= k;\n    set_val(n[t].ch[flg], flg ? k -\
    \ n[n[t].ch[0]].size : k, x);\n    if constexpr (semigroup<M>::value) pushup(t);\n\
    \  }\n  T get_val(node_id t, std::size_t k) {\n    if (!n[t].ch[0]) return reflect(t);\n\
    \    if constexpr (dual<M>::value) eval(t);\n    bool flg = n[n[t].ch[0]].size\
    \ <= k;\n    return get_val(n[t].ch[flg], flg ? k - n[n[t].ch[0]].size : k);\n\
    \  }\n  T &at_val(node_id t, std::size_t k) {\n    if (cp_node(t); !n[t].ch[0])\
    \ return reflect(t);\n    if constexpr (dual<M>::value) eval(t);\n    bool flg\
    \ = n[n[t].ch[0]].size <= k;\n    return at_val(n[t].ch[flg], flg ? k - n[n[t].ch[0]].size\
    \ : k);\n  }\n  static WBT id_to_wbt(node_id t) {\n    WBT ret;\n    return ret.root\
    \ = t, ret;\n  }\n\n public:\n  WeightBalancedTree() : root(0) {}\n  WeightBalancedTree(std::size_t\
    \ n, T val = T()) { root = build(0, n, val); }\n  WeightBalancedTree(const T *bg,\
    \ const T *ed) { root = build(0, ed - bg, bg); }\n  WeightBalancedTree(const std::vector<T>\
    \ &ar)\n      : WeightBalancedTree(ar.data(), ar.data() + ar.size()){};\n  WBT\
    \ &operator+=(WBT rhs) { return root = merge(root, rhs.root), *this; }\n  WBT\
    \ operator+(WBT rhs) { return WBT(*this) += rhs; }\n  std::pair<WBT, WBT> split(std::size_t\
    \ k) {\n    auto [l, r] = split(root, k);\n    return {id_to_wbt(l), id_to_wbt(r)};\n\
    \  }\n  std::tuple<WBT, WBT, WBT> split3(std::size_t a, std::size_t b) {\n   \
    \ auto [tmp, r] = split(root, b);\n    auto [l, c] = split(tmp, a);\n    return\
    \ {id_to_wbt(l), id_to_wbt(c), id_to_wbt(r)};\n  }\n  void push_back(T val) {\
    \ n[ni] = Node{val, 1}, root = merge(root, ni++); }\n  void push_front(T val)\
    \ { n[ni] = Node{val, 1}, root = merge(ni++, root); }\n  void insert(std::size_t\
    \ k, T val) {\n    auto [l, r] = split(root, k);\n    n[ni] = Node{val, 1}, root\
    \ = merge(merge(l, ni++), r);\n  }\n  T pop_back() {\n    assert(root);\n    auto\
    \ [l, t] = split(root, size() - 1);\n    return root = l, reflect(t);\n  }\n \
    \ T pop_front() {\n    assert(root);\n    auto [t, r] = split(root, 1);\n    return\
    \ root = r, reflect(t);\n  }\n  T erase(std::size_t k) {\n    assert(k < size());\n\
    \    auto [l, tmp] = split(root, k);\n    auto [t, r] = split(tmp, 1);\n    return\
    \ root = merge(l, r), reflect(t);\n  }\n  void set(std::size_t k, T val) { set_val(root,\
    \ k, val); }\n  T get(std::size_t k) { return get_val(root, k); }\n  T &at(std::size_t\
    \ k) {\n    static_assert(!semigroup<M>::value, \"\\\"at\\\" is not available\\\
    n\");\n    return at_val(root, k);\n  }\n  template <class L = M,\n          \
    \  typename std::enable_if_t<semigroup<L>::value> * = nullptr>\n  T operator[](std::size_t\
    \ k) {\n    return get(k);\n  }\n  template <class L = M,\n            typename\
    \ std::enable_if_t<!semigroup<L>::value> * = nullptr>\n  T &operator[](std::size_t\
    \ k) {\n    return at(k);\n  }\n  T fold(std::size_t a, std::size_t b) {\n   \
    \ static_assert(semigroup<M>::value, \"\\\"fold\\\" is not available\\n\");\n\
    \    return fold(root, a, b, 0, size());\n  }\n  void apply(std::size_t a, std::size_t\
    \ b, E x) {\n    static_assert(dual<M>::value, \"\\\"apply\\\" is not available\\\
    n\");\n    apply(root, a, b, 0, size(), x);\n  }\n  std::size_t size() { return\
    \ n[root].size; }\n  std::vector<T> dump() {\n    if (!root) return std::vector<T>();\n\
    \    std::vector<T> ret(size());\n    return dump(root, ret.begin()), ret;\n \
    \ }\n  void clear() { root = 0; }\n  static void reset() { ni = 1; }\n  void rebuild()\
    \ {\n    auto dmp = dump();\n    reset(), *this = WBT(dmp);\n  }\n  static std::string\
    \ which_available() {\n    std::string ret = \"\";\n    if constexpr (semigroup<M>::value)\n\
    \      ret += \"\\\"fold\\\" \";\n    else\n      ret += \"\\\"at\\\" \";\n  \
    \  if constexpr (dual<M>::value) ret += \"\\\"apply\\\" \";\n    return ret;\n\
    \  }\n  static double percentage_used() { return 100. * ni / NODE_SIZE; }\n};\n\
    #line 5 \"test/yosupo/persistent_queue.WBT.test.cpp\"\nusing namespace std;\n\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int Q;\n  cin >>\
    \ Q;\n  vector<WeightBalancedTree<int, 1 << 24>> S(Q + 1);\n  for (int i = 1;\
    \ i <= Q; i++) {\n    int op, t;\n    cin >> op >> t;\n    S[i] = S[++t];\n  \
    \  if (op) {\n      cout << S[i].pop_front() << endl;\n    } else {\n      int\
    \ x;\n      cin >> x;\n      S[i].push_back(x);\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n//\
    \ \u6C38\u7D9A\u6027\u306Everify\n#include <bits/stdc++.h>\n#include \"src/DataStructure/WeightBalancedTree.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int Q;\n  cin >> Q;\n  vector<WeightBalancedTree<int, 1 << 24>> S(Q + 1);\n\
    \  for (int i = 1; i <= Q; i++) {\n    int op, t;\n    cin >> op >> t;\n    S[i]\
    \ = S[++t];\n    if (op) {\n      cout << S[i].pop_front() << endl;\n    } else\
    \ {\n      int x;\n      cin >> x;\n      S[i].push_back(x);\n    }\n  }\n  return\
    \ 0;\n}"
  dependsOn:
  - src/DataStructure/WeightBalancedTree.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_queue.WBT.test.cpp
  requiredBy: []
  timestamp: '2022-06-20 22:21:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/persistent_queue.WBT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_queue.WBT.test.cpp
- /verify/test/yosupo/persistent_queue.WBT.test.cpp.html
title: test/yosupo/persistent_queue.WBT.test.cpp
---
