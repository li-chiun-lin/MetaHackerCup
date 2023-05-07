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

void print(vector<int>& v)
{
	for (int x : v)
		cout << x << " ";
	cout << "\n";
}

void print(vector<int>& v, int d)
{
	int n = v.size();

    for (int i = 0; i < n; ++i)
        cout << v[(i + d) % n] << " ";
    cout << "\n";
}

#define D 0

bool consecuivecuts1(vector<int>& A, vector<int>& B, int K)
{
    int N = A.size();

#if D
    cout << "start ================== \n";
    print(A);
    print(B);
#endif

    if (A == B)
    {
#if D
        cout << "end 1 \n";
#endif
        return K != 1;
    }

    if (K == 0)
    {
#if D
        cout << "end 2 \n";
#endif
        return false;
    }

    for (int d = 1; d < N; ++d)
    {
        bool good = true;

        for (int i = 0; i < N && good; ++i)
            if (B[i] != A[(i + d) % N])
            {
#if D
        cout << "fail at index " << d << " " << B[i] << " " << A[(i + d) % N] << "\n";
#endif
                good = false;
            }

        if (good)
        {
#if D
            cout << "find " << d << "\n";
            print(A, d);
#endif

            if (N == 2)
                return K % 2;
                
            return true;
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
		cout << (consecuivecuts1(A, B, K) ? "YES" : "NO") << "\n";
	}

	return 0;
}

