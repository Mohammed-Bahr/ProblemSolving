from typing import List
class Solution:
    def twoSumLimitMemory(self, numbers: List[int], target: int) -> List[int]:
        twoD = [0 for i in range(len(numbers))] * len(numbers)
        for i in range(len(numbers)):
            for j in range(i + 1, len(numbers)):
                if numbers[i] + numbers[j] == target:
                    return [i+1, j+1]
                else:
                    continue
        return []
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(numbers)):
            if target - numbers[i] in map:
                return [map[target - numbers[i]]+1, i+1]
            map[numbers[i]] = i
        return []


Sol = Solution()
print(Sol.twoSum([2,3,4], 6))