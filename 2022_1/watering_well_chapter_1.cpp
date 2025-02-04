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

const long long MOD = 1e9 + 7;

// Modular exponentiation: Computes (a^b) % MOD efficiently
long long pow_mod(long long a, long long b) 
{
    long long result = 1;
    while (b) 
    {
        if (b & 1) 
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

// Modular multiplication: Computes (a * b) % MOD safely
long long mul_mod(long long a, long long b) 
{
    long long result = 0;
    while (b) 
    {
        if (b & 1) 
            result = (result + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return result;
}

// Modular squaring: Computes (a^2) % MOD safely
long long squ_mod(long long a) 
{
    return (a * a) % MOD;
}

// Computes the squared distance metric between trees and wells
long long dst(const vector<int>& tree, const vector<int>& well) 
{
    long long sigma_t = 0, sigma_t2 = 0;
    long long sigma_w = 0, sigma_w2 = 0;
    long long n = tree.size(), q = well.size();

    for (int t : tree) 
    {
        sigma_t = (sigma_t + t) % MOD;
        sigma_t2 = (sigma_t2 + squ_mod(t)) % MOD;
    }

    for (int w : well) 
    {
        sigma_w = (sigma_w + w) % MOD;
        sigma_w2 = (sigma_w2 + squ_mod(w)) % MOD;
    }

    return (n * sigma_w2 % MOD 
          + MOD - (2 * sigma_w % MOD * sigma_t % MOD) % MOD 
          + q * sigma_t2 % MOD) % MOD;
}

// Computes the total watering distance metric for two sets of trees and wells
long long watering(const vector<int>& A, const vector<int>& B, 
                   const vector<int>& X, const vector<int>& Y) 
{
    return (dst(A, X) + dst(B, Y)) % MOD;
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

