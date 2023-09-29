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

long long naive(long long A, long long B, long long C)
{
	long long ans = 0;

	for (long long x = 0; x * A <= C; ++ x)
		for (long long y = 0; y * B + x * A <= C; ++y)
		{
			long long buns = (x + y) * 2;
			long long cheese = x + y * 2;

			ans = max(ans, min(buns - 1, cheese));
		}

	return ans;
}

long long take3(long long A, long long B, long long C)
{
	if (A * 2 <= B)
	{
		long long x = C / A;
		long long buns = x * 2;
		long long cheese = x;

		return max(min(buns - 1, cheese), 0LL);
	}
	else
	{
		long long y = C / B;
		long long x = (C - B * y) / A;
		long long buns = (x + y) * 2;
		long long cheese = x + y * 2;
		long long k1 = max(min(buns - 1, cheese), 0LL);

		-- y;
		x = (C - B * y) / A;
		buns = (x + y) * 2;
		cheese = x + y * 2;
		long long k2 = max(min(buns - 1, cheese), 0LL);

		return max(k1, k2);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long A, B, C;
		cin >> A >> B >> C;

		cout << "Case #" << t << ": ";
		//cout << naive(A, B, C) << "\n";
		cout << take3(A, B, C) << "\n";
	}

	return 0;
}

