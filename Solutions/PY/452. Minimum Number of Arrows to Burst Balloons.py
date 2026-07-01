# from typing import List

# class Solution:
#     def findMinArrowShots(self, points: List[List[int]]) -> int:
#         left:list = []
#         right:list = []
#         points.sort()
#         for i in points :
#             left.append(i[0])
#         for i in points :
#             right.append(i[1])   
            
#         r:int = 0
#         # ans:list = []
#         count:int = 0
#         for i in range(len(points)):
#             if left[i] > right[r]:
#                 count += 1
#                 r += 1
        
        
            
#         return count 
    
    
    
                
            
         


from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0

        points.sort(key=lambda x: x[1])

        r = points[0][1]  
        count = 1  

        for i in range(1, len(points)):
            if points[i][0] > r:
                count += 1
                r = points[i][1]  

        return count

def main():
    # Example input
    points = [[1,2],[3,4],[5,6],[7,8]]
    points1 =  [[10,16],[2,8],[1,6],[7,12]]
    
    
    sol = Solution()
    result = sol.findMinArrowShots(points)
    
    print("Minimum number of arrows needed:", result)


if __name__ == "__main__":
    main()
