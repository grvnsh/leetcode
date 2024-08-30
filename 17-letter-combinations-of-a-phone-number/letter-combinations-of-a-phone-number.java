class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.isEmpty()) {
            return new ArrayList<>();
        }

        String[] combo = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> ans = new ArrayList<>();

        for (int i = 0; i < digits.length(); i++) {
            int index = digits.charAt(i) - '2';
            if (i == 0) {
                for (char c : combo[index].toCharArray()) {
                    ans.add(String.valueOf(c));
                }
            } else {
                List<String> temp = new ArrayList<>();
                for (char c : combo[index].toCharArray()) {
                    for (String s : ans) {
                        temp.add(s + c);
                    }
                }
                ans = temp;
            }
        }

        return ans;
    }
}