def solve():
    import sys
    input_data = sys.stdin.read().splitlines()
    i = 0
    resultados = []
    while i < len(input_data):
        if input_data[i].strip() == "":
            i += 1
            continue
        n = int(input_data[i].strip())
        i += 1
        if n == 0:
            break
        p = int(input_data[i].strip())
        i += 1
        pedidos = []
        for _ in range(n):
            tempo, pizzas = map(int, input_data[i].split())
            i += 1
            pedidos.append((tempo, pizzas))
        
        dp = [0] * (p + 1)
        for tempo, pizzas in pedidos:
            for j in range(p, pizzas - 1, -1):
                dp[j] = max(dp[j], dp[j - pizzas] + tempo)
                
        resultados.append(f"{max(dp)} min.")
    
    sys.stdout.write("\n".join(resultados) + "\n")
    
if __name__ == '__main__':
    solve()
