/*
Out of Memory
*/

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

using namespace std;

void print(vector<vector<int>>& adj)
{
	for (int i = 0; i < size(adj); ++i)
	{
		cout << (i + 1) << ": ";
		for (auto x : adj[i])
			cout << (x + 1) << " ";
		cout << "\n";
	}
}

void dfs(int p, int u, vector<vector<int>>& adj, vector<vector<int>>& next)
{
	for (int v : adj[u])
		if (v != p)
		{
			next[u].emplace_back(v);
			dfs(u, v, adj, next);
		}
}

int F(int S, int K, vector<int>& A, vector<vector<int>>& next, vector<vector<int>>& dp)
{
	if (K == 0)
		return 0;

	if (next[S].empty())
		return A[S];

	if (dp[S][K] != -1)
		return dp[S][K];

	auto take = INT_MAX;
	auto dont = INT_MAX;

	for (auto v : next[S])
	{
		take = min(take, F(v, K - 1, A, next, dp));
		dont = min(dont, F(v, K, A, next, dp));
	}

	return dp[S][K] = max(take + A[S], dont);
}

long long minflow_maxcut(int N, int M, vector<int>& A, vector<pair<int, int>>& UV)
{
	vector<vector<int>> adj(N);

	for (auto [u, v] : UV)
	{
		adj[u - 1].emplace_back(v - 1);
		adj[v - 1].emplace_back(u - 1);
	}

	vector<vector<int>> next(N);

	dfs(-1, 0, adj, next);

	//cout << "\n";
	//cout << N << " " << M << "\n";

	vector<vector<int>> dp(N, vector<int>(M + 1, -1));

	long long ans = 0;
	long long mod = 998244353;

	for (int S = 0; S < N; ++S)
		for (int K = 1; K <= M; ++K)
		{
			auto r = F(S, K, A, next, dp);
			ans = (ans + r) % mod;
			//cout << (S + 1) << " " << K << " : " << r << "\n";
		}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		//cout << N << " " << M << "\n";

		vector<int> A(N);
		vector<pair<int, int>> UV(N - 1);

		for (auto& x : A)
			cin >> x;

		for (auto& [u, v] : UV)
			cin >> u >> v;

		cout << "Case #" << t << ": ";
		cout << minflow_maxcut(N, M, A, UV) << "\n";
	}

	return 0;
}

