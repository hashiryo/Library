---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dynamic.hpp
    title: "Segment-Tree(\u52D5\u7684\u69CB\u7BC9)"
  - icon: ':question:'
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
    \ (\u7279\u6B8A\u30E2\u30CE\u30A4\u30C9+\u5EA7\u5727\u30B5\u30DC\u308A)\n// https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query\n\
    // (\u6C38\u7D9A)\n\n// BEGIN CUT HERE\n\n#ifndef HAS_CHECK\n#define HAS_CHECK(member,\
    \ Dummy)                              \\\n  template <class T>               \
    \                           \\\n  struct has_##member {                      \
    \                 \\\n    template <class U, Dummy>                          \
    \       \\\n    static std::true_type check(U *);                         \\\n\
    \    static std::false_type check(...);                        \\\n    static\
    \ T *mClass;                                         \\\n    static const bool\
    \ value = decltype(check(mClass))::value; \\\n  };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy = (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy = typename U::member)\n#endif\n\ntemplate <typename M, bool persistent\
    \ = false, std::uint8_t HEIGHT = 30>\nclass SegmentTree_Dynamic {\n  HAS_MEMBER(op);\n\
    \  HAS_MEMBER(ti);\n  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n\
    \  HAS_TYPE(E);\n  template <class L>\n  using monoid = std::conjunction<has_T<L>,\
    \ has_op<L>, has_ti<L>>;\n  template <class L>\n  using dual =\n      std::conjunction<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n  using id_t = long long;\n\
    \  template <class T, class tDerived, class F = std::nullptr_t>\n  struct Node_B\
    \ {\n    using E = F;\n    T val;\n    tDerived *ch[2] = {nullptr, nullptr};\n\
    \  };\n  template <bool mo_, bool du_, typename tEnable = void>\n  struct Node_D\
    \ : Node_B<M, Node_D<mo_, du_, tEnable>> {};\n  template <bool mo_, bool du_>\n\
    \  struct Node_D<mo_, du_, typename std::enable_if_t<mo_ && !du_>>\n      : Node_B<typename\
    \ M::T, Node_D<mo_, du_>> {};\n  template <bool mo_, bool du_>\n  struct Node_D<mo_,\
    \ du_, typename std::enable_if_t<du_>>\n      : Node_B<typename M::T, Node_D<mo_,\
    \ du_>, typename M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n\
    \  };\n  using Node = Node_D<monoid<M>::value, dual<M>::value>;\n  using T = decltype(Node::val);\n\
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
    \      if (t->lazy_flg) M::mapping(t->val, t->lazy, 1), t->lazy_flg = false;\n\
    \    return t->val;\n  }\n  static inline void propagate(Node *&t, const E &x,\
    \ const id_t &sz) {\n    t->lazy_flg ? (M::composition(t->lazy, x), x) : t->lazy\
    \ = x;\n    t->lazy_flg = true;\n    if constexpr (monoid<M>::value) M::mapping(t->val,\
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
    \ 1)) return ret;\n  }\n  constexpr D inv() const { return pow(D::mod - 2); }\n\
    \  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, u64>, u128, u64>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_integral_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod)\
    \ : n % B::mod) {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n#define ASSIGN(m,\
    \ p) return x m## = B::mod & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na\
    \ &operator+=(const ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const\
    \ ModInt_Na &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Uint = u64;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_integral_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    #define ASGN(op, a) return x op## = a, x += (B::mod << 1) & -(x >> 63), *this\n\
    \  constexpr mod_t &operator+=(const mod_t &r) { ASGN(+, r.x - (B::mod << 1));\
    \ }\n  constexpr mod_t &operator-=(const mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n\
    \  constexpr mod_t &operator*=(const mod_t &r) { return x = mul(x, r.x), *this;\
    \ }\n  constexpr bool operator==(const mod_t &r) const { return norm() == r.norm();\
    \ }\n  constexpr u64 val() const {\n    u64 ret = reduce(x) - B::mod;\n    return\
    \ ret + (B::mod & -(ret >> 63));\n  }\n\n private:\n  static constexpr inline\
    \ u64 reduce(const u128 &w) {\n    return u64(w >> 64) + B::mod - ((u128(u64(w)\
    \ * B::iv) * B::mod) >> 64);\n  }\n  static constexpr inline u64 mul(u64 l, u64\
    \ r) { return reduce(u128(l) * r); }\n  u64 x = 0;\n  constexpr inline u64 norm()\
    \ const { return x - (B::mod & -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64\
    \ n, int e = 6, u64 x = 1) {\n  return e ? mul_inv(n, e - 1, x * (2 - x * n))\
    \ : x;\n}\ntemplate <u64 MOD>\nstruct StaticB_Na : sta_mint_base {\n protected:\n\
    \  using Uint = conditional_t < MOD<UINT_MAX, uint32_t, u64>;\n  static constexpr\
    \ Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct StaticB_Mon : sta_mint_base\
    \ {\n protected:\n  static_assert(MOD & 1);\n  static constexpr u64 mod = MOD,\
    \ iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate <class Int, int id =\
    \ -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<Int>);\n\
    \  static inline void set_mod(Int m) { mod = m; }\n\n protected:\n  using Uint\
    \ = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate <int id>\n\
    struct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64 m) {\n\
    \    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n protected:\n\
    \  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing StaticModInt\
    \ =\n    conditional_t<mod &(mod >= UINT_MAX), ModInt_Mon<StaticB_Mon<mod>>,\n\
    \                  ModInt_Na<StaticB_Na<mod>>>;\nstruct Montgomery {};\ntemplate\
    \ <class Int, int id = -1>\nusing DynamicModInt =\n    conditional_t<is_same_v<Int,\
    \ Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n                  ModInt_Na<DynamicB_Na<Int,\
    \ id>>>;\n}  // namespace modint_internal\nusing modint_internal::DynamicModInt,\
    \ modint_internal::StaticModInt,\n    modint_internal::Montgomery, modint_internal::is_dynamicmodint_v,\n\
    \    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n#line\
    \ 8 \"test/yosupo/range_affine_range_sum.DynSeg.test.cpp\"\n\nusing namespace\
    \ std;\n\nusing Mint = StaticModInt<998244353>;\nstruct RaffineQ_RsumQ {\n  using\
    \ T = Mint;\n  using E = pair<Mint, Mint>;\n  static T ti() { return 0; }\n  static\
    \ T op(const T &l, const T &r) { return l + r; }\n  static void mapping(T &v,\
    \ const E &f, int sz) {\n    v = f.first * v + f.second * sz;\n  }\n  static void\
    \ composition(E &pre, const E &suf) {\n    pre = {suf.first * pre.first, suf.first\
    \ * pre.second + suf.second};\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  Mint a[N];\n  for (int i = 0; i < N; i++) cin\
    \ >> a[i];\n  SegmentTree_Dynamic<RaffineQ_RsumQ> seg(a, a + N);\n  while (Q--)\
    \ {\n    bool op;\n    int l, r;\n    cin >> op >> l >> r;\n    if (op) {\n  \
    \    cout << seg.fold(l, r) << endl;\n    } else {\n      Mint b, c;\n      cin\
    \ >> b >> c;\n      seg.apply(l, r, {Mint(b), Mint(c)});\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n//\u9045\u5EF6\u4F1D\u642C\u306Everify\n\n#include <bits/stdc++.h>\n#include\
    \ \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n\nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct RaffineQ_RsumQ\
    \ {\n  using T = Mint;\n  using E = pair<Mint, Mint>;\n  static T ti() { return\
    \ 0; }\n  static T op(const T &l, const T &r) { return l + r; }\n  static void\
    \ mapping(T &v, const E &f, int sz) {\n    v = f.first * v + f.second * sz;\n\
    \  }\n  static void composition(E &pre, const E &suf) {\n    pre = {suf.first\
    \ * pre.first, suf.first * pre.second + suf.second};\n  }\n};\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n\
    \  Mint a[N];\n  for (int i = 0; i < N; i++) cin >> a[i];\n  SegmentTree_Dynamic<RaffineQ_RsumQ>\
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
  timestamp: '2022-09-19 00:53:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.DynSeg.test.cpp
- /verify/test/yosupo/range_affine_range_sum.DynSeg.test.cpp.html
title: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
---
