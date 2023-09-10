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

int lazy_loading(int N, vector<int>& W)
{
	int trip = 0;
	int i = 0;
	bool have_rem = false;

	sort(begin(W), end(W));

	for (int j = N - 1; i <= j; --j)
	{
		int w = W[j];

		while (w < 50 && i < j)
		{
			w += W[j];
			++ i;
		}

		if (w >= 50)
			++ trip;
		else
			have_rem = true;
	}

	if (trip == 0 && have_rem)
		++ trip;

	return trip;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> W(N);

		for (auto& w : W)
			cin >> w;

		cout << "Case #" << t << ": ";
		cout << lazy_loading(N, W) << "\n";
	}

	return 0;
}

