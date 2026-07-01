from collections import deque


class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        q = deque()
        time , fresh = 0 , 0

        rows , colms = len(grid) , len(grid[0])

        for r in range(rows):
            for c in range(colms):
                if grid[r][c] == 1 :
                    fresh += 1

                if grid[r][c] == 2 :
                    q.append([r,c])

        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        while q and fresh > 0:
            
            for i in range(len(q)):
                r, c = q.popleft()
                for dr, dc in directions:
                    row, col = dr + r, dc + c
                    if row < 0 or row == len(grid) or col < 0 or col == len(grid[0]) or grid[row][col] != 1:
                        continue
                    grid[row][col] = 2
                    fresh -= 1
                    q.append([row,col])

            time += 1

        return time if fresh == 0 else -1 



grid = [[2,1,1],[1,1,1],[1,1,1]]
sol = Solution()
print(sol.orangesRotting(grid)) 