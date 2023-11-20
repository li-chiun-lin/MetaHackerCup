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

void print(const vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

bool dfs(vector<int>& cnt, int S, int accu, int total, map<vector<int>, bool>& dp)
{
	if (total == 0)
		return true;

	if (dp.find(cnt) != end(dp))
		return dp[cnt];

	for (int val = 1; val < size(cnt); ++val)
	{
		if (cnt[val] == 0)
			continue;

		if (accu + val <= S)
		{
			-- cnt[val];

			auto r = dfs(cnt, S, (accu + val) % S, total - val, dp);

			++ cnt[val];

			if (r)
				return dp[cnt] = r;
		}
	}

	return dp[cnt] = false;
}

bool valid(vector<int>& cnt, int S)
{
	for (int val = 1; val < size(cnt); ++val)
		if (cnt[val] && val > S)
			return false;

	return true;
}

vector<int> spooky_splits(int N, int M, vector<pair<int, int>>& P)
{
	vector<vector<int>> adj(N + 1);

	for (auto [a, b] : P)
	{
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> cnt(N + 1);
	vector<bool> visited(N + 1);
	queue<int> que;

	for (int i = 1; i <= N; ++i)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		que.push(i);
		int s = 1;

		while (que.size())
		{
			auto u = que.front();
			que.pop();

			for (auto v : adj[u])
				if (! visited[v])
				{
					++ s;
					que.push(v);
					visited[v] = true;
				}
		}

		++ cnt[s];
	}

	vector<int> ans;

	for (int K = 1; K <= N; ++K)
	{
		if (N % K)
			continue;

		int S = N / K;

		if (! valid(cnt, S))
			continue;

		map<vector<int>, bool> dp;

		if (dfs(cnt, S, 0, N, dp))
			ans.push_back(K);
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

		vector<pair<int, int>> P(M);

		for (auto& [a, b] : P)
			cin >> a >> b;

		auto r = spooky_splits(N, M, P);

		cout << "Case #" << t << ": ";
		print(r);
	}

	return 0;
}

