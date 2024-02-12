---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/Math/sparse_fps.hpp
    title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_d.test.cpp
    title: test/atcoder/abc179_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc222_h.sparse_FPS.test.cpp
    title: test/atcoder/abc222_h.sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc236_ex.test.cpp
    title: test/atcoder/abc236_ex.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc276_g.sparse_FPS.test.cpp
    title: test/atcoder/abc276_g.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/binomial_coefficient_prime_mod.test.cpp
    title: test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_sparse_FPS.test.cpp
    title: test/yosupo/exp_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_sparse_FPS.test.cpp
    title: test/yosupo/inv_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_sparse_FPS.test.cpp
    title: test/yosupo/log_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_sparse_FPS.test.cpp
    title: test/yosupo/pow_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_sparse_FPS.test.cpp
    title: test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.sparse_FPS.test.cpp
    title: test/yukicoder/1080.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/125.multiple_mobius.test.cpp
    title: test/yukicoder/125.multiple_mobius.test.cpp
  - icon: ':x:'
    path: test/yukicoder/125.phi.test.cpp
    title: test/yukicoder/125.phi.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1939.test.cpp
    title: test/yukicoder/1939.test.cpp
  - icon: ':x:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/FactorialPrecalculation.hpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"src/Internal/modint_traits.hpp\"\n#include <type_traits>\n\
    namespace math_internal {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class\
    \ mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\n\
    template <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/FactorialPrecalculation.hpp\"\ntemplate <class mod_t>\
    \ class FactorialPrecalculation {\n static_assert(is_modint_v<mod_t>);\n static\
    \ inline std::vector<mod_t> iv, fct, fiv;\npublic:\n static void reset() { iv.clear(),\
    \ fct.clear(), fiv.clear(); }\n static inline mod_t inv(int n) {\n  assert(0 <\
    \ n);\n  if (int k= iv.size(); k <= n) {\n   if (iv.resize(n + 1); !k) iv[1]=\
    \ 1, k= 2;\n   for (int mod= mod_t::mod(), q; k <= n; ++k) q= (mod + k - 1) /\
    \ k, iv[k]= iv[k * q - mod] * q;\n  }\n  return iv[n];\n }\n static inline mod_t\
    \ fact(int n) {\n  assert(0 <= n);\n  if (int k= fct.size(); k <= n) {\n   if\
    \ (fct.resize(n + 1); !k) fct[0]= 1, k= 1;\n   for (; k <= n; ++k) fct[k]= fct[k\
    \ - 1] * k;\n  }\n  return fct[n];\n }\n static inline mod_t finv(int n) {\n \
    \ assert(0 <= n);\n  if (int k= fiv.size(); k <= n) {\n   if (fiv.resize(n + 1);\
    \ !k) fiv[0]= 1, k= 1;\n   for (; k <= n; ++k) fiv[k]= fiv[k - 1] * inv(k);\n\
    \  }\n  return fiv[n];\n }\n static inline mod_t nPr(int n, int r) { return r\
    \ < 0 || n < r ? mod_t(0) : fact(n) * finv(n - r); }\n // [x^r] (1 + x)^n\n static\
    \ inline mod_t nCr(int n, int r) { return r < 0 || n < r ? mod_t(0) : fact(n)\
    \ * finv(n - r) * finv(r); }\n // [x^r] (1 - x)^{-n}\n static inline mod_t nHr(int\
    \ n, int r) { return !r ? mod_t(1) : nCr(n + r - 1, r); }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"src/Internal/modint_traits.hpp\"\
    \ntemplate <class mod_t> class FactorialPrecalculation {\n static_assert(is_modint_v<mod_t>);\n\
    \ static inline std::vector<mod_t> iv, fct, fiv;\npublic:\n static void reset()\
    \ { iv.clear(), fct.clear(), fiv.clear(); }\n static inline mod_t inv(int n) {\n\
    \  assert(0 < n);\n  if (int k= iv.size(); k <= n) {\n   if (iv.resize(n + 1);\
    \ !k) iv[1]= 1, k= 2;\n   for (int mod= mod_t::mod(), q; k <= n; ++k) q= (mod\
    \ + k - 1) / k, iv[k]= iv[k * q - mod] * q;\n  }\n  return iv[n];\n }\n static\
    \ inline mod_t fact(int n) {\n  assert(0 <= n);\n  if (int k= fct.size(); k <=\
    \ n) {\n   if (fct.resize(n + 1); !k) fct[0]= 1, k= 1;\n   for (; k <= n; ++k)\
    \ fct[k]= fct[k - 1] * k;\n  }\n  return fct[n];\n }\n static inline mod_t finv(int\
    \ n) {\n  assert(0 <= n);\n  if (int k= fiv.size(); k <= n) {\n   if (fiv.resize(n\
    \ + 1); !k) fiv[0]= 1, k= 1;\n   for (; k <= n; ++k) fiv[k]= fiv[k - 1] * inv(k);\n\
    \  }\n  return fiv[n];\n }\n static inline mod_t nPr(int n, int r) { return r\
    \ < 0 || n < r ? mod_t(0) : fact(n) * finv(n - r); }\n // [x^r] (1 + x)^n\n static\
    \ inline mod_t nCr(int n, int r) { return r < 0 || n < r ? mod_t(0) : fact(n)\
    \ * finv(n - r) * finv(r); }\n // [x^r] (1 - x)^{-n}\n static inline mod_t nHr(int\
    \ n, int r) { return !r ? mod_t(1) : nCr(n + r - 1, r); }\n};"
  dependsOn:
  - src/Internal/modint_traits.hpp
  isVerificationFile: false
  path: src/Math/FactorialPrecalculation.hpp
  requiredBy:
  - src/Math/sparse_fps.hpp
  timestamp: '2024-02-03 19:27:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/atcoder/abc179_d.test.cpp
  - test/atcoder/abc236_ex.test.cpp
  - test/atcoder/abc276_g.sparse_FPS.test.cpp
  - test/atcoder/abc222_h.sparse_FPS.test.cpp
  - test/yukicoder/1533.test.cpp
  - test/yukicoder/125.phi.test.cpp
  - test/yukicoder/1080.sparse_FPS.test.cpp
  - test/yukicoder/125.multiple_mobius.test.cpp
  - test/yukicoder/1939.test.cpp
  - test/yukicoder/310.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/yosupo/log_of_sparse_FPS.test.cpp
  - test/yosupo/pow_of_sparse_FPS.test.cpp
  - test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - test/yosupo/exp_of_sparse_FPS.test.cpp
  - test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - test/yosupo/inv_of_sparse_FPS.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: src/Math/FactorialPrecalculation.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570 \u4ED6 (\u968E\u4E57\u524D\u8A08\u7B97) ($\\mathbb{F}_p$)"
---
