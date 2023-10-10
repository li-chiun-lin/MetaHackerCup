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

vector<int> sum41(int P)
{
	vector<int> factor;
	int sum = 0;

	for (int i = 2; i * i <= P && P > 1; ++i)
	{
		while (P > 1 && P % i == 0)
		{
			if (i > 41)
				return {};

			factor.push_back(i);
			sum += i;
			P /= i;
		}
	}

	if (P > 1)
	{
		factor.push_back(P);
		sum += P;
	}

	if (sum > 41)
		return {};

	while (sum < 41)
	{
		factor.push_back(1);
		++ sum;
	}

	return factor;
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

