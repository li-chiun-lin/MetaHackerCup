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

bool secondhands(int N, int K, vector<int>& S)
{
    if (N > K * 2)
        return false;

    map<int, int> hit;

    for (int s : S)
        if (++ hit[s] > 2)
            return false;

    return true;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N, K;
        cin >> N >> K;

        vector<int> S(N);

        for (int& s : S)
            cin >> s;

		cout << "Case #" << t << ": ";
		cout << (secondhands(N, K, S) ? "YES" : "NO") << endl;
	}

	return 0;
}

