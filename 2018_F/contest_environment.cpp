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

bool contest(vector<string>& D)
{
	int N = D[0].size();
	
	return true;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		vector<string> D(2);

		cin >> D[0] >> D[1];

		cout << "Case #" << t << ": ";
		cout << (contest(D) ? "Possible" : "Impossible") << "\n";
	}

	return 0;
}

