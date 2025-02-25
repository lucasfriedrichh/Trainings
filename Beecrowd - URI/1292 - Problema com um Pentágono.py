while True:
    try:
        n = float(input())
        K = 1.0673956817  
        lado_quadrado = K * n
        print(f"{lado_quadrado:.10f}")
    except EOFError:
        break
