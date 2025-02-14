class Solution:
    def maximumSum(self, nums: list[int]) -> int:
        dic = {}
        for num in nums:
            digit_sum = sum(int(d) for d in str(num))
            if digit_sum not in dic:
                dic[digit_sum] = []
            dic[digit_sum].append(num)
        
        ans = -1
        for group in dic.values():
            if len(group) < 2:
                continue
            group.sort(reverse=True)
            ans = max(ans, group[0] + group[1])
        
        return ans