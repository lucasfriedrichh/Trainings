def resposta(n):
    mul = 1
    auxn = n
    while auxn % 1 != 0:    
        mul+=1
        auxn = n
        auxn *= mul
    
    return int(auxn), mul

while True:
    n = int(input())
    
    if n == 0:
        break

    a, b = map(int, input().split())

    vet = list(map(int, input().split()))

    ans = 9999999
    peso_ans = 999999


    for porcao in range(1, max(vet)):
        X = 0
        max_Y = 0
        for e in vet:
            idas = 0
            ingerido = 0
            while ingerido < e:
                idas += 1
                ingerido += porcao

            X += ingerido - e
            if idas > max_Y:
                max_Y = idas
            peso_atual = a * X + b * max_Y

        if peso_atual < peso_ans and idas <= 3:
            ans = X
            peso_ans = peso_atual

    numerador, denominador = resposta(ans)
    
    if denominador != 1:
        print(f'{numerador} / {denominador}')
    else:
        print(numerador)