from enums import Enum

class State(Enum):
    BUY = 0
    SELL = 1
    REST = 2    

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        if not prices:
            return 0
        if len(prices) == 1:
            return 0
        
        dp = {
            State.BUY: -prices[0],
            State.SELL: 0,
            State.REST: 0
        }
        
        
        for price in prices[1:]:
            prev_buy = dp[State.BUY]
            prev_sell = dp[State.SELL]
            prev_rest = dp[State.REST]
            
            dp[State.BUY] = max(prev_buy, prev_rest - price)
            dp[State.SELL] = prev_buy + price
            dp[State.REST] = max(prev_rest, prev_sell)
            
            
        return max(dp[State.SELL], dp[State.REST])
            