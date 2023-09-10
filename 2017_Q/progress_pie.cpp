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

bool progress(double P, int X, int Y)
{
	double a = X - 50;
	double b = Y - 50;
	double c = sqrt(a * a + b * b);

	if (c > 50)
		return false;

	double rad = asin(abs(a) / c);
	double deg = (rad * 180) / M_PI;
	double p = P * 360 / 100;

	if (a < 0 && b < 0)
		deg += 180;
	else if (a < 0)
		deg = 360 - deg;
	else if (b < 0)
		deg = 180 - deg;

	return deg <= p;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int P, X, Y;
		cin >> P >> X >> Y;

		cout << "Case #" << t << ": ";
		cout << (progress(P, X, Y) ? "black" : "white") << "\n";
	}

	return 0;
}

