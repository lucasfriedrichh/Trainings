while True:
    try:
        x1, x2 = map(int, input().split())
        print(abs(x1-x2))
        
    except EOFError:
        break