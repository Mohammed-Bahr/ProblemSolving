import math
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = math.ceil((left + right) / 2)

            
            if nums[mid] == target  :
                return True
            
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            
            elif nums[mid] >= nums[left]:
                if nums[left] <= target <= nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] <= target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        
        return False
    
    
    
    
    
def main():
    sol = Solution()
    nums = [2,5,6,0,0,1,2]
    nums1 = [1,0,1,1,1]
    target = 0
    print(sol.search(nums,target))
    print ("Second test case -> ")
    print(sol.search(nums1,target))

if __name__ == "__main__":
    main()