/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

pair<int, int> line_of_delivery(int N, int G, vector<int>& E)
{
	vector<int> S(N);

    // Modify the elements in E and copy them to S
    for (int i = 0; i < N; ++i) {
        E[i] -= (N - i - 1);  // Adjust E[i] based on the index
        S[i] = E[i];  // Copy the modified E[i] into S
    }

    // Sort the array S
    sort(S.begin(), S.end());

    // Adjust elements in S by adding the index
    for (int i = 0; i < N; ++i) {
        S[i] += i;
    }

    // Initialize the pair to store the minimum distance and corresponding value
    pair<int, int> p = {INT_MAX, -1};

    // Find the minimum distance between elements in S and G
    for (auto s : S) {
        p = min(p, {abs(s - G), -s});
    }

    // Count how many elements in S are less than -p.second
    int cnt = 0;
    for (auto s : S) {
        if (s < -p.second) {
            ++cnt;
        }
    }

    // Return the result: (N - cnt, minimum absolute distance to G)
    return {N - cnt, p.first};
}


int main()
{
	int T;
	cin >> T;

	srand(time(0));

	for (int t = 1; t <= T; ++t)
	{
		int N, G;
        cin >> N >> G;

        vector<int> E(N);

		for (auto& e : E)
			cin >> e;

		//srand(0);	

		auto [a, b] = line_of_delivery(N, G, E);

		cout << "Case #" << t << ": ";
		cout << a << " " << b << "\n";
	}

	return 0;
}

