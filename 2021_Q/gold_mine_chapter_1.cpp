#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int find_max(int u, vector<vector<int>>& adj, vector<int> &ore, vector<bool> &visited)
{
	int m = 0;

	for (int v : adj[u])
	{
		if (visited[v])
			continue;

		visited[v] = true;
		int r = find_max(v, adj, ore, visited);
		m = max(m, r);
		visited[v] = false;
	}

	return m + ore[u - 1];
}

int gold_mine_1(vector<int> ore, vector<pair<int, int>> tunnel)
{
	int n = (int)ore.size();
	vector<vector<int>> adj(n + 1);
	vector<bool> visited(n + 1);

	for (auto& e : tunnel)
	{
		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);
	}

	visited[1] = true;

	if (adj[1].size() == 0)
		return ore[0];
	else if (adj[1].size() == 1)
	{
		visited[adj[1][0]] = true;
		return find_max(adj[1][0], adj, ore, visited) + ore[0];
	}
	else
	{
		priority_queue<int> pq;
		for (int v : adj[1])
		{
			visited[v] = true;
			pq.push(find_max(v, adj, ore, visited));
		}

		int r = pq.top();
		pq.pop();
		r += pq.top();
		
		return r + ore[0];
	}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int N;
		cin >> N;

		vector<int> vec(N);

		for (int j = 0; j < N; ++j)
			cin >> vec[j];

		vector<pair<int, int>> edge(N - 1);

		for (int j = 0; j < N - 1; ++j)
		{
			int a, b;
			cin >> a >> b;
			edge[j] = { a, b };
		}

		cout << "Case #" << i << ": ";
		cout << gold_mine_1(vec, edge) << endl;
	}

	return 0;
}