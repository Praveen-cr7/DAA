#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

void print_solution(int path[V]) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // Complete the circuit
}

bool is_valid(int v, int graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v]) {
        return false; // No edge between last vertex and v
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false; // Vertex already in the path
        }
    }

    return true;
}

bool hamiltonian_circuit_util(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]]) {
            print_solution(path);
            return true;
        }
        return false;
    }

    for (int v = 1; v < V; v++) {
        if (is_valid(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonian_circuit_util(graph, path, pos + 1)) {
                return true;
            }
            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

void hamiltonian_circuit(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0; // Start from vertex 0

    if (!hamiltonian_circuit_util(graph, path, 1)) {
        printf("No Hamiltonian Circuit exists.\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonian_circuit(graph);

    return 0;
}

