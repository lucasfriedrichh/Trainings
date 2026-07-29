from collections import Counter 

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        if k <= 0:
            return ""

        freq = Counter(s)
        odd = [ch for ch, qtd in freq.items() if qtd % 2]

        if len(odd) > 1:
            return ""

        middle = odd[0] if odd else ""
        half = {ch: qtd // 2 for ch, qtd in freq.items() if qtd // 2}
        chars = sorted(half)

        def binom_capped(n: int, r: int, limit: int) -> int:
            r = min(r, n - r)
            result = 1

            for i in range(1, r + 1):
                result = result * (n - r + i) // i
                if result >= limit:
                    return limit

            return result

        def count_permutations_capped(counts: dict[str, int], limit: int) -> int:
            result = 1
            used = 0

            for ch in chars:
                qtd = counts[ch]
                if qtd == 0:
                    continue

                needed = (limit + result - 1) // result
                result *= binom_capped(used + qtd, qtd, needed)

                if result >= limit:
                    return limit

                used += qtd

            return result

        if count_permutations_capped(half, k) < k:
            return ""

        left = []

        while sum(half.values()) > 0:
            for ch in chars:
                if half[ch] == 0:
                    continue

                half[ch] -= 1
                completions = count_permutations_capped(half, k)

                if completions < k:
                    k -= completions
                    half[ch] += 1
                else:
                    left.append(ch)
                    break

        left = "".join(left)
        return left + middle + left[::-1]
    
sol = Solution()
print(sol.smallestPalindrome("abba" , k=2))