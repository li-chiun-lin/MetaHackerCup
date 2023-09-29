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

bool check(map<int, int>& apple, long long daily)
{
	for (auto [k, v] : apple)
	{
		if (k * 2 >= daily)
			break;
		else if (k * 2 == daily)
			return v % 2 == 0;
		else if (apple.count(daily - k) == 0 || apple[daily - k] != v)
			return false;
	}

	return true;
}

int take2(int N, vector<int>& A)
{
	if (N == 1)
		return 1;

	long long sum = accumulate(begin(A), end(A), 0LL);
	map<int, int> apple;

	for (int a : A)
		++ apple[a];

	for (auto it = rbegin(apple); it != rend(apple); ++it)
	{
		int extra = it->first;

		if ((sum - extra) % (N - 1))
			continue;

		long long daily = (sum - extra) / (N - 1);

		if (daily <= extra)
			continue;

		sum -= extra;
		if (-- apple[extra] == 0)
			apple.erase(extra);

		if (check(apple, daily))
			return daily - extra;
		
		sum += extra;
		++ apple[extra];
	}

	return -1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> A(N * 2 - 1);

		for (auto& x : A)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << take2(N, A) << "\n";
	}

	return 0;
}

