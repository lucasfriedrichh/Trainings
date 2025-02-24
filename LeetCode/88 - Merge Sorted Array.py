class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        ans = []
        
        for i in range(m):
            print(f'add: {nums1[i]}')
            ans.append(nums1[i])
            
        for i in range(n):
            print(f'add: {nums2[i]}')
            ans.append(nums2[i])
            
        ans.sort()
        return nums1
    
    
sol= Solution()

sol.merge([1,2,3,0,0,0], 3 , )