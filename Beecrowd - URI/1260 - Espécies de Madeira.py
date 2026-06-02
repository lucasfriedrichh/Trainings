n = int(input())
input()

for t in range(n):
    mapa = {}
    count = 0

    while True:
        try:
            esp = input()
        except EOFError:
            break
        
        if esp == "":
            break
        
        count += 1
        
        if mapa.get(esp) == None:
            mapa[esp] = 1
        else:
            mapa[esp] = mapa.get(esp) + 1
    
    if t > 0:
        print()

    mapa = dict(sorted(mapa.items()))
    for i in (mapa):
        pct = (mapa[i] * 100) / count
        ans = str(i) + " " + f"{pct:.4f}"
        print(ans)
        
