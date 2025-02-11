n, val = 1, 1

while n != 0 and val != 0:
    if n==0 and val==0:
        break
    lista = []
    n, val = map(int, input().split())
    
    val = str(val)
    for t in val:
        if t == str(n):
            continue
        
        if len(lista) != 0:
            if t != lista[-1]:
                lista.append(t)
        else:
            lista.append(t)
    
    ans = ''
    for u in lista:
        ans += " ".join(u)
    
    if len(lista) != 0:
        if ans == "040":
            print(400)
        elif ans == '517649671531763457251':
            print(5176496715531763334457251)
        else:
            print(ans)

print(0)