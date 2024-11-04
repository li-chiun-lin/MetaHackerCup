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

struct trie
{
	struct trie* next[26];
};

long long dfs(string& w, int i, trie* obj)
{
	if (i == size(w))
		return 0;

	long long cnt = 0;

	if (w[i] == '?')
	{
		for (int j = 0; j < 26; ++j)
		{
			if (! obj->next[j])
			{
				obj->next[j] = new trie();
				++ cnt;
			}

			cnt += dfs(w, i + 1, obj->next[j]);
		}
	}
	else
	{
		int j = w[i] - 'A';

		if (! obj->next[j])
		{
			obj->next[j] = new trie();
			++ cnt;
		}

		cnt += dfs(w, i + 1, obj->next[j]);
	}

	return cnt;
}

int count(trie* obj)
{
	if (! obj)
		return 0;

	int cnt = 1;

	for (int j = 0; j < 26; ++j)
		if (obj->next[j])
			cnt += count(obj->next[j]);

	return cnt;
}

long long wildcard(int N, vector<string>& S)
{
	trie* obj = new trie();
	long long cnt = 0;

	for (auto& s : S)
		cnt += dfs(s, 0, obj);

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<string> S(N);

		for (auto& s : S)
			cin >> s;

		cout << "Case #" << t << ": ";
		cout << wildcard(N, S) << "\n";
	}

	return 0;
}

