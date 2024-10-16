class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        for (int i = 0; i <= n - k; i++) {
            ans[i] = exp(nums, i, i + k - 1);
        }
        return ans;
    }
    private int exp(int[] nums, int start, int end) {
        int max = nums[start];
        int ans = nums[start];
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] != ans + 1) {
                return -1;
            }
            ans++;
            max = Math.max(max, nums[i]);
        }
        return max;
    }
}