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

double subsonic(int N, vector<int>& A, vector<int>& B)
{
	double ub = INT_MAX;
	double lb = 0;

	for (int i = 0; i < N; ++i)
	{
		double u = A[i] ? (double)(i + 1) / A[i] : INT_MAX;
		double l = B[i] ? (double)(i + 1) / B[i] : INT_MAX;

		ub = min(ub, u);
		lb = max(lb, l);
	}

	return ub >= lb ? lb : -1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> A(N), B(N);

		for (int i = 0; i < N; ++i)
			cin >> A[i] >> B[i];

		cout << "Case #" << t << ": ";
		cout << subsonic(N, A, B) << "\n";
	}

	return 0;
}

