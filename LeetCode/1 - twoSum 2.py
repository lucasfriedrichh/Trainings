class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hasher = {}
        for idx, i  in enumerate(nums):
            if hasher.get(i) is not None:
                return [hasher.get(i), idx]
            hasher[target - i] = idx