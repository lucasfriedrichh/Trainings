#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, N;
    while (cin >> C >> N) {
        vector<pair<int, int>> carros; // posição inicial e comprimento
        map<int, pair<int, int>> posicoes; // placa -> posição e comprimento
        int faturamento = 0;

        for (int i = 0; i < N; i++) {
            char acao;
            cin >> acao;

            if (acao == 'C') {
                int placa, comp;
                cin >> placa >> comp;

                int pos = 0;
                bool encontrou = false;

                for (auto &[inicio, tam] : carros) {
                    if (inicio - pos >= comp) {
                        encontrou = true;
                        break;
                    }
                    pos = inicio + tam;
                }

                if (!encontrou && C - pos >= comp)
                    encontrou = true;

                if (encontrou) {
                    carros.push_back({pos, comp});
                    posicoes[placa] = {pos, comp};
                    faturamento += 10;
                    sort(carros.begin(), carros.end());
                }
            } else {
                int placa;
                cin >> placa;
                auto [pos, tam] = posicoes[placa];

                carros.erase(remove(carros.begin(), carros.end(), make_pair(pos, tam)), carros.end());
                posicoes.erase(placa);
            }
        }

        cout << faturamento << "\n";
    }

    return 0;
}