/*
incorrect
not finished
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

bool consecuivecuts1(int N, int K, vector<int>& A, vector<int>& B)
{
    for (int cut = 0; cut < N; ++cut)
    {
        if (B[cut] == A[0])
        {
            bool match = true;
            int i = 0;

            while (cut + i < N && match)
            {
                if (A[i] != B[cut + i])
                    match = false;

                ++ i;
            }

            if (! match)
                continue;

            int j = 0;
            while (j + i < N && match)
            {
                if (A[j + i] != B[j])
                    match = false;

                ++ j;
            }

            if (! match)
                continue;

            if (N > 2)
            {
                if (cut)
                    return K != 0;
                else
                    return K != 1;
            }
            else
            {
                if (cut)
                    return K % 2 != 0;
                else
                    return K % 2 == 0;
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
		cout << (consecuivecuts1(N, K, A, B) ? "YES" : "NO") << "\n";
	}

	return 0;
}

