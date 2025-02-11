#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> LG;
map<int, bool> vis;
int V,E;

void dfs(int u){
    vis[u]=true;
    for (auto cidade : LG[u])
        if(!vis[cidade])
            dfs(cidade);
}


int main(){

    


    return 0;

}