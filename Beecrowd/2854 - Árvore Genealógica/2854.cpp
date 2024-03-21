#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> LG;
int V,E;
set<string> pessoas;
map<string, bool> vis;


void dfs(string u){
    vis[u] = true;
    for (auto e : LG[u]){
        if(!vis[e]){
            dfs(e);
        }
    }
}

int main(){
    cin >> V >> E;
    string p1,_,p2;
    int ans = 0;
    
    for (int i = 0; i < E; i++){
        cin >> p1 >> _ >> p2;
        LG[p1].push_back(p2);
        LG[p2].push_back(p1);
        pessoas.insert(p1);
        pessoas.insert(p2);
        vis[p1] = false;
        vis[p2] = false;
    }

    for (auto pessoa : pessoas){
        if (!vis[pessoa]){
            dfs(pessoa);
            ans ++;
        }
    }
    
    cout << ans << endl;
    return 0;
}