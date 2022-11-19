#include "../inc/pathfinder.h"

static bool mx_presence_check(char c) {
    char *test = "1234567890,\n";

    for (int i = 0; i < 12; i++)
        if (c == test[i]) return true;

    return false;
}

char **mx_file_to_arr(char *file) {
    int index = 0;
    char *copy = mx_strdup(file);

    while (copy[index] != '\0') {
        if (mx_presence_check(copy[index])) copy[index] = '$';
        index++;
    }

    char **array = mx_strsplit(copy, '$');
    return array;
}
