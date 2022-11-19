#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    if (!str) return -1; // for "" error -1 add < && !mx_strlen(str)> else it will return 0

    int words = 0;
    int c = 0;

    if (str[c++] != delimiter) words++;

    while (str[c + 1] != '\0')
        if (str[c++] == delimiter && str[c] != delimiter) words++;

    return str[c] == '\0' && str[c - 1] != delimiter ? words + 1 : words;
}
