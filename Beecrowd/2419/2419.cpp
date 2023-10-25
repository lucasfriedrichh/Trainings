#include <bits/stdc++.h>
using namespace std;

int ans = 0;
char M[1123][1123];

bool top(int i, int j){
    if(M[i][j] == '#'){
        // return M[i-1][j] == '.';
        if(M[i-1][j] == '.'){
            // cout << i << " " << j << endl;
            return true;
        }
    }  
    return false;

}

bool bottom(int i, int j){
    if(M[i][j] == '#'){
        // return M[i+1][j] == '.';
        if(M[i+1][j] == '.'){
            // cout << i << " " << j << endl;
            return true;
        }

    }
    return false;

}

bool left(int i, int j){
    if(M[i][j] == '#'){
        // return M[i][j-1] == '.';
        if(M[i][j-1] == '.'){
            // cout << i << " " << j << endl;
            return true;
        }

    }
    return false;

}

bool right(int i, int j){
    if(M[i][j] == '#'){
        // return M[i][j+1] == '.';
        
        if(M[i][j+1] == '.'){
            // cout << i << " " << j << endl;
            return true;
        }
    }
    return false;

}

int main(){
    int row, col;
    cin >> row >> col;
    
    //leitura
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            bool flag = false;
            if(i != 0){
                if(top(i,j)){
                    ans++;
                    flag = true;
                }
            }else if (M[i][j] == '#' && !flag){
                ans ++;
                flag = true;

            }

            if(i < row -1 && !flag){
                if(bottom(i,j)){
                    ans++;
                    flag = true;
                }
            }else if (M[i][j] == '#' && !flag){
                ans ++;
                flag = true;

            }

            if(j != 0 && !flag){
                if(left(i,j)){
                    ans++;
                    flag = true;
                }
            }else if (M[i][j] == '#' && !flag){
                ans ++;
                flag = true;

            }

            if(i < col -1 && !flag){
                if(right(i,j)){
                    ans++;
                }
            }else if (M[i][j] == '#' && !flag){
                ans ++;
            }
        }
    }    


    cout << ans;    

    return 0;
}