---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u3060\u3051\u6301\u3063\u3066\u304A\u304F\
      \u3084\u3064"
  - icon: ':x:'
    path: src/NumberTheory/enumerate_primes.hpp
    title: "\u7D20\u6570\u306E\u5217\u6319"
  - icon: ':question:'
    path: src/NumberTheory/famous_arithmetic_functions.hpp
    title: "\u6709\u540D\u306A\u6570\u8AD6\u7684\u95A2\u6570"
  - icon: ':x:'
    path: src/NumberTheory/tables.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30C6\u30FC\u30D6\u30EB\u3084gcd \u7573\
      \u307F\u8FBC\u307F\u306A\u3069"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_d
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_d
  bundledCode: "#line 1 \"test/atcoder/abc172_d.numth.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n// O(N)\n#include <iostream>\n\
    #line 2 \"src/NumberTheory/enumerate_primes.hpp\"\n#include <algorithm>\n#line\
    \ 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include <iterator>\ntemplate\
    \ <class T> struct ListRange {\n using Iterator= typename std::vector<T>::const_iterator;\n\
    \ Iterator bg, ed;\n Iterator begin() const { return bg; }\n Iterator end() const\
    \ { return ed; }\n size_t size() const { return std::distance(bg, ed); }\n const\
    \ T &operator[](int i) const { return bg[i]; }\n};\n#line 4 \"src/NumberTheory/enumerate_primes.hpp\"\
    \nnamespace nt_internal {\nusing namespace std;\nvector<int> ps, lf;\nvoid sieve(int\
    \ N) {\n static int n= 2, i= 1;\n if (n > N) return;\n if (lf.resize((N >> 1)\
    \ + 1); n == 2) ps.push_back(n++);\n for (; n <= N; n+= 2, ++i) {\n  if (!lf[i])\
    \ ps.push_back(lf[i]= n);\n  for (int j= 1, e= min(lf[i], N / n), k= ps.size();\
    \ j < k && ps[j] <= e; ++j) lf[(ps[j] * n) >> 1]= ps[j];\n }\n}\nListRange<int>\
    \ enumerate_primes(int N) {\n sieve(N);\n return {ps.cbegin(), upper_bound(ps.cbegin(),\
    \ ps.cend(), N)};\n}\nint least_prime_factor(int n) { return n & 1 ? sieve(n),\
    \ lf[(n >> 1)] : 2; }\n// f(p,e) := f(p^e)\ntemplate <class T, class F> vector<T>\
    \ completely_multiplicative_table(int N, const F &f) {\n vector<T> ret(N + 1);\n\
    \ sieve(N);\n for (int n= 3, i= 1; n <= N; n+= 2, ++i) ret[n]= lf[i] == n ? f(n,\
    \ 1) : ret[lf[i]] * ret[n / lf[i]];\n if (int n= 4; 2 <= N)\n  for (T t= ret[2]=\
    \ f(2, 1); n <= N; n+= 2) ret[n]= t * ret[n >> 1];\n return ret[1]= 1, ret;\n\
    }\n}\nusing nt_internal::enumerate_primes, nt_internal::least_prime_factor, nt_internal::completely_multiplicative_table;\n\
    // O(N log k / log N + N)\ntemplate <class T> static std::vector<T> pow_table(int\
    \ N, uint64_t k) {\n if (k == 0) return std::vector<T>(N + 1, 1);\n auto f= [k](int\
    \ p, int) {\n  T ret= 1, b= p;\n  for (auto e= k;; b*= b) {\n   if (e & 1) ret*=\
    \ b;\n   if (!(e>>= 1)) return ret;\n  }\n };\n return completely_multiplicative_table<T>(N,\
    \ f);\n}\n#line 3 \"src/NumberTheory/tables.hpp\"\nnamespace nt_internal {\nvector<int>\
    \ lfw;\nvector<char> lfe;\nvoid set_lfe(int N) {\n static int n= 3, i= 1;\n if\
    \ (n > N) return;\n for (sieve(N), lfw.resize((N >> 1) + 1), copy(lf.begin() +\
    \ i, lf.begin() + (N >> 1) + 1, lfw.begin() + i), lfe.resize((N >> 1) + 1, 1);\
    \ n <= N; n+= 2, ++i)\n  if (int j= (n / lf[i]) >> 1; lf[i] == lf[j]) lfe[i]+=\
    \ lfe[j], lfw[i]*= lfw[j];\n}\n// O(log n)\nvector<pair<int, short>> factorize(int\
    \ n) {\n vector<pair<int, short>> ret;\n if (short t; !(n & 1)) ret.emplace_back(2,\
    \ t= __builtin_ctz(n)), n>>= t;\n if (int i= n >> 1; n > 1)\n  for (set_lfe(n);\
    \ n > 1; i= n >> 1) ret.emplace_back(lf[i], lfe[i]), n/= lfw[i];\n return ret;\n\
    }\n// f(p,e) := f(p^e)\ntemplate <class T, class F> vector<T> multiplicative_table(int\
    \ N, const F &f) {\n vector<T> ret(N + 1);\n set_lfe(N);\n for (int n= 3, i= 1;\
    \ n <= N; n+= 2, ++i) ret[n]= lfw[i] == n ? f(lf[i], lfe[i]) : ret[lfw[i]] * ret[n\
    \ / lfw[i]];\n for (int n= 2, t; n <= N; n+= 2) t= __builtin_ctz(n), ret[n]= n\
    \ & (n - 1) ? ret[n & -n] * ret[n >> t] : f(2, t);\n return ret[1]= 1, ret;\n\
    }\n// O(N)\ntemplate <class T= int> vector<T> mobius_table(int N) {\n vector<T>\
    \ ret(N + 1);\n set_lfe(N), ret[1]= 1;\n for (int n= 3, i= 1; n <= N; n+= 2, ++i)\
    \ ret[n]= lfw[i] == n ? -(lfe[i] == 1) : ret[lfw[i]] * ret[n / lfw[i]];\n for\
    \ (int n= 2; n <= N; n+= 4) ret[n]= -ret[n >> 1];\n return ret;\n}\n// O(N)\n\
    template <class T= int> vector<T> totient_table(int N) {\n vector<T> ret(N + 1);\n\
    \ set_lfe(N), ret[1]= 1;\n for (int n= 3, i= 1; n <= N; n+= 2, ++i) ret[n]= lfw[i]\
    \ == n ? lf[i] == n ? n - 1 : ret[n / lf[i]] * lf[i] : ret[lfw[i]] * ret[n / lfw[i]];\n\
    \ for (int n= 2; n <= N; n+= 2) ret[n]= ret[n >> 1];\n return ret;\n}\n}\nusing\
    \ nt_internal::factorize, nt_internal::multiplicative_table, nt_internal::mobius_table,\
    \ nt_internal::totient_table;\n// f -> g s.t. g(n) = sum_{m|n} f(m), O(N log log\
    \ N)\ntemplate <typename T> void divisor_zeta(std::vector<T> &a) {\n for (auto\
    \ p: enumerate_primes(a.size() - 1))\n  for (int j= 1, e= a.size(); p * j < e;\
    \ ++j) a[p * j]+= a[j];\n}\n// a -> h s.t. a(n) = sum_{m|n} h(m), O(N log log\
    \ N)\ntemplate <typename T> void divisor_mobius(std::vector<T> &a) {\n for (auto\
    \ p: enumerate_primes(a.size() - 1))\n  for (int j= (a.size() - 1) / p; j; --j)\
    \ a[p * j]-= a[j];\n}\n// O(N log log N)\ntemplate <typename T> std::vector<T>\
    \ lcm_convolve(std::vector<T> a, std::vector<T> b) {\n std::size_t N= std::max(a.size(),\
    \ b.size());\n for (a.resize(N), b.resize(N), divisor_zeta(a), divisor_zeta(b);\
    \ N--;) a[N]*= b[N];\n return divisor_mobius(a), a;\n}\n// a -> g s.t. g(n) =\
    \ sum_{n|m} a(m), O(N log log N)\ntemplate <typename T> static void multiple_zeta(std::vector<T>\
    \ &a) {\n for (auto p: enumerate_primes(a.size() - 1))\n  for (int j= (a.size()\
    \ - 1) / p; j; --j) a[j]+= a[p * j];\n}\n// a -> h s.t. a(n) = sum_{n|m} h(m),\
    \ O(N log log N)\ntemplate <typename T> static void multiple_mobius(std::vector<T>\
    \ &a) {\n for (auto p: enumerate_primes(a.size() - 1))\n  for (int j= 1, e= a.size();\
    \ p * j < e; ++j) a[j]-= a[p * j];\n}\n// O(N log log N)\ntemplate <typename T>\
    \ static std::vector<T> gcd_convolve(std::vector<T> a, std::vector<T> b) {\n std::size_t\
    \ N= std::max(a.size(), b.size());\n for (a.resize(N), b.resize(N), multiple_zeta(a),\
    \ multiple_zeta(b); N--;) a[N]*= b[N];\n return multiple_mobius(a), a;\n}\n#line\
    \ 3 \"src/NumberTheory/famous_arithmetic_functions.hpp\"\n#include <cstdint>\n\
    namespace famous_arithmetic_functions {\nnamespace mul {\ntemplate <class T> struct\
    \ Totient {\n static constexpr T f(uint64_t p, short e) {\n  T ret= p - 1;\n \
    \ while (--e) ret*= p;\n  return ret;\n }\n static std::vector<T> poly() { return\
    \ {-1, 1}; }\n};\ntemplate <class T> struct Moebius {\n static constexpr T f(uint64_t,\
    \ short e) { return (e == 0) - (e == 1); }\n static std::vector<T> poly() { return\
    \ {-1}; }\n};\ntemplate <class T> struct Liouville {\n static constexpr T f(uint64_t,\
    \ short e) { return e & 1 ? -1 : 1; }\n static std::vector<T> poly() { return\
    \ {-1}; }\n};\ntemplate <class T, uint64_t k> struct Divisor {\n static constexpr\
    \ T f(uint64_t p, short e) {\n  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (uint64_t\
    \ kk= k; kk; kk>>= 1, b*= b)\n   if (kk & 1) pk*= b;\n  for (short i= 0; i <=\
    \ e; i++, pkpw*= pk) ret+= pkpw;\n  return ret;\n }\n static std::vector<T> poly()\
    \ {\n  std::vector<T> ret(k + 1, 0);\n  return ret[0]+= 1, ret[k]+= 1, ret;\n\
    \ }\n};\ntemplate <class T> struct Dedekind {\n static constexpr T f(uint64_t\
    \ p, short e) {\n  T ret= p + 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n\
    \ }\n static std::vector<T> poly() { return {1, 1}; }\n};\n}  // namespace mul\n\
    namespace add {\ntemplate <class T> struct BigOmega {  // the total number of\
    \ prime factors of n\n static constexpr T f(uint64_t, short e) { return e; }\n\
    \ static std::vector<T> poly() { return {1}; }\n};\ntemplate <class T> struct\
    \ LittleOmega {  // the total number of different prime factors of n\n static\
    \ constexpr T f(uint64_t, short) { return 1; }\n static std::vector<T> poly()\
    \ { return {1}; }\n};\ntemplate <class T> struct Sopfr {  // the sum of primes\
    \ dividing n counting multiplicity\n static constexpr T f(uint64_t p, short e)\
    \ { return p * e; }\n static std::vector<T> poly() { return {0, 1}; }\n};\ntemplate\
    \ <class T> struct Sopf {  // the sum of the distinct primes dividing n\n static\
    \ constexpr T f(uint64_t p, short) { return p; }\n static std::vector<T> poly()\
    \ { return {0, 1}; }\n};\n}  // namespace add\n}\n#line 6 \"test/atcoder/abc172_d.numth.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using namespace famous_arithmetic_functions;\n int N;\n cin >> N;\n auto d=\
    \ multiplicative_table<long long>(N, mul::Divisor<int, 0>::f);\n long long ans=\
    \ 0;\n for (long long i= 1; i <= N; i++) ans+= d[i] * i;\n cout << ans << '\\\
    n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n//\
    \ O(N)\n#include <iostream>\n#include \"src/NumberTheory/tables.hpp\"\n#include\
    \ \"src/NumberTheory/famous_arithmetic_functions.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using namespace\
    \ famous_arithmetic_functions;\n int N;\n cin >> N;\n auto d= multiplicative_table<long\
    \ long>(N, mul::Divisor<int, 0>::f);\n long long ans= 0;\n for (long long i= 1;\
    \ i <= N; i++) ans+= d[i] * i;\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/NumberTheory/tables.hpp
  - src/NumberTheory/enumerate_primes.hpp
  - src/Internal/ListRange.hpp
  - src/NumberTheory/famous_arithmetic_functions.hpp
  isVerificationFile: true
  path: test/atcoder/abc172_d.numth.test.cpp
  requiredBy: []
  timestamp: '2024-02-06 21:31:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc172_d.numth.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc172_d.numth.test.cpp
- /verify/test/atcoder/abc172_d.numth.test.cpp.html
title: test/atcoder/abc172_d.numth.test.cpp
---
