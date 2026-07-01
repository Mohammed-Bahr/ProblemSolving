class Solution:
    def largestRectangleArea(self, heights):
        stack = []          # stack stores indices
        max_area = 0
        heights.append(0)   # sentinel to flush the stack at the end

        for i in range(len(heights)):
            # while current bar is smaller than the top of stack
            while stack and heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]     # height of the rectangle

                # width calculation
                if stack:
                    w = i - stack[-1] - 1
                else:
                    w = i

                max_area = max(max_area, h * w)

            stack.append(i)

        return max_area
