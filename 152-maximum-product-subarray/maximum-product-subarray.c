int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int max = nums[0];
    int min = nums[0];
    int res = max;
    for (int i = 1; i < numsSize; i++) {
        int pos = max;
        max = fmax(nums[i], fmax(max * nums[i], min * nums[i]));
        min = fmin(nums[i], fmin(pos * nums[i], min * nums[i]));
        res = fmax(res, max);
    }
    return res;
}