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

int dfs(int K, int load, int truck, int cur_town, vector<int>& S, vector<int>& D, vector<vector<int>>& dst, vector<vector<vector<int>>>& dp)
{
	if (load == K && truck == 0)
		return 0;

	if (dp[load][truck][cur_town] != -1)
		return dp[load][truck][cur_town];

	int drop = load - truck;
	int can_drop = 1e9;
	int can_load = 1e9;

	if (truck)
		can_drop = dfs(K, load, truck - 1, D[drop], S, D, dst, dp) + dst[cur_town][D[drop]];

	if (load < K && truck < 2)
		can_load = dfs(K, load + 1, truck + 1, S[load], S, D, dst, dp) + dst[cur_town][S[load]];

	return dp[load][truck][cur_town] = min(can_drop, can_load);
}

int manic_moving(int N, int M, int K, vector<tuple<int, int, int>>& R, vector<int>& S, vector<int>& D)
{
	vector<vector<pair<int, int>>> adj(N + 1);

	for (auto [a, b, g] : R)
	{
		adj[a].push_back({b, g});
		adj[b].push_back({a, g});
	}

	// shortest distance
	vector<vector<int>> dst(N + 1, vector<int>(N + 1, 1e9));
	
	for (int i = 1; i <= N; ++i)
	{
		dst[i][i] = 0;
		queue<int> que;
		que.push(i);

		while (que.size())
		{
			auto u = que.front();
			que.pop();

			for (auto [v, g] : adj[u])
			{
				if (dst[i][v] > dst[i][u] + g)
				{
					dst[i][v] = dst[i][u] + g;
					que.push(v);
				}
			}
		}
	}

	// reachability check
	for (int i = 0; i < K; ++i)
		if (dst[1][S[i]] == 1e9 || dst[1][D[i]] == 1e9)
			return -1;

	vector<vector<vector<int>>> dp(K + 1, 
		vector<vector<int>>(3, 
		vector<int>(N + 1, -1)));

	return dfs(K, 0, 0, 1, S, D, dst, dp);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, K;
		cin >> N >> M >> K;

		vector<tuple<int, int, int>> R(M);
		vector<int> S(K), D(K);

		for (auto& [a, b, g] : R)
			cin >> a >> b >> g;

		for (int i = 0; i < K; ++i)
			cin >> S[i] >> D[i];

		cout << "Case #" << t << ": ";
		cout << manic_moving(N, M, K, R, S, D) << "\n";
	}

	return 0;
}

