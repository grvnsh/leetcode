impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        if nums.is_empty() { return 0; }
        if nums.len() == 1 { return nums[0]; }
        let mut max = nums[0];
        let mut min = nums[0];
        let mut res = max;
        let mut pos;
        for &num in nums.iter().skip(1) {
            pos = max;
            max = num.max(max * num).max(min * num);
            min = num.min(pos * num).min(min * num);
            res = res.max(max);
        }
        res
    }
}