def dfs(graph, visited, node, depth):
    visited[node] = True
    print("bb" * depth + f"{node}")

    for neighbor in sorted(graph[node]):
        if not visited[neighbor]:
            print("bb" * (depth + 1) + f"{node}-{neighbor} pathR(G,{neighbor})")
            dfs(graph, visited, neighbor, depth + 1)


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")

    N = int(data[0])
    idx = 1

    results = []

    for _ in range(N):
        V, E = map(int, data[idx].split())
        idx += 1


        graph = {i: [] for i in range(V)}

        for __ in range(E):
            u, v = map(int, data[idx].split())
            idx += 1
            graph[u].append(v)
            graph[v].append(u)


        visited = [False] * V

        for node in range(V):
            if not visited[node]:
                results.append(f"bb{node}")
                dfs(graph, visited, node, 1)

        results.append("")

    print("\n".join(results))


if __name__ == "__main__":
    main()
