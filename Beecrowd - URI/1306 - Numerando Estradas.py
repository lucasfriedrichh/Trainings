def fat(n):
    if n < 0:
        return 0
    
    resultado = 1
    for i in range(1, n + 1):
        resultado *= i
    return resultado

counter = 0
while True:
    counter +=1
    v1,v2 = map(int, input().split())
    if v1 == 0 and v2 == 0:
        break


    if v1 <= v2:
            result = 0    

    suffixes_needed = (v1 + v2 - 1) // v2 - 1

    if suffixes_needed > 26:
        result = "impossible"
    else:
        result = suffixes_needed
    
    print(f"Case {counter}: {result}")
    