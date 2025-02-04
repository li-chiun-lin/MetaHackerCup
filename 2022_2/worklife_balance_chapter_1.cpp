/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
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

// Fenwick Tree implementation to support prefix sum and updates
struct FenwickTree
{
    vector<int> values; // Original values
    vector<int> tree;  // Fenwick Tree structure

    FenwickTree(int size) : values(size + 1), tree(size + 1) {}

    // Calculate prefix sum up to index `idx`
    int prefixSum(int idx) const
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    // Add `delta` to the value at index `idx`
    void update(int idx, int delta)
    {
        values[idx] += delta;
        while (idx < tree.size())
        {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    // Get the value at index `idx`
    int get(int idx) const
    {
        return values[idx];
    }

    // Calculate the sum of values in the range [left, right]
    int rangeSum(int left, int right) const
    {
        return prefixSum(right) - prefixSum(left - 1);
    }

    // Set the value at index `idx` to `value`
    void set(int idx, int value)
    {
        update(idx, value - values[idx]);
    }
};

// Perform `count` swaps between indices `from` and `to` in two arrays
void applySwaps(vector<int>& left, vector<int>& right, int from, int to, int count)
{
    left[from] -= count;
    right[from] += count;
    right[to] -= count;
    left[to] += count;
}

// Strategy A: Balance the difference `diff` using specific swaps
int strategyA(vector<int> left, vector<int> right, int diff)
{
    int swap13 = min({left[0], right[2], diff / 4});
    applySwaps(left, right, 0, 2, swap13);
    diff -= 4 * swap13;

    int swap12 = min({left[0], right[1], diff / 2});
    applySwaps(left, right, 0, 1, swap12);
    diff -= 2 * swap12;

    int swap23 = min({left[1], right[2], diff / 2});
    applySwaps(left, right, 1, 2, swap23);
    diff -= 2 * swap23;

    return diff ? 1e9 : swap13 + swap12 + swap23;
}

// Strategy B: Handle negative `diff` using additional swaps
int strategyB(vector<int> left, vector<int> right, int diff)
{
    int swap13 = min({left[0], right[2], (diff + 3) / 4});
    applySwaps(left, right, 0, 2, swap13);
    diff -= 4 * swap13;

    int swap21 = 0;
    int swap32 = 0;

    if (diff < 0)
    {
        swap21 = min({left[1], right[0], -diff / 2});
        applySwaps(left, right, 1, 0, swap21);
        diff += 2 * swap21;

        swap32 = min({left[2], right[1], -diff / 2});
        applySwaps(left, right, 2, 1, swap32);
        diff += 2 * swap32;
    }

    return diff ? 1e9 : swap13 + swap21 + swap32;
}

// Main function to calculate the work-life balance score
long long worklife_balance(int N, int M, vector<int>& A, vector<int>& X, vector<int>& Y, vector<int>& Z)
{
    // Initialize Fenwick trees for three categories
    FenwickTree trees[3] = {FenwickTree(N), FenwickTree(N), FenwickTree(N)};

    // Populate initial values into the trees
    for (int i = 0; i < N; ++i)
    {
        trees[A[i] - 1].set(i + 1, 1);
    }

    long long totalSwaps = 0;

    for (int i = 0; i < M; ++i)
    {
        // Update the Fenwick trees based on the current operation
        for (int category = 0; category < 3; ++category)
        {
            trees[category].set(X[i], category == Y[i] - 1);
        }

        vector<int> left(3), right(3);
        int sumLeft = 0, sumRight = 0;

        // Calculate the prefix and suffix sums for each category
        for (int category = 0; category < 3; ++category)
        {
            left[category] = trees[category].rangeSum(1, Z[i]);
            right[category] = trees[category].rangeSum(Z[i] + 1, N);
            sumLeft += (category + 1) * left[category];
            sumRight += (category + 1) * right[category];
        }

        // Skip if already balanced
        if (sumLeft == sumRight)
        {
            continue;
        }

        // Ensure `sumLeft` is the smaller sum
        if (sumLeft > sumRight)
        {
            swap(sumLeft, sumRight);
            swap(left, right);
        }

        int diff = sumRight - sumLeft;

        // Use the better strategy to balance
        int minSwaps = min(strategyA(left, right, diff), strategyB(left, right, diff));

        totalSwaps += (minSwaps == 1e9) ? -1 : minSwaps;
    }

    return totalSwaps;
}

int main()
{
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase)
    {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        vector<int> X(M), Y(M), Z(M);

        for (auto& value : A)
        {
            cin >> value;
        }

        for (int i = 0; i < M; ++i)
        {
            cin >> X[i] >> Y[i] >> Z[i];
        }

        cout << "Case #" << testCase << ": " << worklife_balance(N, M, A, X, Y, Z) << "\n";
    }

    return 0;
}


