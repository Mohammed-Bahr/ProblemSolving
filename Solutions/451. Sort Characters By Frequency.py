from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        return ''.join(
            ch * count
            for ch, count in sorted(freq.items(), key=lambda x: x[1], reverse=True)
        )


def main():
    s = Solution()
    print(s.frequencySort("tree"))


if __name__ == "__main__":
    main()
