class Solution(object):
    def shortestSubstrings(self, arr):
        """
        :type arr: List[str]
        :rtype: List[str]
        """
        n = len(arr)
        ans = [''] * n
        def u(s, i):
            return all(s not in arr[j] for j in range(n) if j != i)
        for i in range(n):
            min = float('inf')
            x = ''
            for l in range(1, len(arr[i]) + 1):
                for s in range(len(arr[i]) - l + 1):
                    sub = arr[i][s:s + l]
                    if u(sub, i):
                        if l < min or (l == min and sub < x):
                            min = l
                            x = sub
                if min != float('inf'):
                    break
            ans[i] = x
        return ans