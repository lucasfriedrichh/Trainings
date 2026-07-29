class Solution:
    def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = [False] * n
        complete_components = 0

        for start in range(n):
            if visited[start]:
                continue

            stack = [start]
            visited[start] = True
            vertices = 0
            degree_sum = 0

            while stack:
                vertex = stack.pop()
                vertices += 1
                degree_sum += len(graph[vertex])

                for neighbor in graph[vertex]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        stack.append(neighbor)

            edges_in_component = degree_sum // 2
            if edges_in_component == vertices * (vertices - 1) // 2:
                complete_components += 1

        return complete_components
