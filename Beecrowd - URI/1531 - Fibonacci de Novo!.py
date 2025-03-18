import sys, math

# Fast doubling: calcula (F(n), F(n+1)) modulo mod.
def fib(n, mod):
    if n == 0:
        return (0, 1)
    a, b = fib(n >> 1, mod)
    c = (a * ((2 * b - a) % mod)) % mod
    d = (a * a + b * b) % mod
    if n & 1:
        return (d, (c + d) % mod)
    else:
        return (c, d)

# Cria uma lista de primos até 'limit' (usando a Crivo de Eratóstenes).
def get_primes(limit):
    sieve = [True] * (limit+1)
    sieve[0] = sieve[1] = False
    for i in range(2, int(limit**0.5)+1):
        if sieve[i]:
            for j in range(i*i, limit+1, i):
                sieve[j] = False
    return [i for i, is_prime in enumerate(sieve) if is_prime]

# Lista de primos para fatoração (até aproximadamente sqrt(2e6) ≈ 1500).
primes_list = get_primes(1500)

# Fatora n usando os primos pré-computados.
def factorize(n):
    factors = {}
    for p in primes_list:
        if p * p > n:
            break
        while n % p == 0:
            factors[p] = factors.get(p, 0) + 1
            n //= p
    if n > 1:
        factors[n] = factors.get(n, 0) + 1
    return factors

# Dado n, retorna todos os divisores de n (ordenados).
def get_divisors(n):
    facs = factorize(n)
    divisors = [1]
    for p, exp in facs.items():
        new_divs = []
        for d in divisors:
            factor = 1
            for _ in range(exp):
                factor *= p
                new_divs.append(d * factor)
        divisors.extend(new_divs)
    return sorted(divisors)

# Calcula o período de Pisano para uma potência de primo p^a.
def pisano_prime_power(p, a):
    if p == 2:
        if a == 1:
            return 3
        elif a == 2:
            return 6
        else:
            return 3 * (2 ** (a - 1))
    if p == 5:
        if a == 1:
            return 20
        else:
            return 4 * (5 ** a)
    # Para p ≠ 2,5
    # Determina o candidato: se 5 for resíduo quadrático modulo p, candidato = p-1, senão = 2*(p+1)
    if pow(5, (p - 1) // 2, p) == 1:
        candidate = p - 1
    else:
        candidate = 2 * (p + 1)
    # Testa os divisores de 'candidate' em ordem crescente
    divs = get_divisors(candidate)
    period_p = None
    for d in divs:
        f, f_next = fib(d, p)
        if f % p == 0 and f_next % p == 1:
            period_p = d
            break
    if period_p is None:
        period_p = candidate
    return period_p * (p ** (a - 1))

# Calcula o período de Pisano para um módulo M qualquer, usando fatoração.
def pisano(m):
    facs = factorize(m)
    period = 1
    for p, a in facs.items():
        pp = pisano_prime_power(p, a)
        period = (period * pp) // math.gcd(period, pp)
    return period

# Função principal: lê os casos de teste e processa cada um.
def main():
    input_data = sys.stdin.read().strip().split()
    if not input_data: 
        return
    it = iter(input_data)
    results = []
    for n_str, m_str in zip(it, it):
        N = int(n_str)
        M = int(m_str)
        # Calcula o período de Pisano para M
        pis = pisano(M)
        # Reduz o índice: F(N) mod pis
        index = fib(N, pis)[0]  # F(N) mod pis
        # Calcula F(index) mod M – isto é Fib(F(N)) mod M.
        result = fib(index, M)[0]
        results.append(str(result))
    sys.stdout.write("\n".join(results))

if __name__ == '__main__':
    main()
