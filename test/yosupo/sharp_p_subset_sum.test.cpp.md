---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sharp_p_subset_sum
    links:
    - https://judge.yosupo.jp/problem/sharp_p_subset_sum
  bundledCode: "#line 1 \"test/yosupo/sharp_p_subset_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"src/Math/FormalPowerSeries.hpp\"\
    \n/**\n * @title \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @category \u6570\u5B66\
    \n */\n// verify\u7528: https://loj.ac/problem/150\n\n#ifndef call_from_test\n\
    #line 9 \"src/Math/FormalPowerSeries.hpp\"\nusing namespace std;\n#endif\n\nnamespace\
    \ ntt {\ntemplate <uint64_t mod, uint64_t prim_root>\nclass UnsafeMod {\n private:\n\
    \  using u128 = __uint128_t;\n  static constexpr uint64_t mul_inv(uint64_t n,\
    \ int e = 6, uint64_t x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x *\
    \ (2 - x * n));\n  }\n\n public:\n  static constexpr uint64_t inv = mul_inv(mod,\
    \ 6, 1);\n  static constexpr uint64_t r2 = -u128(mod) % mod;\n  static constexpr\
    \ int level = __builtin_ctzll(mod - 1);\n  UnsafeMod() {}\n  UnsafeMod(uint64_t\
    \ n) : x(init(n)){};\n  static uint64_t modulo() { return mod; }\n  static uint64_t\
    \ init(uint64_t w) { return reduce(u128(w) * r2); }\n  static uint64_t reduce(const\
    \ u128 w) {\n    return uint64_t(w >> 64) + mod - ((u128(uint64_t(w) * inv) *\
    \ mod) >> 64);\n  }\n  static UnsafeMod omega() {\n    return UnsafeMod(prim_root).pow((mod\
    \ - 1) >> level);\n  }\n  UnsafeMod &operator+=(UnsafeMod rhs) {\n    this->x\
    \ += rhs.x;\n    return *this;\n  }\n  UnsafeMod &operator-=(UnsafeMod rhs) {\n\
    \    this->x += 2 * mod - rhs.x;\n    return *this;\n  }\n  UnsafeMod &operator*=(UnsafeMod\
    \ rhs) {\n    this->x = reduce(u128(this->x) * rhs.x);\n    return *this;\n  }\n\
    \  UnsafeMod operator+(UnsafeMod rhs) const { return UnsafeMod(*this) += rhs;\
    \ }\n  UnsafeMod operator-(UnsafeMod rhs) const { return UnsafeMod(*this) -= rhs;\
    \ }\n  UnsafeMod operator*(UnsafeMod rhs) const { return UnsafeMod(*this) *= rhs;\
    \ }\n  uint64_t get() const { return reduce(this->x) % mod; }\n  void set(uint64_t\
    \ n) const { this->x = n; }\n  UnsafeMod pow(uint64_t exp) const {\n    UnsafeMod\
    \ ret = UnsafeMod(1);\n    for (UnsafeMod base = *this; exp; exp >>= 1, base *=\
    \ base)\n      if (exp & 1) ret *= base;\n    return ret;\n  }\n  UnsafeMod inverse()\
    \ const { return pow(mod - 2); }\n};\ntemplate <typename mod_t>\nvoid convolute(mod_t\
    \ *A, int s1, mod_t *B, int s2, bool cyclic = false) {\n  int s = (cyclic ? max(s1,\
    \ s2) : s1 + s2 - 1);\n  int size = 1;\n  while (size < s) size <<= 1;\n  mod_t\
    \ roots[mod_t::level] = {mod_t::omega()};\n  for (int i = 1; i < mod_t::level;\
    \ i++) roots[i] = roots[i - 1] * roots[i - 1];\n  fill(A + s1, A + size, 0);\n\
    \  ntt_dit4(A, size, 1, roots);\n  if (A == B && s1 == s2) {\n    for (int i =\
    \ 0; i < size; i++) A[i] *= A[i];\n  } else {\n    fill(B + s2, B + size, 0);\n\
    \    ntt_dit4(B, size, 1, roots);\n    for (int i = 0; i < size; i++) A[i] *=\
    \ B[i];\n  }\n  ntt_dit4(A, size, -1, roots);\n  mod_t inv = mod_t(size).inverse();\n\
    \  for (int i = 0; i < (cyclic ? size : s); i++) A[i] *= inv;\n}\ntemplate <typename\
    \ mod_t>\nvoid rev_permute(mod_t *A, int n) {\n  int r = 0, nh = n >> 1;\n  for\
    \ (int i = 1; i < n; i++) {\n    int h = nh;\n    while (!((r ^= h) & h)) h >>=\
    \ 1;\n    if (r > i) swap(A[i], A[r]);\n  }\n}\ntemplate <typename mod_t>\nvoid\
    \ ntt_dit4(mod_t *A, int n, int sign, mod_t *roots) {\n  rev_permute(A, n);\n\
    \  int logn = __builtin_ctz(n);\n  if (logn & 1)\n    for (int i = 0; i < n; i\
    \ += 2) {\n      mod_t a = A[i], b = A[i + 1];\n      A[i] = a + b, A[i + 1] =\
    \ a - b;\n    }\n  mod_t imag = roots[mod_t::level - 2];\n  if (sign < 0) imag\
    \ = imag.inverse();\n  mod_t one = mod_t(1);\n  for (int e = 2 + (logn & 1); e\
    \ < logn + 1; e += 2) {\n    const int m = 1 << e;\n    const int m4 = m >> 2;\n\
    \    mod_t dw = roots[mod_t::level - e];\n    if (sign < 0) dw = dw.inverse();\n\
    \    const int block_size = max(m, (1 << 15) / int(sizeof(A[0])));\n    for (int\
    \ k = 0; k < n; k += block_size) {\n      mod_t w = one, w2 = one, w3 = one;\n\
    \      for (int j = 0; j < m4; j++) {\n        for (int i = k + j; i < k + block_size;\
    \ i += m) {\n          mod_t a0 = A[i + m4 * 0] * one, a2 = A[i + m4 * 1] * w2;\n\
    \          mod_t a1 = A[i + m4 * 2] * w, a3 = A[i + m4 * 3] * w3;\n          mod_t\
    \ t02 = a0 + a2, t13 = a1 + a3;\n          A[i + m4 * 0] = t02 + t13, A[i + m4\
    \ * 2] = t02 - t13;\n          t02 = a0 - a2, t13 = (a1 - a3) * imag;\n      \
    \    A[i + m4 * 1] = t02 + t13, A[i + m4 * 3] = t02 - t13;\n        }\n      \
    \  w *= dw, w2 = w * w, w3 = w2 * w;\n      }\n    }\n  }\n}\nconst int size =\
    \ 1 << 22;\nusing m64_1 = ntt::UnsafeMod<34703335751681, 3>;\nusing m64_2 = ntt::UnsafeMod<35012573396993,\
    \ 3>;\nm64_1 f1[size], g1[size];\nm64_2 f2[size], g2[size];\n\n}  // namespace\
    \ ntt\n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n\
    \  using FPS = FormalPowerSeries;\n  using vector<mint>::vector;\n\n public:\n\
    \  void shrink() {\n    while (this->size() && this->back() == mint(0)) this->pop_back();\n\
    \  }\n  FPS part(int beg, int end = -1) const {\n    if (end < 0) end = beg, beg\
    \ = 0;\n    FPS ret(end - beg);\n    for (int i = beg; i < min(end, int(this->size()));\
    \ i++)\n      ret[i - beg] = (*this)[i];\n    return ret;\n  }\n  FPS pre(int\
    \ sz) const {\n    FPS ret(this->begin(), this->begin() + min(sz, int(this->size())));\n\
    \    ret.shrink();\n    return ret;\n  }\n  size_t ctz() const {\n    for (size_t\
    \ i = 0; i < this->size(); i++)\n      if ((*this)[i] != mint(0)) return i;\n\
    \    return this->size();\n  }\n  FPS operator>>(size_t size) const {\n    if\
    \ (this->size() <= size) return {};\n    return FPS(this->begin() + size, this->end());\n\
    \  }\n  FPS operator<<(size_t size) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ size, mint(0));\n    return ret;\n  }\n  FPS rev() const { return FPS(this->rbegin(),\
    \ this->rend()); }\n  FPS operator-() {\n    FPS ret(*this);\n    for (int i =\
    \ 0; i < (int)ret.size(); i++) ret[i] = -ret[i];\n    return ret;\n  }\n  FPS\
    \ &operator+=(const mint &v) {\n    (*this)[0] += v;\n    return *this;\n  }\n\
    \  FPS &operator-=(const mint &v) {\n    (*this)[0] -= v;\n    return *this;\n\
    \  }\n  FPS &operator*=(const mint &v) {\n    for (size_t k = 0; k < this->size();\
    \ k++) (*this)[k] *= v;\n    return *this;\n  }\n  FPS &operator/=(const mint\
    \ &v) {\n    for (size_t k = 0; k < this->size(); k++) (*this)[k] /= v;\n    return\
    \ *this;\n  }\n  FPS &operator+=(const FPS &rhs) {\n    if (this->size() < rhs.size())\
    \ this->resize(rhs.size(), mint(0));\n    for (int i = 0; i < (int)rhs.size();\
    \ i++) (*this)[i] += rhs[i];\n    return *this;\n  }\n  FPS &operator-=(const\
    \ FPS &rhs) {\n    if (this->size() < rhs.size()) this->resize(rhs.size(), mint(0));\n\
    \    for (int i = 0; i < (int)rhs.size(); i++) (*this)[i] -= rhs[i];\n    return\
    \ *this;\n  }\n  FPS &operator*=(const FPS &rhs) {\n    size_t f_min = this->ctz(),\
    \ g_min = rhs.ctz();\n    if (f_min == this->size() || g_min == rhs.size())\n\
    \      return *this = FPS(this->size() + rhs.size());\n    return *this = ((*this\
    \ >> f_min).mul(rhs >> g_min) << (f_min + g_min));\n  }\n  FPS &operator/=(const\
    \ FPS &rhs) {\n    if (this->size() < rhs.size()) return *this = FPS();\n    FPS\
    \ frev = this->rev();\n    FPS rrev = rhs.rev();\n    if (rhs.size() < 1150) return\
    \ *this = frev.divrem_rev_n(rrev).first.rev();\n    FPS inv = rrev.inv(this->size()\
    \ - rhs.size() + 1);\n    return *this = frev.div_rev_pre(rrev, inv).rev();\n\
    \  }\n  FPS &operator%=(const FPS &rhs) {\n    if (this->size() < rhs.size())\
    \ return *this;\n    FPS frev = this->rev();\n    FPS rrev = rhs.rev();\n    if\
    \ (rhs.size() < 1150) return *this = frev.divrem_rev_n(rrev).second.rev();\n \
    \   FPS inv = rrev.inv(frev.size() - rhs.size() + 1);\n    return *this = frev.rem_rev_pre(rrev,\
    \ inv).rev();\n  }\n  FPS operator+(const mint &v) const { return FPS(*this) +=\
    \ v; }     // O(1)\n  FPS operator-(const mint &v) const { return FPS(*this) -=\
    \ v; }     // O(1)\n  FPS operator*(const mint &v) const { return FPS(*this) *=\
    \ v; }     // O(N)\n  FPS operator/(const mint &v) const { return FPS(*this) /=\
    \ v; }     // O(N)\n  FPS operator+(const FPS &rhs) const { return FPS(*this)\
    \ += rhs; }  // O(N)\n  FPS operator-(const FPS &rhs) const { return FPS(*this)\
    \ -= rhs; }  // O(N)\n  FPS operator*(const FPS &rhs) const { return FPS(*this)\
    \ *= rhs; }  // O(NlogN)\n  FPS operator/(const FPS &rhs) const { return FPS(*this)\
    \ /= rhs; }  // O(NlogN)\n  FPS operator%(const FPS &rhs) const { return FPS(*this)\
    \ %= rhs; }  // O(NlogN)\n  mint eval(mint x) const {\n    mint res, w = 1;\n\
    \    for (auto &v : *this) res += w * v, w *= x;\n    return res;\n  }\n\n public:\n\
    \  static mint mod_sqrt(mint x) {\n    if (x == 0 || mint::modulo() == 2) return\
    \ x;\n    if (x.pow((mint::modulo() - 1) >> 1) != 1) return mint(0);  // no solutions\n\
    \    mint b(2);\n    mint w(b * b - x);\n    while (w.pow((mint::modulo() - 1)\
    \ >> 1) == 1) b += mint(1), w = b * b - x;\n    auto mul = [&](pair<mint, mint>\
    \ u, pair<mint, mint> v) {\n      mint a = (u.first * v.first + u.second * v.second\
    \ * w);\n      mint b = (u.first * v.second + u.second * v.first);\n      return\
    \ make_pair(a, b);\n    };\n    unsigned e = (mint::modulo() + 1) >> 1;\n    auto\
    \ ret = make_pair(mint(1), mint(0));\n    for (auto bs = make_pair(b, mint(1));\
    \ e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1) ret = mul(ret, bs);\n    return\
    \ ret.first.get() * 2 < mint::modulo() ? ret.first : -ret.first;\n  }\n\n private:\n\
    \  template <typename T,\n            typename enable_if<is_integral<T>::value>::type\
    \ * = nullptr>\n  static inline void sub(const vector<T> &v, ntt::m64_1 v1[],\
    \ ntt::m64_2 v2[]) {\n    for (size_t i = 0; i < v.size(); i++) v1[i] = v[i],\
    \ v2[i] = v[i];\n  }\n  template <typename T,\n            typename enable_if<!is_integral<T>::value>::type\
    \ * = nullptr>\n  static inline void sub(const vector<T> &v, ntt::m64_1 v1[],\
    \ ntt::m64_2 v2[]) {\n    for (size_t i = 0; i < v.size(); i++)\n      v1[i] =\
    \ v[i].get(), v2[i] = v[i].get();\n  }\n  static void mul2(const FPS &f, const\
    \ FPS &g, bool cyclic = false) {\n    using namespace ntt;\n    sub(f, f1, f2);\n\
    \    if (&f == &g) {\n      convolute(f1, f.size(), f1, f.size(), cyclic);\n \
    \     convolute(f2, f.size(), f2, f.size(), cyclic);\n    } else {\n      sub(g,\
    \ g1, g2);\n      convolute(f1, f.size(), g1, g.size(), cyclic);\n      convolute(f2,\
    \ f.size(), g2, g.size(), cyclic);\n    }\n  }\n  static FPS mul_crt(int beg,\
    \ int end) {\n    using namespace ntt;\n    auto inv = m64_2(m64_1::modulo()).inverse();\n\
    \    mint mod1 = m64_1::modulo();\n    FPS ret(end - beg);\n    for (int i = 0;\
    \ i < (int)ret.size(); i++) {\n      uint64_t r1 = f1[i + beg].get(), r2 = f2[i\
    \ + beg].get();\n      ret[i] = mint(r1)\n               + mint((m64_2(r2 + m64_2::modulo()\
    \ - r1) * inv).get()) * mod1;\n    }\n    return ret;\n  }\n  FPS mul(const FPS\
    \ &g) const {\n    if (this->size() == 0 || g.size() == 0) return FPS();\n   \
    \ if (this->size() + g.size() < 750 || this->size() < 8 || g.size() < 8) {\n \
    \     FPS ret(this->size() + g.size() - 1, 0);\n      for (size_t i = 0; i < this->size();\
    \ i++)\n        for (size_t j = 0; j < g.size(); j++) ret[i + j] += (*this)[i]\
    \ * g[j];\n      return ret;\n    }\n    const FPS &f = *this;\n    mul2(f, g,\
    \ false);\n    return mul_crt(0, int(f.size() + g.size() - 1));\n  }\n  FPS middle_product(const\
    \ FPS &g) const {\n    const FPS &f = *this;\n    if (f.size() == 0 || g.size()\
    \ == 0) return FPS();\n    mul2(f, g, true);\n    return mul_crt(f.size(), g.size());\n\
    \  }\n  FPS mul_cyclically(const FPS &g) const {\n    const FPS &f = *this;\n\
    \    if (f.size() == 0 || g.size() == 0) return FPS();\n    mul2(f, g, true);\n\
    \    int s = max(f.size(), g.size()), size = 1;\n    while (size < s) size <<=\
    \ 1;\n    return mul_crt(0, size);\n  }\n  static FPS sub_mul(const FPS &f, const\
    \ FPS &q, const FPS &d) {\n    size_t sq = q.size();\n    FPS p = q.mul_cyclically(d);\n\
    \    size_t mask = p.size() - 1;\n    for (size_t i = 0; i < sq; i++) p[i & mask]\
    \ -= f[i & mask];\n    FPS r = f.part(sq, f.size());\n    for (size_t i = 0; i\
    \ < r.size(); i++) r[i] -= p[(sq + i) & mask];\n    return r;\n  }\n  FPS comp_dc(const\
    \ FPS &g, int deg = -1) const {\n    if (deg < 0) deg = max(this->size(), g.size());\n\
    \    if (this->size() <= 1) return *this;\n    if (g.size() == 0) return FPS({(*this)[0]});\n\
    \    if (g.size() == 1) return FPS({eval(g[0])});\n    if (this->size() <= 8)\
    \ {\n      FPS ret = {this->back()};\n      for (int i = this->size() - 2; i >=\
    \ 0; i--)\n        ret = (ret * g).pre(deg) + (*this)[i];\n      return ret;\n\
    \    }\n    vector<FPS> pw(deg);\n    pw[0] = {1};\n    pw[1] = g;\n    int m\
    \ = 2;\n    for (; m < deg; m *= 2) pw[m] = (pw[m / 2] * pw[m / 2]).pre(deg);\n\
    \    function<FPS(FPS, int)> rec = [&](FPS p, size_t k) {\n      p.shrink();\n\
    \      if (p.size() <= 1) return p;\n      while (k >= p.size()) k /= 2;\n   \
    \   FPS q(begin(p) + k, end(p));\n      p.resize(k);\n      FPS ret = rec(p, k);\n\
    \      if (pw[k].size() > 0) ret = (ret + rec(q, k) * pw[k]).pre(deg);\n     \
    \ return ret;\n    };\n    return rec(*this, m);\n  }\n\n public:\n  pair<FPS,\
    \ FPS> divrem_rev_n(const FPS &brev) {\n    FPS frev(*this);\n    if (frev.size()\
    \ < brev.size()) return make_pair(FPS(), frev);\n    int sq = frev.size() - brev.size()\
    \ + 1;\n    FPS qrev(sq, 0);\n    mint inv = brev[0].inverse();\n    for (size_t\
    \ i = 0; i < qrev.size(); ++i) {\n      qrev[i] = frev[i] * inv;\n      for (size_t\
    \ j = 0; j < brev.size(); ++j) frev[j + i] -= brev[j] * qrev[i];\n    }\n    return\
    \ {qrev, frev.part(sq, frev.size())};\n  }\n  FPS div_rev_pre(const FPS &brev,\
    \ const FPS &brevinv) const {\n    if (this->size() < brev.size()) return FPS();\n\
    \    size_t sq = this->size() - brev.size() + 1;\n    assert(this->size() >= sq\
    \ && brevinv.size() >= sq);\n    return (this->part(sq) * brevinv.part(sq)).part(sq);\n\
    \  }\n  FPS rem_rev_pre(const FPS &brev, const FPS &brevinv) const {\n    if (this->size()\
    \ < brev.size()) return FPS(*this);\n    return sub_mul(*this, div_rev_pre(brev,\
    \ brevinv), brev);\n  }\n\n public:\n  FPS inv(int deg = -1) const {  // O(NlogN)\n\
    \    assert((*this)[0] != mint(0));\n    if (deg < 0) deg = this->size();\n  \
    \  FPS ret(1, mint(1) / (*this)[0]);\n    for (int e = 1, ne; e < deg; e = ne)\
    \ {\n      ne = min(2 * e, deg);\n      FPS h = ret.part(ne - e) * -ret.middle_product(this->part(ne));\n\
    \      for (int i = e; i < ne; i++) ret.push_back(h[i - e]);\n    }\n    return\
    \ ret;\n  }\n  FPS diff() const {  // O(N)\n    FPS ret(max(0, int(this->size()\
    \ - 1)));\n    for (size_t i = 1; i < this->size(); i++) ret[i - 1] = (*this)[i]\
    \ * mint(i);\n    return ret;\n  }\n  FPS inte() const {  // O(N)\n    FPS ret(this->size()\
    \ + 1);\n    ret[0] = mint(0);\n    for (size_t i = 0; i < this->size(); i++)\n\
    \      ret[i + 1] = (*this)[i] / mint(i + 1);\n    return ret;\n  }\n  FPS log(int\
    \ deg = -1) const {  // O(NlogN)\n    assert((*this)[0] == mint(1));\n    if (deg\
    \ < 0) deg = this->size();\n    return ((this->diff() * this->inv(deg)).part(deg\
    \ - 1)).inte();\n  }\n  FPS exp(int deg = -1) const {  // O(NlogN)\n    assert((*this)[0]\
    \ == mint(0));\n    if (deg < 0) deg = this->size();\n    FPS ret({1, 1 < this->size()\
    \ ? (*this)[1] : 0}), retinv(1, 1);\n    FPS f = this->diff();\n    FPS retdif\
    \ = ret.diff();\n    for (int e = 1, ne = 2, nne; ne < deg; e = ne, ne = nne)\
    \ {\n      nne = min(2 * ne, deg);\n      FPS h = retinv.part(ne - e) * -retinv.middle_product(ret);\n\
    \      for (int i = e; i < ne; i++) retinv.push_back(h[i - e]);\n      FPS a =\
    \ ret * f.part(nne) - retdif;\n      FPS c = (retinv * a.part(nne)).inte();\n\
    \      h = ret.middle_product(c.part(nne));\n      for (int i = ne; i < nne; i++)\
    \ {\n        ret.push_back(h[i - ne]);\n        retdif.push_back(mint(i) * h[i\
    \ - ne]);\n      }\n    }\n    return ret;\n  }\n  pair<FPS, FPS> cos_and_sin(int\
    \ deg = -1) const {  // O(NlogN)\n    if (deg < 0) deg = this->size();\n    mint\
    \ i = mod_sqrt(-1);\n    FPS a = (*this * i).exp(deg), b = (*this * (-i)).exp(deg);\n\
    \    return make_pair((a + b) / mint(2), (a - b) / (mint(2) * i));\n  }\n  FPS\
    \ sqrt(int deg = -1) const {  // O(NlogN)\n    if (deg < 0) deg = this->size();\n\
    \    int xpw = this->ctz();\n    if (xpw == this->size()) return FPS(deg, 0);\n\
    \    if (xpw & 1) return FPS();  // no solutions\n    if (deg - xpw / 2 <= 0)\
    \ return FPS(deg, 0);\n    mint sqr = mod_sqrt((*this)[xpw]);\n    if (sqr * sqr\
    \ != (*this)[xpw]) return FPS();  // no solutions\n    FPS ret({sqr});\n    mint\
    \ inv2 = mint(1) / mint(2);\n    for (int i = 1; i < deg - xpw / 2; i <<= 1)\n\
    \      (ret += (this->part(xpw, xpw + i * 2) * ret.inv(i * 2)).part(i * 2))\n\
    \          *= inv2;\n    return (ret << (xpw / 2)).part(deg);\n  }\n  FPS pow(uint64_t\
    \ k, int deg = -1) const {  // O(NlogN)\n    if (deg < 0) deg = this->size();\n\
    \    int i = this->ctz();\n    if (i == this->size() || i * k > deg) return FPS(deg,\
    \ 0);\n    int n = deg - i * k;\n    mint inv = mint(1) / (*this)[i];\n    FPS\
    \ ret = ((((*this) >> i) * inv).log(n) * k).exp(n) * (*this)[i].pow(k);\n    return\
    \ (ret << (i * k)).part(deg);\n  }\n  FPS shift(mint c) const {  // O(NlogN)\n\
    \    int n = this->size();\n    FPS ret(n), p(n);\n    mint fact = 1, cpw = 1;\n\
    \    for (int i = 0; i < n; fact *= (++i)) ret[i] = (*this)[i] * fact;\n    mint\
    \ finv = mint(n) / fact;\n    for (int i = n; i > 0; i--) p[i - 1] = i == n ?\
    \ finv : p[i] * i;\n    for (int i = 0; i < n; i++, cpw *= c) p[i] *= cpw;\n \
    \   ret = (ret.rev() * p).part(n).rev();\n    for (int i = n - 1; i >= 0; finv\
    \ *= (i--)) ret[i] *= finv;\n    return ret;\n  }\n  FPS comp(const FPS &g, int\
    \ deg = -1) const {  // O((NlogN)^(1.5)?)\n    if (deg < 0) deg = max(this->size(),\
    \ g.size());\n    if (this->size() <= 1) return this->part(deg);\n    if (g.size()\
    \ == 0) return FPS({(*this)[0]}).part(deg);\n    if (g.size() == 1) return FPS({eval(g[0])}).part(deg);\n\
    \    size_t k = (int)::sqrt(deg) + 1;\n    if (k >= g.size() || this->size() <\
    \ 100 || g.ctz() >= k)\n      return comp_dc(g, deg).part(deg);\n    FPS p = g.pre(k);\n\
    \    FPS q = g - p, fp = comp_dc(p, deg), qpw = {1}, tmp = p.diff();\n    int\
    \ xpw = tmp.ctz();\n    tmp = (tmp >> xpw).inv(deg);\n    mint fact = 1;\n   \
    \ FPS ret;\n    for (int i = 0, b = deg / k + 1; i < b; i++) {\n      ret += (fp\
    \ * qpw).pre(deg) / fact;\n      fp = ((fp.diff() >> xpw) * tmp).pre(deg);\n \
    \     qpw = (qpw * q).pre(deg);\n      fact *= i + 1;\n    }\n    return ret.part(deg);\n\
    \  }\n};\n#line 1 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category\
    \ \u6570\u5B66\n */\n\n#ifndef call_from_test\n#line 8 \"src/Math/ModInt.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <int mod>\nstruct ModInt {\n  int64_t\
    \ x;\n  ModInt() : x(0) {}\n  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod -\
    \ (-y) % mod)) {}\n  ModInt &operator+=(const ModInt &p) {\n    if ((x += p.x)\
    \ >= mod) x -= mod;\n    return *this;\n  }\n  ModInt &operator-=(const ModInt\
    \ &p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  ModInt &operator*=(const ModInt &p) {\n    x = (int)(1LL * x * p.x % mod);\n\
    \    return *this;\n  }\n  ModInt &operator/=(const ModInt &p) { return *this\
    \ *= p.inverse(); }\n  ModInt operator-() const { return ModInt() - *this; }\n\
    \  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }\n  ModInt\
    \ operator-(const ModInt &p) const { return ModInt(*this) -= p; }\n  ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n  ModInt operator/(const ModInt\
    \ &p) const { return ModInt(*this) /= p; }\n  bool operator==(const ModInt &p)\
    \ const { return x == p.x; }\n  bool operator!=(const ModInt &p) const { return\
    \ x != p.x; }\n  ModInt inverse() const {\n    int a = x, b = mod, u = 1, v =\
    \ 0, t;\n    while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);\n\
    \    return ModInt(u);\n  }\n  ModInt pow(int64_t e) const {\n    ModInt ret(1);\n\
    \    for (ModInt b = *this; e; e >>= 1, b *= b)\n      if (e & 1) ret *= b;\n\
    \    return ret;\n  }\n  friend ostream &operator<<(ostream &os, const ModInt\
    \ &p) { return os << p.x; }\n  friend istream &operator>>(istream &is, ModInt\
    \ &a) {\n    int64_t t;\n    is >> t;\n    a = ModInt<mod>(t);\n    return (is);\n\
    \  }\n  static int modulo() { return mod; }\n  int get() const { return x; }\n\
    };\n#line 9 \"test/yosupo/sharp_p_subset_sum.test.cpp\"\n#undef call_from_test\n\
    \n// log(1+x^s_1)(1+x^s_2)...(1+x^s_N)=log(1+x^s_1)+log(1+x^s_2)+...log(1+x^s_N)\n\
    // log(1+x)=x-x^2/2+x^3/3-x^4/4...\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  using FPS = FormalPowerSeries<Mint>;\n \
    \ int N, T;\n  cin >> N >> T;\n  int c[T + 1];\n  fill(c, c + T + 1, 0);\n  for\
    \ (int i = 0; i < N; i++) {\n    int s;\n    cin >> s;\n    c[s]++;\n  }\n  FPS\
    \ a(T + 1);\n  for (int t = 1; t <= T; t++)\n    if (c[t]) {\n      for (int j\
    \ = 1; j * t <= T; j++) {\n        Mint tmp = Mint(c[t]) / Mint(j);\n        a[j\
    \ * t] += j & 1 ? tmp : -tmp;\n      }\n    }\n  FPS ans = a.exp();\n  for (int\
    \ t = 1; t <= T; t++) {\n    cout << (t ? \" \" : \"\") << ans[t];\n  }\n  cout\
    \ << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/Math/FormalPowerSeries.hpp\"\n#include \"src/Math/ModInt.hpp\"\n#undef\
    \ call_from_test\n\n// log(1+x^s_1)(1+x^s_2)...(1+x^s_N)=log(1+x^s_1)+log(1+x^s_2)+...log(1+x^s_N)\n\
    // log(1+x)=x-x^2/2+x^3/3-x^4/4...\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  using FPS = FormalPowerSeries<Mint>;\n \
    \ int N, T;\n  cin >> N >> T;\n  int c[T + 1];\n  fill(c, c + T + 1, 0);\n  for\
    \ (int i = 0; i < N; i++) {\n    int s;\n    cin >> s;\n    c[s]++;\n  }\n  FPS\
    \ a(T + 1);\n  for (int t = 1; t <= T; t++)\n    if (c[t]) {\n      for (int j\
    \ = 1; j * t <= T; j++) {\n        Mint tmp = Mint(c[t]) / Mint(j);\n        a[j\
    \ * t] += j & 1 ? tmp : -tmp;\n      }\n    }\n  FPS ans = a.exp();\n  for (int\
    \ t = 1; t <= T; t++) {\n    cout << (t ? \" \" : \"\") << ans[t];\n  }\n  cout\
    \ << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/FormalPowerSeries.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/sharp_p_subset_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 13:43:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sharp_p_subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp.html
title: test/yosupo/sharp_p_subset_sum.test.cpp
---
