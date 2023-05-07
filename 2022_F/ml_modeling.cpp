/*
something's wrong
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

void print(map<int, vector<tuple<double, double, double>>>& well)
{
	for (auto& [r, pos] : well)
	{
		cout << r << ": ";
		for (auto& [x, y, s] : pos)
			cout << x << "," << y << " ";
		cout << "\n";
	}

	cout << "\n";
}

double dst2(double x1, double y1, double x2, double y2)
{
	double dx = x1 - x2;
	double dy = y1 - y2;
	return dx * dx + dy * dy;
}

tuple<int, int, int, int, int> ml(int N, vector<pair<double, double>>& trees)
{
	map<int, vector<tuple<double, double, double>>> wells;
	int ubound = 50;
	int ubound_square = ubound * ubound;

	for (int x = 0; x <= ubound; ++x)
		for (int y = 0; y <= ubound; ++y)
		{
			double r_square = 1;
			double dst_square_sum = 0;

			for (auto& [tx, ty] : trees)
			{
				auto dst_square = dst2(x, y, tx, ty);
				r_square = max(r_square, dst_square);
				dst_square_sum += dst_square;
			}

			if (r_square > ubound_square)
				continue;

			int r = ceil(sqrt(r_square));
			wells[r].push_back({x, y, dst_square_sum});
		}
	
	double min_area = INT64_MAX;
	tuple<int, int, int, int, int> ret;

	for (auto& [r, pos] : wells)
	{
		for (int i = 0; i < pos.size(); ++i)
		{
			auto [x1, y1, s1] = pos[i];

			for (int j = i + 1; j < pos.size(); ++j)
			{
				auto [x2, y2, s2] = pos[j];

				int dst_between_two_wells_square = dst2(x1, y1, x2, y2);
				int r2_square = pow(2 * r, 2);

				if (dst_between_two_wells_square >= r2_square)
					continue;

				double dst_between_two_wells = sqrt(dst_between_two_wells_square);
				double d4 = sqrt(r2_square - dst_between_two_wells_square);
				double area = r * r * M_PI
						 	- r * r * 2 * atan2(dst_between_two_wells, d4)
						 	- dst_between_two_wells * 0.5 * d4;

				if (min_area > area)
				{
					min_area = area;

					if (s1 < s2)
						ret = {x1, y1, x2, y2, r};
					else
						ret = {x2, y2, x1, y1, r};
				}
			}
		}
	}

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

		vector<pair<double, double>> tree(N);

		for (auto& x : tree)
			cin >> x.first >> x.second;

		auto [Ax, Ay, Bx, By, R] = ml(N, tree);

		cout << "Case #" << t << ": ";
		cout << Ax << " " << Ay << " " << Bx << " " << By << " " << R << "\n";
	}

	return 0;
}

