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

int find(vector<int>& g, int x)
{
	return g[x] == x ? x : g[x] = find(g, g[x]);
}

void join(vector<int>& g, int x, int y)
{
	g[find(g, x)] = find(g, y);
}

int fall_in_line(int N, vector<pair<int, int>>& P)
{
	int mx = 0;

	//cout << "\n";

	for (int i = 0; i < N; ++i)
	{
		map<pair<int, int>, int> cnt;
		pair<int, int> d;
		auto [x1, y1] = P[i];

		//cout << "i " << x1 << " " << y1 << "\n";

		for (int j = i + 1; j < N; ++j)
		{
			auto [x2, y2] = P[j];

			//cout << "  j " << x2 << " " << y2 << "\n";

			int dx = x1 - x2;
			int dy = y1 - y2;

			if (dx)
			{
				if (dy)
				{
					//cout << "dx dy " << dx << " " << dy << "\n";
					int g = gcd(dx, dy);
					dy /= g;
					dx /= g;

					//cout << "g " << g << "\n";
					//cout << dy << " " << dy << "\n";

					if (dx < 0)
					{
						dx *= -1;
						dy *= -1;
					}

					d = {dy, dx};
				}
				else
				{
					//cout << "dx 0\n";
					d = {0, 0};
				}
			}
			else
			{
				//cout << "0 dy\n";
				d = {-1, 0};
			}

			++ cnt[d];
		}

		//cout << "i = " << i << "\n";

		for (auto& [p, c] : cnt)
		{
			//cout << "  " << p.first << "," << p.second << " " << c << "\n";
			mx = max(mx, c);
		}
	}

	//cout << "mx = " << mx << "\n";

	return N - (mx + 1);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<pair<int, int>> P(N);

		for (auto& [x, y] : P)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		cout << fall_in_line(N, P) << "\n";
	}

	return 0;
}

