from collections import deque
from typing import List

# class Solution:
#     def diff(self, w1, w2):
#         count = 0
#         for i in range(len(w1)):
#             if w1[i] != w2[i]:
#                 count += 1
#         return count == 1

#     def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
#         if endWord not in wordList:
#             return 0

#         q = deque()
#         q.append((beginWord, 1))

#         visited = set()

#         while q:
#             word, steps = q.popleft()

#             if word == endWord:
#                 return steps

#             for w in wordList:
#                 if w not in visited and self.diff(word, w):
#                     visited.add(w)
#                     q.append((w, steps + 1))

#         return 0


# if __name__ == "__main__":
#     solution = Solution()
#     beginWord = "hit"
#     endWord = "cog"
#     wordList = ["hot","dot","dog","lot","log","cog"]
#     print(solution.ladderLength(beginWord, endWord, wordList))

#------------------------------------------------------------------------------------------------
#  optimal solution

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0
        
        # 1. Pre-process the dictionary into generic states
        mapping = defaultdict(list)
        for word in wordSet:
            for i in range(len(word)):
                pattern = word[:i] + '*' + word[i+1:]
                mapping[pattern].append(word)
        
        # 2. Execute BFS
        q = deque([(beginWord, 1)])
        visited = set([beginWord])
        
        while q:
            word, steps = q.popleft()
            
            if word == endWord:
                return steps
            
            # Find neighbors using the fast hash map lookups
            for i in range(len(word)):
                pattern = word[:i] + '*' + word[i+1:]
                
                for neighbor in mapping[pattern]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        q.append((neighbor, steps + 1))
        
        return 0

if __name__ == "__main__":
    solution = Solution()
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    print(solution.ladderLength(beginWord, endWord, wordList))