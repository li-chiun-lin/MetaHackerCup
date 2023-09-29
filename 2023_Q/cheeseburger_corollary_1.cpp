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

bool check(int S, int D, int K)
{
	int bun = (S + D) * 2;
	int cheese = S + D * 2;

	return bun >= K + 1 && cheese >= K;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int S, D, K;
		cin >> S >> D >> K;

		cout << "Case #" << t << ": ";
		cout << (check(S, D, K) ? "YES" : "NO") << "\n";
	}

	return 0;
}

