#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int bc; cin  >> bc;
        int posX, posY;
        cin >> posX >> posY;
        int ans=1;
        int dist = 1e9;
        for(int i=1; i<=bc; i++){
            int cx, cy;
            cin >> cx >> cy;
            double distancia = sqrt( ((posX-cx)*(posX-cx)) + ((posY-cy)*(posY-cy))); 
            if(distancia<dist){
                dist= distancia;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}