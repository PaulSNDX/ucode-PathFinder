#include "../inc/pathfinder.h"

int mx_first_line(char *str, char delim, int fd) {
    int len = 0;

    for (int i = 0; str[i] != '\0'; len++)
        if ((char) str[i++] == delim) break;

    char *substr = mx_strnew(len);
    substr[len] = '\0';

    for (int i = 0; i < len; i++) substr[i] = str[i];

    int number = mx_atoi(substr);
    mx_strdel(&substr);
    mx_strdel(&str);

    if (number <= 0) mx_first_line_error(fd);
    
    close(fd);
    return number;
}
