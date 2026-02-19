import heapq
from typing import List

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.heap = []

        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        heapq.heappush(self.heap, val)

        if len(self.heap) > self.k:
            heapq.heappop(self.heap)

        return self.heap[0]


def main():
    kthLargest = KthLargest(3, [4, 5, 8, 2])

    print(kthLargest.add(3))   # 4
    print(kthLargest.add(5))   # 5
    print(kthLargest.add(10))  # 5
    print(kthLargest.add(9))   # 8
    print(kthLargest.add(4))   # 8


if __name__ == "__main__":
    main()