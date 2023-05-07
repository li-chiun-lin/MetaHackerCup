/*

*/

//#pragma comment(linker, "/STACK:128777216")
//#pragma comment(linker, "/STACK:64777216")
//#pragma comment(linker, "/STACK:16777216")

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

long long josephus(long long n, long long k)
{
	long long offset = 0;

	for (long long i = 1; i <= n; )
	{
		if (offset + k >= i)
		{
			offset = (offset + k) % i + 1;
			++ i;
		}
		else
		{
			long long moves = (i - offset - 1) / k;
			moves = min(moves, n + 1 - i);
			offset += (k + 1) * moves;
			i += moves;
		}
	}

	return offset;

	#if 0
	if (n == 1)
		return 0;

	if (k == 1)
		return n - 1;

	if (k > n)
		return (josephus(n - 1, k) + k) % n;

	long long ret = josephus(n - n / k, k);
	ret -= n % k;

	if (ret < 0)
		ret += n;
	else
		ret += ret / (k - 1);

	return ret;
	#endif

	//return n == 1 ? 1 : (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long N, K;
		cin >> N >> K;

		cout << "Case #" << t << ": ";
		cout << josephus(N, K) << "\n";
	}

	return 0;
}

