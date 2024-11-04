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

void dfs(int len, unsigned long long val, int prev_digit, vector<vector<vector<unsigned long long>>>& result)
{
	if (prev_digit)
		result[prev_digit][len].push_back(val);

	if (len == 8)
		return ;

	val *= 10ULL;

	for (int d = prev_digit; d <= 9; ++d)
		dfs(len + 1, val + d, d, result);
}

long long reverse(long long x)
{
	long long y = 0;

	while (x)
	{
		y = y * 10 + (x % 10);
		x /= 10;
	}

	return y;
}

int cnt(unsigned long long x)
{
	int c = 0;

	while (x)
	{
		++ c;
		x /= 10;
	}

	return c;
}

unsigned long long merge(unsigned long long x, int d, unsigned long long y)
{
	x = x * 10ULL + d;
	x = x * (unsigned long long)pow(10ULL, cnt(y)) + y;

	return x;
}

long long cottontail(unsigned long long A, unsigned long long B, unsigned long long M, set<unsigned long long>& mountain)
{
	long long ans = 0;

	for (auto v : mountain)
	{
		if (v < A)
			continue;

		if (v > B)
			break;

		if (v % M == 0)
			++ ans;
	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	vector<vector<vector<unsigned long long>>> uphill(10, vector<vector<unsigned long long>>(10)), downhill(10, vector<vector<unsigned long long>>(10));

	for (int d = 1; d <= 9; ++d)
		dfs(1, d, d, uphill);

	for (int d = 1; d <= 9; ++d)
		for (int l = 1; l <= 8; ++l)
			for (auto x : uphill[d][l])
				downhill[d][l].push_back(reverse(x));

	set<unsigned long long> mountain;

	for (int d = 1; d <= 9; ++d)
		mountain.insert(d);

	for (int d = 2; d <= 9; ++d)
		for (int dx = 1; dx < d; ++dx)
			for (int dy = 1; dy < d; ++dy)
				for (int l = 1; l <= 8; ++l)
					for (unsigned long long x : uphill[dx][l])
						for (unsigned long long y : downhill[dy][l])
							mountain.insert(merge(x, d, y));

	for (int t = 1; t <= T; ++t)
	{
		unsigned long long A, B, M;

		cin >> A >> B >> M;

		cout << "Case #" << t << ": ";
		cout << cottontail(A, B, M, mountain) << "\n";
	}

	return 0;
}

