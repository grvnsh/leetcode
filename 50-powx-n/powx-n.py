class Solution(object):
    def myPow(self, x, n):
        if n == 0:
            return 1.0
        
        N = n
        if N < 0:
            x = 1 / x
            N = -N
        
        result = 1.0
        prod = x
        
        while N > 0:
            if N % 2 == 1:
                result *= prod
            prod *= prod
            N //= 2
        
        return result
        