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

class Node
{
public:
    vector<Node*> child;
    Node() : child(2){};
};

void print(vector<string>& v, int N1)
{
	for (int i = 0; i < N1; ++i)
		cout << v[i] << "\n";
}

void dfs(Node* root, string& word, vector<string>& code, string& C1)
{
    if (! root)
        return ;

    if (root->child[0] == NULL && root->child[1] == NULL)
    {
        if (word != C1)
            code.push_back(word);
        return ;
    }

    word.push_back(' ');

    if (root->child[0])
    {
        word.back() = '.';
        dfs(root->child[0], word, code, C1);
    }

    if (root->child[1])
    {
        word.back() = '-';
        dfs(root->child[1], word, code, C1);
    }

    word.pop_back();
}

void secondmeaning(int N, string& C1)
{
    Node* root = new Node();
    Node* ptr = root;
    int leaf = 1;

    for (char c : C1)
    {
        ptr->child[0] = new Node();
        ptr->child[1] = new Node();
        ++ leaf;

        if (c == '.')
        {
            ptr = ptr->child[0];
        }
        else
        {
            ptr = ptr->child[1];
        }
    }

    Node* code1 = ptr;

    queue<Node*> que;
    que.push(root);

    while (leaf < N)
    {
        auto u = que.front();
        que.pop();

        if (u->child[0] == NULL && u->child[1] == NULL && u != code1)
        {
            u->child[0] = new Node();
            u->child[1] = new Node();
            ++ leaf;
        }
        
        if (u->child[0])
            que.push(u->child[0]);

        if (u->child[1])
            que.push(u->child[1]);
    }

    vector<string> code;
    string word = "";

    dfs(root, word, code, C1);

    sort(begin(code), end(code));

    print(code, N - 1);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N;
        string C1;
        cin >> N >> C1;

		cout << "Case #" << t << ": \n";
		secondmeaning(N, C1);
	}

	return 0;
}

