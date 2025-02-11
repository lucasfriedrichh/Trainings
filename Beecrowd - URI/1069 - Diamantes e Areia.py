from collections import deque

n = int(input())

for _ in range(n):
    fila = deque()
    text = input()
    cout = 0
    
    for i in text:
        if i == '<':
            fila.append(i)
        if i == '>' and len(fila) > 0:
            fila.pop()
            cout+=1
    
    print(cout)