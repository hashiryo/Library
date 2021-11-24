---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SplayTree.hpp
    title: "Splay\u6728"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n// set_balance \u3057\u306A\u3044\u3068 \u30B9\u30BF\u30C3\u30AF\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\n// \uFF08\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    \ wrong_avl_killer_01\uFF09\n\n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SplayTree.hpp\"\
    \n/**\n * @title Splay\u6728\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *\
    \ @brief O(logN)\n * \u6728\u306E\u6DF1\u3055\u304C10^5\u3050\u3089\u3044\u306B\
    \u306A\u308B\u3068\u518D\u5E30\u95A2\u6570\u304C\u30B9\u30BF\u30C3\u30AF\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u8D77\u3053\u3059\u306E\u3067\u6CE8\u610F\
    \n * set_balance() \u3067\u30E9\u30F3\u30C0\u30E0\u306Bsplay\u3059\u308B\u306E\
    \u3067\u306A\u3089\u3059\u3053\u3068\u304C\u3067\u304D\u308B\u306F\u305A\n * \u5358\
    \u4F4D\u5143\u306F\u5FC5\u8981\u306A\u3057\uFF08\u9045\u5EF6\u5074\u3082\uFF09\
    \n * \u533A\u9593reverse\u304C\u3067\u304D\u308B\u3002\uFF08\u534A\u7FA4\u306E\
    \u53EF\u63DB\u6027\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u306A\u3044\u306E\u3067\
    \u7121\u99C4\u306B\u30E1\u30E2\u30EA\u3068\u6642\u9593\u3092\u4F7F\u3046\u3051\
    \u3069\uFF09\n * \u5404\u30CE\u30FC\u30C9\u304C\u90E8\u5206\u6728\u306E\u30B5\u30A4\
    \u30BA\u3092\u4FDD\u6301\u3057\u3066\u3044\u308B\u306E\u3067mapping\u95A2\u6570\
    \u3067\u306F\u5F15\u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\u308B\n */\n\n\
    // BEGIN CUT HERE\n#define HAS_CHECK(member, Dummy)                          \
    \    \\\n  template <class T>                                          \\\n  struct\
    \ has_##member {                                       \\\n    template <class\
    \ U, Dummy>                                 \\\n    static std::true_type check(U\
    \ *);                         \\\n    static std::false_type check(...);     \
    \                   \\\n    static T *mClass;                                \
    \         \\\n    static const bool value = decltype(check(mClass))::value; \\\
    \n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    \ntemplate <class M, bool reversible = false>\nclass SplayTree {\n  HAS_MEMBER(op);\n\
    \  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n\
    \  template <class L>\n  using semigroup = std::conjunction<has_T<L>, has_op<L>>;\n\
    \  template <class L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>,\
    \ has_mapping<L>, has_composition<L>>;\n  template <class T, class tDerived, class\
    \ F = std::nullptr_t>\n  struct Node_B {\n    using E = F;\n    T val;\n    tDerived\
    \ *ch[2];\n    std::size_t size;\n  };\n  template <bool sg_, bool du_, bool rev_,\
    \ typename tEnable = void>\n  struct Node_D : Node_B<M, Node_D<sg_, du_, rev_,\
    \ tEnable>> {};\n  template <bool sg_, bool du_, bool rev_>\n  struct Node_D<sg_,\
    \ du_, rev_, typename std::enable_if_t<sg_ && !du_ && !rev_>>\n      : Node_B<typename\
    \ M::T, Node_D<sg_, du_, rev_>> {\n    typename M::T sum;\n  };\n  template <bool\
    \ sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_\
    \ && du_ && !rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename\
    \ M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n  };\n  template\
    \ <bool sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
    \ && du_ && !rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename\
    \ M::E> {\n    typename M::T sum;\n    typename M::E lazy;\n    bool lazy_flg\
    \ = false;\n  };\n  template <bool sg_, bool du_, bool rev_>\n  struct Node_D<sg_,\
    \ du_, rev_, typename std::enable_if_t<!sg_ && !du_ && rev_>>\n      : Node_B<M,\
    \ Node_D<sg_, du_, rev_>> {\n    bool rev_flg = false;\n  };\n  template <bool\
    \ sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
    \ && !du_ && rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>> {\n\
    \    typename M::T sum, rsum;\n    bool rev_flg = false;\n  };\n  template <bool\
    \ sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_\
    \ && du_ && rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename\
    \ M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false, rev_flg = false;\n\
    \  };\n  template <bool sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_,\
    \ typename std::enable_if_t<sg_ && du_ && rev_>>\n      : Node_B<typename M::T,\
    \ Node_D<sg_, du_, rev_>, typename M::E> {\n    typename M::T sum, rsum;\n   \
    \ typename M::E lazy;\n    bool lazy_flg = false, rev_flg = false;\n  };\n  using\
    \ Node = Node_D<semigroup<M>::value, dual<M>::value, reversible>;\n  using T =\
    \ decltype(Node::val);\n  using E = typename Node::E;\n  Node *root;\n  Node *build(T\
    \ *bg, T *ed) {\n    if (bg == ed) return nullptr;\n    T *mid = bg + (ed - bg)\
    \ / 2;\n    return pushup(new Node{*mid, {build(bg, mid), build(mid + 1, ed)}});\n\
    \  }\n  Node *build(std::size_t bg, std::size_t ed, const T &val) {\n    if (bg\
    \ == ed) return nullptr;\n    std::size_t mid = bg + (ed - bg) / 2;\n    return\
    \ pushup(\n        new Node{val, {build(bg, mid, val), build(mid + 1, ed, val)}});\n\
    \  }\n  void dump(typename std::vector<T>::iterator itr, Node *t) {\n    if (!t)\
    \ return;\n    if constexpr (dual<M>::value) eval_propagate(t);\n    if constexpr\
    \ (reversible) eval_toggle(t);\n    std::size_t sz = t->ch[0] ? t->ch[0]->size\
    \ : 0;\n    *(itr + sz) = t->val, dump(itr, t->ch[0]), dump(itr + sz + 1, t->ch[1]);\n\
    \  }\n  template <bool b>\n  void helper(Node *&t) {\n    if (!t->ch[b]) return;\n\
    \    t->size += t->ch[b]->size;\n    if constexpr (semigroup<M>::value)\n    \
    \  if constexpr (b) {\n        t->sum = M::op(t->sum, t->ch[1]->sum);\n      \
    \  if constexpr (reversible) t->rsum = M::op(t->ch[1]->rsum, t->rsum);\n     \
    \ } else {\n        t->sum = M::op(t->ch[0]->sum, t->sum);\n        if constexpr\
    \ (reversible) t->rsum = M::op(t->rsum, t->ch[0]->rsum);\n      }\n  }\n  inline\
    \ Node *pushup(Node *t) {\n    if (!t) return t;\n    t->size = 1;\n    if constexpr\
    \ (semigroup<M>::value) {\n      t->sum = t->val;\n      if constexpr (reversible)\
    \ t->rsum = t->val;\n    }\n    return helper<0>(t), helper<1>(t), t;\n  }\n \
    \ inline void propagate(Node *t, const E &x) {\n    if (!t) return;\n    t->lazy\
    \ = t->lazy_flg ? M::composition(t->lazy, x) : x;\n    if constexpr (semigroup<M>::value)\
    \ {\n      t->sum = M::mapping(t->sum, x, t->size);\n      if constexpr (reversible)\
    \ t->rsum = M::mapping(t->rsum, x, t->size);\n    }\n    t->val = M::mapping(t->val,\
    \ x, 1), t->lazy_flg = true;\n  }\n  inline void toggle(Node *t) {\n    if (!t)\
    \ return;\n    if constexpr (semigroup<M>::value) std::swap(t->sum, t->rsum);\n\
    \    std::swap(t->ch[0], t->ch[1]), t->rev_flg = !t->rev_flg;\n  }\n  inline void\
    \ eval_propagate(Node *t) {\n    if (t->lazy_flg)\n      propagate(t->ch[0], t->lazy),\
    \ propagate(t->ch[1], t->lazy),\n          t->lazy_flg = false;\n  }\n  inline\
    \ void eval_toggle(Node *t) {\n    if (t->rev_flg) toggle(t->ch[0]), toggle(t->ch[1]),\
    \ t->rev_flg = false;\n  }\n  inline void rot(Node *&t, bool d) {\n    Node *s\
    \ = t->ch[d];\n    t->ch[d] = s->ch[!d], s->ch[!d] = pushup(t), t = pushup(s);\n\
    \  }\n  inline void splay(Node *&t, std::size_t k) {\n    if (!t) return;\n  \
    \  if constexpr (dual<M>::value) eval_propagate(t);\n    if constexpr (reversible)\
    \ eval_toggle(t);\n    std::size_t sz = t->ch[0] ? t->ch[0]->size : 0;\n    if\
    \ (sz == k) return;\n    bool d = sz < k;\n    if (d) k -= sz + 1;\n    if constexpr\
    \ (dual<M>::value) eval_propagate(t->ch[d]);\n    if constexpr (reversible) eval_toggle(t->ch[d]);\n\
    \    sz = t->ch[d]->ch[0] ? t->ch[d]->ch[0]->size : 0;\n    if (sz != k) {\n \
    \     bool c = sz < k;\n      if (c) k -= sz + 1;\n      splay(t->ch[d]->ch[c],\
    \ k);\n      c == d ? rot(t, d) : rot(t->ch[d], !d);\n    }\n    rot(t, d);\n\
    \  }\n  template <class F>\n  void query(std::size_t a, std::size_t b, const F\
    \ &f) {\n    if (size() == b) {\n      a-- ? (splay(root, a), f(root->ch[1]),\
    \ pushup(root)) : (f(root), root);\n    } else {\n      splay(root, b);\n    \
    \  a-- ? (splay(root->ch[0], a), f(root->ch[0]->ch[1]), pushup(root->ch[0]))\n\
    \          : (f(root->ch[0]), root->ch[0]);\n      pushup(root);\n    }\n  }\n\
    \  static inline unsigned xor128() {\n    static unsigned x = 123456789, y = 362436069,\
    \ z = 521288629, w = 88675123;\n    unsigned t = (x ^ (x << 11));\n    return\
    \ x = y, y = z, z = w, (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n  }\n\n public:\n\
    \  SplayTree(Node *t = nullptr) : root(t) {}\n  SplayTree(std::size_t n, T val)\
    \ { root = build(0, n, val); }\n  SplayTree(T *bg, T *ed) { root = build(bg, ed);\
    \ }\n  SplayTree(const std::vector<T> &ar)\n      : SplayTree(ar.data(), ar.data()\
    \ + ar.size()) {}\n  std::vector<T> dump() {\n    std::vector<T> ret(size());\n\
    \    return dump(ret.begin(), root), ret;\n  }\n  static std::string which_available()\
    \ {\n    std::string ret = \"\";\n    if constexpr (semigroup<M>::value)\n   \
    \   ret += \"\\\"fold\\\" \";\n    else\n      ret += \"\\\"at\\\" \";\n    if\
    \ constexpr (dual<M>::value) ret += \"\\\"apply\\\" \";\n    if constexpr (reversible)\
    \ ret += \"\\\"reverse\\\" \";\n    return ret;\n  }\n  std::size_t size() { return\
    \ root ? root->size : 0; }\n  void clear() { root = nullptr; }\n  template <class\
    \ L = M,\n            typename std::enable_if_t<semigroup<L>::value> * = nullptr>\n\
    \  const T &operator[](id_t k) {\n    return get(k);\n  }\n  template <class L\
    \ = M,\n            typename std::enable_if_t<!semigroup<L>::value> * = nullptr>\n\
    \  T &operator[](id_t k) {\n    return at(k);\n  }\n  const T &get(std::size_t\
    \ k) { return splay(root, k), root->val; }\n  T &at(std::size_t k) {\n    static_assert(!semigroup<M>::value,\
    \ \"\\\"at\\\" is not available\");\n    return splay(root, k), root->val;\n \
    \ }\n  void set(std::size_t k, T val) {\n    splay(root, k), root->val = val,\
    \ pushup(root);\n  }\n  void set_balance() {\n    if (root) splay(root, xor128()\
    \ % size()), splay(root, xor128() % size());\n  }\n  T fold(std::size_t a, std::size_t\
    \ b) {\n    static_assert(semigroup<M>::value, \"\\\"fold\\\" is not available\"\
    );\n    if (size() == b) {\n      return a-- ? splay(root, a), root->ch[1]->sum\
    \ : root->sum;\n    } else {\n      splay(root, b);\n      return a-- ? (splay(root->ch[0],\
    \ a), root->ch[0]->ch[1]->sum)\n                 : root->ch[0]->sum;\n    }\n\
    \  }\n  void apply(std::size_t a, std::size_t b, E x) {\n    static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\");\n    query(a, b, [&](Node *t) { propagate(t,\
    \ x); });\n  }\n  void reverse(std::size_t a, std::size_t b) {\n    static_assert(reversible,\
    \ \"\\\"reverse\\\" is not available\");\n    query(a, b, [&](Node *t) { toggle(t);\
    \ });\n  }\n  std::pair<SplayTree, SplayTree> split(std::size_t k) {\n    assert(k\
    \ <= size());\n    if (size() == k) return {*this, SplayTree()};\n    splay(root,\
    \ k);\n    Node *l = root->ch[0];\n    root->ch[0] = nullptr;\n    return {SplayTree(l),\
    \ SplayTree(pushup(root))};\n  }\n  std::tuple<SplayTree, SplayTree, SplayTree>\
    \ split3(std::size_t a,\n                                                    \
    \ std::size_t b) {\n    auto [tmp, right] = split(b);\n    auto [left, center]\
    \ = tmp.split(a);\n    return {left, center, right};\n  }\n  SplayTree &operator+=(SplayTree\
    \ rhs) {  // merge\n    root ? (splay(root, root->size - 1), root->ch[1] = rhs.root,\
    \ pushup(root))\n         : root = rhs.root;\n    return *this;\n  }\n  SplayTree\
    \ &operator+(SplayTree rhs) { return *this += rhs; }\n  void push_back(T val)\
    \ { insert(size(), val); }\n  void push_front(T val) { insert(0, val); }\n  void\
    \ insert(std::size_t k, T val) {\n    assert(!k || (root && k <= root->size));\n\
    \    if (size() == k) {\n      root = pushup(new Node{val, {root, nullptr}});\n\
    \    } else {\n      splay(root, k), root = new Node{val, {root->ch[0], root}};\n\
    \      root->ch[1]->ch[0] = nullptr, pushup(root->ch[1]), pushup(root);\n    }\n\
    \  }\n  T pop_back() { return erase(root->size - 1); }\n  T pop_front() { return\
    \ erase(0); }\n  T erase(std::size_t k) {\n    assert(root && k < root->size);\n\
    \    splay(root, k);\n    T ret = root->val;\n    splay(root->ch[1], 0);\n   \
    \ if (root->ch[1])\n      root->ch[1]->ch[0] = root->ch[0], root = pushup(root->ch[1]);\n\
    \    else\n      root = root->ch[0];\n    return ret;\n  }\n};\n#line 3 \"src/Math/ModInt.hpp\"\
    \n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\
    namespace internal {\ntemplate <std::uint64_t mod, std::uint64_t prim_root, class\
    \ ModInt>\nstruct ModIntImpl {\n  static constexpr std::uint64_t modulo() { return\
    \ mod; }\n  static constexpr std::uint64_t pr_rt() { return prim_root; }\n  friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt &rhs) {\n    return\
    \ os << rhs.val();\n  }\n};\n}  // namespace internal\ntemplate <std::uint64_t\
    \ mod, std::uint64_t prim_root = 0>\nclass ModInt\n    : public internal::ModIntImpl<mod,\
    \ prim_root, ModInt<mod, prim_root>> {\n  using u64 = std::uint64_t;\n  static\
    \ constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e == 0 ? x\
    \ : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv = mul_inv(mod,\
    \ 6, 1), r2 = -__uint128_t(mod) % mod;\n  static constexpr u64 init(u64 w) { return\
    \ reduce(__uint128_t(w) * r2); }\n  static constexpr u64 reduce(const __uint128_t\
    \ w) {\n    return u64(w >> 64) + mod - ((__uint128_t(u64(w) * inv) * mod) >>\
    \ 64);\n  }\n  u64 x;\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  static\
    \ constexpr u64 norm(u64 w) { return w - (mod & -(w >= mod)); }\n  constexpr ModInt\
    \ operator-() const {\n    ModInt ret;\n    return ret.x = ((mod << 1) & -(x !=\
    \ 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const ModInt &rhs) {\n  \
    \  return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >> 63), *this;\n  }\n\
    \  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x\
    \ += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(__uint128_t(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n\
    \  constexpr ModInt pow(std::uint64_t k) const {\n    ModInt ret = ModInt(1);\n\
    \    for (ModInt base = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret\
    \ *= base;\n    return ret;\n  }\n  constexpr ModInt inverse() const { return\
    \ pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this == ModInt(0)\
    \ || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return ModInt(0);\
    \  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod\
    \ - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt,\
    \ ModInt> u, std::pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first\
    \ + u.second * v.second * w);\n      ModInt b = (u.first * v.second + u.second\
    \ * v.first);\n      return std::make_pair(a, b);\n    };\n    std::uint64_t e\
    \ = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n    for (auto\
    \ bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1)\
    \ ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first : -ret.first;\n\
    \  }\n  constexpr u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return\
    \ ret + (mod & -(ret >> 63));\n  }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n\
    };\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2, pr_rt> : internal::ModIntImpl<2,\
    \ pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t n = 0) : x(n & 1)\
    \ {}\n  constexpr ModInt operator-() const { return *this; }\n  constexpr ModInt\
    \ &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator*=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator/=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs)\
    \ const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t k) const\
    \ { return !k ? ModInt(1) : *this; }\n  constexpr ModInt sqrt() const { return\
    \ *this; }\n  constexpr ModInt inverse() const { return *this; }\n  constexpr\
    \ std::uint64_t val() const { return x; }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, is;\n  }\n\n private:\n  bool x;\n\
    };\n#line 10 \"test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp\"\n\
    using namespace std;\n\nusing Mint = ModInt<998244353>;\nstruct RaffineRsumQ {\n\
    \  using T = Mint;\n  using E = pair<T, T>;\n  static T op(const T &vl, const\
    \ T &vr) { return vl + vr; }\n  static T mapping(const T &val, const E &f, int\
    \ sz) {\n    return f.first * val + f.second * sz;\n  }\n  static E composition(const\
    \ E &pre, const E &suf) {\n    return make_pair(pre.first * suf.first,\n     \
    \                suf.first * pre.second + suf.second);\n  }\n};\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n\
    \  Mint a[N];\n  for (int i = 0; i < N; i++) cin >> a[i];\n  SplayTree<RaffineRsumQ,\
    \ true> splay(a, a + N);\n  for (int q = 0; q < Q; q++) {\n    int op;\n    cin\
    \ >> op;\n    if (op == 0) {\n      int i, x;\n      cin >> i >> x;\n      splay.insert(i,\
    \ x);\n    } else if (op == 1) {\n      int i;\n      cin >> i;\n      splay.erase(i);\n\
    \    } else if (op == 2) {\n      int l, r;\n      cin >> l >> r;\n      splay.reverse(l,\
    \ r);\n    } else if (op == 3) {\n      int l, r, b, c;\n      cin >> l >> r >>\
    \ b >> c;\n      splay.apply(l, r, {b, c});\n    } else {\n      int l, r;\n \
    \     cin >> l >> r;\n      cout << splay.fold(l, r) << '\\n';\n    }\n    if\
    \ (q % 100000 == 0) splay.set_balance();\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n// set_balance \u3057\u306A\u3044\u3068 \u30B9\u30BF\u30C3\u30AF\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\n// \uFF08\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    \ wrong_avl_killer_01\uFF09\n\n#include <bits/stdc++.h>\n#include \"src/DataStructure/SplayTree.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint = ModInt<998244353>;\n\
    struct RaffineRsumQ {\n  using T = Mint;\n  using E = pair<T, T>;\n  static T\
    \ op(const T &vl, const T &vr) { return vl + vr; }\n  static T mapping(const T\
    \ &val, const E &f, int sz) {\n    return f.first * val + f.second * sz;\n  }\n\
    \  static E composition(const E &pre, const E &suf) {\n    return make_pair(pre.first\
    \ * suf.first,\n                     suf.first * pre.second + suf.second);\n \
    \ }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N,\
    \ Q;\n  cin >> N >> Q;\n  Mint a[N];\n  for (int i = 0; i < N; i++) cin >> a[i];\n\
    \  SplayTree<RaffineRsumQ, true> splay(a, a + N);\n  for (int q = 0; q < Q; q++)\
    \ {\n    int op;\n    cin >> op;\n    if (op == 0) {\n      int i, x;\n      cin\
    \ >> i >> x;\n      splay.insert(i, x);\n    } else if (op == 1) {\n      int\
    \ i;\n      cin >> i;\n      splay.erase(i);\n    } else if (op == 2) {\n    \
    \  int l, r;\n      cin >> l >> r;\n      splay.reverse(l, r);\n    } else if\
    \ (op == 3) {\n      int l, r, b, c;\n      cin >> l >> r >> b >> c;\n      splay.apply(l,\
    \ r, {b, c});\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout\
    \ << splay.fold(l, r) << '\\n';\n    }\n    if (q % 100000 == 0) splay.set_balance();\n\
    \  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/SplayTree.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-11-23 15:43:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
---
