---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SkewHeap.hpp
    title: Skew-Heap
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_9_C.SkewHeap.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SkewHeap.hpp\"\n/**\n\
    \ * @title Skew-Heap\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief \u30DE\
    \u30FC\u30B8\u3067\u304D\u308B\u30D2\u30FC\u30D7\n * @brief top: O(1), pop, push,\
    \ merge: O(logN)\n * @brief apply(v): \u5168\u4F53\u306B\u4F5C\u7528\u7D20v\u3092\
    \u9069\u7528\n */\n\n// BEGIN CUT HERE\n\n#define HAS_CHECK(member, Dummy)   \
    \                           \\\n  template <class tClass>                    \
    \                 \\\n  struct has_##member {                                \
    \       \\\n    template <class U, Dummy>                                 \\\n\
    \    static std::true_type check(U *);                         \\\n    static\
    \ std::false_type check(...);                        \\\n    static tClass *mClass;\
    \                                    \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    \ntemplate <typename T, typename Compare = std::less<T>, typename M = void>\n\
    struct SkewHeap {\n  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(E);\n\
    \  template <class L>\n  using dual = std::conjunction<has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class tDerived, class U = std::nullptr_t>\n\
    \  struct Node_B {\n    using E = U;\n    T key;\n    tDerived *ch[2];\n  };\n\
    \  template <bool du_, typename tEnable = void>\n  struct Node_D : Node_B<Node_D<du_>>\
    \ {};\n  template <bool du_>\n  struct Node_D<du_, typename std::enable_if_t<du_>>\n\
    \      : Node_B<Node_D<du_>, typename M::E> {\n    typename M::E lazy;\n    bool\
    \ lazy_flg = false;\n  };\n  using Node = Node_D<dual<M>::value>;\n  using E =\
    \ typename Node::E;\n  Node *root;\n  static inline void propagate(Node *&t, const\
    \ E &x) {\n    if (!t) return;\n    t->lazy_flg ? (M::composition(t->lazy, x),\
    \ x) : (t->lazy = x);\n    M::mapping(t->key, x), t->lazy_flg = true;\n  }\n \
    \ static inline void eval(Node *t) {\n    if (t->lazy_flg)\n      propagate(t->ch[0],\
    \ t->lazy), propagate(t->ch[1], t->lazy),\n          t->lazy_flg = false;\n  }\n\
    \  Node *merge(Node *a, Node *b) {\n    if (!a || !b) return a ? a : b;\n    if\
    \ (Compare()(a->key, b->key)) std::swap(a, b);\n    if constexpr (dual<M>::value)\
    \ eval(a);\n    return std::swap(a->ch[0], a->ch[1] = merge(b, a->ch[1])), a;\n\
    \  }\n\n public:\n  /* max heap */\n  SkewHeap() : root(nullptr) {}\n  void push(T\
    \ key) { root = merge(root, new Node{key}); }\n  T pop() {\n    T ret = root->key;\n\
    \    if constexpr (dual<M>::value) eval(root);\n    return root = merge(root->ch[0],\
    \ root->ch[1]), ret;\n  }\n  T top() { return root->key; }\n  bool empty() { return\
    \ !root; }\n  void apply(E v) {\n    static_assert(dual<M>::value, \"\\\"apply\\\
    \" is not available\\n\");\n    propagate(root, v);\n  }\n  SkewHeap &operator+=(SkewHeap\
    \ r) { return root = merge(root, r.root), *this; }\n  SkewHeap operator+(SkewHeap\
    \ r) { return SkewHeap(*this) += r; }\n};\n#line 5 \"test/aoj/ALDS1_9_C.SkewHeap.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  SkewHeap<int> S;\n  string op;\n  while (cin >> op && op != \"end\") {\n  \
    \  if (op[0] == 'i') {\n      int k;\n      cin >> k;\n      S.push(k);\n    }\
    \ else {\n      cout << S.pop() << endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SkewHeap.hpp\"\nusing\
    \ namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  SkewHeap<int> S;\n  string op;\n  while (cin >> op && op != \"end\") {\n  \
    \  if (op[0] == 'i') {\n      int k;\n      cin >> k;\n      S.push(k);\n    }\
    \ else {\n      cout << S.pop() << endl;\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/SkewHeap.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_9_C.SkewHeap.test.cpp
  requiredBy: []
  timestamp: '2022-11-18 21:48:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_9_C.SkewHeap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_9_C.SkewHeap.test.cpp
- /verify/test/aoj/ALDS1_9_C.SkewHeap.test.cpp.html
title: test/aoj/ALDS1_9_C.SkewHeap.test.cpp
---
