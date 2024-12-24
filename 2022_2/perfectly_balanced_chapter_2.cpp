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

int perfect(vector<int>& A, vector<tuple<int, int, int>>& query)
{
    return 0;
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

        vector<tuple<int, int, int>> query(Q);

        for (auto& [i, x, y] : query)
            cin >> i >> x >> y;

		cout << "Case #" << t << ": ";
		cout << perfect(A, query) << "\n";
	}

	return 0;
}

