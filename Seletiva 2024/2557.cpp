#include <bits/stdc++.h>

using namespace std;

int main(){
    string expressao;
    while(cin >> expressao){
        string sub1, sub2, sub3;
        size_t indp1, indp2;
        for(size_t i = 0; i < expressao.length(); i++){
            if(expressao[i] != '+')
                sub1 += expressao[i];
            else{
                indp1=i;
                break;
            }
        } 
        for(size_t i = indp1+1; i < expressao.length(); i++){
            if(expressao[i] != '=')
                sub2 += expressao[i];
            else{
                indp2=i;
                break;
            }
        } 
        for(size_t i = indp2+1; i < expressao.length(); i++){
            sub3+=expressao[i];
        } 
        if(sub1=="R"){
            int ans = stoi(sub3)-stoi(sub2);
            cout << ans << "\n";
        }else if(sub2=="L"){
            int ans = stoi(sub3)-stoi(sub1);
            cout << ans << "\n";
        }else{
            int ans = stoi(sub1)+stoi(sub2);
            cout << ans << "\n";
        }
    }
    return 0;
}