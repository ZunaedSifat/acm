#include <bits/stdc++.h>
using namespace std;

// change these values
const int MAXN = 100010;
const int NOT_FOUND = 0;
const int INIT_LAZY_VALUE = 0;
const int LAZY_CLEAR_VALUE = 0;
int combine(int a, int b) { return a + b; }


int arr[MAXN], tree[4*MAXN], lazy[4*MAXN];

int left(int n) { return 2*n; }
int right(int n) { return 2*n + 1; }
int mid(int b, int e) { return (b+e)/2; }


void build_segtree(int n, int b, int e) {
    if (b == e) {
        tree[n] = arr[b];
        lazy[n] = INIT_LAZY_VALUE;
    } else {
        build_segtree(left(n), b, mid(b, e));
        build_segtree(right(n), mid(b, e)+1, e);
        tree[n] = combine(tree[left(n)], tree[right(n)]);
        lazy[n] = INIT_LAZY_VALUE;
    }
}


void propagate_lazy(int n, int b, int e) {
    tree[n] += (e-b+1) * lazy[n];           // change here
    if (b != e) {
        lazy[left(n)] = combine(lazy[left(n)], lazy[n]);
        lazy[right(n)] = combine(lazy[right(n)], lazy[n]);
    }

    lazy[n] = LAZY_CLEAR_VALUE;
}


void update_segtree(int n, int b, int e, int l, int r, int x) {
    propagate_lazy(n, b, e);
    if (r < b or e < l) return;
    else if (l <= b and e <= r) {
        lazy[n] = combine(x, lazy[n]);
        propagate_lazy(n, b, e);
    } else {
        update_segtree(left(n), b, mid(b, e), l, r, x);
        update_segtree(right(n), mid(b, e)+1, e, l, r, x);
        tree[n] = combine(tree[left(n)], tree[right(n)]);
    }
}


int query_segtree(int n, int b, int e, int l, int r) {
    propagate_lazy(n, b, e);
    if (r < b or e < l) return NOT_FOUND;
    else if (l <= b and e <= r) return tree[n];
    else {
        return combine(query_segtree(left(n), b, mid(b, e), l, r),
                    query_segtree(right(n), mid(b, e)+1, e, l, r));
    }
}


int main() {

}