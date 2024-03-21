#include <bits/stdc++.h>
using namespace std;

int ans = 0;
char M[1123][1123];

bool top(int i, int j){
    if(M[i - 1][j] == '.')
        return true;
    
    return false;
}

bool bottom(int i, int j){
    if(M[i+1][j] == '.')
        return true;
    
    return false;
}

bool left(int i, int j){
    if(M[i][j-1] == '.')
        return true;

    return false;
}

bool right(int i, int j){
    if(M[i][j+1] == '.')
        return true;

    return false;
}

int main(){
    int row, col;
    cin >> row >> col ;
    bool flag = false;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            flag = false;
            if (M[i][j] == '#'){
                if (i == 0){
                    ans++;
                    flag = true;
                }else{
                    if(top(i, j)){
                        ans++;
                        flag = true;
                    }
                }

                if (i == row-1 && !flag){
                    ans++;
                    flag = true;
                }else if(i != row-1 && !flag){
                    if(bottom(i,j)){
                        ans++;
                        flag = true;
                    }
                }

                if(j != 0 && !flag){
                    if (left(i,j)){
                        ans++;
                        flag = true;
                    }
                }else if( j == 0 && !flag){
                    ans++;
                    flag = true;
                }

                if(j != col -1 && !flag){
                    if(right(i,j)){
                        ans++;
                    }
                }else if(j == col -1 && !flag){
                    ans++;
                }
            }
        }
        
    }

    cout << ans << endl;
}    