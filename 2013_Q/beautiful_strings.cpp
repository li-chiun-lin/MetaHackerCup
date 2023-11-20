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

int beautiful_string(string& s)
{
	int sum = 0;
	vector<int> cnt(26);

	for (char c : s)
		if (isalpha(c))
			++ cnt[tolower(c) - 'a'];

	sort(begin(cnt), end(cnt));

	for (int i = 0; i < 26; ++i)
		sum += cnt[i] * (i + 1);

	return sum;
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
		cout << beautiful_string(s) << "\n";
	}

	return 0;
}

