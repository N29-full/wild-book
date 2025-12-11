#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x)  (x).begin(), (x).end()
#define sz(x) 	(int)(x).size()

const int N = 1e5+10;
const int M = 1e5+10;
const ll INF = (ll)1e18;
const int mod = 1e9+7;
const ld eps  = 1e-9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ...
    return 0;
}
/*
@echo off
g++ -std=c++17 -o gen.exe gen.cpp
g++ -std=c++17 -o solution.exe solution.cpp
g++ -std=c++17 -o brute.exe brute.cpp
for /l %%x in (1, 1, 1000) do (
    gen > input.in
    solution < input.in > output1.out
    brute < input.in > output2.out
    fc output1.out output2.out > diagnostics || exit /b
    echo %%x
)
echo norm
pause
*/