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

const int MOD = 998244353;

// Manages counts of occurrences for each name, with support for efficient least common element retrieval
struct NameFrequency
{
    set<pair<int, int>> count_to_id; // Sorted set of (count, id) pairs
    map<int, int> id_to_count; // Maps each id to its count for easy updates

    // Increment the count of a name (by id)
    void increment(int id, int value = 1)
    {
        if (id_to_count.count(id)) {
            int count = id_to_count[id];
            count_to_id.erase({count, id});  // Remove current pair

            count += value;
            count_to_id.insert({count, id}); // Update pair with new count
            id_to_count[id] = count;
        } else {
            id_to_count[id] = value;
            count_to_id.insert({value, id});
        }
    }

    // Decrement the count of a name (by id)
    void decrement(int id, int value = 1)
    {
        int count = id_to_count[id];
        count_to_id.erase({count, id});  // Remove current pair

        if (count > value) {
            count -= value;
            count_to_id.insert({count, id}); // Update pair if count remains positive
            id_to_count[id] = count;
        } else {
            id_to_count.erase(id); // Remove name if count goes to zero
        }
    }

    // Get the id with the smallest count, or 0 if empty
    int get_min_id()
    {
        return count_to_id.empty() ? 0 : (begin(count_to_id)->second + 1);
    }
};

// Merges name frequencies from `b` into `a` to accumulate descendant data
void merge_frequencies(NameFrequency& a, NameFrequency& b)
{
    if (a.count_to_id.size() < b.count_to_id.size()) 
        swap(a, b);

    for (const auto& [id, count] : b.id_to_count) 
        a.increment(id, count);
}

// Calculates a unique hash based on ancestor and descendant results
int compute_hash(int N, long long M, const vector<int>& A, const vector<int>& D)
{
    long long hash_value = 0;
    ++M;

    for (int i = 0; i < N; ++i) {
        hash_value = (hash_value * M + A[i]) % MOD;
        hash_value = (hash_value * M + D[i]) % MOD;
    }

    return hash_value;
}

// DFS to calculate ancestor results by traversing downward through each node
void calculate_ancestors(int node, const vector<vector<int>>& tree, const vector<int>& name_indices, NameFrequency& freq, vector<int>& A)
{
    A[node] = freq.get_min_id();
    freq.increment(name_indices[node]);

    for (int child : tree[node]) 
        calculate_ancestors(child, tree, name_indices, freq, A);

    freq.decrement(name_indices[node]);
}

// DFS to calculate descendant results by traversing upward through each node
NameFrequency calculate_descendants(int node, const vector<vector<int>>& tree, const vector<int>& name_indices, vector<int>& D)
{
    NameFrequency freq;

    for (int child : tree[node]) {
        auto child_freq = calculate_descendants(child, tree, name_indices, D);
        merge_frequencies(freq, child_freq);
    }

    D[node] = freq.get_min_id();
    freq.increment(name_indices[node]);

    return freq;
}

// Main function to compute hash for least common ancestor and descendant results for each person
int least_common_ancestor(int N, vector<int>& P, vector<string>& S)
{
    // Build the tree as an adjacency list from the parents array
    vector<vector<int>> tree(N);
    for (int i = 0; i < N; ++i)
        if (P[i] != -1)
            tree[P[i] - 1].push_back(i);

    // Extract unique names and map each name to an index
    set<string> unique_names_set(S.begin(), S.end());
    vector<string> unique_names(unique_names_set.begin(), unique_names_set.end());
    map<string, int> name_to_index;
    int unique_name_count = unique_names.size();
    for (int i = 0; i < unique_name_count; ++i) 
        name_to_index[unique_names[i]] = i;

    // Map each person to the index of their name in the unique names list
    vector<int> name_indices(N);
    for (int i = 0; i < N; ++i) 
        name_indices[i] = name_to_index[S[i]];

    // Arrays to store ancestor and descendant results
    vector<int> A(N), D(N);

    // Compute ancestor results using downward DFS
    NameFrequency downward_freq;
    calculate_ancestors(0, tree, name_indices, downward_freq, A);

    // Compute descendant results using upward DFS
    calculate_descendants(0, tree, name_indices, D);

    // Calculate and return hash based on ancestor and descendant results
    return compute_hash(N, unique_name_count, A, D);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> P(N);
		vector<string> S(N);

		for (int i = 0; i < N; ++i)
			cin >> P[i] >> S[i];

		cout << "Case #" << t << ": ";
		cout << least_common_ancestor(N, P, S) << "\n";
	}

	return 0;
}

