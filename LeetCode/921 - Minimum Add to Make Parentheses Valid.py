class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        if len(s) == 0:
            return 0
        
        stack = []
        
        for par in s:
            if par == '(':
                stack.append(par)
            else:
                stack.pop()
                
        return len(stack)