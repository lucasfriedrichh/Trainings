#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lg;
vector<bool> vis;

void dfs(int u){
    vis[u] = true;
    cout << u << " ";
    for (auto x : lg[u]){
        if(!vis[x])
            dfs(x);
    }
}

int main(){
    lg.assign(5,vector<int>());
    vis.assign(5, false);

    lg[0].push_back(1);
    lg[0].push_back(3);
    lg[1].push_back(0);
    lg[1].push_back(3);
    lg[2].push_back(3);
    lg[3].push_back(2);
    
    dfs(0);

    return 0;
}