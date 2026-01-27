from typing import *
class NotOptimalSolution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        n = len(temperatures)
        memo = {}
        for i in range(len(temperatures)):
            count = 1
            for j in range(i + 1, len(temperatures)):
                if j in memo:
                    res[i] = memo[j]
                    break
                res[i] = count
                memo[j] = count
                count += 1
                if temperatures[j] > temperatures[i]:
                    break
                if n-1 == j:
                    res[i] = 0
            
        return res

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


class TwoPointersSolution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0] * n
        left = 0
        right = 1
        while left < n:
            if right >= n:
                res[left] = 0
                left += 1
                right = left + 1
                continue
            
            if temperatures[right] > temperatures[left] :
                res[left] = right - left
                left += 1
                right = left + 1
            else:
                right += 1

        return res


sol = Solution()
print(sol.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))


print ("Two Pointers Solution")
twoPointersSol = TwoPointersSolution()
print(twoPointersSol.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))