#include <bits/stdc++.h>
using namespace std;


string to_bin(int num)
{
    string ans;
    for (int i = 30; i >= 0; i--)
        ans.push_back((num & (1<<i)) ? '0' : '1');
    return ans;
}

const int K = 2;
struct Vertex {
    int next[K];
    int cnt = 0;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};
vector<Vertex> trie(1);

void add_string(int num)
{
    string s = to_bin(num);
    int v = 0;
    trie[v].cnt++;

    for (char ch : s) {
        int c = ch - '0';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
        trie[v].cnt++;
    }
}

void erase_string(int num)
{
    string s = to_bin(num);
    int v = 0;
    trie[v].cnt--;

    for (char ch : s) {
        int c = ch - '0';
        v = trie[v].next[c];
        trie[v].cnt--;
    }
}
int get_xor(int num)
{
    string s = to_bin(num);
    int res = 0, v = 0;
    for (char ch : s)
    {
        int c = ch - '0', u = trie[v].next[!c];
        if (u != -1 and trie[u].cnt) {
            v = u;
            res += res + 1;
        } else {
            v = trie[v].next[c];
            res += res;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q, val;
    char ch;

    cin >> q;

    add_string(0);
    while (q--)
    {
        cin >> ch >> val;
        if (ch == '+') add_string(val);
        else if (ch == '-') erase_string(val);
        else cout << get_xor(val) << endl;
    }
}
