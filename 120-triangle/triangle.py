class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        def minimum(arr, size):
            min_value = arr[0]
            for i in range(1, size):
                if arr[i] < min_value:
                    min_value = arr[i]
            return min_value
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(i + 1):
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
        return triangle[0][0]