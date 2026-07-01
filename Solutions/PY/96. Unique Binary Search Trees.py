#CATALAN NUMBER
import math
class Solution(object):
    def numTrees(self, n):
        # Base case is technically handled by the loop initialization,
        # but we can return early for n=0 and n=1 for clarity/minor optimization.
        # This is a good guard clause, though the DP array handles it too.
        # if n <= 1:
        #     return 1

        # dp[i] will store the number of structurally unique BSTs with i nodes.
        # Initialize an array of size n+1 with zeros.
        dp = [0] * (n + 1)
        
        # Base Cases:
        # 0 nodes (empty tree) = 1 way
        # 1 node = 1 way
        dp[0] = 1
        # dp[1] = 1 is implicitly handled by the code block, but assigning it is clearer
        if n >= 1:
            dp[1] = 1

        # Calculate dp[i] from i=2 up to n
        for i in range(2, n + 1):
            # i is the total number of nodes in the current BST
            
            # j iterates over the possible choices for the ROOT node (value 1 to i)
            # j is the SIZE of the left part plus the root (j-1 nodes on left + 1 root)
            for j in range(1, i + 1):
                # j-1: Number of nodes in the LEFT subtree (nodes smaller than the root j)
                left_subtrees = dp[j - 1]
                
                # i-j: Number of nodes in the RIGHT subtree (nodes larger than the root j)
                right_subtrees = dp[i - j]
                
                # The total number of ways when j is the root is the product of
                # the ways to form the left and right subtrees.
                # Add this product to the total for dp[i].
                dp[i] += left_subtrees * right_subtrees

        return dp[n]
    
    
    def optimizednumTrees(self, n):
        return int(1 / (n + 1) * math.comb(2 * n, n))
    
    
print(Solution().numTrees(3))
print(Solution().optimizednumTrees(3))


