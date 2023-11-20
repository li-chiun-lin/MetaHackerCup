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

int find_the_min(int n, int k, int a, long long b, int c, int r)
{
	vector<int> m(2 * k + 1);
	set<int> available;
	multiset<int> dup;

	for (int i = 0; i <= k; ++i)
		available.insert(i);

	m[0] = a;
	available.erase(a);
	dup.insert(a);

	for (int i = 1; i < k; ++i)
	{
		m[i] = (b * m[i - 1] + c) % r;
		available.erase(m[i]);
		dup.insert(m[i]);
	}

	for (int i = k; i < 2 * k; ++i)
	{
		m[i] = *begin(available);
		available.erase(m[i]);

		dup.erase(dup.find(m[i - k]));

		if (m[i - k] <= k && dup.find(m[i - k]) == end(dup))
			available.insert(m[i - k]);
	}

	m[2 * k] = *begin(available);

	if (n <= 2 * k)
		return m[n];
	else
		return m[k + (n - 2 * k - 1) % (k + 1)];
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int n, k, a, b, c, r;
		cin >> n >> k >> a >> b >> c >> r;

		cout << "Case #" << t << ": ";
		cout << find_the_min(n - 1, k, a, b, c, r) << "\n";
	}

	return 0;
}

