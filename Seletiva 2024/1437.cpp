#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int pos = 0;
        string s; cin >> s;
        for(int i = 0; i < n; i++){
            if(s[i] == 'D')
                pos++;
            else
                pos--;
            if(pos > 3)
                pos = 0;
            if(pos < 0)
                pos = 3;
        }
        if(!pos)
            cout << "N\n";
        else if(pos == 1)
            cout << "L\n";
        else if(pos == 2)
            cout << "S\n";
        else
            cout << "O\n";
    }
    return 0;
}