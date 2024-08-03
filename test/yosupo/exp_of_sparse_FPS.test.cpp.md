---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/FactorialPrecalculation.hpp
    title: "\u4E8C\u9805\u4FC2\u6570 \u4ED6 (\u968E\u4E57\u524D\u8A08\u7B97) ($\\\
      mathbb{F}_p$)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u6839 ($\\mathbb{F}_p$)"
  - icon: ':question:'
    path: src/Math/sparse_fps.hpp
    title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/NumberTheory/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/yosupo/exp_of_sparse_FPS.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse\"\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n\
    #include <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int\
    \ mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for\
    \ (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b\
    \ * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing i64= long long;\n\
    using u64= unsigned long long;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return l+= r, l < (M) ? l : l\
    \ - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { return l-=\
    \ r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static CE IL U set(U n) { return\
    \ n; } \\\n static CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n)\
    \ { return n; }\ntemplate <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n\
    \ u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)),\
    \ r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l)\
    \ * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n)\
    \ const { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n\
    \  NORM;\n }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n\
    \ static CE u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x *\
    \ (2 - x * n)) : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >>\
    \ B) + mod - ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n\
    \ CE MP_Na(): mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32\
    \ r) const { return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n\
    };\nstruct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0)\
    \ {}\n CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s)\
    \ + m - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r);\
    \ }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE\
    \ IL u64 quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n)\
    \ const { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n\
    \ u64 mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1)\
    \ << 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r);\
    \ }\n PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64\
    \ n) { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64\
    \ n) const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const\
    \ { return (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n -\
    \ quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1():\
    \ s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m),\
    \ d(m << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 2 \"src/Math/sparse_fps.hpp\"\
    \n#include <cstdint>\n#line 5 \"src/Math/FactorialPrecalculation.hpp\"\ntemplate\
    \ <class mod_t> class FactorialPrecalculation {\n static_assert(is_modint_v<mod_t>);\n\
    \ static inline std::vector<mod_t> iv, fct, fiv;\npublic:\n static void reset()\
    \ { iv.clear(), fct.clear(), fiv.clear(); }\n static inline mod_t inv(int n) {\n\
    \  assert(0 < n);\n  if (int k= iv.size(); k <= n) {\n   if (iv.resize(n + 1);\
    \ !k) iv[1]= 1, k= 2;\n   for (int mod= mod_t::mod(), q; k <= n; ++k) q= (mod\
    \ + k - 1) / k, iv[k]= iv[k * q - mod] * q;\n  }\n  return iv[n];\n }\n static\
    \ inline mod_t fact(int n) {\n  assert(0 <= n);\n  if (int k= fct.size(); k <=\
    \ n) {\n   if (fct.resize(n + 1); !k) fct[0]= 1, k= 1;\n   for (; k <= n; ++k)\
    \ fct[k]= fct[k - 1] * k;\n  }\n  return fct[n];\n }\n static inline mod_t finv(int\
    \ n) {\n  assert(0 <= n);\n  if (int k= fiv.size(); k <= n) {\n   if (fiv.resize(n\
    \ + 1); !k) fiv[0]= 1, k= 1;\n   for (; k <= n; ++k) fiv[k]= fiv[k - 1] * inv(k);\n\
    \  }\n  return fiv[n];\n }\n static inline mod_t nPr(int n, int r) { return r\
    \ < 0 || n < r ? mod_t(0) : fact(n) * finv(n - r); }\n // [x^r] (1 + x)^n\n static\
    \ inline mod_t nCr(int n, int r) { return r < 0 || n < r ? mod_t(0) : fact(n)\
    \ * finv(n - r) * finv(r); }\n // [x^r] (1 - x)^{-n}\n static inline mod_t nHr(int\
    \ n, int r) { return !r ? mod_t(1) : nCr(n + r - 1, r); }\n};\n#line 3 \"src/NumberTheory/is_prime.hpp\"\
    \nnamespace math_internal {\ntemplate <class Uint, class MP, u64... args> constexpr\
    \ bool miller_rabin(Uint n) {\n const MP md(n);\n const Uint s= __builtin_ctzll(n\
    \ - 1), d= n >> s, one= md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a:\
    \ {args...})\n  if (Uint b= a % n; b)\n   if (Uint p= md.norm(pow(md.set(b), d,\
    \ md)); p != one)\n    for (int i= s; p != n1; p= md.norm(md.mul(p, p)))\n   \
    \  if (!(--i)) return 0;\n return 1;\n}\nconstexpr bool is_prime(u64 n) {\n if\
    \ (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n if (n < (1 << 30)) return miller_rabin<u32,\
    \ MP_Mo<u32, u64, 32, 31>, 2, 7, 61>(n);\n if (n < (1ull << 62)) return miller_rabin<u64,\
    \ MP_Mo<u64, u128, 64, 63>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    \ return miller_rabin<u64, MP_D2B1, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    }\n}\nusing math_internal::is_prime;\n#line 4 \"src/Math/mod_sqrt.hpp\"\nnamespace\
    \ math_internal {\ntemplate <class Int, class MP> constexpr i64 inner_sqrt(Int\
    \ a, Int p) {\n const MP md(p);\n Int e= (p - 1) >> 1, one= md.set(1);\n if (a=\
    \ md.set(a); md.norm(pow(a, e, md)) != one) return -1;\n Int b= 0, d= md.diff(0,\
    \ a), ret= one, r2= 0, b2= one;\n while (md.norm(pow(d, e, md)) == one) b= md.plus(b,\
    \ one), d= md.diff(md.mul(b, b), a);\n auto mult= [&md, d](Int &u1, Int &u2, Int\
    \ v1, Int v2) {\n  Int tmp= md.plus(md.mul(u1, v1), md.mul(md.mul(u2, v2), d));\n\
    \  u2= md.plus(md.mul(u1, v2), md.mul(u2, v1)), u1= tmp;\n };\n for (++e;; mult(b,\
    \ b2, b, b2)) {\n  if (e & 1) mult(ret, r2, b, b2);\n  if (!(e>>= 1)) return ret=\
    \ md.get(ret), ret * 2 < p ? ret : p - ret;\n }\n}\nconstexpr i64 mod_sqrt(i64\
    \ a, i64 p) {\n assert(p > 0), assert(a >= 0), assert(is_prime(p)), a%= p;\n if\
    \ (a <= 1 || p == 2) return a;\n if (p < (1 << 30)) return inner_sqrt<u32, MP_Mo<u32,\
    \ u64, 32, 31>>(a, p);\n if (p < (1ll << 62)) return inner_sqrt<u64, MP_Mo<u64,\
    \ u128, 64, 63>>(a, p);\n return inner_sqrt<u64, MP_D2B1>(a, p);\n}\n}\nusing\
    \ math_internal::mod_sqrt;\n#line 5 \"src/Math/sparse_fps.hpp\"\nnamespace sfps\
    \ {\nnamespace sfps_internal {\nusing namespace std;\ntemplate <class K> using\
    \ Dat= vector<pair<int, K>>;\ntemplate <class K> Dat<K> to_sfps(const vector<K>&\
    \ f, int b, int N) {\n Dat<K> p;\n for (int e= min<int>(N + 1, f.size()); b <\
    \ e; ++b)\n  if (f[b] != K(0)) p.emplace_back(b, f[b]);\n return p;\n}\n// f/g,\
    \ O(N S_g)\ntemplate <class K> vector<K> div(vector<K> f, const vector<K>& g,\
    \ int N) {\n assert(g[0] != K(0)), f.resize(N + 1);\n auto p= to_sfps(g, 1, N);\n\
    \ const K iv= K(1) / g[0];\n for (int i= 0; i <= N; f[i++]*= iv)\n  for (auto&&\
    \ [j, v]: p) {\n   if (i < j) break;\n   f[i]-= f[i - j] * v;\n  }\n return f;\n\
    }\ntemplate <class mod_t> void pw_mul_pw(mod_t* f, const Dat<mod_t>& p, const\
    \ Dat<mod_t>& q, mod_t a, mod_t b, int N) {\n static_assert(is_modint_v<mod_t>);\n\
    \ vector<mod_t> x(N + 1), y(N);\n f[0]= 1;\n for (int i= 0, k= 1; i < N; i= k++,\
    \ f[i]*= FactorialPrecalculation<mod_t>::inv(i)) {\n  for (auto&& [j, v]: q) {\n\
    \   if (i < j) break;\n   y[i]+= f[i - j] * v;\n  }\n  (y[i]+= f[i])*= a;\n  for\
    \ (auto&& [j, v]: p) {\n   if (k < j) break;\n   x[k]+= v * (y[k - j] * j - x[k\
    \ - j]);\n  }\n  f[k]= x[k];\n  for (auto&& [j, v]: q) {\n   if (k < j) break;\n\
    \   f[k]+= v * (b * j - k) * f[k - j];\n  }\n }\n}\ntemplate <class K> int mn_dg(const\
    \ vector<K>& f) {\n for (int z= 0, e= f.size(); z < e; ++z)\n  if (f[z] != K(0))\
    \ return z;\n return -1;\n}\ntemplate <class mod_t> mod_t pw(mod_t a, int64_t\
    \ k) { return k < 0 ? mod_t(1) / a.pow(-k) : a.pow(k); }\n// f^k (k can be negative),\
    \ O(N S_f)\ntemplate <class mod_t> vector<mod_t> pow(const vector<mod_t>& f, int64_t\
    \ k, int N) {\n vector<mod_t> F(N + 1);\n if (!k) return F[0]= 1, F;\n int x=\
    \ mn_dg(f);\n assert(!(x < 0 && k < 0));\n if (x < 0) return F;\n auto o= __int128_t(x)\
    \ * k;\n if (o > N) return F;\n mod_t p0= f[x], ip= mod_t(1) / p0, a= pw(p0, k);\n\
    \ auto p= to_sfps(f, x + 1, N - o + x);\n for (auto& [j, v]: p) v*= ip, j-= x;\n\
    \ pw_mul_pw<mod_t>(F.data() + o, p, {}, k, 0, N - o);\n for (int i= o; i <= N;\
    \ ++i) F[i]*= a;\n return F;\n}\n// f^k g^l (k, l can be negative), O(N(S_f+S_g))\n\
    template <class mod_t> vector<mod_t> pow_mul_pow(const vector<mod_t>& f, int64_t\
    \ k, const vector<mod_t>& g, int64_t l, int N) {\n if (!k) return pow(g, l, N);\n\
    \ if (!l) return pow(f, k, N);\n int x= mn_dg(f), y= mn_dg(g);\n vector<mod_t>\
    \ F(N + 1);\n assert(!(x < 0 && k < 0)), assert(!(y < 0 && l < 0));\n if (x <\
    \ 0 || y < 0) return F;\n auto o= __int128_t(x) * k + __int128_t(y) * l;\n if\
    \ (assert(o >= 0); o > N) return F;\n mod_t p0= f[x], q0= g[y], ip= mod_t(1) /\
    \ p0, iq= mod_t(1) / q0, a= pw(p0, k) * pw(q0, l);\n auto p= to_sfps(f, x + 1,\
    \ N - o + x), q= to_sfps(g, y + 1, N - o + y);\n for (auto& [j, v]: p) v*= ip,\
    \ j-= x;\n for (auto& [j, v]: q) v*= iq, j-= y;\n pw_mul_pw<mod_t>(F.data() +\
    \ o, p, q, k, l + 1, N - o);\n for (int i= o; i <= N; ++i) F[i]*= a;\n return\
    \ F;\n}\n// \u221A(f/g), O(N(S_f+S_g))\ntemplate <class mod_t> vector<mod_t> sqrt_of_div(const\
    \ vector<mod_t>& f, const vector<mod_t>& g, int N) {\n int x= mn_dg(f), y= mn_dg(g),\
    \ o= (x - y) >> 1;\n vector<mod_t> F(N + 1);\n if (assert(y >= 0); x < 0) return\
    \ F;\n if (assert(x >= y); (x - y) & 1) return {};  // no solution\n mod_t p0=\
    \ f[x], ip= mod_t(1) / p0, iq= mod_t(1) / g[y], a= mod_sqrt(p0 * iq, mod_t::mod()),\
    \ i2= mod_t(1) / 2;\n auto p= to_sfps(f, x + 1, N - o + x), q= to_sfps(g, y +\
    \ 1, N - o + y);\n for (auto& [j, v]: p) v*= ip, j-= x;\n for (auto& [j, v]: q)\
    \ v*= iq, j-= y;\n pw_mul_pw<mod_t>(F.data() + o, p, q, i2, -i2 + 1, N - o);\n\
    \ for (int i= o; i <= N; ++i) F[i]*= a;\n return F;\n}\n// log(f), O(N S_f)\n\
    template <class mod_t> vector<mod_t> log(vector<mod_t> f, int N) {\n assert(f[0]\
    \ == mod_t(1));\n auto p= to_sfps(f, 1, N);\n f.resize(N + 1);\n for (int i= 1;\
    \ i <= N; ++i, f[i]*= i)\n  for (auto&& [j, v]: p) {\n   if (i <= j) break;\n\
    \   f[i]-= f[i - j] * v;\n  }\n for (int i= 2; i <= N; ++i) f[i]*= FactorialPrecalculation<mod_t>::inv(i);\n\
    \ return f[0]= 0, f;\n}\n// exp(f/g), O(N(S_f+S_g))\ntemplate <class mod_t> vector<mod_t>\
    \ exp_of_div(const vector<mod_t>& f, const vector<mod_t>& g, int N) {\n int x=\
    \ mn_dg(f), y= mn_dg(g);\n assert(y >= 0), assert(x < 0 || x > y);\n auto p= to_sfps(f,\
    \ 0, N + y), q= to_sfps(g, y + 1, N + y);\n mod_t iv= mod_t(1) / g[y];\n for (auto&\
    \ [j, v]: p) v*= iv, j-= y;\n for (auto& [j, v]: q) v*= iv, j-= y;\n vector<mod_t>\
    \ F(N + 1), dF(N), a(N), b(N);\n F[0]= 1;\n for (int i= 0; i < N; ++i) {\n  for\
    \ (auto&& [j, v]: p) {\n   if (i < j) break;\n   b[i]+= v * F[i - j];\n  }\n \
    \ for (auto&& [j, v]: q) {\n   if (i < j) break;\n   a[i]-= v * (a[i - j] + b[i\
    \ + 1 - j] * j);\n   dF[i]-= v * dF[i - j];\n  }\n  for (auto&& [j, v]: p) {\n\
    \   if (i + 1 < j) break;\n   dF[i]+= v * j * F[i + 1 - j];\n  }\n  F[i + 1]=\
    \ (dF[i]+= a[i]) * FactorialPrecalculation<mod_t>::inv(i + 1);\n }\n return F;\n\
    }\n}\nusing sfps_internal::div, sfps_internal::pow, sfps_internal::pow_mul_pow,\
    \ sfps_internal::pow_mul_pow, sfps_internal::sqrt_of_div, sfps_internal::log,\
    \ sfps_internal::exp_of_div;\n// 1/f, O(N S_f)\ntemplate <class K> std::vector<K>\
    \ inv(const std::vector<K>& f, int N) { return div<K>({1}, f, N); }\n// (f/g)^k\
    \ (k can be negative), O(N(S_f+S_g))\ntemplate <class mod_t> std::vector<mod_t>\
    \ pow_of_div(const std::vector<mod_t>& f, const std::vector<mod_t>& g, int64_t\
    \ k, int N) { return pow_mul_pow(f, k, g, -k, N); }\n// \u221Af, O(N S_f)\ntemplate\
    \ <class mod_t> std::vector<mod_t> sqrt(const std::vector<mod_t>& f, int N) {\
    \ return sqrt_of_div<mod_t>(f, {1}, N); }\n// exp(f), O(N S_f)\ntemplate <class\
    \ mod_t> std::vector<mod_t> exp(const std::vector<mod_t>& f, int N) { return exp_of_div<mod_t>(f,\
    \ {1}, N); }\n}\n#line 6 \"test/yosupo/exp_of_sparse_FPS.test.cpp\"\nusing namespace\
    \ std;\nint main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint=\
    \ ModInt<998244353>;\n long long N, K;\n cin >> N >> K;\n vector<Mint> a(N);\n\
    \ for (int i; K--;) cin >> i >> a[i];\n auto ans= sfps::exp(a, N - 1);\n for (int\
    \ i= 0; i < N; i++) cout << ans[i] << \" \\n\"[i == N - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/Math/ModInt.hpp\"\n#include\
    \ \"src/Math/sparse_fps.hpp\"\nusing namespace std;\nint main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(false);\n using Mint= ModInt<998244353>;\n long long N,\
    \ K;\n cin >> N >> K;\n vector<Mint> a(N);\n for (int i; K--;) cin >> i >> a[i];\n\
    \ auto ans= sfps::exp(a, N - 1);\n for (int i= 0; i < N; i++) cout << ans[i] <<\
    \ \" \\n\"[i == N - 1];\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/sparse_fps.hpp
  - src/Math/FactorialPrecalculation.hpp
  - src/Math/mod_sqrt.hpp
  - src/NumberTheory/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/exp_of_sparse_FPS.test.cpp
  requiredBy: []
  timestamp: '2024-02-05 22:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/exp_of_sparse_FPS.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/exp_of_sparse_FPS.test.cpp
- /verify/test/yosupo/exp_of_sparse_FPS.test.cpp.html
title: test/yosupo/exp_of_sparse_FPS.test.cpp
---
