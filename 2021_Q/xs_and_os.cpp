#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> xo(vector<string> grid)
{
	map<int, set<set<pair<int, int>>>> hit;

	int n = (int)grid.size();

	// each row
	for (int i = 0; i < n; ++i)
	{
		int c = 0;
		set<pair<int, int>> s;
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == 'X')
				;
			else if (grid[i][j] == 'O')
			{
				c = 0;
				break;
			}
			else
			{
				++c;
				s.insert({ i, j });
			}
		}

		if (c)
			hit[c].insert(s);
	}

	// each col
	for (int j = 0; j < n; ++j)
	{
		int c = 0;
		set<pair<int, int>> s;

		for (int i = 0; i < n; ++i)
		{
			if (grid[i][j] == 'X')
				;
			else if (grid[i][j] == 'O')
			{
				c = 0;
				break;
			}
			else
			{
				++c;
				s.insert({ i, j });
			}
		}

		if (c)
			hit[c].insert(s);
	}

	if (hit.size() == 0)
		return { 0, 0 };

	auto it = hit.begin();

	return { it->first, (int)it->second.size() };




}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int N;
		cin >> N;

		vector<string> vec(N);

		for (int j = 0; j < N; ++j)
			cin >> vec[j];

		auto r = xo(vec);

		cout << "Case #" << i << ": ";

		if (r[0] == 0)
			cout << "Impossible" << endl;
		else
			cout << r[0] << " " << r[1] << endl;
	}

	return 0;
}