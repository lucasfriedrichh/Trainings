#include <bits/stdc++.h>

using namespace std;

int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    
        while(true){
            int N, C, T1, T2;
            if(!(cin >> N >> C >> T1 >> T2))
                break;
            
            vector<int> holes(N);
            for (int i = 0; i < N; i++){
                cin >> holes[i];
            }
            sort(holes.begin(), holes.end());
            
            vector<int> extended(2 * N);
            for (int i = 0; i < N; i++){
                extended[i] = holes[i];
                extended[i + N] = holes[i] + C;
            }
            
            int best = INT_MAX;
            for (int i = 0; i < N; i++){
                vector<int> dp(N + 1, 0);
                dp[N] = 0; 
                
                for (int j = N - 1; j >= 0; j--){
                    int pos = extended[i + j];
                    
                    int k1 = upper_bound(extended.begin() + i + j, 
                                           extended.begin() + i + N, 
                                           pos + T1) - extended.begin();
                    int cost1 = T1 + dp[k1 - i];
                    
                    int k2 = upper_bound(extended.begin() + i + j, 
                                           extended.begin() + i + N, 
                                           pos + T2) - extended.begin();
                    int cost2 = T2 + dp[k2 - i];
                    
                    dp[j] = min(cost1, cost2);
                }
                best = min(best, dp[0]);
            }
            
            cout << best << "\n";
        }
        
        return 0;
 
}