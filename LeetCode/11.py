class Solution:
    def maxArea(self, height: list[int]) -> int:
        l, r = 0, len(height)-1
        ans = 0
        while l < r:
            menorHeight = min(height[r], height[l])
            distancia = r - l
            currentVol = menorHeight * distancia
            if ans < currentVol:
                ans = currentVol
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans

sol = Solution()

print(sol.maxArea([1,8,6,2,5,4,8,3,7]))