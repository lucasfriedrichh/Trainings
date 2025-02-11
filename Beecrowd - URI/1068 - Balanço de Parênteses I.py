from collections import deque
fila = deque()

while True:
    try:
        e = input()
        fila.clear()
        flag = False
        for i in e:
            if i == '(':
                fila.append(i)
            if i == ')':
                if len(fila) == 0:
                    flag =True
                    print("incorrect")
                    break
                else:
                    fila.pop()
        
        if len(fila) == 0 and not flag:
            print('correct')
        else:
            if flag:
                continue
            print('incorrect')
            flag = False
                
    except EOFError:
        break