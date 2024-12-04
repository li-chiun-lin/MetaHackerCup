/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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

const int MOD = 998244353;

// Function to perform modular multiplication
// Multiplies two numbers a and b under modulo m
int mul(long long a, long long b, int m) {
    long long result = 0;  // Initialize result
    long long base = b % m; // Ensure b is within the modulus range

    while (base) {
        // If the current bit of base is set, add `a` to the result
        if (base & 1)
            result = (result + a) % m;

        // Double the value of a and reduce modulo m
        a = (a + a) % m;
        base >>= 1; // Shift base right by 1
    }

    return result;
}

// Function to perform modular exponentiation
// Computes (a^x) % m using iterative squaring
int pow(long long a, long long x, int m) {
    long long result = 1;  // Initialize result
    a = a % m;             // Ensure a is within the modulus range

    while (x > 0) {
        // If the current bit of x is set, multiply result by `a`
        if (x & 1)
            result = (result * a) % m;

        // Square `a` and reduce modulo m
        a = (a * a) % m;
        x >>= 1; // Shift x right by 1
    }

    return result;
}

// Function to find the modular inverse of `a` under modulo `m`
// Using Fermat's Little Theorem: a^(m-2) % m (only works when m is prime)
int inv(long long a, int m) {
    return pow(a, m - 2, m); // Compute modular inverse using pow
}

// Function to calculate a specific formula: ((2L + 1) * (W - G)) % mod
int substantial_losses(long long W, long long G, long long L) {
    // Compute (2 * L + 1) % mod
    long long a = (2 * L + 1) % MOD;
    
    // Compute (W - G) % mod, ensuring non-negative result by adding MOD and taking % again
    long long b = (W - G + MOD) % MOD;

    // Return the product a * b under the modulo
    return (a * b) % MOD;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long W, G, L;

		cin >> W >> G >> L;

		cout << "Case #" << t << ": ";
		cout << substantial_losses(W, G, L) << "\n";
	}

	return 0;
}

