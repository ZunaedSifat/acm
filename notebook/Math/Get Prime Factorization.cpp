// returns a vector of pairs (factor, power)
vector <pair <int, int>> get_prime_factorization(ll n) {
    auto primes = seive((int) sqrt(n));
    vector <pair <int, int>> prime_factors;

    for (auto p : primes) {
        if (n == 1 or p*p > n) break;
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) n /= p, cnt++;
            prime_factors.push_back({p, cnt});
        }
    }
    if (n != 1) prime_factors.push_back({n, 1});
    
    return prime_factors;
}