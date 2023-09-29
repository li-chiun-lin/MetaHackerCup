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

bool check(int R, int C, int A, int B)
{
	return R > C;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C, A, B;
		cin >> R >> C >> A >> B;

		cout << "Case #" << t << ": ";
		cout << (check(R, C, A, B) ? "YES" : "NO") << "\n";
	}

	return 0;
}

