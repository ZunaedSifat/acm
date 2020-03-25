struct FenwickTree2D {
    vector<vector<int>> bit; int n, m;

    // creates a 2D fenwick tree of size n*m
    /**  It's 0-indexed, so be careful! **/
    FenwickTree2D(int n, int m) : bit(n, vector<int>(m)), n(n), m(m) {}

    // adds delta to point (x, y)
    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }

    // returns the sum of rectangle having (0, 0) as the bottom-left
    // and (x, y) as the top right co-ordinate
    int sum(int x, int y) {
        if (x < 0 or y < 0) return 0;

        int res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                res += bit[i][j];
        return res;
    }

    // returns the sum of rectangle having (x1, y1) as the bottom-left
    // and (x2, y2) as the top right co-ordinate.
    int rectangle_sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
    }

    // returns the value in point (x, y)
    int value_in(int x, int y) {
        return rectangle_sum(x, y, x, y);
    }
};
