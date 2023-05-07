/*
to be continued.
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void print(vector<int>& v)
{
	if (v.empty())
	{
		cout << "no solution\n";
		return ;
	}

	for (auto& x : v)
		cout << x << " ";
	cout << "\n";
}

vector<int> div(vector<int>& F, vector<int>& G)
{
	int m = F.size();
	int n = G.size();
	int shift = m - n;

	if (shift < 0)
		return {};

	vector<int> H(shift + 1);

	while (shift >= 0)
	{
		if (F[shift + n - 1] % G[n - 1])
			return {};

		int x = F[shift + n - 1] / G[n - 1];

		for (int i = n - 1; i >= 0; --i)
			F[shift + i] -= G[i] * x;

		H[shift --] = x;
	}

	for (int i = 0; i < n; ++i)
		if (F[i])
			return {};
	
	return H;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int D;
		cin >> D;

		vector<int> F(D + 1);

		for (auto& f : F)
			cin >> f;

		cin >> D;

		vector<int> G(D + 1);
		
		for (auto& g : G)
			cin >> g;

		cout << "Case #" << t << ": ";
		auto r = div(F, G);
		print(r);
	}

	return 0;
}

