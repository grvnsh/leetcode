bool segment(char* s, char** wordDict, int wordDictSize, int start, int* res) {
    if (start == strlen(s)) {
        return true;
    }
    if (res[start] != -1) {
        return res[start];
    }
    for (int i = 0; i < wordDictSize; i++) {
        int wordLen = strlen(wordDict[i]);
        if (strncmp(s + start, wordDict[i], wordLen) == 0) {
            if (segment(s, wordDict, wordDictSize, start + wordLen, res)) {
                res[start] = 1;
                return true;
            }
        }
    }
    res[start] = 0;
    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    int* ans = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        ans[i] = -1;
    }
    bool result = segment(s, wordDict, wordDictSize, 0, ans);
    free(ans);
    return result;
}
