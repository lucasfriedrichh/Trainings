class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == target:
                    return True
        
        return False
            