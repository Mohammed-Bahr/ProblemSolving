# import math


# class Solution:
#     def numDistinct(self, s: str, t: str) -> int:
#         hashmap_s = {}
#         hashmap_t = {}

#         for i in range(len(s)):
#             hashmap_s[s[i]] = hashmap_s.get(s[i], 0) + 1

#         for i in range(len(t)):
#             hashmap_t[t[i]] = hashmap_t.get(t[i], 0) + 1

#         for char in hashmap_t:
#             count_s = hashmap_s.get(char, 0)
#             count_t = hashmap_t[char]

#             diff = count_s - count_t
#             if diff == 0:
#                 hashmap_s[char] = 0
#                 hashmap_t[char] = 0
#                 continue
#             else:
#                 continue

#         result1 = 0
#         for char in hashmap_t:
#             result1 += hashmap_t[char]

#         result2 = 0
#         for char in hashmap_s:
#             result2 += hashmap_s[char]

#         return math.comb(result2, result1)


# s = Solution()
# print(s.numDistinct("babgbag", "bag"))


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        # If t is longer than s, it's impossible to form the subsequence
        if len(t) > len(s):
            return 0

        m, n = len(s), len(t)

        # Create a 2D DP array initialized to 0
        # dp[i][j] = number of distinct subsequences of t[0:j] in s[0:i]
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Base Case: An empty string 't' can be formed exactly 1 way from any prefix of 's'
        # (by simply deleting all characters from 's')
        for i in range(m + 1):
            dp[i][0] = 1

        # Fill the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # If the current characters match
                if s[i - 1] == t[j - 1]:
                    # We can either USE this character (dp[i-1][j-1])
                    # OR we can IGNORE this character and use previous matches (dp[i-1][j])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                else:
                    # If they don't match, we must IGNORE this character in 's'
                    dp[i][j] = dp[i - 1][j]

        # The bottom-right corner of the grid contains the final answer
        return dp[m][n]


# Test cases
solution = Solution()
print(solution.numDistinct("babgbag", "bag"))  # Output should be 5
print(solution.numDistinct("rabbbit", "rabbit"))  # Output should be 3
