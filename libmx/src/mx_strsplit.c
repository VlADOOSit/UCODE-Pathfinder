#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) {
        return NULL;
    }
    char **result = NULL;
    int count = 0;

    result = (char**)malloc((mx_count_words(s, c) + 1) * sizeof(char*));

    while (*s) {
        if (*s != c) {
            int word_len = 0;
	        while (s[word_len] != c && s[word_len]) {
                word_len++;   
            }
            result[count] = mx_strndup(s, word_len);
            s += word_len;
            count++;
            continue;
        }
        s++;
    }
    result[count] = NULL;
    return result;
}
