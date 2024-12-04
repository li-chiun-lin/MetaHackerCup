/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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

const int TRIALS = 2000;  // Number of random trials for line fitting

/**
 * @brief Finds the minimum number of points to remove to make all remaining points collinear.
 * 
 * @param N The number of points.
 * @param P A vector of pairs representing the (x, y) coordinates of the points.
 * @return The minimum number of points to remove to make the remaining points collinear.
 */
int fall_in_line(int N, vector<pair<int, int>>& P) {
    int best = 0;  // Track the largest number of points on a single line

    // Perform multiple random trials to check lines between pairs of points
    for (int t = 0; t < TRIALS; ++t) {
        int r1 = rand() % N;  // Random index for the first point
        int r2 = rand() % N;  // Random index for the second point

        // Ensure that we pick two distinct points
        if (r1 == r2) {
            --t;  // Retry this trial
            continue;
        }

        // Destructure the selected points
        auto [p1x, p1y] = P[r1];
        auto [p2x, p2y] = P[r2];

        // Determine if the line between the two points is vertical
        bool vertical = (p1x == p2x);
        long long rise = 0, run = 0, bNum = 0;  // Variables to define the line equation

        // If not vertical, calculate the rise, run, and intercept
        if (!vertical) {
            rise = p2y - p1y;
            run = p2x - p1x;
            bNum = run * p1y - rise * p1x;  // Calculate bNum = (run * y1 - rise * x1)
        }

        int onLine = 0;  // Counter for points on the current line

        // Check how many points lie on this line
        for (const auto& [px, py] : P) {
            if (vertical) {
                if (px == p1x) ++onLine;  // For vertical lines, check x-coordinate equality
            } else {
                long long expectedRunUnits = rise * px + bNum;
                if (expectedRunUnits % run == 0 && expectedRunUnits / run == py) {
                    ++onLine;  // For non-vertical lines, check if (rise * px + bNum) / run == py
                }
            }
        }

        // Update the best line if the current line has more points
        best = max(best, onLine);
    }

    // Return the minimum number of points to remove to make the remaining points collinear
    return N - best;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<pair<int, int>> P(N);

		for (auto& [x, y] : P)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		cout << fall_in_line(N, P) << "\n";
	}

	return 0;
}

