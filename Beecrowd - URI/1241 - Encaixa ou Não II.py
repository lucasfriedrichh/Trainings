n = int(input())

for _ in range(n):
    x1, x2 = map(int, input().split())
    if len(str(x2)) > len(str(x1)):
        print('nao encaixa')
        continue
    
    aux = (len(str(x2)))
    aux1 = str(x1)
    aux1 = aux1[-aux :]

    if aux1 == str(x2):
        print('encaixa')
    else:
        print("nao encaixa")
