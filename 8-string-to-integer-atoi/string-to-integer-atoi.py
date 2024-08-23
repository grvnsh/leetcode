class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        if not s:
            return 0
        sign = -1 if s[0] == '-' else 1
        if s[0] in ['-', '+']:
            s = s[1:]
        ans = 0
        for char in s:
            if not char.isdigit():
                break
            ans = ans * 10 + int(char)
            if sign * ans <= -2**31:
                return -2**31
            if sign * ans >= 2**31 - 1:
                return 2**31 - 1
        return sign * ans