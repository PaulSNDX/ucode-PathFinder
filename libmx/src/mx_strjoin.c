#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (!s1 && !s2) return NULL;
    if (!s1 || !s2) return mx_strdup((!s1) ? s2 : s1);

    char *join = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    return mx_strcat(mx_strcat(join, s1), s2);
}
