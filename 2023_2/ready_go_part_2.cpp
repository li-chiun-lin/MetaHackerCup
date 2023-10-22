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

int ready_go(int R, int C, vector<string>& A)
{
	int d[5] = {0, 1, 0, -1, 0};
	vector<vector<bool>> visited(R, vector<bool>(C));
	vector<vector<int>> count(R, vector<int>(C));

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (A[i][j] == 'W' && ! visited[i][j])
			{
				visited[i][j] = true;
				queue<pair<int, int>> que;
				int cnt_space = 0;
				int cnt_white = 1;

				vector<vector<bool>> visited_space(R, vector<bool>(C));
				int si = 0;
				int sj = 0;
				
				que.push({i, j});

				while (que.size())
				{
					auto [x, y] = que.front();
					que.pop();

					for (int k = 0; k < 4; ++k)
					{
						int xx = x + d[k];
						int yy = y + d[k + 1];

						if (0 <= xx && xx < R && 0 <= yy && yy < C && ! visited[xx][yy] && ! visited_space[xx][yy])
						{
							if (A[xx][yy] == '.')
							{
								++ cnt_space;
								si = xx;
								sj = yy;
								visited_space[xx][yy] = true;
							}
							else if (A[xx][yy] == 'W')
							{
								visited[xx][yy] = true;
								++ cnt_white;
								que.push({xx, yy});
							}
							else
							{

							}
						}
					}
				}

				if (cnt_space == 1)
					count[si][sj] += cnt_white;
			}

	int ans = 0;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (A[i][j] == '.')
				ans = max(ans, count[i][j]);

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C;
		cin >> R >> C;

		vector<string> A(R);

		for (auto& x : A)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << ready_go(R, C, A) << "\n";
	}

	return 0;
}

