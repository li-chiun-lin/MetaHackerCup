/*
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void print(vector<long long>& v)
{
	for (long long x : v)
		cout << x << " ";
	cout << "\n";
}

void secondflight_2(int N, vector<vector<int>>& R, vector<vector<int>>& D)
{
    int M = R.size();
    int Q = D.size();

    unordered_map<int, unordered_map<int, int>> cap;
    unordered_map<int, unordered_set<int>> adj;
    unordered_map<int, int> deg;

    for (auto& r : R)
    {
        cap[r[0]][r[1]] = r[2];
        cap[r[1]][r[0]] = r[2];

        adj[r[0]].insert(r[1]);
        adj[r[1]].insert(r[0]);

        ++ deg[r[0]];
        ++ deg[r[1]];
    }

    vector<long long> ret;
    unordered_map<int, unordered_map<int, long long>> cache;

    for (auto& d : D)
    {
        if (deg[d[0]] > deg[d[1]])
            swap(d[0], d[1]);

        if (cache[d[0]].find(d[1]) != end(cache[d[0]]))
        {
            ret.push_back(cache[d[0]][d[1]]);
            continue;
        }
        
        long long F = 0;

        if (adj[d[0]].count(d[1]))
            F += cap[d[0]][d[1]] * 2;

        for (int x : adj[d[0]])
        {
            if (adj[x].count(d[1]))
                F += min(cap[d[0]][x], cap[x][d[1]]);
        }

        cache[d[0]][d[1]] = F;
        ret.push_back(F);
    }

    print(ret);
}


int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N, M, Q;
        cin >> N >> M >> Q;

        vector<vector<int>> R(M, vector<int>(3));

        for (auto& r : R)
            cin >> r[0] >> r[1] >> r[2];

        vector<vector<int>> D(Q, vector<int>(2));

        for (auto& d : D)
            cin >> d[0] >> d[1];

		cout << "Case #" << t << ": ";
		secondflight_2(N, R, D);
	}

	return 0;
}

