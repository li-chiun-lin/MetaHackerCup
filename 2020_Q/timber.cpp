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
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void print(vector<pair<int, int>>& v)
{
	for (auto [p, h] : v)
		cout << "(" << p << "," << h << ") ";
	cout << "\n";
}

void dfs(int N, vector<pair<int, int>>& tree, int i, int end, int len, int& ret)
{
	if (i == N)
	{
		ret = max(ret, len);
		return ;
	}

	int left = 0;
	int dont = 0;
	int right = 0;
	auto [p, h] = tree[i];

	// fall to left
	if (end == p - h)
	{
		dfs(N, tree, i + 1, p, len + h, ret);
	}
	else if (end < p - h)
	{
		ret = max(ret, len);
		dfs(N, tree, i + 1, p - h, h, ret);
	}

	// fall to right
	if (end == p)
	{
		dfs(N, tree, i + 1, p + h, len + h, ret);
	}
	else if (end < p)
	{
		ret = max(ret, len);
		dfs(N, tree, i + 1, p + h, h, ret);
	}

	// do not cut
	dfs(N, tree, i + 1, end, len, ret);
}

int timber(int N, vector<pair<int, int>>& tree)
{
	sort(begin(tree), end(tree));
	int ret = 0;

	dfs(N, tree, 0, INT_MIN, 0, ret);

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<pair<int, int>> tree(N);

		for (auto& [p, h] : tree)
			cin >> p >> h;

		cout << "Case #" << t << ": ";
		cout << timber(N, tree) << "\n";
	}

	return 0;
}

