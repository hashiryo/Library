---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u6839 ($\\mathbb{F}_p$)"
  - icon: ':question:'
    path: src/Math/sparse_fps.hpp
    title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/yosupo/inv_of_sparse_FPS.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse\"\n\
    #include <bits/stdc++.h>\n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int>\
    \ constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y=\
    \ z - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\n\
    struct m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t>\
    \ CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64 MOD>\
    \ struct SB: s_b {\nprotected:\n static CE mpt md= mpt(MOD);\n};\ntemplate <class\
    \ mpt, int id> struct RB: r_b {\n static inline void set_mod(u64 m) { md= mpt(m);\
    \ }\nprotected:\n static inline mpt md;\n};\ntemplate <class Int, class U, class\
    \ B> struct MInt: public B {\n using Uint= U;\n static CE inline auto mod() {\
    \ return B::md.mod; }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n\
    \ template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T\
    \ v): x(B::md.set(v.val() % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod\
    \ - (-n) % B::md.mod : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
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
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using StaticModInt=\
    \ conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>, MOD>>, conditional_t<MOD&(MOD\
    \ < LLONG_MAX), MInt<i64, u64, SB<MP_Mo, MOD>>, MInt<i64, u64, SB<MP_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id= -1> using RuntimeModInt=\
    \ conditional_t<is_same_v<Int, Montgomery>, MInt<i64, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ i64>, is_same<Int, u64>>, MInt<i64, u64, RB<MP_Na<u64>, id>>, MInt<int, u32,\
    \ RB<MP_Na<u32>, id>>>>;\n#undef CE\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Montgomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LIM> mod_t\
    \ get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m=\
    \ mod_t::mod();\n static mod_t dat[LIM];\n static int l= 1;\n if (l == 1) dat[l++]=\
    \ 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n\
    #line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate <class\
    \ Uint, class mod_pro_t, u64... args> constexpr bool miller_rabin(Uint n) {\n\
    \ const mod_pro_t md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one=\
    \ md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...}) {\n  Uint b=\
    \ a % n, p= pow(md.set(b), d, md), i= s;\n  while (p= md.norm(p), (p != one &&\
    \ p != n1 && b && i--)) p= md.mul(p, p);\n  if (md.norm(p) != n1 && i != s) return\
    \ 0;\n }\n return true;\n}\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n\
    \ % 6 % 4 != 1) return (n | 1) == 3;\n if (n < UINT_MAX) return miller_rabin<u32,\
    \ MP_Na<u32>, 2, 7, 61>(n);\n if (n < LLONG_MAX) return miller_rabin<u64, MP_Mo,\
    \ 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64,\
    \ MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing\
    \ math_internal::is_prime;\n#line 4 \"src/Math/mod_sqrt.hpp\"\nnamespace math_internal\
    \ {\ntemplate <class Int, class mod_pro_t> constexpr int64_t inner_sqrt(Int a,\
    \ Int p) {\n const mod_pro_t md(p);\n Int e= (p - 1) >> 1, one= md.set(1);\n if\
    \ (a= md.set(a); md.norm(pow(a, e, md)) != one) return -1;\n Int b= 0, d= md.diff(0,\
    \ a), ret= one, r2= 0, b2= one;\n while (md.norm(pow(d, e, md)) == one) b= md.plus(b,\
    \ one), d= md.diff(md.mul(b, b), a);\n auto mult= [&md, d](Int &u1, Int &u2, Int\
    \ v1, Int v2) {\n  Int tmp= md.plus(md.mul(u1, v1), md.mul(md.mul(u2, v2), d));\n\
    \  u2= md.plus(md.mul(u1, v2), md.mul(u2, v1)), u1= tmp;\n };\n for (++e;; mult(b,\
    \ b2, b, b2)) {\n  if (e & 1) mult(ret, r2, b, b2);\n  if (!(e>>= 1)) return ret=\
    \ md.get(ret), ret * 2 < p ? ret : p - ret;\n }\n}\nconstexpr int64_t mod_sqrt(int64_t\
    \ a, int64_t p) {\n assert(p > 0), assert(a >= 0), assert(is_prime(p)), a%= p;\n\
    \ if (a <= 1 || p == 2) return a;\n if (p < INT_MAX) return inner_sqrt<u32, MP_Na<u32>>(a,\
    \ p);\n return inner_sqrt<u64, MP_Mo>(a, p);\n}\n}\nusing math_internal::mod_sqrt;\n\
    #line 5 \"src/Math/sparse_fps.hpp\"\ntemplate <class K> std::vector<K> sparse_inv(const\
    \ std::vector<K> &f, int n) {\n assert(f[0] != K(0));\n std::vector<std::pair<int,\
    \ K>> dat;\n for (int i= 1, ed= std::min<int>(n, f.size()); i < ed; i++)\n  if\
    \ (f[i] != K(0)) dat.emplace_back(i, f[i]);\n std::vector<K> ret(n);\n const K\
    \ iv= ret[0]= K(1) / f[0];\n for (int i= 1; i < n; ret[i++]*= iv)\n  for (auto\
    \ &&[j, v]: dat) {\n   if (i < j) break;\n   ret[i]-= ret[i - j] * v;\n  }\n return\
    \ ret;\n}\ntemplate <class K> std::vector<K> sparse_div(std::vector<K> f, const\
    \ std::vector<K> &g, int n) {\n assert(g[0] != K(0));\n std::vector<std::pair<int,\
    \ K>> dat;\n for (int i= 1, ed= std::min<int>(n, g.size()); i < ed; i++)\n  if\
    \ (g[i] != K(0)) dat.emplace_back(i, g[i]);\n f.resize(n);\n const K iv= K(1)\
    \ / g[0];\n for (int i= 0; i < n; f[i++]*= iv)\n  for (auto &&[j, v]: dat) {\n\
    \   if (i < j) break;\n   f[i]-= f[i - j] * v;\n  }\n return f;\n}\ntemplate <class\
    \ mod_t, std::size_t _Nm= 1 << 24> std::vector<mod_t> sparse_log(const std::vector<mod_t>\
    \ &f, int n) {\n assert(f[0] == mod_t(1));\n std::vector<mod_t> df(n - 1);\n for\
    \ (int i= 1, ed= std::min<int>(n, f.size()); i < ed; i++) df[i - 1]+= f[i] * i;\n\
    \ df= sparse_div(df, f, n - 1);\n std::vector<mod_t> ret(n);\n for (int i= 1;\
    \ i < n; i++) ret[i]= df[i - 1] * get_inv<mod_t, _Nm>(i);\n return ret;\n}\ntemplate\
    \ <class mod_t, std::size_t _Nm= 1 << 24> std::vector<mod_t> sparse_exp(const\
    \ std::vector<mod_t> &f, int n) {\n assert(f[0] == mod_t(0));\n std::vector<std::pair<int,\
    \ mod_t>> dat;\n for (int i= 1, ed= std::min<int>(n, f.size()); i < ed; i++)\n\
    \  if (f[i] != mod_t(0)) dat.emplace_back(i - 1, f[i] * i);\n std::vector<mod_t>\
    \ ret(n);\n ret[0]= 1;\n for (int i= 1; i < n; ret[i]*= get_inv<mod_t, _Nm>(i),\
    \ i++)\n  for (auto &&[j, v]: dat) {\n   if (i <= j) break;\n   ret[i]+= ret[i\
    \ - 1 - j] * v;\n  }\n return ret;\n}\ntemplate <class mod_t, std::size_t _Nm=\
    \ 1 << 24> std::vector<mod_t> sparse_pow(const std::vector<mod_t> &f, std::uint64_t\
    \ k, int n) {\n std::vector<mod_t> ret(n);\n if (k == 0) return ret[0]= 1, ret;\n\
    \ int cnt= 0, ed= std::min<int>(n, f.size());\n while (cnt < ed && f[cnt] == mod_t(0))\
    \ cnt++;\n const __int128_t ofs= (__int128_t)k * cnt, sz= n - ofs;\n if (sz <=\
    \ 0) return ret;\n std::vector<std::pair<int, mod_t>> dat;\n for (int i= cnt +\
    \ 1; i < ed; i++)\n  if (f[i] != mod_t(0)) dat.emplace_back(i - cnt, f[i]);\n\
    \ mod_t *bf= ret.data() + k * cnt, mk= k, iv= mod_t(1) / f[cnt];\n bf[0]= f[cnt].pow(k);\n\
    \ for (int i= 1; i < sz; bf[i]*= get_inv<mod_t, _Nm>(i) * iv, i++)\n  for (auto\
    \ &&[j, v]: dat) {\n   if (i < j) break;\n   bf[i]+= v * (mk * j - (i - j)) *\
    \ bf[i - j];\n  }\n return ret;\n}\ntemplate <class mod_t, std::size_t _Nm= 1\
    \ << 24> std::vector<mod_t> sparse_sqrt(const std::vector<mod_t> &f, int n) {\n\
    \ std::vector<mod_t> ret(n);\n int cnt= 0, ed= std::min<int>(n, f.size());\n while\
    \ (cnt < ed && f[cnt] == mod_t(0)) cnt++;\n if (cnt == ed) return ret;\n if (cnt\
    \ & 1) return {};  // no solution\n const int ofs= cnt >> 1, sz= n - ofs;\n std::vector<std::pair<int,\
    \ mod_t>> dat;\n for (int i= cnt + 1; i < ed; i++)\n  if (f[i] != mod_t(0)) dat.emplace_back(i\
    \ - cnt, f[i]);\n mod_t *bf= ret.data() + ofs, mk= mod_t(1) / 2, iv= mod_t(1)\
    \ / f[cnt];\n bf[0]= mod_sqrt(f[cnt].val(), mod_t::mod());\n if (bf[0] * bf[0]\
    \ != f[cnt]) return {};  // no solution\n for (int i= 1; i < sz; bf[i]*= get_inv<mod_t,\
    \ _Nm>(i) * iv, i++)\n  for (auto &&[j, v]: dat) {\n   if (i < j) break;\n   bf[i]+=\
    \ v * (mk * j - (i - j)) * bf[i - j];\n  }\n return ret;\n}\n// F'/F = f(x)/g(x),\
    \ F[0]=1\ntemplate <class mod_t, std::size_t _Nm= 1 << 24> std::vector<mod_t>\
    \ sparse_log_differentiation(const std::vector<mod_t> &f, const std::vector<mod_t>\
    \ &g, int n) {\n assert(g[0] == mod_t(1));\n std::vector<std::pair<int, mod_t>>\
    \ dat_f, dat_g;\n for (int i= 0, ed= std::min<int>(f.size(), n); i < ed; i++)\n\
    \  if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n for (int i= 1, ed= std::min<int>(g.size(),\
    \ n); i < ed; i++)\n  if (g[i] != mod_t(0)) dat_g.emplace_back(i, g[i]);\n std::vector<mod_t>\
    \ ret(n), d(n - 1);\n ret[0]= 1;\n for (int i= 0; i < n - 1; i++) {\n  for (auto\
    \ &&[j, v]: dat_g) {\n   if (i < j) break;\n   d[i]-= v * d[i - j];\n  }\n  for\
    \ (auto &&[j, v]: dat_f) {\n   if (i < j) break;\n   d[i]+= v * ret[i - j];\n\
    \  }\n  ret[i + 1]= d[i] * get_inv<mod_t, _Nm>(i + 1);\n }\n return ret;\n}\n\
    template <class mod_t, std::size_t _Nm= 1 << 24>  // exp(f/g)\nstd::vector<mod_t>\
    \ sparse_exp_of_div(const std::vector<mod_t> &f, const std::vector<mod_t> &g,\
    \ int n) {\n assert(f[0] == mod_t(0)), assert(g[0] == mod_t(1));\n std::vector<std::pair<int,\
    \ mod_t>> dat_f, dat_g;\n for (int i= 1, ed= std::min<int>(f.size(), n); i < ed;\
    \ i++)\n  if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n for (int i= 0,\
    \ ed= std::min<int>(g.size(), n); i < ed; i++)\n  if (g[i] != mod_t(0)) dat_g.emplace_back(i,\
    \ g[i]);\n std::vector<mod_t> a(f.size() + g.size() - 2), b(2 * g.size() - 1);\n\
    \ for (auto &&[i, x]: dat_f)\n  for (auto &&[j, y]: dat_g) a[i + j - 1]+= x *\
    \ y * (i - j);\n for (auto &&[i, x]: dat_g)\n  for (auto &&[j, y]: dat_g) b[i\
    \ + j]+= x * y;  // a = f'g-fg', b = g^2\n return sparse_log_differentiation<mod_t,\
    \ _Nm>(a, b, n);\n}\ntemplate <class mod_t, std::size_t _Nm= 1 << 24>  // (f/g)^k\n\
    std::vector<mod_t> sparse_pow_of_div(const std::vector<mod_t> &f, const std::vector<mod_t>\
    \ &g, std::uint64_t k, int n) {\n assert(f[0] == mod_t(1)), assert(g[0] == mod_t(1));\n\
    \ std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n for (int i= 0, ed= std::min<int>(f.size(),\
    \ n); i < ed; i++)\n  if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n for\
    \ (int i= 0, ed= std::min<int>(g.size(), n); i < ed; i++)\n  if (g[i] != mod_t(0))\
    \ dat_g.emplace_back(i, g[i]);\n std::vector<mod_t> a(f.size() + g.size() - 2),\
    \ b(2 * g.size() - 1);\n for (auto &&[i, x]: dat_f)\n  for (auto &&[j, y]: dat_g)\
    \ a[i + j - 1]+= x * y * (i - j) * k;\n for (auto &&[i, x]: dat_f)\n  for (auto\
    \ &&[j, y]: dat_g) b[i + j]+= x * y;  // a = k(f'g-fg'), b = fg\n return sparse_log_differentiation<mod_t,\
    \ _Nm>(a, b, n);\n}\n#line 6 \"test/yosupo/inv_of_sparse_FPS.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = StaticModInt<998244353>;\n  long long N, K;\n  cin >> N >> K;\n\
    \  vector<Mint> a(N);\n  while (K--) {\n    int i;\n    cin >> i;\n    cin >>\
    \ a[i];\n  }\n  auto ans = sparse_inv(a, N);\n  for (int i = 0; i < N; i++) cout\
    \ << ans[i] << \" \\n\"[i == N - 1];\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/sparse_fps.hpp\"\
    \nusing namespace std;\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = StaticModInt<998244353>;\n  long long N, K;\n  cin >> N >> K;\n\
    \  vector<Mint> a(N);\n  while (K--) {\n    int i;\n    cin >> i;\n    cin >>\
    \ a[i];\n  }\n  auto ans = sparse_inv(a, N);\n  for (int i = 0; i < N; i++) cout\
    \ << ans[i] << \" \\n\"[i == N - 1];\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/sparse_fps.hpp
  - src/Math/mod_sqrt.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/inv_of_sparse_FPS.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 22:12:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/inv_of_sparse_FPS.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/inv_of_sparse_FPS.test.cpp
- /verify/test/yosupo/inv_of_sparse_FPS.test.cpp.html
title: test/yosupo/inv_of_sparse_FPS.test.cpp
---
