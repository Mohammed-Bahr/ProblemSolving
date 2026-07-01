class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n <= 1:
            return 0
        
        jumps = 0
        current_end = 0
        farthest = 0
        
        for i in range(n - 1):
            farthest = max(farthest, i + nums[i])
            
            if i == current_end:
                jumps += 1
                current_end = farthest
                
                if current_end >= n - 1:
                    break
        
        return jumps
        
        
        
def main():
    sol = Solution()
    nums = [2,3,1,1,4]
    
    result = sol.jump(nums)
    print(result)
    
    
    
# run main
if __name__ == "__main__":
    main()