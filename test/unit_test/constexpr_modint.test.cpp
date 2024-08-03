// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/aplusb
#include <iostream>
#include "src/Math/ModInt.hpp"
using namespace std;
using Mint= ModInt<1000000007>;
constexpr auto a= Mint(2) + 3;
static_assert(a == 5);
constexpr auto b= Mint(2) - 3;
static_assert(b == 1000000006);
constexpr auto c= Mint(2) * 3;
static_assert(c == 6);
constexpr auto d= Mint(2) / 3;
static_assert(d == 666666672);
constexpr auto e= Mint(2).pow(3);
static_assert(e == 8);
constexpr auto f= -Mint(2);
static_assert(f == 1000000005);
constexpr auto g= Mint(2).inv();
static_assert(g == 500000004);
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 int A, B;
 cin >> A >> B;
 cout << A + B << '\n';
 return 0;
}