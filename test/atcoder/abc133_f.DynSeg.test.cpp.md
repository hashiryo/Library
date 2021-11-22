---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/LinkCutTree.hpp
    title: Link-Cut-Tree
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dynamic.hpp
    title: "Segment-Tree(\u52D5\u7684\u69CB\u7BC9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc133/tasks/abc133_f
    links:
    - https://atcoder.jp/contests/abc133/tasks/abc133_f
  bundledCode: "#line 1 \"test/atcoder/abc133_f.DynSeg.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n\n// \u6C38\u7D9A\u914D\
    \u5217(at) \u306E verify\n\n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\
    \n/**\n * @title Segment-Tree(\u52D5\u7684\u69CB\u7BC9)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * \u9045\u5EF6\u4F1D\u642C\u53EF\n * \u6C38\u7D9A\u5316\u53EF\
    \n * O(logN)\n */\n\n// verify\u7528:\n// https://codeforces.com/contest/464/problem/E\
    \ (\u6C38\u7D9A+\u9045\u5EF6\u4F1D\u642C+find*2)\n// https://codeforces.com/contest/947/problem/C\
    \ (find+xor)\n// https://codeforces.com/contest/966/problem/C (find+xor)\n// https://codeforces.com/contest/295/problem/E\
    \ (\u7279\u6B8A\u30E2\u30CE\u30A4\u30C9+\u5EA7\u5727\u30B5\u30DC\u308A)\n\n//\
    \ BEGIN CUT HERE\n\n#define HAS_CHECK(member, Dummy)                         \
    \     \\\n  template <class T>                                          \\\n \
    \ struct has_##member {                                       \\\n    template\
    \ <class U, Dummy>                                 \\\n    static std::true_type\
    \ check(U *);                         \\\n    static std::false_type check(...);\
    \                        \\\n    static T *mClass;                           \
    \              \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    \ntemplate <typename M, bool persistent = false, std::uint8_t HEIGHT = 30>\nclass\
    \ SegmentTree_Dynamic {\n  HAS_MEMBER(op);\n  HAS_MEMBER(ti);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition)\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
    \ L>\n  using monoid = std::conjunction<has_T<L>, has_op<L>, has_ti<L>>;\n  template\
    \ <class L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  using id_t = long long;\n  template <class T, class\
    \ tDerived, class F = std::nullptr_t>\n  struct Node_B {\n    using E = F;\n \
    \   T val;\n    tDerived *ch[2] = {nullptr, nullptr};\n  };\n  template <bool\
    \ mo_, bool du_, typename tEnable = void>\n  struct Node_D : Node_B<M, Node_D<mo_,\
    \ du_, tEnable>> {};\n  template <bool mo_, bool du_>\n  struct Node_D<mo_, du_,\
    \ typename std::enable_if_t<mo_ && !du_>>\n      : Node_B<typename M::T, Node_D<mo_,\
    \ du_>> {};\n  template <bool mo_, bool du_>\n  struct Node_D<mo_, du_, typename\
    \ std::enable_if_t<du_>>\n      : Node_B<typename M::T, Node_D<mo_, du_>, typename\
    \ M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n  };\n  using\
    \ Node = Node_D<monoid<M>::value, dual<M>::value>;\n  using T = decltype(Node::val);\n\
    \  using E = typename Node::E;\n  Node *root;\n  static inline constexpr T def_val()\
    \ {\n    if constexpr (monoid<M>::value)\n      return M::ti();\n    else\n  \
    \    return T();\n  }\n  template <class S>\n  void build(Node *&t, const id_t\
    \ &n, std::array<id_t, 2> b, const S &bg) {\n    if (n <= b[0]) return;\n    id_t\
    \ m = (b[0] + b[1]) >> 1;\n    if (b[1] - b[0] == 1) {\n      if constexpr (std::is_same_v<S,\
    \ T>)\n        t = new Node{bg};\n      else\n        t = new Node{*(bg + b[0])};\n\
    \    } else {\n      t = new Node{def_val()};\n      build(t->ch[0], n, {b[0],\
    \ m}, bg), build(t->ch[1], n, {m, b[1]}, bg);\n      if constexpr (monoid<M>::value)\
    \ pushup(t);\n    }\n  }\n  void dump(Node *t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b,\n            typename std::vector<T>::iterator itr) {\n    if (r <= b[0]\
    \ || b[1] <= l) return;\n    if (l <= b[0] && b[1] <= r && !t) {\n      for (id_t\
    \ i = b[0]; i < b[1]; i++) *(itr + i) = def_val();\n    } else if (b[1] - b[0]\
    \ != 1) {\n      if constexpr (dual<M>::value) eval(t, b[1] - b[0]);\n      auto\
    \ m = (b[0] + b[1]) >> 1;\n      dump(t ? t->ch[0] : nullptr, l, r, {b[0], m},\
    \ itr);\n      dump(t ? t->ch[1] : nullptr, l, r, {m, b[1]}, itr);\n    } else\n\
    \      *(itr + b[0]) = t->val;\n  }\n  static inline void pushup(Node *&t) {\n\
    \    t->val = def_val();\n    if (t->ch[0]) t->val = M::op(t->ch[0]->val, t->val);\n\
    \    if (t->ch[1]) t->val = M::op(t->val, t->ch[1]->val);\n  }\n  static inline\
    \ void propagate(Node *&t, const E &x, const id_t &sz) {\n    t->lazy = t->lazy_flg\
    \ ? M::composition(t->lazy, x) : x;\n    t->val = M::mapping(t->val, x, sz), t->lazy_flg\
    \ = true;\n  }\n  static inline void cp_node(Node *&t) {\n    if (!t)\n      t\
    \ = new Node{def_val()};\n    else if constexpr (persistent)\n      t = new Node(*t);\n\
    \  }\n  static inline void eval(Node *&t, const id_t &sz) {\n    if (!t->lazy_flg)\
    \ return;\n    cp_node(t->ch[0]), cp_node(t->ch[1]), t->lazy_flg = false;\n  \
    \  propagate(t->ch[0], t->lazy, sz / 2), propagate(t->ch[1], t->lazy, sz / 2);\n\
    \  }\n  T fold(Node *&t, const id_t &l, const id_t &r, std::array<id_t, 2> b,\n\
    \         const id_t &bias) {\n    if (!t || r <= b[0] || b[1] <= l) return def_val();\n\
    \    if (l <= b[0] && b[1] <= r) return t->val;\n    if constexpr (dual<M>::value)\
    \ eval(t, b[1] - b[0]);\n    id_t m = (b[0] + b[1]) >> 1;\n    bool flg = (bias\
    \ >> (__builtin_ctzll(b[1] - b[0]) - 1)) & 1;\n    return M::op(fold(t->ch[flg],\
    \ l, r, {b[0], m}, bias),\n                 fold(t->ch[!flg], l, r, {m, b[1]},\
    \ bias));\n  }\n  void apply(Node *&t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b,\n             const E &x) {\n    if (r <= b[0] || b[1] <= l) return;\n\
    \    id_t m = (b[0] + b[1]) >> 1;\n    cp_node(t);\n    if (l <= b[0] && b[1]\
    \ <= r) return propagate(t, x, b[1] - b[0]), void();\n    eval(t, b[1] - b[0]);\n\
    \    apply(t->ch[0], l, r, {b[0], m}, x), apply(t->ch[1], l, r, {m, b[1]}, x);\n\
    \    if constexpr (monoid<M>::value) pushup(t);\n  }\n  void set_val(Node *&t,\
    \ const id_t &k, const T &val, std::uint8_t h) {\n    cp_node(t);\n    if (!h)\
    \ return t->val = val, void();\n    if constexpr (dual<M>::value) eval(t, 1LL\
    \ << h);\n    set_val(t->ch[(k >> (h - 1)) & 1], k, val, h - 1);\n    if constexpr\
    \ (monoid<M>::value) pushup(t);\n  }\n  T &at_val(Node *&t, const id_t &k, std::uint8_t\
    \ h) {\n    cp_node(t);\n    if (!h) return t->val;\n    if constexpr (dual<M>::value)\
    \ eval(t, 1LL << h);\n    return at_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n\
    \  }\n  bool is_null(Node *&t, const id_t &k, std::uint8_t h) {\n    if (!t) return\
    \ true;\n    if (!h) return false;\n    if constexpr (dual<M>::value) eval(t,\
    \ 1LL << h);\n    return is_null(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n\
    \  T get_val(Node *&t, const id_t &k, std::uint8_t h) {\n    if (!t) return def_val();\n\
    \    if (!h) return t->val;\n    if constexpr (dual<M>::value) eval(t, 1LL <<\
    \ h);\n    return get_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n  template\
    \ <bool last>\n  static inline T calc_op(Node *&t, const T &v) {\n    if constexpr\
    \ (last)\n      return M::op((t ? t->val : def_val()), v);\n    else\n      return\
    \ M::op(v, (t ? t->val : def_val()));\n  }\n  template <bool last>\n  static inline\
    \ bool is_in(const id_t &m, const id_t &k) {\n    if constexpr (last)\n      return\
    \ k <= m;\n    else\n      return m <= k;\n  }\n  template <bool last, class C,\
    \ std::size_t N>\n  static id_t find(const id_t &k, std::array<id_t, 2> b, const\
    \ id_t &bias,\n                   std::uint8_t h, const C &check, std::array<Node\
    \ *, N> &ts,\n                   std::array<T, N> &sums) {\n    static_assert(monoid<M>::value,\
    \ \"\\\"find\\\" is not available\\n\");\n    static std::array<T, N> sums2;\n\
    \    if (std::all_of(ts.begin(), ts.end(), [](Node *t) { return !t; }))\n    \
    \  return -1;\n    if (!h) {\n      for (std::size_t i = N; i--;) sums[i] = calc_op<last>(ts[i],\
    \ sums[i]);\n      return std::apply(check, sums) ? std::get<last>(b) : -1;\n\
    \    } else if (is_in<last>(k, b[0])) {\n      for (std::size_t i = N; i--;) sums2[i]\
    \ = calc_op<last>(ts[i], sums[i]);\n      if (!std::apply(check, sums2)) return\
    \ sums = std::move(sums2), -1;\n    }\n    if constexpr (dual<M>::value)\n   \
    \   for (std::size_t i = N; i--;) eval(ts[i], b[1] - b[0]);\n    std::array<Node\
    \ *, N> ss;\n    id_t m = (b[0] + b[1]) >> 1;\n    bool flg = (bias >> (h - 1))\
    \ & 1;\n    if (!is_in<last>(m, k)) {\n      for (std::size_t i = N; i--;) ss[i]\
    \ = ts[i] ? ts[i]->ch[flg] : nullptr;\n      id_t ret = find<last>(k, {b[0], m},\
    \ bias, h - 1, check, ss, sums);\n      if (ret >= 0) return ret;\n    }\n   \
    \ for (std::size_t i = N; i--;) ss[i] = ts[i] ? ts[i]->ch[!flg] : nullptr;\n \
    \   return find<last>(k, {m, b[1]}, bias, h - 1, check, ss, sums);\n  }\n\n public:\n\
    \  SegmentTree_Dynamic(Node *t = nullptr) : root(t) {}\n  SegmentTree_Dynamic(std::size_t\
    \ n, T val) : root(nullptr) {\n    build(root, n, {0, 1LL << HEIGHT}, val);\n\
    \  }\n  SegmentTree_Dynamic(T *bg, T *ed) : root(nullptr) {\n    build(root, ed\
    \ - bg, {0, 1LL << HEIGHT}, bg);\n  }\n  SegmentTree_Dynamic(const std::vector<T>\
    \ &ar)\n      : SegmentTree_Dynamic(ar.data(), ar.data() + ar.size()) {}\n  void\
    \ set(id_t k, T val) { set_val(root, k, val, HEIGHT); }\n  T get(id_t k) { return\
    \ get_val(root, k, HEIGHT); }\n  bool is_null(id_t k) { return is_null(root, k,\
    \ HEIGHT); }\n  T &at(id_t k) {\n    static_assert(!monoid<M>::value, \"\\\"at\\\
    \" is not available\\n\");\n    return at_val(root, k, HEIGHT);\n  }\n  template\
    \ <class L = M,\n            typename std::enable_if_t<monoid<L>::value> * = nullptr>\n\
    \  T operator[](id_t k) {\n    return get(k);\n  }\n  template <class L = M,\n\
    \            typename std::enable_if_t<!monoid<L>::value> * = nullptr>\n  T &operator[](id_t\
    \ k) {\n    return at(k);\n  }\n  T fold(id_t a, id_t b, id_t bias = 0) {\n  \
    \  static_assert(monoid<M>::value, \"\\\"fold\\\" is not available\\n\");\n  \
    \  return fold(root, a, b, {0, 1LL << HEIGHT}, bias);\n  }\n  // find i s.t.\n\
    \  //  check(fold(k,i)) == False, check(fold(k,i+1)) == True\n  // return -1 if\
    \ not found\n  template <class C>\n  id_t find_first(id_t a, C check, id_t bias\
    \ = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node *, 1> t{root};\n\
    \    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n  }\n\
    \  template <std::size_t N, class C>\n  static id_t find_first(id_t a, C check,\n\
    \                         std::array<SegmentTree_Dynamic, N> segs,\n         \
    \                id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  // find i s.t.\n  //  check(fold(i+1,k)) == False, check(fold(i,k))\
    \ == True\n  // return -1 if not found\n  template <class C>\n  id_t find_last(id_t\
    \ b, C check, id_t bias = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node\
    \ *, 1> t{root};\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ t, sum);\n  }\n  template <std::size_t N, class C>\n  static id_t find_last(id_t\
    \ b, C check,\n                        std::array<SegmentTree_Dynamic, N> segs,\n\
    \                        id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  void apply(id_t a, id_t b, E x) {\n    static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\\n\");\n    apply(root, a, b, {0, 1LL << HEIGHT},\
    \ x);\n  }\n  std::vector<T> dump(id_t bg, id_t ed) {\n    std::vector<T> ret(ed\
    \ - bg);\n    dump(root, bg, ed, {0, 1LL << HEIGHT}, ret.begin());\n    return\
    \ ret;\n  }\n  static std::string which_available() {\n    std::string ret = \"\
    \";\n    if constexpr (monoid<M>::value)\n      ret += \"\\\"fold\\\" \\\"find\\\
    \" \";\n    else\n      ret += \"\\\"at\\\" \";\n    if constexpr (dual<M>::value)\
    \ ret += \"\\\"apply\\\" \";\n    return ret;\n  }\n};\n#line 3 \"src/DataStructure/LinkCutTree.hpp\"\
    \n/**\n * @title Link-Cut-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n\
    \ * @brief O(logN)\n * \u5358\u4F4D\u5143\u306F\u5FC5\u8981\u306A\u3057\uFF08\u9045\
    \u5EF6\u5074\u3082\uFF09\n * \u5404\u30CE\u30FC\u30C9\u304C\u90E8\u5206\u6728\u306E\
    \u30B5\u30A4\u30BA\u3092\u4FDD\u6301\u3057\u3066\u3044\u306A\u3044\u306E\u3067\
    mapping\u95A2\u6570\u3067\u306F\u5F15\u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\
    \u306A\u3044\n */\n\n// BEGIN CUT HERE\n\n#define HAS_CHECK(member, Dummy)   \
    \                           \\\n  template <class T>                         \
    \                 \\\n  struct has_##member {                                \
    \       \\\n    template <class U, Dummy>                                 \\\n\
    \    static std::true_type check(U *);                         \\\n    static\
    \ std::false_type check(...);                        \\\n    static T *mClass;\
    \                                         \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    \ntemplate <typename M = void>\nclass LinkCutTree {\n  HAS_MEMBER(op);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition)\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
    \ L>\n  using semigroup = std::conjunction<has_T<L>, has_op<L>>;\n  template <class\
    \ L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class tDerived, class U = std::nullptr_t,\
    \ class F = std::nullptr_t>\n  struct Node_B {\n    using T = U;\n    using E\
    \ = F;\n    tDerived *ch[2], *par;\n    bool rev_flg;\n  };\n  template <bool\
    \ sg_, bool du_, typename tEnable = void>\n  struct Node_D : Node_B<Node_D<sg_,\
    \ du_, tEnable>> {};\n  template <bool sg_, bool du_>\n  struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && !du_>>\n      : Node_B<Node_D<sg_, du_>, typename\
    \ M::T> {\n    typename M::T val, sum, rsum;\n  };\n  template <bool sg_, bool\
    \ du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<!sg_ && du_>>\n  \
    \    : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  template <bool\
    \ sg_, bool du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<sg_ && du_>>\n\
    \      : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val, sum, rsum;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  using\
    \ Node = Node_D<semigroup<M>::value, dual<M>::value>;\n  using T = typename Node::T;\n\
    \  using E = typename Node::E;\n  inline int dir(Node *&t) {\n    if (t->par)\
    \ {\n      if (t->par->ch[0] == t) return 0;\n      if (t->par->ch[1] == t) return\
    \ 1;\n    }\n    return 2;\n  }\n  inline void rot(Node *t) {\n    Node *p = t->par;\n\
    \    int d = dir(t);\n    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par = p;\n   \
    \ t->ch[!d] = p;\n    if constexpr (semigroup<M>::value) pushup(p), pushup(t);\n\
    \    t->par = p->par;\n    if ((d = dir(p)) < 2) {\n      p->par->ch[d] = t;\n\
    \      if constexpr (semigroup<M>::value) pushup(t->par);\n    }\n    p->par =\
    \ t;\n  }\n  inline void splay(Node *t) {\n    eval(t);\n    for (int t_d = dir(t),\
    \ p_d; t_d < 2; rot(t), t_d = dir(t)) {\n      if ((p_d = dir(t->par)) < 2) eval(t->par->par);\n\
    \      eval(t->par), eval(t);\n      if (p_d < 2) rot(t_d == p_d ? t->par : t);\n\
    \    }\n  }\n  inline void pushup(Node *t) {\n    t->rsum = t->sum = t->val;\n\
    \    if (t->ch[0])\n      t->sum = M::op(t->ch[0]->sum, t->sum),\n      t->rsum\
    \ = M::op(t->rsum, t->ch[0]->rsum);\n    if (t->ch[1])\n      t->sum = M::op(t->sum,\
    \ t->ch[1]->sum),\n      t->rsum = M::op(t->ch[1]->rsum, t->rsum);\n  }\n  inline\
    \ void propagate(Node *t, const E &x) {\n    t->lazy = t->lazy_flg ? M::composition(t->lazy,\
    \ x) : x;\n    t->val = M::mapping(t->val, x);\n    if constexpr (semigroup<M>::value)\n\
    \      t->sum = M::mapping(t->sum, x), t->rsum = M::mapping(t->rsum, x);\n   \
    \ t->lazy_flg = true;\n  }\n  inline void toggle(Node *t) {\n    std::swap(t->ch[0],\
    \ t->ch[1]);\n    if constexpr (semigroup<M>::value) std::swap(t->sum, t->rsum);\n\
    \    t->rev_flg = !t->rev_flg;\n  }\n  inline void eval(Node *t) {\n    if constexpr\
    \ (dual<M>::value) {\n      if (t->lazy_flg) {\n        if (t->ch[0]) propagate(t->ch[0],\
    \ t->lazy);\n        if (t->ch[1]) propagate(t->ch[1], t->lazy);\n        t->lazy_flg\
    \ = false;\n      }\n    }\n    if (t->rev_flg) {\n      if (t->ch[0]) toggle(t->ch[0]);\n\
    \      if (t->ch[1]) toggle(t->ch[1]);\n      t->rev_flg = false;\n    }\n  }\n\
    \  inline Node *expose(Node *t) {\n    Node *r = nullptr;\n    for (Node *p =\
    \ t; p; r = p, p = p->par) {\n      splay(p), p->ch[1] = r;\n      if constexpr\
    \ (semigroup<M>::value) pushup(p);\n    }\n    return splay(t), r;\n  }\n  std::vector<Node>\
    \ ns;\n\n public:\n  LinkCutTree(std::size_t n) : ns(n) {}\n  LinkCutTree(std::size_t\
    \ n, T val) : ns(n) {\n    for (std::size_t i = n; i--;) ns[i].val = val;\n  }\n\
    \  void evert(std::size_t k) { expose(&ns[k]), toggle(&ns[k]), eval(&ns[k]); }\n\
    \  void link(std::size_t c, std::size_t p) {\n    evert(c), expose(&ns[p]);\n\
    \    assert(!ns[c].par);\n    ns[p].ch[1] = &ns[c], ns[c].par = &ns[p];\n    if\
    \ constexpr (semigroup<M>::value) pushup(&ns[p]);\n  }\n  void cut(std::size_t\
    \ c, std::size_t p) {\n    evert(p), expose(&ns[c]);\n    assert(ns[c].ch[0] ==\
    \ &ns[p]);\n    ns[c].ch[0] = ns[c].ch[0]->par = nullptr;\n    if constexpr (semigroup<M>::value)\
    \ pushup(&ns[c]);\n  }\n  int par(std::size_t x) {\n    expose(&ns[x]);\n    Node\
    \ *t = ns[x].ch[0];\n    if (!t) return -1;\n    while (t->ch[1]) eval(t), t =\
    \ t->ch[1];\n    return splay(t), t - &ns[0];\n  }\n  int lca(std::size_t x, std::size_t\
    \ y) {\n    if (x == y) return x;\n    expose(&ns[x]);\n    Node *u = expose(&ns[y]);\n\
    \    return ns[x].par ? u - &ns[0] : -1;\n  }\n  const T &operator[](std::size_t\
    \ k) { return get(k); }\n  const T &get(std::size_t k) {\n    static_assert(semigroup<M>::value\
    \ || dual<M>::value,\n                  \"\\\"get\\\" is not available\\n\");\n\
    \    return expose(&ns[k]), ns[k].val;\n  }\n  void set(std::size_t k, T v) {\n\
    \    static_assert(semigroup<M>::value || dual<M>::value,\n                  \"\
    \\\"set\\\" is not available\\n\");\n    expose(&ns[k]), ns[k].val = v;\n    if\
    \ constexpr (semigroup<M>::value) pushup(&ns[k]);\n  }\n  T fold(std::size_t a,\
    \ std::size_t b) {  // [a,b] closed section\n    static_assert(semigroup<M>::value,\
    \ \"\\\"fold\\\" is not available\\n\");\n    return evert(a), expose(&ns[b]),\
    \ ns[b].sum;\n  }\n  void apply(std::size_t a, std::size_t b, E v) {  // [a,b]\
    \ closed section\n    static_assert(dual<M>::value, \"\\\"apply\\\" is not available\\\
    n\");\n    evert(a), expose(&ns[b]), propagate(&ns[b], v), eval(&ns[b]);\n  }\n\
    \  static std::string which_available() {\n    std::string ret = \"\";\n    if\
    \ constexpr (semigroup<M>::value || dual<M>::value)\n      ret += \"\\\"set\\\"\
    \ \\\"get\\\" \";\n    if constexpr (semigroup<M>::value) ret += \"\\\"fold\\\"\
    \ \";\n    if constexpr (dual<M>::value) ret += \"\\\"apply\\\" \";\n    return\
    \ ret;\n  }\n};\n#line 8 \"test/atcoder/abc133_f.DynSeg.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n\
    \  cin >> N >> Q;\n  LinkCutTree lct(N);\n  vector<tuple<int, int, int>> adj[N];\n\
    \  for (int i = 0; i < N - 1; i++) {\n    int a, b, c, d;\n    cin >> a >> b >>\
    \ c >> d;\n    lct.link(--a, --b);\n    adj[a].emplace_back(b, c, d);\n    adj[b].emplace_back(a,\
    \ c, d);\n  }\n  using PerArr = SegmentTree_Dynamic<int, true, 17>;\n  PerArr\
    \ Arr1[N], Arr2[N];\n  int sum[N];\n  sum[0] = 0;\n  auto dfs = [&adj, &Arr1,\
    \ &Arr2, &sum](auto f, int v, int p) -> void {\n    for (auto [u, c, d] : adj[v])\n\
    \      if (u != p) {\n        Arr1[u] = Arr1[v], Arr2[u] = Arr2[v];\n        Arr1[u][c]\
    \ += 1, Arr2[u][c] += d;\n        sum[u] = sum[v] + d;\n        f(f, u, v);\n\
    \      }\n  };\n  dfs(dfs, 0, -1);\n  lct.evert(0);\n  for (int i = 0; i < Q;\
    \ i++) {\n    int x, y, u, v;\n    cin >> x >> y >> u >> v;\n    int lca = lct.lca(--u,\
    \ --v);\n    cout << sum[u] + sum[v] - 2 * sum[lca] +\n                y * (Arr1[u].get(x)\
    \ + Arr1[v].get(x) - 2 * Arr1[lca].get(x)) -\n                (Arr2[u].get(x)\
    \ + Arr2[v].get(x) - 2 * Arr2[lca].get(x))\n         << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n\n\
    // \u6C38\u7D9A\u914D\u5217(at) \u306E verify\n\n#include <bits/stdc++.h>\n#include\
    \ \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include \"src/DataStructure/LinkCutTree.hpp\"\
    \nusing namespace std;\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  LinkCutTree lct(N);\n  vector<tuple<int, int,\
    \ int>> adj[N];\n  for (int i = 0; i < N - 1; i++) {\n    int a, b, c, d;\n  \
    \  cin >> a >> b >> c >> d;\n    lct.link(--a, --b);\n    adj[a].emplace_back(b,\
    \ c, d);\n    adj[b].emplace_back(a, c, d);\n  }\n  using PerArr = SegmentTree_Dynamic<int,\
    \ true, 17>;\n  PerArr Arr1[N], Arr2[N];\n  int sum[N];\n  sum[0] = 0;\n  auto\
    \ dfs = [&adj, &Arr1, &Arr2, &sum](auto f, int v, int p) -> void {\n    for (auto\
    \ [u, c, d] : adj[v])\n      if (u != p) {\n        Arr1[u] = Arr1[v], Arr2[u]\
    \ = Arr2[v];\n        Arr1[u][c] += 1, Arr2[u][c] += d;\n        sum[u] = sum[v]\
    \ + d;\n        f(f, u, v);\n      }\n  };\n  dfs(dfs, 0, -1);\n  lct.evert(0);\n\
    \  for (int i = 0; i < Q; i++) {\n    int x, y, u, v;\n    cin >> x >> y >> u\
    \ >> v;\n    int lca = lct.lca(--u, --v);\n    cout << sum[u] + sum[v] - 2 * sum[lca]\
    \ +\n                y * (Arr1[u].get(x) + Arr1[v].get(x) - 2 * Arr1[lca].get(x))\
    \ -\n                (Arr2[u].get(x) + Arr2[v].get(x) - 2 * Arr2[lca].get(x))\n\
    \         << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Dynamic.hpp
  - src/DataStructure/LinkCutTree.hpp
  isVerificationFile: true
  path: test/atcoder/abc133_f.DynSeg.test.cpp
  requiredBy: []
  timestamp: '2021-11-21 18:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc133_f.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc133_f.DynSeg.test.cpp
- /verify/test/atcoder/abc133_f.DynSeg.test.cpp.html
title: test/atcoder/abc133_f.DynSeg.test.cpp
---
