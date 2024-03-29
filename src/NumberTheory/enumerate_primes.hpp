#pragma once
#include <algorithm>
#include <cstdint>
#include "src/Internal/ListRange.hpp"
namespace nt_internal {
using namespace std;
vector<int> ps, lf;
void sieve(int N) {
 static int n= 2;
 if (n > N) return;
 if (lf.resize((N + 1) >> 1); n == 2) ps.push_back(n++);
 int M= (N - 1) / 2;
 for (int j= 1, e= ps.size(); j < e; ++j) {
  int p= ps[j];
  if (int64_t(p) * p > N) break;
  for (auto k= int64_t(p) * max(n / p / 2 * 2 + 1, p) / 2; k <= M; k+= p) lf[k]+= p * !lf[k];
 }
 for (; n <= N; n+= 2)
  if (!lf[n >> 1]) {
   ps.push_back(lf[n >> 1]= n);
   for (auto j= int64_t(n) * n / 2; j <= M; j+= n) lf[j]+= n * !lf[j];
  }
}
ConstListRange<int> enumerate_primes() { return {ps.cbegin(), ps.cend()}; }
ConstListRange<int> enumerate_primes(int N) {
 sieve(N);
 return {ps.cbegin(), upper_bound(ps.cbegin(), ps.cend(), N)};
}
int least_prime_factor(int n) { return n & 1 ? sieve(n), lf[(n >> 1)] : 2; }
// f(p,e) := f(p^e)
template <class T, class F> vector<T> completely_multiplicative_table(int N, const F &f) {
 vector<T> ret(N + 1);
 sieve(N);
 for (int n= 3, i= 1; n <= N; n+= 2, ++i) ret[n]= lf[i] == n ? f(n, 1) : ret[lf[i]] * ret[n / lf[i]];
 if (int n= 4; 2 <= N)
  for (T t= ret[2]= f(2, 1); n <= N; n+= 2) ret[n]= t * ret[n >> 1];
 return ret[1]= 1, ret;
}
}
using nt_internal::enumerate_primes, nt_internal::least_prime_factor, nt_internal::completely_multiplicative_table;
// O(N log k / log N + N)
template <class T> static std::vector<T> pow_table(int N, uint64_t k) {
 if (k == 0) return std::vector<T>(N + 1, 1);
 auto f= [k](int p, int) {
  T ret= 1, b= p;
  for (auto e= k;; b*= b) {
   if (e & 1) ret*= b;
   if (!(e>>= 1)) return ret;
  }
 };
 return completely_multiplicative_table<T>(N, f);
}