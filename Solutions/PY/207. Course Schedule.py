# class Solution:
#     def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
#         courses = {}
#         visited = set()
#         for i in range(numCourses):
#             if prerequisites[i][0] == i:
#                 courses[i] = [prerequisites[i][1]]
#             else:
#                 courses[i] = []
        
#         def dfs(node):
#             if node in visited:
#                 return False
#             visited.add(node)
#             for course in courses[node]:
#                 if not dfs(course):
#                     return False
#             return True
        
#         for i in range(numCourses):
#             if not dfs(i):
#                 return False
#         return True
        


from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {i: [] for i in range(numCourses)}
        for course, pre in prerequisites:
            graph[course].append(pre)

        visiting = set()
        visited = set()

        def dfs(course):
            if course in visiting:   
                return False
            if course in visited:    
                return True

            visiting.add(course)
            for pre in graph[course]:
                if not dfs(pre):
                    return False
            visiting.remove(course)
            visited.add(course)
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False
        return True




s = Solution()
print(s.canFinish(2, [[1,0]]))