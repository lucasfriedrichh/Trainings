#include <bits/stdc++.h>
using namespace std;

const int lim = 17; 
long double dist[lim][lim]; 

long double dp[lim][1 << lim];
int limMask = (1 << lim) - 1; 
long double solve(int atual, int mask, int n) {
    if (dp[atual][mask] != 0) return dp[atual][mask];
    if (mask == (1 << n) - 1) {
        return dp[atual][mask] = 0; 
    }

    long double res = 1e13; 
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
        long double aux = solve(i, mask | (1 << i), n);
        if (mask) aux += dist[atual][i];
            res = min(res, aux);
        }
    }
    return dp[atual][mask] = res;
}