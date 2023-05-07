/*
TLE
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

//void run(int P, int size, vector<int>& coef, vector<long long>& freq)
void run(int P, int size, vector<int>& coef, unordered_map<int, long long>& freq)
{
	long long a1 = coef[0];
	long long a2 = coef[1];
	long long a3 = 0;

	++ freq[a1 % P];
	++ freq[a2 % P];

	for (int i = 3; i <= size; ++i)
	{
		a3 = (a1 * coef[2] + a2 * coef[3] + coef[4]) % P;
		++ freq[a3 % P];
		a1 = a2;
		a2 = a3;
	}
}

#if 1
int generator(int P)
{
	for (int g = 2; g < P; ++g)
	{
		long long a = 1;
		bool valid = true;

		for (int i = 1; i < P - 1 && valid; ++i)
		{
			a = (a * g) % P;
			valid = a != 1;
		}

		if ((a * g) % P == 1)
			return g;
	}

	return -1;
}
#endif

vector<int> prime_divisor(int P1)
{
	vector<int> p;
	vector<bool> sieve(P1 + 1, true);

	for (long long i = 2; i * i <= P1; ++i)
		if (sieve[i])
		{
			p.push_back(i);

			for (long long j = i * i; j <= P1; j += i)
				sieve[j] = false;
		}

	return p;
}

#if 0
int generator(int P)
{
	auto divisor = prime_divisor(P - 1);

	reverse(begin(divisor), end(divisor));

	for (int g = 2; g < P; ++g)
	{
		int pow = 0;
		long long a = 1;
		bool valid = true;

		for (auto& q : divisor)
		{
			int d = (P - 1) / q;
			while (pow ++ < d)
				a = (a * g) % P;

			if (a == 1)
			{
				valid = false;
				break;
			}
		}

		if (valid)
			return g;
	}

	return 0;
}
#endif

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

void print(vector<vector<int>>& v)
{
	for (auto& r : v)
		print(r);
}

vector<vector<int>> mul_tab(int P)
{
	vector<vector<int>> tab(P, vector<int>(P));

	for (long long i = 1; i < P; ++i)
		for (long long j = 1; j < P; ++j)
			tab[i][j] = (i * j) % P;

	return tab;
}

void check_generator(int P, int g)
{
	long long a = 1;

	for (int x = 1; x < P; ++x)
	{
		a = (a * g) % P;
		cout << a << " ";
	}
	cout << "\n";
}

void check_tab(int P, vector<vector<int>>& tab, vector<int>& exp, vector<int>& log)
{
	for (int i = 1; i < P; ++i)
		for (int j = 1; j < P; ++j)
		{
			int r = exp[(log[i] + log[j]) % (P - 1)];

			if (r != tab[i][j])
				cout << "!";
		}
}



long long scott(int P, int L, int N, int M, vector<int>& A, vector<int>& B)
{
	//auto pd = prime_divisor(P - 1);
	//print(pd);

	int g = generator(P);

	//auto tab = mul_tab(P);
	vector<long long> exp(P), log(P);

	long long a = 1;
	exp[0] = 1;

	for (int x = 1; x < P; ++x)
	{
		a = (a * g) % P;
		exp[x] = a;
		log[a] = x;
	}

#if 0
	//check_tab(P, tab, exp, log);
	cout << "Prime " << P << "\n";
	cout << "Generator " << g << " : ";
	//check_generator(P, g);
	//print(exp);
	//print(log);
	cout << "\n";
	//print(tab);
#endif
	

	//vector<long long> ra(P), rb(P);
	unordered_map<int, long long> ra, rb;

	run(P, N, A, ra);
	run(P, M, B, rb);

	//cout << "check 1\n";

	long long ret = ra[0] * M + rb[0] * N;
	//long long ret = 0;

	vector<long long> ll(P + 1);

#if 1
	for (int i = 1; i < P; ++i)
	{
		if (ra[i] == 0)
			continue;

		for (int j = i + 1; j < P; ++j)
		{
			if (rb[j] == 0)
				continue;

			//cout << i << " " << j << "\n";

			int l = exp[(log[i] + log[j]) % (P - 1)];
			ll[l] += ra[i] * rb[j];
			ll[l] += ra[j] * rb[i];

			//if (l < L)
			{
				//ret += ra[i] * rb[j];
				//ret += ra[j] * rb[i];
			}
		}
	}

	for (int i = 1; i < P; ++i)
	{
		int l = exp[(log[i] + log[i]) % (P - 1)];
		ll[l] += ra[i] * rb[i];
	}

	for (int i = 0; i < L; ++i)
		ret += ll[i];
#endif



#if 0
	

	for (auto& a : ra)
	{
		if (a.first == 0)
		{
			//ret += a.second * M;
			continue;
		}
		
		for (auto& b : rb)
		{
			if (b.first == 0)
			{
				//ret += b.second * N;
				continue;
			}

			int l = exp[(log[a.first] + log[b.first]) % (P - 1)];
			ll[l] += a.second * b.second;
			
			//if (l < L)
			//	ret += a.second * b.second;
		}
	}

	for (int i = 0; i < L; ++i)
		ret += ll[i];

#endif

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int P, L;
		cin >> P >> L;

		int N;
		cin >> N;

		vector<int> A(5), B(5);

		for (auto& a : A)
			cin >> a;

		int M;
		cin >> M;

		for (auto& b : B)
			cin >> b;

		cout << "Case #" << t << ": ";
		cout << scott(P, L, N, M, A, B) << "\n";
	}

	return 0;
}

