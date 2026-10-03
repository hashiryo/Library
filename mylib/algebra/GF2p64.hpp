#pragma once
#ifdef __x86_64__
#include <immintrin.h>
#else
#include <simde/x86/avx2.h>
#include <simde/x86/clmul.h>
#include <simde/x86/bmi.h>
#endif
#include <tuple>
#include <utility>
#include <type_traits>
#include <iostream>
#include <cassert>
#include "include/debug.hpp"
namespace gf2p64_internal {
using u64= unsigned long long;
using u32= unsigned;
using u16= unsigned short;
using u8= unsigned char;
struct LinMap {
 u64 g[64], t[8][256];
 constexpr LinMap(const u64 b[64]): g{}, t{} {
  for(int i= 0; i < 64; ++i) {
   g[i]= b[i];
   u64* l= t[i >> 3];
   for(u8 h= 1 << (i & 7), b= h; b--;) l[h | b]= l[b] ^ g[i];
  }
 }
 inline constexpr u64 operator()(u64 a) const { return t[0][u8(a)] ^ t[1][u8(a >> 8)] ^ t[2][u8(a >> 16)] ^ t[3][u8(a >> 24)] ^ t[4][u8(a >> 32)] ^ t[5][u8(a >> 40)] ^ t[6][u8(a >> 48)] ^ t[7][u8(a >> 56)]; }
 constexpr LinMap operator*(const LinMap& r) const {
  u64 h[64]= {};
  for(int i= 0; i < 64; ++i) h[i]= (*this)(r.g[i]);
  return LinMap(h);
 }
};
constexpr u64 TO_NIM_B[64]= {0x0000000000000001, 0x5211145c804b6109, 0x7c8bc2cad259879f, 0x565854b4c60c1e0b, 0x4068acf7104c20c3, 0x662d2bd0f2739155, 0x7a90c83701fa8323, 0x21cfa750247e8755, 0x67d1044e545abf47, 0x4d9d3b5a8568f839, 0x567a9d7331b6b3c6, 0x1ca54bfdd6d1ae59, 0x454fa483275db25c, 0x6766df6fec4e9d44, 0x35cb621cec1fe7f9, 0x4c606d3e52faf263, 0x57640dc825a57954, 0x7aca87838b7f6315, 0x6d53c884ebf2b0ed, 0x3721d998bb50164b, 0x7aa7c62fd6cd53ab, 0x47cbb2c51f7c040f, 0x132063b7f5e42489, 0x0c1b36c8b2993f8a, 0x60119ecff680497a, 0x5175da444cc11791, 0x5792ff4554765b09, 0x0c9fdb8a01334e82, 0x2be0a763a68a4725, 0x3c2dc8260ad051f6, 0x6c4c9fed8816bb9c, 0x630062753ffaf766,
                             0x7b37d31b5d519225, 0x2364f7f79705691c, 0x453eb8a83e2fec71, 0x7c0121b37e828666, 0x59190d3250e66011, 0x103207f9dda18cae, 0x28233dce01c69b76, 0x4fa519899227a5e7, 0x4567ba46ee7bc6cd, 0x0a284773d021afd5, 0x63894079bbe3a824, 0x11013c7fdfaaa5c2, 0x1aa984f18574f3b0, 0x0cbaba126fd0c4db, 0x0b8797719e6dc725, 0x4a2845680aefaa72, 0x536d2535f6934e15, 0x01db7a57effcd689, 0x7e1ed0ad01e2a5ad, 0x0aedc9b3cee826f6, 0x7ba716eccf9f68e1, 0x5d5e23bc0f3dc38f, 0x0b5f2a3b88674d83, 0x2de9bafc2f00f8d4, 0x3b56712ad419c7e0, 0x3ab4be8c30c19253, 0x2708522ffaa654b0, 0x2b8bca57bf643598, 0x588825d1a5fa8e1c, 0x86adf8bf4d45962f, 0x51b4c15d8719dd73, 0xe4a2b3b59783d0aa};
constexpr u64 FROM_NIM_B[64]= {0x0000000000000001, 0x19c9369f278adc02, 0xa181e7d66f5ff795, 0x5db84357ce785d09, 0xa0bae2f9d2430cc8, 0xb7ea5a9705b771c0, 0xba4f3cd82801769d, 0x4886cde01b8241d0, 0x0a6f43f2aaf612ed, 0xebd0142f98030a32, 0xa81f89cda43f3792, 0xe99aec6b66ccb814, 0xa69d1ff025fc2f82, 0x48a81132d25db068, 0x4a900f9dcaa9644f, 0xe5ce4ea88259972a, 0xf7094c336029f04c, 0xe191dde287bc9c6b, 0xaacaff12bff239b8, 0x49bc5212be1bc1ca, 0xfe57defb454446cf, 0xa1dffcf944bdf6a7, 0xb9f1bdb5cee941ee, 0x12e5e889275c22de, 0x5bcb6b117b77eeed, 0x03eb1ab59d05ae4b, 0x02a25d7076ddd386, 0x53164a606c612245, 0xebb33f5822f66059, 0xe9be765f5747b93e, 0x552a78df373a354f, 0xbcf5ac65f31fb8bf,
                               0xe411e728becdc77b, 0xf35c26d7b57cdca6, 0x4499da83de4ca5f7, 0x40ab25bdca4ae226, 0xee004b6f1dff7218, 0x0d122da9821c5b41, 0x51fbfcb058120efe, 0xa148b1fa84905b22, 0xbb8ed3e647604d8d, 0xe2d93fef2472776f, 0x4c17a2541a10e6b5, 0x1d879e08903708e7, 0x0fbe7d0d1934da90, 0x5bf977d9c6f61d30, 0x06832fc918260412, 0x0fe22e843ebf73e3, 0x4d7ef4e4fa28d60d, 0x402250d979afbed5, 0x067902b8c8ca2d4f, 0xf38d113fe1d6bb16, 0x414f0248b02b5b7d, 0xf041922915824ce9, 0x11a72fb5e30c93d9, 0x12e54f4d63102aee, 0xbc46ac14b3141c6c, 0x1f172b3c16c645bb, 0x584b492ed4e8fa6c, 0x00a852e9a32cc133, 0xa180861bce00a45e, 0xa194b6bcb4645fb9, 0x4509002ad808a4fb, 0xc5172a0055602f69};
constexpr LinMap TO_NIM= LinMap(TO_NIM_B);
constexpr LinMap FROM_NIM= LinMap(FROM_NIM_B);
constexpr LinMap F1= []() {
 u64 g[64]= {1};
 for(int i= 32; --i;) g[i]= u64(1) << (i * 2);
 for(int i= 62; i-- > 32;) g[i]= u64(27) << ((i - 32) * 2);
 g[62]= 0xb00000000000001b, g[63]= 0xc00000000000005a;
 return LinMap(g);
}();
constexpr LinMap F2= F1 * F1;
constexpr LinMap F3= F2 * F1;
constexpr LinMap F4= F2 * F2;
constexpr LinMap F7= F4 * F3;
constexpr LinMap F8= F4 * F4;
constexpr LinMap F15= F8 * F7;
constexpr LinMap F16= F8 * F8;
constexpr LinMap F32= F16 * F16;
constexpr LinMap F48= F32 * F16;
constexpr LinMap F63= F48 * F15;
inline u64 mul(u64 a, u64 b) {
 static constexpr u8 RED[]= {0, 27, 45, 54, 90, 65, 119, 108};
 __m128i v= _mm_clmulepi64_si128(_mm_cvtsi64_si128(a), _mm_cvtsi64_si128(b), 0);
 u64 h= v[1], d= h ^ (h << 1);
 return v[0] ^ RED[h >> 60] ^ d ^ (d << 3);
}
inline u64 sq(u64 a) {
 static constexpr u8 RED_SQ[4]= {0, 27, 90, 65};
 const __m128i MASK_LO= _mm_set1_epi8(0x0f);
 const __m128i SPR= _mm_setr_epi8(0x00, 0x03, 0x0c, 0x0f, 0x30, 0x33, 0x3c, 0x3f, (char)0xc0, (char)0xc3, (char)0xcc, (char)0xcf, (char)0xf0, (char)0xf3, (char)0xfc, (char)0xff);
 __m128i v= _mm_set_epi64x(0, a);
 __m128i x= _mm_shuffle_epi8(SPR, _mm_and_si128(_mm_unpacklo_epi8(v, _mm_srli_epi16(v, 4)), MASK_LO));
 u64 d= x[1];
 return (x[0] & 0x5555555555555555) ^ RED_SQ[a >> 62] ^ d ^ (d << 3);
}
template <bool V, int IMM= 0> inline __m256i mul2(const __m256i& a_vec, const __m256i& b_vec) {
 const __m256i RED256= _mm256_setr_epi8(0, 27, 45, 54, 90, 65, 119, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 45, 54, 90, 65, 119, 108, 0, 0, 0, 0, 0, 0, 0, 0);
 __m256i prod;
 if constexpr(V) prod= _mm256_clmulepi64_epi128(a_vec, b_vec, IMM);
 else prod= _mm256_setr_m128i(_mm_clmulepi64_si128(_mm256_castsi256_si128(a_vec), _mm256_castsi256_si128(b_vec), IMM), _mm_clmulepi64_si128(_mm256_extracti128_si256(a_vec, 1), _mm256_extracti128_si256(b_vec, 1), IMM));
 __m256i h= _mm256_srli_si256(prod, 8);
 __m256i d= _mm256_xor_si256(h, _mm256_slli_epi64(h, 1));
 return _mm256_xor_si256(_mm256_xor_si256(prod, _mm256_shuffle_epi8(RED256, _mm256_srli_epi64(h, 60))), _mm256_xor_si256(d, _mm256_slli_epi64(d, 3)));
}
inline std::pair<u64, u64> unpack(const __m256i& vec) { return std::make_pair(u64(_mm256_extract_epi64(vec, 0)), u64(_mm256_extract_epi64(vec, 2))); }
template <bool VPCLMUL= 1> inline u64 pw(u64 a, u64 e) {
 u64 t[16]= {1, a, sq(a)};
 __m256i t12= _mm256_set_epi64x(0, t[2], 0, a);
 __m256i t34= mul2<VPCLMUL>(t12, _mm256_set1_epi64x(t[2]));
 std::tie(t[3], t[4])= unpack(t34);
 __m256i t4= _mm256_set1_epi64x(t[4]);
 __m256i t56= mul2<VPCLMUL>(t4, t12);
 std::tie(t[5], t[6])= unpack(t56);
 std::tie(t[7], t[8])= unpack(mul2<VPCLMUL>(t4, t34));
 __m256i t8= _mm256_set1_epi64x(t[8]);
 std::tie(t[9], t[10])= unpack(mul2<VPCLMUL>(t8, t12));
 std::tie(t[11], t[12])= unpack(mul2<VPCLMUL>(t8, t34));
 std::tie(t[13], t[14])= unpack(mul2<VPCLMUL>(t8, t56));
 t[15]= mul(t[7], t[8]);
 auto [b6, b7]= unpack(mul2<VPCLMUL>(_mm256_set_epi64x(0, F32(t[(e >> 60) & 0xf]), 0, F32(t[(e >> 56) & 0xf])), _mm256_set_epi64x(0, t[(e >> 28) & 0xf], 0, t[(e >> 24) & 0xf])));
 auto [b4, b5]= unpack(mul2<VPCLMUL>(_mm256_set_epi64x(0, F32(t[(e >> 52) & 0xf]), 0, F32(t[(e >> 48) & 0xf])), _mm256_set_epi64x(0, t[(e >> 20) & 0xf], 0, t[(e >> 16) & 0xf])));
 __m256i b23= mul2<VPCLMUL>(_mm256_set_epi64x(0, F32(t[(e >> 44) & 0xf]), 0, F32(t[(e >> 40) & 0xf])), _mm256_set_epi64x(0, t[(e >> 12) & 0xf], 0, t[(e >> 8) & 0xf]));
 __m256i b01= mul2<VPCLMUL>(_mm256_set_epi64x(0, F32(t[(e >> 36) & 0xf]), 0, F32(t[(e >> 32) & 0xf])), _mm256_set_epi64x(0, t[(e >> 4) & 0xf], 0, t[e & 0xf]));
 auto [b2, b3]= unpack(mul2<VPCLMUL>(_mm256_set_epi64x(0, F16(b7), 0, F16(b6)), b23));
 auto [b0, b1]= unpack(mul2<VPCLMUL>(_mm256_set_epi64x(0, F8(b3), 0, F8(b2)), mul2<VPCLMUL>(_mm256_set_epi64x(0, F16(b5), 0, F16(b4)), b01)));
 return mul(F4(b1), b0);
}
template <class U> struct LinMap16 {
 U t[2][256];
 constexpr LinMap16(const U b[16]): t{} {
  for(int i= 0; i < 16; ++i) {
   U* l= t[i >> 3];
   for(u8 h= 1 << (i & 7), j= h; j--;) l[h | j]= l[j] ^ b[i];
  }
 }
 inline constexpr U operator()(const u16 x) const { return t[0][u8(x)] ^ t[1][x >> 8]; }
};
constexpr u64 EMB_B[]= {0x0000000000000001, 0x5fbfaec6aeac0002, 0xb06c601895640004, 0xb013b5277b7c0008, 0xb5ebb915248a0010, 0x109bb25b2c600020, 0xbf3bd95bd4190040, 0x0fc66342279b0080, 0xb6418f5e57c50100, 0xaa194bd4b83f0200, 0x1b5217b4dcc70400, 0xbb06fa73867a0800, 0x006fd55b23331000, 0x4ae8fb39198c2000, 0xfbd141b29b4f4000, 0x1d9ce1776be78000};
constexpr LinMap16<u64> EMB= LinMap16<u64>(EMB_B);
constexpr u32 MG_B[16]= {11778, 26543, 52504, 2252, 62850, 2916, 10521, 61878, 56874, 42750, 3345, 46259, 4395, 25479, 2375, 31014}, MGI_B[16]= {31924, 38226, 20204, 7599, 29649, 43528, 31690, 42995, 5042, 974, 38821, 36722, 24051, 36426, 48847, 56272};
struct Inv16 {
 u16 t[65536];
};
template <int D> struct Inv {
 static constexpr Inv16 INV16= []() {
  u32 f[2][256]{}, b[2][256]{};
  for(int i= 0; i < 16; ++i)
   for(u32 h= 1 << (i & 7), j= h; j--;) f[i >> 3][h | j]= f[i >> 3][j] ^ MG_B[i], b[i >> 3][h | j]= b[i >> 3][j] ^ MGI_B[i];
  Inv16 r{};
  r.t[1]= 1;
  for(u32 k= 32767, x= 1, y= 1; k--;) x= f[0][x & 255] ^ f[1][x >> 8], y= b[0][y & 255] ^ b[1][y >> 8], r.t[x]= y, r.t[y]= x;
  return r;
 }();
 template <bool V> static inline u64 iv(u64 a) {
  assert(a);
  u64 a32= F32(a), b= mul(a, a32);
  auto [g, c]= unpack(mul2<V>(_mm256_set_epi64x(0, b, 0, a32), _mm256_set1_epi64x(F16(b))));
  return mul(EMB(INV16.t[u16(c)]), g);
 }
};
constexpr u32 MH_B[16]= {42619, 34034, 37264, 59687, 13661, 58726, 9805, 26873, 8763, 63546, 2437, 49325, 17957, 37424, 41924, 9918}, MHI_B[16]= {65259, 13521, 41942, 64933, 45949, 48995, 32680, 14796, 1131, 41664, 58865, 25754, 5510, 38977, 46447, 39768};
struct InvLn16 {
 u32 t[65536];
};
struct Ln641 {
 u16 t[1 << 14];
 u16 operator()(u64 a) const { return t[u16((a * 0xffef5fb99f1bf6e7) >> 50)]; }
};
constexpr u16 PHI_B[16]= {49349, 60640, 60091, 52204, 8753, 26688, 50952, 24030, 14026, 41051, 57150, 31936, 39252, 22252, 63476, 55223};
constexpr u32 MC_B[32]= {0xca137f44, 0x02f9ac22, 0x24119ddf, 0x677fa964, 0x1c3c90b8, 0x61acd330, 0x087e6d0e, 0x98f43405, 0x17ef3800, 0x46a70e74, 0xfdd52d61, 0x9767f2ed, 0xa06bb110, 0xf0ef2346, 0x88d7f773, 0x3bdf87f2, 0xb557b556, 0xaedbaed9, 0xb9ceb9ca, 0xce1bce13, 0x8c848c94, 0xb29cb2bc, 0x65706530, 0xacf1ac71, 0x2fef2eef, 0x48d34ad3, 0xd0b4d4b4, 0x658a6d8a, 0x117b017b, 0xd3a9f3a9, 0x7fa43fa4, 0xbc2d3c2d};
struct ClassTable65537 {
 u16 t[65535];
 u32 K0, s;
};
constexpr u32 OR_L= 6700417, OR_N= 58900, OR_S= 4337141, OR_I= 13, OR_BB= 14, OR_SLOTS= 8u << OR_BB, OR_PAD= 64;
constexpr u32 OR_C1= 0x40c1ee2e, OR_MG2_B[32]= {0x800e5536, 0xf206dc7f, 0xebe52465, 0x3db3b546, 0x7b06720d, 0xc4276035, 0x6532ca3c, 0x9bbfa71f, 0x3641a727, 0xf919cc6c, 0x5bcde957, 0xdc1e972a, 0xc64b8dfb, 0x11dc26a8, 0x37e7ab06, 0x597ccd7c, 0x0c0191c3, 0x16083352, 0x01f518c9, 0x2b2f7dd3, 0x982e7286, 0xc34076ee, 0x206f6920, 0x98d2c1d7, 0x9b52d4b3, 0x93cc096c, 0x98b2f2bf, 0x03b9fa4e, 0xccaf01d0, 0x5d3fe80e, 0xb91c8774, 0xfdefb3a2};
constexpr u32 OR_MT1_B[32]= {0x72e12e3b, 0xe16f64aa, 0x5ec400dd, 0x5baaa4c1, 0xd8a77c7b, 0x475e9b5e, 0xc2705cee, 0xdc1b78ce, 0xf58842a1, 0xfa371ae4, 0x05e8731b, 0x77e28090, 0x02ce177a, 0xa927bdce, 0x0696177e, 0x661b6e7f, 0xcad3c1f4, 0xcf993c9d, 0x914d1c64, 0xbc31e925, 0x78f615ca, 0x4014dc84, 0x1b3f5a7f, 0x70b2d2b6, 0xed3323f5, 0x897807b1, 0x3cb6dcf0, 0xf6526d26, 0x4000fe3a, 0x1f4b257b, 0x8ac1c7d9, 0x65bfe9a2};
constexpr u32 OR_LAM_B[64]= {0x00000000, 0x9793a0ad, 0x2f27415b, 0x2d35097e, 0x5e4e82b6, 0x43132bcc, 0x5a6a12fc, 0xd864f1ed, 0xbc9d056c, 0x861eeb46, 0x86265798, 0xbea091e6, 0xb4d425f8, 0x837f73c7, 0xb0c9e3db, 0x262565ac, 0x793a0ad9, 0xde69177e, 0x0c3dd68d, 0x9a2d0e52, 0x0c4caf31, 0xf3c09abe, 0x7d4123cd, 0x59261485, 0x69a84bf1, 0xc9c9bee2, 0x06fee78f, 0x34f6bd91, 0x6193c7b7, 0x18006846, 0x4c4acb58, 0xef7fe856, 0xf27415b2, 0x8db5b88a, 0xbcd22efd, 0xc11b2fe7, 0x187bad1a, 0x05982b31, 0x345a1ca5, 0x225c23c2, 0x18995e62, 0x0c48b0d6, 0xe781357d, 0xf5a83712, 0xfa82479a, 0x33217c80, 0xb24c290a, 0xc9295abc, 0xd35097e2, 0x26059b47, 0x93937dc5, 0x7ee7dd66, 0x0dfdcf1e, 0xc9a22bf2, 0x69ed7b22, 0x6779ca9a, 0xc3278f6e, 0xa69df839, 0x3000d08c, 0xcc04cc86, 0x989596b0, 0xe1a94462, 0xdeffd0ad, 0x202b58ec};
constexpr u64 OR_H1= 0x9944cc327ae8fc24;
constexpr u32 OR_P2INV[32]= {1, 3350209, 5025313, 5862865, 6281641, 6491029, 6595723, 6648070, 3324035, 5012226, 2506113, 4603265, 5651841, 6176129, 6438273, 6569345, 6634881, 6667649, 6684033, 6692225, 6696321, 6698369, 6699393, 6699905, 6700161, 6700289, 6700353, 6700385, 6700401, 6700409, 6700413, 6700415};
template <int N> struct Lin32 {
 u32 t[N][256];
 constexpr Lin32(const u32 b[N * 8]): t{} {
  for(int i= 0; i < N * 8; ++i)
   for(u32 h= 1 << (i & 7), j= h; j--;) t[i >> 3][h | j]= t[i >> 3][j] ^ b[i];
 }
 constexpr u32 operator()(u64 x) const {
  u32 r= 0;
  for(int k= 0; k < N; ++k) r^= t[k][u8(x >> 8 * k)];
  return r;
 }
};
#ifdef __x86_64__
inline u64 orbit_canon_avx2(u32 w) {
 const __m256i W= _mm256_set1_epi32(int(w));
 const __m256i r0= _mm256_or_si256(_mm256_sllv_epi32(W, _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7)), _mm256_srlv_epi32(W, _mm256_setr_epi32(32, 31, 30, 29, 28, 27, 26, 25)));
 const __m256i r1= _mm256_or_si256(_mm256_slli_epi32(r0, 8), _mm256_srli_epi32(r0, 24));
 const __m256i r2= _mm256_or_si256(_mm256_slli_epi32(r0, 16), _mm256_srli_epi32(r0, 16));
 const __m256i r3= _mm256_or_si256(_mm256_slli_epi32(r0, 24), _mm256_srli_epi32(r0, 8));
 __m256i m= _mm256_min_epu32(_mm256_min_epu32(r0, r1), _mm256_min_epu32(r2, r3));
 m= _mm256_min_epu32(m, _mm256_permute2x128_si256(m, m, 1));
 m= _mm256_min_epu32(m, _mm256_shuffle_epi32(m, 0x4e));
 m= _mm256_min_epu32(m, _mm256_shuffle_epi32(m, 0xb1));
 const u32 f= u32(_mm256_movemask_ps(_mm256_castsi256_ps(_mm256_cmpeq_epi32(r0, m)))) | u32(_mm256_movemask_ps(_mm256_castsi256_ps(_mm256_cmpeq_epi32(r1, m)))) << 8 | u32(_mm256_movemask_ps(_mm256_castsi256_ps(_mm256_cmpeq_epi32(r2, m)))) << 16 | u32(_mm256_movemask_ps(_mm256_castsi256_ps(_mm256_cmpeq_epi32(r3, m)))) << 24;
 return u64(__builtin_ctz(f)) << 32 | u32(_mm256_cvtsi256_si32(m));
}
#endif
constexpr u64 orbit_canon(u32 w) {
#ifdef __x86_64__
 if(!std::is_constant_evaluated()) return orbit_canon_avx2(w);
#endif
 const u32 nw= ~w;
 u32 z= nw;
 for(u32 t= 1, nz; t < 32 && (nz= z & (nw << t | nw >> (32 - t))); ++t) z= nz;
 u32 j= (31 - __builtin_ctz(z)) & 31, best= j ? w << j | w >> (32 - j) : w, k= j;
 for(z&= z - 1; z; z&= z - 1) {
  j= (31 - __builtin_ctz(z)) & 31;
  if(const u32 v= j ? w << j | w >> (32 - j) : w; v < best) best= v, k= j;
 }
 return u64(k) << 32 | best;
}
struct alignas(64) OrbitTab {
 u64 t[OR_SLOTS + OR_PAD];
 u8 cnt[(OR_SLOTS + OR_PAD) / 8];
 u32 p, c, n;
};
struct OrbitPow {
 u64 lo[256], mid[256], hi[(OR_L >> 16) + 1], hp[OR_I];
};
inline u32 orbit_home(u32 key) { return ((key * 0x9e3779b1u) >> (32 - OR_BB)) * 8; }
template <int D> struct Log {
 static constexpr LinMap mul_linmap(u64 c) {
  u64 basis[64]= {c};
  for(int i= 1; i < 64; ++i) basis[i]= (basis[i - 1] << 1) ^ (0x1b & -(basis[i - 1] >> 63));
  return LinMap(basis);
 }
 static constexpr InvLn16 IL16= []() {
  u32 f[2][256]{}, b[2][256]{};
  for(int i= 0; i < 16; ++i)
   for(u32 h= 1 << (i & 7), j= h; j--;) f[i >> 3][h | j]= f[i >> 3][j] ^ MH_B[i], b[i >> 3][h | j]= b[i >> 3][j] ^ MHI_B[i];
  InvLn16 r{};
  r.t[1]= 1 << 16;
  for(u32 l= 1, x= 1, y= 1; l < 32768; ++l) x= f[0][x & 255] ^ f[1][x >> 8], y= b[0][y & 255] ^ b[1][y >> 8], r.t[x]= y << 16 | l, r.t[y]= x << 16 | (65535 - l);
  return r;
 }();
 static constexpr LinMap F9= []() { return F8 * F1; }(), F57= F48 * F9;
 static constexpr Ln641 LN641= []() {
  Ln641 h{};
  LinMap m= mul_linmap(0x6bf808f7824282a2);
  for(u64 k= 0, cur= 1; k < 641; ++k, cur= m(cur)) h.t[u16((cur * 0xffef5fb99f1bf6e7) >> 50)]= k * 590 * 128 % 641;
  return h;
 }();
 static constexpr LinMap16<u16> PHI= []() { return LinMap16<u16>(PHI_B); }();
 static constexpr ClassTable65537 cls65537(ClassTable65537 r, u32 k, u32 e) {
  u32 m[4][256]{};
  for(int i= 0; i < 32; ++i)
   for(u32 h= 1 << (i & 7), j= h; j--;) m[i >> 3][h | j]= m[i >> 3][j] ^ MC_B[i];
  u32 s= r.s, b0, b1, l1;
  for(; k < e; ++k) {
   s= m[0][s & 255] ^ m[1][s >> 8 & 255] ^ m[2][s >> 16 & 255] ^ m[3][s >> 24], b0= s & 65535, b1= s >> 16, l1= 65535 - (IL16.t[b1] & 65535);
   if(b0) r.t[((IL16.t[b0] & 65535) + l1) % 65535]= u16(k - 1);
   else r.K0= k;
   if(b0 ^ b1) r.t[((IL16.t[b0 ^ b1] & 65535) + l1) % 65535]= u16(65536 - k);
   else r.K0= 65537 - k;
  }
  r.s= s;
  return r;
 }
 static constexpr ClassTable65537 CLS65537_0= cls65537({{}, 0, 1}, 1, 16385), CLS65537= cls65537(CLS65537_0, 16385, 32769);
 static inline u32 log_65537(u64 n, u64 fn) {
  const u16 b1= n ^ fn;
  if(!b1) return 0;
  const u16 b0= n ^ PHI(b1);
  if(!b0) return CLS65537.K0;
  u32 idx= (IL16.t[b0] & 65535) + 65535 - (IL16.t[b1] & 65535);
  if(idx >= 65535) idx-= 65535;
  return CLS65537.t[idx] + 1u;
 }
 static constexpr Lin32<4> OR_M1= []() { return Lin32<4>(OR_MT1_B); }();
 static constexpr Lin32<8> OR_LAM= []() { return Lin32<8>(OR_LAM_B); }();
 static constexpr OrbitTab orbit_part(const OrbitTab& r0, u32 e) {
  OrbitTab r= r0;
  u32 m[4][256]{};
  for(int i= 0; i < 32; ++i)
   for(u32 h= 1 << (i & 7), j= h; j--;) m[i >> 3][h | j]= m[i >> 3][j] ^ OR_MG2_B[i];
  u32 p= r.p, c= r.c, n= r.n;
  for(; n <= e; ++n) {
   const u64 ck= orbit_canon(c);
   const u32 best= u32(ck), k= u32(ck >> 32);
   u32 g= (best * 0x9e3779b1u) >> (32 - OR_BB);
   while(r.cnt[g] == 8) ++g;
   r.t[g * 8 + r.cnt[g]++]= u64(best) << 32 | u32((u64(2 * n - 1) << k) % OR_L);
   const u32 x= m[0][c & 255] ^ m[1][c >> 8 & 255] ^ m[2][c >> 16 & 255] ^ m[3][c >> 24] ^ p;
   p= c, c= x;
  }
  r.p= p, r.c= c, r.n= n;
  return r;
 }
 static constexpr OrbitTab OR_TAB_0= orbit_part(OrbitTab{{}, {}, OR_C1, OR_C1, 1}, 5890), OR_TAB_1= orbit_part(OR_TAB_0, 11780), OR_TAB_2= orbit_part(OR_TAB_1, 17670), OR_TAB_3= orbit_part(OR_TAB_2, 23560), OR_TAB_4= orbit_part(OR_TAB_3, 29450), OR_TAB_5= orbit_part(OR_TAB_4, 35340), OR_TAB_6= orbit_part(OR_TAB_5, 41230), OR_TAB_7= orbit_part(OR_TAB_6, 47120), OR_TAB_8= orbit_part(OR_TAB_7, 53010), OR_TAB= orbit_part(OR_TAB_8, OR_N);
 static constexpr LinMap OR_MUL_G= mul_linmap(0x00f542601703f991), OR_MUL_G256= mul_linmap(0x5f915310c81c09e9), OR_MUL_G65536= mul_linmap(0x40cee54547d2d10a), OR_MUL_H= mul_linmap(OR_H1);
 static constexpr OrbitPow OR_POW= []() {
  OrbitPow r{};
  r.lo[0]= r.mid[0]= r.hi[0]= r.hp[0]= 1;
  for(int i= 1; i < 256; ++i) r.lo[i]= OR_MUL_G(r.lo[i - 1]), r.mid[i]= OR_MUL_G256(r.mid[i - 1]);
  for(u32 i= 1; i <= (OR_L >> 16); ++i) r.hi[i]= OR_MUL_G65536(r.hi[i - 1]);
  for(u32 i= 1; i < OR_I; ++i) r.hp[i]= OR_MUL_H(r.hp[i - 1]);
  return r;
 }();
 static constexpr Lin32<8> OR_LAMH= []() {
  u32 b[64]{};
  for(int i= 0; i < 64; ++i) b[i]= OR_LAM(OR_MUL_H(u64(1) << i));
  return Lin32<8>(b);
 }();
 static inline u32 orbit_lookup(u32 key) {
  const __m256i K= _mm256_set1_epi64x((long long)(u64(key) << 32));
  for(u32 h= orbit_home(key);; h+= 8) {
   const __m256i* q= (const __m256i*)&OR_TAB.t[h];
   const u32 f= u32(_mm256_movemask_ps(_mm256_castsi256_ps(_mm256_cmpeq_epi32(_mm256_loadu_si256(q), K)))) | u32(_mm256_movemask_ps(_mm256_castsi256_ps(_mm256_cmpeq_epi32(_mm256_loadu_si256(q + 1), K)))) << 8;
   if(f & 0xaaaa) return u32(OR_TAB.t[h + (__builtin_ctz(f & 0xaaaa) >> 1)]);
   if(f & 0x5555) return 0;
  }
 }
 static inline u32 orbit_find(u64 y, u32 c, u64 ck, u32 i) {
  constexpr u32 L= OR_L;
  if(!c) return u32(u64(OR_S) * i % L);
  const u32 e= orbit_lookup(u32(ck));
  if(!e) return L;
  const u32 e1= u32(u64(e) * OR_P2INV[ck >> 32] % L);
  const u64 z= i ? mul(y, OR_POW.hp[i]) : y, g= mul(mul(OR_POW.lo[e1 & 255], OR_POW.mid[e1 >> 8 & 255]), OR_POW.hi[e1 >> 16]);
  return u32((u64(OR_S) * i + (z == g ? e1 : L - e1)) % L);
 }
 static inline void orbit_prefetch(u64 ck) { _mm_prefetch((const char*)&OR_TAB.t[orbit_home(u32(ck))], _MM_HINT_T0); }
 static inline u32 log_6700417(u64 y) {
  u32 c0= OR_LAM(y), c1= OR_LAMH(y);
  for(u32 i= 0; i < OR_I; i+= 2) {
   const u64 k0= c0 ? orbit_canon(c0) : 0, k1= c1 ? orbit_canon(c1) : 0;
   orbit_prefetch(k0), orbit_prefetch(k1);
   if(const u32 e= orbit_find(y, c0, k0, i); e != OR_L) return e;
   if(i + 1 < OR_I)
    if(const u32 e= orbit_find(y, c1, k1, i + 1); e != OR_L) return e;
   const u32 c2= OR_M1(c1) ^ c0;
   c1= OR_M1(c2) ^ c1, c0= c2;
  }
  return OR_L;
 }
 template <bool V> static inline u64 ln(u64 x) {
  assert(x);
  const u64 x32= F32(x), n= mul(x, x32), fn= F16(n);
  auto [x_f16, w]= unpack(mul2<V>(_mm256_set_epi64x(0, sq(x32), 0, n), _mm256_set1_epi64x(fn)));
  const u16 xf= u16(x_f16);
  const u32 il= IL16.t[xf];
  const u64 s= mul(EMB(u16(il >> 16)), w), w1= mul(s, F9(s)), e57= F57(w1);
  auto [w2, y]= unpack(mul2<V>(_mm256_set_epi64x(0, e57, 0, sq(w1)), _mm256_set_epi64x(0, s, 0, w1)));
  u32 r3= log_6700417(y);
  const u64 w3= mul(s, sq(w2)), w4= mul(w3, F4(w3));
  u64 r0= LN641(mul(e57, w4)), r2= log_65537(n, fn);
  const __uint128_t acc= 0x663d80ff99c27f * r0 + __uint128_t(0x2f205935d0dfa6ca) * r3 + 0x1000100010001ull * (il & 65535) + 0xffff0000ffff * r2;
  const u64 lo= u64(acc), t= lo + u64(acc >> 64);
  return t + (t < lo);
 }
};
class GF2p64 {
 u64 x;
 template <int D> inline u64 iv_() const {
#ifdef __x86_64__
  if(__builtin_cpu_supports("vpclmulqdq")) return Inv<D>::template iv<1>(x);
#endif
  return Inv<D>::template iv<0>(x);
 }
public:
 GF2p64(): x(0) {}
 GF2p64(u64 y): x(y) {}
 static GF2p64 from_nimber(u64 n) { return GF2p64(FROM_NIM(n)); }
 auto operator<=>(const GF2p64&) const= default;
 GF2p64& operator+=(GF2p64 r) { return x^= r.x, *this; }
 GF2p64& operator-=(GF2p64 r) { return x^= r.x, *this; }
 GF2p64& operator*=(GF2p64 r) { return x= mul(x, r.x), *this; }
 template <int D= 0> GF2p64& operator/=(GF2p64 r) { return x= mul(x, r.iv_<D>()), *this; }
 GF2p64 operator+(GF2p64 r) const { return x ^ r.x; }
 GF2p64 operator-(GF2p64 r) const { return x ^ r.x; }
 GF2p64 operator*(GF2p64 r) const { return mul(x, r.x); }
 template <int D= 0> GF2p64 operator/(GF2p64 r) const { return mul(x, r.iv_<D>()); }
 GF2p64 square() const { return sq(x); }
 GF2p64 sqrt() const { return F63(x); }
 template <int D= 0> GF2p64 inv() const { return iv_<D>(); }
 GF2p64 pow(u64 e) const {
#ifdef __x86_64__
  if(__builtin_cpu_supports("vpclmulqdq")) return pw<1>(x, e);
#endif
  return pw<0>(x, e);
 }
 template <int D= 0> u64 log() const {
#ifdef __x86_64__
  if(__builtin_cpu_supports("vpclmulqdq")) return Log<D>::template ln<1>(x);
#endif
  return Log<D>::template ln<0>(x);
 }
 u64 to_nimber() const { return TO_NIM(x); }
 explicit operator u64() const { return x; }
 explicit operator bool() const { return x != 0; }
 friend std::ostream& operator<<(std::ostream& os, const GF2p64& r) { return os << r.x; }
 friend std::istream& operator>>(std::istream& is, GF2p64& r) { return is >> r.x; }
};
}
using gf2p64_internal::GF2p64;
