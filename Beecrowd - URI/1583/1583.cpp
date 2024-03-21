#include <bits/stdc++.h>
using namespace std;

#define MAX 52

char M[MAX][MAX];
bool vis[MAX][MAX];
int n, m;

int di[] = {
    -1, 0,0,+1
};

int dj[] = {
    0 ,-1 ,+1,0
};

inline bool isValid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j<m;
}

void floodFill(int i, int j){
    if(!isValid(i,j) || M[i][j] == 'X' || vis[i][j]) return;
    vis[i][j] = true;
    M[i][j] = 'T';

    for(int k = 0; k < 4; k++){
        floodFill(i + di[k],j + dj[k]);
    }


}

int main(){

    while (true) {
        cin >> n >> m;
        if(!n && !m){
            break;
        }


        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> M[i][j];
            }
        }

        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(M[i][j] == 'T'){
                    floodFill(i,j);
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout<< M[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}