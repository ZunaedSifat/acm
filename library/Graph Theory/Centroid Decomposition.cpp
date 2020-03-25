#include <bits/stdc++.h>
using namespace std;

typedef vector <vector<int>> Graph;
Graph graph;

// To use this call the constructor with graph and root.
// access the parent in the decomposed tree by calling obj.parent[u]
struct CentroidDecomposition {
    vector <bool> done;
    vector <int> parent, children_cnt;
    
    CentroidDecomposition(int root) {
        done.resize(graph.size());
        parent.resize(graph.size(), -1);
        children_cnt.resize(graph.size());

        dfs_decompose(root);
        // done.clear();
        // children_cnt.clear();
    }

    void dfs_size(int u, int par) {
        children_cnt[u] = 1;
        for (int v: graph[u]) {
            if (done[v] or v == par) continue;
            dfs_size(v, u);
            children_cnt[u] += children_cnt[v];
        }
    }

    int find_centroid(int u, int par, int sz) {
        for (int v: graph[u]) {
            if (!done[v] and v != par and children_cnt[v] > sz) {
                return find_centroid(v,u,sz);
            }
        }

        return u;
    }

    int dfs_decompose(int u) {
        dfs_size(u, -1);
        int centroid = find_centroid(u, -1, children_cnt[u]/2);

        done[centroid] = 1;
        for (int v : graph[centroid]) {
            if (!done[v]) {
                parent[dfs_decompose(v)] = centroid;
            }
        }

        return centroid;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, u, v;
    cin >> n;

    graph.resize(n+1); // 1-indexed
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    CentroidDecomposition cd(1);
    for (int i = 1; i <= n; i++)
        cout << "parent of " << i << " in the decomposed tree is " << cd.parent[i] << endl;
}
