def main():
    t = int(input().strip())
    for _ in range(t):
        A, B = input().split()
        if A.endswith(B):
            print("encaixa")
        else:
            print("nao encaixa")
        

if __name__ == '__main__':
    main()
