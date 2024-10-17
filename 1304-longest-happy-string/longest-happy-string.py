class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
        max = []
        for c1, ch in [(-a, 'a'), (-b, 'b'), (-c, 'c')]:
            if c1 != 0:
                heapq.heappush(max, (c1, ch))
        ans = []
        while max:
            c1, ch = heapq.heappop(max)
            if len(ans) >= 2 and ans[-1] == ans[-2] == ch:
                if not max:
                    break
                c2, ch2 = heapq.heappop(max)
                ans.append(ch2)
                c2 += 1
                if c2 != 0:
                    heapq.heappush(max, (c2, ch2))
            else:
                ans.append(ch)
                c1 += 1
            if c1 != 0:
                heapq.heappush(max, (c1, ch))
        return ''.join(ans)