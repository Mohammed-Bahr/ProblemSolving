from typing import *
# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
        
#         nums.sort()
#         res = []
#         map = {}
#         for i in range(len(nums)):
#             map[nums[i]] = i
#         for i in range(len(nums)):
#             for j in range(i + 1, len(nums)):
#                 remaining = -(nums[i] + nums[j])
#                 if remaining in map:
#                     if map[remaining] > i and map[remaining] > j:
#                         res.append([nums[i], nums[j], remaining])
#         res.sort()
#         set_res = set()
#         for i in range(len(res)):
#             set_res.add(tuple(res[i]))
#         return list(set_res)    
# -----------------------------------------------------------
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        n = len(nums)

        for i in range(n):
            # skip duplicates for i
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            l, r = i + 1, n - 1

            while l < r:
                total = nums[i] + nums[l] + nums[r]

                if total == 0:
                    res.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1

                    # skip duplicates
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                    while l < r and nums[r] == nums[r + 1]:
                        r -= 1

                elif total < 0:
                    l += 1
                else:
                    r -= 1

        return res

    
def main():
    sol = Solution()
    nums = [-1,0,1,2,-1,-4]
    print(sol.threeSum(nums))

if __name__ == "__main__":
    main()