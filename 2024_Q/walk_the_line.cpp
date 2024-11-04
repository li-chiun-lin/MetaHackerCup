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

bool walk_the_line(int N, int K, vector<int>& S)
{
	sort(begin(S), end(S));
	long long sum = 0;

	if (size(S) > 2)
	{
		sum += 2ll * S[0] * (size(S) - 2);
		sum += S[0];
	}
	else if (size(S))
	{
		sum += S[0];
	}
	
	return sum <= K;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> S(N);

		for (auto& s : S)
			cin >> s;

		cout << "Case #" << t << ": ";
		cout << (walk_the_line(N, K, S) ? "YES" : "NO") << "\n";
	}

	return 0;
}

