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

int dfs(int N, vector<string>& G, int i, int j, vector<vector<int>>& dp)
{
	if (j == N - 1)
		return i == 1;

	if (dp[i][j] != -1)
		return dp[i][j];

	long long cnt = 0;
	
	if (i == 0 || i == 2)
	{
		if (G[1][j] == '.' && G[1][j + 1] == '.')
			cnt += dfs(N, G, 1, j + 1, dp);
	}
	else //if (i == 1)
	{
		if (j + 1 < N)
		{
			if (G[0][j] == '.' && G[0][j + 1] == '.')
				cnt += dfs(N, G, 0, j + 1, dp);

			if (G[2][j] == '.' && G[2][j + 1] == '.')
				cnt += dfs(N, G, 2, j + 1, dp);
		}
	}

	return dp[i][j] = cnt % mod;
}

int flow(int N, vector<string>& G)
{
	if (G[0][0] == '#' || G[2][N - 1] == '#')
		return 0;

	vector<vector<int>> dp(3, vector<int>(N, 0));

	dp[1][N - 1] = 1;

	for (int j = N - 2; j >= 0; --j)
	{
		if (G[1][j] == '.' && G[1][j + 1] == '.')
			dp[0][j] = dp[2][j] = dp[1][j + 1] % mod;

		if (G[0][j] == '.' && G[0][j + 1] == '.')
			dp[1][j] += dp[0][j + 1];

		if (G[2][j] == '.' && G[2][j + 1] == '.')
			dp[1][j] += dp[2][j + 1];

		dp[1][j] %= mod;
	}

	return dp[0][0];

	//return dfs(N, G, 0, 0, dp);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<string> G(3);

		for (auto& g : G)
			cin >> g;

		cout << "Case #" << t << ": ";
		cout << flow(N, G) << "\n";
	}

	return 0;
}

