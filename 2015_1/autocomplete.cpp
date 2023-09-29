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
	int cnt;
	struct trie* next[26];
};

int autocomplete(int N, vector<string>& W)
{
	int ans = 0;
	trie *root = new trie();

	for (auto& w : W)
	{
		trie *obj = root;

		for (auto c : w)
		{
			int idx = c - 'a';

			if (! obj->next[idx])
				obj->next[idx] = new trie();

			obj = obj->next[idx];
			++ obj->cnt;
		}

		obj = root;

		for (auto c : w)
		{
			obj = obj->next[c - 'a'];
			++ ans;

			if (obj->cnt == 1)
				break;
		}
	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<string> W(N);

		for (auto& x : W)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << autocomplete(N, W) << "\n";
	}

	return 0;
}

