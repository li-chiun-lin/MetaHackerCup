/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void print(pair<int, double> x)
{
	//cout << x.first << " " << fixed << setprecision(6) << x.second << "\n";
	//printf("%d %.8lf\n", x.first, x.second);

	double d = (x.second * 1e9 + 0.5) / 1e9;
	printf("%d %.6lf\n", x.first, d);
}

void print(vector<vector<double>>& grid)
{
	for (int i = 0; i < grid.size(); ++i)
	{
		if (i & 1)
		{
			for (int j = 0; j < grid[i].size(); ++j)
				cout << setw(8) << setprecision(4) << grid[i][j];
		}
		else
		{
			cout << string(4, ' ');

			for (int j = 0; j < grid[i].size() - 1; ++j)
				cout << setw(8) << setprecision(4) << grid[i][j];
		}

		cout << "\n";
	}
}

double drop(int R, int C, int K, int D, set<vector<int>>& ss)
{
	vector<vector<double>> grid(R, vector<double>(C));
	grid[0][D] = 1;  

	for (int i = 0; i < R - 1; ++i)
	{
		if (i & 1)
		{
			for (int j = 1; j < C - 1; ++j)
			{
				if (ss.count({i + 1, j}))
					grid[i + 2][j] += grid[i][j];
				else
				{
					grid[i + 1][j - 1] += grid[i][j] / 2;
					grid[i + 1][j] += grid[i][j] / 2;
				}
			}
		}
		else
		{
			if (ss.count({i + 1, 0}))
				grid[i + 2][0] += grid[i][0];
			else
				grid[i + 1][1] += grid[i][0];
			
			for (int j = 1; j < C - 2; ++j)
			{
				if (ss.count({i + 1, j}))
					grid[i + 2][j] += grid[i][j];
				else
				{
					grid[i + 1][j] += grid[i][j] / 2;
					grid[i + 1][j + 1] += grid[i][j] / 2;
				}
			}

			if (ss.count({i + 1, C - 2}))
				grid[i + 2][C - 2] += grid[i][C - 2];
			else
				grid[i + 1][C - 2] += grid[i][C - 2];
		}
	}

	//cout << "\n";
	//print(grid);

	return grid[R - 1][K];
}

pair<int, double> peg(int R, int C, int K, int M, vector<vector<int>>& missing)
{
	set<vector<int>> ss(begin(missing), end(missing));
	//set<vector<int>> ss;

	int max_i = 0;
	double max_v = 0;

	for (int i = 0; i < C - 1; ++i)
	{
		auto v = drop(R, C, K, i, ss);

		if (max_v < v)
		{
			max_v = v;
			max_i = i;
		}
	}

	return {max_i, max_v};
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C, K, M;
		cin >> R >> C >> K >> M;

		vector<vector<int>> missing(M, vector<int>(2));

		for (auto& m : missing)
			cin >> m[0] >> m[1];

		cout << "Case #" << t << ": ";
		print(peg(R, C, K, M, missing));
	}

	return 0;
}

