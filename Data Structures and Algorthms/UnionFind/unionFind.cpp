#include <bits/stdc++.h>

using namespace std;

class UnionFind{
private:
    vector<int> pai, rank;
public:
    UnionFind(int N){
        rank.assign(N, 0);
        pai.assign(N, 0);
        for(int u = 0; u < N; u++){
            pai[u] = u;
        }
    }
    int findSet(int u){
        if(u == pai[u])
            return u;
        return pai[u] = findSet(pai[u]);
    }
    bool isSameSet(int u, int v){
        return findSet(u) == findSet(v);
    }
    void unionSet(int u, int v){
        if(isSameSet(u, v))
            return;
        int x = findSet(u);
        int y = findSet(v);
        if(rank[x] > rank[y])
            pai[y] = x;
        else{
            pai[x] = y;
            if(rank[x] == rank[y])
                rank[y]++;
        }
    }
};


int main(){

    return 0;
}