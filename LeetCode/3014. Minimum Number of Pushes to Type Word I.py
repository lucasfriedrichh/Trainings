
class Solution:
    def minimumPushes(self, word: str) -> int:
        return sum(index // 8 + 1 for index in range(len(word)))