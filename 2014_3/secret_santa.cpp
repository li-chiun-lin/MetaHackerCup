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
			cout << setw(4) << c;
		cout << "\n";
	}
}

int secret_santa(int K, vector<int>& n)
{
	long long ans = 1;
	int mod = 1e9 + 7;
	

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int K;
		cin >> K;

		vector<int> n(K);

		for (auto& x : n)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << secret_santa(K, n) << "\n";
	}

	return 0;
}

