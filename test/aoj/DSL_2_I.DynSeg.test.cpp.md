---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/DynamicSegmentTree.hpp
    title: "\u52D5\u7684\u69CB\u7BC9Segment-Tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"test/aoj/DSL_2_I.DynSeg.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\n\n//\
    \ \u9045\u5EF6\u4F1D\u642C\u306Everify\n\n#include <bits/stdc++.h>\n#line 3 \"\
    src/DataStructure/DynamicSegmentTree.hpp\"\n/**\n * @title \u52D5\u7684\u69CB\u7BC9\
    Segment-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * \u6C38\u7D9A\u5316\
    \u53EF\n * \u30D1\u30C8\u30EA\u30B7\u30A2\u6728\u30AA\u30D7\u30B7\u30E7\u30F3\u3067\
    \u30E1\u30E2\u30EA\u7BC0\u7D04\u3067\u304D\u308B\u304B\u3082\uFF08\u30B9\u30D1\
    \u30FC\u30B9\u306A\u3089\u52B9\u679C\u5927\uFF09\n * O(logN)\n */\n\n// verify\u7528\
    :\n// https://codeforces.com/contest/464/problem/E (\u6C38\u7D9A+\u9045\u5EF6\u4F1D\
    \u642C+find*2)\n// https://codeforces.com/contest/947/problem/C (find+xor)\n//\
    \ https://codeforces.com/contest/966/problem/C (find+xor)\n// https://codeforces.com/contest/295/problem/E\
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
    \ntemplate <typename M, bool persistent = false, std::uint8_t HEIGHT = 30,\n \
    \         bool patricia = false>\nclass DynamicSegmentTree {\n  HAS_MEMBER(op);\n\
    \  HAS_MEMBER(ti);\n  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition)\n  HAS_TYPE(T);\n\
    \  HAS_TYPE(E);\n  template <class L>\n  using monoid = std::conjunction<has_T<L>,\
    \ has_op<L>, has_ti<L>>;\n  template <class L>\n  using dual =\n      std::conjunction<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n  using id_t = long long;\n\
    \  template <class T, class tDerived, class F = std::nullptr_t>\n  struct Node_B\
    \ {\n    using E = F;\n    T val;\n    tDerived *ch[2] = {nullptr, nullptr};\n\
    \    Node_B(id_t b = 0, std::uint8_t l = 0, T v = def_val()) : val(v) {}\n  };\n\
    \  template <class T, class tDerived, class F = std::nullptr_t>\n  struct Node_P\
    \ : public Node_B<T, tDerived, F> {\n    id_t bits;\n    std::uint8_t len;\n \
    \   Node_P(id_t b = 0, std::uint8_t l = 0, T v = def_val())\n        : Node_B<T,\
    \ tDerived, F>(b, l, v), bits(b), len(l) {}\n  };\n  template <bool mo_, bool\
    \ du_, bool pa_, typename tEnable = void>\n  struct Node_D : Node_B<M, Node_D<mo_,\
    \ du_, pa_, tEnable>> {\n    using Node_B<M, Node_D<mo_, du_, pa_, tEnable>>::Node_B;\n\
    \  };\n  template <bool mo_, bool du_, bool pa_>\n  struct Node_D<mo_, du_, pa_,\
    \ typename std::enable_if_t<mo_ && !du_ && !pa_>>\n      : Node_B<typename M::T,\
    \ Node_D<mo_, du_, pa_>> {\n    using Node_B<typename M::T, Node_D<mo_, du_, pa_>>::Node_B;\n\
    \  };\n  template <bool mo_, bool du_, bool pa_>\n  struct Node_D<mo_, du_, pa_,\
    \ typename std::enable_if_t<du_ && !pa_>>\n      : Node_B<typename M::T, Node_D<mo_,\
    \ du_, pa_>, typename M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n\
    \    using Node_B<typename M::T, Node_D<mo_, du_, pa_>, typename M::E>::Node_B;\n\
    \  };\n  template <bool mo_, bool du_, bool pa_>\n  struct Node_D<mo_, du_, pa_,\
    \ typename std::enable_if_t<!mo_ && !du_ && pa_>>\n      : Node_P<M, Node_D<mo_,\
    \ du_, pa_>> {\n    using Node_P<M, Node_D<mo_, du_, pa_>>::Node_P;\n  };\n  template\
    \ <bool mo_, bool du_, bool pa_>\n  struct Node_D<mo_, du_, pa_, typename std::enable_if_t<mo_\
    \ && !du_ && pa_>>\n      : Node_P<typename M::T, Node_D<mo_, du_, pa_>> {\n \
    \   using Node_P<typename M::T, Node_D<mo_, du_, pa_>>::Node_P;\n  };\n  template\
    \ <bool mo_, bool du_, bool pa_>\n  struct Node_D<mo_, du_, pa_, typename std::enable_if_t<du_\
    \ && pa_>>\n      : Node_P<typename M::T, Node_D<mo_, du_, pa_>, typename M::E>\
    \ {\n    typename M::E lazy;\n    bool lazy_flg = false;\n    using Node_P<typename\
    \ M::T, Node_D<mo_, du_, pa_>, typename M::E>::Node_P;\n  };\n  using Node = Node_D<monoid<M>::value,\
    \ dual<M>::value, patricia>;\n  using T = decltype(Node::val);\n  using E = typename\
    \ Node::E;\n  Node *root;\n  static inline constexpr T def_val() {\n    if constexpr\
    \ (monoid<M>::value)\n      return M::ti();\n    else\n      return T();\n  }\n\
    \  template <class S>\n  void build(Node *&t, const id_t &n, std::array<id_t,\
    \ 2> b, const S &bg) {\n    if (n <= b[0]) return;\n    id_t m = (b[0] + b[1])\
    \ >> 1;\n    if constexpr (patricia)\n      while (n <= m) b[1] = m, m = (b[0]\
    \ + b[1]) >> 1;\n    if (b[1] - b[0] == 1) {\n      if constexpr (std::is_same_v<S,\
    \ T>)\n        t = new Node(b[0], HEIGHT + 1, bg);\n      else\n        t = new\
    \ Node(b[0], HEIGHT + 1, *(bg + b[0]));\n    } else {\n      std::uint8_t h =\
    \ __builtin_ctzll(b[1] - b[0]);\n      t = new Node(m >> h, std::uint8_t(HEIGHT\
    \ + 1 - h));\n      build(t->ch[0], n, {b[0], m}, bg), build(t->ch[1], n, {m,\
    \ b[1]}, bg);\n      if constexpr (monoid<M>::value) pushup(t);\n    }\n  }\n\
    \  void dump(Node *t, const id_t &l, const id_t &r, std::array<id_t, 2> b,\n \
    \           typename std::vector<T>::iterator itr, std::uint8_t h) {\n    if (r\
    \ <= b[0] || b[1] <= l) return;\n    if (l <= b[0] && b[1] <= r && !t) {\n   \
    \   for (id_t i = b[0]; i < b[1]; i++) *(itr + i) = def_val();\n    } else if\
    \ (b[1] - b[0] != 1) {\n      if constexpr (dual<M>::value) eval(t, b[1] - b[0]);\n\
    \      auto m = (b[0] + b[1]) >> 1;\n      dump(next(t, h, 0), l, r, {b[0], m},\
    \ itr, h - 1);\n      dump(next(t, h, 1), l, r, {m, b[1]}, itr, h - 1);\n    }\
    \ else\n      *(itr + b[0]) = t->val;\n  }\n  static inline void pushup(Node *&t)\
    \ {\n    t->val = def_val();\n    if (t->ch[0]) t->val = M::op(t->ch[0]->val,\
    \ t->val);\n    if (t->ch[1]) t->val = M::op(t->val, t->ch[1]->val);\n  }\n  static\
    \ inline void separate(Node *&t, const std::uint8_t &len) {\n    if (len <= 1)\
    \ return;\n    bool flg = (t->bits >> (len - 2)) & 1;\n    t->ch[flg] = new Node{*t},\
    \ t->ch[!flg] = nullptr;\n    t->len -= len - 1, t->bits >>= len - 1;\n  }\n \
    \ static inline void propagate(Node *&t, const E &x, const id_t &sz) {\n    t->lazy\
    \ = t->lazy_flg ? M::composition(t->lazy, x) : x;\n    t->val = M::mapping(t->val,\
    \ x, sz);\n    t->lazy_flg = true;\n  }\n  template <bool r>\n  static inline\
    \ void cp_eval(Node *&t) {\n    if (!t->ch[r]) {\n      if constexpr (patricia)\n\
    \        t->ch[r] = new Node((t->bits << 1) | r, std::uint8_t(t->len + 1));\n\
    \      else\n        t->ch[r] = new Node();\n    } else if constexpr (persistent)\n\
    \      t->ch[r] = new Node(*t->ch[r]);\n  }\n  static inline void eval(Node *&t,\
    \ const id_t &sz) {\n    if (!t->lazy_flg) return;\n    cp_eval<0>(t), cp_eval<1>(t);\n\
    \    if constexpr (patricia)\n      separate(t->ch[0], t->ch[0]->len - t->len),\n\
    \          separate(t->ch[1], t->ch[1]->len - t->len);\n    propagate(t->ch[0],\
    \ t->lazy, sz / 2), propagate(t->ch[1], t->lazy, sz / 2);\n    t->lazy_flg = false;\n\
    \  }\n  T fold(Node *&t, const id_t &l, const id_t &r, std::array<id_t, 2> b,\n\
    \         const id_t &bias) {\n    if (!t || r <= b[0] || b[1] <= l) return def_val();\n\
    \    if (l <= b[0] && b[1] <= r) return t->val;\n    if constexpr (dual<M>::value)\
    \ eval(t, b[1] - b[0]);\n    id_t m = (b[0] + b[1]) >> 1;\n    bool flg = (bias\
    \ >> (__builtin_ctzll(b[1] - b[0]) - 1)) & 1;\n    return M::op(fold(t->ch[flg],\
    \ l, r, {b[0], m}, bias),\n                 fold(t->ch[!flg], l, r, {m, b[1]},\
    \ bias));\n  }\n  T fold(Node *&t, const id_t &l, const id_t &r, const id_t &bias)\
    \ {\n    static id_t bits, b[2];\n    if (!t) return def_val();\n    std::uint8_t\
    \ h = (HEIGHT + 1) - t->len;\n    bits = (bias >> h) ^ t->bits, b[0] = bits <<\
    \ h, b[1] = (bits + 1) << h;\n    if (r <= b[0] || b[1] <= l) return def_val();\n\
    \    if (l <= b[0] && b[1] <= r) return t->val;\n    if constexpr (dual<M>::value)\
    \ eval(t, b[1] - b[0]);\n    bool flg = (bias >> (h - 1)) & 1;\n    return M::op(fold(t->ch[flg],\
    \ l, r, bias), fold(t->ch[!flg], l, r, bias));\n  }\n  void apply(Node *&t, const\
    \ id_t &l, const id_t &r, std::array<id_t, 2> b,\n             const E &x) {\n\
    \    if (r <= b[0] || b[1] <= l) return;\n    std::uint8_t h = __builtin_ctzll(b[1]\
    \ - b[0]);\n    id_t m = (b[0] + b[1]) >> 1;\n    if (!t) {\n      t = new Node(m\
    \ >> h, std::uint8_t(HEIGHT + 1 - h));\n    } else if constexpr (persistent)\n\
    \      t = new Node{*t};\n    if constexpr (patricia) separate(t, h + t->len -\
    \ HEIGHT);\n    if (l <= b[0] && b[1] <= r) return propagate(t, x, b[1] - b[0]),\
    \ void();\n    eval(t, b[1] - b[0]);\n    apply(t->ch[0], l, r, {b[0], m}, x),\
    \ apply(t->ch[1], l, r, {m, b[1]}, x);\n    if constexpr (monoid<M>::value) pushup(t);\n\
    \  }\n  void set_val(Node *&t, const id_t &k, const T &val, std::uint8_t h) {\n\
    \    if (!t)\n      t = new Node(0, 0, val);\n    else if constexpr (persistent)\n\
    \      t = new Node{*t};\n    if (!h) return t->val = val, void();\n    if constexpr\
    \ (dual<M>::value) eval(t, 1LL << h);\n    set_val(t->ch[(k >> (h - 1)) & 1],\
    \ k, val, h - 1);\n    if constexpr (monoid<M>::value) pushup(t);\n  }\n  void\
    \ set_val(Node *&t, const id_t &k, const T &val) {\n    if (!t) return t = new\
    \ Node(k, HEIGHT + 1, val), void();\n    if constexpr (persistent) t = new Node{*t};\n\
    \    id_t bits = (k >> ((HEIGHT + 1) - t->len));\n    if (bits != t->bits) {\n\
    \      std::uint8_t i = 64 - __builtin_clzll(bits ^ t->bits);\n      bool flg\
    \ = (t->bits >> (i - 1)) & 1;\n      t->ch[flg] = new Node{*t}, t->ch[!flg] =\
    \ new Node(k, HEIGHT + 1, val);\n      t->len -= i, t->bits >>= i;\n    } else\
    \ if (t->len != HEIGHT + 1) {\n      if constexpr (dual<M>::value) eval(t, HEIGHT\
    \ + 1 - t->len);\n      set_val(t->ch[(k >> (HEIGHT - t->len)) & 1], k, val);\n\
    \    } else\n      return t->val = val, void();\n    if constexpr (monoid<M>::value)\
    \ pushup(t);\n  }\n  T &at_val(Node *&t, const id_t &k, std::uint8_t h) {\n  \
    \  if (!t)\n      t = new Node();\n    else if constexpr (persistent)\n      t\
    \ = new Node{*t};\n    if (!h) return t->val;\n    if constexpr (dual<M>::value)\
    \ eval(t, 1LL << h);\n    return at_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n\
    \  }\n  T &at_val(Node *&t, const id_t &k) {\n    if (!t) return t = new Node(k,\
    \ HEIGHT + 1), t->val;\n    if constexpr (persistent) t = new Node{*t};\n    id_t\
    \ bits = (k >> ((HEIGHT + 1) - t->len));\n    if (bits != t->bits) {\n      std::uint8_t\
    \ i = 64 - __builtin_clzll(bits ^ t->bits);\n      bool flg = (t->bits >> (i -\
    \ 1)) & 1;\n      t->ch[flg] = new Node{*t}, t->ch[!flg] = new Node(k, HEIGHT\
    \ + 1);\n      t->len -= i, t->bits >>= i;\n      return t->val;\n    } else if\
    \ (t->len != HEIGHT + 1) {\n      if constexpr (dual<M>::value) eval(t, HEIGHT\
    \ + 1 - t->len);\n      return at_val(t->ch[(k >> (HEIGHT - t->len)) & 1], k);\n\
    \    }\n    return t->val;\n  }\n  bool is_null(Node *&t, const id_t &k, std::uint8_t\
    \ h) {\n    if (!t) return true;\n    if (!h) return false;\n    if constexpr\
    \ (dual<M>::value) eval(t, 1LL << h);\n    return is_null(t->ch[(k >> (h - 1))\
    \ & 1], k, h - 1);\n  }\n  bool is_null(Node *&t, const id_t &k) {\n    if (!t\
    \ || (k >> ((HEIGHT + 1) - t->len)) != t->bits) return true;\n    if (t->len ==\
    \ HEIGHT + 1) return false;\n    if constexpr (dual<M>::value) eval(t, HEIGHT\
    \ + 1 - t->len);\n    return is_null(t->ch[(k >> (HEIGHT - t->len)) & 1], k);\n\
    \  }\n  T get_val(Node *&t, const id_t &k, std::uint8_t h) {\n    if (!t) return\
    \ def_val();\n    if (!h) return t->val;\n    if constexpr (dual<M>::value) eval(t,\
    \ 1LL << h);\n    return get_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n\
    \  T get_val(Node *&t, const id_t &k) {\n    if (!t || (k >> ((HEIGHT + 1) - t->len))\
    \ != t->bits) return def_val();\n    if (t->len == HEIGHT + 1) return t->val;\n\
    \    if constexpr (dual<M>::value) eval(t, HEIGHT + 1 - t->len);\n    return get_val(t->ch[(k\
    \ >> (HEIGHT - t->len)) & 1], k);\n  }\n  template <bool last>\n  static inline\
    \ T calc_op(Node *&t, const T &v) {\n    if constexpr (last)\n      return M::op((t\
    \ ? t->val : def_val()), v);\n    else\n      return M::op(v, (t ? t->val : def_val()));\n\
    \  }\n  template <bool last>\n  static inline bool is_in(const id_t &m, const\
    \ id_t &k) {\n    if constexpr (last)\n      return k <= m;\n    else\n      return\
    \ m <= k;\n  }\n  static inline Node *next(Node *&t, const std::uint8_t &h, const\
    \ bool &f) {\n    if constexpr (patricia) {\n      if (!t) return nullptr;\n \
    \     std::uint8_t len = h + t->len - (HEIGHT + 1);\n      if (!len) return t->ch[f];\n\
    \      return (f == ((t->bits >> (len - 1)) & 1)) ? t : nullptr;\n    } else\n\
    \      return t ? t->ch[f] : nullptr;\n  }\n  template <bool last, class C, std::size_t\
    \ N>\n  static id_t find(const id_t &k, std::array<id_t, 2> b, const id_t &bias,\n\
    \                   std::uint8_t h, const C &check, std::array<Node *, N> &ts,\n\
    \                   std::array<T, N> &sums) {\n    static_assert(monoid<M>::value,\
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
    \ = next(ts[i], h, flg);\n      id_t ret = find<last>(k, {b[0], m}, bias, h -\
    \ 1, check, ss, sums);\n      if (ret >= 0) return ret;\n    }\n    for (std::size_t\
    \ i = N; i--;) ss[i] = next(ts[i], h, !flg);\n    return find<last>(k, {m, b[1]},\
    \ bias, h - 1, check, ss, sums);\n  }\n\n public:\n  DynamicSegmentTree(Node *t\
    \ = nullptr) : root(t) {}\n  DynamicSegmentTree(std::size_t n, T val) {\n    build(root,\
    \ n, {0, 1LL << HEIGHT}, val);\n  }\n  DynamicSegmentTree(T *bg, T *ed) {\n  \
    \  build(root, ed - bg, {0, 1LL << HEIGHT}, bg);\n  }\n  DynamicSegmentTree(const\
    \ std::vector<T> &ar) {\n    build(root, ar.size(), {0, 1LL << HEIGHT}, ar.data());\n\
    \  }\n  void set(id_t k, T val) {\n    if constexpr (patricia)\n      set_val(root,\
    \ k, val);\n    else\n      set_val(root, k, val, HEIGHT);\n  }\n  T get(id_t\
    \ k) {\n    if constexpr (patricia)\n      return get_val(root, k);\n    else\n\
    \      return get_val(root, k, HEIGHT);\n  }\n  bool is_null(id_t k) {\n    if\
    \ constexpr (patricia)\n      return is_null(root, k);\n    else\n      return\
    \ is_null(root, k, HEIGHT);\n  }\n  T &at(id_t k) {\n    static_assert(!monoid<M>::value,\
    \ \"\\\"at\\\" is not available\\n\");\n    if constexpr (patricia)\n      return\
    \ at_val(root, k);\n    else\n      return at_val(root, k, HEIGHT);\n  }\n  template\
    \ <class L = M,\n            typename std::enable_if_t<monoid<L>::value> * = nullptr>\n\
    \  T operator[](id_t k) {\n    return get(k);\n  }\n  template <class L = M,\n\
    \            typename std::enable_if_t<!monoid<L>::value> * = nullptr>\n  T &operator[](id_t\
    \ k) {\n    return at(k);\n  }\n  T fold(id_t a, id_t b, id_t bias = 0) {\n  \
    \  static_assert(monoid<M>::value, \"\\\"fold\\\" is not available\\n\");\n  \
    \  if constexpr (patricia)\n      return fold(root, a, b, bias);\n    else\n \
    \     return fold(root, a, b, {0, 1LL << HEIGHT}, bias);\n  }\n  // find i s.t.\n\
    \  //  check(fold(k,i)) == False, check(fold(k,i+1)) == True\n  // return -1 if\
    \ not found\n  template <class C>\n  id_t find_first(id_t a, C check, id_t bias\
    \ = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node *, 1> t{root};\n\
    \    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n  }\n\
    \  template <std::size_t N, class C>\n  static id_t find_first(id_t a, C check,\n\
    \                         std::array<DynamicSegmentTree, N> segs,\n          \
    \               id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  // find i s.t.\n  //  check(fold(i+1,k)) == False, check(fold(i,k))\
    \ == True\n  // return -1 if not found\n  template <class C>\n  id_t find_last(id_t\
    \ b, C check, id_t bias = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node\
    \ *, 1> t{root};\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ t, sum);\n  }\n  template <std::size_t N, class C>\n  static id_t find_last(id_t\
    \ b, C check, std::array<DynamicSegmentTree, N> segs,\n                      \
    \  id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n \
    \   std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i] =\
    \ segs[i].root;\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  void apply(id_t a, id_t b, E x) {\n    static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\\n\");\n    apply(root, a, b, {0, 1LL << HEIGHT},\
    \ x);\n  }\n  std::vector<T> dump(id_t bg, id_t ed) {\n    std::vector<T> ret(ed\
    \ - bg);\n    dump(root, bg, ed, {0, 1LL << HEIGHT}, ret.begin(), HEIGHT);\n \
    \   return ret;\n  }\n  static std::string which_available() {\n    std::string\
    \ ret = \"\";\n    if constexpr (monoid<M>::value)\n      ret += \"\\\"fold\\\"\
    \ \\\"find\\\"\";\n    else\n      ret += \"\\\"at\\\" \";\n    if constexpr (dual<M>::value)\
    \ ret += \"\\\"apply\\\" \";\n    return ret;\n  }\n};\n#line 8 \"test/aoj/DSL_2_I.DynSeg.test.cpp\"\
    \n\nusing namespace std;\n\nstruct RSQandRUQ {\n  using T = int;\n  using E =\
    \ int;\n  static T op(T l, T r) { return l + r; }\n  static T ti() { return 0;\
    \ }\n  static T mapping(T v, E f, int sz) { return f * sz; }\n  static T composition(E\
    \ pre, E suf) { return suf; }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n >> q;\n  DynamicSegmentTree<RSQandRUQ> seg(n, 0);\n \
    \ for (int i = 0; i < q; i++) {\n    int op, s, t;\n    cin >> op >> s >> t;\n\
    \    if (op == 0) {\n      int x;\n      cin >> x;\n      seg.apply(s, t + 1,\
    \ x);\n    } else {\n      cout << seg.fold(s, t + 1) << '\\n';\n    }\n  }\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n\n// \u9045\u5EF6\u4F1D\u642C\u306Everify\n\n#include <bits/stdc++.h>\n#include\
    \ \"src/DataStructure/DynamicSegmentTree.hpp\"\n\nusing namespace std;\n\nstruct\
    \ RSQandRUQ {\n  using T = int;\n  using E = int;\n  static T op(T l, T r) { return\
    \ l + r; }\n  static T ti() { return 0; }\n  static T mapping(T v, E f, int sz)\
    \ { return f * sz; }\n  static T composition(E pre, E suf) { return suf; }\n};\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int n, q;\n  cin\
    \ >> n >> q;\n  DynamicSegmentTree<RSQandRUQ> seg(n, 0);\n  for (int i = 0; i\
    \ < q; i++) {\n    int op, s, t;\n    cin >> op >> s >> t;\n    if (op == 0) {\n\
    \      int x;\n      cin >> x;\n      seg.apply(s, t + 1, x);\n    } else {\n\
    \      cout << seg.fold(s, t + 1) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/DynamicSegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_I.DynSeg.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 14:08:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_I.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_I.DynSeg.test.cpp
- /verify/test/aoj/DSL_2_I.DynSeg.test.cpp.html
title: test/aoj/DSL_2_I.DynSeg.test.cpp
---
