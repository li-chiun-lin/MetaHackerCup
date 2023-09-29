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

int boomerang_crews(int N, int M, int D, vector<int>& A, vector<int>& B)
{
	int win = 0;

	return win;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, D;
		cin >> N >> M >> D;

		vector<int> A(N), B(M);

		for (auto& x : A)
			cin >> x;

		for (auto& x : B)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << boomerang_crews(N, M, D, A, B) << "\n";
	}

	return 0;
}

