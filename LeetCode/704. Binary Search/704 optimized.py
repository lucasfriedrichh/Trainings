#234ms using binary search

class Solution:
    def search(self, nums: list[int], target: int) -> int:
        l,r = 0, len(nums) - 1

        while l <= r:
            m = l + ((r - l) // 2)  # (l + r) // 2 can lead to overflow
            if nums[m] > target:
                r = m -1
            elif nums[m] < target:
                l = m + 1
            elif target == nums[m]:
                return m
        return -1



sol = Solution()
sol.search([1,23,5,8,26,1,83,161,12], 5)