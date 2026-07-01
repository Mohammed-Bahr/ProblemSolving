class Solution(object):
    def minDistance(self, word1, word2):
        # Handle edge cases where one string is empty
        if not word1:
            return len(word2)
        if not word2:
            return len(word1)
        
        if len(word1) == 1 and len(word2) == 1:
            return len(word2) + 1 if word1 != word2 else 0
        
        
        if len(word2) == 1:
            return len(word1) + 1 if word2 not in word1 else len(word1) - 1
        if len(word1) == 1:
            return len(word2) + 1 if word1 not in word2 else len(word2) - 1
        
        # Initialize the DP table
        dp = [[0] * (len(word2) + 1) for _ in range(len(word1) + 1)]

        # Fill last row (base case: word1 is effectively empty here)
        for i in range(len(word2) + 1):
            dp[len(word1)][i] = len(word2) - i

        # Fill last column (base case: word2 is effectively empty here)
        for i in range(len(word1) + 1):
            dp[i][len(word2)] = len(word1) - i

        # Iterate backwards to fill the rest of the grid
        for p1 in range(len(word1) - 1, -1, -1):
            for p2 in range(len(word2) - 1, -1, -1):
                if word1[p1] == word2[p2]:
                    # Characters match: cost is same as next diagonal state
                    dp[p1][p2] = dp[p1 + 1][p2 + 1]
                else:
                    # Characters mismatch: 1 + min of insert, delete, replace
                    dp[p1][p2] = 1 + min(
                        dp[p1 + 1][p2 + 1],  # replace
                        dp[p1 + 1][p2],      # delete
                        dp[p1][p2 + 1]       # insert
                    )

        return dp[0][0]
    
    
    
def main():
    sol = Solution()
    word1= "horse"
    word2 = "ros"
    
    

    result = sol.minDistance(word1, word2)
    print(result)


# run main
if __name__ == "__main__":
    main()
