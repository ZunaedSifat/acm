#include <bits/stdc++.h>
using namespace std;

typedef vector <vector<int>> Graph;
Graph graph;

struct LowestCommonAncestor {
    int l, timer;
    Graph up;
    vector <int> tin, tout;

    LowestCommonAncestor(int root) {
        preprocess(root);
    }

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;

        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
        for (int u : graph[v]) {
            if (u != p) dfs(u, v);
        }

        tout[v] = ++timer;
    }

    void preprocess(int root) {
        tin.resize(graph.size());
        tout.resize(graph.size());

        timer = 0;
        l = ceil(log2(graph.size()));
        up.assign(graph.size(), vector<int>(l + 1));
        
        dfs(root, root);
    }

    bool is_ancestor(int u, int v) const {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) const {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;

        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }

        return up[u][0];
    }
};