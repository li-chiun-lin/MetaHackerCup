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

// Finds the bounding box around all '1' cells in the grid G
tuple<int, int, int, int> findBoundingBox(vector<string>& G) {
    int gridSize = G.size();
    int minRow = gridSize, maxRow = -1, minCol = gridSize, maxCol = -1;

    for (int row = 0; row < gridSize; ++row)
        for (int col = 0; col < gridSize; ++col)
            if (G[row][col] == '1') {
                minRow = min(minRow, row);
                maxRow = max(maxRow, row);
                minCol = min(minCol, col);
                maxCol = max(maxCol, col);
            }

    return {minRow, maxRow, minCol, maxCol};
}

// Rotates the grid G 90 degrees clockwise
vector<string> rotateGrid(const vector<string>& G) {
    int gridSize = G.size();
    vector<string> rotated(gridSize, string(gridSize, ' '));

    for (int row = 0; row < gridSize; row++)
        for (int col = 0; col < gridSize; col++)
            rotated[row][col] = G[gridSize - col - 1][row];

    return rotated;
}

// Calculates the area of the bounding box
int calculateArea(int minRow, int maxRow, int minCol, int maxCol) {
    return (maxRow == -1 || maxCol == -1 || minRow > maxRow || minCol > maxCol) 
           ? 0 
           : (maxRow - minRow + 1) * (maxCol - minCol + 1);
}

// Case 1: Finds maximum area when K=1
int calculateMaxAreaCase1(int N, int K, vector<string>& G) {
    auto [minRow, maxRow, minCol, maxCol] = findBoundingBox(G);
    int maxArea = calculateArea(minRow, maxRow, minCol, maxCol);

    for (int row = 0; row < N; ++row)
        for (int col = 0; col < N; ++col)
            if (G[row][col] == '?') {
                int tempMinRow = min(minRow, row);
                int tempMaxRow = max(maxRow, row);
                int tempMinCol = min(minCol, col);
                int tempMaxCol = max(maxCol, col);

                maxArea = max(maxArea, calculateArea(tempMinRow, tempMaxRow, tempMinCol, tempMaxCol));
            }

    return maxArea;
}

// Case 2: Finds maximum area when K=2
int calculateMaxAreaCase2(int N, int K, vector<string>& G) {
    auto [minRow, maxRow, minCol, maxCol] = findBoundingBox(G);
    int maxArea = calculateArea(minRow, maxRow, minCol, maxCol);

    vector<pair<int, int>> topLeftCells, bottomRightCells;
    int rightBound = N;
    int leftBound = -1;

    for (int row = 0; row < N; ++row)
        for (int col = 0; col < rightBound; ++col)
            if (G[row][col] == '?') {
                rightBound = col;
                topLeftCells.push_back({row, col});
            }

    for (int row = N - 1; row >= 0; --row)
        for (int col = N - 1; col > leftBound; --col)
            if (G[row][col] == '?') {
                leftBound = col;
                bottomRightCells.push_back({row, col});
            }

    for (auto [topRow, topCol] : topLeftCells)
        for (auto [botRow, botCol] : bottomRightCells) {
            int tempMinRow = min({minRow, topRow, botRow});
            int tempMaxRow = max({maxRow, topRow, botRow});
            int tempMinCol = min({minCol, topCol, botCol});
            int tempMaxCol = max({maxCol, topCol, botCol});

            maxArea = max(maxArea, calculateArea(tempMinRow, tempMaxRow, tempMinCol, tempMaxCol));
        }

    return maxArea;
}

// Case 3: Finds maximum area when K=3
int calculateMaxAreaCase3(int N, int K, vector<string>& G) {
    auto [minRow, maxRow, minCol, maxCol] = findBoundingBox(G);
    int maxArea = calculateArea(minRow, maxRow, minCol, maxCol);

    vector<pair<int, int>> topLeftCells;
    int rightBound = N;

    for (int row = 0; row < N; ++row)
        for (int col = 0; col < rightBound; ++col)
            if (G[row][col] == '?') {
                rightBound = col;
                topLeftCells.push_back({row, col});
            }

    int maxRight = 0;
    int maxBottom = 0;

    for (int row = 0; row < N; ++row)
        for (int col = 0; col < N; ++col)
            if (G[row][col] == '?') {
                maxRight = max(maxRight, col);
                maxBottom = max(maxBottom, row);
            }

    for (auto [topRow, topCol] : topLeftCells) {
        maxArea = max(maxArea, calculateArea(min(minRow, topRow), max(maxRow, maxBottom), min(minCol, topCol), max(maxCol, maxRight)));
    }

    return maxArea;
}

// Case 4: Finds maximum area when K=4
int calculateMaxAreaCase4(int N, int K, vector<string>& G) {
    int minLeft = N, maxRight = -1, minTop = N, maxBottom = -1;

    for (int row = 0; row < N; ++row)
        for (int col = 0; col < N; ++col)
            if (G[row][col] == '?') {
                minLeft = min(minLeft, col);
                maxRight = max(maxRight, col);
                minTop = min(minTop, row);
                maxBottom = max(maxBottom, row);
            }

    auto [minRow, maxRow, minCol, maxCol] = findBoundingBox(G);
    int tempMinRow = min(minRow, minTop);
    int tempMaxRow = max(maxRow, maxBottom);
    int tempMinCol = min(minCol, minLeft);
    int tempMaxCol = max(maxCol, maxRight);

    return calculateArea(tempMinRow, tempMaxRow, tempMinCol, tempMaxCol);
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;

        vector<string> G(N);
        for (auto& row : G)
            cin >> row;

        int maxArea = 0;

        if (K == 0) {
            auto [minRow, maxRow, minCol, maxCol] = findBoundingBox(G);
            maxArea = calculateArea(minRow, maxRow, minCol, maxCol);
        }
        else if (K == 1) {
            maxArea = calculateMaxAreaCase1(N, K, G);
        }
        else if (K == 2) {
            auto rotatedG = rotateGrid(G);
            maxArea = max(calculateMaxAreaCase2(N, K, G), calculateMaxAreaCase2(N, K, rotatedG));
        }
        else if (K == 3) {
            auto rotatedG = rotateGrid(G);
            maxArea = max(calculateMaxAreaCase3(N, K, G), calculateMaxAreaCase3(N, K, rotatedG));
        }
        else {
            maxArea = calculateMaxAreaCase4(N, K, G);
        }

        cout << "Case #" << t << ": " << maxArea << "\n";
    }

    return 0;
}

