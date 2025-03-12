// TLE não sei faze

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6;

long long fast_exp(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    long long N, K, L;

    while (cin >> N >> K >> L) {
        long long formas = 0;
        long long max_bus = N / 10;
        
        long long K_exp = fast_exp(K, N / 5);
        long long L_exp = 1;

        for (long long bus = 0; bus <= max_bus; bus++) {
            long long micro = (N - bus * 10) / 5;
            if (bus > 0) {
                K_exp = (K_exp * fast_exp(K, MOD - 2)) % MOD;
                L_exp = (L_exp * L) % MOD;
            }
            formas = (formas + (L_exp * K_exp) % MOD) % MOD;
        }

        cout << setw(6) << setfill('0') << formas << "\n";
    }

    return 0;
}
