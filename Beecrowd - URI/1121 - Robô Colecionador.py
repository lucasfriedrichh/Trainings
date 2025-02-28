def main():
    import sys
    input_data = sys.stdin.read().splitlines()
    idx = 0
    output = []
    while idx < len(input_data):
        # Pula linhas vazias, se houver
        if not input_data[idx].strip():
            idx += 1
            continue
        N, M, S = map(int, input_data[idx].split())
        idx += 1
        if N == 0 and M == 0 and S == 0:
            break

        arena = []
        start_x = start_y = 0
        orientation = None
        # Lê o mapa e identifica a posição e orientação inicial do robô
        for i in range(N):
            row = list(input_data[idx].rstrip())
            idx += 1
            for j in range(M):
                if row[j] in "NLSO":
                    start_x, start_y = i, j
                    orientation = row[j]
                    row[j] = '.'  # Remove o marcador de início da arena
            arena.append(row)

        instructions = input_data[idx].strip()
        idx += 1

        # Mapeamento de orientações para índices:
        # 0 -> Norte, 1 -> Leste, 2 -> Sul, 3 -> Oeste
        dirs = {'N': 0, 'L': 1, 'S': 2, 'O': 3}
        # Vetores de movimento para cada direção
        moves = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        ori = dirs[orientation]
        x, y = start_x, start_y
        stickers = 0

        for ch in instructions:
            if ch == 'D':           # Gira 90 graus para a direita
                ori = (ori + 1) % 4
            elif ch == 'E':         # Gira 90 graus para a esquerda
                ori = (ori - 1) % 4
            elif ch == 'F':         # Move uma célula para a frente
                nx = x + moves[ori][0]
                ny = y + moves[ori][1]
                if 0 <= nx < N and 0 <= ny < M and arena[nx][ny] != '#':
                    x, y = nx, ny
                    if arena[x][y] == '*':
                        stickers += 1
                        arena[x][y] = '.'
        output.append(str(stickers))
    # Imprime a saída sem espaços ou linhas a mais
    sys.stdout.write("\n".join(output) + "\n")

if __name__ == '__main__':
    main()
