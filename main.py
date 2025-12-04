# class Solution(object):
#     def minDistance(self, word1, word2):
#         if not word1:
#             return len(word2)
#         if not word2:
#             return len(word1)

#         dp = [[0] * (len(word2) + 1) for _ in range(len(word1) + 1)]

#         # fill last row
#         for i in range(len(word2) + 1):
#             dp[len(word1)][i] = len(word2) - i

#         # fill last column
#         for i in range(len(word1) + 1):
#             dp[i][len(word2)] = len(word1) - i

#         for p1 in range(len(word1) - 1, -1, -1):
#             for p2 in range(len(word2) - 1, -1, -1):
#                 if word1[p1] == word2[p2]:
#                     dp[p1][p2] = dp[p1 + 1][p2 + 1]
#                 else:
#                     dp[p1][p2] = 1 + min(
#                         dp[p1 + 1][p2 + 1],  # replace
#                         dp[p1 + 1][p2],      # delete
#                         dp[p1][p2 + 1]       # insert
#                     )

#         return dp[0][0]

class Solution(object):
    def maxAreaOfIsland(self, grid):
        rows, cols = len(grid), len(grid[0])
        maxArea = 0
        
        def DFS(i, j):
            if i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] == 0:
                return 0
            
            grid[i][j] = 0  # mark visited
            area = 1
            
            area += DFS(i + 1, j)
            area += DFS(i - 1, j)
            area += DFS(i, j + 1)
            area += DFS(i, j - 1)
            
            return area
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, DFS(i, j))
        
        return maxArea

    
def main():
    sol = Solution()
    grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    result = sol.maxAreaOfIsland(grid)
    print(result)
    
if __name__ == "__main__":
    main()
    
    
    
  