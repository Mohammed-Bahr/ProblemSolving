from typing import List

# class Solution:
#     def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
#         total_gas = 0
#         total_cost = 0
#         index = 0
#         index_sum = []
#         max_index = 0
#         prev = gas[0] - cost[0]

#         for g, c in zip(gas, cost):
#             total_gas += g
#             total_cost += c

#             index_sum.append(g - c)

#             if g - c > prev:
#                 max_index = index
#                 prev = g - c

#             index += 1

#         if total_gas < total_cost:
#             return -1

#         # ---------------------------------
#         start = max_index
#         tank = 0
#         n = len(gas)

#         for i in range(n):
#             idx = (start + i) % n
#             tank += index_sum[idx]

#             if tank < 0:
#                 return -1

#         return start


from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total = 0
        tank = 0
        start = 0

        for i in range(len(gas)):
            diff = gas[i] - cost[i]

            total += diff
            tank += diff

            if tank < 0:
                start = i + 1
                tank = 0

        if total < 0:
            return -1
        
        return start

        

gas = [1,2,3,4,5]
cost = [3,4,5,1,2]

print (Solution().canCompleteCircuit(gas,cost))