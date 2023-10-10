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

long long gcdExtended(long long a, long long b, long long& x, long long& y)
{
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }

    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, x1, y1);
 
    x = y1 - (b / a) * x1;
    y = x1;
 
    return gcd;
}

long long inv(long long A, long long M)
{
    //long long x, y;
    //long long g = gcdExtended(A, M, x, y);
    //return (x % M + M) % M;

	long long m0 = M;
    long long y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        long long q = A / M;
        long long t = M;
 
        M = A % M, A = t;
        t = y;
 
        y = x - q * y;
        x = t;
    }
 
    if (x < 0)
        x += m0;
 
    return x;
}

void print(vector<long long>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

long long great_day(int N, vector<int>& A, int Q, vector<pair<int, int>>& LR)
{
	vector<long long> sweep(N + 2, 1);
	long long times = 1000000006;
	long long mod = 1000000007;
	long long iinv = inv(times, mod);
	long long ans = 0;

	//cout << "inv " << inv(times, mod) << "\n";

	for (auto [l, r] : LR)
	{
		//cout << "range " << l << " " << r << "\n";
		sweep[l - 1] = (sweep[l - 1] * times) % mod;
		sweep[r] = (sweep[r] * iinv) % mod;

		//print(sweep);

		long long accu = 1;
		int min_day = -1;
		long long min_g = -1;

		for (int i = 0; i < N; ++i)
		{
			accu = (accu * sweep[i]) % mod;
			long long g = (accu * A[i]) % mod;

			//cout << g << " ";

			if (min_g < g)
			{
				min_g = g;
				min_day = i;
			}
		}

		//cout << "\n";

		ans += min_day + 1;
	}

	//cout << "\n";
	//print(sweep);

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> A(N);

		for (auto& x : A)
			cin >> x;

		int Q;
		cin >> Q;

		vector<pair<int, int>> LR(Q);

		for (auto& [l, r] : LR)
			cin >> l >> r;

		cout << "Case #" << t << ": ";
		cout << great_day(N, A, Q, LR) << "\n";
	}

	return 0;
}

