#include <iostream>
#include <map>

using namespace std;

bool isVowel(char c)
{
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int consis1(string str)
{
	map<char, int> hit;
	int cnt_vow = 0;
	int cnt_con = 0;
	int max_vow = 0;
	int max_con = 0;

	for (char c : str)
	{
		++hit[c];

		if (isVowel(c))
			++cnt_vow;
	}

	if (hit.size() == 1)
		return 0;

	cnt_con = str.size() - cnt_vow;

	for (auto it = hit.begin(); it != hit.end(); ++it)
	{
		if (isVowel(it->first))
		{
			max_vow = max(max_vow, it->second);
		}
		else
		{
			max_con = max(max_con, it->second);
		}
	}

	int to_vow = cnt_con + (cnt_vow - max_vow) * 2;
	int to_con = cnt_vow + (cnt_con - max_con) * 2;

	return min(to_vow, to_con);
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		string str = "";

		cin >> str;

		cout << "Case #" << i << ": ";
		cout << consis1(str) << endl;
	}

	return 0;
}