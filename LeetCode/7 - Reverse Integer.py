class Solution:
    def reverse(self, x: int) -> int:

        ans = ''
        x = str(x)
        if x[0] == '-':
            ans += '-'
            x=x[1:]
            
        ans += x[::-1]

        print(ans)    