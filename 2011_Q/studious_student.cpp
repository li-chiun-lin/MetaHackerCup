/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class cmp
{
public:
	bool operator()(string& a, string& b)
	{
		return a + b < b + a;
	}
};

void print(vector<string> &W)
{
	for (auto& w : W)
		cout << w << " ";
	cout << "\n";
}

void print(vector<int>& v)
{
	for (auto& x : v)
		cout << x << " ";
	cout << "\n";
}

string least(vector<string>& S)
{
	int n = S.size();
	vector<int> perm(n);
	iota(begin(perm), end(perm), 0);

	string ret(n + 1, 'z');

	do 
	{
		string str = "";
		
		for (int x : perm)
			str += S[x];

		ret = min(ret, str);

	} while (next_permutation(begin(perm), end(perm)));

	return ret;
}

string student(int M, vector<string>& W)
{
	string ret = "";
	
#if 0
	vector<vector<string>> seg(26);

	for (auto& w : W)
		seg[w[0] - 'a'].push_back(w);

	for (auto& s : seg)
		if (s.size())
			ret += least(s);
#endif

	sort(begin(W), end(W), cmp());

	for (auto& w : W)
		ret += w;

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int M;
		cin >> M;

		vector<string> W(M);

		for (auto& w : W)
			cin >> w;

		cout << "Case #" << t << ": ";
		cout << student(M, W) << "\n";
	}

	return 0;
}

