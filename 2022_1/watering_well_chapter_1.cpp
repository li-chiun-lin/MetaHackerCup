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

# define D 0

int pow_mod(long a, long b)
{
    long mod = 1e9 + 7;
    long r = 1;

    while (b)
    {
        if (b & 1)
            r = (r * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return r % mod;
}

int mul_mod(long a, long b)
{
    long mod = 1e9 + 7;
    long r = 0;

    while (b)
    {
        if (b & 1)
            r = (r + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }

    return r % mod;
}

int squ_mod(long a)
{
    long mod = 1e9 + 7;
    long b = a;
    long r = 0;

    while (b)
    {
        if (b & 1)
            r = (r + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }

    return r % mod;

}

void print(vector<int>& v)
{
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}

int dst(vector<int>& tree, vector<int>& well)
{
    long long mod = 1e9 + 7;
    long long sigma_t = 0;
    long long sigma_t2 = 0;
    long long sigma_w = 0;
    long long sigma_w2 = 0;
    long long n = tree.size();
    long long q = well.size();

    for (int t : tree)
    {
        sigma_t = (sigma_t + t) % mod;
        sigma_t2 = (sigma_t2 + ((t * t) % mod)) % mod;
    }

    for (int w : well)
    {
        sigma_w = (sigma_w + w) % mod;
        sigma_w2 = (sigma_w2 + ((w * w) % mod)) % mod;
    }

#if D
    cout << "tree : ";
    print(tree);
    cout << sigma_t << " " << sigma_t2 << "\n";
    cout << "well : ";
    print(well);
    cout << sigma_w << " " << sigma_w2 << "\n";
#endif

    return (
            ((n * sigma_w2) % mod) 
        + ((((-2 * sigma_w * sigma_t) % mod) + mod) % mod)
        + ((q * sigma_t2) % mod)
        ) % mod;
}

int watering(vector<int>& A, vector<int>& B, vector<int>& X, vector<int>&Y)
{
    long long mod = 1e9 + 7;

    int r1 = dst(A, X);
    int r2 = dst(B, Y);
#if D
    cout << "cor 1: " << r1 << "\n";
    cout << "cor 2: " << r2 << "\n";
#endif
    return (r1 + r2) % mod;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N;
        cin >> N;

        int a, b;
        vector<int> A(N), B(N);
        
        for (int i = 0; i < N; ++i)
        {
            cin >> a >> b;
            A[i] = a;
            B[i] = b;
        }

        int Q;
        cin >> Q;

        vector<int> X(Q), Y(Q);

        for (int i = 0; i < Q; ++i)
        {
            cin >> a >> b;
            X[i] = a;
            Y[i] = b;
        }

		cout << "Case #" << t << ": ";
		cout << watering(A, B, X, Y) << "\n";
	}

	return 0;
}

