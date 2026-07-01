class Solution(object):
    def solve(self, board):
        if not board:
            return
        
        rows, cols = len(board), len(board[0])

        def DFS(r, c):
            if r < 0 or c < 0 or r >= rows or c >= cols:
                return
            if board[r][c] != "O":
                return
            
            board[r][c] = "Z"
            DFS(r + 1, c)
            DFS(r - 1, c)
            DFS(r, c + 1)
            DFS(r, c - 1)

        for r in range(rows):
            for c in range(cols):
                if (r == 0 or r == rows - 1 or c == 0 or c == cols - 1) and board[r][c] == "O":
                    DFS(r, c)

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == "Z":
                    board[r][c] = "O"



board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
sol = Solution()
sol.solve(board)
print(board)