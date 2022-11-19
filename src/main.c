#include "../inc/pathfinder.h"

static void mx_free_adjacency_array(int **adjacency_array, int islands) {
    for (int i = 0; i < islands; i++)
        free(adjacency_array[i]);

    free(adjacency_array);
}

static void mx_2Dchar_array_del(char **arr, int islands) {
    for (int i = 0; i < islands; i++)
        mx_strdel(&arr[i]);
    free(arr);
}

static void mx_clean(int **adjacency_array, int islands, char **V, char **array, char *file) {
    mx_free_adjacency_array(adjacency_array, islands);
    mx_2Dchar_array_del(V, islands);
    mx_2Dchar_array_del(array, islands);
    mx_strdel(&file);
}

int main(int argc, char *argv[]) {
    int islands = mx_amount_of_islands(argc, argv);
    
    char *file = mx_file_to_str(argv[1]);
    int lines = mx_count_lines(file) - 1;
    char **V = mx_check_file(file, lines, islands);
    char **array = mx_file_to_arr(file);

    int **adjacency_array = mx_check_duplication_and_max_len(array, file, lines, V, islands);

    mx_dijkstra(adjacency_array, V, islands);
    mx_clean(adjacency_array, islands, V, array, file);
}
