class Solution(object):
    def myPow(self, x, n):
        if n == 0:
            return 1.0
        absN = n
        if absN < 0:
            x = 1 / x
            absN = -absN
        result = 1.0
        prod = x
        while absN > 0:
            if absN % 2 == 1:
                result *= prod
            prod *= prod
            absN //= 2
        return result