---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/set_power_series.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2345.test.cpp
    title: test/aoj/2345.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc199_d.test.cpp
    title: test/atcoder/abc199_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_g.test.cpp
    title: test/atcoder/abc213_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc253_ex.test.cpp
    title: test/atcoder/abc253_ex.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc105_f.test.cpp
    title: test/atcoder/arc105_f.test.cpp
  - icon: ':x:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2507.test.cpp
    title: test/yukicoder/2507.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/set_power_series.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#include <cassert>\nnamespace sps {\nnamespace sps_internal\
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
    \ + (N >> 1), g.data(), N >> 1, n);\n}\n}\nusing sps_internal::subset_zeta, sps_internal::subset_mobius,\
    \ sps_internal::supset_zeta, sps_internal::supset_mobius, sps_internal::hadamard,\
    \ sps_internal::or_convolve, sps_internal::and_convolve, sps_internal::xor_convolve,\
    \ sps_internal::convolve, sps_internal::semi_relaxed_convolve, sps_internal::self_relaxed_convolve,\
    \ sps_internal::inv, sps_internal::div, sps_internal::exp, sps_internal::log,\
    \ sps_internal::egf_comp, sps_internal::poly_comp, sps_internal::egf_T;\n}\n#line\
    \ 3 \"src/Graph/UndirectedGraphSetPowerSeries.hpp\"\nclass UndirectedGraphSetPowerSeries\
    \ {\n using u64= unsigned long long;\n template <class T> using Sps= std::vector<T>;\n\
    \ template <class T> using Poly= std::vector<T>;\n const int n, N, m, o;\n std::vector<u64>\
    \ adj;\n std::vector<int> es;\n template <class T> static inline T pow(T x, int\
    \ k) {\n  for (T ret(1);; x*= x)\n   if (k& 1 ? ret*= x : 0; !(k>>= 1)) return\
    \ ret;\n }\n template <class F> inline void bfs(int s, const F& f) const {\n \
    \ for (int t= s, u, j; t;)\n   for (f(u= 1 << __builtin_ctz(t)); u;) j= __builtin_ctz(u),\
    \ t^= 1 << j, u^= 1 << j, u|= es[j] & t;\n }\n template <class T, class G> static\
    \ inline void transform_articulation(Sps<T>& f, const G& g) {\n  const int M=\
    \ f.size() / 2;\n  Sps<T> tmp(M);\n  for (int I= M; I; I>>= 1) {\n   for (int\
    \ t= 0; t < M; t+= I)\n    for (int u= I, t2= t << 1; u--;) tmp[t | u]= f[t2 |\
    \ I | u];\n   tmp= g(tmp);\n   for (int t= 0; t < M; t+= I)\n    for (int u= I,\
    \ t2= t << 1; u--;) f[t2 | I | u]= tmp[t | u];\n  }\n }\n template <class T, bool\
    \ b> inline void transform_bridge(Sps<T>& f) const {\n  const int M= N / 2;\n\
    \  Sps<T> tmp(M), tmp2;\n  for (int i= n, I= M; --i; I>>= 1) {\n   for (int t=\
    \ 0; t < M; t+= I)\n    for (int u= I, t2= t << 1; u--;) tmp[t | u]= f[t2 | I\
    \ | u];\n   tmp2.assign(M, 0);\n   for (int t= 0; t < M; t+= I)\n    for (int\
    \ j= i, J= I, t2= t << 1; J>>= 1, j--;)\n     for (int s= J, J2= J * 2; s < I;\
    \ s+= J2)\n      for (int u= s + J; u-- > s;) {\n       if constexpr (b) tmp2[t\
    \ | u]+= f[t2 | u] * adj[i * m + j];\n       else tmp2[t | u]-= f[t2 | u] * adj[i\
    \ * m + j];\n      }\n   tmp= sps::convolve(tmp, sps::exp(tmp2));\n   for (int\
    \ t= 0; t < M; t+= I)\n    for (int u= I, t2= t << 1; u--;) f[t2 | I | u]= tmp[t\
    \ | u];\n  }\n }\n template <class T> inline std::vector<T> cyc() const {\n  std::vector<T>\
    \ cyc(1 << o);\n  for (int i= 0; i < o; ++i) {\n   int a= i + i, b= a + 1, K=\
    \ a + 2, I= 1 << i;\n   std::vector<T> dp0(K << i);\n   dp0[a]= 1;\n   for (int\
    \ s= 0; s < I; ++s) {\n    T* dp0s= dp0.data() + (s * K);\n    for (int u= s |\
    \ I, S= u, j, j0, j1; S; S^= 1 << j) {\n     j= __builtin_ctz(S), j0= j + j, j1=\
    \ j0 + 1;\n     const u64 *A0= adj.data() + (j0 * m), *A1= A0 + m;\n     T dp0s0=\
    \ dp0s[j0], dp0s1= dp0s[j1];\n     cyc[u]+= dp0s0 * A0[b] + dp0s1 * A1[b];\n \
    \    for (int U= I - 1 - s, k, k0, k1; U; U^= 1 << k) {\n      k= __builtin_ctz(U),\
    \ k0= k + k, k1= k0 + 1;\n      dp0s[(K << k) + k0]+= dp0s0 * A0[k1] + dp0s1 *\
    \ A1[k1], dp0s[(K << k) + k1]+= dp0s0 * A0[k0] + dp0s1 * A1[k0];\n     }\n   \
    \ }\n   }\n  }\n  return cyc;\n }\n template <class T> inline std::pair<std::vector<T>,\
    \ std::vector<T>> cyc_pth() const {\n  std::vector<T> cyc(1 << o), pth(1 << o);\n\
    \  for (int i= 0; i < o; ++i) {\n   int a= i + i, b= a + 1, K= a + 2, I= 1 <<\
    \ i;\n   std::vector<T> dp0(K << i), dp1(K << i);\n   dp0[a]= 1;\n   for (int\
    \ s= 0; s < I; ++s) {\n    T *dp0s= dp0.data() + (s * K), *dp1s= dp1.data() +\
    \ (s * K);\n    for (int j= 0; j < K; ++j) dp1s[b]+= dp0s[j];\n    for (int u=\
    \ s | I, S= u, j, j0, j1; S; S^= 1 << j) {\n     j= __builtin_ctz(S), j0= j +\
    \ j, j1= j0 + 1;\n     const u64 *A0= adj.data() + (j0 * m), *A1= A0 + m;\n  \
    \   T dp0s0= dp0s[j0], dp0s1= dp0s[j1], dp1s0= dp1s[j0], dp1s1= dp1s[j1];\n  \
    \   cyc[u]+= dp0s0 * A0[b] + dp0s1 * A1[b], pth[u]+= dp1s0 + dp1s1;\n     for\
    \ (int U= I - 1 - s, k, k0, k1; U; U^= 1 << k) {\n      k= __builtin_ctz(U), k0=\
    \ k + k, k1= k0 + 1;\n      dp0s[(K << k) + k0]+= dp0s0 * A0[k1] + dp0s1 * A1[k1],\
    \ dp0s[(K << k) + k1]+= dp0s0 * A0[k0] + dp0s1 * A1[k0];\n      dp1s[(K << k)\
    \ + k0]+= dp1s0 * A0[k1] + dp1s1 * A1[k1], dp1s[(K << k) + k1]+= dp1s0 * A0[k0]\
    \ + dp1s1 * A1[k0];\n     }\n    }\n   }\n  }\n  return {cyc, pth};\n }\npublic:\n\
    \ UndirectedGraphSetPowerSeries(int n): n(n), N(1 << n), m(n + (n & 1)), o(m /\
    \ 2), adj(m * m), es(n) {}\n template <class Int> UndirectedGraphSetPowerSeries(const\
    \ std::vector<std::vector<Int>>& g): n(g.size()), N(1 << n), m(n + (n & 1)), o(m\
    \ / 2), adj(m * m), es(n) {\n  for (int i= n; i--;)\n   for (int j= i; j--;) assert(g[i][j]\
    \ == g[j][i]);\n  for (int i= n; i--;)\n   for (int j= n; j--;) adj[i * m + j]=\
    \ g[i][j];\n  for (int i= n; i--;)\n   for (int j= n; j--;) es[i]|= !(!(adj[i\
    \ * m + j])) << j;\n }\n void add_edge(int u, int v, u64 cnt= 1) {\n  adj[u *\
    \ m + v]= (adj[v * m + u]+= cnt), es[u]|= (1 << v), es[v]|= (1 << u);\n  if (!(adj[u\
    \ * m + v])) es[u]^= (1 << v), es[v]^= (1 << u);\n }\n const auto operator[](int\
    \ u) const { return adj.begin() + (u * m); }\n template <class T> static inline\
    \ Sps<T> only_connected(const Sps<T>& f) { return sps::log(f); }\n template <class\
    \ T> static inline Sps<T> disjoint_union(const Sps<T>& f) { return sps::exp(f);\
    \ }\n template <class T> static inline Sps<T> only_biconnected(Sps<T> f) { return\
    \ transform_articulation(f, sps::log<T>), f; }\n template <class T> static inline\
    \ Sps<T> articulation_union(Sps<T> f) { return transform_articulation(f, sps::exp<T>),\
    \ f; }\n template <class T> inline Sps<T> only_2edge_connected(Sps<T> f) const\
    \ { return transform_bridge<T, false>(f), f; }\n template <class T> inline Sps<T>\
    \ bridge_union(Sps<T> f) const { return transform_bridge<T, true>(f), f; }\n inline\
    \ Sps<u64> edge_num() const {\n  Sps<u64> ret(N, 0);\n  for (int i= n; i--;)\n\
    \   for (int j= i; j--;) ret[(1 << i) | (1 << j)]= adj[i * m + j];\n  return sps::subset_zeta(ret),\
    \ ret;\n }\n inline Sps<int> connected_component_num() const {\n  Sps<int> ret(N,\
    \ 0);\n  for (int s= N; s--;) bfs(s, [&](int) { ret[s]++; });\n  return ret;\n\
    \ }\n inline Sps<u64> cycle_space_rank() const {\n  Sps<u64> e= edge_num(), ret(N,\
    \ 0);\n  Sps<int> k= connected_component_num();\n  for (int s= N; s--;) ret[s]=\
    \ e[s] + k[s] - __builtin_popcount(s);\n  return ret;\n }\n inline Sps<u64> odd_deg_num()\
    \ const {\n  Sps<u64> ret(N, 0);\n  for (int i= n, I= N; I>>= 1, i--;)\n   for\
    \ (int t= 0, I2= I << 1; t < N; t+= I2)\n    for (int u= I, cnt, v, j; u--; ret[t\
    \ | I | u]+= cnt & 1)\n     for (cnt= 0, v= t | u; v; v^= 1 << j) cnt+= adj[i\
    \ * m + (j= __builtin_ctz(v))];\n  return ret;\n }\n inline Sps<u64> selfloop_num()\
    \ const {\n  Sps<u64> ret(N, 0);\n  for (int i= 0, I= 1; i < n; ++i, I<<= 1)\n\
    \   for (int u= I; u--;) ret[I | u]= ret[u] + adj[i * m + i];\n  return ret;\n\
    \ }\n template <class T, class Int> static inline Sps<T> space_size(const Sps<Int>&\
    \ rank) {\n  Sps<T> ret(rank.size());\n  for (int s= rank.size(); s--;) ret[s]=\
    \ pow<T>(2, rank[s]);\n  return ret;\n }\n template <class T> inline Sps<T> graph()\
    \ const { return space_size<T>(edge_num()); }\n template <class T> inline Sps<T>\
    \ cycle_space_size() const { return space_size<T>(cycle_space_rank()); }\n template\
    \ <class T> inline Sps<T> connected_graph() const { return sps::log(graph<T>());\
    \ }\n template <class T> inline Sps<T> eulerian_graph() const { return sps::log(cycle_space_size<T>());\
    \ }\n template <class T> inline Sps<T> connected_biparate_graph() const {\n  Sps<T>\
    \ tmp= graph<T>(), ret(N, 1);\n  for (int s= N; s--;) ret[s]/= tmp[s];\n  ret=\
    \ sps::convolve(ret, ret);\n  for (int s= N; s--;) ret[s]*= tmp[s];\n  ret= sps::log(ret);\n\
    \  for (int s= N; s--;) ret[s]/= 2;\n  return ret;\n }\n template <class T> inline\
    \ Sps<T> tree() const {\n  Sps<u64> e= edge_num();\n  Sps<T> ret= {0, 1};\n  ret.reserve(N);\n\
    \  for (int I= 2; I < N; I<<= 1) {\n   Sps<T> g(ret);\n   for (int s= I; --s;)\
    \ g[s]*= e[s | I] - e[s] - e[I];\n   g= sps::exp(g), std::copy(g.begin(), g.end(),\
    \ std::back_inserter(ret));\n  }\n  return ret;\n }\n template <class T> inline\
    \ Sps<T> forest() const { return sps::exp(tree<T>()); }\n template <class T> inline\
    \ Sps<T> cycle_graph() const {\n  T dp[N][n - 1];\n  Sps<T> ret(N, 0);\n  for\
    \ (int i= n, I= N; I>>= 1, --i;) {\n   for (int s= I; --s;) std::fill_n(dp[s],\
    \ i, 0);\n   for (int j= i; j--;) dp[1 << j][j]= adj[i * m + j];\n   for (int\
    \ s= 1; s < I; ++s)\n    for (int t= s, j, u, r, k; t; ret[s | I]+= dp[s][j] *\
    \ adj[j * m + i])\n     for (t^= 1 << (j= __builtin_ctz(t)), u= r= s ^ (1 << j);\
    \ u; dp[s][j]+= dp[r][k] * adj[k * m + j]) u^= 1 << (k= __builtin_ctz(u));\n \
    \ }\n  for (int i= n; i--;)\n   for (int j= i; j--;) ret[(1 << i) | (1 << j)]-=\
    \ adj[i * m + j];\n  for (int s= N; --s;) ret[s]/= 2;\n  return ret;\n }\n template\
    \ <class T> inline Sps<T> biconnected_graph() const {\n  Sps<T> ret= connected_graph<T>();\n\
    \  return transform_articulation(ret, sps::log<T>), ret;\n }\n template <class\
    \ T> inline Sps<T> two_edge_connected_graph() const {\n  Sps<T> ret= connected_graph<T>();\n\
    \  return transform_bridge<T, false>(ret), ret;\n }\n template <class T> inline\
    \ Sps<T> cactus_graph() const {\n  auto ret= cycle_graph<T>();\n  for (int i=\
    \ n; i--;)\n   for (int j= i; j--;) ret[(1 << i) | (1 << j)]+= adj[i * m + j];\n\
    \  return transform_articulation(ret, sps::exp<T>), ret;\n }\n template <class\
    \ T> inline Sps<T> acyclic_orientations() const {\n  auto k= connected_component_num();\n\
    \  Sps<T> g(N, 0);\n  for (int s= N; --s;)\n   if (k[s] == __builtin_popcount(s))\
    \ g[s]= k[s] & 1 ? -1 : 1;\n  return g[0]= 1, sps::inv(g);\n }\n template <class\
    \ T> inline std::vector<T> colorings_using_exactly_k_colors_num() const {\n  if\
    \ (n == 0) return {0};  // impossible in any number of ways\n  auto k= connected_component_num();\n\
    \  std::vector<T> indep(N, 0);\n  for (int s= N; --s;) indep[s]= k[s] == __builtin_popcount(s);\n\
    \  return sps::egf_T(indep);\n }\n template <class T> inline Poly<T> chromatic_polynomial()\
    \ const {\n  auto e= colorings_using_exactly_k_colors_num<T>();\n  if (e.back()\
    \ == 0) return {0};\n  Poly<T> ret(n + 1, 0);\n  T tmp[n]= {1};\n  for (int i=\
    \ 1, j; i < n; ++i)\n   for (j= i; j--; tmp[j]*= -i) ret[j + 1]+= tmp[j] * e[i],\
    \ tmp[j + 1]+= tmp[j];\n  for (int j= n; j--;) ret[j + 1]+= tmp[j];\n  return\
    \ ret;\n }\n template <class T> inline T tutte_polynomial(T x, T y) const {\n\
    \  int sum[N], s, t, lim= 2, i, j;\n  T fum[10'000]= {0, 1};\n  std::vector<T>\
    \ g= {0}, h;\n  for (g.reserve(N), h.reserve(N), i= 0; i < n; h= sps::exp(h),\
    \ std::copy(h.begin(), h.end(), std::back_inserter(g)), ++i) {\n   for (sum[0]=\
    \ j= 0; j < i; j++)\n    for (s= t= 1 << j; s--;) sum[s | t]= sum[s] + adj[i *\
    \ m + j];\n   for (h.resize(s= 1 << i); s--; h[s]= g[s] * fum[sum[s]])\n    for\
    \ (; lim <= sum[s]; lim++) fum[lim]= fum[lim - 1] * y + 1;\n  }\n  for (x-= 1,\
    \ t= ~0, j= 0, i= n; i--;) j+= adj[i * m + i];\n  for (bfs((s= N) - 1, [&](int\
    \ u) { t^= u; }); --s&= t;) g[s]*= x;\n  return sps::exp(g)[N - 1] * pow(y, j);\n\
    \ }\n template <class T> inline T perfect_matching() const { return sps::exp(cyc<T>()).back();\
    \ }\n template <class T> inline T all_matching() const {\n  auto [cyc, pth]= cyc_pth<T>();\n\
    \  for (int s= cyc.size(); s--;) cyc[s]+= pth[s];\n  return sps::exp(cyc).back();\n\
    \ }\n template <class T> std::vector<T> k_mathcing() const {\n  auto [cyc, pth]=\
    \ cyc_pth<T>();\n  auto ret= sps::egf_T(pth, sps::exp(cyc));\n  return std::reverse(ret.begin(),\
    \ ret.end()), ret.resize(n / 2 + 1), ret;\n }\n};\n"
  code: "#pragma once\n#include \"src/Math/set_power_series.hpp\"\nclass UndirectedGraphSetPowerSeries\
    \ {\n using u64= unsigned long long;\n template <class T> using Sps= std::vector<T>;\n\
    \ template <class T> using Poly= std::vector<T>;\n const int n, N, m, o;\n std::vector<u64>\
    \ adj;\n std::vector<int> es;\n template <class T> static inline T pow(T x, int\
    \ k) {\n  for (T ret(1);; x*= x)\n   if (k& 1 ? ret*= x : 0; !(k>>= 1)) return\
    \ ret;\n }\n template <class F> inline void bfs(int s, const F& f) const {\n \
    \ for (int t= s, u, j; t;)\n   for (f(u= 1 << __builtin_ctz(t)); u;) j= __builtin_ctz(u),\
    \ t^= 1 << j, u^= 1 << j, u|= es[j] & t;\n }\n template <class T, class G> static\
    \ inline void transform_articulation(Sps<T>& f, const G& g) {\n  const int M=\
    \ f.size() / 2;\n  Sps<T> tmp(M);\n  for (int I= M; I; I>>= 1) {\n   for (int\
    \ t= 0; t < M; t+= I)\n    for (int u= I, t2= t << 1; u--;) tmp[t | u]= f[t2 |\
    \ I | u];\n   tmp= g(tmp);\n   for (int t= 0; t < M; t+= I)\n    for (int u= I,\
    \ t2= t << 1; u--;) f[t2 | I | u]= tmp[t | u];\n  }\n }\n template <class T, bool\
    \ b> inline void transform_bridge(Sps<T>& f) const {\n  const int M= N / 2;\n\
    \  Sps<T> tmp(M), tmp2;\n  for (int i= n, I= M; --i; I>>= 1) {\n   for (int t=\
    \ 0; t < M; t+= I)\n    for (int u= I, t2= t << 1; u--;) tmp[t | u]= f[t2 | I\
    \ | u];\n   tmp2.assign(M, 0);\n   for (int t= 0; t < M; t+= I)\n    for (int\
    \ j= i, J= I, t2= t << 1; J>>= 1, j--;)\n     for (int s= J, J2= J * 2; s < I;\
    \ s+= J2)\n      for (int u= s + J; u-- > s;) {\n       if constexpr (b) tmp2[t\
    \ | u]+= f[t2 | u] * adj[i * m + j];\n       else tmp2[t | u]-= f[t2 | u] * adj[i\
    \ * m + j];\n      }\n   tmp= sps::convolve(tmp, sps::exp(tmp2));\n   for (int\
    \ t= 0; t < M; t+= I)\n    for (int u= I, t2= t << 1; u--;) f[t2 | I | u]= tmp[t\
    \ | u];\n  }\n }\n template <class T> inline std::vector<T> cyc() const {\n  std::vector<T>\
    \ cyc(1 << o);\n  for (int i= 0; i < o; ++i) {\n   int a= i + i, b= a + 1, K=\
    \ a + 2, I= 1 << i;\n   std::vector<T> dp0(K << i);\n   dp0[a]= 1;\n   for (int\
    \ s= 0; s < I; ++s) {\n    T* dp0s= dp0.data() + (s * K);\n    for (int u= s |\
    \ I, S= u, j, j0, j1; S; S^= 1 << j) {\n     j= __builtin_ctz(S), j0= j + j, j1=\
    \ j0 + 1;\n     const u64 *A0= adj.data() + (j0 * m), *A1= A0 + m;\n     T dp0s0=\
    \ dp0s[j0], dp0s1= dp0s[j1];\n     cyc[u]+= dp0s0 * A0[b] + dp0s1 * A1[b];\n \
    \    for (int U= I - 1 - s, k, k0, k1; U; U^= 1 << k) {\n      k= __builtin_ctz(U),\
    \ k0= k + k, k1= k0 + 1;\n      dp0s[(K << k) + k0]+= dp0s0 * A0[k1] + dp0s1 *\
    \ A1[k1], dp0s[(K << k) + k1]+= dp0s0 * A0[k0] + dp0s1 * A1[k0];\n     }\n   \
    \ }\n   }\n  }\n  return cyc;\n }\n template <class T> inline std::pair<std::vector<T>,\
    \ std::vector<T>> cyc_pth() const {\n  std::vector<T> cyc(1 << o), pth(1 << o);\n\
    \  for (int i= 0; i < o; ++i) {\n   int a= i + i, b= a + 1, K= a + 2, I= 1 <<\
    \ i;\n   std::vector<T> dp0(K << i), dp1(K << i);\n   dp0[a]= 1;\n   for (int\
    \ s= 0; s < I; ++s) {\n    T *dp0s= dp0.data() + (s * K), *dp1s= dp1.data() +\
    \ (s * K);\n    for (int j= 0; j < K; ++j) dp1s[b]+= dp0s[j];\n    for (int u=\
    \ s | I, S= u, j, j0, j1; S; S^= 1 << j) {\n     j= __builtin_ctz(S), j0= j +\
    \ j, j1= j0 + 1;\n     const u64 *A0= adj.data() + (j0 * m), *A1= A0 + m;\n  \
    \   T dp0s0= dp0s[j0], dp0s1= dp0s[j1], dp1s0= dp1s[j0], dp1s1= dp1s[j1];\n  \
    \   cyc[u]+= dp0s0 * A0[b] + dp0s1 * A1[b], pth[u]+= dp1s0 + dp1s1;\n     for\
    \ (int U= I - 1 - s, k, k0, k1; U; U^= 1 << k) {\n      k= __builtin_ctz(U), k0=\
    \ k + k, k1= k0 + 1;\n      dp0s[(K << k) + k0]+= dp0s0 * A0[k1] + dp0s1 * A1[k1],\
    \ dp0s[(K << k) + k1]+= dp0s0 * A0[k0] + dp0s1 * A1[k0];\n      dp1s[(K << k)\
    \ + k0]+= dp1s0 * A0[k1] + dp1s1 * A1[k1], dp1s[(K << k) + k1]+= dp1s0 * A0[k0]\
    \ + dp1s1 * A1[k0];\n     }\n    }\n   }\n  }\n  return {cyc, pth};\n }\npublic:\n\
    \ UndirectedGraphSetPowerSeries(int n): n(n), N(1 << n), m(n + (n & 1)), o(m /\
    \ 2), adj(m * m), es(n) {}\n template <class Int> UndirectedGraphSetPowerSeries(const\
    \ std::vector<std::vector<Int>>& g): n(g.size()), N(1 << n), m(n + (n & 1)), o(m\
    \ / 2), adj(m * m), es(n) {\n  for (int i= n; i--;)\n   for (int j= i; j--;) assert(g[i][j]\
    \ == g[j][i]);\n  for (int i= n; i--;)\n   for (int j= n; j--;) adj[i * m + j]=\
    \ g[i][j];\n  for (int i= n; i--;)\n   for (int j= n; j--;) es[i]|= !(!(adj[i\
    \ * m + j])) << j;\n }\n void add_edge(int u, int v, u64 cnt= 1) {\n  adj[u *\
    \ m + v]= (adj[v * m + u]+= cnt), es[u]|= (1 << v), es[v]|= (1 << u);\n  if (!(adj[u\
    \ * m + v])) es[u]^= (1 << v), es[v]^= (1 << u);\n }\n const auto operator[](int\
    \ u) const { return adj.begin() + (u * m); }\n template <class T> static inline\
    \ Sps<T> only_connected(const Sps<T>& f) { return sps::log(f); }\n template <class\
    \ T> static inline Sps<T> disjoint_union(const Sps<T>& f) { return sps::exp(f);\
    \ }\n template <class T> static inline Sps<T> only_biconnected(Sps<T> f) { return\
    \ transform_articulation(f, sps::log<T>), f; }\n template <class T> static inline\
    \ Sps<T> articulation_union(Sps<T> f) { return transform_articulation(f, sps::exp<T>),\
    \ f; }\n template <class T> inline Sps<T> only_2edge_connected(Sps<T> f) const\
    \ { return transform_bridge<T, false>(f), f; }\n template <class T> inline Sps<T>\
    \ bridge_union(Sps<T> f) const { return transform_bridge<T, true>(f), f; }\n inline\
    \ Sps<u64> edge_num() const {\n  Sps<u64> ret(N, 0);\n  for (int i= n; i--;)\n\
    \   for (int j= i; j--;) ret[(1 << i) | (1 << j)]= adj[i * m + j];\n  return sps::subset_zeta(ret),\
    \ ret;\n }\n inline Sps<int> connected_component_num() const {\n  Sps<int> ret(N,\
    \ 0);\n  for (int s= N; s--;) bfs(s, [&](int) { ret[s]++; });\n  return ret;\n\
    \ }\n inline Sps<u64> cycle_space_rank() const {\n  Sps<u64> e= edge_num(), ret(N,\
    \ 0);\n  Sps<int> k= connected_component_num();\n  for (int s= N; s--;) ret[s]=\
    \ e[s] + k[s] - __builtin_popcount(s);\n  return ret;\n }\n inline Sps<u64> odd_deg_num()\
    \ const {\n  Sps<u64> ret(N, 0);\n  for (int i= n, I= N; I>>= 1, i--;)\n   for\
    \ (int t= 0, I2= I << 1; t < N; t+= I2)\n    for (int u= I, cnt, v, j; u--; ret[t\
    \ | I | u]+= cnt & 1)\n     for (cnt= 0, v= t | u; v; v^= 1 << j) cnt+= adj[i\
    \ * m + (j= __builtin_ctz(v))];\n  return ret;\n }\n inline Sps<u64> selfloop_num()\
    \ const {\n  Sps<u64> ret(N, 0);\n  for (int i= 0, I= 1; i < n; ++i, I<<= 1)\n\
    \   for (int u= I; u--;) ret[I | u]= ret[u] + adj[i * m + i];\n  return ret;\n\
    \ }\n template <class T, class Int> static inline Sps<T> space_size(const Sps<Int>&\
    \ rank) {\n  Sps<T> ret(rank.size());\n  for (int s= rank.size(); s--;) ret[s]=\
    \ pow<T>(2, rank[s]);\n  return ret;\n }\n template <class T> inline Sps<T> graph()\
    \ const { return space_size<T>(edge_num()); }\n template <class T> inline Sps<T>\
    \ cycle_space_size() const { return space_size<T>(cycle_space_rank()); }\n template\
    \ <class T> inline Sps<T> connected_graph() const { return sps::log(graph<T>());\
    \ }\n template <class T> inline Sps<T> eulerian_graph() const { return sps::log(cycle_space_size<T>());\
    \ }\n template <class T> inline Sps<T> connected_biparate_graph() const {\n  Sps<T>\
    \ tmp= graph<T>(), ret(N, 1);\n  for (int s= N; s--;) ret[s]/= tmp[s];\n  ret=\
    \ sps::convolve(ret, ret);\n  for (int s= N; s--;) ret[s]*= tmp[s];\n  ret= sps::log(ret);\n\
    \  for (int s= N; s--;) ret[s]/= 2;\n  return ret;\n }\n template <class T> inline\
    \ Sps<T> tree() const {\n  Sps<u64> e= edge_num();\n  Sps<T> ret= {0, 1};\n  ret.reserve(N);\n\
    \  for (int I= 2; I < N; I<<= 1) {\n   Sps<T> g(ret);\n   for (int s= I; --s;)\
    \ g[s]*= e[s | I] - e[s] - e[I];\n   g= sps::exp(g), std::copy(g.begin(), g.end(),\
    \ std::back_inserter(ret));\n  }\n  return ret;\n }\n template <class T> inline\
    \ Sps<T> forest() const { return sps::exp(tree<T>()); }\n template <class T> inline\
    \ Sps<T> cycle_graph() const {\n  T dp[N][n - 1];\n  Sps<T> ret(N, 0);\n  for\
    \ (int i= n, I= N; I>>= 1, --i;) {\n   for (int s= I; --s;) std::fill_n(dp[s],\
    \ i, 0);\n   for (int j= i; j--;) dp[1 << j][j]= adj[i * m + j];\n   for (int\
    \ s= 1; s < I; ++s)\n    for (int t= s, j, u, r, k; t; ret[s | I]+= dp[s][j] *\
    \ adj[j * m + i])\n     for (t^= 1 << (j= __builtin_ctz(t)), u= r= s ^ (1 << j);\
    \ u; dp[s][j]+= dp[r][k] * adj[k * m + j]) u^= 1 << (k= __builtin_ctz(u));\n \
    \ }\n  for (int i= n; i--;)\n   for (int j= i; j--;) ret[(1 << i) | (1 << j)]-=\
    \ adj[i * m + j];\n  for (int s= N; --s;) ret[s]/= 2;\n  return ret;\n }\n template\
    \ <class T> inline Sps<T> biconnected_graph() const {\n  Sps<T> ret= connected_graph<T>();\n\
    \  return transform_articulation(ret, sps::log<T>), ret;\n }\n template <class\
    \ T> inline Sps<T> two_edge_connected_graph() const {\n  Sps<T> ret= connected_graph<T>();\n\
    \  return transform_bridge<T, false>(ret), ret;\n }\n template <class T> inline\
    \ Sps<T> cactus_graph() const {\n  auto ret= cycle_graph<T>();\n  for (int i=\
    \ n; i--;)\n   for (int j= i; j--;) ret[(1 << i) | (1 << j)]+= adj[i * m + j];\n\
    \  return transform_articulation(ret, sps::exp<T>), ret;\n }\n template <class\
    \ T> inline Sps<T> acyclic_orientations() const {\n  auto k= connected_component_num();\n\
    \  Sps<T> g(N, 0);\n  for (int s= N; --s;)\n   if (k[s] == __builtin_popcount(s))\
    \ g[s]= k[s] & 1 ? -1 : 1;\n  return g[0]= 1, sps::inv(g);\n }\n template <class\
    \ T> inline std::vector<T> colorings_using_exactly_k_colors_num() const {\n  if\
    \ (n == 0) return {0};  // impossible in any number of ways\n  auto k= connected_component_num();\n\
    \  std::vector<T> indep(N, 0);\n  for (int s= N; --s;) indep[s]= k[s] == __builtin_popcount(s);\n\
    \  return sps::egf_T(indep);\n }\n template <class T> inline Poly<T> chromatic_polynomial()\
    \ const {\n  auto e= colorings_using_exactly_k_colors_num<T>();\n  if (e.back()\
    \ == 0) return {0};\n  Poly<T> ret(n + 1, 0);\n  T tmp[n]= {1};\n  for (int i=\
    \ 1, j; i < n; ++i)\n   for (j= i; j--; tmp[j]*= -i) ret[j + 1]+= tmp[j] * e[i],\
    \ tmp[j + 1]+= tmp[j];\n  for (int j= n; j--;) ret[j + 1]+= tmp[j];\n  return\
    \ ret;\n }\n template <class T> inline T tutte_polynomial(T x, T y) const {\n\
    \  int sum[N], s, t, lim= 2, i, j;\n  T fum[10'000]= {0, 1};\n  std::vector<T>\
    \ g= {0}, h;\n  for (g.reserve(N), h.reserve(N), i= 0; i < n; h= sps::exp(h),\
    \ std::copy(h.begin(), h.end(), std::back_inserter(g)), ++i) {\n   for (sum[0]=\
    \ j= 0; j < i; j++)\n    for (s= t= 1 << j; s--;) sum[s | t]= sum[s] + adj[i *\
    \ m + j];\n   for (h.resize(s= 1 << i); s--; h[s]= g[s] * fum[sum[s]])\n    for\
    \ (; lim <= sum[s]; lim++) fum[lim]= fum[lim - 1] * y + 1;\n  }\n  for (x-= 1,\
    \ t= ~0, j= 0, i= n; i--;) j+= adj[i * m + i];\n  for (bfs((s= N) - 1, [&](int\
    \ u) { t^= u; }); --s&= t;) g[s]*= x;\n  return sps::exp(g)[N - 1] * pow(y, j);\n\
    \ }\n template <class T> inline T perfect_matching() const { return sps::exp(cyc<T>()).back();\
    \ }\n template <class T> inline T all_matching() const {\n  auto [cyc, pth]= cyc_pth<T>();\n\
    \  for (int s= cyc.size(); s--;) cyc[s]+= pth[s];\n  return sps::exp(cyc).back();\n\
    \ }\n template <class T> std::vector<T> k_mathcing() const {\n  auto [cyc, pth]=\
    \ cyc_pth<T>();\n  auto ret= sps::egf_T(pth, sps::exp(cyc));\n  return std::reverse(ret.begin(),\
    \ ret.end()), ret.resize(n / 2 + 1), ret;\n }\n};"
  dependsOn:
  - src/Math/set_power_series.hpp
  isVerificationFile: false
  path: src/Graph/UndirectedGraphSetPowerSeries.hpp
  requiredBy: []
  timestamp: '2024-02-06 15:06:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2345.test.cpp
  - test/atcoder/abc213_g.test.cpp
  - test/atcoder/arc105_f.test.cpp
  - test/atcoder/abc253_ex.test.cpp
  - test/atcoder/abc199_d.test.cpp
  - test/yukicoder/2507.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
documentation_of: src/Graph/UndirectedGraphSetPowerSeries.hpp
layout: document
title: "\u7121\u5411\u30B0\u30E9\u30D5\u6570\u3048\u4E0A\u3052(\u96C6\u5408\u51AA\u7D1A\
  \u6570)"
---

グラフ $G(V,E)$ について扱う. 
1. $S\subseteq V$ を頂点集合とする**誘導**部分グラフの "ほげ" の個数を $f_S$ とするとき,  $f$ が「ほげの個数を表す集合冪級数」であるとする.
2. $S\subseteq V$ を頂点集合とする部分グラフのうちそれが "ほげグラフ" であるものの個数を $f_S$ とするとき, $f$ が「ほげグラフを表す集合冪級数」であるとする. 

## メンバ関数

※ `selfloop_num()`, `tutte_polynomial(x,y)` 以外は自己ループは無視する. \
※ 多重辺は考慮する.

|名前|概要|計算量|
|---|---|---|
|`UndirectedGraphSetPowerSeries(n)`|コンストラクタ. <br> 頂点数 $n$ を渡す| 以下 $n=\lvert V\rvert$ とする.|
|`UndirectedGraphSetPowerSeries`<br>`(vector<vector<int>> g)`|コンストラクタ. <br>隣接行列を渡す.||
|`add_edge(u,v,c=1)`|無向辺 $(u,v)$ を $c$ 本追加する.||
|`operator[](u)`|隣接行列の第u行目を返す.||
|`only_connected(f)`| 集合冪級数 $f$ が表すグラフについて, そのうち連結してるものだけに制限したグラフ (e.g. 森 → 木) を表す集合冪級数を返す. <br> $f_{\varnothing}=1$ でないと assert で落ちる.      |$\mathcal{O}(n^22^n)$|
|`disjoint_union(f)`|集合冪級数 $f$ が表すグラフについて, それを [disjoint union](https://en.wikipedia.org/wiki/Disjoint_union_of_graphs) (e.g. 木 → 森) したグラフを表す集合冪級数を返す. <br> $f$ が表すグラフは連結であることを想定している. <br> $f_{\varnothing}=0$ でないと assert で落ちる. |$\mathcal{O}(n^22^n)$|
|`only_biconnected(f)`|集合冪級数 $f$ が表すグラフについて, そのうち2頂点連結してるものだけに制限したグラフを表す集合冪級数を返す. <br> $f$ が表すグラフは連結であることを想定している. <br> 各頂点 $v\in V$ について $f_{\lbrace v\rbrace}=1$ でないと assert で落ちる.  |$\mathcal{O}(n^32^n)$|
|`articulation_union(f)`|集合冪級数 $f$ が表すグラフについて, それを関節点で結合したグラフを表す集合冪級数をを返す. <br> $f$ が表すグラフは2頂点連結であることを想定している. <br> 各頂点 $v\in V$ について $f_{\lbrace v\rbrace}=0$ でないと assert で落ちる.  |$\mathcal{O}(n^32^n)$|
|`only_2edge_connected(f)`|集合冪級数 $f$ が表すグラフについて, そのうち2辺連結してるものだけに制限したグラフを表す集合冪級数をを返す. <br> $f$ が表すグラフは連結であることを想定している. |$\mathcal{O}(n^32^n)$|
|`bridge_union(f)`|集合冪級数 $f$ が表すグラフについて, それを橋で結合したグラフを表す集合冪級数をを返す. <br> $f$ が表すグラフは2辺連結であることを想定している. |$\mathcal{O}(n^32^n)$|
|`edge_num()`|辺空間の基底の数 (辺の本数) を表す集合冪級数を返す.|$\mathcal{O}(n2^n)$|
|`connected_component_num()`|連結成分の個数を表す集合冪級数を返す.|$\mathcal{O}(n2^n)$|
|`cycle_space_rank()`|[サイクル基底](https://en.wikipedia.org/wiki/Cycle_basis)の数を表す集合冪級数を返す.|$\mathcal{O}(n2^n)$|
|`selfloop_num()`|自己ループの数を表す集合冪級数を返す.|$\mathcal{O}(2^n)$|
|`odd_deg_num()`|奇数次数の頂点の数を表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`space_size<T>(rank)`|$\mathbb{F}_2$ベクトル空間の基底の数を表す集合冪級数 $f^{\rm rank}$ を渡して, その空間の元の個数を表す集合冪級数を返す.|$\mathcal{O}(2^n)$|
|`graph<T>()`|辺空間の元の個数を表す集合冪級数 (任意のグラフを表す集合冪級) を返す.|$\mathcal{O}(n2^n)$|
|`cycle_space_size<T>()`|サイクル空間の元の個数を表す集合冪級数 (全ての頂点の次数が偶数のグラフを表す集合冪級数) を返す. |$\mathcal{O}(n2^n)$|
|`connected_graph<T>()`|連結グラフを表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`eulerian_graph<T>()`|[オイラーグラフ](https://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E8%B7%AF) (オイラー閉路をもつグラフ) を表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`connected_biparate_graph<T>()`|連結二部グラフを表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`tree<T>()`|木を表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`forest<T>()`|森を表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`cycle_graph<T>()`|[閉路グラフ](https://ja.wikipedia.org/wiki/%E9%96%89%E8%B7%AF%E3%82%B0%E3%83%A9%E3%83%95)を表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`biconnected_graph<T>()`|2頂点連結グラフを表す集合冪級数を返す.|$\mathcal{O}(n^32^n)$|
|`two_edge_connected_graph<T>()`|2辺連結グラフを表す集合冪級数を返す.|$\mathcal{O}(n^32^n)$|
|`cactus_graph<T>()`|[カクタスグラフ](https://ja.wikipedia.org/wiki/%E3%82%AB%E3%82%AF%E3%82%BF%E3%82%B9%E3%82%B0%E3%83%A9%E3%83%95)を表す集合冪級数を返す.|$\mathcal{O}(n^32^n)$|
|`acyclic_orientations<T>()`|[acyclic orientations](https://en.wikipedia.org/wiki/Acyclic_orientation) (DAGにするような向き付け) の個数を表す集合冪級数を返す.|$\mathcal{O}(n^22^n)$|
|`colorings_using_exactly_k_colors_num<T>()`|グラフ $G$ について要素数が $n+1$ 個の配列 `a` を返す.<br> `a[k]` はちょうど $k$ 色を使った頂点彩色の組み合わせ数である.  |$\mathcal{O}(n^22^n)$|
|`chromatic_polynomial<T>()`|グラフ $G$ の[彩色多項式](https://en.wikipedia.org/wiki/Chromatic_polynomial) $P(G,x)=\sum_{i=0}^na_ix^i$ (の係数) を返す. <br> $n=0$ の場合は`vector({0})`を返す.|$\mathcal{O}(n^22^n)$|
|`tutte_polynomial<T>(x,y)`|グラフ $G$ の[Tutte多項式](https://en.wikipedia.org/wiki/Tutte_polynomial)に対して $x,y$ を代入した値を返す. |$\mathcal{O}(n^22^n)$|
|`perfect_matching<T>()`|グラフ $G$ の完全マッチングの組み合わせ数を返す. |$\mathcal{O}(n^22^{n/2})$|
|`all_matching<T>()`|グラフ $G$ の（完全とは限らない）マッチングの組み合わせ数を返す. |$\mathcal{O}(n^22^{n/2})$|
|`k_matching<T>()`|グラフ $G$ について要素数が $\lfloor n/2\rfloor+1$ 個の配列 `a` を返す. <br> `a[k]` はちょうど $k$ 本のマッチングがある組み合わせ数である.|$\mathcal{O}(n^22^{n/2})$|


## 参考
[https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex](https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex)

## 問題例
[LibreOJ #155. Tutte 多项式](https://loj.ac/p/155) (Tutte 多項式) \
[LibreOJ #3165. 「CEOI2019」游乐园](https://loj.ac/p/3165) (acyclic_orientations (Tutte 多項式, 彩色多項式)) \
[LibreOJ #6673. EntropyIncreaser 与山林](https://loj.ac/p/6673) (オイラーグラフ) \
[LibreOJ #6719. 「300iq Contest 2」数仙人掌 加强版](https://loj.ac/p/6719) (カクタスグラフ) \
[LibreOJ #6729. 点双连通生成子图计数](https://loj.ac/p/6729) (二重点連結グラフ) \
[LibreOJ #6730. 边双连通生成子图计数](https://loj.ac/p/6730) (二重辺連結グラフ) \
[LibreOJ #6787. 色多项式](https://loj.ac/p/6787) (彩色多項式)\
[LibraOJ #2340. 「WC2018」州区划分](https://loj.ac/p/2340) \
[Xmas Contest 2022 F - Fast as Fast as Ryser](https://atcoder.jp/contests/xmascon22/tasks/xmascon22_f) (k-matchig) \
[Yuhao Du Contest 7 F. Fast as Ryser](https://qoj.ac/contest/449/problem/2068) (k-mathcing)