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
#include <vector>

using namespace std;

void print(vector<pair<int, int>>& v)
{
	for (auto& [k, v] : v)
        cout << k << "(" << v << ") ";
    cout << "\n";
}

vector<pair<int, int>> run_length(vector<int>& X)
{
    vector<pair<int, int>> ret;

    int r = X[0];
    int l = 1;

    for (int i = 1; i < X.size(); ++i)
    {
        if (r == X[i])
            ++ l;
        else
        {
            ret.push_back({r, l});
            r = X[i];
            l = 1;
        }
    }

    ret.push_back({r, l});

    return ret;
}

bool adjust(vector<pair<int, int>>& XX)
{
    if (XX.size() > 1 && XX[0].first == XX.back().first)
    {
        XX[0].second += XX.back().second;
        XX.pop_back();
        return true;
    }

    return false;
}

#define D 0

bool consecuive_cuts_2(int N, int K, vector<int>& A, vector<int>& B)
{
    auto AA = run_length(A);
    auto BB = run_length(B);

#if D
    cout << "\n";
    print(AA);
    print(BB);
#endif

    auto adjA = adjust(AA);
    auto adjB = adjust(BB);

#if D
    cout << "after adjust\n";
    print(AA);
    print(BB);
#endif

    if (AA.size() != BB.size())
        return false;

    int NN = AA.size();

    if (NN == 1)
        return true;

#if D
    cout << "NN = " << NN << " " << adjA << " " << adjB << "\n";
    cout << "K = " << K << "\n";
#endif

    for (int cut = 0; cut < NN; ++cut)
    {
        if (BB[cut] != AA[0])
            continue;

#if D
        cout << "check a cut at " << cut << "\n";
#endif

        bool match = true;

        int i = 0;
        while (cut + i < NN && match)
        {
            if (AA[i] != BB[cut + i])
                match = false;

            ++ i;
        }

#if D
        cout << "first match " << match << " " << i << "\n";
#endif

        if (! match)
            continue;

        int j = 0;
        while (j + i < NN && match)
        {
            if (AA[j + i] != BB[j])
                match = false;

            ++ j;
        }

#if D
        cout << "second match " << match << "\n";
#endif

        if (! match)
            continue;

#if D
        cout << "find a cut at " << cut << "\n";
#endif

        if (NN > 2)
        {
            if (cut)
            {
                if (adjA && adjB && A != B)
                    return K != 1;
                else
                    return K != 0;
            }
            else // cut == 0
                return K != 1;
        }
        else // NN == 2
        {
            if (cut)
            {
                if (! adjA && ! adjB)
                {
                    if (N == 2)
                        return K % 2 != 0;
                    else
                        return K != 0;
                }
                else if (adjA && adjB)
                    return K > 1;
                else
                    return K != 0;
            }
            else // cut == 0
            {
                if (! adjA && ! adjB)
                {
                    if (N == 2)
                        return K % 2 == 0;
                    else
                        return K != 1;
                }
                else if (adjA && adjB)
                    return K != 1;
                else
                    return K != 0;
            }
        }
    }

    return false;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);

        for (auto& x : A)
            cin >> x;

        for (auto& x : B)
            cin >> x;

		cout << "Case #" << t << ": ";
		cout << (consecuive_cuts_2(N, K, A, B) ? "YES" : "NO") << "\n";
	}

	return 0;
}

