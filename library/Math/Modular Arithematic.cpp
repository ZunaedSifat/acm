int bigmod(int num, int exp, int mod) {
    if (exp == 0) return 1;
    int ans = bigmod(num, exp/2, mod);
    ans = ans * ans % mod;
    if (exp & 1) ans = ans * num % mod;
    return ans;
}

// Todo: Understand & add using extended Euclid

// Only works for prime numbers
int mod_inverse(int num) {
    return bigmod(num, mod-2, mod);
}

// Finding the modular inverse for every number modulo m
void mod_inverse(int n, int mod) {
    inv[1] = 1;
    for(int i = 2; i < n; ++i)
        inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
}