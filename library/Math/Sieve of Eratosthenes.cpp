// performs sieve of erathoneus on the given is_prime array
void sieve(bool is_prime[], int n) {
    fill(is_prime, is_prime+n, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*i <= n; i++)
        if (is_prime[i]) for (int j = i*i; j <= n; j+=i)
            is_prime[j] = false;
}