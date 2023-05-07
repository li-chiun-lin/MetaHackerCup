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

int risky(int R, int C, vector<string>& tile)
{
	int d[] = {1, 0, -1, 0, 1};
	int ret = 0;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			tile[i][j] -= '0';

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			for (int k = 0; k < 4; ++k)
			{
				int ii = i;
				int jj = j;
				int kinetic_energy = 0;

				while (0 <= ii && ii < R && 0 <= jj && jj < C)
				{
					kinetic_energy += tile[ii][jj];

					int iii = ii + d[k];
					int jjj = jj + d[k + 1];
					int consume_energy = 0;
					int tile_count = 0;

					while (0 <= iii && iii < R && 0 <= jjj && jjj < C && 
						   consume_energy + tile[iii][jjj] <= kinetic_energy)
					{
						consume_energy += tile[iii][jjj];
						++ tile_count;
						iii += d[k];
						jjj += d[k + 1];
					}

					ret = max(ret, tile_count);
					ii += d[k];
					jj += d[k + 1];
				}
			}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C;
		cin >> R >> C;

		vector<string> tile(R);

		for (auto& t : tile)
			cin >> t;

		cout << "Case #" << t << ": ";
		cout << risky(R, C, tile) << "\n";
	}

	return 0;
}

