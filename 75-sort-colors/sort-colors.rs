impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut l = 0;
        let mut m = 0;
        let mut h = nums.len();
        while m < h {
            match nums[m] {
                0 => {
                    nums.swap(l, m);
                    l += 1;
                    m += 1;
                }
                1 => {
                    m += 1;
                }
                2 => {
                    h -= 1;
                    nums.swap(m, h);
                }
                _ => unreachable!(),
            }
        }
    }
}