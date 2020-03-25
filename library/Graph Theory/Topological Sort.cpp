vector<int> graph[maxn], ans;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : graph[v])
        if (!visited[u]) dfs(u);

    ans.push_back(v);
}
 
// calling this function with save the toplogical order in the answer vector
void topological_sort(int n) { // n = vertex-count
    visited.assign(n, false);
    ans.clear();

    for (int i = 0; i < n; ++i)
        if (!visited[i]) dfs(i);
    reverse(ans.begin(), ans.end());
}