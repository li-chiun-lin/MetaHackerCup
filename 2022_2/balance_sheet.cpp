#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Merge two vectors (v1 and v2) with a limit (K) and an additional constant value (c2)
vector<long long> merge(const vector<long long>& v1, const vector<long long>& v2, int K, long long c2)
{
    vector<long long> result; // Resultant merged vector
    int i = 0, j = 0;
    int n = v1.size(), m = v2.size();

    // Merge elements from v1 and v2 until one is exhausted or result size reaches K
    while (i < n && j < m && result.size() < K)
    {
        if (v1[i] >= v2[j] + c2)
        {
            result.push_back(v1[i++]);
        }
        else
        {
            result.push_back(v2[j++] + c2);
        }
    }

    // Add remaining elements from v1 if result size is less than K
    while (i < n && result.size() < K)
    {
        result.push_back(v1[i++]);
    }

    // Add remaining elements from v2 (adjusted by c2) if result size is less than K
    while (j < m && result.size() < K)
    {
        result.push_back(v2[j++] + c2);
    }

    return result;
}

// Calculate maximum balance for all clients
int balance(int N, int K, const vector<tuple<int, int, int, int>>& client)
{
    // Create events for start and end days for all clients
    vector<tuple<int, int, int, int>> events(N * 2);
    for (int i = 0; i < N; ++i)
    {
        auto [a, b, x, y] = client[i];
        events[i * 2] = {a, x, i, 0};      // Start day event
        events[i * 2 + 1] = {b, y, i, 1};  // End day event
    }

    // Sort events by day in descending order
    sort(events.rbegin(), events.rend());

    // Initialize profit trackers
    vector<vector<long long>> profit(N, {0});
    vector<long long> currentValues; // Temporary values storage
    int previousDay = -1;

    // Process events
    for (const auto& [day, price, id, type] : events)
    {
        // Clear temporary values when moving to a new day
        if (previousDay != day)
        {
            currentValues.clear();
        }

        if (type == 0) // Start day event
        {
            currentValues = merge(currentValues, profit[id], K, price);
        }
        else // End day event
        {
            vector<long long> adjustedValues;

            // Calculate adjusted values by subtracting the price
            for (const auto& value : currentValues)
            {
                if (value > price)
                {
                    adjustedValues.push_back(value - price);
                }
            }

            // Merge adjusted values with the current client's profit
            profit[id] = merge(profit[id], adjustedValues, K, 0);
        }

        previousDay = day;
    }

    // Combine all profits across clients
    vector<long long> finalValues;
    for (const auto& p : profit)
    {
        finalValues = merge(finalValues, p, K, 0);
    }

    // Calculate the final result modulo 1e9 + 7
    long long answer = 0;
    const long long MOD = 1e9 + 7;
    for (const auto& value : finalValues)
    {
        answer = (answer + value) % MOD;
    }

    return answer;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, K;
        cin >> N >> K;

        vector<tuple<int, int, int, int>> client(N);
        for (auto& [a, b, x, y] : client)
        {
            cin >> a >> b >> x >> y;
        }

        cout << "Case #" << t << ": " << balance(N, K, client) << "\n";
    }

    return 0;
}
