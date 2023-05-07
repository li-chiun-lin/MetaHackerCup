/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void print(vector<string>& G)
{
    for (auto& g : G)
        cout << g << "\n";
}

void print(vector<vector<int>>& v)
{
    cout << "\n";
	for (auto& r : v)
	{
		for (auto& c : r)
            cout << c << " ";
        cout << "\n";
	}
}

void print(int R, int C, vector<vector<char>>& G)
{
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (G[i][j] == '|')
                cout << '^';
            else
                cout << G[i][j];
        }
        cout << "\n";
    }
}

const int d[5] = {0, -1, 0, 1, 0};

int cnt_good(int R, int C, vector<vector<bool>>& bad, int i, int j)
{
    int good = 0;

    for (int k = 0; k < 4; ++k)
    {
        int ii = i + d[k];
        int jj = j + d[k + 1];

        if (0 <= ii && ii < R && 0 <= jj && jj < C && ! bad[ii][jj])
            ++ good;
    }

    return good;
}

void secondfriend_2(int R, int C, vector<string>& G)
{
    int cnt = 0;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (G[i][j] == '^')
                ++ cnt;

    if (R == 1 || C == 1)
    {
        if (cnt)
            cout << "Impossible\n";
        else
        {
            cout << "Possible\n";
            print(G);
        }
    }
    else
    {
        vector<vector<bool>> bad(R, vector<bool>(C));

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (G[i][j] == '#')
                    bad[i][j] = true;


        queue<pair<int, int>> que;

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
            {
                if (G[i][j] != '.')
                    continue;

                if (cnt_good(R, C, bad, i, j) < 2)
                {
                    bad[i][j] = true;
                    que.push({i, j});
                }
            }

        while (que.size())
        {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            for (int k = 0; k < 4; ++k)
            {
                int ii = i + d[k];
                int jj = j + d[k + 1];

                if (0 <= ii && ii < R && 0 <= jj && jj < C && 
                    G[ii][jj] == '.' && !bad[ii][jj] && cnt_good(R, C, bad, ii, jj) < 2)
                {
                    bad[ii][jj] = true;
                    que.push({ii, jj});
                }
            }
        }

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (G[i][j] == '^' && bad[i][j])
                {
                    cout << "Impossible\n";
                    return ;
                }

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (G[i][j] == '.' && ! bad[i][j])
                    G[i][j] = '^';


        cout << "Possible\n";
        print(G);
    }
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int R, C;
        cin >> R >> C;

        vector<string> G(R);
        int cnt = 0;

        for (auto& g : G)
            cin >> g;

		cout << "Case #" << t << ": ";
		secondfriend_2(R, C, G);
	}

	return 0;
}

