#define _USE_MATH_DEFINES

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
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
#include <functional>

using namespace std;

// Global constants
int limit = 10000;  // Limit for factorial precomputation
int mod = 1e9 + 7;  // Modulo value for computations to prevent overflow

// Function to calculate modular exponentiation: (a^x) % mod
long long pow_mod(long long a, int x) {
    long long r = 1;
    a %= mod;

    while (x) {
        if (x & 1)  // If the current bit of x is 1, multiply r by a
            r = r * a % mod;

        a = a * a % mod;  // Square a for the next bit
        x >>= 1;  // Move to the next bit of x
    }

    return r;
}

// Function to compute the number of valid permutations
long long duplicate_order(long long N, long long M1, long long M2, long long H, long long S, vector<long long>& fact, vector<long long>& inv) {
    // Lambda function to calculate binomial coefficient: C(n, k) = n! / (k! * (n-k)!)
    function<long long(int, int)> binom = [&](int n, int k) {
        if (k > n)
            return 0LL;
        if (k == 0 || k == n)
            return 1LL;
        return fact[n] * inv[k] % mod * inv[n - k] % mod;
    };

    if (H > N)  // If the number of differing characters exceeds the total length, no solution exists
        return 0;

    // Precompute cumulative sums for combinations of M1 and M2
    vector<long long> accu(min(M1, M2) + 2);
    for (int left = 0; left <= min(M1, M2); ++left) {
        long long curr = binom(N - H, left) * pow_mod(S - 1, left) % mod;
        accu[left + 1] = (curr + accu[left]) % mod;  // Cumulative sum
    }

    long long ans = 0;  // Final answer to hold the result

    // Iterate over all possible combinations of zeros (a), ones (b), and others (c) in the prefix
    for (int a = 0; a <= H; ++a) {
        for (int b = 0; b <= H - a; ++b) {
            int c = H - a - b;  // Remaining characters in the prefix that are not zeros or ones
            int left_m1 = M1 - b - c;  // Remaining zeros allowed in the suffix
            int left_m2 = M2 - a - c;  // Remaining ones allowed in the suffix

            if (left_m1 < 0 || left_m2 < 0)  // Skip invalid configurations
                continue;

            // Calculate the current number of valid configurations
            long long curr = binom(H, a)  // Choose a zeros in H positions
                           * binom(H - a, b) % mod  // Choose b ones in remaining positions
                           * pow_mod(S - 2, c) % mod  // Choose c characters from the remaining (S-2) symbols
                           * accu[min(left_m1, left_m2) + 1] % mod;  // Use precomputed cumulative sum
            ans = (ans + curr) % mod;  // Add to the answer
        }
    }

    // Multiply by additional factors to account for differing characters and same suffix
    ans = ans * pow_mod(S * (S - 1), H) % mod  // H positions must differ completely
          * pow_mod(S, N - H) % mod  // N-H positions must be the same
          * binom(N, H) % mod;  // Choose H positions out of N to differ

    return ans;
}

int main() {
    // Precompute factorials and modular inverses
    vector<long long> fact(limit + 2), inv(limit + 2);

    fact[0] = 1;
    for (int i = 1; i <= limit; ++i) {
        fact[i] = fact[i - 1] * i % mod;  // Factorial computation
        inv[i] = pow_mod(fact[i], mod - 2);  // Modular inverse using Fermat's Little Theorem
    }

    int T;  // Number of test cases
    cin >> T;

    // Process each test case
    for (int t = 1; t <= T; ++t) {
        long long N, M1, M2, H, S;  // Input parameters
        cin >> N >> M1 >> M2 >> H >> S;

        cout << "Case #" << t << ": ";
        cout << duplicate_order(N, M1, M2, H, S, fact, inv) << "\n";
    }

    return 0;
}
