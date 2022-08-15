---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.Patricia.test.cpp
    title: test/aoj/2270.Patricia.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3024.Patricia.test.cpp
    title: test/aoj/3024.Patricia.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.Patricia.test.cpp
    title: test/atcoder/abc133_f.Patricia.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.Patricia.test.cpp
    title: test/yosupo/set_xor_min.Patricia.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.Patricia.test.cpp
    title: test/yukicoder/649.Patricia.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment-Tree(\u30D1\u30C8\u30EA\u30B7\u30A2\u6728)"
    links:
    - https://atcoder.jp/contests/kupc2018/tasks/kupc2018_m
    - https://codeforces.com/contest/295/problem/E
    - https://codeforces.com/contest/947/problem/C
    - https://codeforces.com/contest/966/problem/C
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_Patricia.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Segment-Tree(\u30D1\u30C8\u30EA\u30B7\u30A2\u6728)\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * \u30B9\u30D1\u30FC\u30B9\u306A\u3089\u30E1\
    \u30E2\u30EA\u7BC0\u7D04\u3067\u304D\u308B\u304B\u3082\n * \u9045\u5EF6\u4F1D\u642C\
    \u4E0D\u53EF\n * \u6C38\u7D9A\u5316\u53EF\n * O(logN)\n */\n\n// verify\u7528\
    :\n// https://codeforces.com/contest/947/problem/C (find+xor)\n// https://codeforces.com/contest/966/problem/C\
    \ (find+xor)\n// https://codeforces.com/contest/295/problem/E (\u7279\u6B8A\u30E2\
    \u30CE\u30A4\u30C9+\u5EA7\u5727\u30B5\u30DC\u308A)\n// https://atcoder.jp/contests/kupc2018/tasks/kupc2018_m\
    \ (\u30D1\u30C8\u30EA\u30B7\u30A2\u306E\u52B9\u529B\u767A\u63EE)\n\n// BEGIN CUT\
    \ HERE\n\n#define HAS_CHECK(member, Dummy)                              \\\n \
    \ template <class T>                                          \\\n  struct has_##member\
    \ {                                       \\\n    template <class U, Dummy>  \
    \                               \\\n    static std::true_type check(U *);    \
    \                     \\\n    static std::false_type check(...);             \
    \           \\\n    static T *mClass;                                        \
    \ \\\n    static const bool value = decltype(check(mClass))::value; \\\n  };\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\ntemplate\
    \ <typename M, bool persistent = false, std::uint8_t HEIGHT = 30>\nclass SegmentTree_Patricia\
    \ {\n  HAS_MEMBER(op);\n  HAS_MEMBER(ti);\n  HAS_TYPE(T);\n  template <class L>\n\
    \  using monoid = std::conjunction<has_T<L>, has_op<L>, has_ti<L>>;\n  using id_t\
    \ = long long;\n  template <class T, class tDerived>\n  struct Node_B {\n    id_t\
    \ bits;\n    std::uint8_t len;\n    T val;\n    tDerived *ch[2] = {nullptr, nullptr};\n\
    \  };\n  template <bool mo_, typename tEnable = void>\n  struct Node_D : Node_B<M,\
    \ Node_D<mo_, tEnable>> {};\n  template <bool mo_>\n  struct Node_D<mo_, typename\
    \ std::enable_if_t<mo_>>\n      : Node_B<typename M::T, Node_D<mo_>> {};\n  using\
    \ Node = Node_D<monoid<M>::value>;\n  using T = decltype(Node::val);\n  Node *root;\n\
    \  static inline constexpr T def_val() {\n    if constexpr (monoid<M>::value)\n\
    \      return M::ti();\n    else\n      return T();\n  }\n  template <class S>\n\
    \  void build(Node *&t, const id_t &n, std::array<id_t, 2> b, const S &bg) {\n\
    \    if (n <= b[0]) return;\n    id_t m = (b[0] + b[1]) >> 1;\n    while (n <=\
    \ m) b[1] = m, m = (b[0] + b[1]) >> 1;\n    if (b[1] - b[0] == 1) {\n      if\
    \ constexpr (std::is_same_v<S, T>)\n        t = new Node{b[0], HEIGHT + 1, bg};\n\
    \      else\n        t = new Node{b[0], HEIGHT + 1, *(bg + b[0])};\n    } else\
    \ {\n      std::uint8_t h = __builtin_ctzll(b[1] - b[0]);\n      t = new Node{m\
    \ >> h, std::uint8_t(HEIGHT + 1 - h), def_val()};\n      build(t->ch[0], n, {b[0],\
    \ m}, bg), build(t->ch[1], n, {m, b[1]}, bg);\n      if constexpr (monoid<M>::value)\n\
    \        t->val = M::op(t->ch[0]->val, t->ch[1]->val);\n    }\n  }\n  void dump(Node\
    \ *t, const id_t &l, const id_t &r, std::array<id_t, 2> b,\n            typename\
    \ std::vector<T>::iterator itr, std::uint8_t h) {\n    if (r <= b[0] || b[1] <=\
    \ l) return;\n    if (l <= b[0] && b[1] <= r && !t) {\n      for (id_t i = b[0];\
    \ i < b[1]; i++) *(itr + i) = def_val();\n    } else if (b[1] - b[0] != 1) {\n\
    \      auto m = (b[0] + b[1]) >> 1;\n      dump(next(t, h, 0), l, r, {b[0], m},\
    \ itr, h - 1);\n      dump(next(t, h, 1), l, r, {m, b[1]}, itr, h - 1);\n    }\
    \ else\n      *(itr + b[0]) = t->val;\n  }\n  T fold(Node *&t, const id_t &l,\
    \ const id_t &r, const id_t &bias) {\n    static id_t bits, b[2];\n    if (!t)\
    \ return def_val();\n    std::uint8_t h = (HEIGHT + 1) - t->len;\n    bits = (bias\
    \ >> h) ^ t->bits, b[0] = bits << h, b[1] = (bits + 1) << h;\n    if (r <= b[0]\
    \ || b[1] <= l) return def_val();\n    if (l <= b[0] && b[1] <= r) return t->val;\n\
    \    bool flg = (bias >> (h - 1)) & 1;\n    return M::op(fold(t->ch[flg], l, r,\
    \ bias), fold(t->ch[!flg], l, r, bias));\n  }\n  void set_val(Node *&t, const\
    \ id_t &k, const T &val) {\n    if (!t) return t = new Node{k, HEIGHT + 1, val},\
    \ void();\n    if constexpr (persistent) t = new Node{*t};\n    id_t bits = (k\
    \ >> ((HEIGHT + 1) - t->len));\n    if (bits != t->bits) {\n      std::uint8_t\
    \ i = 64 - __builtin_clzll(bits ^ t->bits);\n      bool flg = (t->bits >> (i -\
    \ 1)) & 1;\n      t->ch[flg] = new Node{*t}, t->ch[!flg] = new Node{k, HEIGHT\
    \ + 1, val};\n      t->len -= i, t->bits >>= i;\n    } else if (t->len != HEIGHT\
    \ + 1) {\n      set_val(t->ch[(k >> (HEIGHT - t->len)) & 1], k, val);\n    } else\n\
    \      return t->val = val, void();\n    if constexpr (monoid<M>::value)\n   \
    \   t->val = M::op(t->ch[0]->val, t->ch[1]->val);\n  }\n  T &at_val(Node *&t,\
    \ const id_t &k) {\n    if (!t) return t = new Node{k, HEIGHT + 1, def_val()},\
    \ t->val;\n    if constexpr (persistent) t = new Node{*t};\n    id_t bits = (k\
    \ >> ((HEIGHT + 1) - t->len));\n    if (bits != t->bits) {\n      std::uint8_t\
    \ i = 64 - __builtin_clzll(bits ^ t->bits);\n      bool flg = (t->bits >> (i -\
    \ 1)) & 1;\n      t->ch[flg] = new Node{*t},\n      t->ch[!flg] = new Node{k,\
    \ HEIGHT + 1, def_val()};\n      t->len -= i, t->bits >>= i;\n      return t->ch[!flg]->val;\n\
    \    } else if (t->len != HEIGHT + 1)\n      return at_val(t->ch[(k >> (HEIGHT\
    \ - t->len)) & 1], k);\n    return t->val;\n  }\n  bool is_null(Node *&t, const\
    \ id_t &k) {\n    if (!t || (k >> ((HEIGHT + 1) - t->len)) != t->bits) return\
    \ true;\n    if (t->len == HEIGHT + 1) return false;\n    return is_null(t->ch[(k\
    \ >> (HEIGHT - t->len)) & 1], k);\n  }\n  T get_val(Node *&t, const id_t &k) {\n\
    \    if (!t || (k >> ((HEIGHT + 1) - t->len)) != t->bits) return def_val();\n\
    \    if (t->len == HEIGHT + 1) return t->val;\n    return get_val(t->ch[(k >>\
    \ (HEIGHT - t->len)) & 1], k);\n  }\n  template <bool last>\n  static inline T\
    \ calc_op(Node *&t, const T &v) {\n    if constexpr (last)\n      return M::op((t\
    \ ? t->val : def_val()), v);\n    else\n      return M::op(v, (t ? t->val : def_val()));\n\
    \  }\n  template <bool last>\n  static inline bool is_in(const id_t &m, const\
    \ id_t &k) {\n    if constexpr (last)\n      return k <= m;\n    else\n      return\
    \ m <= k;\n  }\n  static inline Node *next(Node *&t, const std::uint8_t &h, const\
    \ bool &f) {\n    if (!t) return nullptr;\n    std::uint8_t len = h + t->len -\
    \ (HEIGHT + 1);\n    if (!len) return t->ch[f];\n    return (f == ((t->bits >>\
    \ (len - 1)) & 1)) ? t : nullptr;\n  }\n  template <bool last, class C, std::size_t\
    \ N>\n  static id_t find(const id_t &k, std::array<id_t, 2> b, const id_t &bias,\n\
    \                   std::uint8_t h, const C &check, std::array<Node *, N> &ts,\n\
    \                   std::array<T, N> &sums) {\n    static_assert(monoid<M>::value,\
    \ \"\\\"find\\\" is not available\\n\");\n    static std::array<T, N> sums2;\n\
    \    if (std::all_of(ts.begin(), ts.end(), [](Node *t) { return !t; }))\n    \
    \  return -1;\n    if (!h) {\n      for (std::size_t i = N; i--;) sums[i] = calc_op<last>(ts[i],\
    \ sums[i]);\n      return std::apply(check, sums) ? std::get<last>(b) : -1;\n\
    \    } else if (is_in<last>(k, b[0])) {\n      for (std::size_t i = N; i--;) sums2[i]\
    \ = calc_op<last>(ts[i], sums[i]);\n      if (!std::apply(check, sums2)) return\
    \ sums = std::move(sums2), -1;\n    }\n    std::array<Node *, N> ss;\n    id_t\
    \ m = (b[0] + b[1]) >> 1;\n    bool flg = (bias >> (h - 1)) & 1;\n    if (!is_in<last>(m,\
    \ k)) {\n      for (std::size_t i = N; i--;) ss[i] = next(ts[i], h, flg);\n  \
    \    id_t ret = find<last>(k, {b[0], m}, bias, h - 1, check, ss, sums);\n    \
    \  if (ret >= 0) return ret;\n    }\n    for (std::size_t i = N; i--;) ss[i] =\
    \ next(ts[i], h, !flg);\n    return find<last>(k, {m, b[1]}, bias, h - 1, check,\
    \ ss, sums);\n  }\n\n public:\n  SegmentTree_Patricia(Node *t = nullptr) : root(t)\
    \ {}\n  SegmentTree_Patricia(std::size_t n, T val) : root(nullptr) {\n    build(root,\
    \ n, {0, 1LL << HEIGHT}, val);\n  }\n  SegmentTree_Patricia(T *bg, T *ed) : root(nullptr)\
    \ {\n    build(root, ed - bg, {0, 1LL << HEIGHT}, bg);\n  }\n  SegmentTree_Patricia(const\
    \ std::vector<T> &ar)\n      : SegmentTree_Patricia(ar.data(), ar.data() + ar.size())\
    \ {}\n  void set(id_t k, T val) { set_val(root, k, val); }\n  T get(id_t k) {\
    \ return get_val(root, k); }\n  bool is_null(id_t k) { return is_null(root, k);\
    \ }\n  T &at(id_t k) {\n    static_assert(!monoid<M>::value, \"\\\"at\\\" is not\
    \ available\\n\");\n    return at_val(root, k);\n  }\n  template <class L = M,\n\
    \            typename std::enable_if_t<monoid<L>::value> * = nullptr>\n  T operator[](id_t\
    \ k) {\n    return get(k);\n  }\n  template <class L = M,\n            typename\
    \ std::enable_if_t<!monoid<L>::value> * = nullptr>\n  T &operator[](id_t k) {\n\
    \    return at(k);\n  }\n  T fold(id_t a, id_t b, id_t bias = 0) {\n    static_assert(monoid<M>::value,\
    \ \"\\\"fold\\\" is not available\\n\");\n    return fold(root, a, b, bias);\n\
    \  }\n  // find i s.t.\n  //  check(fold(k,i)) == False, check(fold(k,i+1)) ==\
    \ True\n  // return -1 if not found\n  template <class C>\n  id_t find_first(id_t\
    \ a, C check, id_t bias = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node\
    \ *, 1> t{root};\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ t, sum);\n  }\n  template <std::size_t N, class C>\n  static id_t find_first(id_t\
    \ a, C check,\n                         std::array<SegmentTree_Patricia, N> segs,\n\
    \                         id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  // find i s.t.\n  //  check(fold(i+1,k)) == False, check(fold(i,k))\
    \ == True\n  // return -1 if not found\n  template <class C>\n  id_t find_last(id_t\
    \ b, C check, id_t bias = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node\
    \ *, 1> t{root};\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ t, sum);\n  }\n  template <std::size_t N, class C>\n  static id_t find_last(id_t\
    \ b, C check,\n                        std::array<SegmentTree_Patricia, N> segs,\n\
    \                        id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  std::vector<T> dump(id_t bg, id_t ed) {\n    std::vector<T>\
    \ ret(ed - bg);\n    dump(root, bg, ed, {0, 1LL << HEIGHT}, ret.begin(), HEIGHT);\n\
    \    return ret;\n  }\n  static std::string which_available() {\n    std::string\
    \ ret = \"\";\n    if constexpr (monoid<M>::value)\n      ret += \"\\\"fold\\\"\
    \ \\\"find\\\"\";\n    else\n      ret += \"\\\"at\\\" \";\n    return ret;\n\
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Segment-Tree(\u30D1\
    \u30C8\u30EA\u30B7\u30A2\u6728)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n\
    \ * \u30B9\u30D1\u30FC\u30B9\u306A\u3089\u30E1\u30E2\u30EA\u7BC0\u7D04\u3067\u304D\
    \u308B\u304B\u3082\n * \u9045\u5EF6\u4F1D\u642C\u4E0D\u53EF\n * \u6C38\u7D9A\u5316\
    \u53EF\n * O(logN)\n */\n\n// verify\u7528:\n// https://codeforces.com/contest/947/problem/C\
    \ (find+xor)\n// https://codeforces.com/contest/966/problem/C (find+xor)\n// https://codeforces.com/contest/295/problem/E\
    \ (\u7279\u6B8A\u30E2\u30CE\u30A4\u30C9+\u5EA7\u5727\u30B5\u30DC\u308A)\n// https://atcoder.jp/contests/kupc2018/tasks/kupc2018_m\
    \ (\u30D1\u30C8\u30EA\u30B7\u30A2\u306E\u52B9\u529B\u767A\u63EE)\n\n// BEGIN CUT\
    \ HERE\n\n#define HAS_CHECK(member, Dummy)                              \\\n \
    \ template <class T>                                          \\\n  struct has_##member\
    \ {                                       \\\n    template <class U, Dummy>  \
    \                               \\\n    static std::true_type check(U *);    \
    \                     \\\n    static std::false_type check(...);             \
    \           \\\n    static T *mClass;                                        \
    \ \\\n    static const bool value = decltype(check(mClass))::value; \\\n  };\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\ntemplate\
    \ <typename M, bool persistent = false, std::uint8_t HEIGHT = 30>\nclass SegmentTree_Patricia\
    \ {\n  HAS_MEMBER(op);\n  HAS_MEMBER(ti);\n  HAS_TYPE(T);\n  template <class L>\n\
    \  using monoid = std::conjunction<has_T<L>, has_op<L>, has_ti<L>>;\n  using id_t\
    \ = long long;\n  template <class T, class tDerived>\n  struct Node_B {\n    id_t\
    \ bits;\n    std::uint8_t len;\n    T val;\n    tDerived *ch[2] = {nullptr, nullptr};\n\
    \  };\n  template <bool mo_, typename tEnable = void>\n  struct Node_D : Node_B<M,\
    \ Node_D<mo_, tEnable>> {};\n  template <bool mo_>\n  struct Node_D<mo_, typename\
    \ std::enable_if_t<mo_>>\n      : Node_B<typename M::T, Node_D<mo_>> {};\n  using\
    \ Node = Node_D<monoid<M>::value>;\n  using T = decltype(Node::val);\n  Node *root;\n\
    \  static inline constexpr T def_val() {\n    if constexpr (monoid<M>::value)\n\
    \      return M::ti();\n    else\n      return T();\n  }\n  template <class S>\n\
    \  void build(Node *&t, const id_t &n, std::array<id_t, 2> b, const S &bg) {\n\
    \    if (n <= b[0]) return;\n    id_t m = (b[0] + b[1]) >> 1;\n    while (n <=\
    \ m) b[1] = m, m = (b[0] + b[1]) >> 1;\n    if (b[1] - b[0] == 1) {\n      if\
    \ constexpr (std::is_same_v<S, T>)\n        t = new Node{b[0], HEIGHT + 1, bg};\n\
    \      else\n        t = new Node{b[0], HEIGHT + 1, *(bg + b[0])};\n    } else\
    \ {\n      std::uint8_t h = __builtin_ctzll(b[1] - b[0]);\n      t = new Node{m\
    \ >> h, std::uint8_t(HEIGHT + 1 - h), def_val()};\n      build(t->ch[0], n, {b[0],\
    \ m}, bg), build(t->ch[1], n, {m, b[1]}, bg);\n      if constexpr (monoid<M>::value)\n\
    \        t->val = M::op(t->ch[0]->val, t->ch[1]->val);\n    }\n  }\n  void dump(Node\
    \ *t, const id_t &l, const id_t &r, std::array<id_t, 2> b,\n            typename\
    \ std::vector<T>::iterator itr, std::uint8_t h) {\n    if (r <= b[0] || b[1] <=\
    \ l) return;\n    if (l <= b[0] && b[1] <= r && !t) {\n      for (id_t i = b[0];\
    \ i < b[1]; i++) *(itr + i) = def_val();\n    } else if (b[1] - b[0] != 1) {\n\
    \      auto m = (b[0] + b[1]) >> 1;\n      dump(next(t, h, 0), l, r, {b[0], m},\
    \ itr, h - 1);\n      dump(next(t, h, 1), l, r, {m, b[1]}, itr, h - 1);\n    }\
    \ else\n      *(itr + b[0]) = t->val;\n  }\n  T fold(Node *&t, const id_t &l,\
    \ const id_t &r, const id_t &bias) {\n    static id_t bits, b[2];\n    if (!t)\
    \ return def_val();\n    std::uint8_t h = (HEIGHT + 1) - t->len;\n    bits = (bias\
    \ >> h) ^ t->bits, b[0] = bits << h, b[1] = (bits + 1) << h;\n    if (r <= b[0]\
    \ || b[1] <= l) return def_val();\n    if (l <= b[0] && b[1] <= r) return t->val;\n\
    \    bool flg = (bias >> (h - 1)) & 1;\n    return M::op(fold(t->ch[flg], l, r,\
    \ bias), fold(t->ch[!flg], l, r, bias));\n  }\n  void set_val(Node *&t, const\
    \ id_t &k, const T &val) {\n    if (!t) return t = new Node{k, HEIGHT + 1, val},\
    \ void();\n    if constexpr (persistent) t = new Node{*t};\n    id_t bits = (k\
    \ >> ((HEIGHT + 1) - t->len));\n    if (bits != t->bits) {\n      std::uint8_t\
    \ i = 64 - __builtin_clzll(bits ^ t->bits);\n      bool flg = (t->bits >> (i -\
    \ 1)) & 1;\n      t->ch[flg] = new Node{*t}, t->ch[!flg] = new Node{k, HEIGHT\
    \ + 1, val};\n      t->len -= i, t->bits >>= i;\n    } else if (t->len != HEIGHT\
    \ + 1) {\n      set_val(t->ch[(k >> (HEIGHT - t->len)) & 1], k, val);\n    } else\n\
    \      return t->val = val, void();\n    if constexpr (monoid<M>::value)\n   \
    \   t->val = M::op(t->ch[0]->val, t->ch[1]->val);\n  }\n  T &at_val(Node *&t,\
    \ const id_t &k) {\n    if (!t) return t = new Node{k, HEIGHT + 1, def_val()},\
    \ t->val;\n    if constexpr (persistent) t = new Node{*t};\n    id_t bits = (k\
    \ >> ((HEIGHT + 1) - t->len));\n    if (bits != t->bits) {\n      std::uint8_t\
    \ i = 64 - __builtin_clzll(bits ^ t->bits);\n      bool flg = (t->bits >> (i -\
    \ 1)) & 1;\n      t->ch[flg] = new Node{*t},\n      t->ch[!flg] = new Node{k,\
    \ HEIGHT + 1, def_val()};\n      t->len -= i, t->bits >>= i;\n      return t->ch[!flg]->val;\n\
    \    } else if (t->len != HEIGHT + 1)\n      return at_val(t->ch[(k >> (HEIGHT\
    \ - t->len)) & 1], k);\n    return t->val;\n  }\n  bool is_null(Node *&t, const\
    \ id_t &k) {\n    if (!t || (k >> ((HEIGHT + 1) - t->len)) != t->bits) return\
    \ true;\n    if (t->len == HEIGHT + 1) return false;\n    return is_null(t->ch[(k\
    \ >> (HEIGHT - t->len)) & 1], k);\n  }\n  T get_val(Node *&t, const id_t &k) {\n\
    \    if (!t || (k >> ((HEIGHT + 1) - t->len)) != t->bits) return def_val();\n\
    \    if (t->len == HEIGHT + 1) return t->val;\n    return get_val(t->ch[(k >>\
    \ (HEIGHT - t->len)) & 1], k);\n  }\n  template <bool last>\n  static inline T\
    \ calc_op(Node *&t, const T &v) {\n    if constexpr (last)\n      return M::op((t\
    \ ? t->val : def_val()), v);\n    else\n      return M::op(v, (t ? t->val : def_val()));\n\
    \  }\n  template <bool last>\n  static inline bool is_in(const id_t &m, const\
    \ id_t &k) {\n    if constexpr (last)\n      return k <= m;\n    else\n      return\
    \ m <= k;\n  }\n  static inline Node *next(Node *&t, const std::uint8_t &h, const\
    \ bool &f) {\n    if (!t) return nullptr;\n    std::uint8_t len = h + t->len -\
    \ (HEIGHT + 1);\n    if (!len) return t->ch[f];\n    return (f == ((t->bits >>\
    \ (len - 1)) & 1)) ? t : nullptr;\n  }\n  template <bool last, class C, std::size_t\
    \ N>\n  static id_t find(const id_t &k, std::array<id_t, 2> b, const id_t &bias,\n\
    \                   std::uint8_t h, const C &check, std::array<Node *, N> &ts,\n\
    \                   std::array<T, N> &sums) {\n    static_assert(monoid<M>::value,\
    \ \"\\\"find\\\" is not available\\n\");\n    static std::array<T, N> sums2;\n\
    \    if (std::all_of(ts.begin(), ts.end(), [](Node *t) { return !t; }))\n    \
    \  return -1;\n    if (!h) {\n      for (std::size_t i = N; i--;) sums[i] = calc_op<last>(ts[i],\
    \ sums[i]);\n      return std::apply(check, sums) ? std::get<last>(b) : -1;\n\
    \    } else if (is_in<last>(k, b[0])) {\n      for (std::size_t i = N; i--;) sums2[i]\
    \ = calc_op<last>(ts[i], sums[i]);\n      if (!std::apply(check, sums2)) return\
    \ sums = std::move(sums2), -1;\n    }\n    std::array<Node *, N> ss;\n    id_t\
    \ m = (b[0] + b[1]) >> 1;\n    bool flg = (bias >> (h - 1)) & 1;\n    if (!is_in<last>(m,\
    \ k)) {\n      for (std::size_t i = N; i--;) ss[i] = next(ts[i], h, flg);\n  \
    \    id_t ret = find<last>(k, {b[0], m}, bias, h - 1, check, ss, sums);\n    \
    \  if (ret >= 0) return ret;\n    }\n    for (std::size_t i = N; i--;) ss[i] =\
    \ next(ts[i], h, !flg);\n    return find<last>(k, {m, b[1]}, bias, h - 1, check,\
    \ ss, sums);\n  }\n\n public:\n  SegmentTree_Patricia(Node *t = nullptr) : root(t)\
    \ {}\n  SegmentTree_Patricia(std::size_t n, T val) : root(nullptr) {\n    build(root,\
    \ n, {0, 1LL << HEIGHT}, val);\n  }\n  SegmentTree_Patricia(T *bg, T *ed) : root(nullptr)\
    \ {\n    build(root, ed - bg, {0, 1LL << HEIGHT}, bg);\n  }\n  SegmentTree_Patricia(const\
    \ std::vector<T> &ar)\n      : SegmentTree_Patricia(ar.data(), ar.data() + ar.size())\
    \ {}\n  void set(id_t k, T val) { set_val(root, k, val); }\n  T get(id_t k) {\
    \ return get_val(root, k); }\n  bool is_null(id_t k) { return is_null(root, k);\
    \ }\n  T &at(id_t k) {\n    static_assert(!monoid<M>::value, \"\\\"at\\\" is not\
    \ available\\n\");\n    return at_val(root, k);\n  }\n  template <class L = M,\n\
    \            typename std::enable_if_t<monoid<L>::value> * = nullptr>\n  T operator[](id_t\
    \ k) {\n    return get(k);\n  }\n  template <class L = M,\n            typename\
    \ std::enable_if_t<!monoid<L>::value> * = nullptr>\n  T &operator[](id_t k) {\n\
    \    return at(k);\n  }\n  T fold(id_t a, id_t b, id_t bias = 0) {\n    static_assert(monoid<M>::value,\
    \ \"\\\"fold\\\" is not available\\n\");\n    return fold(root, a, b, bias);\n\
    \  }\n  // find i s.t.\n  //  check(fold(k,i)) == False, check(fold(k,i+1)) ==\
    \ True\n  // return -1 if not found\n  template <class C>\n  id_t find_first(id_t\
    \ a, C check, id_t bias = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node\
    \ *, 1> t{root};\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ t, sum);\n  }\n  template <std::size_t N, class C>\n  static id_t find_first(id_t\
    \ a, C check,\n                         std::array<SegmentTree_Patricia, N> segs,\n\
    \                         id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  // find i s.t.\n  //  check(fold(i+1,k)) == False, check(fold(i,k))\
    \ == True\n  // return -1 if not found\n  template <class C>\n  id_t find_last(id_t\
    \ b, C check, id_t bias = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node\
    \ *, 1> t{root};\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ t, sum);\n  }\n  template <std::size_t N, class C>\n  static id_t find_last(id_t\
    \ b, C check,\n                        std::array<SegmentTree_Patricia, N> segs,\n\
    \                        id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  std::vector<T> dump(id_t bg, id_t ed) {\n    std::vector<T>\
    \ ret(ed - bg);\n    dump(root, bg, ed, {0, 1LL << HEIGHT}, ret.begin(), HEIGHT);\n\
    \    return ret;\n  }\n  static std::string which_available() {\n    std::string\
    \ ret = \"\";\n    if constexpr (monoid<M>::value)\n      ret += \"\\\"fold\\\"\
    \ \\\"find\\\"\";\n    else\n      ret += \"\\\"at\\\" \";\n    return ret;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Patricia.hpp
  requiredBy: []
  timestamp: '2021-11-23 17:04:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/649.Patricia.test.cpp
  - test/yosupo/set_xor_min.Patricia.test.cpp
  - test/aoj/2270.Patricia.test.cpp
  - test/aoj/3024.Patricia.test.cpp
  - test/atcoder/abc133_f.Patricia.test.cpp
documentation_of: src/DataStructure/SegmentTree_Patricia.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree_Patricia.hpp
- /library/src/DataStructure/SegmentTree_Patricia.hpp.html
title: "Segment-Tree(\u30D1\u30C8\u30EA\u30B7\u30A2\u6728)"
---