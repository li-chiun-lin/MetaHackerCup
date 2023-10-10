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

void print(map<pair<int, int>, int>& m)
{
	for (auto& [p, v] : m)
	{
		auto [x, y] = p;

		cout << "[" << setw(3) << x << "," << setw(3) << y << "] = " << v << "\n";
	}
	
	cout << "\n";
}

void count(double X0, double Y0, long long D, vector<pair<int, int>>& P, map<pair<int, int>, int>& hist)
{
	for (auto [X, Y] : P)
	{
		long long dx = X - X0;
		long long dy = Y - Y0;

		if (dx * dx + dy * dy > D * D)
			continue;

		if (dy == 0 && dx == 0)
			++ hist[{0, 0}];
		else if (dy == 0)
			++ hist[{dx / abs(dx), 0}];
		else if (dx == 0)
			++ hist[{0, dy / abs(dy)}];
		else
		{
			long long g = gcd(dx, dy);
			++ hist[{dx / g, dy / g}];
		}
	}
}

long long boomerang(int X0, int Y0, int D, int N, vector<pair<int, int>>& P)
{
	long long ans = 0;
	map<pair<int, int>, int> hist1;

	count(X0, Y0, D, P, hist1);

	for (auto& [p, A] : hist1)
	{
		// move to new (X', Y') D units away from (X0, Y0).

		// count again to find B.

		// ans = max(ans, A * B);
	}
	

	cout << "\n";
	print(hist1);


	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int X0, Y0, D, N;
		cin >> X0 >> Y0 >> D >> N;

		vector<pair<int, int>> P(N);

		for (auto& [x, y] : P)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		cout << boomerang(X0, Y0, D, N, P) << "\n";
	}

	return 0;
}

