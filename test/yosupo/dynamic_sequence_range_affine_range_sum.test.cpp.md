---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SplayTree.hpp
    title: Splay-Tree
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \n/**\n * @title Splay-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ O(logN)\n * \u6728\u306E\u6DF1\u3055\u304C10^5\u3050\u3089\u3044\u306B\u306A\
    \u308B\u3068\u518D\u5E30\u95A2\u6570\u304C\u30B9\u30BF\u30C3\u30AF\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u8D77\u3053\u3059\u306E\u3067\u6CE8\u610F\n * set_balance()\
    \ \u3067\u30E9\u30F3\u30C0\u30E0\u306Bsplay\u3059\u308B\u306E\u3067\u306A\u3089\
    \u3059\u3053\u3068\u304C\u3067\u304D\u308B\u306F\u305A\n * \u5358\u4F4D\u5143\u306F\
    \u5FC5\u8981\u306A\u3057\uFF08\u9045\u5EF6\u5074\u3082\uFF09\n * \u533A\u9593\
    reverse\u304C\u3067\u304D\u308B\u3002\uFF08\u534A\u7FA4\u306E\u53EF\u63DB\u6027\
    \u3092\u4EEE\u5B9A\u3057\u3066\u3044\u306A\u3044\u306E\u3067\u7121\u99C4\u306B\
    \u30E1\u30E2\u30EA\u3068\u6642\u9593\u3092\u4F7F\u3046\u3051\u3069\uFF09\n * \u5404\
    \u30CE\u30FC\u30C9\u304C\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\u4FDD\
    \u6301\u3057\u3066\u3044\u308B\u306E\u3067mapping\u95A2\u6570\u3067\u306F\u5F15\
    \u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\u308B\n */\n\n// BEGIN CUT HERE\n\
    \n#ifndef HAS_CHECK\n#define HAS_CHECK(member, Dummy)                        \
    \      \\\n  template <class T>                                          \\\n\
    \  struct has_##member {                                       \\\n    template\
    \ <class U, Dummy>                                 \\\n    static std::true_type\
    \ check(U *);                         \\\n    static std::false_type check(...);\
    \                        \\\n    static T *mClass;                           \
    \              \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    #endif\n\ntemplate <class M, bool reversible = false>\nclass SplayTree {\n  HAS_MEMBER(op);\n\
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
    \ decltype(Node::val);\n  using E = typename Node::E;\n  Node *root;\n  static\
    \ inline Node *build(const T *bg, const T *ed) {\n    if (bg == ed) return nullptr;\n\
    \    const T *mid = bg + (ed - bg) / 2;\n    return pushup(new Node{*mid, {build(bg,\
    \ mid), build(mid + 1, ed)}});\n  }\n  static inline Node *build(std::size_t bg,\
    \ std::size_t ed, const T &val) {\n    if (bg == ed) return nullptr;\n    std::size_t\
    \ mid = bg + (ed - bg) / 2;\n    return pushup(\n        new Node{val, {build(bg,\
    \ mid, val), build(mid + 1, ed, val)}});\n  }\n  static inline void dump(typename\
    \ std::vector<T>::iterator itr, Node *t) {\n    if (!t) return;\n    if constexpr\
    \ (dual<M>::value) eval_propagate(t);\n    if constexpr (reversible) eval_toggle(t);\n\
    \    std::size_t sz = t->ch[0] ? t->ch[0]->size : 0;\n    *(itr + sz) = t->val,\
    \ dump(itr, t->ch[0]), dump(itr + sz + 1, t->ch[1]);\n  }\n  template <bool b>\n\
    \  static inline void helper(Node *&t) {\n    if (!t->ch[b]) return;\n    t->size\
    \ += t->ch[b]->size;\n    if constexpr (semigroup<M>::value)\n      if constexpr\
    \ (b) {\n        t->sum = M::op(t->sum, t->ch[1]->sum);\n        if constexpr\
    \ (reversible) t->rsum = M::op(t->ch[1]->rsum, t->rsum);\n      } else {\n   \
    \     t->sum = M::op(t->ch[0]->sum, t->sum);\n        if constexpr (reversible)\
    \ t->rsum = M::op(t->rsum, t->ch[0]->rsum);\n      }\n  }\n  static inline Node\
    \ *pushup(Node *t) {\n    if (!t) return t;\n    t->size = 1;\n    if constexpr\
    \ (semigroup<M>::value) {\n      t->sum = t->val;\n      if constexpr (reversible)\
    \ t->rsum = t->sum;\n    }\n    return helper<0>(t), helper<1>(t), t;\n  }\n \
    \ static inline void propagate(Node *t, const E &x) {\n    if (!t) return;\n \
    \   t->lazy_flg ? (M::composition(t->lazy, x), x) : t->lazy = x;\n    if constexpr\
    \ (semigroup<M>::value) {\n      M::mapping(t->sum, x, t->size);\n      if constexpr\
    \ (reversible) M::mapping(t->rsum, x, t->size);\n    }\n    M::mapping(t->val,\
    \ x, 1), t->lazy_flg = true;\n  }\n  static inline void toggle(Node *t) {\n  \
    \  if (!t) return;\n    if constexpr (semigroup<M>::value) std::swap(t->sum, t->rsum);\n\
    \    std::swap(t->ch[0], t->ch[1]), t->rev_flg = !t->rev_flg;\n  }\n  static inline\
    \ void eval_propagate(Node *t) {\n    if (t->lazy_flg)\n      propagate(t->ch[0],\
    \ t->lazy), propagate(t->ch[1], t->lazy),\n          t->lazy_flg = false;\n  }\n\
    \  static inline void eval_toggle(Node *t) {\n    if (t->rev_flg) toggle(t->ch[0]),\
    \ toggle(t->ch[1]), t->rev_flg = false;\n  }\n  static inline void rot(Node *&t,\
    \ bool d) {\n    Node *s = t->ch[d];\n    t->ch[d] = s->ch[!d], s->ch[!d] = pushup(t),\
    \ t = pushup(s);\n  }\n  static inline void splay(Node *&t, std::size_t k) {\n\
    \    if (!t) return;\n    if constexpr (dual<M>::value) eval_propagate(t);\n \
    \   if constexpr (reversible) eval_toggle(t);\n    std::size_t sz = t->ch[0] ?\
    \ t->ch[0]->size : 0;\n    if (sz == k) return;\n    bool d = sz < k;\n    if\
    \ (d) k -= sz + 1;\n    if constexpr (dual<M>::value) eval_propagate(t->ch[d]);\n\
    \    if constexpr (reversible) eval_toggle(t->ch[d]);\n    sz = t->ch[d]->ch[0]\
    \ ? t->ch[d]->ch[0]->size : 0;\n    if (sz != k) {\n      bool c = sz < k;\n \
    \     if (c) k -= sz + 1;\n      splay(t->ch[d]->ch[c], k);\n      c == d ? rot(t,\
    \ d) : rot(t->ch[d], !d);\n    }\n    rot(t, d);\n  }\n  template <class F>\n\
    \  void query(std::size_t a, std::size_t b, const F &f) {\n    if (size() == b)\
    \ {\n      a-- ? (splay(root, a), f(root->ch[1]), pushup(root)) : (f(root), root);\n\
    \    } else {\n      splay(root, b);\n      a-- ? (splay(root->ch[0], a), f(root->ch[0]->ch[1]),\
    \ pushup(root->ch[0]))\n          : (f(root->ch[0]), root->ch[0]);\n      pushup(root);\n\
    \    }\n  }\n  static inline unsigned xor128() {\n    static unsigned x = 123456789,\
    \ y = 362436069, z = 521288629, w = 88675123;\n    unsigned t = (x ^ (x << 11));\n\
    \    return x = y, y = z, z = w, (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n  }\n\
    \n public:\n  SplayTree(Node *t = nullptr) : root(t) {}\n  SplayTree(std::size_t\
    \ n, T val = T()) { root = build(0, n, val); }\n  SplayTree(const T *bg, const\
    \ T *ed) { root = build(bg, ed); }\n  SplayTree(const std::vector<T> &ar)\n  \
    \    : SplayTree(ar.data(), ar.data() + ar.size()) {}\n  std::vector<T> dump()\
    \ {\n    std::vector<T> ret(size());\n    return dump(ret.begin(), root), ret;\n\
    \  }\n  static std::string which_available() {\n    std::string ret = \"\";\n\
    \    if constexpr (semigroup<M>::value)\n      ret += \"\\\"fold\\\" \";\n   \
    \ else\n      ret += \"\\\"at\\\" \";\n    if constexpr (dual<M>::value) ret +=\
    \ \"\\\"apply\\\" \";\n    if constexpr (reversible) ret += \"\\\"reverse\\\"\
    \ \";\n    return ret;\n  }\n  std::size_t size() { return root ? root->size :\
    \ 0; }\n  void clear() { root = nullptr; }\n  template <class L = M,\n       \
    \     typename std::enable_if_t<semigroup<L>::value> * = nullptr>\n  const T &operator[](std::size_t\
    \ k) {\n    return get(k);\n  }\n  template <class L = M,\n            typename\
    \ std::enable_if_t<!semigroup<L>::value> * = nullptr>\n  T &operator[](std::size_t\
    \ k) {\n    return at(k);\n  }\n  const T &get(std::size_t k) { return splay(root,\
    \ k), root->val; }\n  T &at(std::size_t k) {\n    static_assert(!semigroup<M>::value,\
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
    namespace modint_internal {\nusing namespace std;\nstruct modint_base {};\nstruct\
    \ sta_mint_base : modint_base {};\nstruct dyn_mint_base : modint_base {};\ntemplate\
    \ <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base, mod_t>;\n\
    template <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
    \ mod_t>;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\n\
    struct ModIntImpl {\n  static constexpr inline auto modulo() { return D::mod;\
    \ }\n  constexpr D operator-() const { return D() -= (D &)*this; }\n  constexpr\
    \ D &operator/=(const D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const\
    \ D &r) const { return D((D &)*this) += r; }\n  constexpr D operator-(const D\
    \ &r) const { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r)\
    \ const { return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const\
    \ { return D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const\
    \ { return !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D\
    \ ret(1), b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>=\
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    typename D::Int x = 1,\
    \ y = 0, a = ((D *)this)->val(), b = D::mod;\n    for (typename D::Int q = 0,\
    \ z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y * (q = a / b), a = b,\
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  friend ostream &operator<<(ostream\
    \ &os, const D &r) { return os << r.val(); }\n  friend istream &operator>>(istream\
    \ &is, D &r) {\n    long long v;\n    return is >> v, r = D(v), is;\n  }\n};\n\
    template <class B>\nstruct ModInt_Na : public B, public ModIntImpl<ModInt_Na<B>>\
    \ {\n  using Int = typename B::Int;\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, uint32_t>, u64, u128>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod) : n % B::mod)\
    \ {}\n#define ASSIGN(m, p) return x m## = B::mod & -((x p## = r.x) >= B::mod),\
    \ *this\n  constexpr ModInt_Na &operator+=(const ModInt_Na &r) { ASSIGN(-, +);\
    \ }\n  constexpr ModInt_Na &operator-=(const ModInt_Na &r) { ASSIGN(+, -); }\n\
    #undef ASSIGN\n  constexpr ModInt_Na &operator*=(const ModInt_Na &r) {\n    return\
    \ x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr bool operator==(const\
    \ ModInt_Na &r) const { return x == r.x; }\n  constexpr auto val() const { return\
    \ x; }\n\n private:\n  typename B::Uint x = 0;\n};\ntemplate <class B>\nstruct\
    \ ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>> {\n  using Int = int64_t;\n\
    \  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n  constexpr\
    \ ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n  template\
    \ <class T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod - ((-n)\
    \ % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op## = a, x\
    \ += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const mod_t\
    \ &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const mod_t\
    \ &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const mod_t\
    \ &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const mod_t\
    \ &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const {\n  \
    \  u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
    \  }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n   \
    \ return u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n\
    \  static constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r);\
    \ }\n  u64 x = 0;\n  constexpr inline u64 norm() const { return x - (B::mod &\
    \ -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n\
    \  return e ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\n\
    struct StaticB_Na : sta_mint_base {\n protected:\n  using Int = conditional_t\
    \ < MOD < INT_MAX, int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n\
    \  using Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing DynamicModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n\
    \                  ModInt_Na<DynamicB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::DynamicModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_dynamicmodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    #line 10 \"test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp\"\nusing\
    \ namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct RaffineRsumQ\
    \ {\n  using T = Mint;\n  using E = pair<T, T>;\n  static T op(const T &vl, const\
    \ T &vr) { return vl + vr; }\n  static void mapping(T &val, const E &f, int sz)\
    \ {\n    val = f.first * val + f.second * sz;\n  }\n  static void composition(E\
    \ &pre, const E &suf) {\n    pre = {pre.first * suf.first, suf.first * pre.second\
    \ + suf.second};\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  Mint a[N];\n  for (int i = 0; i < N; i++) cin\
    \ >> a[i];\n  SplayTree<RaffineRsumQ, true> splay(a, a + N);\n  for (int q = 0;\
    \ q < Q; q++) {\n    int op;\n    cin >> op;\n    if (op == 0) {\n      int i,\
    \ x;\n      cin >> i >> x;\n      splay.insert(i, x);\n    } else if (op == 1)\
    \ {\n      int i;\n      cin >> i;\n      splay.erase(i);\n    } else if (op ==\
    \ 2) {\n      int l, r;\n      cin >> l >> r;\n      splay.reverse(l, r);\n  \
    \  } else if (op == 3) {\n      int l, r, b, c;\n      cin >> l >> r >> b >> c;\n\
    \      splay.apply(l, r, {b, c});\n    } else {\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << splay.fold(l, r) << '\\n';\n    }\n    if (q % 100000\
    \ == 0) splay.set_balance();\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n// set_balance \u3057\u306A\u3044\u3068 \u30B9\u30BF\u30C3\u30AF\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\n// \uFF08\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    \ wrong_avl_killer_01\uFF09\n\n#include <bits/stdc++.h>\n#include \"src/DataStructure/SplayTree.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\n\
    struct RaffineRsumQ {\n  using T = Mint;\n  using E = pair<T, T>;\n  static T\
    \ op(const T &vl, const T &vr) { return vl + vr; }\n  static void mapping(T &val,\
    \ const E &f, int sz) {\n    val = f.first * val + f.second * sz;\n  }\n  static\
    \ void composition(E &pre, const E &suf) {\n    pre = {pre.first * suf.first,\
    \ suf.first * pre.second + suf.second};\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  Mint a[N];\n  for\
    \ (int i = 0; i < N; i++) cin >> a[i];\n  SplayTree<RaffineRsumQ, true> splay(a,\
    \ a + N);\n  for (int q = 0; q < Q; q++) {\n    int op;\n    cin >> op;\n    if\
    \ (op == 0) {\n      int i, x;\n      cin >> i >> x;\n      splay.insert(i, x);\n\
    \    } else if (op == 1) {\n      int i;\n      cin >> i;\n      splay.erase(i);\n\
    \    } else if (op == 2) {\n      int l, r;\n      cin >> l >> r;\n      splay.reverse(l,\
    \ r);\n    } else if (op == 3) {\n      int l, r, b, c;\n      cin >> l >> r >>\
    \ b >> c;\n      splay.apply(l, r, {b, c});\n    } else {\n      int l, r;\n \
    \     cin >> l >> r;\n      cout << splay.fold(l, r) << '\\n';\n    }\n    if\
    \ (q % 100000 == 0) splay.set_balance();\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/SplayTree.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-10-28 12:41:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
---
