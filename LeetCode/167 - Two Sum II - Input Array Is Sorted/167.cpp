#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l, r;
        l = 0;
        r = numbers.size();
        vector<int> ans;
        while(l<r){
            int currentSum = numbers[l]+numbers[r];
            if(currentSum < target)
                l++;
            if(currentSum > target)
                r--;
            if(currentSum == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};