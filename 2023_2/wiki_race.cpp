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

void compress(int u, vector<vector<int>>& adj, vector<unordered_set<string>>& S, vector<int>& P)
{
	while (adj[u].size() == 1)
	{
		int v = adj[u][0];

		S[u].insert(begin(S[v]), end(S[v]));
		adj[u] = adj[v];
	}

	for (auto v : adj[u])
	{
		P[v] = u;
		compress(v, adj, S, P);
	}
}

int dfs(int u, const string& w, vector<int>& P, vector<vector<int>>& adj, vector<unordered_set<string>>& S)
{
	int cnt_missing = 0;

	for (int v : adj[u])
	{
		cnt_missing += dfs(v, w, P, adj, S);

		if (cnt_missing >= 2)
			return cnt_missing;
	}

	if (S[u].count(w) == 0)
	{
		// leaf node
		if (adj[u].empty() || cnt_missing)
			return 1;
	}

	return 0;
}

int wiki_race(int N, vector<int>& P, vector<int>& M, vector<unordered_set<string>>& S)
{
	vector<vector<int>> adj(N + 1);
	int L = 0;

	for (int i = 2; i <= N; ++i)
		adj[P[i]].push_back(i);

	for (int i = 1; i <= N; ++i)
		if (adj[i].empty())
			++ L;

	unordered_map<string, int> freq;
	
	for (auto& s : S)
		for (auto& w : s)
			++ freq[w];

	compress(1, adj, S, P);

	int cnt = 0;

	for (auto& [w, c] : freq)
	{
		if (c < L)
			continue;

		if (dfs(1, w, P, adj, S) == 0)
			++ cnt;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> P(N + 1);
		vector<int> M(N + 1);
		vector<unordered_set<string>> S(N + 1);

		for (int i = 2; i <= N; ++i)
			cin >> P[i];

		for (int i = 1; i <= N; ++i)
		{
			cin >> M[i];
			string s;

			for (int j = 0; j < M[i]; ++j)
			{
				cin >> s;
				S[i].insert(s);
			}
		}

		cout << "Case #" << t << ": ";
		cout << wiki_race(N, P, M, S) << "\n";
	}

	return 0;
}

