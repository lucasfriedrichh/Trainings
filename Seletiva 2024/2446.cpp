#include <bits/stdc++.h>
using namespace std;

#define MAXM 1123

int V, M;
int c[MAXM];

int solve(int v, int m){
    if(v < 0) 
        return false;
    if(v == 0) 
        return true;
    if(m == 0) 
        return false;
    return solve(v-c[m], m-1) || solve(v, m-1);
}

int main(){
    int V, M, i;
    while(cin >> V >> M){
        for(i = 1; i <= M; i++)
            cin >> c[i];
        cout << (solve(V, M) ? "S\n" : "N\n");
    }
    return 0;
}