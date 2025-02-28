#include <bits/stdc++.h>

using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true){
        int M, N;
        cin >> M >> N;
        if(M==0 && N==0) break;
        
        int L; 
        cin >> L;
        int K;
        cin >> K;
        vector<int> boards(K);
        int maxBoard = 0;
        for (int i = 0; i < K; i++){
            cin >> boards[i];
            if(boards[i] > maxBoard) maxBoard = boards[i];
        }
 
        int maxNeeded = max(M, N);
        vector<int> freq(maxNeeded + 1, 0);
        
        for (int i = 0; i < K; i++){
            int len = boards[i];
            if(len <= maxNeeded){
                freq[len]++;
            }
        }
 
        long long best = LLONG_MAX;
 
        auto solveOrientation = [&](int T, int R) -> long long {
            int exact = freq[T];
            int useExact = min(R, exact);
            int remaining = R - useExact;

            
            long long pairs = 0;
            int lim = (T - 1) / 2;
            for (int a = 1; a <= lim; a++){
                int b = T - a;
                if(b <= maxNeeded){
                    pairs += min(freq[a], freq[b]);
                }
            }
            
            if(T % 2 == 0){
                int a = T / 2;
                pairs += freq[a] / 2;
            }
 
            if(remaining > pairs) return -1LL;
            return (long long)useExact + 2LL * remaining;
        };
 
        if((N * 100) % L == 0){
            int R = (N * 100) / L;
            long long candidate = solveOrientation(M, R);
            if(candidate != -1)
                best = min(best, candidate);
        }
 
        if((M * 100) % L == 0){
            int R = (M * 100) / L;
            long long candidate = solveOrientation(N, R);
            if(candidate != -1)
                best = min(best, candidate);
        }
 
        if(best == LLONG_MAX)
            cout << "impossivel" << "\n";
        else
            cout << best << "\n";
    }
    return 0;
}
