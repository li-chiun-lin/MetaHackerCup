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

int homework(int A, int B, int K)
{
	vector<int> sieve(B + 1);
	int cnt = 0;

	for (long long i = 2; i <= B; ++i)
		if (sieve[i] == 0)
			for (long long j = i; j <= B; j += i)
				++ sieve[j];

	for (int i = A; i <= B; ++i)
		if (sieve[i] == K)
			++ cnt;

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int A, B, K;
		cin >> A >> B >> K;

		cout << "Case #" << t << ": ";
		cout << homework(A, B, K) << "\n";
	}

	return 0;
}

