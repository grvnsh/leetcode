char* simplifyPath(char* path) {
    int w = 0, r = 0, l = 0;
    int n = strlen(path);
    for (r = 0; r <= n; r++) {
        if (r == n || path[r] == '/') {
            if (l == 0) {
                continue;
            } else if (l == 1 && path[r-1] == '.') {
                l = 0;
            } else if (l == 2 && path[r-2] == '.' && path[r-1] == '.') {
                while (w > 0 && path[w-1] != '/') w--;
                if (w > 0) w--;
                l = 0;
            } else {
                if (w == 0 || path[w-1] != '/') {
                    path[w++] = '/';
                }
                memmove(&path[w], &path[r-l], l);
                w += l;
                l = 0;
            }
        } else {
            l++;
        }
    }
    if (w == 0) {
        path[w++] = '/';
    }
    path[w] = '\0';
    return path;
}