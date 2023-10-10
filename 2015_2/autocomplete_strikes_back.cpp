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
	bool eow;
	struct trie* next[26];
};

int autocomplete_strikes_back(int N, int K, vector<string>& W)
{
	trie* root = new trie();

	for (auto& w : W)
	{
		trie* obj = root;

		for (auto c : w)
		{
			int i = c - 'a';

			if (! obj->next[i])
				obj->next[i] = new trie();

			obj->cnt += 1;
			obj = obj->next[i];
			
		}

		obj->cnt += 1;
		obj->eow = true;
	}

	int ans = 0;

#if 0
	queue<trie*> que;
	que.push(root);
	int step = 0;

	cout << "\n push root\n";

	while (int s = que.size())
	{
		if (K == 0)
			break;

		while (s --)
		{
			auto u = que.front();
			que.pop();

			cout << "pop  cnt " << u->cnt << " eow " << u->eow << "\n";

			if (u->eow || u->cnt == 1)
			{
				cout << "select += " << step << "\n"; 
				-- K;
				ans += step;
			}
			
			if (u->cnt > 1)
			{
#if 0
				for (auto v : u->next)
					if (v)
						que.push(v);
#else
				for (int v = 0; v < 26; ++v)
					if (u->next[v])
					{
						cout << "push " << (char)('a' + v) << "\n";
						que.push(u->next[v]);
					}
#endif
			}
		}

		++ step;
		cout << "goto step " << step << "\n";
	}
#endif
	

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<string> W(N);

		for (auto& x : W)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << autocomplete_strikes_back(N, K, W) << "\n";
	}

	return 0;
}

