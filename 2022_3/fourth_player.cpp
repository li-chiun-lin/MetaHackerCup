/*
unfinished
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

# define DEBUG 0

int score(set<int>& A1, set<int>& B1, set<int>& A2, set<int>& B2)
{
    int s = 0;
    int n = A1.size();

    for (int i = 0; i < n; ++i)
    {
        
    }

    return s;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N;
        cin >> N;

        int n = N / 4;
        int x;

        set<int> A1, A2, B1, B2;

        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            A1.insert(x);
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            B1.insert(x);
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            A2.insert(x);
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            B2.insert(x);
        }

		cout << "Case #" << t << ": ";
		cout << score(A1, B1, A2, B2) << "\n";
	}

	return 0;
}

