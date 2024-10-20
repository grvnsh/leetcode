class Solution {
    private int max_or = 0;
    private int[] nums;

    public int countMaxOrSubsets(int[] nums) {
        this.nums = nums;
        for (int num : nums) {
            max_or |= num;
        }
        return back(0, 0);
    }

    private int back(int i, int curr) {
        if (i == nums.length) {
            return curr == max_or ? 1 : 0;
        }

        int in = back(i + 1, curr | nums[i]);
        int out = back(i + 1, curr);

        return in + out;
    }
}