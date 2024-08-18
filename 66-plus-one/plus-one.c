/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int n = 1; 
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    *returnSize = digitsSize;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + n;
        result[i + 1] = sum % 10;
        n = sum / 10;
    }
    if (n == 1) {
        result[0] = n;
        (*returnSize)++;
    } else {
        memmove(result, result + 1, digitsSize * sizeof(int));
    }
    return result;
}