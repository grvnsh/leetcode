int reverse(int x) {
    int max = 2147483647;
    int min = -2147483648;
    if ((x <= max) && (x >= min)) {
        int result = 0;
        int n = 0;
        while (x != 0) {
            int n = x % 10;
            x /= 10;
            if (result > max / 10 || (result == max / 10 && n > 7)) {
                return 0;
            }
            if (result < min / 10 || (result == min / 10 && n < -8)) {
                return 0;
            }
            result = (result * 10) + n;
        }
        return result;
    }
    return 0;
}