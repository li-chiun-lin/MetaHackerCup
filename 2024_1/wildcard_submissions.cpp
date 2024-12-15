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

const long long MOD = 998244353;              // Modulo constant for results
const int kBitCountPow = 16;                  // Power of 2 used in bitmask calculations
const int kBitCountBase = (1 << kBitCountPow) - 1;  // Mask for lower 16 bits

// Precomputed data structures
vector<int> bit_count_lookup(1 << kBitCountPow);    // Precomputed bit counts
vector<int> last_bit(1 << 25, -1);                  // Last set bit positions
vector<long long> power26(1 << 7);                 // Powers of 26 modulo MOD
vector<vector<long long>> qmask_result(kBitCountPow + 1, vector<long long>(1 << kBitCountPow, 0));  // Precomputed mask results
vector<vector<vector<long long>>> fast_qmask_result(kBitCountPow + 1, vector<vector<long long>>(1 << kBitCountPow, vector<long long>(49)));  // Fast lookup for masks

// Counts set bits using bit manipulation
inline int calculate_bitcount(int x) {
    int count = 0;
    while (x) {
        ++count;
        x &= (x - 1);  // Clears the last set bit
    }
    return count;
}

// Faster bit counting using precomputed lookup
inline int fast_bitcount(int x) {
    return bit_count_lookup[x & kBitCountBase] + bit_count_lookup[x >> kBitCountPow];
}

// Computes fast result using precomputed mask results
long long compute_fast_result(unsigned long long mask, int cnt, long long val) {
    vector<int> masks(4), sums(4);
    int sum = 0;

    // Extracts bit chunks of size 16 from the mask
    for (int i = 3; i >= 0; --i) {
        sums[i] = sum;
        masks[i] = static_cast<int>(mask & kBitCountBase);  
        sum += bit_count_lookup[masks[i]];
        mask >>= kBitCountPow;
    }

    cnt -= 64;  // Adjust count after processing 64 bits
    long long total = 0;

    // Calculates contribution from masks
    for (int i = 0; i < 4; ++i) {
        cnt = min(kBitCountPow, cnt + kBitCountPow);
        if (cnt > 0) {
            total += fast_qmask_result[cnt][masks[i]][sums[i]];
        }
    }

    return val ? (val * power26[sum] + total) % MOD : total % MOD;
}

// Precomputes data for fast calculations
void initialize_precomputed_data() {
    
    // Precompute powers of 26 modulo MOD
    power26[0] = 1;  // 26^0 = 1
    for (int i = 1; i < (1 << 7); ++i) 
        power26[i] = (power26[i - 1] * 26) % MOD;  // Store 26^i % MOD for i in [1, 128]

    // Precompute bit counts for all numbers up to 2^kBitCountPow
    // This allows fast bit counting using a lookup table
    for (int i = 0; i < (1 << kBitCountPow); ++i) 
        bit_count_lookup[i] = calculate_bitcount(i);  // Count number of set bits in i

    // Precompute last set bit positions for masks up to 2^25
    // This is used for quickly determining the last set bit in a bitmask
    for (int mask = 1; mask < (1 << 25); ++mask) 
        for (int i = 24; i >= 0; --i) 
            if (mask & (1 << i)) {  // Check if bit i is set in mask
                last_bit[mask] = i;  // Store the last set bit position
                break;
            }

    // Precompute results for qmask operations:
    // qmask_result[cnt][mask] stores the contribution of 'mask' with 'cnt' bits considered.
    // fast_qmask_result[cnt][mask][d] stores contributions for different bit sums.

    for (int mask = 0; mask < (1 << kBitCountPow); ++mask)
        for (int cnt = 0; cnt <= kBitCountPow; ++cnt) {
            long long current = 0;

            // Calculate contributions by simulating character placement
            for (int i = cnt - 1; i >= 0; --i) {
                if (mask & (1 << i)) 
                    current = ((current + 1) * 26) % MOD;  // Add contribution if bit i is set
                else if (++current == MOD) 
                    current = 0;  // Handle modulo reset
            }

            qmask_result[cnt][mask] = current;  // Store the computed result

            // Precompute results for fast mask operations using 49 different sums
            for (int d = 0; d < 49; ++d) 
                fast_qmask_result[cnt][mask][d] = (power26[d] * current) % MOD;
        }
}


// Main function to compute the result for wildcard merging
long long wildcard(int N, vector<string>& S) {
    vector<pair<long long, long long>> qmasks(N, {0, 0});  // Stores '?' masks
    vector<vector<int>> lcp(N, vector<int>(N, 0));         // Longest Common Prefix

    // Compute '?' masks and LCP for all strings
    for (int i = 0; i < N; ++i) {
        int length = S[i].length();
        for (int t = 0; t < length; ++t) {
            if (S[i][t] == '?') {
                if (t < 64) {
                    qmasks[i].first |= (1LL << t);  // Set bit in first part
                } else {
                    qmasks[i].second |= (1LL << (t - 64));  // Set bit in second part
                }
            }
        }

        lcp[i][i] = length;  // LCP with itself is length
        for (int j = i + 1; j < N; ++j) {
            int min_length = min(length, (int)S[j].size());
            lcp[i][j] = min_length;

            for (int t = 0; t < min_length; ++t) {
                if (S[i][t] != '?' && S[j][t] != '?' && S[i][t] != S[j][t]) {
                    lcp[i][j] = t;  // Mismatch found
                    break;
                }
            }
            lcp[j][i] = lcp[i][j];
        }
    }

    vector<int> masks_lcp(1 << N, 1 << 7);  // LCP for all masks
    vector<pair<long long, long long>> masks_qmasks(1 << N, {-1LL, -1LL});  // Masks after merging

    // Generate masks and calculate LCP
    for (int i = 0; i < N; ++i) {
        masks_lcp[1 << i] = lcp[i][i];
        for (int mask = 1; mask < (1 << i); ++mask) {
            int lb = last_bit[mask];
            int pmask = (mask ^ (1 << lb)) | (1 << i);
            int nmask = mask | (1 << i);
            masks_lcp[nmask] = min({masks_lcp[mask], masks_lcp[pmask], lcp[i][lb]});
        }
    }

    // Compute the result using inclusion-exclusion principle
    long long result = 0;
    for (int mask = 1; mask < (1 << N); ++mask) {
        int length = masks_lcp[mask];
        const auto &qmask = masks_qmasks[mask];
        long long current = compute_fast_result(qmask.first, length, 0);
        result += (fast_bitcount(mask) & 1 ? current : -current);
        if (result < 0) result += MOD;
    }
    return (result + 1) % MOD;
}

int main() {
    initialize_precomputed_data();  // Preprocess all data

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        vector<string> S(N);
        for (auto& s : S) cin >> s;

        cout << "Case #" << t << ": " << wildcard(N, S) << "\n";
    }
    return 0;
}
