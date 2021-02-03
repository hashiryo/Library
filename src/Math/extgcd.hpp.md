---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/inv_of_Poly.test.cpp
    title: test/yosupo/inv_of_Poly.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u591A\u9805\u5F0F\u306E\u62E1\u5F35\u4E92\u9664\u6CD5"
    links:
    - https://loj.ac/article/2773
  bundledCode: "#line 2 \"src/Math/extgcd.hpp\"\n#include <bits/stdc++.h>\n#line 3\
    \ \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <std::uint64_t mod, std::uint64_t prim_root\
    \ = 0>\nclass ModInt {\n  using u64 = std::uint64_t;\n  using u128 = __uint128_t;\n\
    \  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e ==\
    \ 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv\
    \ = mul_inv(mod, 6, 1), r2 = -u128(mod) % mod;\n  static constexpr u64 init(u64\
    \ w) { return reduce(u128(w) * r2); }\n  static constexpr u64 reduce(const u128\
    \ w) {\n    return u64(w >> 64) + mod - ((u128(u64(w) * inv) * mod) >> 64);\n\
    \  }\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t\
    \ n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static\
    \ constexpr u64 modulo() { return mod; }\n  static constexpr u64 norm(u64 w) {\
    \ return w - (mod & -(w >= mod)); }\n  static constexpr u64 pr_rt() { return prim_root;\
    \ }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x\
    \ = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n    return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >>\
    \ 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return\
    \ x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(u128(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr ModInt pow(u64 k) const {\n    ModInt ret\
    \ = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *= base)\n    \
    \  if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt inverse()\
    \ const { return pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this\
    \ == ModInt(0) || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return\
    \ ModInt(0);  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n \
    \   while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto\
    \ mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt, ModInt> v) {\n    \
    \  ModInt a = (u.first * v.first + u.second * v.second * w);\n      ModInt b =\
    \ (u.first * v.second + u.second * v.first);\n      return std::make_pair(a, b);\n\
    \    };\n    u64 e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n\
    \    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n  \
    \    if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.val();\n\
    \  }\n  u64 x;\n};\n#line 4 \"src/Math/FormalPowerSeries.hpp\"\n/**\n * @title\
    \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @category \u6570\u5B66\n */\n// verify\u7528\
    : https://loj.ac/problem/150\n\n// BEGIN CUT HERE\n\ntemplate <class mint, int\
    \ LIM = (1 << 22)>\nstruct FormalPowerSeries : std::vector<mint> {\n  using std::vector<mint>::vector;\n\
    \n private:\n  using FPS = FormalPowerSeries<mint, LIM>;\n  using m64_1 = ModInt<34703335751681,\
    \ 3>;\n  using m64_2 = ModInt<35012573396993, 3>;\n  static inline m64_1 a1[LIM],\
    \ b1[LIM], c1[LIM];\n  static inline m64_2 a2[LIM], b2[LIM], c2[LIM];\n  static\
    \ inline mint bf1[LIM], bf2[LIM];\n  template <class mod_t>\n  static inline void\
    \ idft(int n, mod_t x[]) {\n    static mod_t iW[LIM];\n    static constexpr std::uint64_t\
    \ mod = mod_t::modulo();\n    static constexpr unsigned pr = mod_t::pr_rt();\n\
    \    static_assert(pr != 0);\n    static constexpr mod_t G(pr);\n    static int\
    \ lim = 0;\n    if (lim == 0) iW[0] = 1, lim = 1;\n    for (int m = lim; m < n\
    \ / 2; m *= 2) {\n      mod_t idw = G.pow(mod - 1 - (mod - 1) / (4 * m));\n  \
    \    for (int i = 0; i < m; i++) iW[m + i] = iW[i] * idw;\n      lim = n / 2;\n\
    \    }\n    for (int m = 1; m < n; m *= 2)\n      for (int s = 0, k = 0; s < n;\
    \ s += 2 * m, ++k)\n        for (int i = s, j = s + m; i < s + m; ++i, ++j) {\n\
    \          mod_t u = x[i], v = x[j];\n          x[i] = u + v, x[j] = (u - v) *\
    \ iW[k];\n        }\n    mod_t iv(mod - (mod - 1) / n);\n    for (int i = 0; i\
    \ < n; i++) x[i] *= iv;\n  }\n  template <class mod_t>\n  static inline void dft(int\
    \ n, mod_t x[]) {\n    static mod_t W[LIM];\n    static constexpr std::uint64_t\
    \ mod = mod_t::modulo();\n    static constexpr unsigned pr = mod_t::pr_rt();\n\
    \    static_assert(pr != 0);\n    static constexpr mod_t G(pr);\n    static int\
    \ lim = 0;\n    if (lim == 0) W[0] = 1, lim = 1;\n    for (int m = lim; m < n\
    \ / 2; m *= 2) {\n      mod_t dw = G.pow((mod - 1) / (4 * m));\n      for (int\
    \ i = 0; i < m; i++) W[m + i] = W[i] * dw;\n      lim = n / 2;\n    }\n    for\
    \ (int m = n; m >>= 1;)\n      for (int s = 0, k = 0; s < n; s += 2 * m, ++k)\n\
    \        for (int i = s, j = s + m; i < s + m; ++i, ++j) {\n          mod_t u\
    \ = x[i], v = x[j] * W[k];\n          x[i] = u + v, x[j] = u - v;\n        }\n\
    \  }\n  static inline void crt(m64_1 f1[], m64_2 f2[], int b, int e, mint ret[])\
    \ {\n    static constexpr m64_2 iv = m64_2(m64_1::modulo()).inverse();\n    static\
    \ constexpr mint mod1 = m64_1::modulo();\n    for (int i = b; i < e; i++) {\n\
    \      std::uint64_t r1 = f1[i].val(), r2 = f2[i].val();\n      ret[i] = mint(r1)\n\
    \               + mint((m64_2(r2 + m64_2::modulo() - r1) * iv).val()) * mod1;\n\
    \    }\n  }\n  template <typename T, typename std::enable_if<\n              \
    \              std::is_integral<T>::value>::type * = nullptr>\n  static inline\
    \ void subst(m64_1 f1[], m64_2 f2[], int b, int e, T ret[]) {\n    for (int i\
    \ = b; i < e; i++) f1[i] = ret[i], f2[i] = ret[i];\n  }\n  template <typename\
    \ T, typename std::enable_if<\n                            !std::is_integral<T>::value>::type\
    \ * = nullptr>\n  static inline void subst(m64_1 f1[], m64_2 f2[], int b, int\
    \ e, T ret[]) {\n    std::uint64_t tmp;\n    for (int i = b; i < e; i++) tmp =\
    \ ret[i].val(), f1[i] = tmp, f2[i] = tmp;\n  }\n  static inline mint get_inv(int\
    \ i) {\n    static mint INV[LIM];\n    static int lim = 0;\n    static constexpr\
    \ std::uint64_t mod = mint::modulo();\n    if (lim <= i) {\n      if (lim == 0)\
    \ INV[1] = 1, lim = 2;\n      for (int j = lim; j <= i; j++) INV[j] = INV[mod\
    \ % j] * (mod - mod / j);\n      lim = i + 1;\n    }\n    return INV[i];\n  }\n\
    \n public:\n  int deg() const {\n    int n = int(this->size()) - 1;\n    while\
    \ (n >= 0 && (*this)[n] == mint(0)) n--;\n    return n;\n  }\n  FPS &norm() {\
    \ return this->resize(std::max(this->deg() + 1, 1)), *this; }\n  std::uint64_t\
    \ inline get_len(std::uint64_t n) const {\n    return --n, n |= n >> 1, n |= n\
    \ >> 2, n |= n >> 4, n |= n >> 8,\n           n |= n >> 16, n |= n >> 32, ++n;\n\
    \  }\n  FPS mul(const FPS &y) const {\n    if (deg() == -1 || y.deg() == -1) return\
    \ {0};\n    int n = this->size(), m = y.size(), sz = n + m - 1;\n    FPS ret(sz,\
    \ 0);\n    if (std::min(n, m) <= 8) {\n      for (int i = 0; i < n; i++)\n   \
    \     for (int j = 0; j < m; j++) ret[i + j] += (*this)[i] * y[j];\n    } else\
    \ {\n      subst(a1, a2, 0, n, this->data()), subst(b1, b2, 0, m, y.data());\n\
    \      int len = get_len(sz);\n      std::fill(a1 + n, a1 + len, 0), std::fill(b1\
    \ + m, b1 + len, 0);\n      std::fill(a2 + n, a2 + len, 0), std::fill(b2 + m,\
    \ b2 + len, 0);\n      dft(len, a1), dft(len, b1), dft(len, a2), dft(len, b2);\n\
    \      for (int i = 0; i < len; i++) a1[i] *= b1[i], a2[i] *= b2[i];\n      idft(len,\
    \ a1), idft(len, a2), crt(a1, a2, 0, sz, ret.data());\n    }\n    return ret;\n\
    \  }\n  FPS inv() const {\n    assert(!this->empty() && (*this)[0] != mint(0));\n\
    \    int n = this->size(), len = get_len(n);\n    std::copy_n(this->begin(), n,\
    \ bf1), std::fill(bf1 + n, bf1 + len, 0);\n    FPS ret(len, 0);\n    ret[0] =\
    \ bf1[0].inverse();\n    for (int i = 1; i < 32 && i < n; ret[i++] *= -ret[0])\n\
    \      for (int j = 1; j <= i; j++) ret[i] += bf1[j] * ret[i - j];\n    for (int\
    \ i = 64; i <= len; i <<= 1) {\n      subst(a1, a2, 0, i, bf1), subst(b1, b2,\
    \ 0, i, ret.data());\n      dft(i, a1), dft(i, b1), dft(i, a2), dft(i, b2);\n\
    \      for (int j = i - 1; j >= 0; j--) a1[j] *= b1[j], a2[j] *= b2[j];\n    \
    \  idft(i, a1), idft(i, a2);\n      crt(a1, a2, i >> 1, i, ret.data()), subst(a1,\
    \ a2, i >> 1, i, ret.data());\n      std::fill_n(a1, i >> 1, 0), std::fill_n(a2,\
    \ i >> 1, 0), dft(i, a1),\n          dft(i, a2);\n      for (int j = i - 1; j\
    \ >= 0; j--) a1[j] *= b1[j], a2[j] *= b2[j];\n      idft(i, a1), idft(i, a2),\
    \ crt(a1, a2, i >> 1, i, ret.data());\n      for (int j = i >> 1; j < i; j++)\
    \ ret[j] = -ret[j];\n    }\n    return ret.resize(n), ret;\n  }\n  inline FPS\
    \ div_con(const FPS &g, const FPS &g0) const {\n    if (this->size() == 1) return\
    \ {(*this)[0] * g[0].inverse()};\n    int n = this->size(), len = get_len(n),\
    \ len2 = len >> 1,\n        m = std::min<int>(n, g.size());\n    FPS ret(n);\n\
    \    std::copy_n(this->begin(), n, bf1), std::fill(bf1 + n, bf1 + len, 0);\n \
    \   std::copy_n(g.begin(), m, bf2), std::fill(bf2 + m, bf2 + len, 0);\n    subst(a1,\
    \ a2, 0, len2, g0.data()), subst(b1, b2, 0, len2, bf1);\n    std::fill(a1 + len2,\
    \ a1 + len, 0), std::fill(a2 + len2, a2 + len, 0);\n    std::fill(b1 + len2, b1\
    \ + len, 0), std::fill(b2 + len2, b2 + len, 0);\n    dft(len, a1), dft(len, b1),\
    \ dft(len, a2), dft(len, b2);\n    for (int i = 0; i < len; i++) b1[i] *= a1[i],\
    \ b2[i] *= a2[i];\n    idft(len, b1), idft(len, b2), crt(b1, b2, 0, len2, ret.data());\n\
    \    subst(b1, b2, 0, len2, ret.data()), subst(c1, c2, 0, len, bf2);\n    std::fill(b1\
    \ + len2, b1 + len, 0), std::fill(b2 + len2, b2 + len, 0);\n    dft(len, c1),\
    \ dft(len, b1), dft(len, c2), dft(len, b2);\n    for (int i = 0; i < len; i++)\
    \ c1[i] *= b1[i], c2[i] *= b2[i];\n    idft(len, c1), idft(len, c2), crt(c1 +\
    \ len2, c2 + len2, 0, len2, bf1);\n    for (int i = len2; i < len; i++) bf1[i]\
    \ -= bf1[i - len2];\n    subst(c1, c2, len2, len, bf1);\n    std::fill_n(c1, len2,\
    \ 0), std::fill_n(c2, len2, 0), dft(len, c1),\n        dft(len, c2);\n    for\
    \ (int i = len; i >= 0; i--) c1[i] *= a1[i], c2[i] *= a2[i];\n    idft(len, c1),\
    \ idft(len, c2), crt(c1, c2, len2, n, ret.data());\n    return ret;\n  }\n  inline\
    \ std::pair<FPS, FPS> quorem_rev_con(const FPS &yr,\n                        \
    \                    const FPS &g0r) const {\n    if (this->size() < yr.size())\
    \ return std::make_pair(FPS{0}, *this);\n    int sq = this->size() - yr.size()\
    \ + 1, len = get_len(sq);\n    FPS qr = FPS(this->begin(), this->begin() + sq).div_con(yr,\
    \ g0r);\n    if (yr.size() == 1) return std::make_pair(qr, FPS{0});\n    len =\
    \ get_len(std::max(qr.size(), yr.size()));\n    int mask = len - 1;\n    subst(a1,\
    \ a2, 0, sq, qr.data()), subst(b1, b2, 0, yr.size(), yr.data());\n    std::fill(a1\
    \ + sq, a1 + len, 0), std::fill(a2 + sq, a2 + len, 0);\n    std::fill(b1 + yr.size(),\
    \ b1 + len, 0),\n        std::fill(b2 + yr.size(), b2 + len, 0);\n    dft(len,\
    \ a1), dft(len, a2), dft(len, b1), dft(len, b2);\n    for (int i = len - 1; i\
    \ >= 0; i--) a1[i] *= b1[i], a2[i] *= b2[i];\n    idft(len, a1), idft(len, a2),\
    \ crt(a1, a2, 0, len, bf1);\n    for (int i = sq - 1; i >= 0; i--) bf1[i & mask]\
    \ -= (*this)[i & mask];\n    FPS rem(this->begin() + sq, this->end());\n    for\
    \ (int i = rem.size() - 1; i >= 0; i--) rem[i] -= bf1[(sq + i) & mask];\n    return\
    \ std::make_pair(qr, rem);\n  }\n  inline std::pair<FPS, FPS> quorem_rev_n(const\
    \ FPS &yr) const {\n    if (this->size() < yr.size()) return std::make_pair(FPS{0},\
    \ *this);\n    int sq = this->size() - yr.size() + 1;\n    std::copy_n(this->begin(),\
    \ this->size(), bf1);\n    FPS qr(sq, 0);\n    mint iv = yr[0].inverse();\n  \
    \  for (int i = 0; i < sq; i++) {\n      qr[i] = bf1[i] * iv;\n      for (int\
    \ j = 0; j < (int)yr.size(); j++) bf1[j + i] -= yr[j] * qr[i];\n    }\n    return\
    \ std::make_pair(qr, FPS(bf1 + sq, bf1 + this->size()));\n  }\n  FPS div(const\
    \ FPS &y) const {\n    if (this->size() == 1) return {(*this)[0] * y[0].inverse()};\n\
    \    int len2 = get_len(this->size()) / 2;\n    FPS g(len2);\n    for (int i =\
    \ std::min<int>(y.size(), len2) - 1; i >= 0; i--) g[i] = y[i];\n    return div_con(y,\
    \ g.inv());\n  }\n  FPS quo(FPS y) const {\n    FPS x(*this);\n    x.norm(), y.norm();\n\
    \    if (x.size() < y.size()) return FPS{0};\n    if (x.size() == y.size()) return\
    \ FPS{x.back() / y.back()};\n    reverse(x.begin(), x.end()), reverse(y.begin(),\
    \ y.end());\n    FPS ret = y.size() < 1024 ? x.quorem_rev_n(y).first\n       \
    \                       : (x.resize(x.size() - y.size() + 1), x.div(y));\n   \
    \ reverse(ret.begin(), ret.end());\n    return ret;\n  }\n  std::pair<FPS, FPS>\
    \ quorem(FPS y) const {\n    FPS x(*this);\n    x.norm(), y.norm();\n    if (x.size()\
    \ < y.size()) return std::make_pair(FPS{0}, x);\n    if (x.size() == y.size())\
    \ {\n      mint tmp = x.back() / y.back();\n      return std::make_pair(FPS{tmp},\
    \ x - y * tmp);\n    }\n    reverse(x.begin(), x.end()), reverse(y.begin(), y.end());\n\
    \    FPS q, r;\n    if (y.size() < 1024)\n      tie(q, r) = x.quorem_rev_n(y);\n\
    \    else {\n      int len2 = get_len(x.size() - y.size() + 1) / 2;\n      FPS\
    \ gr(len2);\n      for (int i = std::min<int>(y.size(), len2) - 1; i >= 0; i--)\
    \ gr[i] = y[i];\n      tie(q, r) = x.quorem_rev_con(y, gr.inv());\n    }\n   \
    \ reverse(q.begin(), q.end()), reverse(r.begin(), r.end());\n    return std::make_pair(q,\
    \ r.norm());\n  }\n  FPS diff() const {\n    FPS ret(std::max(0, int(this->size()\
    \ - 1)));\n    for (int i = this->size() - 1; i > 0; i--) ret[i - 1] = (*this)[i]\
    \ * i;\n    return ret;\n  }\n  FPS inte() const {\n    int len = this->size()\
    \ + 1;\n    FPS ret(len, 0);\n    for (int i = len - 1; i >= 1; i--) ret[i] =\
    \ (*this)[i - 1] * get_inv(i);\n    return ret;\n  }\n  FPS log() const {\n  \
    \  assert((*this)[0] == mint(1));\n    return this->size() == 1 ? FPS{0} : this->diff().div(*this).inte();\n\
    \  }\n  FPS exp() const {\n    assert((*this)[0] == mint(0));\n    int n = this->size(),\
    \ len = get_len(n);\n    if (n == 1) return {1};\n    static mint b[LIM], f[LIM\
    \ / 2];\n    std::copy_n(this->data(), n, bf1), std::fill(bf1 + n, bf1 + len,\
    \ 0);\n    FPS ret(len, 0);\n    std::fill_n(bf2, len, 0), std::fill_n(c1, len,\
    \ 0), std::fill_n(c2, len, 0);\n    ret[0] = 1, ret[1] = bf1[1], bf2[0] = 1, bf2[1]\
    \ = -bf1[1];\n    for (int i = 1; i != len; ++i) b[i - 1] = mint(i) * bf1[i];\n\
    \    subst(c1, c2, 0, 2, ret.data()), dft(4, c1), dft(4, c2);\n    std::uint64_t\
    \ tmp;\n    for (int i = 4, i2 = 2; i <= len; i <<= 1, i2 <<= 1) {\n      for\
    \ (int j = i >> 2; j < i2; j++) f[j - 1] = ret[j] * mint(j);\n      subst(b1,\
    \ b2, 0, i2 - 1, b), b1[i2 - 1] = 0, b2[i2 - 1] = 0;\n      dft(i2, b1), dft(i2,\
    \ b2);\n      for (int j = i2 - 1; j >= 0; j--) b1[j] *= c1[j], b2[j] *= c2[j];\n\
    \      idft(i2, b1), idft(i2, b2), crt(b1, b2, 0, i2, bf1);\n      for (int j\
    \ = i2 - 3; j >= 0; j--)\n        tmp = (f[j] - bf1[j]).val(), b1[j + i2] = tmp,\
    \ b2[j + i2] = tmp;\n      tmp = (bf1[i2 - 2] - f[i2 - 2]).val(), b1[i2 - 2] =\
    \ tmp, b2[i2 - 2] = tmp;\n      tmp = (-bf1[i2 - 1]).val(), b1[i2 - 1] = tmp,\
    \ b2[i2 - 1] = tmp;\n      std::fill_n(b1, i2 - 2, 0), std::fill_n(b2, i2 - 2,\
    \ 0);\n      b1[i - 2] = b1[i - 1] = 0, b2[i - 2] = b2[i - 1] = 0;\n      subst(a1,\
    \ a2, 0, i, bf2), dft(i, a1), dft(i, a2), dft(i, b1), dft(i, b2);\n      for (int\
    \ j = 0; j < i; j++) b1[j] *= a1[j], b2[j] *= a2[j];\n      idft(i, b1), idft(i,\
    \ b2), crt(b1, b2, i2 - 1, i - 1, bf2 + 1);\n      for (int j = i - 1; j >= i2;\
    \ j--) (bf2[j] *= get_inv(j)) -= bf1[j];\n      subst(b1, b2, i2, i, bf2);\n \
    \     std::fill_n(b1, i2, 0), std::fill_n(b2, i2, 0), dft(i, b1), dft(i, b2);\n\
    \      for (int j = i - 1; j >= 0; j--) c1[j] *= b1[j], c2[j] *= b2[j];\n    \
    \  idft(i, c1), idft(i, c2), crt(c1, c2, i2, i, ret.data());\n      for (int j\
    \ = i2; j < i; j++) ret[j] = -ret[j];\n      if (i != len) {\n        subst(c1,\
    \ c2, 0, i, ret.data()), dft(i << 1, c1), dft(i << 1, c2);\n        for (int j\
    \ = i - 1; j >= 0; j--)\n          b1[j] = c1[j] * a1[j], b2[j] = c2[j] * a2[j];\n\
    \        idft(i, b1), idft(i, b2), crt(b1, b2, i2, i, bf2);\n        subst(b1,\
    \ b2, i2, i, bf2);\n        std::fill_n(b1, i2, 0), std::fill_n(b2, i2, 0), dft(i,\
    \ b1), dft(i, b2);\n        for (int j = i - 1; j >= 0; j--) b1[j] *= a1[j], b2[j]\
    \ *= a2[j];\n        idft(i, b1), idft(i, b2), crt(b1, b2, i2, i, bf2);\n    \
    \    for (int j = i2; j < i; j++) bf2[j] = -bf2[j];\n      }\n    }\n    return\
    \ ret.resize(n), ret;\n  }\n  FPS pow(std::uint64_t k) const {\n    int n = this->size(),\
    \ cnt = 0;\n    while (cnt < n && (*this)[cnt] == mint(0)) cnt++;\n    if (k *\
    \ cnt >= (std::uint64_t)n) return FPS(n, 0);\n    mint iv = (*this)[cnt].inverse();\n\
    \    FPS pt = ((FPS(this->begin() + cnt, this->end()) * iv).log() * k).exp()\n\
    \             * (*this)[cnt].pow(k),\n        ret(n, 0);\n    for (int i = k *\
    \ cnt, j = 0; i < n; i++, j++) ret[i] = pt[j];\n    return ret;\n  }\n  std::pair<FPS,\
    \ FPS> cos_and_sin() const {\n    static constexpr mint imag = mint(-1).sqrt();\n\
    \    static constexpr mint iv2 = mint(mint::modulo() - (mint::modulo() - 1) /\
    \ 2);\n    FPS a = (*this * imag).exp(), b = (*this * (-imag)).exp();\n    return\
    \ std::make_pair((a + b) * iv2, (a - b) * iv2 / imag);\n  }\n  FPS sqrt() const\
    \ {\n    static constexpr mint iv2 = mint(mint::modulo() - (mint::modulo() - 1)\
    \ / 2);\n    int n = this->size(), cnt = 0;\n    while (cnt < n && (*this)[cnt]\
    \ == mint(0)) cnt++;\n    if (cnt == n) return FPS(n, 0);\n    if (cnt & 1) return\
    \ FPS();  // no solution\n    mint sqr = (*this)[cnt].sqrt();\n    if (sqr * sqr\
    \ != (*this)[cnt]) return FPS();  // no solution\n    int len = get_len(n - cnt\
    \ / 2);\n    FPS ret({sqr});\n    ret.resize(len);\n    std::copy_n(this->begin()\
    \ + cnt, n - cnt, bf1),\n        std::fill(bf1 + n - cnt, bf1 + len, 0);\n   \
    \ std::fill_n(bf2, len, 0), bf2[0] = ret[0].inverse();\n    std::uint64_t tmp;\n\
    \    tmp = ret[0].val(), b1[0] = tmp, b2[0] = tmp, b1[1] = 0, b2[1] = 0;\n   \
    \ dft(2, b1), dft(2, b2);\n    for (int i = 2, i2 = 1; i <= len; i <<= 1, i2 <<=\
    \ 1) {\n      for (int j = i2 - 1; j >= 0; j--)\n        c1[j] = b1[j] * b1[j],\
    \ c2[j] = b2[j] * b2[j];\n      idft(i2, c1), idft(i2, c2), crt(c1, c2, 0, i2,\
    \ ret.data() + i2);\n      for (int j = i - 2; j >= i2; j--)\n        tmp = (ret[j]\
    \ - bf1[j - i2] - bf1[j]).val(), c1[j] = tmp, c2[j] = tmp;\n      tmp = (ret[i\
    \ - 1] - bf1[i2 - 1]).val(), c1[i2 - 1] = tmp,\n      c2[i2 - 1] = tmp;\n    \
    \  tmp = (-bf1[i - 1]).val(), c1[i - 1] = tmp, c2[i - 1] = tmp;\n      std::fill_n(c1,\
    \ i2 - 1, 0), std::fill_n(c2, i2 - 1, 0),\n          subst(a1, a2, 0, i, bf2);\n\
    \      dft(i, a1), dft(i, a2), dft(i, c1), dft(i, c2);\n      for (int j = i -\
    \ 1; j >= 0; j--) c1[j] *= a1[j], c2[j] *= a2[j];\n      idft(i, c1), idft(i,\
    \ c2), crt(c1, c2, i2, i, bf2);\n      for (int j = i2; j < i; j++) ret[j] = -bf2[j]\
    \ * iv2;\n      if (i != len) {\n        subst(b1, b2, 0, i, ret.data()), dft(i,\
    \ b1), dft(i, b2);\n        for (int j = i - 1; j >= 0; j--)\n          c1[j]\
    \ = b1[j] * a1[j], c2[j] = b2[j] * a2[j];\n        idft(i, c1), idft(i, c2), crt(c1,\
    \ c2, i2, i, bf2);\n        subst(c1, c2, i2, i, bf2);\n        std::fill_n(c1,\
    \ i2, 0), std::fill_n(c2, i2, 0), dft(i, c1), dft(i, c2);\n        for (int j\
    \ = i - 1; j >= 0; j--) c1[j] *= a1[j], c2[j] *= a2[j];\n        idft(i, c1),\
    \ idft(i, c2), crt(c1, c2, i2, i, bf2);\n        for (int j = i2; j < i; j++)\
    \ bf2[j] = -bf2[j];\n      }\n    }\n    for (int i = n - cnt / 2 - 1; i >= 0;\
    \ i--) ret[i + cnt / 2] = ret[i];\n    std::fill_n(ret.begin(), cnt / 2, 0);\n\
    \    return ret;\n  }\n  FPS shift(mint c) const {\n    int n = this->size();\n\
    \    FPS ret(n), p(n);\n    mint f = 1, cpw = 1;\n    for (int i = 0; i < n; f\
    \ *= ++i) ret[n - i - 1] = (*this)[i] * f;\n    f = mint(n) / f;\n    for (int\
    \ i = n; i > 0; i--) p[i - 1] = i == n ? f : p[i] * i;\n    for (int i = 0; i\
    \ < n; i++, cpw *= c) p[i] *= cpw;\n    p *= ret, p.resize(n);\n    std::reverse_copy(p.begin(),\
    \ p.begin() + n, ret.begin());\n    for (int i = n - 1; i >= 2; f *= i--) ret[i]\
    \ *= f;\n    return ret;\n  }\n  FPS comp(const FPS &g) const {\n    int n = this->size(),\
    \ k = std::sqrt(1. * n);\n    if (k * k < n) k++;\n    int d = (n - 1 + k) / k;\n\
    \    std::vector<FPS> gpw(d + 1);\n    gpw[0] = {1};\n    for (int i = 1; i <=\
    \ d; i++) {\n      gpw[i] = gpw[i - 1] * g;\n      if ((int)gpw[i].size() > n)\
    \ gpw[i].resize(n);\n    }\n    FPS ret(n, 0), gd{1}, tmp;\n    for (int i = 0;\
    \ i < k; i++) {\n      tmp = {(*this)[i * d]};\n      for (int j = 1; j < d &&\
    \ i * d + j < n; j++)\n        tmp += gpw[j] * (*this)[i * d + j];\n      tmp\
    \ *= gd;\n      for (int j = std::min<int>(n, tmp.size()) - 1; j >= 0; j--)\n\
    \        ret[j] += tmp[j];\n      gd *= gpw[d];\n      if ((int)gd.size() > n)\
    \ gd.resize(n);\n    }\n    return ret;\n  }\n  mint eval(mint x) const {\n  \
    \  mint res, w = 1;\n    for (auto &v : *this) res += w * v, w *= x;\n    return\
    \ res;\n  }\n  FPS operator-() {\n    FPS ret(this->size());\n    for (int i =\
    \ ret.size() - 1; i >= 0; i--) ret[i] = -(*this)[i];\n    return ret;\n  }\n \
    \ FPS &operator+=(const mint &v) {\n    if (this->empty()) this->resize(1, 0);\n\
    \    return (*this)[0] += v, *this;\n  }\n  FPS &operator-=(const mint &v) { return\
    \ *this += -v; }\n  FPS &operator*=(const mint &v) {\n    for (int i = this->size()\
    \ - 1; i >= 0; i--) (*this)[i] *= v;\n    return *this;\n  }\n  FPS &operator/=(const\
    \ mint &v) {\n    for (int i = this->size() - 1; i >= 0; i--) (*this)[i] /= v;\n\
    \    return *this;\n  }\n  FPS &operator+=(const FPS &r) {\n    if (this->size()\
    \ < r.size()) this->resize(r.size(), 0);\n    for (int i = r.size() - 1; i >=\
    \ 0; i--) (*this)[i] += r[i];\n    return this->norm();\n  }\n  FPS &operator-=(const\
    \ FPS &r) {\n    if (this->size() < r.size()) this->resize(r.size(), 0);\n   \
    \ for (int i = r.size() - 1; i >= 0; i--) (*this)[i] -= r[i];\n    return this->norm();\n\
    \  }\n  FPS &operator*=(const FPS &r) { return *this = norm().mul(FPS(r).norm());\
    \ }\n  FPS &operator/=(const FPS &r) { return *this = this->quo(r); }\n  FPS &operator%=(const\
    \ FPS &r) { return *this = this->quorem(r).second; }\n  FPS operator+(const mint\
    \ &v) const { return FPS(*this) += v; }\n  FPS operator-(const mint &v) const\
    \ { return FPS(*this) -= v; }\n  FPS operator*(const mint &v) const { return FPS(*this)\
    \ *= v; }\n  FPS operator/(const mint &v) const { return FPS(*this) /= v; }\n\
    \  FPS operator+(const FPS &r) const { return FPS(*this) += r; }\n  FPS operator-(const\
    \ FPS &r) const { return FPS(*this) -= r; }\n  FPS operator*(const FPS &r) const\
    \ { return FPS(*this) *= r; }\n  FPS operator/(const FPS &r) const { return this->quo(r);\
    \ }\n  FPS operator%(const FPS &r) const { return this->quorem(r).second; }\n\
    };\n#line 5 \"src/Math/extgcd.hpp\"\n/**\n * @title \u591A\u9805\u5F0F\u306E\u62E1\
    \u5F35\u4E92\u9664\u6CD5\n * @category \u6570\u5B66\n *  O(Nlog^2N)\n * @see https://loj.ac/article/2773\n\
    \ */\n\n// BEGIN CUT HERE\n\n// ax + by = gcd(a, b)\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ extgcd(FormalPowerSeries<mint> a,\n                               FormalPowerSeries<mint>\
    \ b,\n                               FormalPowerSeries<mint> &x,\n           \
    \                    FormalPowerSeries<mint> &y) {\n  using poly = FormalPowerSeries<mint>;\n\
    \  using pv = std::array<poly, 2>;\n  using pm = std::array<pv, 2>;\n  assert(a.deg()\
    \ >= 0);\n  assert(b.deg() >= 0);\n  auto isI = [](const pm &m) {\n    static\
    \ constexpr mint ONE(1);\n    return m[0][1].deg() == -1 && m[1][0].deg() == -1\
    \ && m[0][0].deg() == 0\n           && m[0][0][0] == ONE && m[1][1].deg() == 0\
    \ && m[1][1][0] == ONE;\n  };\n  auto mulv = [&](const pm &lhs, const pv &rhs)\
    \ {\n    if (isI(lhs)) return rhs;\n    return pv{lhs[0][0] * rhs[0] + lhs[0][1]\
    \ * rhs[1],\n              lhs[1][0] * rhs[0] + lhs[1][1] * rhs[1]};\n  };\n \
    \ auto mul = [&](const pm &lhs, const pm &rhs) {\n    if (isI(lhs)) return rhs;\n\
    \    if (isI(rhs)) return lhs;\n    return pm{pv{lhs[0][0] * rhs[0][0] + lhs[0][1]\
    \ * rhs[1][0],\n                 lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1]},\n\
    \              pv{lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0],\n           \
    \      lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]}};\n  };\n  auto mulQ_l =\
    \ [&](const poly &q, const pm &rhs) {\n    return pm{pv{rhs[1][0], rhs[1][1]},\n\
    \              pv{rhs[0][0] - q * rhs[1][0], rhs[0][1] - q * rhs[1][1]}};\n  };\n\
    \  auto mulQ_r = [&](const pm &lhs, const poly &q) {\n    return pm{pv{lhs[0][1],\
    \ lhs[0][0] - lhs[0][1] * q},\n              pv{lhs[1][1], lhs[1][0] - lhs[1][1]\
    \ * q}};\n  };\n  std::function<pm(poly, poly)> hgcd = [&](const poly &p0, const\
    \ poly &p1) {\n    assert(p0.deg() > p1.deg());\n    int m = ((p0.deg() - 1) >>\
    \ 1) + 1, n = p1.deg();\n    if (n < m) return pm{pv{poly{1}, poly{}}, pv{poly{},\
    \ poly{1}}};\n    pm R(hgcd(poly(p0.begin() + m, p0.end()), poly(p1.begin() +\
    \ m, p1.end())));\n    pv ab(mulv(R, pv{p0, p1}));\n    if (ab[1].deg() < m) return\
    \ R;\n    std::pair<poly, poly> qr(ab[0].quorem(ab[1]));\n    int k = 2 * m -\
    \ ab[1].deg();\n    if ((int)qr.second.size() <= k) return mulQ_l(qr.first, R);\n\
    \    return mul(hgcd(poly(ab[1].begin() + k, ab[1].end()),\n                 \
    \   poly(qr.second.begin() + k, qr.second.end())),\n               mulQ_l(qr.first,\
    \ R));\n  };\n  std::function<pm(poly, poly)> cogcd = [&](const poly &p0, const\
    \ poly &p1) {\n    assert(p0.deg() > p1.deg());\n    pm M(hgcd(p0, p1));\n   \
    \ pv p2p3(mulv(M, pv{p0, p1}));\n    if (p2p3[1].deg() == -1) return M;\n    std::pair<poly,\
    \ poly> qr(p2p3[0].quorem(p2p3[1]));\n    if (qr.second.deg() == -1) return mulQ_l(qr.first,\
    \ M);\n    return mul(cogcd(p2p3[1], qr.second), mulQ_l(qr.first, M));\n  };\n\
    \  pm c;\n  if (a.norm().deg() > b.norm().deg()) {\n    c = cogcd(a, b);\n  }\
    \ else {\n    std::pair<poly, poly> qr(a.quorem(b));\n    c = mulQ_r(cogcd(b,\
    \ qr.second), qr.first);\n  }\n  return a * (x = c[0][0]) + b * (y = c[0][1]);\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n\
    #include \"src/Math/FormalPowerSeries.hpp\"\n/**\n * @title \u591A\u9805\u5F0F\
    \u306E\u62E1\u5F35\u4E92\u9664\u6CD5\n * @category \u6570\u5B66\n *  O(Nlog^2N)\n\
    \ * @see https://loj.ac/article/2773\n */\n\n// BEGIN CUT HERE\n\n// ax + by =\
    \ gcd(a, b)\ntemplate <class mint>\nFormalPowerSeries<mint> extgcd(FormalPowerSeries<mint>\
    \ a,\n                               FormalPowerSeries<mint> b,\n            \
    \                   FormalPowerSeries<mint> &x,\n                            \
    \   FormalPowerSeries<mint> &y) {\n  using poly = FormalPowerSeries<mint>;\n \
    \ using pv = std::array<poly, 2>;\n  using pm = std::array<pv, 2>;\n  assert(a.deg()\
    \ >= 0);\n  assert(b.deg() >= 0);\n  auto isI = [](const pm &m) {\n    static\
    \ constexpr mint ONE(1);\n    return m[0][1].deg() == -1 && m[1][0].deg() == -1\
    \ && m[0][0].deg() == 0\n           && m[0][0][0] == ONE && m[1][1].deg() == 0\
    \ && m[1][1][0] == ONE;\n  };\n  auto mulv = [&](const pm &lhs, const pv &rhs)\
    \ {\n    if (isI(lhs)) return rhs;\n    return pv{lhs[0][0] * rhs[0] + lhs[0][1]\
    \ * rhs[1],\n              lhs[1][0] * rhs[0] + lhs[1][1] * rhs[1]};\n  };\n \
    \ auto mul = [&](const pm &lhs, const pm &rhs) {\n    if (isI(lhs)) return rhs;\n\
    \    if (isI(rhs)) return lhs;\n    return pm{pv{lhs[0][0] * rhs[0][0] + lhs[0][1]\
    \ * rhs[1][0],\n                 lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1]},\n\
    \              pv{lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0],\n           \
    \      lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]}};\n  };\n  auto mulQ_l =\
    \ [&](const poly &q, const pm &rhs) {\n    return pm{pv{rhs[1][0], rhs[1][1]},\n\
    \              pv{rhs[0][0] - q * rhs[1][0], rhs[0][1] - q * rhs[1][1]}};\n  };\n\
    \  auto mulQ_r = [&](const pm &lhs, const poly &q) {\n    return pm{pv{lhs[0][1],\
    \ lhs[0][0] - lhs[0][1] * q},\n              pv{lhs[1][1], lhs[1][0] - lhs[1][1]\
    \ * q}};\n  };\n  std::function<pm(poly, poly)> hgcd = [&](const poly &p0, const\
    \ poly &p1) {\n    assert(p0.deg() > p1.deg());\n    int m = ((p0.deg() - 1) >>\
    \ 1) + 1, n = p1.deg();\n    if (n < m) return pm{pv{poly{1}, poly{}}, pv{poly{},\
    \ poly{1}}};\n    pm R(hgcd(poly(p0.begin() + m, p0.end()), poly(p1.begin() +\
    \ m, p1.end())));\n    pv ab(mulv(R, pv{p0, p1}));\n    if (ab[1].deg() < m) return\
    \ R;\n    std::pair<poly, poly> qr(ab[0].quorem(ab[1]));\n    int k = 2 * m -\
    \ ab[1].deg();\n    if ((int)qr.second.size() <= k) return mulQ_l(qr.first, R);\n\
    \    return mul(hgcd(poly(ab[1].begin() + k, ab[1].end()),\n                 \
    \   poly(qr.second.begin() + k, qr.second.end())),\n               mulQ_l(qr.first,\
    \ R));\n  };\n  std::function<pm(poly, poly)> cogcd = [&](const poly &p0, const\
    \ poly &p1) {\n    assert(p0.deg() > p1.deg());\n    pm M(hgcd(p0, p1));\n   \
    \ pv p2p3(mulv(M, pv{p0, p1}));\n    if (p2p3[1].deg() == -1) return M;\n    std::pair<poly,\
    \ poly> qr(p2p3[0].quorem(p2p3[1]));\n    if (qr.second.deg() == -1) return mulQ_l(qr.first,\
    \ M);\n    return mul(cogcd(p2p3[1], qr.second), mulQ_l(qr.first, M));\n  };\n\
    \  pm c;\n  if (a.norm().deg() > b.norm().deg()) {\n    c = cogcd(a, b);\n  }\
    \ else {\n    std::pair<poly, poly> qr(a.quorem(b));\n    c = mulQ_r(cogcd(b,\
    \ qr.second), qr.first);\n  }\n  return a * (x = c[0][0]) + b * (y = c[0][1]);\n\
    }\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/Math/extgcd.hpp
  requiredBy: []
  timestamp: '2021-02-03 15:48:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/inv_of_Poly.test.cpp
documentation_of: src/Math/extgcd.hpp
layout: document
redirect_from:
- /library/src/Math/extgcd.hpp
- /library/src/Math/extgcd.hpp.html
title: "\u591A\u9805\u5F0F\u306E\u62E1\u5F35\u4E92\u9664\u6CD5"
---
