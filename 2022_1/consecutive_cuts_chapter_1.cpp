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

void runlength(vector<int>& data, vector<pair<int, long long>>& code)
{
    int run = data[0];
    long long length = 1;

    for (int i = 1; i < data.size(); ++i)
    {
        if (data[i - 1] == data[i])
        {
            ++ length;
        }
        else
        {
            code.push_back({run, length});
            run = data[i];
            length = 1;
        }
    }

    code.push_back({run, length});

}

bool consecuivecuts1(vector<int>& A_data, vector<int>& B_data, int K)
{
    vector<pair<int, long long>> A, B;

    runlength(A_data, A);
    runlength(B_data, B);

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

        if (B[0].first == A[d].first && 
            B[N - 1].first == A[(d + N - 1) % N].first &&
            B[0].first == B[N - 1].first)
        {
            if (B[0].second + B[N - 1].second != 
                A[d].second + A[(d + N - 1) % N].second)
                good = false;
        }
        else
        {
            if (B[0] != A[d] || B[N - 1] != A[(d + N - 1) % N])
                good = false;
        }

        for (int i = 1; i < N - 1 && good; ++i)
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

