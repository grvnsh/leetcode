impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let max_or = nums.iter().fold(0, |acc, &x| acc | x);
        
        fn back(i: usize, curr: i32, nums: &Vec<i32>, max_or: i32) -> i32 {
            if i == nums.len() {
                return if curr == max_or { 1 } else { 0 };
            }
            
            let in_ = back(i + 1, curr | nums[i], nums, max_or);
            let out = back(i + 1, curr, nums, max_or);
            
            in_ + out
        }
        
        back(0, 0, &nums, max_or)
    }
}