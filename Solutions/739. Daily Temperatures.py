from typing import *
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0] * n
        stack = [] 

        for i in range(n):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                prev = stack.pop()
                res[prev] = i - prev
            stack.append(i)

        return res

    # def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
    #     n = len(temperatures)
    #     res = [0] * n
    #     left = 0
    #     right = 1
    #     while left < n:
    #         if right >= n:
    #             res[left] = 0
    #             left += 1
    #             right = left + 1
    #             continue
            
    #         if temperatures[right] > temperatures[left] :
    #             res[left] = right - left
    #             left += 1
    #             right = left + 1
    #         else:
    #             right += 1

    #     return res
 