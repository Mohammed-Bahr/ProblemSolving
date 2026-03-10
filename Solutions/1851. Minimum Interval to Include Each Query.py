from typing import List
import heapq


# class Solution:
#     def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
#         intervals.sort()
#         res = []

#         for query in queries:
#             min_interval = float('inf')

#             for interval in intervals:
#                 if query >= interval[0] and query <= interval[1]:
#                     min_interval = min(min_interval, interval[1] - interval[0] + 1)

#             if min_interval == float('inf'):
#                 res.append(-1)
#             else:
#                 res.append(min_interval)

#         return res

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:

        intervals.sort()
        sorted_queries = sorted([(q, i) for i, q in enumerate(queries)])

        res = [-1] * len(queries)
        heap = []

        i = 0

        for q, idx in sorted_queries:

            while i < len(intervals) and intervals[i][0] <= q:
                l, r = intervals[i]
                heapq.heappush(heap, (r - l + 1, r))
                i += 1

            while heap and heap[0][1] < q:
                heapq.heappop(heap)

            if heap:
                res[idx] = heap[0][0]

        return res

if __name__ == "__main__":
    intervals = [[1,4],[2,4],[3,6],[4,4]]
    queries = [2,3,4,5]

    print(Solution().minInterval(intervals, queries))