/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char two[4] = "abc";
    char three[4] = "def";
    char four[4] = "ghi";
    char five[4] = "jkl";
    char six[4] = "mno";
    char seven[5] = "pqrs";
    char eight[4] = "tuv";
    char nine[5] = "wxyz";
    char *combo[8] = {two, three, four, five, six, seven, eight, nine};
    char **ans = (char **)malloc(1000 * sizeof(char *));
    int count = 0;
    if (digits == NULL || strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    for (int i = 0; i < strlen(digits); i++) {
        int index = digits[i] - '2';
        if (i == 0) {
            for (int j = 0; j < strlen(combo[index]); j++) {
                ans[count] = (char *)malloc(2 * sizeof(char));
                ans[count][0] = combo[index][j];
                ans[count][1] = '\0';
                count++;
            }
        } else {
            int prevCount = count;
            for (int j = 0; j < strlen(combo[index]); j++) {
                for (int k = 0; k < prevCount; k++) {
                    ans[count] = (char *)malloc((strlen(ans[k]) + 2) * sizeof(char));
                    sprintf(ans[count], "%s%c", ans[k], combo[index][j]);
                    count++;
                }
            }
        }
    }
    int validCount = 0;
    for (int i = 0; i < count; i++) {
        if (strlen(ans[i]) == strlen(digits)) {
            ans[validCount++] = ans[i];
        } else {
            free(ans[i]);
        }
    }
    count = validCount;
    *returnSize = count;
    return ans;
}
