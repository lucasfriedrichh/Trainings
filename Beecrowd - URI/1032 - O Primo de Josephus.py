def gerar_primos(limite):
    primos = []
    eh_primo = [True] * (limite + 1)
    eh_primo[0] = eh_primo[1] = False

    for i in range(2, limite + 1):
        if eh_primo[i]:
            primos.append(i)
            for j in range(i * i, limite + 1, i):
                eh_primo[j] = False

    return primos

def josephus_primos(n, primos):
    pessoas = list(range(1, n + 1))
    indice = 0
    primo_indice = 0

    while len(pessoas) > 1:
        salto = primos[primo_indice] - 1
        indice = (indice + salto) % len(pessoas)
        pessoas.pop(indice)
        primo_indice += 1

    return pessoas[0]

def main():
    primos = gerar_primos(40000)
    while True:
        n = int(input())
        if n == 0:
            break
        resultado = josephus_primos(n, primos)
        print(resultado)

if __name__ == "__main__":
    main()
