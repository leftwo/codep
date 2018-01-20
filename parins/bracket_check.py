# python3
import sys
class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for i, next in enumerate(s):
            if next == '(' or next == '[' or next == '{':
                stack.append(next)

            elif next == ')' or next == ']' or next == '}':
                if len(stack) == 0:
                    return False

                if (stack[-1] == '[' and next == ']') or \
                   (stack[-1] == '{' and next == '}') or \
                   (stack[-1] == '(' and next == ')'):
                    stack.pop()
                else:
                    return False
            else:
                return False

        if len(stack) != 0:
            return False
    
        return True
