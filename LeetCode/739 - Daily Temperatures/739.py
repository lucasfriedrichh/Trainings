class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        ans = [0] * len(temperatures) #Declaration of the ans with full 0's
        stack = []
        
        for i, t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                stackT, stackInd = stack.pop()
                ans[stackInd] = (i - stackInd)
            stack.append([t,i])

        return ans            


sol = Solution()
print(sol.dailyTemperatures([73,74,75,71,69,72,76,73]))