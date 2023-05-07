/*
LTE
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

bool check(vector<int>& p1, vector<int>& p2)
{
    int dif = 0;
    bool valid = true;

    for (int i = 0; i < 26 && valid && dif < 2; ++i)
    {
        if (p1[i] == p2[i])
            ;
        else if (p1[i] < p2[i])
            valid = false;
        else
            dif += p1[i] - p2[i];
    }

    return valid && dif == 1;
}

int perfect(string& S, vector<vector<int>>& query)
{
    int cnt = 0;

    for (char& c : S)
        c -= 'a';

    for (auto& lr : query)
    {
        int start = lr[0] - 1;
        int len = lr[1] - lr[0] + 1;

        if (len % 2 == 0)
            continue;

        //string sub = S.substr(lr[0] - 1, len);
        //cout << sub << "\n";

        int half = len / 2;
        auto mid = S[start + half];
        //cout << mid << "\n";

        vector<int> left(26), right(26);

        for (int i = 0; i < half; ++i)
        {
            ++ left[S[start + i]];
            ++ right[S[start + len - 1 - i]];
        }

        // case 1: delete at middle

        if (left == right)
        {
            ++ cnt;
            continue;
        }

        // case 2: delete at left part
        ++ left[mid];

        if (check(left, right))
        {
            ++ cnt;
            continue;
        }

        -- left[mid];

        // case 3: delete at right part

        ++ right[mid];

        if (check(right, left))
        {
            ++ cnt;
            continue;
        }

        -- right[mid];
    }

    return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        string S;
        cin >> S;

        int Q;
        cin >> Q;

        vector<vector<int>> query(Q, vector<int>(2));

        for (int i = 0; i < Q; ++i)
            cin >> query[i][0] >> query[i][1];

		cout << "Case #" << t << ": ";
		cout << perfect(S, query) << "\n";
	}

	return 0;
}

