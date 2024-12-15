/*

*/

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

const int kInf = 507;

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}


struct Team
{
    vector<int> assigned, unassigned;
    int min_val{kInf};

    int size()
    {
        return assigned.size() + unassigned.size();
    }

    bool operator<(const Team& other) const
    {
        return min_val < other.min_val;
    }
};

bool isValidAssignment(vector<int>& vals, int last, int diff, vector<int>& costs)
{
    sort(vals.begin(), vals.end());
    int k = vals.size();
    costs.resize(2 + k);
    vector<int> c(2 + k);

    if (diff < 0)
    {
        costs[0] = -diff;
        costs[1] = 0;
    }
    else
    {
        costs[0] = 0;
        costs[1] = diff;
    }

    c[1] = last;

    for (int i = 0; i < k; i++)
    {
        c[i + 2] = vals[i];
        costs[i + 2] = min(costs[i], costs[i + 1]) + (c[i + 2] - c[i + 1]);
    }

    if (k == 3 && costs[k] > costs[k - 1])
    {
        return false;
    }

    if (k == 2 && costs[k - 1] > costs[k])
    {
        return false;
    }

    return true;
}

bool dfs(vector<int>& W, int M, vector<Team>& teams, set<tuple<int, int, int>>& visitedStates, map<tuple<int, int, int>, vector<int>>& parentAssignments, map<tuple<int, int, int>, tuple<int, int, int>>& nextState, int index, int diff, int last)
{
    if (index == M || teams[index].min_val == kInf)
    {
        return true;
    }
    tuple<int, int, int> st{index, diff, last};
    if (visitedStates.count(st))
    {
        return false;
    }
    visitedStates.insert(st);
    const Team& T = teams[index];
    if (T.unassigned.empty())
    {
        if (last >= T.min_val)
        {
            return false;
        }
        int k = T.assigned.size();
        vector<int> vals(k);
        for (int i = 0; i < k; i++)
        {
            vals[i] = W[T.assigned[i]];
        }
        vector<int> costs;
        if (!isValidAssignment(vals, last, diff, costs))
        {
            return false;
        }
        bool cur = dfs(W, M, teams, visitedStates, parentAssignments, nextState, index + 1, costs[k + 1] - costs[k], vals.back());
        if (cur)
        {
            parentAssignments[st] = vals;
			nextState[st] = {index + 1, costs[k + 1] - costs[k], vals.back()};
        }
        return cur;
    }
    if (T.assigned.size() == 1)
    {
        int assignedPos = W[T.assigned[0]];
        int tt = T.unassigned.size();
        for (int i = max(1, max(last + 1, assignedPos - tt)); i <= assignedPos + 1; i++)
        {
            if (i == assignedPos)
            {
                continue;
            }
            vector<int> vals(1, assignedPos);
            vals.push_back(i);
            if (tt == 2)
            {
                if (i + 1 == assignedPos)
                {
                    vals.push_back(i + 2);
                }
                else
                {
                    vals.push_back(i + 1);
                }
            }
            vector<int> costs;
            if (!isValidAssignment(vals, last, diff, costs))
            {
                continue;
            }
            int k = vals.size();
            bool cur = dfs(W, M, teams, visitedStates, parentAssignments, nextState, index + 1, costs[k + 1] - costs[k], vals.back());
            if (cur)
            {
                parentAssignments[st] = vals;
                nextState[st] = {index + 1, costs[k + 1] - costs[k], vals.back()};
                return true;
            }
        }
        return false;
    }
    vector<int> assignedPositions(2);
    for (int i = 0; i < 2; i++)
    {
        assignedPositions[i] = W[T.assigned[i]];
    }
    if (assignedPositions[0] > assignedPositions[1])
    {
        swap(assignedPositions[0], assignedPositions[1]);
    }
    for (int i = max(1, max(last + 1, assignedPositions[0] - 1)); i <= assignedPositions[1] + 1; i++)
    {
        if (i == assignedPositions[0] || i == assignedPositions[1])
        {
            continue;
        }
        vector<int> vals = assignedPositions;
        vals.push_back(i);
        vector<int> costs;
        if (!isValidAssignment(vals, last, diff, costs))
        {
            continue;
        }
        int k = vals.size();
        bool cur = dfs(W, M, teams, visitedStates, parentAssignments, nextState, index + 1, costs[k + 1] - costs[k], vals.back());
        if (cur)
        {
            parentAssignments[st] = vals;
            nextState[st] = {index + 1, costs[k + 1] - costs[k], vals.back()};
            return true;
        }
    }
    return false;
}

void assignValuesToTeam(vector<int>& W, const Team& T, const vector<int>& vals)
{
    set<int> used;
    for (int i : T.assigned)
    {
        used.insert(W[i]);
    }
    vector<int> availableValues;
    for (int val : vals)
    {
        if (!used.count(val))
        {
            availableValues.push_back(val);
        }
    }
    for (int i : T.unassigned)
    {
        W[i] = availableValues.back();
        availableValues.pop_back();
    }
}

bool validateFinalAssignment(int N, vector<int>& W, vector<int>& C)
{
    vector<int> sortedValues = W;
    vector<int> costs(N);
    sort(sortedValues.begin(), sortedValues.end());
    costs[0] = 1000000;
    costs[1] = sortedValues[1] - sortedValues[0];
    for (int i = 2; i < N; i++)
    {
        costs[i] = min(costs[i - 1], costs[i - 2]) + (sortedValues[i] - sortedValues[i - 1]);
    }
    vector<vector<int>> groups(N);
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        groups[C[i]].push_back(W[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (groups[i].empty())
        {
            continue;
        }
        sort(groups[i].begin(), groups[i].end());
        result += groups[i].back() - groups[i][0];
    }
    return costs[N - 1] == result;
}


bool splitting_hares(int N, vector<int>& W, vector<int>& C)
{
	vector<Team> teamsBackup(N);

	for (int i = 0; i < N; ++i)
	{
		if (W[i] == -1)
		{
			teamsBackup[C[i]].unassigned.push_back(i);
		}
		else
		{
			teamsBackup[C[i]].assigned.push_back(i);
			teamsBackup[C[i]].min_val = min(teamsBackup[C[i]].min_val, W[i]);
		}
	}

	vector<Team> teams;

    for (int i = 0; i < N; i++)
    {
        if (teamsBackup[i].size())
        {
            teams.push_back(teamsBackup[i]);
        }
    }
    sort(teams.begin(), teams.end());
    int M = teams.size();

	for (int i = 0; i < M; i++)
        if (teams[i].size() > 3)
            return false;

	set<tuple<int, int, int>> visitedStates;	
    map<tuple<int, int, int>, vector<int>> parentAssignments;
    map<tuple<int, int, int>, tuple<int, int, int>> nextState;
	int index = 0;
	int diff = -kInf;
	int last = -kInf;
    tuple<int, int, int> st{index, diff, last};
    bool res = dfs(W, M, teams, visitedStates, parentAssignments, nextState, index, diff, last);

	if (res)
    {
        for (;;)
        {
            auto nextStateIt = nextState.find(st);
            if (nextStateIt == nextState.end())
            {
                break;
            }
            assignValuesToTeam(W, teams[get<0>(st)], parentAssignments[st]);
            st = nextStateIt->second;
        }
        int val = 10000;
        for (int i = 0; i < M; i++)
        {
            if (teams[i].min_val != kInf)
            {
                continue;
            }
            vector<int> vals;
            for (int j = 0; j < (int)teams[i].unassigned.size(); j++)
            {
                vals.push_back(val--);
            }
            assignValuesToTeam(W, teams[i], vals);
            --val;
        }
        if (!validateFinalAssignment(N, W, C))
        {
            return false;
        }
    }
    return res;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> W(N), C(N);

		for (auto& x : W)
			cin >> x;

		for (auto& x : C)
		{
			cin >> x;
			-- x;
		}

		auto r = splitting_hares(N, W, C);

		cout << "Case #" << t << ": ";

		if (r)
		{
			cout << "Yes\n";
			print(W);
		}
		else
		{
			cout << "No\n";
		}
	}

	return 0;
}

