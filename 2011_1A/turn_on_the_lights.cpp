/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int light(int R, int C, vector<string>& button)
{
	int ret = INT_MAX;
	int limit = 1 << C;
	//vector<vector<bool>> press(R + 2, vector<bool>(C + 2));
	

	for (int combination = 0; combination < limit; ++ combination)
	{
		int press[20][20] = {0};

		for (int j = 0; j < C; ++j)
			if (combination & (1 << j))
				press[1][j + 1] = 1;

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
			{
				bool s = 
					press[i][j + 1] ^
					press[i + 1][j] ^
					press[i + 1][j + 1] ^
					press[i + 1][j + 2];

				if ((button[i][j] == 'X' && s) ||
					(button[i][j] != 'X' && ! s))
					press[i + 2][j + 1] = 1;
				else
					press[i + 2][j + 1] = 0;
			}

		bool valid = true;
		for (int j = 0; j < C && valid; ++j)
			if (press[R + 1][j + 1])
				valid = false;

		if (valid)
		{
			int cnt = 0;

			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
					cnt += press[i + 1][j + 1];

			ret = min(ret, cnt);
		}
	}

	return ret == INT_MAX ? -1 : ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C;
		cin >> R >> C;

		vector<string> button(R);

		for (auto& b : button)
			cin >> b;

		cout << "Case #" << t << ": ";
		cout << light(R, C, button) << "\n";
	}

	return 0;
}

