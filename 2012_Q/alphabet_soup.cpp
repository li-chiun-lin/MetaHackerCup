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
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int soup(string& S)
{
	map<char, int> hit;

	for (char c : S)
		++ hit[c];

	int ret = INT_MAX;

	string h = "HAKERUP";
	
	for (char c : h)
		ret = min(ret, hit[c]);

	ret = min(ret, hit['C'] / 2);

	return ret;
}

int main()
{
	int T;
	cin >> T;

	string dummy;
	getline(cin, dummy);

	for (int t = 1; t <= T; ++t)
	{
		string S;

		getline(cin, S);

		cout << "Case #" << t << ": ";
		cout << soup(S) << "\n";
	}

	return 0;
}

