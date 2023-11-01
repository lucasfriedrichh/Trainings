#Tomando TLE
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        flag = False
        ans = []

        for i in range(len(nums)):
            mul = 1
            for j in range(len(nums)):
                if i != j:
                    if mul == 1:
                        mul = nums[j]
                    else:
                        mul = nums[j] * mul

            ans.append(mul)
            flag = True

        return ans


sol = Solution()
print(sol.productExceptSelf())