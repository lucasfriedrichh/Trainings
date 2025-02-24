#include <bits/stdc++.h>

using namespace std;

int main(){
    int R1, X1, Y1, R2, X2, Y2;
    
    while(cin >> R1 >> X1 >> Y1 >> R2 >> X2 >> Y2){
        double distance = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
        
        if(distance + R2 <= R1)
            cout << "RICO" << endl;
        else
            cout << "MORTO" << endl;
    }
    
    return 0;
}
