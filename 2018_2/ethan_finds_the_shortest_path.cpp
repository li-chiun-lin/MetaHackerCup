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

void print(vector<vector<int>>& E)
{
	cout << E.size() << "\n";

	for (auto& e : E)
		cout << e[0] << " " << e[1] << " " << e[2] << "\n";
}

int ethan_shortest_path(int N, int K, vector<vector<int>>& E)
{
	int x = K;
	int y = K - 1;
	int sum = 0;

	// corner case
	if (N == 2 || K <= 2)
	{
		E.push_back({1, N, 1});
		return 0;
	}

	// the shortest path i.e. the direct edge.
	E.push_back({1, N, K});

	// ethan's path
	for (int i = 0; i < min(N - 1, K - 1); ++i)
	{
		E.push_back({i + 1, i + 2, y});
		sum += y --;
	}

	// redirect the last edge of ethan's path to node N.
	E.back()[1] = N;

	return sum - x;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<vector<int>> E;

		cout << "Case #" << t << ": ";
		cout << ethan_shortest_path(N, K, E) << "\n";
		print(E);
	}

	return 0;
}

