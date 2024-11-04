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

int mod = 1e9 + 7;

long long dfs(vector<int>& V, vector<int>& prev, vector<int>& next, int l, int r, int s, vector<vector<vector<long long>>>& dp)
{
	if (dp[l][r][s] != -1)
		return dp[l][r][s];

	long long ans = V[l] > V[r] ? 1 : 0;

	for (int i = l + 1; i < r; ++i)
		if (V[i] >= V[l] && V[i] >= V[r])
		{
			if (V[i] > s && next[i] >= r)
			{
				ans += dfs(V, prev, next, l, i, s + 1, dp) * (V[i] - s);
				ans %= mod;
			}

			if (V[i] > V[r] && V[i] > s && prev[i] <= l)
			{
				ans += dfs(V, prev, next, i, r, s + 1, dp) * (V[i] - s);
				ans %= mod;
			}
		}

	return dp[l][r][s] = ans;
}

int diversity_num(int M, vector<int>& V)
{
	
	vector<int> prev(M + 1), next(M + 1, M + 1);

	for (int i = 1; i <= M; ++i)
	{
		for (int j = i - 1; j >= 1; --j)
			if (V[j] == V[i])
			{
				prev[i] = j;
				break;
			}

		for (int j = i + 1; j <= M; ++j)
			if (V[j] == V[i])
			{
				next[i] = j;
				break;
			}
	}

	vector<vector<vector<long long>>> dp(M + 2, 
		vector<vector<long long>>(M + 2, 
		vector<long long>(M + 2, -1)));

	long long ans = 1;

	for (int l = 1; l <= M; ++l)
	{
		if (prev[l] == 0)
		{
			ans += dfs(V, prev, next, l, M + 1, 1, dp) * V[l];
			ans %= mod;
		}

		if (next[l] == M + 1)
		{
			ans += dfs(V, prev, next, 0, l, 1, dp) * V[l];
			ans %= mod;
		}
	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int M;
		cin >> M;

		vector<int> V(M + 2);

		for (int i = 1; i <= M; ++i)
			cin >> V[i];

		cout << "Case #" << t << ": ";
		cout << diversity_num(M, V) << "\n";
	}

	return 0;
}

