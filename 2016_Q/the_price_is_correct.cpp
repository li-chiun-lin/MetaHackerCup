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

long long the_price_is_correct(int N, int P, vector<int>& B)
{
	long long cnt = 0;
	long long acc = 0;

	for (int l = 0, r = 0; r < N; ++ r)
	{
		acc += B[r];

		while (l < r && acc > P)
			acc -= B[l ++];

		if (acc <= P)
			cnt += r - l + 1;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, P;
		cin >> N >> P;

		vector<int> B(N);

		for (auto& x : B)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << the_price_is_correct(N, P, B) << "\n";
	}

	return 0;
}

