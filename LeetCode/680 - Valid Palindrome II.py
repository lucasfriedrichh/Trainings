class Solution:
     def validPalindrome(self, s: str) -> bool:
        def isPalindromeRange(i, j):
            """Check if the string from index i to j is a palindrome."""
            return all(s[k] == s[j-k+i] for k in range(i, j))
        
        left, right = 0, len(s) - 1
        
        while left < right:
            if s[left] != s[right]:
                # Try skipping either the left or the right character
                return isPalindromeRange(left+1, right) or isPalindromeRange(left, right-1)
            left += 1
            right -= 1
        
        return True