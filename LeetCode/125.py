class Solution:
    def isPalindrome(self, s: str) -> bool:
        strnew = "".join(ch for ch in s if ch.isalnum())
        strnew = strnew.lower()
        
        if strnew == strnew[::-1]:
            return True
        
        return False
