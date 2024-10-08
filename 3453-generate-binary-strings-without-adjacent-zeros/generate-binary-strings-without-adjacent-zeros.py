class Solution(object):
    def validStrings(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def backtrack(curr, prev):
            if len(curr) == n:
                ans.append(curr)
                return
            backtrack(curr + '1', False)
            if not prev:
                backtrack(curr + '0', True)
        ans = []
        backtrack('', False)
        return ans