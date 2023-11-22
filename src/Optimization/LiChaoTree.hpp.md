---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/function_traits.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u306B\u95A2\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.LiCT.test.cpp
    title: test/aoj/2603.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.LiCT.test.cpp
    title: test/aoj/2725.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3086.LiCT.test.cpp
    title: test/aoj/3086.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.LiCT.test.cpp
    title: test/yosupo/line_add_get_min.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
    title: test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1297.LiCT.1.test.cpp
    title: test/yukicoder/1297.LiCT.1.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1297.LiCT.2.test.cpp
    title: test/yukicoder/1297.LiCT.2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1867.test.cpp
    title: test/yukicoder/1867.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2332.RH.test.cpp
    title: test/yukicoder/2332.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2332.zalgo.test.cpp
    title: test/yukicoder/2332.zalgo.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2458.LiCT.test.cpp
    title: test/yukicoder/2458.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/409.LiCT.test.cpp
    title: test/yukicoder/409.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/703.LiCT.test.cpp
    title: test/yukicoder/703.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/704.LiCT.test.cpp
    title: test/yukicoder/704.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/705.LiCT.test.cpp
    title: test/yukicoder/705.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/913.LiCT.test.cpp
    title: test/yukicoder/913.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/952.LiCT.test.cpp
    title: test/yukicoder/952.LiCT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/LiChaoTree.hpp\"\n#include <limits>\n#include\
    \ <algorithm>\n#include <vector>\n#include <tuple>\n#line 2 \"src/Internal/function_traits.hpp\"\
    \n#include <type_traits>\n// clang-format off\nnamespace function_template_internal{\n\
    template<class C>struct is_function_object{\n template<class U,int dummy=(&U::operator(),0)>\
    \ static std::true_type check(U *);\n static std::false_type check(...);\n static\
    \ C *m;\n static constexpr bool value= decltype(check(m))::value;\n};\ntemplate<class\
    \ F,bool,bool>struct function_type_impl{using type= void;};\ntemplate<class F>struct\
    \ function_type_impl<F,true,false>{using type= F *;};\ntemplate<class F>struct\
    \ function_type_impl<F,false,true>{using type= decltype(&F::operator());};\ntemplate<class\
    \ F> using function_type_t= typename function_type_impl<F,std::is_function_v<F>,is_function_object<F>::value>::type;\n\
    template<class... Args>struct result_type_impl{using type= void;};\ntemplate<class\
    \ R,class... Args>struct result_type_impl<R(*)(Args...)>{using type= R;};\ntemplate<class\
    \ C,class R,class... Args>struct result_type_impl<R(C::*)(Args...)>{using type=\
    \ R;};\ntemplate<class C,class R,class... Args>struct result_type_impl<R(C::*)(Args...)const>{using\
    \ type= R;};\ntemplate<class F> using result_type_t= typename result_type_impl<function_type_t<F>>::type;\n\
    template<class... Args>struct argument_type_impl{using type= void;};\ntemplate<class\
    \ R,class... Args>struct argument_type_impl<R(*)(Args...)>{using type= std::tuple<Args...>;};\n\
    template<class C,class R,class... Args>struct argument_type_impl<R(C::*)(Args...)>{using\
    \ type= std::tuple<Args...>;};\ntemplate<class C,class R,class... Args>struct\
    \ argument_type_impl<R(C::*)(Args...)const>{using type= std::tuple<Args...>;};\n\
    template<class F> using argument_type_t= typename argument_type_impl<function_type_t<F>>::type;\n\
    }\nusing function_template_internal::result_type_t,function_template_internal::argument_type_t;\n\
    // clang-format on\n#line 2 \"src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum\
    \ { MAXIMIZE= -1, MINIMIZE= 1 };\n#line 8 \"src/Optimization/LiChaoTree.hpp\"\n\
    template <class F, class T> class LiChaoTree {};\ntemplate <class F, class T,\
    \ class... Prms> class LiChaoTree<F, std::tuple<T, Prms...>> {\n using R= result_type_t<F>;\n\
    \ F f;\n const T LB, UB;\n std::vector<std::tuple<Prms...>> ps;\n template <MinMaxEnum\
    \ sgn, bool persistent> class LiChaoTreeInterface {\n  LiChaoTree *ins;\n  struct\
    \ Node {\n   int id= -1;\n   Node *ch[2]= {nullptr, nullptr};\n  } *root;\n  static\
    \ constexpr R ID= (sgn == MINIMIZE ? std::numeric_limits<R>::max() : std::numeric_limits<R>::lowest())\
    \ / 2;\n  static inline bool cmp(R p, R n, int pi, int ni) {\n   if constexpr\
    \ (sgn == MINIMIZE) return p > n || (p == n && pi > ni);\n   else return p < n\
    \ || (p == n && pi > ni);\n  }\n  static inline bool end(T l, T r) {\n   if constexpr\
    \ (std::is_floating_point_v<T>) return r - l < 1e-9;\n   else return r - l ==\
    \ 1;\n  }\n  static inline T ub(T r) {\n   if constexpr (std::is_floating_point_v<T>)\
    \ return r;\n   else return r - 1;\n  }\n  inline R eval(int id, T x) const {\
    \ return id < 0 ? ID : std::apply(ins->f, std::tuple_cat(std::make_tuple(x), ins->ps[id]));\
    \ }\n  inline void addl(Node *&t, int id, T xl, T xr) {\n   if (!t) return t=\
    \ new Node{id}, void();\n   T xr_= ub(xr);\n   bool bl= cmp(eval(t->id, xl), eval(id,\
    \ xl), t->id, id), br= cmp(eval(t->id, xr_), eval(id, xr_), t->id, id);\n   if\
    \ (!bl && !br) return;\n   if constexpr (persistent) t= new Node(*t);\n   if (bl\
    \ && br) return t->id= id, void();\n   T xm= (xl + xr) / 2;\n   if (cmp(eval(t->id,\
    \ xm), eval(id, xm), t->id, id)) std::swap(t->id, id), bl= !bl;\n   if (!end(xl,\
    \ xr)) bl ? addl(t->ch[0], id, xl, xm) : addl(t->ch[1], id, xm, xr);\n  }\n  inline\
    \ void adds(Node *&t, int id, T l, T r, T xl, T xr) {\n   if (r <= xl || xr <=\
    \ l) return;\n   if (l <= xl && xr <= r) return addl(t, id, xl, xr);\n   if (!t)\
    \ t= new Node;\n   else if constexpr (persistent) t= new Node(*t);\n   T xm= (xl\
    \ + xr) / 2;\n   adds(t->ch[0], id, l, r, xl, xm), adds(t->ch[1], id, l, r, xm,\
    \ xr);\n  }\n  inline std::pair<R, int> query(const Node *t, T x, T xl, T xr)\
    \ const {\n   if (!t) return {ID, -1};\n   R a= eval(t->id, x);\n   if (end(xl,\
    \ xr)) return {a, t->id};\n   T xm= (xl + xr) / 2;\n   auto b= x < xm ? query(t->ch[0],\
    \ x, xl, xm) : query(t->ch[1], x, xm, xr);\n   return cmp(a, b.first, t->id, b.second)\
    \ ? b : std::make_pair(a, t->id);\n  }\n public:\n  LiChaoTreeInterface()= default;\n\
    \  LiChaoTreeInterface(LiChaoTree *ins): ins(ins), root(nullptr) {}\n  void insert(const\
    \ Prms &...args) { ins->ps.emplace_back(args...), addl(root, ins->ps.size() -\
    \ 1, ins->LB, ins->UB); }\n  // [l,r)\n  void insert(T l, T r, const Prms &...args)\
    \ {\n   if (l < r) ins->ps.emplace_back(args...), adds(root, ins->ps.size() -\
    \ 1, l, r, ins->LB, ins->UB);\n  }\n  std::pair<R, int> query(T x) const { return\
    \ query(root, x, ins->LB, ins->UB); }\n  const std::tuple<Prms...> &params(int\
    \ id) const { return ins->ps[id]; }\n };\npublic:\n LiChaoTree(const F &f, T LB=\
    \ -2e9, T UB= 2e9): f(f), LB(LB), UB(UB) {}\n template <MinMaxEnum sgn= MINIMIZE,\
    \ bool persistent= false> LiChaoTreeInterface<sgn, persistent> make_tree() { return\
    \ this; }\n};\ntemplate <class F, class T, class U> LiChaoTree(F, T, U) -> LiChaoTree<F,\
    \ argument_type_t<F>>;\ntemplate <class F, class T> LiChaoTree(F, T) -> LiChaoTree<F,\
    \ argument_type_t<F>>;\ntemplate <class F> LiChaoTree(F) -> LiChaoTree<F, argument_type_t<F>>;\n"
  code: "#pragma once\n#include <limits>\n#include <algorithm>\n#include <vector>\n\
    #include <tuple>\n#include \"src/Internal/function_traits.hpp\"\n#include \"src/Optimization/MinMaxEnum.hpp\"\
    \ntemplate <class F, class T> class LiChaoTree {};\ntemplate <class F, class T,\
    \ class... Prms> class LiChaoTree<F, std::tuple<T, Prms...>> {\n using R= result_type_t<F>;\n\
    \ F f;\n const T LB, UB;\n std::vector<std::tuple<Prms...>> ps;\n template <MinMaxEnum\
    \ sgn, bool persistent> class LiChaoTreeInterface {\n  LiChaoTree *ins;\n  struct\
    \ Node {\n   int id= -1;\n   Node *ch[2]= {nullptr, nullptr};\n  } *root;\n  static\
    \ constexpr R ID= (sgn == MINIMIZE ? std::numeric_limits<R>::max() : std::numeric_limits<R>::lowest())\
    \ / 2;\n  static inline bool cmp(R p, R n, int pi, int ni) {\n   if constexpr\
    \ (sgn == MINIMIZE) return p > n || (p == n && pi > ni);\n   else return p < n\
    \ || (p == n && pi > ni);\n  }\n  static inline bool end(T l, T r) {\n   if constexpr\
    \ (std::is_floating_point_v<T>) return r - l < 1e-9;\n   else return r - l ==\
    \ 1;\n  }\n  static inline T ub(T r) {\n   if constexpr (std::is_floating_point_v<T>)\
    \ return r;\n   else return r - 1;\n  }\n  inline R eval(int id, T x) const {\
    \ return id < 0 ? ID : std::apply(ins->f, std::tuple_cat(std::make_tuple(x), ins->ps[id]));\
    \ }\n  inline void addl(Node *&t, int id, T xl, T xr) {\n   if (!t) return t=\
    \ new Node{id}, void();\n   T xr_= ub(xr);\n   bool bl= cmp(eval(t->id, xl), eval(id,\
    \ xl), t->id, id), br= cmp(eval(t->id, xr_), eval(id, xr_), t->id, id);\n   if\
    \ (!bl && !br) return;\n   if constexpr (persistent) t= new Node(*t);\n   if (bl\
    \ && br) return t->id= id, void();\n   T xm= (xl + xr) / 2;\n   if (cmp(eval(t->id,\
    \ xm), eval(id, xm), t->id, id)) std::swap(t->id, id), bl= !bl;\n   if (!end(xl,\
    \ xr)) bl ? addl(t->ch[0], id, xl, xm) : addl(t->ch[1], id, xm, xr);\n  }\n  inline\
    \ void adds(Node *&t, int id, T l, T r, T xl, T xr) {\n   if (r <= xl || xr <=\
    \ l) return;\n   if (l <= xl && xr <= r) return addl(t, id, xl, xr);\n   if (!t)\
    \ t= new Node;\n   else if constexpr (persistent) t= new Node(*t);\n   T xm= (xl\
    \ + xr) / 2;\n   adds(t->ch[0], id, l, r, xl, xm), adds(t->ch[1], id, l, r, xm,\
    \ xr);\n  }\n  inline std::pair<R, int> query(const Node *t, T x, T xl, T xr)\
    \ const {\n   if (!t) return {ID, -1};\n   R a= eval(t->id, x);\n   if (end(xl,\
    \ xr)) return {a, t->id};\n   T xm= (xl + xr) / 2;\n   auto b= x < xm ? query(t->ch[0],\
    \ x, xl, xm) : query(t->ch[1], x, xm, xr);\n   return cmp(a, b.first, t->id, b.second)\
    \ ? b : std::make_pair(a, t->id);\n  }\n public:\n  LiChaoTreeInterface()= default;\n\
    \  LiChaoTreeInterface(LiChaoTree *ins): ins(ins), root(nullptr) {}\n  void insert(const\
    \ Prms &...args) { ins->ps.emplace_back(args...), addl(root, ins->ps.size() -\
    \ 1, ins->LB, ins->UB); }\n  // [l,r)\n  void insert(T l, T r, const Prms &...args)\
    \ {\n   if (l < r) ins->ps.emplace_back(args...), adds(root, ins->ps.size() -\
    \ 1, l, r, ins->LB, ins->UB);\n  }\n  std::pair<R, int> query(T x) const { return\
    \ query(root, x, ins->LB, ins->UB); }\n  const std::tuple<Prms...> &params(int\
    \ id) const { return ins->ps[id]; }\n };\npublic:\n LiChaoTree(const F &f, T LB=\
    \ -2e9, T UB= 2e9): f(f), LB(LB), UB(UB) {}\n template <MinMaxEnum sgn= MINIMIZE,\
    \ bool persistent= false> LiChaoTreeInterface<sgn, persistent> make_tree() { return\
    \ this; }\n};\ntemplate <class F, class T, class U> LiChaoTree(F, T, U) -> LiChaoTree<F,\
    \ argument_type_t<F>>;\ntemplate <class F, class T> LiChaoTree(F, T) -> LiChaoTree<F,\
    \ argument_type_t<F>>;\ntemplate <class F> LiChaoTree(F) -> LiChaoTree<F, argument_type_t<F>>;"
  dependsOn:
  - src/Internal/function_traits.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: false
  path: src/Optimization/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2023-10-31 18:36:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/line_add_get_min.LiCT.test.cpp
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
  - test/yukicoder/705.LiCT.test.cpp
  - test/yukicoder/952.LiCT.test.cpp
  - test/yukicoder/1867.test.cpp
  - test/yukicoder/703.LiCT.test.cpp
  - test/yukicoder/2332.RH.test.cpp
  - test/yukicoder/2332.zalgo.test.cpp
  - test/yukicoder/704.LiCT.test.cpp
  - test/yukicoder/913.LiCT.test.cpp
  - test/yukicoder/1297.LiCT.1.test.cpp
  - test/yukicoder/2458.LiCT.test.cpp
  - test/yukicoder/1297.LiCT.2.test.cpp
  - test/yukicoder/409.LiCT.test.cpp
  - test/aoj/3086.LiCT.test.cpp
  - test/aoj/2725.LiCT.test.cpp
  - test/aoj/2603.LiCT.test.cpp
documentation_of: src/Optimization/LiChaoTree.hpp
layout: document
title: Li-Chao-Tree
---
( 例えば 一次関数などの ) 高々一点で交わる $x$ の関数群 $f_i(x) = f(x; \boldsymbol{p}^{(i)})= f(x;p^{(i)}_0,\dots,p^{(i)}_n)$ を扱うデータ構造. \
浮動小数点数もいけるはず. \
2点以上で交わる可能性がある関数群を挿入した時の動作は未定義.\
クラステンプレートは推論させる.

## 使用例
宣言
```c++
auto f = [](long long x, int a, int b){return a * x + b;}; // ax+b
LiChaoTree lct(f);
auto tree = lct.make_tree<MINIMIZE>();
```
クエリ
```c++
tree.insert(2, 3); // 2x+3
tree.insert(0, 2, 1, 1); // x+1 (0<= x < 2)
auto [val1, id1] = tree.query(1);
cout << val1 << " "<< id1 << endl; // 2 1
auto [val2, id2] = tree.query(-1);
cout << val2 << " "<< id2 << endl; // 1 0
```

## `LiChaoTree` クラス
まず初期化のために触るクラス. \
内部で関数やパラメータを格納したりの役割がある.

|メンバ関数|概要|
|---|---|
|`LiChaoTree(f, LB, UB)`|コンストラクタ. <br> $x$ の関数 $f(x;p_0,\dots,p_n)$ を渡す. <br> クエリとして考える $x$ の半開区間 $\lbrack \mathrm{LB}, \mathrm{UB})$ を渡す. ( デフォルトは `LB=-2e9`, `UB=2e9`)|
|`make_tree<sgn, persistent>()`| `LiChaoTreeInterface` クラスのオブジェクトを返す. <br> 何も関数が挿入されていない空のデータ構造を返す. <br> template 第一引数で最小か最大を指定する. (デフォルトは最小) <br> template 第二引数が true なら永続化. (デフォルトはfalse)|

## `LiChaoTreeInterface` クラス

メインで触ることになるもの.

|メンバ関数|概要|計算量|
|---|---|---|
|1. `insert(p_0,...,p_n)` <br> 2. `insert(l,r,p_0,...,p_n)`|1. 関数 $f(x;p_0,\dots,p_n)$ を挿入. <br> 2. 半開区間制約付きの関数 $f(x;p_0,\dots,p_n) \hspace{1mm}x\in\lbrack l,r) $ を挿入. | 1. $\mathcal{O}(\log n)$ <br> 2.$\mathcal{O}((\log n)^2)$　|
|`query(x)` | { $x$ における最小値(最大値), それを達成する関数の番号 } を返す. <br>存在しない場合 { 十分大きな(小さな)値, -1 } を返す. |$\mathcal{O}(\log n)$ | 

## 問題例

[Kyoto University Programming Contest 2019 L - タケノコ](https://atcoder.jp/contests/kupc2019/tasks/kupc2019_l) (永続) \
[AtCoder Regular Contest 051 D - 長方形](https://atcoder.jp/contests/arc051/tasks/arc051_d) (doubleでac) \
[Yandex Contest Алгоритм 2022 K. Stepwise subsequence ](https://contest.yandex.com/contest/42710/problems/K) (有理数クラス, doubleでac) \
[COLOCON -Colopl programming contest 2018- Final C - スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c) \
[技術室奥プログラミングコンテスト#2 F - NPCの家 (NPC's House)](https://atcoder.jp/contests/tkppc2/tasks/tkppc2016_f) 