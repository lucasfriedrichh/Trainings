while True:
    try:
        n = int(input())
        tt = 420
        ans = 0
        for i in range(n):
            h,m,c = map(int, input().split())
            while tt < (h * 60) + m:
                tt += 30
            if (tt - ((h*60) + m) > c):
                ans+=1
            tt += 30
            
        print(ans)
    except EOFError:
        break