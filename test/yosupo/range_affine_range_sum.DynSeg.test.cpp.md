---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dynamic.hpp
    title: "Segment-Tree(\u52D5\u7684\u69CB\u7BC9)"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.DynSeg.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n//\u9045\
    \u5EF6\u4F1D\u642C\u306Everify\n\n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\
    \n/**\n * @title Segment-Tree(\u52D5\u7684\u69CB\u7BC9)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * \u9045\u5EF6\u4F1D\u642C\u53EF\n * \u6C38\u7D9A\u5316\u53EF\
    \n * O(logN)\n */\n\n// verify\u7528:\n// https://codeforces.com/contest/464/problem/E\
    \ (\u6C38\u7D9A+\u9045\u5EF6\u4F1D\u642C+find*2)\n// https://codeforces.com/contest/947/problem/C\
    \ (find+xor)\n// https://codeforces.com/contest/966/problem/C (find+xor)\n// https://codeforces.com/contest/295/problem/E\
    \ (\u7279\u6B8A\u30E2\u30CE\u30A4\u30C9+\u5EA7\u5727\u30B5\u30DC\u308A)\n\n//\
    \ BEGIN CUT HERE\n\n#ifndef HAS_CHECK\n#define HAS_CHECK(member, Dummy)      \
    \                        \\\n  template <class T>                            \
    \              \\\n  struct has_##member {                                   \
    \    \\\n    template <class U, Dummy>                                 \\\n  \
    \  static std::true_type check(U *);                         \\\n    static std::false_type\
    \ check(...);                        \\\n    static T *mClass;               \
    \                          \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    #endif\n\ntemplate <typename M, bool persistent = false, std::uint8_t HEIGHT =\
    \ 30>\nclass SegmentTree_Dynamic {\n  HAS_MEMBER(op);\n  HAS_MEMBER(ti);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
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
    \ T &reflect(Node *&t) {\n    if constexpr (dual<M>::value && !monoid<M>::value)\n\
    \      if (t->lazy_flg)\n        t->val = M::mapping(t->val, t->lazy, 1), t->lazy_flg\
    \ = false;\n    return t->val;\n  }\n  static inline void propagate(Node *&t,\
    \ const E &x, const id_t &sz) {\n    t->lazy = t->lazy_flg ? M::composition(t->lazy,\
    \ x) : x, t->lazy_flg = true;\n    if constexpr (monoid<M>::value) t->val = M::mapping(t->val,\
    \ x, sz);\n  }\n  static inline void cp_node(Node *&t) {\n    if (!t)\n      t\
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
    \    id_t m = (b[0] + b[1]) >> 1;\n    if (cp_node(t); l <= b[0] && b[1] <= r)\
    \ return propagate(t, x, b[1] - b[0]);\n    eval(t, b[1] - b[0]);\n    apply(t->ch[0],\
    \ l, r, {b[0], m}, x), apply(t->ch[1], l, r, {m, b[1]}, x);\n    if constexpr\
    \ (monoid<M>::value) pushup(t);\n  }\n  void set_val(Node *&t, const id_t &k,\
    \ const T &val, std::uint8_t h) {\n    if (cp_node(t); !h) return reflect(t) =\
    \ val, void();\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n    set_val(t->ch[(k\
    \ >> (h - 1)) & 1], k, val, h - 1);\n    if constexpr (monoid<M>::value) pushup(t);\n\
    \  }\n  T &at_val(Node *&t, const id_t &k, std::uint8_t h) {\n    if (cp_node(t);\
    \ !h) return reflect(t);\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n\
    \    return at_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n  bool is_null(Node\
    \ *&t, const id_t &k, std::uint8_t h) {\n    if (!t) return true;\n    if (!h)\
    \ return false;\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n    return\
    \ is_null(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n  T get_val(Node *&t, const\
    \ id_t &k, std::uint8_t h) {\n    if (!t) return def_val();\n    if (!h) return\
    \ reflect(t);\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n    return\
    \ get_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n  template <bool last>\n\
    \  static inline T calc_op(Node *&t, const T &v) {\n    if constexpr (last)\n\
    \      return M::op((t ? t->val : def_val()), v);\n    else\n      return M::op(v,\
    \ (t ? t->val : def_val()));\n  }\n  template <bool last>\n  static inline bool\
    \ is_in(const id_t &m, const id_t &k) {\n    if constexpr (last)\n      return\
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
    \  }\n  SegmentTree_Dynamic(const T *bg, const T *ed) : root(nullptr) {\n    build(root,\
    \ ed - bg, {0, 1LL << HEIGHT}, bg);\n  }\n  SegmentTree_Dynamic(const std::vector<T>\
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
    \  //  check(fold(a,i)) == False, check(fold(a,i+1)) == True\n  // return -1 if\
    \ not found\n  template <class C>\n  id_t find_first(id_t a, C check, id_t bias\
    \ = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node *, 1> t{root};\n\
    \    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n  }\n\
    \  template <std::size_t N, class C>\n  static id_t find_first(id_t a, C check,\n\
    \                         std::array<SegmentTree_Dynamic, N> segs,\n         \
    \                id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  // find i s.t.\n  //  check(fold(i+1,b)) == False, check(fold(i,b))\
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
    \ - bg);\n    return dump(root, bg, ed, {0, 1LL << HEIGHT}, ret.begin()), ret;\n\
    \  }\n  static std::string which_available() {\n    std::string ret = \"\";\n\
    \    if constexpr (monoid<M>::value)\n      ret += \"\\\"fold\\\" \\\"find\\\"\
    \ \";\n    else\n      ret += \"\\\"at\\\" \";\n    if constexpr (dual<M>::value)\
    \ ret += \"\\\"apply\\\" \";\n    return ret;\n  }\n};\n#line 3 \"src/Math/ModInt.hpp\"\
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
    };\n#line 8 \"test/yosupo/range_affine_range_sum.DynSeg.test.cpp\"\n\nusing namespace\
    \ std;\n\nusing Mint = ModInt<998244353>;\nstruct RaffineQ_RsumQ {\n  using T\
    \ = Mint;\n  using E = pair<Mint, Mint>;\n  static T ti() { return 0; }\n  static\
    \ T op(const T &l, const T &r) { return l + r; }\n  static T mapping(const T &l,\
    \ const E &r, int sz) {\n    return r.first * l + r.second * sz;\n  }\n  static\
    \ E composition(const E &l, const E &r) {\n    return make_pair(r.first * l.first,\
    \ r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  Mint a[N];\n  for\
    \ (int i = 0; i < N; i++) cin >> a[i];\n  SegmentTree_Dynamic<RaffineQ_RsumQ>\
    \ seg(a, a + N);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op\
    \ >> l >> r;\n    if (op) {\n      cout << seg.fold(l, r) << endl;\n    } else\
    \ {\n      Mint b, c;\n      cin >> b >> c;\n      seg.apply(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n//\u9045\u5EF6\u4F1D\u642C\u306Everify\n\n#include <bits/stdc++.h>\n#include\
    \ \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n\nusing namespace std;\n\nusing Mint = ModInt<998244353>;\nstruct RaffineQ_RsumQ\
    \ {\n  using T = Mint;\n  using E = pair<Mint, Mint>;\n  static T ti() { return\
    \ 0; }\n  static T op(const T &l, const T &r) { return l + r; }\n  static T mapping(const\
    \ T &l, const E &r, int sz) {\n    return r.first * l + r.second * sz;\n  }\n\
    \  static E composition(const E &l, const E &r) {\n    return make_pair(r.first\
    \ * l.first, r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  Mint a[N];\n  for\
    \ (int i = 0; i < N; i++) cin >> a[i];\n  SegmentTree_Dynamic<RaffineQ_RsumQ>\
    \ seg(a, a + N);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op\
    \ >> l >> r;\n    if (op) {\n      cout << seg.fold(l, r) << endl;\n    } else\
    \ {\n      Mint b, c;\n      cin >> b >> c;\n      seg.apply(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree_Dynamic.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
  requiredBy: []
  timestamp: '2022-06-19 22:48:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.DynSeg.test.cpp
- /verify/test/yosupo/range_affine_range_sum.DynSeg.test.cpp.html
title: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
---
