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

void chain(int K)
{
	vector<pair<int, int>> edge = {{1, 2}};
	int r = 2;
	int cnt = 0;
	int Dr = 1;

	while (cnt < K)
	{
		while (cnt + 2 * Dr <= K)
		{
			edge.push_back({r + Dr, r});
			cnt += 2 * Dr;
			++ Dr;
		}

		r += Dr - 1;
		Dr = 1;
	}

	cout << r << " " << edge.size() << "\n";

	for (auto& [a, b] : edge)
		cout << a << " " << b << "\n";
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int K;
		cin >> K;

		cout << "Case #" << t << ": ";
		chain(K);
	}

	return 0;
}

