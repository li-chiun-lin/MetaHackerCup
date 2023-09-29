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

void print(vector<vector<long long>>& v)
{
	for (auto& r : v)
	{
		for (auto c : r)
			cout << c << " ";
		cout << "\n";
	}
	cout << "\n";
}

pair<int, int> winning_at_sports(int A, int B)
{
	int mod = 1e9 + 7;
	vector<vector<long long>> stressfree(A + 1, vector<long long>(B + 1));
	vector<vector<long long>> stressful(A + 1, vector<long long>(B + 1));

	stressfree[1][0] = 1;

	for (int a = 2; a <= A; ++a)
		for (int b = 0; b <= B && b < a; ++b)
			stressfree[a][b] = ((b ? stressfree[a][b - 1] : 0)
							 + (a - 1 > b ? stressfree[a - 1][b] : 0)) % mod;

	for (int a = 0; a <= A; ++a)
	{
		stressful[a][0] = 1;
		stressful[a][1] = 1;
	}

	for (int b = 2; b <= B; ++b)
	{
		for (int a = 0; a <= b; ++a)
			stressful[a][b] = ((a ? stressful[a - 1][b] : 0)
							+ (a <= b - 1 ? stressful[a][b - 1] : 0)) % mod;

		for (int a = b + 1; a <= A; ++a)
			stressful[a][b] = stressful[a - 1][b];
	}

	return {stressfree[A][B], stressful[A][B]};
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string A, B;

		getline(cin, A, '-');
		getline(cin, B);

		auto [a, b] = winning_at_sports(stoi(A), stoi(B));

		cout << "Case #" << t << ": ";
		cout << a << " " << b << "\n";
	}

	return 0;
}

