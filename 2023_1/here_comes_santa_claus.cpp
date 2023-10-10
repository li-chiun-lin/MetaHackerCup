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

double santa_claus(int N, vector<int>& X)
{
	sort(begin(X), end(X));

	double sum_left = X[0] + X[1];
	double sum_right = X[N - 1] + X[N - 2];

	if (N == 5)
	{
		// add to left
		double s_l = X[0] + X[2];

		// add to right
		double s_r = X[N - 1] + X[N - 3];

		return max(sum_right - s_l, s_r - sum_left) / 2;
	}
	else
	{
		return (sum_right - sum_left) / 2;
	}

	
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> X(N);

		for (auto& x : X)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << fixed << setprecision(6) << santa_claus(N, X) << "\n";
	}

	return 0;
}

