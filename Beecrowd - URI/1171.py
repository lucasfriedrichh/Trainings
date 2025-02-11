from collections import OrderedDict

n = int(input())

chaves = []
for i in range(n):
    n = int(input())
    chaves.append(n)
    
def adicionar_chave(dicionario, chave):
    if chave in dicionario:
        dicionario[chave] += 1
    else:
        dicionario[chave] = 1
    return dicionario

dicionario_final = {}
list(map(lambda chave: adicionar_chave(dicionario_final, chave), chaves))

print(dicionario_final)
