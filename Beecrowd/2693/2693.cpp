#include <bits/stdc++.h>

using namespace std;

struct aluno {
  string nome;
  string regiao;
  int dist;
};

bool compara(const aluno &a1, const aluno &a2) {
  return a1.dist < a2.dist 
        || (a1.dist == a2.dist && a1.regiao < a2.regiao)
        || (a1.dist == a2.dist && a1.regiao == a2.regiao && a1.nome < a2.nome);
}

int main() {
  int q;
  vector<aluno> vet;
  aluno aux;
  while (cin >> q) 
    while (q--) {
        cin >> aux.nome >> aux.regiao >> aux.dist;
        vet.push_back(aux);
    
    sort(vet.begin(), vet.end(), compara);
    for (auto a : vet) 
        cout << a.nome << endl;
    
    vet.clear();
  }
}