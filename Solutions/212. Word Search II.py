from typing import *

class node:
    def __init__(self) -> None:
        self.children = {}
        self.end = False
    
    def addWord(self, word):
        curr = self
        for c in word:
            if c not in curr.children:
                curr.children[c] = node()
            curr = curr.children[c]
        curr.end = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = node()
        for w in words:
            root.addWord(w)

        rows, cols = len(board), len(board[0])
        res, visit = set(), set()

        def DFS(row, col, curr_node, word):
            if (row < 0 or col < 0 or row == rows or col == cols or
                (row, col) in visit or board[row][col] not in curr_node.children):
                return

            visit.add((row, col))
            curr_node = curr_node.children[board[row][col]]
            word += board[row][col]

            if curr_node.end:
                res.add(word)

            DFS(row - 1, col, curr_node, word)
            DFS(row + 1, col, curr_node, word)
            DFS(row, col - 1, curr_node, word)
            DFS(row, col + 1, curr_node, word)

            visit.remove((row, col))

        for r in range(rows):
            for c in range(cols):
                DFS(r, c, root, "")

        return list(res)


# ===== MAIN FUNCTION =====
def main():
    board = [
        ["o", "a", "a", "n"],
        ["e", "t", "a", "e"],
        ["i", "h", "k", "r"],
        ["i", "f", "l", "v"]
    ]

    words = ["oath", "pea", "eat", "rain"]

    solution = Solution()
    result = solution.findWords(board, words)

    print("Found words:", result)


if __name__ == "__main__":
    main()
