---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/RedBlackTree_Lazy.hpp
    title: "\u8D64\u9ED2\u6728(\u9045\u5EF6\u4F1D\u642C)"
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
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.RBTL.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n//\u9045\
    \u5EF6\u4F1D\u642C\u306Everify\n#include <bits/stdc++.h>\n\n#line 3 \"src/DataStructure/RedBlackTree_Lazy.hpp\"\
    \n/**\n * @title \u8D64\u9ED2\u6728(\u9045\u5EF6\u4F1D\u642C)\n * @category \u30C7\
    \u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <typename M, size_t LIM = 1 << 20>\nstruct RedBlackTree_Lazy {\n  using T =\
    \ typename M::T;\n  using E = typename M::E;\n  using RBTL = RedBlackTree_Lazy;\n\
    \n public:\n  enum COLOR { BLACK, RED };\n  struct Node {\n    Node *ch[2];\n\
    \    COLOR color;\n    int level, cnt;\n    T val, dat;\n    E lazy;\n    Node()\
    \ {}\n    Node(const T &k)\n        : val(k),\n          dat(k),\n          ch{nullptr,\
    \ nullptr},\n          color(BLACK),\n          level(0),\n          cnt(1),\n\
    \          lazy(M::ei()) {}\n    Node(Node *l, Node *r, const T &k)\n        :\
    \ val(k), color(RED), ch{l, r}, lazy(M::ei()) {}\n  };\n  struct nPool {\n   \
    \ std::vector<Node> pool;\n    std::vector<Node *> stock;\n    int ptr;\n    nPool(int\
    \ sz) : pool(sz), stock(sz) { clear(); }\n    inline Node *alloc() { return stock[--ptr];\
    \ }\n    inline void free(Node *t) { stock[ptr++] = t; }\n    void clear() {\n\
    \      ptr = (int)pool.size();\n      for (int i = 0; i < pool.size(); i++) stock[i]\
    \ = &pool[i];\n    }\n  };\n\n protected:\n  inline Node *alloc(Node *l, Node\
    \ *r) {\n    auto t = &(*pool.alloc() = Node(l, r, M::ti()));\n    return pushup(t);\n\
    \  }\n  virtual Node *clone(Node *t) { return t; }\n  Node *propagate(Node *t)\
    \ {\n    t = clone(t);\n    if (t->lazy != M::ei()) {\n      if (!t->ch[0]) {\n\
    \        t->val = M::g(t->val, t->lazy);\n      } else {\n        for (char b\
    \ = 0; b < 2; b++)\n          if (t->ch[b]) {\n            t->ch[b] = clone(t->ch[b]);\n\
    \            t->ch[b]->lazy = M::h(t->ch[b]->lazy, t->lazy);\n            t->ch[b]->dat\
    \ = M::g(t->ch[b]->dat, t->lazy);\n          }\n      }\n      t->lazy = M::ei();\n\
    \    }\n    return pushup(t);\n  }\n  inline Node *rotate(Node *t, bool b) {\n\
    \    Node *s;\n    s = propagate(t->ch[!b]);\n    t->ch[!b] = s->ch[b];\n    s->ch[b]\
    \ = t;\n    pushup(t);\n    return pushup(s);\n  }\n  Node *submerge(Node *l,\
    \ Node *r) {\n    if (l->level == r->level) return alloc(l, r);\n    bool b =\
    \ l->level < r->level;\n    if (!b) std::swap(l, r);\n    r = propagate(r);\n\
    \    Node *c = (r->ch[!b] = b ? submerge(l, r->ch[0]) : submerge(r->ch[1], l));\n\
    \    if (r->color == BLACK && c->color == RED && c->ch[!b]\n        && c->ch[!b]->color\
    \ == RED) {\n      r->color = RED;\n      c->color = BLACK;\n      if (r->ch[b]->color\
    \ == BLACK) return rotate(r, b);\n      r->ch[b]->color = BLACK;\n    }\n    return\
    \ pushup(r);\n  }\n  Node *build(int l, int r, const std::vector<T> &v) {\n  \
    \  if (l + 1 >= r) return alloc(v[l]);\n    return merge(build(l, (l + r) >> 1,\
    \ v), build((l + r) >> 1, r, v));\n  }\n  Node *pushup(Node *t) {\n    t->cnt\
    \ = count(t->ch[0]) + count(t->ch[1]) + !t->ch[0];\n    t->level = t->ch[0] ?\
    \ t->ch[0]->level + (t->ch[0]->color == BLACK) : 0;\n    t->dat = M::f(M::f(dat(t->ch[0]),\
    \ t->val), dat(t->ch[1]));\n    return t;\n  }\n  void dump(Node *r, typename\
    \ std::vector<T>::iterator &it, E lazy) {\n    if (r->lazy != M::ei()) lazy =\
    \ M::h(lazy, r->lazy);\n    if (r->ch[0] == nullptr) {\n      *it++ = M::g(r->val,\
    \ lazy);\n      return;\n    }\n    dump(r->ch[0], it, lazy);\n    dump(r->ch[1],\
    \ it, lazy);\n  }\n  inline Node *alloc(const T &val) { return &(*pool.alloc()\
    \ = Node(val)); }\n  inline int count(const Node *t) { return t ? t->cnt : 0;\
    \ }\n  inline const T dat(const Node *t) { return t ? t->dat : M::ti(); }\n  std::pair<Node\
    \ *, Node *> split(Node *t, int k) {\n    if (!t) return {nullptr, nullptr};\n\
    \    t = propagate(t);\n    if (k == 0) return {nullptr, t};\n    if (k >= count(t))\
    \ return {t, nullptr};\n    Node *l = t->ch[0], *r = t->ch[1];\n    pool.free(t);\n\
    \    if (k < count(l)) {\n      auto pp = split(l, k);\n      return {pp.first,\
    \ merge(pp.second, r)};\n    }\n    if (k > count(l)) {\n      auto pp = split(r,\
    \ k - count(l));\n      return {merge(l, pp.first), pp.second};\n    }\n    return\
    \ {l, r};\n  }\n  Node *merge(Node *l, Node *r) {\n    if (!l || !r) return l\
    \ ? l : r;\n    Node *c = submerge(l, r);\n    c->color = BLACK;\n    return c;\n\
    \  }\n  void set_val(Node *&t, int k, const T &x) {\n    if (!t->ch[0]) {\n  \
    \    t = clone(t);\n      t->val = t->dat = x;\n      return;\n    }\n    t =\
    \ propagate(t);\n    if (k < count(t->ch[0]))\n      set_val(t->ch[0], k, x);\n\
    \    else\n      set_val(t->ch[1], k - count(t->ch[0]), x);\n    t = pushup(t);\n\
    \  }\n  T get(Node *&t, int k) {\n    if (!t->ch[0]) return t->val;\n    return\
    \ k < count(t->ch[0]) ? get(t->ch[0], k)\n                               : get(t->ch[1],\
    \ k - count(t->ch[0]));\n  }\n  RedBlackTree_Lazy(Node *t) : root(t) {}\n\n protected:\n\
    \  static nPool pool;\n  Node *root;\n\n public:\n  RedBlackTree_Lazy() : root(nullptr)\
    \ {}\n  RedBlackTree_Lazy(int n, T val = M::ti())\n      : RedBlackTree_Lazy(std::vector<T>(n,\
    \ val)) {}\n  RedBlackTree_Lazy(const std::vector<T> &v) {\n    root = build(0,\
    \ (int)v.size(), v);\n  }\n  void build(const std::vector<T> &v) { root = build(0,\
    \ (int)v.size(), v); }\n  void push_front(const T &v) { root = merge(alloc(v),\
    \ root); }\n  void push_back(const T &v) { root = merge(root, alloc(v)); }\n \
    \ T pop_front() {\n    auto ret = split(root, 1);\n    root = ret.second;\n  \
    \  return ret.first->val;\n  }\n  T pop_back() {\n    auto ret = split(root, count(root)\
    \ - 1);\n    root = ret.first;\n    return ret.second->val;\n  }\n  // merge\n\
    \  RBTL operator+(const RBTL &r) {\n    if (!this->root || !r.root) return this->root\
    \ ? *this : r;\n    Node *c = submerge(this->root, r.root);\n    c->color = BLACK;\n\
    \    return RBTL(c);\n  }\n  // [0,k) [k,size)\n  std::pair<RBTL, RBTL> split(int\
    \ k) {\n    auto tmp = split(root, k);\n    return std::make_pair(RBTL(tmp.first),\
    \ RBTL(tmp.first));\n  }\n  // [0,a) [a,b) [b,size)\n  std::tuple<RBTL, RBTL,\
    \ RBTL> split3(int a, int b) {\n    auto x = split(root, a);\n    auto y = split(x.second,\
    \ b - a);\n    return std::make_tuple(RBTL(x.first), RBTL(y.first), RBTL(y.second));\n\
    \  }\n  void insert(int k, const T &v) {\n    auto x = split(root, k);\n    root\
    \ = merge(merge(x.first, alloc(v)), x.second);\n  }\n  T erase(int k) {\n    auto\
    \ x = split(root, k);\n    auto y = split(x.second, 1);\n    T v = y.first->val;\n\
    \    pool.free(y.first);\n    root = merge(x.first, y.second);\n    return v;\n\
    \  }\n  //[a,b)\n  T query(int a, int b) {\n    auto x = split(root, a);\n   \
    \ auto y = split(x.second, b - a);\n    T ret = dat(y.first);\n    root = merge(x.first,\
    \ merge(y.first, y.second));\n    return ret;\n  }\n  T operator[](int k) { return\
    \ get(root, k); }\n  void set_val(int k, const T &x) { set_val(root, k, x); }\n\
    \  //[a,b)\n  void update(int a, int b, E v) {\n    auto x = split(root, a);\n\
    \    auto y = split(x.second, b - a);\n    y.first->lazy = M::h(y.first->lazy,\
    \ v);\n    root = merge(x.first, merge(propagate(y.first), y.second));\n  }\n\
    \  std::vector<T> dump() {\n    std::vector<T> v((size_t)count(root));\n    auto\
    \ it = begin(v);\n    dump(root, it, M::ei());\n    return v;\n  }\n  int size()\
    \ { return count(root); }\n};\ntemplate <typename M, size_t LIM>\ntypename RedBlackTree_Lazy<M,\
    \ LIM>::nPool RedBlackTree_Lazy<M, LIM>::pool(LIM);\n#line 3 \"src/Math/ModInt.hpp\"\
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
    };\n#line 7 \"test/yosupo/range_affine_range_sum.RBTL.test.cpp\"\nusing namespace\
    \ std;\n\nusing Mint = ModInt<998244353>;\n// RsumQ\u306F\u30E2\u30CE\u30A4\u30C9\
    \u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\u3066\u304A\u304F\nstruct RaffineQ_RsumQ\
    \ {\n  struct T {\n    Mint val;\n    int size;\n    T(Mint v = 0, int s = 1)\
    \ : val(v), size(s) {}\n  };\n  using E = pair<Mint, Mint>;\n  static T ti() {\
    \ return T(0, 0); }\n  static E ei() { return make_pair(Mint(1), Mint(0)); }\n\
    \  static T f(const T &l, const T &r) {\n    return T(l.val + r.val, l.size +\
    \ r.size);\n  }\n  static T g(const T &l, const E &r) {\n    return T(r.first\
    \ * l.val + r.second * l.size, l.size);\n  }\n  static E h(const E &l, const E\
    \ &r) {\n    return make_pair(r.first * l.first, r.first * l.second + r.second);\n\
    \  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<RaffineQ_RsumQ::T> v(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    Mint a;\n    cin >> a;\n    v[i] = {a, 1};\n  }\n  RedBlackTree_Lazy<RaffineQ_RsumQ>\
    \ rbt(v);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op >> l >>\
    \ r;\n    if (op) {\n      cout << rbt.query(l, r).val << endl;\n    } else {\n\
    \      Mint b, c;\n      cin >> b >> c;\n      rbt.update(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n//\u9045\u5EF6\u4F1D\u642C\u306Everify\n#include <bits/stdc++.h>\n\n#include\
    \ \"src/DataStructure/RedBlackTree_Lazy.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \nusing namespace std;\n\nusing Mint = ModInt<998244353>;\n// RsumQ\u306F\u30E2\
    \u30CE\u30A4\u30C9\u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\u3066\u304A\u304F\
    \nstruct RaffineQ_RsumQ {\n  struct T {\n    Mint val;\n    int size;\n    T(Mint\
    \ v = 0, int s = 1) : val(v), size(s) {}\n  };\n  using E = pair<Mint, Mint>;\n\
    \  static T ti() { return T(0, 0); }\n  static E ei() { return make_pair(Mint(1),\
    \ Mint(0)); }\n  static T f(const T &l, const T &r) {\n    return T(l.val + r.val,\
    \ l.size + r.size);\n  }\n  static T g(const T &l, const E &r) {\n    return T(r.first\
    \ * l.val + r.second * l.size, l.size);\n  }\n  static E h(const E &l, const E\
    \ &r) {\n    return make_pair(r.first * l.first, r.first * l.second + r.second);\n\
    \  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<RaffineQ_RsumQ::T> v(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    Mint a;\n    cin >> a;\n    v[i] = {a, 1};\n  }\n  RedBlackTree_Lazy<RaffineQ_RsumQ>\
    \ rbt(v);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op >> l >>\
    \ r;\n    if (op) {\n      cout << rbt.query(l, r).val << endl;\n    } else {\n\
    \      Mint b, c;\n      cin >> b >> c;\n      rbt.update(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/RedBlackTree_Lazy.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.RBTL.test.cpp
  requiredBy: []
  timestamp: '2021-10-24 00:31:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.RBTL.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.RBTL.test.cpp
- /verify/test/yosupo/range_affine_range_sum.RBTL.test.cpp.html
title: test/yosupo/range_affine_range_sum.RBTL.test.cpp
---
