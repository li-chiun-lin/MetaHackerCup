#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>

using namespace std;

int weak_typing_1(string w)
{
	char cur = 0;
	int sw = 0;

	for (char c : w)
	{
		if (c == 'F')
			continue;

		if (cur == 0)
		{
			cur = c;
		}
		else if (cur != c)
		{
			++sw;
			cur = c;
		}
	}

	return sw;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int N;
		string W;

		cin >> N >> W;

		cout << "Case #" << i << ": ";
		cout << weak_typing_1(W) << endl;
	}

	return 0;
}