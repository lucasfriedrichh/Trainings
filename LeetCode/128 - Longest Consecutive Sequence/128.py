class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        nums.sort()
        ans = 0
        temp = 0

        if len(nums) == 1:
            return 1
        elif len(nums) == 0:
            return 0
        print(nums)

        for i in range(len(nums)):
            print(f"nums[i] - 1 == nums[i-1]: {nums[i] - 1} == {nums[i-1]}")
            

            if nums[i] != nums[i-1]:
                if nums[i] - 1 == nums[i-1]:
                    temp+=1
                    if temp > ans:
                        ans = temp
                else:
                    temp = 0


        return ans+1
    
sol = Solution()
print(sol.longestConsecutive([100,4,200,1,3,2]))