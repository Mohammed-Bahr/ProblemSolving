class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        rows , cols = len(grid) , len(grid[0])
        def DFS(i , j):
            if i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] == "0":
                return
            grid[i][j] = "0"
            DFS(i + 1, j) # down
            DFS(i - 1, j) # up
            DFS(i, j + 1) # right
            DFS(i, j - 1) # left
           
           
        def BFS(i , j) :
            if i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] == "0":
                return
            grid[i][j] = "0"
        count = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    DFS(i , j)
                    count += 1
        return count
  
      
def main():
    sol = Solution()
    grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]

    result = sol.numIslands(grid)
    print(result)


if __name__ == "__main__":
    main()
