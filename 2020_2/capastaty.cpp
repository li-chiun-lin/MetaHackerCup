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

void print(vector<vector<int>>& table)
{
	for (auto& t : table)
		cout << t[0] << " " << t[1] << " " << t[2] << "\n";
	cout << "\n";
}

long long capastaty(int N, vector<int>& S, vector<int>& X, vector<int>& Y)
{
	long long cnt = 0;
	long long must_move = 0;
	long long must_fill = 0;
	long long can_fill = 0;
	long long can_move = 0;

	for (int i = 0; i < N; ++i)
	{
		int s = S[i];
		int lb = X[i];
		int ub = lb + Y[i];

		if (s < lb)
			must_fill += lb - s;
		else if (ub < s)
			must_move += s - ub;
		
		if (s < ub)
			can_fill += ub - s;

		if (lb < s)
			can_move += s - lb;
	}

	if (must_fill > can_move)
		return -1;

	if (must_move > can_fill)
		return -1;

	return max(must_move, must_fill);
}

void extend(int N, int K, vector<int>& V, long long A, long long B, long long C, long long D)
{
	for (int i = K; i < N; ++i)
		V[i] = (A * V[i - 2] + B * V[i - 1] + C) % D; 
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> S(N), X(N), Y(N);
		long long As, Bs, Cs, Ds;
		long long Ax, Bx, Cx, Dx;
		long long Ay, By, Cy, Dy;

		for (int i = 0; i < K; ++i)
			cin >> S[i];

		cin >> As >> Bs >> Cs >> Ds;

		extend(N, K, S, As, Bs, Cs, Ds);

		for (int i = 0; i < K; ++i)
			cin >> X[i];

		cin >> Ax >> Bx >> Cx >> Dx;

		extend(N, K, X, Ax, Bx, Cx, Dx);

		for (int i = 0; i < K; ++i)
			cin >> Y[i];

		cin >> Ay >> By >> Cy >> Dy;

		extend(N, K, Y, Ay, By, Cy, Dy);

		cout << "Case #" << t << ": ";
		cout << capastaty(N, S, X, Y) << "\n";
	}

	return 0;
}

