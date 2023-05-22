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

void print(vector<vector<bool>> P)
{
	for (auto& r : P)
	{
		for (auto c : r)
			cout << (c ? "Y" : "N");
		cout << "\n";
	}
}

vector<vector<bool>> travel(int N, string& I, string& O)
{
	vector<vector<bool>> P(N, vector<bool>(N));

	for (int i = 0; i < N; ++i)
		P[i][i] = true;

	// from i -> j
	for (int j = 1; j < N; ++j)
		for (int i = 0; i < j; ++i)
			P[i][j] = P[i][j - 1] && O[j - 1] == 'Y' && I[j] == 'Y';

	// from j <- i
	for (int j = N - 2; 0 <= j; --j)
		for (int i = N - 1; j < i; --i)
			P[i][j] = P[i][j + 1] && O[j + 1] == 'Y' && I[j] == 'Y';


	return P;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		string I, O;

		cin >> N;
		cin >> I;
		cin >> O;

		cout << "Case #" << t << ":\n";
		print(travel(N, I, O));
		
	}

	return 0;
}

