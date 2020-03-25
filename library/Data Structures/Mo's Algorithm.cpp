#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> OrderedSet;
OrderedSet ost;

// make BLOCK = sqrt(MAXN)
const int MAXN = 100010, BLOCK = 300;
int result[MAXN], arr[MAXN];

struct Query {
    int l, r, k, id;
    bool operator <(const Query &rhs) const {
		if (l / BLOCK != rhs.l / BLOCK) make_pair(l, r) < make_pair(rhs.l, rhs.r);
        return (l / BLOCK & 1) ? (r < rhs.r) : (r > rhs.r);
	}
} query[MAXN];

void mo_insert (int idx) { ost.insert(arr[idx]); }
void mo_remove (int idx) { ost.erase(arr[idx]); }
int mo_query(int k) { return *ost.find_by_order(k-1); }

void mo_process(int q) {
    sort (query, query+q);
    int l = 1, r = 0; // l = 0, r = -1 if the ds is 0-indexed
    for (int i = 0 ; i < q ; i++) {
        int ql = query[i].l, qr = query[i].r, id = query[i].id;
        
        // The order is important -____-
        while (l > ql) mo_insert(--l);
        while (r < qr) mo_insert(++r);
        while (l < ql) mo_remove(l++);
        while (r > qr) mo_remove(r--);

        result[id] = mo_query(query[i].k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 0 ; i < q ; i++) {
        cin >> query[i].l >> query[i].r >> query[i].k;
        query[i].id = i;
    }

    mo_process(q);
    for (int i = 0; i < q; i++)
        cout << result[i] << '\n';

    return 0;
}