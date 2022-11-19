#include "../inc/pathfinder.h"

int mx_count_lines(char *str) {
    int lines = 0;

    while (*str != '\0') {
        if (*str == '\n') lines++;
        str++;
    }
    
    return lines;
}
