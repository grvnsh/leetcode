impl Solution {
    pub fn number_of_submatrices(grid: Vec<Vec<char>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut pfx = vec![vec![0; n + 1]; m + 1];
        let mut pfy = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            for j in 1..=n {
                pfx[i][j] = pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
                pfy[i][j] = pfy[i - 1][j] + pfy[i][j - 1] - pfy[i - 1][j - 1];
                if grid[i - 1][j - 1] == 'X' {
                    pfx[i][j] += 1;
                }
                if grid[i - 1][j - 1] == 'Y' {
                    pfy[i][j] += 1;
                }
            }
        }
        let mut count = 0;
        for i2 in 1..=m {
            for j2 in 1..=n {
                let x = pfx[i2][j2];
                let y = pfy[i2][j2];
                if x == y && x > 0 {
                    count += 1;
                }
            }
        }
        count
    }
}