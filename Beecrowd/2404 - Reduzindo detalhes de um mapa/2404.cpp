#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

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

int kruskal(int N, vector<edge> &edgeList){
    UnionFind uf(N+1);
    int ans = 0;

    for(auto e : edgeList){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    return ans;
}

int main(){
    int N, E;
    int u, v, w;
    vector<edge> edgeList;
    cin >> N >> E;

    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        edgeList.push_back({w, {v, u}});
        edgeList.push_back({w, {u, v}});
    }
    sort(edgeList.begin(), edgeList.end());
    cout <<  kruskal(N, edgeList) << endl;

    return 0;
}