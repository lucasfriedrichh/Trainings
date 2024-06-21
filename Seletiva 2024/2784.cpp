#include <bits/stdc++.h>
using namespace std;

#define INF ((int)1e9)

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, M;
vector<int> dist;
vector<vii> LG;

void dijkstra(int s){
    dist.assign(N + 1, INF);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, s));
    while(!Q.empty()){
        int u = Q.top().second; Q.pop();
        for(auto e : LG[u]){
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push(ii(dist[v], v));
            }
        }
    }
}

int main(){
    cin >> N >> M;
    LG.assign(N + 1, vii());
    for(int i = 0; i < M; i++){
        int u, v, w; cin >> u >> v >> w;
        LG[u].push_back({v, w});
        LG[v].push_back({u, w});
    }
    int server; cin >> server;
    dijkstra(server);
    sort(dist.begin(), dist.end());
    int mn = dist[1], mx = -1;
    for(auto &val : dist){
        if(val == INF)
            break;
        mx = val;
    }
    // cout << "Mx: " << mx << " | Mn: " << mn << "\n";
    cout << mx - mn << "\n";
    return 0;
}