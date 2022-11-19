#pragma once

#include "../libmx/inc/libmx.h"

//MAIN
int mx_amount_of_islands(int argc, char *argv[]);
int mx_first_line(char *str, char delim, int fd);
int mx_count_lines(char *str);
char **mx_check_file(char *file, int lines, int islands);
char **mx_file_to_arr(char *file);
int **mx_check_duplication_and_max_len(char **array, char *file, int lines, char **V, int islands);
void mx_dijkstra(int **adjacency_array, char **V, int islands);

// ERRORS
void mx_usage_error(void);
void mx_file_error(const char *filename, int fd);
void mx_empty_file_error(const char *filename, char *file_str, int fd);
void mx_first_line_error(int fd);
void mx_file_line_error(int line, char *file, char *V, char *dst01, char *dst02, char *dst03);
void mx_islands_error(char *file);
void mx_duplicate_error(char **array, char **V, char *file);
void mx_INT_MAX_error(char **array, char **V, char *file);
