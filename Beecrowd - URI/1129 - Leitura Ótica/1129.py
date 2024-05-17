ops = 'ABCDE*'

while True:
    n = int(input())
    if n == 0:
        break
    
    for i in range(n):
        p = -1
        lista = [int(x) for x in input().split()]

        for j in range(len(lista)):
            if lista[j] <= 127:
                if p != -1:
                    p = 5
                    break
                p = j
        print(ops[p])