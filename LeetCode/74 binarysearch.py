# 57ms

class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        for i in range(len(matrix)):
            if matrix[i][-1] < target:
                continue
            l,r = 0, len(matrix[i]) -1

            while l<=r:
                arr = matrix[i]
                m = l + ((r - l) // 2)  # (l + r) // 2 can lead to overflow
                if arr[m] > target:
                    r = m -1
                elif arr[m] < target:
                    l = m + 1
                elif target == arr[m]:
                    return True
                
        return False
                


