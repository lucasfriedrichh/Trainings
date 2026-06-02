def find(parent, x):
    # print("find( " + str(parent) + ", " + str(x) + ")")
    while parent[x] != x:
        # print("primeiro: " + str(parent[x]) + " != ["+str(x) + "]")
        
        parent[x] = parent[parent[x]]
        x = parent[x]
        
        # print("Segundo: " + str(parent[x]) + " != ["+str(x) + "]")
    return x

def union(parent, size, a, b):
    root_a = find(parent, a)
    root_b = find(parent, b)

    if root_a == root_b:
        return False

    if size[root_a] < size[root_b]:
        root_a, root_b = root_b, root_a

    parent[root_b] = root_a
    size[root_a] += size[root_b]
    return True

def main():
    n, m = map(int, input().split())

    parent = list(range(n + 1))
    size = [1] * (n + 1)
    families = n

    for _ in range(m):
        a, b = map(int, input().split())

        if union(parent, size, a, b):
            families -= 1

    # print(families)


if __name__ == "__main__":
    main()
