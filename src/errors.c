#include "../inc/pathfinder.h"

static void mx_close(int fd) {
    close(fd);
    exit(0);
}

static void mx_str_file_free(char *file) {
    mx_strdel(&file);
    exit(0);
}

void mx_usage_error(void) {
    mx_printerr("usage: ./pathfinder [filename]\n");
    exit(0);
}

void mx_file_error(const char *filename, int fd) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
    mx_close(fd);
}

void mx_empty_file_error(const char *filename, char *file_str, int fd) {
    mx_strdel(&file_str);
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" is empty\n");
    mx_close(fd);
}

void mx_first_line_error(int fd) {
    mx_printerr("error: line 1 is not valid\n");
    mx_close(fd);
}

void mx_file_line_error(int line, char *file, char *V, char *dst01, char *dst02, char *dst03) {
    mx_strdel(&V);
    mx_strdel(&dst01);
    mx_strdel(&dst02);
    mx_strdel(&dst03);
    mx_printerr("error: line ");
    mx_printerr((const char *) mx_itoa(line));
    mx_printerr(" is not valid\n");
    mx_str_file_free(file);
}

void mx_islands_error(char *file) {
    mx_printerr("error: invalid number of islands\n");
    mx_str_file_free(file);
}

void mx_duplicate_error(char **array, char **V, char *file) {
    mx_printerr("error: duplicate bridges\n");
    mx_strdel(array);
    mx_strdel(V);
    mx_str_file_free(file);
}

void mx_INT_MAX_error(char **array, char **V, char *file) {
    mx_printerr("error: sum of bridges lengths is too big\n");
    mx_strdel(array);
    mx_strdel(V);
    mx_str_file_free(file);
}
