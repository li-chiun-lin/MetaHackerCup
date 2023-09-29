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

pair<string, string> cooking_the_books(string& N)
{
	pair<string, string> ans = {N, N};
	int n = N.size();

	// largest
	for (int i = 0; i < n; ++i)
	{
		int m = -1;
		int v = N[i];

		// try to find any digit larger than N[i]
		for (int j = n - 1; j > i; --j)
			if (v < N[j])
			{
				v = N[j];
				m = j;
			}

		if (m == -1)
			continue;

		swap(N[i], N[m]);
		ans.first = N;
		swap(N[i], N[m]);
		break;
	}

	// smallest
	for (int i = 0; i < n; ++i)
	{
		int m = -1;
		int v = N[i];
		
		// special case to avoid leading zero
		if (i == 0)
		{
			for (int j = n - 1; j > i; --j)
				if (N[j] != '0' && v > N[j])
				{
					v = N[j];
					m = j;
				}
		}
		else
		{
			for (int j = n - 1; j > i; --j)
				if (v > N[j])
				{
					v = N[j];
					m = j;
				}
		}

		if (m == -1)
			continue;

		swap(N[i], N[m]);
		ans.second = N;
		swap(N[i], N[m]);
		break;
	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string N;
		cin >> N;

		auto [l, s] = cooking_the_books(N);

		cout << "Case #" << t << ": ";
		cout << s << " " << l << "\n";
	}

	return 0;
}

