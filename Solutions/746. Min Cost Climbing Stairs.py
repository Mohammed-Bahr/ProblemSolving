class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        n = len(cost)
        dp = [0] * n
        dp[0] = cost[0]
        dp[1] = cost[1]

        for i in range(2 , len(cost)):
            dp[i] = cost[i] + min(dp[i-1] , dp[i - 2])

        res = min(dp[n-1] , dp[n-2])

        return res


cost = [1,100,1,1,1,100,1,1,100,1]
sol = Solution()

print(sol.minCostClimbingStairs(cost))