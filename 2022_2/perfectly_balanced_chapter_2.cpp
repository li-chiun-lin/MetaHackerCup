/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Fenwick Tree (Binary Indexed Tree) implementation
class FenwickTree
{
public:
    vector<unsigned long long> tree; // Tree structure to store cumulative frequencies
    int size;

    // Constructor initializes the tree with given size
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    // Updates the Fenwick Tree at index 'i' by adding 'value'
    void update(int i, unsigned long long value)
    {
        for (; i < size; i |= i + 1)
            tree[i] += value;
    }

    // Computes the prefix sum from index 0 to i
    unsigned long long query(int i) const
    {
        unsigned long long result = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            result += tree[i];
        return result;
    }
};

// Function to process queries and determine the number of valid cases
int perfect(int N, vector<int>& A, int Q, const vector<tuple<int, int, int>>& queries, 
            const vector<unsigned long long>& H, const vector<unsigned long long>& S)
{
    FenwickTree tree(N);

    // Initializing Fenwick Tree with the hash values of elements in A
    for (int i = 0; i < N; ++i)
        tree.update(i, H[A[i]]);

    int answer = 0;

    // Processing each query
    for (const auto& [type, x, y] : queries)
    {
        if (type == 1) // Update operation
        {
            int index = x - 1;
            tree.update(index, H[y] - H[A[index]]); // Update difference in Fenwick Tree
            A[index] = y; // Update element in array
        }
        else // Check for a balanced partition
        {
            int left = x - 1, right = y - 1;
            int length = right - left + 1;

            // Check only for odd-length subarrays
            if (length % 2)
            {
                int mid1 = left + length / 2; // Middle element index
                int mid2 = mid1 + 1; // Next middle element index (if required)
                
                // Check both middle elements for valid difference
                for (int i : {mid1, mid2})
                {
                    if (i > right) break;

                    // Compute sum of left and right halves
                    auto leftSum = tree.query(i - 1) - tree.query(left - 1);
                    auto rightSum = tree.query(right) - tree.query(i - 1);
                    auto diff = (i == mid1) ? (rightSum - leftSum) : (leftSum - rightSum);
                    
                    // If the difference exists in sorted hash values, increment answer
                    if (binary_search(S.begin(), S.end(), diff))
                    {
                        ++answer;
                        break;
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    constexpr int MAX_SIZE = 1e7;
    vector<unsigned long long> hash(MAX_SIZE);

    // Generate random hash values for elements
    for (int i = 0; i < MAX_SIZE; ++i)
        hash[i] = (static_cast<unsigned long long>(rand()) << 32) | rand();

    // Create a sorted version of the hash values
    vector<unsigned long long> sorted_hash = hash;
    sort(sorted_hash.begin(), sorted_hash.end());

    int T;
    cin >> T;

    // Process each test case
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int& a : A) cin >> a;

        int Q;
        cin >> Q;

        vector<tuple<int, int, int>> queries(Q);
        for (auto& [i, x, y] : queries)
            cin >> i >> x >> y;

        // Output the result for the test case
        cout << "Case #" << t << ": " << perfect(N, A, Q, queries, hash, sorted_hash) << "\n";
    }

    return 0;
}

