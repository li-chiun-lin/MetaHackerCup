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

bool leapfrog1(string& L)
{
	int N = L.size();
	int cntB = 0;

	for (auto c : L)
		if (c == 'B')
			++ cntB;

	if (cntB == N - 1)
		return false;

	if (cntB * 2 < N - 1)
		return false;

	return true;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string L;
		cin >> L;

		cout << "Case #" << t << ": ";
		cout << (leapfrog1(L) ? "Y" : "N") << "\n";
	}

	return 0;
}

