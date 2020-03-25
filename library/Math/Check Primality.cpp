// checks whether a number is prime in O(sqrt(n)) time
// without any extra space or precalculation
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i*i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}