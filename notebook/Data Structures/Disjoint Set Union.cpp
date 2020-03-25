// Disjoint Set Union (DSU) space O(n), query time: ammortized O(1)

const int maxn = 500010;
int parent[maxn], set_size[maxn];

int find_set(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (set_size[a] < set_size[b])
            swap(a, b);
        parent[b] = a;
        set_size[a] += set_size[b];
    }
}

// call this method before calling any other
void init(int n) { // both 0 & 1-indexed
    for (int i = 0; i <= n; i++) {
        parent[i] = i; set_size[i] = 1;
    }
}