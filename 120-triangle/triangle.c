int minimum(int arr[], int size) { 
    int min = arr[0]; 
    for (int i = 1; i < size; i++) { 
        if (arr[i] < min) { 
            min = arr[i]; 
        } 
    } 
    return min; 
} 
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (triangle[i + 1][j] < triangle[i + 1][j + 1]) {
                triangle[i][j] += triangle[i + 1][j];
            } else {
                triangle[i][j] += triangle[i + 1][j + 1];
            }
        }
    }
    return triangle[0][0];
}