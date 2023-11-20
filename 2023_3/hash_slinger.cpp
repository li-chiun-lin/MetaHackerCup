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

int hash_slinger(int N, int M, vector<int>& A)
{
	int ub = 1 << ((int)log2(M) + 1);
	vector<long long> accu(N + 1);

	for (int i = 0; i < N; ++i)
		accu[i + 1] = (accu[i] + A[i]) % M;

	vector<vector<bool>> dp(N + 1, vector<bool>(ub));

	dp[0][0] = true;

	for (int i = 0; i <= N; ++i)
	{
		for (long long x = 0; x < ub; ++x)
		{
			if (dp[i][x])
			{
				for (int j = i + 1; j <= N; ++j)
				{
					dp[j][x] = true;
					dp[j][x ^ ((accu[j] - accu[i] + M) % M)] = true;
				}
			}
		}
	}

	#if 0
	cout << "\n";
	for (int x = 0; x < ub; ++x)
		if (dp[N][x])
			cout << x << " ";
	cout << "\n";
	#endif

	int ans = 0;

	for (int x = 0; x < ub; ++x)
		ans += dp[N][x];
	
	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		vector<int> A(N);

		for (auto& x : A)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << hash_slinger(N, M, A) << "\n";
	}

	return 0;
}

