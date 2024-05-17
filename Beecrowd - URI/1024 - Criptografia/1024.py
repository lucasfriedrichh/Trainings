n = int(input())

for _ in range(n):
    strr = input()

    novoStr = ""
    for letra in M:
        novoStr += chr(ord(letra) + 3) if letra.isalpha() else letra
    M = novoStr[::-1]
    M = M[:len(M)//2] + ''.join([chr(ord(letra) - 1) for letra in M[len(M)//2:]])

    print(M)

