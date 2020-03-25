// sovles https://www.spoj.com/problems/QTREE2/en/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1<<30;

typedef vector <vector<pair <int, int>>> Graph;
Graph graph;

#define ver first
#define cost second
#define debug(x) cerr << #x << ": " << x << endl;

struct LowestCommonAncestor {
    int l, timer;
    vector <vector <int>> up;
    vector <int> tin, tout, dist, costs;

    LowestCommonAncestor(int root) {
        preprocess(root);

        dist.resize(graph.size());
        costs.resize(graph.size());
        calc_dist(root);
    }

    void calc_dist(int vertex, int parent = -1, int cur_dist = 0, int cur_cost = 0) {
        dist[vertex] = cur_dist;
        costs[vertex] = cur_cost;
        for (auto child: graph[vertex])
            if (child.ver != parent) 
                calc_dist(child.ver, vertex, cur_dist+1, cur_cost + child.cost);
    }

    int distance_between(int l, int r) {
        return dist[l] + dist[r] - 2*dist[lca(l, r)];
    }

    int cost_between(int l, int r) {
        return costs[l] + costs[r] - 2*costs[lca(l, r)];
    }

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;

        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
        for (auto u : graph[v]) {
            if (u.ver != p) dfs(u.ver, v);
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

    int t;
    cin >> t;

    while (t--)
    {
        int n, u, v, q, r;
        cin >> n;

        graph.clear();
        graph.resize(n+1);
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v >> r;
            graph[u].push_back({v, r});
            graph[v].push_back({u, r});
        }

        LowestCommonAncestor lca(1);

        string cmd;
        while (cin >> cmd, cmd != "DONE") {
            if (cmd == "DIST") {
                cin >> u >> v;
                cout << lca.cost_between(u, v) << "\n";
            } else {
                cin >> u >> v >> r;
                int l = lca.lca(u, v);
                
                r--;
                if (lca.dist[u] - lca.dist[l] < r) {
                    r = lca.distance_between(u, v) - r;
                    u = v;
                }

                int res = u;
                for (int i = lca.l-1; i >= 0; i--)
                    if (r & (1<<i)) res = lca.up[res][i];
                cout << res << "\n";
            }
        }

        cout << "\n";

    }

    return 0;
}