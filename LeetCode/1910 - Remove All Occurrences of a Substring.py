class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while True:
            if s.__contains__(part):
                s = s.replace(part, '',1)
            else:
                return s
        
sol = Solution()
print(sol.removeOccurrences('aabababa','aba'))