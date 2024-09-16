void arr(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i] || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    arr(grid, gridSize, gridColSize, i+1, j);
    arr(grid, gridSize, gridColSize, i-1, j);
    arr(grid, gridSize, gridColSize, i, j+1);
    arr(grid, gridSize, gridColSize, i, j-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                arr(grid, gridSize, gridColSize, i, j);
                count++;
            }
        }
    }
    return count;
}