class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [''] * numRows
        i = 0
        d = False

        for c in s:
            rows[i] += c
            if i == 0 or i == numRows - 1:
                d = not d
            i += 1 if d else -1

        return ''.join(rows)