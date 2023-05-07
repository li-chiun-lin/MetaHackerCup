/*
TLE
*/

#include <algorithm>
//#include <bit>
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
#include <unordered_map>
#include <vector>

using namespace std;

struct trie
{
    int sub;
    struct trie* next[26];
};

void merge(trie* dst, trie* src)
{
    for (int i = 0; i < 26; ++i)
    {
        if (src->next[i])
        {
            if (! dst->next[i])
            {
                dst->next[i] = new trie();
                ++ (dst->sub);
            }

            merge(dst->next[i], src->next[i]);
        }
    }
}

void dispose(trie* obj)
{
    for (int i = 0; i < 26; ++i)
        if (obj->next[i])
            dispose(obj->next[i]);

    free(obj);
}

long long cnt(trie* obj)
{
    long long c = obj->sub;

    for (int i = 0; i < 26; ++i)
        if (obj->next[i])
            c += cnt(obj->next[i]);

    return c;
}

long long cnt(trie* t1, trie* t2, trie* t3)
{
    if (! t1 && ! t2 && ! t3)
        return 0;

    long long c = 0;

    for (int i = 0; i < 26; ++i)
    {
        if (t1 && t1->next[i])
            c += cnt(t1 ? t1->next[i] : NULL, t2 ? t2->next[i] : NULL, t3 ? t3->next[i] : NULL);
        else if (t2 && t2->next[i])
            c += cnt(t1 ? t1->next[i] : NULL, t2 ? t2->next[i] : NULL, t3 ? t3->next[i] : NULL);
        else if (t3 && t3->next[i])
            c += cnt(t1 ? t1->next[i] : NULL, t2 ? t2->next[i] : NULL, t3 ? t3->next[i] : NULL);
    }

    return c + 1;
}

void print(trie* obj)
{
    if (! obj)
        return ;

    cout << "sub : " << obj->sub << "\n";
    
    for (int i = 0; i < 26; ++i)
        if (obj->next[i])
            cout << (char)('a' + i) << " ";
    cout << "\n";

    for (int i = 0; i < 26; ++i)
        if (obj->next[i])
            print(obj->next[i]);
}

void print(vector<trie*>& node)
{
    for (auto& n : node)
        cout << n->sub << "\n";
    cout << "\n";
}

void print(vector<string>& str)
{
    for (auto& s : str)
        cout << "_" << s << "_" << "\n";
    cout << "\n";
}

void print(set<string>& str)
{
    for (auto& s : str)
        cout << "_" << s << "_" << "\n";
    cout << "\n";
}

void dfs(trie* obj, string& str, vector<string>& ret)
{
    if (! obj)
        return ;

    ret.push_back(str);

    for (int i = 0; i < 26; ++i)
    {
        if (obj->next[i])
        {
            str.push_back(i + 'a');
            dfs(obj->next[i], str, ret);
            str.pop_back();
        }
    }
}

void dfs(trie* obj, string& str, set<string>& ret)
{
    if (! obj)
        return ;

    ret.insert(str);

    for (int i = 0; i < 26; ++i)
    {
        if (obj->next[i])
        {
            str.push_back(i + 'a');
            dfs(obj->next[i], str, ret);
            str.pop_back();
        }
    }
}

vector<string> allstr(trie* obj)
{
    vector<string> ret;
    string str = "";

    dfs(obj, str, ret);

    print(ret);

    return ret;
}

void allstr(trie* obj, set<string>& ss)
{
    if (! obj)
        return ;

    string str = "";

    dfs(obj, str, ss);
}



long long thirdtrie(vector<trie*>& obj)
{
    long long ret = 0;
    int n = obj.size();

    vector<set<string>> sss(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                auto c = cnt(obj[i], obj[j], obj[k]);
                //cout << i << " " << j << " " << k << " - " << c << "\n";
                ret += c;
            }
        }
    }

    return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int N;
        cin >> N;

        vector<trie*> obj(N);

        for (int i = 0; i < N; ++i)
        {
            obj[i] = new trie();
            int M;
            cin >> M;

            vector<trie*> node(M);

            for (auto& n : node)
                n = new trie();

            int p;
            char c;

            for (int i = 1; i < M; ++i)
            {
                cin >> p >> c;

                node[p - 1]->next[c - 'a'] = node[i];
                ++ (node[p - 1]->sub);
            }

            obj[i] = node[0];
        }

		cout << "Case #" << t << ": ";
		cout << thirdtrie(obj) << "\n";
	}

	return 0;
}

