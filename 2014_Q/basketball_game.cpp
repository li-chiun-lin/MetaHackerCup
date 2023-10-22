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

void print(const vector<string>& v)
{
	for (auto& s : v)
		cout << s << " ";
	cout << "\n";
}

vector<string> basketball_game(int N, int M, int P, vector<tuple<string, int, int>>& S)
{
	vector<string> name(N);
	vector<int> shot_percentage(N);
	vector<int> height(N);
	vector<int> draft_number(N);
	vector<int> id(N);
	
	for (int i = 0; i < N; ++i)
	{
		auto& [n, s, h] = S[i];
		name[i] = n;
		shot_percentage[i] = s;
		height[i] = h;
		id[i] = i;
	}

	sort(begin(id), end(id), 
		[&](int a, int b)
		{
			return shot_percentage[a] == shot_percentage[b] 
				? height[a] > height[b]
				: shot_percentage[a] > shot_percentage[b];
		});

	for (int i = 0; i < N; ++i)
		draft_number[id[i]] = i;

	vector<int> played_time(N);
	vector<vector<int>> playing(2);
	vector<vector<int>> bench(2);

	for (int i = 0; i < N; ++i)
		bench[draft_number[i] % 2].push_back(i);

	for (auto& b : bench)
		sort(begin(b), end(b), [&](int a, int b)
		{
			return draft_number[a] > draft_number[b];
		});

	for (int b = 0; b <= 1; ++b)
	{
		for (int i = 0; i < P; ++i)
		{
			playing[b].push_back(bench[b].back());
			bench[b].pop_back();
		}
	}

#if 0
	for (int b = 0; b <= 1; ++b)
	{
		cout << "\ninitial playing " << b << "\n";
		for (auto i : playing[b])
			cout << setw(10) << name[i] << "\n";

		cout << "\ninitial bench " << b << "\n";
		for (auto i : bench[b])
			cout << setw(10) << name[i] << "\n";
	}
#endif

	auto cmp_played_time = [&](int a, int b)
	{
		return played_time[a] == played_time[b]
			? draft_number[a] < draft_number[b]
			: played_time[a] < played_time[b];
	};

	for (int b = 0; b <= 1; ++b)
	{
		if (bench[b].empty())
			continue;
		
		for (int t = 1; t <= M; ++t)
		{
			for (auto i : playing[b])
				++ played_time[i];

			auto leave = max_element(begin(playing[b]), end(playing[b]), cmp_played_time);
			auto enter = min_element(begin(bench[b]), end(bench[b]), cmp_played_time);

			auto tmp = *leave;
			*leave = *enter;
			*enter = tmp;
		}
	}

	vector<string> ans;

	for (auto& p : playing)
		for (auto i : p)
			ans.push_back(name[i]);
	
	sort(begin(ans), end(ans));
	
	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, P;
		cin >> N >> M >> P;

		vector<tuple<string, int, int>> S(N);

		for (auto& [n, s, h] : S)
			cin >> n >> s >> h;

		cout << "Case #" << t << ": ";
		print(basketball_game(N, M, P, S));
	}

	return 0;
}

