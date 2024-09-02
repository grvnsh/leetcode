impl Solution {
    pub fn gray_code(n: i32) -> Vec<i32> {
        let number = 1 << n;
        let mut ans = Vec::with_capacity(number);
        for i in 0..number {
            ans.push((i ^ (i >> 1)) as i32);
        }
        ans
    }
}