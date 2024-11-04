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

pair<int, int> line_of_dev(int N, int G, vector<int>& E)
{
	int d = INT_MAX;
	int s = -1;

	sort(begin(E), end(E), greater<>());

	for (int i = 0; i < size(E); ++i)
	{
		int a = abs(E[i] - G);

		if (d > a)
		{
			d = a;
			s = i + 1;
		}
	}

	return {s, d};
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, G;
		cin >> N >> G;

		vector<int> E(N);

		for (auto& x : E)
			cin >> x;

		auto [a, b] = line_of_dev(N, G, E);

		cout << "Case #" << t << ": ";
		cout << a << " " << b << "\n";
	}

	return 0;
}

