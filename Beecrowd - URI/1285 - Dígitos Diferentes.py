def has_all_unique_digits(num):
    s = str(num)
    return len(s) == len(set(s))

try:
    while True:
        line = input().strip()
        if not line:
            continue
        
        parts = line.split()
        N, M = map(int, parts)
        count = 0
        
        for num in range(N, M + 1):
            if has_all_unique_digits(num):
                count += 1
        print(count)
except EOFError:
    pass
