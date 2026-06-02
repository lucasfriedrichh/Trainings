n, s = map(int, input().split())
lista = map(int, input().split())

d = dict()
ans = 0

for i in lista:
    find = s - i
    if d.get(find) != None:
        ans += d.get(find)
    
    if d.get(i) != None:
        d[i] += 1  
    else:
        d[i] = 1  

print(ans) 
    

