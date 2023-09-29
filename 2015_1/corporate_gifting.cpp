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

void print(vector<vector<int>>& adj)
{
	for (int i = 0; i < size(adj); ++i)
	{
		cout << i << " : ";
		for (auto x : adj[i])
			cout << x << " ";
		cout << "\n";
	}
}

#if 1
int dfs(int u, vector<vector<int>>& adj, long long& cost)
{
	int c = 1;

	if (adj[u].size())
	{
		set<int> ss;

		for (auto v : adj[u])
		{
			ss.insert(dfs(v, adj, cost));
		}

		while (ss.count(c))
			++ c;
	}

	cost += c;
	return c;
}
#endif

long long corporate_gifting(int N, vector<int>& P)
{
	vector<vector<int>> adj(N + 1);

	for (int i = 0; i < N; ++i)
		adj[P[i]].push_back(i + 1);

	long long cost = 0;

	dfs(1, adj, cost);

	return cost;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> P(N);

		for (auto& x : P)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << corporate_gifting(N, P) << "\n";
	}

	return 0;
}

