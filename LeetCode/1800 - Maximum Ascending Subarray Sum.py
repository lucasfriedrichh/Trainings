class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        n = len(nums)
        maxV = 0
        curVal = nums[0]
        
        for i in range(1, n):
            if nums[i-1] < nums[i]:
                curVal+=nums[i]
            else:
                maxV = max(maxV, curVal)
                curVal = nums[i]
                
        return max(curVal, maxV)