std::vector<int> minp, primes, f;

void sieve(int n) {
    minp.assign(n + 1, 0);
    f.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            f[i] = 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                f[i * p] = f[i];
                break;
            }
            f[i * p] = f[i] + 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }
}
