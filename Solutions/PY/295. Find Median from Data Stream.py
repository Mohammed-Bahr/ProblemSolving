from math import floor

class MedianFinder(object):

    def __init__(self):
        self.nums = []

    def addNum(self, num):
        self.nums.append(num)

    def findMedian(self):
        self.nums.sort()
        n = len(self.nums)

        if n % 2 == 0:
            return (self.nums[n//2] + self.nums[n//2 - 1]) / 2
        else:
            return self.nums[n//2]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()


def main():
    medianFinder = MedianFinder()

    medianFinder.addNum(1)
    print("After addNum(1):", medianFinder.nums)

    medianFinder.addNum(2)
    print("After addNum(2):", medianFinder.nums)

    print("Median:", medianFinder.findMedian())  # expected 1.5

    medianFinder.addNum(3)
    print("After addNum(3):", medianFinder.nums)

    print("Median:", medianFinder.findMedian())  # expected 2.0


if __name__ == "__main__":
    main()
