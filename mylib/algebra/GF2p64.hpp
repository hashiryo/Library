#pragma once
#ifdef __x86_64__
#include <immintrin.h>
#else
#include <simde/x86/avx2.h>
#include <simde/x86/clmul.h>
#include <simde/x86/bmi.h>
#endif
#include <utility>
#include <iostream>
#include "include/debug.hpp"
namespace gf2p64_internal {
using u64= unsigned long long;
using u32= unsigned;
using u8= unsigned char;
struct LinMap {
 u64 g[64], t[8][256];
 constexpr LinMap(const u64 b[64]): g{}, t{} {
  for(int i= 0; i < 64; ++i) g[i]= b[i];
  for(int p= 0; p < 8; ++p)
   for(int j= 0; j < 8; ++j) {
    const u64 v= g[8 * p + j];
    const int half= 1 << j;
    for(int b= 0; b < half; ++b) t[p][half + b]= t[p][b] ^ v;
   }
 }
 inline constexpr u64 operator()(u64 a) const { return t[0][u8(a)] ^ t[1][u8(a >> 8)] ^ t[2][u8(a >> 16)] ^ t[3][u8(a >> 24)] ^ t[4][u8(a >> 32)] ^ t[5][u8(a >> 40)] ^ t[6][u8(a >> 48)] ^ t[7][u8(a >> 56)]; }
 constexpr LinMap operator*(const LinMap& r) const {
  u64 h[64]= {};
  for(int i= 0; i < 64; ++i) h[i]= (*this)(r.g[i]);
  return LinMap(h);
 }
};
constexpr u64 TO_NIM_BAS[64]= {0x0000000000000001, 0x5211145C804B6109, 0x7C8BC2CAD259879F, 0x565854B4C60C1E0B, 0x4068ACF7104C20C3, 0x662D2BD0F2739155, 0x7A90C83701FA8323, 0x21CFA750247E8755, 0x67D1044E545ABF47, 0x4D9D3B5A8568F839, 0x567A9D7331B6B3C6, 0x1CA54BFDD6D1AE59, 0x454FA483275DB25C, 0x6766DF6FEC4E9D44, 0x35CB621CEC1FE7F9, 0x4C606D3E52FAF263, 0x57640DC825A57954, 0x7ACA87838B7F6315, 0x6D53C884EBF2B0ED, 0x3721D998BB50164B, 0x7AA7C62FD6CD53AB, 0x47CBB2C51F7C040F, 0x132063B7F5E42489, 0x0C1B36C8B2993F8A, 0x60119ECFF680497A, 0x5175DA444CC11791, 0x5792FF4554765B09, 0x0C9FDB8A01334E82, 0x2BE0A763A68A4725, 0x3C2DC8260AD051F6, 0x6C4C9FED8816BB9C, 0x630062753FFAF766,
                               0x7B37D31B5D519225, 0x2364F7F79705691C, 0x453EB8A83E2FEC71, 0x7C0121B37E828666, 0x59190D3250E66011, 0x103207F9DDA18CAE, 0x28233DCE01C69B76, 0x4FA519899227A5E7, 0x4567BA46EE7BC6CD, 0x0A284773D021AFD5, 0x63894079BBE3A824, 0x11013C7FDFAAA5C2, 0x1AA984F18574F3B0, 0x0CBABA126FD0C4DB, 0x0B8797719E6DC725, 0x4A2845680AEFAA72, 0x536D2535F6934E15, 0x01DB7A57EFFCD689, 0x7E1ED0AD01E2A5AD, 0x0AEDC9B3CEE826F6, 0x7BA716ECCF9F68E1, 0x5D5E23BC0F3DC38F, 0x0B5F2A3B88674D83, 0x2DE9BAFC2F00F8D4, 0x3B56712AD419C7E0, 0x3AB4BE8C30C19253, 0x2708522FFAA654B0, 0x2B8BCA57BF643598, 0x588825D1A5FA8E1C, 0x86ADF8BF4D45962F, 0x51B4C15D8719DD73, 0xE4A2B3B59783D0AA};
constexpr u64 FROM_NIM_BAS[64]= {0x0000000000000001, 0x19C9369F278ADC02, 0xA181E7D66F5FF795, 0x5DB84357CE785D09, 0xA0BAE2F9D2430CC8, 0xB7EA5A9705B771C0, 0xBA4F3CD82801769D, 0x4886CDE01B8241D0, 0x0A6F43F2AAF612ED, 0xEBD0142F98030A32, 0xA81F89CDA43F3792, 0xE99AEC6B66CCB814, 0xA69D1FF025FC2F82, 0x48A81132D25DB068, 0x4A900F9DCAA9644F, 0xE5CE4EA88259972A, 0xF7094C336029F04C, 0xE191DDE287BC9C6B, 0xAACAFF12BFF239B8, 0x49BC5212BE1BC1CA, 0xFE57DEFB454446CF, 0xA1DFFCF944BDF6A7, 0xB9F1BDB5CEE941EE, 0x12E5E889275C22DE, 0x5BCB6B117B77EEED, 0x03EB1AB59D05AE4B, 0x02A25D7076DDD386, 0x53164A606C612245, 0xEBB33F5822F66059, 0xE9BE765F5747B93E, 0x552A78DF373A354F, 0xBCF5AC65F31FB8BF,
                                 0xE411E728BECDC77B, 0xF35C26D7B57CDCA6, 0x4499DA83DE4CA5F7, 0x40AB25BDCA4AE226, 0xEE004B6F1DFF7218, 0x0D122DA9821C5B41, 0x51FBFCB058120EFE, 0xA148B1FA84905B22, 0xBB8ED3E647604D8D, 0xE2D93FEF2472776F, 0x4C17A2541A10E6B5, 0x1D879E08903708E7, 0x0FBE7D0D1934DA90, 0x5BF977D9C6F61D30, 0x06832FC918260412, 0x0FE22E843EBF73E3, 0x4D7EF4E4FA28D60D, 0x402250D979AFBED5, 0x067902B8C8CA2D4F, 0xF38D113FE1D6BB16, 0x414F0248B02B5B7D, 0xF041922915824CE9, 0x11A72FB5E30C93D9, 0x12E54F4D63102AEE, 0xBC46AC14B3141C6C, 0x1F172B3C16C645BB, 0x584B492ED4E8FA6C, 0x00A852E9A32CC133, 0xA180861BCE00A45E, 0xA194B6BCB4645FB9, 0x4509002AD808A4FB, 0xC5172A0055602F69};
constexpr LinMap TO_NIM= LinMap(TO_NIM_BAS);
constexpr LinMap FROM_NIM= LinMap(FROM_NIM_BAS);
constexpr LinMap F1= []() {
 u64 g[64]= {1};
 for(int i= 1; i < 32; ++i) g[i]= u64(1) << (i * 2);
 for(int i= 32; i < 62; ++i) g[i]= u64(27) << ((i - 32) * 2);
 g[62]= 0xB00000000000001B, g[63]= 0xC00000000000005A;
 return LinMap(g);
}();
constexpr LinMap F2= F1 * F1;
constexpr LinMap F3= F2 * F1;
constexpr LinMap F4= F2 * F2;
constexpr LinMap F5= F4 * F1;
constexpr LinMap F6= F4 * F2;
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
 static GF2p64 from_nimber(u64 n) { return GF2p64(FROM_NIM(n)); }
 auto operator<=>(const GF2p64&) const= default;
 GF2p64& operator+=(GF2p64 r) { return x^= r.x, *this; }
 GF2p64& operator-=(GF2p64 r) { return x^= r.x, *this; }
 GF2p64& operator*=(GF2p64 r) { return x= mul(x, r.x), *this; }
 GF2p64 operator+(GF2p64 r) const { return GF2p64(x ^ r.x); }
 GF2p64 operator-(GF2p64 r) const { return GF2p64(x ^ r.x); }
 GF2p64 operator*(GF2p64 r) const { return GF2p64(mul(x, r.x)); }
 GF2p64 square() const { return GF2p64(sq(x)); }
 GF2p64 sqrt() const { return GF2p64(F63(x)); }
 u64 to_nimber() const { return TO_NIM(x); }
 explicit operator u64() const { return x; }
 explicit operator bool() const { return x != 0; }
 friend std::ostream& operator<<(std::ostream& os, const GF2p64& r) { return os << r.x; }
 friend std::istream& operator>>(std::istream& is, GF2p64& r) { return is >> r.x; }
};
}
using gf2p64_internal::GF2p64;
