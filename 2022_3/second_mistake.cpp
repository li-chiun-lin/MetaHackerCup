/*
TLE
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

#if 0
long long secondmistake(vector<string>& V, vector<string>& W)
{
    long long ret = 0;
    char alph[4] = {'m', 'e', 't', 'a'};
    map<char, int> idx = {{'m', 0}, {'e', 1}, {'t', 2}, {'a', 3}};
    set<string> hit;

    sort(begin(V), end(V));

    for (auto& w : W)
    {
        int L = w.size();

        //cout << w << "  -- \n";

        for (int i = 0; i < L; ++i)
            for (int j = i + 1; j < L; ++j)
            {
                int idxi = idx[w[i]];
                for (int ii = 0; ii < 3; ++ii)
                {
                    w[i] = alph[(++ idxi) % 4];

                    int idxj = idx[w[j]];
                    for (int jj = 0; jj < 3; ++jj)
                    {
                        w[j] = alph[(++ idxj) % 4];

                        if (hit.find(w) == end(hit))
                        {
                            auto it = lower_bound(begin(V), end(V), w);
                            
                            if (*it == w)
                            {
                                ++ ret;
                                hit.insert(w);
                            }
                        }
                        else
                            ++ ret;
                    }

                    w[j] = alph[++ idxj % 4];
                }

                w[i] = alph[++ idxi % 4];
            }

        //cout << "\n";
    }

    return ret;
}
#endif

long long secondmistake(vector<string>& V, vector<string>& W)
{
    long long ret = 0;
    char alph[4] = {'m', 'e', 't', 'a'};
    map<char, int> idx = {{'m', 0}, {'e', 1}, {'t', 2}, {'a', 3}};
    set<string> hit;

    sort(begin(V), end(V));

    for (auto& w : W)
    {
        for (auto& v : V)
        {
            int dif = 0;

            for (int i = 0; i < w.size() && dif < 3; ++i)
                if (w[i] != v[i])
                    ++ dif;

            if (dif == 2)
                ++ ret;
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
        int N;
        cin >> N;

        vector<string> V(N);

        for (auto& v : V)
            cin >> v;

        int Q;
        cin >> Q;

        vector<string> W(Q);

        for (auto& w : W)
            cin >> w;

		cout << "Case #" << t << ": ";
		cout << secondmistake(V, W) << "\n";
	}

	return 0;
}

