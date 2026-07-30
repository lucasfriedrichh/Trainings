class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        combinations = []

        def backtrack(cur, open, close):
            if len(cur) == 2 * n:
                combinations.append(cur)
                return
            if open < n:
                backtrack(cur+"(", open+1, close)
            if close < open:
                backtrack(cur+")", open, close+1)  
        
        backtrack("",0,0)
        return combinations