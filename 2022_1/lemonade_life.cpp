/*
incorrect
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

struct Point {
	long long x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

long long cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
	size_t n = P.size(), k = 0;
	if (n <= 3) return P;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (size_t i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (size_t i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && cross(H[k-2], H[k-1], P[i-1]) <= 0) k--;
		H[k++] = P[i-1];
	}

	H.resize(k-1);
	return H;
}

long long dst2(Point& p0, Point& p1)
{
    return (p1.x - p0.x) * (p1.x - p0.x)
         + (p1.y - p0.y) * (p1.y - p0.y);
}

void print(vector<vector<int>>& P)
{
    for (auto& p : P)
    {
        for (auto& v : p)
            cout << v << " ";
        cout << "\n";
    }
    cout << "\n";
}

void print(stack<vector<int>> sta)
{
    while (sta.size())
    {
        cout << sta.top()[0] << " " << sta.top()[1] << "\n";
        sta.pop();
    }

    cout << "\n";
}

void print(vector<Point>& P)
{
    for (auto& p : P)
        cout << p.x << " " << p.y << "\n";
    cout << "\n";
}

long long dfs(vector<Point>& convex, long long K, long long D2, int i, vector<long long>& dp)
{
    //cout << "enter " << i << " " << D2 << " ";
    int M = convex.size();

    if (i == M - 1)
        return 0;

    if (dp[i])
        return dp[i];

    long long ret = LLONG_MAX;

    for (int j = i + 1; j < M; ++j)
    {
        
        auto d = dst2(convex[i], convex[j]);

        if (d > D2)
            continue;

        auto r = dfs(convex, K, D2, j, dp);

        //cout << " check " << j << " " << d << " " << r << " ";

        if (r != -1)
            ret = min(ret, r + max(K, d));
    }

    if (ret == LLONG_MAX)
        return dp[i] = -1;

    return dp[i] = ret;
}

int lemonade(vector<Point>& P, int K, int D)
{
    int N = P.size();
    long long D2 = (long long)D * D;
    int end_x = P.back().x;
    auto convex = convex_hull(P);
    int M = convex.size();

    vector<Point> convex1;
    set<int> dup;

    for (int i = 1; i < M; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (cross(convex[0], convex[i], convex[j]) == 0)
            {
                //cout << "same line " << i << " " << j << "\n";
                dup.insert(i);
                dup.insert(j);
            }
        }
    }

    convex1.push_back(convex[0]);

    for (int i = 1; i < M; ++i)
    {
        if (dup.count(i))
            continue;

        convex1.push_back(convex[i]);
    }

    //print(convex);
    

    int M1 = convex1.size();

    if (M1 < 2)
        return -1;
    
    sort(begin(convex1), end(convex1));

    //print(convex1);

    vector<long long> dp(M1);

    return dfs(convex1, K, D2, 0, dp);

}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N, K, D;
        cin >> N >> K >> D;

        vector<Point> P(N);
        int x, y;

        for (int i = 0; i < N; ++i)
        {
            cin >> x >> y;
            P[i].x = x;
            P[i].y = y;
        }

        //P = {{0, 0}, {1, 1}, {2, 2}, {4, 4}, {0, 3}, {1, 2}, {3, 1}, {3, 3}};

		cout << "Case #" << t << ": ";
		cout << lemonade(P, K, D) << "\n";
	}

	return 0;
}

