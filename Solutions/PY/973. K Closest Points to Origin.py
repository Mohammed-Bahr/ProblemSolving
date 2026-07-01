from math import sqrt
from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        closest = []
        for point in points:
            res = sqrt(point[0] ** 2 + point[1] ** 2)
            closest.append([point, res])

        closest.sort(key=lambda x: x[1])
        return [point[0] for point in closest[:k]]


def main():
    s = Solution()
    print(s.kClosest([[3,3],[5,-1],[-2,4]], 2))


if __name__ == "__main__":
    main()