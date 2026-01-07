
from typing import List
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        return [x[0] for x in freq[:k]]
        

def main():
    s = Solution()
    print(s.topKFrequent([1], 1))

if __name__ == "__main__":
    main()
