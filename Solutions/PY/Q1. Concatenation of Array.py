class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        res = nums + nums
        return res


def main():
    s = Solution()
    print(s.getConcatenation([1, 2, 3]))


if __name__ == "__main__":
    main()