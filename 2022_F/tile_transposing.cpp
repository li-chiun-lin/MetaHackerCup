/*
TLE
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
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void print(vector<vector<int>>& G)
{
	for (auto& g : G)
	{
		for (auto c : g)
			cout << c << " ";
		cout << "\n";
	}
	cout << "\n";
}

int d[] = {1, 0, -1, 0, 1};

int cnt(int R, int C, vector<vector<int>>& G, int x, int y)
{
	queue<pair<int, int>> que;
	vector<vector<bool>> visited(R, vector<bool>(C));

	que.push({x, y});
	visited[x][y] = true;
	int c = 1;

	while (que.size())
	{
		auto [i, j] = que.front();
		que.pop();

		//cout << "pop\n";

		for (int k = 0; k < 4; ++k)
		{
			int ii = i + d[k];
			int jj = j + d[k + 1];

			if (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][jj] == G[x][y] && ! visited[ii][jj])
			{
				//cout << "push " << "\n";
				visited[ii][jj] = true;
				que.push({ii, jj});
				++ c;
			}
		}
	}

	return c < 3 ? 0 : c;
}

long long tile(int R, int C, vector<vector<int>>& G)
{
	long long ret = 0;

	//cout << "\n";

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{
			//cout << (i + 1) << " " << (j + 1) << "\n";
			//print(G);

			int ii = i + 1;

			if (ii < R && G[i][j] != G[ii][j])
			{
				swap(G[i][j], G[ii][j]);
				int c1 = cnt(R, C, G, i, j);
				int c2 = cnt(R, C, G, ii, j);
				swap(G[i][j], G[ii][j]);

				ret += c1 + c2;

				//cout << "swap down " << (ii + 1) << " " << c1 << "+" << c2 << "\n";
			}

			//print(G);

			int jj = j + 1;

			if (jj < C && G[i][j] != G[i][jj])
			{
				
				swap(G[i][j], G[i][jj]);
				int c1 = cnt(R, C, G, i, j);
				int c2 = cnt(R, C, G, i, jj);
				swap(G[i][j], G[i][jj]);

				ret += c1 + c2;

				//cout << "swap right " << (jj + 1) << " " << c1 << "+" << c2 << "\n";
			}

			//print(G);
		}

	return ret * 2;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C;
		cin >> R >> C;

		vector<vector<int>> G(R, vector<int>(C));

		for (auto& g : G)
			for (auto& c : g)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << tile(R, C, G) << "\n";
	}

	return 0;
}

