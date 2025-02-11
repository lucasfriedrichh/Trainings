class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        j = -1 
        lastSeen = {} 

        for index, letra in enumerate(s):
            j = max(j, lastSeen.get(letra, -1))
            print(f"j: {j}")
            ans = max(ans, index - j)
            lastSeen[letra] = index

        return ans
    

solution = Solution()

print(solution.lengthOfLongestSubstring("dvdf")) 