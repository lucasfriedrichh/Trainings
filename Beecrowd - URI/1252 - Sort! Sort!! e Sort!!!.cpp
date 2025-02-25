#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int N, M;
        cin >> N >> M;
        cout << N << " " << M << "\n";
        if(N == 0 && M == 0) break;
        
        vector<int> nums(N);
        for (int i = 0; i < N; i++){
            cin >> nums[i];
        }
        
        sort(nums.begin(), nums.end(), [M](int a, int b) {
            int modA = a % M;
            int modB = b % M;
            if(modA != modB)
                return modA < modB;
            
            bool aOdd = (a % 2 != 0);
            bool bOdd = (b % 2 != 0);
            
            
            if(aOdd != bOdd)
                return aOdd; 
            
            
            if(aOdd && bOdd)
                return a > b;
            
            
            return a < b;
        });
        
        for(auto num : nums){
            cout << num << "\n";
        }
    }
    
    return 0;
}
