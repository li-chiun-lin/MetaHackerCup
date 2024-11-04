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

int cottontail(long long A, long long B, long long M)
{
	int ans = 0;

	for (int l = 1; l <= 9; ++l)
		for (int r = l; r <= 9; ++r)
		{
			long long val = 0;
			
			for (int d = l; d <= r; ++d)
				val = val * 10 + d;

			for (int d = r - 1; d >= l; --d)
				val = val * 10 + d;

			if (A <= val && val <= B && val % M == 0)
				++ ans;
		}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long A, B, M;

		cin >> A >> B >> M;

		cout << "Case #" << t << ": ";
		cout << cottontail(A, B, M) << "\n";
	}

	return 0;
}

