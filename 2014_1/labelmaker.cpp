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

string labelmaker(string& L, unsigned long long N)
{
	string ans = "";
	int n = size(L);

	sort(begin(L), end(L));

	while (N --)
	{
		ans.push_back(L[N % n]);
		N /= n;
	}

	reverse(begin(ans), end(ans));

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string L;
		unsigned long long N;
		cin >> L >> N;

		cout << "Case #" << t << ": ";
		cout << labelmaker(L, N) << "\n";
	}

	return 0;
}

