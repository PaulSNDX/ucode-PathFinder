#include "../inc/pathfinder.h"

static int mx_find_in_arr(char **V, char *res) {
    int index = -1;

    while (mx_strcmp(V[++index], res));

    return index;
}

static int mx_find_V_index(char **V, char *array, int i) {
    int delimiter = mx_get_char_index(array, '-');
    char *res = NULL;

    if (!i) res = mx_strndup(array, delimiter);
    else res = mx_strndup(&array[delimiter + 1], mx_strlen(array) - delimiter - 1);

    int index = mx_find_in_arr(V, res);
    mx_strdel(&res);
    
    return index + i - i;
}

int **mx_check_duplication_and_max_len(char **array, char *file, int lines, char **V, int islands) {
    //DUPLICATION
    int i = 0;
    
    while (i < lines) {
        for (int j = 0; j < lines; j++)
            if (i != j && !mx_strcmp(array[i], array[j])) mx_duplicate_error(array, V, file);
        i++;
    }
    
    //MAX LEN
    int index = mx_get_char_index(file, '\n') + 1;
    long lenSum = 0;
    int adj[lines];
    int idx_temp = 0;

    while (lines--) {
        index += 1 + mx_get_char_index(&file[index], ',');
        char *temp = mx_strndup(&file[index], mx_get_char_index(&file[index], '\n'));
        int current = mx_atoi(temp);
        lenSum += current;
        if (current < __INT_MAX__) adj[idx_temp++] = current;

        mx_strdel(&temp);
    }
    
    if (lenSum >= __INT_MAX__) mx_INT_MAX_error(array, V, file);

    //ADJACENCY ARRAY
    int **adjacency_array = (int **) malloc(sizeof(int **) * islands);

    for (int i = 0; i < islands; i++)
        adjacency_array[i] = (int *) malloc(sizeof(int *) * islands);

    lines = 0;

    while (lines < idx_temp) {
        int first = mx_find_V_index(V, array[lines], 0);
        int second = mx_find_V_index(V, array[lines], 1);
        
        adjacency_array[first][second] = adj[lines];
        adjacency_array[second][first] = adj[lines++];
    }
    
    return adjacency_array; 
}
