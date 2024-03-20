#include <bits/stdc++.h>

using namespace std;

#define MAX 5

char LG[MAX][MAX];
bool vis[MAX][MAX];

int di[] = {
    -1, 0,0,+1
};

int dj[] = {
    0 ,-1 ,+1,0
};

bool isValid(int i, int j){
    return (i >= 0 && i<5) && (j >= 0 && j<5);
}

void floodFill(int i, int j){
    if(LG[i][j] == '0' || vis[i][j] || !isValid(i,j)) return;
    vis[i][j] = true;
    LG[i][j] = '2';

    for(int k = 0; k < 4; k++){
        floodFill(i + di[k],j + dj[k]);
    }
}


int main() {
    int n;




    return 0;
}