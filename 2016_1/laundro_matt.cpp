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

long long laundro(int L, int N, int M, int D, vector<int>& W)
{
	vector<long long> washed;
	priority_queue<
		pair<long long, int>, 
		vector<pair<long long, int>>, 
		greater<>> pq;

	int idx_dryer = 0;
	vector<long long> dryer(min(L, M));

	for (int i = 0; i < N; ++i)
		pq.push({W[i], i});

	while (L --)
	{
		auto [f, i] = pq.top();
		pq.pop();
		pq.push({f + W[i], i});

		washed.push_back(f);

		dryer[idx_dryer] = max(dryer[idx_dryer], f) + D;
		idx_dryer = (idx_dryer + 1) % M;
	}

	return dryer[(idx_dryer - 1 + M) % M];
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int L, N, M, D;
		cin >> L >> N >> M >> D;

		vector<int> W(N);

		for (auto& x : W)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << laundro(L, N, M, D, W) << "\n";
	}

	return 0;
}

