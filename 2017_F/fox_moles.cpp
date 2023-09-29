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

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

void print(map<int, vector<int>>& m)
{
	for (auto& [k, v] : m)
	{
		cout << k << " = ";
		print(v);
	}
}

void print(vector<vector<int>>& m)
{
	for (int i = 0; i < size(m); ++i)
	{
		cout << setw(2) << i << " : ";
		print(m[i]);
	}
}

void print(map<int, int>& m)
{
	for (auto [k, v] : m)
		cout << k << ":" << v << " ";
	cout << "\n";
}

int fox_moles(int N, vector<int>& P, vector<int>& R)
{
	map<int, int> label;
	map<int, vector<int>> adj;

	for (int i = 0; i < N; ++i)
	{
		int l = P[i] - R[i];
		int r = P[i] + R[i];

		adj[l].push_back(r);
		adj[r].push_back(l);
		label[P[i]] = 0;
	}

	int seg = 0;

	for (auto& [p, lst] : adj)
	{
		if (label.count(p))
			continue;

		++ seg;
		label[p] = 1;
		queue<int> que;
		que.push(p);

		while (que.size())
		{
			auto u = que.front();
			que.pop();

			for (auto v : adj[u])
			{
				if (label.count(v))
				{
					if (label[v] == label[u])
						return -1;
				}
				else
				{
					label[v] = label[u] * -1;
					que.push(v);
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		int l = P[i] - R[i];
		int r = P[i] + R[i];

		if (label[l] == label[r])
			return -1;
	}

	cout << "segment " << seg << "\n";
	print(label);

	int cnt = 1;

	for (auto [k, v] : label)
		if (v == -1)
			++ cnt;

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

		vector<int> P(N), R(N);

		for (int i = 0; i < N; ++i)
			cin >> P[i] >> R[i];

		cout << "Case #" << t << ": ";
		cout << fox_moles(N, P, R) << "\n";
	}

	return 0;
}

