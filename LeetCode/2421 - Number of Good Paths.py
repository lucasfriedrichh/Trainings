from collections import defaultdict
from typing import List

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u]) 
        return self.parent[u]

    def union(self, u, v):
        rootU = self.find(u)
        rootV = self.find(v)
        if rootU == rootV:
            return False
        
        if self.size[rootU] < self.size[rootV]:
            rootU, rootV = rootV, rootU
        self.parent[rootV] = rootU
        self.size[rootU] += self.size[rootV]
        return True

class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        n = len(vals)
        adj = defaultdict(list)
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        nodes_sorted = sorted(range(n), key=lambda x: vals[x])
        uf = UnionFind(n)
        countInComp = [defaultdict(int) for _ in range(n)]
        for i in range(n):
            countInComp[i][vals[i]] = 1

        answer = n

        idx = 0
        while idx < n:
            value_group = []
            current_val = vals[nodes_sorted[idx]]
            
            while idx < n and vals[nodes_sorted[idx]] == current_val:
                value_group.append(nodes_sorted[idx])
                idx += 1

            for node in value_group:
                for neighbor in adj[node]:
                    if vals[neighbor] <= current_val:
                        uf.union(node, neighbor)

            root_count = defaultdict(int)
            for node in value_group:
                root = uf.find(node)
                root_count[root] += 1

            for root, count in root_count.items():
                answer += count * (count - 1) // 2  

        return answer
