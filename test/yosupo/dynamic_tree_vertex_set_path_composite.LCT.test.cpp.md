---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/LinkCutTree_Monoid.hpp
    title: "Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9)"
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/LinkCutTree_Monoid.hpp\"\
    \n/**\n * @title Link-Cut-Tree(\u30E2\u30CE\u30A4\u30C9)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename\
    \ M>\nstruct LinkCutTree_Monoid {\n  using T = typename M::T;\n  struct Node {\n\
    \    Node *ch[2], *par;\n    bool rev;\n    T val, dat, rdat;\n    Node(T init\
    \ = M::ti()) : rev(false), val(init), dat(init), rdat(init) {\n      ch[0] = ch[1]\
    \ = par = nullptr;\n    }\n  };\n\n private:\n  bool is_root(Node *x) {\n    return\
    \ !x->par || (x->par->ch[0] != x && x->par->ch[1] != x);\n  }\n  bool dir(Node\
    \ *x) { return x->par && x->par->ch[1] == x; }\n  void rot(Node *t) {\n    Node\
    \ *p = t->par;\n    bool d = dir(t);\n    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par\
    \ = p;\n    t->ch[!d] = p;\n    pushup(p);\n    pushup(t);\n    t->par = p->par;\n\
    \    if (!is_root(p)) {\n      p->par->ch[dir(p)] = t;\n      pushup(t->par);\n\
    \    }\n    p->par = t;\n  }\n  void splay(Node *x) {\n    eval(x);\n    while\
    \ (!is_root(x)) {\n      if (!is_root(x->par)) eval(x->par->par);\n      eval(x->par);\n\
    \      eval(x);\n      if (!is_root(x->par)) {\n        if (dir(x) == dir(x->par))\n\
    \          rot(x->par);\n        else\n          rot(x);\n      }\n      rot(x);\n\
    \    }\n  }\n  void pushup(Node *t) {\n    t->rdat = t->dat = t->val;\n    if\
    \ (t->ch[0])\n      t->dat = M::f(t->ch[0]->dat, t->dat),\n      t->rdat = M::f(t->rdat,\
    \ t->ch[0]->rdat);\n    if (t->ch[1])\n      t->dat = M::f(t->dat, t->ch[1]->dat),\n\
    \      t->rdat = M::f(t->ch[1]->rdat, t->rdat);\n  }\n  Node *expose(Node *x)\
    \ {\n    Node *r = nullptr;\n    for (Node *p = x; p; p = p->par) {\n      splay(p);\n\
    \      p->ch[1] = r;\n      pushup(p);\n      r = p;\n    }\n    splay(x);\n \
    \   return r;\n  }\n  void toggle(Node *t) {\n    std::swap(t->ch[0], t->ch[1]);\n\
    \    std::swap(t->dat, t->rdat);\n    t->rev ^= 1;\n  }\n  Node *eval(Node *t)\
    \ {\n    if (t->rev) {\n      if (t->ch[0]) toggle(t->ch[0]);\n      if (t->ch[1])\
    \ toggle(t->ch[1]);\n      t->rev = false;\n    }\n    return t;\n  }\n\n private:\n\
    \  std::vector<Node> ns;\n  size_t linkcnt;\n\n public:\n  LinkCutTree_Monoid(int\
    \ n, T init = M::ti()) : ns(n, init), linkcnt(0) {}\n  // make k the root\n  void\
    \ evert(int k) {\n    expose(&ns[k]);\n    toggle(&ns[k]);\n    eval(&ns[k]);\n\
    \  }\n  // add link from c to p\n  void link(int c, int p) {\n    assert(linkcnt++\
    \ < ns.size() - 1);\n    evert(c);\n    expose(&ns[p]);\n    ns[p].ch[1] = &ns[c];\n\
    \    ns[c].par = &ns[p];\n    pushup(&ns[p]);\n  }\n  // cut link from c to p\n\
    \  void cut(int c, int p) {\n    linkcnt--;\n    evert(p);\n    expose(&ns[c]);\n\
    \    Node *y = ns[c].ch[0];\n    ns[c].ch[0] = y->par = nullptr;\n    pushup(&ns[c]);\n\
    \  }\n  int lca(int x, int y) {\n    expose(&ns[x]);\n    Node *u = expose(&ns[y]);\n\
    \    return ns[x].par ? u - &ns[0] : -1;\n  }\n  T operator[](int k) { return\
    \ ns[k].val; }\n  // [a,b] closed section\n  T query(int a, int b) {\n    evert(a);\n\
    \    expose(&ns[b]);\n    return ns[b].dat;\n  }\n  void set_val(int k, T v) {\n\
    \    expose(&ns[k]);\n    ns[k].val = v;\n    eval(&ns[k]);\n  }\n};\n#line 3\
    \ \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <std::uint64_t mod, std::uint64_t prim_root\
    \ = 0>\nclass ModInt {\n  using u64 = std::uint64_t;\n  using u128 = __uint128_t;\n\
    \  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e ==\
    \ 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv\
    \ = mul_inv(mod, 6, 1), r2 = -u128(mod) % mod;\n  static constexpr u64 init(u64\
    \ w) { return reduce(u128(w) * r2); }\n  static constexpr u64 reduce(const u128\
    \ w) {\n    return u64(w >> 64) + mod - ((u128(u64(w) * inv) * mod) >> 64);\n\
    \  }\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t\
    \ n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static\
    \ constexpr u64 modulo() { return mod; }\n  static constexpr u64 norm(u64 w) {\
    \ return w - (mod & -(w >= mod)); }\n  static constexpr u64 pr_rt() { return prim_root;\
    \ }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x\
    \ = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n    return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >>\
    \ 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return\
    \ x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(u128(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr ModInt pow(u64 k) const {\n    ModInt ret\
    \ = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *= base)\n    \
    \  if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt inverse()\
    \ const { return pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this\
    \ == ModInt(0) || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return\
    \ ModInt(0);  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n \
    \   while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto\
    \ mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt, ModInt> v) {\n    \
    \  ModInt a = (u.first * v.first + u.second * v.second * w);\n      ModInt b =\
    \ (u.first * v.second + u.second * v.first);\n      return std::make_pair(a, b);\n\
    \    };\n    u64 e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n\
    \    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n  \
    \    if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.val();\n\
    \  }\n  u64 x;\n};\n#line 6 \"test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp\"\
    \nusing namespace std;\n#undef call_from_test\n\nusing Mint = ModInt<998244353>;\n\
    struct RcompositeQ {\n  using T = pair<Mint, Mint>;\n  static T ti() { return\
    \ make_pair(Mint(1), Mint(0)); }\n  static T f(const T &l, const T &r) {\n   \
    \ return make_pair(r.first * l.first, r.first * l.second + r.second);\n  }\n};\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  LinkCutTree_Monoid<RcompositeQ> lct(N);\n  for (int i = 0; i <\
    \ N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n    lct.set_val(i, {a, b});\n\
    \  }\n  for (int i = 0; i < N - 1; i++) {\n    int u, v;\n    cin >> u >> v;\n\
    \    lct.link(u, v);\n  }\n  while (Q--) {\n    int op;\n    cin >> op;\n    if\
    \ (op == 0) {\n      int u, v, w, x;\n      cin >> u >> v >> w >> x;\n      lct.cut(u,\
    \ v);\n      lct.link(w, x);\n    } else if (op == 1) {\n      int p;\n      Mint\
    \ c, d;\n      cin >> p >> c >> d;\n      lct.set_val(p, {c, d});\n    } else\
    \ {\n      int u, v;\n      Mint x;\n      cin >> u >> v >> x;\n      auto ans\
    \ = lct.query(u, v);\n      cout << ans.first * x + ans.second << endl;\n    }\n\
    \  }\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/LinkCutTree_Monoid.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n#undef call_from_test\n\
    \nusing Mint = ModInt<998244353>;\nstruct RcompositeQ {\n  using T = pair<Mint,\
    \ Mint>;\n  static T ti() { return make_pair(Mint(1), Mint(0)); }\n  static T\
    \ f(const T &l, const T &r) {\n    return make_pair(r.first * l.first, r.first\
    \ * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  LinkCutTree_Monoid<RcompositeQ> lct(N);\n  for\
    \ (int i = 0; i < N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n    lct.set_val(i,\
    \ {a, b});\n  }\n  for (int i = 0; i < N - 1; i++) {\n    int u, v;\n    cin >>\
    \ u >> v;\n    lct.link(u, v);\n  }\n  while (Q--) {\n    int op;\n    cin >>\
    \ op;\n    if (op == 0) {\n      int u, v, w, x;\n      cin >> u >> v >> w >>\
    \ x;\n      lct.cut(u, v);\n      lct.link(w, x);\n    } else if (op == 1) {\n\
    \      int p;\n      Mint c, d;\n      cin >> p >> c >> d;\n      lct.set_val(p,\
    \ {c, d});\n    } else {\n      int u, v;\n      Mint x;\n      cin >> u >> v\
    \ >> x;\n      auto ans = lct.query(u, v);\n      cout << ans.first * x + ans.second\
    \ << endl;\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/LinkCutTree_Monoid.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  requiredBy: []
  timestamp: '2021-02-02 14:03:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
---
