class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i != j:
                    if nums[i] + nums[j] == target:
                        return [i,j]


solution = Solution()

nums = [3,3]
target = 6
print(solution.twoSum(nums, target))