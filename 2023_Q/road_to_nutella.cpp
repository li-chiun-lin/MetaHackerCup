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

void print(vector<vector<int>>& dst)
{
	int n = dst.size();
	int w = 3;

	cout << "\n";

	cout << setw(w) << "" << "|";
	for (int j = 1; j < n; ++j)
		cout << setw(w) << j;
	cout << "\n";

	cout << "---" << "+";
	for (int j = 1; j < n; ++j)
		cout << "---";
	cout << "\n";

	for (int i = 1; i < n; ++i)
	{
		cout << setw(w) << i << "|";

		for (int j = 1; j < n; ++j)
			cout << setw(w) << (dst[i][j] == INT_MAX ? -1 : dst[i][j]);
		cout << "\n";
	}
	
}

int road_to_nutella(int N, int M, int Q, vector<pair<int, int>>& E, vector<pair<int, int>>& R)
{
	vector<vector<int>> adj(N + 1);

	for (auto [u, v] : E)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<vector<vector<int>>> dst(2, 
		vector<vector<int>>(N + 1, 
			vector<int>(N + 1, INT_MAX)));

	//cout << "\n\n\n";

	for (int i = 1; i <= N; ++i)
	{
		//if (dst[0][i][i] != INT_MAX)
		//	continue;

		dst[0][i][i] = 0;
		//dst[1][i][i] = 0;
		queue<pair<int, int>> que;
		que.push({i, 0});

		//cout << "initiate from " << i << "\n";

		while (size(que))
		{
			auto [u, f] = que.front();
			que.pop();

			//cout << "process " << u << " with foot " << f << "\n"; 

			int other_f = 1 - f;

			for (auto v : adj[u])
			{
				//cout << "check adj " << v << "\n";
				if (dst[other_f][i][v] > dst[f][i][u] + 1)
				{
					dst[other_f][i][v] = dst[f][i][u] + 1;
					que.push({v, other_f});

					//cout << v << " with foot " << other_f << " is longer, set to " << dst[other_f][i][v] << "\n";
				}
			}
		}

		//print(dst[0]);
	}

	print(dst[0]);
	print(dst[1]);

	long long ans = 0;

	for (auto [s, e] : R)
	{
		long long m = max(dst[0][s][e], dst[1][s][e]);
		ans += m == INT_MAX ? -1 : m;
	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, Q;
		cin >> N >> M;

		vector<pair<int, int>> E(M);

		for (auto& [u, v] : E)
			cin >> u >> v;

		cin >> Q;

		vector<pair<int, int>> R(Q);

		for (auto& [a, b] : R)
			cin >> a >> b;

		cout << "Case #" << t << ": ";
		cout << road_to_nutella(N, M, Q, E, R) << "\n";
	}

	return 0;
}

