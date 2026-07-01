

class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        dp = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]

        for p1 in range(len(text1) - 1, -1, -1):
            for p2 in range(len(text2) - 1, -1, -1):

                if text1[p1] == text2[p2]:
                    dp[p1][p2] = 1 + dp[p1 + 1][p2 + 1]
                else:
                    dp[p1][p2] = max(dp[p1 + 1][p2], dp[p1][p2 + 1])

        return dp[0][0]


def main():
    sol = Solution()
    word1 = "abcde"
    word2 = "ace"

    result = sol.longestCommonSubsequence(word1, word2)
    print(result)


if __name__ == "__main__":
    main()
