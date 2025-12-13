class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if not intervals:
            return 0

        intervals.sort()

        n = len(intervals)
        L = 0
        R = 1
        i = 1
        last = 0
        count = 0

        while i < n:
            if intervals[i][L] < intervals[last][R]:
                count += 1
                if intervals[i][R] < intervals[last][R]:
                    last = i
            else:
                last = i
            i += 1

        return count

  
def main():
    sol = Solution()
    intervals = [[1,2],[2,3],[3,4],[1,3]]
    inter = [[1,2],[1,2],[1,2]]
    inte = [[1,2],[2,3]]
    result = sol.eraseOverlapIntervals(inte)
    print(result)
    
if __name__ == "__main__":
    main()
    
    
    
  
                    
                
                