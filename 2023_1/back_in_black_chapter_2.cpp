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

long long back_in_black(int N, string& S, int Q, vector<int>& B)
{
	int cnt = 0;

	for (auto& c : S)
		c -= '0';

	vector<int> P(N);

	for (int i = 0; i < N; ++i)
		if (S[i])
		{
			for (int j = i; j < N; j += i + 1)
				S[j] = 1 - S[j];

			P[i] = 1;
			++ cnt;
		}

	long long sum = 0;

	for (auto b : B)
	{
		if (P[b - 1])
			-- cnt;
		else
			++ cnt;

		P[b - 1] = 1 - P[b - 1];
		sum += cnt;
	}

	return sum;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, Q;
		string S;
		cin >> N >> S >> Q;

		vector<int> B(Q);

		for (auto& x : B)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << back_in_black(N, S, Q, B) << "\n";
	}

	return 0;
}

