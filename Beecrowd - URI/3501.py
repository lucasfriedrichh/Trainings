row, col = map(int, input().split())
matriz = [list(map(int, input().split())) for _ in range(row)]
limit = int(input())

def calcula(l,c):
    ans1 = ""
    ans2 = ""
    for i in range(limit):
        ans1 += str(matriz[l][c+i])
        
    if l <= row - limit:
        for i in range(limit):
            ans2 += str(matriz[l+i][c+i])
    
    if ans1 > ans2:
        return ans1
    return ans2

ans = ""
for r in range(row):
    for c in range(col):   
        if c == (col-limit) + 1:
            break
        
        ans_temp = calcula(r,c)
        if ans < ans_temp:
            ans = ans_temp
print(ans)