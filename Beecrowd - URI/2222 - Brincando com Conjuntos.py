def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    T = int(data[0])
    result = []
    index = 1

    for _ in range(T):
        N = int(data[index])
        index += 1

        sets = []

        for _ in range(N):
            line = list(map(int, data[index].split()))
            index += 1
            Mi, elements = line[0], set(line[1:])
            sets.append(elements)

        Q = int(data[index])
        index += 1

        for _ in range(Q):
            operation = list(map(int, data[index].split()))
            index += 1

            op_type, X, Y = operation
            X -= 1
            Y -= 1

            if op_type == 1:
                result.append(len(sets[X] & sets[Y]))
            elif op_type == 2:
                result.append(len(sets[X] | sets[Y]))

    sys.stdout.write("\n".join(map(str, result)) + "\n")

if __name__ == "__main__":
    main()
