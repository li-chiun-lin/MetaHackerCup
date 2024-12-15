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

const long long MOD = 998'244'353;

// Recursive function to calculate the number of valid decompositions starting from index `i`
int dfs(string& E, int i, vector<int>& dp)
{
	int n = size(E);

	// Base cases
	if (i == n) return 1;       // Reached the end, valid way
	if (i > n) return 0;        // Out of bounds, invalid way
	if (dp[i]) return dp[i];    // Return precomputed result if available

	char cur = E[i];

	if (cur == '0') return 0;   // Leading zero, invalid
	if (i == n - 1) return 1;   // Single character left, valid

	char nxt = E[i + 1];
	int cnt1 = dfs(E, i + 1, dp);  // Count one-character interpretation
	int cnt2 = 0;

	// Handle two-character interpretations
	if (cur == '1' || cur == '?') cnt2 = dfs(E, i + 2, dp);
	else if (cur == '2') cnt2 = (nxt >= '7' && nxt <= '9') ? 0 : dfs(E, i + 2, dp);

	// Store and return the result modulo `MOD`
	return dp[i] = (cnt1 + cnt2) % MOD;
}

// Function to generate the K-th smallest valid string and count valid decompositions
pair<string, int> substitution_cipher(string& E, int K)
{
	int n = size(E);
	vector<int> cnt(n);  // Array to store valid options for each '?'

	char pre = '0';

	// Process each character in the string `E`
	for (int i = 0; i < n; ++i)
	{
		char cur = E[i];
		char nxt = (i + 1 < n) ? E[i + 1] : 'X';  // Next character or 'X' if at the end

		// Handle cases with zero locks (e.g., "20?0")
		if (i + 2 < n && E[i + 2] == '0') nxt = 'X';

		// Skip non-'?' characters
		if (cur != '?')
		{
			pre = cur;
			continue;
		}

		// Determine possible replacements for '?'
		if (nxt == '0') cnt[i] = 2;                       // Can only use '1' or '2'
		else if (nxt >= '1' && nxt <= '6') cnt[i] = 2;    // Both '1' and '2' valid
		else if (nxt >= '7' && nxt <= '9') cnt[i] = 1;    // Only '1' valid
		else if (nxt == 'X')                              // End of string
		{
			if (pre == '1') cnt[i] = 9;                   // Any digit after '1'
			else if (pre == '2') cnt[i] = 6;              // Digits '1' to '6' after '2'
			else if (pre == '0' || (pre >= '3' && pre <= '9')) cnt[i] = 9;  // Any digit
			else if (pre == '?') { cnt[i] = 15; cnt[i - 1] = 0; }           // Both '1' and '2' scenarios
		}
		else if (nxt == '?') cnt[i] = 2;                  // Either '1' or '2' valid

		pre = cur;
	}

	// Generate the K-th smallest valid string
	stringstream buf;
	int pos = 1;
	--K;  // Convert K to zero-based indexing

	for (int i = n - 1; i >= 0; --i)
	{
		char c = E[i];

		if (c >= '0' && c <= '9')
		{
			buf << c;
		}
		else
		{
			int sub = 0;
			if (pos < 100000000)
			{
				int mod = pos * cnt[i];
				sub = (K % mod) / pos;
				pos *= cnt[i];
			}
			if (cnt[i] == 15)
			{
				if (sub <= 5) buf << (6 - sub) << 2;
				else buf << (15 - sub) << 1;
				--i;
			}
			else
			{
				buf << (cnt[i] - sub);
			}
		}
	}

	// Calculate the total number of valid decompositions using DFS
	vector<int> dp(n);
	for (int i = n - 1; i >= 0; --i) dfs(E, i, dp);

	int splits = dfs(E, 0, dp);

	string ret = buf.str();
	reverse(begin(ret), end(ret));  // Reverse the string to get the correct order

	return {ret, splits};
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string E;
		int K;

		cin >> E >> K;

		auto [s, c] = substitution_cipher(E, K);

		cout << "Case #" << t << ": ";
		cout << s << " " << c << "\n";
	}

	return 0;
}

