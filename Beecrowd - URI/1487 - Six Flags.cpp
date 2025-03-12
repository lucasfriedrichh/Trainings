#include <bits/stdc++.h>
using namespace std;

int main() {
    int instancia = 1;
    int N, T;

    while (cin >> N >> T, N || T) {
        vector<int> dp(T + 1, 0);

        for (int i = 0; i < N; i++) {
            int duracao, pontuacao;
            cin >> duracao >> pontuacao;

            for (int t = duracao; t <= T; t++)
                dp[t] = max(dp[t], dp[t - duracao] + pontuacao);
            
        }

        cout << "Instancia " << instancia++ << "\n";
        cout << dp[T] << "\n\n";
    }

    return 0;
}
