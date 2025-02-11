def main():
    while True:
        B, N = map(int, input().split())

        if B == 0 and N == 0:
            break

        reserves = list(map(int, input().split()))

        for _ in range(N):
            D, C, V = map(int, input().split())

            reserves[D - 1] -= V
            reserves[C - 1] += V

        if all(reserve >= 0 for reserve in reserves):
            print('S')
        else:
            print('N')

if __name__ == "__main__":
    main()
