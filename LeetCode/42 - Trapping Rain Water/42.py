class Solution:
    def trap(self, height: list[int]) -> int:
        l,r = 0

        while r != len(height):
            r+=1
            
