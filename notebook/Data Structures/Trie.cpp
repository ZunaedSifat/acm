const int K = 2;
struct Vertex {
    int next[K], cnt = 0;
    Vertex() { fill(begin(next), end(next), -1); }
};

vector<Vertex> trie(1);
void add(string s) {
    int v = 0; trie[v].cnt++;

    for (char ch : s) {
        int c = ch - '0';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c]; trie[v].cnt++;
    }
}

void erase(string s) {
    int v = 0; trie[v].cnt--;
    for (char ch : s) {
        int c = ch - '0'; v = trie[v].next[c]; trie[v].cnt--;
    }
}

int go(string s) {
    int res = 0, v = 0;
    for (char ch : s) {
        int c = ch - '0', u = trie[v].next[!c];
        if (u != -1 and trie[u].cnt) {
            v = u; res += res + 1;
        } else {
            v = trie[v].next[c]; res += res;
        }
    }

    return res;
}