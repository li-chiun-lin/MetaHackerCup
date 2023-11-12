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

int aaaaaa(int N, int M, vector<string>& G)
{
	vector<vector<int>> tl(N + 1, vector<int>(M + 1));
	vector<vector<int>> br(N + 1, vector<int>(M + 1));

	// the longest queue from top-left corner (0, 0) to (i, j)
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (G[i][j] == '.')
			{
				if ((i == 0 && j == 0) || 
					(tl[i + 1][j] || tl[i][j + 1]))
					tl[i + 1][j + 1] = max(tl[i + 1][j], tl[i][j + 1]) + 1;
				// else, it's not connected to (0, 0)
			}

	// the longest queue from (i, j) to anywhere in the bottom-right part
	for (int i = N - 1; i >= 0; --i)
		for (int j = M - 1; j >= 0; --j)
			if (G[i][j] == '.')
			{
				if (br[i + 1][j] || br[i][j + 1])
					br[i][j] = max(br[i + 1][j], br[i][j + 1]) + 1;
				else
					br[i][j] = 1;	// by default, the spot at (i, j)
			}

	int ans = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (G[i][j] == '.' && tl[i + 1][j + 1])
			{
				// case 0: no upward or leftward
				ans = max(ans, tl[i + 1][j + 1] + br[i][j] - 1);

				// case 1: one upward
				if (j + 1 < M)
				{
					int ii = i;

					while (ii >= 0 && G[ii][j + 1] == '.')
					{
						int r = tl[i + 1][j + 1] + br[ii][j + 2] + (i - ii + 1);
						ans = max(ans, r);
						-- ii;
					}
				}

				// case 2: one leftward
				if (i + 1 < N)
				{
					int jj = j;

					while (jj >= 0 && G[i + 1][jj] == '.')
					{
						int r = tl[i + 1][j + 1] + br[i + 2][jj] + (j - jj + 1);
						ans = max(ans, r);
						-- jj;
					}
				}
			}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		vector<string> G(N);

		for (auto& x : G)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << aaaaaa(N, M, G) << "\n";
	}

	return 0;
}

