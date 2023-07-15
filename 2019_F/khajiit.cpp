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

void print(string& S, int N, int M)
{
	cout << S[0] << " ";

	for (int i = 0; i < N; ++i)
	{
		for (int j = M - 1; j >= 0; --j)
			cout << S[i * M + j + 1];
		cout << " ";
	}
	cout << "\n";
}

void print(vector<vector<int>>& unbalanced)
{
	for (int i = 0; i < unbalanced.size(); ++i)
	{
		cout << (char)('A' + i) << ": ";

		for (auto x : unbalanced[i])
			cout << x << " ";
		cout << "\n";
	}
	cout << "\n";
}

long long khajiit(int N, int M, string& X, string& Y)
{
	int NM1 = X.size();
	long long cnt = 0;

	// for each line, 
	for (int i = 0; i < N; ++i)
	{
		int k = M - 1;

		// check each town from far to near.
		for (int j = M - 1; j >= 0; --j)
		{
			int idx = i * M + j + 1;
			vector<bool> not_found(2);

			// if we encounter an unmatch stock, 
			if (X[idx] != Y[idx])
			{
				// we have known that there are no matching of this type in this line.
				if (not_found[X[idx] - 'A'])
				{
					cnt += j + 1;
					continue;
				}

				// we start the search from where we stop previously.
				k = min(k, j - 1);
				int idx2 = i * M + k + 1;

				// find the nearest match stock within this line.
				while (k >= 0 && X[idx] != Y[idx2])
				{
					-- k;
					-- idx2;
				}

				// if we found a match stock, 
				// it means any stock in between are the same type as X[idx], 
				// we don't have to simulate each swap, 
				// we only sway the two end-points.
				if (k >= 0)
				{
					// this is the number of swap we have to perform.
					cnt += j - k;
					swap(Y[idx2], Y[idx]);
				}
				// if no paring found
				else
				{
					// mark this fact, 
					// so that we don't waste time on any furture search of this type in this line.
					not_found[X[idx] - 'A'] = true;

					// since this X[idx] will eventually find its match in other line, 
					// we count the number of swaps we need to move X[idx] to root 0.
					cnt += j + 1;
				}
			}
		}
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		string X, Y;

		cin >> N >> M >> X >> Y;

		cout << "Case #" << t << ": ";
		cout << khajiit(N, M, X, Y) << "\n";
	}

	return 0;
}

