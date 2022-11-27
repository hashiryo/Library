---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SplayTree.hpp
    title: Splay-Tree
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
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
    \    else\n      root = root->ch[0];\n    return ret;\n  }\n};\n#line 3 \"src/Math/mod_inv.hpp\"\
    \n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\
    \u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0,\
    \ b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y =\
    \ z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ?\
    \ mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n\
    \ * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category \u6570\
    \u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\n\
    namespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\nclass MIntPro_Montg {\n  u64 mod,\
    \ iv, r2;\n  constexpr u64 inv(u64 n, int e = 6, u64 x = 1) {\n    return e ?\
    \ inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n  constexpr inline u64 reduce(const\
    \ u128 &w) const {\n    return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod)\
    \ >> 64);\n  }\n\n public:\n  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0)\
    \ {}\n  constexpr MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod)\
    \ {}\n  constexpr inline u64 mul(u64 l, u64 r) const { return reduce(u128(l) *\
    \ r); }\n#define BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n\
    \  constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n\
    \  constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n\
    \  constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline\
    \ u64 get(u64 n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n -\
    \ (mod & -(n >= mod)); }\n  constexpr u64 modulo() const { return mod; }\n};\n\
    template <class Uint>\nclass MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\n  Uint mod;\n\n public:\n  constexpr MIntPro_Na() : mod(0){};\n\
    \  constexpr MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint\
    \ l, Uint r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l\
    \ m## = mod & -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint\
    \ r) const { BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const\
    \ { BOP(+, -); }\n#undef BOP\n  constexpr inline Uint set(u64 n) const { return\
    \ n % mod; }\n  static constexpr inline Uint get(Uint n) { return n; }\n  static\
    \ constexpr inline Uint norm(Uint n) { return n; }\n  constexpr Uint modulo()\
    \ const { return mod; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n\
    \ * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class Uint, class B>\nstruct ModInt : public B\
    \ {\n  static constexpr inline auto modulo() { return B::md.modulo(); }\n  constexpr\
    \ ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x) {}\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt(T\
    \ v) : x(B::md.set(v.val())) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt(T n)\n      : x(B::md.set(n\
    \ < 0 ? modulo() - ((-n) % modulo()) : n)) {}\n  constexpr ModInt operator-()\
    \ const { return ModInt() - *this; }\n#define FUNC(name, op)          \\\n  constexpr\
    \ ModInt name const { \\\n    ModInt ret;                 \\\n    return ret.x\
    \ = op, ret;     \\\n  }\n  FUNC(operator+(const ModInt &r), B::md.plus(x, r.x))\n\
    \  FUNC(operator-(const ModInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const\
    \ ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k,\
    \ B::md))\n#undef FUNC\n  constexpr ModInt operator/(const ModInt &r) const {\
    \ return *this * r.inv(); }\n  constexpr ModInt &operator+=(const ModInt &r) {\
    \ return *this = *this + r; }\n  constexpr ModInt &operator-=(const ModInt &r)\
    \ { return *this = *this - r; }\n  constexpr ModInt &operator*=(const ModInt &r)\
    \ { return *this = *this * r; }\n  constexpr ModInt &operator/=(const ModInt &r)\
    \ { return *this = *this / r; }\n  constexpr bool operator==(const ModInt &r)\
    \ const {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr bool\
    \ operator!=(const ModInt &r) const { return !(*this == r); }\n  constexpr bool\
    \ operator<(const ModInt &r) const {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
    \  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(), modulo());\
    \ }\n  constexpr inline Uint val() const { return B::md.get(x); }\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &r) {\n    return os << r.val();\n  }\n\
    \  friend istream &operator>>(istream &is, ModInt &r) {\n    long long v;\n  \
    \  return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX, ModInt<int,\
    \ u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD &(MOD < LLONG_MAX),\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Montg, MOD>>,\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>, MOD>>>>;\n\
    class Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt =\
    \ conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM>\n\
    mod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l = 1;\n  if (l\
    \ == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m % l] * (m - m / l);\n\
    \  return dat[n];\n}\n#line 10 \"test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct RaffineRsumQ\
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
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-11-27 21:09:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
---
