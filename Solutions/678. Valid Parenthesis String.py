from typing import *
from collections import deque

class Solution:

    def checkValidString(self, s: str) -> bool:

        stack = deque()
        astric = 0

        for c in s:

            if c == '(':
                stack.append(c)

            elif c == '*':
                astric += 1

            elif c == ')':
                if stack:
                    stack.pop()
                elif astric > 0:
                    astric -= 1
                else:
                    return False

        remaining = len(stack)

        if remaining == 0:
            return True

        return astric >= remaining


s = "()"
s1 = "(*)"
s2 = "(*)))"

sol = Solution()

print(sol.checkValidString(s))
print(sol.checkValidString(s1))
print(sol.checkValidString(s2))