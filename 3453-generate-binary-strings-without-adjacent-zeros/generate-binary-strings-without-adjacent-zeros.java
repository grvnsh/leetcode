class Solution {
    public List<String> validStrings(int n) {
        List<String> ans = new ArrayList<>();
        gen("", n, ans);
        return ans;   
    }
    private void gen(String curr, int left, List<String> l) {
        if (left == 0) {
            l.add(curr);
            return;
        }
        if (curr.isEmpty() || curr.charAt(curr.length() - 1) == '1') {
            gen(curr + "0", left - 1, l);
        }
        gen(curr + "1", left - 1, l);
    }
}