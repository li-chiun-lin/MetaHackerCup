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

void print(vector<string>& board)
{
	cout << "\n";
	for (auto& b : board)
	{
		for (auto& c : b)
			cout << c << " ";
		cout << "\n";
	}
}

void diagonal(vector<string> board, int r, int c, set<pair<int, int>>& threatened)
{
	for (int i = r + 1, j = c + 1; i < 16 && j < 16; ++ i, ++j) if (board[i][j] != '.') { threatened.insert({i, j}); break; }
	for (int i = r + 1, j = c - 1; i < 16 && j >= 0; ++ i, --j) if (board[i][j] != '.') { threatened.insert({i, j}); break; }	
	for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; -- i, --j) if (board[i][j] != '.') { threatened.insert({i, j}); break; }
	for (int i = r - 1, j = c + 1; i >= 0 && j < 16; -- i, ++j) if (board[i][j] != '.') { threatened.insert({i, j}); break; }
}

void cross(vector<string> board, int r, int c, set<pair<int, int>>& threatened)
{
	for (int i = r + 1; i < 16; ++i) if (board[i][c] != '.') { threatened.insert({i, c}); break; }
	for (int i = r - 1; i >= 0; --i) if (board[i][c] != '.') { threatened.insert({i, c}); break; }
	for (int j = c + 1; j < 16; ++j) if (board[r][j] != '.') { threatened.insert({r, j}); break; }
	for (int j = c - 1; j >= 0; --j) if (board[r][j] != '.') { threatened.insert({r, j}); break; }
}

void king(vector<string> board, int r, int c, set<pair<int, int>>& threatened)
{
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
				continue;

			int ii = r + i;
			int jj = c + j;

			if (0 <= ii && ii < 16 && 0 <= jj && jj < 16 && board[ii][jj] != '.')
				threatened.insert({ii, jj});
		}
}

int dr[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dc[] = {2, -2, 2, -2, 1, -1, 1, -1};

void nightrider(vector<string> board, int r, int c, set<pair<int, int>>& threatened)
{
	int cnt = 0;

	for (int k = 0; k < 8; ++k)
	{
		int ii = r + dr[k];
		int jj = c + dc[k];

		while (0 <= ii && ii < 16 && 0 <= jj && jj < 16)
		{
			if (board[ii][jj] != '.')
			{
				threatened.insert({ii, jj});
				break;
			}

			ii += dr[k];
			jj += dc[k];
		}
	}
}

void night(vector<string> board, int r, int c, set<pair<int, int>>& threatened)
{
	int cnt = 0;

	for (int k = 0; k < 8; ++k)
	{
		int ii = r + dr[k];
		int jj = c + dc[k];

		if (0 <= ii && ii < 16 && 0 <= jj && jj < 16 && board[ii][jj] != '.')
			threatened.insert({ii, jj});
	}
}

int kraken(vector<string> board, int r, int c, set<pair<int, int>>& threatened)
{
	int cnt = 0;

	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j)
		{
			if (i == r && j == c)
				continue;

			if (board[i][j] != '.')
				threatened.insert({i, j});
		}
	return cnt;
}

int chess(int P, vector<char>& C, vector<int>& R, vector<int>& F)
{
	vector<string> board(16, string(16, '.'));

	for (int i = 0; i < P; ++i)
		board[R[i] - 1][F[i] - 1] = C[i];

	//print(board);

	set<pair<int, int>> threatened;

	for (int i = 0; i < P; ++i)
	{
		int r = R[i] - 1;
		int c = F[i] - 1;

		switch(C[i])
		{
			case 'K':
				king(board, r, c, threatened);
			break;
			case 'Q':
				diagonal(board, r, c, threatened);
				cross(board, r, c, threatened);
			break;
			case 'R':
				cross(board, r, c, threatened);
			break;
			case 'B':
				diagonal(board, r, c, threatened);
			break;
			case 'N':
				night(board, r, c, threatened);
			break;
			case 'S':
				nightrider(board, r, c, threatened);
			break;
			case 'A':
				diagonal(board, r, c, threatened);
				night(board, r, c, threatened);
			break;
			case 'E':
				kraken(board, r, c, threatened);
			break;
			default:
			break;
		}
	}

	return threatened.size();
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int P;
		cin >> P;

		vector<char> C(P);
		vector<int> R(P), F(P);

		for (int i = 0; i < P; ++i)
			cin >> C[i] >> R[i] >> F[i];

		cout << "Case #" << t << ": ";
		cout << chess(P, C, R, F) << "\n";
	}

	return 0;
}

