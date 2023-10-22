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

int check(deque<int> AA, deque<int> BB, int zi, int N)
{
	int mid = N / 2;
	int NN = N + N;

	for (int j = 0; j <= NN; ++j)
		{
			if (zi == mid)
			{
				bool valid = true;
				for (int a = 0, b = N - 1; a < b && valid; ++a, --b)
					if (AA[a] > BB[a] || AA[a] != BB[b])
						valid = false;

				if (valid)
					return j;
			}

			zi = (zi - 1 + N) % N;
			AA.push_back(BB.front());
			BB.push_back(AA.front());
			AA.pop_front();
			BB.pop_front();
		}

	return -1;
}


int meta_game(int N, vector<int>& A, vector<int>& B)
{
	vector<int> cmp(N);
	int cnt_zero = 0;
	int zi = 0;

	for (int i = 0; i < N; ++i)
	{
		if (A[i] < B[i])
			cmp[i] = -1;
		else if (A[i] > B[i])
			cmp[i] = 1;
		else
		{
			++ cnt_zero;
			zi = i;
		}
	}

	if (cnt_zero != N % 2)
		return -1;

	int cnt_inv = 0;
	int yi = 0;

	for (int i = 1; i < N; ++i)
	{
		if (A[i - 1] < B[i - 1] && A[i] > B[i])
		{
			++ cnt_inv;
			yi = i;
		}
		else if (A[i - 1] > B[i - 1] && A[i] < B[i])
		{
			++ cnt_inv;
			yi = i;
		}
	}

	if (cnt_inv > 1)
		return -1;

	deque<int> AA(begin(A), end(A)), BB(begin(B), end(B));

	if (N % 2)
	{
		return check(AA, BB, zi, N);
	}
	else
	{
		vector<int> candidate = {0, N - 1};
		
		if (cnt_inv)
			candidate.push_back(yi);

		int ans = N + N;

		for (auto c : candidate)
		{
			auto r = check(AA, BB, c, N);

			if (r != -1)
				ans = min(ans, r);
		}

		return ans == N + N ? -1 : ans;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> A(N), B(N);

		for (auto& x : A)
			cin >> x;

		for (auto& x : B)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << meta_game(N, A, B) << "\n";
	}

	return 0;
}

