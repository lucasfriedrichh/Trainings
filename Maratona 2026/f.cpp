#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long p = 1;

    while (p * 3 <= N) {
        p *= 3;
    }

    long long ans;

    if (N <= 2 * p) {
        ans = N + p;
    } else {
        ans = 3 * (N - p);
    }

    cout << ans << '\n';

    return 0;
}