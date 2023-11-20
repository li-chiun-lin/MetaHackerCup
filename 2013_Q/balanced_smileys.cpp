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

bool dfs(string& s, int i, int cnt)
{
	if (cnt < 0)
		return false;

	if (i == size(s))
		return cnt == 0;

	if (s[i] == '(')
	{
		if (i && s[i - 1] == ':' && dfs(s, i + 1, cnt))
			return true;

		if (dfs(s, i + 1, cnt + 1))
			return true;
	}
	else if (s[i] == ')')
	{
		if (i && s[i - 1] == ':' && dfs(s, i + 1, cnt))
			return true;

		if (dfs(s, i + 1, cnt - 1))
			return true;
	}
	else
	{
		if (dfs(s, i + 1, cnt))
			return true;
	}

	return false;
}

bool balanced_smileys(string& s)
{
	return dfs(s, 0, 0);
}

int main()
{
	int T;
	cin >> T;

	string s;
	getline(cin, s);

	for (int t = 1; t <= T; ++t)
	{
		getline(cin, s);

		cout << "Case #" << t << ": ";
		cout << (balanced_smileys(s) ? "YES" : "NO") << "\n";
	}

	return 0;
}

