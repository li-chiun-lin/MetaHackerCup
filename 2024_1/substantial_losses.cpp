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

int mul(long long a, long long b, int m)
{
	long long r = 1;
	long long base = b;

	while (base)
	{
		if (base & 1)
			r = (r + b) % m;

		b = (b + b) % m;
		base >>= 1;
	}

	return r;
}

int pow(long long a, long long x, int m)
{
	long long r = 1;

	while (x)
	{
		if (x & 1)
			r = r * a % m;

		a = a * a % m;
		x >>= 1;
	}

	return r;
}

int inv(long long a, int m)
{
	return pow(a, m - 2, m);
}

int substantial_losses(long long W, long long G, long long L)
{
	int mod = 998244353;
	
	//L %= mod;

	long long a = (L * 2 + 1) % mod;
	long long b = (W - G) % mod;

	return a * b % mod;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long W, G, L;

		cin >> W >> G >> L;

		cout << "Case #" << t << ": ";
		cout << substantial_losses(W, G, L) << "\n";
	}

	return 0;
}

