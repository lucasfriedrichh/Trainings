def josephus(n, k):
    retorno = 0
    for i in range(1, n):
        retorno = (retorno + k) % i
    return retorno

def main():
    while True:
        qtsRegioes = int(input())
        if qtsRegioes == 0:
            break

        pulo = 1
        while True:
            if josephus(qtsRegioes, pulo) != 11:
                pulo += 1
            else:
                break

        print(pulo)

if __name__ == "__main__":
    main()
