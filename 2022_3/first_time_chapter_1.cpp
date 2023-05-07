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
#include <unordered_map>
#include <vector>

using namespace std;

void print(vector<set<int>>& ss)
{
    for (auto& s : ss)
    {
        for (auto& x : s)
            cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

void print_color(vector<set<int>>& color)
{
    int i = 0;
    for (auto& c : color)
    {
        cout << i ++ << " : ";
        for (auto& x : c)
            cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

# define DEBUG 0

int first_time(int N, int M, int K, vector<vector<int>>& AB)
{
    int L = (N + K - 1) / K;
    vector<set<int>> ss;
    set<int> s;
    vector<set<int>> color(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        s.insert(i);
        color[i].insert(ss.size());

        if (s.size() == K)
        {
            ss.push_back(s);
            s.clear();
        }
    }

    if (s.size())
        ss.push_back(s);

#if DEBUG
    cout << "init \n";
    print(ss);
    print_color(color);
#endif

    for (int t = 0; t < M; ++t)
    {
        int from = AB[t][0];
        int to = AB[t][1];

        for (int si : color[from])
        {
            ss[si].erase(from);
            ss[si].insert(to);

            if (ss[si].size() > 1)
            {
                color[to].insert(si);
            }
            else
            {
            }
        }

        color[from].clear();

#if DEBUG
        cout << "after t " << t << "\n";
        print(ss);
        print_color(color);
#endif

        bool valid = true;

        for (auto& sx : ss)
            if (sx.size() > 1)
            {
                valid = false;
                break;
            }

        if (valid)
            return t + 1;
    }

    return -1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<int>> AB(M, vector<int>(2));

        for (auto& ab : AB)
            cin >> ab[0] >> ab[1];



		cout << "Case #" << t << ": ";
		cout << first_time(N, M, K, AB) << "\n";
	}

	return 0;
}

