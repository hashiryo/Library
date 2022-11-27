---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2614.rollinghash.test.cpp
    title: test/aoj/2614.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.rollinghash.test.cpp
    title: test/aoj/2711.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rollinghash.test.cpp
    title: test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - icon: ':x:'
    path: test/yosupo/z_algorithm.rollinghash.test.cpp
    title: test/yosupo/z_algorithm.rollinghash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\\
      cdots\\times K_n$)"
    links: []
  bundledCode: "#line 2 \"src/Math/CartesianProduct.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\\
    cdots\\times K_n$)\n * @category \u6570\u5B66\n * \u30ED\u30EA\u30CF\u306E\u305F\
    \u3081\u306B\u4F5C\u3063\u305F\n */\n\n// BEGIN CUT HERE\n\ntemplate <class...\
    \ Ks>\nstruct CartesianProduct : std::tuple<Ks...> {\n  static constexpr int N\
    \ = sizeof...(Ks);\n  using Self = CartesianProduct;\n  using std::tuple<Ks...>::tuple;\n\
    \  template <class T>\n  CartesianProduct(const T &v) {\n    fill(v, std::make_index_sequence<N>());\n\
    \  }\n  template <class T, std::size_t... I>\n  std::array<int, N> fill(const\
    \ T &v, std::index_sequence<I...>) {\n    return {{(void(std::get<I>(*this) =\
    \ v), 0)...}};\n  }\n#define HELPER(name, op)                                \
    \               \\\n  template <std::size_t... I>                            \
    \              \\\n  std::array<int, N> name(const Self &y, std::index_sequence<I...>)\
    \ {  \\\n    return {{(void(std::get<I>(*this) op## = std::get<I>(y)), 0)...}};\
    \ \\\n  }                                                                    \\\
    \n  Self &operator op##=(const Self &r) {                                \\\n\
    \    return name(r, std::make_index_sequence<N>()), *this;              \\\n \
    \ }\n  HELPER(add_assign, +)\n  HELPER(dif_assign, -)\n  HELPER(mul_assign, *)\n\
    \  HELPER(div_assign, /)\n#undef HELPER\n  Self operator+(const Self &r) const\
    \ { return Self(*this) += r; }\n  Self operator-(const Self &r) const { return\
    \ Self(*this) -= r; }\n  Self operator*(const Self &r) const { return Self(*this)\
    \ *= r; }\n  Self operator/(const Self &r) const { return Self(*this) /= r; }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u4EE3\u6570\u7CFB\
    \u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\cdots\\times K_n$)\n * @category \u6570\
    \u5B66\n * \u30ED\u30EA\u30CF\u306E\u305F\u3081\u306B\u4F5C\u3063\u305F\n */\n\
    \n// BEGIN CUT HERE\n\ntemplate <class... Ks>\nstruct CartesianProduct : std::tuple<Ks...>\
    \ {\n  static constexpr int N = sizeof...(Ks);\n  using Self = CartesianProduct;\n\
    \  using std::tuple<Ks...>::tuple;\n  template <class T>\n  CartesianProduct(const\
    \ T &v) {\n    fill(v, std::make_index_sequence<N>());\n  }\n  template <class\
    \ T, std::size_t... I>\n  std::array<int, N> fill(const T &v, std::index_sequence<I...>)\
    \ {\n    return {{(void(std::get<I>(*this) = v), 0)...}};\n  }\n#define HELPER(name,\
    \ op)                                               \\\n  template <std::size_t...\
    \ I>                                          \\\n  std::array<int, N> name(const\
    \ Self &y, std::index_sequence<I...>) {  \\\n    return {{(void(std::get<I>(*this)\
    \ op## = std::get<I>(y)), 0)...}}; \\\n  }                                   \
    \                                 \\\n  Self &operator op##=(const Self &r) {\
    \                                \\\n    return name(r, std::make_index_sequence<N>()),\
    \ *this;              \\\n  }\n  HELPER(add_assign, +)\n  HELPER(dif_assign, -)\n\
    \  HELPER(mul_assign, *)\n  HELPER(div_assign, /)\n#undef HELPER\n  Self operator+(const\
    \ Self &r) const { return Self(*this) += r; }\n  Self operator-(const Self &r)\
    \ const { return Self(*this) -= r; }\n  Self operator*(const Self &r) const {\
    \ return Self(*this) *= r; }\n  Self operator/(const Self &r) const { return Self(*this)\
    \ /= r; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/CartesianProduct.hpp
  requiredBy: []
  timestamp: '2022-10-29 19:15:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/z_algorithm.rollinghash.test.cpp
  - test/aoj/2711.rollinghash.test.cpp
  - test/aoj/2614.rollinghash.test.cpp
  - test/aoj/ALDS1_14_B.rollinghash.test.cpp
documentation_of: src/Math/CartesianProduct.hpp
layout: document
redirect_from:
- /library/src/Math/CartesianProduct.hpp
- /library/src/Math/CartesianProduct.hpp.html
title: "\u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\cdots\\times\
  \ K_n$)"
---
