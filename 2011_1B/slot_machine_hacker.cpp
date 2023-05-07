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

long long secret;

int getRandomNumber() {
	secret = (secret * 5402147 + 54321) % 10000001;
	return secret % 1000;
}

void slot(int N, vector<int>& observation)
{
	set<int> candidate;

	for (int i = 0; i < 10000001; ++i)
	{
		bool valid = true;
		secret = i;

		for (int j = 0; j < N && valid; ++j)
			if (getRandomNumber() != observation[j])
				valid = false;

		if (valid)
			candidate.insert(secret);
	}

	if (candidate.size() == 0)
		cout << "Wrong machine\n";
	else if (candidate.size() > 1)
		cout << "Not enough observations\n";
	else
	{
		secret = *begin(candidate);

		for (int i = 0; i < 10; ++i)
			cout << getRandomNumber() << " ";
		cout << "\n";
	}
}


int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> observation(N);

		for (auto& o : observation)
			cin >> o;

		cout << "Case #" << t << ": ";
		slot(N, observation);
	}

	return 0;
}

