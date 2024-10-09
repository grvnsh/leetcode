class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] pfX = new int[m + 1][n + 1];
        int[][] pfY = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pfX[i][j] = pfX[i - 1][j] + pfX[i][j - 1] - pfX[i - 1][j - 1];
                pfY[i][j] = pfY[i - 1][j] + pfY[i][j - 1] - pfY[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 'X') pfX[i][j]++;
                if (grid[i - 1][j - 1] == 'Y') pfY[i][j]++;
            }
        }
        int count = 0;
        for (int i2 = 1; i2 <= m; i2++) {
            for (int j2 = 1; j2 <= n; j2++) {
                int x = pfX[i2][j2];
                int y = pfY[i2][j2];
                if (x == y && x > 0) count++;
            }
        }
        return count;
    }
}