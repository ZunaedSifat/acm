// returns number of factors of n
ll number_of_factors(ll n) {
    ll ans = 1;
    auto prime_factors = get_prime_factorization(n);
    for (auto item : prime_factors)
        ans *= (item.second + 1);

    return ans;
}

// Add the formula from https://cp-algorithms.com/algebra/divisors.html