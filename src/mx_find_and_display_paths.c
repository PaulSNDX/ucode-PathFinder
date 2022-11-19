#include "../inc/pathfinder.h"

static void mx_print_output(int **adjacency_array, char **V, int *distance, int islands, int i, int startnode) {
    bool route_exist = true;
    int priority[islands][islands];
    for (int i = 0; i < islands; i++) {
        for (int j = 0; j < islands; j++) {
            priority[i][j] = 1;
        }
    }
    while (route_exist) {
        route_exist = false;
        char *split_line = "========================================\n";
    
        int p = i;
        int arr_counter = 0;

        mx_printstr(split_line);
    
        mx_printstr("Path: ");
        while (p != startnode) {
            arr_counter++;
            int y = p;
            for (int j = 0; j < islands; j++) {
                int bridge = adjacency_array[y][j];
                if (bridge != 0 && bridge == distance[y] - distance[j]) {
                    if (y == p) p = j;
                    else if (priority[p][y] < priority[j][y]) p = j;
                }
            }
        }
        mx_printstr(V[p]);
        mx_printstr(" -> ");
        mx_printstr(V[i]);
        mx_printstr("\nRoute: ");
        char *route[arr_counter];
        char *distance_path[arr_counter];
        int counter_copy = arr_counter;
        arr_counter = 0;
        p = i;
        bool priority_chandge = false;

        while (p != startnode) {
            int y = p;
            for (int j = 0; j < islands; j++) {
                int bridge = adjacency_array[y][j];
                if (bridge != 0 && bridge == distance[y] - distance[j]) {
                    if (y == p) {
                        p = j;
                    }
                    else if (priority[p][y] < priority[j][y]) {
                        p = j;
                    }
                    else if (priority[j][y] == 1) {
                        route_exist = true;
                    }
                }
            }
            
            if (!priority_chandge) {
                priority[p][y] = 0;
                priority[y][p] = 0;
                priority_chandge = true;
            }

            bool full = true;
            for (int j = 0; j < islands; j++) {
                int bridge = adjacency_array[y][j];
                if (bridge != 0 && bridge == distance[y] - distance[j]) {
                    if (priority[j][y] == 1) {
                        full = false;
                    }
                }
            }
            if (full) {
                priority_chandge = false;
                for (int j = 0; j < islands; j++) {
                    int bridge = adjacency_array[y][j];
                    if (bridge != 0 && bridge == distance[y] - distance[j]) {
                        priority[j][y] = 1;
                    }
                }
            }
            route[arr_counter] = mx_strdup(V[p]);
            distance_path[arr_counter++] = mx_strdup(mx_itoa(adjacency_array[y][p]));
        }
        while (arr_counter--) {
            mx_printstr(route[arr_counter]);
            mx_printstr(" -> ");
        }
        mx_printstr(V[i]);
        mx_printstr("\nDistance: ");
        arr_counter = counter_copy;
        if (arr_counter > 1)
            while (arr_counter--) {
                mx_printstr(distance_path[arr_counter]);
                mx_printstr(arr_counter ? " + " : " = ");
            }
        mx_printstr(mx_itoa(distance[i]));
        mx_printstr("\n");
        mx_printstr(split_line);

        for (int i = 0; i < counter_copy; i++) {
            mx_strdel(&route[i]);
            mx_strdel(&distance_path[i]);
        }
        mx_strdel(route);
        mx_strdel(distance_path);
    }
}

void mx_dijkstra(int **adjacency_array, char **V, int islands) {
    int adjacency_array_copy[islands][islands];
    int *distance = (int *) malloc(sizeof(int *) * islands);
    int visited[islands];
    int mindistance;
    int nextnode;
    int count;
    int temp = 0;

    for (int startnode = 0; startnode < islands - 1; startnode++) {
        for(int i = 0; i < islands; i++) {
            for(int j = 0; j < islands; j++)
                adjacency_array_copy[i][j] = !adjacency_array[i][j] ? 999999999 : adjacency_array[i][j];
            
            distance[i] = adjacency_array_copy[startnode][i];
            visited[i] = 0;
        }

        distance[startnode] = 0;
        visited[startnode] = 1;
        count = 1;

        while (count++ < islands - 1) {
            mindistance = 999999999;
        
            for(int i = 0; i < islands; i++) {
                if(distance[i] < mindistance && !visited[i]) {
                    mindistance = distance[i];
                    nextnode = i;
                }
            }
            
            visited[nextnode] = 1;

            for(int i = 0; i < islands; i++) {
                if(!visited[i])
                    if(mindistance + adjacency_array_copy[nextnode][i] < distance[i]) {
                        distance[i] = mindistance + adjacency_array_copy[nextnode][i];
                    }
            }
        }
        
        for(int i = temp; i < islands; i++) {
            if (i != startnode)
                mx_print_output(adjacency_array, V, distance, islands, i, startnode);
        }
        temp++;
    }

    free(distance);
    distance = NULL;
}
