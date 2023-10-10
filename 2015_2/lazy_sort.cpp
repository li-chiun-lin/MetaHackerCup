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

bool check(int pivot, int i, int j, vector<int>& P)
{
	int left = pivot;
	int right = pivot;

	while (i < j)
	{
		if (P[i] == left - 1)
		{
			++ i;
			-- left;
		}
		else if (P[i] == right + 1)
		{
			++ i;
			++ right;
		}
		else if (P[j] == left - 1)
		{
			-- j;
			-- left;
		}
		else if (P[j] == right + 1)
		{
			-- j;
			++ right;
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool lazy_sort(int N, vector<int>& P)
{
	return check(P[0], 1, N - 1, P) || check(P.back(), 0, N - 2, P);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> P(N);

		for (auto& x : P)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << (lazy_sort(N, P) ? "yes" : "no") << "\n";
	}

	return 0;
}

