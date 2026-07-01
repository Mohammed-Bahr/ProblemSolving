
class Wrong_Solution(object):
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        ans = []
        n = len(firstList)
        
        if not firstList or not secondList:
            return ans
        
        for i in range(1,n):
            left = max(firstList[i-1][0] , secondList[i-1][0])
            right = min(firstList[i-1][1] , secondList[i-1][1])
            if left > right:
                continue
            ans.append([left , right])
            #----------------------------------------------------
            left = max(firstList[i][0] , secondList[i-1][0])
            right = min(firstList[i][1] , secondList[i-1][1])
            if left > right:
                continue
            ans.append([left , right])
          
            
        left = max(firstList[n-1][0] , secondList[n-1][0])
        right = min(firstList[n-1][1] , secondList[n-1][1])
        if left <= right:
            ans.append([left , right]) 
            
        return ans
  
  
class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        if not firstList or not secondList:
            return []

        ans = []
        n = len(firstList)
        m = len(secondList)

        i = 0
        j = 0

        while i < n and j < m:
            left = max(firstList[i][0], secondList[j][0])
            right = min(firstList[i][1], secondList[j][1])

            if left <= right:
                ans.append([left, right])

            if firstList[i][1] < secondList[j][1]:
                i += 1
            else:
                j += 1

        return ans
  
def main():
    sol = Solution()
    firstList = [[0,2],[5,10],[13,23],[24,25]]
    secondList = [[1,5],[8,12],[15,24],[25,26]]
    result = sol.intervalIntersection(firstList , secondList)
    print(result)
    
if __name__ == "__main__":
    main()
    
    
    
  