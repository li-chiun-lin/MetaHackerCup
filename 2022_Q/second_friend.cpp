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

void print(int R, int C, char c = '^')
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            cout << c;
        cout << "\n";
    }
}

void print(vector<string>& G)
{
    for (auto& g : G)
        cout << g << "\n";
}

const int d[5] = {0, -1, 0, 1, 0};

bool dfs(int R, int C, vector<string>& G, int ui, int uj)
{
    int f = 0;

    for (int k = 0; k < 4 && f < 2; ++k)
    {
        int vi = ui + d[k];
        int vj = uj + d[k + 1];

        if (0 <= vi && vi < R && 0 <= vj && vj < C && G[vi][vj] != '.')
            ++ f;
    }

    if (f >= 2)
        return true;

    vector<pair<int, int>> new_tree;

    for (int k = 0; k < 4 && f < 2; ++k)
    {
        int vi = ui + d[k];
        int vj = uj + d[k + 1];

        if (0 <= vi && vi < R && 0 <= vj && vj < C && G[vi][vj] == '.')
        {
            G[vi][vj] = '|';
            new_tree.push_back({vi, vj});
            
            if (dfs(R, C, G, vi, vj))
                ++ f;
        }
    }

    if (f >= 2)
        return true;

    for (auto& v : new_tree)
        G[v.first][v.second] = '.';

    return false;
}

void secondfriend(int R, int C, vector<string>& G)
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (G[i][j] != '^')
                continue;

            if (! dfs(R, C, G, i, j))
            {
                cout << "Impossible\n";
                return ;
            }
        }

    cout << "Possible\n";

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (G[i][j] == '|')
                G[i][j] = '^';

    print(G);
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
        {
            cout << "Impossible\n";
            return ;
        }
        else
        {
            cout << "Possible\n";
        }
    }
    else
    {
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (G[i][j] == '.')
                    G[i][j] = '^';

        cout << "Possible\n";
        
    }

    print(G);
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

