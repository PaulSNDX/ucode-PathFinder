#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    for (int i = 0; i < len; i++) {
        if (src[i] == '\0') {
            while (i < mx_strlen(dst)) dst[i++] = '\0';
            break;
        } else dst[i] = src[i];
    }
    dst[len] = '\0';
    return dst;
}
