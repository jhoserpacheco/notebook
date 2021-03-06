La función Rho de Pollard calcula un divisor no trivial de n. IMPORTANTE: Deben agregarse Modular Multiplication y Greatest common divisor para long long.

long long pollardRho(long long n) {
    long long i = 0, k = 2, x = 3, y = 3, d;
    while (true) {
        x = (modmul(x, x, n) + n - 1) % n;
        d = gcd(abs(y - x), n);
        if (d != 1 && d != n) return d;
        if (++i == k) y = x, k <<= 1;
    }
}
