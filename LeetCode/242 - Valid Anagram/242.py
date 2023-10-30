class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        str1 = []
        str2 = []
        
        for char in s:
            str1.append(char)

        for char in t:
            str2.append(char)

        str1.sort()
        str2.sort()

        if str1 == str2:
            return True
        return False


solution = Solution()

solution.isAnagram("teste", "teste")