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

int boomerang(int N, string& A, string& B)
{
	int cnt = 0;
	int l = 0;
	int r = N - 1;

	while (l < r)
	{
		while (l < r && B[l] == B[l + 1])
			++ l;

		while (l < r && B[r - 1] == B[r])
			-- r;

		++ l;
		-- r;
		++ cnt;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		string A, B;
		cin >> N >> A >> B;

		cout << "Case #" << t << ": ";
		cout << boomerang(N, A, B) << "\n";
	}

	return 0;
}

