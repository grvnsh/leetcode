void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    /*matrixColSize = strlen(matrix)+2;
    int arr[matrixSize][100];
    int row[matrixSize];
    int col[100];
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < strlen(matrix)+2; j++) {
            if ((matrix[i][j] > INT_MAX) || (matrix[i][j] < INT_MIN)) {
                return;
            }
            if (matrix[i][j] == 0) {
                //arr[i][j] = 0;
                row[i] = i;
                col[j] = j;
            } else {
                //arr[i][j] = 1;
            }
            printf("%d\n", row[i]);
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < strlen(matrix)+2; j++) {
            //matrix[row[i]][j] = 0;
            //matrix[i][col[j]] = 0;
            //printf("%d\n", matrix[i][j]);
        }
    }
    //printf("%d\n", strlen(matrix)+2);
    */
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        return;
    }

    int colSize = matrixColSize[0];
    int row[matrixSize];
    int col[colSize];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}