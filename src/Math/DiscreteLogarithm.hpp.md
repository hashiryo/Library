---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/function_type.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc222_g.test.cpp
    title: test/atcoder/abc222_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':x:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/261.test.cpp
    title: test/yukicoder/261.test.cpp
  - icon: ':x:'
    path: test/yukicoder/950.test.cpp
    title: test/yukicoder/950.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/DiscreteLogarithm.hpp\"\n#include <cmath>\n#include\
    \ <vector>\n#line 2 \"src/Internal/function_type.hpp\"\n#include <type_traits>\n\
    template <class C> struct is_function_object {\n template <class U, int dummy=\
    \ (&U::operator(), 0)> static std::true_type check(U *);\n static std::false_type\
    \ check(...);\n static C *m;\n static constexpr bool value= decltype(check(m))::value;\n\
    };\ntemplate <class F, bool, bool> struct function_type_impl {\n using type= void;\n\
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
    #line 5 \"src/Math/DiscreteLogarithm.hpp\"\n// mapping : T \xD7 E -> T\n// op\
    \ : E \xD7 E -> E\n// hash : T -> int\n// s,t \u2208 T, x \u2208 E\n// return\
    \ min{ i : x^i(s) = t and i \u2208 [0,N) } or -1 (not found)\ntemplate <class\
    \ F, class G, class H> class DiscreteLogarithm {\n const F &mapping;\n const G\
    \ &op;\n const H &hash;\n const int64_t lim;\n using T= result_type_t<F>;\n using\
    \ E= result_type_t<G>;\npublic:\n DiscreteLogarithm(const F &mapping, const G\
    \ &op, const H &hash, int64_t lim= 1ll << 50): mapping(mapping), op(op), hash(hash),\
    \ lim(lim) { static_assert(std::is_convertible_v<std::invoke_result_t<H, T>, int>);\
    \ }\n int64_t operator()(const E &x, T s, const T &t, int64_t N= -1) const {\n\
    \  if (N < 0) N= lim;\n  const int m= 1 << std::__lg(int(std::sqrt(N) + 1)), mask=\
    \ m - 1;\n  std::vector<T> val(m), vs(m);\n  std::vector<int> os(m + 1), so(m);\n\
    \  T s1= t;\n  for (int i= 0; i < m; ++i) ++os[so[i]= hash(val[i]= s1= mapping(s1,\
    \ x)) & mask];\n  for (int i= 0; i < m; ++i) os[i + 1]+= os[i];\n  for (int i=\
    \ 0; i < m; ++i) vs[--os[so[i]]]= val[i];\n  E y= x;\n  for (int k= m; k>>= 1;)\
    \ y= op(y, y);\n  bool failed= false;\n  for (int64_t n= 0;; s= s1) {\n   for\
    \ (int a= hash(s1= mapping(s, y)) & mask, j= os[a]; j < os[a + 1]; ++j) {\n  \
    \  if (s1 == vs[j]) {\n     for (int i= 0;; s= mapping(s, x)) {\n      if (s ==\
    \ t) return n + i < N ? n + i : -1;\n      if (++i == m) break;\n     }\n    \
    \ if (failed) return -1;\n     failed= true;\n     break;\n    }\n   }\n   if\
    \ ((n+= m) >= N) break;\n  }\n  return -1;\n }\n};\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n#include \"src/Internal/function_type.hpp\"\
    \n// mapping : T \xD7 E -> T\n// op : E \xD7 E -> E\n// hash : T -> int\n// s,t\
    \ \u2208 T, x \u2208 E\n// return min{ i : x^i(s) = t and i \u2208 [0,N) } or\
    \ -1 (not found)\ntemplate <class F, class G, class H> class DiscreteLogarithm\
    \ {\n const F &mapping;\n const G &op;\n const H &hash;\n const int64_t lim;\n\
    \ using T= result_type_t<F>;\n using E= result_type_t<G>;\npublic:\n DiscreteLogarithm(const\
    \ F &mapping, const G &op, const H &hash, int64_t lim= 1ll << 50): mapping(mapping),\
    \ op(op), hash(hash), lim(lim) { static_assert(std::is_convertible_v<std::invoke_result_t<H,\
    \ T>, int>); }\n int64_t operator()(const E &x, T s, const T &t, int64_t N= -1)\
    \ const {\n  if (N < 0) N= lim;\n  const int m= 1 << std::__lg(int(std::sqrt(N)\
    \ + 1)), mask= m - 1;\n  std::vector<T> val(m), vs(m);\n  std::vector<int> os(m\
    \ + 1), so(m);\n  T s1= t;\n  for (int i= 0; i < m; ++i) ++os[so[i]= hash(val[i]=\
    \ s1= mapping(s1, x)) & mask];\n  for (int i= 0; i < m; ++i) os[i + 1]+= os[i];\n\
    \  for (int i= 0; i < m; ++i) vs[--os[so[i]]]= val[i];\n  E y= x;\n  for (int\
    \ k= m; k>>= 1;) y= op(y, y);\n  bool failed= false;\n  for (int64_t n= 0;; s=\
    \ s1) {\n   for (int a= hash(s1= mapping(s, y)) & mask, j= os[a]; j < os[a + 1];\
    \ ++j) {\n    if (s1 == vs[j]) {\n     for (int i= 0;; s= mapping(s, x)) {\n \
    \     if (s == t) return n + i < N ? n + i : -1;\n      if (++i == m) break;\n\
    \     }\n     if (failed) return -1;\n     failed= true;\n     break;\n    }\n\
    \   }\n   if ((n+= m) >= N) break;\n  }\n  return -1;\n }\n};"
  dependsOn:
  - src/Internal/function_type.hpp
  isVerificationFile: false
  path: src/Math/DiscreteLogarithm.hpp
  requiredBy: []
  timestamp: '2023-04-02 00:58:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc222_g.test.cpp
  - test/atcoder/abc270_g.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/261.test.cpp
  - test/yukicoder/950.test.cpp
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: src/Math/DiscreteLogarithm.hpp
layout: document
title: "\u96E2\u6563\u5BFE\u6570"
---

半群 $E$ が 集合 $T$ に(右)作用するとする. \
入力 : $x\in E$, $s,t\in T$, $n\in \mathbb{N}$ \
出力 : //[ \begin{cases} -1 & I = \varnothing, \\ \min I &\mathrm{otherwise}.\end{cases} //] ただし $I= \lbrace $ $ i \in \mathbb{N}:$ $0 \le i < n$ かつ $sx^i=t$  $\rbrace$ 

## メンバ関数

| 名前                                     | 概要                                                                                                                                                                                          | 計算量                                                                                                   |
| ---------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------- |
| `DiscreteLogarithm(mapping,op,hash,lim)` | コンストラクタ.  <br> `mapping` : $ T \times E \rightarrow T$ ( 作用 ) <br> `op` : $E \times E \rightarrow E$ ( 半群 $E$ の二項演算 ) <br> `hash` : $T \rightarrow \mathbb{N}$ ( int に変換 ) |                                                                                                          |
| `operator()(x,s,t,n)`                    | 離散対数を計算                                                                                                                                                                                | $\mathcal{O}(A\sqrt{n}+B\log{n})$ <br> 作用, 二項演算の計算量がそれぞれ $\mathcal{O}(A), \mathcal{O}(B)$ |

## 参考
[https://maspypy.com/モノイド作用に関する離散対数問題](https://maspypy.com/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89%E4%BD%9C%E7%94%A8%E3%81%AB%E9%96%A2%E3%81%99%E3%82%8B%E9%9B%A2%E6%95%A3%E5%AF%BE%E6%95%B0%E5%95%8F%E9%A1%8C)