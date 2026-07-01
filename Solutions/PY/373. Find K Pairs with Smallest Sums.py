# import heapq
# class Solution(object):
#     def kSmallestPairs(self, nums1, nums2, k):
#         """
#         :type nums1: List[int]
#         :type nums2: List[int]
#         :type k: int
#         :rtype: List[List[int]]
#         """
#         seq = []
#         pqueue = []
        
#         for n1 in nums1:
#             for n2 in nums2:
#                 seq.append([n1 , n2])
#         seq.sort(key=lambda x: x[0] + x[1])

#         res = []
#         for i in range(k):
#             res.append(seq[i])
#         return res
    
import heapq

class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        if not nums1 or not nums2:
            return []

        heap = []
        result = []

        for i in range(min(len(nums1), k)):
            heapq.heappush(heap, (nums1[i] + nums2[0], i, 0))

        while heap and len(result) < k:
            _sum, i, j = heapq.heappop(heap)
            result.append([nums1[i], nums2[j]])

            if j + 1 < len(nums2):
                heapq.heappush(heap, (nums1[i] + nums2[j+1], i, j+1))

        return result
   
   
def main():
    sol = Solution()
    num1 = [1,1,2]
    num2 = [1,2 , 3]
    k = 2
    result = sol.kSmallestPairs(num1 ,num2 , k)
    print(result)
    
if __name__ == "__main__":
    main()
    
    
    
  
