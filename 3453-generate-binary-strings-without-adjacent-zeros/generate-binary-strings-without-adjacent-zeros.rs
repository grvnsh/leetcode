impl Solution {
    pub fn valid_strings(n: i32) -> Vec<String> {
        let mut res = Vec::new();
        Self::backtrack(n as usize, String::new(), false, &mut res);
        res
    }
    fn backtrack(n: usize, curr: String, prev: bool, res: &mut Vec<String>) {
        if curr.len() == n {
            res.push(curr);
            return;
        }
        Self::backtrack(n, curr.clone() + "1", false, res);
        if !prev {
            Self::backtrack(n, curr + "0", true, res);
        }
    }
}