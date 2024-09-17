class Solution {
    private void arr(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        arr(grid, i+1, j);
        arr(grid, i-1, j);
        arr(grid, i, j+1);
        arr(grid, i, j-1);
    }
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    arr(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
}