#include "../inc/libmx.h"

int mx_strlen(const char *str) {
    if (str == NULL || *str == '\0') return 0;
    
    int count = 0;
    
    while (*str != '\0') {
        str++;
        count++;
    }
    return count;
}
