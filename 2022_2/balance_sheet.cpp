/*
LTE
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

void print_data(vector<vector<int>>& v)
{
    int id = 0;
	for (auto& r : v)
	{
        cout << id ++ << " : ";
		for (auto& c : r)
            cout << c << " ";
        cout << "\n";
	}
}

void print(vector<vector<int>>& adj)
{
	int w = 2;

	for (int i = 0; i < adj.size(); ++i)
	{
		cout << setw(w) << i << " : ";
		for (int x : adj[i])
			cout << setw(w) << x;
		cout << endl;
	}
	cout << endl;
}

void print(vector<int>& v)
{
	for (int x : v)
		cout << x << " ";
	cout << "\n";
}

int balance(vector<vector<int>>& client, int K)
{
    int n = client.size();
    vector<vector<int>> adj(n);
    vector<int> deg(n);

    sort(begin(client), end(client));

    //cout << "\n";
    //print_data(client);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (client[i][1] == client[j][0] && client[i][3] < client[j][2])
            {
                adj[i].push_back(j);
                ++ deg[j];
            }
        }
    }

    //print(adj);
    //print(deg);

    queue<vector<int>> que;

    for (int i = 0; i < n; ++i)
        if (adj[i].size())
            que.push({i, 0});

    priority_queue<int, vector<int>, greater<>> pq;

    while (que.size())
    {
        int u = que.front()[0];
        int p = que.front()[1];
        que.pop();

        //cout << "process " << u << "\n";

        //cout << "push " << p << "\n";

        pq.push(p);
        if (pq.size() > K)
        {
            //cout << "pop " << pq.top() << "\n";
            pq.pop();
        }

        for (int v : adj[u])
        {
            //if (-- deg[v] == 0)
            {
                //cout << "enque " << v << "\n";
                que.push({v, p + client[v][2] - client[u][3]});
            }
        }
    }

    int sum = 0;

    while (pq.size())
    {
        sum += pq.top();
        pq.pop();
    }


    return sum;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N, K;
        cin >> N >> K;

        vector<vector<int>> client(N, vector<int>(4));

        for (auto& c : client)
            for (int i = 0; i < 4; ++i)
                cin >> c[i];

		cout << "Case #" << t << ": ";
		cout << balance(client, K) << "\n";
	}

	return 0;
}

