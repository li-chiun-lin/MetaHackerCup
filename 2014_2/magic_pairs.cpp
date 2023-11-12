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

void print(vector<long long>& B)
{
	for (auto x : B)
		cout << setw(3) << x;
	cout << "\n";
}

long long magic_pairs(int N, int M, vector<long long>& B1, vector<long long>& B2)
{
	long long cnt = 0;


	
	
#if 0
	cout << "\n";
	vector<long long> I(max(N, M));
	iota(begin(I), end(I), 0);
	print(I);
	print(B1);
	print(B2);
#endif




	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;
		int NM = max(N, M);
		vector<long long> B1(N), B2(M);
		long long a1, a2, b1, b2, c1, c2, r1, r2;

		cin >> B1[0] >> a1 >> b1 >> c1 >> r1;
		cin >> B2[0] >> a2 >> b2 >> c2 >> r2;

		for (int i = 1; i < NM; ++i)
		{
			if (i < N)
				B1[i] = (a1 * B1[(i - 1) % N] + b1 * B2[(i - 1) % M] + c1) % r1;

			if (i < M)
				B2[i] = (a2 * B1[(i - 1) % N] + b2 * B2[(i - 1) % M] + c2) % r2;
		}

		cout << "Case #" << t << ": ";
		cout << magic_pairs(N, M, B1, B2) << "\n";
	}

	return 0;
}

