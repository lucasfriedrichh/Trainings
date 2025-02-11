def solve_case(M, N, L, K, X):
    def cover_floor(dimension):
        needed_boards = []
        for x in X:
            if x == dimension:
                return 1
        
            if x < dimension:
                needed_boards.append(x)
        
        needed_boards.sort(reverse=True)
        
        i, j = 0, len(needed_boards) - 1
        num_boards = 0
        
        while i <= j:
    
            if needed_boards[i] >= dimension:
                num_boards += 1
                i += 1
    
            elif needed_boards[i] + needed_boards[j] >= dimension:
                num_boards += 1
                i += 1
                j -= 1
            else:
                return -1
        
        return num_boards if i > j else -1
    
    if M * 100 % L == 0:
        result_M = cover_floor(N)
        if result_M != -1:
            return result_M
    
    if N * 100 % L == 0:
        result_N = cover_floor(M)
        if result_N != -1:
            return result_N
    
    return 'impossivel'


def main():
    while True:
        M, N = map(int, input().split())
        if M == 0 and N == 0:
            break
        
        L = int(input())
        K = int(input())
        X = list(map(int, input().split()))
        
        result = solve_case(M, N, L, K, X)
        print(result)

if __name__ == "__main__":
    main()
