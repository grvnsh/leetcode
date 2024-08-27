class Solution {
    public String simplifyPath(String path) {
        char[] chars = path.toCharArray();
        int w = 0, r = 0, l = 0;
        int n = chars.length;
        for (r = 0; r <= n; r++) {
            if (r == n || chars[r] == '/') {
                if (l == 0 || (l == 1 && chars[r-1] == '.')) {
                    l = 0;
                } else if (l == 2 && chars[r-2] == '.' && chars[r-1] == '.') {
                    if (w > 0) {
                        w--;
                        while (w > 0 && chars[w-1] != '/') w--;
                    }
                    l = 0;
                } else {
                    if (w == 0 || chars[w-1] != '/') {
                        chars[w++] = '/';
                    }
                    System.arraycopy(chars, r-l, chars, w, l);
                    w += l;
                    l = 0;
                }
            } else {
                l++;
            }
        }
        if (w == 0) {
            chars[w++] = '/';
        } else if (w > 1 && chars[w-1] == '/') {
            w--;
        }
        return new String(chars, 0, w);
    }
}