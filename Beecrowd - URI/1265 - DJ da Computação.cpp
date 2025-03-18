#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        int N, Q;
        cin >> N >> Q;
        if(N == 0 && Q == 0) break; 

        vector<string> titles(N);
        for(int i = 0; i < N; i++){
            cin >> titles[i];
        }
        
        vector<long long> queries(Q);
        for(int i = 0; i < Q; i++){
            cin >> queries[i];
        }
        
        for(int i = 0; i < Q; i++){
            long long k = queries[i];
            long long cumulative = 0;
            int L = 1;
            
            while (true) {
                
                long long power = 1;
                for (int j = 0; j < L; j++){
                    power *= N;
                }
                
                long long groupCount = (long long)L * power;
                if (cumulative + groupCount >= k)
                    break;
                cumulative += groupCount;
                L++;
            }
            
            long long k_prime = k - cumulative;
            
            long long word_index = (k_prime - 1) / L;
            
            int pos = (int)((k_prime - 1) % L);
            
            string word(L, 'A');
            for (int i = L - 1; i >= 0; i--){
                int digit = word_index % N;
                word[i] = 'A' + digit;
                word_index /= N;
            }
            
            int soundIndex = word[pos] - 'A';
            cout << titles[soundIndex] << "\n";
        }
        cout << "\n"; 
    }
    return 0;
}
