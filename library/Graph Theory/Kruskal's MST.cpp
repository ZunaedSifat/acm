struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector <Edges> kruskal(vector <Edge> &edges, int node_cnt) {
    sort(edges.begin(), edges.end());
    vector <Edges> mst;
    
    init(node_cnt); // see disjoint set union
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            mst.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    return mst;
}
