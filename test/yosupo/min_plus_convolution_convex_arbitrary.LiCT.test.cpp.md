---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/function_type.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Optimization/LiChaoTree.hpp
    title: Li-Chao-Tree
  - icon: ':question:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#include <iostream>\n#line 2 \"src/Optimization/LiChaoTree.hpp\"\n#include <limits>\n\
    #include <algorithm>\n#include <vector>\n#include <tuple>\n#line 2 \"src/Internal/function_type.hpp\"\
    \n#include <type_traits>\nnamespace function_template_internal {\ntemplate <class\
    \ C> struct is_function_object {\n template <class U, int dummy= (&U::operator(),\
    \ 0)> static std::true_type check(U *);\n static std::false_type check(...);\n\
    \ static C *m;\n static constexpr bool value= decltype(check(m))::value;\n};\n\
    template <class F, bool, bool> struct function_type_impl {\n using type= void;\n\
    };\ntemplate <class F> struct function_type_impl<F, true, false> {\n using type=\
    \ F *;\n};\ntemplate <class F> struct function_type_impl<F, false, true> {\n using\
    \ type= decltype(&F::operator());\n};\ntemplate <class F> using function_type_t=\
    \ typename function_type_impl<F, std::is_function_v<F>, is_function_object<F>::value>::type;\n\
    template <class... Args> struct result_type_impl {\n using type= void;\n};\ntemplate\
    \ <class R, class... Args> struct result_type_impl<R (*)(Args...)> {\n using type=\
    \ R;\n};\ntemplate <class C, class R, class... Args> struct result_type_impl<R\
    \ (C::*)(Args...)> {\n using type= R;\n};\ntemplate <class C, class R, class...\
    \ Args> struct result_type_impl<R (C::*)(Args...) const> {\n using type= R;\n\
    };\ntemplate <class F> using result_type_t= typename result_type_impl<function_type_t<F>>::type;\n\
    template <class... Args> struct argument_type_impl {\n using type= void;\n};\n\
    template <class R, class... Args> struct argument_type_impl<R (*)(Args...)> {\n\
    \ using type= std::tuple<Args...>;\n};\ntemplate <class C, class R, class... Args>\
    \ struct argument_type_impl<R (C::*)(Args...)> {\n using type= std::tuple<Args...>;\n\
    };\ntemplate <class C, class R, class... Args> struct argument_type_impl<R (C::*)(Args...)\
    \ const> {\n using type= std::tuple<Args...>;\n};\ntemplate <class F> using argument_type_t=\
    \ typename argument_type_impl<function_type_t<F>>::type;\ntemplate <class T> struct\
    \ other_than_first_argument_type_impl {\n using type= void;\n};\ntemplate <class\
    \ T, class... Args> struct other_than_first_argument_type_impl<std::tuple<T, Args...>>\
    \ {\n using type= std::tuple<Args...>;\n};\ntemplate <class T> using other_than_first_argument_type_t=\
    \ typename other_than_first_argument_type_impl<T>::type;\n}\nusing function_template_internal::result_type_t,\
    \ function_template_internal::argument_type_t, function_template_internal::other_than_first_argument_type_t;\n\
    #line 2 \"src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum { MAXIMIZE= -1, MINIMIZE=\
    \ 1 };\n#line 8 \"src/Optimization/LiChaoTree.hpp\"\ntemplate <class F> class\
    \ LiChaoTree {\n using A= argument_type_t<F>;\n static_assert(std::tuple_size_v<A>\
    \ > 1);\n using T= std::tuple_element_t<0, A>;\n using P= other_than_first_argument_type_t<A>;\n\
    \ using R= result_type_t<F>;\n F f;\n const T LB, UB;\n std::vector<P> ps;\n template\
    \ <MinMaxEnum sgn, bool persistent> class LiChaoTreeInterface {\n  LiChaoTree\
    \ *ins;\n  struct Node {\n   int id= -1;\n   Node *ch[2]= {nullptr, nullptr};\n\
    \  } *root;\n  static constexpr R ID= (sgn == MINIMIZE ? std::numeric_limits<R>::max()\
    \ : std::numeric_limits<R>::lowest()) / 2;\n  static inline bool cmp(R p, R n,\
    \ int pi, int ni) {\n   if constexpr (sgn == MINIMIZE) return p > n || (p == n\
    \ && pi > ni);\n   else return p < n || (p == n && pi > ni);\n  }\n  static inline\
    \ bool end(T l, T r) {\n   if constexpr (std::is_floating_point_v<T>) return r\
    \ - l < 1e-9;\n   else return r - l == 1;\n  }\n  static inline T ub(T r) {\n\
    \   if constexpr (std::is_floating_point_v<T>) return r;\n   else return r - 1;\n\
    \  }\n  inline R eval(int id, T x) const { return id < 0 ? ID : std::apply(ins->f,\
    \ std::tuple_cat(std::make_tuple(x), ins->ps[id])); }\n  inline void addl(Node\
    \ *&t, int id, T xl, T xr) {\n   if (!t) return t= new Node{id}, void();\n   T\
    \ xr_= ub(xr);\n   bool bl= cmp(eval(t->id, xl), eval(id, xl), t->id, id), br=\
    \ cmp(eval(t->id, xr_), eval(id, xr_), t->id, id);\n   if (!bl && !br) return;\n\
    \   if constexpr (persistent) t= new Node(*t);\n   if (bl && br) return t->id=\
    \ id, void();\n   T xm= (xl + xr) / 2;\n   if (cmp(eval(t->id, xm), eval(id, xm),\
    \ t->id, id)) std::swap(t->id, id), bl= !bl;\n   if (!end(xl, xr)) bl ? addl(t->ch[0],\
    \ id, xl, xm) : addl(t->ch[1], id, xm, xr);\n  }\n  inline void adds(Node *&t,\
    \ int id, T l, T r, T xl, T xr) {\n   if (r <= xl || xr <= l) return;\n   if (l\
    \ <= xl && xr <= r) return addl(t, id, xl, xr);\n   if (!t) t= new Node;\n   else\
    \ if constexpr (persistent) t= new Node(*t);\n   T xm= (xl + xr) / 2;\n   adds(t->ch[0],\
    \ id, l, r, xl, xm), adds(t->ch[1], id, l, r, xm, xr);\n  }\n  inline std::pair<R,\
    \ int> query(const Node *t, T x, T xl, T xr) const {\n   if (!t) return {ID, -1};\n\
    \   R a= eval(t->id, x);\n   if (end(xl, xr)) return {a, t->id};\n   T xm= (xl\
    \ + xr) / 2;\n   auto b= x < xm ? query(t->ch[0], x, xl, xm) : query(t->ch[1],\
    \ x, xm, xr);\n   return cmp(a, b.first, t->id, b.second) ? b : std::make_pair(a,\
    \ t->id);\n  }\n public:\n  LiChaoTreeInterface()= default;\n  LiChaoTreeInterface(LiChaoTree\
    \ *ins): ins(ins), root(nullptr) {}\n  template <class... Args> std::enable_if_t<sizeof...(Args)\
    \ == std::tuple_size_v<P>, void> insert(Args &&...args) {\n   static_assert(std::is_convertible_v<std::tuple<Args...>,\
    \ P>);\n   ins->ps.emplace_back(std::forward<Args>(args)...), addl(root, ins->ps.size()\
    \ - 1, ins->LB, ins->UB);\n  }\n  // [l,r)\n  template <class... Args> std::enable_if_t<sizeof...(Args)\
    \ == std::tuple_size_v<P>, void> insert(T l, T r, Args &&...args) {\n   static_assert(std::is_convertible_v<std::tuple<Args...>,\
    \ P>);\n   if (l >= r) return;\n   ins->ps.emplace_back(std::forward<Args>(args)...),\
    \ adds(root, ins->ps.size() - 1, l, r, ins->LB, ins->UB);\n  }\n  std::pair<R,\
    \ int> query(T x) const { return query(root, x, ins->LB, ins->UB); }\n  const\
    \ P &params(int id) const { return ins->ps[id]; }\n };\npublic:\n LiChaoTree(const\
    \ F &f, T LB= -2e9, T UB= 2e9): f(f), LB(LB), UB(UB) {}\n template <MinMaxEnum\
    \ sgn= MINIMIZE, bool persistent= false> LiChaoTreeInterface<sgn, persistent>\
    \ make_tree() { return this; }\n};\n#line 4 \"test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n long long a[N], b[M];\n for (int i= 0; i < N; ++i)\
    \ cin >> a[i];\n for (int j= 0; j < M; ++j) cin >> b[j];\n LiChaoTree lct([&](int\
    \ i, int j) { return a[i - j] + b[j]; }, 0, N + M - 1);\n auto tree= lct.make_tree<MINIMIZE>();\n\
    \ for (int j= 0; j < M; ++j) tree.insert(j, N + j, j);\n for (int i= 0; i < N\
    \ + M - 1; ++i) cout << tree.query(i).first << \" \\n\"[i == N + M - 2];\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#include <iostream>\n#include \"src/Optimization/LiChaoTree.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n\
    \ cin >> N >> M;\n long long a[N], b[M];\n for (int i= 0; i < N; ++i) cin >> a[i];\n\
    \ for (int j= 0; j < M; ++j) cin >> b[j];\n LiChaoTree lct([&](int i, int j) {\
    \ return a[i - j] + b[j]; }, 0, N + M - 1);\n auto tree= lct.make_tree<MINIMIZE>();\n\
    \ for (int j= 0; j < M; ++j) tree.insert(j, N + j, j);\n for (int i= 0; i < N\
    \ + M - 1; ++i) cout << tree.query(i).first << \" \\n\"[i == N + M - 2];\n return\
    \ 0;\n}"
  dependsOn:
  - src/Optimization/LiChaoTree.hpp
  - src/Internal/function_type.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: true
  path: test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
  requiredBy: []
  timestamp: '2023-10-17 15:04:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp.html
title: test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
---
