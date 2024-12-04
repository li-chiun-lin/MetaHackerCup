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

bool all_triplets(int N, vector<int>& U, vector<int>& V)
{
	vector<vector<int>> adj(N);

	for (int i = 0; i < N - 1; ++i)
	{
		adj[U[i] - 1].push_back(V[i] - 1);
		adj[V[i] - 1].push_back(U[i] - 1);
	}

	for (int u = 0; u < N; ++u)
	{
		vector<int> left;

		for (int v : adj[u])
			if (v < u)
				left.push_back(v);

		int twoEdge = -1;

		for (int l : left)
			if (size(adj[l]) > 1)
			{
				twoEdge = l;
				break;
			}

		int oneEdge = -1;

		for (int l : left)
			if (l != twoEdge)
			{
				oneEdge = l;
				break;
			}

		if (twoEdge != -1 && oneEdge != -1)
			return false;
	}

	return true;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> U(N - 1), V(N - 1);

		for (int i = 0; i < N - 1; ++i)
			cin >> U[i] >> V[i];

		cout << "Case #" << t << ": ";
		cout << (all_triplets(N, U, V) ? "Lucky" : "Wrong") << "\n";
	}

	return 0;
}

