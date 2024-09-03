class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        def segment(start, res):
            if start == len(s):
                return True
            if start in res:
                return res[start]
            for word in wordDict:
                if s.startswith(word, start):
                    if segment(start + len(word), res):
                        res[start] = True
                        return True
            res[start] = False
            return False
        return segment(0, {})