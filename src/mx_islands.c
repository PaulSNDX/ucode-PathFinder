#include "../inc/pathfinder.h"

int mx_amount_of_islands(int argc, char *argv[]) {
    if (argc != 2) mx_usage_error();
    
    int fd = open(argv[1], O_RDONLY);
    char *filename = argv[1];

    if (fd <= 0) mx_file_error(filename, fd);
    
    char *file_str = mx_file_to_str(filename);
    if (file_str == NULL) mx_empty_file_error(filename, file_str, fd);

    return mx_first_line(file_str, '\n', fd);
}
