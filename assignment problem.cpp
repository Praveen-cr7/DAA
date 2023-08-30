#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4

int min_cost = INT_MAX;

void branch_and_bound(int cost_matrix[N][N], int assigned[N], int total_cost, int task) {
    if (task == N) {
        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
        return;
    }

    for (int agent = 0; agent < N; agent++) {
        if (!assigned[agent]) {
            assigned[agent] = 1;
            branch_and_bound(cost_matrix, assigned, total_cost + cost_matrix[agent][task], task + 1);
            assigned[agent] = 0;
        }
    }
}

int main() {
    int cost_matrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int assigned[N] = {0};
    branch_and_bound(cost_matrix, assigned, 0, 0);

    printf("Minimum assignment cost: %d\n", min_cost);

    return 0;
}

