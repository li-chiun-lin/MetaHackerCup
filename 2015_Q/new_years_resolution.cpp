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

bool new_years_resolution(int GP, int GC, int GF, int N, vector<tuple<int, int, int>>& F)
{
	int ub = 1 << N;

	for (int select = 1; select < ub; ++select)
	{
		int p = GP, c = GC, f = GF;

		for (int j = 0, mask = 1; j < N && p >= 0 && c >= 0 && f >= 0; ++j, mask <<= 1)
			if (mask & select)
			{
				auto [x, y, z] = F[j];
				p -= x;
				c -= y;
				f -= z;
			}

		if (p == 0 && c == 0 && f == 0)
			return true;
	}

	return false;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, GP, GC, GF;
		cin >> GP >> GC >> GF >> N;

		vector<tuple<int, int, int>> F(N);

		for (auto& [p, c, f] : F)
			cin >> p >> c >> f;

		cout << "Case #" << t << ": ";
		cout << (new_years_resolution(GP, GC, GF, N, F) ? "yes" : "no") << "\n";
	}

	return 0;
}

