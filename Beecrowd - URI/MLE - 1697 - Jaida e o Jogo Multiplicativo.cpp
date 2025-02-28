#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            if ((long long)i * i <= n) {
                for (int j = i*i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    

    vector<int> smallPrimes = sieve(31623);
    
    while(T--){
        int N;
        cin >> N;
        bool hasOne = false;
        unordered_set<int> P; 
        vector<int> numbers(N);
        for (int i = 0; i < N; i++){
            cin >> numbers[i];
            if(numbers[i] == 1) hasOne = true;
        }
        
        if(!hasOne){
            cout << 0 << "\n";
            continue;
        }
        
    
        for (int a : numbers) {
            if(a == 1) continue;
            int temp = a;
            for (int p : smallPrimes) {
                if ((long long)p * p > temp) break;
                if(temp % p == 0){
                    P.insert(p);
                    while(temp % p == 0)
                        temp /= p;
                }
            }
            if(temp > 1) {
            
                P.insert(temp);
            }
        }
        
    
        int candidate = 2;
        while(true){
        
            bool isPrime = true;
            for (int i = 2; i * i <= candidate; i++){
                if(candidate % i == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                if(P.find(candidate) == P.end()){
                    break;
                }
            }
            candidate++;
        }
        
    
        cout << candidate - 1 << "\n";
    }
    return 0;
}
