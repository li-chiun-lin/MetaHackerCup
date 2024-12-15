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

pair<int, int> line_of_delivery(int N, int G, vector<int>& E) {
    // Adjust each element of E by subtracting (N - i - 1) from E[i]
    for (int i = 0; i < N; ++i)
        E[i] -= (N - i - 1);

    // Sort the adjusted vector E
    sort(E.begin(), E.end());

    // Adjust each element by adding its index back
    for (int i = 0; i < N; ++i)
        E[i] += i;

    // Initialize the minimum distance and corresponding value
    pair<int, int> p = {INT_MAX, -1};

    // Find the minimum absolute distance between elements in E and the goal G
    for (auto e : E)
        p = min(p, {abs(e - G), -e});

    // Count how many elements in E are less than the negative of the smallest value found
    int cnt = 0;
    for (auto e : E)
        if (e < -p.second)
            ++cnt;

    // Return the number of required deliveries and the minimum absolute distance
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

