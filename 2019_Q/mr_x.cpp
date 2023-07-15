/*
to be continued.
*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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

struct node
{
	char val;
	struct node* left;
	struct node* right;

	node(char c = '-') : val(c) {} 
};

void to_string(node* root, string& s)
{
	if (! root)
		return ;

	if (! root->left && ! root->right)
	{
		s.push_back(root->val);
	}
	else
	{
		s.push_back('(');
		to_string(root->left, s);
		s.push_back(root->val);
		to_string(root->right, s);
		s.push_back(')');
	}
}

char dfs(node* root)
{
	if (! root)
		return '-';

	if (! root->left && ! root->right)
	{
		//if (root->val == 'x' || root->val == 'X')
		//	root->val = '0';
		
		return root->val;
	}
	else
	{
		char l = dfs(root->left);
		char r = dfs(root->right);

		if (l == r)
		{
			if (l == 'x' || l == 'X')
			{
				root->val = '^';
				return '0';
			}
			else
			{
				if (root->val == '^')
					return '0';
				else
					return l;
			}
		}
		else
		{
			if ((l == 'x' && r == 'X') || (l == 'X' && r == 'x'))
			{
				root->val = '&';
				return '0';
			}
			else if (l == 'x' || l == 'X')
			{
				if (r == '0')
				{
					root->val = '&';
					return '0';
				}
				else
				{
					root->val = '|';
					return '1';
				}
			}
			else if (r == 'x' || r == 'X')
			{
				if (l == '0')
				{
					root->val = '&';
					return '0';
				}
				else
				{
					root->val = '|';
					return '1';
				}
			}
			else
			{
				if (root->val =='|')
					return '1';
				else
					return '0';
			}
		}
	}
}

int mr_x(string& E)
{
	node* root = new node();
	node* ptr = root;
	stack<node*> sta;

	for (char c : E)
	{
		if (c == '(')
		{
			sta.push(ptr);

			if (! ptr->left)
				ptr = ptr->left = new node();
			else
				ptr = ptr->right = new node();
		}
		else if (c == ')')
		{
			ptr = sta.top();
			sta.pop();
		}
		else if (c == 'x' || c == 'X' || c == '0' || c == '1')
		{
			if (! ptr->left)
				ptr->left = new node(c);
			else
				ptr->right = new node(c);
		}
		else
		{
			ptr->val = c;
		}
	}

	cout << "\n";
	cout << E << "\n";
	string s1 = "";
	to_string(root->left, s1);
	cout << s1 << "\n";

	return 0;
	
	#if 0
	dfs(root->left);
	string s2 = "";
	to_string(root->left, s2);
	cout << s2 << "\n";

	if (E.size() == 1)
	{
		if (E[0] == 'x' || E[0] == 'X')
			return 1;
		else
			return 0;
	}

	int cnt = 0;

	for (int i = 0; i < E.size(); ++i)
		cnt += E[i] != s2[i];
	

	return cnt;
	#endif
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string E;
		cin >> E;

		cout << "Case #" << t << ": ";
		cout << mr_x(E) << "\n";
	}

	return 0;
}

