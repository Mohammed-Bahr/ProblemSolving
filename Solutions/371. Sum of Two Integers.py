class Solution:
    def getSum(a: int, b: int) -> int:
        mask = 0xFFFFFFFF  # 32-bit mask to keep numbers within 32 bits
        
        while b != 0:
            # Calculate sum without carry and the carry separately
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
            
        # If the result has the sign bit set (negative in 32-bit), convert to Python's negative int
        return a if a < 0x80000000 else ~(a ^ mask)

num1 = 5
num2 = 3

res = Solution()
print(res.getSum(num1, num2))

