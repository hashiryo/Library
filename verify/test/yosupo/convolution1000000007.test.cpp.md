---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/convolution1000000007.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/convolution1000000007.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 01:13:46+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod_1000000007">https://judge.yosupo.jp/problem/convolution_mod_1000000007</a>


## Depends on

* :question: <a href="../../../library/src/Math/FormalPowerSeries.hpp.html">形式的冪級数</a>
* :question: <a href="../../../library/src/Math/ModInt.hpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Math/FormalPowerSeries.hpp"
#include "src/Math/ModInt.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  using Mint = ModInt<int(1e9 + 7)>;
  using FPS = FormalPowerSeries<Mint>;
  FPS a(N), b(M);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int j = 0; j < M; j++) cin >> b[j];
  auto c = a * b;
  for (int k = 0; k < N + M - 1; k++) {
    cout << c[k] << (k < N + M - 2 ? " " : "\n");
  }
  cout << flush;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/convolution1000000007.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/Math/FormalPowerSeries.hpp"
/**
 * @title 形式的冪級数
 * @category 数学
 *  mod=998244353とかでない素数modのModInt<mod>でも使える
 *  nttの配列のサイズに注意(REの原因になりがち)
 */
// verify用: https://loj.ac/problem/150

#ifndef call_from_test
#line 11 "src/Math/FormalPowerSeries.hpp"
using namespace std;
#endif

namespace ntt {
template <uint64_t mod, uint64_t prim_root>
class Mod64 {
 private:
  using u128 = __uint128_t;
  static constexpr uint64_t mul_inv(uint64_t n, int e = 6, uint64_t x = 1) {
    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));
  }

 public:
  static constexpr uint64_t inv = mul_inv(mod, 6, 1);
  static constexpr uint64_t r2 = -u128(mod) % mod;
  static constexpr int level = __builtin_ctzll(mod - 1);
  static_assert(inv * mod == 1, "invalid 1/M modulo 2^64.");
  Mod64() {}
  Mod64(uint64_t n) : x(init(n)){};
  static uint64_t modulo() { return mod; }
  static uint64_t init(uint64_t w) { return reduce(u128(w) * r2); }
  static uint64_t reduce(const u128 w) {
    return uint64_t(w >> 64) + mod - ((u128(uint64_t(w) * inv) * mod) >> 64);
  }
  static Mod64 omega() { return Mod64(prim_root).pow((mod - 1) >> level); }
  Mod64 &operator+=(Mod64 rhs) {
    this->x += rhs.x;
    return *this;
  }
  Mod64 &operator-=(Mod64 rhs) {
    this->x += 2 * mod - rhs.x;
    return *this;
  }
  Mod64 &operator*=(Mod64 rhs) {
    this->x = reduce(u128(this->x) * rhs.x);
    return *this;
  }
  Mod64 operator+(Mod64 rhs) const { return Mod64(*this) += rhs; }
  Mod64 operator-(Mod64 rhs) const { return Mod64(*this) -= rhs; }
  Mod64 operator*(Mod64 rhs) const { return Mod64(*this) *= rhs; }
  uint64_t get() const { return reduce(this->x) % mod; }
  void set(uint64_t n) const { this->x = n; }
  Mod64 pow(uint64_t exp) const {
    Mod64 ret = Mod64(1);
    for (Mod64 base = *this; exp; exp >>= 1, base *= base)
      if (exp & 1) ret *= base;
    return ret;
  }
  Mod64 inverse() const { return pow(mod - 2); }
  uint64_t x;
};
template <typename mod_t>
void convolute(mod_t *A, int s1, mod_t *B, int s2, bool cyclic = false) {
  int s = (cyclic ? max(s1, s2) : s1 + s2 - 1);
  int size = 1;
  while (size < s) size <<= 1;
  mod_t roots[mod_t::level] = {mod_t::omega()};
  for (int i = 1; i < mod_t::level; i++) roots[i] = roots[i - 1] * roots[i - 1];
  fill(A + s1, A + size, 0);
  ntt_dit4(A, size, 1, roots);
  if (A == B && s1 == s2) {
    for (int i = 0; i < size; i++) A[i] *= A[i];
  } else {
    fill(B + s2, B + size, 0);
    ntt_dit4(B, size, 1, roots);
    for (int i = 0; i < size; i++) A[i] *= B[i];
  }
  ntt_dit4(A, size, -1, roots);
  mod_t inv = mod_t(size).inverse();
  for (int i = 0; i < (cyclic ? size : s); i++) A[i] *= inv;
}
template <typename mod_t>
void rev_permute(mod_t *A, int n) {
  int r = 0, nh = n >> 1;
  for (int i = 1; i < n; i++) {
    int h = nh;
    while (!((r ^= h) & h)) h >>= 1;
    if (r > i) swap(A[i], A[r]);
  }
}
template <typename mod_t>
void ntt_dit4(mod_t *A, int n, int sign, mod_t *roots) {
  rev_permute(A, n);
  int logn = __builtin_ctz(n);
  if (logn & 1)
    for (int i = 0; i < n; i += 2) {
      mod_t a = A[i], b = A[i + 1];
      A[i] = a + b, A[i + 1] = a - b;
    }
  mod_t imag = roots[mod_t::level - 2];
  if (sign < 0) imag = imag.inverse();
  mod_t one = mod_t(1);
  for (int e = 2 + (logn & 1); e < logn + 1; e += 2) {
    const int m = 1 << e;
    const int m4 = m >> 2;
    mod_t dw = roots[mod_t::level - e];
    if (sign < 0) dw = dw.inverse();
    const int block_size = max(m, (1 << 15) / int(sizeof(A[0])));
    for (int k = 0; k < n; k += block_size) {
      mod_t w = one, w2 = one, w3 = one;
      for (int j = 0; j < m4; j++) {
        for (int i = k + j; i < k + block_size; i += m) {
          mod_t a0 = A[i + m4 * 0] * one, a2 = A[i + m4 * 1] * w2;
          mod_t a1 = A[i + m4 * 2] * w, a3 = A[i + m4 * 3] * w3;
          mod_t t02 = a0 + a2, t13 = a1 + a3;
          A[i + m4 * 0] = t02 + t13, A[i + m4 * 2] = t02 - t13;
          t02 = a0 - a2, t13 = (a1 - a3) * imag;
          A[i + m4 * 1] = t02 + t13, A[i + m4 * 3] = t02 - t13;
        }
        w *= dw, w2 = w * w, w3 = w2 * w;
      }
    }
  }
}
const int size = 1 << 22;
using m64_1 = ntt::Mod64<34703335751681, 3>;
using m64_2 = ntt::Mod64<35012573396993, 3>;
m64_1 f1[size], g1[size];
m64_2 f2[size], g2[size];

}  // namespace ntt

template <typename mint>
struct FormalPowerSeries : vector<mint> {
  using FPS = FormalPowerSeries;
  using vector<mint>::vector;

 public:
  void shrink() {
    while (this->size() && this->back() == mint(0)) this->pop_back();
  }
  FPS part(int beg, int end = -1) const {
    if (end < 0) end = beg, beg = 0;
    FPS ret(end - beg);
    for (int i = beg; i < min(end, int(this->size())); i++)
      ret[i - beg] = (*this)[i];
    return ret;
  }
  FPS pre(int sz) const {
    FPS ret(this->begin(), this->begin() + min(sz, int(this->size())));
    ret.shrink();
    return ret;
  }
  size_t ctz() const {
    for (size_t i = 0; i < this->size(); i++)
      if ((*this)[i] != mint(0)) return i;
    return this->size();
  }
  FPS operator>>(size_t size) const {
    if (this->size() <= size) return {};
    return FPS(this->begin() + size, this->end());
  }
  FPS operator<<(size_t size) const {
    FPS ret(*this);
    ret.insert(ret.begin(), size, mint(0));
    return ret;
  }
  FPS rev() const { return FPS(this->rbegin(), this->rend()); }
  FPS operator-() {
    FPS ret(*this);
    for (int i = 0; i < (int)ret.size(); i++) ret[i] = -ret[i];
    return ret;
  }
  FPS &operator+=(const mint &v) {
    (*this)[0] += v;
    return *this;
  }
  FPS &operator-=(const mint &v) {
    (*this)[0] -= v;
    return *this;
  }
  FPS &operator*=(const mint &v) {
    for (size_t k = 0; k < this->size(); k++) (*this)[k] *= v;
    return *this;
  }
  FPS &operator/=(const mint &v) {
    *this *= mint(1) / v;
    return *this;
  }
  FPS &operator+=(const FPS &rhs) {
    if (this->size() < rhs.size()) this->resize(rhs.size());
    for (int i = 0; i < (int)rhs.size(); i++) (*this)[i] += rhs[i];
    return *this;
  }
  FPS &operator-=(const FPS &rhs) {
    if (this->size() < rhs.size()) this->resize(rhs.size());
    for (int i = 0; i < (int)rhs.size(); i++) (*this)[i] -= rhs[i];
    return *this;
  }
  FPS &operator*=(const FPS &rhs) {
    size_t f_min = this->ctz(), g_min = rhs.ctz();
    if (f_min == this->size() || g_min == rhs.size())
      return *this = FPS(this->size() + rhs.size());
    return *this = ((*this >> f_min).mul(rhs >> g_min) << (f_min + g_min));
  }
  FPS &operator/=(const FPS &rhs) {
    if (this->size() < rhs.size()) return *this = FPS();
    FPS frev = this->rev();
    FPS rrev = rhs.rev();
    if (rhs.size() < 1150) return *this = frev.divrem_rev_n(rrev).first.rev();
    FPS inv = rrev.inv(this->size() - rhs.size() + 1);
    return *this = frev.div_rev_pre(rrev, inv).rev();
  }
  FPS &operator%=(const FPS &rhs) {
    if (this->size() < rhs.size()) return *this;
    FPS frev = this->rev();
    FPS rrev = rhs.rev();
    if (rhs.size() < 1150) return *this = frev.divrem_rev_n(rrev).second.rev();
    FPS inv = rrev.inv(frev.size() - rhs.size() + 1);
    return *this = frev.rem_rev_pre(rrev, inv).rev();
  }
  FPS operator+(const mint &v) const { return FPS(*this) += v; }     // O(1)
  FPS operator-(const mint &v) const { return FPS(*this) -= v; }     // O(1)
  FPS operator*(const mint &v) const { return FPS(*this) *= v; }     // O(N)
  FPS operator/(const mint &v) const { return FPS(*this) /= v; }     // O(N)
  FPS operator+(const FPS &rhs) const { return FPS(*this) += rhs; }  // O(N)
  FPS operator-(const FPS &rhs) const { return FPS(*this) -= rhs; }  // O(N)
  FPS operator*(const FPS &rhs) const { return FPS(*this) *= rhs; }  // O(NlogN)
  FPS operator/(const FPS &rhs) const { return FPS(*this) /= rhs; }  // O(NlogN)
  FPS operator%(const FPS &rhs) const { return FPS(*this) %= rhs; }  // O(NlogN)
  mint eval(mint x) const {
    mint res, w = 1;
    for (auto &v : *this) res += w * v, w *= x;
    return res;
  }

 public:
  static mint mod_sqrt(mint x) {
    if (x == 0 || mint::modulo() == 2) return x;
    if (x.pow((mint::modulo() - 1) >> 1) != 1) return mint(0);  // no solutions
    mint b(2);
    mint w(b * b - x);
    while (w.pow((mint::modulo() - 1) >> 1) == 1) b += mint(1), w = b * b - x;
    auto mul = [&](pair<mint, mint> u, pair<mint, mint> v) {
      mint a = (u.first * v.first + u.second * v.second * w);
      mint b = (u.first * v.second + u.second * v.first);
      return make_pair(a, b);
    };
    unsigned e = (mint::modulo() + 1) >> 1;
    auto ret = make_pair(mint(1), mint(0));
    for (auto bs = make_pair(b, mint(1)); e; e >>= 1, bs = mul(bs, bs))
      if (e & 1) ret = mul(ret, bs);
    return ret.first.get() * 2 < mint::modulo() ? ret.first : -ret.first;
  }

 private:
  static void mul2(const FPS &f, const FPS &g, bool cyclic = false) {
    using namespace ntt;
    for (size_t i = 0; i < f.size(); i++)
      f1[i] = f[i].get(), f2[i] = f[i].get();
    if (&f == &g) {
      convolute(f1, f.size(), f1, f.size(), cyclic);
      convolute(f2, f.size(), f2, f.size(), cyclic);
    } else {
      for (size_t i = 0; i < g.size(); i++)
        g1[i] = g[i].get(), g2[i] = g[i].get();
      convolute(f1, f.size(), g1, g.size(), cyclic);
      convolute(f2, f.size(), g2, g.size(), cyclic);
    }
  }
  static FPS mul_crt(int beg, int end) {
    using namespace ntt;
    auto inv = m64_2(m64_1::modulo()).inverse();
    mint mod1(m64_1::modulo());
    FPS ret(end - beg);
    for (int i = 0; i < (int)ret.size(); i++) {
      uint64_t r1 = f1[i + beg].get(), r2 = f2[i + beg].get();
      ret[i] = mint(r1)
               + mint((m64_2(r2 + m64_2::modulo() - r1) * inv).get()) * mod1;
    }
    return ret;
  }
  FPS mul_n(const FPS &g) const {
    if (this->size() == 0 || g.size() == 0) return FPS();
    FPS ret(this->size() + g.size() - 1, 0);
    for (size_t i = 0; i < this->size(); i++)
      for (size_t j = 0; j < g.size(); j++) ret[i + j] += (*this)[i] * g[j];
    return ret;
  }
  FPS mul(const FPS &g) const {
    if (this->size() == 0 || g.size() == 0) return FPS();
    if (this->size() + g.size() < 750 || this->size() < 8 || g.size() < 8)
      return mul_n(g);
    const FPS &f = *this;
    mul2(f, g, false);
    return mul_crt(0, int(f.size() + g.size() - 1));
  }
  FPS middle_product(const FPS &g) const {
    const FPS &f = *this;
    if (f.size() == 0 || g.size() == 0) return FPS();
    mul2(f, g, true);
    return mul_crt(f.size(), g.size());
  }
  FPS mul_cyclically(const FPS &g) const {
    const auto &f = *this;
    if (f.size() == 0 || g.size() == 0) return FPS();
    mul2(f, g, true);
    int s = max(f.size(), g.size()), size = 1;
    while (size < s) size <<= 1;
    return mul_crt(0, size);
  }
  static FPS sub_mul(const FPS &f, const FPS &q, const FPS &d) {
    size_t sq = q.size();
    FPS p = q.mul_cyclically(d);
    size_t mask = p.size() - 1;
    for (size_t i = 0; i < sq; i++) p[i & mask] -= f[i & mask];
    FPS r = f.part(sq, f.size());
    for (size_t i = 0; i < r.size(); i++) r[i] -= p[(sq + i) & mask];
    return r;
  }
  FPS comp_dc(const FPS &g, int deg = -1) const {
    if (deg < 0) deg = max(this->size(), g.size());
    if (this->size() <= 1) return *this;
    if (g.size() == 0) return FPS({(*this)[0]});
    if (g.size() == 1) return FPS({eval(g[0])});
    if (this->size() <= 8) {
      FPS ret = {this->back()};
      for (int i = this->size() - 2; i >= 0; i--)
        ret = (ret * g).pre(deg) + (*this)[i];
      return ret;
    }
    vector<FPS> pw(deg);
    pw[0] = {1};
    pw[1] = g;
    int m = 2;
    for (; m < deg; m *= 2) pw[m] = (pw[m / 2] * pw[m / 2]).pre(deg);
    function<FPS(FPS, int)> rec = [&](FPS p, size_t k) {
      p.shrink();
      if (p.size() <= 1) return p;
      while (k >= p.size()) k /= 2;
      FPS q(begin(p) + k, end(p));
      p.resize(k);
      FPS ret = rec(p, k);
      if (pw[k].size() > 0) ret = (ret + rec(q, k) * pw[k]).pre(deg);
      return ret;
    };
    return rec(*this, m);
  }

 public:
  pair<FPS, FPS> divrem_rev_n(const FPS &brev) {
    FPS frev(*this);
    if (frev.size() < brev.size()) return make_pair(FPS(), frev);
    int sq = frev.size() - brev.size() + 1;
    FPS qrev(sq, 0);
    mint inv = brev[0].inverse();
    for (size_t i = 0; i < qrev.size(); ++i) {
      qrev[i] = frev[i] * inv;
      for (size_t j = 0; j < brev.size(); ++j) frev[j + i] -= brev[j] * qrev[i];
    }
    return {qrev, frev.part(sq, frev.size())};
  }
  FPS div_rev_pre(const FPS &brev, const FPS &brevinv) const {
    if (this->size() < brev.size()) return FPS();
    size_t sq = this->size() - brev.size() + 1;
    assert(this->size() >= sq && brevinv.size() >= sq);
    return (this->part(sq) * brevinv.part(sq)).part(sq);
  }
  FPS rem_rev_pre(const FPS &brev, const FPS &brevinv) const {
    if (this->size() < brev.size()) return FPS(*this);
    return sub_mul(*this, div_rev_pre(brev, brevinv), brev);
  }

 public:
  FPS inv(int deg = -1) const {  // O(NlogN)
    assert((*this)[0] != mint(0));
    if (deg < 0) deg = this->size();
    FPS ret(1, mint(1) / (*this)[0]);
    for (int e = 1, ne; e < deg; e = ne) {
      ne = min(2 * e, deg);
      FPS h = ret.part(ne - e) * -ret.middle_product(this->part(ne));
      for (int i = e; i < ne; i++) ret.push_back(h[i - e]);
    }
    return ret;
  }
  FPS diff() const {  // O(N)
    FPS ret(max(0, int(this->size() - 1)));
    for (size_t i = 1; i < this->size(); i++) ret[i - 1] = (*this)[i] * mint(i);
    return ret;
  }
  FPS inte() const {  // O(N)
    FPS ret(this->size() + 1);
    ret[0] = mint(0);
    for (size_t i = 0; i < this->size(); i++)
      ret[i + 1] = (*this)[i] / mint(i + 1);
    return ret;
  }
  FPS log(int deg = -1) const {  // O(NlogN)
    assert((*this)[0] == mint(1));
    if (deg < 0) deg = this->size();
    return ((this->diff() * this->inv(deg)).part(deg - 1)).inte();
  }
  FPS exp(int deg = -1) const {  // O(NlogN)
    assert((*this)[0] == mint(0));
    if (deg < 0) deg = this->size();
    FPS ret({1, 1 < this->size() ? (*this)[1] : 0}), retinv(1, 1);
    FPS f = this->diff();
    FPS retdif = ret.diff();
    for (int e = 1, ne = 2, nne; ne < deg; e = ne, ne = nne) {
      nne = min(2 * ne, deg);
      FPS h = retinv.part(ne - e) * -retinv.middle_product(ret);
      for (int i = e; i < ne; i++) retinv.push_back(h[i - e]);
      FPS a = ret * f.part(nne) - retdif;
      FPS c = (retinv * a.part(nne)).inte();
      h = ret.middle_product(c.part(nne));
      for (int i = ne; i < nne; i++) {
        ret.push_back(h[i - ne]);
        retdif.push_back(mint(i) * h[i - ne]);
      }
    }
    return ret;
  }
  pair<FPS, FPS> cos_and_sin(int deg = -1) const {  // O(NlogN)
    if (deg < 0) deg = this->size();
    mint i = mod_sqrt(-1);
    FPS a = (*this * i).exp(deg), b = (*this * (-i)).exp(deg);
    return make_pair((a + b) / mint(2), (a - b) / (mint(2) * i));
  }
  FPS sqrt(int deg = -1) const {  // O(NlogN)
    if (deg < 0) deg = this->size();
    int xpw = this->ctz();
    if (xpw == this->size()) return FPS(deg, 0);
    if (xpw & 1) return FPS();  // no solutions
    if (deg - xpw / 2 <= 0) return FPS(deg, 0);
    mint sqr = mod_sqrt((*this)[xpw]);
    if (sqr * sqr != (*this)[xpw]) return FPS();  // no solutions
    FPS ret({sqr});
    mint inv2 = mint(1) / mint(2);
    for (int i = 1; i < deg - xpw / 2; i <<= 1)
      (ret += (this->part(xpw, xpw + i * 2) * ret.inv(i * 2)).part(i * 2))
          *= inv2;
    return (ret << (xpw / 2)).part(deg);
  }
  FPS pow(uint64_t k, int deg = -1) const {  // O(NlogN)
    if (deg < 0) deg = this->size();
    int i = this->ctz();
    if (i == this->size() || i * k > deg) return FPS(deg, 0);
    int n = deg - i * k;
    mint inv = mint(1) / (*this)[i];
    FPS ret = ((((*this) >> i) * inv).log(n) * k).exp(n) * (*this)[i].pow(k);
    return (ret << (i * k)).part(deg);
  }
  FPS shift(mint c) const {  // O(NlogN)
    int n = this->size();
    FPS ret(n), p(n);
    mint fact = 1, cpw = 1;
    for (int i = 0; i < n; fact *= (++i)) ret[i] = (*this)[i] * fact;
    mint finv = mint(n) / fact;
    for (int i = n; i > 0; i--) p[i - 1] = i == n ? finv : p[i] * i;
    for (int i = 0; i < n; i++, cpw *= c) p[i] *= cpw;
    ret = (ret.rev() * p).part(n).rev();
    for (int i = n - 1; i >= 0; finv *= (i--)) ret[i] *= finv;
    return ret;
  }
  FPS comp(const FPS &g, int deg = -1) const {  // O((NlogN)^(1.5)?)
    if (deg < 0) deg = max(this->size(), g.size());
    if (this->size() <= 1) return this->part(deg);
    if (g.size() == 0) return FPS({(*this)[0]}).part(deg);
    if (g.size() == 1) return FPS({eval(g[0])}).part(deg);
    size_t k = (int)::sqrt(deg) + 1;
    if (k >= g.size() || this->size() < 100 || g.ctz() >= k)
      return comp_dc(g, deg).part(deg);
    FPS p = g.pre(k);
    FPS q = g - p, fp = comp_dc(p, deg), qpw = {1}, tmp = p.diff();
    int xpw = tmp.ctz();
    tmp = (tmp >> xpw).inv(deg);
    mint fact = 1;
    FPS ret;
    for (int i = 0, b = deg / k + 1; i < b; i++) {
      ret += (fp * qpw).pre(deg) / fact;
      fp = ((fp.diff() >> xpw) * tmp).pre(deg);
      qpw = (qpw * q).pre(deg);
      fact *= i + 1;
    }
    return ret.part(deg);
  }
};
#line 1 "src/Math/ModInt.hpp"
/**
 * @title ModInt
 * @category 数学
 */

#ifndef call_from_test
#line 8 "src/Math/ModInt.hpp"
using namespace std;
#endif

template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) { return *this *= p.inverse(); }
  ModInt operator-() const { return ModInt() - *this; }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
    return ModInt(u);
  }
  ModInt pow(int64_t e) const {
    ModInt ret(1);
    for (ModInt b = *this; e; e >>= 1, b *= b)
      if (e & 1) ret *= b;
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int modulo() { return mod; }
  int get() const { return x; }
};
#line 9 "test/yosupo/convolution1000000007.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  using Mint = ModInt<int(1e9 + 7)>;
  using FPS = FormalPowerSeries<Mint>;
  FPS a(N), b(M);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int j = 0; j < M; j++) cin >> b[j];
  auto c = a * b;
  for (int k = 0; k < N + M - 1; k++) {
    cout << c[k] << (k < N + M - 2 ? " " : "\n");
  }
  cout << flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

