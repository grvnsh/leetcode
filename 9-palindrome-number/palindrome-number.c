bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int rev_mid = 0;
    while (x > rev_mid) {
        rev_mid = rev_mid * 10 + x % 10;
        x /= 10;
    }
    return x == rev_mid || x == rev_mid / 10;
}