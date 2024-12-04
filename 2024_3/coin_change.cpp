/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
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

using namespace std;

// Constants for precomputations and chunk limits
const int MAX_EXACT_H = 100000000;
const long long MAX_CHUNK = 1000000000;
const int SMALL_LIMIT = 100000000;
const double EULER = 0.5772156649015328606065120900824;

// Precomputed harmonic series values
double h[MAX_EXACT_H] = {};

// Function to compute the harmonic number H(k)
double H(long long k) {
    if (k < MAX_EXACT_H) {
        return h[(int)k];
    }
    return log(k) + EULER; // Approximation for large k
}

// Solve for small values of N
double solve_small(long long N, int P) {
    double p = P / 100.0;
    double ans = 0;

    for (long k = 0; k < N; ++k) {
        double bestCost = 1e9;

        for (int C = 1; C <= 100; ++C) {
            double chanceNew = min((C - 1) * p, 1.0);
            double chance = chanceNew + (1.0 - chanceNew) * (N - k) / (double)N;
            double cost = C / chance;
            bestCost = min(bestCost, cost);

            if (chanceNew >= 1 || P == 0) {
                break;
            }
        }
        ans += bestCost;
    }

    return ans;
}

// Solve for large values of N
double solve_large(long long N, int P) {
    double p = P / 100.0;

    // Maximum coins needed to guarantee a new coin
    double M = (P > 0) ? ceil(100.0 / P) + 1 : 999;

    // Breakpoints B1 and B2
    long long B1 = (long long)ceil(N - (N * p / (p + 1)));

    auto binary_search_B2 = [=]() -> long long {
        long long lo = 0, hi = N;
        while (lo + 1 < hi) {
            long long mid = (lo + hi) / 2;
            double val = (M - 1) / ((M - 2) * p + (1 - (M - 2) * p) * (N - mid) / (double)N);
            if (val > M) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    };

    long long B2 = (P > 0) ? binary_search_B2() : N;
    B2 = max(B2, B1);

    double ans = 0;

    // Contribution from [0, B1-1]: 1 coin per toy
    ans += N * (H(N) - H(N - B1));

    // Contribution from [B1, B2-1]: Spend M-1 coins
    long long chunkSize = (B2 - B1) / MAX_CHUNK + 1;
    for (long long left = B1; left < B2; left += chunkSize) {
        long long right = min(left + chunkSize - 1, B2 - 1);
        double size = right - left + 1;

        double leftVal = (M - 1) / ((M - 2) * p + (1 - (M - 2) * p) * (N - left) / (double)N);
        double rightVal = (M - 1) / ((M - 2) * p + (1 - (M - 2) * p) * (N - right) / (double)N);

        double midVal = (leftVal + rightVal) / 2;
        ans += midVal * size;
    }

    // Contribution from [B2, N-1]: Spend M coins
    ans += (N - B2) * M;

    return ans;
}


double coin_change(long long N, int P)
{
	return N < SMALL_LIMIT ? solve_small(N, P) : solve_large(N, P);
}

int main()
{
	// Precompute the harmonic series up to MAX_EXACT_H
    h[0] = 0;
    for (int i = 1; i < MAX_EXACT_H; ++i) {
        h[i] = h[i - 1] + 1.0 / i;
    }

	int T;
	cin >> T;
	cout.precision(10);

	for (int t = 1; t <= T; ++t)
	{
		long long N;
		double P;

		cin >> N >> P;

		cout << "Case #" << t << ": ";
		cout << fixed << coin_change(N, P) << "\n";
	}

	return 0;
}

