#include <bits/stdc++.h>

using namespace std;

using namespace std;

int main() {
    int n, k, instancia = 1;
    while (cin >> n >> k) {
        if (n == 0 && k == 0)
            break;
        vector<string> nomes(n);
        for (int i = 0; i < n; i++) {
            cin >> nomes[i];
        }
        
        for (int i = 0; i < n && k > 0; i++) {
            int posMenor = i;
        
            for (int j = i + 1; j < n && j <= i + k; j++) {
                if (nomes[j] < nomes[posMenor]) {
                    posMenor = j;
                }
            }
        
            while (posMenor > i) {
                swap(nomes[posMenor], nomes[posMenor - 1]);
                posMenor--;
                k--;
            }
        }
        
        cout << "Instancia " << instancia++ << "\n";
        
        for (int i = 0; i < n; i++) {
            cout << nomes[i] << " ";
        }
        cout << "\n\n";
    }
    return 0;
}