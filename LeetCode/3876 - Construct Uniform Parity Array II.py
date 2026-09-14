class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        min_odd = 1000000000
        
        for i in range(len(nums1)):
            if nums1[i] % 2 != 0:
                min_odd = min(min_odd, nums1[i])
        
        if min_odd == 1000000000:
            return True
        
        for num in nums1:
            if num % 2 == 0 and num <= min_odd:
                return False
            
        return True
                
        
        
            
sol = Solution()
print(sol.uniformArray([2, 3, 5]))

