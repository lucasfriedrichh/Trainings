#include <bits/stdc++.h>
using namespace std;


map<int, vector<int>> LG;
int V,E;
map<int, bool> vis;
vector<int> cidades;

void dfs(int u){
    vis[u]=true;
    for (auto cidade : LG[u])
        if(!vis[cidade])
            dfs(cidade);
}

int main(){
    int n, cases = 0;
    cin >> n;   
    

    while (n--){
        int v, u, ans = -1;
        cases++;
        cin >> V >> E;

        if(V == 1){
            cout << "Caso #" << cases << ": " << "a promessa foi cumprida\n";
            continue;
        }
        else if(!E){
            cout << "Caso #" << cases << ": " << "ainda falta(m) " << V - 1 << " estrada(s)\n";
            continue;
        }


        for (int i = 0; i < E; i++){
            cin >> u >> v;
            LG[u].push_back(v);
            LG[v].push_back(u);
            vis[i+1] = false;
        }

        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        
        if(!ans){
            cout << "Caso # " << cases << ": a promessa foi cumprida" << endl;
        }else
            cout << "Caso # " << cases << ": ainda falta(m) "<< ans << " estrada(s)" << endl;
    }
}