/*
incomplete
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

bool check(int L, vector<tuple<int, int, int>>& meeting)
{
	int end = 0;

	for (auto [s, e, i] : meeting)
	{
		if (end + L <= s)
			return true;

		end = max(end, e);
	}

	return false;
}

void dfs(int L, vector<tuple<int, int, int>>& meeting, int i, int end, vector<int>& cnt, int& ans)
{
	int n = size(meeting);

	while (i < n)
	{
		auto [s, e, _] = meeting[i];

		if (e <= end)
		{
			++ i;
		}
		else
		{
			break;
		}
	}

	if (i == n)
	{
		ans = min(ans, max(cnt[0], cnt[1]));
		return ;
	}

	auto [s, e, id] = meeting[i];

	if (end + L <= s)
	{
		return ;
	}


	// take
	++ cnt[id];
	dfs(L, meeting, i + 1, max(end, e), cnt, ans);
	-- cnt[id];
	
	// dont
	dfs(L, meeting, i + 1, end, cnt, ans);
}


int lunch(int J, int W, int L, vector<pair<int, int>>& AB, vector<pair<int, int>>& CD)
{
	
	int ub = 8e7;
	vector<tuple<int, int, int>> meeting;

	for (auto [s, e] : AB)
		meeting.push_back({s, e, 0});

	for (auto [s, e] : CD)
		meeting.push_back({s, e, 1});

	sort(begin(meeting), end(meeting));
	meeting.push_back({ub, ub, 0});

	if (check(L, meeting))
		return -1;

	vector<int> cnt(2);
	int ans = J + W;

	dfs(L, meeting, 0, 0, cnt, ans);


	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int J, W, L;
		cin >> J >> W >> L;

		vector<pair<int, int>> AB(J), CD(W);

		for (auto& [a, b] : AB)
			cin >> a >> b;

		for (auto& [c, d] : CD)
			cin >> c >> d;

		cout << "Case #" << t << ": ";
		auto r = lunch(J, W, L, AB, CD);

		if (r != -1)
			cout << r << "\n";
		else
			cout << "Lunchtime" << "\n";
	}

	return 0;
}

