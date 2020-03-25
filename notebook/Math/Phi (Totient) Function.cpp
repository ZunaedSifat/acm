// Calculates phi(n) is O(sqrt(n)) time. No extra space is required
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1) result -= result / n;
    
    return result;
}

// phi(a*b) = phi(a) * phi(b) * phi(gcd(a, b)) / gcd(a, b)
// if a & b are relatively prime, phi(a*b) = phi(a) * phi(b)
// using this, we can calculate phi(1...n) using precalculated seive
// O(n log n) time and O(n) space
void get_phi(bool is_prime[], int phi[], int n) {
    phi[0] = 0; phi[1] = 1;
    for (int i = 2; i < n; i++) {
        if (is_prime[i]) phi = i - 1;
        else {
            int a = get_a_prime_divisor_of(i);
            int b = i / a, gcd = __gcd(a, b);
            phi[i] = phi[a] * phi[b] * phi[gcd] / gcd;
        }
    }
}