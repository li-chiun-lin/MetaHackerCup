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

int boomerang(int N, vector<pair<int, int>>& S)
{
	int cnt = 0;
	vector<vector<int>> dst(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		auto [x0, y0] = S[i];
		map<int, int> hist;

		for (int j = 0; j < N; ++j)
		{
			auto [x, y] = S[j];

			if (dst[i][j] == 0)
				dst[j][i] = dst[i][j] = (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y);

			++ hist[dst[i][j]];
		}

		for (auto [k, v] : hist)
			cnt += v * (v - 1) / 2;
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

		vector<pair<int, int>> S(N);

		for (auto& [x, y] : S)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		cout << boomerang(N, S) << "\n";
	}

	return 0;
}

