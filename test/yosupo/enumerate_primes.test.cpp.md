---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u3060\u3051\u6301\u3063\u3066\u304A\u304F\
      \u3084\u3064"
  - icon: ':question:'
    path: src/NumberTheory/enumerate_primes.hpp
    title: "\u7D20\u6570\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo/enumerate_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include <iostream>\n\
    #include <vector>\n#line 2 \"src/NumberTheory/enumerate_primes.hpp\"\n#include\
    \ <algorithm>\n#include <cstdint>\n#line 3 \"src/Internal/ListRange.hpp\"\n#include\
    \ <iterator>\ntemplate <class T> struct ListRange {\n using Iterator= typename\
    \ std::vector<T>::iterator;\n Iterator bg, ed;\n Iterator begin() const { return\
    \ bg; }\n Iterator end() const { return ed; }\n size_t size() const { return std::distance(bg,\
    \ ed); }\n T &operator[](int i) const { return bg[i]; }\n friend std::ostream\
    \ &operator<<(std::ostream &os, const ListRange &r) {\n  return os << '[' << r.bg[0],\
    \ std::for_each(r.bg + 1, r.ed, [&os](const T &x) { os << \", \" << x; }), os\
    \ << ']';\n }\n};\ntemplate <class T> struct ConstListRange {\n using Iterator=\
    \ typename std::vector<T>::const_iterator;\n Iterator bg, ed;\n Iterator begin()\
    \ const { return bg; }\n Iterator end() const { return ed; }\n size_t size() const\
    \ { return std::distance(bg, ed); }\n const T &operator[](int i) const { return\
    \ bg[i]; }\n friend std::ostream &operator<<(std::ostream &os, const ConstListRange\
    \ &r) {\n  return os << '[' << r.bg[0], std::for_each(r.bg + 1, r.ed, [&os](const\
    \ T &x) { os << \", \" << x; }), os << ']';\n }\n};\n#line 5 \"src/NumberTheory/enumerate_primes.hpp\"\
    \nnamespace nt_internal {\nusing namespace std;\nvector<int> ps, lf;\nvoid sieve(int\
    \ N) {\n static int n= 2;\n if (n > N) return;\n if (lf.resize((N + 1) >> 1);\
    \ n == 2) ps.push_back(n++);\n int M= (N - 1) / 2;\n for (int j= 1, e= ps.size();\
    \ j < e; ++j) {\n  int p= ps[j];\n  if (int64_t(p) * p > N) break;\n  for (auto\
    \ k= int64_t(p) * max(n / p / 2 * 2 + 1, p) / 2; k <= M; k+= p) lf[k]+= p * !lf[k];\n\
    \ }\n for (; n <= N; n+= 2)\n  if (!lf[n >> 1]) {\n   ps.push_back(lf[n >> 1]=\
    \ n);\n   for (auto j= int64_t(n) * n / 2; j <= M; j+= n) lf[j]+= n * !lf[j];\n\
    \  }\n}\nConstListRange<int> enumerate_primes() { return {ps.cbegin(), ps.cend()};\
    \ }\nConstListRange<int> enumerate_primes(int N) {\n sieve(N);\n return {ps.cbegin(),\
    \ upper_bound(ps.cbegin(), ps.cend(), N)};\n}\nint least_prime_factor(int n) {\
    \ return n & 1 ? sieve(n), lf[(n >> 1)] : 2; }\n// f(p,e) := f(p^e)\ntemplate\
    \ <class T, class F> vector<T> completely_multiplicative_table(int N, const F\
    \ &f) {\n vector<T> ret(N + 1);\n sieve(N);\n for (int n= 3, i= 1; n <= N; n+=\
    \ 2, ++i) ret[n]= lf[i] == n ? f(n, 1) : ret[lf[i]] * ret[n / lf[i]];\n if (int\
    \ n= 4; 2 <= N)\n  for (T t= ret[2]= f(2, 1); n <= N; n+= 2) ret[n]= t * ret[n\
    \ >> 1];\n return ret[1]= 1, ret;\n}\n}\nusing nt_internal::enumerate_primes,\
    \ nt_internal::least_prime_factor, nt_internal::completely_multiplicative_table;\n\
    // O(N log k / log N + N)\ntemplate <class T> static std::vector<T> pow_table(int\
    \ N, uint64_t k) {\n if (k == 0) return std::vector<T>(N + 1, 1);\n auto f= [k](int\
    \ p, int) {\n  T ret= 1, b= p;\n  for (auto e= k;; b*= b) {\n   if (e & 1) ret*=\
    \ b;\n   if (!(e>>= 1)) return ret;\n  }\n };\n return completely_multiplicative_table<T>(N,\
    \ f);\n}\n#line 5 \"test/yosupo/enumerate_primes.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, A, B;\n\
    \ cin >> N >> A >> B;\n auto ps= enumerate_primes(N);\n int pi= ps.size();\n vector<int>\
    \ ans;\n for (int i= 0; A * i + B < pi; i++) ans.push_back(ps[A * i + B]);\n int\
    \ X= ans.size();\n cout << pi << \" \" << X << '\\n';\n for (int i= 0; i < X;\
    \ i++) cout << ans[i] << \" \\n\"[i == X - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/NumberTheory/enumerate_primes.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, A, B;\n cin >> N >> A >> B;\n auto ps= enumerate_primes(N);\n int pi=\
    \ ps.size();\n vector<int> ans;\n for (int i= 0; A * i + B < pi; i++) ans.push_back(ps[A\
    \ * i + B]);\n int X= ans.size();\n cout << pi << \" \" << X << '\\n';\n for (int\
    \ i= 0; i < X; i++) cout << ans[i] << \" \\n\"[i == X - 1];\n return 0;\n}"
  dependsOn:
  - src/NumberTheory/enumerate_primes.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2024-02-12 17:38:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_primes.test.cpp
- /verify/test/yosupo/enumerate_primes.test.cpp.html
title: test/yosupo/enumerate_primes.test.cpp
---
