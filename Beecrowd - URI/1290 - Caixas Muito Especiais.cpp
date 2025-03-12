#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<int> item(3);
        cin >> item[0] >> item[1] >> item[2];
        sort(item.begin(), item.end());

        map<vector<int>, int> estoque;

        for (int i = 0; i < M; i++) {
            vector<int> caixa(3);
            cin >> caixa[0] >> caixa[1] >> caixa[2];
            sort(caixa.begin(), caixa.end());

            // Checa se a caixa pode acomodar o item
            if (caixa[0] >= item[0] && caixa[1] >= item[1] && caixa[2] >= item[2]) {
                estoque[caixa]++;
            }
        }

        int menor_sobra = INT_MAX;
        bool possivel = false;

        for (auto &[caixa, quantidade] : estoque) {
            if (quantidade >= N) {
                int sobra = (caixa[0] * caixa[1] * caixa[2]) - (item[0] * item[1] * item[2]);
                if (sobra < menor_sobra) {
                    menor_sobra = sobra;
                    possivel = true;
                }
            }
        }

        if (possivel) {
            cout << menor_sobra << "\n";
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}
