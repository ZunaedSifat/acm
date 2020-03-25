// Sparse table is a data structure that allows us to calculate min, max, gcd in O(1) time
// It takes O(n log n) time and space for precalculations
// In order to use this, update the value of maxn, max_log and the function in both the methods
// Then preprocess by calling preprocess method and get result by calling query

const int maxn = 100010, max_log = 25;
int tree[maxn][max_log], log_2[maxn];

// for 1 based, call with n+1
void preprocess(int arr[], int n) {    
    // Initialize M for the intervals with length 1
    for (int i = 0; i < n; i++)
        tree[i][0] = arr[i];   
    
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 0; (i+(1<<j)-1) < n; i++) {
            tree[i][j] = __gcd(tree[i][j-1], tree[i+(1<<(j-1))][j-1]);
        }
    }

    log_2[1] = 0;
    for (int i = 2; i < maxn; i++)
        log_2[i] = log_2[i>>1]+1;
}

int query(int L, int R) { // Returns gcd of arr[L..R]
    int j = log_2[R-L+1];   // For [2,10], j = 3, we compare tree[0][3] and tree[3][3]
    return __gcd(tree[L][j], tree[R-(1<<j)+1][j]);
}