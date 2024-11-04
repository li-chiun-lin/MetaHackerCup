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

double line_by_line(double N, double P)
{
	P /= 100.0;
	double logP = log(P);
	double logPP = (N - 1) * logP / N;
	double PP = exp(logPP);

	return (PP - P) * 100;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, P;
		cin >> N >> P;

		cout << "Case #" << t << ": ";
		cout << fixed << setprecision(16) << line_by_line(N, P) << "\n";
	}

	return 0;
}

