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

int back_in_black(int N, string& S, int Q, vector<int>& B)
{
	int cnt = 0;

	for (auto& c : S)
		c -= '0';

	map<int, int> hist;

	for (auto b : B)
		++ hist[b];

	for (auto [b, c] : hist)
	{
		if (c % 2 == 0)
			continue;
			
		for (int i = b - 1; i < N; i += b)
			S[i] = 1 - S[i];
	}

	for (int i = 0; i < N; ++i)
		if (S[i])
		{
			for (int j = i; j < N; j += i + 1)
				S[j] = 1 - S[j];

			++ cnt;
		}

	return cnt;
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

