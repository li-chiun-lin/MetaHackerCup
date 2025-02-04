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

// Fenwick tree class for range sum queries and point updates
class FenwickTree {
    vector<long long> tree; // Fenwick tree array to store sums
    int size; // Size of the tree (same as array length)

public:
    // Constructor initializes the Fenwick tree with size n
    FenwickTree(int n) : size(n), tree(n) { }

    // Update the tree at index x by adding value v
    void update(int x, long long v) {
        // Traverse the tree and update the necessary indices
        while (x < size) {
            tree[x] += v;
            x |= (x + 1); // Move to the next position
        }
    }

    // Query the prefix sum up to index x
    long long query(int x) {
        long long sum = 0;
        // Traverse the tree to get the sum up to index x
        while (x >= 0) {
            sum += tree[x];
            x = (x & (x + 1)) - 1; // Move to the previous position
        }
        return sum;
    }
};

// Update the Fenwick trees when an element at index i changes
void updateFenwickTrees(int idx, int coeff, vector<int>& A, 
                        FenwickTree& totalFenwickTree, 
                        vector<FenwickTree>& frequencyFenwickTrees, 
                        vector<FenwickTree>& indexFenwickTrees) {
    // Update the total sum tree with the new value
    totalFenwickTree.update(idx, coeff * (A[idx] + 1)); 
    // Update the frequency trees for the values (0 or 1)
    frequencyFenwickTrees[A[idx]].update(idx, coeff); 
    // Update the index trees with the value of the current index
    indexFenwickTrees[A[idx]].update(idx, coeff * idx); 
}

// Main function to solve the problem
long long work_life_balance_chapter_2(int N, int M, vector<int>& A, vector<tuple<int, int, int>>& B)
{
    // Decrement each element of A by 1 for 0-based indexing
    for (auto& a : A)
        --a;

    // Initialize Fenwick trees for total sum, frequency of 0s and 1s, and indices
    FenwickTree totalFenwickTree(N);
    vector<FenwickTree> frequencyFenwickTrees(2, FenwickTree(N)); // Fenwick trees for 0 and 1
    vector<FenwickTree> indexFenwickTrees(2, FenwickTree(N)); // Fenwick trees for indices

    // Initialize the Fenwick trees with the initial array values
    for (int i = 0; i < N; i++) {
        updateFenwickTrees(i, 1, A, totalFenwickTree, frequencyFenwickTrees, indexFenwickTrees);
    }

    long long sum = 0;

    // Process each operation described in B
    for (auto [x, y, z] : B)
    {
        // Adjust for 0-based indexing
        --x;
        --y;
        --z;

        // Before updating, decrement the value at index x in the trees
        updateFenwickTrees(x, -1, A, totalFenwickTree, frequencyFenwickTrees, indexFenwickTrees);
        A[x] = y; // Change the value at index x
        // After updating, increment the value at index x in the trees
        updateFenwickTrees(x, 1, A, totalFenwickTree, frequencyFenwickTrees, indexFenwickTrees);

        // Calculate the prefix sums for the left and right segments
        long long leftSum = totalFenwickTree.query(z);
        long long rightSum = totalFenwickTree.query(N - 1) - totalFenwickTree.query(z);
        long long diff = leftSum - rightSum;

        // If the difference is odd, no valid result can be found
        if (diff & 1) {
            sum -= 1;
            continue;
        }

        // Determine the values for the left and right sides based on the sign of the difference
        int leftValue = (diff > 0) ? 1 : 0;
        int rightValue = (diff > 0) ? 0 : 1;
        long long count = abs(diff) / 2;

        // Check if there are enough values to satisfy the condition
        if (frequencyFenwickTrees[leftValue].query(z) < count || 
            frequencyFenwickTrees[rightValue].query(N - 1) - frequencyFenwickTrees[rightValue].query(z) < count) {
            sum -= 1;
            continue;
        }

        // Calculate the result for the left side (using binary search)
        long long leftResult = 0;
        {
            int low = -1, high = z;
            while (low < high) {
                int mid = (low + high + 1) >> 1;
                if (frequencyFenwickTrees[leftValue].query(z) - frequencyFenwickTrees[leftValue].query(mid) < count) {
                    high = mid - 1;
                } else {
                    low = mid;
                }
            }
            // Calculate the auxiliary sum for the left segment
            long long aux = indexFenwickTrees[leftValue].query(z) - indexFenwickTrees[leftValue].query(low);
            long long limit = count * z - count * (count - 1) / 2;
            leftResult = limit - aux;
        }

        // Calculate the result for the right side (using binary search)
        long long rightResult = 0;
        {
            int low = z, high = N - 1;
            while (low < high) {
                int mid = (low + high) >> 1;
                if (frequencyFenwickTrees[rightValue].query(mid) - frequencyFenwickTrees[rightValue].query(z) < count) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            long long aux = indexFenwickTrees[rightValue].query(low) - indexFenwickTrees[rightValue].query(z);
            long long limit = count * (z + 1) + count * (count - 1) / 2;
            rightResult = aux - limit;
        }

        // Add the result to the final sum
        sum += leftResult + rightResult + count * count;
    }

    return sum;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, M;

        cin >> N >> M;

        vector<int> A(N);

        // Read the array A
        for (auto& a : A)
        {
            cin >> a;
        }

        vector<tuple<int, int, int>> B(M);

        // Read the operations in B (x, y, z) for each query
        for (auto& [x, y, z] : B)
        {
            cin >> x >> y >> z;
        }

        cout << "Case #" << t << ": ";
        // Process the input and output the result
        cout << work_life_balance_chapter_2(N, M, A, B) << "\n";
    }

    return 0;
}

