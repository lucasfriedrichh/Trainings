import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    T = int(input_data[0])
    idx = 1
    
    LIMIT = 5000
    
    max_sum = 2 * LIMIT
    is_square = [False] * (max_sum + 1)
    i = 1
    while i*i <= max_sum:
        is_square[i*i] = True
        i += 1

    def max_balls(N):
        if N == 0:
            return 0
        
        tops = [0] * N  
        
        for ball in range(1, LIMIT + 1):
            placed = False
            for j in range(N):
                top_j = tops[j]
                if top_j == 0 or is_square[top_j + ball]:
                    tops[j] = ball
                    placed = True
                    break
            if not placed:
                
                return ball - 1
        
        
        return -1  

    outputs = []
    for _ in range(T):
        N = int(input_data[idx])
        idx += 1
        result = max_balls(N)
        if result == -1:
            outputs.append("-1")
        else:
            outputs.append(str(result))
    
    print("\n".join(outputs))


if __name__ == "__main__":
    solve()
