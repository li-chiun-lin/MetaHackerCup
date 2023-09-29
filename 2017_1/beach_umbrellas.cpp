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

long long dfs(vector<int>& R, int i, int j, vector<vector<long long>>& dp)
{
	if (i < 0)
	{
		//cout << "good end\n";
		return 1;
	}

	if (j < 0)
	{
		//cout << "bad end\n";
		return 0;
	}

	if (dp[i][j] != -1)
		return dp[i][j];

	long long ret = 0;

	// put i-th umbrella at location j
	if (R[i] <= j)
	{
		//cout << "put " << i << " unbrella at " << (j - R[i]) << "\n";
		ret += dfs(R, i - 1, j - R[i] - R[i], dp);
	}

	// dont
	ret += dfs(R, i, j - 1, dp);

	return dp[i][j] = ret;
}

int beach_umbrellas(int N, int M, vector<int>& R)
{
	map<int, int> hist;

	for (auto x : R)
		++ hist[x];

	map<int, long long> end_with;
	long long mod = 1e9 + 7;

	for (int i = 0; i < N; ++i)
	{
		if (end_with.find(R[i]) == end(end_with))
		{
			int v = R[i];
			swap(R[i], R.back());
			vector<vector<long long>> dp(N, vector<long long>(M + R.back(), -1));
			
			end_with[v] = dfs(R, N - 1, M - 1 + R.back(), dp);

			swap(R[i], R.back());
		}
	}

	long long r = 0;

	for (auto [k, v] : hist)
	{
		//long long rr = end_with[k];

		long long rr = (end_with[k] * v) % mod;

		for (int i = 2; i < N; ++i)
			rr = (rr * i) % mod;

		r = (r + rr) % mod;
	}

	return r;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		vector<int> R(N);

		for (auto& x : R)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << beach_umbrellas(N, M, R) << "\n";
	}

	return 0;
}

