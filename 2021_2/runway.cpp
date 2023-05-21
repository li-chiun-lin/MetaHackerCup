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

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

void print(vector<pair<int, int>>& m)
{
#if 0
	vector<int> style(m.size());

	for (auto& [k, v] : m)
		style[v] = k;

	for (auto s : style)
		cout << s << " ";
#else
	for (auto& [k, v] : m)
		cout << k << " ";
#endif
	
	cout << "\n";
}

# define D 0

int runway(int N, int M, vector<int>& S, vector<vector<int>>& P)
{
	vector<int> change(M);

	vector<pair<int, int>> order(M);

	for (int i = 0; i < M; ++i)
		order[i] = {S[i], i};

#if D
	cout << "debug\n";
#endif

	for (auto& round : P)
	{
		int i = 0;
		int j = 0;

		sort(begin(order), end(order), 
			[&] (auto& a, auto& b)
			{
				if (a.first == b.first)
					return change[a.second] > change[b.second];
				
				return a.first < b.first;
			});

		sort(begin(round), end(round));
		vector<int> need_change;
		vector<int> missing_style;

#if D
		cout << "new round\n";
		cout << "order\t";
		print(order);
		cout << "round\t";
		print(round);
#endif
		
		while (i < M && j < M)
		{
			if (order[i].first < round[j])
			{
#if D
				cout << "need_change " << i << "\n";
#endif
				need_change.push_back(i ++);
			}
			else if (order[i].first > round[j])
			{
#if D
				cout << "missing style " << round[j] << "\n";
#endif
				missing_style.push_back(j ++);
			}
			else
			{
				++ i;
				++ j;
			}
		}

		while (i < M)
		{
#if D
			cout << "need_change " << i << "\n";
#endif
			need_change.push_back(i ++);
		}

		while (j < M)
		{
#if D
			cout << "missing style " << round[j] << "\n";
#endif
			missing_style.push_back(j ++);
		}

		if (need_change.size() != missing_style.size())
		{
			cout << "error: size mis-match\n";
			return -1;
		}

		for (int i = 0; i < need_change.size(); ++i)
		{
#if D
			cout << "change modele " << need_change[i] << " : " << order[need_change[i]].first << " -> " << round[missing_style[i]] << "\n";
#endif
			++ change[order[need_change[i]].second];
			order[need_change[i]].first = round[missing_style[i]];
		}
	}

	int cnt = 0;

	for (int i = 0; i < M; ++i)
		cnt += max(change[i] - 1, 0);

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		vector<int> S(M);
		vector<vector<int>> P(N, vector<int>(M));

		for (auto& s : S)
			cin >> s;

		for (auto& r : P)
			for (auto& c : r)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << runway(N, M, S, P) << "\n";
	}

	return 0;
}

