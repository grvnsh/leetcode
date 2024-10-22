char findKthBit(int n, int k) {
    if (n == 1 || k == 1) {
        return '0';
    }
    int len = (1 << n) - 1; 
    int m = len / 2 + 1; 
    if (k == m) {
        return '1';
    } else if (k < m) {
        return findKthBit(n - 1, k);
    } else {
        return findKthBit(n - 1, len - k + 1) == '0' ? '1' : '0';
    }
}