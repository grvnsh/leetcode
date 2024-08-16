class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def brackets(l, r, str):
		if len(str) == n * 2:
			result.append(str)
			return 
		if l < n:
			brackets(l + 1, r, str + '(')
		if r < l:
			brackets(l, r + 1, str + ')')
	result = []
	brackets(0, 0, '')
	return result