#include <iostream>


using namespace std;

int fibo[101];


int main(){
    fibo[0]=0;fibo[1]=1;
    for(int i=2; i<101; i++){
        fibo[i]= fibo[i-1] + fibo[i-2];
    }
    int n;
    while(cin >> n)cout << fibo[n] << endl;
    return 0;
}