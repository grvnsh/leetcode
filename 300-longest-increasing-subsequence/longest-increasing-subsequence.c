int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int arr[numsSize];
    arr[0] = 1;
    int len = 1;
    for (int i = 1; i < numsSize; i++) {
        arr[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                arr[i] = fmax(arr[i], arr[j] + 1);
            }
        }
        len = fmax(len, arr[i]);
    }
    return len;
}