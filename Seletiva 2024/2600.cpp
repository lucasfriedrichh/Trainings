#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int arr[6];
        set<int> numeros;
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];
        numeros.insert(arr[0]);
        numeros.insert(arr[1]);
        numeros.insert(arr[2]);
        numeros.insert(arr[3]);
        numeros.insert(arr[4]);
        numeros.insert(arr[5]);
        bool passei = true;
        for(int i=1; i<=6; i++){
            if(!numeros.count(i)){
                cout << "NAO\n";
                passei=false;
                break;
            }
        }
        if(passei){
        if( (arr[0]+arr[5]==7) && (arr[1]+arr[3]==7) && (arr[2]+arr[4]==7) )cout << "SIM\n";
        else cout << "NAO\n";
        }
    }
    return 0;
}