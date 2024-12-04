#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

// Function to check if all triplets satisfy the conditions
bool all_triplets(const string& S, int N, const vector<int>& U, const vector<int>& V) {
    // Build adjacency list for the graph
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        adj[U[i] - 1].push_back(V[i] - 1);
        adj[V[i] - 1].push_back(U[i] - 1);
    }

    // Check based on the string order
    if (S == "kij" || S == "kji") {
        // Always true for these orders
        return true;
    } else if (S == "ikj" || S == "jki") {
        // Check specific conditions for "ikj" and "jki"
        for (int u = 0; u < N; ++u) {
            vector<int> smaller;

            // Collect neighbors smaller than the current node
            for (int v : adj[u])
                if (v < u)
                    smaller.push_back(v);

            int twoEdge = -1, oneEdge = -1;

            // Find a node with more than one edge
            for (int x : smaller)
                if (adj[x].size() > 1) {
                    twoEdge = x;
                    break;
                }

            // Find a different node
            for (int y : smaller)
                if (y != twoEdge) {
                    oneEdge = y;
                    break;
                }

            // Invalid configuration
            if (twoEdge != -1 && oneEdge != -1)
                return false;
        }
    } else {
        // Handle other orders using down edges and lowest hit calculations
        vector<int> downEdge(N, 0), lowestHit(N, INT_MAX);

        // Compute down edges and the lowest node each node connects to
        for (int u = 0; u < N; ++u) {
            for (int v : adj[u])
                if (v < u) {
                    ++downEdge[u];
                    lowestHit[u] = min(lowestHit[u], v);
                }
        }

        // Check for M-shaped configurations
        for (int u = 0; u < N; ++u) {
            int reachableArms = 0, reachableLowerArms = 0;

            for (int v : adj[u])
                if (v > u && downEdge[v] > 1) {
                    ++reachableArms;
                    if (lowestHit[v] < u)
                        ++reachableLowerArms;
                }

            if (reachableArms >= 2 && reachableLowerArms > 0)
                return false;
        }

        // Check for Vulcano-shaped configurations
        for (int u = 0; u < N; ++u) {
            int reachableArms = 0, reachableShorts = 0;

            for (int v : adj[u]) {
                if (v > u && downEdge[v] > 1)
                    ++reachableArms;
                if (v < u)
                    ++reachableShorts;
            }

            if (reachableArms >= 1 && reachableShorts >= 1)
                return false;
        }
    }

    return true; // All conditions satisfied
}

int main() {
    int T; // Number of test cases
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        string S;
        cin >> S; // String order

        int N;
        cin >> N; // Number of nodes

        vector<int> U(N - 1), V(N - 1); // Edges
        for (int i = 0; i < N - 1; ++i)
            cin >> U[i] >> V[i];

        // Print the result for each test case
        cout << "Case #" << t << ": " 
             << (all_triplets(S, N, U, V) ? "Lucky" : "Wrong") << "\n";
    }

    return 0;
}
