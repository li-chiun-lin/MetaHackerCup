/*
incorrect
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
	bool eow;
	int idx;

	struct trie* next[26];
};

int text_editor(int N, int K, vector<string>& W)
{
	trie* root = new trie();

	for (int i = 0; i < size(W); ++i)
	{
		trie* ptr = root;

		for (char c : W[i])
		{
			int idx = c - 'a';

			if (! ptr->next[idx])
				ptr->next[idx] = new trie();

			ptr = ptr->next[idx];
		}

		ptr->eow = true;
		ptr->idx = i;
	}

	vector<string> select;
	queue<trie*> que;

	que.push(root);

	while(select.size() < K)
	{
		auto u = que.front();
		que.pop();

		for (auto v : u->next)
		{
			if (! v)
				continue;

			if (v->eow)
				select.push_back(W[v->idx]);

			que.push(v);
		}
	}

	if (K == 1)
		return select[0].size() * 2 + 1;

	while (select.size() > K)
		select.pop_back();

	sort(begin(select), end(select));

	cout << "\n";
	for (auto& s : select)
		cout << s << "\n";

	int cnt = select[0].size() + 1;

	cout << "count before loop " << cnt << "\n";

	for (int i = 1; i < K; ++i)
	{
		int j = 0;

		while (j < select[i - 1].size() && j < select[i].size() && select[i - 1][j] == select[i][j])
			++ j;

		cnt += 1 + select[i - 1].size() + select[i].size() - 2 * j;

		cout << i << " : " << "cnt " << cnt << "\n";
	}

	return cnt + select.back().size();
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
		cout << text_editor(N, K, W) << "\n";
	}

	return 0;
}

