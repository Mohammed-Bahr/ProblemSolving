from math import ceil
from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        piles.sort()
        divisor: int = 1

        while True:
            total_hours: int = 0
            for bananas in piles:
                total_hours += ceil(bananas / divisor)

            if total_hours > h:
                divisor += 1
            else:
                break

        return divisor



class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        answer = right

        while left <= right:
            mid = (left + right) // 2

            hours = 0
            for pile in piles:
                hours += ceil(pile / mid)

            if hours <= h:
                answer = mid      
                right = mid - 1   
            else:
                left = mid + 1    

        return answer


def main():
    sol = Solution()
    piles = [30,11,23,4,20]
    h = 5

    print(sol.minEatingSpeed(piles, h))


if __name__ == "__main__":
    main()
