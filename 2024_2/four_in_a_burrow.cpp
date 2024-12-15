#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>
using namespace std;

const int R = 6, C = 7;
using State = array<char, C>;

int getCMinusF(const vector<vector<char>>& board, const State& state) {
    int count = 0;

	for (int col = 0; col < C; col++) {
        for (int row = 0; row < state[col]; row++) {
            auto cell = board[row][col];
			if (cell == 'C') count++;
            else if (cell == 'F') count--;
        }
    }
	
    return count;
}

// Backward search
void backward(const vector<vector<char>>& board, State state, set<State>& visited) {
    if (visited.count(state)) return;
    visited.insert(state);

    bool removeC = getCMinusF(board, state) == 1;

    for (int col = 0; col < C; col++) {
        if (state[col] == 0) continue;

        char toRemove = board[state[col] - 1][col];
        if ((toRemove == 'C') != removeC) continue;

        state[col]--;
        backward(board, state, visited);
        state[col]++;
    }
}

// Forward search
void forward(const vector<vector<char>>& board, State state, set<State>& visited) {
    if (visited.count(state)) return;
    visited.insert(state);

    bool addC = getCMinusF(board, state) == 0;

    for (int col = 0; col < C; col++) {
        if (state[col] == R) continue;

        char toAdd = board[state[col]][col];
        if ((toAdd == 'C') != addC) continue;

        state[col]++;
        forward(board, state, visited);
        state[col]--;
    }
}

char getWinner(const vector<vector<char>>& board, const State& state) {
    bool Cwin = false, Fwin = false;

    for (int c = 0; c < C; c++) {
        for (int r = 0; r < state[c]; r++) {
            // Vertical Check (Down)
            if (r + 3 < R && r + 1 < state[c] && r + 2 < state[c] && r + 3 < state[c]) {
                char c1 = board[r][c];
                char c2 = board[r + 1][c];
                char c3 = board[r + 2][c];
                char c4 = board[r + 3][c];
                if (c1 == c2 && c2 == c3 && c3 == c4) {
                    Cwin |= (c1 == 'C');
                    Fwin |= (c1 == 'F');
                }
            }

            // Horizontal Check (Right)
            if (c + 3 < C && r < state[c + 1] && r < state[c + 2] && r < state[c + 3]) {
                char c1 = board[r][c];
                char c2 = board[r][c + 1];
                char c3 = board[r][c + 2];
                char c4 = board[r][c + 3];
                if (c1 == c2 && c2 == c3 && c3 == c4) {
                    Cwin |= (c1 == 'C');
                    Fwin |= (c1 == 'F');
                }
            }

            // Diagonal Check (Down-Right)
            if (r + 3 < R && c + 3 < C && r + 1 < state[c + 1] && r + 2 < state[c + 2] && r + 3 < state[c + 3]) {
                char c1 = board[r][c];
                char c2 = board[r + 1][c + 1];
                char c3 = board[r + 2][c + 2];
                char c4 = board[r + 3][c + 3];
                if (c1 == c2 && c2 == c3 && c3 == c4) {
                    Cwin |= (c1 == 'C');
                    Fwin |= (c1 == 'F');
                }
            }

            // Diagonal Check (Down-Left)
            if (r + 3 < R && c - 3 >= 0 && r + 1 < state[c - 1] && r + 2 < state[c - 2] && r + 3 < state[c - 3]) {
                char c1 = board[r][c];
                char c2 = board[r + 1][c - 1];
                char c3 = board[r + 2][c - 2];
                char c4 = board[r + 3][c - 3];
                if (c1 == c2 && c2 == c3 && c3 == c4) {
                    Cwin |= (c1 == 'C');
                    Fwin |= (c1 == 'F');
                }
            }
        }
    }

    if (Cwin && Fwin) return '?';
    if (Cwin) return 'C';
    if (Fwin) return 'F';
    return '0';
}

// Main solving function
char four_in_a_burrow(vector<vector<char>>& board) {
    // Reverse the row order
    reverse(board.begin(), board.end());

    set<State> dp_fwd, dp_rev;
    State initial = {};
    State final = {R, R, R, R, R, R, R};

    backward(board, final, dp_rev);
    forward(board, initial, dp_fwd);

    bool Cwin = false, Fwin = false;
    for (const auto& state : dp_fwd) {
        if (!dp_rev.count(state)) continue;

        char winner = getWinner(board, state);
        Cwin |= (winner == 'C');
        Fwin |= (winner == 'F');
    }

    if (Cwin && Fwin) return '?';
    if (Cwin) return 'C';
    if (Fwin) return 'F';
    return '0';
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<vector<char>> board(R, vector<char>(C));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> board[i][j];

        cout << "Case #" << t << ": " << four_in_a_burrow(board) << "\n";
    }
    return 0;
}
