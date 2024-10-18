class Solution {
    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<int[]> max = new PriorityQueue<>((x, y) -> y[1] - x[1]);
        if (a > 0) max.offer(new int[]{0, a});
        if (b > 0) max.offer(new int[]{1, b});
        if (c > 0) max.offer(new int[]{2, c});
        StringBuilder ans = new StringBuilder();
        while (!max.isEmpty()) {
            int[] curr = max.poll();
            int n = ans.length();
            if (n >= 2 && ans.charAt(n - 1) - 'a' == curr[0] && ans.charAt(n - 2) - 'a' == curr[0]) {
                if (max.isEmpty()) break;
                int[] next = max.poll();
                ans.append((char) (next[0] + 'a'));
                if (--next[1] > 0) max.offer(next);
                max.offer(curr);
            } else {
                ans.append((char) (curr[0] + 'a'));
                if (--curr[1] > 0) max.offer(curr);
            }
        }
        return ans.toString();
    }
}