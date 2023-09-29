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

int pie_progress(int N, int M, vector<vector<int>>& C)
{
	vector<int> cnt(N);
	int acc = 0;

	for (int d = 0; d < N; ++d)
	{
		sort(begin(C[d]), end(C[d]));

		int min_cost = INT_MAX;
		int min_day = 0;

		for (int i = 0; i <= d; ++i)
		{
			int cost = cnt[i] < M ? C[i][cnt[i]] + (cnt[i] * 2 + 1) : INT_MAX;

			if (min_cost > cost)
			{
				min_cost = cost;
				min_day = i;
			}
		}

		acc += min_cost;
		++ cnt[min_day];
	}

	return acc;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int>> C(N, vector<int>(M));

		for (auto& r : C)
			for (auto& c : r)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << pie_progress(N, M, C) << "\n";
	}

	return 0;
}

