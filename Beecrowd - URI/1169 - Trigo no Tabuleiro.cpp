#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        unsigned long long total = 1;
        for (int i = 0; i < x; i++){
            total *= 2ULL;
        }
        total -= 1;
        
        unsigned long long kg = total / 12000;
        
        cout << kg << " kg" << endl;
    }
    return 0;
}
