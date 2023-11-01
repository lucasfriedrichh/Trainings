#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end()); //[1,1,1,2,2,3]
        
        for(auto x : nums){
            mp[x] += 1 ;
        }

        vector<pair<int,int>> vec(mp.begin(),mp.end());


        sort(vec.begin(), vec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second > b.second;
            });
    
        for(auto val : vec){
            cout << val.first << "-" << val.second << endl;
        }
        vector<int> ans;

        int aux = 0;
        for(auto x : vec){
            if (aux ==k)
                break;

            ans.push_back(x.first);
            aux++;
        }

        return ans;
    }
    };
