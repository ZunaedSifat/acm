const int maxn = 100010;        // 1. change here
int a[maxn], tree[4*maxn], lazy[4*maxn];

#define NOT_FOUND 0             // 2. for query merging
#define INIT_LAZY_VALUE 0       // 3. set initial lazy value
#define combine(l, r) (l+r)     // 4. combine here.

int left(int n) { return 2*n; }
int right(int n) { return 2*n + 1; }

// call this with build(1, 1, n) to preprocess
void build(int n, int b, int e) {
    if (b == e) {
        tree[n] = a[b];
        lazy[n] = INIT_LAZY_VALUE;
    } else {
        int mid = (b+e)/2;
        build(left(n), b, mid);
        build(right(n), mid+1, e);
        tree[n] = combine(tree[left(n)], tree[right(n)]);
        lazy[n] = INIT_LAZY_VALUE;
    }
}

// Push lazy down and merge lazy
void propagate(int n, int b, int e) {
    tree[n] += (e-b+1) * lazy[n];
    if (b != e) {
        lazy[left(n)] += lazy[n];          // 5. merge lazy
        lazy[right(n)] += lazy[n];         // 5. merge lazy
    }

    lazy[n] = 0;                           // 6. clear lazy
}

void update(int n, int b, int e, int l, int r, int x) {
    propagate(n, b, e);
    if (r < b or e < l) return;
    else if (l <= b and e <= r) {
        lazy[n] += x;                      // 5. merge lazy
        propagate(n, b, e);
    } else {
        int mid = (b+e)/2;
        update(left(n), b, mid, l, r, x);
        update(right(n), mid+1, e, l, r, x);
        tree[n] = combine(tree[left(n)], tree[right(n)]);
    }
}

int query(int u, int b, int e, int l, int r) {
    propagate(u, b, e);
    if (r < b or e < l) return NOT_FOUND;
    else if (l <= b and e <= r) return tree[u];
    else {
        int mid = (b+e)/2;
        return combine(query(left(u), b, mid, l, r),
                    query(right(u), mid+1, e, l, r));
    }
}