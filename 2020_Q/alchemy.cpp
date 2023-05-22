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

bool alchemy(int N, string& C)
{
	string sta;

	for (char c : C)
	{
		while (sta.size() >= 2)
		{
			bool b1 = sta[sta.size() - 1] == c;
			bool b2 = sta[sta.size() - 2] == c;

			if (b1 && b2)
				break;
			else if (! b1 && ! b2)
				c = c == 'A' ? 'B' : 'A';
			
			sta.pop_back();
			sta.pop_back();
		}

		sta.push_back(c);
	}

	return sta.size() == 1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		string C;

		cin >> N;
		cin >> C;

		cout << "Case #" << t << ": ";
		cout << (alchemy(N, C) ? "Y" : "N") << "\n";
	}

	return 0;
}

