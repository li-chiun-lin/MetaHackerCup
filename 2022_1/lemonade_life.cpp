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

// Define the subtraction operator for pair<int, int>
pair<int, int> operator-(const pair<int, int>& p1, const pair<int, int>& p2) {
    return pair<int, int>(p1.first - p2.first, p1.second - p2.second);  // Subtract corresponding elements
}

// Function to compute cross product (used for sorting points and convex hull)
long long cross(const pair<int, int>& p1, const pair<int, int>& p2) {
    return (long long)p1.first * p2.second - (long long)p1.second * p2.first;
}

// Function to compute squared distance between two points (pair)
long long sqrLen(const pair<int, int>& p1, const pair<int, int>& p2) {
    return (long long)(p1.first - p2.first) * (p1.first - p2.first) + (long long)(p1.second - p2.second) * (p1.second - p2.second);
}

long long lemonade(int N, int K, long long D, vector<pair<int, int>>& P)
{
    D *= D;  // Square D

    auto p0 = *min_element(P.begin(), P.end());  // Find the point with the smallest y-coordinate

    for (auto& p : P) {
        p = p - p0;  // Translate all points so that p0 is at the origin
    }

    sort(begin(P), end(P), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
        long long c = cross(p1, p2);  // Compute cross product
        return c > 0 || (c == 0 && sqrLen(p1, {0, 0}) < sqrLen(p2, {0, 0}));  // Sort by cross product and then by squared distance
    });

    int m = 1;  // Initialize the number of points in the convex hull
    for (int i = 1; i < N; ++i) {
        while (m >= 2 && cross(P[i] - P[m - 1], P[m - 1] - P[m - 2]) >= 0) {
            --m;  // Remove the last point from the convex hull
        }
        P[m++] = P[i];  // Add the current point to the convex hull
    }

    int s = 0;  // Initialize the leftmost point in the convex hull
    int t = 0;  // Initialize the rightmost point in the convex hull

    for (int i = 0; i < m; ++i)
    {
        if (P[i].first < P[s].first)
            s = i;  // Find the leftmost point in the convex hull
        
        if (P[i].first > P[t].first)
            t = i;  // Find the rightmost point in the convex hull
    }

    vector<long long> dist(m, 1e18);  // Initialize the vector of distances
    vector<bool> used(m);  // Initialize the vector of used points
    dist[s] = 0;  // Set the distance of the leftmost point to 0

    for (int it = 0; it < m; ++it)
    {
        int v = -1;

        for (int i = 0; i < m; ++i)
        {
            if (!used[i] && (v == -1 || dist[i] < dist[v]))
                v = i;  // Find the closest unused point
        }

        used[v] = true;  // Mark the point as used

        for (int u = 0; u < m; ++u)
        {
            if (! used[u])
            {
                long long d = sqrLen(P[u], P[v]);  // Compute the squared distance between the points

                if (d > D)
                    continue;  // Skip if the distance is too large

                d = max(d, (long long)K);  // Set the distance to K if it is smaller
                d += dist[v];  // Add the distance to the current point
                dist[u] = min(dist[u], d);  // Update the distance to the point
            }
        }
    }

    return dist[t] == 1e18 ? -1 : dist[t];  // Return the distance to the rightmost point
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N, K, D;
        cin >> N >> K >> D;

        vector<pair<int, int>> P(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> P[i].first >> P[i].second;
        }

		cout << "Case #" << t << ": ";
		cout << lemonade(N, K, D, P) << "\n";
	}

	return 0;
}

