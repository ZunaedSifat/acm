#include <bits/stdc++.h>
using namespace std;

// In order to use this, update the value of MAXN_SPARSE, MAX_LOG and the function in both the methods
// Then build_sparse_table by calling build_sparse_table method and get result by calling query_sparse_table

const int MAXN_SPARSE = 100010, MAX_LOG = 25;
int spase_table[MAXN_SPARSE][MAX_LOG], log_2[MAXN_SPARSE];

inline int sparse_combine(int a, int b) { return min(a, b); }           // change here.

// enter the array and the size to build sparse table for the array
void build_sparse_table(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++)
        spase_table[i][0] = arr[i];   
    
    for (int j = 1; (1<<j) < arr_size; j++) {
        for (int i = 0; (i+(1<<j)-1) < arr_size; i++) {
            spase_table[i][j] = sparse_combine(spase_table[i][j-1],
                        spase_table[i+(1<<(j-1))][j-1]);
        }
    }

    log_2[1] = 0;
    for (int i = 2; i < MAXN_SPARSE; i++)
        log_2[i] = log_2[i>>1]+1;
}

 // Returns sparse_combine of arr[left_idx...right_idx]
int query_sparse_table(int left_idx, int right_idx) {
    int j = log_2[right_idx-left_idx+1];
    return sparse_combine(spase_table[left_idx][j], spase_table[right_idx-(1<<j)+1][j]);
}