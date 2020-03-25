// solves https://www.codechef.com/problems/TALCA

#include <bits/stdc++.h>
using namespace std;

const int inf = 1<<30;

typedef vector <vector<int>> Graph;
Graph graph;

struct LowestCommonAncestor {
    int l, timer;
    Graph up;
    vector <int> tin, tout, dist;

    LowestCommonAncestor(int root) {
        preprocess(root);

        dist.resize(graph.size());
        calc_dist(root);
    }

    void calc_dist(int vertex, int parent = -1, int cur_dist = 0) {
        dist[vertex] = cur_dist;
        for (auto child: graph[vertex])
            if (child != parent) calc_dist(child, vertex, cur_dist+1);
    }

    int distance_between(int l, int r) {
        return dist[l] + dist[r] - 2*dist[lca(l, r)];
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

    int query(int r, int u, int v) {
        int possible[] = {r, u, v, lca(r, u), lca(u, v), lca(v, r)};
        int min_dist = inf, res = -1;

        for (int i = 0; i < 6; i++) {
            int cur = possible[i];
            int cur_dist = distance_between(cur, r) + distance_between(cur, u) + distance_between(cur, v);
            if (cur_dist < min_dist)
                min_dist = cur_dist, res = cur;
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, u, v, q, r;
    cin >> n;

    graph.resize(n+1);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    LowestCommonAncestor lca(1);
    
    cin >> q;
    while (q--)
    {
        cin >> r >> u >> v;
        cout << lca.query(r, u, v) << "\n";
    }    

    return 0;
}