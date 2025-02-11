class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        lista = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        neg = False
        ans = ''
        first = True
        
        for c in s:
            if c == '-' and first:
                neg = True
                first = False
                continue
            
            if c == '+' and first:
                first = False
                continue
            
            if c not in lista:
                break
            
            ans += c
            first = False

        if ans == '':
            return 0

        result = int(ans)
        if neg:
            result = -result

        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        if result < INT_MIN:
            return INT_MIN
        if result > INT_MAX:
            return INT_MAX
        
        return result