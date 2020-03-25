#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 300010;
const ll NOT_FOUND = 0;

ll arr[MAXN], tree[4*MAXN];


ll combine(ll a, ll b) { return a + b; }
int left(int n) { return 2*n; }
int right(int n) { return 2*n + 1; }
int mid(int b, int e) { return (b+e)/2; }

void build_segtree(int n, int b, int e) {
    if (b == e) {
        tree[n] = arr[b];
    } else {
        build_segtree(left(n), b, mid(b, e));
        build_segtree(right(n), mid(b, e)+1, e);
        tree[n] = combine(tree[left(n)], tree[right(n)]);
    }
}


void update_segtree(int n, int b, int e, int l, int r, int new_val) {
    if (r < b or e < l) return;
    else if (l <= b and e <= r) {
        tree[n] = new_val;
    } else {
        update_segtree(left(n), b, mid(b, e), l, r, new_val);
        update_segtree(right(n), mid(b, e)+1, e, l, r, new_val);
        tree[n] = combine(tree[left(n)], tree[right(n)]);
    }
}


ll query_segtree(int n, int b, int e, int l, int r) {
    if (r < b or e < l) return NOT_FOUND;
    else if (l <= b and e <= r) return tree[n];
    else {
        return combine(query_segtree(left(n), b, mid(b, e), l, r),
                    query_segtree(right(n), mid(b, e)+1, e, l, r));
    }
}