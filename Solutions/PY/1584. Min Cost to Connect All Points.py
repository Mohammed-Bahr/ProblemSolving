from math import inf


class Solution(object):
    def minCostConnectPoints(self, points):
        res = 0
        n = len(points)
        
        visited = [False] * n
        min_dist = [inf] * n
        min_dist[0] = 0   
        for p1 in range(n):
            u = -1
            for i in range(n):
                if not visited[i] and (u == -1 or min_dist[i] < min_dist[u]):
                    u = i

            visited[u] = True
            res += min_dist[u]

            for p2 in range(n):
                if not visited[p2]:
                    manhattan_distance =  abs( points[u][0] - points[p2][0]) + \
                                         abs(points[u][1] - points[p2][1])

                    min_dist[p2] = min(min_dist[p2], manhattan_distance)

        return res


points = [[0,0],[2,2],[3,10],[5,2],[7,0]]

print(Solution().minCostConnectPoints(points))