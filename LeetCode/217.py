class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        if len(nums) == 1:
            return False

        nums.sort()
        for i in range(len(nums)):
            if nums[i] == nums[i-1]:
                return True
            
        return False
    
solution = Solution()

print(solution.containsDuplicate([0]))