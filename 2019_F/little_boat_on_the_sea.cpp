/*
to be continued.
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

void print_des(vector<int>& v)
{
	for (int i = 1; i < v.size(); ++i)
		cout << setw(3) << i;
	cout << "\n";
	
	for (int i = 1; i < v.size(); ++i)
		cout << setw(3) << v[i];
	cout << "\n";
}

void print(vector<vector<int>>& adj)
{
	for (int i = 1; i < adj.size(); ++i)
	{
		cout << setw(2) << i << " : ";
		print(adj[i]);
	}
	cout << "\n";
}

void print(map<string, vector<int>>& species)
{
	for (auto& [s, v] : species)
	{
		cout << setw(10) << s << " ";
		for (auto x : v)
			cout << x << " ";
		cout << "\n";
	}

	cout << "\n";
}

int dfs(vector<vector<int>>& adj, vector<int>& other, int p, int u, set<int>& follower)
{
	follower.insert(u);
		
	int cnt = 1;

	for (int v : adj[u])
	{
		if (v == p)
			continue;

		if (other[v] && follower.count(other[v]))
			continue;

		follower.insert(v);

		cnt += dfs(adj, other, u, v, follower);

		follower.erase(v);
	}

	return cnt;
}

int boat(int N, vector<string>& A, vector<pair<int, int>>& XY)
{
	vector<vector<int>> adj(N + 1);

	for (auto [x, y] : XY)
	{
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	map<string, vector<int>> species;

	for (int i = 0; i < N; ++i)
		species[A[i]].push_back(i + 1);

	vector<int> other(N + 2);

	for (auto& [s, v] : species)
		if (s != "-" && v.size() == 2)
		{
			other[v[0]] = v[1];
			other[v[1]] = v[0];
		}

	//cout << "\n";
	//print(species);
	//print(adj);
	//print_des(descendant);

	int cnt = 0;

	for (int i = 1; i <= N; ++i)
	{
		set<int> follower;

		follower.insert(i);

		cnt += dfs(adj, other, -1, i, follower) - 1;
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

		vector<string> A(N);

		for (auto& a : A)
			cin >> a;

		vector<pair<int, int>> XY(N - 1);

		for (auto& [x, y] : XY)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		cout << boat(N, A, XY) << "\n";
	}

	return 0;
}

