---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/KDTree.hpp
    title: kD-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc234/tasks/abc234_h
    links:
    - https://atcoder.jp/contests/abc234/tasks/abc234_h
  bundledCode: "#line 1 \"test/atcoder/abc234_h.KDT.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc234/tasks/abc234_h\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/DataStructure/KDTree.hpp\"\n/**\n * @title kD-Tree\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @see https://trap.jp/post/1489/\n */\n\n\
    // verify\u7528\n// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g (\u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC+\u9045\u5EF6\u4F1D\u642C)\n// https://atcoder.jp/contests/past202004-open/tasks/past202004_n\
    \ (\u53CC\u5BFE)\n\n// BEGIN CUT HERE\n\n#ifndef HAS_CHECK\n#define HAS_CHECK(member,\
    \ Dummy)                              \\\n  template <class T>               \
    \                           \\\n  struct has_##member {                      \
    \                 \\\n    template <class U, Dummy>                          \
    \       \\\n    static std::true_type check(U *);                         \\\n\
    \    static std::false_type check(...);                        \\\n    static\
    \ T *mClass;                                         \\\n    static const bool\
    \ value = decltype(check(mClass))::value; \\\n  };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy = (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy = typename U::member)\n#endif\n\ntemplate <std::uint8_t K, class\
    \ pos_t, class M>\nclass KDTree {\n  HAS_MEMBER(op);\n  HAS_MEMBER(ti);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
    \ L>\n  using monoid = std::conjunction<has_T<L>, has_op<L>, has_ti<L>>;\n  template\
    \ <class L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class T, class F = std::nullptr_t>\n  struct\
    \ Node_B {\n    using E = F;\n    T val;\n    int ch[2] = {-1, -1};\n    pos_t\
    \ range[K][2], pos[K];\n  };\n  template <bool sg_, bool du_, typename tEnable\
    \ = void>\n  struct Node_D : Node_B<M> {};\n  template <bool sg_, bool du_>\n\
    \  struct Node_D<sg_, du_, typename std::enable_if_t<sg_ && !du_>>\n      : Node_B<typename\
    \ M::T> {\n    typename M::T sum;\n  };\n  template <bool sg_, bool du_>\n  struct\
    \ Node_D<sg_, du_, typename std::enable_if_t<!sg_ && du_>>\n      : Node_B<typename\
    \ M::T, typename M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n\
    \  };\n  template <bool sg_, bool du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<sg_\
    \ && du_>>\n      : Node_B<typename M::T, typename M::E> {\n    typename M::T\
    \ sum;\n    typename M::E lazy;\n    bool lazy_flg = false;\n  };\n  using Node\
    \ = Node_D<monoid<M>::value, dual<M>::value>;\n  using T = decltype(Node::val);\n\
    \  using E = typename Node::E;\n  std::vector<Node> ns;\n\n public:\n  using PosVal\
    \ = std::pair<std::array<pos_t, K>, T>;\n  using Iter = typename std::vector<PosVal>::iterator;\n\
    \  using Range = std::array<std::array<pos_t, 2>, K>;\n\n private:\n  inline void\
    \ pushup(int i) {\n    ns[i].sum = ns[i].val;\n    if (ns[i].ch[0] != -1) ns[i].sum\
    \ = M::op(ns[ns[i].ch[0]].sum, ns[i].sum);\n    if (ns[i].ch[1] != -1) ns[i].sum\
    \ = M::op(ns[i].sum, ns[ns[i].ch[1]].sum);\n  }\n  inline void propagate(int i,\
    \ const E &x) {\n    if (i == -1) return;\n    ns[i].lazy_flg ? (M::composition(ns[i].lazy,\
    \ x), x) : (ns[i].lazy = x);\n    M::mapping(ns[i].val, x), ns[i].lazy_flg = true;\n\
    \    if constexpr (monoid<M>::value) M::mapping(ns[i].sum, x);\n  }\n  inline\
    \ void eval(int i) {\n    if (!ns[i].lazy_flg) return;\n    ns[i].lazy_flg = false;\n\
    \    propagate(ns[i].ch[0], ns[i].lazy), propagate(ns[i].ch[1], ns[i].lazy);\n\
    \  }\n  inline void build(int &i, Iter bg, Iter ed, std::uint8_t div = 0) {\n\
    \    static int cnt = 0;\n    if (ed - bg < 1) return;\n    const int n = ed -\
    \ bg;\n    auto md = bg + n / 2;\n    std::nth_element(bg, md, ed, [div](const\
    \ PosVal &l, const PosVal &r) {\n      return l.first[div] < r.first[div];\n \
    \   });\n    ns[i = cnt++].val = md->second;\n    for (std::uint8_t j = K; j--;\
    \ ns[i].pos[j] = md->first[j]) {\n      auto [mn, mx] =\n          std::minmax_element(bg,\
    \ ed, [j](const PosVal &l, const PosVal &r) {\n            return l.first[j] <\
    \ r.first[j];\n          });\n      ns[i].range[j][0] = mn->first[j], ns[i].range[j][1]\
    \ = mx->first[j];\n    }\n    if (std::uint8_t nex = (div + 1) % K; n > 1)\n \
    \     build(ns[i].ch[0], bg, md, nex), build(ns[i].ch[1], md + 1, ed, nex);\n\
    \    if constexpr (monoid<M>::value) pushup(i);\n  }\n  template <class F, class\
    \ G, class H>\n  inline T fold(int i, const F &in, const G &inall, const H &outall)\
    \ {\n    static_assert(monoid<M>::value, \"\\\"fold\\\" is not available\");\n\
    \    if (i == -1 || outall(ns[i].range)) return M::ti();\n    if (inall(ns[i].range))\
    \ return ns[i].sum;\n    if constexpr (dual<M>::value) eval(i);\n    T ret = M::op(fold(ns[i].ch[0],\
    \ in, inall, outall),\n                  fold(ns[i].ch[1], in, inall, outall));\n\
    \    return in(ns[i].pos) ? M::op(ret, ns[i].val) : ret;\n  }\n  template <class\
    \ F, class G, class H>\n  inline void apply(int i, const F &in, const G &inall,\
    \ const H &outall,\n                    const E &x) {\n    static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\");\n    if (i == -1 || outall(ns[i].range))\
    \ return;\n    if (inall(ns[i].range)) return propagate(i, x), void();\n    if\
    \ (eval(i); in(ns[i].pos)) M::mapping(ns[i].val, x);\n    apply(ns[i].ch[0], in,\
    \ inall, outall, x);\n    apply(ns[i].ch[1], in, inall, outall, x);\n    if constexpr\
    \ (monoid<M>::value) pushup(i);\n  }\n  inline std::pair<T, bool> get(int i, const\
    \ std::array<pos_t, K> &pos) {\n    if (i == -1) return {T(), false};\n    bool\
    \ myself = true;\n    for (std::uint8_t j = K; j--; myself &= pos[j] == ns[i].pos[j])\n\
    \      if (ns[i].range[j][1] < pos[j] || pos[j] < ns[i].range[j][0])\n       \
    \ return {T(), false};\n    if (myself) return {ns[i].val, true};\n    if constexpr\
    \ (dual<M>::value) eval(i);\n    auto ret = get(ns[i].ch[0], pos);\n    return\
    \ !ret.second ? get(ns[i].ch[1], pos) : ret;\n  }\n  inline bool set(int i, const\
    \ std::array<pos_t, K> &pos, const T &x) {\n    if (i == -1) return false;\n \
    \   bool myself = true, ret = true;\n    for (std::uint8_t j = K; j--; myself\
    \ &= pos[j] == ns[i].pos[j])\n      if (ns[i].range[j][1] < pos[j] || pos[j] <\
    \ ns[i].range[j][0])\n        return false;\n    if constexpr (dual<M>::value)\
    \ eval(i);\n    if (myself)\n      ns[i].val = x;\n    else if (!(ret = set(ns[i].ch[0],\
    \ pos, x)))\n      ret = set(ns[i].ch[1], pos, x);\n    if constexpr (monoid<M>::value)\
    \ pushup(i);\n    return ret;\n  }\n  template <typename... Args>\n  static inline\
    \ Range to_range(std::initializer_list<Args>... intervals) {\n    static_assert(sizeof...(intervals)\
    \ == K);\n    static_assert(std::conjunction_v<std::is_same<Args, pos_t>...>);\n\
    \    Range r;\n    std::uint8_t i = 0;\n    for (auto &&x : {intervals...}) {\n\
    \      std::vector<pos_t> tmp(x);\n      assert(tmp.size() == 2), assert(tmp[0]\
    \ <= tmp[1]);\n      r[i][0] = tmp[0], r[i][1] = tmp[1], i++;\n    }\n    return\
    \ r;\n  }\n  static inline auto funcs(const Range &r) {\n    return std::make_tuple(\n\
    \        [r](pos_t pos[K]) {\n          for (std::uint8_t i = K; i--;)\n     \
    \       if (pos[i] < r[i][0] || r[i][1] < pos[i]) return false;\n          return\
    \ true;\n        },\n        [r](pos_t range[K][2]) {\n          for (std::uint8_t\
    \ i = K; i--;)\n            if (range[i][0] < r[i][0] || r[i][1] < range[i][1])\
    \ return false;\n          return true;\n        },\n        [r](pos_t range[K][2])\
    \ {\n          for (std::uint8_t i = K; i--;)\n            if (range[i][1] < r[i][0]\
    \ || r[i][1] < range[i][0]) return true;\n          return false;\n        });\n\
    \  }\n\n public:\n  KDTree(std::vector<PosVal> v) : ns(v.size()) {\n    int root;\n\
    \    build(root, v.begin(), v.end());\n  }\n  T get(std::array<pos_t, K> pos)\
    \ {\n    auto [ret, flg] = get(0, pos);\n    return assert(flg), ret;\n  }\n \
    \ template <typename... Args>\n  T get(Args... ids) {\n    static_assert(sizeof...(ids)\
    \ == K);\n    static_assert(std::conjunction_v<std::is_convertible<Args, pos_t>...>);\n\
    \    auto [ret, flg] = get(0, {ids...});\n    return assert(flg), ret;\n  }\n\
    \  void set(T x, std::array<pos_t, K> pos) { assert(set(0, pos, x)); }\n  template\
    \ <typename... Args>\n  void set(T x, Args... ids) {\n    static_assert(sizeof...(ids)\
    \ == K);\n    static_assert(std::conjunction_v<std::is_convertible<Args, pos_t>...>);\n\
    \    assert(set(0, {ids...}, x));\n  }\n  T fold(const Range &r) {\n    auto [in,\
    \ inall, outall] = funcs(r);\n    return fold(0, in, inall, outall);\n  }\n  template\
    \ <typename... Args>\n  T fold(std::initializer_list<Args> &&...intervals) {\n\
    \    auto r = to_range(intervals...);\n    auto [in, inall, outall] = funcs(r);\n\
    \    return fold(0, in, inall, outall);\n  }\n  template <class F, class G, class\
    \ H>\n  T fold(const F &in, const G &inall, const H &outall) {\n    return fold(0,\
    \ in, inall, outall);\n  }\n  void apply(E x, const Range &r) {\n    auto [in,\
    \ inall, outall] = funcs(r);\n    apply(0, in, inall, outall, x);\n  }\n  template\
    \ <typename... Args>\n  void apply(E x, std::initializer_list<Args> &&...intervals)\
    \ {\n    auto r = to_range(intervals...);\n    auto [in, inall, outall] = funcs(r);\n\
    \    apply(0, in, inall, outall, x);\n  }\n  template <class F, class G, class\
    \ H>\n  void apply(E x, const F &in, const G &inall, const H &outall) {\n    apply(0,\
    \ in, inall, outall, x);\n  }\n};\n#line 4 \"test/atcoder/abc234_h.KDT.test.cpp\"\
    \n\n//  \u5186\u5F62\u30AF\u30A8\u30EA\nusing namespace std;\n\nstruct IDs {\n\
    \  using T = vector<int>;\n  static T ti() { return {}; }\n  static T op(T l,\
    \ T r) {\n    if (l.size() < r.size()) l.swap(r);\n    for (int x : r) l.push_back(x);\n\
    \    return l;\n  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  long long N, K;\n  cin >> N >> K;\n  using KDT = KDTree<2, long long, IDs>;\n\
    \  std::vector<typename KDT::PosVal> v(N);\n  for (int i = 0; i < N; i++) {\n\
    \    long long x, y;\n    cin >> x >> y;\n    v[i].first = {x, y}, v[i].second\
    \ = {i + 1};\n  }\n  KDT kdt(v);\n  vector<pair<int, int>> ans;\n  for (auto [p,\
    \ ii] : v) {\n    auto [x, y] = p;\n    int i = ii[0];\n    auto in = [x, y, K](long\
    \ long pos[2]) {\n      long long dx = pos[0] - x, dy = pos[1] - y;\n      return\
    \ dx * dx + dy * dy <= K * K;\n    };\n    auto inall = [x, y, K](long long range[2][2])\
    \ {\n      long long dx = max(abs(range[0][0] - x), abs(range[0][1] - x));\n \
    \     long long dy = max(abs(range[1][0] - y), abs(range[1][1] - y));\n      return\
    \ dx * dx + dy * dy <= K * K;\n    };\n    auto outall = [x, y, K](long long range[2][2])\
    \ {\n      long long dx = clamp(x, range[0][0], range[0][1]) - x;\n      long\
    \ long dy = clamp(y, range[1][0], range[1][1]) - y;\n      return dx * dx + dy\
    \ * dy > K * K;\n    };\n    auto ids = kdt.fold(in, inall, outall);\n    for\
    \ (int j : ids)\n      if (i < j) ans.emplace_back(i, j);\n  }\n  sort(ans.begin(),\
    \ ans.end());\n  cout << ans.size() << '\\n';\n  for (auto [i, j] : ans) cout\
    \ << i << \" \" << j << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_h\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/DataStructure/KDTree.hpp\"\n\n//  \u5186\u5F62\
    \u30AF\u30A8\u30EA\nusing namespace std;\n\nstruct IDs {\n  using T = vector<int>;\n\
    \  static T ti() { return {}; }\n  static T op(T l, T r) {\n    if (l.size() <\
    \ r.size()) l.swap(r);\n    for (int x : r) l.push_back(x);\n    return l;\n \
    \ }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  long\
    \ long N, K;\n  cin >> N >> K;\n  using KDT = KDTree<2, long long, IDs>;\n  std::vector<typename\
    \ KDT::PosVal> v(N);\n  for (int i = 0; i < N; i++) {\n    long long x, y;\n \
    \   cin >> x >> y;\n    v[i].first = {x, y}, v[i].second = {i + 1};\n  }\n  KDT\
    \ kdt(v);\n  vector<pair<int, int>> ans;\n  for (auto [p, ii] : v) {\n    auto\
    \ [x, y] = p;\n    int i = ii[0];\n    auto in = [x, y, K](long long pos[2]) {\n\
    \      long long dx = pos[0] - x, dy = pos[1] - y;\n      return dx * dx + dy\
    \ * dy <= K * K;\n    };\n    auto inall = [x, y, K](long long range[2][2]) {\n\
    \      long long dx = max(abs(range[0][0] - x), abs(range[0][1] - x));\n     \
    \ long long dy = max(abs(range[1][0] - y), abs(range[1][1] - y));\n      return\
    \ dx * dx + dy * dy <= K * K;\n    };\n    auto outall = [x, y, K](long long range[2][2])\
    \ {\n      long long dx = clamp(x, range[0][0], range[0][1]) - x;\n      long\
    \ long dy = clamp(y, range[1][0], range[1][1]) - y;\n      return dx * dx + dy\
    \ * dy > K * K;\n    };\n    auto ids = kdt.fold(in, inall, outall);\n    for\
    \ (int j : ids)\n      if (i < j) ans.emplace_back(i, j);\n  }\n  sort(ans.begin(),\
    \ ans.end());\n  cout << ans.size() << '\\n';\n  for (auto [i, j] : ans) cout\
    \ << i << \" \" << j << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/KDTree.hpp
  isVerificationFile: true
  path: test/atcoder/abc234_h.KDT.test.cpp
  requiredBy: []
  timestamp: '2022-09-10 19:37:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc234_h.KDT.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc234_h.KDT.test.cpp
- /verify/test/atcoder/abc234_h.KDT.test.cpp.html
title: test/atcoder/abc234_h.KDT.test.cpp
---
