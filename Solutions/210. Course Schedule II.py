from typing import *

class Solution:
    def dfs(self, course, graph, visiting, visited, order):
        if course in visiting:
            return False  
        if course in visited:
            return True   

        visiting.add(course)
        for pre in graph[course]:
            if not self.dfs(pre, graph, visiting, visited, order):
                return False

        visiting.remove(course)
        visited.add(course)
        order.append(course)
        return True

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(numCourses)}
        for course, pre in prerequisites:
            graph[course].append(pre)

        visiting = set()
        visited = set()
        order = []

        for course in range(numCourses):
            if course not in visited:
                if not self.dfs(course, graph, visiting, visited, order):
                    return []

        return order
 
    
def main():
    sol = Solution()
    print("Test case 1:")
    print(sol.findOrder(2, [[1,0]]))
    print("Test case 2:")
    print(sol.findOrder(4, [[1,0],[2,0],[3,1],[3,2]]))
    
    
main()