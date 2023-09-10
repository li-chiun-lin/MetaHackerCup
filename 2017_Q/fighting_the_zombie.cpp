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

tuple<int, int, int> parse(string s)
{
	int i = 0;
	int X = 0;
	int Y = 0;
	int sign = 0;
	int Z = 0;

	while (s[i] != 'd')
	{
		X = X * 10 + s[i] - '0';
		++ i;
	}

	++ i;

	while (isdigit(s[i]))
	{
		Y = Y * 10 + s[i] - '0';
		++ i;
	}

	if (i == s.size())
		return {X, Y, Z};

	sign = s[i] == '+' ? 1 : -1;

	++ i;

	while (i < s.size())
	{
		Z = Z * 10 + s[i] - '0';
		++ i;
	}

	return {X, Y, sign * Z};
}

void print(map<int, long double>& m)
{
	for (auto [k, v] : m)
		cout << k << ":" << v << " ";
	cout << "\n";
}

void print(vector<map<int, long double>>& m)
{
	for (auto& e : m)
		print(e);
	cout << "\n";
}

map<int, long double> comb(int X, int Y, int Z)
{
	vector<map<int, long double>> cnt(2);
	int cur = 0;
	int pre = 1;
	cnt[pre][0] = 1;

	for (int k = 1; k <= X; ++k)
	{
		cnt[cur] = {};

		for (int v = 1; v <= Y; ++v)
		{
			for (auto [vv, cc] : cnt[pre])
			{
				cnt[cur][vv + v] += cc;
			}
		}

		pre = cur;
		cur = 1 - cur;
	}

	cnt[cur] = {};
	
	for (auto [vv, cc] : cnt[pre])
		cnt[cur][vv + Z] = cc;

	return cnt[cur];
}

long double fighting_the_zombie(int H, int S, vector<string>& P)
{
	long double ret = 0;

	for (auto& p : P)
	{
		auto [X, Y, Z] = parse(p);
		auto cnt = comb(X, Y, Z);
		long double accu = 0;
		long double total = 1;

		for (int i = 0; i < X; ++i)
			total *= Y;

		for (auto [k, v] : cnt)
			if (k >= H)
				accu += v / total;

		ret = max(ret, accu);

		//cout << X << " " << Y << " " << Z << "\n";
		//print(cnt);
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int H, S;
		cin >> H >> S;

		vector<string> P(S);

		for (auto& p : P)
			cin >> p;

		cout << "Case #" << t << ": ";
		cout << fixed << setprecision(6) << fighting_the_zombie(H, S, P) << "\n";
	}

	return 0;
}

