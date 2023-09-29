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

int coding_contest_creation(int N, vector<int>& D)
{
	int insert = 0;
	int cnt = 0;
	int i = 0;
	int pre = -1;

	//cout << "\n";

	while (i < N)
	{
		if (cnt == 0)
		{
			++ cnt;
			pre = D[i ++];
		}
		else if (cnt == 4 || pre >= D[i])
		{
			insert += 4 - cnt;
			cnt = 0;
		}
		else if (D[i] - pre <= 10)
		{
			++ cnt;
			pre = D[i ++];
		}
		else
		{
			++ cnt;
			++ insert;
			pre += 10;
		}
	}

	return insert + (4 - cnt);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> D(N);

		for (auto& x : D)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << coding_contest_creation(N, D) << "\n";
	}

	return 0;
}

