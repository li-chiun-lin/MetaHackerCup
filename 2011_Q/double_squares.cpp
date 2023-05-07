/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

set<long long> ss;

int double_square(long long X)
{
	long long v = 0;

	while ((v = ss.size() * ss.size()) <= X)
		ss.insert(v);

	int cnt = 0;

	for (auto a : ss)
	{
		if (a * 2 > X)
			break;

		cnt += ss.count(X - a);
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long X;
		cin >> X;

		cout << "Case #" << t << ": ";
		cout << double_square(X) << "\n";
	}

	return 0;
}

