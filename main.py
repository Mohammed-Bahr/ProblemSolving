# def my_decorator (func):
#     def wrapper ():
#         print("starting" + func.__name__)
#         func()
#         print("Complete !")

#     return wrapper

# @my_decorator
# def  do_this():
#     print("do this function")


# @my_decorator
# def do_that ():
#     print("do that function.")


# do_that()
# do_that()





class Solution(object):
    def fib(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1

        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1

        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]

    def distributeCandies(self, candyType):
        """
        :type candyType: List[int]
        :rtype: int
        """
        lis = set()
        for i in candyType:
            lis.add(i)
        
        sumition = 0
        for i in lis:
            sumition += i

        
        return sumition / 2


candyType = [1,1,2,2,3,3]

sol = Solution()
print (sol.distributeCandies(candyType))
