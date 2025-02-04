#define _USE_MATH_DEFINES

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
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

// Fenwick Tree implementation for range sum queries and point updates
class FenwickTree {
  int size;                     // Size of the array
  vector<long long> data;    // Data storage for Fenwick Tree

  // Computes prefix sum from index 0 to r-1
  long long prefixSum(int r) const {
    long long s = 0;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;  // Move to the previous segment
    }
    return s;
  }

public:
  FenwickTree() : size(0) {}
  explicit FenwickTree(int size) : size(size), data(size) {}

  // Adds value to the element at index
  void add(int index, int value) {
    for (++index; index <= size; index += index & -index) {
      data[index - 1] += static_cast<long long>(value);
    }
  }

  // Computes range sum from left to right-1
  int rangeSum(int left, int right) const {
    return prefixSum(right) - prefixSum(left);
  }
};

// Counts non-overlapping subarrays with maximum value of at least d
long long count(int R, int C, vector<vector<pair<int, int>>>& positions, int d) {
  long long totalCount = 0;
  FenwickTree fenwick(C);  // Initialize Fenwick Tree for range sum queries

  for (int value = 0; value < R * C; ++value) {
    size_t leftCover = 0, rightCover = 0;

    // Process each position where the value exists
    for (const auto& [x, y] : positions[value]) {
      int minX = max(0, x - (d - 1));
      int maxX = min(R - 1, x + (d - 1));
      int minY = max(0, y - (d - 1));
      int maxY = min(C - 1, y + (d - 1));

      // Add points within valid X range to Fenwick Tree
      while (rightCover < positions[value].size() && positions[value][rightCover].first <= maxX) {
        fenwick.add(positions[value][rightCover].second, 1);
        ++rightCover;
      }

      // Remove points outside the valid X range from Fenwick Tree
      while (leftCover < positions[value].size() && positions[value][leftCover].first < minX) {
        fenwick.add(positions[value][leftCover].second, -1);
        ++leftCover;
      }

      // Calculate the total area covered
      int totalArea = (maxX - minX + 1) * (maxY - minY + 1);
      int overlappingArea = fenwick.rangeSum(minY, maxY + 1);
      totalCount += totalArea - overlappingArea;
    }

    // Clear the Fenwick Tree
    while (leftCover < rightCover) {
      fenwick.add(positions[value][leftCover].second, -1);
      ++leftCover;
    }
  }
  return totalCount;
}

// Finds the minimum distance where at least K non-overlapping areas exist
// Uses binary search to minimize the distance d
int bunny(int R, int C, long long K, vector<vector<int>>& B) {
  // Store positions of each number in the grid
  vector<vector<pair<int, int>>> positions(R * C);

  for (int i = 0; i < R; ++i) 
    for (int j = 0; j < C; ++j) 
      positions[B[i][j] - 1].push_back({i, j});

  int low = 1, high = max(R, C) - 1, answer = -1;

  // Binary search for the minimum distance
  while (low <= high) {
    int mid = (low + high) / 2;

    // Check if the current distance covers at least K areas
    if (count(R, C, positions, mid) < K) {
      answer = mid;  // Update answer if valid
      low = mid + 1; // Search in the larger range if more coverage is needed
    } else {
      high = mid - 1; // Search in the smaller range if current distance is too large
    }
  }

  return answer;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t) {
    int R, C;
    long long K;
    cin >> R >> C >> K;

    vector<vector<int>> B(R, vector<int>(C));

    // Read grid values
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        cin >> B[i][j];

    cout << "Case #" << t << ": ";
    cout << bunny(R, C, K, B) << "\n";
  }

  return 0;
}
