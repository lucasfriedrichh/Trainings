n = int(input())
lista = list(map(int, input().split()))

ans = 0

for i in lista:
    if n == i:
        ans += 1
        
print(ans)