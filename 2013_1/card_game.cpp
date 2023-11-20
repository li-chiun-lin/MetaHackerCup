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

long long pow(long long a, int x, int m)
{
	long long r = 1;

	while (x)
	{
		if (x & 1)
			r = (r * a) % m;
		
		a = (a * a) % m;
		x >>= 1;
	}

	return r;
}

int inv(long long a, int m)
{
	return pow(a, m - 2, m);
}

long long card_game(int N, int K, vector<int>& a)
{
	int m = 1e9 + 7;
	long long nu = 1;

	for (int i = 1; i <= K - 1; ++i)
		nu = (nu * i) % m;

	long long de = inv(nu, m);
	long long ans = 0;

	sort(begin(a), end(a));

	for (int i = K - 1, j = 1; i < N; ++i, ++j)
	{
		long long sum = nu * a[i] % m;
		ans = (ans + sum) % m;
		nu = nu * (i + 1) % m;
		nu = nu * inv(j, m) % m;
	}

	return (ans * de) % m;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> a(N);

		for (auto& x : a)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << card_game(N, K, a) << "\n";
	}

	return 0;
}

