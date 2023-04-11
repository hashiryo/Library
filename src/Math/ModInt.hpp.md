---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/FFT/BigInt.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':question:'
    path: src/FFT/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':x:'
    path: src/FFT/MultiVariateConvolution.hpp
    title: "\u591A\u5909\u6570\u7573\u307F\u8FBC\u307F"
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':x:'
    path: src/FFT/Polynomial.hpp
    title: "\u591A\u9805\u5F0F"
  - icon: ':x:'
    path: src/FFT/SubProductTree.hpp
    title: "\u8907\u6570\u306E\u5024\u4EE3\u5165\u3068\u591A\u9805\u5F0F\u88DC\u9593"
  - icon: ':question:'
    path: src/FFT/bostan_mori.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u7684\u6570\u5217\u306E\u7B2C$k$\u9805"
  - icon: ':question:'
    path: src/FFT/convolve.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  - icon: ':x:'
    path: src/FFT/extgcd.hpp
    title: "\u591A\u9805\u5F0F\u306E\u62E1\u5F35\u4E92\u9664\u6CD5"
  - icon: ':x:'
    path: src/FFT/fps_div.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 div"
  - icon: ':x:'
    path: src/FFT/fps_exp.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 exp"
  - icon: ':question:'
    path: src/FFT/fps_inv.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 inv"
  - icon: ':x:'
    path: src/FFT/fps_sqrt.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 sqrt"
  - icon: ':x:'
    path: src/FFT/polynomial_matrix_prod.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306E\u7DCF\u7A4D"
  - icon: ':x:'
    path: src/FFT/sample_points_shift.hpp
    title: "\u591A\u9805\u5F0F\u306E\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8"
  - icon: ':x:'
    path: src/FFT/sequences.hpp
    title: "\u6709\u540D\u306A\u6570\u5217(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u4F7F\
      \u7528)"
  - icon: ':question:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  - icon: ':question:'
    path: src/Math/ModInt_Runtime.hpp
    title: "ModInt(\u5B9F\u884C\u6642mod\u30BB\u30C3\u30C8)"
  - icon: ':question:'
    path: src/Math/sparse_fps.hpp
    title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2257.test.cpp
    title: test/aoj/2257.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.MinPoly.test.cpp
    title: test/aoj/2397.MinPoly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.test.cpp
    title: test/aoj/2397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530.test.cpp
    title: test/aoj/2530.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2614.rollinghash.test.cpp
    title: test/aoj/2614.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.rollinghash.test.cpp
    title: test/aoj/2711.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2863.test.cpp
    title: test/aoj/2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3072.test.cpp
    title: test/aoj/3072.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rollinghash.test.cpp
    title: test/aoj/ALDS1_14_B.rollinghash.test.cpp
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
    path: test/aoj/NTL_2_A.test.cpp
    title: test/aoj/NTL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_B.test.cpp
    title: test/aoj/NTL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_C.test.cpp
    title: test/aoj/NTL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_D.test.cpp
    title: test/aoj/NTL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_E.test.cpp
    title: test/aoj/NTL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_F.test.cpp
    title: test/aoj/NTL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc129_e.test.cpp
    title: test/atcoder/abc129_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc138_f.test.cpp
    title: test/atcoder/abc138_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc160_f.test.cpp
    title: test/atcoder/abc160_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_g.test.cpp
    title: test/atcoder/abc213_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_h.test.cpp
    title: test/atcoder/abc213_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc222_g.test.cpp
    title: test/atcoder/abc222_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc222_h.sparse_FPS.test.cpp
    title: test/atcoder/abc222_h.sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc230_h.test.cpp
    title: test/atcoder/abc230_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc234_g.test.cpp
    title: test/atcoder/abc234_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc235_f.test.cpp
    title: test/atcoder/abc235_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256_f.DynSeg.test.cpp
    title: test/atcoder/abc256_f.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256_f.SegDual.test.cpp
    title: test/atcoder/abc256_f.SegDual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256_f.WBT.test.cpp
    title: test/atcoder/abc256_f.WBT.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc276_g.sparse_FPS.test.cpp
    title: test/atcoder/abc276_g.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/atcoder/agc038_c.numth.test.cpp
    title: test/atcoder/agc038_c.numth.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc105_f.test.cpp
    title: test/atcoder/arc105_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc115_e.test.cpp
    title: test/atcoder/arc115_e.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc116_c.dujiao.test.cpp
    title: test/atcoder/arc116_c.dujiao.test.cpp
  - icon: ':x:'
    path: test/yosupo/bernoulli.test.cpp
    title: test/yosupo/bernoulli.test.cpp
  - icon: ':x:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/comp_of_FPS.test.cpp
    title: test/yosupo/comp_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/convolution1000000007.test.cpp
    title: test/yosupo/convolution1000000007.test.cpp
  - icon: ':x:'
    path: test/yosupo/convolution_large.test.cpp
    title: test/yosupo/convolution_large.test.cpp
  - icon: ':x:'
    path: test/yosupo/convolution_mod_2_64.test.cpp
    title: test/yosupo/convolution_mod_2_64.test.cpp
  - icon: ':x:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/division_of_Poly.test.cpp
    title: test/yosupo/division_of_Poly.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_FPS.FPS.test.cpp
    title: test/yosupo/exp_of_FPS.FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_FPS.test.cpp
    title: test/yosupo/exp_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_sparse_FPS.test.cpp
    title: test/yosupo/exp_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/find_linear_recurrence.test.cpp
    title: test/yosupo/find_linear_recurrence.test.cpp
  - icon: ':x:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_FPS.FPS.test.cpp
    title: test/yosupo/inv_of_FPS.FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_FPS.test.cpp
    title: test/yosupo/inv_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_Poly.test.cpp
    title: test/yosupo/inv_of_Poly.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_sparse_FPS.test.cpp
    title: test/yosupo/inv_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/inverse_matrix.test.cpp
    title: test/yosupo/inverse_matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/linear_equations.test.cpp
    title: test/yosupo/linear_equations.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_FPS.FPS.test.cpp
    title: test/yosupo/log_of_FPS.FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_FPS.test.cpp
    title: test/yosupo/log_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_sparse_FPS.test.cpp
    title: test/yosupo/log_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  - icon: ':x:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/yosupo/multivariate_convolution.test.cpp
    title: test/yosupo/multivariate_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/partition.MSET.test.cpp
    title: test/yosupo/partition.MSET.test.cpp
  - icon: ':x:'
    path: test/yosupo/partition.test.cpp
    title: test/yosupo/partition.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_set_range_composite.SegTree.test.cpp
    title: test/yosupo/point_set_range_composite.SegTree.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_FPS.FPS.test.cpp
    title: test/yosupo/pow_of_FPS.FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_FPS.test.cpp
    title: test/yosupo/pow_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_sparse_FPS.test.cpp
    title: test/yosupo/pow_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
    title: test/yosupo/range_affine_range_sum.DynSeg.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
    title: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.WBT.test.cpp
    title: test/yosupo/range_affine_range_sum.WBT.test.cpp
  - icon: ':x:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':x:'
    path: test/yosupo/sharp_p_subset_sum.PSET.test.cpp
    title: test/yosupo/sharp_p_subset_sum.PSET.test.cpp
  - icon: ':x:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/shift_of_FPS.test.cpp
    title: test/yosupo/shift_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_FPS.test.cpp
    title: test/yosupo/sqrt_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_sparse_FPS.test.cpp
    title: test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_1.test.cpp
    title: test/yosupo/stirling_1.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_2.test.cpp
    title: test/yosupo/stirling_2.test.cpp
  - icon: ':x:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.test.cpp
    title: test/yosupo/sum_of_totient_function.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_set_path_composite.HLD.test.cpp
    title: test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - icon: ':x:'
    path: test/yosupo/z_algorithm.rollinghash.test.cpp
    title: test/yosupo/z_algorithm.rollinghash.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1019.test.cpp
    title: test/yukicoder/1019.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1075.test.cpp
    title: test/yukicoder/1075.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.sparse_FPS.test.cpp
    title: test/yukicoder/1080.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.test.cpp
    title: test/yukicoder/1080.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1124.test.cpp
    title: test/yukicoder/1124.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1145.test.cpp
    title: test/yukicoder/1145.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1333.test.cpp
    title: test/yukicoder/1333.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test/yukicoder/137.div_at.test.cpp
    title: test/yukicoder/137.div_at.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.MinPoly.test.cpp
    title: test/yukicoder/1750.MinPoly.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1939.test.cpp
    title: test/yukicoder/1939.test.cpp
  - icon: ':x:'
    path: test/yukicoder/215.Poly.test.cpp
    title: test/yukicoder/215.Poly.test.cpp
  - icon: ':x:'
    path: test/yukicoder/215.test.cpp
    title: test/yukicoder/215.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.HLD.test.cpp
    title: test/yukicoder/235.HLD.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.LCT.test.cpp
    title: test/yukicoder/235.LCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  - icon: ':x:'
    path: test/yukicoder/315.test.cpp
    title: test/yukicoder/315.test.cpp
  - icon: ':x:'
    path: test/yukicoder/42.test.cpp
    title: test/yukicoder/42.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502.test.cpp
    title: test/yukicoder/502.test.cpp
  - icon: ':x:'
    path: test/yukicoder/644.test.cpp
    title: test/yukicoder/644.test.cpp
  - icon: ':x:'
    path: test/yukicoder/650.LCT.test.cpp
    title: test/yukicoder/650.LCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/658.test.cpp
    title: test/yukicoder/658.test.cpp
  - icon: ':x:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  - icon: ':x:'
    path: test/yukicoder/685.test.cpp
    title: test/yukicoder/685.test.cpp
  - icon: ':x:'
    path: test/yukicoder/737.test.cpp
    title: test/yukicoder/737.test.cpp
  - icon: ':x:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  - icon: ':x:'
    path: test/yukicoder/886.numth.test.cpp
    title: test/yukicoder/886.numth.test.cpp
  - icon: ':x:'
    path: test/yukicoder/950.test.cpp
    title: test/yukicoder/950.test.cpp
  - icon: ':x:'
    path: test/yukicoder/963.FPS.test.cpp
    title: test/yukicoder/963.FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/963.test.cpp
    title: test/yukicoder/963.test.cpp
  - icon: ':x:'
    path: test/yukicoder/980.test.cpp
    title: test/yukicoder/980.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include\
    \ <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod)\
    \ {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for (Int\
    \ q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a / b), a= b, b= c -\
    \ b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n\
    #define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n\
    \ CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n  return\
    \ l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { \\\n  if\
    \ (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n static CE\
    \ IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\n\
    \ static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 4 \"\
    src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\nstruct\
    \ m_b {};\nstruct s_b: m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b,\
    \ mod_t>;\ntemplate <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b,\
    \ mod_t>;\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n template <class\
    \ T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val()\
    \ % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T, __int128_t>,\
    \ nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod)\
    \ ? B::md.mod - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt&\
    \ r), B::md.plus(x, r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n\
    \ FUNC(operator*(const MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x,\
    \ k, B::md))\n#undef FUNC\n CE MInt operator/(const MInt& r) const { return *this\
    \ * r.inv(); }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r;\
    \ }\n CE MInt& operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt&\
    \ operator*=(const MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const\
    \ MInt& r) { return *this= *this / r; }\n CE bool operator==(const MInt& r) const\
    \ { return B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt&\
    \ r) const { return !(*this == r); }\n CE bool operator<(const MInt& r) const\
    \ { return B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return\
    \ mod_inv<Int>(val(), B::md.mod); }\n CE inline Uint val() const { return B::md.get(x);\
    \ }\n friend ostream& operator<<(ostream& os, const MInt& r) { return os << r.val();\
    \ }\n friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is\
    \ >> v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using\
    \ ModInt= conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32,\
    \ u64, 32, 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64,\
    \ SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64,\
    \ u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LM> mod_t get_inv(int\
    \ n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m= mod_t::mod();\n\
    \ static mod_t dat[LM];\n static int l= 1;\n if (l == 1) dat[l++]= 1;\n while\
    \ (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n"
  code: "#pragma once\n#include \"src/Math/mod_inv.hpp\"\n#include \"src/Internal/Remainder.hpp\"\
    \nnamespace math_internal {\n#define CE constexpr\nstruct m_b {};\nstruct s_b:\
    \ m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\n\
    template <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\n\
    template <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n\
    };\ntemplate <class Int, class U, class B> struct MInt: public B {\n using Uint=\
    \ U;\n static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n\
    \ CE MInt(const MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ CE MInt(T n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod - n :\
    \ n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() - *this;\
    \ }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  ret.x=\
    \ op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LM> mod_t get_inv(int\
    \ n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m= mod_t::mod();\n\
    \ static mod_t dat[LM];\n static int l= 1;\n if (l == 1) dat[l++]= 1;\n while\
    \ (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}"
  dependsOn:
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  isVerificationFile: false
  path: src/Math/ModInt.hpp
  requiredBy:
  - src/FFT/fps_inv.hpp
  - src/FFT/FormalPowerSeries.hpp
  - src/FFT/SubProductTree.hpp
  - src/FFT/Polynomial.hpp
  - src/FFT/sequences.hpp
  - src/FFT/NTT.hpp
  - src/FFT/bostan_mori.hpp
  - src/FFT/convolve.hpp
  - src/FFT/fps_div.hpp
  - src/FFT/sample_points_shift.hpp
  - src/FFT/fps_exp.hpp
  - src/FFT/extgcd.hpp
  - src/FFT/BigInt.hpp
  - src/FFT/fps_sqrt.hpp
  - src/FFT/polynomial_matrix_prod.hpp
  - src/FFT/MultiVariateConvolution.hpp
  - src/Math/sparse_fps.hpp
  - src/Math/ModInt_Runtime.hpp
  - src/LinearAlgebra/MinimalPolynomial.hpp
  timestamp: '2023-04-09 22:20:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc160_f.test.cpp
  - test/atcoder/abc256_f.WBT.test.cpp
  - test/atcoder/abc256_f.DynSeg.test.cpp
  - test/atcoder/abc222_g.test.cpp
  - test/atcoder/abc270_g.test.cpp
  - test/atcoder/abc256_f.SegDual.test.cpp
  - test/atcoder/abc235_f.test.cpp
  - test/atcoder/abc230_h.test.cpp
  - test/atcoder/abc234_g.test.cpp
  - test/atcoder/agc038_c.numth.test.cpp
  - test/atcoder/abc276_g.sparse_FPS.test.cpp
  - test/atcoder/arc115_e.test.cpp
  - test/atcoder/arc105_f.test.cpp
  - test/atcoder/abc138_f.test.cpp
  - test/atcoder/arc116_c.dujiao.test.cpp
  - test/atcoder/abc129_e.test.cpp
  - test/atcoder/abc222_h.sparse_FPS.test.cpp
  - test/atcoder/abc213_g.test.cpp
  - test/atcoder/abc213_h.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
  - test/yosupo/lcm_convolution.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/log_of_sparse_FPS.test.cpp
  - test/yosupo/inv_of_FPS.FPS.test.cpp
  - test/yosupo/matrix_product.test.cpp
  - test/yosupo/exp_of_sparse_FPS.test.cpp
  - test/yosupo/pow_of_FPS.FPS.test.cpp
  - test/yosupo/convolution_mod_2_64.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/yosupo/division_of_Poly.test.cpp
  - test/yosupo/z_algorithm.rollinghash.test.cpp
  - test/yosupo/stirling_1.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - test/yosupo/exp_of_FPS.test.cpp
  - test/yosupo/stirling_2.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
  - test/yosupo/dynamic_sequence_range_affine_range_sum.test.cpp
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
  - test/yosupo/inv_of_sparse_FPS.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/comp_of_FPS.test.cpp
  - test/yosupo/inv_of_Poly.test.cpp
  - test/yosupo/convolution1000000007.test.cpp
  - test/yosupo/discrete_logarithm_mod.test.cpp
  - test/yosupo/range_affine_range_sum.DynSeg.test.cpp
  - test/yosupo/linear_equations.test.cpp
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  - test/yosupo/convolution_large.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - test/yosupo/partition.MSET.test.cpp
  - test/yosupo/sum_of_totient_function.test.cpp
  - test/yosupo/sqrt_of_FPS.test.cpp
  - test/yosupo/log_of_FPS.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/shift_of_FPS.test.cpp
  - test/yosupo/bernoulli.test.cpp
  - test/yosupo/inv_of_FPS.test.cpp
  - test/yosupo/pow_of_FPS.test.cpp
  - test/yosupo/point_set_range_composite.SegTree.test.cpp
  - test/yosupo/find_linear_recurrence.test.cpp
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/multivariate_convolution.test.cpp
  - test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
  - test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  - test/yosupo/log_of_FPS.FPS.test.cpp
  - test/yosupo/range_affine_range_sum.WBT.test.cpp
  - test/yosupo/pow_of_sparse_FPS.test.cpp
  - test/yosupo/subset_convolution.test.cpp
  - test/yosupo/exp_of_FPS.FPS.test.cpp
  - test/yosupo/sharp_p_subset_sum.PSET.test.cpp
  - test/yosupo/partition.test.cpp
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/aoj/2530.test.cpp
  - test/aoj/2397.MinPoly.test.cpp
  - test/aoj/2397.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/3072.test.cpp
  - test/aoj/0168.test.cpp
  - test/aoj/2257.test.cpp
  - test/aoj/NTL_2_B.test.cpp
  - test/aoj/NTL_2_D.test.cpp
  - test/aoj/NTL_2_E.test.cpp
  - test/aoj/2614.rollinghash.test.cpp
  - test/aoj/NTL_2_A.test.cpp
  - test/aoj/2863.test.cpp
  - test/aoj/NTL_2_F.test.cpp
  - test/aoj/NTL_2_C.test.cpp
  - test/aoj/2711.rollinghash.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/215.Poly.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/yukicoder/215.test.cpp
  - test/yukicoder/1750.test.cpp
  - test/yukicoder/963.test.cpp
  - test/yukicoder/42.test.cpp
  - test/yukicoder/737.test.cpp
  - test/yukicoder/685.test.cpp
  - test/yukicoder/1939.test.cpp
  - test/yukicoder/137.div_at.test.cpp
  - test/yukicoder/1124.test.cpp
  - test/yukicoder/658.test.cpp
  - test/yukicoder/886.numth.test.cpp
  - test/yukicoder/1145.test.cpp
  - test/yukicoder/650.LCT.test.cpp
  - test/yukicoder/315.test.cpp
  - test/yukicoder/1075.test.cpp
  - test/yukicoder/3046.test.cpp
  - test/yukicoder/502.test.cpp
  - test/yukicoder/1333.test.cpp
  - test/yukicoder/1080.test.cpp
  - test/yukicoder/235.HLD.test.cpp
  - test/yukicoder/950.test.cpp
  - test/yukicoder/644.test.cpp
  - test/yukicoder/980.test.cpp
  - test/yukicoder/1750.MinPoly.test.cpp
  - test/yukicoder/235.LCT.test.cpp
  - test/yukicoder/963.FPS.test.cpp
  - test/yukicoder/1269.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/1533.test.cpp
  - test/yukicoder/1417.test.cpp
  - test/yukicoder/665.test.cpp
  - test/yukicoder/1019.test.cpp
  - test/yukicoder/1080.sparse_FPS.test.cpp
documentation_of: src/Math/ModInt.hpp
layout: document
title: ModInt
---
