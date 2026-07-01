class Solution:
    def reverseBits(self, n: int) -> int:
        bits = format(n, '032b')
        stack = list(bits)
        res = ""
        
        while stack:
            res += stack.pop()
            
        return int(res, 2)

if __name__ == "__main__":
    sol = Solution()
    print(sol.reverseBits(43261596))