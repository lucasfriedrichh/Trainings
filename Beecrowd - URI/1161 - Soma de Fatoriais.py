def fatorial(n) -> int:
    if n == 0:
        return 1
    ans = 1
    for i in range(n + 1):
        if i <= 1:
            continue
        ans = i * ans
    return ans

def main():
    while True:
        try:
            v1,v2  = map(int, input().split())
            print(fatorial(v1) + fatorial(v2))
        except EOFError:
            break
        
if __name__ == "__main__":
    main()
