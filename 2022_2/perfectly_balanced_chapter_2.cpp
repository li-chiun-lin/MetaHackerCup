/*
to be continued.
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

void print(unordered_map<int, int>& hit)
{
    for (auto& h : hit)
        cout << h.first << " = " << h.second << "\n";
    cout << "\n";
}

bool check(unordered_map<int, int>& hit)
{
    for (auto& h : hit)
        if (h.second)
            return false;

    return true;
}

int perfect(vector<int>& A, vector<vector<int>>& query)
{
    int cnt = 0;

    //cout << "======================================\n";

    for (auto& q : query)
    {
        //cout << "\n\n\n\n";
        //cout << "query " << q[0] << " " << q[1] << " " << q[2] << "\n";

        if (q[0] == 1)
        {
            A[q[1] - 1] = q[2];
            continue;
        }
        
        int start = q[1] - 1;
        int len = q[2] - q[1] + 1;

        //cout << "  " << start << " - " << len << "\n";

        if (len % 2 == 0)
            continue;

        int half = len / 2;
        auto mid = A[start + half];

        //cout << "mid " << mid << "\n";

        unordered_map<int, int> hit;

        for (int i = 0; i < half; ++i)
        {
            ++ hit[A[start + i]];
            -- hit[A[start + len - 1 - i]];
        }

        //cout << "print 1 \n";
        //print(hit);

        int dif = 0;
        int non = 0;
        for (auto it = begin(hit); it != end(hit); ++ it)
        {
            //cout << " " << it->first << " " << dif << "\n";
            if (it->second)
            {
                dif += abs(it->second);
                ++ non;
            }
        }


        //cout << "print 2  size " << hit.size() << "  diff " << dif << "\n";
        //print(hit);

        if (non > 2 || dif > 2)
            continue;

        if (non == 0)
            ++ cnt;
        else if (non == 1)
        {
            if (abs(hit[mid]) == 2)
                ++ cnt;
        }
        else
        {
            if (abs(hit[mid]) == 1)
                ++ cnt;
        }

        //cout << "count " << cnt << "\n";
    }

    return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N;
        cin >> N;

        vector<int> A(N);

        for (int& a : A)
            cin >> a;

        int Q;
        cin >> Q;

        vector<vector<int>> query(Q, vector<int>(3));

        for (auto& q : query)
            cin >> q[0] >> q[1] >> q[2];

		cout << "Case #" << t << ": ";
		cout << perfect(A, query) << "\n";
	}

	return 0;
}

