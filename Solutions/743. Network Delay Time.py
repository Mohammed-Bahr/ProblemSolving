import collections
import heapq

class Solution(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        edges = collections.defaultdict(list)
        """
        u -> is the source node 
        v -> is the target node 
        w -> is the weight of the edge 
        """
        for u, v, w in times:
            edges[u].append((v, w))

        minheap = [(0, k)]
        res = 0
        visited = set()

        while minheap:
            w1, n1 = heapq.heappop(minheap)
            if n1 in visited:
                continue
            visited.add(n1)
            res = max(res, w1)
            for n2, w2 in edges[n1]:
                if n2 not in visited:
                    heapq.heappush(minheap, (w1 + w2, n2))

        return res if len(visited) == n else -1

times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2

sol = Solution()
print(sol.networkDelayTime(times, n, k))