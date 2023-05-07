#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

void print(map<int, vector<int>>& adj)
{
	for (auto& h : adj)
	{
		cout << (char)('A' + h.first) << ": ";
		for (auto& x : h.second)
			cout << (char)('A' + x) << " ";
		cout << endl;
	}
	cout << endl;
}

void print(map<char, int>& hit)
{
	for (auto& h : hit)
		cout << h.first << " - " << h.second << endl;
}

void print(vector<vector<int>>& dst)
{
	cout << "   ";
	for (char i = 'A'; i <= 'Z'; ++i)
		cout << setw(3) << i;
	cout << endl;

	for (int i = 0; i < 26; ++i)
	{
		cout << setw(3) << (char)('A' + i);
		for (int j = 0; j < 26; ++j)
			cout << setw(3) << (dst[i][j] == INT_MAX ? -1 : dst[i][j]);
		cout << endl;
	}
	cout << endl;
}

int bfs(int from, int to, map<int, vector<int>>& adj)
{
	queue<int> que;
	map<int, bool> visited;
	int s = 0;
	int p = 0;

	que.push(from);
	visited[from] = true;

	while (s = (int)que.size())
	{
		while (s--)
		{
			char u = que.front();
			que.pop();

			if (u == to)
				return p;

			for (char v : adj[u])
			{
				if (visited[v])
					continue;

				visited[v] = true;
				que.push(v);
			}
		}

		++p;
	}

	return INT_MAX;
}



int consis2(string str, vector<string> vec)
{
	map<int, int> hit;
	map<int, vector<int>> adj;
	vector<vector<int>> dst(26, vector<int>(26, INT_MAX));

	for (char c : str)
		++hit[c - 'A'];

	if (hit.size() == 1)
		return 0;

	for (auto& e : vec)
		adj[e[0] - 'A'].push_back(e[1] - 'A');

	// create table
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			dst[i][j] = bfs(i, j, adj);

	//print(adj);
	//print(dst);

	int m = INT_MAX;

	for (int v = 0; v < 26; ++v)
	{
		int c = 0;

		for (auto& u : hit)
		{
			if (dst[u.first][v] == INT_MAX)
			{
				c = INT_MAX;
				break;
			}

			c += dst[u.first][v] * u.second;
		}

		//cout << "to " << (char)(v + 'A') << " " << (c == INT_MAX ? -1 : c) << endl;

		m = min(m, c);
	}

	return m == INT_MAX ? -1 : m;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		string str = "";
		int K = 0;
		cin >> str;
		cin >> K;

		vector<string> vec(K);

		for (int j = 0; j < K; ++j)
			cin >> vec[j];

		cout << "Case #" << i << ": ";
		cout << consis2(str, vec) << endl;
	}

	return 0;
}