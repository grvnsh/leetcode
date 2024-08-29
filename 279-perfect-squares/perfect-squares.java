class Solution {
    private boolean isPerfectSquare(int x) {
        int root = (int) Math.sqrt(x);
        return root * root == x;
    }

    public int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        int[] a = new int[n + 1];
        Arrays.fill(a, n); 
        a[0] = 0;
        List<Integer> square = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            square.add(i * i);
            if (i * i <= n) {
                a[i * i] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int s : square) {
                if (s > i) break;
                a[i] = Math.min(a[i], 1 + a[i - s]);
            }
        }
        return a[n];
    }
}