from math import gcd

class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        elif n == 2:
            return 2
        
        odd = 0
        even = 0
        
        add_odd = 1
        add_even = 0
        
        for _ in range(n):
            odd += add_odd
            add_odd +=2
            even += add_even
            add_even +=2
            
        return gcd(odd, even)
            