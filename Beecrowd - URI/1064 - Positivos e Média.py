pos = 0
ans = 0

for _ in range(6):
    n = float(input())
    if n >= 0:
        ans += float(n)
        pos+=1

    
resp = ans/pos
print(f"{pos} valores positivos")
print(f"{resp:.1f}")