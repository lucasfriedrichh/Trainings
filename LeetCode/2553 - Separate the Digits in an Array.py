def divten(v1):
    val = v1//10
    resto = v1%10
    return val, resto
    
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            while num > 10:
                v1, nums = divten(num)
                ans.append(v1)
                
            ans.append(num)

        print(ans)
        
