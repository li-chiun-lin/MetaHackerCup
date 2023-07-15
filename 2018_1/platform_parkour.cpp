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

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

void print(vector<vector<int>>& v)
{
	for (auto& r : v)
		cout << r[0] << " <> " << r[1] << " ^" << r[2] << " v" << r[3] << "\n";
	cout << "\n";
}

int platform(int N, int M, vector<int>& H, vector<vector<int>>& P)
{
	cout << "\n";
	print(H);
	print(P);

	return 0;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		long long W, X, Y, Z;
		vector<int> H(N);
		vector<vector<int>> P(M, vector<int>(4));

		cin >> H[0] >> H[1] >> W >> X >> Y >> Z;

		for (int i = 2; i < N; ++i)
			H[i] = (W * H[i - 2] + X * H[i - 1] + Y) % Z;

		for (auto& p : P)
			cin >> p[0] >> p[1] >> p[2] >> p[3];

		cout << "Case #" << t << ": ";
		cout << platform(N, M, H, P) << "\n";
	}

	return 0;
}

