from typing import List
from collections import deque
# class Solution:
#     def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
#         removing_nodes = deque()
#         nodes = []
#         for edge in edges:
#             if edge[1] in nodes:
#                 removing_nodes.append(edge)
#             else:
#                 nodes.append(edge[1])
#         return list(removing_nodes.popleft())

class Solution:
    def findRedundantConnection(self, edges):
        parent = {}

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            px, py = find(x), find(y)
            if px == py:
                return False
            parent[py] = px
            return True

        for u, v in edges:
            if u not in parent:
                parent[u] = u
            if v not in parent:
                parent[v] = v
            if not union(u, v):
                return [u, v]


print(Solution().findRedundantConnection([[1,3],[3,4],[1,5],[3,5],[2,3]]))