class Solution:
    def arrayRankTransform(self, arr):
        ranks = {
            values: index + 1
            for index, values in enumerate(sorted(set(arr)))
        }
        
        return [ranks[value] for value in arr]