#pragma once
#include <type_traits>
#include <cassert>
template <class Int> constexpr inline Int mod_inv(Int a, Int mod) {
 static_assert(std::is_signed_v<Int>);
 Int x= 1, y= 0, b= mod;
 for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b * q;
 return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;
}