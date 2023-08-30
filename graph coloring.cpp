#include <stdio.h>
#include <stdbool.h>

#define N 10

bool is_safe(int graph[N][N], int vertex, int color[], int c) {
    for (int i = 0; i < N; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_backtracking(int graph[N][N], int num_colors, int vertex, int color[]) {
    if (vertex == N) {
        return true;
    }

    for (int c = 1; c <= num_colors; c++) {
        if (is_safe(graph, vertex, color, c)) {
            color[vertex] = c;
            if (graph_coloring_backtracking(graph, num_colors, vertex + 1, color)) {
                return true;
            }
            color[vertex] = 0;
        }
    }
    return false;
}

int main() {
    int graph[N][N];
    int num_colors, color[N];

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (graph_coloring_backtracking(graph, num_colors, 0, color)) {
        printf("Solution exists. Vertex colors: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
    } else {
        printf("No solution exists for the given parameters.\n");
    }

    return 0;
}

