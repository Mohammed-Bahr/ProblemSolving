class Solution(object):
    def change(self, amount, coins):
        memo = {}

        def DFS(i, total):
            if (i, total) in memo:
                return memo[(i, total)]

            if total == amount:
                return 1
            if total > amount or i >= len(coins):
                return 0

            res = DFS(i, total + coins[i]) + DFS(i + 1, total)

            memo[(i, total)] = res
            return res

        return DFS(0, 0)


# test
amount = 3
coins = [2]

sol = Solution()
print(sol.change(amount, coins))