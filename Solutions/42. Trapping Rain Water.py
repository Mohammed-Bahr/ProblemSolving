class Solution(object):
    def trap(self, height):
        if not height:
            return 0

        maxleft = []
        maxright = []
        water = 0

        maxvalue = height[0]

        for i in height:
            if i >= maxvalue:
                maxvalue = i
            maxleft.append(maxvalue)

        reversed_height = height[::-1]
        maxvalue = reversed_height[0]

        for i in reversed_height:
            if i >= maxvalue:
                maxvalue = i
            maxright.append(maxvalue)

        maxright = maxright[::-1]

        for i in range(len(height)):
            res = min(maxleft[i], maxright[i]) - height[i]
            if res > 0 :
                water += res
        return water



sol = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]

print (sol.trap(height))