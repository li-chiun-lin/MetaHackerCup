/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Function to check if the frequency vector `a` is "almost perfect" compared to `b`
// Returns true if all characters in `b` are present in `a`, and `a` has exactly one surplus character.
bool isAlmostPerfect(const vector<int>& a, const vector<int>& b) {
    int surplus = 0;

    for (int c = 0; c < 26; ++c) {
        if (a[c] < b[c]) {
            return false; // `a` lacks characters present in `b`
        }
        surplus += a[c] - b[c];
    }

    return surplus == 1; // True if total surplus is exactly one
}

// Function to compute character frequencies for a substring [left, right]
// using a precomputed prefix frequency array `freq`
vector<int> computeFrequencies(int left, int right, const vector<vector<int>>& freq) {
    vector<int> f(26);

    for (int c = 0; c < 26; ++c) {
        f[c] = freq[right + 1][c] - freq[left][c];
    }

    return f;
}

// Function to count the number of "almost perfect" substrings based on queries
int countAlmostPerfectSubstrings(const string& S, const vector<pair<int, int>>& queries) {
    int n = S.size();

    // Precompute prefix frequency array for each character
    vector<vector<int>> freq(n + 1, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        freq[i + 1] = freq[i];
        ++freq[i + 1][S[i] - 'a'];
    }

    int count = 0; // Count of "almost perfect" substrings

    // Process each query
    for (const auto& [left, right] : queries) {
        int l = left - 1;  // Convert to 0-based indexing
        int r = right - 1;

        if ((r - l + 1) % 2 == 0) {
            continue; // Skip even-length substrings
        }

        int mid = l + (r - l) / 2;

        // Check two possible splits for "almost perfect" condition
        if (isAlmostPerfect(computeFrequencies(l, mid, freq), computeFrequencies(mid + 1, r, freq)) ||
            isAlmostPerfect(computeFrequencies(mid, r, freq), computeFrequencies(l, mid - 1, freq))) {
            ++count;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        string S;
        cin >> S;

        int Q;
        cin >> Q;

        vector<pair<int, int>> queries(Q);
        for (auto& [L, R] : queries) {
            cin >> L >> R;
        }

        cout << "Case #" << t << ": " << countAlmostPerfectSubstrings(S, queries) << "\n";
    }

    return 0;
}
