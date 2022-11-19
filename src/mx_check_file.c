#include "../inc/pathfinder.h"

static bool mx_isalpha_line(char *str) {
    if (mx_strlen(str) <= 0) return false;

    for (int i = 0; i < mx_strlen(str); i++)
        if (!mx_isalpha(str[i])) return false;

    return true;
}

static bool mx_isInSTR(char *value, char *str, int len) {
    if (!str) return false;

    char **arr = mx_strsplit(str, '|');

    for (int i = 0; i < len; i++)
        if (mx_strcmp(value, arr[i]) == 0) return true;

    return false;
}

char **mx_check_file(char *file, int lines, int islands) {
    char *V = NULL;
    int current_line = 1;
    int V_len = 0;
    int index = mx_get_char_index(file, '\n') + 1;

    char *dst01 = NULL;
    char *dst02 = NULL;
    char *dst03 = NULL;

    while (file[index] != '\0' && current_line <= lines) {
        int len01 = mx_get_char_index(&file[index], '-');
        if (len01 < 0)
            mx_file_line_error(current_line + 1, file, V, dst01, dst02, dst03);
    
        dst01 = mx_strndup(&file[index], len01);
        index += len01 + 1;

        int len02 = mx_get_char_index(&file[index], ',');
        if (len02 < 0)
            mx_file_line_error(current_line + 1, file, V, dst01, dst02, dst03);

        dst02 = mx_strndup(&file[index], len02);
        index += len02 + 1;

        int len03 = mx_get_char_index(&file[index], '\n');
        if (len03 < 0)
            mx_file_line_error(current_line + 1, file, V, dst01, dst02, dst03);
        
        dst03 = mx_strndup(&file[index], len03);
        index += len03 + 1;

        if (!mx_isalpha_line(dst01) || !mx_isalpha_line(dst02) || mx_atoi(dst03) <= 0 || mx_strcmp(dst01, dst02) == 0)
            mx_file_line_error(current_line + 1, file, V, dst01, dst02, dst03);

        if (!mx_isInSTR(dst01, V, V_len)) {
            V = mx_strjoin(mx_strjoin(V, dst01), "|");
            V_len++;
        }
        if (!mx_isInSTR(dst02, V, V_len)) {
            V = mx_strjoin(mx_strjoin(V, dst02), "|");
            V_len++;
        }
        
        current_line++;
    }
    
    mx_strdel(&dst01);
    mx_strdel(&dst02);
    mx_strdel(&dst03);
  
    if (V_len != islands) {
        mx_strdel(&V);
        mx_islands_error(file);
    }

    return mx_strsplit(V, '|');
}
