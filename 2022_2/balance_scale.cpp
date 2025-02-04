/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

// Function to compute a^x % mod using modular exponentiation
long long exp(long long a, int x) {
    a %= mod; // Ensure a is within modulo range
    long long res = 1;
    while (x) {
        if (x & 1) // If x is odd, multiply res by a
            res = res * a % mod;
        a = a * a % mod; // Square a for the next bit
        x >>= 1; // Shift x right by 1 bit
    }
    return res;
}

// Function to compute the modular multiplicative inverse of a
// Using Fermat's Little Theorem: a^(mod-2) % mod is the inverse of a
long long inv(long long a) {
    return exp(a, mod - 2);
}

// Function to solve the balance scale problem
long long balance_scale(int N, int K, vector<int>& C, vector<int>& W) {
    long long lighter = 0, equal = 0, heavier = 0;

    // Classify the weights of teams based on the weight of the first team
    for (int i = 1; i < N; ++i) {
        if (W[i] < W[0])
            lighter += C[i]; // Teams lighter than the first team
        else if (W[i] == W[0])
            equal += C[i]; // Teams with equal weight to the first team
        else
            heavier += C[i]; // Teams heavier than the first team
    }

    long long total = C[0] + lighter + equal + heavier; // Total weight sum
    long long not_heavier = total - heavier; // Sum of weights not heavier than the first team
    ++K; // Increment K to match 1-based indexing

    // Precompute factorials modulo mod
    vector<long long> fac(total + 1, 1);
    for (int i = 1; i <= total; ++i)
        fac[i] = fac[i - 1] * i % mod;

    // Lambda function to calculate nCk % mod
    auto choose = [&](long long n, long long k) -> long long {
        if (k < 0 || n < 0 || n < k)
            return 0LL; // Invalid cases
        return fac[n] * inv(fac[k]) % mod * inv(fac[n - k]) % mod;
    };

    // Calculate the answer step by step
    long long numerator = ((choose(not_heavier, K) - choose(lighter, K)) % mod + mod) % mod;
    long long denominator = choose(total, K);
    long long prob_some_equal = numerator * inv(denominator) % mod;

    long long result = prob_some_equal * C[0] % mod * inv(C[0] + equal) % mod;

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;

        vector<int> C(N), W(N);

        for (int i = 0; i < N; ++i)
            cin >> C[i] >> W[i];

        cout << "Case #" << t << ": ";
        cout << balance_scale(N, K, C, W) << "\n";
    }

    return 0;
}