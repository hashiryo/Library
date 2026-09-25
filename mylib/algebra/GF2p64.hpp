#pragma once
#ifdef __x86_64__
#include <immintrin.h>
#else
#include <simde/x86/avx2.h>
#include <simde/x86/clmul.h>
#include <simde/x86/bmi.h>
#endif
#include <utility>
#include "include/debug.hpp"
namespace gf2p64_internal {
using u64= unsigned long long;
using u32= unsigned;
using u8= unsigned char;
inline constexpr u64 apply(const u64 t[8][256], u64 a) { return t[0][u8(a)] ^ t[1][u8(a >> 8)] ^ t[2][u8(a >> 16)] ^ t[3][u8(a >> 24)] ^ t[4][u8(a >> 32)] ^ t[5][u8(a >> 40)] ^ t[6][u8(a >> 48)] ^ t[7][u8(a >> 56)]; }
struct Frob {
 u64 g[64], t[8][256];
};
constexpr Frob expand(u64 b[64]) {
 Frob f{};
 for(int i= 0; i < 64; ++i) f.g[i]= b[i];
 for(int p= 0; p < 8; ++p)
  for(int j= 0; j < 8; ++j) {
   const u64 v= f.g[8 * p + j];
   const int half= 1 << j;
   for(int b= 0; b < half; ++b) f.t[p][half + b]= f.t[p][b] ^ v;
  }
 return f;
}
constexpr Frob compose(const Frob& hi, const Frob& lo) {
 u64 g[64]= {1};
 for(int i= 0; i < 64; ++i) g[i]= apply(hi.t, lo.g[i]);
 return expand(g);
}
constexpr Frob make_frob1() {
 u64 g[64]= {1};
 for(int i= 1; i < 32; ++i) g[i]= u64(1) << (i * 2);
 for(int i= 32; i < 62; ++i) g[i]= u64(27) << ((i - 32) * 2);
 g[62]= 0xB00000000000001B, g[63]= 0xC00000000000005A;
 return expand(g);
};
constexpr Frob F1= make_frob1();
constexpr Frob F2= compose(F1, F1);
constexpr Frob F3= compose(F2, F1);
constexpr Frob F4= compose(F2, F2);
constexpr Frob F5= compose(F4, F1);
constexpr Frob F6= compose(F4, F2);
constexpr Frob F7= compose(F4, F3);
constexpr Frob F8= compose(F4, F4);
constexpr Frob F15= compose(F8, F7);
constexpr Frob F16= compose(F8, F8);
constexpr Frob F32= compose(F16, F16);
constexpr Frob F48= compose(F32, F16);
constexpr Frob F63= compose(F48, F15);
inline u64 mul(u64 a, u64 b) {
 static constexpr u8 RED[]= {0, 27, 45, 54, 90, 65, 119, 108};
 __m128i v= _mm_clmulepi64_si128(_mm_cvtsi64_si128(a), _mm_cvtsi64_si128(b), 0);
 u64 h= v[1], d= h ^ (h << 1);
 return v[0] ^ RED[h >> 60] ^ d ^ (d << 3);
}
inline u64 sq(u64 a) {
 static constexpr u8 RED_SQ[4]= {0, 27, 90, 65};
 const __m128i MASK_LO= _mm_set1_epi8(0x0F);
 const __m128i SPR= _mm_setr_epi8(0x00, 0x03, 0x0C, 0x0F, 0x30, 0x33, 0x3C, 0x3F, (char)0xC0, (char)0xC3, (char)0xCC, (char)0xCF, (char)0xF0, (char)0xF3, (char)0xFC, (char)0xFF);
 __m128i v= _mm_set_epi64x(0, a);
 __m128i x= _mm_shuffle_epi8(SPR, _mm_and_si128(_mm_unpacklo_epi8(v, _mm_srli_epi16(v, 4)), MASK_LO));
 u64 d= x[1];
 return (x[0] & 0x5555555555555555) ^ RED_SQ[a >> 62] ^ d ^ (d << 3);
}
template <bool VPCLMUL= 1, int IMM= 0> inline __m256i mul2(const __m256i& a_vec, const __m256i& b_vec) {
 const __m256i RED256= _mm256_setr_epi8(0, 27, 45, 54, 90, 65, 119, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 45, 54, 90, 65, 119, 108, 0, 0, 0, 0, 0, 0, 0, 0);
 __m256i prod;
 if constexpr(VPCLMUL) prod= _mm256_clmulepi64_epi128(a_vec, b_vec, IMM);
 else prod= _mm256_setr_m128i(_mm_clmulepi64_si128(_mm256_castsi256_si128(a_vec), _mm256_castsi256_si128(b_vec), IMM), _mm_clmulepi64_si128(_mm256_extracti128_si256(a_vec, 1), _mm256_extracti128_si256(b_vec, 1), IMM));
 __m256i h= _mm256_srli_si256(prod, 8);
 __m256i d= _mm256_xor_si256(h, _mm256_slli_epi64(h, 1));
 return _mm256_xor_si256(_mm256_xor_si256(prod, _mm256_shuffle_epi8(RED256, _mm256_srli_epi64(h, 60))), _mm256_xor_si256(d, _mm256_slli_epi64(d, 3)));
}
inline std::pair<u64, u64> unpack(const __m256i& vec) { return std::make_pair(u64(_mm256_extract_epi64(vec, 0)), u64(_mm256_extract_epi64(vec, 2))); }
class GF2p64 {
 u64 x;
public:
 GF2p64(): x(0) {}
 GF2p64(u64 y): x(y) {}
 auto operator<=>(const GF2p64&) const= default;
 GF2p64& operator+=(GF2p64 r) { return x^= r.x, *this; }
 GF2p64& operator-=(GF2p64 r) { return x^= r.x, *this; }
 GF2p64& operator*=(GF2p64 r) { return x= mul(x, r.x), *this; }
 GF2p64 operator+(GF2p64 r) const { return GF2p64(x ^ r.x); }
 GF2p64 operator-(GF2p64 r) const { return GF2p64(x ^ r.x); }
 GF2p64 operator*(GF2p64 r) const { return GF2p64(mul(x, r.x)); }
 GF2p64 square() const { return GF2p64(sq(x)); }
 GF2p64 sqrt() const { return GF2p64(apply(F63.t, x)); }
 explicit operator u64() const { return x; }
 explicit operator bool() const { return x != 0; }
};
}
using gf2p64_internal::GF2p64;
