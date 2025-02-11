def lensort(a):
    return sorted(a, key=len, reverse=True)

n = int(input())

for _ in range(n):
    text = input().split()
    aux = lensort(text)
    ans = ' '.join(aux)
    print(ans)