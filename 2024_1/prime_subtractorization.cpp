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

long long prime_sub(int N, vector<bool>& sieve)
{
	int cnt = 0;

	for (int i = 3; i + 2 <= N; i += 2)
		if (sieve[i] && sieve[i + 2])
			++ cnt;

	if (N >= 5)
		++ cnt;

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	int ub = 1e7;
	vector<bool> sieve(ub, true);

	for (long long i = 2; i < ub; ++i)
		if (sieve[i])
			for (long long j = i * i; j < ub; j += i)
				sieve[j] = false;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		cout << "Case #" << t << ": ";
		cout << prime_sub(N, sieve) << "\n";
	}

	return 0;
}

