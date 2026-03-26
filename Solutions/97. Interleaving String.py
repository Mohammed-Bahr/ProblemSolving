class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, n3 = len(s1), len(s2), len(s3)

        if n1 + n2 != n3:
            return False

        dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]
        dp[0][0] = True

        for p1 in range(1, n1 + 1):
            dp[p1][0] = dp[p1-1][0] and s1[p1-1] == s3[p1-1]

        for p2 in range(1, n2 + 1):
            dp[0][p2] = dp[0][p2-1] and s2[p2-1] == s3[p2-1]

        for p1 in range(1, n1 + 1):
            for p2 in range(1, n2 + 1):
                p3 = p1 + p2 - 1
                dp[p1][p2] = (dp[p1-1][p2] and s1[p1-1] == s3[p3]) or \
                             (dp[p1][p2-1] and s2[p2-1] == s3[p3])

        return dp[n1][n2]


s = Solution()
print(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"))  # True
print(s.isInterleave("aabcc", "dbbca", "aadbbbaccc"))  # False
print(s.isInterleave("", "", ""))                       # True