---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/Graph/UndirectedGraphSetPowerSeries.hpp
    title: "\u7121\u5411\u30B0\u30E9\u30D5\u6570\u3048\u4E0A\u3052(\u96C6\u5408\u51AA\
      \u7D1A\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2345.test.cpp
    title: test/aoj/2345.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc199_d.test.cpp
    title: test/atcoder/abc199_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_g.test.cpp
    title: test/atcoder/abc213_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc236_ex.test.cpp
    title: test/atcoder/abc236_ex.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc253_ex.test.cpp
    title: test/atcoder/abc253_ex.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc105_f.test.cpp
    title: test/atcoder/arc105_f.test.cpp
  - icon: ':x:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_composite_set_power_series.test.cpp
    title: test/yosupo/polynomial_composite_set_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1142.test.cpp
    title: test/yukicoder/1142.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1753.test.cpp
    title: test/yukicoder/1753.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1901.test.cpp
    title: test/yukicoder/1901.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2507.test.cpp
    title: test/yukicoder/2507.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/set_power_series.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#include <cassert>\nnamespace sps {\nnamespace _sps_internal\
    \ {\nusing namespace std;\n#define _ZETA(s, l) \\\n if constexpr (!t) A[s + l]+=\
    \ A[s]; \\\n else if constexpr (t == 1) A[s + l]-= A[s]; \\\n else if constexpr\
    \ (t == 2) A[s]+= A[s + l]; \\\n else if constexpr (t == 3) A[s]-= A[s + l]; \\\
    \n else tie(A[s], A[s + l])= make_pair(A[s] + A[s + l], A[s] - A[s + l]);\ntemplate\
    \ <int t, class T> void rec(T A[], int l) {\n if (l > 127) {\n  l>>= 1, rec<t>(A,\
    \ l), rec<t>(A + l, l);\n  for (int s= 0; s < l; ++s) _ZETA(s, l);\n } else\n\
    \  for (int k= 1; k < l; k<<= 1)\n   for (int i= 0; i < l; i+= k + k)\n    for\
    \ (int j= 0; j < k; ++j) _ZETA(i + j, k);\n}\n#undef _ZETA\n/*  f -> g s.t. g[S]\
    \ = sum_{T subseteq S} f[T]  O(n 2^n) */\ntemplate <class T> void subset_zeta(vector<T>&\
    \ f) { rec<0>(f.data(), f.size()); }\n/*  f -> h s.t. f[S] = sum_{T subseteq S}\
    \ h[T]  O(n 2^n) */\ntemplate <class T> void subset_mobius(vector<T>& f) { rec<1>(f.data(),\
    \ f.size()); }\n/*  f -> g s.t. g[S] = sum_{S subseteq T} f[T]  O(n 2^n) */\n\
    template <class T> void supset_zeta(vector<T>& f) { rec<2>(f.data(), f.size());\
    \ }\n/*  f -> h s.t. f[S] = sum_{S subseteq T} h[T]  O(n 2^n) */\ntemplate <class\
    \ T> void supset_mobius(vector<T>& f) { rec<3>(f.data(), f.size()); }\n/* h[S]\
    \ = sum_{U | T == S} f[U]g[T]  O(n 2^n) */\ntemplate <class T> vector<T> or_convolve(vector<T>\
    \ f, vector<T> g) {\n subset_zeta(f), subset_zeta(g);\n for (int s= f.size();\
    \ s--;) f[s]*= g[s];\n return subset_mobius(f), f;\n}\n/* h[S] = sum_{U & T ==\
    \ S} f[U]g[T]  O(n 2^n) */\ntemplate <class T> vector<T> and_convolve(vector<T>\
    \ f, vector<T> g) {\n supset_zeta(f), supset_zeta(g);\n for (int s= f.size();\
    \ s--;) f[s]*= g[s];\n return supset_mobius(f), f;\n}\n/* f -> g s.t. g[S] = sum_{T}\
    \ (-1)^{|S & T|} f[T] */\ntemplate <class T> void hadamard(vector<T>& f) { rec<4>(f.data(),\
    \ f.size()); }\n/* h[S] = sum_{U ^ T = S} f[U]g[T] */\ntemplate <class T> vector<T>\
    \ xor_convolve(vector<T> f, vector<T> g) {\n hadamard(f), hadamard(g);\n for (int\
    \ s= f.size(); s--;) f[s]*= g[s];\n hadamard(f);\n if (T iv= T(1) / f.size();\
    \ iv == 0)\n  for (int s= f.size(); s--;) f[s]/= f.size();\n else\n  for (int\
    \ s= f.size(); s--;) f[s]*= iv;\n return f;\n}\ntemplate <int t, class T> void\
    \ rec_r(T A[], int l, int n, int c= 0) {\n if (l >= (n << 4)) {\n  l>>= 1, rec_r<t>(A,\
    \ l, n, c), rec_r<t>(A + l, l, n, c + 1);\n  for (int s= l / n; s--;)\n   if constexpr\
    \ (!t)\n    for (int d= 0, e= __builtin_popcount(s) + c + 1; d < e; ++d) A[s *\
    \ n + d + l]+= A[s * n + d];\n   else\n    for (int d= __builtin_popcount(s) +\
    \ c + 1; d < n; ++d) A[s * n + d + l]-= A[s * n + d];\n } else\n  for (int k=\
    \ 1, m= l / n; k < m; k<<= 1)\n   for (int i= 0; i < m; i+= k + k)\n    for (int\
    \ j= 0; j < k; ++j)\n     if constexpr (!t)\n      for (int u= i + j, s= u + k,\
    \ d= 0, e= __builtin_popcount(s) + c; d < e; ++d) A[s * n + d]+= A[u * n + d];\n\
    \     else\n      for (int u= i + j, s= u + k, d= __builtin_popcount(s) + c; d\
    \ < n; ++d) A[s * n + d]-= A[u * n + d];\n}\ntemplate <class T> void rnk_zeta(const\
    \ T f[], T F[], int n) {\n for (int s= 1 << n; s--;) F[s * (n + 1) + __builtin_popcount(s)]=\
    \ f[s];\n rec_r<0>(F, (n + 1) << n, n + 1);\n}\ntemplate <class T> void rnk_mobius(T\
    \ F[], T f[], int n) {\n rec_r<1>(F, (n + 1) << n, n + 1);\n for (int s= 1 <<\
    \ n; s--;) f[s]= F[s * (n + 1) + __builtin_popcount(s)];\n}\ntemplate <class T>\
    \ void cnv_(T A[], T B[], int n) {\n for (int s= 1 << (n - 1); s--;) {\n  T t,\
    \ *a= A + s * n, *b= B + s * n;\n  for (int c= __builtin_popcount(s), d= min(2\
    \ * c, n - 1), e; d >= c; a[d--]= t)\n   for (t= 0, e= d - c; e <= c; ++e) t+=\
    \ a[e] * b[d - e];\n }\n}\ntemplate <class T> void cnv_na(const T f[], const T\
    \ g[], T h[], int N) {\n for (int s= N, t; s--;)\n  for (h[t= s]= f[s] * g[0];\
    \ t; --t&= s) h[s]+= f[s ^ t] * g[t];\n}\n// fg, O(n^2 2^n)\ntemplate <class T>\
    \ vector<T> convolve(const vector<T>& f, const vector<T>& g) {\n const int N=\
    \ f.size(), n= __builtin_ctz(N);\n assert(!(N & (N - 1))), assert(N == (int)g.size());\n\
    \ vector<T> h(N);\n if (n < 11) return cnv_na(f.data(), g.data(), h.data(), N),\
    \ h;\n vector<T> F((n + 1) << n);\n if (rnk_zeta(f.data(), F.data(), n); f.data()\
    \ == g.data()) return cnv_(F.data(), F.data(), n + 1), rnk_mobius(F.data(), h.data(),\
    \ n), h;\n vector<T> G((n + 1) << n);\n return rnk_zeta(g.data(), G.data(), n),\
    \ cnv_(F.data(), G.data(), n + 1), rnk_mobius(F.data(), h.data(), n), h;\n}\n\
    template <class T> void div_na(T f[], const T g[], int N) {\n for (int s= 1; s\
    \ < N; ++s)\n  for (int t= s; t; --t&= s) f[s]-= f[s ^ t] * g[t];\n}\n// 1/f,\
    \ \"f[empty] = 1\" is required, O(n^2 2^n)\ntemplate <class T> vector<T> inv(const\
    \ vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N);\n assert(!(N &\
    \ (N - 1))), assert(f[0] == 1);\n vector<T> h(N);\n if (n < 11) return h[0]= 1,\
    \ div_na(h.data(), f.data(), N), h;\n vector<T> F((n + 1) << n), G((n + 1) <<\
    \ n);\n rnk_zeta(f.data(), G.data(), n);\n for (int s= N; s--;) {\n  T *a= F.data()\
    \ + s * (n + 1), *b= G.data() + s * (n + 1);\n  a[0]= 1;\n  for (int d= 0, c=\
    \ __builtin_popcount(s); d++ < n;)\n   for (int e= max(0, d - c); e < d; ++e)\
    \ a[d]-= a[e] * b[d - e];\n }\n return rnk_mobius(F.data(), h.data(), n), h;\n\
    }\n// f/g, \"f[empty] = 1\" is required, O(n^2 2^n)\ntemplate <class T> vector<T>\
    \ div(vector<T> f, const vector<T>& g) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1))), assert(N == (int)g.size()), assert(g[0] == 1);\n if\
    \ (n < 12) return div_na(f.data(), g.data(), N), f;\n vector<T> F((n + 1) << n),\
    \ G((n + 1) << n);\n rnk_zeta(f.data(), F.data(), n), rnk_zeta(g.data(), G.data(),\
    \ n);\n for (int s= N; s--;) {\n  T *a= F.data() + s * (n + 1), *b= G.data() +\
    \ s * (n + 1);\n  for (int d= 0, c= __builtin_popcount(s); d++ < n;)\n   for (int\
    \ e= max(0, d - c); e < d; ++e) a[d]-= a[e] * b[d - e];\n }\n return rnk_mobius(F.data(),\
    \ f.data(), n), f;\n}\ntemplate <class T, class P> void oncnv_(const T f[], T\
    \ h[], const P& phi, int n) {\n vector<T> F((n + 1) << n), G((n + 1) << n);\n\
    \ rnk_zeta(f, F.data(), n), fill_n(G.data(), 1 << n, h[0]);\n T* a= G.data() +\
    \ (1 << n);\n for (int l= 1 << n; l>>= 1;) phi(l, a[l]= h[0] * f[l]), h[l]= a[l];\n\
    \ for (int d= 2, s; d <= n; ++d) {\n  for (rec<0>(a, 1 << n), a+= (s= 1 << n);\
    \ --s;)\n   if (int c= __builtin_popcount(s); c <= d && d <= 2 * c)\n    for (int\
    \ e= d; e--;) a[s]+= G[e << n | s] * F[s * (n + 1) + d - e];\n  for (rec<1>(a,\
    \ 1 << n), s= 1 << n; --s;)\n   if (__builtin_popcount(s) == d) phi(s, a[s]),\
    \ h[s]= a[s];\n   else a[s]= 0;\n }\n}\n// h[S] = phi(S, sum_{T subsetneq S} h[T]f[S/T]\
    \ )  O(n^2 2^n)\n// phi: [](int, T&x)\ntemplate <class T, class P> vector<T> semi_relaxed_convolve(const\
    \ vector<T>& f, T init, const P& phi) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1)));\n vector<T> h(N);\n if (h[0]= init; n < 12) {\n  for\
    \ (int s= 1, t; s < N; phi(s, h[s]), ++s)\n   for (t= s; t; --t&= s) h[s]+= h[s\
    \ ^ t] * f[t];\n } else oncnv_(f.data(), h.data(), phi, n);\n return h;\n}\n//\
    \ h[S] = phi(S, 1/2 sum_{empty neq T subseteq S} h[T]h[S/T] )  O(n^2 2^n)\n//\
    \ phi: [](int, T&x)\ntemplate <class T, class P> vector<T> self_relaxed_convolve(const\
    \ P& phi, int n) {\n const int e= min(n, 12);\n int i= 0, l= 1;\n vector<T> f(1\
    \ << n);\n for (int u= 1; i < e; l<<= 1, ++i)\n  for (int s= 0; s < l; phi(u,\
    \ f[u]), ++s, ++u)\n   for (int t= s; t; --t&= s) f[u]+= f[u ^ t] * f[t];\n for\
    \ (; i < n; l<<= 1, ++i)\n  phi(l, f[l]), oncnv_(\n                    f.data(),\
    \ f.data() + l, [&](int s, T& x) { phi(s | l, x); }, i);\n return f;\n}\n// exp(f)\
    \ , \"f[empty] = 0\" is required,  O(n^2 2^n)\ntemplate <class T> vector<T> exp(const\
    \ vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N), e= min(n, 11);\n\
    \ assert(!(N & (N - 1))), assert(f[0] == 0);\n vector<T> h(N);\n int i= 0, l=\
    \ 1;\n for (h[0]= 1; i < e; l<<= 1, ++i) cnv_na(h.data(), f.data() + l, h.data()\
    \ + l, l);\n for (; i < n; l<<= 1, ++i) {\n  vector<T> F((i + 1) << i), G((i +\
    \ 1) << i);\n  rnk_zeta(h.data(), F.data(), i), rnk_zeta(f.data() + l, G.data(),\
    \ i), cnv_(F.data(), G.data(), i + 1), rnk_mobius(F.data(), h.data() + l, i);\n\
    \ }\n return h;\n}\n// log(f) , \"f[empty] = 1\" is required,  O(n^2 2^n)\ntemplate\
    \ <class T> vector<T> log(const vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N),\
    \ e= min(n, 12);\n assert(!(N & (N - 1))), assert(f[0] == 1);\n vector<T> h= f;\n\
    \ int i= 0, l= 1;\n for (; i < e; l<<= 1, ++i) div_na(h.data() + l, f.data(),\
    \ l);\n if (i < n) {\n  vector<T> G(n << (n - 1));\n  rnk_zeta(f.data(), G.data(),\
    \ n - 1);\n  for (; i < n; l<<= 1, ++i) {\n   vector<T> F((i + 1) << i, 0);\n\
    \   if constexpr (is_floating_point_v<T>) {\n    fill_n(F.data(), l, h[l]= f[l]);\n\
    \    T* a= F.data() + l;\n    for (int m= l; m>>= 1;) h[l | m]= a[m]= f[l | m]\
    \ - h[l] * f[m];\n    for (int d= 2, s; d <= i; ++d) {\n     for (rec<0>(a, l),\
    \ a+= (s= l); --s;)\n      if (int c= __builtin_popcount(s); c <= d && d <= 2\
    \ * c)\n       for (int e= d; e--;) a[s]+= F[e << i | s] * G[s * n + d - e];\n\
    \     for (rec<1>(a, l), s= l; --s;)\n      if (__builtin_popcount(s) == d) h[l\
    \ | s]= a[s]= f[l | s] - a[s];\n      else a[s]= 0;\n    }\n   } else {\n    rnk_zeta(f.data()\
    \ + l, F.data(), i);\n    for (int s= l; s--;) {\n     T t, *a= F.data() + s *\
    \ (i + 1), *b= G.data() + s * n;\n     for (int d= 0, c= __builtin_popcount(s),\
    \ e; d++ < i; a[d]-= t)\n      for (t= 0, e= max(0, d - c); e < d; ++e) t+= a[e]\
    \ * b[d - e];\n    }\n    rnk_mobius(F.data(), h.data() + l, i);\n   }\n  }\n\
    \ }\n return h;\n}\n// F(f) =  sum_i F_i f^i/i! , \"f[empty] = 0\" is required,\
    \ O(n^2 2^n)\ntemplate <class T> vector<T> egf_comp(const vector<T>& F, const\
    \ vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N), e= min(n, 11);\n\
    \ assert(!(N & (N - 1))), assert(f[0] == 0);\n vector<T> h(N);\n T* b= h.data()\
    \ + N;\n for (int i= n - F.size(); i++ < n;) h[N - (1 << i)]= F[n - i];\n int\
    \ i= 0, l= 1;\n for (; i < e; l<<= 1, ++i)\n  for (int j= N >> 1; j >= l; j>>=\
    \ 1) cnv_na(b - j, f.data() + l, b - j - j + l, l);\n if (i < n) {\n  vector<T>\
    \ A(n << (n - 1)), B(n << (n - 1));\n  for (; i < n; l<<= 1, ++i) {\n   fill_n(B.data(),\
    \ (i + 1) << i, 0), rnk_zeta(f.data() + l, B.data(), i);\n   for (int j= N >>\
    \ 1; j >= l; j>>= 1) fill_n(A.data(), (i + 1) << i, 0), rnk_zeta(b - j, A.data(),\
    \ i), cnv_(A.data(), B.data(), i + 1), rnk_mobius(A.data(), b - j - j + l, i);\n\
    \  }\n }\n return h;\n}\n// P(f) = sum_{i=0}^m P_i f^i ,  O(n^2 2^n)\ntemplate\
    \ <class T> vector<T> poly_comp(vector<T> P, vector<T> f) {\n const int N= f.size(),\
    \ n= __builtin_ctz(N);\n assert(!(N & (N - 1)));\n vector<T> F(n + 1);\n for (int\
    \ j= 0, e= P.size();; ++j, --e) {\n  for (int i= e; i--;) (F[j]*= f[0])+= P[i];\n\
    \  if (j == n || e <= 1) break;\n  for (int i= 1; i < e; ++i) P[i - 1]= P[i] *\
    \ i;\n }\n return f[0]= 0, egf_comp(F, f);\n}\ntemplate <class T> vector<T> _egfT(const\
    \ T* b, T* h, int M, int n) {\n T *a, *d;\n vector<T> c(n + 1);\n int l= M;\n\
    \ if (int i= __builtin_ctz(M); i > 10) {\n  vector<T> F((i + 1) << i), G((i +\
    \ 1) << i);\n  for (int m, s; i > 10; fill_n(F.data(), (i + 1) << i, 0), rnk_zeta(h,\
    \ F.data(), i), cnv_(F.data(), G.data(), i + 1), rnk_mobius(F.data(), h, i), b-=\
    \ (l>>= 1), --i)\n   for (fill_n(G.data(), (i + 1) << i, 0), rnk_zeta(b, G.data(),\
    \ i), m= M; m > l; m>>= 1)\n    for (a= h + (m - l), fill_n(F.data(), (i + 1)\
    \ << i, 0), rnk_zeta(a + m - l, F.data(), i), cnv_(F.data(), G.data(), i + 1),\
    \ rec_r<1>(F.data(), (i + 1) << i, i + 1), s= l; s--;) a[s]+= F[s * (i + 1) +\
    \ __builtin_popcount(s)];\n }\n for (; l; cnv_na(h, b, h, l), b-= (l>>= 1))\n\
    \  for (int m= M, s, t; m > l; m>>= 1)\n   for (a= h + (m - l), d= a + (m - l),\
    \ s= l; s--;)\n    for (a[t= s]+= d[s] * b[0]; t; --t&= s) a[s]+= d[s ^ t] * b[t];\n\
    \ for (int i= 0; i <= n; ++i) c[i]= h[(1 << (n - i)) - 1];\n return c;\n}\n//\
    \ [X^{[n]}] f^k/k! for k=0,1,...,n , O(n^2 2^n)\ntemplate <class T> vector<T>\
    \ egf_T(vector<T> f) {\n const int N= f.size(), n= __builtin_ctz(N);\n assert(!(N\
    \ & (N - 1)));\n if (n == 0) return {1};\n if (n == 1) return {0, f[1]};\n return\
    \ _egfT(f.data() + (N >> 2), f.data() + (N >> 1), N >> 2, n);\n}\n// [X^{[n]}]\
    \ f^k/k! g for k=0,1,...,n , O(n^2 2^n)\ntemplate <class T> vector<T> egf_T(const\
    \ vector<T>& f, vector<T> g) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1)));\n if (n == 0) return {g[1]};\n return _egfT(f.data()\
    \ + (N >> 1), g.data(), N >> 1, n);\n}\n}\nusing _sps_internal::subset_zeta, _sps_internal::subset_mobius,\
    \ _sps_internal::supset_zeta, _sps_internal::supset_mobius, _sps_internal::hadamard,\
    \ _sps_internal::or_convolve, _sps_internal::and_convolve, _sps_internal::xor_convolve,\
    \ _sps_internal::convolve, _sps_internal::semi_relaxed_convolve, _sps_internal::self_relaxed_convolve,\
    \ _sps_internal::inv, _sps_internal::div, _sps_internal::exp, _sps_internal::log,\
    \ _sps_internal::egf_comp, _sps_internal::poly_comp, _sps_internal::egf_T;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <cassert>\n\
    namespace sps {\nnamespace _sps_internal {\nusing namespace std;\n#define _ZETA(s,\
    \ l) \\\n if constexpr (!t) A[s + l]+= A[s]; \\\n else if constexpr (t == 1) A[s\
    \ + l]-= A[s]; \\\n else if constexpr (t == 2) A[s]+= A[s + l]; \\\n else if constexpr\
    \ (t == 3) A[s]-= A[s + l]; \\\n else tie(A[s], A[s + l])= make_pair(A[s] + A[s\
    \ + l], A[s] - A[s + l]);\ntemplate <int t, class T> void rec(T A[], int l) {\n\
    \ if (l > 127) {\n  l>>= 1, rec<t>(A, l), rec<t>(A + l, l);\n  for (int s= 0;\
    \ s < l; ++s) _ZETA(s, l);\n } else\n  for (int k= 1; k < l; k<<= 1)\n   for (int\
    \ i= 0; i < l; i+= k + k)\n    for (int j= 0; j < k; ++j) _ZETA(i + j, k);\n}\n\
    #undef _ZETA\n/*  f -> g s.t. g[S] = sum_{T subseteq S} f[T]  O(n 2^n) */\ntemplate\
    \ <class T> void subset_zeta(vector<T>& f) { rec<0>(f.data(), f.size()); }\n/*\
    \  f -> h s.t. f[S] = sum_{T subseteq S} h[T]  O(n 2^n) */\ntemplate <class T>\
    \ void subset_mobius(vector<T>& f) { rec<1>(f.data(), f.size()); }\n/*  f -> g\
    \ s.t. g[S] = sum_{S subseteq T} f[T]  O(n 2^n) */\ntemplate <class T> void supset_zeta(vector<T>&\
    \ f) { rec<2>(f.data(), f.size()); }\n/*  f -> h s.t. f[S] = sum_{S subseteq T}\
    \ h[T]  O(n 2^n) */\ntemplate <class T> void supset_mobius(vector<T>& f) { rec<3>(f.data(),\
    \ f.size()); }\n/* h[S] = sum_{U | T == S} f[U]g[T]  O(n 2^n) */\ntemplate <class\
    \ T> vector<T> or_convolve(vector<T> f, vector<T> g) {\n subset_zeta(f), subset_zeta(g);\n\
    \ for (int s= f.size(); s--;) f[s]*= g[s];\n return subset_mobius(f), f;\n}\n\
    /* h[S] = sum_{U & T == S} f[U]g[T]  O(n 2^n) */\ntemplate <class T> vector<T>\
    \ and_convolve(vector<T> f, vector<T> g) {\n supset_zeta(f), supset_zeta(g);\n\
    \ for (int s= f.size(); s--;) f[s]*= g[s];\n return supset_mobius(f), f;\n}\n\
    /* f -> g s.t. g[S] = sum_{T} (-1)^{|S & T|} f[T] */\ntemplate <class T> void\
    \ hadamard(vector<T>& f) { rec<4>(f.data(), f.size()); }\n/* h[S] = sum_{U ^ T\
    \ = S} f[U]g[T] */\ntemplate <class T> vector<T> xor_convolve(vector<T> f, vector<T>\
    \ g) {\n hadamard(f), hadamard(g);\n for (int s= f.size(); s--;) f[s]*= g[s];\n\
    \ hadamard(f);\n if (T iv= T(1) / f.size(); iv == 0)\n  for (int s= f.size();\
    \ s--;) f[s]/= f.size();\n else\n  for (int s= f.size(); s--;) f[s]*= iv;\n return\
    \ f;\n}\ntemplate <int t, class T> void rec_r(T A[], int l, int n, int c= 0) {\n\
    \ if (l >= (n << 4)) {\n  l>>= 1, rec_r<t>(A, l, n, c), rec_r<t>(A + l, l, n,\
    \ c + 1);\n  for (int s= l / n; s--;)\n   if constexpr (!t)\n    for (int d= 0,\
    \ e= __builtin_popcount(s) + c + 1; d < e; ++d) A[s * n + d + l]+= A[s * n + d];\n\
    \   else\n    for (int d= __builtin_popcount(s) + c + 1; d < n; ++d) A[s * n +\
    \ d + l]-= A[s * n + d];\n } else\n  for (int k= 1, m= l / n; k < m; k<<= 1)\n\
    \   for (int i= 0; i < m; i+= k + k)\n    for (int j= 0; j < k; ++j)\n     if\
    \ constexpr (!t)\n      for (int u= i + j, s= u + k, d= 0, e= __builtin_popcount(s)\
    \ + c; d < e; ++d) A[s * n + d]+= A[u * n + d];\n     else\n      for (int u=\
    \ i + j, s= u + k, d= __builtin_popcount(s) + c; d < n; ++d) A[s * n + d]-= A[u\
    \ * n + d];\n}\ntemplate <class T> void rnk_zeta(const T f[], T F[], int n) {\n\
    \ for (int s= 1 << n; s--;) F[s * (n + 1) + __builtin_popcount(s)]= f[s];\n rec_r<0>(F,\
    \ (n + 1) << n, n + 1);\n}\ntemplate <class T> void rnk_mobius(T F[], T f[], int\
    \ n) {\n rec_r<1>(F, (n + 1) << n, n + 1);\n for (int s= 1 << n; s--;) f[s]= F[s\
    \ * (n + 1) + __builtin_popcount(s)];\n}\ntemplate <class T> void cnv_(T A[],\
    \ T B[], int n) {\n for (int s= 1 << (n - 1); s--;) {\n  T t, *a= A + s * n, *b=\
    \ B + s * n;\n  for (int c= __builtin_popcount(s), d= min(2 * c, n - 1), e; d\
    \ >= c; a[d--]= t)\n   for (t= 0, e= d - c; e <= c; ++e) t+= a[e] * b[d - e];\n\
    \ }\n}\ntemplate <class T> void cnv_na(const T f[], const T g[], T h[], int N)\
    \ {\n for (int s= N, t; s--;)\n  for (h[t= s]= f[s] * g[0]; t; --t&= s) h[s]+=\
    \ f[s ^ t] * g[t];\n}\n// fg, O(n^2 2^n)\ntemplate <class T> vector<T> convolve(const\
    \ vector<T>& f, const vector<T>& g) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1))), assert(N == (int)g.size());\n vector<T> h(N);\n if (n\
    \ < 11) return cnv_na(f.data(), g.data(), h.data(), N), h;\n vector<T> F((n +\
    \ 1) << n);\n if (rnk_zeta(f.data(), F.data(), n); f.data() == g.data()) return\
    \ cnv_(F.data(), F.data(), n + 1), rnk_mobius(F.data(), h.data(), n), h;\n vector<T>\
    \ G((n + 1) << n);\n return rnk_zeta(g.data(), G.data(), n), cnv_(F.data(), G.data(),\
    \ n + 1), rnk_mobius(F.data(), h.data(), n), h;\n}\ntemplate <class T> void div_na(T\
    \ f[], const T g[], int N) {\n for (int s= 1; s < N; ++s)\n  for (int t= s; t;\
    \ --t&= s) f[s]-= f[s ^ t] * g[t];\n}\n// 1/f, \"f[empty] = 1\" is required, O(n^2\
    \ 2^n)\ntemplate <class T> vector<T> inv(const vector<T>& f) {\n const int N=\
    \ f.size(), n= __builtin_ctz(N);\n assert(!(N & (N - 1))), assert(f[0] == 1);\n\
    \ vector<T> h(N);\n if (n < 11) return h[0]= 1, div_na(h.data(), f.data(), N),\
    \ h;\n vector<T> F((n + 1) << n), G((n + 1) << n);\n rnk_zeta(f.data(), G.data(),\
    \ n);\n for (int s= N; s--;) {\n  T *a= F.data() + s * (n + 1), *b= G.data() +\
    \ s * (n + 1);\n  a[0]= 1;\n  for (int d= 0, c= __builtin_popcount(s); d++ < n;)\n\
    \   for (int e= max(0, d - c); e < d; ++e) a[d]-= a[e] * b[d - e];\n }\n return\
    \ rnk_mobius(F.data(), h.data(), n), h;\n}\n// f/g, \"f[empty] = 1\" is required,\
    \ O(n^2 2^n)\ntemplate <class T> vector<T> div(vector<T> f, const vector<T>& g)\
    \ {\n const int N= f.size(), n= __builtin_ctz(N);\n assert(!(N & (N - 1))), assert(N\
    \ == (int)g.size()), assert(g[0] == 1);\n if (n < 12) return div_na(f.data(),\
    \ g.data(), N), f;\n vector<T> F((n + 1) << n), G((n + 1) << n);\n rnk_zeta(f.data(),\
    \ F.data(), n), rnk_zeta(g.data(), G.data(), n);\n for (int s= N; s--;) {\n  T\
    \ *a= F.data() + s * (n + 1), *b= G.data() + s * (n + 1);\n  for (int d= 0, c=\
    \ __builtin_popcount(s); d++ < n;)\n   for (int e= max(0, d - c); e < d; ++e)\
    \ a[d]-= a[e] * b[d - e];\n }\n return rnk_mobius(F.data(), f.data(), n), f;\n\
    }\ntemplate <class T, class P> void oncnv_(const T f[], T h[], const P& phi, int\
    \ n) {\n vector<T> F((n + 1) << n), G((n + 1) << n);\n rnk_zeta(f, F.data(), n),\
    \ fill_n(G.data(), 1 << n, h[0]);\n T* a= G.data() + (1 << n);\n for (int l= 1\
    \ << n; l>>= 1;) phi(l, a[l]= h[0] * f[l]), h[l]= a[l];\n for (int d= 2, s; d\
    \ <= n; ++d) {\n  for (rec<0>(a, 1 << n), a+= (s= 1 << n); --s;)\n   if (int c=\
    \ __builtin_popcount(s); c <= d && d <= 2 * c)\n    for (int e= d; e--;) a[s]+=\
    \ G[e << n | s] * F[s * (n + 1) + d - e];\n  for (rec<1>(a, 1 << n), s= 1 << n;\
    \ --s;)\n   if (__builtin_popcount(s) == d) phi(s, a[s]), h[s]= a[s];\n   else\
    \ a[s]= 0;\n }\n}\n// h[S] = phi(S, sum_{T subsetneq S} h[T]f[S/T] )  O(n^2 2^n)\n\
    // phi: [](int, T&x)\ntemplate <class T, class P> vector<T> semi_relaxed_convolve(const\
    \ vector<T>& f, T init, const P& phi) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1)));\n vector<T> h(N);\n if (h[0]= init; n < 12) {\n  for\
    \ (int s= 1, t; s < N; phi(s, h[s]), ++s)\n   for (t= s; t; --t&= s) h[s]+= h[s\
    \ ^ t] * f[t];\n } else oncnv_(f.data(), h.data(), phi, n);\n return h;\n}\n//\
    \ h[S] = phi(S, 1/2 sum_{empty neq T subseteq S} h[T]h[S/T] )  O(n^2 2^n)\n//\
    \ phi: [](int, T&x)\ntemplate <class T, class P> vector<T> self_relaxed_convolve(const\
    \ P& phi, int n) {\n const int e= min(n, 12);\n int i= 0, l= 1;\n vector<T> f(1\
    \ << n);\n for (int u= 1; i < e; l<<= 1, ++i)\n  for (int s= 0; s < l; phi(u,\
    \ f[u]), ++s, ++u)\n   for (int t= s; t; --t&= s) f[u]+= f[u ^ t] * f[t];\n for\
    \ (; i < n; l<<= 1, ++i)\n  phi(l, f[l]), oncnv_(\n                    f.data(),\
    \ f.data() + l, [&](int s, T& x) { phi(s | l, x); }, i);\n return f;\n}\n// exp(f)\
    \ , \"f[empty] = 0\" is required,  O(n^2 2^n)\ntemplate <class T> vector<T> exp(const\
    \ vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N), e= min(n, 11);\n\
    \ assert(!(N & (N - 1))), assert(f[0] == 0);\n vector<T> h(N);\n int i= 0, l=\
    \ 1;\n for (h[0]= 1; i < e; l<<= 1, ++i) cnv_na(h.data(), f.data() + l, h.data()\
    \ + l, l);\n for (; i < n; l<<= 1, ++i) {\n  vector<T> F((i + 1) << i), G((i +\
    \ 1) << i);\n  rnk_zeta(h.data(), F.data(), i), rnk_zeta(f.data() + l, G.data(),\
    \ i), cnv_(F.data(), G.data(), i + 1), rnk_mobius(F.data(), h.data() + l, i);\n\
    \ }\n return h;\n}\n// log(f) , \"f[empty] = 1\" is required,  O(n^2 2^n)\ntemplate\
    \ <class T> vector<T> log(const vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N),\
    \ e= min(n, 12);\n assert(!(N & (N - 1))), assert(f[0] == 1);\n vector<T> h= f;\n\
    \ int i= 0, l= 1;\n for (; i < e; l<<= 1, ++i) div_na(h.data() + l, f.data(),\
    \ l);\n if (i < n) {\n  vector<T> G(n << (n - 1));\n  rnk_zeta(f.data(), G.data(),\
    \ n - 1);\n  for (; i < n; l<<= 1, ++i) {\n   vector<T> F((i + 1) << i, 0);\n\
    \   if constexpr (is_floating_point_v<T>) {\n    fill_n(F.data(), l, h[l]= f[l]);\n\
    \    T* a= F.data() + l;\n    for (int m= l; m>>= 1;) h[l | m]= a[m]= f[l | m]\
    \ - h[l] * f[m];\n    for (int d= 2, s; d <= i; ++d) {\n     for (rec<0>(a, l),\
    \ a+= (s= l); --s;)\n      if (int c= __builtin_popcount(s); c <= d && d <= 2\
    \ * c)\n       for (int e= d; e--;) a[s]+= F[e << i | s] * G[s * n + d - e];\n\
    \     for (rec<1>(a, l), s= l; --s;)\n      if (__builtin_popcount(s) == d) h[l\
    \ | s]= a[s]= f[l | s] - a[s];\n      else a[s]= 0;\n    }\n   } else {\n    rnk_zeta(f.data()\
    \ + l, F.data(), i);\n    for (int s= l; s--;) {\n     T t, *a= F.data() + s *\
    \ (i + 1), *b= G.data() + s * n;\n     for (int d= 0, c= __builtin_popcount(s),\
    \ e; d++ < i; a[d]-= t)\n      for (t= 0, e= max(0, d - c); e < d; ++e) t+= a[e]\
    \ * b[d - e];\n    }\n    rnk_mobius(F.data(), h.data() + l, i);\n   }\n  }\n\
    \ }\n return h;\n}\n// F(f) =  sum_i F_i f^i/i! , \"f[empty] = 0\" is required,\
    \ O(n^2 2^n)\ntemplate <class T> vector<T> egf_comp(const vector<T>& F, const\
    \ vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N), e= min(n, 11);\n\
    \ assert(!(N & (N - 1))), assert(f[0] == 0);\n vector<T> h(N);\n T* b= h.data()\
    \ + N;\n for (int i= n - F.size(); i++ < n;) h[N - (1 << i)]= F[n - i];\n int\
    \ i= 0, l= 1;\n for (; i < e; l<<= 1, ++i)\n  for (int j= N >> 1; j >= l; j>>=\
    \ 1) cnv_na(b - j, f.data() + l, b - j - j + l, l);\n if (i < n) {\n  vector<T>\
    \ A(n << (n - 1)), B(n << (n - 1));\n  for (; i < n; l<<= 1, ++i) {\n   fill_n(B.data(),\
    \ (i + 1) << i, 0), rnk_zeta(f.data() + l, B.data(), i);\n   for (int j= N >>\
    \ 1; j >= l; j>>= 1) fill_n(A.data(), (i + 1) << i, 0), rnk_zeta(b - j, A.data(),\
    \ i), cnv_(A.data(), B.data(), i + 1), rnk_mobius(A.data(), b - j - j + l, i);\n\
    \  }\n }\n return h;\n}\n// P(f) = sum_{i=0}^m P_i f^i ,  O(n^2 2^n)\ntemplate\
    \ <class T> vector<T> poly_comp(vector<T> P, vector<T> f) {\n const int N= f.size(),\
    \ n= __builtin_ctz(N);\n assert(!(N & (N - 1)));\n vector<T> F(n + 1);\n for (int\
    \ j= 0, e= P.size();; ++j, --e) {\n  for (int i= e; i--;) (F[j]*= f[0])+= P[i];\n\
    \  if (j == n || e <= 1) break;\n  for (int i= 1; i < e; ++i) P[i - 1]= P[i] *\
    \ i;\n }\n return f[0]= 0, egf_comp(F, f);\n}\ntemplate <class T> vector<T> _egfT(const\
    \ T* b, T* h, int M, int n) {\n T *a, *d;\n vector<T> c(n + 1);\n int l= M;\n\
    \ if (int i= __builtin_ctz(M); i > 10) {\n  vector<T> F((i + 1) << i), G((i +\
    \ 1) << i);\n  for (int m, s; i > 10; fill_n(F.data(), (i + 1) << i, 0), rnk_zeta(h,\
    \ F.data(), i), cnv_(F.data(), G.data(), i + 1), rnk_mobius(F.data(), h, i), b-=\
    \ (l>>= 1), --i)\n   for (fill_n(G.data(), (i + 1) << i, 0), rnk_zeta(b, G.data(),\
    \ i), m= M; m > l; m>>= 1)\n    for (a= h + (m - l), fill_n(F.data(), (i + 1)\
    \ << i, 0), rnk_zeta(a + m - l, F.data(), i), cnv_(F.data(), G.data(), i + 1),\
    \ rec_r<1>(F.data(), (i + 1) << i, i + 1), s= l; s--;) a[s]+= F[s * (i + 1) +\
    \ __builtin_popcount(s)];\n }\n for (; l; cnv_na(h, b, h, l), b-= (l>>= 1))\n\
    \  for (int m= M, s, t; m > l; m>>= 1)\n   for (a= h + (m - l), d= a + (m - l),\
    \ s= l; s--;)\n    for (a[t= s]+= d[s] * b[0]; t; --t&= s) a[s]+= d[s ^ t] * b[t];\n\
    \ for (int i= 0; i <= n; ++i) c[i]= h[(1 << (n - i)) - 1];\n return c;\n}\n//\
    \ [X^{[n]}] f^k/k! for k=0,1,...,n , O(n^2 2^n)\ntemplate <class T> vector<T>\
    \ egf_T(vector<T> f) {\n const int N= f.size(), n= __builtin_ctz(N);\n assert(!(N\
    \ & (N - 1)));\n if (n == 0) return {1};\n if (n == 1) return {0, f[1]};\n return\
    \ _egfT(f.data() + (N >> 2), f.data() + (N >> 1), N >> 2, n);\n}\n// [X^{[n]}]\
    \ f^k/k! g for k=0,1,...,n , O(n^2 2^n)\ntemplate <class T> vector<T> egf_T(const\
    \ vector<T>& f, vector<T> g) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1)));\n if (n == 0) return {g[1]};\n return _egfT(f.data()\
    \ + (N >> 1), g.data(), N >> 1, n);\n}\n}\nusing _sps_internal::subset_zeta, _sps_internal::subset_mobius,\
    \ _sps_internal::supset_zeta, _sps_internal::supset_mobius, _sps_internal::hadamard,\
    \ _sps_internal::or_convolve, _sps_internal::and_convolve, _sps_internal::xor_convolve,\
    \ _sps_internal::convolve, _sps_internal::semi_relaxed_convolve, _sps_internal::self_relaxed_convolve,\
    \ _sps_internal::inv, _sps_internal::div, _sps_internal::exp, _sps_internal::log,\
    \ _sps_internal::egf_comp, _sps_internal::poly_comp, _sps_internal::egf_T;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/set_power_series.hpp
  requiredBy:
  - src/Graph/UndirectedGraphSetPowerSeries.hpp
  timestamp: '2024-02-18 22:00:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1901.test.cpp
  - test/yukicoder/2507.test.cpp
  - test/yukicoder/1753.test.cpp
  - test/yukicoder/1142.test.cpp
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/polynomial_composite_set_power_series.test.cpp
  - test/yosupo/subset_convolution.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/aoj/2345.test.cpp
  - test/atcoder/abc236_ex.test.cpp
  - test/atcoder/abc199_d.test.cpp
  - test/atcoder/abc213_g.test.cpp
  - test/atcoder/arc105_f.test.cpp
  - test/atcoder/abc253_ex.test.cpp
  - test/atcoder/abc212_h.test.cpp
documentation_of: src/Math/set_power_series.hpp
layout: document
title: "\u96C6\u5408\u51AA\u7D1A\u6570"
---

集合 $S,T,U \in 2^{\lbrace0,1,\dots,n-1\rbrace}$ を2進数表記によって非負整数と同一視する.\
環 $K$ 上の集合冪級数 $f,g,h \in K\lbrack x_0,\dots,x_{n-1}\rbrack/(x_0^2,\dots,x_{n-1}^2)$ を 

$\displaystyle 
\begin{aligned}
f(X) = \sum_{S=0}^{2^n-1}f_SX^S, &&g(X) = \sum_{S=0}^{2^n-1}g_SX^S, &&h(X) = \sum_{S=0}^{2^n-1}h_SX^S
\end{aligned}
$

と表記する. ただし $X^S = \prod_{i\in S}x_i$ である.\
$K$は乗法の逆元は必要としない. (各演算は定義できる)

名前空間 `sps` の中に関数が置いてある.

一部，集合冪級数の演算ではないものが含まれているかも

## 関数

| 名前    | 概要  | 計算量    |
| --- | --- | --- |
| `subset_zeta(f)`   | $f$ を $g_S = \sum_{T \subseteq S} f_T$ となる $g$ に変換する.| $O(n2^n)$ |
| `subset_mobius(f)`    | $f$ を $f_S = \sum_{T \subseteq S} h_T$ となる $h$ に変換する.| $O(n2^n)$ |
| `supset_zeta(f)`   | $f$ を $g_S = \sum_{S \subseteq T} f_T$ となる $g$ に変換する.| $O(n2^n)$ |
| `supset_mobius(f)`    | $f$ を $f_S = \sum_{S \subseteq T} h_T$ となる $h$ に変換する.| $O(n2^n)$ |
| `hadamard(f)`   | $f$ を $g_S = \sum_{T} (-1)^{\lvert T\cap S \rvert} f_T$ となる $g$ に変換する. <br> $2^{n/2}$ で割っていない. | $O(n2^n)$ |
| `or_convolve(f,g)`   | $h_S = \sum_{U\cup T = S} f_Ug_{T}$ となる $h$ を返す.  | $O(n2^n)$    |
| `and_convolve(f,g)`   | $h_S = \sum_{U\cap T = S} f_Ug_{T}$ となる $h$ を返す.  | $O(n2^n)$    |
| `xor_convolve(f,g)`   | $h_S = \sum_{U\oplus T = S} f_Ug_{T}$ となる $h$ を返す.  | $O(n2^n)$    |
| `convolve(f,g)`   | $h = fg$ つまり $h_S = \sum_{T \subseteq S} f_Tg_{S\setminus T}$ となる $h$ を返す.  | $O(n^22^n)$    |
| `semi_relaxed_convolve(f, init, phi)` | $\displaystyle  h_S=\begin{cases}  \text{init} & S = \varnothing, \newline \phi_S\left(\sum_{T \subsetneq S} h_Tf_{S\setminus T}\right)& S \neq \varnothing \end{cases}$<br> となる $h$ を返す. <br> $\phi_S$ は `phi(int,T&)` という参照渡しの関数で与える. | $O(n^22^n)$    |
| `self_relaxed_convolve<T>(phi, n)`    | $\displaystyle h_S=\begin{cases} 0 & S= \varnothing, \newline \phi_S\left(\frac{1}{2}\sum_{\varnothing \neq T \subsetneq S}  h_Th_{S\setminus T}\right) & S \neq \varnothing \end{cases}$<br> となる $h$ を返す. <br> $\phi_S$ は `phi(int,T&)` という参照渡しの関数で与える.　<br> | $O(n^22^n)$    |
| `inv(f)`| $h = 1/f$ つまり <br> $\displaystyle \sum_{T \subseteq S} h_Tf_{S\setminus T} = \begin{cases}1 & S=\varnothing,\\ 0 & S\neq \varnothing\end{cases}$ <br>となる $h$  を返す. <br> $f_{\varnothing}=1$ でないと assert で落ちる.    | $O(n^22^n)$    |
| `div(f,g)`| $h = f/g$ つまり $f_S = \sum_{T \subseteq S} h_Tg_{S\setminus T}$ となる $h$  を返す. <br> $f_{\varnothing}=1$ でないと assert で落ちる.    | $O(n^22^n)$    |
| `exp(f)`| $\displaystyle  \exp(f) =  \sum_{i=0}^{\infty} \frac{f^i}{i!} $ を返す. <br> $f_{\varnothing}=0$ でないと assert で落ちる.    | $O(n^22^n)$    |
| `log(f)`| $ \log f $ ( $\exp$ の逆関数 )を返す. <br> $f_{\varnothing}=1$ でないと assert で落ちる.    | $O(n^22^n)$    |
| `egf_comp(F,f)`  | $\displaystyle  F(f) = \sum_{i=0}^{\infty} F_i\frac{f^i}{i!} $ を返す. <br> $f_{\varnothing}=0$ でないと assert で落ちる. | $O(n^22^n)$    |
| `poly_comp(P,f)` | 多項式の合成 $\displaystyle  P(f) = \sum_{i=0}^{m-1}P_if^i $ を返す.   | $O(n^22^n+nm)$ |
| `egf(f)`| $k=0,1,\dots,n$ について<br> $\displaystyle \left\lbrack X^{2^n-1}\right\rbrack\frac{f^k}{k!}$<br> を返す.  | $O(n^22^n)$    |
| `egf(f,g)`   | $k=0,1,\dots,n$ について <br>$\displaystyle \left\lbrack X^{2^n-1}\right\rbrack\frac{f^k}{k!}g$<br> を返す. | $O(n^22^n)$    |

## 参考
[https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex](https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex) \
[https://notes.sshwy.name/Math/Subset-Power-Series](https://notes.sshwy.name/Math/Subset-Power-Series) \
[https://maspypy.com/category/集合べき級数](https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0)
## 問題例
[Xmas Contest 2020 H - Hierarchical Phylogeny](https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h) (self relax or 合成 1-√(1-2f)) \
[LibraOJ #2340. 「WC2018」州区划分](https://loj.ac/p/2340) (semi relax)
