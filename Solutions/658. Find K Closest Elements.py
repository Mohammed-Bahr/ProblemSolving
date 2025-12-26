# from typing import *
# class Solution:
    
#     def BinarySearch (self , arr:List[int] , x:int) -> int :
#         left:int = 0
#         right:int = len(arr) - 1
#         for i in range(len(arr)):
#             mid = (left + right) // 2
#             if arr[mid] == x:
#                 return mid
#             elif arr[mid] > x:
#                 right = mid - 1
                
#             else :
#                 left = mid + 1
                
#         return -1

#     def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
#         if len(arr) <= 1 :
#             return arr
        
        
#         index:int =  self.BinarySearch(arr , x)
#         res:List[int] = []
#         if index != -1 :
#             res.append(x)
            
#         left = index - 1
#         right = index + 1
#         diff1 = abs(arr[left] - x)
#         diff2 = abs(arr[right] - x)
        
#         while len(res) < k :
#             if diff1 < diff2 :
#                 res.append(arr[left])
#                 left -= 1
#             elif diff1 > diff2 :
#                 res.append(arr[right])
#                 right += 1
                
#             else:
#                 if arr[left] < arr[right]:
#                     res.append(arr[left])
#                     left -= 1
#                 else:
#                     res.append(arr[right])
#                     right += 1
                    
#         res.sort()
#         return res
    
    
    
# def main():
#     sol = Solution()
    
#     arr = [1, 2, 3, 4, 5]
#     k = 4
#     x = 3

#     result = sol.findClosestElements(arr, k, x)
#     print("Result:", result)


# if __name__ == "__main__":
#     main()







from typing import *

class Solution:
    
    def BinarySearch(self, arr: List[int], x: int) -> int:
        left = 0
        right = len(arr) - 1
        
        for _ in range(len(arr)):
            if left > right:
                break
            mid = (left + right) // 2
            
            if arr[mid] == x:
                return mid
            elif arr[mid] > x:
                right = mid - 1
            else:
                left = mid + 1
                
        return -1

    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if len(arr) <= k:
            return arr
        
        index = self.BinarySearch(arr, x)
        res = []
        
        if index == -1:
            left = 0
            right = len(arr) - 1
            while left <= right:
                mid = (left + right) // 2
                if arr[mid] < x:
                    left = mid + 1
                else:
                    right = mid - 1
            left -= 1
            right = left + 1
        else:
            res.append(arr[index])
            left = index - 1
            right = index + 1
        
        while len(res) < k:
            if left < 0:
                res.append(arr[right])
                right += 1
            elif right >= len(arr):
                res.append(arr[left])
                left -= 1
            else:
                diff1 = abs(arr[left] - x)
                diff2 = abs(arr[right] - x)
                
                if diff1 <= diff2:
                    res.append(arr[left])
                    left -= 1
                else:
                    res.append(arr[right])
                    right += 1
        
        res.sort()
        return res


def main():
    sol = Solution()
    
    arr = [1, 2, 3, 4, 5]
    k = 4
    x = 3

    result = sol.findClosestElements(arr, k, x)
    print("Result:", result)


if __name__ == "__main__":
    main()
