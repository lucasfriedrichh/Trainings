class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        remove_pos = set()
        
        for i, char in enumerate(s): 
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    stack.pop()
                else:
                    remove_pos.add(i)
                    
        while stack:
            remove_pos.add(stack.pop())

        result = []
        for i, char in enumerate(s):
            if i not in remove_pos:
                result.append(char)

        return "".join(result)
