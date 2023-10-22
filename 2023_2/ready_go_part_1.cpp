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

bool ready_go(int R, int C, vector<string>& A)
{
	int d[5] = {0, 1, 0, -1, 0};
	vector<vector<bool>> visited(R, vector<bool>(C));

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (A[i][j] == 'W' && ! visited[i][j])
			{
				visited[i][j] = true;
				queue<pair<int, int>> que;
				int cnt_space = 0;

				vector<vector<bool>> visited_space(R, vector<bool>(C));
				
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
								visited_space[xx][yy] = true;
							}
							else if (A[xx][yy] == 'W')
							{
								visited[xx][yy] = true;
								que.push({xx, yy});
							}
							else
							{

							}
						}
					}
				}

				if (cnt_space == 1)
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
		int R, C;
		cin >> R >> C;

		vector<string> A(R);

		for (auto& x : A)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << (ready_go(R, C, A) ? "YES" : "NO") << "\n";
	}

	return 0;
}

