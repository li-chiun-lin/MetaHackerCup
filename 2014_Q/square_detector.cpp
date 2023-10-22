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

bool square_detector(int N, vector<string>& G)
{
	int cnt = 0;

	for (auto& r : G)
		for (auto c : r)
			if (c == '#')
				++ cnt;

	int len = sqrt(cnt);

	if (len * len != cnt)
		return false;

	for (int i = 0; i + len - 1 < N; ++i)
		for (int j = 0; j + len - 1 < N; ++j)
			if (G[i][j] == '#')
			{
				for (int x = 0; x < len; ++x)
					for (int y = 0; y < len; ++y)
						if (G[i + x][j + y] != '#')
							return false;

				return true;
			}

	return false;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<string> G(N);

		for (auto& x : G)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << (square_detector(N, G) ? "YES" : "NO") << "\n";
	}

	return 0;
}

