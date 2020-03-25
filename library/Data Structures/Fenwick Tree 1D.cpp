struct FenwickTree {
    vector<int> bit; int n;

    FenwickTree(int n) : n(n) {
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) { // returns sum[0...r]
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) { // returns sum[l...r]
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    // This is a neat application of Fenwick tree.
    void lower_bound_of_sum(int sum) {
        int lo = 1, hi = n, ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (tree.sum(mid-1) <= sum)
                ans = mid, lo = mid+1;
            else
                hi = mid-1;
        }

        return ans;
    }
};
