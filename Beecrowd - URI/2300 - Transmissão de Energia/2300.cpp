#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> LG;
int V,E;
map<int, bool> vis;

void dfs(int u) noexcept{
    vis[u] = true;
    for(const auto &v : LG[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    int u, v;
    int teste = 0;
    
    while(cin >> V >> E && V && E){
        bool ans = false;
        teste += 1;
        for (int i = 0; i < E; i++){
            cin >> u >> v;
            LG[u].push_back(v);
            LG[v].push_back(u);
        }

        for(int i = 1; i <= V; i++)
            vis[i] = false;
        
        dfs(1);
        
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                dfs(i);
                ans= true;
            }
        }

        if(ans)
            cout << "Teste " << teste << endl << "falha" << endl << endl;
        else 
            cout << "Teste " << teste << endl << "normal" << endl << endl;
        
        LG.clear();
    }

    return 0;
}