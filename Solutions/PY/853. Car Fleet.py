from typing import *
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        map = {}
        for i in range(len(position)):
            map[position[i]] = speed[i]
        map = dict(sorted(map.items(), reverse=True))
        stack =[]
        for pos in map:
            time = (target - pos) / map[pos]
            if not stack or time > stack[-1]:
                stack.append(time)
        return len(stack)
    
    
    
    
    
sol = Solution()
print(sol.carFleet(12, [10,8,0,5,3], [2,4,1,1,3]))  # 3