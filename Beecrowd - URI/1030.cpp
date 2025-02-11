#include <bits/stdc++.h>
 
using namespace std;
 
int josephus(int pessoas, int pulos) {
    int x = 0, i;
    for (i = 2; i <= pessoas; ++i) {
        x = (x + pulos) % i;
    }
    
    return x;
}


int main() {
    int t, i; 
    
    int n, k; 
    cin >> t;
    
    for (i = 0; i < t; ++i) {
        cin >> n >> k;
        cout << "Case " << i + 1 << ": ";
        cout << josephus(n, k) + 1 << endl;
    }
    return 0; 
}