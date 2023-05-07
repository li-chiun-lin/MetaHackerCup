/*

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

int nfact(int a, int b, int n)
{
	vector<int> sieve(b + 1);

	for (int i = 2; i <= b; ++i)
		if (sieve[i] == 0)
			for (int j = i; j <= b; j += i)
				++ sieve[j];

	int cnt = 0;

	for (int i = a; i <= b; ++i)
		if (sieve[i] == n)
			++ cnt;

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int a, b, n;
		cin >> a >> b >> n;

		cout << "Case #" << t << ": ";
		cout << nfact(a, b, n) << "\n";
	}

	return 0;
}

