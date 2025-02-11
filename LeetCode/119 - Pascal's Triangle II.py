class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]

        numRows = rowIndex + 1
        
        ans = []
        row = 1
        for i in range(numRows):
            rowArr = []
            for j in range(row):
                if j == 0 or j == (row-1):
                    rowArr.append(1)
                else:
                    rowArr.append(ans[i-1][j-1] + ans[i-1][j])
                
            ans.append(rowArr)
            row+=1
        return ans[-1]
    