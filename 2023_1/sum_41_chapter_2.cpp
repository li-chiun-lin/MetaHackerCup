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

void print(const vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

void dfs(int P, int sum, vector<int>& factor, vector<int>& cur, vector<int>& ans, int& len_ans)
{
	if (P == 1)
	{
		int len = cur.size() + (41 - sum);

		if (len_ans > len)
		{
			len_ans = len;
			ans = cur;
		}
	}
	else
	{
		for (auto f : factor)
		{
			if (P % f || sum + f > 41)
				continue;

			cur.push_back(f);
			dfs(P / f, sum + f, factor, cur, ans, len_ans);
			cur.pop_back();
		}
	}
}

vector<int> sum41(int P)
{
	if (P == 1)
		return vector<int>(41, 1);

	vector<int> factor;

	for (int i = 2; i <= 41; ++i)
		if (P % i == 0)
			factor.push_back(i);

	vector<int> cur, ans;
	int len_ans = 1e9;
	
	dfs(P, 0, factor, cur, ans, len_ans);

	if (ans.size())
	{
		int sum = accumulate(begin(ans), end(ans), 0);

		while (sum ++ < 41)
			ans.push_back(1);
	}
	
	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int P;
		cin >> P;

		cout << "Case #" << t << ": ";
		auto r = sum41(P);

		if (r.size() == 0 || r.size() > 100)
			cout << -1 << "\n";
		else
		{
			cout << r.size() << " ";
			print(r);
		}
	}

	return 0;
}

