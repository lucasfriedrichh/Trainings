for i in range(int(input())):
    cmps = list(map(str, input().split()))
    final = []
    for c in cmps:
        if c not in final:
            final.append(c)
    final = sorted(final)
    first = True
    for j in range(len(final)):
        if first:
            print(f"{final[j]}", end="")
            first = False
        else:
            print(f" {final[j]}", end="")
        if j == len(final) - 1:
            print()